#pragma once

#include "types.h"

struct WLMenuScene;

// Table of four functions that member 0x80c of WLMenuScene points to.
typedef struct WLMenuCallbacks {
    /* 00 */ void (*field0)(void *a, struct WLMenuScene *b, void *c);
    /* 04 */ s32 (*field4)(void *a);
    /* 08 */ void (*field8)(void);
    /* 0c */ void (*fieldC)(void);
} WLMenuCallbacks;

// 0x16-byte entries from 4 of Unk02174e4c_818.
typedef struct Unk02174e4c_818_04 {
    /* 00 */ u16 field0[0xa];
    /* 14 */ u16 field14;
} Unk02174e4c_818_04;

// The 0x5c bytes at 0x818 of WLMenuScene.
typedef struct Unk02174e4c_818 {
    /* 00 */ s32 field0;
    /* 04 */ Unk02174e4c_818_04 field4[4];
} Unk02174e4c_818;

// 0x874-byte object that gWLMenuScene points to.
typedef struct WLMenuScene {
    /* 000 */ u8 mMainOam[0x404];
    /* 404 */ u8 mSubOam[0x404];
    /* 808 */ void *mHeap;
    /* 80c */ WLMenuCallbacks *mCurrentCallbacks;
    /* 810 */ s32 mRequestedCallbacksIndex;
    /* 814 */ s32 mCurrentCallbacksIndex;
    /* 818 */ Unk02174e4c_818 field818;
} WLMenuScene;

Unk02174e4c_818 *func_0202f14c(void);
void func_0202f160(void);
u32 j_IsDwc_2(void);
u32 IsDwc_2(void);
u16 *GetBiosBootIndicatorRef(void);
void EndMultiplayerMenu(void);
void AdvanceWLMenuScene(void *a);
void InitWLMenuScene(void *heap);
void SetSomeDispcntSubMask(u32 bits);
void SetSomeDispcntTopMask(u32 bits);
