#include "03/Menu/scroll_bar.h"

#include "03/code_021cc000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/unk_021d6000.h"
#include "03/System/task_input.h"
#include "03/code_021cdbd0.h"
#include "03/unk_021d7000.h"
#include "code_02147cd8.h"
#include "player.h"
#include "03/System/rect.h"
#include "03/System/exp_heap.h"
#include "03/System/tasks.h"

const u8 gScrollBarImageIds[3] = {0x10, 0xf, 0xe};
const u8 gScrollBarLengths[3] = {0x55, 0x36, 0x1e};

void CreateScrollBar(u32 sizeIndex, u32 trackLength, u16 positionX, u16 positionY, u32 offset) {
    (gScrollBar = AllocZeroedExpHeapBlock(0x20, 4))->mSizeIndex = sizeIndex;
    gScrollBar->mTrackLength = trackLength;
    gScrollBar->mOffset = offset;
    SetPosition(positionX, positionY, &gScrollBar->mX);
    gScrollBar->mResource = CreateOamRangeFromNceImage(0, gScrollBarImageIds[sizeIndex], 1);
    SetOamRangePosition(gScrollBar->mResource, -1, positionX, positionY + offset);
    SetOamRangePriority(gScrollBar->mResource, -1, 1);
    gScrollBar->mTask = AddTask(0, AdvanceScrollBar, NULL, 0x80);
}

void ReleaseScrollBar(void) {
    RemoveTaskEntryWrapper(0, gScrollBar->mTask);
    DeleteOamRange(gScrollBar->mResource);
    FreeExpHeapBlockAndClearPointer(&gScrollBar);
}

u8 GetScrollBarOffset(void) {
    return gScrollBar->mOffset;
}

u8 GetScrollBarEvent(void) {
    return gScrollBar->mEvent;
}

void PlaceScrollBarWrapper(s32 offset) {
    PlaceScrollBar(offset);
}

void EnableScrollBarInput(void) {
    gScrollBar->mInputDisabled = 0;
}

void DisableScrollBarInput(void) {
    gScrollBar->mInputDisabled = 1;
}

void AdvanceScrollBar(void) {
    gScrollBar->mEvent = 0;
    switch (gScrollBar->mState) {
        case 0:
            if (gScrollBar->mInputDisabled == 0) {
                switch (GetPressedScrollBarPart()) {
                    case 1:
                        if (gScrollBar->mSizeIndex != 0) {
                            StartSoundSeq(0x16);
                            SetSoundSeqVolume(0);
                            gScrollBar->mEvent = 1;
                            GetTouchPoint(gScrollBar->mDragStartTouch);
                            gScrollBar->mDragStartOffset = gScrollBar->mOffset;
                            gScrollBar->mState = 1;
                        }
                        break;
                    case 2:
                        StartScrollBarArrowHold(2);
                        break;
                    case 3:
                        StartScrollBarArrowHold(3);
                        break;
                    case 4:
                        MoveScrollBarToTouch();
                        break;
                }
            }
            break;
        case 1:
            AdvanceScrollBarDrag();
            break;
        case 2:
            if (GetTouchedScrollBarArrow(2) != 2) {
                gScrollBar->mEvent = 5;
                gScrollBar->mState = 0;
            } else if (GetPressedScrollBarPart() == 2) {
                StartScrollBarArrowHold(2);
            }
            break;
        case 3:
            if (GetTouchedScrollBarArrow(3) != 3) {
                gScrollBar->mEvent = 7;
                gScrollBar->mState = 0;
            } else if (GetPressedScrollBarPart() == 3) {
                StartScrollBarArrowHold(3);
            }
            break;
    }
}

void AdvanceScrollBarDrag(void) {
    u16 touchPoint[2];
    s32 newOffset;
    s32 maxOffset;
    if (IsTouchDownInRect(&gTouchScreenRect) != 0) {
        GetTouchPoint(touchPoint);
        if (touchPoint[0] >= gScrollBar->mX - 0x1e) {
            newOffset = gScrollBar->mDragStartOffset + (touchPoint[1] - gScrollBar->mDragStartTouch[1]);
            if (newOffset < 0) {
                newOffset = 0;
            } else {
                maxOffset = gScrollBar->mTrackLength - gScrollBarLengths[gScrollBar->mSizeIndex];
                if (newOffset >= maxOffset) {
                    newOffset = maxOffset;
                }
            }
            SetScrollBarDragSound(newOffset);
            PlaceScrollBar(newOffset);
            gScrollBar->mEvent = 2;
            return;
        }
    }
    StopSoundSeq();
    gScrollBar->mState = 0;
    gScrollBar->mEvent = 3;
}

void SetScrollBarDragSound(s32 targetOffset) {
    s32 distance = gScrollBar->mOffset - targetOffset;
    u32 volume;
    u32 pitch;
    if (distance < 0) {
        distance = -distance;
    }
    if (distance < 2) {
        volume = 0;
    } else if (distance < 6) {
        volume = FX_DivS32(0x7f, 6 - distance);
    } else {
        volume = 0x7f;
    }
    SetSoundSeqVolume(volume);
    if (distance < 2) {
        pitch = -0x100;
    } else if (distance < 6) {
        pitch = FX_DivS32(0x200, 6 - distance) - 0x100;
    } else {
        pitch = 0x100;
    }
    SetSoundSeqTrackPitch(0xffff, pitch);
}

void StartScrollBarArrowHold(int arrow) {
    u8 resultCode;
    gScrollBar->mState = (s8) arrow;
    if (arrow == 2) {
        resultCode = 4;
    } else {
        resultCode = 6;
    }
    gScrollBar->mEvent = resultCode;
}

void MoveScrollBarToTouch(void) {
    u16 touchPoint[2];
    u32 barLength;
    s32 newOffset;
    s32 maxOffset;
    GetTouchPoint(touchPoint);
    barLength = gScrollBarLengths[gScrollBar->mSizeIndex];
    newOffset = touchPoint[1] - gScrollBar->mY - (barLength >> 1);
    if (newOffset < 0) {
        newOffset = 0;
    } else {
        maxOffset = gScrollBar->mTrackLength - barLength;
        if (newOffset >= maxOffset) {
            newOffset = maxOffset;
        }
    }
    PlaceScrollBar(newOffset);
    gScrollBar->mEvent = 3;
}

int GetPressedScrollBarPart(void) {
    int v1;
    int pressed;
    u8 partRect[8];
    GetScrollBarPartRect(1, (void *) partRect);
    v1 = IsTouchPressedOrRepeatedInRect((const Rect *) (u16 *) (void *) partRect);
    if (v1 != 0) {
        return 1;
    }
    v1 = 2;
    do {
        GetScrollBarPartRect(v1, (void *) partRect);
        pressed = IsTouchPressedOrRepeatedInRect((const Rect *) (u16 *) (void *) partRect);
        if (pressed != 0) {
            return v1;
        }
        v1 = v1 + 1;
    } while (v1 <= 3);
    GetScrollBarPartRect(4, (void *) partRect);
    v1 = IsTouchPressedInRect((const Rect *) (u16 *) ((u16 *) (void *) partRect));
    if (v1 != 0) {
        return 4;
    }
    return 0;
}

int GetTouchedScrollBarArrow(int a) {
    int touchDown;
    int part;
    u8 partRect[8];
    part = 2;
    do {
        GetScrollBarPartRect(part, (void *) partRect);
        touchDown = IsTouchDownInRect((const Rect *) (u16 *) (void *) partRect);
        if (touchDown != 0) {
            return part;
        }
        part = part + 1;
    } while (part <= 3);
    return 0;
}

void GetScrollBarPartRect(s32 part, u16 *rect) {
    rect[0] = gScrollBar->mX;
    rect[2] = rect[0] + 0xc;
    switch (part) {
        case 1:
            rect[1] = gScrollBar->mY + gScrollBar->mOffset;
            rect[3] = rect[1] + gScrollBarLengths[gScrollBar->mSizeIndex];
            break;
        case 2:
            rect[1] = gScrollBar->mY - 0xd;
            rect[3] = gScrollBar->mY;
            break;
        case 3:
            rect[1] = gScrollBar->mY + gScrollBar->mTrackLength;
            rect[3] = rect[1] + 0xd;
            break;
        case 4:
            rect[1] = gScrollBar->mY;
            rect[3] = rect[1] + gScrollBar->mTrackLength;
            break;
    }
}

void PlaceScrollBar(s32 offset) {
    ScrollBar *state = gScrollBar;
    SetOamRangePosition(state->mResource, -1, state->mX, offset + state->mY);
    gScrollBar->mOffset = offset;
}
