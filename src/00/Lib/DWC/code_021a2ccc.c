#include "00/Lib/DWC/code_021a2ccc.h"

#include "00/Lib/GameSpy/gt2Main.h"
#include "00/code_021a1ae0.h"
#include "03/Net/essid_packet_steps.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "00/unk_021b5000.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "00/code_021a1000.h"
#include "00/code_021a2000.h"
#include "os_tick.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/code_0219b000.h"
#include "code_021329f8.h"
#include "code_02139f70.h"
#include "00/unk_021b4000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/Lib/DWC/dwc_match.h"

char gDwcMagicStrings[3] = "DT";
WiFiMessageLayer *gWiFiMessageLayer = NULL;

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

// Per login (called by DWC_InitFriendsMatch): stores gWiFiMessageLayer, zeroes the struct and sets mSendChunkSize.
void DWCi_InitTransport(WiFiMessageLayer *state) {
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
    if (gWiFiMessageLayer->mPingCallback != NULL) {
        gWiFiMessageLayer->mPingCallback(latency, DWCi_GetConnectionAID(connection));
    }
}

// One step per frame in connection state 6 (returns at once when the layer is NULL): for each participant (except the
// own index) continues the chunked send and, when the elapsed time since the last receive exceeds the peer's limit,
// calls the timeout callback func (mReceiveTimeoutCallback; no writer in src).
void DWCi_TransportProcess(void) {
    u8 *aids;
    s32 aidCount;
    s32 i;
    u8 aid;
    WiFiPeerMessage *peer;
    s32 remaining;
    s32 chunk;
    u64 now;
    if (gWiFiMessageLayer != NULL) {
        aidCount = DWC_GetAIDList(&aids);
        for (i = 0; i < aidCount; i++) {
            aid = aids[i];
            if (aid != DWC_GetMyAID() && DWCs_GetSendState(aid) == 1) {
                peer = DWCs_GetTransConnection(aid);
                remaining = peer->mSendSize - peer->mSentSize;
                chunk = gWiFiMessageLayer->mSendChunkSize;
                if (remaining <= chunk) {
                    chunk = remaining;
                }
                if (DWCs_GetOutgoingBufferFreeSize(aid) < chunk) {
                    continue;
                }
                DWCs_Send(aid, (peer->mSendBuffer + peer->mSentSize), chunk, 1);
                peer->mSentSize += chunk;
                if (peer->mSentSize == peer->mSendSize) {
                    if (gWiFiMessageLayer->mSendCallback != NULL) {
                        gWiFiMessageLayer->mSendCallback(peer->mSendSize, aid);
                    }
                    peer->mSendState = 0;
                    peer->mSendBuffer = NULL;
                    peer->mSentSize = 0;
                    peer->mSendSize = 0;
                }
            }
            if (DWC_IsValidAID(aid) != 0) {
                peer = DWCs_GetTransConnection(aid);
                if (gWiFiMessageLayer->mReceiveTimeoutCallback != NULL && peer->mReceiveTimeoutTime != 0) {
                    now = OS_GetTick();
                    if ((u32) _ll_udiv((now - peer->mPreviousReceiveTick) << 6, 0x82ea) >
                        peer->mReceiveTimeoutTime) {
                        gWiFiMessageLayer->mReceiveTimeoutCallback(aid);
                        peer->mPreviousReceiveTick = now;
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
        gWiFiMessageLayer->mPeers[aid].mSendState = 0;
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
    return gWiFiMessageLayer->mPeers[aid].mSendState;
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
        if ((gWiFiMessageLayer->mReceiveTimeoutCallback != NULL) && (peer->mReceiveTimeoutTime != 0)) {
            v3 = OS_GetTick();
            peer->mPreviousReceiveTick = v3;
        }
    }
}

void DWCs_RecvDataHeader(int aid, void *message, s32 size) {
    WiFiPeerMessage *connection = &gWiFiMessageLayer->mPeers[aid];
    u32 t[2];
    u16 type;
    connection->mLastReceiveState = DWCs_GetRecvState(aid);
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
    if (gWiFiMessageLayer->mReceiveTimeoutCallback != NULL && connection->mReceiveTimeoutTime != 0) {
        connection->mPreviousReceiveTick = OS_GetTick();
    }
}

void DWCs_RecvSystemDataBody(u32 aid, void *message, s32 size) {
    WiFiPeerMessage *peer = DWCs_GetTransConnection(aid);
    peer->mReceiveState = peer->mLastReceiveState;
    switch (peer->mMessageKind) {
        case 2:
        case 3:
        case 4:
            DWCi_ProcessMatchSynPacket(aid, peer->mMessageKind, message);
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
