#include "00/Lib/GameSpy/peer_connection.h"
#include "00/Lib/DWC/matching_result_codes.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/login_connect_close.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/profile_search.h"

#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/profile_info_set.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "quick_sort.h"
#include "00/Lib/GameSpy/callback_queue.h"

s32 gpiProcessPeerInitiatingConnection(GPConnection *connection, GPIPeer *peer) {
    GPIConnection *gpState;
    GPIPeer *otherPeer;
    BOOL canFreeSig;
    s32 result;
    u32 state;
    s32 bytesRead;
    u32 connClosed;
    GPIProfile *profileEntry;
    char *input;
    char *end;

    gpState = connection->mGpiConnection;
    switch (peer->mState) {
        case PROFILE_PEER_STATE_WAIT_PROFILE_INFO:
            break;
        case PROFILE_PEER_STATE_START_CONNECT:
            result = gpiPeerStartConnect(connection, peer);
            if (result != 0) {
                return result;
            }
            break;
        case PROFILE_PEER_STATE_WAIT_CONNECT:
            result = gpiCheckSocketConnect(connection, peer->mSocket, &state);
            if (result != 0) {
                return result;
            }
            if (state == 4) {
                gpiSetErrorString(connection, "Error connecting to a peer.");
                return 3;
            } else if (state == 3) {
                canFreeSig = TRUE;
                if (gpiGetProfile(connection, peer->mProfileId, &profileEntry) == 0) {
                    gpiSetErrorString(connection, "Error connecting to a peer.");
                    return 3;
                }
                gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, "\\auth\\");
                gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, "\\pid\\");
                gpiAppendIntToBuffer(connection, &peer->mOutputBuffer, gpState->mProfileId);
                gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, "\\nick\\");
                gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, gpState->mNick);
                gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, "\\sig\\");
                gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, profileEntry->mPeerSig);
                gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, "\\final\\");
                for (otherPeer = gpState->mPeerList; otherPeer != NULL; otherPeer = otherPeer->mNext) {
                    if (otherPeer->mProfileId == peer->mProfileId && otherPeer != peer &&
                        otherPeer->mState <= PROFILE_PEER_STATE_WAIT_CONNECT) {
                        canFreeSig = FALSE;
                    }
                }
                if (canFreeSig != FALSE) {
                    DWCi_GsFree(profileEntry->mPeerSig);
                    profileEntry->mPeerSig = NULL;
                    if (gpiCanFreeProfile(profileEntry) != 0) {
                        gpiRemoveProfile(connection, profileEntry);
                    }
                }
                peer->mState = PROFILE_PEER_STATE_WAIT_AUTH;
            }
            break;
        case PROFILE_PEER_STATE_WAIT_AUTH:
            result = gpiRecvToBuffer(connection, peer->mSocket, (GPIBuffer *) &peer->mInputBuffer, &bytesRead, &connClosed,
                                      (const s8 *) "PR");
            if (result != 0) {
                return result;
            }
            end = strstr(peer->mInputBuffer, "\\final\\");
            if (end == NULL) {
                break;
            }
            *end = 0;
            input = peer->mInputBuffer;
            if (strncmp(input, "\\anack\\", 7) == 0) {
                peer->mNackCount = peer->mNackCount + 1;
                if (peer->mNackCount > 1) {
                    gpiSetErrorString(connection, "Error getting buddy authorization.");
                    return 3;
                }
                result = gpiPeerGetSig(connection, peer);
                if (result != 0) {
                    return result;
                }
            } else if (strncmp(input, "\\aack\\", 6) != 0) {
                gpiSetErrorString(connection, "Error parsing buddy message.");
                return 3;
            }
            peer->mState = PROFILE_PEER_STATE_CONNECTED;
            peer->mInputBufferLength = FALSE;
            break;
        default:
            AssertionFailed("0", "gpiPeer.c", NULL, 0x9f);
            break;
    }
    if (peer->mOutputBuffer.mLength > 0) {
        result = gpiSendFromBuffer(connection, peer->mSocket, &peer->mOutputBuffer, &connClosed, 1, (const s8 *) "PR");
        if (connClosed != 0 || result != 0) {
            peer->mState = PROFILE_PEER_STATE_CLOSED;
        }
    }
    return 0;
}

s32 gpiProcessPeerAcceptingConnection(GPConnection *connection, GPIPeer *peer) {
    GPIConnection *gpState;
    s32 len;
    u32 connClosed;
    s32 result;
    s32 pid;
    char *end;
    char *input;
    char intText[0x10];
    char nickText[0x1f];
    char sig[0x21];
    char sigDigest[0x21];
    char buffer[0x103];

    gpState = connection->mGpiConnection;
    if (peer->mState != PROFILE_PEER_STATE_WAIT_AUTH) {
        AssertionFailed("peer->state == GPI_PEER_WAITING", "gpiPeer.c", NULL, 0xc1);
    }
    result = gpiRecvToBuffer(connection, peer->mSocket, (GPIBuffer *) &peer->mInputBuffer, &len, &connClosed,
                              (const s8 *) "PR");
    if (result != 0) {
        return result;
    }
    if (connClosed != 0) {
        peer->mState = PROFILE_PEER_STATE_CLOSED;
        return 0;
    }
    end = strstr(peer->mInputBuffer, "\\final\\");
    if (end != NULL) {
        *end = 0;
        input = peer->mInputBuffer;
        if (strncmp(input, "\\auth\\", 6) == 0) {
            if (gpiValueForKey(input, "\\pid\\", intText, 0x10) == FALSE) {
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            pid = StrtolBase10(intText);
            if (gpiValueForKey(peer->mInputBuffer, "\\nick\\", nickText, 0x1f) == FALSE) {
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            if (gpiValueForKey(peer->mInputBuffer, "\\sig\\", sig, 0x21) == FALSE) {
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            sprintf(buffer, "%s%d%d", gpState->mPassword, gpState->mProfileId, pid);
            MD5Digest(buffer, strlen(buffer), sigDigest);
            if (strcmp(sig, sigDigest) != 0) {
                gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, "\\anack\\");
                gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, "\\final\\");
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, "\\aack\\");
            gpiAppendStringToBuffer(connection, &peer->mOutputBuffer, "\\final\\");
            peer->mState = PROFILE_PEER_STATE_CONNECTED;
            peer->mProfileId = pid;
        } else {
            peer->mState = PROFILE_PEER_STATE_CLOSED;
            return 0;
        }
        peer->mInputBufferLength = FALSE;
    }
    return 0;
}

s32 gpiPeerSendMessages(GPConnection *connection, GPIPeer *peer) {
    GPIMessage *message;
    u32 connClosed;
    s32 result;

    if (peer->mOutputBuffer.mLength != 0) {
        return 0;
    }
    if (ArrayLength(peer->mQueuedMessages) != 0) {
        do {
            message = ArrayNth(peer->mQueuedMessages, 0);
            result = gpiSendFromBuffer(connection, peer->mSocket, &message->mBuffer, &connClosed, 0, (const s8 *) "PR");
            if (connClosed != 0 || result != 0) {
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            if (message->mBuffer.mPos != message->mBuffer.mLength) {
                break;
            }
            ArrayDeleteAt(peer->mQueuedMessages, 0);
        } while (ArrayLength(peer->mQueuedMessages) != 0);
    }
    return 0;
}

s32 gpiProcessPeerConnected(GPConnection *connection, GPIPeer *peerConn) {
    GPIConnection *gpState;
    BuddyMessageData *arg;
    s32 bytesRead;
    u32 connClosed;
    GPICallback callback;
    s32 message;
    s32 type;
    s32 msgBytes;
    s32 result;

    gpState = connection->mGpiConnection;
    if (peerConn->mOutputBuffer.mLength != 0) {
        result =
            gpiSendFromBuffer(connection, peerConn->mSocket, &peerConn->mOutputBuffer, &connClosed, 1, (const s8 *) "PR");
        if (connClosed != 0 || result != 0) {
            peerConn->mState = PROFILE_PEER_STATE_CLOSED;
            return 0;
        }
    }
    if (peerConn->mOutputBuffer.mLength == 0) {
        result = gpiPeerSendMessages(connection, peerConn);
        if (result != 0) {
            return result;
        }
        if (peerConn->mState == PROFILE_PEER_STATE_CLOSED) {
            return 0;
        }
    }
    result = gpiRecvToBuffer(connection, peerConn->mSocket, (GPIBuffer *) &peerConn->mInputBuffer, &bytesRead, &connClosed,
                              (const s8 *) "PR");
    if (result != 0) {
        peerConn->mState = PROFILE_PEER_STATE_CLOSED;
        return 0;
    }
    if (bytesRead > 0) {
        peerConn->mTimeout = GetTickSeconds(NULL) + 0x12c;
    }
    do {
        result = gpiReadMessageFromBuffer(connection, (GPIBuffer *) &peerConn->mInputBuffer, &message, &type, &msgBytes);
        if (result != 0) {
            return result;
        }
        if (message != 0) {
            switch (type) {
                case BUDDY_MESSAGE_TYPE_MESSAGE:
                    callback = gpState->mCallbacks[3];
                    if (callback.mCallback != NULL) {
                        arg = DWCi_GsMalloc(0xc);
                        if (arg == NULL) {
                            gpiSetErrorString(connection, "Out of memory.");
                            return PROFILE_RESULT_OUT_OF_MEMORY;
                        }
                        arg->mProfile = peerConn->mProfileId;
                        arg->mUnk_08 = goastrdup((const char *) message);
                        arg->mDate = GetTickSeconds(NULL);
                        result =
                            gpiAddCallback(connection, callback, arg, NULL, PROFILE_CALLBACK_TYPE_FREE_MESSAGE_TEXT);
                        if (result != 0) {
                            return result;
                        }
                    }
                    break;
                case BUDDY_MESSAGE_TYPE_PING:
                    gpiSendBuddyMessage(connection, peerConn->mProfileId, BUDDY_MESSAGE_TYPE_PONG, "1");
                    break;
                // file transfer messages
                case 200:
                case BUDDY_MESSAGE_TYPE_TRANSFER_REPLY:
                case 202:
                case 203:
                case 204:
                case 205:
                case 206:
                case 207:
                case 208:
                    gpiHandleTransferMessage(connection, peerConn, type, peerConn->mInputBuffer, message, msgBytes);
                    break;
            }
            gpiClipBufferToPosition(connection, (GPIBuffer *) &peerConn->mInputBuffer);
        }
    } while (message != 0);
    if (connClosed != 0) {
        peerConn->mState = PROFILE_PEER_STATE_CLOSED;
    }
    return 0;
}

s32 gpiProcessPeer(GPConnection *connection, GPIPeer *peer) {
    s32 result = 0;

    if (peer->mState == PROFILE_PEER_STATE_NOT_CONNECTED) {
        AssertionFailed("peer->state != GPI_PEER_NOT_CONNECTED", "gpiPeer.c", NULL, 0x1d9);
    }
    if (peer->mState != PROFILE_PEER_STATE_CONNECTED) {
        if (peer->mInitiated != 0) {
            result = gpiProcessPeerInitiatingConnection(connection, peer);
        } else {
            result = gpiProcessPeerAcceptingConnection(connection, peer);
        }
    }
    if (result == 0 && peer->mState == PROFILE_PEER_STATE_CONNECTED) {
        result = gpiProcessPeerConnected(connection, peer);
    }
    return result;
}

void gpiDestroyPeer(GPConnection *connection, GPIPeer *peer) {
    shutdown(peer->mSocket, 2);
    closesocket(peer->mSocket);
    DWCi_GsFree(peer->mInputBuffer);
    peer->mInputBuffer = NULL;
    DWCi_GsFree(peer->mOutputBuffer.mBuffer);
    peer->mOutputBuffer.mBuffer = NULL;
    if (peer->mQueuedMessages != NULL) {
        ArrayFree(peer->mQueuedMessages);
        peer->mQueuedMessages = NULL;
    }
    DWCi_GsFree(peer);
}

void gpiRemovePeer(GPConnection *connection, GPIPeer *peer) {
    GPIConnection *gpState = connection->mGpiConnection;
    GPIPeer *previous;
    GPIPeer *current;
    GPIMessage *message;
    s32 unusedLocal;

    if (peer == NULL) {
        AssertionFailed("peer != NULL", "gpiPeer.c", NULL, 0x213);
    }
    previous = gpState->mPeerList;
    if (previous == peer) {
        gpState->mPeerList = peer->mNext;
    } else {
        current = previous->mNext;
        while (current != peer) {
            if (current == NULL) {
                AssertionFailed("0", "gpiPeer.c", NULL, 0x225);
                gpiDebug(connection, "Tried to remove peer not in list.");
                return;
            }
            previous = current;
            current = current->mNext;
        }
        previous->mNext = peer->mNext;
    }
    if (ArrayLength(peer->mQueuedMessages) != 0) {
        do {
            message = ArrayNth(peer->mQueuedMessages, 0);
            if (message->mType < BUDDY_MESSAGE_TYPE_STATUS) {
                gpiSendServerBuddyMessage(connection, peer->mProfileId, message->mType,
                                          (const char *) message->mBuffer.mBuffer + message->mStart);
            }
            ArrayDeleteAt(peer->mQueuedMessages, 0);
        } while (ArrayLength(peer->mQueuedMessages) != 0);
    }
    gpiDestroyPeer(connection, peer);
}

void gpiSetPeerSocketSizes(s32 sock) {
    SetReceiveBufferSize(sock, 0x4000);
    SetReceiveBufferSize(sock, 0x8000);
    SetReceiveBufferSize(sock, 0x10000);
    SetReceiveBufferSize(sock, 0x20000);
    SetReceiveBufferSize(sock, 0x40000);
    SetSendBufferSize(sock, 0x4000);
    SetSendBufferSize(sock, 0x8000);
    SetSendBufferSize(sock, 0x10000);
    GetReceiveBufferSize(sock);
    GetSendBufferSize(sock);
}

s32 gpiProcessPeers(GPConnection *connection) {
    GPIConnection *gpState = connection->mGpiConnection;
    GPIPeer *peerConn;
    GPIPeer *followingPeer;
    s32 value;

    if (gpState->mListenSocket != -1 && CanReceiveOnSocket(gpState->mListenSocket) != 0) {
        value = AcceptConnection(gpState->mListenSocket, NULL, NULL);
        if (value != -1) {
            peerConn = gpiAddPeer(connection, -1, 0);
            if (peerConn != NULL) {
                peerConn->mState = PROFILE_PEER_STATE_WAIT_AUTH;
                peerConn->mSocket = value;
                SetSockBlocking(value, 0);
                gpiSetPeerSocketSizes(peerConn->mSocket);
            } else {
                closesocket(value);
            }
        }
    }
    peerConn = gpState->mPeerList;
    while (peerConn != NULL) {
        followingPeer = peerConn->mNext;
        value = gpiProcessPeer(connection, peerConn);
        if (peerConn->mState == PROFILE_PEER_STATE_CLOSED || value != 0 ||
            (s32) GetTickSeconds(NULL) > peerConn->mTimeout) {
            gpiRemovePeer(connection, peerConn);
        }
        peerConn = followingPeer;
    }
    return 0;
}

GPIPeer *gpiGetConnectedPeer(GPConnection *connection, u32 profileid) {
    GPIPeer *node = connection->mGpiConnection->mPeerList;
    while (node != NULL) {
        if (node->mProfileId == profileid && node->mState == PROFILE_PEER_STATE_CONNECTED) {
            return node;
        }
        node = node->mNext;
    }
    return NULL;
}

void gpiFreeMessage(void **bufferPointer) {
    DWCi_GsFree(*bufferPointer);
    *bufferPointer = NULL;
}

GPIPeer *gpiAddPeer(GPConnection *connection, u32 profileid, u32 initiate) {
    GPIConnection *gpState = connection->mGpiConnection;
    GPIPeer *peerConn = DWCi_GsMalloc(0x40);

    if (peerConn == NULL) {
        return NULL;
    }
    memset(peerConn, 0, sizeof(*peerConn));
    peerConn->mState = PROFILE_PEER_STATE_NOT_CONNECTED;
    peerConn->mInitiated = initiate;
    peerConn->mSocket = -1;
    peerConn->mProfileId = profileid;
    peerConn->mTimeout = GetTickSeconds(NULL) + 0x12c;
    peerConn->mNext = gpState->mPeerList;
    peerConn->mQueuedMessages = ArrayNew(0x18, 0, (void (*)(void *)) gpiFreeMessage);
    gpState->mPeerList = peerConn;
    return peerConn;
}

int gpiPeerGetSig(GPConnection *connection, GPIPeer *peer) {
    int result;
    GPIOperation *pendingOp;
    result = gpiAddOperation(connection, PROFILE_OPERATION_INFO, NULL, &pendingOp, 0, NULL, 0);
    if ((result == 0) &&
        (result = gpiSendGetInfo(connection, peer->mProfileId, pendingOp->mId), result == 0)) {
        peer->mState = PROFILE_PEER_STATE_WAIT_PROFILE_INFO;
        result = 0;
    }
    return result;
}

s32 gpiPeerStartConnect(GPConnection *connection, GPIPeer *peer) {
    SOCSockAddrIn address;
    GPIProfile *profileRec;
    s32 connectResult;
    u32 *addressWords;

    if (gpiGetProfile(connection, peer->mProfileId, &profileRec) == 0) {
        gpiSetErrorString(connection, "Error connecting to a peer.");
        return 3;
    }
    peer->mSocket = OpenNetSocket(2, 1, 0);
    if (peer->mSocket == -1) {
        gpiSetError(connection, 5, "There was an error creating a socket.");
        gpiCallErrorCallback(connection, PROFILE_RESULT_NETWORK_ERROR, 0);
        return PROFILE_RESULT_NETWORK_ERROR;
    }
    if (SetSockBlocking(peer->mSocket, 0) == FALSE) {
        gpiSetError(connection, 5, "There was an error making a socket non-blocking.");
        gpiCallErrorCallback(connection, PROFILE_RESULT_NETWORK_ERROR, 0);
        return PROFILE_RESULT_NETWORK_ERROR;
    }
    gpiSetPeerSocketSizes(peer->mSocket);
    addressWords = (u32 *) &address;
    addressWords[0] = 0;
    addressWords[1] = 0;
    address.mFamily = SOCKET_FAMILY_IPV4;
    address.mAddr = profileRec->mBuddyStatus->mIp;
    address.mPort = profileRec->mBuddyStatus->mPort;
    connectResult = connect(peer->mSocket, &address, 8);
    if (connectResult == -1) {
        connectResult = GOAGetLastError(peer->mSocket);
        if (connectResult != -6 && connectResult != -0x1a && connectResult != -0x4c) {
            gpiSetError(connection, 5, "There was an error connecting a socket.");
            gpiCallErrorCallback(connection, PROFILE_RESULT_NETWORK_ERROR, 1);
            return PROFILE_RESULT_NETWORK_ERROR;
        }
    }
    peer->mState = PROFILE_PEER_STATE_WAIT_CONNECT;
    return 0;
}

s32 gpiPeerAddMessage(GPConnection *connection, GPIPeer *peer, u32 type, const char *message) {
    u32 len;
    s32 result;

    if (peer == NULL) {
        AssertionFailed("peer != NULL", "gpiPeer.c", NULL, 0x340);
    }
    if (message == NULL) {
        AssertionFailed("message != NULL", "gpiPeer.c", NULL, 0x341);
    }
    len = strlen(message);
    {
        GPIMessage queuedMsg = {0};
        queuedMsg.mType = type;
        result = gpiAppendStringToBuffer(connection, &queuedMsg, "\\m\\");
        if (result != 0) {
            return result;
        }
        result = gpiAppendIntToBuffer(connection, &queuedMsg, type);
        if (result != 0) {
            return result;
        }
        result = gpiAppendStringToBuffer(connection, &queuedMsg, "\\len\\");
        if (result != 0) {
            return result;
        }
        result = gpiAppendIntToBuffer(connection, &queuedMsg, len);
        if (result != 0) {
            return result;
        }
        result = gpiAppendStringToBuffer(connection, &queuedMsg, "\\msg\\\n");
        if (result != 0) {
            return result;
        }
        queuedMsg.mStart = queuedMsg.mBuffer.mLength;
        result = gpiAppendStringToBufferLen(connection, &queuedMsg.mBuffer, message, len);
        if (result != 0) {
            return result;
        }
        result = gpiAppendCharToBuffer(connection, &queuedMsg.mBuffer, 0);
        if (result != 0) {
            return result;
        }
        ArrayAppend(peer->mQueuedMessages, &queuedMsg);
        peer->mTimeout = GetTickSeconds(NULL) + 0x12c;
        return 0;
    }
}

u32 gpiPeerStartTransferMessage(GPConnection *connection, GPIPeer *peer, u32 type, GPITransferID *transferID) {
    char buffer[0x44];
    u32 count = transferID->mCount;
    u32 profileid = transferID->mProfileId;
    u32 time = transferID->mTime;

    if (transferID == NULL) {
        AssertionFailed("transferID", "gpiPeer.c", NULL, 0x376);
    }
    sprintf(buffer, "\\m\\%d\\xfer\\%d %u %u", type, profileid, count, time);
    return gpiSendOrBufferString(connection, peer, buffer);
}

s32 gpiPeerFinishTransferMessage(GPConnection *connection, GPIPeer *peer, const char *message, s32 len) {
    char buffer[0x24];
    s32 result;

    if (peer == NULL) {
        AssertionFailed("peer != NULL", "gpiPeer.c", NULL, 0x389);
    }
    if (message == NULL) {
        message = "";
    }
    if (len == -1) {
        len = strlen(message);
    }
    sprintf(buffer, "\\len\\%d\\msg\\\n", len);
    result = gpiSendOrBufferString(connection, peer, buffer);
    if (result != 0) {
        return result;
    }
    result = gpiSendOrBufferStringLen(connection, peer, message, len);
    if (result != 0) {
        return result;
    }
    result = gpiSendOrBufferChar(connection, peer, 0);
    if (result != 0) {
        return result;
    }
    peer->mTimeout = GetTickSeconds(NULL) + 0x12c;
    return 0;
}
