#include "00/code_02193b88.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196594.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193000.h"

#include "00/code_0218e2dc.h"
#include "00/code_02194000.h"
#include "00/code_021965a0.h"
#include "00/unk_021b4000.h"
#include "00/code_021a3668.h"
#include "00/unk_021b3000.h"
#include "00/code_02190548.h"
#include "00/code_0219218c.h"
#include "00/code_02192000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0218f15c.h"
#include "00/code_021a3678.h"
#include "code_021382a8.h"
#include "00/code_02190cd4.h"

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
                GpiSetErrorMessage(connection, gPeerConnectErrorString);
                return 3;
            } else if (state == 3) {
                canFreeSig = TRUE;
                if (GpiFindProfile(connection, peer->mProfileId, &profileEntry) == 0) {
                    GpiSetErrorMessage(connection, gPeerConnectErrorString);
                    return 3;
                }
                GpiAppendBufferString(connection, peer->mOutputBuffer, gAuthStatement);
                GpiAppendBufferString(connection, peer->mOutputBuffer, data_ov000_021b34d8);
                GpiAppendBufferNumber(connection, peer->mOutputBuffer, gpState->mProfileId);
                GpiAppendBufferString(connection, peer->mOutputBuffer, data_ov000_021b34e0);
                GpiAppendBufferString(connection, peer->mOutputBuffer, gpState->mNick);
                GpiAppendBufferString(connection, peer->mOutputBuffer, data_ov000_021b34e8);
                GpiAppendBufferString(connection, peer->mOutputBuffer, profileEntry->mUnk_18);
                GpiAppendBufferString(connection, peer->mOutputBuffer, data_ov000_021b34c8);
                for (otherPeer = gpState->mPeerList; otherPeer != NULL; otherPeer = otherPeer->mNext) {
                    if (otherPeer->mProfileId == peer->mProfileId && otherPeer != peer && otherPeer->mState <= 0x67) {
                        canFreeSig = FALSE;
                    }
                }
                if (canFreeSig != FALSE) {
                    DWCi_GsFree(profileEntry->mUnk_18);
                    profileEntry->mUnk_18 = NULL;
                    if (GpiIsProfileEmpty(profileEntry) != 0) {
                        GpiRemoveProfile(connection, profileEntry);
                    }
                }
                peer->mState = 0x68;
            }
            break;
        case 0x68:
            result = GpiReceiveBuffer(connection, peer->mSocket, (GpiBuffer *) &peer->mInputBuffer, &len, &socketGone,
                                      gPeerBufferName);
            if (result != 0) {
                return result;
            }
            end = strstr(peer->mInputBuffer, data_ov000_021b34c8);
            if (end == NULL) {
                break;
            }
            *end = 0;
            input = peer->mInputBuffer;
            if (strncmp(input, gAnackStatement, 7) == 0) {
                peer->mUnk_14 = peer->mUnk_14 + 1;
                if (peer->mUnk_14 > 1) {
                    GpiSetErrorMessage(connection, gPeerAuthorizationErrorString);
                    return 3;
                }
                result = gpiPeerGetSig(connection, peer);
                if (result != 0) {
                    return result;
                }
            } else if (strncmp(input, gAackStatement, 6) != 0) {
                GpiSetErrorMessage(connection, gPeerMessageParseErrorString);
                return 3;
            }
            peer->mState = 0x69;
            peer->mUnk_20 = FALSE;
            break;
        default:
            AssertionFailed(data_ov000_021b3440, gGpiPeerFileName, NULL, 0x9f);
            break;
    }
    if (peer->mOutputBufferLength > 0) {
        result = GpiSendBuffer(connection, peer->mSocket, (GpiBuffer *) peer->mOutputBuffer, &socketGone, 1,
                               gPeerBufferName);
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
        AssertionFailed(gPeerWaitingAssertion, gGpiPeerFileName, NULL, 0xc1);
    }
    result = GpiReceiveBuffer(connection, peer->mSocket, (GpiBuffer *) &peer->mInputBuffer, &len, &socketGone,
                              gPeerBufferName);
    if (result != 0) {
        return result;
    }
    if (socketGone != 0) {
        peer->mState = 0x6a;
        return 0;
    }
    end = strstr(peer->mInputBuffer, data_ov000_021b34c8);
    if (end != NULL) {
        *end = 0;
        input = peer->mInputBuffer;
        if (strncmp(input, gAuthStatement, 6) == 0) {
            if (GpiGetValue(input, data_ov000_021b34d8, intText, 0x10) == FALSE) {
                peer->mState = 0x6a;
                return 0;
            }
            pid = StrtolBase10(intText);
            if (GpiGetValue(peer->mInputBuffer, data_ov000_021b34e0, nickText, 0x1f) == FALSE) {
                peer->mState = 0x6a;
                return 0;
            }
            if (GpiGetValue(peer->mInputBuffer, data_ov000_021b34e8, sig, 0x21) == FALSE) {
                peer->mState = 0x6a;
                return 0;
            }
            sprintf(buffer, gSigHashFormat, gpState->mPassword, gpState->mProfileId, pid);
            MD5Digest(buffer, strlen(buffer), sigDigest);
            if (strcmp(sig, sigDigest) != 0) {
                GpiAppendBufferString(connection, peer->mOutputBuffer, gAnackStatement);
                GpiAppendBufferString(connection, peer->mOutputBuffer, data_ov000_021b34c8);
                peer->mState = 0x6a;
                return 0;
            }
            GpiAppendBufferString(connection, peer->mOutputBuffer, gAackStatement);
            GpiAppendBufferString(connection, peer->mOutputBuffer, data_ov000_021b34c8);
            peer->mState = 0x69;
            peer->mProfileId = pid;
        } else {
            peer->mState = 0x6a;
            return 0;
        }
        peer->mUnk_20 = FALSE;
    }
    return 0;
}

s32 gpiPeerSendMessages(GpConnection *connection, GpiPeer *peer) {
    Unk02194370Entry *message;
    u32 socketGone;
    s32 result;

    if (peer->mOutputBufferLength != 0) {
        return 0;
    }
    if (DarrayGetCount(peer->mQueuedMessages) != 0) {
        do {
            message = DarrayGetElement(peer->mQueuedMessages, 0);
            result = GpiSendBuffer(connection, peer->mSocket, (GpiBuffer *) message, &socketGone, 0, gPeerBufferName);
            if (socketGone != 0 || result != 0) {
                peer->mState = 0x6a;
                return 0;
            }
            if (message->mPos != message->mLength) {
                break;
            }
            DarrayRemove(peer->mQueuedMessages, 0);
        } while (DarrayGetCount(peer->mQueuedMessages) != 0);
    }
    return 0;
}

s32 gpiProcessPeerConnected(GpConnection *connection, GpiPeer *peerConn) {
    GpiConnection *gpState;
    Unk021941c4Msg *arg;
    s32 len;
    u32 socketGone;
    GpiCallback callback;
    s32 buffer;
    s32 type;
    s32 msgBytes;
    s32 result;

    gpState = connection->mGpiConnection;
    if (peerConn->mOutputBufferLength != 0) {
        result = GpiSendBuffer(connection, peerConn->mSocket, (GpiBuffer *) peerConn->mOutputBuffer, &socketGone, 1,
                               gPeerBufferName);
        if (socketGone != 0 || result != 0) {
            peerConn->mState = 0x6a;
            return 0;
        }
    }
    if (peerConn->mOutputBufferLength == 0) {
        result = gpiPeerSendMessages(connection, peerConn);
        if (result != 0) {
            return result;
        }
        if (peerConn->mState == 0x6a) {
            return 0;
        }
    }
    result = GpiReceiveBuffer(connection, peerConn->mSocket, (GpiBuffer *) &peerConn->mInputBuffer, &len, &socketGone,
                              gPeerBufferName);
    if (result != 0) {
        peerConn->mState = 0x6a;
        return 0;
    }
    if (len > 0) {
        peerConn->mUnk_10 = GetUnixTime(NULL) + 0x12c;
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
                            GpiSetErrorMessage(connection, data_ov000_021b3494);
                            return 1;
                        }
                        arg->mUnk_00 = peerConn->mProfileId;
                        arg->mUnk_08 = goastrdup((const char *) buffer);
                        arg->mUnk_04 = GetUnixTime(NULL);
                        result = GpiQueueCallback(connection, callback, arg, NULL, 2);
                        if (result != 0) {
                            return result;
                        }
                    }
                    break;
                case 0x66:
                    gpiSendBuddyMessage(connection, peerConn->mProfileId, 0x67, gPongMessageText);
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
        AssertionFailed(gPeerNotConnectedAssertion, gGpiPeerFileName, NULL, 0x1d9);
    }
    if (peer->mState != 0x69) {
        if (peer->mUnk_04 != 0) {
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
    DWCi_GsFree(*(void **) peer->mOutputBuffer);
    *(void **) peer->mOutputBuffer = NULL;
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
    Unk0219405c *message;
    s32 e;

    if (peer == NULL) {
        AssertionFailed(gPeerAssertText, gGpiPeerFileName, NULL, 0x213);
    }
    previous = gpState->mPeerList;
    if (previous == peer) {
        gpState->mPeerList = peer->mNext;
    } else {
        current = previous->mNext;
        while (current != peer) {
            if (current == NULL) {
                AssertionFailed(data_ov000_021b3440, gGpiPeerFileName, NULL, 0x225);
                gpiDebug(connection, gPeerNotInListDebugString);
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
            if (message->mUnk_10 < 0x64) {
                gpiSendServerBuddyMessage(connection, peer->mProfileId, message->mUnk_10,
                                          message->mBuffer + message->mUnk_14);
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
    s32 d;

    if (gpState->mListenSocket != -1 && CanReceiveOnSocket(gpState->mListenSocket) != 0) {
        d = AcceptConnection(gpState->mListenSocket, NULL, NULL);
        if (d != -1) {
            peerConn = GpiPeerCreate(connection, -1, 0);
            if (peerConn != NULL) {
                peerConn->mState = 0x68;
                peerConn->mSocket = d;
                SetSockBlocking(d, 0);
                gpiSetPeerSocketSizes(peerConn->mSocket);
            } else {
                closesocket(d);
            }
        }
    }
    peerConn = gpState->mPeerList;
    while (peerConn != NULL) {
        followingPeer = peerConn->mNext;
        d = GpiPeerUpdate(connection, peerConn);
        if (peerConn->mState == 0x6a || d != 0 || (s32) GetUnixTime(NULL) > peerConn->mUnk_10) {
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
    peerConn->mUnk_04 = initiate;
    peerConn->mSocket = -1;
    peerConn->mProfileId = profileid;
    peerConn->mUnk_10 = GetUnixTime(NULL) + 0x12c;
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
    Unk02193d64 address;
    GpiProfile *profileRec;
    s32 openResult;
    u32 *addressWords;

    if (GpiFindProfile(connection, peer->mProfileId, &profileRec) == 0) {
        GpiSetErrorMessage(connection, gPeerConnectErrorString);
        return 3;
    }
    peer->mSocket = OpenNetSocket(2, 1, 0);
    if (peer->mSocket == -1) {
        GpiSetError(connection, 5, data_ov000_021b33bc);
        GpiQueueErrorCallback(connection, 3, 0);
        return 3;
    }
    if (SetSockBlocking(peer->mSocket, 0) == FALSE) {
        GpiSetError(connection, 5, data_ov000_021b33e4);
        GpiQueueErrorCallback(connection, 3, 0);
        return 3;
    }
    gpiSetPeerSocketSizes(peer->mSocket);
    addressWords = (u32 *) &address;
    addressWords[0] = 0;
    addressWords[1] = 0;
    address.mUnk_01 = 2;
    address.mUnk_04 = profileRec->mBuddyStatus->mUnk_10;
    address.mUnk_02 = profileRec->mBuddyStatus->mUnk_14;
    openResult = connect(peer->mSocket, &address, 8);
    if (openResult == -1) {
        openResult = GOAGetLastError(peer->mSocket);
        if (openResult != -6 && openResult != -0x1a && openResult != -0x4c) {
            GpiSetError(connection, 5, data_ov000_021b3418);
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
        AssertionFailed(gPeerAssertText, gGpiPeerFileName, NULL, 0x340);
    }
    if (message == NULL) {
        AssertionFailed(gMessageAssertText, gGpiPeerFileName, NULL, 0x341);
    }
    len = strlen(message);
    {
        GPIMessage queuedMsg = {0};
        queuedMsg.mType = type;
        result = GpiAppendBufferString(connection, &queuedMsg, data_ov000_021b338c);
        if (result != 0) {
            return result;
        }
        result = GpiAppendBufferNumber(connection, &queuedMsg, type);
        if (result != 0) {
            return result;
        }
        result = GpiAppendBufferString(connection, &queuedMsg, data_ov000_021b3390);
        if (result != 0) {
            return result;
        }
        result = GpiAppendBufferNumber(connection, &queuedMsg, len);
        if (result != 0) {
            return result;
        }
        result = GpiAppendBufferString(connection, &queuedMsg, gMsgLineKey);
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
        peer->mUnk_10 = GetUnixTime(NULL) + 0x12c;
        return 0;
    }
}

u32 GpiPeerSendXfer(GpConnection *connection, GpiPeer *peer, u32 type, GpiTransferId *transferID) {
    char buffer[0x44];
    u32 count = transferID->mUnk_04;
    u32 profileid = transferID->mUnk_00;
    u32 time = transferID->mUnk_08;

    if (transferID == NULL) {
        AssertionFailed(gTransferIdAssertText, gGpiPeerFileName, NULL, 0x376);
    }
    sprintf(buffer, gTransferMessageFormat, type, profileid, count, time);
    return GpiPeerSendString(connection, (Unk02190988 *) peer, buffer);
}

s32 GpiPeerSendLenMsg(GpConnection *connection, GpiPeer *peer, const char *message, s32 len) {
    char buffer[0x24];
    s32 result;

    if (peer == NULL) {
        AssertionFailed(gPeerAssertText, gGpiPeerFileName, NULL, 0x389);
    }
    if (message == NULL) {
        message = data_ov000_021b3348;
    }
    if (len == -1) {
        len = strlen(message);
    }
    sprintf(buffer, gLenMsgFormat, len);
    result = GpiPeerSendString(connection, (Unk02190988 *) peer, buffer);
    if (result != 0) {
        return result;
    }
    result = GpiPeerSendBytes(connection, (Unk02190988 *) peer, message, len);
    if (result != 0) {
        return result;
    }
    result = GpiPeerSendByte(connection, (Unk02190988 *) peer, 0);
    if (result != 0) {
        return result;
    }
    peer->mUnk_10 = GetUnixTime(NULL) + 0x12c;
    return 0;
}
