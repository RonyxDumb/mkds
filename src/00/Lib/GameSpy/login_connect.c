#include "00/Lib/GameSpy/login_connect_close.h"

#include "00/Lib/GameSpy/operation_queue.h"
#include "00/Lib/GameSpy/profile_walk.h"
#include "00/Lib/GameSpy/random_seed.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/login_connect.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "scan_text_random.h"
#include "signed_int_divide.h"
#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/GameSpy/callback_queue.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"
#include "00/Lib/GameSpy/availability_check.h"

char gConnectionManagerName[0x40] = "gpcm.gs.nintendowifi.net";

void randomString(char *buffer, s32 numChars) {
    s32 index;

    for (index = 0; index < numChars; index++) {
        buffer[index] = ((const s8 *) "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789")[rand() % 0x3e];
    }
    buffer[index] = 0;
}

u32 gpiStartConnect(GPConnection *connection, GPIOperation *operation) {
    GPIConnection *gpState;
    SOCSockAddrIn address;
    SOCHostEnt *resolvedHost;
    u32 len;
    s32 lastError;

    gpState = connection->mGpiConnection;
    if (gpState->mFirewall == FALSE) {
        gpState->mListenSocket = OpenNetSocket(2, 1, 0);
        if (gpState->mListenSocket == -1) {
            gpiSetError(connection, 5, "There was an error creating a socket.");
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
        if (SetSockBlocking(gpState->mListenSocket, 0) == FALSE) {
            gpiSetError(connection, 5, "There was an error making a socket non-blocking.");
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
        __builtin__clear(&address, sizeof(address));
        address.mFamily = SOCKET_FAMILY_IPV4;
        if (bind(gpState->mListenSocket, &address, 8) == -1) {
            gpiSetError(connection, 5, "There was an error binding a socket.");
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
        if (listen(gpState->mListenSocket, 5) == -1) {
            gpiSetError(connection, 5, "There was an error listening on a socket.");
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
        len = 8;
        if (getsockname(gpState->mListenSocket, &address, &len) == -1) {
            gpiSetError(connection, 5, "There was an error getting a socket's addres.");
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
        gpState->mPort = address.mPort;
    } else {
        gpState->mListenSocket = -1;
        gpState->mPort = 0;
    }
    gpState->mConnectSocket = OpenNetSocket(2, 1, 0);
    if (gpState->mConnectSocket == -1) {
        gpiSetError(connection, 5, "There was an error creating a socket.");
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    if (SetSockBlocking(gpState->mConnectSocket, 0) == FALSE) {
        gpiSetError(connection, 5, "There was an error making a socket non-blocking.");
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    resolvedHost = SOC_GetHostByName(gConnectionManagerName);
    if (resolvedHost == NULL) {
        gpiSetError(connection, 5, "Could not resolve connection mananger host name.");
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    __builtin__clear(&address, sizeof(address));
    address.mFamily = SOCKET_FAMILY_IPV4;
    address.mAddr = **resolvedHost->mAddrList;
    if (address.mAddr == 0) {
        AssertionFailed("address.sin_addr.s_addr != 0", "gpiConnect.c", NULL, 0x90);
    }
    address.mPort = GPI_CONNECTION_MANAGER_PORT_NETWORK_ORDER;
    if (connect(gpState->mConnectSocket, &address, 8) == -1) {
        lastError = GOAGetLastError(gpState->mConnectSocket);
        if (lastError != -6 && lastError != -26 && lastError != -76) {
            gpiSetError(connection, 5, "There was an error connecting a socket.");
            gpiCallErrorCallback(connection, 3, 1);
            return 3;
        }
    }
    operation->mState = PROFILE_CONNECT_STATE_WAIT_CHALLENGE;
    gpState->mConnectState = PROFILE_CONNECTION_SOCKET_OPENING;
    return 0;
}

u32 GpiStartConnect(GPConnection *connection, const char *nick, const char *uniquenick, const char *email,
                    const char *password, const s8 *authtoken, const s8 *partnerchallenge, const char *cdkey,
                    s32 firewall, s32 newuser, s32 blocking, GPCallback callback, s32 param) {
    GPIConnection *gpState;
    GPIConnectData *data;
    GPIOperation *pendingOp;
    u32 result;

    gpState = connection->mGpiConnection;
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        result = gpiReset(connection);
        if (result != 0) {
            return result;
        }
    }
    if (gpState->mConnectState != PROFILE_CONNECTION_IDLE) {
        gpiSetErrorString(connection, "Invalid connection.");
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
            gpiSetErrorString(connection, "Invalid firewall.");
            return 2;
    }
    gpState->mFirewall = TRUE;
    CopyStringWithTerminator(gpState->mNick, nick, 0x1f);
    CopyStringWithTerminator((char *) gpState->mUniquenick, uniquenick, 0x15);
    CopyStringWithTerminator(gpState->mEmail, email, 0x33);
    CopyStringWithTerminator((char *) gpState->mPassword, password, 0x1f);
    _strlwr((s8 *) gpState->mEmail);
    data = DWCi_GsMalloc(0x308);
    if (data == NULL) {
        gpiSetErrorString(connection, "Out of memory.");
        return 1;
    }
    memset(data, 0, sizeof(*data));
    data->mNewuser = newuser;
    if (*authtoken != 0 && *partnerchallenge != 0) {
        CopyStringWithTerminator((char *) data->mAuthtoken, (const char *) authtoken, 0x100);
        CopyStringWithTerminator((char *) data->mPartnerChallenge, (const char *) partnerchallenge, 0x100);
    }
    if (cdkey != NULL) {
        CopyStringWithTerminator((char *) data->mCdkey, cdkey, 0x41);
    }
    result = gpiAddOperation(connection, PROFILE_OPERATION_CONNECT, data, &pendingOp, blocking, callback, param);
    if (result != 0) {
        return result;
    }
    result = gpiStartConnect(connection, pendingOp);
    if (result != 0) {
        pendingOp->mResult = result;
        gpiFailedOpCallback(connection, pendingOp);
        gpiDisconnect(connection, 0);
        return result;
    }
    if (pendingOp->mBlocking != 0) {
        result = gpiProcess(connection, pendingOp->mId);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

u32 gpiSendLogin(GPConnection *connection, GPIConnectData *data) {
    GPIConnection *gpState;
    s8 *hashInput;
    s8 *loginName;
    GPIProfile *profile;
    char response[0x21];
    char buffer[0x200];
    char loginNameBuf[0x57];
    u16 port;

    gpState = connection->mGpiConnection;
    randomString(data->mUserChallenge, 0x20);
    if (data->mPartnerChallenge[0] != 0) {
        hashInput = data->mPartnerChallenge;
    } else {
        hashInput = gpState->mPassword;
    }
    MD5Digest((const char *) hashInput, strlen((const char *) hashInput), data->mPasswordHash);
    if (data->mAuthtoken[0] != 0) {
        loginName = data->mAuthtoken;
    } else if (gpState->mUniquenick[0] != 0) {
        loginName = gpState->mUniquenick;
    } else {
        sprintf(loginNameBuf, "%s@%s", gpState->mNick, gpState->mEmail);
        loginName = (s8 *) loginNameBuf;
    }
    sprintf(buffer, "%s%s%s%s%s%s", data->mPasswordHash, "                                                ", loginName,
            data->mUserChallenge, data, data->mPasswordHash);
    MD5Digest(buffer, strlen(buffer), response);
    if (gpState->mInfoCaching != 0) {
        gpiFindProfileByUser(connection, gpState->mNick, gpState->mEmail, &profile);
        if (profile != NULL) {
            gpState->mUserId = profile->mUserId;
            gpState->mProfileId = profile->mProfileId;
        }
    }
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\login\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\challenge\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, data->mUserChallenge);
    if (data->mAuthtoken[0] != 0) {
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\authtoken\\");
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, data->mAuthtoken);
    } else if (gpState->mUniquenick[0] != 0) {
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\uniquenick\\");
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, gpState->mUniquenick);
    } else {
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\user\\");
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, gpState->mNick);
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "@");
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, gpState->mEmail);
    }
    if (gpState->mUserId != 0) {
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\userid\\");
        gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mUserId);
    }
    if (gpState->mProfileId != 0) {
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\profileid\\");
        gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mProfileId);
    }
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\response\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, response);
    if (gpState->mFirewall == TRUE) {
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\firewall\\1");
    }
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\port\\");
    port = gpState->mPort;
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer,
                          (s16) (u16) (((port >> 8) & 0xff) | ((port << 8) & 0xff00)));
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\productid\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mProductId);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\gamename\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, gGsiAcGamename);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\namespaceid\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mNamespaceId);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\id\\1");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\final\\");
    return 0;
}

u32 gpiSendNewuser(GPConnection *connection, GPIConnectData *data) {
    GPIConnection *gpState;
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
    B64Encode(passwordMasked, passwordEncoded, length, B64_ENCODING_ALTERNATE);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\newuser\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\email\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, gpState->mEmail);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\nick\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, gpState->mNick);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\passwordenc\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, passwordEncoded);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\productid\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mProductId);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\gamename\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, gGsiAcGamename);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\namespaceid\\");
    gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mNamespaceId);
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\uniquenick\\");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, gpState->mUniquenick);
    if (data->mCdkey[0] != 0) {
        length = strlen((const char *) data->mCdkey);
        Util_RandSeed(0x79707367);
        for (index = 0; index < length; index++) {
            randomByte = Util_RandInt(0, 0xff);
            cdKeyMasked[index] = randomByte ^ data->mCdkey[index];
        }
        cdKeyMasked[index] = 0;
        B64Encode(cdKeyMasked, cdKeyEncoded, length, B64_ENCODING_ALTERNATE);
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\cdkeyenc\\");
        gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, cdKeyEncoded);
    }
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\id\\1");
    gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\final\\");
    return 0;
}

u32 gpiProcessConnect(GPConnection *connection, GPIOperation *operation, const char *input) {
    GPIConnection *gpState;
    GPIConnectData *data;
    char digestHex[0x21];
    char uniqueNickText[0x15];
    char buffer[0x200];
    char loginNameBuf[0x52];
    GPICallback callback;
    ConnectReply *arg;
    void *loginName;
    u32 result;

    gpState = connection->mGpiConnection;
    if (gpiCheckForError(connection, input, 0) != FALSE) {
        if (gpState->mErrorNumber == PROFILE_ERROR_REMOVES_PROFILE && gpState->mProfileId != 0) {
            gpiRemoveProfileByID(connection, gpState->mProfileId);
            gpState->mUserId = 0;
            gpState->mProfileId = 0;
        } else if (gpState->mErrorNumber == PROFILE_ERROR_RETURNS_PROFILE_ID) {
            if (gpiValueForKey(input, "\\pid\\", buffer, 0x200) != FALSE) {
                gpState->mProfileId = StrtolBase10(buffer);
            }
        }
        if (strstr(input, "\\fatal\\") != NULL) {
            gpiSetError(connection, gpState->mErrorNumber, gpState->mErrorMessage);
            gpiCallErrorCallback(connection, 4, 1);
            return 4;
        }
        gpiSetError(connection, gpState->mErrorNumber, gpState->mErrorMessage);
        gpiCallErrorCallback(connection, 4, 0);
        return 4;
    }
    data = (GPIConnectData *) operation->mData;
    switch (operation->mState) {
        case PROFILE_CONNECT_STATE_WAIT_CHALLENGE:
            if (strncmp(input, "\\lc\\1", 5) != 0) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            if (gpiValueForKey(input, "\\challenge\\", data->mServerChallenge, 0x80) == FALSE) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            if (data->mNewuser != 0) {
                result = gpiSendNewuser(connection, data);
                if (result != 0) {
                    return result;
                }
                operation->mState = PROFILE_CONNECT_STATE_WAIT_NEW_USER_REPLY;
            } else {
                result = gpiSendLogin(connection, data);
                if (result != 0) {
                    return result;
                }
                operation->mState = PROFILE_CONNECT_STATE_WAIT_LOGIN_REPLY;
            }
            break;
        case PROFILE_CONNECT_STATE_WAIT_NEW_USER_REPLY:
            if (strncmp(input, "\\nur\\", 5) != 0) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            if (gpiValueForKey(input, "\\userid\\", buffer, 0x200) == FALSE) {
                gpiSetError(connection, 1, "Unexepected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mUserId = StrtolBase10(buffer);
            if (gpiValueForKey(input, "\\profileid\\", buffer, 0x200) == FALSE) {
                gpiSetError(connection, 1, "Unexepected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mProfileId = StrtolBase10(buffer);
            result = gpiSendLogin(connection, data);
            if (result != 0) {
                return result;
            }
            operation->mState = PROFILE_CONNECT_STATE_WAIT_LOGIN_REPLY;
            break;
        case PROFILE_CONNECT_STATE_WAIT_LOGIN_REPLY:
            if (strncmp(input, "\\lc\\2", 5) != 0) {
                gpiSetError(connection, 1, "Unexpected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            if (gpiValueForKey(input, "\\sesskey\\", buffer, 0x200) == FALSE) {
                gpiSetError(connection, 1, "Unexepected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mSesskey = StrtolBase10(buffer);
            if (gpiValueForKey(input, "\\userid\\", buffer, 0x200) == FALSE) {
                gpiSetError(connection, 1, "Unexepected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mUserId = StrtolBase10(buffer);
            if (gpiValueForKey(input, "\\profileid\\", buffer, 0x200) == FALSE) {
                gpiSetError(connection, 1, "Unexepected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            gpState->mProfileId = StrtolBase10(buffer);
            if (gpiValueForKey(input, "\\uniquenick\\", uniqueNickText, 0x15) == FALSE) {
                uniqueNickText[0] = 0;
            }
            if (gpiValueForKey(input, "\\lt\\", gpState->mLoginTicket, 0x19) == FALSE) {
                gpState->mLoginTicket[0] = 0;
            }
            if (data->mAuthtoken[0] != 0) {
                loginName = data->mAuthtoken;
            } else if (gpState->mUniquenick[0] != 0) {
                loginName = gpState->mUniquenick;
            } else {
                sprintf(loginNameBuf, "%s@%s", gpState->mNick, gpState->mEmail);
                loginName = loginNameBuf;
            }
            sprintf(buffer, "%s%s%s%s%s%s", data->mPasswordHash, "                                                ",
                    loginName, data, data->mUserChallenge, data->mPasswordHash);
            MD5Digest(buffer, strlen(buffer), digestHex);
            if (gpiValueForKey(input, "\\proof\\", buffer, 0x200) == FALSE) {
                gpiSetError(connection, 1, "Unexepected data was received from the server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            if (memcmp(digestHex, buffer, 0x20) != 0) {
                gpiSetError(connection, 0x108, "Could not authenticate server.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            if (gpState->mInfoCaching != 0) {
                GPIProfile *profile = gpiProfileListAdd(connection, gpState->mProfileId);
                profile->mProfileId = gpState->mProfileId;
                profile->mUserId = gpState->mUserId;
            }
            gpState->mConnectState = PROFILE_CONNECTION_LOGGED_IN;
            callback = operation->mCallback;
            if (callback.mCallback != NULL) {
                arg = DWCi_GsMalloc(0x20);
                if (arg == NULL) {
                    gpiSetErrorString(connection, "Out of memory.");
                    return 1;
                }
                memset(arg, 0, sizeof(*arg));
                arg->mProfile = gpState->mProfileId;
                arg->mResult = GP_REQUEST_OK;
                CopyStringWithTerminator(arg->mUniquenick, uniqueNickText, 0x15);
                result = gpiAddCallback(connection, callback, arg, operation, 0);
                if (result != 0) {
                    return result;
                }
            }
            gpiRemoveOperation(connection, operation);
            break;
    }
    return 0;
}

int gpiCheckConnect(GPConnection *connection) {
    int result;
    GPIConnection *gpState;
    u32 state;
    gpState = connection->mGpiConnection;
    result = gpiCheckSocketConnect(connection, gpState->mConnectSocket, &state);
    if (result == 0) {
        if (state == 4) {
            gpiSetError(connection, 0x107u, "The server has refused the connection.");
            gpiCallErrorCallback(connection, 4, 1);
            return 4;
        }
        if (state == 0) {
            return 0;
        }
        if (state != 3) {
            AssertionFailed("state == GPI_CONNECTED", "gpiConnect.c", NULL, 0x2ef);
        }
        gpState->mConnectState = PROFILE_CONNECTION_HANDSHAKE;
        result = 0;
    }
    return result;
}

s32 gpiDisconnectCleanupProfile(GPConnection *connection, GPIProfile *profile, void *data) {
    GPIConnection *gpState;

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
        gpiRemoveProfile(connection, profile);
        return 0;
    }
    return 1;
}

void gpiDisconnect(GPConnection *connection, s32 tellServer) {
    GPIConnection *gpState;
    GPIOperation *unusedOperation;
    GPIPeer *peerConn;
    u32 connClosed;

    gpState = connection->mGpiConnection;
    if (gpState->mConnectState == PROFILE_CONNECTION_CLOSED) {
        return;
    }
    if (gpState->mConnectState != PROFILE_CONNECTION_IDLE) {
        if (tellServer != 0 && gpState->mConnectState == PROFILE_CONNECTION_LOGGED_IN) {
            gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\logout\\\\sesskey\\");
            gpiAppendIntToBuffer(connection, &gpState->mOutputBuffer, gpState->mSesskey);
            gpiAppendStringToBuffer(connection, &gpState->mOutputBuffer, "\\final\\");
        }
        gpiSendFromBuffer(connection, gpState->mConnectSocket, &gpState->mOutputBuffer, &connClosed, 1, (const s8 *) "CM");
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
        gpState->mConnectState = PROFILE_CONNECTION_CLOSED;
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
        gpiRemoveOperation(connection, gpState->mOperationList);
    }
    gpState->mOperationList = NULL;
    peerConn = gpState->mPeerList;
    while (peerConn != NULL) {
        GPIPeer *doomedPeer = peerConn;
        peerConn = peerConn->mNext;
        gpiDestroyPeer(connection, doomedPeer);
    }
    gpState->mPeerList = NULL;
    while (gpiProfileMap(connection, gpiDisconnectCleanupProfile, NULL) == 0) {
    }
}
