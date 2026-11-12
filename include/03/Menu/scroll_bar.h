#pragma once

#include "types.h"

typedef struct ScrollBar {
    /* 00 */ struct OamRange *mResource;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ u32 mTask;
    /* 10 */ u16 mX;
    /* 12 */ u16 mY;
    /* 14 */ u16 mDragStartTouch[2];
    /* 18 */ u8 mDragStartOffset;
    /* 19 */ u8 mTrackLength;
    /* 1a */ u8 mOffset;
    /* 1b */ u8 mSizeIndex;
    /* 1c */ u8 mState;
    /* 1d */ u8 mEvent;
    /* 1e */ u8 mInputDisabled;
} ScrollBar;

void ReleaseScrollBar(void);
void CreateScrollBar(u32 sizeIndex, u32 trackLength, u16 positionX, u16 positionY, u32 offset);
void PlaceScrollBar(s32 offset);
void GetScrollBarPartRect(s32 part, u16 *rect);
int GetTouchedScrollBarArrow(int a);
int GetPressedScrollBarPart(void);
void MoveScrollBarToTouch(void);
void StartScrollBarArrowHold(int arrow);
void SetScrollBarDragSound(s32 targetOffset);
void AdvanceScrollBarDrag(void);
void AdvanceScrollBar(void);
void DisableScrollBarInput(void);
void EnableScrollBarInput(void);
void PlaceScrollBarWrapper(s32 offset);
u8 GetScrollBarEvent(void);
u8 GetScrollBarOffset(void);

extern const u8 gScrollBarImageIds[3];
extern const u8 gScrollBarLengths[3];

extern struct ScrollBar *gScrollBar;
