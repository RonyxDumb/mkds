#pragma once

#include "types.h"
#include "dwc_account.h"
#include "00/code_0218f960.h"

// Login machine, embedded in WiFiConnection at 0x84 (0x264 bytes = the MI_CpuFill8 of InitWiFiLogin), reached through
// gWiFiLogin and stepped by DWCi_LoginProcess in connection state 2. mState 1 waits for the HTTP reply that holds the
// auth token and a second string; 2 to 4 run the GP connect with them (state 2: check the saved record's profile id,
// make the socket, done; state 3 then 4: profile name check in DWCi_GPGetInfoCallback, which can send the machine back
// to state 1); 5 is done. It is not strictly two logins in turn.
typedef struct WiFiLogin {
    /* 00 */ GpConnection *mGpConnection;
    // 0 idle, 1 waiting for the HTTP reply, 2 GP connect for a known profile (success: id check, socket, done), 3 GP
    // connect then 4 profile name check (DWCi_GPGetInfoCallback), 5 done. Written only by the machine; 0 is
    // DWCi_CloseLogin.
    /* 04 */ s32 mState;
    // Game id 0x4d6 (DWC_InitFriendsMatch's fourth parameter): given to GpInitialize, which stores it as
    // GpiConnection.mProductId and writes it after '\productid\'.
    /* 08 */ u32 mProductId;
    /* 0c */ u32 mGamecode;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    // Set by InitWiFiLogin (DWCi_LoginCallback). Called with (error kind, 0, arg) by DWCi_StopLogin and with (0,
    // profile id, arg) when state 2 succeeds.
    /* 18 */ void (*mResultCallback)();
    /* 1c */ void *mResultCallbackArg;
    /* 20 */ DWCAccUserData *mUserData;
    /* 24 */ u8 pad_24[4];
    // Http (0x1a60 bytes; declared void *) of the running request: made by DWCi_RemoteLogin, freed when the reply
    // or an error ends the request and by DWCi_ShutdownLogin.
    /* 28 */ void *mHttp;
    // u64 tick reading (OS_GetTick) taken when the HTTP request started;
    // DWCi_RemoteLoginProcess reports error 2 when (ticks << 6) / 0x82ea, the milliseconds since then, exceeds 10000.
    /* 2c */ u64 mRequestStartTime;
    // TRUE from DWCi_GPConnect until the GP connect callback or an error; DWCi_LoginProcess times the connect
    // out while it is TRUE.
    /* 34 */ BOOL mConnectPending;
    // OS_GetTick reading when the GP connect started; (ticks << 6) / 0x82ea is ms, limit 60000 ms (DWCi_LoginProcess).
    /* 38 */ u64 mConnectStartTime;
    /* 40 */ DWCAccFriendData mTempLoginId;
    // First string of the HTTP reply (0x100 buffer): given to the GP connect as its first credential, which
    // GpiWriteLogin writes after '\authtoken\'; also passed to StartBuddySync (stats login).
    // The reply's second string (mUnk_14c) is the password substitute the library hashes, not
    // the library's '\challenge\' (a random string the library makes).
    /* 4c */ char mAuthToken[0x100];
    // Second string of the HTTP reply (0x100 buffer), the second GP connect credential: GpiStartConnect copies it to
    // q.mUnk_1c2 and GpiWriteLogin hashes it where it would hash the password. Not the
    // library's \challenge\ value.
    /* 14c */ char mPartnerChallenge[0x100];
    /* 24c */ char mUsername[9];
    /* 255 */ char mGsbrcd[0xf];
} WiFiLogin;

// Points at WiFiConnection.mLogin: set by InitWiFiLogin (once per login), set to 0 by DWCi_ShutdownLogin.
extern WiFiLogin *gWiFiLogin;

void DWCi_CloseLogin(void);
