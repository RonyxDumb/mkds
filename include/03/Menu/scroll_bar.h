#pragma once

#include "types.h"
#include "03/System/tasks.h"

typedef struct Rect Rect;

// Parts of the bar that can be touched, as returned by GetPressedScrollBarPart (0 = none).
enum {
    SCROLL_BAR_PART_THUMB = 1,
    SCROLL_BAR_PART_ARROW_UP,
    SCROLL_BAR_PART_ARROW_DOWN,
    SCROLL_BAR_PART_TRACK,
};

// Values of ScrollBar.mState; the two hold states have the value of the arrow part being held.
enum {
    SCROLL_BAR_STATE_IDLE,
    SCROLL_BAR_STATE_DRAG,
    SCROLL_BAR_STATE_HOLD_ARROW_UP,
    SCROLL_BAR_STATE_HOLD_ARROW_DOWN,
};

// Values of ScrollBar.mEvent, set by one AdvanceScrollBar call and read through GetScrollBarEvent. OFFSET_SETTLED is
// the end of a drag or a tap on the track.
enum {
    SCROLL_BAR_EVENT_NONE,
    SCROLL_BAR_EVENT_THUMB_PRESSED,
    SCROLL_BAR_EVENT_THUMB_DRAGGED,
    SCROLL_BAR_EVENT_OFFSET_SETTLED,
    SCROLL_BAR_EVENT_ARROW_UP_PRESSED,
    SCROLL_BAR_EVENT_ARROW_UP_RELEASED,
    SCROLL_BAR_EVENT_ARROW_DOWN_PRESSED,
    SCROLL_BAR_EVENT_ARROW_DOWN_RELEASED,
};

// A scroll bar: its screen object, step task, position, drag start, track length, size, thumb offset, state, event of
// the last step and input flag.
typedef struct ScrollBar {
    /* 00 */ struct OamRange *mResource;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ TaskEntry *mTask;
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
void GetScrollBarPartRect(s32 part, Rect *rect);
int GetTouchedScrollBarArrow(int unusedArg);
int GetPressedScrollBarPart(void);
void MoveScrollBarToTouch(void);
void StartScrollBarArrowHold(int arrow);
void SetScrollBarDragSound(s32 targetOffset);
void AdvanceScrollBarDrag(void);
void AdvanceScrollBar(TaskEntry *task, void *arg);
void DisableScrollBarInput(void);
void EnableScrollBarInput(void);
void PlaceScrollBarWrapper(s32 offset);
u8 GetScrollBarEvent(void);
u8 GetScrollBarOffset(void);

extern const u8 gScrollBarImageIds[3];
extern const u8 gScrollBarLengths[3];

extern struct ScrollBar *gScrollBar;
