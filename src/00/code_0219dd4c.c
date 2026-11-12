#include "00/code_0219dd4c.h"

#include "00/code_021a0958.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219e4e8.h"
#include "00/code_0219e134.h"
#include "00/code_021a01dc.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "00/code_0219de4c.h"
#include "00/code_0219de5c.h"
#include "00/code_0219eac8.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"
#include "00/code_0218aea4.h"
#include "00/code_0219dee0.h"
#include "00/code_0218b000.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_0218d818.h"
#include "00/code_021a3264.h"
#include "00/code_021a2950.h"
#include "00/code_0219fb48.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"
#include "00/code_0219f4c4.h"
#include "code_0200f5ac.h"
#include "00/code_0219c954.h"
#include "00/code_0219eaf4.h"
#include "00/code_0219b580.h"
#include "00/code_0219c000.h"
#include "00/code_0219c384.h"
#include "00/code_021a17bc.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219a654.h"
#include "00/code_0219d128.h"
#include "00/code_021988e8.h"
#include "00/code_0219a000.h"
#include "00/code_0219b000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a1000.h"
#include "os_printf.h"
#include "00/code_021a10b0.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0218a000.h"
#include "00/code_0218c000.h"
#include "Main/Net/friend_data_type_wrapper.h"
#include "code_0213a460.h"
#include "code_02152500.h"
#include "00/code_0219dabc.h"
#include "00/code_0219887c.h"
#include "00/code_0219dd48.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a4000.h"
#include "00/code_021a4b84.h"
#include "00/code_02188720.h"
#include "code_0214cfe4.h"
#include "00/code_021a1ac0.h"
#include "00/code_02198a8c.h"
#include "00/code_021a1ae0.h"

// Per login: stores the GP connection, socket and callbacks and resets the search.
void DWCi_MatchInit(WiFiMatching *wiFiMatching, GpConnection *gpConnection, void **connectionSocket,
                    void *connectionCallbacks, void *gameName, void *secretKey, void *buddies, u32 buddyEntryCount) {
    gWiFiMatching = wiFiMatching;
    wiFiMatching->mGpConnection = gpConnection;
    gWiFiMatching->mConnectionSocket = connectionSocket;
    gWiFiMatching->mConnectionCallbacks = connectionCallbacks;
    gWiFiMatching->mQr2 = NULL;
    gWiFiMatching->mOwnAddress = NULL;
    gWiFiMatching->mOwnPort = 0;
    gWiFiMatching->mServerList = NULL;
    gWiFiMatching->mState = 0;
    gWiFiMatching->mUnk_0f = 0;
    gWiFiMatching->mUnk_19 = 0;
    gWiFiMatching->mUnk_1a5 = 0;
    gWiFiMatching->mOwnProfileId = 0;
    gWiFiMatching->mGameName = gameName;
    gWiFiMatching->mSecretKey = secretKey;
    gWiFiMatching->mBuddies = buddies;
    gWiFiMatching->mBuddyEntryCount = buddyEntryCount;
    MI_CpuFill8(gWiFiMatching->mBuddyEntryIndices, 0, 0x40);
    gWiFiMatching->mBuddyEntryIndexCount = 0;
    gWiFiMatching->mResultCallback = NULL;
    gWiFiMatching->mResultCallbackArg = 0;
    gWiFiMatching->mEvalCallback = 0;
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
            (Unk021a4a08Func88) DWCi_QR2ServerKeyCallback, (Unk021a4a08Func8c) DWCi_QR2PlayerKeyCallback,
            (Unk021a4a08Func8c) DWCi_QR2TeamKeyCallback, (Unk021a4a08Func94) DWCi_QR2KeyListCallback,
            (Unk021a4a08Func98) DWCi_QR2CountCallback, (Unk021a4a08Func9c) DWCi_QR2AddErrorCallback, NULL);
        if (initResult == 0) {
            break;
        }
        if (initResult != 3 || attempt == 4) {
            DWCi_HandleQR2Error(initResult);
            return initResult;
        }
        attempt++;
    } while (attempt < 5);
    gWiFiMatching->mOwnAddress = NULL;
    gWiFiMatching->mOwnPort = 0;
    qr2_register_publicaddress_callback(gWiFiMatching->mQr2, DWCi_QR2PublicAddrCallback);
    qr2_register_natneg_callback(gWiFiMatching->mQr2, DWCi_QR2NatnegCallback);
    qr2_register_clientmessage_callback(gWiFiMatching->mQr2, DWCi_QR2ClientMsgCallback);
    qr2_send_statechanged(gWiFiMatching->mQr2);
    return initResult;
}

// Starts a filter search (mode 0) and keeps the caller's filter text for the server list filter.
void DWCi_ConnectToAnybodyAsync(u32 numEntry, const void *addFilter, u32 matchedCallback, u32 matchedParam,
                                u32 evalCallback, u32 evalParam) {
    char filterText[0x100];
    s32 filterRoom;
    if (gMatchingFilterText != NULL) {
        DWC_Free(4, (u32) gMatchingFilterText, 0);
        gMatchingFilterText = NULL;
    }
    if (addFilter != NULL) {
        filterRoom = DWCi_GetDefaultMatchFilter(filterText, -1, 0x20, 3);
        filterRoom = 0x100 - filterRoom - strlen(gAndEmptyParensString);
        gMatchingFilterText = DWC_Alloc(4, filterRoom);
        if (gMatchingFilterText == NULL) {
            DWCi_StopMatching(11, -80001);
            return;
        }
        MI_CpuCopy8(addFilter, gMatchingFilterText, filterRoom);
        *((u8 *) gMatchingFilterText + filterRoom - 1) = 0;
    }
    ((void (*)(u32, u32, u32, u32)) DWCi_SetMatchCommonParam)(0, numEntry, matchedCallback, matchedParam);
    gWiFiMatching->mEvalCallback = evalCallback;
    gWiFiMatching->mEvalCallbackArg = evalParam;
    gWiFiMatching->mState = 2;
    if (gWiFiMatching->mServerList == NULL) {
        gWiFiMatching->mServerList = ServerBrowserNewA(gWiFiMatching->mGameName, gWiFiMatching->mGameName,
                                                       gWiFiMatching->mSecretKey, 0, 20, 1, 0, DWCi_SBCallback, 0);
    }
    if (gWiFiMatching->mServerList == NULL && DWCi_HandleSBError(5) != 0) {
        return;
    }
    DWCi_SetGPStatus(3, gEmptyString, NULL);
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
                                void *matchedCallback, u32 matchedParam, u32 evalCallback, u32 evalParam) {
    char numDigits[12];
    u8 keyValueStr[0x24];
    ((void (*)(u32, u32, u32, u32)) DWCi_SetMatchCommonParam)(1, numEntry, (u32) matchedCallback, matchedParam);
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
    gWiFiMatching->mState = 4;
    if (gWiFiMatching->mServerList == NULL) {
        gWiFiMatching->mServerList = ServerBrowserNewA(gWiFiMatching->mGameName, gWiFiMatching->mGameName,
                                                       gWiFiMatching->mSecretKey, 0, 20, 1, 0, DWCi_SBCallback, 0);
    }
    if (gWiFiMatching->mServerList == NULL && DWCi_HandleSBError(5) != 0) {
        return;
    }
    OS_SNPrintf(numDigits, 12, gUnsignedFormat, numEntry);
    DWC_SetCommonKeyValueString(gFmeKey, numDigits, keyValueStr, 0x2f);
    DWC_AddCommonKeyValueString(gMdfKey, distantFriend != 0 ? gYString : gNString, keyValueStr, 0x2f);
    OS_SNPrintf(numDigits, 12, gUnsignedFormat, 3);
    DWC_AddCommonKeyValueString(gVerKey, numDigits, keyValueStr, 0x2f);
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
void DWCi_MatchProcess(s32 param_1) {
    WiFiMatching *wiFiMatching;
    u32 waitMs;
    QueryRecord *qr2Obj;
    if (gWiFiMatching == NULL) {
        return;
    }
    if (DWCi_IsError() != 0) {
        return;
    }
    if (param_1 == 0) {
        if (gWiFiMatching->mQr2 != NULL) {
            qr2_think(gWiFiMatching->mQr2);
        }
        if (gWiFiMatching->mConnectionSocket != NULL) {
            gt2Think(*gWiFiMatching->mConnectionSocket);
        }
        return;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mState == 0) {
        return;
    }
    switch (wiFiMatching->mState) {
        case 4:
            if (wiFiMatching->mResvTimeoutMs != 0) {
                if ((OS_GetTick() - wiFiMatching->mResvTimeoutStartTick) * 64 / 0x82ea > wiFiMatching->mResvTimeoutMs) {
                    wiFiMatching->mResvTimeoutMs = 0;
                    wiFiMatching = gWiFiMatching;
                    param_1 = wiFiMatching->mMode;
                    if (param_1 == 3) {
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
                    } else if (DWCi_RetryReserving(param_1) == 0) {
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
        case 2:
        case 3:
        case 5:
            if ((s32) wiFiMatching->mServerUpdateWaitKind > 0) {
                if (wiFiMatching->mState == 3) {
                    waitMs = (u32) (wiFiMatching->mLastParticipantPos * 3000) + 3000;
                } else if (wiFiMatching->mServerUpdateWaitKind == 1) {
                    waitMs = 1000;
                } else {
                    waitMs = 3000;
                }
                if ((OS_GetTick() - wiFiMatching->mServerUpdateWaitStartTick) * 64 / 0x82ea > waitMs) {
                    if (DWCi_HandleSBError(DWCi_SBUpdateAsync(wiFiMatching->mReplyProfileId)) != 0) {
                        return;
                    }
                    gWiFiMatching->mServerUpdateWaitKind = 0;
                }
            }
            break;
        case 7:
            if (wiFiMatching->mIncomingWaitStartTime != 0) {
                if (MatchingGetTickMilliseconds() - wiFiMatching->mIncomingWaitStartTime > 25000) {
                    gWiFiMatching->mIncomingWaitStartTime = 0;
                    if (DWCi_CancelPreConnectedClientProcess(gWiFiMatching->mParticipantProfileIds[0]) == 0) {
                        return;
                    }
                }
            } else if (wiFiMatching->mLastCommand == 6) {
                if (MatchingGetTickMilliseconds() - wiFiMatching->mLastCommandTime > 6000) {
                    wiFiMatching->mResendCount++;
                    wiFiMatching = gWiFiMatching;
                    if (wiFiMatching->mResendCount > 5) {
                        DWCi_StopResendingMatchCommand();
                        if (DWCi_CancelPreConnectedClientProcess(gWiFiMatching->mParticipantProfileIds[0]) == 0) {
                            return;
                        }
                    } else if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                                   6, wiFiMatching->mLastCommandProfileId, wiFiMatching->mLastCommandAddress,
                                   wiFiMatching->mLastCommandPort, wiFiMatching->mLastCommandValues,
                                   wiFiMatching->mLastCommandValueCount)) != 0) {
                        return;
                    }
                }
            }
            break;
        case 11:
            if (wiFiMatching->mLastCommand == 2) {
                if ((wiFiMatching->mMode == 0 &&
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
        case 13:
            if (wiFiMatching->mLastCommand == 8) {
                if (MatchingGetTickMilliseconds() - wiFiMatching->mLastCommandTime > 30000) {
                    wiFiMatching->mResendCount++;
                    wiFiMatching = gWiFiMatching;
                    if (wiFiMatching->mResendCount != 0) {
                        DWCi_StopResendingMatchCommand();
                        wiFiMatching = gWiFiMatching;
                        if (wiFiMatching->mMode == 2) {
                            if (DWCi_CancelPreConnectedServerProcess(
                                    wiFiMatching->mParticipantProfileIds[wiFiMatching->mLastParticipantPos]) == 0) {
                                return;
                            }
                        } else {
                            DWCi_RestartFromTimeout();
                        }
                    } else if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                                   8, wiFiMatching->mLastCommandProfileId, wiFiMatching->mLastCommandAddress,
                                   wiFiMatching->mLastCommandPort, wiFiMatching->mLastCommandValues,
                                   wiFiMatching->mLastCommandValueCount)) != 0) {
                        return;
                    }
                }
            }
            break;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mState == 11 || wiFiMatching->mState == 6) {
        if (wiFiMatching->mNNFailedTime != 0) {
            if (MatchingGetTickMilliseconds() - wiFiMatching->mNNFailedTime > 10000) {
                DWCi_NNCompletedCallback(1, 0, 0, wiFiMatching->mNNInfo);
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
        if ((qr2Obj->mUserStateChangeRequested == FALSE && (wiFiMatching->mMode == 0 || wiFiMatching->mMode == 1) &&
             (wiFiMatching->mState == 1 || wiFiMatching->mState == 2 || wiFiMatching->mState == 3 ||
              wiFiMatching->mState == 4 || wiFiMatching->mState == 6 || wiFiMatching->mState == 11)) ||
            (wiFiMatching->mMode == 2 && wiFiMatching->mState == 11)) {
            qr2_send_statechanged(qr2Obj);
        }
    }
    NNThink();
    if (gWiFiMatching->mConnectionSocket != NULL) {
        gt2Think(*gWiFiMatching->mConnectionSocket);
    }
    if (gWiFiMatching->mState == 18) {
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
    volatile u32 v;
    u32 firstByte;
    if (size == 0 || data == NULL) {
        return 0;
    }
    v = 0;
    MIi_CpuClear32(v, &originAddr, 8);
    originAddr.mFamily = 2;
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

// Accepts an incoming connection in state 7 from the expected participant, otherwise refuses it with a reason text.
void DWCi_GT2ConnectAttemptCallback(u32 socket, Unk0219887c *connection, u32 address, u32 port, s32 latency,
                                    char *message) {
    WiFiMatching *wiFiMatching;
    DWCConnectionInfo *connectionInfo;
    void **connHandleSlot;
    s32 index;
    s32 participantPos;
    s32 t;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching == NULL || wiFiMatching->mState != 7 || wiFiMatching->mStopPending != 0) {
        gt2Reject((Gt2Connection *) connection, gInitStateString, -1);
        return;
    }
    index = DWCi_GT2GetConnectionListIdx();
    if (index == -1) {
        gt2Reject((Gt2Connection *) connection, gServerFullString, -1);
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
            gt2Reject((Gt2Connection *) connection, gUnexpectedConnectAttemptString, -1);
            return;
        }
    }
    gWiFiMatching->mIncomingWaitStartTime = 0;
    if (gt2Accept((Gt2Connection *) connection, gWiFiMatching->mConnectionCallbacks) == 0) {
        DWCi_StopMatching(6, -80410);
        return;
    }
    DWCi_StopResendingMatchCommand();
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mLastParticipantPos == 0) {
        t = latency >> 1;
        if (t >= 0xffff) {
            t = 0xffff;
        }
        wiFiMatching->mSynLatency = t;
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
void DWCi_GT2ConnectedCallback(Unk0219887c *connection, s32 result) {
    WiFiMatching *wiFiMatching;
    s32 index;
    void **connHandleSlot;
    DWCConnectionInfo *connInfoRec;
    char pidDigits[12];
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching == NULL) {
        return;
    }
    if (wiFiMatching->mState != 7 && wiFiMatching->mState != 12) {
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
    if (gWiFiMatching->mState == 12) {
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
    gWiFiMatching->mLastCommand = 0xff;
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
        DWCi_SetGPStatus(0, gEmptyString, NULL);
        wiFiMatching = gWiFiMatching;
        isServer = wiFiMatching->mMode == 2 ? 1 : 0;
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
    if (wiFiMatching->mMode != 2) {
        wiFiMatching->mNNCompletedCount = 0;
        gWiFiMatching->mNumEntry = 0;
        qr2_send_statechanged(gWiFiMatching->mQr2);
    }
}

void DWCi_ProcessMatchSynPacket(s32 peerIndex, s32 kind, u8 *data) {
    WiFiMatching *wiFiMatching;
    s32 i;
    u32 *q;
    s32 v;
    switch (kind) {
        case 2:
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mState == 1) {
                if (data[0] == 1) {
                    wiFiMatching->mEventProfileId = 0;
                }
                i = data[1];
                gWiFiMatching->mParticipantIndices[i] = data[2];
                gWiFiMatching->mParticipantProfileIds[i] = gWiFiMatching->mOwnProfileId;
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mMode == 0 || wiFiMatching->mMode == 1) {
                    wiFiMatching = gWiFiMatching;
                    wiFiMatching->mNumEntry = wiFiMatching->mLastParticipantPos;
                }
                gWiFiMatching->mState = 9;
            }
            DWCi_SendMatchSynPacket(peerIndex, 3);
            break;
        case 3:
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mState == 16) {
                q = &wiFiMatching->mSynReplyMask;
                *q = *q | (1 << peerIndex);
                v = data[0] | (data[1] << 8);
                if (v > gWiFiMatching->mSynLatency) {
                    gWiFiMatching->mSynLatency = v;
                }
                v = DWCi_GetAIDBitmask(0);
                if (gWiFiMatching->mSynReplyMask == v) {
                    for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
                        DWCi_SendMatchSynPacket(gWiFiMatching->mParticipantIndices[i], 4);
                    }
                    gWiFiMatching->mState = 17;
                }
            } else {
                DWCi_SendMatchSynPacket(peerIndex, 4);
            }
            break;
        case 4:
            if (gWiFiMatching->mState == 9) {
                DWCi_PostProcessConnection(4);
            }
            break;
    }
}

u32 DWCi_ProcessMatchClosing(s32 error, s32 errorCode, s32 profileId) {
    WiFiMatching *wiFiMatching;
    if (DWC_GetState() != 5) {
        return 0;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMode == 2) {
        return 1;
    }
    if (error != 0) {
        DWCi_StopMatching(error, errorCode - 80000);
        return 1;
    }
    wiFiMatching->mParticipantIndices[0] = 0;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mStopPending == 1 || wiFiMatching->mCloseKind == 1 || wiFiMatching->mCloseKind == 2) {
        return 1;
    }
    if (wiFiMatching->mNNCookie != 0) {
        NNCancel(wiFiMatching->mNNCookie);
        gWiFiMatching->mNNCookie = 0;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mLastParticipantPos != 0) {
        if (wiFiMatching->mCloseKind == 0) {
            wiFiMatching->mCloseKind = 3;
            gt2CloseAllConnectionsHard(*gWiFiMatching->mConnectionSocket);
        }
    } else if (wiFiMatching->mMode == 3) {
        DWCi_StopMatching(6, -80430);
    } else if (wiFiMatching->mPriorProfileId != 0) {
        DWCi_ResumeMatching();
    } else if (wiFiMatching->mState == 1) {
        wiFiMatching->mState = 18;
        gWiFiMatching->mResumeWaitStartTime = MatchingGetTickMilliseconds();
    } else {
        DWCi_RestartFromCancel(1);
    }
    return 1;
}

void DWCi_ProcessMatchSCClosing(u32 clientPid) {
    if (gWiFiMatching->mCloseKind != 2) {
        DWCi_CancelPreConnectedServerProcess(clientPid);
    }
}

u32 DWCi_DeleteHostByProfileID(int profileId, int count) {
    int position;
    int v2;
    v2 = *(s32 *) &gWiFiMatching;
    if (0 == v2) {
        return 0;
    }
    position = 0;
    if (0 < count) {
        do {
            if (profileId == *(s32 *) (v2 + 0xf4)) {
                DWCi_DeleteHostByIndex(position, count);
                return 1;
            }
            v2 = v2 + 4;
            position = position + 1;
        } while (position < count);
    }
    return 0;
}

u32 DWCi_DeleteHostByIndex(s32 position, s32 count) {
    WiFiMatching *wiFiMatching;
    u32 profileId;
    u32 *m;
    s32 i;
    s32 n;
    s32 k;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching == NULL) {
        return 0;
    }
    profileId = wiFiMatching->mParticipantProfileIds[position];
    m = &wiFiMatching->mParticipantMask;
    *m = *m & ~(1 << wiFiMatching->mParticipantIndices[position]);
    DWCi_SetNumValidConnection();
    if (position < count - 1) {
        i = 0;
        n = count - position;
        if (n > 0) {
            do {
                s32 a = position + i;
                gWiFiMatching->mParticipantCommandAddresses[a] = gWiFiMatching->mParticipantCommandAddresses[a + 1];
                gWiFiMatching->mParticipantCommandPorts[a] = gWiFiMatching->mParticipantCommandPorts[a + 1];
                gWiFiMatching->mParticipantProfileIds[a] = gWiFiMatching->mParticipantProfileIds[a + 1];
                gWiFiMatching->mParticipantConnectAddresses[a] = gWiFiMatching->mParticipantConnectAddresses[a + 1];
                gWiFiMatching->mParticipantConnectPorts[a] = gWiFiMatching->mParticipantConnectPorts[a + 1];
                gWiFiMatching->mParticipantIndices[a] = gWiFiMatching->mParticipantIndices[a + 1];
                i++;
            } while (i < n);
        }
    }
    if (count > 0) {
        k = count - 1;
        gWiFiMatching->mParticipantCommandAddresses[k] = 0;
        gWiFiMatching->mParticipantCommandPorts[k] = 0;
        gWiFiMatching->mParticipantProfileIds[k] = 0;
        gWiFiMatching->mParticipantConnectAddresses[k] = 0;
        gWiFiMatching->mParticipantConnectPorts[k] = 0;
        gWiFiMatching->mParticipantIndices[k] = 0;
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
    s32 n;
    s32 i;
    u32 bitmap;
    i = 0;
    n = -1;
    wiFiMatching = gWiFiMatching;
    bitmap = wiFiMatching->mParticipantMask;
    for (; i < 32; i++) {
        if ((bitmap & (1 << i)) != 0) {
            n++;
        }
    }
    if (n == -1) {
        wiFiMatching->mLastMaskedParticipantPos = 0;
    } else {
        wiFiMatching->mLastMaskedParticipantPos = n;
    }
}

u32 DWCi_GetAllAIDList(void **output) {
    if (gWiFiMatching == NULL) {
        return 0;
    }
    *output = gWiFiMatching->mParticipantIndices;
    return gWiFiMatching->mLastParticipantPos + 1;
}

u32 DWCi_GetValidAIDList(void **aidList) {
    s32 i;
    u8 *c;
    u8 *q;
    WiFiMatching *p;
    u8 b;
    if (gWiFiMatching == NULL) {
        return 0;
    }
    MI_CpuFill8(gMatchingMaskedParticipantIndices, 0, 0x20);
    i = 0;
    c = (u8 *) gWiFiMatching;
    if (i <= ((WiFiMatching *) c)->mLastMaskedParticipantPos) {
        q = gMatchingMaskedParticipantIndices;
        p = (WiFiMatching *) c;
        do {
            b = c[0x2b8];
            if ((p->mParticipantMask & (1 << b)) == 0) {
                break;
            }
            *q = b;
            c++;
            q++;
            i++;
        } while (i <= p->mLastMaskedParticipantPos);
    }
    *aidList = gMatchingMaskedParticipantIndices;
    return gWiFiMatching->mLastMaskedParticipantPos + 1;
}

u32 DWCi_GPSetServerStatus(void) {
    char numText[12];
    u8 keyValueStr[32];
    if (gWiFiMatching->mMode != 2) {
        return 0;
    }
    OS_SNPrintf(numText, 0xc, gUnsignedFormat, gWiFiMatching->mNumEntry + 1);
    DWC_SetCommonKeyValueString(gScmKey, numText, keyValueStr, 0x2f);
    OS_SNPrintf(numText, 0xc, gUnsignedFormat, gWiFiMatching->mLastParticipantPos + 1);
    DWC_AddCommonKeyValueString(gScnKey, numText, keyValueStr, 0x2f);
    OS_SNPrintf(numText, 0xc, gUnsignedFormat, 3);
    DWC_AddCommonKeyValueString(gVerKey, numText, keyValueStr, 0x2f);
    return DWCi_SetGPStatus(6, keyValueStr, NULL);
}

void DWCi_ShutdownMatch(void) {
    gWiFiMatching = NULL;
    if (gMatchingFilterText != NULL) {
        DWC_Free(4, (u32) gMatchingFilterText, 0);
        gMatchingFilterText = NULL;
    }
    DWCi_ClearGameMatchKeys();
    if (gOptMinComp != NULL) {
        DWC_Free(4, (u32) gOptMinComp, 0);
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
    vu16 h;
    vu16 g;

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
    gWiFiMatching->mCloseKind = 0;
    gWiFiMatching->mCancelSynLatency = 0;
    gWiFiMatching->mServerPort = 0;
    gWiFiMatching->mServerAddress = 0;
    gWiFiMatching->mLastPeerMessageSendTime = 0;
    gWiFiMatching->mResumeWaitStartTime = 0;
    func_0214d018_inline(&gWiFiMatching->mLastCommand, 0x98);
    if (level == 2) {
        gWiFiMatching->mNNCompletedCount = gWiFiMatching->mLastParticipantPos;
        if (gWiFiMatching->mMode == 3) {
            gWiFiMatching->mState = 1;
            return;
        }
        if (gWiFiMatching->mMode == 2) {
            gWiFiMatching->mState = 10;
            return;
        }
    } else {
        gWiFiMatching->mLastParticipantPos = 0;
        gWiFiMatching->mLastMaskedParticipantPos = 0;
        gWiFiMatching->mNNCompletedCount = 0;
        gWiFiMatching->mMresvPresent = 0;
        gWiFiMatching->mMresvProfileId = 0;
        gWiFiMatching->mServerUpdateWaitKind = 0;
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
        func_0214d018_inline(gWiFiMatching->mParticipantCommandAddresses, 0x80);
        h = 0;
        MIi_CpuClear16(h, gWiFiMatching->mParticipantCommandPorts, 0x40);
        func_0214d018_inline(gWiFiMatching->mParticipantProfileIds, 0x80);
        func_0214d018_inline(gWiFiMatching->mNNInfo, 0xc);
        func_0214d018_inline(gWiFiMatching->mParticipantConnectAddresses, 0x80);
        g = 0;
        MIi_CpuClear16(g, gWiFiMatching->mParticipantConnectPorts, 0x40);
        MI_CpuFill8(gWiFiMatching->mParticipantIndices, 0, 0x20);
        func_0214d018_inline(gWiFiMatching->mReceivedList, 0x84);
        if (level == 1) {
            if (gWiFiMatching->mMode == 0) {
                gWiFiMatching->mState = 3;
                return;
            }
            if (gWiFiMatching->mMode == 1) {
                gWiFiMatching->mState = 4;
                return;
            }
        } else {
            gWiFiMatching->mMode = 0;
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
void DWCi_SetMatchCommonParam(u8 matchType, u8 numEntry, UnkFunc *matchedCallback, u32 matchedParam) {
    WiFiMatching **v1;
    DWCi_ResetMatchParam(0);
    v1 = &gWiFiMatching;
    gWiFiMatching->mMode = matchType;
    (*v1)->mNumEntry = numEntry;
    (*v1)->mResultCallback = matchedCallback;
    (*v1)->mResultCallbackArg = matchedParam;
    (*v1)->mNatnegCounts[1] = 0;
    (*v1)->mParticipantIndices[0] = 0;
    qr2_register_keyA(0x32, gDwcPidKey);
    qr2_register_keyA(0x33, gDwcMtypeKey);
    qr2_register_keyA(0x34, gDwcMresvKey);
    qr2_register_keyA(0x35, gDwcMverKey);
    qr2_register_keyA(0x36, gDwcEvalKey);
}

void DWCi_CloseMatching(void) {
    if (gWiFiMatching != NULL) {
        if (gWiFiMatching->mServerList != NULL) {
            ServerBrowserFree(gWiFiMatching->mServerList);
            gWiFiMatching->mServerList = NULL;
        }
        NNFreeNegotiateList();
        gWiFiMatching->mState = 0;
        if (gMatchingFilterText != NULL) {
            DWC_Free(4, (u32) gMatchingFilterText, 0);
            gMatchingFilterText = NULL;
        }
        DWCi_ClearGameMatchKeys();
        gWiFiMatching->mQr2ShutdownPending = 1;
    }
}

u32 DWCi_SBUpdateAsync(u32 profileId) {
    char filterText[0x100];
    u8 fieldIds[0xa8];
    s32 i;
    u8 *e;
    u8 *w;
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
    if (gWiFiMatching->mMode == 0 || gWiFiMatching->mMode == 1) {
        i = 0;
        e = gMatchingKeys[0];
        w = fieldIds + 7;
        for (; i < 0x9a; i++) {
            if (e[0] != 0) {
                *w = e[0];
                w++;
                fieldCount++;
            }
            e += 12;
        }
    }
    switch (gWiFiMatching->mState) {
        case 3:
            profileId = gWiFiMatching->mPriorProfileId;
            if (profileId == 0) {
                DWCi_GetDefaultMatchFilter(filterText, gWiFiMatching->mOwnProfileId, gWiFiMatching->mNumEntry,
                                           gWiFiMatching->mMode);
                if (gMatchingFilterText != NULL) {
                    OS_SNPrintf(filterText, 0x100, gAndParenFormat, filterText, gMatchingFilterText);
                }
                break;
            }
        case 2:
        case 4:
        case 5:
            OS_SNPrintf(filterText, 0x100, gKeyEqualsUnsignedFormat, gDwcPidKey, profileId);
            gWiFiMatching->mReplyProfileId = profileId;
            break;
    }
    ServerBrowserClear(gWiFiMatching->mServerList);
    for (i = 0; i < 5; i++) {
        updateResult = ServerBrowserLimitUpdateA(gWiFiMatching->mServerList, 1, 0, fieldIds, fieldCount, (u32) filterText,
                                            0x10);
        if (updateResult == 0 || updateResult != 2) {
            break;
        }
    }
    return updateResult;
}

s32 DWCi_GetDefaultMatchFilter(char *buffer, s32 profileId, s32 numEntry, s32 mode) {
    return OS_SNPrintf(buffer, 0x100, gMatchingFilterFormat, gDwcMverKey, 3, gDwcPidKey, profileId, numEntry, numEntry,
                       gDwcMtypeKey, mode, gDwcMresvKey, gDwcPidKey);
}

u32 DWCi_NNStartupAsync(s32 isQR2, s32 cookie, u32 server) {
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
            if (SBServerGetPublicInetAddress((u32 *) server) ==
                ServerBrowserGetMyPublicIPAddr(gWiFiMatching->mServerList)) {
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
                gWiFiMatching->mParticipantConnectAddresses[index] = SBServerGetPublicInetAddress((u32 *) server);
                gWiFiMatching->mParticipantConnectPorts[index] = SBServerGetPublicQueryPort(server);
                canStart = FALSE;
            }
        }
        if (canStart != FALSE) {
            gWiFiMatching->mCookieRandom = DWCi_GetMathRand32(0x10000);
            gWiFiMatching->mNNCookie = cookie;
        } else {
            words[0] = SOC_GetHostID();
            words[1] = GetSocketPort(*gWiFiMatching->mConnectionSocket);
            result = DWCi_SendMatchCommand(6, gWiFiMatching->mParticipantProfileIds[index],
                                           SBServerGetPublicInetAddress((u32 *) server),
                                           SBServerGetPublicQueryPort(server), words, 2);
            gWiFiMatching->mResendCount = 0;
            if (result != 0) {
                return 2;
            }
            gWiFiMatching->mNNCookie = 0;
        }
        gWiFiMatching->mNNInfo[0] = 0;
        gWiFiMatching->mNNInfo[1] = 0;
        *(u16 *) &gWiFiMatching->mNNInfo[2] = SBServerGetPublicQueryPort(server);
        *(u32 *) &gWiFiMatching->mNNInfo[4] = SBServerGetPublicInetAddress((u32 *) server);
    } else {
        canStart = TRUE;
        gWiFiMatching->mNNInfo[0] = 1;
        gWiFiMatching->mNNInfo[1] = startResult;
        *(u16 *) &gWiFiMatching->mNNInfo[2] = startResult;
        *(u32 *) &gWiFiMatching->mNNInfo[4] = startResult;
        gWiFiMatching->mNNCookie = cookie;
    }
    if (canStart != FALSE) {
        startResult = DWCi_DoNatNegotiationAsync((DWCNNInfo *) gWiFiMatching->mNNInfo);
    } else {
        DWCi_NNCompletedCallback(0, GetSocketDescriptor(*gWiFiMatching->mConnectionSocket), 0, gWiFiMatching->mNNInfo);
        gWiFiMatching->mIncomingWaitStartTime = 0;
    }
    return startResult;
}

u32 DWCi_DoNatNegotiationAsync(DWCNNInfo *nnInfo) {
    u32 beginResult;
    s32 i;

    if (nnInfo->mIsQR2 == 0) {
        if (DWCi_HandleSBError(ServerBrowserSendNatNegotiateCookieToServerA(gWiFiMatching->mServerList,
                                                                   gt2AddressToString(nnInfo->mAddress, 0, 0),
                                                                   nnInfo->mPort, nnInfo->mCookie)) != 0) {
            return 2;
        }
    }
    for (i = 0; i < 5; i++) {
        beginResult = NNBeginNegotiationWithSocket(GetSocketDescriptor(*gWiFiMatching->mConnectionSocket), nnInfo->mCookie,
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
    u32 *w;
    s32 n;
    s32 k;
    s32 tmpLen;

    n = 0;
    if (gWiFiMatching->mMode == 0 ||
        ((gWiFiMatching->mMode == 3 || gWiFiMatching->mDistantFriend != 0) && command == 6)) {
        n = DWCi_SendSBMsgCommand(command, address, port, values, valueCount);
    } else {
        if (values != NULL && valueCount != 0) {
            w = values;
            n = OS_SNPrintf(message, 0x200, gUnsignedFormat, w[0]);
            for (k = 1; k < valueCount; k++) {
                tmpLen = OS_SNPrintf(numBuf, 0x10, gSlashUnsignedFormat, w[k]);
                MI_CpuCopy8(numBuf, message + n, tmpLen);
                n += tmpLen;
            }
        }
        message[n] = 0;
        n = DWCi_SendGPBuddyMsgCommand(gWiFiMatching->mGpConnection, command, profileId, message);
    }
    if (command == 2 || command == 6 || (u8) (command + 0xf8) <= 1) {
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
    return n;
}

u32 DWCi_SendSBMsgCommand(u32 command, u32 address, u32 port, u32 *values, u32 valueCount) {
    u32 valuesCopy[0x21];
    MatchingSendHeader header;
    u32 sendResult;
    s32 i;

    if (values != NULL && valueCount != 0) {
        MIi_CpuCopy32(values, valuesCopy, valueCount * 4);
    } else {
        valueCount = 0;
    }
    *(MatchingSignatureText *) &header = *(MatchingSignatureText *) gMatchingSignature;
    header.mVersion = 3;
    header.mCommand = command;
    header.mValuesSize = valueCount * 4;
    header.mPort = gWiFiMatching->mOwnPort;
    header.mAddress = gWiFiMatching->mOwnAddress;
    header.mProfileId = gWiFiMatching->mOwnProfileId;
    for (i = 0; i < 5; i++) {
        sendResult = ServerBrowserSendMessageToServerA(gWiFiMatching->mServerList, gt2AddressToString(address, 0, 0), port,
                                                    (u8 *) &header, header.mValuesSize + 0x14);
        if (sendResult == 0 || sendResult != 2) {
            break;
        }
    }
    return sendResult;
}

s32 DWCi_SendGPBuddyMsgCommand(struct GpConnection *gpConnection, u32 command, u32 profileId, const char *text) {
    char msgBuf[0x200];
    char *e;
    char *g;
    s32 len2;
    s32 len;

    len = OS_SNPrintf(msgBuf, 0x200, gGpMessagePrefixFormat, gGpcmPrefix, 3, gMatTag);
    msgBuf[len] = command;
    g = msgBuf + 1;
    e = g + len;
    g[len] = 0;
    if (text != NULL) {
        len2 = strlen(text);
        MI_CpuCopy8(text, e, len2);
        e[len2] = 0;
    }
    return GpSendMessage(gpConnection, profileId, msgBuf);
}

s32 DWCi_GetGPBuddyAdditionalMsg(char *out, const char *text, s32 index) {
    const char *textEnd;
    const char *slash;
    s32 i;
    s32 len;

    textEnd = strchr(text, 0);
    for (i = 0; i < index; i++) {
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
s32 DWCi_ProcessRecvMatchCommand(s32 command, u32 profileId, u32 c, u16 d, u32 *values, s32 valueCount) {
    u32 *w;
    u32 z;
    PeerAddress s;
    u32 g[0x41];
    s32 i;
    s32 t;
    u16 y;
    s32 x;
    u32 u;
    u8 v;
    WiFiMatching *o;
    WiFiMatching *p;
    DWCMatchOptMinCompleteIn *q;
    u32 *n;

    i = 0;
    o = gWiFiMatching;
    if (o == NULL || o->mState == 0) {
        return 1;
    }
    switch (command) {
        case 1:
        case 11:
            t = DWCi_CheckResvCommand(profileId, values[0], command == 11 ? 1 : 0);
            if (t == 2) {
                if (gWiFiMatching->mMode != 0) {
                    c = values[1];
                    d = values[2];
                }
                if (DWCi_HandleMatchCommandError(DWCi_ProcessResvOK(profileId, c, d)) != 0) {
                    return 0;
                }
                p = gWiFiMatching;
                if (p->mMode == 2 && p->mNewParticipantCallback != NULL) {
                    gWiFiMatching->mNewParticipantCallback(DWCi_GetFriendListIndex(profileId),
                                                           p->mNewParticipantCallbackArg);
                }
                g[0] = gWiFiMatching->mNNCompletedCount;
                for (i = 1; i <= gWiFiMatching->mNNCompletedCount; i++) {
                    g[i] = gWiFiMatching->mParticipantProfileIds[i];
                }
                p = gWiFiMatching;
                g[i++] = (u32) p->mOwnAddress;
                g[i++] = p->mOwnPort;
                p->mState = 11;
            }
            if (t == 0xff) {
                break;
            }
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(t, profileId, c, d, g, i)) == 0) {
                break;
            }
            return 0;
        case 2:
            if (o->mState != 4) {
                break;
            }
            if (profileId != o->mReplyProfileId) {
                break;
            }
            o->mPriorProfileId = 0;
            gWiFiMatching->mPriorResvDelayCount = 0;
            gWiFiMatching->mResvTimeoutMs = 0;
            gWiFiMatching->mResvDelayPending = 0;
            gWiFiMatching->mParticipantCommandAddresses[0] = (values + values[0])[1];
            gWiFiMatching->mParticipantCommandPorts[0] = (values + values[0])[2];
            gWiFiMatching->mServerAddress = (values + values[0])[1];
            gWiFiMatching->mServerPort = (values + values[0])[2];
            if (gWiFiMatching->mMode == 1) {
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
            if (gWiFiMatching->mMode == 0) {
                if (gWiFiMatching->mLastParticipantPos != 0) {
                    DWCi_MakeBackupServerData(profileId, values);
                    if (DWCi_HandleMatchCommandError(DWCi_ChangeToClient()) != 0) {
                        return 0;
                    }
                }
                gWiFiMatching->mState = 6;
                if (DWCi_HandleNNError(
                        DWCi_NNStartupAsync(0, 0, ServerBrowserGetServer(gWiFiMatching->mServerList, 0))) == 0) {
                    break;
                }
                return 0;
            } else {
                gWiFiMatching->mState = 5;
                if (DWCi_HandleSBError(DWCi_SBUpdateAsync(profileId)) == 0) {
                    break;
                }
                return 0;
            }
        case 3:
            if (o->mState != 4) {
                break;
            }
            if (profileId != o->mReplyProfileId) {
                break;
            }
            return DWCi_RetryReserving();
        case 4:
            if (o->mState != 4) {
                break;
            }
            if (profileId != o->mReplyProfileId) {
                break;
            }
            o->mResvTimeoutStartTick = OS_GetTick();
            if ((o->mPriorProfileId != 0 && o->mPriorResvDelayCount < 0x10) || o->mMode == 3) {
                o->mResvDelayPending = 1;
                p = gWiFiMatching;
                p->mResvDelayStartTick = OS_GetTick();
                if (p->mMode == 3) {
                    break;
                }
                p->mPriorResvDelayCount++;
                break;
            }
            o->mPriorProfileId = 0;
            gWiFiMatching->mPriorResvDelayCount = 0;
            p = gWiFiMatching;
            if (p->mMode == 0) {
                p->mState = 3;
                gWiFiMatching->mServerUpdateWaitKind = 1;
                gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
            } else if (p->mMode == 1) {
                DWCi_SendResvCommandToFriend(1, 0);
            }
            break;
        case 5:
            if (o->mMresvPresent == 0) {
                break;
            }
            if (profileId != o->mMresvProfileId) {
                break;
            }
            if (o->mMode == 2 && o->mLastParticipantPos == 1 && o->mParticipantProfileIds[1] == profileId) {
                gt2CloseAllConnectionsHard(*o->mConnectionSocket);
            }
            if (DWCi_CancelPreConnectedServerProcess(profileId) == 0) {
                return 0;
            }
            break;
        case 6:
            x = values[0];
            y = values[1];
            if (o->mState == 1) {
                o->mState = 6;
            } else {
                if (o->mState != 6 && o->mState != 11) {
                    break;
                }
                if (profileId != o->mMresvProfileId) {
                    break;
                }
            }
            gWiFiMatching->mLastCommand = 0xff;
            p = gWiFiMatching;
            n = &p->mParticipantProfileIds[p->mLastParticipantPos + 1];
            if (profileId != *n) {
                *n = profileId;
            }
            s.mAddress = x;
            s.mPort = ((y >> 8) & 0xff) | ((y << 8) & 0xff00);
            gWiFiMatching->mNNInfo[0] = 1;
            p = gWiFiMatching;
            DWCi_NNCompletedCallback(0, GetSocketDescriptor(*p->mConnectionSocket), &s, p->mNNInfo);
            gWiFiMatching->mIncomingWaitStartTime = 0;
            break;
        case 7:
            z = values[0];
            u = values[1];
            o->mParticipantProfileIds[o->mNNCompletedCount + 1] = z;
            gWiFiMatching->mParticipantIndices[gWiFiMatching->mNNCompletedCount + 1] = u;
            qr2_send_statechanged(gWiFiMatching->mQr2);
            p = gWiFiMatching;
            if (p->mNewParticipantCallback == NULL) {
                break;
            }
            gWiFiMatching->mNewParticipantCallback(DWCi_GetFriendListIndex(z), p->mNewParticipantCallbackArg);
            break;
        case 8:
            x = values[0];
            z = x;
            if (x == 0) {
                u = values[1];
                o->mParticipantIndices[u] = values[2];
                gWiFiMatching->mParticipantProfileIds[u] = gWiFiMatching->mOwnProfileId;
                DWCi_PostProcessConnection(3);
                break;
            }
            u = values[1];
            v = values[2];
            w = &o->mParticipantProfileIds[u];
            if (x == *w && u == o->mLastParticipantPos - 1) {
                if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(9, profileId, o->mParticipantCommandAddresses[0],
                                                                       o->mParticipantCommandPorts[0], &z, 1)) == 0) {
                    break;
                }
                return 0;
            }
            *w = x;
            gWiFiMatching->mParticipantIndices[u] = v;
            gWiFiMatching->mParticipantCommandAddresses[u] = values[3];
            gWiFiMatching->mParticipantCommandPorts[u] = values[4];
            gWiFiMatching->mServerAddress = values[3];
            gWiFiMatching->mServerPort = values[4];
            gWiFiMatching->mState = 5;
            if (DWCi_HandleSBError(DWCi_SBUpdateAsync(z)) != 0) {
                return 0;
            }
            gWiFiMatching->mResvTimeoutMs = 0;
            gWiFiMatching->mResvDelayPending = 0;
            break;
        case 9:
            if (o->mState != 13) {
                break;
            }
            if (values[0] != o->mParticipantProfileIds[o->mPostProcessPos + 1]) {
                break;
            }
            o->mPostProcessPos++;
            DWCi_PostProcessConnection(0);
            break;
        case 10:
            if (o->mMode == 0 || DWCi_AreAllBuddies(values + 1, values[0]) != 0) {
                gWiFiMatching->mPriorProfileId = values[1];
                gWiFiMatching->mPriorResvDelayCount = 0;
            } else {
                gWiFiMatching->mPriorProfileId = 0;
            }
            p = gWiFiMatching;
            if (p->mLastParticipantPos != 0) {
                gt2CloseAllConnectionsHard(*p->mConnectionSocket);
                break;
            }
            if (DWCi_ResumeMatching() == 0) {
                break;
            }
            return 0;
        case 12:
            if (o->mMode == 0 || o->mMode == 1) {
                if (DWCi_CancelPreConnectedClientProcess(profileId) != 0) {
                    break;
                }
                return 0;
            }
            if (o->mMode == 3) {
                if (values[0] == 0) {
                    o->mEventProfileId = profileId;
                    DWCi_CloseAllConnectionsByTimeout();
                    DWCi_RestartFromCancel(0);
                } else {
                    DWCi_CloseCancelHostAsync(values[0]);
                }
            }
            break;
        case 13:
        case 14:
        case 15:
            if (DWCi_ProcessCancelMatchSynCommand(profileId, command, values[0]) != FALSE) {
                break;
            }
            return 0;
        case 16:
            if (profileId != o->mParticipantProfileIds[0]) {
                return 1;
            }
            for (i = 0; i < valueCount; i++) {
                t = DWCi_GetAIDFromProfileID(values[i], 0);
                if (t != 0xff) {
                    DWC_CloseConnectionHard(t);
                }
            }
            break;
        case 17:
            q = gOptMinComp;
            if (q != NULL && q->mValid != 0 && MatchingGetTickMilliseconds() - q->mStartTime >= q->mTimeout) {
                g[0] = 1;
            } else {
                g[0] = 0;
            }
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(0x12, profileId, c, d, g, 1)) == 0) {
                break;
            }
            return 0;
        case 18:
            if (o->mState != 0x13) {
                break;
            }
            t = DWCi_GetAIDFromProfileID(profileId, 0);
            if (t == 0xff) {
                break;
            }
            gOptMinComp->mRecvBit |= 1 << t;
            if (values[0] != 0) {
                gOptMinComp->mTimeoutBit |= 1 << t;
            }
            break;
        case 19:
            DWCi_StopMatching(10, -80000);
            return 0;
    }
    return 1;
}

s32 DWCi_CheckResvCommand(s32 profileId, u32 senderMode, s32 priorFlag) {
    s32 reply;

    switch (gWiFiMatching->mMode) {
        case 1:
            if (GpIsBuddy(gWiFiMatching->mGpConnection, profileId) == 0) {
                reply = 0xff;
                break;
            }
        case 0:
            if (senderMode != gWiFiMatching->mMode || gWiFiMatching->mStopPending != 0 ||
                gWiFiMatching->mNNCompletedCount == gWiFiMatching->mNumEntry ||
                (gWiFiMatching->mMresvPresent != 0 && gWiFiMatching->mMresvProfileId == gWiFiMatching->mOwnProfileId)) {
                reply = 3;
                if (gWiFiMatching->mMode == 0 && gWiFiMatching->mQr2->mUserStateChangeRequested == FALSE &&
                    gWiFiMatching->mMresvPresent != 0 &&
                    gWiFiMatching->mMresvProfileId == gWiFiMatching->mOwnProfileId) {
                    qr2_send_statechanged(gWiFiMatching->mQr2);
                }
            } else if ((gWiFiMatching->mState != 3 && gWiFiMatching->mState != 4) ||
                       (gWiFiMatching->mOwnAddress == NULL && gWiFiMatching->mOwnPort == 0)) {
                reply = 4;
            } else if (gWiFiMatching->mReplyProfileId != 0) {
                if (gWiFiMatching->mReplyProfileId == profileId) {
                    if (priorFlag != 0 || ((s32) gWiFiMatching->mOwnProfileId < profileId &&
                                           profileId != gWiFiMatching->mPriorProfileId)) {
                        reply = 2;
                    } else {
                        reply = 0xff;
                    }
                } else if (priorFlag != 0 ||
                           ((s32) gWiFiMatching->mOwnProfileId < profileId && gWiFiMatching->mPriorProfileId == 0)) {
                    if (DWCi_HandleMatchCommandError(DWCi_CancelReservation(gWiFiMatching->mReplyProfileId)) != 0) {
                        return 0xff;
                    }
                    reply = 2;
                } else {
                    reply = 3;
                }
            } else {
                reply = 2;
            }
            break;
        case 2:
            if (GpIsBuddy(gWiFiMatching->mGpConnection, profileId) == 0) {
                reply = 0xff;
            } else if (senderMode != 3 || gWiFiMatching->mNNCompletedCount == gWiFiMatching->mNumEntry) {
                reply = 3;
            } else if (gOptSCBlock.mValid == 1 && gOptSCBlock.mLock == 1) {
                reply = 0x13;
            } else if (gWiFiMatching->mState != 10 ||
                       (gWiFiMatching->mOwnAddress == NULL && gWiFiMatching->mOwnPort == 0)) {
                reply = 4;
            } else {
                reply = 2;
            }
            break;
    }
    return reply;
}

u32 DWCi_ProcessResvOK(u32 profileId, u32 address, u16 port) {
    u32 words[2];
    s32 i;
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
    for (i = 1; i <= gWiFiMatching->mNNCompletedCount; i++) {
        result = DWCi_SendMatchCommand(7, gWiFiMatching->mParticipantProfileIds[i],
                                       gWiFiMatching->mParticipantCommandAddresses[i],
                                       gWiFiMatching->mParticipantCommandPorts[i], words, 2);
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
    if (gWiFiMatching->mMode == 0) {
        return DWCi_HandleSBError(result);
    }
    return ReportMatchingGpResult(result);
}

u32 DWCi_SendResvCommand(u32 profileId, s32 delay) {
    u32 words[3];
    u32 serverEntry;
    u32 wordCount;
    u32 resvKind;

    if (delay != 0) {
        gWiFiMatching->mResvDelayPending = 1;
        gWiFiMatching->mResvDelayStartTick = OS_GetTick();
        gWiFiMatching->mParticipantProfileIds[0] = profileId;
        return 0;
    }
    if (gWiFiMatching->mMode == 0) {
        serverEntry = ServerBrowserGetServer(gWiFiMatching->mServerList, 0);
        gWiFiMatching->mParticipantProfileIds[0] = SbServerGetInt((SbServer *) serverEntry, gDwcPidKey, 0);
        gWiFiMatching->mParticipantCommandAddresses[0] = SBServerGetPublicInetAddress((u32 *) serverEntry);
        gWiFiMatching->mParticipantCommandPorts[0] = SBServerGetPublicQueryPort(serverEntry);
        gWiFiMatching->mReplyProfileId = gWiFiMatching->mParticipantProfileIds[0];
        wordCount = 1;
    } else {
        if (gWiFiMatching->mMode == 1) {
            gWiFiMatching->mParticipantProfileIds[0] = profileId;
        }
        gWiFiMatching->mReplyProfileId = profileId;
        words[1] = (u32) gWiFiMatching->mOwnAddress;
        words[2] = gWiFiMatching->mOwnPort;
        wordCount = 3;
    }
    gWiFiMatching->mResvTimeoutMs = 6000;
    gWiFiMatching->mResvTimeoutStartTick = OS_GetTick();
    gWiFiMatching->mResvDelayPending = 0;
    resvKind = gWiFiMatching->mPriorProfileId != 0 ? 11 : 1;
    words[0] = gWiFiMatching->mMode;
    return DWCi_SendMatchCommand(resvKind, profileId, gWiFiMatching->mParticipantCommandAddresses[0],
                                 gWiFiMatching->mParticipantCommandPorts[0], words, wordCount);
}

u32 DWCi_SendResvCommandToFriend(s32 delay, s32 init) {
    BOOL d;
    s32 firstIndex;
    BOOL wrapped;
    s32 entryTextLength;
    char g[8];
    s32 buddy;
    char verText[12];
    GpBuddyStatus status;
    WiFiMatching *wiFiMatching;
    s32 profileId;
    u32 gpStatus;
    s32 k;
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
    d = init == 0;
    while (1) {
        if (d != FALSE || wrapped != FALSE) {
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
        for (k = 1; k <= gWiFiMatching->mLastParticipantPos; k++) {
            if (profileId == gWiFiMatching->mParticipantProfileIds[k]) {
                break;
            }
        }
        if (k <= gWiFiMatching->mLastParticipantPos) {
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
        verLen = DWC_GetCommonValueString(gVerKey, verText, status.mStatusString, 0x2f);
        entryTextLength = DWC_GetCommonValueString(gFmeKey, g + 2, status.mStatusString, 0x2f);
        peerTextLength = DWC_GetCommonValueString(gMdfKey, g, status.mStatusString, 0x2f);
        if (verLen > 0 && entryTextLength > 0 && peerTextLength > 0) {
            if (strtoul(verText, NULL, 10) == 3) {
                if (gWiFiMatching->mNumEntry == strtoul(g + 2, NULL, 10)) {
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
    if (wiFiMatching->mMode == 0) {
        wiFiMatching->mState = 3;
        if (DWCi_HandleSBError(DWCi_SBUpdateAsync(0)) != 0) {
            return 0;
        }
    } else if (wiFiMatching->mMode == 1) {
        if (DWCi_HandleMatchCommandError(DWCi_SendResvCommandToFriend(0, 0)) != 0) {
            return 0;
        }
    } else if (wiFiMatching->mMode == 3) {
        DWCi_StopMatching(6, -80410);
        return 0;
    }
    return 1;
}

u32 DWCi_CancelReservation(u32 profileId) {
    u32 result;
    result = DWCi_SendMatchCommand(5, profileId, gWiFiMatching->mParticipantCommandAddresses[0],
                                   gWiFiMatching->mParticipantCommandPorts[0], NULL, 0);
    gWiFiMatching->mReplyProfileId = 0;
    return result;
}

u32 DWCi_CancelPreConnectedServerProcess(u32 clientPid) {
    s32 i;
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
    gWiFiMatching->mLastCommand = 0xff;
    if (gWiFiMatching->mNNCookie != 0) {
        NNCancel(gWiFiMatching->mNNCookie);
        gWiFiMatching->mNNCookie = 0;
    }
    gWiFiMatching->mNNCompletedCount = gWiFiMatching->mLastParticipantPos;
    gWiFiMatching->mReplyProfileId = 0;
    if (hostSide == 0) {
        if (gWiFiMatching->mMode != 3) {
            DWCi_RestartFromTimeout();
        }
    } else if (gWiFiMatching->mMode == 0) {
        gWiFiMatching->mState = 3;
        gWiFiMatching->mServerUpdateWaitKind = 2;
        gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
    } else if (gWiFiMatching->mMode == 1) {
        gWiFiMatching->mState = 4;
        DWCi_SendResvCommandToFriend(1, 0);
    } else if (gWiFiMatching->mMode == 2) {
        gWiFiMatching->mState = 14;
        gWiFiMatching->mCancelSynReplyMask = 0;
        gWiFiMatching->mCancelSynLatency = 0;
        DWCi_CloseCancelHostAsync(clientPid);
        for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
            if (DWCi_SendCancelMatchSynCommand(gWiFiMatching->mParticipantProfileIds[i], 0xd) == 0) {
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
    if (gWiFiMatching->mMode == 3) {
        if (gWiFiMatching->mLastParticipantPos != 0) {
            DWCi_CloseAllConnectionsByTimeout();
        }
        DWCi_StopMatching(6, -80430);
        return 0;
    }
    gWiFiMatching->mNNCompletedCount = gWiFiMatching->mLastParticipantPos;
    gWiFiMatching->mPriorProfileId = 0;
    if (gWiFiMatching->mNNCookie != 0) {
        NNCancel(gWiFiMatching->mNNCookie);
        gWiFiMatching->mNNCookie = 0;
    }
    if (gWiFiMatching->mLastParticipantPos != 0) {
        DWCi_RestartFromTimeout();
    } else {
        gWiFiMatching->mState = 4;
        result = DWCi_RetryReserving();
    }
    return result;
}

u32 DWCi_ChangeToClient(void) {
    s32 i;
    u32 r;

    for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
        r = DWCi_SendMatchCommand(10, gWiFiMatching->mParticipantProfileIds[i],
                                  gWiFiMatching->mParticipantCommandAddresses[i],
                                  gWiFiMatching->mParticipantCommandPorts[i], gWiFiMatching->mReceivedList,
                                  gWiFiMatching->mReceivedList[0] + 1);
        if (r != 0) {
            return r;
        }
    }
    gWiFiMatching->mMresvPresent = 0;
    gWiFiMatching->mMresvProfileId = 0;
    gWiFiMatching->mCloseKind = 1;
    gt2CloseAllConnectionsHard(*gWiFiMatching->mConnectionSocket);
    gWiFiMatching->mCloseKind = 0;
    return 0;
}

void DWCi_PostProcessConnection(s32 type) {
    WiFiMatching *wiFiMatching;
    u32 words[4];
    s32 wordCount;
    s32 clearFlag;
    s32 n;
    BOOL c;
    wordCount = 3;
    clearFlag = 0;
    switch (type) {
        case 0:
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mPostProcessPos < wiFiMatching->mLastParticipantPos - 1) {
                wiFiMatching->mState = 13;
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
                if (wiFiMatching->mMode == 0) {
                    wiFiMatching->mState = 3;
                } else if (wiFiMatching->mMode == 1) {
                    wiFiMatching->mState = 4;
                } else {
                    wiFiMatching->mState = 10;
                }
                gWiFiMatching->mPostProcessPos = 0;
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mMode == 2 || wiFiMatching->mLastParticipantPos == wiFiMatching->mNumEntry) {
                    if (wiFiMatching->mMode == 2) {
                        wiFiMatching = gWiFiMatching;
                        wiFiMatching->mEventProfileId =
                            wiFiMatching->mParticipantProfileIds[wiFiMatching->mLastParticipantPos];
                    } else {
                        wiFiMatching->mEventProfileId = 0;
                        wiFiMatching = gWiFiMatching;
                        wiFiMatching->mParticipantProfileIds[0] = wiFiMatching->mOwnProfileId;
                    }
                    gWiFiMatching->mState = 16;
                    gWiFiMatching->mSynReplyMask = 0;
                    for (n = 1; n <= gWiFiMatching->mLastParticipantPos; n++) {
                        DWCi_SendMatchSynPacket(gWiFiMatching->mParticipantIndices[n], 2);
                    }
                } else {
                    words[0] = 0;
                    words[1] = wiFiMatching->mLastParticipantPos;
                    words[2] = wiFiMatching->mParticipantIndices[wiFiMatching->mLastParticipantPos];
                    if (wiFiMatching->mMode == 0) {
                        wiFiMatching->mServerUpdateWaitKind = 2;
                        gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                    } else if (wiFiMatching->mMode == 1) {
                        DWCi_SendResvCommandToFriend(1, 0);
                    }
                }
                if (gWiFiMatching->mMode != 2) {
                    clearFlag = 1;
                }
            }
            if (gWiFiMatching->mState == 16) {
                break;
            }
            wiFiMatching = gWiFiMatching;
            n = wiFiMatching->mLastParticipantPos;
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                    8, wiFiMatching->mParticipantProfileIds[n], wiFiMatching->mParticipantCommandAddresses[n],
                    wiFiMatching->mParticipantCommandPorts[n], words, wordCount)) != 0) {
                return;
            }
            gWiFiMatching->mResendCount = 0;
            break;
        case 1:
            gWiFiMatching->mState = 1;
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mMode == 3) {
                wiFiMatching->mEventProfileId = wiFiMatching->mParticipantProfileIds[wiFiMatching->mLastParticipantPos];
            }
            clearFlag = 1;
            break;
        case 2:
            gWiFiMatching->mState = 1;
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mMode == 0 || wiFiMatching->mMode == 1) {
                wiFiMatching->mMresvPresent = 1;
                gWiFiMatching->mMresvProfileId = gWiFiMatching->mOwnProfileId;
            }
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mLastParticipantPos > 1) {
                if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                        9, wiFiMatching->mParticipantProfileIds[0], wiFiMatching->mParticipantCommandAddresses[0],
                        wiFiMatching->mParticipantCommandPorts[0],
                        &wiFiMatching->mParticipantProfileIds[wiFiMatching->mLastParticipantPos - 1], 1)) != 0) {
                    return;
                }
            }
            break;
        case 3:
            gWiFiMatching->mState = 1;
            gWiFiMatching->mEventProfileId = clearFlag;
            clearFlag = 1;
            break;
        case 4:
            if (gWiFiMatching->mMode != 2) {
                DWCi_SetGPStatus(2, gEmptyString, (void *) clearFlag);
            }
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mEventProfileId == 0) {
                c = TRUE;
            } else {
                c = FALSE;
            }
            gWiFiMatching->mResultCallback(0, 0, c, 0, DWCi_GetFriendListIndex(gWiFiMatching->mEventProfileId),
                                           wiFiMatching->mResultCallbackArg);
            wiFiMatching = gWiFiMatching;
            if (wiFiMatching->mMode == 0 || wiFiMatching->mMode == 1) {
                DWCi_CloseMatching();
            } else {
                if (wiFiMatching->mServerList != NULL) {
                    ServerBrowserFree(wiFiMatching->mServerList);
                    gWiFiMatching->mServerList = NULL;
                }
                NNFreeNegotiateList();
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mMode == 2) {
                    if (ReportMatchingGpResult(DWCi_GPSetServerStatus()) != 0) {
                        return;
                    }
                    if (gOptSCBlock.mValid == 1) {
                        gOptSCBlock.mLock = 1;
                    }
                    gWiFiMatching->mState = 10;
                } else {
                    wiFiMatching->mState = 1;
                }
                gWiFiMatching->mEventProfileId = 0;
            }
            gWiFiMatching->mStopPending = 0;
            break;
    }
    if (clearFlag != 0) {
        wiFiMatching = gWiFiMatching;
        if (wiFiMatching->mMode != 3) {
            ServerBrowserClear(wiFiMatching->mServerList);
        }
    }
}

u32 DWCi_AreAllBuddies(u32 *pidList, u32 pidListLen) {
    WiFiMatching *wiFiMatching;
    u32 i;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mDistantFriend != 0 && wiFiMatching->mState == 4) {
        return 1;
    }
    for (i = 0; i < pidListLen; i++) {
        if (GpIsBuddy(wiFiMatching->mGpConnection, *pidList) == 0) {
            return 0;
        }
        wiFiMatching = gWiFiMatching;
        if (wiFiMatching->mDistantFriend != 0 && wiFiMatching->mState == 1) {
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
    if (wiFiMatching->mState == 2) {
        DWCi_FinishCancelMatching();
        return;
    }
    wiFiMatching->mStopPending = 1;
    wiFiMatching = gWiFiMatching;
    word = wiFiMatching->mMode;
    if (word == 3) {
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
    if (wiFiMatching->mState == 4 || wiFiMatching->mState == 5 || wiFiMatching->mState == 6 ||
        wiFiMatching->mState == 7 || wiFiMatching->mState == 11 || wiFiMatching->mState == 12) {
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
    if (wiFiMatching->mNNCookie != 0) {
        NNCancel(wiFiMatching->mNNCookie);
        gWiFiMatching->mNNCookie = 0;
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
    if (ReportMatchingGpResult(DWCi_SetGPStatus(1, gEmptyString, NULL)) == 0) {
        DWCi_CloseMatching();
        wiFiMatching = gWiFiMatching;
        eventProfileId = wiFiMatching->mEventProfileId;
        if (eventProfileId != 0) {
            isServer = TRUE;
        } else if (wiFiMatching->mMode == 2) {
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
        result = DWCi_SendMatchCommand(12, wiFiMatching->mMresvProfileId,
                                       wiFiMatching->mParticipantCommandAddresses[hostIndex],
                                       wiFiMatching->mParticipantCommandPorts[hostIndex], &word, 1);
        gWiFiMatching->mMresvPresent = 0;
        gWiFiMatching->mMresvProfileId = 0;
    }
    return result;
}

void DWCi_RestartFromCancel(s32 level) {
    WiFiMatching *wiFiMatching;
    s32 b;
    BOOL isSelf;
    if (level == 0) {
        DWCi_FinishCancelMatching();
        return;
    }
    DWCi_ResetMatchParam(level);
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMode == 2 || wiFiMatching->mMode == 3) {
        if (wiFiMatching->mEventProfileId == 0) {
            isSelf = TRUE;
        } else {
            isSelf = FALSE;
        }
        gWiFiMatching->mResultCallback(0, 1, isSelf, 0, DWCi_GetFriendListIndex(wiFiMatching->mEventProfileId),
                                       wiFiMatching->mResultCallbackArg);
    } else if (wiFiMatching->mMode == 0) {
        if (level == 1) {
            if (DWCi_HandleSBError(DWCi_SBUpdateAsync(0)) != 0) {
                return;
            }
        }
    } else if (wiFiMatching->mMode == 1) {
        if (level == 1) {
            DWCi_SendResvCommandToFriend(0, 0);
        }
    }
}

void DWCi_RestartFromTimeout(void) {
    WiFiMatching *wiFiMatching;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMode != 2 && wiFiMatching->mMode != 3) {
        DWCi_CloseAllConnectionsByTimeout();
        DWCi_RestartFromCancel(1);
    }
}

u32 DWCi_ResumeMatching(void) {
    u32 result;
    WiFiMatching *wiFiMatching;
    gWiFiMatching->mMresvPresent = 0;
    gWiFiMatching->mMresvProfileId = 0;
    gWiFiMatching->mCloseKind = 0;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mPriorProfileId != 0) {
        if (wiFiMatching->mMode == 0) {
            wiFiMatching->mState = 3;
            result = DWCi_SBUpdateAsync(0);
            if (DWCi_HandleSBError(result) != 0) {
                return result;
            }
        } else if (wiFiMatching->mMode == 1) {
            wiFiMatching->mState = 4;
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
        gWiFiMatching->mCloseKind = 2;
        gt2CloseConnectionHard(*connection);
        gWiFiMatching->mCloseKind = 0;
        return 1;
    }
    DWCi_DeleteHostByProfileID(profileId, gWiFiMatching->mLastParticipantPos + 1);
    return 0;
}

void DWCi_CloseAllConnectionsByTimeout(void) {
    gWiFiMatching->mCloseKind = 2;
    gt2CloseAllConnectionsHard(*gWiFiMatching->mConnectionSocket);
    gWiFiMatching->mCloseKind = 0;
}

// Tells the participants in the mask to drop the others, then closes the connections to those not in the mask.
u32 DWCi_CloseShutdownClientSC(u32 mask) {
    u32 idList[32];
    u32 validIds[32];
    s32 validCount;
    s32 idCount;
    s32 n;
    s32 i;
    u32 b;
    WiFiMatching *wiFiMatching;
    idCount = 0;
    validCount = 0;
    n = 1;
    wiFiMatching = gWiFiMatching;
    for (; n <= wiFiMatching->mLastParticipantPos; n++) {
        b = 1 << gWiFiMatching->mParticipantIndices[n];
        if ((mask & b) != 0) {
            validIds[validCount] = wiFiMatching->mParticipantProfileIds[n];
            validCount++;
        } else {
            idList[idCount] = wiFiMatching->mParticipantProfileIds[n];
            idCount++;
        }
    }
    for (i = 0; i < validCount; i++) {
        if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(0x10, validIds[i], 0, 0, idList, idCount)) != 0) {
            return 0;
        }
    }
    gWiFiMatching->mCloseKind = 2;
    for (i = 0; i < idCount; i++) {
        s32 aid;
        aid = DWCi_GetAIDFromProfileID(idList[i], 0);
        if (aid != 0xff) {
            DWC_CloseConnectionHard(aid);
        }
    }
    gWiFiMatching->mCloseKind = 0;
    return 1;
}

void DWCi_SendMatchSynPacket(s32 peerIndex, u16 kind) {
    u8 hostIndex;
    u8 payload[3];
    volatile WiFiMatching *wiFiMatching; // fields are read again on each use
    switch (kind) {
        case 2:
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
        case 3:
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
    s32 n;
    u8 b;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mState == 9 || wiFiMatching->mState == 16 || wiFiMatching->mState == 17) {
        elapsed = MatchingGetTickMilliseconds() - wiFiMatching->mLastPeerMessageSendTime;
    } else {
        return 1;
    }
    switch (wiFiMatching->mState) {
        case 9:
            if (elapsed > 6000) {
                DWCi_SendMatchSynPacket(wiFiMatching->mParticipantIndices[0], 3);
            }
            break;
        case 16:
            if (elapsed > 6000) {
                wiFiMatching->mSynResendCounts[0]++;
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mSynResendCounts[0] > 5) {
                    if (wiFiMatching->mMode == 0 || wiFiMatching->mMode == 1) {
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
                    for (n = 1; n <= wiFiMatching->mLastParticipantPos; n++, wiFiMatching = gWiFiMatching) {
                        wiFiMatching = gWiFiMatching;
                        b = wiFiMatching->mParticipantIndices[n];
                        if ((wiFiMatching->mSynReplyMask & (1 << b)) == 0) {
                            DWCi_SendMatchSynPacket(b, 2);
                        }
                    }
                }
            }
            break;
        case 17:
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
    if (command == 13) {
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
    s32 n;
    u32 aid;
    if (DWC_GetState() != 6) {
        return TRUE;
    }
    switch (command) {
        case 13:
            if (gWiFiMatching->mState != 8) {
                gWiFiMatching->mState = 8;
                DWCi_CloseCancelHostAsync(data);
            }
            if (DWCi_SendCancelMatchSynCommand(profileId, 14) == 0) {
                return FALSE;
            }
            break;
        case 14:
            if (gWiFiMatching->mState == 14) {
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
                    gWiFiMatching->mCancelSynReplyMask |= 1 << aid;
                }
                mask = DWCi_GetAIDBitmask(1);
                wiFiMatching = gWiFiMatching;
                if (wiFiMatching->mCancelSynReplyMask == mask) {
                    for (n = 1; n <= wiFiMatching->mLastParticipantPos; n++, wiFiMatching = gWiFiMatching) {
                        if (DWCi_SendCancelMatchSynCommand(wiFiMatching->mParticipantProfileIds[n], 15) == 0) {
                            return FALSE;
                        }
                    }
                    wiFiMatching->mState = 15;
                }
            } else {
                if (DWCi_SendCancelMatchSynCommand(profileId, 15) == 0) {
                    return FALSE;
                }
            }
            break;
        case 15:
            if (gWiFiMatching->mState == 8) {
                DWCi_RestartFromCancel(2);
            }
            break;
    }
    return TRUE;
}

u32 DWCi_ProcessCancelMatchSynTimeout(void) {
    WiFiMatching *wiFiMatching;
    u64 elapsed;
    s32 n;
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mState == 8 || wiFiMatching->mState == 14 || wiFiMatching->mState == 15) {
        elapsed = MatchingGetTickMilliseconds() - wiFiMatching->mLastCancelSynSendTime;
    } else {
        return 1;
    }
    switch (wiFiMatching->mState) {
        case 8:
            if (elapsed > 6000) {
                if (DWCi_SendCancelMatchSynCommand(wiFiMatching->mParticipantProfileIds[0], 14) == 0) {
                    return 0;
                }
            }
            break;
        case 14:
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
                    for (n = 1; n <= wiFiMatching->mLastParticipantPos; n++, wiFiMatching = gWiFiMatching) {
                        if ((gWiFiMatching->mCancelSynReplyMask & (1 << gWiFiMatching->mParticipantIndices[n])) == 0) {
                            if (DWCi_SendCancelMatchSynCommand(wiFiMatching->mParticipantProfileIds[n], 13) == 0) {
                                return 0;
                            }
                        }
                    }
                }
            }
            break;
        case 15:
            if (wiFiMatching->mCancelSynLatency < elapsed) {
                DWCi_RestartFromCancel(2);
            }
            break;
    }
    return 1;
}

u8 DWCi_GetNewMatchKey(void) {
    u8 i = 0;
    do {
        if (gMatchingKeys[i][0] == 0) {
            return i + 100;
        }
        i++;
    } while (i < 154);
    return 0;
}

void DWCi_ClearGameMatchKeys(void) {
    s32 i;
    volatile u32 v;
    u8(*e)[12];
    i = 0;
    e = gMatchingKeys;
    for (; i < 0x9a; i++) {
        if (*(u32 *) &e[0][4] != 0) {
            DWC_Free(4, *(u32 *) &e[0][4], 0);
        }
        e++;
    }
    v = 0;
    MIi_CpuClear32(v, gMatchingKeys, 0x738);
}

u8 DWCi_GetAIDFromList(void) {
    u8 i;
    s32 j;
    volatile WiFiMatching *p; // fields are read again on each use
    i = 0;
    p = gWiFiMatching;
    for (; i < 0x20; i++) {
        for (j = 0; j <= p->mNNCompletedCount; j++) {
            if (i == p->mParticipantIndices[j]) {
                break;
            }
        }
        if (j > p->mNNCompletedCount) {
            break;
        }
    }
    return i;
}

s32 DWCi_CheckDWCServer(u32 server) {
    if (SbServerGetInt((SbServer *) server, gNumPlayersKey, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) server, gMaxPlayersKey, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) server, gDwcMtypeKey, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) server, gDwcMresvKey, -1) == -1 &&
        SbServerGetInt((SbServer *) server, gDwcMresvKey, 0) == 0) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) server, gDwcMverKey, -1) == -1) {
        return 0;
    }
    return SbServerGetInt((SbServer *) server, gDwcPidKey, 0);
}

s32 DWCi_GetAIDFromProfileID(u32 profileId, s32 b) {
    if (b == 0) {
        b = 1;
    } else {
        b = 0;
    }
    for (; b <= gWiFiMatching->mLastParticipantPos; b++) {
        if (profileId == gWiFiMatching->mParticipantProfileIds[b]) {
            return gWiFiMatching->mParticipantIndices[b];
        }
    }
    return 0xff;
}

u32 DWCi_GetAIDBitmask(s32 valid) {
    s32 i;
    u32 mask = 0;

    if (valid != 0) {
        return gWiFiMatching->mParticipantMask & ~1;
    }
    for (i = 1; i <= gWiFiMatching->mLastParticipantPos; i++) {
        mask |= 1 << gWiFiMatching->mParticipantIndices[i];
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
    s32 n;
    optMinComp = gOptMinComp;
    if (optMinComp == NULL) {
        return;
    }
    if (optMinComp->mValid == 0) {
        return;
    }
    wiFiMatching = gWiFiMatching;
    if (wiFiMatching->mMode == 2) {
        return;
    }
    if (wiFiMatching->mMode == 3) {
        return;
    }
    if (wiFiMatching->mState == 0x13) {
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
            if (wiFiMatching->mMode == 0) {
                wiFiMatching->mState = 3;
                gWiFiMatching->mServerUpdateWaitKind = 2;
                gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                return;
            }
            wiFiMatching->mState = 4;
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
        for (n = 1; n <= (wiFiMatching = gWiFiMatching)->mLastParticipantPos; n++) {
            if ((gOptMinComp->mRecvBit & (1 << wiFiMatching->mParticipantIndices[n])) == 0) {
                wiFiMatching = gWiFiMatching;
                if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                        0x11, wiFiMatching->mParticipantProfileIds[n], wiFiMatching->mParticipantCommandAddresses[n],
                        wiFiMatching->mParticipantCommandPorts[n], NULL, 0)) != 0) {
                    return;
                }
            }
        }
        gOptMinComp->mRetry++;
    } else if (wiFiMatching->mState == 3 || wiFiMatching->mState == 4) {
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
        wiFiMatching->mState = 0x13;
        for (n = 1; n <= gWiFiMatching->mLastParticipantPos; n++) {
            wiFiMatching = gWiFiMatching;
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(
                    0x11, wiFiMatching->mParticipantProfileIds[n], wiFiMatching->mParticipantCommandAddresses[n],
                    wiFiMatching->mParticipantCommandPorts[n], NULL, 0)) != 0) {
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
        case 2:
            DWCi_StopLogin(kind, detail - 0xfa00);
            break;
        case 4:
            DWCi_StopFriendProcess(kind, detail - 0x12110);
            break;
        case 5:
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
    enum { K6 = 6 } dwcError;
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
            dwcError = K6;
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

void DWCi_SBCallback(MatchingServerList *list, s32 event, s32 server) {
    s32 d;
    u32 listedServer;
    WiFiMatching *wiFiMatching;
    switch (event) {
        case 0:
            DWCi_SBPrintServerData(server);
            return;
        case 4:
            d = 0;
            if ((s32) ServerBrowserCount(list) > 0) {
                do {
                    listedServer = ServerBrowserGetServer(list, d);
                    if (DWCi_CheckDWCServer(listedServer) == 0) {
                        ServerBrowserRemoveServer(list, listedServer);
                        d--;
                    }
                    d++;
                } while (d < (s32) ServerBrowserCount(list));
            }
            switch (gWiFiMatching->mState) {
                case 2:
                    d = 0;
                    if ((s32) ServerBrowserCount(list) > 0) {
                        do {
                            listedServer = ServerBrowserGetServer(list, d);
                            wiFiMatching = gWiFiMatching;
                            if (wiFiMatching->mOwnAddress != NULL &&
                                wiFiMatching->mOwnAddress ==
                                    (void *) SBServerGetPublicInetAddress((u32 *) listedServer) &&
                                wiFiMatching->mOwnPort != 0 &&
                                gWiFiMatching->mOwnPort == SBServerGetPublicQueryPort(listedServer)) {
                                break;
                            }
                            d++;
                        } while (d < (s32) ServerBrowserCount(list));
                    }
                    if (d < (s32) ServerBrowserCount(list)) {
                        gWiFiMatching->mState = 3;
                        gWiFiMatching->mReplyProfileId = 0;
                        if (DWCi_HandleSBError(DWCi_SBUpdateAsync(gWiFiMatching->mReplyProfileId)) != 0) {
                            return;
                        }
                        return;
                    }
                    gWiFiMatching->mServerUpdateWaitKind = 2;
                    gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                    return;
                case 3:
                    DWCi_EvaluateServers(1);
                    if (ServerBrowserCount(list) != 0) {
                        if (DWCi_HandleMatchCommandError(DWCi_SendResvCommand(0, 0)) != 0) {
                            return;
                        }
                        gWiFiMatching->mState = 4;
                        gWiFiMatching->mServerUpdateWaitKind = 0;
                        return;
                    }
                    gWiFiMatching->mServerUpdateWaitKind = 2;
                    gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                    return;
                case 5:
                    if (ServerBrowserCount(list) != 0) {
                        do {
                            listedServer = ServerBrowserGetServer(list, 0);
                            if (gWiFiMatching->mServerAddress == SBServerGetPublicInetAddress((u32 *) listedServer) &&
                                gWiFiMatching->mServerPort == SBServerGetPublicQueryPort(listedServer)) {
                                break;
                            }
                            ServerBrowserRemoveServer(list, listedServer);
                        } while (ServerBrowserCount(list) != 0);
                    }
                    if (ServerBrowserCount(list) != 0) {
                        listedServer = SbServerGetInt((SbServer *) ServerBrowserGetServer(list, 0), gDwcPidKey, 0);
                        wiFiMatching = gWiFiMatching;
                        if (wiFiMatching->mMode == 1 && listedServer == wiFiMatching->mParticipantProfileIds[0]) {
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
                                gWiFiMatching->mState = 4;
                                if (DWCi_HandleMatchCommandError(DWCi_SendResvCommandToFriend(0, 0)) != 0) {
                                    return;
                                }
                                return;
                            }
                        }
                        gWiFiMatching->mState = 6;
                        if (DWCi_HandleNNError(DWCi_NNStartupAsync(0, 0, ServerBrowserGetServer(list, 0))) != 0) {
                            return;
                        }
                        return;
                    }
                    gWiFiMatching->mServerUpdateWaitKind = 2;
                    gWiFiMatching->mServerUpdateWaitStartTick = OS_GetTick();
                    return;
            }
            return;
        case 5:
            break;
    }
}

void DWCi_SBPrintServerData(s32 server) {}

// Removes servers already in the list or refused by mEvalCallback and stores the callback's value for each remaining
// one under dwc_eval.
BOOL DWCi_EvaluateServers(s32 sort) {
    BOOL removedAny;
    BOOL removedThis;
    s32 e;
    u32 serverEntry;
    u32 g;
    s32 h;
    removedAny = FALSE;
    e = 0;
    for (; e < (s32) ServerBrowserCount(gWiFiMatching->mServerList); e++) {
        serverEntry = ServerBrowserGetServer(gWiFiMatching->mServerList, e);
        if (gWiFiMatching->mMode == 0) {
            g = SbServerGetInt((SbServer *) serverEntry, gDwcPidKey, 0);
            removedThis = FALSE;
            for (h = 1; h <= gWiFiMatching->mLastParticipantPos; h++) {
                if (g == gWiFiMatching->mParticipantProfileIds[h]) {
                    ServerBrowserRemoveServer(gWiFiMatching->mServerList, serverEntry);
                    e--;
                    removedThis = TRUE;
                    break;
                }
            }
            if (removedThis != FALSE) {
                continue;
            }
        }
        if (gWiFiMatching->mEvalCallback != 0) {
            g = ((s32(*)(s32, u32)) gWiFiMatching->mEvalCallback)(e, gWiFiMatching->mEvalCallbackArg);
            if ((s32) g > 0) {
                if ((s32) g > 0x7fffff) {
                    g = 0x7fffff;
                }
                SbServerSetInt((SbServer *) serverEntry, gDwcEvalKey, (g << 8) | DWCi_GetMathRand32(0x100));
            } else {
                ServerBrowserRemoveServer(gWiFiMatching->mServerList, serverEntry);
                e--;
                removedAny = TRUE;
            }
        } else {
            SbServerSetInt((SbServer *) serverEntry, gDwcEvalKey, DWCi_GetMathRand32(0x80));
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
    if (gMatchingKeys[index][0] != 0) {
        if (gMatchingKeyIsString[index * 12] != 0) {
            qr2_buffer_addA(buffer, *(const char **) &gMatchingKeyValue[index * 12]);
        } else {
            qr2_buffer_add_int(buffer, **(s32 **) &gMatchingKeyValue[index * 12]);
        }
    }
}

void DWCi_QR2PlayerKeyCallback(void) {}

void DWCi_QR2TeamKeyCallback(void) {}

void DWCi_QR2KeyListCallback(s32 keytype, MatchingKeyIds *keyIds, void *userdata) {
    s32 i;
    u8 *d;
    switch (keytype) {
        case 0:
            qr2_keybuffer_add(keyIds, 8);
            qr2_keybuffer_add(keyIds, 0xa);
            qr2_keybuffer_add(keyIds, 0x32);
            qr2_keybuffer_add(keyIds, 0x33);
            qr2_keybuffer_add(keyIds, 0x34);
            qr2_keybuffer_add(keyIds, 0x35);
            qr2_keybuffer_add(keyIds, 0x36);
            i = 0;
            d = gMatchingKeys[0];
            for (; i < 0x9a; i++) {
                if (d[0] != 0) {
                    qr2_keybuffer_add(keyIds, d[0]);
                }
                d += 12;
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

void DWCi_QR2PublicAddrCallback(void *address, u16 port) {
    gWiFiMatching->mOwnAddress = address;
    gWiFiMatching->mOwnPort = port;
}

void DWCi_QR2NatnegCallback(u32 cookie) {
    if (gWiFiMatching->mState == 1) {
        gWiFiMatching->mState = 6;
    } else if (gWiFiMatching->mState != 6 && gWiFiMatching->mState != 0xb) {
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
        gWiFiMatching->mLastCommand = 0xff;
    }
}

void DWCi_QR2ClientMsgCallback(const void *data, u32 len) {
    MatchingReceiveHeader header;
    u8 body[0x80];
    u32 offset;
    offset = 0;
    if (len >= 0x14) {
        do {
            MI_CpuCopy8(data, &header, 0x14);
            if (strncmp(header.mSignature, gMatchingSignature, 4) != 0) {
                break;
            }
            if (header.mVersion != 3) {
                break;
            }
            MI_CpuCopy8(data + 0x14, body, header.mValuesSize);
            if (DWCi_ProcessRecvMatchCommand(header.mCommand, header.mProfileId, header.mAddress, header.mPort,
                                             (u32 *) body, header.mValuesSize >> 2) == 0) {
                break;
            }
            offset += header.mValuesSize + 0x14;
        } while (offset + 0x14 <= len);
    }
}
