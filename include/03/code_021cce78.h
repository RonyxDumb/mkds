#pragma once

#include "types.h"
#include "03/code_021cca74.h"
#include "03/types_021da26c.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"
#include "code_02142eac.h"

// Object found through the pointers at 0x10 of an WMStartScanExCallback.
typedef struct Unk021ccf30_10 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u8 mUnk_04[6];
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ u8 mUnk_0c[0x20];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u8 mUnk_2e[0xe];
    /* 3c */ u16 mUnk_3c;
} Unk021ccf30_10;

typedef struct WMStartScanExCallback {
    /* 00 */ u8 mUnk_00[0xe];
    /* 0e */ u16 mBssDescCount;
    /* 10 */ Unk021ccf30_10 *mBssDesc[0x10];
    /* 50 */ u16 mLinkLevel[0x10];
} WMStartScanExCallback;

extern u8 gScrollBarImageIds[];
extern u8 gOtherElementPrefix[];

void ReleaseScrollBar(void);
void CreateScrollBar(u32 sizeIndex, u32 trackLength, u16 positionX, u16 positionY, u32 offset);
void StoreApScanEntries(WMStartScanExCallback *scanResult);
void ApScanCallback(Unk021425e8 *message);
