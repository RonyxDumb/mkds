#include "00/Lib/GameSpy/code_02194bb8.h"
#include "00/Lib/GameSpy/code_0218f960.h"

#include "00/Lib/GameSpy/code_02196590.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "string.h"
#include "code_02134398.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/code_02194000.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/unk_021b2000.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/Lib/GameSpy/code_02196480.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/Lib/GameSpy/code_02193b88.h"
#include "00/code_02193000.h"
#include "00/Lib/GameSpy/code_02193634.h"
#include "code_021384cc.h"
#include "00/unk_021b4000.h"
#include "00/Lib/GameSpy/code_02190cd4.h"
#include "00/Lib/NitroWiFi/socl_startup.h"
#include "00/Lib/GameSpy/code_0218d488.h"

char gSearchManagerName[0x40] = "gpsp.gs.nintendowifi.net";

void gpiHandleTransferMessage(GpConnection *connection, GpiPeer *peer, s32 type, const char *headers, s32 buffer,
                              s32 len) {
    char value[0x40];
    GpiTransferId transferKey;

    if (GpiGetValue(headers, "\\xfer\\", value, 0x40) != FALSE) {
        if (sscanf(value, "%d %u %u", &transferKey.mProfileId, &transferKey.mCount, &transferKey.mTime) == 3) {
            gpiSendTransferReply(connection, &transferKey, peer, 2, NULL);
        }
    }
}

s32 GpiOpenSearchSocket(GpConnection *connection, GpiOperation *operation) {
    GPISearchData *data;
    SOCHostEnt *resolvedHost;
    s32 openResult;

    data = operation->mData;
    data->mInputBufferCapacity = 0x1000;
    data->mInputBuffer = DWCi_GsMalloc(data->mInputBufferCapacity + 1);
    if (data->mInputBuffer == NULL) {
        GpiSetErrorMessage(connection, "Out of memory.");
        return 1;
    }
    data->mSocket = OpenNetSocket(2, 1, 0);
    if (data->mSocket == -1) {
        GpiSetError(connection, 5, "There was an error creating a socket.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    if (SetSockBlocking(data->mSocket, 0) == FALSE) {
        GpiSetError(connection, 5, "There was an error making a socket non-blocking.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    resolvedHost = SOC_GetHostByName(gSearchManagerName);
    if (resolvedHost == NULL) {
        GpiSetError(connection, 5, "Could not resolve search mananger host name.");
        GpiQueueErrorCallback(connection, 3, 1);
        return 3;
    }
    {
        SOCSockAddrIn address = {0};

        address.mFamily = 2;
        address.mAddr = resolvedHost->mAddrList[0][0];
        if (address.mAddr == 0) {
            AssertionFailed("address.sin_addr.s_addr != 0", "gpiSearch.c", NULL, 0x59);
        }
        address.mPort = 0xcd74;
        if (connect(data->mSocket, &address, 8) == -1) {
            openResult = GOAGetLastError(data->mSocket);
            if (openResult != -6 && openResult != -0x1a && openResult != -0x4c) {
                GpiSetError(connection, 5, "There was an error connecting a socket.");
                GpiQueueErrorCallback(connection, 3, 1);
                return 3;
            }
        }
    }
    operation->mState = PROFILE_SEARCH_STATE_WAIT_CONNECT;
    return 0;
}

BOOL GpiCreateSearch(GpConnection *connection, GPISearchData **searchData, u32 kind) {
    GPISearchData *data;

    data = DWCi_GsMalloc(sizeof(GPISearchData));
    if (data == NULL) {
        GpiSetErrorMessage(connection, "Out of memory.");
        return TRUE;
    }
    memset(data, 0, sizeof(GPISearchData));
    data->mKind = kind;
    data->mSocket = -1;
    data->mInputBuffer = NULL;
    data->mInputBufferLength = 0;
    data->mInputBufferPos = 0;
    data->mInputBufferCapacity = 0;
    data->mOutputBufferLength = 0;
    data->mOutputBufferPos = 0;
    data->mOutputBufferCapacity = 0x1000;
    data->mOutputBuffer = DWCi_GsMalloc(data->mOutputBufferCapacity + 1);
    if (data->mOutputBuffer == NULL) {
        GpiSetErrorMessage(connection, "Out of memory.");
        return TRUE;
    }
    data->mProcessing = 0;
    data->mRemove = 0;
    *searchData = data;
    return FALSE;
}

int GpiStartSearchOperation(GpConnection *connection, GPISearchData *data, u32 blocking, GpiCallbackFn callback,
                            u32 param) {
    int result;
    GpiOperation *pendingOp;
    connection->mGpiConnection->mSearchCount = connection->mGpiConnection->mSearchCount + 1;
    result = GpiCreateOperation(connection, PROFILE_OPERATION_SEARCH, data, &pendingOp, blocking, callback, param);
    if (((result == 0) && (result = GpiOpenSearchSocket(connection, pendingOp), result == 0)) &&
        ((pendingOp->mBlocking == 0 || (result = GpiUpdateConnection(connection, pendingOp->mId), result == 0)))) {
        result = 0;
    }
    return result;
}

int gpiProfileSearch(GpConnection *connection, s8 *nick, s8 *uniquenick, s8 *email, s8 *firstname, s8 *lastname,
                     int icquin, int skip, u32 blocking, GpiCallbackFn callback, u32 param) {
    int result;
    GPISearchData *data;
    if ((((((nick == NULL) || (*nick == 0)) && ((email == NULL || (*email == 0)))) &&
          ((firstname == NULL || (*firstname == 0)))) &&
         ((lastname == NULL || (*lastname == 0)))) &&
        ((icquin == 0 && ((uniquenick == NULL || (*uniquenick == 0)))))) {
        GpiSetErrorMessage(connection, "No search criteria.");
        return 2;
    }
    result = GpiCreateSearch(connection, &data, PROFILE_SEARCH_KIND_PROFILES);
    if (result == 0) {
        if (nick == NULL) {
            data->mNick[0] = 0;
        } else {
            GpiCopyString((char *) data->mNick, (const char *) nick, 0x1f);
        }
        if (uniquenick == NULL) {
            data->mUniquenick[0] = 0;
        } else {
            GpiCopyString((char *) data->mUniquenick, (const char *) uniquenick, 0x15);
        }
        if (email == NULL) {
            data->mEmail[0] = 0;
        } else {
            GpiCopyString((char *) data->mEmail, (const char *) email, 0x33);
        }
        _strlwr(data->mEmail);
        if (firstname == NULL) {
            data->mFirstname[0] = 0;
        } else {
            GpiCopyString((char *) data->mFirstname, (const char *) firstname, 0x1f);
        }
        if (lastname == NULL) {
            data->mLastname[0] = 0;
        } else {
            GpiCopyString((char *) data->mLastname, (const char *) lastname, 0x1f);
        }
        data->mIcquin = icquin;
        if (skip < 0) {
            skip = 0;
        }
        data->mSkip = skip;
        result = GpiStartSearchOperation(connection, data, blocking, callback, param);
        if (result == 0) {
            result = 0;
        }
    }
    return result;
}

s32 GpiUpdateSearch(GpConnection *connection, GpiOperation *operation) {
    char key[0x200];
    char value[0x200];
    ProfileSearchReply response;
    u32 state;
    s32 readPos;
    GpiCallback profilesCallback;
    u32 bytesRead;
    u32 socketGone;
    GpiCallback uniqueNickCallback;
    GpiCallback othersCallback;
    GpiCallback newUserCallback;
    GpiCallback checkNickCallback;
    GpiCallback playerMatchCallback;
    GpiCallback nicksCallback;
    GpiCallback emailCheckCallback;
    BOOL isDone;
    s32 savedPos;
    GpiConnection *gpState;
    GPISearchData *data;
    BOOL loop;
    s32 result;
    BOOL matchDone;
    s32 resultValue;
    s32 profileValue;
    s32 previousMore;
    char *allocatedText;
    ProfileMatch *profileMatches;
    ProfileMatch *profileMatch;
    PlayerMatch *playerMatches;
    PlayerMatch *playerMatch;
    EmailCheckReply *u2;
    UserNicksReply *u3;
    FindPlayersReply *u4;
    GpCheckNewUserResponseArg *u5;
    ReverseBuddiesReply *u7;
    s32 matchIndex;
    SuggestNickReply *u9;

    gpState = connection->mGpiConnection;
    data = operation->mData;
    if (operation->mBlocking != 0) {
        loop = TRUE;
    } else {
        loop = FALSE;
    }
    do {
        result = GpiSendBuffer(connection, data->mSocket, (GpiBuffer *) &data->mOutputBuffer, &socketGone, 1,
                               (const s8 *) "SM");
        if (result != 0) {
            return result;
        }
        if (operation->mState == PROFILE_SEARCH_STATE_WAIT_CONNECT) {
            result = GpiCheckConnectComplete(connection, data->mSocket, &state);
            if (result != 0) {
                return result;
            }
            if (state == 4) {
                GpiSetError(connection, 0xd01, "Could not connect to the search manager.");
                GpiQueueErrorCallback(connection, 4, 0);
                return 4;
            }
            if (state == 3) {
                if (data->mKind == PROFILE_SEARCH_KIND_PROFILES) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\search\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\sesskey\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mSesskey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\profileid\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mProfileId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                    if (data->mNick[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, "\\nick\\");
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mNick);
                    }
                    if (data->mUniquenick[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, "\\uniquenick\\");
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mUniquenick);
                    }
                    if (data->mEmail[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, "\\email\\");
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                    }
                    if (data->mFirstname[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, "\\firstname\\");
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mFirstname);
                    }
                    if (data->mLastname[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, "\\lastname\\");
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mLastname);
                    }
                    if (data->mIcquin != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, "\\icquin\\");
                        GpiAppendBufferNumber(connection, &data->mOutputBuffer, data->mIcquin);
                    }
                    if (data->mSkip > 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, "\\skip\\");
                        GpiAppendBufferNumber(connection, &data->mOutputBuffer, data->mSkip);
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_VALID_EMAIL) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\valid\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\email\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                } else if (data->mKind == PROFILE_SEARCH_KIND_NICKS) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\nicks\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\email\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\pass\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mPassword);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                } else if (data->mKind == PROFILE_SEARCH_KIND_PLAYER_MATCH) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\pmatch\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\sesskey\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mSesskey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\profileid\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mProfileId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\productid\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, data->mProductId);
                } else if (data->mKind == PROFILE_SEARCH_KIND_CHECK_NICK) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\check\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\nick\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mNick);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\email\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\pass\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mPassword);
                } else if (data->mKind == PROFILE_SEARCH_KIND_NEW_USER) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\newuser\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\nick\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mNick);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\email\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mEmail);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\pass\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mPassword);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\productID\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mProductId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\uniquenick\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mUniquenick);
                    if (data->mCdkey[0] != 0) {
                        GpiAppendBufferString(connection, &data->mOutputBuffer, "\\cdkey\\");
                        GpiAppendBufferString(connection, &data->mOutputBuffer, data->mCdkey);
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_OTHERS) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\others\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\sesskey\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mSesskey);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\profileid\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mProfileId);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                } else if (data->mKind == PROFILE_SEARCH_KIND_UNIQUE_NICK) {
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\uniquesearch\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\preferrednick\\");
                    GpiAppendBufferString(connection, &data->mOutputBuffer, data->mUniquenick);
                    GpiAppendBufferString(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    GpiAppendBufferNumber(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                } else {
                    AssertionFailed("0", "gpiSearch.c", NULL, 0x275);
                }
                GpiAppendBufferString(connection, &data->mOutputBuffer, "\\gamename\\");
                GpiAppendBufferString(connection, &data->mOutputBuffer, gGsiAcGamename);
                GpiAppendBufferString(connection, &data->mOutputBuffer, "\\final\\");
                operation->mState = PROFILE_SEARCH_STATE_WAIT_REPLY;
            }
        } else if (operation->mState == PROFILE_SEARCH_STATE_WAIT_REPLY) {
            result = GpiReceiveBuffer(connection, data->mSocket, (GpiBuffer *) &data->mInputBuffer, (s32 *) &bytesRead,
                                      &socketGone, (const s8 *) "SM");
            if (result != 0) {
                if (result != 3) {
                    return result;
                }
                GpiSetError(connection, 0xd01, "There was an error reading from the server.");
                GpiQueueErrorCallback(connection, 3, 0);
                return 3;
            }
            if (strstr(data->mInputBuffer, "\\final\\") != NULL) {
                readPos = 0;
                operation->mState = PROFILE_SEARCH_STATE_REPLY_READ;
                if (GpiReadError(connection, data->mInputBuffer, 1) != FALSE) {
                    data->mRemove = TRUE;
                    return 4;
                }
                if (data->mKind == PROFILE_SEARCH_KIND_PROFILES) {
                    isDone = FALSE;
                    response.mResult = GP_REQUEST_OK;
                    response.mNumMatches = 0;
                    response.mMatches = NULL;
                    response.mMore = PROFILE_SEARCH_MORE_DONE;
                    do {
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "bsrdone") == 0) {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, "more") == 0 && strcmp(value, "0") != 0) {
                                response.mMore = PROFILE_SEARCH_MORE_CONTINUE;
                            }
                            isDone = TRUE;
                        } else if (strcmp(key, "bsr") == 0) {
                            profileMatches = DWCi_GsRealloc(response.mMatches, ++response.mNumMatches * 0xac);
                            response.mMatches = profileMatches;
                            if (profileMatches == NULL) {
                                GpiSetErrorMessage(connection, "Out of memory.");
                                return 1;
                            }
                            matchIndex = response.mNumMatches - 1;
                            profileMatch = &profileMatches[matchIndex];
                            memset(profileMatch, 0, sizeof(*profileMatch));
                            profileMatches[matchIndex].mProfile = StrtolBase10(value);
                            matchDone = FALSE;
                            do {
                                savedPos = readPos;
                                result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                                if (result != 0) {
                                    return result;
                                }
                                if (strcmp(key, "nick") == 0) {
                                    GpiCopyString(profileMatch->mNick, value, 0x1f);
                                } else if (strcmp(key, "uniquenick") == 0) {
                                    GpiCopyString(profileMatch->mUniquenick, value, 0x15);
                                } else if (strcmp(key, "firstname") == 0) {
                                    GpiCopyString(profileMatch->mFirstname, value, 0x1f);
                                } else if (strcmp(key, "lastname") == 0) {
                                    GpiCopyString(profileMatch->mLastname, value, 0x1f);
                                } else if (strcmp(key, "email") == 0) {
                                    GpiCopyString(profileMatch->mEmail, value, 0x33);
                                } else if (strcmp(key, "bsr") == 0 || strcmp(key, "bsrdone") == 0) {
                                    matchDone = TRUE;
                                    readPos = savedPos;
                                }
                            } while (matchDone == FALSE);
                        } else {
                            GpiSetError(connection, 1, "Error reading from the search server.");
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                    } while (isDone == FALSE);
                    previousMore = response.mMore;
                    profilesCallback = operation->mCallback;
                    if (profilesCallback.mCallback != NULL) {
                        profilesCallback.mCallback(connection, &response, profilesCallback.mParam);
                    }
                    if (previousMore == PROFILE_SEARCH_MORE_CONTINUE &&
                        response.mMore == PROFILE_SEARCH_MORE_CONTINUE) {
                        result = gpiProfileSearch(connection, data->mNick, data->mUniquenick, data->mEmail,
                                                  data->mFirstname, data->mLastname, data->mIcquin,
                                                  response.mNumMatches + data->mSkip, operation->mBlocking,
                                                  operation->mCallback.mCallback, operation->mCallback.mParam);
                        if (result != 0) {
                            return result;
                        }
                    }
                    DWCi_GsFree(response.mMatches);
                    response.mMatches = NULL;
                } else if (data->mKind == PROFILE_SEARCH_KIND_VALID_EMAIL) {
                    emailCheckCallback = operation->mCallback;
                    if (emailCheckCallback.mCallback != NULL) {
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "vr") != 0) {
                            GpiSetError(connection, 1, "Error reading from the search server.");
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        u2 = DWCi_GsMalloc(0x3c);
                        if (u2 == NULL) {
                            GpiSetErrorMessage(connection, "Out of memory.");
                            return 1;
                        }
                        u2->mResult = GP_REQUEST_OK;
                        GpiCopyString(u2->mEmail, (const char *) data->mEmail, 0x33);
                        if ((s8) value[0] == 0x30) {
                            u2->mIsValid = FALSE;
                        } else {
                            u2->mIsValid = TRUE;
                        }
                        result = GpiQueueCallback(connection, emailCheckCallback, u2, operation,
                                                  PROFILE_CALLBACK_TYPE_PLAIN);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_NICKS) {
                    nicksCallback = operation->mCallback;
                    if (nicksCallback.mCallback != NULL) {
                        u3 = DWCi_GsMalloc(0x44);
                        if (u3 == NULL) {
                            GpiSetErrorMessage(connection, "Out of memory.");
                            return 1;
                        }
                        u3->mResult = GP_REQUEST_OK;
                        strcpy(u3->mEmail, (const char *) data->mEmail);
                        u3->mNumNicks = 0;
                        u3->mNicks = NULL;
                        u3->mUniquenicks = NULL;
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "nr") != 0) {
                            GpiSetError(connection, 1, "Error reading from the search server.");
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        isDone = FALSE;
                        do {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, "nick") == 0) {
                                allocatedText = DWCi_GsRealloc(u3->mNicks, (u3->mNumNicks + 1) * 4);
                                if (allocatedText == NULL) {
                                    GpiSetErrorMessage(connection, "Out of memory.");
                                    return 1;
                                }
                                u3->mNicks = (char **) allocatedText;
                                allocatedText = DWCi_GsMalloc(0x1f);
                                if (allocatedText == NULL) {
                                    GpiSetErrorMessage(connection, "Out of memory.");
                                    return 1;
                                }
                                u3->mNicks[u3->mNumNicks] = allocatedText;
                                GpiCopyString(u3->mNicks[u3->mNumNicks], value, 0x1f);
                                u3->mNumNicks++;
                            } else if (strcmp(key, "uniquenick") == 0) {
                                if (u3->mNumNicks > 0) {
                                    allocatedText = DWCi_GsRealloc(u3->mUniquenicks, u3->mNumNicks * 4);
                                    if (allocatedText == NULL) {
                                        GpiSetErrorMessage(connection, "Out of memory.");
                                        return 1;
                                    }
                                    u3->mUniquenicks = (char **) allocatedText;
                                    allocatedText = DWCi_GsMalloc(0x15);
                                    if (allocatedText == NULL) {
                                        GpiSetErrorMessage(connection, "Out of memory.");
                                        return 1;
                                    }
                                    u3->mUniquenicks[u3->mNumNicks - 1] = allocatedText;
                                    GpiCopyString(u3->mUniquenicks[u3->mNumNicks - 1], value, 0x15);
                                }
                            } else if (strcmp(key, "ndone") == 0) {
                                isDone = TRUE;
                            } else {
                                GpiSetError(connection, 1, "Error reading from the search server.");
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (isDone == FALSE);
                        result = GpiQueueCallback(connection, nicksCallback, u3, operation,
                                                  PROFILE_CALLBACK_TYPE_FREE_NICK_LISTS);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_PLAYER_MATCH) {
                    playerMatchCallback = operation->mCallback;
                    if (playerMatchCallback.mCallback != NULL) {
                        u4 = DWCi_GsMalloc(0x10);
                        if (u4 == NULL) {
                            GpiSetErrorMessage(connection, "Out of memory.");
                            return 1;
                        }
                        u4->mProductId = data->mProductId;
                        isDone = FALSE;
                        u4->mResult = GP_REQUEST_OK;
                        u4->mNumMatches = 0;
                        u4->mMatches = NULL;
                        do {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, "psrdone") == 0) {
                                isDone = TRUE;
                            } else if (strcmp(key, "psr") == 0) {
                                u4->mNumMatches++;
                                u4->mMatches = DWCi_GsRealloc(u4->mMatches, u4->mNumMatches * 0x128);
                                playerMatches = u4->mMatches;
                                if (playerMatches == NULL) {
                                    GpiSetErrorMessage(connection, "Out of memory.");
                                    return 1;
                                }
                                matchIndex = u4->mNumMatches - 1;
                                playerMatch = &playerMatches[matchIndex];
                                memset(playerMatch, 0, sizeof(*playerMatch));
                                playerMatch->mStatus = 1;
                                playerMatches[matchIndex].mProfile = StrtolBase10(value);
                                matchDone = FALSE;
                                do {
                                    savedPos = readPos;
                                    result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                                    if (result != 0) {
                                        return result;
                                    }
                                    if (strcmp(key, "status") == 0) {
                                        GpiCopyString(playerMatch->mStatusString, value, 0x100);
                                    } else if (strcmp(key, "nick") == 0) {
                                        GpiCopyString(playerMatch->mNick, value, 0x1f);
                                    }
                                    if (strcmp(key, "statuscode") == 0) {
                                        playerMatch->mStatus = StrtolBase10(value);
                                    } else if (strcmp(key, "psr") == 0 || strcmp(key, "psrdone") == 0) {
                                        matchDone = TRUE;
                                        readPos = savedPos;
                                    }
                                } while (matchDone == FALSE);
                            } else {
                                GpiSetError(connection, 1, "Error reading from the search server.");
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (isDone == FALSE);
                        result = GpiQueueCallback(connection, playerMatchCallback, u4, operation,
                                                  PROFILE_CALLBACK_TYPE_FREE_MATCH_LIST);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_CHECK_NICK) {
                    checkNickCallback = operation->mCallback;
                    if (checkNickCallback.mCallback != NULL) {
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "cur") != 0) {
                            GpiSetError(connection, 1, "Error reading from the search server.");
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        resultValue = StrtolBase10(value);
                        if (resultValue != 0) {
                            gpState->mErrorNumber = resultValue;
                            profileValue = 0;
                        } else {
                            if (GpiGetValue(data->mInputBuffer, "\\pid\\", value, 0x200) == FALSE) {
                                GpiSetError(connection, 1, "Error reading from the search server.");
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                            profileValue = StrtolBase10(value);
                        }
                        u5 = DWCi_GsMalloc(8);
                        if (u5 == NULL) {
                            GpiSetErrorMessage(connection, "Out of memory.");
                            return 1;
                        }
                        u5->mResult = resultValue;
                        u5->mProfile = profileValue;
                        result =
                            GpiQueueCallback(connection, checkNickCallback, u5, operation, PROFILE_CALLBACK_TYPE_PLAIN);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_NEW_USER) {
                    newUserCallback = operation->mCallback;
                    if (newUserCallback.mCallback != NULL) {
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "nur") != 0) {
                            GpiSetError(connection, 1, "Error reading from the search server.");
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        resultValue = StrtolBase10(value);
                        if (resultValue != 0) {
                            gpState->mErrorNumber = resultValue;
                        }
                        if (GpiGetValue(data->mInputBuffer, "\\pid\\", value, 0x200) == FALSE) {
                            if (resultValue == 0) {
                                GpiSetError(connection, 1, "Error reading from the search server.");
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                            profileValue = 0;
                        } else {
                            profileValue = StrtolBase10(value);
                        }
                        u5 = DWCi_GsMalloc(8);
                        if (u5 == NULL) {
                            GpiSetErrorMessage(connection, "Out of memory.");
                            return 1;
                        }
                        u5->mResult = resultValue;
                        u5->mProfile = profileValue;
                        result =
                            GpiQueueCallback(connection, newUserCallback, u5, operation, PROFILE_CALLBACK_TYPE_PLAIN);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_OTHERS) {
                    othersCallback = operation->mCallback;
                    if (othersCallback.mCallback != NULL) {
                        u7 = DWCi_GsMalloc(0xc);
                        if (u7 == NULL) {
                            GpiSetErrorMessage(connection, "Out of memory.");
                            return 1;
                        }
                        u7->mResult = GP_REQUEST_OK;
                        u7->mNumProfiles = 0;
                        u7->mProfiles = NULL;
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "others") != 0) {
                            GpiSetError(connection, 1, "Error reading from the search server.");
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        isDone = FALSE;
                        do {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, "odone") == 0) {
                                isDone = TRUE;
                            } else if (strcmp(key, "o") == 0) {
                                profileMatches = DWCi_GsRealloc(u7->mProfiles, (u7->mNumProfiles + 1) * 0xac);
                                if (profileMatches == NULL) {
                                    GpiSetErrorMessage(connection, "Out of memory.");
                                    return 1;
                                }
                                u7->mProfiles = profileMatches;
                                profileMatches = u7->mProfiles;
                                matchIndex = u7->mNumProfiles;
                                profileMatch = &profileMatches[matchIndex];
                                memset(profileMatch, 0, sizeof(*profileMatch));
                                u7->mNumProfiles++;
                                profileMatches[matchIndex].mProfile = StrtolBase10(value);
                                matchDone = FALSE;
                                do {
                                    savedPos = readPos;
                                    result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                                    if (result != 0) {
                                        return result;
                                    }
                                    if (strcmp(key, "nick") == 0) {
                                        GpiCopyString(profileMatch->mNick, value, 0x1f);
                                    } else if (strcmp(key, "uniquenick") == 0) {
                                        GpiCopyString(profileMatch->mUniquenick, value, 0x15);
                                    } else if (strcmp(key, "first") == 0) {
                                        GpiCopyString(profileMatch->mFirstname, value, 0x1f);
                                    } else if (strcmp(key, "last") == 0) {
                                        GpiCopyString(profileMatch->mLastname, value, 0x1f);
                                    } else if (strcmp(key, "email") == 0) {
                                        GpiCopyString(profileMatch->mEmail, value, 0x33);
                                    } else if (strcmp(key, "o") == 0 || strcmp(key, "odone") == 0) {
                                        matchDone = TRUE;
                                        readPos = savedPos;
                                    }
                                } while (matchDone == FALSE);
                            } else {
                                GpiSetError(connection, 1, "Error reading from the search server.");
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (isDone == FALSE);
                        result = GpiQueueCallback(connection, othersCallback, u7, operation,
                                                  PROFILE_CALLBACK_TYPE_FREE_OTHERS_PROFILES_IF_SET);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_UNIQUE_NICK) {
                    uniqueNickCallback = operation->mCallback;
                    if (uniqueNickCallback.mCallback != NULL) {
                        matchIndex = 0;
                        u9 = DWCi_GsMalloc(0xc);
                        if (u9 == NULL) {
                            GpiSetErrorMessage(connection, "Out of memory.");
                            return 1;
                        }
                        u9->mResult = GP_REQUEST_OK;
                        u9->mNumSuggestedNicks = 0;
                        u9->mSuggestedNicks = NULL;
                        result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "us") != 0) {
                            GpiSetError(connection, 1, "Error reading from the search server.");
                            GpiQueueErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        u9->mNumSuggestedNicks = StrtolBase10(value);
                        u9->mSuggestedNicks = DWCi_GsMalloc(u9->mNumSuggestedNicks * 4);
                        if (u9->mSuggestedNicks == NULL) {
                            GpiSetErrorMessage(connection, "Out of memory.");
                            return 1;
                        }
                        isDone = FALSE;
                        do {
                            result = GpiReadKeyValue(connection, data->mInputBuffer, &readPos, key, value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, "nick") == 0) {
                                u9->mSuggestedNicks[matchIndex] = DWCi_GsMalloc(0x15);
                                if (u9->mSuggestedNicks[matchIndex] == NULL) {
                                    GpiSetErrorMessage(connection, "Out of memory.");
                                    return 1;
                                }
                                GpiCopyString(u9->mSuggestedNicks[matchIndex], value, 0x15);
                                matchIndex++;
                            } else if (strcmp(key, "usdone") == 0) {
                                if (matchIndex != u9->mNumSuggestedNicks) {
                                    AssertionFailed("count == arg->numSuggestedNicks", "gpiSearch.c", NULL, 0x515);
                                }
                                u9->mNumSuggestedNicks = matchIndex;
                                isDone = TRUE;
                            } else {
                                GpiSetError(connection, 1, "Error reading from the search server.");
                                GpiQueueErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (isDone == FALSE);
                        result = GpiQueueCallback(connection, uniqueNickCallback, u9, operation,
                                                  PROFILE_CALLBACK_TYPE_FREE_SUGGESTED_NICKS);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else {
                    AssertionFailed("0", "gpiSearch.c", NULL, 0x52a);
                }
                data->mRemove = TRUE;
                loop = FALSE;
            }
        }
        if (loop != FALSE) {
            msleep(10);
        }
    } while (loop != FALSE);
    return 0;
}

BOOL GpiUpdateSearches(GpConnection *connection) {
    GpiConnection *gpState;
    GpiOperation **operations;
    GpiOperation *pendingOp;
    GPISearchData *data;
    u32 result;
    s32 count;
    s32 index;

    gpState = connection->mGpiConnection;
    count = 0;
    if (gpState->mSearchCount > 0) {
        operations = DWCi_GsMalloc(gpState->mSearchCount * 4);
        if (operations == NULL) {
            GpiSetErrorMessage(connection, "Out of memory.");
            return TRUE;
        }
        for (pendingOp = gpState->mOperationList; pendingOp != NULL; pendingOp = pendingOp->mNext) {
            if (pendingOp->mType == PROFILE_OPERATION_SEARCH && pendingOp->mState != PROFILE_SEARCH_STATE_REPLY_READ &&
                pendingOp->mData->mProcessing == 0) {
                if (count >= gpState->mSearchCount) {
                    AssertionFailed("num < iconnection->numSearches", "gpiSearch.c", NULL, 0x563);
                }
                operations[count++] = pendingOp;
                pendingOp->mData->mProcessing = 1;
            }
        }
        for (index = 0; index < count; index++) {
            result = GpiUpdateSearch(connection, operations[index]);
            if (result != 0) {
                operations[index]->mResult = result;
            }
        }
        for (index = 0; index < count; index++) {
            data = operations[index]->mData;
            data->mProcessing = 0;
            if (data->mRemove != 0) {
                GpiRemoveOperation(connection, operations[index]);
            }
        }
        DWCi_GsFree(operations);
    }
    return FALSE;
}
