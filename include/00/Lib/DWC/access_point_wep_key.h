#pragma once

#include "types.h"

struct ACWORK;

// WEP key description for WCM_ConnectAsync: mMode, mKeyId and the key bytes mKey; FillApWepKey fills mMode and mKey.
typedef struct WCMWepDesc {
    /* 00 */ u8 mMode;
    /* 01 */ u8 mKeyId;
    /* 02 */ u8 mKey[0x50];
} WCMWepDesc;

// One saved connection entry: ISP login, SSIDs, WEP keys and the IP, gateway and DNS addresses.
typedef struct DWCMemPage {
    /* 00 */ u8 mIspId[0x20];
    /* 20 */ u8 mIspPass[0x20];
    /* 40 */ u8 mSsids[2][0x20];
    /* 80 */ u8 mWepKeys[0x40];
    /* c0 */ u8 mIp[4];
    /* c4 */ u8 mGateway[4];
    /* c8 */ u8 mDns1[4];
    /* cc */ u8 mDns2[4];
    /* d0 */ u8 mNetmaskCidr;
    /* d1 */ u8 mWep2Keys[4][5];
    /* e5 */ u8 mAuthType;
    /* e6 */ u8 mWepMode : 2;
    /* e7 */ u8 mSetType;
    /* e8 */ u8 pad_e8[0x18];
} DWCMemPage;

u32 FillApWepKey(struct ACWORK *object, u32 type, WCMWepDesc *out);
