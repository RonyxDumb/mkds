#pragma once

#include "types.h"
#include "code_02142eac.h"

// Entry of the table at offset 0x1300 of an ApScan.
typedef struct ApScanEntry {
    /* 00 */ u8 mSsid[0x20];
    /* 20 */ u8 mBssid[6];
    /* 26 */ u16 mLinkLevel;
    /* 28 */ u8 mCapaLevel;
} ApScanEntry;

// 0x44 bytes: InitApScan copies them from gApScanParamTemplate; the first 0x38 bytes are the object
// WM_StartScanEx takes.
typedef struct ScanParamBlock {
    /* 00 */ ScanExParam mScanExParam;
    /* 38 */ u8 mUnk_38[0xc];
} ScanParamBlock;

// Object that gApScan points to (0x1e60 bytes).
typedef struct ApScan {
    /* 0000 */ u8 mUnk_0000[0xf00];
    /* 0f00 */ u8 mScanBuf[0x400];
    /* 1300 */ ApScanEntry mEntries[0x14];
    /* 1648 */ ScanParamBlock mScanParam;
    /* 168c */ WMStatus mStatus;
    /* 1e48 */ u8 mStopRequested;
    /* 1e49 */ u8 mUnk_1e49[0x17];
} ApScan;
