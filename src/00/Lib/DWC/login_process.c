#include "00/Lib/DWC/friend_status.h"
#include "00/Lib/GameSpy/profile_info_set.h"
#include "00/Lib/DWC/matching_result_codes.h"
#include "00/Lib/DWC/login_process.h"

#include "00/Lib/DWC/login_control.h"
#include "00/Lib/DWC/buddy_friends.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/login_state.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/DWC/network_check_status.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/DWC/match_init.h"
#include "tick_counter.h"
#include "signed_int_divide.h"
#include "float_subtract_int64_muldiv.h"
#include "narrow_string_functions.h"
#include "cpu_copy_fill.h"
#include "friend_data_account_fields.h"
#include "00/Lib/GameSpy/preauthenticated_connect.h"
#include "00/Lib/wifi_library_globals.h"
#include "reset_interrupts_halt.h"
#include "00/Lib/DWC/auth_http_params.h"
#include "wifi_settings_nvram_backup.h"
#include "wifi_id_and_backup_check.h"
#include "00/Lib/DWC/http_header_build.h"
#include "00/Lib/CPS/tcp_ip_stack.h"
#include "00/Lib/NitroWiFi/rssi_link_level.h"
#include "00/Lib/DWC/shop_access_point_key.h"
#include "00/Lib/NitroWiFi/wifi_stack_bridge.h"
#include "00/Lib/DWC/server_auth.h"
#include "00/Lib/DWC/error_state.h"
#include "00/Lib/GameSpy/protocol_messages.h"
#include "00/Lib/DWC/friends_match_session.h"

void (*stRemoteAuthCallback)();
void *pStRemoteAuthParam;
WiFiLogin *gWiFiLogin;

void DWCi_LoginAsync(void) {
    DWCi_RemoteLogin(DWCi_RemoteAuthCallback, NULL);
    gWiFiLogin->mState = WIFI_LOGIN_WAIT_AUTH_REPLY;
    gWiFiLogin->mConnectPending = FALSE;
}

// One step per frame while WiFiConnection.mState is 2 (DWC_ProcessFriendsMatch returns first when an error is pending);
// WiFiLogin.mState 1 runs DWCi_RemoteLoginProcess, 2 to 4 call gpProcess when the GP connection exists and, while
// mConnectPending is set, stop the login with error 6 after 60 s; 0 and 5 do nothing.
void DWCi_LoginProcess(void) {
    WiFiLogin *wiFiLogin;
    if (gWiFiLogin == NULL || DWCi_IsError() != 0) {
        return;
    }
    wiFiLogin = gWiFiLogin;
    switch (wiFiLogin->mState) {
        case WIFI_LOGIN_WAIT_AUTH_REPLY:
            DWCi_RemoteLoginProcess();
            break;
        case WIFI_LOGIN_CONNECT_KNOWN_ID:
        case WIFI_LOGIN_CONNECT_NEW_ID:
        case WIFI_LOGIN_CHECK_NEW_ID_NAME:
            if (wiFiLogin->mGpConnection != NULL && wiFiLogin->mGpConnection->mGpiConnection != NULL) {
                gpProcess(wiFiLogin->mGpConnection);
            }
            if (gWiFiLogin->mConnectPending != FALSE) {
                if ((((u64) OS_GetTick() - gWiFiLogin->mConnectStartTime) << 6) / 0x82ea > 0xea60) {
                    DWCi_StopLogin(6, -61070);
                    gWiFiLogin->mConnectPending = FALSE;
                }
            }
            break;
        case WIFI_LOGIN_DONE:
            break;
    }
}

DWCAccUserData *DWCi_GetUserData(void) {
    if (gWiFiLogin != NULL) {
        return gWiFiLogin->mUserData;
    }
    return NULL;
}

// Records the (kind, code) pair with DWCi_SetError, calls mResultCallback (when set) with (kind, 0,
// mResultCallbackArg), then resets the machine with DWCi_CloseLogin; does nothing when gWiFiLogin is NULL or the kind
// is 0.
void DWCi_StopLogin(s32 error, s32 errorCode) {
    if (gWiFiLogin != NULL && error != 0) {
        DWCi_SetError(error, errorCode);
        if (gWiFiLogin->mResultCallback != NULL) {
            gWiFiLogin->mResultCallback(error, 0, gWiFiLogin->mResultCallbackArg);
        }
        DWCi_CloseLogin();
    }
}

// Frees the Http when there is one (DWC_Auth_Abort and DWC_Auth_Destroy first) and sets gWiFiLogin to NULL; the object
// itself is part of WiFiConnection and is not freed. Called by DWC_ShutdownFriendsMatch; no NULL test of gWiFiLogin.
void DWCi_ShutdownLogin(void) {
    if (gWiFiLogin->mHttp != NULL) {
        DWC_Auth_Abort();
        DWC_Auth_Destroy();
        DWC_Free(0, gWiFiLogin->mHttp, 0);
        gWiFiLogin->mHttp = NULL;
    }
    gWiFiLogin = NULL;
}

// Writes the start values back (mState 0, mConnectPending FALSE) when the object exists; called by
// DWCi_StopLogin. Keeps the Http and the strings (DWCi_ShutdownLogin frees the Http).
void DWCi_CloseLogin(void) {
    if (gWiFiLogin != NULL) {
        gWiFiLogin->mState = WIFI_LOGIN_IDLE;
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
        case PROFILE_RESULT_OUT_OF_MEMORY:
            errorKind = 0xb;
            errorCode = -1;
            break;
        case PROFILE_RESULT_BAD_PARAMETER:
            errorKind = 0xb;
            errorCode = -2;
            break;
        case PROFILE_RESULT_NETWORK_ERROR:
            errorKind = 6;
            errorCode = -10;
            break;
        case PROFILE_RESULT_SERVER_ERROR:
            errorKind = 6;
            errorCode = -20;
            break;
    }
    DWCi_StopLogin(errorKind, errorCode - 0xee48);
    return result;
}

// Callback of the GP connect (DWCi_GPConnect hands it to GpConnectPreAuthenticatedA): clears mConnectPending; on
// success in mState 2 first sets the GP status online, then checks the saved record's profile id and, only when
// DWCi_GT2Startup and DWCi_QR2Startup with the profile id both return 0, sets mState 5 and reports success through
// mResultCallback (id mismatch: error 6); on success in mState 3 calls GpGetInfo with the profile id and
// DWCi_GPGetInfoCallback; a GP error goes to ReportWiFiLoginGpResult.
void DWCi_GPConnectCallback(GPConnection *connection, ConnectReply *arg, u32 param) {
    gWiFiLogin->mConnectPending = FALSE;
    if (arg->mResult == PROFILE_REQUEST_OK) {
        if (gWiFiLogin->mState == WIFI_LOGIN_CONNECT_KNOWN_ID) {
            if (ReportWiFiLoginGpResult(DWCi_SetGPStatus(FRIEND_STATUS_ONLINE, "", NULL)) == 0) {
                if (gWiFiLogin->mUserData->mGsProfileId == arg->mProfile) {
                    if (DWCi_GT2Startup() == 0 && DWCi_QR2Startup(arg->mProfile) == 0) {
                        gWiFiLogin->mState = WIFI_LOGIN_DONE;
                        gWiFiLogin->mResultCallback(0, arg->mProfile, gWiFiLogin->mResultCallbackArg);
                    }
                } else {
                    DWCi_StopLogin(6, -60000);
                }
            }
        } else if (gWiFiLogin->mState == WIFI_LOGIN_CONNECT_NEW_ID) {
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
    DWCi_GPConnect(authToken, partnerChallenge, DWCi_GPConnectCallback, WIFI_LOGIN_CONNECT_KNOWN_ID);
}

// Copies authToken and partnerChallenge, sets mConnectStartTime and mConnectPending, starts the GP connect
// (GpConnectPreAuthenticatedA) with callback, reporting a failed start through ReportWiFiLoginGpResult, and only when
// it started sets mState to targetState (WIFI_LOGIN_CONNECT_KNOWN_ID from DWCi_RemoteAuthCallback,
// WIFI_LOGIN_CONNECT_NEW_ID from DWCi_RemoteLoginProcess); DWCi_LoginProcess then pumps gpProcess and times the connect
// out.
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
// login id text (from the saved record's id when DWCi_Acc_IsAuthentic accepts it, otherwise from mTempLoginId, which it
// fills from the pseudo id or a new id, or gives a new player id when it already holds one), allocates the Http
// (0x1a60), records the start time and issues the request; DWCi_RemoteLoginProcess polls the reply. Called by
// DWCi_LoginAsync and by the profile check DWCi_GPGetInfoCallback, which restarts the request.
void DWCi_RemoteLogin(void (*callback)(), void *param) {
    AuthCreateParams authParams;
    void *httpBlock;
    u64 startTick;
    MI_CpuFill8(&authParams, 0, sizeof(AuthCreateParams));
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
    gWiFiLogin->mRequestStartTick = startTick;
    DWC_Auth_Create(&authParams, httpBlock);
}

// State 1 step of DWCi_LoginProcess (every frame while mState is 1): when the reply is done (status 0x14) copies the
// token and the second string, frees the Http and goes on through the stored callback (when DWCi_Acc_IsAuthentic
// accepts the saved record) or DWCi_GPConnect with state 3; when DWC_Auth_GetError reports any other nonzero status,
// reports error 2 once 10 s have passed since the request started, otherwise closes the request and issues it again.
void DWCi_RemoteLoginProcess(void) {
    AuthCreateParams authParams;
    DWCAuthResult authResult;
    DWCAuthResult failedAuthResult;
    if (DWC_Auth_GetError() == 0x14) {
        DWC_Auth_GetResult(&authResult.mReturnCode);
        strcpy(gWiFiLogin->mAuthToken, authResult.mToken);
        strcpy(gWiFiLogin->mPartnerChallenge, authResult.mChallenge);
        DWC_Auth_Destroy();
        DWC_Free(0, gWiFiLogin->mHttp, 0);
        gWiFiLogin->mHttp = NULL;
        if (DWCi_Acc_IsAuthentic(gWiFiLogin->mUserData) != 0) {
            stRemoteAuthCallback(gWiFiLogin->mAuthToken, gWiFiLogin->mPartnerChallenge, pStRemoteAuthParam);
        } else {
            DWCi_GPConnect(gWiFiLogin->mAuthToken, gWiFiLogin->mPartnerChallenge, DWCi_GPConnectCallback,
                           WIFI_LOGIN_CONNECT_NEW_ID);
        }
    } else if (DWC_Auth_GetError() != 0) {
        if ((((u64) OS_GetTick() - gWiFiLogin->mRequestStartTick) << 6) / 0x82ea > 0x2710) {
            DWC_Auth_GetResult(&failedAuthResult.mReturnCode);
            DWC_Auth_Destroy();
            DWC_Free(0, gWiFiLogin->mHttp, 0);
            gWiFiLogin->mHttp = NULL;
            DWCi_StopLogin(2, failedAuthResult.mReturnCode);
        } else {
            DWC_Auth_Destroy();
            MI_CpuFill8(&authParams, 0, sizeof(AuthCreateParams));
            strcpy(authParams.mGsbrcd, gWiFiLogin->mGsbrcd);
            authParams.mAlloc = (void *(*) (const void *, u32)) DWC_Alloc;
            authParams.mFree = (void (*)(const void *, void *, u32)) DWC_Free;
            DWC_Auth_Create(&authParams, gWiFiLogin->mHttp);
        }
    }
}

void DWCi_GPGetInfoCallback(GPConnection *connection, GetInfoReply *arg, u32 param) {
    char lastNameToSet[0x15];
    char accountName[0x15];
    char tempUserName[0x15];
    WiFiLogin *wiFiLogin;
    if (arg->mResult != PROFILE_REQUEST_OK) {
        return;
    }
    wiFiLogin = gWiFiLogin;
    if (wiFiLogin->mState == WIFI_LOGIN_CONNECT_NEW_ID) {
        if ((s8) arg->mLastname[0] == 0) {
            DWCi_Acc_LoginIdToUserName(&wiFiLogin->mUserData->mPseudo, wiFiLogin->mGamecode, lastNameToSet);
            if (ReportWiFiLoginGpResult(GpSetInfosA(connection, PROFILE_INFO_LASTNAME, (const s8 *) lastNameToSet)) ==
                0) {
                gWiFiLogin->mState = WIFI_LOGIN_CHECK_NEW_ID_NAME;
                if (ReportWiFiLoginGpResult(GpGetInfo(connection, arg->mProfile, 0, 0, DWCi_GPGetInfoCallback, 0)) !=
                    0) {
                    return;
                }
            }
        } else {
            gpDisconnect(connection);
            DWCi_RemoteLogin(DWCi_RemoteAuthCallback, NULL);
            gWiFiLogin->mState = WIFI_LOGIN_WAIT_AUTH_REPLY;
        }
    } else if (wiFiLogin->mState == WIFI_LOGIN_CHECK_NEW_ID_NAME) {
        DWCi_Acc_LoginIdToUserName(&wiFiLogin->mUserData->mPseudo, wiFiLogin->mGamecode, accountName);
        if (strcmp(arg->mLastname, accountName) == 0) {
            DWCi_Acc_LoginIdToUserName(&gWiFiLogin->mTempLoginId, gWiFiLogin->mGamecode, tempUserName);
            DWCi_Acc_SetLoginIdToUserData(gWiFiLogin->mUserData, &gWiFiLogin->mTempLoginId, arg->mProfile);
            gpDisconnect(connection);
            stRemoteAuthCallback(gWiFiLogin->mAuthToken, gWiFiLogin->mPartnerChallenge, pStRemoteAuthParam);
        } else {
            if (ReportWiFiLoginGpResult(GpGetInfo(connection, arg->mProfile, 0, 0, DWCi_GPGetInfoCallback, 0)) != 0) {
                return;
            }
        }
    }
}

// 1 only in mState WIFI_LOGIN_DONE (set on success by DWCi_GPConnectCallback), 0 when the object is NULL;
// DWC_DeleteBuddyFriendData and DWCi_GetFriendBuddyStatus test it.
u32 DWCi_CheckLogin(void) {
    if ((gWiFiLogin != NULL) && (gWiFiLogin->mState == WIFI_LOGIN_DONE)) {
        return 1;
    }
    return 0;
}
