#pragma once

#include "types.h"
#include "03/Menu/scroll_bar.h"
#include "03/types_021da26c.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"
#include "code_02142eac.h"

typedef struct WMStartScanExCallback {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mErrcode;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mState;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mBssDescCount;
    /* 10 */ WMBssDesc *mBssDesc[0x10];
    /* 50 */ u16 mLinkLevel[0x10];
} WMStartScanExCallback;

extern u8 gScrollBarImageIds[];
extern u8 gOtherElementPrefix[];

void ReleaseScrollBar(void);
void CreateScrollBar(u32 sizeIndex, u32 trackLength, u16 positionX, u16 positionY, u32 offset);
void StoreApScanEntries(WMStartScanExCallback *scanResult);
void ApScanCallback(Unk021425e8 *message);
