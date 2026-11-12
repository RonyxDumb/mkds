#pragma once

#include "types.h"

typedef struct OamEntry OamEntry;
typedef struct OamRange OamRange;
typedef struct TaskEntry TaskEntry;

// Object behind gEditAddrKeyboard.
typedef struct EditAddrKeyboard {
    /* 00 */ void *mRowTexts[4];
    /* 10 */ OamEntry *mDigitKeys[10];
    /* 38 */ OamEntry *mExtraKeys[2];
    /* 40 */ OamRange *mRow4Keys[2];
    /* 48 */ OamRange *mRowTextRanges[4];
    /* 58 */ struct OamRange *mCursor;
    /* 5c */ TaskEntry *mStepTask;
    /* 60 */ u8 mInput;
    /* 61 */ s8 mPressedKeyIndex;
    /* 62 */ s8 mHighlightedKeyIndex;
    /* 63 */ s8 mCursorKeyIndex;
    /* 64 */ s8 mPreviousKeyIndex;
    /* 65 */ u8 mRepeatCalls;
    /* 66 */ u8 mRemoveCharEnabled;
    /* 67 */ u8 mAddCharEnabled;
    /* 68 */ u8 mNextGroupEnabled;
    /* 69 */ u8 mRemoveDisabledSoundPlayed;
} EditAddrKeyboard;

// Five bytes moved as one value.
typedef struct EditKeyboardRowCounts {
    /* 0 */ u8 mUnk_00[5];
} EditKeyboardRowCounts;

void ReleaseEditAddrKeyboard(u32 task);
void AdvanceEditAddrKeyboardSlideOutRow0(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideOutRow1(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideOutRow2(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideOutRow3(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideOutRow4(TaskEntry *task);
void MoveEditAddrKeyboardCursor(u32 direction);
void PlaceEditAddrKeyboardCursor(void);
void SetEditAddrKeyboardKeyHighlight(int keyIndex, int highlight);
void SetEditAddrKeyboardRowY(int row, u32 yPos);
void AdvanceEditAddrKeyboardKeys(void);
void ChangeEditAddrKeyboardHighlight(int keyIndex);
void AdvanceEditAddrKeyboardTouchDown(void);
void AdvanceEditAddrKeyboardTouchReleased(void);
void AdvanceEditAddrKeyboardTouchPressed(void);
void AdvanceEditAddrKeyboardInput(void);
void AdvanceEditAddrKeyboardSlideInRow4(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideInRow3(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideInRow2(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideInRow1(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideInRow0(TaskEntry *task);
BOOL HasEditAddrKeyboard(void);
void SetEditAddrKeyboardNextGroupEnabled(u8 canNextGroup);
void SetEditAddrKeyboardAddCharEnabled(u8 canAdd);
void SetEditAddrKeyboardRemoveCharEnabled(u8 canRemove);
u8 GetEditAddrKeyboardInput(void);
void StartEditAddrKeyboardSlideOut(void);
void CreateEditAddrKeyboard(void);

extern const u16 gEditAddrKeyboardDigitKeyPositions[10][2];
extern const u16 gEditAddrKeyboardKeyTexts[13];
extern const u8 gEditAddrKeyboardRow4KeyInputs[2];
extern u8 gEditAddrKeyboardDigitKeyCounts[5];
extern u8 gEditAddrKeyboardExtraKeyCounts[5];
extern u16 gEditAddrKeyboardTextRectStart[4];
extern const u8 gEditAddrKeyboardKeyPalettes[2];
extern const u8 gEditAddrKeyboardRow4KeyImages[2];
// Interleaved x and y positions of the cursor.
extern const u16 gEditAddrKeyboardCursorX[28];
extern const u16 gEditAddrKeyboardRow4KeyPositions[2][2];
extern const u16 gEditAddrKeyboardExtraKeySize[2];
extern const s8 gEditAddrKeyboardCursorMoves[56];
extern const u8 gEditAddrKeyboardDigitInputs[10];
extern const u8 gEditAddrKeyboardExtraKeyInputs[2];
extern const u16 gEditAddrKeyboardExtraKeyPositions[2][2];
extern const u8 gEditAddrKeyboardRow4HighlightValues[2];
extern const u16 gEditAddrKeyboardRowTextAreaSize[2];
extern const u8 gEditAddrKeyboardExtraKeyImages[2];
extern const u16 gEditAddrKeyboardDigitKeySize[2];
extern const u16 gEditAddrKeyboardRow4KeySize[2];
extern u8 gEditAddrKeyboardRow4KeyCounts[5];

extern struct EditAddrKeyboard *gEditAddrKeyboard;
