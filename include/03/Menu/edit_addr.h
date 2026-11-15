#pragma once

#include "types.h"
#include "03/code_021c6764.h"

typedef struct BgTextCanvas BgTextCanvas;
typedef struct OamEntry OamEntry;

// Index of the last of the four three-digit groups of the address text.
#define EDIT_ADDR_LAST_GROUP 3

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
BOOL IsEditAddrGroupFull(s32 groupLimit);
void UpdateEditAddrInput(void);
void UpdateEditAddr(void);
void UpdateEditAddrKeyboardIn(void);
void UpdateEditAddrFadeIn(void);
void StartEditAddrFadeIn(void);
void LoadEditAddrFilesAndSetBgCnt(void);
void CreateEditAddr(void);

extern const u16 gEditAddrCharSize[2];
extern const u8 gEditAddrCharX[12];
extern u8 gEditAddrGroupMax[3];
extern u8 gEditAddrSubScreenMessageIndices[5];
extern u16 gEditAddrCharRect[3];
extern EditAddrTextFuncs gEditAddrFormatFuncs;
extern EditAddrTextFuncs gEditAddrStoreFuncs;
extern struct EditAddr *gEditAddr;
