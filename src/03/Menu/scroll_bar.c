#include "03/Menu/scroll_bar.h"

#include "03/Graphics/oam_range_set.h"
#include "03/Graphics/oam_range.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/System/task_input.h"
#include "03/Sound/sound_seq.h"
#include "03/Menu/wifi_menu_strings.h"
#include "fixed_vector_math.h"
#include "sound_player_control.h"
#include "03/System/rect.h"
#include "03/System/exp_heap.h"
#include "03/System/tasks.h"

struct ScrollBar *gScrollBar;

const u8 gScrollBarLengths[3] = {0x55, 0x36, 0x1e};
const u8 gScrollBarImageIds[3] = {0x10, 0xf, 0xe};

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

void AdvanceScrollBar(TaskEntry *task, void *arg) {
    gScrollBar->mEvent = SCROLL_BAR_EVENT_NONE;
    switch (gScrollBar->mState) {
        case SCROLL_BAR_STATE_IDLE:
            if (gScrollBar->mInputDisabled == 0) {
                switch (GetPressedScrollBarPart()) {
                    case SCROLL_BAR_PART_THUMB:
                        if (gScrollBar->mSizeIndex != 0) {
                            StartSoundSeq(0x16);
                            SetSoundSeqVolume(0);
                            gScrollBar->mEvent = SCROLL_BAR_EVENT_THUMB_PRESSED;
                            GetTouchPoint(gScrollBar->mDragStartTouch);
                            gScrollBar->mDragStartOffset = gScrollBar->mOffset;
                            gScrollBar->mState = SCROLL_BAR_STATE_DRAG;
                        }
                        break;
                    case SCROLL_BAR_PART_ARROW_UP:
                        StartScrollBarArrowHold(SCROLL_BAR_PART_ARROW_UP);
                        break;
                    case SCROLL_BAR_PART_ARROW_DOWN:
                        StartScrollBarArrowHold(SCROLL_BAR_PART_ARROW_DOWN);
                        break;
                    case SCROLL_BAR_PART_TRACK:
                        MoveScrollBarToTouch();
                        break;
                }
            }
            break;
        case SCROLL_BAR_STATE_DRAG:
            AdvanceScrollBarDrag();
            break;
        case SCROLL_BAR_STATE_HOLD_ARROW_UP:
            if (GetTouchedScrollBarArrow(SCROLL_BAR_PART_ARROW_UP) != SCROLL_BAR_PART_ARROW_UP) {
                gScrollBar->mEvent = SCROLL_BAR_EVENT_ARROW_UP_RELEASED;
                gScrollBar->mState = SCROLL_BAR_STATE_IDLE;
            } else if (GetPressedScrollBarPart() == SCROLL_BAR_PART_ARROW_UP) {
                StartScrollBarArrowHold(SCROLL_BAR_PART_ARROW_UP);
            }
            break;
        case SCROLL_BAR_STATE_HOLD_ARROW_DOWN:
            if (GetTouchedScrollBarArrow(SCROLL_BAR_PART_ARROW_DOWN) != SCROLL_BAR_PART_ARROW_DOWN) {
                gScrollBar->mEvent = SCROLL_BAR_EVENT_ARROW_DOWN_RELEASED;
                gScrollBar->mState = SCROLL_BAR_STATE_IDLE;
            } else if (GetPressedScrollBarPart() == SCROLL_BAR_PART_ARROW_DOWN) {
                StartScrollBarArrowHold(SCROLL_BAR_PART_ARROW_DOWN);
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
            gScrollBar->mEvent = SCROLL_BAR_EVENT_THUMB_MOVED;
            return;
        }
    }
    StopSoundSeq();
    gScrollBar->mState = SCROLL_BAR_STATE_IDLE;
    gScrollBar->mEvent = SCROLL_BAR_EVENT_OFFSET_SETTLED;
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
        volume = Fx_DivS32(0x7f, 6 - distance);
    } else {
        volume = 0x7f;
    }
    SetSoundSeqVolume(volume);
    if (distance < 2) {
        pitch = -0x100;
    } else if (distance < 6) {
        pitch = Fx_DivS32(0x200, 6 - distance) - 0x100;
    } else {
        pitch = 0x100;
    }
    SetSoundSeqTrackPitch(0xffff, pitch);
}

void StartScrollBarArrowHold(int arrow) {
    u8 resultCode;
    gScrollBar->mState = (s8) arrow;
    if (arrow == SCROLL_BAR_PART_ARROW_UP) {
        resultCode = SCROLL_BAR_EVENT_ARROW_UP_PRESSED;
    } else {
        resultCode = SCROLL_BAR_EVENT_ARROW_DOWN_PRESSED;
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
    gScrollBar->mEvent = SCROLL_BAR_EVENT_OFFSET_SETTLED;
}

int GetPressedScrollBarPart(void) {
    int partIndex;
    int pressed;
    Rect partRect;
    GetScrollBarPartRect(SCROLL_BAR_PART_THUMB, &partRect);
    pressed = IsTouchPressedOrRepeatedInRect((const Rect *) (u16 *) &partRect);
    if (pressed != 0) {
        return SCROLL_BAR_PART_THUMB;
    }
    partIndex = SCROLL_BAR_PART_ARROW_UP;
    do {
        GetScrollBarPartRect(partIndex, &partRect);
        pressed = IsTouchPressedOrRepeatedInRect((const Rect *) (u16 *) &partRect);
        if (pressed != 0) {
            return partIndex;
        }
        partIndex = partIndex + 1;
    } while (partIndex <= SCROLL_BAR_PART_ARROW_DOWN);
    GetScrollBarPartRect(SCROLL_BAR_PART_TRACK, &partRect);
    pressed = IsTouchPressedInRect((const Rect *) (u16 *) ((u16 *) &partRect));
    if (pressed != 0) {
        return SCROLL_BAR_PART_TRACK;
    }
    return 0;
}

int GetTouchedScrollBarArrow(int unusedArg) {
    int touchDown;
    int part;
    Rect partRect;
    part = SCROLL_BAR_PART_ARROW_UP;
    do {
        GetScrollBarPartRect(part, &partRect);
        touchDown = IsTouchDownInRect((const Rect *) (u16 *) &partRect);
        if (touchDown != 0) {
            return part;
        }
        part = part + 1;
    } while (part <= SCROLL_BAR_PART_ARROW_DOWN);
    return 0;
}

void GetScrollBarPartRect(s32 part, Rect *rect) {
    rect->mX = gScrollBar->mX;
    rect->mRight = rect->mX + 0xc;
    switch (part) {
        case SCROLL_BAR_PART_THUMB:
            rect->mY = gScrollBar->mY + gScrollBar->mOffset;
            rect->mBottom = rect->mY + gScrollBarLengths[gScrollBar->mSizeIndex];
            break;
        case SCROLL_BAR_PART_ARROW_UP:
            rect->mY = gScrollBar->mY - 0xd;
            rect->mBottom = gScrollBar->mY;
            break;
        case SCROLL_BAR_PART_ARROW_DOWN:
            rect->mY = gScrollBar->mY + gScrollBar->mTrackLength;
            rect->mBottom = rect->mY + 0xd;
            break;
        case SCROLL_BAR_PART_TRACK:
            rect->mY = gScrollBar->mY;
            rect->mBottom = rect->mY + gScrollBar->mTrackLength;
            break;
    }
}

void PlaceScrollBar(s32 offset) {
    ScrollBar *state = gScrollBar;
    SetOamRangePosition(state->mResource, -1, state->mX, offset + state->mY);
    gScrollBar->mOffset = offset;
}
