#include "00/Lib/GameSpy/profile_search.h"
#include "00/Lib/GameSpy/buddy_messages.h"

#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "narrow_string_functions.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/GameSpy/operation_queue.h"
#include "scan_text_random.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/callback_queue.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"
#include "00/Lib/GameSpy/availability_check.h"

char gSearchManagerName[0x40] = "gpsp.gs.nintendowifi.net";

void gpiHandleTransferMessage(GpConnection *connection, GpiPeer *peer, s32 type, const char *headers, s32 buffer,
                              s32 len) {
    char value[0x40];
    GpiTransferId transferKey;

    if (gpiValueForKey(headers, "\\xfer\\", value, 0x40) != FALSE) {
        if (sscanf(value, "%d %u %u", &transferKey.mProfileId, &transferKey.mCount, &transferKey.mTime) == 3) {
            gpiSendTransferReply(connection, &transferKey, peer, 2, NULL);
        }
    }
}

s32 gpiStartProfileSearch(GpConnection *connection, GpiOperation *operation) {
    GPISearchData *data;
    SOCHostEnt *resolvedHost;
    s32 socketError;

    data = operation->mData;
    data->mInputBufferCapacity = 0x1000;
    data->mInputBuffer = DWCi_GsMalloc(data->mInputBufferCapacity + 1);
    if (data->mInputBuffer == NULL) {
        gpiSetErrorString(connection, "Out of memory.");
        return 1;
    }
    data->mSocket = OpenNetSocket(2, 1, 0);
    if (data->mSocket == -1) {
        gpiSetError(connection, 5, "There was an error creating a socket.");
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    if (SetSockBlocking(data->mSocket, 0) == FALSE) {
        gpiSetError(connection, 5, "There was an error making a socket non-blocking.");
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    resolvedHost = SOC_GetHostByName(gSearchManagerName);
    if (resolvedHost == NULL) {
        gpiSetError(connection, 5, "Could not resolve search mananger host name.");
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    {
        SOCSockAddrIn address = {0};

        address.mFamily = SOCKET_FAMILY_IPV4;
        address.mAddr = resolvedHost->mAddrList[0][0];
        if (address.mAddr == 0) {
            AssertionFailed("address.sin_addr.s_addr != 0", "gpiSearch.c", NULL, 0x59);
        }
        address.mPort = GPI_SEARCH_MANAGER_PORT_NETWORK_ORDER;
        if (connect(data->mSocket, &address, 8) == -1) {
            socketError = GOAGetLastError(data->mSocket);
            if (socketError != -6 && socketError != -0x1a && socketError != -0x4c) {
                gpiSetError(connection, 5, "There was an error connecting a socket.");
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
        }
    }
    operation->mState = PROFILE_SEARCH_STATE_WAIT_CONNECT;
    return 0;
}

BOOL gpiInitSearchData(GpConnection *connection, GPISearchData **searchData, u32 kind) {
    GPISearchData *data;

    data = DWCi_GsMalloc(sizeof(GPISearchData));
    if (data == NULL) {
        gpiSetErrorString(connection, "Out of memory.");
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
        gpiSetErrorString(connection, "Out of memory.");
        return TRUE;
    }
    data->mProcessing = 0;
    data->mRemove = 0;
    *searchData = data;
    return FALSE;
}

int gpiStartSearch(GpConnection *connection, GPISearchData *data, u32 blocking, GpiCallbackFn callback,
                            u32 param) {
    int result;
    GpiOperation *pendingOp;
    connection->mGpiConnection->mSearchCount = connection->mGpiConnection->mSearchCount + 1;
    result = gpiAddOperation(connection, PROFILE_OPERATION_SEARCH, data, &pendingOp, blocking, callback, param);
    if (((result == 0) && (result = gpiStartProfileSearch(connection, pendingOp), result == 0)) &&
        ((pendingOp->mBlocking == 0 || (result = gpiProcess(connection, pendingOp->mId), result == 0)))) {
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
        gpiSetErrorString(connection, "No search criteria.");
        return 2;
    }
    result = gpiInitSearchData(connection, &data, PROFILE_SEARCH_KIND_PROFILES);
    if (result == 0) {
        if (nick == NULL) {
            data->mNick[0] = 0;
        } else {
            CopyStringWithTerminator((char *) data->mNick, (const char *) nick, 0x1f);
        }
        if (uniquenick == NULL) {
            data->mUniquenick[0] = 0;
        } else {
            CopyStringWithTerminator((char *) data->mUniquenick, (const char *) uniquenick, 0x15);
        }
        if (email == NULL) {
            data->mEmail[0] = 0;
        } else {
            CopyStringWithTerminator((char *) data->mEmail, (const char *) email, 0x33);
        }
        _strlwr(data->mEmail);
        if (firstname == NULL) {
            data->mFirstname[0] = 0;
        } else {
            CopyStringWithTerminator((char *) data->mFirstname, (const char *) firstname, 0x1f);
        }
        if (lastname == NULL) {
            data->mLastname[0] = 0;
        } else {
            CopyStringWithTerminator((char *) data->mLastname, (const char *) lastname, 0x1f);
        }
        data->mIcquin = icquin;
        if (skip < 0) {
            skip = 0;
        }
        data->mSkip = skip;
        result = gpiStartSearch(connection, data, blocking, callback, param);
        if (result == 0) {
            result = 0;
        }
    }
    return result;
}

s32 gpiProcessSearch(GpConnection *connection, GpiOperation *operation) {
    char key[0x200];
    char value[0x200];
    ProfileSearchReply response;
    u32 state;
    s32 readPos;
    GpiCallback profilesCallback;
    u32 bytesRead;
    u32 socketClosed;
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
    char *allocatedBlock;
    ProfileMatch *profileMatches;
    ProfileMatch *profileMatch;
    PlayerMatch *playerMatches;
    PlayerMatch *playerMatch;
    EmailCheckReply *u2;
    UserNicksReply *u3;
    FindPlayersReply *u4;
    GpCheckNewUserResponseArg *u5;
    ReverseBuddiesReply *u7;
    s32 entryIndex;
    SuggestNickReply *u9;

    gpState = connection->mGpiConnection;
    data = operation->mData;
    if (operation->mBlocking != 0) {
        loop = TRUE;
    } else {
        loop = FALSE;
    }
    do {
        result = gpiSendFromBuffer(connection, data->mSocket, (GpiBuffer *) &data->mOutputBuffer, &socketClosed, 1,
                               (const s8 *) "SM");
        if (result != 0) {
            return result;
        }
        if (operation->mState == PROFILE_SEARCH_STATE_WAIT_CONNECT) {
            result = gpiCheckSocketConnect(connection, data->mSocket, &state);
            if (result != 0) {
                return result;
            }
            if (state == 4) {
                gpiSetError(connection, 0xd01, "Could not connect to the search manager.");
                gpiCallErrorCallback(connection, 4, 0);
                return 4;
            }
            if (state == 3) {
                if (data->mKind == PROFILE_SEARCH_KIND_PROFILES) {
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\search\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\sesskey\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mSesskey);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\profileid\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mProfileId);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                    if (data->mNick[0] != 0) {
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\nick\\");
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mNick);
                    }
                    if (data->mUniquenick[0] != 0) {
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\uniquenick\\");
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mUniquenick);
                    }
                    if (data->mEmail[0] != 0) {
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\email\\");
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mEmail);
                    }
                    if (data->mFirstname[0] != 0) {
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\firstname\\");
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mFirstname);
                    }
                    if (data->mLastname[0] != 0) {
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\lastname\\");
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mLastname);
                    }
                    if (data->mIcquin != 0) {
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\icquin\\");
                        gpiAppendIntToBuffer(connection, &data->mOutputBuffer, data->mIcquin);
                    }
                    if (data->mSkip > 0) {
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\skip\\");
                        gpiAppendIntToBuffer(connection, &data->mOutputBuffer, data->mSkip);
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_VALID_EMAIL) {
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\valid\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\email\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mEmail);
                } else if (data->mKind == PROFILE_SEARCH_KIND_NICKS) {
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\nicks\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\email\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mEmail);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\pass\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mPassword);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                } else if (data->mKind == PROFILE_SEARCH_KIND_PLAYER_MATCH) {
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\pmatch\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\sesskey\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mSesskey);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\profileid\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mProfileId);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\productid\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, data->mProductId);
                } else if (data->mKind == PROFILE_SEARCH_KIND_CHECK_NICK) {
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\check\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\nick\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mNick);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\email\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mEmail);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\pass\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mPassword);
                } else if (data->mKind == PROFILE_SEARCH_KIND_NEW_USER) {
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\newuser\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\nick\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mNick);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\email\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mEmail);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\pass\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mPassword);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\productID\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mProductId);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\uniquenick\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mUniquenick);
                    if (data->mCdkey[0] != 0) {
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\cdkey\\");
                        gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mCdkey);
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_OTHERS) {
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\others\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\sesskey\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mSesskey);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\profileid\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mProfileId);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                } else if (data->mKind == PROFILE_SEARCH_KIND_UNIQUE_NICK) {
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\uniquesearch\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\preferrednick\\");
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, data->mUniquenick);
                    gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\namespaceid\\");
                    gpiAppendIntToBuffer(connection, &data->mOutputBuffer, gpState->mNamespaceId);
                } else {
                    AssertionFailed("0", "gpiSearch.c", NULL, 0x275);
                }
                gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\gamename\\");
                gpiAppendStringToBuffer(connection, &data->mOutputBuffer, gGsiAcGamename);
                gpiAppendStringToBuffer(connection, &data->mOutputBuffer, "\\final\\");
                operation->mState = PROFILE_SEARCH_STATE_WAIT_REPLY;
            }
        } else if (operation->mState == PROFILE_SEARCH_STATE_WAIT_REPLY) {
            result = gpiRecvToBuffer(connection, data->mSocket, (GpiBuffer *) &data->mInputBuffer, (s32 *) &bytesRead,
                                      &socketClosed, (const s8 *) "SM");
            if (result != 0) {
                if (result != 3) {
                    return result;
                }
                gpiSetError(connection, 0xd01, "There was an error reading from the server.");
                gpiCallErrorCallback(connection, 3, 0);
                return 3;
            }
            if (strstr(data->mInputBuffer, "\\final\\") != NULL) {
                readPos = 0;
                operation->mState = PROFILE_SEARCH_STATE_REPLY_READ;
                if (gpiCheckForError(connection, data->mInputBuffer, 1) != FALSE) {
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
                        result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "bsrdone") == 0) {
                            result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
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
                                gpiSetErrorString(connection, "Out of memory.");
                                return 1;
                            }
                            entryIndex = response.mNumMatches - 1;
                            profileMatch = &profileMatches[entryIndex];
                            memset(profileMatch, 0, sizeof(*profileMatch));
                            profileMatches[entryIndex].mProfile = StrtolBase10(value);
                            matchDone = FALSE;
                            do {
                                savedPos = readPos;
                                result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                                if (result != 0) {
                                    return result;
                                }
                                if (strcmp(key, "nick") == 0) {
                                    CopyStringWithTerminator(profileMatch->mNick, value, 0x1f);
                                } else if (strcmp(key, "uniquenick") == 0) {
                                    CopyStringWithTerminator(profileMatch->mUniquenick, value, 0x15);
                                } else if (strcmp(key, "firstname") == 0) {
                                    CopyStringWithTerminator(profileMatch->mFirstname, value, 0x1f);
                                } else if (strcmp(key, "lastname") == 0) {
                                    CopyStringWithTerminator(profileMatch->mLastname, value, 0x1f);
                                } else if (strcmp(key, "email") == 0) {
                                    CopyStringWithTerminator(profileMatch->mEmail, value, 0x33);
                                } else if (strcmp(key, "bsr") == 0 || strcmp(key, "bsrdone") == 0) {
                                    matchDone = TRUE;
                                    readPos = savedPos;
                                }
                            } while (matchDone == FALSE);
                        } else {
                            gpiSetError(connection, 1, "Error reading from the search server.");
                            gpiCallErrorCallback(connection, 3, 1);
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
                        result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "vr") != 0) {
                            gpiSetError(connection, 1, "Error reading from the search server.");
                            gpiCallErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        u2 = DWCi_GsMalloc(0x3c);
                        if (u2 == NULL) {
                            gpiSetErrorString(connection, "Out of memory.");
                            return 1;
                        }
                        u2->mResult = GP_REQUEST_OK;
                        CopyStringWithTerminator(u2->mEmail, (const char *) data->mEmail, 0x33);
                        if ((s8) value[0] == 0x30) {
                            u2->mIsValid = FALSE;
                        } else {
                            u2->mIsValid = TRUE;
                        }
                        result = gpiAddCallback(connection, emailCheckCallback, u2, operation,
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
                            gpiSetErrorString(connection, "Out of memory.");
                            return 1;
                        }
                        u3->mResult = GP_REQUEST_OK;
                        strcpy(u3->mEmail, (const char *) data->mEmail);
                        u3->mNumNicks = 0;
                        u3->mNicks = NULL;
                        u3->mUniquenicks = NULL;
                        result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "nr") != 0) {
                            gpiSetError(connection, 1, "Error reading from the search server.");
                            gpiCallErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        isDone = FALSE;
                        do {
                            result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, "nick") == 0) {
                                allocatedBlock = DWCi_GsRealloc(u3->mNicks, (u3->mNumNicks + 1) * 4);
                                if (allocatedBlock == NULL) {
                                    gpiSetErrorString(connection, "Out of memory.");
                                    return 1;
                                }
                                u3->mNicks = (char **) allocatedBlock;
                                allocatedBlock = DWCi_GsMalloc(0x1f);
                                if (allocatedBlock == NULL) {
                                    gpiSetErrorString(connection, "Out of memory.");
                                    return 1;
                                }
                                u3->mNicks[u3->mNumNicks] = allocatedBlock;
                                CopyStringWithTerminator(u3->mNicks[u3->mNumNicks], value, 0x1f);
                                u3->mNumNicks++;
                            } else if (strcmp(key, "uniquenick") == 0) {
                                if (u3->mNumNicks > 0) {
                                    allocatedBlock = DWCi_GsRealloc(u3->mUniquenicks, u3->mNumNicks * 4);
                                    if (allocatedBlock == NULL) {
                                        gpiSetErrorString(connection, "Out of memory.");
                                        return 1;
                                    }
                                    u3->mUniquenicks = (char **) allocatedBlock;
                                    allocatedBlock = DWCi_GsMalloc(0x15);
                                    if (allocatedBlock == NULL) {
                                        gpiSetErrorString(connection, "Out of memory.");
                                        return 1;
                                    }
                                    u3->mUniquenicks[u3->mNumNicks - 1] = allocatedBlock;
                                    CopyStringWithTerminator(u3->mUniquenicks[u3->mNumNicks - 1], value, 0x15);
                                }
                            } else if (strcmp(key, "ndone") == 0) {
                                isDone = TRUE;
                            } else {
                                gpiSetError(connection, 1, "Error reading from the search server.");
                                gpiCallErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (isDone == FALSE);
                        result = gpiAddCallback(connection, nicksCallback, u3, operation,
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
                            gpiSetErrorString(connection, "Out of memory.");
                            return 1;
                        }
                        u4->mProductId = data->mProductId;
                        isDone = FALSE;
                        u4->mResult = GP_REQUEST_OK;
                        u4->mNumMatches = 0;
                        u4->mMatches = NULL;
                        do {
                            result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
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
                                    gpiSetErrorString(connection, "Out of memory.");
                                    return 1;
                                }
                                entryIndex = u4->mNumMatches - 1;
                                playerMatch = &playerMatches[entryIndex];
                                memset(playerMatch, 0, sizeof(*playerMatch));
                                playerMatch->mStatus = 1;
                                playerMatches[entryIndex].mProfile = StrtolBase10(value);
                                matchDone = FALSE;
                                do {
                                    savedPos = readPos;
                                    result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                                    if (result != 0) {
                                        return result;
                                    }
                                    if (strcmp(key, "status") == 0) {
                                        CopyStringWithTerminator(playerMatch->mStatusString, value, 0x100);
                                    } else if (strcmp(key, "nick") == 0) {
                                        CopyStringWithTerminator(playerMatch->mNick, value, 0x1f);
                                    }
                                    if (strcmp(key, "statuscode") == 0) {
                                        playerMatch->mStatus = StrtolBase10(value);
                                    } else if (strcmp(key, "psr") == 0 || strcmp(key, "psrdone") == 0) {
                                        matchDone = TRUE;
                                        readPos = savedPos;
                                    }
                                } while (matchDone == FALSE);
                            } else {
                                gpiSetError(connection, 1, "Error reading from the search server.");
                                gpiCallErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (isDone == FALSE);
                        result = gpiAddCallback(connection, playerMatchCallback, u4, operation,
                                                  PROFILE_CALLBACK_TYPE_FREE_MATCH_LIST);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_CHECK_NICK) {
                    checkNickCallback = operation->mCallback;
                    if (checkNickCallback.mCallback != NULL) {
                        result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "cur") != 0) {
                            gpiSetError(connection, 1, "Error reading from the search server.");
                            gpiCallErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        resultValue = StrtolBase10(value);
                        if (resultValue != 0) {
                            gpState->mErrorNumber = resultValue;
                            profileValue = 0;
                        } else {
                            if (gpiValueForKey(data->mInputBuffer, "\\pid\\", value, 0x200) == FALSE) {
                                gpiSetError(connection, 1, "Error reading from the search server.");
                                gpiCallErrorCallback(connection, 3, 1);
                                return 3;
                            }
                            profileValue = StrtolBase10(value);
                        }
                        u5 = DWCi_GsMalloc(8);
                        if (u5 == NULL) {
                            gpiSetErrorString(connection, "Out of memory.");
                            return 1;
                        }
                        u5->mResult = resultValue;
                        u5->mProfile = profileValue;
                        result =
                            gpiAddCallback(connection, checkNickCallback, u5, operation, PROFILE_CALLBACK_TYPE_PLAIN);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_NEW_USER) {
                    newUserCallback = operation->mCallback;
                    if (newUserCallback.mCallback != NULL) {
                        result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "nur") != 0) {
                            gpiSetError(connection, 1, "Error reading from the search server.");
                            gpiCallErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        resultValue = StrtolBase10(value);
                        if (resultValue != 0) {
                            gpState->mErrorNumber = resultValue;
                        }
                        if (gpiValueForKey(data->mInputBuffer, "\\pid\\", value, 0x200) == FALSE) {
                            if (resultValue == 0) {
                                gpiSetError(connection, 1, "Error reading from the search server.");
                                gpiCallErrorCallback(connection, 3, 1);
                                return 3;
                            }
                            profileValue = 0;
                        } else {
                            profileValue = StrtolBase10(value);
                        }
                        u5 = DWCi_GsMalloc(8);
                        if (u5 == NULL) {
                            gpiSetErrorString(connection, "Out of memory.");
                            return 1;
                        }
                        u5->mResult = resultValue;
                        u5->mProfile = profileValue;
                        result =
                            gpiAddCallback(connection, newUserCallback, u5, operation, PROFILE_CALLBACK_TYPE_PLAIN);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_OTHERS) {
                    othersCallback = operation->mCallback;
                    if (othersCallback.mCallback != NULL) {
                        u7 = DWCi_GsMalloc(0xc);
                        if (u7 == NULL) {
                            gpiSetErrorString(connection, "Out of memory.");
                            return 1;
                        }
                        u7->mResult = GP_REQUEST_OK;
                        u7->mNumProfiles = 0;
                        u7->mProfiles = NULL;
                        result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "others") != 0) {
                            gpiSetError(connection, 1, "Error reading from the search server.");
                            gpiCallErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        isDone = FALSE;
                        do {
                            result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, "odone") == 0) {
                                isDone = TRUE;
                            } else if (strcmp(key, "o") == 0) {
                                profileMatches = DWCi_GsRealloc(u7->mProfiles, (u7->mNumProfiles + 1) * 0xac);
                                if (profileMatches == NULL) {
                                    gpiSetErrorString(connection, "Out of memory.");
                                    return 1;
                                }
                                u7->mProfiles = profileMatches;
                                profileMatches = u7->mProfiles;
                                entryIndex = u7->mNumProfiles;
                                profileMatch = &profileMatches[entryIndex];
                                memset(profileMatch, 0, sizeof(*profileMatch));
                                u7->mNumProfiles++;
                                profileMatches[entryIndex].mProfile = StrtolBase10(value);
                                matchDone = FALSE;
                                do {
                                    savedPos = readPos;
                                    result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                                    if (result != 0) {
                                        return result;
                                    }
                                    if (strcmp(key, "nick") == 0) {
                                        CopyStringWithTerminator(profileMatch->mNick, value, 0x1f);
                                    } else if (strcmp(key, "uniquenick") == 0) {
                                        CopyStringWithTerminator(profileMatch->mUniquenick, value, 0x15);
                                    } else if (strcmp(key, "first") == 0) {
                                        CopyStringWithTerminator(profileMatch->mFirstname, value, 0x1f);
                                    } else if (strcmp(key, "last") == 0) {
                                        CopyStringWithTerminator(profileMatch->mLastname, value, 0x1f);
                                    } else if (strcmp(key, "email") == 0) {
                                        CopyStringWithTerminator(profileMatch->mEmail, value, 0x33);
                                    } else if (strcmp(key, "o") == 0 || strcmp(key, "odone") == 0) {
                                        matchDone = TRUE;
                                        readPos = savedPos;
                                    }
                                } while (matchDone == FALSE);
                            } else {
                                gpiSetError(connection, 1, "Error reading from the search server.");
                                gpiCallErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (isDone == FALSE);
                        result = gpiAddCallback(connection, othersCallback, u7, operation,
                                                  PROFILE_CALLBACK_TYPE_FREE_OTHERS_PROFILES_IF_SET);
                        if (result != 0) {
                            return result;
                        }
                    }
                } else if (data->mKind == PROFILE_SEARCH_KIND_UNIQUE_NICK) {
                    uniqueNickCallback = operation->mCallback;
                    if (uniqueNickCallback.mCallback != NULL) {
                        entryIndex = 0;
                        u9 = DWCi_GsMalloc(0xc);
                        if (u9 == NULL) {
                            gpiSetErrorString(connection, "Out of memory.");
                            return 1;
                        }
                        u9->mResult = GP_REQUEST_OK;
                        u9->mNumSuggestedNicks = 0;
                        u9->mSuggestedNicks = NULL;
                        result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                        if (result != 0) {
                            return result;
                        }
                        if (strcmp(key, "us") != 0) {
                            gpiSetError(connection, 1, "Error reading from the search server.");
                            gpiCallErrorCallback(connection, 3, 1);
                            return 3;
                        }
                        u9->mNumSuggestedNicks = StrtolBase10(value);
                        u9->mSuggestedNicks = DWCi_GsMalloc(u9->mNumSuggestedNicks * 4);
                        if (u9->mSuggestedNicks == NULL) {
                            gpiSetErrorString(connection, "Out of memory.");
                            return 1;
                        }
                        isDone = FALSE;
                        do {
                            result = gpiReadKeyAndValue(connection, data->mInputBuffer, &readPos, key, value);
                            if (result != 0) {
                                return result;
                            }
                            if (strcmp(key, "nick") == 0) {
                                u9->mSuggestedNicks[entryIndex] = DWCi_GsMalloc(0x15);
                                if (u9->mSuggestedNicks[entryIndex] == NULL) {
                                    gpiSetErrorString(connection, "Out of memory.");
                                    return 1;
                                }
                                CopyStringWithTerminator(u9->mSuggestedNicks[entryIndex], value, 0x15);
                                entryIndex++;
                            } else if (strcmp(key, "usdone") == 0) {
                                if (entryIndex != u9->mNumSuggestedNicks) {
                                    AssertionFailed("count == arg->numSuggestedNicks", "gpiSearch.c", NULL, 0x515);
                                }
                                u9->mNumSuggestedNicks = entryIndex;
                                isDone = TRUE;
                            } else {
                                gpiSetError(connection, 1, "Error reading from the search server.");
                                gpiCallErrorCallback(connection, 3, 1);
                                return 3;
                            }
                        } while (isDone == FALSE);
                        result = gpiAddCallback(connection, uniqueNickCallback, u9, operation,
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

BOOL gpiProcessSearches(GpConnection *connection) {
    GpiConnection *gpState;
    GpiOperation **operations;
    GpiOperation *operation;
    GPISearchData *data;
    u32 result;
    s32 count;
    s32 index;

    gpState = connection->mGpiConnection;
    count = 0;
    if (gpState->mSearchCount > 0) {
        operations = DWCi_GsMalloc(gpState->mSearchCount * 4);
        if (operations == NULL) {
            gpiSetErrorString(connection, "Out of memory.");
            return TRUE;
        }
        for (operation = gpState->mOperationList; operation != NULL; operation = operation->mNext) {
            if (operation->mType == PROFILE_OPERATION_SEARCH && operation->mState != PROFILE_SEARCH_STATE_REPLY_READ &&
                operation->mData->mProcessing == 0) {
                if (count >= gpState->mSearchCount) {
                    AssertionFailed("num < iconnection->numSearches", "gpiSearch.c", NULL, 0x563);
                }
                operations[count++] = operation;
                operation->mData->mProcessing = 1;
            }
        }
        for (index = 0; index < count; index++) {
            result = gpiProcessSearch(connection, operations[index]);
            if (result != 0) {
                operations[index]->mResult = result;
            }
        }
        for (index = 0; index < count; index++) {
            data = operations[index]->mData;
            data->mProcessing = 0;
            if (data->mRemove != 0) {
                gpiRemoveOperation(connection, operations[index]);
            }
        }
        DWCi_GsFree(operations);
    }
    return FALSE;
}
