#include "00/Lib/DWC/code_0219c3e4.h"

#include "00/code_0219c954.h"
#include "00/Lib/DWC/code_0219d128.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c93c.h"
#include "00/code_0219c000.h"
#include "00/Lib/GameSpy/code_0218f15c.h"
#include "00/code_02190000.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/code_02187484.h"
#include "03/Net/essid_wcm.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/code_021a1ae0.h"
#include "os_tick.h"
#include "code_02133048.h"
#include "code_021329f8.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "dwc_account.h"
#include "00/code_0218f000.h"
#include "00/code_0219b000.h"
#include "00/code_0219d000.h"
#include "00/unk_021b4000.h"
#include "code_0200fc8c.h"
#include "00/unk_021b1000.h"
#include "dwc_backup.h"
#include "code_021519d4.h"
#include "00/Lib/DWC/code_02186a9c.h"
#include "00/Lib/CPS/network.h"
#include "00/Lib/NitroWiFi/util.h"
#include "00/Lib/DWC/code_0218a67c.h"
#include "00/Lib/NitroWiFi/cpsif.h"
#include "00/Lib/DWC/code_02185954.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "00/Lib/GameSpy/code_02198a8c.h"
#include "00/Lib/DWC/code_0219b580.h"

void (*stRemoteAuthCallback)();
void *pStRemoteAuthParam;
WiFiLogin *gWiFiLogin;

void DWCi_LoginAsync(void) {
    DWCi_RemoteLogin(DWCi_RemoteAuthCallback, NULL);
    gWiFiLogin->mState = 1;
    gWiFiLogin->mConnectPending = FALSE;
}

// One step per connection frame in state 2 (DWC_ProcessFriendsMatch returns first when an error is pending); mState 1
// runs DWCi_RemoteLoginProcess, 2 to 4 pump GpUpdate and time the GP connect out (60 s), 5 does nothing.
void DWCi_LoginProcess(void) {
    WiFiLogin *wiFiLogin;
    if (gWiFiLogin == NULL || DWCi_IsError() != 0) {
        return;
    }
    wiFiLogin = gWiFiLogin;
    switch (wiFiLogin->mState) {
        case 1:
            DWCi_RemoteLoginProcess();
            break;
        case 2:
        case 3:
        case 4:
            if (wiFiLogin->mGpConnection != NULL && wiFiLogin->mGpConnection->mGpiConnection != NULL) {
                GpUpdate(wiFiLogin->mGpConnection);
            }
            if (gWiFiLogin->mConnectPending != FALSE) {
                if ((((u64) OS_GetTick() - gWiFiLogin->mConnectStartTime) << 6) / 0x82ea > 0xea60) {
                    DWCi_StopLogin(6, -61070);
                    gWiFiLogin->mConnectPending = FALSE;
                }
            }
            break;
        case 5:
            break;
    }
}

DWCAccUserData *DWCi_GetUserData(void) {
    if (gWiFiLogin != NULL) {
        return gWiFiLogin->mUserData;
    }
    return NULL;
}

// Records the (kind, code) pair, calls mResultCallback with the kind and resets the machine (DWCi_CloseLogin); does
// nothing when the object is NULL or the kind is 0. Same extent as DWCi_StopFriendProcess (which closes the stats
// link).
void DWCi_StopLogin(s32 error, s32 errorCode) {
    if (gWiFiLogin != NULL && error != 0) {
        DWCi_SetError(error, errorCode);
        if (gWiFiLogin->mResultCallback != NULL) {
            gWiFiLogin->mResultCallback(error, 0, gWiFiLogin->mResultCallbackArg);
        }
        DWCi_CloseLogin();
    }
}

// Frees the Http (cancel and close the request first) and sets gWiFiLogin to 0; the object itself is part of
// WiFiConnection and is not freed. Called by DWC_ShutdownFriendsMatch; no NULL test of gWiFiLogin.
void DWCi_ShutdownLogin(void) {
    if (gWiFiLogin->mHttp != NULL) {
        DWC_Auth_Abort();
        DWC_Auth_Destroy();
        DWC_Free(0, (u32) gWiFiLogin->mHttp, 0);
        gWiFiLogin->mHttp = NULL;
    }
    *(s32 *) &gWiFiLogin = 0;
}

// Writes the start values back (mState 0, mConnectPending FALSE) when the object exists; called by
// DWCi_StopLogin. Keeps the Http and the strings (DWCi_ShutdownLogin frees the Http).
void DWCi_CloseLogin(void) {
    if (gWiFiLogin != NULL) {
        gWiFiLogin->mState = 0;
        gWiFiLogin->mConnectPending = FALSE;
    }
}

// Maps a GP result code 1 to 4 to (kind 0xb or 6, code -61001, -61002, -61010, -61020) and passes it to
// DWCi_StopLogin (login offset 0xee48 = 61000), returning the result; 0 returns 0 at once. Results above 4 have
// no case.
s32 ReportWiFiLoginGpResult(s32 result) {
    s32 errorKind;
    s32 errorCode;
    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            errorKind = 0xb;
            errorCode = -1;
            break;
        case 2:
            errorKind = 0xb;
            errorCode = -2;
            break;
        case 3:
            errorKind = 6;
            errorCode = -10;
            break;
        case 4:
            errorKind = 6;
            errorCode = -20;
            break;
    }
    DWCi_StopLogin(errorKind, errorCode - 0xee48);
    return result;
}

// Callback of the GP connect, given by DWCi_GPConnect: clears mConnectPending; on success in mState 2 checks
// the saved record's profile id, then (DWCi_GT2Startup, DWCi_QR2Startup with the profile id) sets mState 5 and
// reports success through mResultCallback (id mismatch: error 6); in mState 3 calls GpGetInfo with the
// profile id and DWCi_GPGetInfoCallback as its callback; a GP error goes to ReportWiFiLoginGpResult.
void DWCi_GPConnectCallback(GpConnection *connection, ConnectReply *arg, u32 param) {
    gWiFiLogin->mConnectPending = FALSE;
    if (arg->mResult == 0) {
        if (gWiFiLogin->mState == 2) {
            if (ReportWiFiLoginGpResult(DWCi_SetGPStatus(1, "", NULL)) == 0) {
                if (gWiFiLogin->mUserData->mGsProfileId == arg->mProfile) {
                    if (DWCi_GT2Startup() == 0 && DWCi_QR2Startup(arg->mProfile) == 0) {
                        gWiFiLogin->mState = 5;
                        gWiFiLogin->mResultCallback(0, arg->mProfile, gWiFiLogin->mResultCallbackArg);
                    }
                } else {
                    DWCi_StopLogin(6, -60000);
                }
            }
        } else if (gWiFiLogin->mState == 3) {
            if (ReportWiFiLoginGpResult(GpGetInfo(connection, arg->mProfile, 0, 0, DWCi_GPGetInfoCallback, 0)) != 0) {
                return;
            }
        }
    } else {
        ReportWiFiLoginGpResult(arg->mResult);
    }
}

// The stored done callback of DWCi_RemoteLogin: called through stRemoteAuthCallback with (auth token, second
// string, arg) when the reply is in hand and after the profile check; ignores arg and
// starts the GP connect with state 2 (DWCi_GPConnect with DWCi_GPConnectCallback).
void DWCi_RemoteAuthCallback(char *authToken, char *partnerChallenge) {
    DWCi_GPConnect(authToken, partnerChallenge, DWCi_GPConnectCallback, 2);
}

// Copies the token and the second string, sets mConnectStartTime and mConnectPending, starts the GP connect
// (GpConnectPreAuthenticatedA) with callback c, reporting a failed start through ReportWiFiLoginGpResult, and only when
// it started sets mState to d (2 from DWCi_RemoteAuthCallback, 3 from DWCi_RemoteLoginProcess); DWCi_LoginProcess then
// pumps GpUpdate and times the connect out.
void DWCi_GPConnect(char *authToken, char *partnerChallenge, void (*callback)(), s32 targetState) {
    WiFiLogin *wiFiLogin;
    u32 loginResult;
    u64 connectTick;
    WiFiLogin *loginObject;
    strcpy(gWiFiLogin->mAuthToken, authToken);
    strcpy(gWiFiLogin->mPartnerChallenge, partnerChallenge);
    loginObject = gWiFiLogin;
    connectTick = OS_GetTick();
    loginObject->mConnectStartTime = connectTick;
    loginObject->mConnectPending = TRUE;
    wiFiLogin = gWiFiLogin;
    loginResult = ReportWiFiLoginGpResult(GpConnectPreAuthenticatedA(wiFiLogin->mGpConnection, wiFiLogin->mAuthToken,
                                                                  wiFiLogin->mPartnerChallenge, 1, 0, callback, 0));
    if (loginResult == 0) {
        gWiFiLogin->mState = targetState;
    }
}

// Stores the done callback and its argument in two globals (stRemoteAuthCallback / pStRemoteAuthParam), formats the
// login id text (from the saved record's id, or from a 12-byte id it takes or makes), allocates the Http (0x1a60),
// records the start time and issues the request; DWCi_RemoteLoginProcess polls the reply. Called by DWCi_LoginAsync
// and by the profile check DWCi_GPGetInfoCallback, which restarts the request.
void DWCi_RemoteLogin(void (*callback)(), void *param) {
    AuthCreateParams authParams;
    void *httpBlock;
    u64 startTick;
    MI_CpuFill8(&authParams, 0, 0x2c);
    stRemoteAuthCallback = callback;
    pStRemoteAuthParam = param;
    if (DWCi_Acc_IsAuthentic(gWiFiLogin->mUserData) != 0) {
        DWCi_Acc_LoginIdToUserName(&gWiFiLogin->mUserData->mAuthentic, gWiFiLogin->mUserData->mGamecode,
                                   gWiFiLogin->mUsername);
    } else {
        if (IsFriendDataLoginId(&gWiFiLogin->mTempLoginId) == 0) {
            if (DWCi_Acc_CheckConsoleUserId(&gWiFiLogin->mUserData->mPseudo) != 0) {
                gWiFiLogin->mTempLoginId = gWiFiLogin->mUserData->mPseudo;
            } else {
                DWCi_Acc_CreateTempLoginId(&gWiFiLogin->mTempLoginId);
            }
        } else {
            DWCi_Acc_SetPlayerId(&gWiFiLogin->mTempLoginId, ((s64) OS_GetTick() * 0x5d588b656c078965 + 0x269ec3) >> 32);
        }
        DWCi_Acc_LoginIdToUserName(&gWiFiLogin->mTempLoginId, gWiFiLogin->mGamecode, gWiFiLogin->mUsername);
    }
    strcpy(authParams.mGsbrcd, gWiFiLogin->mGsbrcd);
    authParams.mAlloc = (void *(*) (const void *, u32)) DWC_Alloc;
    authParams.mFree = (void (*)(const void *, void *, u32)) DWC_Free;
    httpBlock = DWC_AllocEx(0, 0x1a60, 4);
    gWiFiLogin->mHttp = httpBlock;
    startTick = OS_GetTick();
    gWiFiLogin->mRequestStartTime = startTick;
    DWC_Auth_Create(&authParams, httpBlock);
}

// State 1 step of DWCi_LoginProcess (every frame while mState is 1): when the reply is done (status 0x14) copies the
// token and the second string, frees the Http and goes on through the stored callback (when DWCi_Acc_IsAuthentic
// accepts the saved record) or DWCi_GPConnect with state 3; while the request runs, reports error 2 after 10
// s, otherwise closes it and issues it again.
void DWCi_RemoteLoginProcess(void) {
    AuthCreateParams authParams;
    DWCAuthResult authResult;
    DWCAuthResult failedAuthResult;
    if (DWC_Auth_GetError() == 0x14) {
        DWC_Auth_GetResult(&authResult.mReturnCode);
        strcpy(gWiFiLogin->mAuthToken, authResult.mToken);
        strcpy(gWiFiLogin->mPartnerChallenge, authResult.mChallenge);
        DWC_Auth_Destroy();
        DWC_Free(0, (u32) gWiFiLogin->mHttp, 0);
        gWiFiLogin->mHttp = NULL;
        if (DWCi_Acc_IsAuthentic(gWiFiLogin->mUserData) != 0) {
            stRemoteAuthCallback(gWiFiLogin->mAuthToken, gWiFiLogin->mPartnerChallenge, pStRemoteAuthParam);
        } else {
            DWCi_GPConnect(gWiFiLogin->mAuthToken, gWiFiLogin->mPartnerChallenge, DWCi_GPConnectCallback, 3);
        }
    } else if (DWC_Auth_GetError() != 0) {
        if ((((u64) OS_GetTick() - gWiFiLogin->mRequestStartTime) << 6) / 0x82ea > 0x2710) {
            DWC_Auth_GetResult(&failedAuthResult.mReturnCode);
            DWC_Auth_Destroy();
            DWC_Free(0, (u32) gWiFiLogin->mHttp, 0);
            gWiFiLogin->mHttp = NULL;
            DWCi_StopLogin(2, failedAuthResult.mReturnCode);
        } else {
            DWC_Auth_Destroy();
            MI_CpuFill8(&authParams, 0, 0x2c);
            strcpy(authParams.mGsbrcd, gWiFiLogin->mGsbrcd);
            authParams.mAlloc = (void *(*) (const void *, u32)) DWC_Alloc;
            authParams.mFree = (void (*)(const void *, void *, u32)) DWC_Free;
            DWC_Auth_Create(&authParams, gWiFiLogin->mHttp);
        }
    }
}

void DWCi_GPGetInfoCallback(GpConnection *connection, GetInfoReply *arg, u32 param) {
    char lastNameToSet[0x15];
    char accountName[0x15];
    char tempUserName[0x15];
    WiFiLogin *wiFiLogin;
    if (arg->mResult != 0) {
        return;
    }
    wiFiLogin = gWiFiLogin;
    if (wiFiLogin->mState == 3) {
        if ((s8) arg->mLastname[0] == 0) {
            DWCi_Acc_LoginIdToUserName(&wiFiLogin->mUserData->mPseudo, wiFiLogin->mGamecode, lastNameToSet);
            if (ReportWiFiLoginGpResult(GpSetInfosA(connection, 0x705, (const s8 *) lastNameToSet)) == 0) {
                gWiFiLogin->mState = 4;
                if (ReportWiFiLoginGpResult(GpGetInfo(connection, arg->mProfile, 0, 0, DWCi_GPGetInfoCallback, 0)) !=
                    0) {
                    return;
                }
            }
        } else {
            GpDisconnect(connection);
            DWCi_RemoteLogin(DWCi_RemoteAuthCallback, NULL);
            gWiFiLogin->mState = 1;
        }
    } else if (wiFiLogin->mState == 4) {
        DWCi_Acc_LoginIdToUserName(&wiFiLogin->mUserData->mPseudo, wiFiLogin->mGamecode, accountName);
        if (strcmp(arg->mLastname, accountName) == 0) {
            DWCi_Acc_LoginIdToUserName(&gWiFiLogin->mTempLoginId, gWiFiLogin->mGamecode, tempUserName);
            DWCi_Acc_SetLoginIdToUserData(gWiFiLogin->mUserData, &gWiFiLogin->mTempLoginId, arg->mProfile);
            GpDisconnect(connection);
            stRemoteAuthCallback(gWiFiLogin->mAuthToken, gWiFiLogin->mPartnerChallenge, pStRemoteAuthParam);
        } else {
            if (ReportWiFiLoginGpResult(GpGetInfo(connection, arg->mProfile, 0, 0, DWCi_GPGetInfoCallback, 0)) != 0) {
                return;
            }
        }
    }
}

// 1 only in mState 5 (set on success by DWCi_GPConnectCallback), 0 when the object is NULL; the buddy sync gates on
// it and DWC_DeleteBuddyFriendData tests it.
u32 DWCi_CheckLogin(void) {
    if ((gWiFiLogin != NULL) && (gWiFiLogin->mState == 5)) {
        return 1;
    }
    return 0;
}
