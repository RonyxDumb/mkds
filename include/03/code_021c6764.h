#pragma once

#include "types.h"

typedef struct BgTextCanvas BgTextCanvas;
typedef struct OamEntry OamEntry;

// Values of Edit.mResult and EditAddr.mResult: what the keyboard closed with, then which button of the confirm message
// box was picked.
enum {
    EDIT_RESULT_CANCELED,
    EDIT_RESULT_CONFIRMED,
    EDIT_RESULT_INVALID,
};

typedef struct Edit {
    /* 00 */ BgTextCanvas *mBgTextCanvas;
    /* 04 */ OamEntry *mOamEntry;
    /* 08 */ u8 mText[0x20];
    /* 28 */ u8 mUnk_28;
    /* 29 */ u8 mCharCount;
    /* 2a */ u8 mResult;
} Edit;

BOOL IsEditTextValid(void);
void UpdateEditMessageClose(void);
void UpdateEditMessageResult(void);
void PlaceEditTextCursor(void);
void PrintEditText(void);
void UpdateEditRelease(void);
void UpdateEditKeyboardOut(void);
void UpdateEditFadeOut(void);
void StartEditClose(void);
void UpdateEditNop(void);
void UpdateEditInput(void);
void UpdateEdit(void);
void UpdateEditKeyboardIn(void);
void UpdateEditFadeIn(void);
void StartEditFadeIn(void);
void LoadEditFilesAndSetBgCnt(void);
void CreateEdit(void);
