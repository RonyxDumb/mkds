#pragma once

#include "types.h"

struct ACWORK;

// Bytes handed out by FillApWepKey: a leading byte, then the payload.
typedef struct WCMWepDesc {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[0x50];
} WCMWepDesc;

// One of the 0x100-byte entries at the start of ACWORK.
typedef struct DWCMemPage {
    /* 00 */ u8 pad_00[0x40];
    /* 40 */ u8 mSsid[0x20];
    /* 60 */ u8 mSecondSsid[0x20];
    /* 80 */ u8 mWepKeys[0x40];
    /* c0 */ u8 mIp[4];
    /* c4 */ u8 mGateway[4];
    /* c8 */ u8 mDns1[4];
    /* cc */ u8 mDns2[4];
    /* d0 */ u8 mNetmaskCidr;
    /* d1 */ u8 mWep2[0x14];
    /* e5 */ u8 pad_e5;
    /* e6 */ u8 mWepMode : 2;
    /* e7 */ u8 mSetType;
    /* e8 */ u8 pad_e8[0x18];
} DWCMemPage;

u32 FillApWepKey(struct ACWORK *object, u32 type, WCMWepDesc *out);
