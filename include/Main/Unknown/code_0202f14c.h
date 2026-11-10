#pragma once

#include "types.h"

struct WLMenuScene;

// Table of four functions that member 0x80c of WLMenuScene points to.
typedef struct WLMenuCallbacks {
    /* 00 */ void (*mInit)(void *a, struct WLMenuScene *b, void *c);
    /* 04 */ s32 (*mAdvance)(void *a);
    /* 08 */ void (*mRelease)(void);
    /* 0c */ void (*mWriteRegisters)(void);
} WLMenuCallbacks;

// 0x16-byte entries from 4 of WLMenuScanSlotPick.
typedef struct ScanSlotText {
    /* 00 */ u16 mText[0xa];
    /* 14 */ u16 mTerminator;
} ScanSlotText;

// The 0x5c bytes at 0x818 of WLMenuScene.
typedef struct WLMenuScanSlotPick {
    /* 00 */ s32 mSlotIndex;
    /* 04 */ ScanSlotText mSlotTexts[4];
} WLMenuScanSlotPick;

// 0x874-byte object that gWLMenuScene points to.
typedef struct WLMenuScene {
    /* 000 */ u8 mMainOam[0x404];
    /* 404 */ u8 mSubOam[0x404];
    /* 808 */ void *mHeap;
    /* 80c */ WLMenuCallbacks *mCurrentCallbacks;
    /* 810 */ s32 mRequestedCallbacksIndex;
    /* 814 */ s32 mCurrentCallbacksIndex;
    /* 818 */ WLMenuScanSlotPick mScanSlotPick;
} WLMenuScene;

WLMenuScanSlotPick *GetWLMenuSceneScanSlotPick(void);
void WriteWLMenuSceneRegisters(void);
u32 func_0202f19c(void);
u32 func_0202f1a8(void);
u16 *func_0202f1d0(void);
void ReleaseWLMenuScene(void);
void AdvanceWLMenuScene(void *a);
void InitWLMenuScene(void *heap);
void func_0202f454(u32 bits);
void func_0202f478(u32 bits);
