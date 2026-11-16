#pragma once

#include "types.h"
#include "03/Menu/edit_keyboard_row_counts.h"

typedef struct OamEntry OamEntry;
typedef struct OamRange OamRange;
typedef struct TaskEntry TaskEntry;

// Values of EditAddrKeyboard.mInput besides the digit characters: NONE when nothing was pressed this frame, NOT_READY
// until the keyboard has slid in, and the four non-digit keys.
enum {
    EDIT_ADDR_KEYBOARD_INPUT_NONE = 0,
    EDIT_ADDR_KEYBOARD_INPUT_REMOVE_CHAR = 0x10,
    EDIT_ADDR_KEYBOARD_INPUT_NEXT_GROUP,
    EDIT_ADDR_KEYBOARD_INPUT_CANCEL,
    EDIT_ADDR_KEYBOARD_INPUT_OK,
    EDIT_ADDR_KEYBOARD_INPUT_NOT_READY = 0x1f,
};

// Cursor key indexes: the ten digit keys come first (index 1 is the middle key of the top row, 2 its right key), then
// the extra keys and the bottom row.
#define EDIT_ADDR_KEY_TOP_MIDDLE 1
#define EDIT_ADDR_KEY_TOP_RIGHT 2
#define EDIT_ADDR_KEY_REMOVE 10
#define EDIT_ADDR_KEY_NEXT_GROUP 11
#define EDIT_ADDR_KEY_CANCEL 12
#define EDIT_ADDR_KEY_OK 13

// The on-screen keyboard that edits an address: mDigitKeys, mExtraKeys and mRow4Keys, the row texts, mCursor, mInput
// and the pressed, highlighted and cursor key indexes.
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

void ReleaseEditAddrKeyboard(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideOutRow0(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideOutRow1(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideOutRow2(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideOutRow3(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideOutRow4(TaskEntry *task, void *arg);
void MoveEditAddrKeyboardCursor(u32 direction);
void PlaceEditAddrKeyboardCursor(void);
void SetEditAddrKeyboardKeyHighlight(int keyIndex, int highlight);
void SetEditAddrKeyboardRowY(int row, u32 yPos);
void AdvanceEditAddrKeyboardKeys(void);
void ChangeEditAddrKeyboardHighlight(int keyIndex);
void AdvanceEditAddrKeyboardTouchDown(void);
void AdvanceEditAddrKeyboardTouchReleased(void);
void AdvanceEditAddrKeyboardTouchPressed(void);
void AdvanceEditAddrKeyboardInput(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideInRow4(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideInRow3(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideInRow2(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideInRow1(TaskEntry *task, void *arg);
void AdvanceEditAddrKeyboardSlideInRow0(TaskEntry *task, void *arg);
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
extern EditKeyboardRowCounts gEditAddrKeyboardDigitKeyCounts;
extern EditKeyboardRowCounts gEditAddrKeyboardExtraKeyCounts;
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
extern EditKeyboardRowCounts gEditAddrKeyboardRow4KeyCounts;

extern struct EditAddrKeyboard *gEditAddrKeyboard;
