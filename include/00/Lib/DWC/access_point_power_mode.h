#pragma once

#include "types.h"
#include "00/Lib/DWC/access_point_wep_key.h"
#include "wireless_link_control.h"

// Values of ACSL.mApType, ACFL.mApType and ACWORK.mConnectApType: the first three are the saved access point slots by
// their first SSID, the next three by their second SSID.
enum {
    AUTO_CONNECT_AP_TYPE_USER_FIRST_SSID = 0,
    AUTO_CONNECT_AP_TYPE_USER_SECOND_SSID = 3,
    AUTO_CONNECT_AP_TYPE_NWCUSBAP_SSID = 6,
    AUTO_CONNECT_AP_TYPE_NDWCSHAP_SSID_PREFIX,
    AUTO_CONNECT_AP_TYPE_FREESPOT_SSID,
    AUTO_CONNECT_AP_TYPE_WAYPORT2_SSID,
    AUTO_CONNECT_AP_TYPE_NINTENDOWFC_SSID,
};

// Values of ACWORK.mConnectType, which limits the search to one kind of access point; the three saved access point
// slots follow AUTO_CONNECT_TYPE_USER_FIRST in order.
enum {
    AUTO_CONNECT_TYPE_ANY,
    AUTO_CONNECT_TYPE_USER_FIRST,
    AUTO_CONNECT_TYPE_NWCUSBAP_SSID = 4,
    AUTO_CONNECT_TYPE_NDWCSHAP_SSID_PREFIX,
    AUTO_CONNECT_TYPE_FREESPOT_SSID,
    AUTO_CONNECT_TYPE_WAYPORT2_SSID,
    AUTO_CONNECT_TYPE_NINTENDOWFC_SSID,
};

// A scan result of an access point (beacon and duplicate counts, type, channel, SSID) kept in the search list.
typedef struct ACSL {
    /* 00 */ u8 mBeaconReceived : 4;
    /* 00 */ u8 mDuplicateMatch : 4;
    /* 01 */ u8 mApType;
    /* 02 */ u8 mChannel;
    /* 03 */ u8 mSsidLength;
    /* 04 */ u8 mSsid[0x20];
} ACSL;

// Values of ACFL.mState, which picks the error code block of GetNotFoundInet: ERROR_51100 gives -511xx, ERROR_51200
// gives -512xx and any other value -513xx.
enum {
    AUTO_CONNECT_FIND_FAILED = 1,
    AUTO_CONNECT_FIND_TEST_ABORTED = 2,
    AUTO_CONNECT_FIND_ERROR_51100 = 3,
    AUTO_CONNECT_FIND_ERROR_51200,
};

// Values of ACWORK.mConnectResult, set by DWCi_AC_CallBackWCM; ConnectAP reacts to the first three.
enum {
    AUTO_CONNECT_RESULT_NONE,
    AUTO_CONNECT_RESULT_RETRY_AUTH_FALLBACK,
    AUTO_CONNECT_RESULT_ERROR_51100,
    AUTO_CONNECT_RESULT_ERROR_51200,
    AUTO_CONNECT_RESULT_OTHER,
};

// A found access point (state, type, signal strength and channel) kept in the find list.
typedef struct ACFL {
    /* 00 */ u8 mState;
    /* 01 */ u8 mApType;
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
