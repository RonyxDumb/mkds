#pragma once

#include "types.h"

typedef struct BgTextCanvas BgTextCanvas;
typedef struct OamEntry OamEntry;

typedef struct Edit {
    /* 00 */ BgTextCanvas *mBgTextCanvas;
    /* 04 */ OamEntry *mOamEntry;
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
