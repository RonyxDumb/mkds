#pragma once

#include "types.h"

typedef struct BgTextCanvas BgTextCanvas;
typedef struct OamEntry OamEntry;

typedef struct EditAddr {
    /* 00 */ BgTextCanvas *mBgTextCanvas;
    /* 04 */ OamEntry *mOamEntry;
    /* 08 */ u8 mText[0xc];
    /* 14 */ u8 mGroupIndex;
    /* 15 */ u8 mResult;
} EditAddr;

// Five functions called with the object at 0x08.
typedef struct EditAddrTextFuncs {
    /* 00 */ void (*mUnk_00[5])(u8 *);
} EditAddrTextFuncs;

extern u16 gEditAddrCharSize[];
extern u8 gEditAddrCharX[];
extern u8 gEditAddrGroupMax[];
extern u8 gEditAddrSubScreenMessageIndices[];
extern u16 gEditAddrCharRect[];
extern EditAddrTextFuncs gEditAddrFormatFuncs;
extern EditAddrTextFuncs gEditAddrStoreFuncs;
extern u8 gEditAddrZeroGroupText[];

void UpdateEditAddrInvalidMessageClose(void);
void UpdateEditAddrInvalidMessageResult(void);
BOOL IsEditAddrTextValid(void);
void WriteEditAddrGroupPadding(void);
void UpdateEditAddrMessageClose(void);
void UpdateEditAddrMessageResult(void);
void PlaceEditAddrGroupOam(void);
void PrintEditAddrText(void);
void ReleaseEditAddr(void);
void UpdateEditAddrResult(void);
void UpdateEditAddrSlideOut(void);
void StartEditAddrClose(void);
void UpdateEditAddrNop(void);
BOOL IsEditAddrGroupFull(s32 param_0);
void UpdateEditAddrInput(void);
void UpdateEditAddr(void);
void UpdateEditAddrKeyboardIn(void);
void UpdateEditAddrFadeIn(void);
void StartEditAddrFadeIn(void);
void LoadEditAddrFilesAndSetBgCnt(void);
void CreateEditAddr(void);
