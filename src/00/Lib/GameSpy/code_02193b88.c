#include "00/Lib/GameSpy/code_02193b88.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/Lib/GameSpy/code_02196480.h"
#include "00/Lib/GameSpy/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_02194bb8.h"
#include "00/code_02193000.h"

#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/code_02194000.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b3000.h"
#include "00/Lib/GameSpy/code_0219218c.h"
#include "00/code_02192000.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "code_021382a8.h"
#include "00/Lib/GameSpy/code_02190cd4.h"

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
        case 0x65:
            break;
        case 0x66:
            result = GpiPeerConnect(connection, peer);
            if (result != 0) {
                return result;
            }
            break;
        case 0x67:
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
                    if (otherPeer->mProfileId == peer->mProfileId && otherPeer != peer && otherPeer->mState <= 0x67) {
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
                peer->mState = 0x68;
            }
            break;
        case 0x68:
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
            peer->mState = 0x69;
            peer->mInputBufferLength = FALSE;
            break;
        default:
            AssertionFailed("0", "gpiPeer.c", NULL, 0x9f);
            break;
    }
    if (peer->mOutputBuffer.mLength > 0) {
        result = GpiSendBuffer(connection, peer->mSocket, &peer->mOutputBuffer, &socketGone, 1, (const s8 *) "PR");
        if (socketGone != 0 || result != 0) {
            peer->mState = 0x6a;
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
    if (peer->mState != 0x68) {
        AssertionFailed("peer->state == GPI_PEER_WAITING", "gpiPeer.c", NULL, 0xc1);
    }
    result = GpiReceiveBuffer(connection, peer->mSocket, (GpiBuffer *) &peer->mInputBuffer, &len, &socketGone,
                              (const s8 *) "PR");
    if (result != 0) {
        return result;
    }
    if (socketGone != 0) {
        peer->mState = 0x6a;
        return 0;
    }
    end = strstr(peer->mInputBuffer, "\\final\\");
    if (end != NULL) {
        *end = 0;
        input = peer->mInputBuffer;
        if (strncmp(input, "\\auth\\", 6) == 0) {
            if (GpiGetValue(input, "\\pid\\", intText, 0x10) == FALSE) {
                peer->mState = 0x6a;
                return 0;
            }
            pid = StrtolBase10(intText);
            if (GpiGetValue(peer->mInputBuffer, "\\nick\\", nickText, 0x1f) == FALSE) {
                peer->mState = 0x6a;
                return 0;
            }
            if (GpiGetValue(peer->mInputBuffer, "\\sig\\", sig, 0x21) == FALSE) {
                peer->mState = 0x6a;
                return 0;
            }
            sprintf(buffer, "%s%d%d", gpState->mPassword, gpState->mProfileId, pid);
            MD5Digest(buffer, strlen(buffer), sigDigest);
            if (strcmp(sig, sigDigest) != 0) {
                GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\anack\\");
                GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\final\\");
                peer->mState = 0x6a;
                return 0;
            }
            GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\aack\\");
            GpiAppendBufferString(connection, &peer->mOutputBuffer, "\\final\\");
            peer->mState = 0x69;
            peer->mProfileId = pid;
        } else {
            peer->mState = 0x6a;
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
                peer->mState = 0x6a;
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
            peerConn->mState = 0x6a;
            return 0;
        }
    }
    if (peerConn->mOutputBuffer.mLength == 0) {
        result = gpiPeerSendMessages(connection, peerConn);
        if (result != 0) {
            return result;
        }
        if (peerConn->mState == 0x6a) {
            return 0;
        }
    }
    result = GpiReceiveBuffer(connection, peerConn->mSocket, (GpiBuffer *) &peerConn->mInputBuffer, &len, &socketGone,
                              (const s8 *) "PR");
    if (result != 0) {
        peerConn->mState = 0x6a;
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
                case 1:
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
                        result = GpiQueueCallback(connection, callback, arg, NULL, 2);
                        if (result != 0) {
                            return result;
                        }
                    }
                    break;
                case 0x66:
                    gpiSendBuddyMessage(connection, peerConn->mProfileId, 0x67, "1");
                    break;
                case 200:
                case 201:
                case 202:
                case 203:
                case 204:
                case 205:
                case 206:
                case 207:
                case 208:
                    gpiHandleTransferMessage(connection, peerConn, type, peerConn->mInputBuffer, buffer, msgBytes);
                    break;
            }
            gpiClipBufferToPosition(connection, (GpiBuffer *) &peerConn->mInputBuffer);
        }
    } while (buffer != 0);
    if (socketGone != 0) {
        peerConn->mState = 0x6a;
    }
    return 0;
}

s32 GpiPeerUpdate(GpConnection *connection, GpiPeer *peer) {
    s32 result = 0;

    if (peer->mState == 0x64) {
        AssertionFailed("peer->state != GPI_PEER_NOT_CONNECTED", "gpiPeer.c", NULL, 0x1d9);
    }
    if (peer->mState != 0x69) {
        if (peer->mInitiated != 0) {
            result = gpiProcessPeerInitiatingConnection(connection, peer);
        } else {
            result = GpiPeerUpdateWaiting(connection, peer);
        }
    }
    if (result == 0 && peer->mState == 0x69) {
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
            if (message->mType < 0x64) {
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
                peerConn->mState = 0x68;
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
        if (peerConn->mState == 0x6a || value != 0 || (s32) GetUnixTime(NULL) > peerConn->mTimeout) {
            GpiPeerRemoveAndWriteQueuedMessages(connection, peerConn);
        }
        peerConn = followingPeer;
    }
    return 0;
}

GpiPeer *gpiGetConnectedPeer(GpConnection *object, u32 key) {
    GpiPeer *node = object->mGpiConnection->mPeerList;
    while (node != NULL) {
        if (node->mProfileId == key && node->mState == 0x69) {
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
    memset(peerConn, 0, 0x40);
    peerConn->mState = 0x64;
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
    int pendingOp[2];
    result = GpiCreateOperation(connection, 2, 0, pendingOp, 0, 0, 0);
    if ((result == 0) &&
        (result = gpiSendGetInfo(connection, peer->mProfileId, *(u32 *) (pendingOp[0] + 0x18)), result == 0)) {
        peer->mState = 0x65;
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
    address.mFamily = 2;
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
    peer->mState = 0x67;
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
