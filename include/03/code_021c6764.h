#pragma once

#include "types.h"

typedef struct BgTextCanvas BgTextCanvas;

// Object at 0x04 of Edit.
typedef struct Unk021da1f8_04 {
    /* 00 */ u32 mAttr01;
    /* 04 */ u16 mAttr2;
} Unk021da1f8_04;

typedef struct Edit {
    /* 00 */ BgTextCanvas *mBgTextCanvas;
    /* 04 */ Unk021da1f8_04 *mOamEntry;
    /* 08 */ u8 mText[0x20];
    /* 28 */ u8 mUnk_28;
    /* 29 */ u8 mCharCount;
    /* 2a */ u8 mResult;
} Edit;

extern u8 gEditLineY[];
extern u16 gEditCharSize[];
extern u8 gEditColumnX[];
extern u8 gEditSubScreenMessages[];

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
