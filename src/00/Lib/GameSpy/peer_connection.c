#include "00/Lib/GameSpy/peer_connection.h"
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

s32 gpiProcessPeerInitiatingConnection(GpConnection *connection, GpiPeer *peer) {
    GpiConnection *gpState;
    GpiPeer *otherPeer;
    BOOL canFreeSig;
    s32 result;
    u32 state;
    s32 len;
    u32 socketGone;
    GpiProfile *profileEntry;
    char *input;
    char *end;

    gpState = connection->mGpiConnection;
    switch (peer->mState) {
        case PROFILE_PEER_STATE_WAIT_PROFILE_INFO:
            break;
        case PROFILE_PEER_STATE_START_CONNECT:
            result = GpiPeerConnect(connection, peer);
            if (result != 0) {
                return result;
            }
            break;
        case PROFILE_PEER_STATE_WAIT_CONNECT:
            result = GpiCheckConnectComplete(connection, peer->mSocket, &state);
            if (result != 0) {
                return result;
            }
            if (state == 4) {
                GpiSetErrorMessage(connection, "Error connecting to a peer.");
                return 3;
            } else if (state == 3) {
                canFreeSig = TRUE;
                if (GpiFindProfile(connection, peer->mProfileId, &profileEntry) == 0) {
                    GpiSetErrorMessage(connection, "Error connecting to a peer.");
                    return 3;
                }
                GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\auth\\");
                GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\pid\\");
                GpiAppendBufferNumber(connection, &peer->mOutputBuffer, gpState->mProfileId);
                GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\nick\\");
                GpiAppendBufferString(connection, &peer->mOutputBuffer, gpState->mNick);
                GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\sig\\");
                GpiAppendBufferString(connection, &peer->mOutputBuffer, profileEntry->mPeerSig);
                GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\final\\");
                for (otherPeer = gpState->mPeerList; otherPeer != NULL; otherPeer = otherPeer->mNext) {
                    if (otherPeer->mProfileId == peer->mProfileId && otherPeer != peer &&
                        otherPeer->mState <= PROFILE_PEER_STATE_WAIT_CONNECT) {
                        canFreeSig = FALSE;
                    }
                }
                if (canFreeSig != FALSE) {
                    DWCi_GsFree(profileEntry->mPeerSig);
                    profileEntry->mPeerSig = NULL;
                    if (GpiIsProfileEmpty(profileEntry) != 0) {
                        GpiRemoveProfile(connection, profileEntry);
                    }
                }
                peer->mState = PROFILE_PEER_STATE_WAIT_AUTH;
            }
            break;
        case PROFILE_PEER_STATE_WAIT_AUTH:
            result = GpiReceiveBuffer(connection, peer->mSocket, (GpiBuffer *) &peer->mInputBuffer, &len, &socketGone,
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
                    GpiSetErrorMessage(connection, "Error getting buddy authorization.");
                    return 3;
                }
                result = gpiPeerGetSig(connection, peer);
                if (result != 0) {
                    return result;
                }
            } else if (strncmp(input, "\\aack\\", 6) != 0) {
                GpiSetErrorMessage(connection, "Error parsing buddy message.");
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
        result = GpiSendBuffer(connection, peer->mSocket, &peer->mOutputBuffer, &socketGone, 1, (const s8 *) "PR");
        if (socketGone != 0 || result != 0) {
            peer->mState = PROFILE_PEER_STATE_CLOSED;
        }
    }
    return 0;
}

s32 GpiPeerUpdateWaiting(GpConnection *connection, GpiPeer *peer) {
    GpiConnection *gpState;
    s32 len;
    u32 socketGone;
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
    result = GpiReceiveBuffer(connection, peer->mSocket, (GpiBuffer *) &peer->mInputBuffer, &len, &socketGone,
                              (const s8 *) "PR");
    if (result != 0) {
        return result;
    }
    if (socketGone != 0) {
        peer->mState = PROFILE_PEER_STATE_CLOSED;
        return 0;
    }
    end = strstr(peer->mInputBuffer, "\\final\\");
    if (end != NULL) {
        *end = 0;
        input = peer->mInputBuffer;
        if (strncmp(input, "\\auth\\", 6) == 0) {
            if (GpiGetValue(input, "\\pid\\", intText, 0x10) == FALSE) {
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            pid = StrtolBase10(intText);
            if (GpiGetValue(peer->mInputBuffer, "\\nick\\", nickText, 0x1f) == FALSE) {
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            if (GpiGetValue(peer->mInputBuffer, "\\sig\\", sig, 0x21) == FALSE) {
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            sprintf(buffer, "%s%d%d", gpState->mPassword, gpState->mProfileId, pid);
            MD5Digest(buffer, strlen(buffer), sigDigest);
            if (strcmp(sig, sigDigest) != 0) {
                GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\anack\\");
                GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\final\\");
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\aack\\");
            GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\final\\");
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

s32 gpiPeerSendMessages(GpConnection *connection, GpiPeer *peer) {
    GPIMessage *message;
    u32 socketGone;
    s32 result;

    if (peer->mOutputBuffer.mLength != 0) {
        return 0;
    }
    if (DarrayGetCount(peer->mQueuedMessages) != 0) {
        do {
            message = DarrayGetElement(peer->mQueuedMessages, 0);
            result = GpiSendBuffer(connection, peer->mSocket, &message->mBuffer, &socketGone, 0, (const s8 *) "PR");
            if (socketGone != 0 || result != 0) {
                peer->mState = PROFILE_PEER_STATE_CLOSED;
                return 0;
            }
            if (message->mBuffer.mPos != message->mBuffer.mLength) {
                break;
            }
            DarrayRemove(peer->mQueuedMessages, 0);
        } while (DarrayGetCount(peer->mQueuedMessages) != 0);
    }
    return 0;
}

s32 gpiProcessPeerConnected(GpConnection *connection, GpiPeer *peerConn) {
    GpiConnection *gpState;
    BuddyMessageData *arg;
    s32 len;
    u32 socketGone;
    GpiCallback callback;
    s32 buffer;
    s32 type;
    s32 msgBytes;
    s32 result;

    gpState = connection->mGpiConnection;
    if (peerConn->mOutputBuffer.mLength != 0) {
        result =
            GpiSendBuffer(connection, peerConn->mSocket, &peerConn->mOutputBuffer, &socketGone, 1, (const s8 *) "PR");
        if (socketGone != 0 || result != 0) {
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
    result = GpiReceiveBuffer(connection, peerConn->mSocket, (GpiBuffer *) &peerConn->mInputBuffer, &len, &socketGone,
                              (const s8 *) "PR");
    if (result != 0) {
        peerConn->mState = PROFILE_PEER_STATE_CLOSED;
        return 0;
    }
    if (len > 0) {
        peerConn->mTimeout = GetUnixTime(NULL) + 0x12c;
    }
    do {
        result = gpiReadMessageFromBuffer(connection, (GpiBuffer *) &peerConn->mInputBuffer, &buffer, &type, &msgBytes);
        if (result != 0) {
            return result;
        }
        if (buffer != 0) {
            switch (type) {
                case GPI_BM_MESSAGE:
                    callback = gpState->mCallbacks[3];
                    if (callback.mCallback != NULL) {
                        arg = DWCi_GsMalloc(0xc);
                        if (arg == NULL) {
                            GpiSetErrorMessage(connection, "Out of memory.");
                            return 1;
                        }
                        arg->mProfile = peerConn->mProfileId;
                        arg->mUnk_08 = goastrdup((const char *) buffer);
                        arg->mDate = GetUnixTime(NULL);
                        result =
                            GpiQueueCallback(connection, callback, arg, NULL, PROFILE_CALLBACK_TYPE_FREE_MESSAGE_TEXT);
                        if (result != 0) {
                            return result;
                        }
                    }
                    break;
                case PROFILE_PEER_STATE_START_CONNECT:
                    gpiSendBuddyMessage(connection, peerConn->mProfileId, GPI_BM_PONG, "1");
                    break;
                case GPI_BM_FILE_SEND_REQUEST:
                case GPI_BM_FILE_SEND_REPLY:
                case GPI_BM_FILE_BEGIN:
                case GPI_BM_FILE_END:
                case GPI_BM_FILE_DATA:
                case GPI_BM_FILE_SKIP:
                case GPI_BM_FILE_TRANSFER_THROTTLE:
                case GPI_BM_FILE_TRANSFER_CANCEL:
                case GPI_BM_FILE_TRANSFER_KEEPALIVE:
                    gpiHandleTransferMessage(connection, peerConn, type, peerConn->mInputBuffer, buffer, msgBytes);
                    break;
            }
            gpiClipBufferToPosition(connection, (GpiBuffer *) &peerConn->mInputBuffer);
        }
    } while (buffer != 0);
    if (socketGone != 0) {
        peerConn->mState = PROFILE_PEER_STATE_CLOSED;
    }
    return 0;
}

s32 GpiPeerUpdate(GpConnection *connection, GpiPeer *peer) {
    s32 result = 0;

    if (peer->mState == PROFILE_PEER_STATE_NOT_CONNECTED) {
        AssertionFailed("peer->state != GPI_PEER_NOT_CONNECTED", "gpiPeer.c", NULL, 0x1d9);
    }
    if (peer->mState != PROFILE_PEER_STATE_CONNECTED) {
        if (peer->mInitiated != 0) {
            result = gpiProcessPeerInitiatingConnection(connection, peer);
        } else {
            result = GpiPeerUpdateWaiting(connection, peer);
        }
    }
    if (result == 0 && peer->mState == PROFILE_PEER_STATE_CONNECTED) {
        result = gpiProcessPeerConnected(connection, peer);
    }
    return result;
}

void GpiPeerDelete(GpConnection *connection, GpiPeer *peer) {
    shutdown(peer->mSocket, 2);
    closesocket(peer->mSocket);
    DWCi_GsFree(peer->mInputBuffer);
    peer->mInputBuffer = NULL;
    DWCi_GsFree(peer->mOutputBuffer.mBuffer);
    peer->mOutputBuffer.mBuffer = NULL;
    if (peer->mQueuedMessages != NULL) {
        DarrayDelete(peer->mQueuedMessages);
        peer->mQueuedMessages = NULL;
    }
    DWCi_GsFree(peer);
}

void GpiPeerRemoveAndWriteQueuedMessages(GpConnection *connection, GpiPeer *peer) {
    GpiConnection *gpState = connection->mGpiConnection;
    GpiPeer *previous;
    GpiPeer *current;
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
    if (DarrayGetCount(peer->mQueuedMessages) != 0) {
        do {
            message = DarrayGetElement(peer->mQueuedMessages, 0);
            if (message->mType < GPI_BM_STATUS) {
                gpiSendServerBuddyMessage(connection, peer->mProfileId, message->mType,
                                          (const char *) message->mBuffer.mBuffer + message->mStart);
            }
            DarrayRemove(peer->mQueuedMessages, 0);
        } while (DarrayGetCount(peer->mQueuedMessages) != 0);
    }
    GpiPeerDelete(connection, peer);
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

s32 GpiUpdatePeers(GpConnection *connection) {
    GpiConnection *gpState = connection->mGpiConnection;
    GpiPeer *peerConn;
    GpiPeer *followingPeer;
    s32 value;

    if (gpState->mListenSocket != -1 && CanReceiveOnSocket(gpState->mListenSocket) != 0) {
        value = AcceptConnection(gpState->mListenSocket, NULL, NULL);
        if (value != -1) {
            peerConn = GpiPeerCreate(connection, -1, 0);
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
        value = GpiPeerUpdate(connection, peerConn);
        if (peerConn->mState == PROFILE_PEER_STATE_CLOSED || value != 0 ||
            (s32) GetUnixTime(NULL) > peerConn->mTimeout) {
            GpiPeerRemoveAndWriteQueuedMessages(connection, peerConn);
        }
        peerConn = followingPeer;
    }
    return 0;
}

GpiPeer *gpiGetConnectedPeer(GpConnection *object, u32 key) {
    GpiPeer *node = object->mGpiConnection->mPeerList;
    while (node != NULL) {
        if (node->mProfileId == key && node->mState == PROFILE_PEER_STATE_CONNECTED) {
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

GpiPeer *GpiPeerCreate(GpConnection *connection, u32 profileid, u32 initiate) {
    GpiConnection *gpState = connection->mGpiConnection;
    GpiPeer *peerConn = DWCi_GsMalloc(0x40);

    if (peerConn == NULL) {
        return NULL;
    }
    memset(peerConn, 0, sizeof(*peerConn));
    peerConn->mState = PROFILE_PEER_STATE_NOT_CONNECTED;
    peerConn->mInitiated = initiate;
    peerConn->mSocket = -1;
    peerConn->mProfileId = profileid;
    peerConn->mTimeout = GetUnixTime(NULL) + 0x12c;
    peerConn->mNext = gpState->mPeerList;
    peerConn->mQueuedMessages = DarrayCreate(0x18, 0, (void (*)(void *)) gpiFreeMessage);
    gpState->mPeerList = peerConn;
    return peerConn;
}

int gpiPeerGetSig(GpConnection *connection, GpiPeer *peer) {
    int result;
    GpiOperation *pendingOp;
    result = GpiCreateOperation(connection, PROFILE_OPERATION_INFO, NULL, &pendingOp, 0, NULL, 0);
    if ((result == 0) &&
        (result = gpiSendGetInfo(connection, peer->mProfileId, pendingOp->mId), result == 0)) {
        peer->mState = PROFILE_PEER_STATE_WAIT_PROFILE_INFO;
        result = 0;
    }
    return result;
}

s32 GpiPeerConnect(GpConnection *connection, GpiPeer *peer) {
    SOCSockAddrIn address;
    GpiProfile *profileRec;
    s32 openResult;
    u32 *addressWords;

    if (GpiFindProfile(connection, peer->mProfileId, &profileRec) == 0) {
        GpiSetErrorMessage(connection, "Error connecting to a peer.");
        return 3;
    }
    peer->mSocket = OpenNetSocket(2, 1, 0);
    if (peer->mSocket == -1) {
        GpiSetError(connection, 5, "There was an error creating a socket.");
        GpiQueueErrorCallback(connection, 3, 0);
        return 3;
    }
    if (SetSockBlocking(peer->mSocket, 0) == FALSE) {
        GpiSetError(connection, 5, "There was an error making a socket non-blocking.");
        GpiQueueErrorCallback(connection, 3, 0);
        return 3;
    }
    gpiSetPeerSocketSizes(peer->mSocket);
    addressWords = (u32 *) &address;
    addressWords[0] = 0;
    addressWords[1] = 0;
    address.mFamily = SOCKET_FAMILY_IPV4;
    address.mAddr = profileRec->mBuddyStatus->mIp;
    address.mPort = profileRec->mBuddyStatus->mPort;
    openResult = connect(peer->mSocket, &address, 8);
    if (openResult == -1) {
        openResult = GOAGetLastError(peer->mSocket);
        if (openResult != -6 && openResult != -0x1a && openResult != -0x4c) {
            GpiSetError(connection, 5, "There was an error connecting a socket.");
            GpiQueueErrorCallback(connection, 3, 1);
            return 3;
        }
    }
    peer->mState = PROFILE_PEER_STATE_WAIT_CONNECT;
    return 0;
}

s32 GpiPeerQueueMessage(GpConnection *connection, GpiPeer *peer, u32 type, const char *message) {
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
        result = GpiAppendBufferString(connection, &queuedMsg, "\\m\\");
        if (result != 0) {
            return result;
        }
        result = GpiAppendBufferNumber(connection, &queuedMsg, type);
        if (result != 0) {
            return result;
        }
        result = GpiAppendBufferString(connection, &queuedMsg, "\\len\\");
        if (result != 0) {
            return result;
        }
        result = GpiAppendBufferNumber(connection, &queuedMsg, len);
        if (result != 0) {
            return result;
        }
        result = GpiAppendBufferString(connection, &queuedMsg, "\\msg\\\n");
        if (result != 0) {
            return result;
        }
        queuedMsg.mStart = queuedMsg.mBuffer.mLength;
        result = GpiAppendBufferBytes(connection, &queuedMsg.mBuffer, message, len);
        if (result != 0) {
            return result;
        }
        result = GpiAppendBufferByte(connection, &queuedMsg.mBuffer, 0);
        if (result != 0) {
            return result;
        }
        DarrayAppend(peer->mQueuedMessages, &queuedMsg);
        peer->mTimeout = GetUnixTime(NULL) + 0x12c;
        return 0;
    }
}

u32 GpiPeerSendXfer(GpConnection *connection, GpiPeer *peer, u32 type, GpiTransferId *transferID) {
    char buffer[0x44];
    u32 count = transferID->mCount;
    u32 profileid = transferID->mProfileId;
    u32 time = transferID->mTime;

    if (transferID == NULL) {
        AssertionFailed("transferID", "gpiPeer.c", NULL, 0x376);
    }
    sprintf(buffer, "\\m\\%d\\xfer\\%d %u %u", type, profileid, count, time);
    return GpiPeerSendString(connection, peer, buffer);
}

s32 GpiPeerSendLenMsg(GpConnection *connection, GpiPeer *peer, const char *message, s32 len) {
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
    result = GpiPeerSendString(connection, peer, buffer);
    if (result != 0) {
        return result;
    }
    result = GpiPeerSendBytes(connection, peer, message, len);
    if (result != 0) {
        return result;
    }
    result = GpiPeerSendByte(connection, peer, 0);
    if (result != 0) {
        return result;
    }
    peer->mTimeout = GetUnixTime(NULL) + 0x12c;
    return 0;
}
