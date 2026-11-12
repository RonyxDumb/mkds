#include "00/Lib/DWC/code_021a3264.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "00/code_0219b000.h"
#include "00/unk_021b5000.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "00/Lib/DWC/code_021a2ccc.h"
#include "00/unk_021b4000.h"
#include "code_02139f70.h"
#include "os_printf.h"
#include "os_tick.h"
#include "code_0200fc8c.h"
#include "code_021329f8.h"
#include "string.h"
#include "code_02134398.h"

MATHRandContext32 gRandContext32;

u32 DWC_SetCommonKeyValueString(void *key, void *value, void *string, u32 separator) {
    OS_SNPrintf(string, 0x1000, "%c%s%c%s", separator, key, separator, value);
    return strlen(string);
}

u32 DWC_AddCommonKeyValueString(void *key, void *value, void *string, u32 separator) {
    DWC_SetCommonKeyValueString(key, value, strchr(string, 0), separator);
    return strlen(string);
}

s32 DWC_GetCommonValueString(const char *key, char *value, const char *string, int separator) {
    const char *pair;
    const char *q;
    s32 len;
    enum { K1 = 1 } k;
    if (value == NULL) {
        return -1;
    }
    pair = strchr(string, separator);
    if (pair == NULL) {
        return -1;
    }
    k = K1;
    while (1) {
        if (strncmp(pair + 1, key, strlen(key)) == 0 &&
            (len = strlen(key), len += (u32) pair, separator == *(s8 *) (len + k))) {
            break;
        }
        q = strchr(pair + 1, separator);
        if (q == NULL) {
            return -1;
        }
        pair = strchr(q + 1, separator);
        if (pair == NULL) {
            return -1;
        }
    }
    pair = strchr(pair + 1, separator);
    if (pair == NULL) {
        return -1;
    }
    q = strchr(pair + 1, separator);
    if (q != NULL) {
        len = q - (pair + 1);
    } else {
        len = strlen(pair + 1);
    }
    strncpy(value, pair + 1, len);
    value[len] = 0;
    return len;
}

u64 MatchingGetTickMilliseconds(void) {
    return _ll_udiv(OS_GetTick() << 6, 0x82ea);
}

u32 DWCi_GetMathRand32(u32 max) {
    u64 seed;
    u64 tick;
    if (gRandContext32.mX == 0 && gRandContext32.mMul == 0 && gRandContext32.mAdd == 0) {
        OS_GetMacAddress(&seed);
        tick = OS_GetTick();
        seed = ((seed >> 24) & 0xffffff) | (tick << 24);
        gRandContext32.mX = seed;
        gRandContext32.mMul = 0x5d588b656c078965;
        gRandContext32.mAdd = 0x269ec3;
    }
    gRandContext32.mX = gRandContext32.mMul * gRandContext32.mX + gRandContext32.mAdd;
    if (max == 0) {
        return gRandContext32.mX >> 32;
    }
    return ((gRandContext32.mX >> 32) * max) >> 32;
}

BOOL DWCi_IsSendableReliable(u32 aid, s32 type) {
    if ((type == 1 && DWC_IsValidAID(aid) == 0) || DWCi_IsValidAID(aid) == FALSE) {
        return FALSE;
    }
    if (DWCs_GetSendState(aid) == 1) {
        return FALSE;
    }
    if (DWCs_GetOutgoingBufferFreeSize(aid) >= DWCs_GetRequiredHeaderSize(type)) {
        return TRUE;
    }
    return FALSE;
}

// Starts a send of kind a (1 = data) to peer b: refuses (FALSE) while an error is pending or DWCi_IsSendableReliable
// says no (peer not usable, kind 1 to a non-participant, already sending, or less send room than the header needs);
// marks the peer sending, stores the buffer and size, writes the 8-byte header and the first chunk (when the socket has
// no room for the chunk it returns TRUE after the header); DWCi_TransportProcess sends the later chunks; calls
// mSendCallback when the whole message went out at once (kind 1 only).
BOOL DWCi_SendReliable(u16 type, u32 aid, u8 *buffer, s32 size) {
    WiFiPeerMessage *peer = DWCs_GetTransConnection(aid);
    DWCTransportHeader header;
    s32 chunk;
    if (DWCi_IsError() != 0) {
        return FALSE;
    }
    if (DWCi_IsSendableReliable(aid, type) == FALSE) {
        return FALSE;
    }
    peer->mSendState = 1;
    peer->mSendBuffer = buffer;
    peer->mSentSize = 0;
    peer->mSendSize = size;
    DWCs_EncodeHeader(&header, type, size);
    DWCs_Send(aid, &header, 8, 1);
    chunk = gWiFiMessageLayer->mSendChunkSize;
    if (size <= chunk) {
        chunk = size;
    }
    if (chunk > DWCs_GetOutgoingBufferFreeSize(aid)) {
        return TRUE;
    }
    DWCs_Send(aid, buffer, chunk, 1);
    peer->mSentSize += chunk;
    if (peer->mSentSize == peer->mSendSize) {
        if (gWiFiMessageLayer->mSendCallback != NULL && type == 1) {
            gWiFiMessageLayer->mSendCallback(peer->mSendSize, aid);
        }
        peer->mSendState = 0;
        peer->mSendBuffer = NULL;
        peer->mSentSize = 0;
        peer->mSendSize = 0;
    }
    return TRUE;
}

BOOL DWC_SendUnreliable(u32 aid, void *buffer, s32 size) {
    if (DWCi_IsError() != 0) {
        return FALSE;
    }
    if (DWC_IsValidAID(aid) == 0) {
        return FALSE;
    }
    if (size > gWiFiMessageLayer->mSendChunkSize) {
        return FALSE;
    }
    DWCs_Send(aid, buffer, size, 0);
    if (gWiFiMessageLayer->mSendCallback != NULL) {
        gWiFiMessageLayer->mSendCallback(size, aid);
    }
    return TRUE;
}

// Gives peer a the buffer b of capacity c to receive into and sets mReceiveState to 1 with both received counters 0;
// refuses (FALSE) while a body is being received into the old buffer (state 2).
BOOL DWC_SetRecvBuffer(u32 aid, void *recvBuffer, s32 size) {
    WiFiPeerMessage *connection = DWCs_GetTransConnection(aid);
    if (DWCs_GetRecvState(aid) == 2) {
        return FALSE;
    }
    connection->mReceiveBuffer = recvBuffer;
    connection->mReceiveBufferSize = size;
    connection->mReceiveState = 1;
    connection->mReceivedSize = 0;
    connection->mReceiveSize = 0;
    return TRUE;
}
