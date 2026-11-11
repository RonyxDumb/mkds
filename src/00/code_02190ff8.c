#include "00/code_02190ff8.h"

#include "00/code_02193634.h"
#include "00/code_02194840.h"
#include "00/code_0218e2a4.h"
#include "00/code_02191200.h"
#include "00/code_021965a0.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"
#include "00/code_02196594.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_021947e4.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021919ac.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "00/code_02193000.h"
#include "code_021384cc.h"
#include "code_02133048.h"
#include "00/code_02193b88.h"
#include "00/code_02190cd4.h"
#include "00/code_021a6d5c.h"

void randomString(s8 *buffer, s32 numChars) {
    s32 index;

    for (index = 0; index < numChars; index++) {
        buffer[index] = gRandomStringCharacters[rand() % 0x3e];
    }
    buffer[index] = 0;
}

u32 GpiOpenSockets(GpConnection *connection, GpiOperation *operation) {
    GpiConnection *gpState;
    SOCSockAddrIn address;
    SOCHostEnt *resolvedHost;
    u32 len;
    s32 openResult;

    gpState = connection->mGpiConnection;
    if (gpState->mFirewall == FALSE) {
        gpState->mListenSocket = OpenNetSocket(2, 1, 0);
        if (gpState->mListenSocket == -1) {
            GpiSetError(connection, 5, gCreateSocketErrorString);
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
        if (SetSockBlocking(gpState->mListenSocket, 0) == FALSE) {
            GpiSetError(connection, 5, gNonBlockingSocketErrorString);
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
        __builtin__clear(&address, sizeof(address));
        address.mFamily = 2;
        if (bind(gpState->mListenSocket, &address, 8) == -1) {
            GpiSetError(connection, 5, gBindSocketErrorString);
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
        if (listen(gpState->mListenSocket, 5) == -1) {
            GpiSetError(connection, 5, gListenSocketErrorString);
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
        len = 8;
        if (getsockname(gpState->mListenSocket, &address, &len) == -1) {
            GpiSetError(connection, 5, gSocketAddressErrorString);
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
        gpState->mPort = address.mPort;
    } else {
        gpState->mListenSocket = -1;
        gpState->mPort = 0;
    }
    gpState->mConnectSocket = OpenNetSocket(2, 1, 0);
    if (gpState->mConnectSocket == -1) {
        GpiSetError(connection, 5, gCreateSocketErrorString);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    if (SetSockBlocking(gpState->mConnectSocket, 0) == FALSE) {
        GpiSetError(connection, 5, gNonBlockingSocketErrorString);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    resolvedHost = SOC_GetHostByName(gConnectionManagerName);
    if (resolvedHost == NULL) {
        GpiSetError(connection, 5, gResolveManagerHostErrorString);
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    __builtin__clear(&address, sizeof(address));
    address.mFamily = 2;
    address.mAddr = **resolvedHost->mAddrList;
    if (address.mAddr == 0) {
        AssertionFailed(gAddressNotZeroAssertion, gGpiConnectFileName, NULL, 0x90);
    }
    address.mPort = 0xcc74;
    if (connect(gpState->mConnectSocket, &address, 8) == -1) {
        openResult = GOAGetLastError(gpState->mConnectSocket);
        if (openResult != -6 && openResult != -26 && openResult != -76) {
            GpiSetError(connection, 5, gConnectSocketErrorString);
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
    }
    operation->mState = 1;
    gpState->mConnectState = 1;
    return 0;
}

u32 GpiStartConnect(GpConnection *connection, const char *nick, const char *uniquenick, const char *email,
                    const char *password, const s8 *authtoken, const s8 *partnerchallenge, const char *cdkey,
                    s32 firewall, s32 newuser, s32 blocking, s32 callback, s32 param) {
    GpiConnection *gpState;
    GPIConnectData *data;
    GpiOperation *pendingOp;
    u32 result;

    gpState = connection->mGpiConnection;
    if (gpState->mConnectState == 4) {
        result = GpiResetConnection(connection);
        if (result != 0) {
            return result;
        }
    }
    if (gpState->mConnectState != 0) {
        GpiSetErrorMessage(connection, gInvalidConnectionErrorString);
        return 2;
    }
    switch (firewall) {
        case 1:
            gpState->mFirewall = TRUE;
            break;
        case 0:
            gpState->mFirewall = FALSE;
            break;
        default:
            GpiSetErrorMessage(connection, gInvalidFirewallErrorString);
            return 2;
    }
    gpState->mFirewall = TRUE;
    GpiCopyString(gpState->mNick, nick, 0x1f);
    GpiCopyString((char *) gpState->mUniquenick, uniquenick, 0x15);
    GpiCopyString(gpState->mEmail, email, 0x33);
    GpiCopyString((char *) gpState->mPassword, password, 0x1f);
    _strlwr((s8 *) gpState->mEmail);
    data = DWCi_GsMalloc(0x308);
    if (data == NULL) {
        GpiSetErrorMessage(connection, data_ov000_021b2cdc);
        return 1;
    }
    memset(data, 0, 0x308);
    data->mNewUser = newuser;
    if (*authtoken != 0 && *partnerchallenge != 0) {
        GpiCopyString((char *) data->mAuthtoken, (const char *) authtoken, 0x100);
        GpiCopyString((char *) data->mPartnerChallenge, (const char *) partnerchallenge, 0x100);
    }
    if (cdkey != NULL) {
        GpiCopyString((char *) data->mCdkey, cdkey, 0x41);
    }
    result = GpiCreateOperation(connection, 0, (s32) data, (s32 *) &pendingOp, blocking, callback, param);
    if (result != 0) {
        return result;
    }
    result = GpiOpenSockets(connection, pendingOp);
    if (result != 0) {
        pendingOp->mResult = result;
        GpiQueueOperationCallback(connection, pendingOp);
        GpiCloseConnection(connection, 0);
        return result;
    }
    if (pendingOp->mBlocking != 0) {
        result = GpiUpdateConnection(connection, pendingOp->mId);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

u32 GpiWriteLogin(GpConnection *connection, GPIConnectData *data) {
    GpiConnection *gpState;
    s8 *passwordPtr;
    s8 *loginName;
    GpiProfile *profileRec;
    char response[0x21];
    char buffer[0x200];
    char loginNameBuf[0x57];
    u16 port;

    gpState = connection->mGpiConnection;
    randomString((s8 *) data->mUserChallenge, 0x20);
    if (data->mPartnerChallenge[0] != 0) {
        passwordPtr = data->mPartnerChallenge;
    } else {
        passwordPtr = gpState->mPassword;
    }
    MD5Digest((const char *) passwordPtr, strlen((const char *) passwordPtr), data->mPasswordHash);
    if (data->mAuthtoken[0] != 0) {
        loginName = data->mAuthtoken;
    } else if (gpState->mUniquenick[0] != 0) {
        loginName = gpState->mUniquenick;
    } else {
        sprintf(loginNameBuf, gNickEmailFormat, gpState->mNick, gpState->mEmail);
        loginName = (s8 *) loginNameBuf;
    }
    sprintf(buffer, gChallengeResponseFormat, data->mPasswordHash, gSpacePadding, loginName, data->mUserChallenge, data,
            data->mPasswordHash);
    MD5Digest(buffer, strlen(buffer), response);
    if (gpState->mInfoCaching != 0) {
        gpiFindProfileByUser(connection, gpState->mNick, gpState->mEmail, (void **) &profileRec);
        if (profileRec != NULL) {
            gpState->mUserId = profileRec->mUserId;
            gpState->mProfileId = profileRec->mProfileId;
        }
    }
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gLoginKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gChallengeKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, data->mUserChallenge);
    if (data->mAuthtoken[0] != 0) {
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gAuthtokenKey);
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, data->mAuthtoken);
    } else if (gpState->mUniquenick[0] != 0) {
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gUniquenickKey);
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gpState->mUniquenick);
    } else {
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gUserKey);
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gpState->mNick);
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gAtString);
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gpState->mEmail);
    }
    if (gpState->mUserId != 0) {
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gUseridKey);
        GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mUserId);
    }
    if (gpState->mProfileId != 0) {
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gProfileidKey);
        GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mProfileId);
    }
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gResponseKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, response);
    if (gpState->mFirewall == TRUE) {
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gFirewall1Key);
    }
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gPortKey);
    port = gpState->mPort;
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer,
                          (s16) (u16) (((port >> 8) & 0xff) | ((port << 8) & 0xff00)));
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gProductidKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mProductId);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gGamenameKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gGsiAcGamename);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gNamespaceidKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mNamespaceId);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gId1Key);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, data_ov000_021b2b3c);
    return 0;
}

u32 GpiWriteNewuser(GpConnection *connection, GPIConnectData *data) {
    GpiConnection *gpState;
    u32 length;
    u32 index;
    s8 randomByte;
    s8 passwordMasked[0x1f];
    s8 passwordEncoded[0x2d];
    s8 cdKeyMasked[0x41];
    s8 cdKeyEncoded[0x59];

    gpState = connection->mGpiConnection;
    length = strlen((const char *) gpState->mPassword);
    Util_RandSeed(0x79707367);
    for (index = 0; index < length; index++) {
        randomByte = Util_RandInt(0, 0xff);
        passwordMasked[index] = randomByte ^ gpState->mPassword[index];
    }
    passwordMasked[index] = 0;
    B64Encode(passwordMasked, passwordEncoded, length, 1);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gNewuserKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gEmailKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gpState->mEmail);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gNickKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gpState->mNick);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gPasswordencKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, passwordEncoded);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gProductidKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mProductId);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gGamenameKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gGsiAcGamename);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gNamespaceidKey);
    GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mNamespaceId);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gUniquenickKey);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gpState->mUniquenick);
    if (data->mCdkey[0] != 0) {
        length = strlen((const char *) data->mCdkey);
        Util_RandSeed(0x79707367);
        for (index = 0; index < length; index++) {
            randomByte = Util_RandInt(0, 0xff);
            cdKeyMasked[index] = randomByte ^ data->mCdkey[index];
        }
        cdKeyMasked[index] = 0;
        B64Encode(cdKeyMasked, cdKeyEncoded, length, 1);
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, gCdkeyencKey);
        GpiAppendBufferString(connection, &gpState->mOutputBuffer, cdKeyEncoded);
    }
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, gId1Key);
    GpiAppendBufferString(connection, &gpState->mOutputBuffer, data_ov000_021b2b3c);
    return 0;
}

u32 GpiProcessConnectOperation(GpConnection *connection, GpiOperation *operation, const char *input) {
    GpiConnection *gpState;
    GPIConnectData *data;
    char digestHex[0x21];
    char uniqueNickText[0x15];
    char buffer[0x200];
    char loginNameBuf[0x52];
    GpiCallback callback;
    ConnectReply *arg;
    void *loginTarget;
    u32 result;

    gpState = connection->mGpiConnection;
    if (GpiReadError(connection, input, 0) != FALSE) {
        if (gpState->mErrorNumber == 0x106 && gpState->mProfileId != 0) {
            GpiRemoveProfileById(connection, gpState->mProfileId);
            gpState->mUserId = 0;
            gpState->mProfileId = 0;
        } else if (gpState->mErrorNumber == 0x201) {
            if (GpiGetValue(input, gPidKey, buffer, 0x200) != FALSE) {
                gpState->mProfileId = StrtolBase10(buffer);
            }
        }
        if (strstr(input, gFatalKey) != NULL) {
            GpiSetError(connection, gpState->mErrorNumber, gpState->mErrorMessage);
            GpiQueueErrorCallback(connection, 4, 1);
            return 4;
        }
        GpiSetError(connection, gpState->mErrorNumber, gpState->mErrorMessage);
        GpiQueueErrorCallback(connection, 4, 0);
        return 4;
    }
    data = (GPIConnectData *) operation->mData;
    switch (operation->mState) {
        case 1:
            if (strncmp(input, gLc1Key, 5) != 0) {
                GpiSetError(connection, 1, data_ov000_021b2bb0);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if (GpiGetValue(input, gChallengeKey, data->mServerChallenge, 0x80) == FALSE) {
                GpiSetError(connection, 1, data_ov000_021b2bb0);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if (data->mNewUser != 0) {
                result = GpiWriteNewuser(connection, data);
                if (result != 0) {
                    return result;
                }
                operation->mState = 3;
            } else {
                result = GpiWriteLogin(connection, data);
                if (result != 0) {
                    return result;
                }
                operation->mState = 2;
            }
            break;
        case 3:
            if (strncmp(input, gNurKey, 5) != 0) {
                GpiSetError(connection, 1, data_ov000_021b2bb0);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if (GpiGetValue(input, gUseridKey, buffer, 0x200) == FALSE) {
                GpiSetError(connection, 1, gConnectUnexpectedDataErrorString);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mUserId = StrtolBase10(buffer);
            if (GpiGetValue(input, gProfileidKey, buffer, 0x200) == FALSE) {
                GpiSetError(connection, 1, gConnectUnexpectedDataErrorString);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mProfileId = StrtolBase10(buffer);
            result = GpiWriteLogin(connection, data);
            if (result != 0) {
                return result;
            }
            operation->mState = 2;
            break;
        case 2:
            if (strncmp(input, gLc2Key, 5) != 0) {
                GpiSetError(connection, 1, data_ov000_021b2bb0);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if (GpiGetValue(input, data_ov000_021b2c44, buffer, 0x200) == FALSE) {
                GpiSetError(connection, 1, gConnectUnexpectedDataErrorString);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mSesskey = StrtolBase10(buffer);
            if (GpiGetValue(input, gUseridKey, buffer, 0x200) == FALSE) {
                GpiSetError(connection, 1, gConnectUnexpectedDataErrorString);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mUserId = StrtolBase10(buffer);
            if (GpiGetValue(input, gProfileidKey, buffer, 0x200) == FALSE) {
                GpiSetError(connection, 1, gConnectUnexpectedDataErrorString);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mProfileId = StrtolBase10(buffer);
            if (GpiGetValue(input, gUniquenickKey, uniqueNickText, 0x15) == FALSE) {
                uniqueNickText[0] = 0;
            }
            if (GpiGetValue(input, gLtKey, (char *) gpState->mUnk_474, 0x19) == FALSE) {
                gpState->mUnk_474[0] = 0;
            }
            if (data->mAuthtoken[0] != 0) {
                loginTarget = data->mAuthtoken;
            } else if (gpState->mUniquenick[0] != 0) {
                loginTarget = gpState->mUniquenick;
            } else {
                sprintf(loginNameBuf, gNickEmailFormat, gpState->mNick, gpState->mEmail);
                loginTarget = loginNameBuf;
            }
            sprintf(buffer, gChallengeResponseFormat, data->mPasswordHash, gSpacePadding, loginTarget, data, data->mUserChallenge,
                    data->mPasswordHash);
            MD5Digest(buffer, strlen(buffer), digestHex);
            if (GpiGetValue(input, gProofKey, buffer, 0x200) == FALSE) {
                GpiSetError(connection, 1, gConnectUnexpectedDataErrorString);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if (memcmp(digestHex, buffer, 0x20) != 0) {
                GpiSetError(connection, 0x108, gAuthenticateServerErrorString);
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
            if (gpState->mInfoCaching != 0) {
                GpiProfile *n = GpiFindOrAddProfile(connection, gpState->mProfileId);
                n->mProfileId = gpState->mProfileId;
                n->mUserId = gpState->mUserId;
            }
            gpState->mConnectState = 3;
            callback = operation->mCallback;
            if (callback.mCallback != NULL) {
                arg = DWCi_GsMalloc(0x20);
                if (arg == NULL) {
                    GpiSetErrorMessage(connection, data_ov000_021b2cdc);
                    return 1;
                }
                memset(arg, 0, 0x20);
                arg->mProfile = gpState->mProfileId;
                arg->mResult = 0;
                GpiCopyString(arg->mUniquenick, uniqueNickText, 0x15);
                result = GpiQueueCallback(connection, callback, arg, operation, 0);
                if (result != 0) {
                    return result;
                }
            }
            GpiRemoveOperation(connection, operation);
            break;
    }
    return 0;
}

int gpiCheckConnect(GpConnection *connection) {
    int result;
    GpiConnection *gpState;
    u32 state;
    gpState = connection->mGpiConnection;
    result = GpiCheckConnectComplete(connection, gpState->mConnectSocket, &state);
    if (result == 0) {
        if (state == 4) {
            GpiSetError(connection, 0x107u, gServerRefusedErrorString);
            GpiQueueErrorCallback(connection, 4, 1);
            return 4;
        }
        if (state == 0) {
            return 0;
        }
        if (state != 3) {
            AssertionFailed(gConnectedStateAssertion, gGpiConnectFileName, NULL, 0x2ef);
        }
        gpState->mConnectState = 2;
        result = 0;
    }
    return result;
}

u32 gpiDisconnectCleanupProfile(GpConnection *connection, GpiProfile *profile) {
    GpiConnection *gpState;

    gpState = connection->mGpiConnection;
    if (profile->mBuddyStatus != NULL && gpState->mInfoCachingBuddyOnly == FALSE) {
        DWCi_GsFree(profile->mBuddyStatus->mStatusString);
        profile->mBuddyStatus->mStatusString = NULL;
        DWCi_GsFree(profile->mBuddyStatus->mLocationString);
        profile->mBuddyStatus->mLocationString = NULL;
        DWCi_GsFree(profile->mBuddyStatus);
        profile->mBuddyStatus = NULL;
    }
    DWCi_GsFree(profile->mAuthSig);
    profile->mAuthSig = NULL;
    DWCi_GsFree(profile->mPeerSig);
    profile->mPeerSig = NULL;
    profile->mRequestCount = 0;
    if (profile->mCache == 0 || (gpState->mInfoCachingBuddyOnly == TRUE && profile->mBuddyStatus == NULL)) {
        GpiRemoveProfile(connection, profile);
        return 0;
    }
    return 1;
}

void GpiCloseConnection(GpConnection *connection, s32 tellServer) {
    GpiConnection *gpState;
    GpiOperation *d;
    GpiPeer *peerConn;
    u32 socketGone;

    gpState = connection->mGpiConnection;
    if (gpState->mConnectState == 4) {
        return;
    }
    if (gpState->mConnectState != 0) {
        if (tellServer != 0 && gpState->mConnectState == 3) {
            GpiAppendBufferString(connection, &gpState->mOutputBuffer, gLogoutKey);
            GpiAppendBufferNumber(connection, &gpState->mOutputBuffer, gpState->mSesskey);
            GpiAppendBufferString(connection, &gpState->mOutputBuffer, data_ov000_021b2b3c);
        }
        GpiSendBuffer(connection, gpState->mConnectSocket, &gpState->mOutputBuffer, &socketGone, 1,
                      data_ov000_021b2b44);
        if (gpState->mConnectSocket != -1) {
            shutdown(gpState->mConnectSocket, 2);
            closesocket(gpState->mConnectSocket);
            gpState->mConnectSocket = -1;
        }
        if (gpState->mListenSocket != -1) {
            shutdown(gpState->mListenSocket, 2);
            closesocket(gpState->mListenSocket);
            gpState->mListenSocket = -1;
        }
        gpState->mConnectState = 4;
        gpState->mUserId = 0;
        gpState->mProfileId = 0;
    }
    DWCi_GsFree(gpState->mInputBuffer);
    gpState->mInputBuffer = NULL;
    DWCi_GsFree(gpState->mCommandBuffer);
    gpState->mCommandBuffer = NULL;
    DWCi_GsFree(gpState->mOutputBuffer.mBuffer);
    gpState->mOutputBuffer.mBuffer = NULL;
    DWCi_GsFree(gpState->mUpdateproBuffer);
    gpState->mUpdateproBuffer = NULL;
    DWCi_GsFree(gpState->mUpdateuiBuffer);
    gpState->mUpdateuiBuffer = NULL;
    while (gpState->mOperationList != NULL) {
        GpiRemoveOperation(connection, gpState->mOperationList);
    }
    gpState->mOperationList = NULL;
    peerConn = gpState->mPeerList;
    while (peerConn != NULL) {
        GpiPeer *doomedPeer = peerConn;
        peerConn = peerConn->mNext;
        GpiPeerDelete(connection, doomedPeer);
    }
    gpState->mPeerList = NULL;
    while (GpiForEachProfileWhileNonZero(connection, gpiDisconnectCleanupProfile, NULL) == 0) {
    }
}
