#include "00/Lib/DWC/dwc_match.h"
#include "00/Lib/DWC/code_021a2ccc.h"
#include "00/code_0219eaf4.h"
#include "00/Lib/GameSpy/sb_serverlist.h"
#include "00/code_0218b000.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/unk_021b5000.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "00/code_0219eac8.h"
#include "00/code_021a1000.h"
#include "00/Lib/DWC/code_021a3264.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_021a4b84.h"
#include "code_02139f70.h"
#include "00/code_021a01dc.h"
#include "00/code_021a0958.h"
#include "00/unk_021b4000.h"
#include "00/code_0219e4e8.h"
#include "00/code_0219e134.h"
#include "code_0214d018.h"
#include "00/code_0219de4c.h"
#include "00/code_0219de5c.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/code_0219dee0.h"
#include "00/code_0219fb48.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"
#include "00/code_0219f4c4.h"
#include "os_tick.h"
#include "00/code_0219c954.h"
#include "00/code_0219c000.h"
#include "00/code_021a17bc.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/Lib/GameSpy/code_0219a654.h"
#include "00/Lib/GameSpy/gt2Utility.h"
#include "00/Lib/DWC/code_0219d128.h"
#include "00/Lib/GameSpy/gt2Main.h"
#include "00/code_0219a000.h"
#include "00/code_0219b000.h"
#include "00/code_0219f9bc.h"
#include "os_printf.h"
#include "00/code_021a10b0.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/code_0218a000.h"
#include "00/code_0218c000.h"
#include "dwc_account.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_0219887c.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a4000.h"
#include "00/Lib/DWC/code_02188720.h"
#include "code_0214cfe4.h"
#include "00/code_021a1ac0.h"
#include "00/Lib/GameSpy/code_02198a8c.h"
#include "00/code_021a1ae0.h"

MatchingSignatureText gMatchingSignature = {"SBCM"};
char gUnsignedFormat[3] = "%u";
char gDwcPidKey[8] = "dwc_pid";
char gDwcEvalKey[9] = "dwc_eval";
MatchingKey gMatchingKeys[154];
u8 gMatchingMaskedParticipantIndices[0x20];
void *gMatchingFilterText;
DWCMatchOptMinCompleteIn *gOptMinComp;
WiFiMatching *gWiFiMatching;
DWCMatchOptSCBlock gOptSCBlock;

u32 DWC_CancelMatching(void) {
    int valid;
    valid = DWC_IsValidCancelMatching();
    if (valid != 0) {
        DWCi_DoCancelMatching();
        return 1;
    }
    return 0;
}

u32 DWC_IsValidCancelMatching(void) {
    if (DWCi_IsError() != 0) {
        return 0;
    }
    if (gWiFiMatching == NULL || DWC_GetState() != WIFI_CONNECTION_PARTNER_SEARCH || gWiFiMatching->mStopPending != 0) {
        return 0;
    }
    return 1;
}

u32 DWC_AddMatchKeyInt(u32 keyId, char *keyString, void *valueSrc) {
    u32 index;
    if (keyString == NULL || valueSrc == NULL) {
        return 0;
    }
    if (keyId >= 100) {
        index = keyId - 100;
        if (gMatchingKeys[index].mKeyId != 0) {
            return keyId;
        }
    }
    keyId = DWCi_GetNewMatchKey();
    if (keyId == 0) {
        return 0;
    }
    index = keyId - 100;
    gMatchingKeys[index].mKeyId = keyId;
    gMatchingKeys[index].mIsString = 0;
    gMatchingKeys[index].mPad = 0;
    if (gMatchingKeys[index].mString != NULL) {
        DWC_Free(4, gMatchingKeys[index].mString, 0);
    }
    gMatchingKeys[index].mString = DWC_Alloc(4, strlen(keyString) + 1);
    if (gMatchingKeys[index].mString == NULL) {
        DWCi_StopMatching(0xb, 0xfffec77f);
        return 0;
    }
    strcpy(gMatchingKeys[index].mString, keyString);
    gMatchingKeys[index].mValue.mNumber = valueSrc;
    qr2_register_keyA(keyId, keyString);
    return keyId;
}

u32 DWC_AddMatchKeyString(u32 keyId, char *keyString, void *valueSrc) {
    u32 index;
    if (keyString == NULL || valueSrc == NULL) {
        return 0;
    }
    if (keyId >= 100) {
        index = keyId - 100;
        if (gMatchingKeys[index].mKeyId != 0) {
            return keyId;
        }
    }
    keyId = DWCi_GetNewMatchKey();
    if (keyId == 0) {
        return 0;
    }
    index = keyId - 100;
    gMatchingKeys[index].mKeyId = keyId;
    gMatchingKeys[index].mIsString = 1;
    gMatchingKeys[index].mPad = 0;
    if (gMatchingKeys[index].mString != NULL) {
        DWC_Free(4, gMatchingKeys[index].mString, 0);
    }
    gMatchingKeys[index].mString = DWC_Alloc(4, strlen(keyString) + 1);
    if (gMatchingKeys[index].mString == NULL) {
        DWCi_StopMatching(0xb, 0xfffec77f);
        return 0;
    }
    strcpy(gMatchingKeys[index].mString, keyString);
    gMatchingKeys[index].mValue.mText = valueSrc;
    qr2_register_keyA(keyId, keyString);
    return keyId;
}

s32 DWC_GetMatchIntValue(u32 index, void *keyString, s32 idefault) {
    SbServer *serverEntry;
    if (gWiFiMatching == NULL || DWCi_IsError() != 0) {
        return idefault;
    }
    serverEntry = ServerBrowserGetServer(gWiFiMatching->mServerList, index);
    if (serverEntry != 0) {
        idefault = SbServerGetInt(serverEntry, keyString, idefault);
    }
    return idefault;
}

u32 DWC_SetMatchingOption(u32 opttype, void *optval, u32 optlen) {
    WiFiMatching *wiFiMatching = gWiFiMatching;
    DWCMatchOptMinCompleteIn *optMinComp;
    DWCMatchOptMinComplete *minCompleteOption = optval;
    if (wiFiMatching == NULL) {
        return 1;
    }
    if (optval == NULL) {
        return 3;
    }
    switch (opttype) {
        case 0:
            if (wiFiMatching->mState == WIFI_MATCH_STATE_MIN_COMPLETE_POLL) {
                return 1;
            }
            if (minCompleteOption->mValid != 0 && minCompleteOption->mMinEntry <= 1) {
                return 3;
            }
            optMinComp = gOptMinComp;
            if (optMinComp == NULL) {
                optMinComp = DWC_Alloc(4, 0x20);
                gOptMinComp = optMinComp;
                if (optMinComp == NULL) {
                    return 4;
                }
            }
            optMinComp->mValid = minCompleteOption->mValid;
            gOptMinComp->mMinEntry = minCompleteOption->mMinEntry;
            gOptMinComp->mRetry = 0;
            gOptMinComp->mPad = 0;
            gOptMinComp->mTimeout = minCompleteOption->mTimeLimit;
            gOptMinComp->mRecvBit = 0;
            gOptMinComp->mTimeoutBit = 0;
            gOptMinComp->mStartTime = MatchingGetTickMilliseconds();
            gOptMinComp->mLastPollTime = MatchingGetTickMilliseconds();
            return 0;
        case 1:
            if (*(u32 *) optval != 0) {
                gOptSCBlock.mValid = 1;
            } else {
                gOptSCBlock.mValid = 0;
            }
            gOptSCBlock.mLock = 0;
            return 0;
        default:
            return 2;
    }
}

s32 DWC_GetMOMinCompState(u64 *time) {
    DWCMatchOptMinCompleteIn *optMinComp = gOptMinComp;
    u64 elapsed;
    if (optMinComp == NULL || optMinComp->mValid == 0) {
        return -1;
    }
    elapsed = MatchingGetTickMilliseconds() - optMinComp->mStartTime;
    if (time != NULL) {
        *time = elapsed;
    }
    return elapsed >= optMinComp->mTimeout;
}

void DWCi_MatchInit(WiFiMatching *wiFiMatching, GpConnection *gpConnection, Gt2Socket **connectionSocket,
                    void *connectionCallbacks, void *gameName, void *secretKey, void *buddies, u32 buddyEntryCount) {
    gWiFiMatching = wiFiMatching;
    wiFiMatching->mGpConnection = gpConnection;
    gWiFiMatching->mConnectionSocket = connectionSocket;
    gWiFiMatching->mConnectionCallbacks = connectionCallbacks;
    gWiFiMatching->mQr2 = NULL;
    gWiFiMatching->mOwnAddress = 0;
    gWiFiMatching->mOwnPort = 0;
    gWiFiMatching->mServerList = NULL;
    gWiFiMatching->mState = WIFI_MATCH_STATE_IDLE;
    gWiFiMatching->mUnk_0f = 0;
    gWiFiMatching->mUnk_19 = 0;
    gWiFiMatching->mUnk_1a5 = 0;
    gWiFiMatching->mOwnProfileId = 0;
    gWiFiMatching->mGameName = gameName;
    gWiFiMatching->mSecretKey = secretKey;
    gWiFiMatching->mBuddies = buddies;
    gWiFiMatching->mBuddyEntryCount = buddyEntryCount;
    MI_CpuFill8(gWiFiMatching->mBuddyEntryIndices, 0, sizeof(gWiFiMatching->mBuddyEntryIndices));
    gWiFiMatching->mBuddyEntryIndexCount = 0;
    gWiFiMatching->mResultCallback = NULL;
    gWiFiMatching->mResultCallbackArg = 0;
    gWiFiMatching->mEvalCallback = NULL;
    gWiFiMatching->mEvalCallbackArg = 0;
    DWCi_ClearGameMatchKeys();
    gOptSCBlock.mValid = 0;
    gOptSCBlock.mLock = 0;
    gOptSCBlock.mPad = 0;
    DWCi_ResetMatchParam(0);
}

u32 DWCi_QR2Startup(u32 profileId) {
    WiFiMatching *wiFiMatching;
    s32 attempt;
    u32 initResult;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mQr2 != NULL) {
        return 0;
    }
    wiFiMatching->mOwnProfileId = profileId;
    attempt = 0;
    do {
        wiFiMatching = gWiFiMatching;
        initResult = qr2_init_socketA(
            &gWiFiMatching->mQr2, GetSocketDescriptor(*wiFiMatching->mConnectionSocket),
            GetSocketPort(*wiFiMatching->mConnectionSocket), wiFiMatching->mGameName, wiFiMatching->mSecretKey, 1, 1,
            (QueryServerKeyFunc) DWCi_QR2ServerKeyCallback, (QueryPlayerTeamKeyFunc) DWCi_QR2PlayerKeyCallback,
            (QueryPlayerTeamKeyFunc) DWCi_QR2TeamKeyCallback, (QueryKeyListFunc) DWCi_QR2KeyListCallback,
            (QueryCountFunc) DWCi_QR2CountCallback, (QueryErrorFunc) DWCi_QR2AddErrorCallback, NULL);
        if (initResult == 0) {
            break;
        }
        if (initResult != 3 || attempt == 4) {
            DWCi_HandleQR2Error(initResult);
            return initResult;
        }
        attempt++;
    } while (attempt < 5);
    gWiFiMatching->mOwnAddress = 0;
    gWiFiMatching->mOwnPort = 0;
    qr2_register_publicaddress_callback(gWiFiMatching->mQr2, DWCi_QR2PublicAddrCallback);
    qr2_register_natneg_callback(gWiFiMatching->mQr2, DWCi_QR2NatnegCallback);
    qr2_register_clientmessage_callback(gWiFiMatching->mQr2, DWCi_QR2ClientMsgCallback);
    qr2_send_statechanged(gWiFiMatching->mQr2);
    return initResult;
}

// Starts a filter search (mode 0) and keeps the caller's filter text for the server list filter.
void DWCi_ConnectToAnybodyAsync(u32 numEntry, const void *addFilter, DWCMatchedCallback matchedCallback,
                                u32 matchedParam, MatchEvalFunc *evalCallback, u32 evalParam) {
    char filterText[0x100];
    s32 filterRoom;
    if (gMatchingFilterText != NULL) {
        DWC_Free(4, gMatchingFilterText, 0);
        gMatchingFilterText = NULL;
    }
    if (addFilter != NULL) {
        filterRoom = DWCi_GetDefaultMatchFilter(filterText, -1, 0x20, 3);
        filterRoom = 0x100 - filterRoom - strlen(" and ()");
        gMatchingFilterText = DWC_Alloc(4, filterRoom);
        if (gMatchingFilterText == NULL) {
            DWCi_StopMatching(11, -80001);
            return;
        }
        MI_CpuCopy8(addFilter, gMatchingFilterText, filterRoom);
        *((u8 *) gMatchingFilterText + filterRoom - 1) = 0;
    }
    ((void (*)(u32, u32, DWCMatchedCallback, u32)) DWCi_SetMatchCommonParam)(0, numEntry, matchedCallback,
                                                                             matchedParam);
    gWiFiMatching->mEvalCallback = evalCallback;
    gWiFiMatching->mEvalCallbackArg = evalParam;
    gWiFiMatching->mState = WIFI_MATCH_STATE_LIST_FIRST_UPDATE;
    if (gWiFiMatching->mServerList == NULL) {
        gWiFiMatching->mServerList = ServerBrowserNewA(gWiFiMatching->mGameName, gWiFiMatching->mGameName,
                                                       gWiFiMatching->mSecretKey, 0, 20, 1, 0, DWCi_SBCallback, 0);
    }
    if (gWiFiMatching->mServerList == NULL && DWCi_HandleSBError(5) != 0) {
        return;
    }
    DWCi_SetGPStatus(3, "", NULL);
    if (DWCi_HandleSBError(DWCi_SBUpdateAsync(gWiFiMatching->mOwnProfileId)) != 0) {
        return;
    }
    if (gWiFiMatching->mQr2 == NULL) {
        DWCi_QR2Startup(gWiFiMatching->mOwnProfileId);
    }
    DWCi_InitOptMinCompParam(0);
}

// Starts a buddy search (mode 1) over a list of buddy entry indices.
void DWCi_ConnectToFriendsAsync(const void *friendIdxList, s32 friendIdxListLen, s32 numEntry, s32 distantFriend,
                                DWCMatchedCallback matchedCallback, u32 matchedParam, MatchEvalFunc *evalCallback,
                                u32 evalParam) {
    char numDigits[12];
    u8 keyValueStr[0x24];
    ((void (*)(u32, u32, DWCMatchedCallback, u32)) DWCi_SetMatchCommonParam)(1, numEntry, matchedCallback,
                                                                             matchedParam);
    gWiFiMatching->mDistantFriend = distantFriend != 0 ? 1 : 0;
    gWiFiMatching->mEvalCallback = evalCallback;
    gWiFiMatching->mEvalCallbackArg = evalParam;
    MI_CpuCopy8(friendIdxList, gWiFiMatching->mBuddyEntryIndices, friendIdxListLen);
    gWiFiMatching->mBuddyEntryIndexCount = friendIdxListLen;
    if (friendIdxListLen == 0 ||
        (friendIdxListLen < numEntry && distantFriend == 0 &&
         (gOptMinComp == NULL || gOptMinComp->mValid == 0 || friendIdxListLen < gOptMinComp->mMinEntry - 1))) {
        DWCi_StopMatching(7, 0);
        return;
    }
    gWiFiMatching->mState = WIFI_MATCH_STATE_RESERVING;
    if (gWiFiMatching->mServerList == NULL) {
        gWiFiMatching->mServerList = ServerBrowserNewA(gWiFiMatching->mGameName, gWiFiMatching->mGameName,
                                                       gWiFiMatching->mSecretKey, 0, 20, 1, 0, DWCi_SBCallback, 0);
    }
    if (gWiFiMatching->mServerList == NULL && DWCi_HandleSBError(5) != 0) {
        return;
    }
    OS_SNPrintf(numDigits, 12, gUnsignedFormat, numEntry);
    DWC_SetCommonKeyValueString("FME", numDigits, keyValueStr, 0x2f);
    DWC_AddCommonKeyValueString("MDF", distantFriend != 0 ? "Y" : "N", keyValueStr, 0x2f);
    OS_SNPrintf(numDigits, 12, gUnsignedFormat, 3);
    DWC_AddCommonKeyValueString("VER", numDigits, keyValueStr, 0x2f);
    if (ReportMatchingGpResult(DWCi_SetGPStatus(4, keyValueStr, NULL)) != 0) {
        return;
    }
    if (DWCi_HandleMatchCommandError(DWCi_SendResvCommandToFriend(0, 1)) != 0) {
        return;
    }
    if (gWiFiMatching->mQr2 == NULL) {
        DWCi_QR2Startup(gWiFiMatching->mOwnProfileId);
    }
    DWCi_InitOptMinCompParam(0);
}

// Per-frame step; the state machine runs only when the parameter is 1.
void DWCi_MatchProcess(s32 runStateMachine) {
    WiFiMatching *wiFiMatching;
    u32 waitMs;
    s32 mode;
    QueryRecord *qr2Obj;
    if (gWiFiMatching == NULL) {
        return;
    }
    if (DWCi_IsError() != 0) {
        return;
    }
    if (runStateMachine == 0) {
        if (gWiFiMatching->mQr2 != NULL) {
            qr2_think(gWiFiMatching->mQr2);
        }
        if (gWiFiMatching->mConnectionSocket != NULL) {
            gt2Think(*gWiFiMatching->mConnectionSocket);
        }
        return;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mState == WIFI_MATCH_STATE_IDLE) {
        return;
    }
    switch (wiFiMatching->mState) {
        case WIFI_MATCH_STATE_RESERVING:
            if (wiFiMatching->mResvTimeoutMs != 0) {
                if ((OS_GetTick() - wiFiMatching->mResvTimeoutStartTick) * 64 / 0x82ea > wiFiMatching->mResvTimeoutMs) {
                    wiFiMatching->mResvTimeoutMs = 0;
                    wiFiMatching = gWiFiMatching;
                    mode = wiFiMatching->mMode;
                    if (mode == 3) {
                        wiFiMatching->mResvRetryCount++;
                        wiFiMatching = gWiFiMatching;
                        if (wiFiMatching->mResvRetryCount > 5) {
                            DWCi_StopMatching(6, -80430);
                            return;
                        }
                        if (DWCi_HandleMatchCommandError(
                                DWCi_SendResvCommand(wiFiMatching->mParticipantProfileIds[0], 0)) != 0) {
                            return;
                        }
                    } else if (DWCi_RetryReserving(mode) == 0) {
                        return;
                    }
                }
            }
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mResvDelayPending != 0) {
                waitMs = (u32) (wiFiMatching->mLastParticipantPos * 3000) + 3000;
                if ((OS_GetTick() - wiFiMatching->mResvDelayStartTick) * 64 / 0x82ea >= waitMs) {
                    if (DWCi_HandleMatchCommandError(
                            DWCi_SendResvCommand(wiFiMatching->mParticipantProfileIds[0], 0)) != 0) {
                        return;
                    }
                }
            }
            break;
        case WIFI_MATCH_STATE_LIST_FIRST_UPDATE:
        case WIFI_MATCH_STATE_LIST_SEARCH:
        case WIFI_MATCH_STATE_HOST_LOOKUP:
            if ((s32) wiFiMatching->mServerUpdateWaitKind > 0) {
                if (wiFiMatching->mState == WIFI_MATCH_STATE_LIST_SEARCH) {
                    waitMs = (u32) (wiFiMatching->mLastParticipantPos * 3000) + 3000;
                } else if (wiFiMatching->mServerUpdateWaitKind == WIFI_MATCH_UPDATE_WAIT_SHORT) {
                    waitMs = 1000;
                } else {
                    waitMs = 3000;
                }
                if ((OS_GetTick() - wiFiMatching->mServerUpdateWaitStartTick) * 64 / 0x82ea > waitMs) {
                    if (DWCi_HandleSBError(DWCi_SBUpdateAsync(wiFiMatching->mReplyProfileId)) != 0) {
                        return;
                    }
                    gWiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_NONE;
                }
            }
            break;
        case WIFI_MATCH_STATE_CONNECT_CLIENT:
            if (wiFiMatching->mIncomingWaitStartTime != 0) {
                if (MatchingGetTickMilliseconds() - wiFiMatching->mIncomingWaitStartTime > 25000) {
                    gWiFiMatching->mIncomingWaitStartTime = 0;
                    if (DWCi_CancelPreConnectedClientProcess(gWiFiMatching->mParticipantProfileIds[0]) == 0) {
                        return;
                    }
                }
            } else if (wiFiMatching->mLastCommand == WIFI_MATCH_COMMAND_CONNECT_INFO) {
                if (MatchingGetTickMilliseconds() - wiFiMatching->mLastCommandTime > 6000) {
                    wiFiMatching->mResendCount++;
                    wiFiMatching = gWiFiMatching;
                    if (wiFiMatching->mResendCount > 5) {
                        DWCi_StopResendingMatchCommand();
                        if (DWCi_CancelPreConnectedClientProcess(gWiFiMatching->mParticipantProfileIds[0]) == 0) {
                            return;
                        }
                    } else if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                                   WIFI_MATCH_COMMAND_CONNECT_INFO, wiFiMatching->mLastCommandProfileId,
                                   wiFiMatching->mLastCommandAddress, wiFiMatching->mLastCommandPort,
                                   wiFiMatching->mLastCommandValues, wiFiMatching->mLastCommandValueCount)) != 0) {
                        return;
                    }
                }
            }
            break;
        case WIFI_MATCH_STATE_NEGOTIATE_SERVER:
            if (wiFiMatching->mLastCommand == WIFI_MATCH_COMMAND_RESERVE_OK) {
                if ((wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH &&
                     MatchingGetTickMilliseconds() - gWiFiMatching->mLastCommandTime > 6000) ||
                    MatchingGetTickMilliseconds() - gWiFiMatching->mLastCommandTime > 19000) {
                    DWCi_StopResendingMatchCommand();
                    if (DWCi_CancelPreConnectedServerProcess(
                            gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]) == 0) {
                        return;
                    }
                }
            }
            break;
        case WIFI_MATCH_STATE_INFORM_PEERS:
            if (wiFiMatching->mLastCommand == WIFI_MATCH_COMMAND_PARTICIPANT_INFO) {
                if (MatchingGetTickMilliseconds() - wiFiMatching->mLastCommandTime > 30000) {
                    wiFiMatching->mResendCount++;
                    wiFiMatching = gWiFiMatching;
                    if (wiFiMatching->mResendCount != 0) {
                        DWCi_StopResendingMatchCommand();
                        wiFiMatching = gWiFiMatching;
                        if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER) {
                            if (DWCi_CancelPreConnectedServerProcess(
                                    wiFiMatching->mParticipantProfileIds[wiFiMatching->mLastParticipantPos]) == 0) {
                                return;
                            }
                        } else {
                            DWCi_RestartFromTimeout();
                        }
                    } else if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                                   WIFI_MATCH_COMMAND_PARTICIPANT_INFO, wiFiMatching->mLastCommandProfileId,
                                   wiFiMatching->mLastCommandAddress, wiFiMatching->mLastCommandPort,
                                   wiFiMatching->mLastCommandValues, wiFiMatching->mLastCommandValueCount)) != 0) {
                        return;
                    }
                }
            }
            break;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mState == WIFI_MATCH_STATE_NEGOTIATE_SERVER ||
        wiFiMatching->mState == WIFI_MATCH_STATE_NEGOTIATE_CLIENT) {
        if (wiFiMatching->mNNFailedTime != 0) {
            if (MatchingGetTickMilliseconds() - wiFiMatching->mNNFailedTime > 10000) {
                DWCi_NNCompletedCallback(1, 0, 0, &wiFiMatching->mNNInfo);
            }
        }
    }
    if (gWiFiMatching->mServerList != NULL) {
        ServerBrowserThink(gWiFiMatching->mServerList);
    }
    if (gWiFiMatching->mQr2 != NULL) {
        qr2_think(gWiFiMatching->mQr2);
        wiFiMatching = gWiFiMatching;
        qr2Obj = wiFiMatching->mQr2;
        if ((qr2Obj->mUserStateChangeRequested == FALSE &&
             (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH ||
              wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) &&
             (wiFiMatching->mState == WIFI_MATCH_STATE_CONNECTED ||
              wiFiMatching->mState == WIFI_MATCH_STATE_LIST_FIRST_UPDATE ||
              wiFiMatching->mState == WIFI_MATCH_STATE_LIST_SEARCH ||
              wiFiMatching->mState == WIFI_MATCH_STATE_RESERVING ||
              wiFiMatching->mState == WIFI_MATCH_STATE_NEGOTIATE_CLIENT ||
              wiFiMatching->mState == WIFI_MATCH_STATE_NEGOTIATE_SERVER)) ||
            (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER &&
             wiFiMatching->mState == WIFI_MATCH_STATE_NEGOTIATE_SERVER)) {
            qr2_send_statechanged(qr2Obj);
        }
    }
    NNThink();
    if (gWiFiMatching->mConnectionSocket != NULL) {
        gt2Think(*gWiFiMatching->mConnectionSocket);
    }
    if (gWiFiMatching->mState == WIFI_MATCH_STATE_RESUME_WAIT) {
        if (MatchingGetTickMilliseconds() - gWiFiMatching->mResumeWaitStartTime > 3000) {
            if (DWCi_ResumeMatching() != 0) {
                return;
            }
        }
    }
    if (DWCi_ProcessMatchSynTimeout() != 0) {
        if (DWCi_ProcessCancelMatchSynTimeout() != 0) {
            DWCi_ProcessOptMinComp();
        }
    }
}

u32 DWCi_GT2UnrecognizedMessageCallback(u32 socket, u32 address, u16 port, u8 *data, u32 size) {
    UnmatchedDataAddress originAddr;
    volatile u32 fillValue;
    u32 firstByte;
    if (size == 0 || data == NULL) {
        return 0;
    }
    fillValue = 0;
    MIi_CpuClear32(fillValue, &originAddr, 8);
    originAddr.mFamily = SOCKET_FAMILY_IPV4;
    originAddr.mAddress = address;
    originAddr.mPort = ((port >> 8) & 0xff) | ((port << 8) & 0xff00);
    firstByte = data[0];
    if ((firstByte == 0xfe && data[1] == 0xfd) || firstByte == 0x5c) {
        if (gWiFiMatching->mQr2 != NULL) {
            qr2_parse_queryA(gWiFiMatching->mQr2, (s8 *) data, size, &originAddr);
        }
    } else if (memcmp(data, NNMagicData, 6) == 0) {
        NNProcessData(data, size, &originAddr);
    } else {
        switch (firstByte) {
            case 0xfe:
                return 0;
            default:
                return 0;
        }
    }
    return 1;
}

// Accepts an incoming connection in the CONNECT_CLIENT state from the expected participant, otherwise refuses it with a
// reason text.
void DWCi_GT2ConnectAttemptCallback(u32 socket, Gt2Connection *connection, u32 address, u32 port, s32 latency,
                                    char *message) {
    WiFiMatching *wiFiMatching;
    DWCConnectionInfo *connectionInfo;
    void **connHandleSlot;
    s32 index;
    s32 participantPos;
    s32 halfLatency;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching == NULL || wiFiMatching->mState != WIFI_MATCH_STATE_CONNECT_CLIENT ||
        wiFiMatching->mStopPending != 0) {
        gt2Reject(connection, "Init state", -1);
        return;
    }
    index = DWCi_GT2GetConnectionListIdx();
    if (index == -1) {
        gt2Reject(connection, "Server full", -1);
        DWCi_StopMatching(6, -87100);
        return;
    }
    if (address != gWiFiMatching->mParticipantConnectAddresses[gWiFiMatching->mLastParticipantPos] ||
        port != gWiFiMatching->mParticipantConnectPorts[gWiFiMatching->mLastParticipantPos]) {
        participantPos = gWiFiMatching->mLastParticipantPos;
        if (*message != 0 && (wiFiMatching = *(WiFiMatching **) &gWiFiMatching,
                              wiFiMatching->mParticipantProfileIds[participantPos] == strtoul(message, NULL, 10))) {
            gWiFiMatching->mParticipantConnectAddresses[participantPos] = address;
            gWiFiMatching->mParticipantConnectPorts[gWiFiMatching->mLastParticipantPos] = port;
        } else {
            gt2Reject(connection, "Unknown connect attempt", -1);
            return;
        }
    }
    gWiFiMatching->mIncomingWaitStartTime = 0;
    if (gt2Accept(connection, gWiFiMatching->mConnectionCallbacks) == 0) {
        DWCi_StopMatching(6, -80410);
        return;
    }
    DWCi_StopResendingMatchCommand();
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mLastParticipantPos == 0) {
        halfLatency = latency >> 1;
        if (halfLatency >= 0xffff) {
            halfLatency = 0xffff;
        }
        wiFiMatching->mSynLatency = halfLatency;
    }
    connHandleSlot = DWCi_GetGT2ConnectionByIdx(index);
    connectionInfo = DWCi_GetConnectionInfoByIdx(index);
    *connHandleSlot = connection;
    gWiFiMatching->mLastParticipantPos++;
    connectionInfo->mIndex = index;
    connectionInfo->mAid = gWiFiMatching->mParticipantIndices[gWiFiMatching->mLastParticipantPos - 1];
    connectionInfo->mReserve = 0;
    connectionInfo->mParam = 0;
    gt2SetConnectionData(connection, connectionInfo);
    DWCi_PostProcessConnection(2);
}

// Result of a connect to a peer: 0 adds the peer, 6 retries the connect up to 5 times, 5 is ignored, 2 ends the
// attempt, other results are reported.
void DWCi_GT2ConnectedCallback(Gt2Connection *connection, s32 result) {
    WiFiMatching *wiFiMatching;
    s32 index;
    void **connHandleSlot;
    DWCConnectionInfo *connInfoRec;
    char pidDigits[12];
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching == NULL) {
        return;
    }
    if (wiFiMatching->mState != WIFI_MATCH_STATE_CONNECT_CLIENT &&
        wiFiMatching->mState != WIFI_MATCH_STATE_CONNECT_SERVER) {
        return;
    }
    if (result != 0) {
        if (result == 5) {
            return;
        }
        if (result == 6) {
            wiFiMatching->mConnectRetryCount++;
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mConnectRetryCount > 5) {
                wiFiMatching->mConnectRetryCount = 0;
                DWCi_CancelPreConnectedServerProcess(
                    gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]);
                return;
            }
            OS_SNPrintf(pidDigits, 12, gUnsignedFormat, wiFiMatching->mOwnProfileId);
            wiFiMatching = gWiFiMatching;
            if (ReportMatchingConnectResult(gt2Connect(
                    *gWiFiMatching->mConnectionSocket, NULL,
                    gt2AddressToString(
                        wiFiMatching->mParticipantConnectAddresses[wiFiMatching->mNNCompletedCount],
                        ((const WiFiMatching *) wiFiMatching)
                            ->mParticipantConnectPorts[((const WiFiMatching *) wiFiMatching)->mNNCompletedCount],
                        0),
                    pidDigits, -1, 5000, wiFiMatching->mConnectionCallbacks, 0)) == 0) {
                return;
            }
            return;
        }
        if (result == 2) {
            if (DWCi_CancelPreConnectedServerProcess(
                    gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]) == 0) {
                return;
            }
            return;
        }
        ReportMatchingConnectResult(result);
        return;
    }
    index = DWCi_GT2GetConnectionListIdx();
    if (index == -1) {
        DWCi_StopMatching(6, -87100);
    }
    connHandleSlot = DWCi_GetGT2ConnectionByIdx(index);
    connInfoRec = DWCi_GetConnectionInfoByIdx(index);
    *connHandleSlot = connection;
    gWiFiMatching->mLastParticipantPos++;
    connInfoRec->mIndex = index;
    connInfoRec->mReserve = 0;
    connInfoRec->mParam = 0;
    connInfoRec->mAid = gWiFiMatching->mParticipantIndices[gWiFiMatching->mLastParticipantPos];
    gt2SetConnectionData(connection, connInfoRec);
    if (gWiFiMatching->mState == WIFI_MATCH_STATE_CONNECT_SERVER) {
        DWCi_PostProcessConnection(0);
        return;
    }
    DWCi_PostProcessConnection(1);
}

void DWCi_MatchGPRecvBuddyMsgCallback(GpConnection *gpConnection, u32 profileId, const char *message) {
    u32 values[33];
    char valueStr[16];
    const char **valueEnd;
    s32 count;
    u32 *valuePtr;
    valueEnd = NULL;
    count = 0;
    valuePtr = values;
    do {
        if (DWCi_GetGPBuddyAdditionalMsg(valueStr, message + 1, count) == -1) {
            break;
        }
        *valuePtr = strtoul(valueStr, valueEnd, 10);
        valuePtr++;
        count++;
    } while (count < 0x80);
    DWCi_ProcessRecvMatchCommand(message[0], profileId, 0, 0, values, count);
}

void DWCi_StopResendingMatchCommand(void) {
    gWiFiMatching->mLastCommand = WIFI_MATCH_COMMAND_NONE;
    gWiFiMatching->mResendCount = 0;
}

void DWCi_StopMatching(s32 kind, s32 code) {
    WiFiMatching *wiFiMatching;
    u32 isServer;
    u32 isSelf;
    u32 eventProfileId;
    if (gWiFiMatching != NULL && kind != 0) {
        DWCi_CloseAllConnectionsByTimeout();
        DWCi_SetError(kind, code);
        DWCi_SetGPStatus(0, "", NULL);
        wiFiMatching = gWiFiMatching;
        isServer = wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER ? 1 : 0;
        eventProfileId = gWiFiMatching->mEventProfileId;
        isSelf = eventProfileId == 0 ? 1 : 0;
        gWiFiMatching->mResultCallback(kind, 0, isSelf, isServer, DWCi_GetFriendListIndex(eventProfileId),
                                       wiFiMatching->mResultCallbackArg);
        DWCi_CloseMatching();
    }
}

void DWCi_ClearQR2Key(void) {
    WiFiMatching *wiFiMatching;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMode != WIFI_MATCH_MODE_SERVER) {
        wiFiMatching->mNNCompletedCount = 0;
        gWiFiMatching->mNumEntry = 0;
        qr2_send_statechanged(gWiFiMatching->mQr2);
    }
}

void DWCi_ProcessMatchSynPacket(s32 peerIndex, s32 kind, u8 *data) {
    WiFiMatching *wiFiMatching;
    s32 participantPos;
    u32 *replyMaskPtr;
    s32 value;
    switch (kind) {
        case WIFI_MESSAGE_KIND_SYNC_REQUEST:
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mState == WIFI_MATCH_STATE_CONNECTED) {
                if (data[0] == 1) {
                    wiFiMatching->mEventProfileId = 0;
                }
                participantPos = data[1];
                gWiFiMatching->mParticipantIndices[participantPos] = data[2];
                gWiFiMatching->mParticipantProfileIds[participantPos] = gWiFiMatching->mOwnProfileId;
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH ||
                    wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                    wiFiMatching = gWiFiMatching;
                    wiFiMatching->mNumEntry = wiFiMatching->mLastParticipantPos;
                }
                gWiFiMatching->mState = WIFI_MATCH_STATE_SYN_CLIENT;
            }
            DWCi_SendMatchSynPacket(peerIndex, WIFI_MESSAGE_KIND_SYNC_REPLY);
            break;
        case WIFI_MESSAGE_KIND_SYNC_REPLY:
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mState == WIFI_MATCH_STATE_SYN_SERVER) {
                replyMaskPtr = &wiFiMatching->mSynReplyMask;
                *replyMaskPtr = *replyMaskPtr | (1 << peerIndex);
                value = data[0] | (data[1] << 8);
                if (value > gWiFiMatching->mSynLatency) {
                    gWiFiMatching->mSynLatency = value;
                }
                value = DWCi_GetAIDBitmask(0);
                if (gWiFiMatching->mSynReplyMask == value) {
                    for (participantPos = 1; participantPos <= gWiFiMatching->mLastParticipantPos; participantPos++) {
                        DWCi_SendMatchSynPacket(gWiFiMatching->mParticipantIndices[participantPos],
                                                WIFI_MESSAGE_KIND_SYNC_GO);
                    }
                    gWiFiMatching->mState = WIFI_MATCH_STATE_SYN_SERVER_DELAY;
                }
            } else {
                DWCi_SendMatchSynPacket(peerIndex, WIFI_MESSAGE_KIND_SYNC_GO);
            }
            break;
        case WIFI_MESSAGE_KIND_SYNC_GO:
            if (gWiFiMatching->mState == WIFI_MATCH_STATE_SYN_CLIENT) {
                DWCi_PostProcessConnection(4);
            }
            break;
    }
}

u32 DWCi_ProcessMatchClosing(s32 error, s32 errorCode, s32 profileId) {
    WiFiMatching *wiFiMatching;
    if (DWC_GetState() != WIFI_CONNECTION_PARTNER_SEARCH) {
        return 0;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER) {
        return 1;
    }
    if (error != 0) {
        DWCi_StopMatching(error, errorCode - 80000);
        return 1;
    }
    wiFiMatching->mParticipantIndices[0] = 0;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mStopPending == 1 || wiFiMatching->mCloseKind == WIFI_MATCH_CLOSE_IGNORE_CALLBACK ||
        wiFiMatching->mCloseKind == WIFI_MATCH_CLOSE_IGNORE_CALLBACK_AND_SC_CANCEL) {
        return 1;
    }
    if (wiFiMatching->mNNInfo.mCookie != 0) {
        NNCancel(wiFiMatching->mNNInfo.mCookie);
        gWiFiMatching->mNNInfo.mCookie = 0;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mLastParticipantPos != 0) {
        if (wiFiMatching->mCloseKind == WIFI_MATCH_CLOSE_NONE) {
            wiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_AFTER_FAILURE;
            gt2CloseAllConnectionsHard(*gWiFiMatching->mConnectionSocket);
        }
    } else if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
        DWCi_StopMatching(6, -80430);
    } else if (wiFiMatching->mPriorProfileId != 0) {
        DWCi_ResumeMatching();
    } else if (wiFiMatching->mState == WIFI_MATCH_STATE_CONNECTED) {
        wiFiMatching->mState = WIFI_MATCH_STATE_RESUME_WAIT;
        gWiFiMatching->mResumeWaitStartTime = MatchingGetTickMilliseconds();
    } else {
        DWCi_RestartFromCancel(1);
    }
    return 1;
}

void DWCi_ProcessMatchSCClosing(u32 clientPid) {
    if (gWiFiMatching->mCloseKind != WIFI_MATCH_CLOSE_IGNORE_CALLBACK_AND_SC_CANCEL) {
        DWCi_CancelPreConnectedServerProcess(clientPid);
    }
}

u32 DWCi_DeleteHostByProfileID(int profileId, int count) {
    int position;
    WiFiMatching *matching;
    matching = gWiFiMatching;
    if (0 == matching) {
        return 0;
    }
    position = 0;
    if (0 < count) {
        do {
            if (profileId == matching->mParticipantProfileIds[position]) {
                DWCi_DeleteHostByIndex(position, count);
                return 1;
            }
            position = position + 1;
        } while (position < count);
    }
    return 0;
}

u32 DWCi_DeleteHostByIndex(s32 position, s32 count) {
    WiFiMatching *wiFiMatching;
    u32 profileId;
    u32 *participantMaskPtr;
    s32 shiftIndex;
    s32 shiftCount;
    s32 lastSlot;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching == NULL) {
        return 0;
    }
    profileId = wiFiMatching->mParticipantProfileIds[position];
    participantMaskPtr = &wiFiMatching->mParticipantMask;
    *participantMaskPtr = *participantMaskPtr & ~(1 << wiFiMatching->mParticipantIndices[position]);
    DWCi_SetNumValidConnection();
    if (position < count - 1) {
        shiftIndex = 0;
        shiftCount = count - position;
        if (shiftCount > 0) {
            do {
                s32 slot = position + shiftIndex;
                gWiFiMatching->mParticipantCommandAddresses[slot] =
                    gWiFiMatching->mParticipantCommandAddresses[slot + 1];
                gWiFiMatching->mParticipantCommandPorts[slot] = gWiFiMatching->mParticipantCommandPorts[slot + 1];
                gWiFiMatching->mParticipantProfileIds[slot] = gWiFiMatching->mParticipantProfileIds[slot + 1];
                gWiFiMatching->mParticipantConnectAddresses[slot] =
                    gWiFiMatching->mParticipantConnectAddresses[slot + 1];
                gWiFiMatching->mParticipantConnectPorts[slot] = gWiFiMatching->mParticipantConnectPorts[slot + 1];
                gWiFiMatching->mParticipantIndices[slot] = gWiFiMatching->mParticipantIndices[slot + 1];
                shiftIndex++;
            } while (shiftIndex < shiftCount);
        }
    }
    if (count > 0) {
        lastSlot = count - 1;
        gWiFiMatching->mParticipantCommandAddresses[lastSlot] = 0;
        gWiFiMatching->mParticipantCommandPorts[lastSlot] = 0;
        gWiFiMatching->mParticipantProfileIds[lastSlot] = 0;
        gWiFiMatching->mParticipantConnectAddresses[lastSlot] = 0;
        gWiFiMatching->mParticipantConnectPorts[lastSlot] = 0;
        gWiFiMatching->mParticipantIndices[lastSlot] = 0;
    }
    return profileId;
}

u8 DWCi_GetNumAllConnection(void) {
    if (gWiFiMatching != NULL) {
        return gWiFiMatching->mLastParticipantPos;
    }
    return 0;
}

u8 DWCi_GetNumValidConnection(void) {
    if (gWiFiMatching != NULL) {
        return gWiFiMatching->mLastMaskedParticipantPos;
    }
    return 0;
}

void DWCi_SetNumValidConnection(void) {
    WiFiMatching *wiFiMatching;
    s32 lastPos;
    s32 bitIndex;
    u32 bitmap;
    bitIndex = 0;
    lastPos = -1;
    wiFiMatching = gWiFiMatching;
    bitmap = wiFiMatching->mParticipantMask;
    for (; bitIndex < 32; bitIndex++) {
        if (BIT_IS_SET(bitmap, bitIndex)) {
            lastPos++;
        }
    }
    if (lastPos == -1) {
        wiFiMatching->mLastMaskedParticipantPos = 0;
    } else {
        wiFiMatching->mLastMaskedParticipantPos = lastPos;
    }
}

u32 DWCi_GetAllAIDList(u8 **output) {
    if (gWiFiMatching == NULL) {
        return 0;
    }
    *output = gWiFiMatching->mParticipantIndices;
    return gWiFiMatching->mLastParticipantPos + 1;
}

u32 DWCi_GetValidAIDList(u8 **aidList) {
    s32 listIndex;
    u8 *participantBytes;
    u8 *outList;
    WiFiMatching *wiFiMatching;
    u8 aid;
    if (gWiFiMatching == NULL) {
        return 0;
    }
    MI_CpuFill8(gMatchingMaskedParticipantIndices, 0, sizeof(gMatchingMaskedParticipantIndices));
    listIndex = 0;
    participantBytes = (u8 *) gWiFiMatching;
    if (listIndex <= ((WiFiMatching *) participantBytes)->mLastMaskedParticipantPos) {
        outList = gMatchingMaskedParticipantIndices;
        wiFiMatching = (WiFiMatching *) participantBytes;
        do {
            aid = participantBytes[0x2b8];
            if ((wiFiMatching->mParticipantMask & (1 << aid)) == 0) {
                break;
            }
            *outList = aid;
            participantBytes++;
            outList++;
            listIndex++;
        } while (listIndex <= wiFiMatching->mLastMaskedParticipantPos);
    }
    *aidList = gMatchingMaskedParticipantIndices;
    return gWiFiMatching->mLastMaskedParticipantPos + 1;
}

u32 DWCi_GPSetServerStatus(void) {
    char numText[12];
    u8 keyValueStr[32];
    if (gWiFiMatching->mMode != WIFI_MATCH_MODE_SERVER) {
        return 0;
    }
    OS_SNPrintf(numText, 0xc, gUnsignedFormat, gWiFiMatching->mNumEntry + 1);
    DWC_SetCommonKeyValueString("SCM", numText, keyValueStr, 0x2f);
    OS_SNPrintf(numText, 0xc, gUnsignedFormat, gWiFiMatching->mLastParticipantPos + 1);
    DWC_AddCommonKeyValueString("SCN", numText, keyValueStr, 0x2f);
    OS_SNPrintf(numText, 0xc, gUnsignedFormat, 3);
    DWC_AddCommonKeyValueString("VER", numText, keyValueStr, 0x2f);
    return DWCi_SetGPStatus(6, keyValueStr, NULL);
}

void DWCi_ShutdownMatch(void) {
    gWiFiMatching = NULL;
    if (gMatchingFilterText != NULL) {
        DWC_Free(4, gMatchingFilterText, 0);
        gMatchingFilterText = NULL;
    }
    DWCi_ClearGameMatchKeys();
    if (gOptMinComp != NULL) {
        DWC_Free(4, gOptMinComp, 0);
        gOptMinComp = NULL;
    }
    gOptSCBlock.mValid = 0;
    gOptSCBlock.mLock = 0;
}

u32 DWCi_IsShutdownMatch(void) {
    if (gWiFiMatching == NULL) {
        return 1;
    }
    return 0;
}

// Resets the per-search fields; level 2 keeps the participant list, 1 clears it, 0 also resets the mode and callbacks.
void DWCi_ResetMatchParam(s32 level) {
    vu16 commandPortFill;
    vu16 connectPortFill;

    gWiFiMatching->mConnectRetryCount = 0;
    gWiFiMatching->mNatnegCounts[0] = 0;
    gWiFiMatching->mCookieRandom = DWCi_GetMathRand32(0x10000);
    gWiFiMatching->mLastNatnegCookie = 0;
    gWiFiMatching->mNNFailedTime = 0;
    gWiFiMatching->mIncomingWaitStartTime = 0;
    gWiFiMatching->mPostProcessPos = 0;
    gWiFiMatching->mStopPending = 0;
    gWiFiMatching->mResvRetryCount = 0;
    gWiFiMatching->mSynResendCounts[0] = 0;
    gWiFiMatching->mSynResendCounts[1] = 0;
    gWiFiMatching->mPriorResvDelayCount = 0;
    gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_NONE;
    gWiFiMatching->mCancelSynLatency = 0;
    gWiFiMatching->mServerPort = 0;
    gWiFiMatching->mServerAddress = 0;
    gWiFiMatching->mLastPeerMessageSendTime = 0;
    gWiFiMatching->mResumeWaitStartTime = 0;
    ClearBuffer32(&gWiFiMatching->mLastCommand, 0x98);
    if (level == 2) {
        gWiFiMatching->mNNCompletedCount = gWiFiMatching->mLastParticipantPos;
        if (gWiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
            gWiFiMatching->mState = WIFI_MATCH_STATE_CONNECTED;
            return;
        }
        if (gWiFiMatching->mMode == WIFI_MATCH_MODE_SERVER) {
            gWiFiMatching->mState = WIFI_MATCH_STATE_ACCEPTING;
            return;
        }
    } else {
        gWiFiMatching->mLastParticipantPos = 0;
        gWiFiMatching->mLastMaskedParticipantPos = 0;
        gWiFiMatching->mNNCompletedCount = 0;
        gWiFiMatching->mMresvPresent = 0;
        gWiFiMatching->mMresvProfileId = 0;
        gWiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_NONE;
        gWiFiMatching->mBuddyEntryIndexPos = 0;
        gWiFiMatching->mSynLatency = 0;
        gWiFiMatching->mResvDelayPending = 0;
        gWiFiMatching->mResvDelayStartTick = 0;
        gWiFiMatching->mResvTimeoutMs = 0;
        gWiFiMatching->mResvTimeoutStartTick = 0;
        gWiFiMatching->mSynReplyMask = 0;
        gWiFiMatching->mReplyProfileId = 0;
        gWiFiMatching->mPriorProfileId = 0;
        gWiFiMatching->mParticipantMask = 0;
        ClearBuffer32(gWiFiMatching->mParticipantCommandAddresses, 0x80);
        commandPortFill = 0;
        MIi_CpuClear16(commandPortFill, gWiFiMatching->mParticipantCommandPorts, 0x40);
        ClearBuffer32(gWiFiMatching->mParticipantProfileIds, 0x80);
        ClearBuffer32(&gWiFiMatching->mNNInfo, sizeof(DWCNNInfo));
        ClearBuffer32(gWiFiMatching->mParticipantConnectAddresses, 0x80);
        connectPortFill = 0;
        MIi_CpuClear16(connectPortFill, gWiFiMatching->mParticipantConnectPorts, 0x40);
        MI_CpuFill8(gWiFiMatching->mParticipantIndices, 0, sizeof(gWiFiMatching->mParticipantIndices));
        ClearBuffer32(gWiFiMatching->mReceivedList, 0x84);
        if (level == 1) {
            if (gWiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
                gWiFiMatching->mState = WIFI_MATCH_STATE_LIST_SEARCH;
                return;
            }
            if (gWiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                gWiFiMatching->mState = WIFI_MATCH_STATE_RESERVING;
                return;
            }
        } else {
            gWiFiMatching->mMode = WIFI_MATCH_MODE_FILTER_SEARCH;
            gWiFiMatching->mNumEntry = 0;
            gWiFiMatching->mQr2ShutdownPending = 0;
            gWiFiMatching->mEventProfileId = 0;
            gWiFiMatching->mDistantFriend = 0;
            gWiFiMatching->mNewParticipantCallback = NULL;
            gWiFiMatching->mNewParticipantCallbackArg = 0;
        }
    }
}

// Sets mode, second value and result callback for a new search and registers the key names 0x32 to 0x36.
void DWCi_SetMatchCommonParam(u8 matchType, u8 numEntry, DWCMatchedCallback matchedCallback, u32 matchedParam) {
    WiFiMatching **matchingSlot;
    DWCi_ResetMatchParam(0);
    matchingSlot = &gWiFiMatching;
    gWiFiMatching->mMode = matchType;
    (*matchingSlot)->mNumEntry = numEntry;
    (*matchingSlot)->mResultCallback = matchedCallback;
    (*matchingSlot)->mResultCallbackArg = matchedParam;
    (*matchingSlot)->mNatnegCounts[1] = 0;
    (*matchingSlot)->mParticipantIndices[0] = 0;
    qr2_register_keyA(0x32, gDwcPidKey);
    qr2_register_keyA(0x33, "dwc_mtype");
    qr2_register_keyA(0x34, "dwc_mresv");
    qr2_register_keyA(0x35, "dwc_mver");
    qr2_register_keyA(0x36, gDwcEvalKey);
}

void DWCi_CloseMatching(void) {
    if (gWiFiMatching != NULL) {
        if (gWiFiMatching->mServerList != NULL) {
            ServerBrowserFree(gWiFiMatching->mServerList);
            gWiFiMatching->mServerList = NULL;
        }
        NNFreeNegotiateList();
        gWiFiMatching->mState = WIFI_MATCH_STATE_IDLE;
        if (gMatchingFilterText != NULL) {
            DWC_Free(4, gMatchingFilterText, 0);
            gMatchingFilterText = NULL;
        }
        DWCi_ClearGameMatchKeys();
        gWiFiMatching->mQr2ShutdownPending = 1;
    }
}

u32 DWCi_SBUpdateAsync(u32 profileId) {
    char filterText[0x100];
    u8 fieldIds[0xa8];
    s32 loopIndex;
    MatchingKey *matchingKey;
    u8 *fieldIdOut;
    u32 fieldCount;
    u32 updateResult;

    fieldCount = 7;
    fieldIds[0] = 8;
    fieldIds[1] = 0xa;
    fieldIds[2] = 0x32;
    fieldIds[3] = 0x33;
    fieldIds[4] = 0x34;
    fieldIds[5] = 0x35;
    fieldIds[6] = 0x36;
    if (gWiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH || gWiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
        loopIndex = 0;
        matchingKey = gMatchingKeys;
        fieldIdOut = fieldIds + 7;
        for (; loopIndex < 0x9a; loopIndex++) {
            if (matchingKey->mKeyId != 0) {
                *fieldIdOut = matchingKey->mKeyId;
                fieldIdOut++;
                fieldCount++;
            }
            matchingKey++;
        }
    }
    switch (gWiFiMatching->mState) {
        case WIFI_MATCH_STATE_LIST_SEARCH:
            profileId = gWiFiMatching->mPriorProfileId;
            if (profileId == 0) {
                DWCi_GetDefaultMatchFilter(filterText, gWiFiMatching->mOwnProfileId, gWiFiMatching->mNumEntry,
                                           gWiFiMatching->mMode);
                if (gMatchingFilterText != NULL) {
                    OS_SNPrintf(filterText, 0x100, "%s and (%s)", filterText, gMatchingFilterText);
                }
                break;
            }
        case WIFI_MATCH_STATE_LIST_FIRST_UPDATE:
        case WIFI_MATCH_STATE_RESERVING:
        case WIFI_MATCH_STATE_HOST_LOOKUP:
            OS_SNPrintf(filterText, 0x100, "%s = %u", gDwcPidKey, profileId);
            gWiFiMatching->mReplyProfileId = profileId;
            break;
    }
    ServerBrowserClear(gWiFiMatching->mServerList);
    for (loopIndex = 0; loopIndex < 5; loopIndex++) {
        updateResult =
            ServerBrowserLimitUpdateA(gWiFiMatching->mServerList, 1, 0, fieldIds, fieldCount, filterText, 0x10);
        if (updateResult == 0 || updateResult != 2) {
            break;
        }
    }
    return updateResult;
}

s32 DWCi_GetDefaultMatchFilter(char *buffer, s32 profileId, s32 numEntry, s32 mode) {
    return OS_SNPrintf(
        buffer, 0x100, "%s = %d and %s != %u and maxplayers = %d and numplayers < %d and %s = %d and %s != %s",
        "dwc_mver", 3, gDwcPidKey, profileId, numEntry, numEntry, "dwc_mtype", mode, "dwc_mresv", gDwcPidKey);
}

u32 DWCi_NNStartupAsync(s32 isQR2, s32 cookie, SbServer *server) {
    u32 words[2];
    u16 hostIdLow;
    u32 index;
    BOOL canStart;
    u32 startResult;
    u32 result;

    index = gWiFiMatching->mNNCompletedCount;
    startResult = 0;
    if (isQR2 == 0) {
        cookie = (gWiFiMatching->mOwnProfileId & 0xffff) | (gWiFiMatching->mCookieRandom << 16);
        if (SBServerHasPrivateAddress(server) != 0) {
            if (SBServerGetPublicInetAddress(server) == ServerBrowserGetMyPublicIPAddr(gWiFiMatching->mServerList)) {
                gWiFiMatching->mParticipantConnectAddresses[index] = SBServerGetPrivateInetAddress(server);
                gWiFiMatching->mParticipantConnectPorts[index] = SBServerGetPrivateQueryPort(server);
                canStart = FALSE;
            } else {
                canStart = TRUE;
            }
        } else {
            hostIdLow = SOC_GetHostID();
            if ((hostIdLow & 0xffff) == 0xa8c0 ||
                ((hostIdLow & 0xff) == 0xac && (hostIdLow & 0xff00u) >= 0x1000 && (hostIdLow & 0xff00u) <= 0x1f00) ||
                (hostIdLow & 0xff) == 0x10) {
                canStart = TRUE;
            } else {
                gWiFiMatching->mParticipantConnectAddresses[index] = SBServerGetPublicInetAddress(server);
                gWiFiMatching->mParticipantConnectPorts[index] = SBServerGetPublicQueryPort(server);
                canStart = FALSE;
            }
        }
        if (canStart != FALSE) {
            gWiFiMatching->mCookieRandom = DWCi_GetMathRand32(0x10000);
            gWiFiMatching->mNNInfo.mCookie = cookie;
        } else {
            words[0] = SOC_GetHostID();
            words[1] = GetSocketPort(*gWiFiMatching->mConnectionSocket);
            result = DWCi_SendMatchCommand(
                WIFI_MATCH_COMMAND_CONNECT_INFO, gWiFiMatching->mParticipantProfileIds[index],
                SBServerGetPublicInetAddress(server), SBServerGetPublicQueryPort(server), words, 2);
            gWiFiMatching->mResendCount = 0;
            if (result != 0) {
                return 2;
            }
            gWiFiMatching->mNNInfo.mCookie = 0;
        }
        gWiFiMatching->mNNInfo.mIsQR2 = 0;
        gWiFiMatching->mNNInfo.mRetryCount = 0;
        gWiFiMatching->mNNInfo.mPort = SBServerGetPublicQueryPort(server);
        gWiFiMatching->mNNInfo.mAddress = SBServerGetPublicInetAddress(server);
    } else {
        canStart = TRUE;
        gWiFiMatching->mNNInfo.mIsQR2 = 1;
        gWiFiMatching->mNNInfo.mRetryCount = startResult;
        gWiFiMatching->mNNInfo.mPort = startResult;
        gWiFiMatching->mNNInfo.mAddress = startResult;
        gWiFiMatching->mNNInfo.mCookie = cookie;
    }
    if (canStart != FALSE) {
        startResult = DWCi_DoNatNegotiationAsync(&gWiFiMatching->mNNInfo);
    } else {
        DWCi_NNCompletedCallback(0, GetSocketDescriptor(*gWiFiMatching->mConnectionSocket), 0, &gWiFiMatching->mNNInfo);
        gWiFiMatching->mIncomingWaitStartTime = 0;
    }
    return startResult;
}

u32 DWCi_DoNatNegotiationAsync(DWCNNInfo *nnInfo) {
    u32 beginResult;
    s32 attempt;

    if (nnInfo->mIsQR2 == 0) {
        if (DWCi_HandleSBError(ServerBrowserSendNatNegotiateCookieToServerA(gWiFiMatching->mServerList,
                                                                            gt2AddressToString(nnInfo->mAddress, 0, 0),
                                                                            nnInfo->mPort, nnInfo->mCookie)) != 0) {
            return 2;
        }
    }
    for (attempt = 0; attempt < 5; attempt++) {
        beginResult =
            NNBeginNegotiationWithSocket(GetSocketDescriptor(*gWiFiMatching->mConnectionSocket), nnInfo->mCookie,
                                         nnInfo->mIsQR2, (void (*)(s32, void *)) DWCi_NNProgressCallback,
                                         (void (*)(s32, s32, void *, void *)) DWCi_NNCompletedCallback, nnInfo);
        if (beginResult == 0 || beginResult != 3) {
            break;
        }
    }
    return beginResult;
}

// Sends a command straight to an address in mode 0 and by GP text otherwise (command 6 can also go to an address);
// commands 2, 6, 8 and 9 are remembered to be sent again.
u32 DWCi_SendMatchCommand(u32 command, u32 profileId, u32 address, u32 port, void *values, s32 valueCount) {
    char numBuf[0x10];
    char message[0x200];
    u32 *valueWords;
    s32 length;
    s32 valueIndex;
    s32 tmpLen;

    length = 0;
    if (gWiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH ||
        ((gWiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT || gWiFiMatching->mDistantFriend != 0) &&
         command == WIFI_MATCH_COMMAND_CONNECT_INFO)) {
        length = DWCi_SendSBMsgCommand(command, address, port, values, valueCount);
    } else {
        if (values != NULL && valueCount != 0) {
            valueWords = values;
            length = OS_SNPrintf(message, 0x200, gUnsignedFormat, valueWords[0]);
            for (valueIndex = 1; valueIndex < valueCount; valueIndex++) {
                tmpLen = OS_SNPrintf(numBuf, 0x10, "/%u", valueWords[valueIndex]);
                MI_CpuCopy8(numBuf, message + length, tmpLen);
                length += tmpLen;
            }
        }
        message[length] = 0;
        length = DWCi_SendGPBuddyMsgCommand(gWiFiMatching->mGpConnection, command, profileId, message);
    }
    if (command == WIFI_MATCH_COMMAND_RESERVE_OK || command == WIFI_MATCH_COMMAND_CONNECT_INFO ||
        (u8) (command + (0x100 - WIFI_MATCH_COMMAND_PARTICIPANT_INFO)) <= 1) {
        gWiFiMatching->mLastCommand = command;
        gWiFiMatching->mLastCommandPort = port;
        gWiFiMatching->mLastCommandAddress = address;
        gWiFiMatching->mLastCommandProfileId = profileId;
        gWiFiMatching->mLastCommandValueCount = valueCount;
        gWiFiMatching->mLastCommandTime = MatchingGetTickMilliseconds();
        if (values != NULL && valueCount != 0) {
            MIi_CpuCopy32(values, gWiFiMatching->mLastCommandValues, valueCount * 4);
        }
    }
    return length;
}

u32 DWCi_SendSBMsgCommand(u32 command, u32 address, u32 port, u32 *values, u32 valueCount) {
    u32 valuesCopy[0x21];
    MatchingSendHeader header;
    u32 sendResult;
    s32 attempt;

    if (values != NULL && valueCount != 0) {
        MIi_CpuCopy32(values, valuesCopy, valueCount * 4);
    } else {
        valueCount = 0;
    }
    *(MatchingSignatureText *) &header = gMatchingSignature;
    header.mVersion = 3;
    header.mCommand = command;
    header.mValuesSize = valueCount * 4;
    header.mPort = gWiFiMatching->mOwnPort;
    header.mAddress = gWiFiMatching->mOwnAddress;
    header.mProfileId = gWiFiMatching->mOwnProfileId;
    for (attempt = 0; attempt < 5; attempt++) {
        sendResult = ServerBrowserSendMessageToServerA(gWiFiMatching->mServerList, gt2AddressToString(address, 0, 0),
                                                       port, &header, header.mValuesSize + 0x14);
        if (sendResult == 0 || sendResult != 2) {
            break;
        }
    }
    return sendResult;
}

s32 DWCi_SendGPBuddyMsgCommand(struct GpConnection *gpConnection, u32 command, u32 profileId, const char *text) {
    char msgBuf[0x200];
    char *textDest;
    char *afterCommand;
    s32 len2;
    s32 len;

    len = OS_SNPrintf(msgBuf, 0x200, "%s%dv%s", "GPCM", 3, "MAT");
    msgBuf[len] = command;
    afterCommand = msgBuf + 1;
    textDest = afterCommand + len;
    afterCommand[len] = 0;
    if (text != NULL) {
        len2 = strlen(text);
        MI_CpuCopy8(text, textDest, len2);
        textDest[len2] = 0;
    }
    return GpSendMessage(gpConnection, profileId, msgBuf);
}

s32 DWCi_GetGPBuddyAdditionalMsg(char *out, const char *text, s32 index) {
    const char *textEnd;
    const char *slash;
    s32 partIndex;
    s32 len;

    textEnd = strchr(text, 0);
    for (partIndex = 0; partIndex < index; partIndex++) {
        slash = strchr(text, 0x2f);
        if (slash == NULL) {
            return -1;
        }
        text = slash + 1;
    }
    slash = strchr(text, 0x2f);
    if (slash == NULL) {
        slash = textEnd;
    }
    if (text == slash) {
        return -1;
    }
    len = slash - text;
    MI_CpuCopy8(text, out, len);
    out[len] = 0;
    return len;
}

// One case per command of a received matching message; returns 0 after an error was reported.
s32 DWCi_ProcessRecvMatchCommand(s32 command, u32 profileId, u32 address, u16 port, u32 *values, s32 valueCount) {
    u32 *profileIdSlot;
    u32 valueProfileId;
    PeerAddress peerAddress;
    u32 sendValues[0x41];
    s32 valueIndex;
    s32 result;
    u16 rawPort;
    s32 firstValue;
    u32 indexValue;
    u8 aidValue;
    WiFiMatching *wiFiMatching;
    WiFiMatching *latestMatching;
    DWCMatchOptMinCompleteIn *optMinComp;
    u32 *profileIdEntry;

    valueIndex = 0;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching == NULL || wiFiMatching->mState == WIFI_MATCH_STATE_IDLE) {
        return 1;
    }
    switch (command) {
        case WIFI_MATCH_COMMAND_RESERVE:
        case WIFI_MATCH_COMMAND_RESERVE_PRIORITY:
            result =
                DWCi_CheckResvCommand(profileId, values[0], command == WIFI_MATCH_COMMAND_RESERVE_PRIORITY ? 1 : 0);
            if (result == WIFI_MATCH_COMMAND_RESERVE_OK) {
                if (gWiFiMatching->mMode != WIFI_MATCH_MODE_FILTER_SEARCH) {
                    address = values[1];
                    port = values[2];
                }
                if (DWCi_HandleMatchCommandError(DWCi_ProcessResvOK(profileId, address, port)) != 0) {
                    return 0;
                }
                latestMatching = gWiFiMatching;
                if (latestMatching->mMode == WIFI_MATCH_MODE_SERVER &&
                    latestMatching->mNewParticipantCallback != NULL) {
                    gWiFiMatching->mNewParticipantCallback(DWCi_GetFriendListIndex(profileId),
                                                           latestMatching->mNewParticipantCallbackArg);
                }
                sendValues[0] = gWiFiMatching->mNNCompletedCount;
                for (valueIndex = 1; valueIndex <= gWiFiMatching->mNNCompletedCount; valueIndex++) {
                    sendValues[valueIndex] = gWiFiMatching->mParticipantProfileIds[valueIndex];
                }
                latestMatching = gWiFiMatching;
                sendValues[valueIndex++] = latestMatching->mOwnAddress;
                sendValues[valueIndex++] = latestMatching->mOwnPort;
                latestMatching->mState = WIFI_MATCH_STATE_NEGOTIATE_SERVER;
            }
            if (result == WIFI_MATCH_COMMAND_NONE) {
                break;
            }
            if (DWCi_HandleMatchCommandError(
                    DWCi_SendMatchCommand(result, profileId, address, port, sendValues, valueIndex)) == 0) {
                break;
            }
            return 0;
        case WIFI_MATCH_COMMAND_RESERVE_OK:
            if (wiFiMatching->mState != WIFI_MATCH_STATE_RESERVING) {
                break;
            }
            if (profileId != wiFiMatching->mReplyProfileId) {
                break;
            }
            wiFiMatching->mPriorProfileId = 0;
            gWiFiMatching->mPriorResvDelayCount = 0;
            gWiFiMatching->mResvTimeoutMs = 0;
            gWiFiMatching->mResvDelayPending = 0;
            gWiFiMatching->mParticipantCommandAddresses[0] = (values + values[0])[1];
            gWiFiMatching->mParticipantCommandPorts[0] = (values + values[0])[2];
            gWiFiMatching->mServerAddress = (values + values[0])[1];
            gWiFiMatching->mServerPort = (values + values[0])[2];
            if (gWiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                if (DWCi_AreAllBuddies(values + 1, values[0]) != 0) {
                    if (gWiFiMatching->mLastParticipantPos != 0) {
                        DWCi_MakeBackupServerData(profileId, values);
                    }
                } else {
                    if (DWCi_HandleMatchCommandError(DWCi_CancelReservation(profileId)) != 0) {
                        return 0;
                    }
                    if (DWCi_HandleMatchCommandError(DWCi_SendResvCommandToFriend(0, 0)) == 0) {
                        break;
                    }
                    return 0;
                }
            }
            if (gWiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
                if (gWiFiMatching->mLastParticipantPos != 0) {
                    DWCi_MakeBackupServerData(profileId, values);
                    if (DWCi_HandleMatchCommandError(DWCi_ChangeToClient()) != 0) {
                        return 0;
                    }
                }
                gWiFiMatching->mState = WIFI_MATCH_STATE_NEGOTIATE_CLIENT;
                if (DWCi_HandleNNError(
                        DWCi_NNStartupAsync(0, 0, ServerBrowserGetServer(gWiFiMatching->mServerList, 0))) == 0) {
                    break;
                }
                return 0;
            } else {
                gWiFiMatching->mState = WIFI_MATCH_STATE_HOST_LOOKUP;
                if (DWCi_HandleSBError(DWCi_SBUpdateAsync(profileId)) == 0) {
                    break;
                }
                return 0;
            }
        case WIFI_MATCH_COMMAND_RESERVE_DENIED:
            if (wiFiMatching->mState != WIFI_MATCH_STATE_RESERVING) {
                break;
            }
            if (profileId != wiFiMatching->mReplyProfileId) {
                break;
            }
            return DWCi_RetryReserving();
        case WIFI_MATCH_COMMAND_RESERVE_WAIT:
            if (wiFiMatching->mState != WIFI_MATCH_STATE_RESERVING) {
                break;
            }
            if (profileId != wiFiMatching->mReplyProfileId) {
                break;
            }
            wiFiMatching->mResvTimeoutStartTick = OS_GetTick();
            if ((wiFiMatching->mPriorProfileId != 0 && wiFiMatching->mPriorResvDelayCount < 0x10) ||
                wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
                wiFiMatching->mResvDelayPending = 1;
                latestMatching = gWiFiMatching;
                latestMatching->mResvDelayStartTick = OS_GetTick();
                if (latestMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
                    break;
                }
                latestMatching->mPriorResvDelayCount++;
                break;
            }
            wiFiMatching->mPriorProfileId = 0;
            gWiFiMatching->mPriorResvDelayCount = 0;
            latestMatching = gWiFiMatching;
            if (latestMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
                latestMatching->mState = WIFI_MATCH_STATE_LIST_SEARCH;
                gWiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_SHORT;
                gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
            } else if (latestMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                DWCi_SendResvCommandToFriend(1, 0);
            }
            break;
        case WIFI_MATCH_COMMAND_CANCEL_RESERVE:
            if (wiFiMatching->mMresvPresent == 0) {
                break;
            }
            if (profileId != wiFiMatching->mMresvProfileId) {
                break;
            }
            if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER && wiFiMatching->mLastParticipantPos == 1 &&
                wiFiMatching->mParticipantProfileIds[1] == profileId) {
                gt2CloseAllConnectionsHard(*wiFiMatching->mConnectionSocket);
            }
            if (DWCi_CancelPreConnectedServerProcess(profileId) == 0) {
                return 0;
            }
            break;
        case WIFI_MATCH_COMMAND_CONNECT_INFO:
            firstValue = values[0];
            rawPort = values[1];
            if (wiFiMatching->mState == WIFI_MATCH_STATE_CONNECTED) {
                wiFiMatching->mState = WIFI_MATCH_STATE_NEGOTIATE_CLIENT;
            } else {
                if (wiFiMatching->mState != WIFI_MATCH_STATE_NEGOTIATE_CLIENT &&
                    wiFiMatching->mState != WIFI_MATCH_STATE_NEGOTIATE_SERVER) {
                    break;
                }
                if (profileId != wiFiMatching->mMresvProfileId) {
                    break;
                }
            }
            gWiFiMatching->mLastCommand = WIFI_MATCH_COMMAND_NONE;
            latestMatching = gWiFiMatching;
            profileIdEntry = &latestMatching->mParticipantProfileIds[latestMatching->mLastParticipantPos + 1];
            if (profileId != *profileIdEntry) {
                *profileIdEntry = profileId;
            }
            peerAddress.mAddress = firstValue;
            peerAddress.mPort = ((rawPort >> 8) & 0xff) | ((rawPort << 8) & 0xff00);
            gWiFiMatching->mNNInfo.mIsQR2 = 1;
            latestMatching = gWiFiMatching;
            DWCi_NNCompletedCallback(0, GetSocketDescriptor(*latestMatching->mConnectionSocket), &peerAddress,
                                     &latestMatching->mNNInfo);
            gWiFiMatching->mIncomingWaitStartTime = 0;
            break;
        case WIFI_MATCH_COMMAND_NEW_PARTICIPANT:
            valueProfileId = values[0];
            indexValue = values[1];
            wiFiMatching->mParticipantProfileIds[wiFiMatching->mNNCompletedCount + 1] = valueProfileId;
            gWiFiMatching->mParticipantIndices[gWiFiMatching->mNNCompletedCount + 1] = indexValue;
            qr2_send_statechanged(gWiFiMatching->mQr2);
            latestMatching = gWiFiMatching;
            if (latestMatching->mNewParticipantCallback == NULL) {
                break;
            }
            gWiFiMatching->mNewParticipantCallback(DWCi_GetFriendListIndex(valueProfileId),
                                                   latestMatching->mNewParticipantCallbackArg);
            break;
        case WIFI_MATCH_COMMAND_PARTICIPANT_INFO:
            firstValue = values[0];
            valueProfileId = firstValue;
            if (firstValue == 0) {
                indexValue = values[1];
                wiFiMatching->mParticipantIndices[indexValue] = values[2];
                gWiFiMatching->mParticipantProfileIds[indexValue] = gWiFiMatching->mOwnProfileId;
                DWCi_PostProcessConnection(3);
                break;
            }
            indexValue = values[1];
            aidValue = values[2];
            profileIdSlot = &wiFiMatching->mParticipantProfileIds[indexValue];
            if (firstValue == *profileIdSlot && indexValue == wiFiMatching->mLastParticipantPos - 1) {
                if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                        WIFI_MATCH_COMMAND_PARTICIPANT_ACK, profileId, wiFiMatching->mParticipantCommandAddresses[0],
                        wiFiMatching->mParticipantCommandPorts[0], &valueProfileId, 1)) == 0) {
                    break;
                }
                return 0;
            }
            *profileIdSlot = firstValue;
            gWiFiMatching->mParticipantIndices[indexValue] = aidValue;
            gWiFiMatching->mParticipantCommandAddresses[indexValue] = values[3];
            gWiFiMatching->mParticipantCommandPorts[indexValue] = values[4];
            gWiFiMatching->mServerAddress = values[3];
            gWiFiMatching->mServerPort = values[4];
            gWiFiMatching->mState = WIFI_MATCH_STATE_HOST_LOOKUP;
            if (DWCi_HandleSBError(DWCi_SBUpdateAsync(valueProfileId)) != 0) {
                return 0;
            }
            gWiFiMatching->mResvTimeoutMs = 0;
            gWiFiMatching->mResvDelayPending = 0;
            break;
        case WIFI_MATCH_COMMAND_PARTICIPANT_ACK:
            if (wiFiMatching->mState != WIFI_MATCH_STATE_INFORM_PEERS) {
                break;
            }
            if (values[0] != wiFiMatching->mParticipantProfileIds[wiFiMatching->mPostProcessPos + 1]) {
                break;
            }
            wiFiMatching->mPostProcessPos++;
            DWCi_PostProcessConnection(0);
            break;
        case WIFI_MATCH_COMMAND_RESUME_MATCHING:
            if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH ||
                DWCi_AreAllBuddies(values + 1, values[0]) != 0) {
                gWiFiMatching->mPriorProfileId = values[1];
                gWiFiMatching->mPriorResvDelayCount = 0;
            } else {
                gWiFiMatching->mPriorProfileId = 0;
            }
            latestMatching = gWiFiMatching;
            if (latestMatching->mLastParticipantPos != 0) {
                gt2CloseAllConnectionsHard(*latestMatching->mConnectionSocket);
                break;
            }
            if (DWCi_ResumeMatching() == 0) {
                break;
            }
            return 0;
        case WIFI_MATCH_COMMAND_CANCEL_HOST:
            if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH ||
                wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                if (DWCi_CancelPreConnectedClientProcess(profileId) != 0) {
                    break;
                }
                return 0;
            }
            if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
                if (values[0] == 0) {
                    wiFiMatching->mEventProfileId = profileId;
                    DWCi_CloseAllConnectionsByTimeout();
                    DWCi_RestartFromCancel(0);
                } else {
                    DWCi_CloseCancelHostAsync(values[0]);
                }
            }
            break;
        case WIFI_MATCH_COMMAND_CANCEL_SYN_FIRST:
        case WIFI_MATCH_COMMAND_CANCEL_SYN_SECOND:
        case WIFI_MATCH_COMMAND_CANCEL_SYN_THIRD:
            if (DWCi_ProcessCancelMatchSynCommand(profileId, command, values[0]) != FALSE) {
                break;
            }
            return 0;
        case WIFI_MATCH_COMMAND_CLOSE_CONNECTIONS:
            if (profileId != wiFiMatching->mParticipantProfileIds[0]) {
                return 1;
            }
            for (valueIndex = 0; valueIndex < valueCount; valueIndex++) {
                result = DWCi_GetAIDFromProfileID(values[valueIndex], 0);
                if (result != 0xff) {
                    DWC_CloseConnectionHard(result);
                }
            }
            break;
        case WIFI_MATCH_COMMAND_MIN_COMPLETE_QUERY:
            optMinComp = gOptMinComp;
            if (optMinComp != NULL && optMinComp->mValid != 0 &&
                MatchingGetTickMilliseconds() - optMinComp->mStartTime >= optMinComp->mTimeout) {
                sendValues[0] = 1;
            } else {
                sendValues[0] = 0;
            }
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(WIFI_MATCH_COMMAND_MIN_COMPLETE_REPLY, profileId,
                                                                   address, port, sendValues, 1)) == 0) {
                break;
            }
            return 0;
        case WIFI_MATCH_COMMAND_MIN_COMPLETE_REPLY:
            if (wiFiMatching->mState != WIFI_MATCH_STATE_MIN_COMPLETE_POLL) {
                break;
            }
            result = DWCi_GetAIDFromProfileID(profileId, 0);
            if (result == 0xff) {
                break;
            }
            BIT_SET(gOptMinComp->mRecvBit, result);
            if (values[0] != 0) {
                BIT_SET(gOptMinComp->mTimeoutBit, result);
            }
            break;
        case WIFI_MATCH_COMMAND_STOP_MATCHING:
            DWCi_StopMatching(10, -80000);
            return 0;
    }
    return 1;
}

s32 DWCi_CheckResvCommand(s32 profileId, u32 senderMode, s32 priorFlag) {
    s32 reply;

    switch (gWiFiMatching->mMode) {
        case WIFI_MATCH_MODE_BUDDY_LIST:
            if (GpIsBuddy(gWiFiMatching->mGpConnection, profileId) == 0) {
                reply = WIFI_MATCH_COMMAND_NONE;
                break;
            }
        case WIFI_MATCH_MODE_FILTER_SEARCH:
            if (senderMode != gWiFiMatching->mMode || gWiFiMatching->mStopPending != 0 ||
                gWiFiMatching->mNNCompletedCount == gWiFiMatching->mNumEntry ||
                (gWiFiMatching->mMresvPresent != 0 && gWiFiMatching->mMresvProfileId == gWiFiMatching->mOwnProfileId)) {
                reply = WIFI_MATCH_COMMAND_RESERVE_DENIED;
                if (gWiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH &&
                    gWiFiMatching->mQr2->mUserStateChangeRequested == FALSE && gWiFiMatching->mMresvPresent != 0 &&
                    gWiFiMatching->mMresvProfileId == gWiFiMatching->mOwnProfileId) {
                    qr2_send_statechanged(gWiFiMatching->mQr2);
                }
            } else if ((gWiFiMatching->mState != WIFI_MATCH_STATE_LIST_SEARCH &&
                        gWiFiMatching->mState != WIFI_MATCH_STATE_RESERVING) ||
                       (gWiFiMatching->mOwnAddress == 0 && gWiFiMatching->mOwnPort == 0)) {
                reply = WIFI_MATCH_COMMAND_RESERVE_WAIT;
            } else if (gWiFiMatching->mReplyProfileId != 0) {
                if (gWiFiMatching->mReplyProfileId == profileId) {
                    if (priorFlag != 0 || ((s32) gWiFiMatching->mOwnProfileId < profileId &&
                                           profileId != gWiFiMatching->mPriorProfileId)) {
                        reply = WIFI_MATCH_COMMAND_RESERVE_OK;
                    } else {
                        reply = WIFI_MATCH_COMMAND_NONE;
                    }
                } else if (priorFlag != 0 ||
                           ((s32) gWiFiMatching->mOwnProfileId < profileId && gWiFiMatching->mPriorProfileId == 0)) {
                    if (DWCi_HandleMatchCommandError(DWCi_CancelReservation(gWiFiMatching->mReplyProfileId)) != 0) {
                        return 0xff;
                    }
                    reply = WIFI_MATCH_COMMAND_RESERVE_OK;
                } else {
                    reply = WIFI_MATCH_COMMAND_RESERVE_DENIED;
                }
            } else {
                reply = WIFI_MATCH_COMMAND_RESERVE_OK;
            }
            break;
        case WIFI_MATCH_MODE_SERVER:
            if (GpIsBuddy(gWiFiMatching->mGpConnection, profileId) == 0) {
                reply = WIFI_MATCH_COMMAND_NONE;
            } else if (senderMode != WIFI_MATCH_MODE_SERVER_CLIENT ||
                       gWiFiMatching->mNNCompletedCount == gWiFiMatching->mNumEntry) {
                reply = WIFI_MATCH_COMMAND_RESERVE_DENIED;
            } else if (gOptSCBlock.mValid == 1 && gOptSCBlock.mLock == 1) {
                reply = WIFI_MATCH_COMMAND_STOP_MATCHING;
            } else if (gWiFiMatching->mState != WIFI_MATCH_STATE_ACCEPTING ||
                       (gWiFiMatching->mOwnAddress == 0 && gWiFiMatching->mOwnPort == 0)) {
                reply = WIFI_MATCH_COMMAND_RESERVE_WAIT;
            } else {
                reply = WIFI_MATCH_COMMAND_RESERVE_OK;
            }
            break;
    }
    return reply;
}

u32 DWCi_ProcessResvOK(u32 profileId, u32 address, u16 port) {
    u32 words[2];
    s32 participantPos;
    u32 result;

    if (gWiFiMatching->mMresvPresent != 0 && gWiFiMatching->mMresvProfileId == profileId) {
        return 0;
    }
    gWiFiMatching->mMresvPresent = 1;
    gWiFiMatching->mMresvProfileId = profileId;
    gWiFiMatching->mResvDelayPending = 0;
    gWiFiMatching->mResvTimeoutMs = 0;
    qr2_send_statechanged(gWiFiMatching->mQr2);
    gWiFiMatching->mReplyProfileId = 0;
    gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mNNCompletedCount + 1] = profileId;
    gWiFiMatching->mParticipantCommandAddresses[gWiFiMatching->mNNCompletedCount + 1] = address;
    gWiFiMatching->mParticipantCommandPorts[gWiFiMatching->mNNCompletedCount + 1] = port;
    gWiFiMatching->mServerAddress = address;
    gWiFiMatching->mServerPort = port;
    gWiFiMatching->mParticipantIndices[gWiFiMatching->mNNCompletedCount + 1] = DWCi_GetAIDFromList();
    words[0] = profileId;
    words[1] = gWiFiMatching->mParticipantIndices[gWiFiMatching->mNNCompletedCount + 1];
    for (participantPos = 1; participantPos <= gWiFiMatching->mNNCompletedCount; participantPos++) {
        result = DWCi_SendMatchCommand(WIFI_MATCH_COMMAND_NEW_PARTICIPANT,
                                       gWiFiMatching->mParticipantProfileIds[participantPos],
                                       gWiFiMatching->mParticipantCommandAddresses[participantPos],
                                       gWiFiMatching->mParticipantCommandPorts[participantPos], words, 2);
        if (result != 0) {
            return result;
        }
    }
    DWCi_InitOptMinCompParam(1);
    return 0;
}

void DWCi_MakeBackupServerData(u32 senderProfileId, u32 *values) {
    u32 len;

    len = values[0] + 2;
    if (len > 2) {
        MIi_CpuCopy32(values + 1, &gWiFiMatching->mReceivedList[2], (len - 2) * 4);
    }
    gWiFiMatching->mReceivedList[0] = len - 1;
    gWiFiMatching->mReceivedList[1] = senderProfileId;
}

u32 DWCi_HandleMatchCommandError(u32 result) {
    if (gWiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
        return DWCi_HandleSBError(result);
    }
    return ReportMatchingGpResult(result);
}

u32 DWCi_SendResvCommand(u32 profileId, s32 delay) {
    u32 words[3];
    SbServer *serverEntry;
    u32 wordCount;
    u32 resvKind;

    if (delay != 0) {
        gWiFiMatching->mResvDelayPending = 1;
        gWiFiMatching->mResvDelayStartTick = OS_GetTick();
        gWiFiMatching->mParticipantProfileIds[0] = profileId;
        return 0;
    }
    if (gWiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
        serverEntry = ServerBrowserGetServer(gWiFiMatching->mServerList, 0);
        gWiFiMatching->mParticipantProfileIds[0] = SbServerGetInt(serverEntry, gDwcPidKey, 0);
        gWiFiMatching->mParticipantCommandAddresses[0] = SBServerGetPublicInetAddress(serverEntry);
        gWiFiMatching->mParticipantCommandPorts[0] = SBServerGetPublicQueryPort(serverEntry);
        gWiFiMatching->mReplyProfileId = gWiFiMatching->mParticipantProfileIds[0];
        wordCount = 1;
    } else {
        if (gWiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
            gWiFiMatching->mParticipantProfileIds[0] = profileId;
        }
        gWiFiMatching->mReplyProfileId = profileId;
        words[1] = gWiFiMatching->mOwnAddress;
        words[2] = gWiFiMatching->mOwnPort;
        wordCount = 3;
    }
    gWiFiMatching->mResvTimeoutMs = 6000;
    gWiFiMatching->mResvTimeoutStartTick = OS_GetTick();
    gWiFiMatching->mResvDelayPending = 0;
    resvKind = gWiFiMatching->mPriorProfileId != 0 ? WIFI_MATCH_COMMAND_RESERVE_PRIORITY : WIFI_MATCH_COMMAND_RESERVE;
    words[0] = gWiFiMatching->mMode;
    return DWCi_SendMatchCommand(resvKind, profileId, gWiFiMatching->mParticipantCommandAddresses[0],
                                 gWiFiMatching->mParticipantCommandPorts[0], words, wordCount);
}

u32 DWCi_SendResvCommandToFriend(s32 delay, s32 init) {
    BOOL advanceFirst;
    s32 firstIndex;
    BOOL wrapped;
    s32 entryTextLength;
    char valueText[8];
    s32 buddy;
    char verText[12];
    GpBuddyStatus status;
    WiFiMatching *wiFiMatching;
    s32 profileId;
    u32 gpStatus;
    s32 participantPos;
    s32 verLen;
    s32 peerTextLength;

    if (init != 0) {
        firstIndex = gWiFiMatching->mBuddyEntryIndexPos;
    } else if (gWiFiMatching->mBuddyEntryIndexPos < gWiFiMatching->mBuddyEntryIndexCount - 1) {
        firstIndex = gWiFiMatching->mBuddyEntryIndexPos + 1;
    } else {
        firstIndex = 0;
    }
    wrapped = FALSE;
    advanceFirst = init == 0;
    while (1) {
        if (advanceFirst != FALSE || wrapped != FALSE) {
            gWiFiMatching->mBuddyEntryIndexPos++;
            if (gWiFiMatching->mBuddyEntryIndexPos >= gWiFiMatching->mBuddyEntryIndexCount) {
                gWiFiMatching->mBuddyEntryIndexPos = 0;
            }
        }
        if (wrapped != FALSE && gWiFiMatching->mBuddyEntryIndexPos == firstIndex) {
            gWiFiMatching->mResvTimeoutMs = 3000;
            gWiFiMatching->mResvTimeoutStartTick = OS_GetTick();
            gWiFiMatching->mResvDelayPending = 0;
            return 0;
        }
        wrapped = TRUE;
        wiFiMatching = gWiFiMatching;
        profileId = DWC_GetGsProfileId(
            DWCi_GetUserData(),
            (DWCAccFriendData *) (wiFiMatching->mBuddies +
                                  wiFiMatching->mBuddyEntryIndices[wiFiMatching->mBuddyEntryIndexPos] * 12));
        if (profileId == 0) {
            continue;
        }
        if (profileId == -1) {
            continue;
        }
        if (IsFriendDataTypeNonZeroWrapper(
                gWiFiMatching->mBuddies + gWiFiMatching->mBuddyEntryIndices[gWiFiMatching->mBuddyEntryIndexPos] * 12) ==
            0) {
            continue;
        }
        for (participantPos = 1; participantPos <= gWiFiMatching->mLastParticipantPos; participantPos++) {
            if (profileId == gWiFiMatching->mParticipantProfileIds[participantPos]) {
                break;
            }
        }
        if (participantPos <= gWiFiMatching->mLastParticipantPos) {
            continue;
        }
        gpStatus = GpGetBuddyIndex(gWiFiMatching->mGpConnection, profileId, &buddy);
        gpStatus |= GpGetBuddyStatus(gWiFiMatching->mGpConnection, buddy, &status);
        if (gpStatus != 0) {
            continue;
        }
        if (status.mStatus != 4) {
            continue;
        }
        verLen = DWC_GetCommonValueString("VER", verText, status.mStatusString, 0x2f);
        entryTextLength = DWC_GetCommonValueString("FME", valueText + 2, status.mStatusString, 0x2f);
        peerTextLength = DWC_GetCommonValueString("MDF", valueText, status.mStatusString, 0x2f);
        if (verLen > 0 && entryTextLength > 0 && peerTextLength > 0) {
            if (strtoul(verText, NULL, 10) == 3) {
                if (gWiFiMatching->mNumEntry == strtoul(valueText + 2, NULL, 10)) {
                    return DWCi_SendResvCommand(profileId, delay);
                }
            }
        }
    }
}

// Starts the search again: the server list in mode 0, the next buddy in mode 1.
u32 DWCi_RetryReserving(void) {
    WiFiMatching *wiFiMatching;

    gWiFiMatching->mPriorProfileId = 0;
    gWiFiMatching->mReplyProfileId = 0;
    gWiFiMatching->mPriorResvDelayCount = 0;
    wiFiMatching = gWiFiMatching;
    wiFiMatching->mResvTimeoutStartTick = OS_GetTick();
    if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
        wiFiMatching->mState = WIFI_MATCH_STATE_LIST_SEARCH;
        if (DWCi_HandleSBError(DWCi_SBUpdateAsync(0)) != 0) {
            return 0;
        }
    } else if (wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
        if (DWCi_HandleMatchCommandError(DWCi_SendResvCommandToFriend(0, 0)) != 0) {
            return 0;
        }
    } else if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
        DWCi_StopMatching(6, -80410);
        return 0;
    }
    return 1;
}

u32 DWCi_CancelReservation(u32 profileId) {
    u32 result;
    result = DWCi_SendMatchCommand(WIFI_MATCH_COMMAND_CANCEL_RESERVE, profileId,
                                   gWiFiMatching->mParticipantCommandAddresses[0],
                                   gWiFiMatching->mParticipantCommandPorts[0], NULL, 0);
    gWiFiMatching->mReplyProfileId = 0;
    return result;
}

u32 DWCi_CancelPreConnectedServerProcess(u32 clientPid) {
    s32 participantPos;
    u32 hostSide;

    if (gWiFiMatching->mMresvPresent != 0 && gWiFiMatching->mMresvProfileId == gWiFiMatching->mOwnProfileId) {
        hostSide = 0;
    } else {
        hostSide = 1;
    }
    if (hostSide != 0) {
        gWiFiMatching->mMresvPresent = 0;
        gWiFiMatching->mMresvProfileId = 0;
        qr2_send_statechanged(gWiFiMatching->mQr2);
    }
    if (gWiFiMatching->mLastParticipantPos < 0x1f) {
        gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1] = 0;
    }
    gWiFiMatching->mLastCommand = WIFI_MATCH_COMMAND_NONE;
    if (gWiFiMatching->mNNInfo.mCookie != 0) {
        NNCancel(gWiFiMatching->mNNInfo.mCookie);
        gWiFiMatching->mNNInfo.mCookie = 0;
    }
    gWiFiMatching->mNNCompletedCount = gWiFiMatching->mLastParticipantPos;
    gWiFiMatching->mReplyProfileId = 0;
    if (hostSide == 0) {
        if (gWiFiMatching->mMode != WIFI_MATCH_MODE_SERVER_CLIENT) {
            DWCi_RestartFromTimeout();
        }
    } else if (gWiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
        gWiFiMatching->mState = WIFI_MATCH_STATE_LIST_SEARCH;
        gWiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_LONG;
        gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
    } else if (gWiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
        gWiFiMatching->mState = WIFI_MATCH_STATE_RESERVING;
        DWCi_SendResvCommandToFriend(1, 0);
    } else if (gWiFiMatching->mMode == WIFI_MATCH_MODE_SERVER) {
        gWiFiMatching->mState = WIFI_MATCH_STATE_CANCEL_SERVER;
        gWiFiMatching->mCancelSynReplyMask = 0;
        gWiFiMatching->mCancelSynLatency = 0;
        DWCi_CloseCancelHostAsync(clientPid);
        for (participantPos = 1; participantPos <= gWiFiMatching->mLastParticipantPos; participantPos++) {
            if (DWCi_SendCancelMatchSynCommand(gWiFiMatching->mParticipantProfileIds[participantPos],
                                               WIFI_MATCH_COMMAND_CANCEL_SYN_FIRST) == 0) {
                return 0;
            }
        }
        if (gWiFiMatching->mLastParticipantPos == 0) {
            DWCi_RestartFromCancel(2);
        }
    }
    return 1;
}

u32 DWCi_CancelPreConnectedClientProcess(u32 serverPid) {
    u32 result;

    result = 1;
    if (gWiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
        if (gWiFiMatching->mLastParticipantPos != 0) {
            DWCi_CloseAllConnectionsByTimeout();
        }
        DWCi_StopMatching(6, -80430);
        return 0;
    }
    gWiFiMatching->mNNCompletedCount = gWiFiMatching->mLastParticipantPos;
    gWiFiMatching->mPriorProfileId = 0;
    if (gWiFiMatching->mNNInfo.mCookie != 0) {
        NNCancel(gWiFiMatching->mNNInfo.mCookie);
        gWiFiMatching->mNNInfo.mCookie = 0;
    }
    if (gWiFiMatching->mLastParticipantPos != 0) {
        DWCi_RestartFromTimeout();
    } else {
        gWiFiMatching->mState = WIFI_MATCH_STATE_RESERVING;
        result = DWCi_RetryReserving();
    }
    return result;
}

u32 DWCi_ChangeToClient(void) {
    s32 participantPos;
    u32 sendResult;

    for (participantPos = 1; participantPos <= gWiFiMatching->mLastParticipantPos; participantPos++) {
        sendResult = DWCi_SendMatchCommand(WIFI_MATCH_COMMAND_RESUME_MATCHING,
                                           gWiFiMatching->mParticipantProfileIds[participantPos],
                                           gWiFiMatching->mParticipantCommandAddresses[participantPos],
                                           gWiFiMatching->mParticipantCommandPorts[participantPos],
                                           gWiFiMatching->mReceivedList, gWiFiMatching->mReceivedList[0] + 1);
        if (sendResult != 0) {
            return sendResult;
        }
    }
    gWiFiMatching->mMresvPresent = 0;
    gWiFiMatching->mMresvProfileId = 0;
    gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_IGNORE_CALLBACK;
    gt2CloseAllConnectionsHard(*gWiFiMatching->mConnectionSocket);
    gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_NONE;
    return 0;
}

void DWCi_PostProcessConnection(s32 type) {
    WiFiMatching *wiFiMatching;
    u32 words[4];
    s32 wordCount;
    s32 clearFlag;
    s32 participantPos;
    BOOL eventProfileZero;
    wordCount = 3;
    clearFlag = 0;
    switch (type) {
        case 0:
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mPostProcessPos < wiFiMatching->mLastParticipantPos - 1) {
                wiFiMatching->mState = WIFI_MATCH_STATE_INFORM_PEERS;
                wiFiMatching = gWiFiMatching;
                words[0] = wiFiMatching->mParticipantProfileIds[wiFiMatching->mPostProcessPos + 1];
                words[1] = wiFiMatching->mPostProcessPos + 1;
                words[2] = wiFiMatching->mParticipantIndices[wiFiMatching->mPostProcessPos + 1];
                words[3] = wiFiMatching->mParticipantCommandAddresses[wiFiMatching->mPostProcessPos + 1];
                words[4] = wiFiMatching->mParticipantCommandPorts[wiFiMatching->mPostProcessPos + 1];
                wordCount = 5;
            } else {
                wiFiMatching->mMresvPresent = 0;
                gWiFiMatching->mMresvProfileId = 0;
                qr2_send_statechanged(gWiFiMatching->mQr2);
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
                    wiFiMatching->mState = WIFI_MATCH_STATE_LIST_SEARCH;
                } else if (wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                    wiFiMatching->mState = WIFI_MATCH_STATE_RESERVING;
                } else {
                    wiFiMatching->mState = WIFI_MATCH_STATE_ACCEPTING;
                }
                gWiFiMatching->mPostProcessPos = 0;
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER ||
                    wiFiMatching->mLastParticipantPos == wiFiMatching->mNumEntry) {
                    if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER) {
                        wiFiMatching = gWiFiMatching;
                        wiFiMatching->mEventProfileId =
                            wiFiMatching->mParticipantProfileIds[wiFiMatching->mLastParticipantPos];
                    } else {
                        wiFiMatching->mEventProfileId = 0;
                        wiFiMatching = gWiFiMatching;
                        wiFiMatching->mParticipantProfileIds[0] = wiFiMatching->mOwnProfileId;
                    }
                    gWiFiMatching->mState = WIFI_MATCH_STATE_SYN_SERVER;
                    gWiFiMatching->mSynReplyMask = 0;
                    for (participantPos = 1; participantPos <= gWiFiMatching->mLastParticipantPos; participantPos++) {
                        DWCi_SendMatchSynPacket(gWiFiMatching->mParticipantIndices[participantPos],
                                                WIFI_MESSAGE_KIND_SYNC_REQUEST);
                    }
                } else {
                    words[0] = 0;
                    words[1] = wiFiMatching->mLastParticipantPos;
                    words[2] = wiFiMatching->mParticipantIndices[wiFiMatching->mLastParticipantPos];
                    if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
                        wiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_LONG;
                        gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                    } else if (wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                        DWCi_SendResvCommandToFriend(1, 0);
                    }
                }
                if (gWiFiMatching->mMode != WIFI_MATCH_MODE_SERVER) {
                    clearFlag = 1;
                }
            }
            if (gWiFiMatching->mState == WIFI_MATCH_STATE_SYN_SERVER) {
                break;
            }
            wiFiMatching = gWiFiMatching;
            participantPos = wiFiMatching->mLastParticipantPos;
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                    WIFI_MATCH_COMMAND_PARTICIPANT_INFO, wiFiMatching->mParticipantProfileIds[participantPos],
                    wiFiMatching->mParticipantCommandAddresses[participantPos],
                    wiFiMatching->mParticipantCommandPorts[participantPos], words, wordCount)) != 0) {
                return;
            }
            gWiFiMatching->mResendCount = 0;
            break;
        case 1:
            gWiFiMatching->mState = WIFI_MATCH_STATE_CONNECTED;
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
                wiFiMatching->mEventProfileId = wiFiMatching->mParticipantProfileIds[wiFiMatching->mLastParticipantPos];
            }
            clearFlag = 1;
            break;
        case 2:
            gWiFiMatching->mState = WIFI_MATCH_STATE_CONNECTED;
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH ||
                wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                wiFiMatching->mMresvPresent = 1;
                gWiFiMatching->mMresvProfileId = gWiFiMatching->mOwnProfileId;
            }
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mLastParticipantPos > 1) {
                if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                        WIFI_MATCH_COMMAND_PARTICIPANT_ACK, wiFiMatching->mParticipantProfileIds[0],
                        wiFiMatching->mParticipantCommandAddresses[0], wiFiMatching->mParticipantCommandPorts[0],
                        &wiFiMatching->mParticipantProfileIds[wiFiMatching->mLastParticipantPos - 1], 1)) != 0) {
                    return;
                }
            }
            break;
        case 3:
            gWiFiMatching->mState = WIFI_MATCH_STATE_CONNECTED;
            gWiFiMatching->mEventProfileId = clearFlag;
            clearFlag = 1;
            break;
        case 4:
            if (gWiFiMatching->mMode != WIFI_MATCH_MODE_SERVER) {
                DWCi_SetGPStatus(2, "", (void *) clearFlag);
            }
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mEventProfileId == 0) {
                eventProfileZero = TRUE;
            } else {
                eventProfileZero = FALSE;
            }
            gWiFiMatching->mResultCallback(0, 0, eventProfileZero, 0,
                                           DWCi_GetFriendListIndex(gWiFiMatching->mEventProfileId),
                                           wiFiMatching->mResultCallbackArg);
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH ||
                wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                DWCi_CloseMatching();
            } else {
                if (wiFiMatching->mServerList != NULL) {
                    ServerBrowserFree(wiFiMatching->mServerList);
                    gWiFiMatching->mServerList = NULL;
                }
                NNFreeNegotiateList();
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER) {
                    if (ReportMatchingGpResult(DWCi_GPSetServerStatus()) != 0) {
                        return;
                    }
                    if (gOptSCBlock.mValid == 1) {
                        gOptSCBlock.mLock = 1;
                    }
                    gWiFiMatching->mState = WIFI_MATCH_STATE_ACCEPTING;
                } else {
                    wiFiMatching->mState = WIFI_MATCH_STATE_CONNECTED;
                }
                gWiFiMatching->mEventProfileId = 0;
            }
            gWiFiMatching->mStopPending = 0;
            break;
    }
    if (clearFlag != 0) {
        wiFiMatching = gWiFiMatching;
        if (wiFiMatching->mMode != WIFI_MATCH_MODE_SERVER_CLIENT) {
            ServerBrowserClear(wiFiMatching->mServerList);
        }
    }
}

u32 DWCi_AreAllBuddies(u32 *pidList, u32 pidListLen) {
    WiFiMatching *wiFiMatching;
    u32 pidIndex;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mDistantFriend != 0 && wiFiMatching->mState == WIFI_MATCH_STATE_RESERVING) {
        return 1;
    }
    for (pidIndex = 0; pidIndex < pidListLen; pidIndex++) {
        if (GpIsBuddy(wiFiMatching->mGpConnection, *pidList) == 0) {
            return 0;
        }
        wiFiMatching = gWiFiMatching;
        if (wiFiMatching->mDistantFriend != 0 && wiFiMatching->mState == WIFI_MATCH_STATE_CONNECTED) {
            return 1;
        }
        pidList++;
    }
    return 1;
}

void DWCi_DoCancelMatching(void) {
    WiFiMatching *wiFiMatching;
    u32 word;
    gWiFiMatching->mEventProfileId = 0;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mState == WIFI_MATCH_STATE_LIST_FIRST_UPDATE) {
        DWCi_FinishCancelMatching();
        return;
    }
    wiFiMatching->mStopPending = 1;
    wiFiMatching = gWiFiMatching;
    word = wiFiMatching->mMode;
    if (word == WIFI_MATCH_MODE_SERVER_CLIENT) {
        wiFiMatching->mStopPending = 1;
        wiFiMatching = gWiFiMatching;
        if (wiFiMatching->mLastParticipantPos != 0) {
            gt2CloseAllConnectionsHard(*wiFiMatching->mConnectionSocket);
        } else {
            if (DWCi_HandleMatchCommandError(DWCi_CancelReservation(wiFiMatching->mParticipantProfileIds[0])) != 0) {
                return;
            }
        }
        DWCi_FinishCancelMatching();
        return;
    }
    if (wiFiMatching->mState == WIFI_MATCH_STATE_RESERVING || wiFiMatching->mState == WIFI_MATCH_STATE_HOST_LOOKUP ||
        wiFiMatching->mState == WIFI_MATCH_STATE_NEGOTIATE_CLIENT ||
        wiFiMatching->mState == WIFI_MATCH_STATE_CONNECT_CLIENT ||
        wiFiMatching->mState == WIFI_MATCH_STATE_NEGOTIATE_SERVER ||
        wiFiMatching->mState == WIFI_MATCH_STATE_CONNECT_SERVER) {
        if (wiFiMatching->mReplyProfileId != 0) {
            if (DWCi_HandleMatchCommandError(DWCi_CancelReservation(wiFiMatching->mParticipantProfileIds[0])) != 0) {
                return;
            }
        }
        if (DWCi_HandleMatchCommandError(DWCi_InvalidateReservation()) != 0) {
            return;
        }
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mNNInfo.mCookie != 0) {
        NNCancel(wiFiMatching->mNNInfo.mCookie);
        gWiFiMatching->mNNInfo.mCookie = 0;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mLastParticipantPos != 0) {
        wiFiMatching->mStopPending = 1;
        gt2CloseAllConnectionsHard(*gWiFiMatching->mConnectionSocket);
    }
    DWCi_FinishCancelMatching();
}

void DWCi_FinishCancelMatching(void) {
    WiFiMatching *wiFiMatching;
    BOOL isServer;
    BOOL isSelf;
    u32 eventProfileId;
    if (ReportMatchingGpResult(DWCi_SetGPStatus(1, "", NULL)) == 0) {
        DWCi_CloseMatching();
        wiFiMatching = gWiFiMatching;
        eventProfileId = wiFiMatching->mEventProfileId;
        if (eventProfileId != 0) {
            isServer = TRUE;
        } else if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER) {
            isServer = TRUE;
        } else {
            isServer = FALSE;
        }
        if (eventProfileId == 0) {
            isSelf = TRUE;
        } else {
            isSelf = FALSE;
        }
        gWiFiMatching->mResultCallback(0, 1, isSelf, isServer, DWCi_GetFriendListIndex(eventProfileId),
                                       wiFiMatching->mResultCallbackArg);
        gWiFiMatching->mStopPending = 0;
    }
}

u32 DWCi_InvalidateReservation(void) {
    u32 result;
    u32 word;
    s32 hostIndex;
    volatile WiFiMatching *wiFiMatching; // fields are read again on each use
    result = 0;
    word = 0;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMresvPresent != 0 && wiFiMatching->mMresvProfileId != 0 &&
        wiFiMatching->mMresvProfileId != wiFiMatching->mOwnProfileId) {
        hostIndex = wiFiMatching->mLastParticipantPos + 1;
        result = DWCi_SendMatchCommand(WIFI_MATCH_COMMAND_CANCEL_HOST, wiFiMatching->mMresvProfileId,
                                       wiFiMatching->mParticipantCommandAddresses[hostIndex],
                                       wiFiMatching->mParticipantCommandPorts[hostIndex], &word, 1);
        gWiFiMatching->mMresvPresent = 0;
        gWiFiMatching->mMresvProfileId = 0;
    }
    return result;
}

void DWCi_RestartFromCancel(s32 level) {
    WiFiMatching *wiFiMatching;
    s32 unusedLocal;
    BOOL isSelf;
    if (level == 0) {
        DWCi_FinishCancelMatching();
        return;
    }
    DWCi_ResetMatchParam(level);
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER || wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
        if (wiFiMatching->mEventProfileId == 0) {
            isSelf = TRUE;
        } else {
            isSelf = FALSE;
        }
        gWiFiMatching->mResultCallback(0, 1, isSelf, 0, DWCi_GetFriendListIndex(wiFiMatching->mEventProfileId),
                                       wiFiMatching->mResultCallbackArg);
    } else if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
        if (level == 1) {
            if (DWCi_HandleSBError(DWCi_SBUpdateAsync(0)) != 0) {
                return;
            }
        }
    } else if (wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
        if (level == 1) {
            DWCi_SendResvCommandToFriend(0, 0);
        }
    }
}

void DWCi_RestartFromTimeout(void) {
    WiFiMatching *wiFiMatching;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMode != WIFI_MATCH_MODE_SERVER && wiFiMatching->mMode != WIFI_MATCH_MODE_SERVER_CLIENT) {
        DWCi_CloseAllConnectionsByTimeout();
        DWCi_RestartFromCancel(1);
    }
}

u32 DWCi_ResumeMatching(void) {
    u32 result;
    WiFiMatching *wiFiMatching;
    gWiFiMatching->mMresvPresent = 0;
    gWiFiMatching->mMresvProfileId = 0;
    gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_NONE;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mPriorProfileId != 0) {
        if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
            wiFiMatching->mState = WIFI_MATCH_STATE_LIST_SEARCH;
            result = DWCi_SBUpdateAsync(0);
            if (DWCi_HandleSBError(result) != 0) {
                return result;
            }
        } else if (wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
            wiFiMatching->mState = WIFI_MATCH_STATE_RESERVING;
            result = DWCi_SendResvCommand(gWiFiMatching->mPriorProfileId, 0);
            if (DWCi_HandleMatchCommandError(result) != 0) {
                return result;
            }
        }
    } else {
        DWCi_RestartFromCancel(1);
    }
    return 0;
}

u32 DWCi_CloseCancelHostAsync(u32 profileId) {
    void **connection;
    gWiFiMatching->mEventProfileId = profileId;
    connection = DWCi_GetGT2ConnectionByProfileID(profileId, gWiFiMatching->mLastParticipantPos + 1);
    if (connection != NULL) {
        gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_IGNORE_CALLBACK_AND_SC_CANCEL;
        gt2CloseConnectionHard(*connection);
        gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_NONE;
        return 1;
    }
    DWCi_DeleteHostByProfileID(profileId, gWiFiMatching->mLastParticipantPos + 1);
    return 0;
}

void DWCi_CloseAllConnectionsByTimeout(void) {
    gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_IGNORE_CALLBACK_AND_SC_CANCEL;
    gt2CloseAllConnectionsHard(*gWiFiMatching->mConnectionSocket);
    gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_NONE;
}

// Tells the participants in the mask to drop the others, then closes the connections to those not in the mask.
u32 DWCi_CloseShutdownClientSC(u32 mask) {
    u32 idList[32];
    u32 validIds[32];
    s32 validCount;
    s32 idCount;
    s32 participantPos;
    s32 idIndex;
    u32 aidBit;
    WiFiMatching *wiFiMatching;
    idCount = 0;
    validCount = 0;
    participantPos = 1;
    wiFiMatching = gWiFiMatching;
    for (; participantPos <= wiFiMatching->mLastParticipantPos; participantPos++) {
        aidBit = 1 << gWiFiMatching->mParticipantIndices[participantPos];
        if ((mask & aidBit) != 0) {
            validIds[validCount] = wiFiMatching->mParticipantProfileIds[participantPos];
            validCount++;
        } else {
            idList[idCount] = wiFiMatching->mParticipantProfileIds[participantPos];
            idCount++;
        }
    }
    for (idIndex = 0; idIndex < validCount; idIndex++) {
        if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(WIFI_MATCH_COMMAND_CLOSE_CONNECTIONS, validIds[idIndex],
                                                               0, 0, idList, idCount)) != 0) {
            return 0;
        }
    }
    gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_IGNORE_CALLBACK_AND_SC_CANCEL;
    for (idIndex = 0; idIndex < idCount; idIndex++) {
        s32 aid;
        aid = DWCi_GetAIDFromProfileID(idList[idIndex], 0);
        if (aid != 0xff) {
            DWC_CloseConnectionHard(aid);
        }
    }
    gWiFiMatching->mCloseKind = WIFI_MATCH_CLOSE_NONE;
    return 1;
}

void DWCi_SendMatchSynPacket(s32 peerIndex, u16 kind) {
    u8 hostIndex;
    u8 payload[3];
    volatile WiFiMatching *wiFiMatching; // fields are read again on each use
    switch (kind) {
        case WIFI_MESSAGE_KIND_SYNC_REQUEST:
            wiFiMatching = gWiFiMatching;
            if (peerIndex == wiFiMatching->mParticipantIndices[wiFiMatching->mLastParticipantPos]) {
                payload[0] = 1;
            } else {
                payload[0] = 0;
            }
            for (hostIndex = 1; hostIndex <= wiFiMatching->mLastParticipantPos; hostIndex++) {
                if (peerIndex == wiFiMatching->mParticipantIndices[hostIndex]) {
                    payload[1] = hostIndex;
                    payload[2] = peerIndex;
                    break;
                }
            }
            break;
        case WIFI_MESSAGE_KIND_SYNC_REPLY:
            wiFiMatching = gWiFiMatching;
            payload[0] = wiFiMatching->mSynLatency;
            payload[1] = wiFiMatching->mSynLatency >> 8;
            break;
    }
    DWCi_SendReliable(kind, peerIndex, payload, 4);
    gWiFiMatching->mLastPeerMessageSendTime = MatchingGetTickMilliseconds();
}

u32 DWCi_ProcessMatchSynTimeout(void) {
    WiFiMatching *wiFiMatching;
    u64 elapsed;
    s32 participantPos;
    u8 aid;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mState == WIFI_MATCH_STATE_SYN_CLIENT || wiFiMatching->mState == WIFI_MATCH_STATE_SYN_SERVER ||
        wiFiMatching->mState == WIFI_MATCH_STATE_SYN_SERVER_DELAY) {
        elapsed = MatchingGetTickMilliseconds() - wiFiMatching->mLastPeerMessageSendTime;
    } else {
        return 1;
    }
    switch (wiFiMatching->mState) {
        case WIFI_MATCH_STATE_SYN_CLIENT:
            if (elapsed > 6000) {
                DWCi_SendMatchSynPacket(wiFiMatching->mParticipantIndices[0], WIFI_MESSAGE_KIND_SYNC_REPLY);
            }
            break;
        case WIFI_MATCH_STATE_SYN_SERVER:
            if (elapsed > 6000) {
                wiFiMatching->mSynResendCounts[0]++;
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mSynResendCounts[0] > 5) {
                    if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH ||
                        wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST) {
                        DWCi_CloseAllConnectionsByTimeout();
                        DWCi_RestartFromCancel(1);
                        break;
                    }
                    if (DWCi_CloseShutdownClientSC(wiFiMatching->mSynReplyMask) == 0) {
                        return 0;
                    }
                    wiFiMatching = gWiFiMatching;
                    if (wiFiMatching->mLastParticipantPos != 0) {
                        wiFiMatching->mSynResendCounts[0] = 0;
                        gWiFiMatching->mLastPeerMessageSendTime = MatchingGetTickMilliseconds();
                    } else {
                        if (DWCi_CancelPreConnectedServerProcess(wiFiMatching->mEventProfileId) == 0) {
                            return 0;
                        }
                    }
                } else {
                    for (participantPos = 1; participantPos <= wiFiMatching->mLastParticipantPos;
                         participantPos++, wiFiMatching = gWiFiMatching) {
                        wiFiMatching = gWiFiMatching;
                        aid = wiFiMatching->mParticipantIndices[participantPos];
                        if ((wiFiMatching->mSynReplyMask & (1 << aid)) == 0) {
                            DWCi_SendMatchSynPacket(aid, WIFI_MESSAGE_KIND_SYNC_REQUEST);
                        }
                    }
                }
            }
            break;
        case WIFI_MATCH_STATE_SYN_SERVER_DELAY:
            if (wiFiMatching->mSynLatency < elapsed) {
                DWCi_PostProcessConnection(4);
            }
            break;
    }
    return 1;
}

u32 DWCi_SendCancelMatchSynCommand(u32 profileId, u32 command) {
    u32 word;
    u32 len;
    if (command == WIFI_MATCH_COMMAND_CANCEL_SYN_FIRST) {
        word = gWiFiMatching->mEventProfileId;
        len = 1;
    } else {
        len = 0;
    }
    if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(command, profileId, 0, 0, &word, len)) != 0) {
        return 0;
    }
    gWiFiMatching->mLastCancelSynSendTime = MatchingGetTickMilliseconds();
    return 1;
}

BOOL DWCi_ProcessCancelMatchSynCommand(u32 profileId, s32 command, u32 data) {
    WiFiMatching *wiFiMatching;
    u64 now;
    u64 lastSent;
    u64 halfRoundTrip;
    u32 mask;
    s32 participantPos;
    u32 aid;
    if (DWC_GetState() != WIFI_CONNECTION_MATCHED) {
        return TRUE;
    }
    switch (command) {
        case WIFI_MATCH_COMMAND_CANCEL_SYN_FIRST:
            if (gWiFiMatching->mState != WIFI_MATCH_STATE_CANCEL_CLIENT) {
                gWiFiMatching->mState = WIFI_MATCH_STATE_CANCEL_CLIENT;
                DWCi_CloseCancelHostAsync(data);
            }
            if (DWCi_SendCancelMatchSynCommand(profileId, WIFI_MATCH_COMMAND_CANCEL_SYN_SECOND) == 0) {
                return FALSE;
            }
            break;
        case WIFI_MATCH_COMMAND_CANCEL_SYN_SECOND:
            if (gWiFiMatching->mState == WIFI_MATCH_STATE_CANCEL_SERVER) {
                now = MatchingGetTickMilliseconds();
                wiFiMatching = gWiFiMatching;
                lastSent = wiFiMatching->mLastCancelSynSendTime;
                if (lastSent + 600 < now) {
                    halfRoundTrip = ((now - lastSent) >> 1) - 300;
                    if (wiFiMatching->mCancelSynLatency < halfRoundTrip) {
                        wiFiMatching->mCancelSynLatency = halfRoundTrip;
                    }
                }
                aid = DWCi_GetAIDFromProfileID(profileId, 0);
                if (aid != 0xff) {
                    BIT_SET(gWiFiMatching->mCancelSynReplyMask, aid);
                }
                mask = DWCi_GetAIDBitmask(1);
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mCancelSynReplyMask == mask) {
                    for (participantPos = 1; participantPos <= wiFiMatching->mLastParticipantPos;
                         participantPos++, wiFiMatching = gWiFiMatching) {
                        if (DWCi_SendCancelMatchSynCommand(wiFiMatching->mParticipantProfileIds[participantPos],
                                                           WIFI_MATCH_COMMAND_CANCEL_SYN_THIRD) == 0) {
                            return FALSE;
                        }
                    }
                    wiFiMatching->mState = WIFI_MATCH_STATE_CANCEL_SERVER_DELAY;
                }
            } else {
                if (DWCi_SendCancelMatchSynCommand(profileId, WIFI_MATCH_COMMAND_CANCEL_SYN_THIRD) == 0) {
                    return FALSE;
                }
            }
            break;
        case WIFI_MATCH_COMMAND_CANCEL_SYN_THIRD:
            if (gWiFiMatching->mState == WIFI_MATCH_STATE_CANCEL_CLIENT) {
                DWCi_RestartFromCancel(2);
            }
            break;
    }
    return TRUE;
}

u32 DWCi_ProcessCancelMatchSynTimeout(void) {
    WiFiMatching *wiFiMatching;
    u64 elapsed;
    s32 participantPos;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mState == WIFI_MATCH_STATE_CANCEL_CLIENT ||
        wiFiMatching->mState == WIFI_MATCH_STATE_CANCEL_SERVER ||
        wiFiMatching->mState == WIFI_MATCH_STATE_CANCEL_SERVER_DELAY) {
        elapsed = MatchingGetTickMilliseconds() - wiFiMatching->mLastCancelSynSendTime;
    } else {
        return 1;
    }
    switch (wiFiMatching->mState) {
        case WIFI_MATCH_STATE_CANCEL_CLIENT:
            if (elapsed > 6000) {
                if (DWCi_SendCancelMatchSynCommand(wiFiMatching->mParticipantProfileIds[0],
                                                   WIFI_MATCH_COMMAND_CANCEL_SYN_SECOND) == 0) {
                    return 0;
                }
            }
            break;
        case WIFI_MATCH_STATE_CANCEL_SERVER:
            if (elapsed > 6000) {
                wiFiMatching->mSynResendCounts[1]++;
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mSynResendCounts[1] > 5) {
                    if (DWCi_CloseShutdownClientSC(wiFiMatching->mCancelSynReplyMask) == 0) {
                        return 0;
                    }
                    wiFiMatching = gWiFiMatching;
                    if (wiFiMatching->mLastParticipantPos != 0) {
                        wiFiMatching->mSynResendCounts[1] = 0;
                        gWiFiMatching->mLastCancelSynSendTime = MatchingGetTickMilliseconds();
                    } else {
                        DWCi_RestartFromCancel(2);
                    }
                } else {
                    for (participantPos = 1; participantPos <= wiFiMatching->mLastParticipantPos;
                         participantPos++, wiFiMatching = gWiFiMatching) {
                        if ((gWiFiMatching->mCancelSynReplyMask &
                             (1 << gWiFiMatching->mParticipantIndices[participantPos])) == 0) {
                            if (DWCi_SendCancelMatchSynCommand(wiFiMatching->mParticipantProfileIds[participantPos],
                                                               13) == 0) {
                                return 0;
                            }
                        }
                    }
                }
            }
            break;
        case WIFI_MATCH_STATE_CANCEL_SERVER_DELAY:
            if (wiFiMatching->mCancelSynLatency < elapsed) {
                DWCi_RestartFromCancel(2);
            }
            break;
    }
    return 1;
}

u8 DWCi_GetNewMatchKey(void) {
    u8 keyIndex = 0;
    do {
        if (gMatchingKeys[keyIndex].mKeyId == 0) {
            return keyIndex + 100;
        }
        keyIndex++;
    } while (keyIndex < 154);
    return 0;
}

void DWCi_ClearGameMatchKeys(void) {
    s32 keyIndex;
    volatile u32 fillValue;
    MatchingKey *matchingKey;
    keyIndex = 0;
    matchingKey = gMatchingKeys;
    for (; keyIndex < 0x9a; keyIndex++) {
        if (matchingKey->mString != NULL) {
            DWC_Free(4, matchingKey->mString, 0);
        }
        matchingKey++;
    }
    fillValue = 0;
    MIi_CpuClear32(fillValue, gMatchingKeys, 0x738);
}

u8 DWCi_GetAIDFromList(void) {
    u8 aid;
    s32 participantPos;
    volatile WiFiMatching *wiFiMatching; // fields are read again on each use
    aid = 0;
    wiFiMatching = gWiFiMatching;
    for (; aid < 0x20; aid++) {
        for (participantPos = 0; participantPos <= wiFiMatching->mNNCompletedCount; participantPos++) {
            if (aid == wiFiMatching->mParticipantIndices[participantPos]) {
                break;
            }
        }
        if (participantPos > wiFiMatching->mNNCompletedCount) {
            break;
        }
    }
    return aid;
}

s32 DWCi_CheckDWCServer(SbServer *server) {
    if (SbServerGetInt(server, "numplayers", -1) == -1) {
        return 0;
    }
    if (SbServerGetInt(server, "maxplayers", -1) == -1) {
        return 0;
    }
    if (SbServerGetInt(server, "dwc_mtype", -1) == -1) {
        return 0;
    }
    if (SbServerGetInt(server, "dwc_mresv", -1) == -1 && SbServerGetInt(server, "dwc_mresv", 0) == 0) {
        return 0;
    }
    if (SbServerGetInt(server, "dwc_mver", -1) == -1) {
        return 0;
    }
    return SbServerGetInt(server, gDwcPidKey, 0);
}

s32 DWCi_GetAIDFromProfileID(u32 profileId, s32 participantPos) {
    if (participantPos == 0) {
        participantPos = 1;
    } else {
        participantPos = 0;
    }
    for (; participantPos <= gWiFiMatching->mLastParticipantPos; participantPos++) {
        if (profileId == gWiFiMatching->mParticipantProfileIds[participantPos]) {
            return gWiFiMatching->mParticipantIndices[participantPos];
        }
    }
    return 0xff;
}

u32 DWCi_GetAIDBitmask(s32 valid) {
    s32 participantPos;
    u32 mask = 0;

    if (valid != 0) {
        return gWiFiMatching->mParticipantMask & ~1;
    }
    for (participantPos = 1; participantPos <= gWiFiMatching->mLastParticipantPos; participantPos++) {
        mask |= 1 << gWiFiMatching->mParticipantIndices[participantPos];
    }
    return mask;
}

void DWCi_InitOptMinCompParam(s32 reset) {
    DWCMatchOptMinCompleteIn *optMinComp;
    optMinComp = gOptMinComp;
    if (optMinComp != NULL && optMinComp->mValid != 0) {
        optMinComp->mRecvBit = 0;
        gOptMinComp->mTimeoutBit = 0;
        gOptMinComp->mRetry = 0;
        gOptMinComp->mLastPollTime = MatchingGetTickMilliseconds();
        if (reset == 0) {
            gOptMinComp->mStartTime = MatchingGetTickMilliseconds();
        }
    }
}

void DWCi_ProcessOptMinComp(void) {
    DWCMatchOptMinCompleteIn *optMinComp;
    WiFiMatching *wiFiMatching;
    u32 mask;
    u8 retry;
    s32 participantPos;
    optMinComp = gOptMinComp;
    if (optMinComp == NULL) {
        return;
    }
    if (optMinComp->mValid == 0) {
        return;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER) {
        return;
    }
    if (wiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT) {
        return;
    }
    if (wiFiMatching->mState == WIFI_MATCH_STATE_MIN_COMPLETE_POLL) {
        mask = DWCi_GetAIDBitmask(0);
        optMinComp = gOptMinComp;
        if (optMinComp->mRecvBit == mask) {
            if (optMinComp->mTimeoutBit == mask) {
                gWiFiMatching->mNumEntry = gWiFiMatching->mLastParticipantPos;
                gWiFiMatching->mPostProcessPos = gWiFiMatching->mLastParticipantPos - 1;
                DWCi_PostProcessConnection(0);
                return;
            }
            optMinComp->mLastPollTime = MatchingGetTickMilliseconds();
            optMinComp->mRecvBit = 0;
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
                wiFiMatching->mState = WIFI_MATCH_STATE_LIST_SEARCH;
                gWiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_LONG;
                gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                return;
            }
            wiFiMatching->mState = WIFI_MATCH_STATE_RESERVING;
            DWCi_SendResvCommandToFriend(1, 0);
            return;
        }
        retry = optMinComp->mRetry;
        if (MatchingGetTickMilliseconds() - optMinComp->mLastPollTime < retry * 0x1770) {
            return;
        }
        if (retry > 5) {
            DWCi_InitOptMinCompParam(1);
            DWCi_CloseAllConnectionsByTimeout();
            DWCi_RestartFromCancel(1);
            return;
        }
        for (participantPos = 1; participantPos <= (wiFiMatching = gWiFiMatching)->mLastParticipantPos;
             participantPos++) {
            if ((gOptMinComp->mRecvBit & (1 << wiFiMatching->mParticipantIndices[participantPos])) == 0) {
                wiFiMatching = gWiFiMatching;
                if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                        WIFI_MATCH_COMMAND_MIN_COMPLETE_QUERY, wiFiMatching->mParticipantProfileIds[participantPos],
                        wiFiMatching->mParticipantCommandAddresses[participantPos],
                        wiFiMatching->mParticipantCommandPorts[participantPos], NULL, 0)) != 0) {
                    return;
                }
            }
        }
        gOptMinComp->mRetry++;
    } else if (wiFiMatching->mState == WIFI_MATCH_STATE_LIST_SEARCH ||
               wiFiMatching->mState == WIFI_MATCH_STATE_RESERVING) {
        if (wiFiMatching->mLastParticipantPos < optMinComp->mMinEntry - 1) {
            return;
        }
        if (optMinComp->mRetry != 0 || MatchingGetTickMilliseconds() - optMinComp->mStartTime < optMinComp->mTimeout) {
            if (optMinComp->mRetry == 0) {
                return;
            }
            optMinComp = gOptMinComp;
            if (MatchingGetTickMilliseconds() - optMinComp->mLastPollTime < (optMinComp->mTimeout >> 2)) {
                return;
            }
        }
        wiFiMatching = gWiFiMatching;
        if (wiFiMatching->mReplyProfileId != 0) {
            if (DWCi_HandleMatchCommandError(DWCi_CancelReservation(wiFiMatching->mReplyProfileId)) != 0) {
                return;
            }
        }
        wiFiMatching = gWiFiMatching;
        wiFiMatching->mState = WIFI_MATCH_STATE_MIN_COMPLETE_POLL;
        for (participantPos = 1; participantPos <= gWiFiMatching->mLastParticipantPos; participantPos++) {
            wiFiMatching = gWiFiMatching;
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                    WIFI_MATCH_COMMAND_MIN_COMPLETE_QUERY, wiFiMatching->mParticipantProfileIds[participantPos],
                    wiFiMatching->mParticipantCommandAddresses[participantPos],
                    wiFiMatching->mParticipantCommandPorts[participantPos], NULL, 0)) != 0) {
                return;
            }
        }
        optMinComp = gOptMinComp;
        optMinComp->mLastPollTime = MatchingGetTickMilliseconds();
        optMinComp->mRetry = 1;
    }
}

u32 ReportMatchingGpResult(u32 result) {
    s32 dwcCategory;
    s32 detailCode;
    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            dwcCategory = 11;
            detailCode = -1;
            break;
        case 2:
            dwcCategory = 11;
            detailCode = -2;
            break;
        case 3:
            dwcCategory = 6;
            detailCode = -10;
            break;
        case 4:
            dwcCategory = 6;
            detailCode = -20;
            break;
    }
    DWCi_StopMatching(dwcCategory, detailCode - 0x13c68);
    return result;
}

u32 DWCi_HandleSBError(u32 result) {
    s32 kind;
    s32 detail;
    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            kind = 6;
            detail = -50;
            break;
        case 2:
            kind = 6;
            detail = -30;
            break;
        case 3:
            kind = 6;
            detail = -20;
            break;
        case 4:
            kind = 6;
            detail = -40;
            break;
        case 5:
            kind = 11;
            detail = -1;
            break;
        case 6:
            kind = 11;
            detail = -2;
            break;
    }
    DWCi_StopMatching(kind, detail - 0x14c08);
    return result;
}

u32 DWCi_HandleQR2Error(u32 error) {
    s32 detail;
    s32 kind;
    if (error == 0) {
        return 0;
    }
    switch (error) {
        case 1:
            kind = 6;
            detail = -50;
            break;
        case 2:
            kind = 6;
            detail = -60;
            break;
        case 3:
            kind = 6;
            detail = -30;
            break;
        case 4:
            kind = 6;
            detail = -80;
            break;
        case 5:
            kind = 6;
            detail = -20;
            break;
    }
    switch (DWC_GetState()) {
        case WIFI_CONNECTION_LOGIN:
            DWCi_StopLogin(kind, detail - 0xfa00);
            break;
        case WIFI_CONNECTION_BUDDY_SYNC:
            DWCi_StopFriendProcess(kind, detail - 0x12110);
            break;
        case WIFI_CONNECTION_PARTNER_SEARCH:
            DWCi_StopMatching(kind, detail - 0x14820);
            break;
        default:
            DWCi_SetError(kind, detail - 0x16f30);
            break;
    }
    return error;
}

s32 DWCi_HandleNNError(s32 error) {
    s32 kind;
    s32 detail;
    if (error == 0) {
        return 0;
    }
    switch (error) {
        case 1:
            kind = 11;
            detail = -1;
            break;
        case 2:
            kind = 6;
            detail = -50;
            break;
        case 3:
            kind = 6;
            detail = -30;
            break;
    }
    DWCi_StopMatching(kind, detail - 0x14ff0);
    return error;
}

s32 DWCi_HandleNNResult(s32 result) {
    enum { DWC_ERROR_NETWORK = 6 } dwcError;
    s32 detail;
    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            dwcError = DWC_ERROR_NETWORK;
            detail = -9;
            break;
    }
    if (dwcError != 0) {
        DWCi_StopMatching(dwcError, detail - 0x14ff0);
    }
    return result;
}

u32 ReportMatchingConnectResult(u32 result) {
    s32 dwcCategory;
    s32 detailCode;
    if (result == 0) {
        return 0;
    }
    switch (result) {
        case 1:
            dwcCategory = 11;
            detailCode = -1;
            break;
        case 2:
        case 5:
            dwcCategory = 0;
            detailCode = 0;
            result = 0;
            break;
        case 3:
            dwcCategory = 6;
            detailCode = -10;
            break;
        case 4:
            dwcCategory = 6;
            detailCode = -30;
            break;
        case 6:
            dwcCategory = 6;
            detailCode = -70;
            break;
        case 7:
            dwcCategory = 6;
            detailCode = -80;
            break;
    }
    if (dwcCategory != 0) {
        DWCi_StopMatching(dwcCategory, detailCode - 0x153d8);
    }
    return result;
}

void DWCi_SBCallback(MatchingServerList *list, s32 event, SbServer *server, u32 instance) {
    s32 serverIndex;
    SbServer *listedServer;
    s32 serverProfileId;
    WiFiMatching *wiFiMatching;
    switch (event) {
        case 0:
            DWCi_SBPrintServerData(server);
            return;
        case 4:
            serverIndex = 0;
            if (ServerBrowserCount(list) > 0) {
                do {
                    listedServer = ServerBrowserGetServer(list, serverIndex);
                    if (DWCi_CheckDWCServer(listedServer) == 0) {
                        ServerBrowserRemoveServer(list, listedServer);
                        serverIndex--;
                    }
                    serverIndex++;
                } while (serverIndex < ServerBrowserCount(list));
            }
            switch (gWiFiMatching->mState) {
                case WIFI_MATCH_STATE_LIST_FIRST_UPDATE:
                    serverIndex = 0;
                    if (ServerBrowserCount(list) > 0) {
                        do {
                            listedServer = ServerBrowserGetServer(list, serverIndex);
                            wiFiMatching = gWiFiMatching;
                            if (wiFiMatching->mOwnAddress != 0 &&
                                wiFiMatching->mOwnAddress == SBServerGetPublicInetAddress(listedServer) &&
                                wiFiMatching->mOwnPort != 0 &&
                                gWiFiMatching->mOwnPort == SBServerGetPublicQueryPort(listedServer)) {
                                break;
                            }
                            serverIndex++;
                        } while (serverIndex < ServerBrowserCount(list));
                    }
                    if (serverIndex < ServerBrowserCount(list)) {
                        gWiFiMatching->mState = WIFI_MATCH_STATE_LIST_SEARCH;
                        gWiFiMatching->mReplyProfileId = 0;
                        if (DWCi_HandleSBError(DWCi_SBUpdateAsync(gWiFiMatching->mReplyProfileId)) != 0) {
                            return;
                        }
                        return;
                    }
                    gWiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_LONG;
                    gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                    return;
                case WIFI_MATCH_STATE_LIST_SEARCH:
                    DWCi_EvaluateServers(1);
                    if (ServerBrowserCount(list) != 0) {
                        if (DWCi_HandleMatchCommandError(DWCi_SendResvCommand(0, 0)) != 0) {
                            return;
                        }
                        gWiFiMatching->mState = WIFI_MATCH_STATE_RESERVING;
                        gWiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_NONE;
                        return;
                    }
                    gWiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_LONG;
                    gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                    return;
                case WIFI_MATCH_STATE_HOST_LOOKUP:
                    if (ServerBrowserCount(list) != 0) {
                        do {
                            listedServer = ServerBrowserGetServer(list, 0);
                            if (gWiFiMatching->mServerAddress == SBServerGetPublicInetAddress(listedServer) &&
                                gWiFiMatching->mServerPort == SBServerGetPublicQueryPort(listedServer)) {
                                break;
                            }
                            ServerBrowserRemoveServer(list, listedServer);
                        } while (ServerBrowserCount(list) != 0);
                    }
                    if (ServerBrowserCount(list) != 0) {
                        serverProfileId = SbServerGetInt(ServerBrowserGetServer(list, 0), gDwcPidKey, 0);
                        wiFiMatching = gWiFiMatching;
                        if (wiFiMatching->mMode == WIFI_MATCH_MODE_BUDDY_LIST &&
                            serverProfileId == wiFiMatching->mParticipantProfileIds[0]) {
                            if (DWCi_EvaluateServers(0) != FALSE) {
                                if (gWiFiMatching->mLastParticipantPos != 0) {
                                    if (DWCi_HandleMatchCommandError(DWCi_ChangeToClient()) != 0) {
                                        return;
                                    }
                                }
                            } else {
                                if (DWCi_HandleMatchCommandError(
                                        DWCi_CancelReservation(gWiFiMatching->mParticipantProfileIds[0])) != 0) {
                                    return;
                                }
                                gWiFiMatching->mState = WIFI_MATCH_STATE_RESERVING;
                                if (DWCi_HandleMatchCommandError(DWCi_SendResvCommandToFriend(0, 0)) != 0) {
                                    return;
                                }
                                return;
                            }
                        }
                        gWiFiMatching->mState = WIFI_MATCH_STATE_NEGOTIATE_CLIENT;
                        if (DWCi_HandleNNError(DWCi_NNStartupAsync(0, 0, ServerBrowserGetServer(list, 0))) != 0) {
                            return;
                        }
                        return;
                    }
                    gWiFiMatching->mServerUpdateWaitKind = WIFI_MATCH_UPDATE_WAIT_LONG;
                    gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                    return;
            }
            return;
        case 5:
            break;
    }
}

void DWCi_SBPrintServerData(SbServer *server) {}

// Removes servers already in the list or refused by mEvalCallback and stores the callback's value for each remaining
// one under dwc_eval.
BOOL DWCi_EvaluateServers(s32 sort) {
    BOOL removedAny;
    BOOL removedThis;
    s32 serverIndex;
    SbServer *serverEntry;
    u32 value;
    s32 participantPos;
    removedAny = FALSE;
    serverIndex = 0;
    for (; serverIndex < ServerBrowserCount(gWiFiMatching->mServerList); serverIndex++) {
        serverEntry = ServerBrowserGetServer(gWiFiMatching->mServerList, serverIndex);
        if (gWiFiMatching->mMode == WIFI_MATCH_MODE_FILTER_SEARCH) {
            value = SbServerGetInt(serverEntry, gDwcPidKey, 0);
            removedThis = FALSE;
            for (participantPos = 1; participantPos <= gWiFiMatching->mLastParticipantPos; participantPos++) {
                if (value == gWiFiMatching->mParticipantProfileIds[participantPos]) {
                    ServerBrowserRemoveServer(gWiFiMatching->mServerList, serverEntry);
                    serverIndex--;
                    removedThis = TRUE;
                    break;
                }
            }
            if (removedThis != FALSE) {
                continue;
            }
        }
        if (gWiFiMatching->mEvalCallback != 0) {
            value = gWiFiMatching->mEvalCallback(serverIndex, gWiFiMatching->mEvalCallbackArg);
            if ((s32) value > 0) {
                if ((s32) value > 0x7fffff) {
                    value = 0x7fffff;
                }
                SbServerSetInt(serverEntry, gDwcEvalKey, (value << 8) | DWCi_GetMathRand32(0x100));
            } else {
                ServerBrowserRemoveServer(gWiFiMatching->mServerList, serverEntry);
                serverIndex--;
                removedAny = TRUE;
            }
        } else {
            SbServerSetInt(serverEntry, gDwcEvalKey, DWCi_GetMathRand32(0x80));
        }
    }
    if (sort != 0 && ServerBrowserCount(gWiFiMatching->mServerList) != 0) {
        ServerBrowserSortA(gWiFiMatching->mServerList, 0, gDwcEvalKey, 0);
    }
    if (removedAny != FALSE && ServerBrowserCount(gWiFiMatching->mServerList) == 0) {
        return FALSE;
    }
    return TRUE;
}

void DWCi_QR2ServerKeyCallback(s32 keyId, QueryBuffer *buffer, void *userdata) {
    s32 index;
    switch (keyId) {
        case 8:
            qr2_buffer_add_int(buffer, gWiFiMatching->mNNCompletedCount);
            return;
        case 0xa:
            qr2_buffer_add_int(buffer, gWiFiMatching->mNumEntry);
            return;
        case 0x32:
            qr2_buffer_add_int(buffer, gWiFiMatching->mOwnProfileId);
            return;
        case 0x33:
            qr2_buffer_add_int(buffer, gWiFiMatching->mMode);
            return;
        case 0x34:
            qr2_buffer_add_int(buffer, gWiFiMatching->mMresvProfileId);
            return;
        case 0x35:
            qr2_buffer_add_int(buffer, 3);
            return;
        case 0x36:
            qr2_buffer_add_int(buffer, 1);
            return;
    }
    index = keyId - 100;
    if (gMatchingKeys[index].mKeyId != 0) {
        if (gMatchingKeys[index].mIsString != 0) {
            qr2_buffer_addA(buffer, gMatchingKeys[index].mValue.mText);
        } else {
            qr2_buffer_add_int(buffer, *gMatchingKeys[index].mValue.mNumber);
        }
    }
}

void DWCi_QR2PlayerKeyCallback(void) {}

void DWCi_QR2TeamKeyCallback(void) {}

void DWCi_QR2KeyListCallback(s32 keytype, MatchingKeyIds *keyIds, void *userdata) {
    s32 keyIndex;
    MatchingKey *matchingKey;
    switch (keytype) {
        case 0:
            qr2_keybuffer_add(keyIds, 8);
            qr2_keybuffer_add(keyIds, 0xa);
            qr2_keybuffer_add(keyIds, 0x32);
            qr2_keybuffer_add(keyIds, 0x33);
            qr2_keybuffer_add(keyIds, 0x34);
            qr2_keybuffer_add(keyIds, 0x35);
            qr2_keybuffer_add(keyIds, 0x36);
            keyIndex = 0;
            matchingKey = gMatchingKeys;
            for (; keyIndex < 0x9a; keyIndex++) {
                if (matchingKey->mKeyId != 0) {
                    qr2_keybuffer_add(keyIds, matchingKey->mKeyId);
                }
                matchingKey++;
            }
            break;
        case 1:
            break;
        case 2:
            break;
    }
}

s32 DWCi_QR2CountCallback(void) {
    return 0;
}

u32 DWCi_QR2AddErrorCallback(u32 error) {
    return DWCi_HandleQR2Error(error);
}

void DWCi_QR2PublicAddrCallback(u32 address, u16 port, void *userData) {
    gWiFiMatching->mOwnAddress = address;
    gWiFiMatching->mOwnPort = port;
}

void DWCi_QR2NatnegCallback(u32 cookie, void *userData) {
    if (gWiFiMatching->mState == WIFI_MATCH_STATE_CONNECTED) {
        gWiFiMatching->mState = WIFI_MATCH_STATE_NEGOTIATE_CLIENT;
    } else if (gWiFiMatching->mState != WIFI_MATCH_STATE_NEGOTIATE_CLIENT &&
               gWiFiMatching->mState != WIFI_MATCH_STATE_NEGOTIATE_SERVER) {
        return;
    }
    if (gWiFiMatching->mLastNatnegCookie == cookie) {
        gWiFiMatching->mNatnegCounts[0]++;
    } else {
        gWiFiMatching->mNatnegCounts[0] = 0;
        gWiFiMatching->mLastNatnegCookie = cookie;
    }
    gWiFiMatching->mNNFailedTime = 0;
    if (DWCi_HandleNNError(DWCi_NNStartupAsync(1, cookie, 0)) == 0) {
        gWiFiMatching->mLastCommand = WIFI_MATCH_COMMAND_NONE;
    }
}

void DWCi_QR2ClientMsgCallback(const void *data, u32 len, void *userData) {
    MatchingReceiveHeader header;
    u32 body[0x20];
    u32 offset;
    offset = 0;
    if (len >= 0x14) {
        do {
            MI_CpuCopy8(data, &header, sizeof(header));
            if (strncmp(header.mSignature, gMatchingSignature.mText, 4) != 0) {
                break;
            }
            if (header.mVersion != 3) {
                break;
            }
            MI_CpuCopy8(data + 0x14, body, header.mValuesSize);
            if (DWCi_ProcessRecvMatchCommand(header.mCommand, header.mProfileId, header.mAddress, header.mPort, body,
                                             header.mValuesSize >> 2) == 0) {
                break;
            }
            offset += header.mValuesSize + 0x14;
        } while (offset + 0x14 <= len);
    }
}

void DWCi_NNProgressCallback(void) {}

void DWCi_NNCompletedCallback(s32 result, s32 gamesocket, PeerAddress *remoteaddr, void *userdata) {
    s32 index;
    s32 outcome;
    u32 unusedFirst;
    u32 unusedSecond;
    char pidText[12];
    if (gWiFiMatching->mState != WIFI_MATCH_STATE_NEGOTIATE_CLIENT &&
        gWiFiMatching->mState != WIFI_MATCH_STATE_NEGOTIATE_SERVER) {
        return;
    }
    if (userdata == NULL) {
        return;
    }
    if (result == 0) {
        ((DWCNNInfo *) userdata)->mCookie = 0;
        gWiFiMatching->mNNCompletedCount++;
        index = gWiFiMatching->mNNCompletedCount;
        if (((DWCNNInfo *) userdata)->mIsQR2 != 0) {
            gWiFiMatching->mParticipantConnectAddresses[index] = remoteaddr->mAddress;
            gWiFiMatching->mParticipantConnectPorts[index] =
                (remoteaddr->mPort >> 8) & 0xff | (remoteaddr->mPort << 8) & 0xff00;
            gWiFiMatching->mNatnegCounts[0] = 0;
            gWiFiMatching->mLastNatnegCookie = 0;
            gWiFiMatching->mNNFailedTime = 0;
            if (gWiFiMatching->mState == WIFI_MATCH_STATE_NEGOTIATE_SERVER) {
                gWiFiMatching->mState = WIFI_MATCH_STATE_CONNECT_SERVER;
            } else {
                gWiFiMatching->mState = WIFI_MATCH_STATE_CONNECT_CLIENT;
            }
            gWiFiMatching->mConnectRetryCount = 0;
            OS_SNPrintf(pidText, 12, gUnsignedFormat, gWiFiMatching->mOwnProfileId);
            if (ReportMatchingConnectResult(
                    gt2Connect(*gWiFiMatching->mConnectionSocket, NULL,
                               gt2AddressToString(gWiFiMatching->mParticipantConnectAddresses[index],
                                                  gWiFiMatching->mParticipantConnectPorts[index], 0),
                               pidText, -1, 0x1388, gWiFiMatching->mConnectionCallbacks, 0)) != 0) {
                return;
            }
            return;
        }
        if (remoteaddr != 0) {
            gWiFiMatching->mParticipantConnectAddresses[index - 1] = remoteaddr->mAddress;
            gWiFiMatching->mParticipantConnectPorts[index - 1] =
                (remoteaddr->mPort >> 8) & 0xff | (remoteaddr->mPort << 8) & 0xff00;
        }
        gWiFiMatching->mIncomingWaitStartTime = MatchingGetTickMilliseconds();
        gWiFiMatching->mState = WIFI_MATCH_STATE_CONNECT_CLIENT;
        return;
    }
    if (((DWCNNInfo *) userdata)->mCookie == 0) {
        return;
    }
    outcome = DWCi_HandleNNResult(result);
    if (outcome != 2 && outcome != 1) {
        return;
    }
    if (((DWCNNInfo *) userdata)->mIsQR2 == 0) {
        if (outcome == 1 || (outcome == 2 && ((DWCNNInfo *) userdata)->mRetryCount >= 1)) {
            ((DWCNNInfo *) userdata)->mCookie = 0;
            if (DWCi_ProcessNNFailure() != 0) {
                if (DWCi_CancelPreConnectedClientProcess(
                        gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos]) != 0) {
                    return;
                }
            }
            return;
        }
        ((DWCNNInfo *) userdata)->mRetryCount++;
        if (DWCi_HandleNNError(DWCi_DoNatNegotiationAsync(userdata)) != 0) {
            return;
        }
        return;
    }
    gWiFiMatching->mNNFailedTime = MatchingGetTickMilliseconds();
    if (outcome == 1 || (outcome == 2 && gWiFiMatching->mNatnegCounts[0] >= 1)) {
        ((DWCNNInfo *) userdata)->mCookie = 0;
        if (DWCi_ProcessNNFailure() != 0) {
            gWiFiMatching->mNatnegCounts[0] = 0;
            gWiFiMatching->mLastNatnegCookie = 0;
            gWiFiMatching->mNNFailedTime = 0;
            if (DWCi_CancelPreConnectedServerProcess(
                    gWiFiMatching->mParticipantProfileIds[gWiFiMatching->mLastParticipantPos + 1]) != 0) {
                return;
            }
        }
    }
}

u32 DWCi_ProcessNNFailure(void) {
    if (gWiFiMatching->mMode == WIFI_MATCH_MODE_SERVER) {
        return 1;
    }
    if (gWiFiMatching->mMode != WIFI_MATCH_MODE_SERVER_CLIENT) {
        gWiFiMatching->mNatnegCounts[1]++;
    }
    if (gWiFiMatching->mMode == WIFI_MATCH_MODE_SERVER_CLIENT || gWiFiMatching->mNatnegCounts[1] >= 5) {
        DWCi_StopMatching(6, -0x15194);
        return 0;
    }
    return 1;
}
