#pragma once

#include "types.h"
#include "00/code_02188de4.h"
#include "code_02142eac.h"

// Entries of 0x24 bytes at 0x300 of ACWORK.
typedef struct ACSL {
    /* 00 */ u8 mUnk_00_lo : 4;
    /* 00 */ u8 mDuplicateMatch : 4;
    /* 01 */ u8 mApType;
    /* 02 */ u8 mChannel;
    /* 03 */ u8 mSsidLength;
    /* 04 */ u8 mSsid[0x20];
} ACSL;

// Entries of 4 bytes at 0x444 of ACWORK.
typedef struct ACFL {
    /* 00 */ u8 mState;
    /* 01 */ u8 pad_01;
    /* 02 */ u8 mRssi;
    /* 03 */ u8 mChannel;
} ACFL;

typedef struct ACWORK {
    /* 000 */ DWCMemPage mUserInfo[3];
    /* 300 */ ACSL mSearchList[9];
    /* 444 */ ACFL mFindList[11];
    /* 470 */ WMBssDesc mBssDesc[11];
    /* cb0 */ u64 mTimeOut;
    /* cb8 */ WCMWepDesc mWepKey;
    /* d0a */ u8 mDmaNo;
    /* d0b */ u8 mPowerMode : 2;
    /* d0b */ u8 mAuthMode : 2;
    /* d0b */ u8 mAroundCount : 4;
    /* d0c */ u8 mConnectType : 4;
    /* d0c */ u8 mSkipNetCheck : 2;
    /* d0c */ u8 mDuplicateFlag : 2;
    /* d0d */ u8 mConnectApType;
    /* d0e */ u8 mPhaseBak;
    /* d0f */ u8 mSearchListNo;
    /* d10 */ u8 mSearchListNum;
    /* d11 */ s8 mSearchChannel;
    /* d12 */ u8 mFindListNum;
    /* d13 */ u8 mConnectNo;
    /* d14 */ u8 mConnectResult;
    /* d15 */ u8 mCount;
    /* d16 */ u16 mStealthChannel;
} ACWORK;

u32 GetPowerMode(ACWORK *work);
