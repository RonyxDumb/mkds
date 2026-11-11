#include "00/code_021a2ccc.h"

#include "00/code_021988e8.h"
#include "00/code_021a1ae0.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_0200f000.h"
#include "00/code_0219b580.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c384.h"
#include "00/code_021a1000.h"
#include "00/code_021a2000.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/code_0219b000.h"
#include "code_021329f8.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02139f70.h"
#include "00/unk_021b4000.h"
#include "string.h"
#include "code_02134398.h"

void DWC_SetUserSendCallback(u32 (*callback)(void)) {
    u32 value0 = (u32) callback;
    u32 value1;
    u32 value2;
    value1 = (u32) &gWiFiMessageLayer;
    value2 = *(const u32 *) ((value1) + 0u);
    value1 = 0x600u;
    *(u32 *) ((value2) + (value1)) = value0;
}

void DWC_SetUserRecvCallback(void (*callback)(u32, void *, u32)) {
    u32 value0 = (u32) callback;
    u32 value1;
    u32 value2;
    value1 = (u32) &gWiFiMessageLayer;
    value2 = *(const u32 *) ((value1) + 0u);
    value1 = 0x604u;
    *(u32 *) ((value2) + (value1)) = value0;
}

void DWCs_EncodeHeader(DWCTransportHeader *header, u16 type, u32 size) {
    strncpy((char *) header->mMagicStrings, gDwcMagicStrings, 2);
    header->mType = type;
    header->mSize = size;
}

u16 DWCs_DecodeHeader(const void *message) {
    DWCTransportHeader header;
    MI_CpuCopy8(message, &header, 8);
    if (memcmp(header.mMagicStrings, gDwcMagicStrings, 2) == 0) {
        return header.mType;
    }
    return 0;
}

s32 DWCs_GetRequiredHeaderSize(s32 type) {
    switch (type) {
        case 2:
        case 3:
        case 4:
            return 12;
        default:
            return 8;
    }
}

// Per login (called by InitWiFiConnection): stores gWiFiMessageLayer, zeroes the struct and sets mSendChunkSize.
void InitWiFiMessageLayer(WiFiMessageLayer *state) {
    gWiFiMessageLayer = state;
    MI_CpuFill8(state, 0, sizeof(WiFiMessageLayer));
    gWiFiMessageLayer->mSendChunkSize = 0x5b9;
}

void DWCi_RecvCallback(Unk0219887c *connection, void *message, s32 size, u32 reliable) {
    if (gWiFiMessageLayer != NULL) {
        if (reliable != 0) {
            DWCs_HandleReliableMessage(connection, message, size);
        } else {
            DWCs_HandleUnreliableMessage(connection, message, size);
        }
    }
}

void DWCi_PingCallback(Unk0219887c *connection, u32 latency) {
    if (gWiFiMessageLayer->mUnk_60c != NULL) {
        gWiFiMessageLayer->mUnk_60c(latency, DWCi_GetConnectionAID(connection));
    }
}

// One step per frame in connection state 6 (returns at once when the layer is NULL): for each participant (except the
// own index) continues the chunked send and, when the elapsed time since the last receive exceeds the peer's limit,
// calls the timeout callback func (mUnk_608; no writer in src).
void UpdateWiFiMessageLayer(void) {
    u8 *aidArray;
    s32 playerCount;
    s32 i;
    u8 aid;
    WiFiPeerMessage *messageSlot;
    s32 remainBytes;
    s32 sendSize;
    u64 nowTicks;
    if (gWiFiMessageLayer != NULL) {
        playerCount = DWC_GetAIDList(&aidArray);
        for (i = 0; i < playerCount; i++) {
            aid = aidArray[i];
            if (aid != GetOwnParticipantIndex() && DWCs_GetSendState(aid) == 1) {
                messageSlot = DWCs_GetTransConnection(aid);
                remainBytes = messageSlot->mSendSize - messageSlot->mSentSize;
                sendSize = gWiFiMessageLayer->mSendChunkSize;
                if (remainBytes <= sendSize) {
                    sendSize = remainBytes;
                }
                if (DWCs_GetOutgoingBufferFreeSize(aid) < sendSize) {
                    continue;
                }
                DWCs_Send(aid, (messageSlot->mSendBuffer + messageSlot->mSentSize), sendSize, 1);
                messageSlot->mSentSize += sendSize;
                if (messageSlot->mSentSize == messageSlot->mSendSize) {
                    if (gWiFiMessageLayer->mSendCallback != NULL) {
                        gWiFiMessageLayer->mSendCallback(messageSlot->mSendSize, aid);
                    }
                    messageSlot->mUnk_1c = 0;
                    messageSlot->mSendBuffer = NULL;
                    messageSlot->mSentSize = 0;
                    messageSlot->mSendSize = 0;
                }
            }
            if (DWC_IsValidAID(aid) != 0) {
                messageSlot = DWCs_GetTransConnection(aid);
                if (gWiFiMessageLayer->mUnk_608 != NULL && messageSlot->mUnk_2c != 0) {
                    nowTicks = OS_GetTick();
                    if ((u32) _ll_udiv((nowTicks - messageSlot->mUnk_24) << 6, 0x82ea) >
                        messageSlot->mUnk_2c) {
                        gWiFiMessageLayer->mUnk_608(aid);
                        messageSlot->mUnk_24 = nowTicks;
                    }
                }
            }
        }
    }
}

void DWCi_ClearTransConnection(int aid) {
    if (gWiFiMessageLayer != NULL) {
        gWiFiMessageLayer->mPeers[aid].mSentSize = 0;
        gWiFiMessageLayer->mPeers[aid].mReceivedSize = 0;
        gWiFiMessageLayer->mPeers[aid].mSendSize = 0;
        gWiFiMessageLayer->mPeers[aid].mReceiveSize = 0;
        gWiFiMessageLayer->mPeers[aid].mUnk_1c = 0;
        gWiFiMessageLayer->mPeers[aid].mMessageKind = 0;
    }
}

void DWCi_ShutdownTransport(void) {
    gWiFiMessageLayer = NULL;
}

WiFiPeerMessage *DWCs_GetTransConnection(int aid) {
    return &gWiFiMessageLayer->mPeers[aid];
}

u8 DWCs_GetSendState(int aid) {
    return gWiFiMessageLayer->mPeers[aid].mUnk_1c;
}

u8 DWCs_GetRecvState(int aid) {
    return gWiFiMessageLayer->mPeers[aid].mReceiveState;
}

void DWCs_Send(u32 aid, void *buffer, u32 size, u32 reliable) {
    void *connection;
    connection = DWCi_GetGT2Connection(aid);
    gt2Send(connection, buffer, size, reliable);
}

void DWCs_HandleReliableMessage(Unk0219887c *connection, void *message, s32 size) {
    u8 aid = DWCi_GetConnectionAID(connection);
    switch (DWCs_GetRecvState(aid)) {
        case 0: {
            u16 n = DWCs_DecodeHeader(message);
            if (n >= 2 && n <= 4) {
                DWCs_RecvDataHeader(aid, message, size);
            }
            break;
        }
        case 1:
            DWCs_RecvDataHeader(aid, message, size);
            break;
        case 2:
            DWCs_RecvDataBody(aid, message, size);
            break;
        case 3:
            DWCs_RecvSystemDataBody(aid, message, size);
            break;
        case 4:
            gWiFiMessageLayer->mPeers[aid].mReceiveState = 1;
            gWiFiMessageLayer->mPeers[aid].mReceivedSize = 0;
            gWiFiMessageLayer->mPeers[aid].mReceiveSize = 0;
            break;
        default:
            OS_Terminate();
            break;
    }
}

void DWCs_HandleUnreliableMessage(Unk0219887c *connection, const void *message, int size) {
    int aid;
    WiFiPeerMessage *peer;
    u64 v3;
    aid = DWCi_GetConnectionAID(connection);
    peer = &gWiFiMessageLayer->mPeers[aid];
    if ((peer->mReceiveBuffer != NULL) && (peer->mReceiveBufferSize >= size)) {
        MI_CpuCopy8(message, peer->mReceiveBuffer, size);
        if (gWiFiMessageLayer->mReceiveCallback != NULL) {
            gWiFiMessageLayer->mReceiveCallback(aid, peer->mReceiveBuffer, size);
        }
        if ((gWiFiMessageLayer->mUnk_608 != NULL) && (peer->mUnk_2c != 0)) {
            v3 = OS_GetTick();
            peer->mUnk_24 = v3;
        }
    }
}

void DWCs_RecvDataHeader(int aid, void *message, s32 size) {
    WiFiPeerMessage *connection = &gWiFiMessageLayer->mPeers[aid];
    u32 t[2];
    u16 type;
    connection->mUnk_1e = DWCs_GetRecvState(aid);
    type = DWCs_DecodeHeader(message);
    switch (type) {
        case 1:
            if (size != 8) {
                return;
            }
            MI_CpuCopy8(message, t, 8);
            connection->mReceiveSize = t[0];
            connection->mReceivedSize = 0;
            if (connection->mReceiveBuffer != NULL && connection->mReceiveBufferSize >= connection->mReceiveSize) {
                connection->mReceiveState = 2;
            } else {
                connection->mReceiveState = 4;
            }
            break;
        case 2:
        case 3:
        case 4:
            connection->mReceiveState = 3;
            break;
    }
    connection->mMessageKind = type;
}

void DWCs_RecvDataBody(int aid, void *message, s32 size) {
    WiFiPeerMessage *connection = &gWiFiMessageLayer->mPeers[aid];
    s32 expected;
    if (DWCs_GetRecvState(aid) == 2) {
        if (connection->mReceivedSize + size > connection->mReceiveBufferSize) {
            OS_Terminate();
        }
        MI_CpuCopy8(message, connection->mReceiveBuffer + connection->mReceivedSize, size);
    }
    connection->mReceivedSize += size;
    expected = connection->mReceiveSize;
    if (connection->mReceivedSize == expected) {
        connection->mReceiveState = 1;
        connection->mReceivedSize = 0;
        connection->mReceiveSize = 0;
        if (gWiFiMessageLayer->mReceiveCallback != NULL) {
            gWiFiMessageLayer->mReceiveCallback(aid, connection->mReceiveBuffer, expected);
        }
    }
    if (gWiFiMessageLayer->mUnk_608 != NULL && connection->mUnk_2c != 0) {
        connection->mUnk_24 = OS_GetTick();
    }
}

void DWCs_RecvSystemDataBody(u32 aid, void *message, s32 size) {
    WiFiPeerMessage *peer = DWCs_GetTransConnection(aid);
    peer->mReceiveState = peer->mUnk_1e;
    switch (peer->mMessageKind) {
        case 2:
        case 3:
        case 4:
            ReceiveMatchingPeerMessage(aid, peer->mMessageKind, message);
            break;
    }
}

s32 DWCs_GetOutgoingBufferFreeSize(u32 aid) {
    s32 freeSize = gt2GetOutgoingBufferFreeSpace(DWCi_GetGT2Connection(aid)) - 0x207;
    if (freeSize <= 0) {
        freeSize = 0;
    }
    return freeSize;
}

BOOL DWC_RegisterMatchingStatus(void) {
    if (gWiFiMatching == NULL || gWiFiMatching->mOwnProfileId == 0 || DWCi_IsError() != 0) {
        return FALSE;
    }
    if (DWCi_QR2Startup(gWiFiMatching->mOwnProfileId) == 0) {
        return TRUE;
    }
    return FALSE;
}
