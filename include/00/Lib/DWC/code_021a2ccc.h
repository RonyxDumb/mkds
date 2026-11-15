#pragma once

#include "types.h"

typedef struct WiFiPeerMessage WiFiPeerMessage;
typedef struct Gt2Connection Gt2Connection;

// Values of WiFiPeerMessage.mReceiveState; see the member.
enum {
    WIFI_PEER_RECEIVE_STATE_INITIAL,
    WIFI_PEER_RECEIVE_STATE_EXPECT_HEADER,
    WIFI_PEER_RECEIVE_STATE_DATA_BODY,
    WIFI_PEER_RECEIVE_STATE_CONTROL_BODY,
    WIFI_PEER_RECEIVE_STATE_DROP_BODY,
};

// Values of WiFiPeerMessage.mMessageKind, the kind in the message header. The last three are the control messages of
// the match start sync: the host sends each participant its position and aid, the participant answers with its latency,
// the host sends the go-ahead.
enum {
    WIFI_MESSAGE_KIND_NONE,
    WIFI_MESSAGE_KIND_DATA,
    WIFI_MESSAGE_KIND_SYNC_REQUEST,
    WIFI_MESSAGE_KIND_SYNC_REPLY,
    WIFI_MESSAGE_KIND_SYNC_GO,
};

// State of the message being sent to, and the one being received from, one peer (index into WiFiMessageLayer.mPeers),
// 0x30 bytes: send side buffer / total size / sent size, receive side buffer / capacity / total size / received size /
// mReceiveState, plus the kind of the message being received.
typedef struct WiFiPeerMessage {
    /* 00 */ u8 *mSendBuffer;
    /* 04 */ u8 *mReceiveBuffer;
    /* 08 */ s32 mReceiveBufferSize;
    // Bytes of the current message already handed to the socket (0 at start, += chunk).
    /* 0c */ s32 mSentSize;
    // Bytes of the current message received so far (reset when a header arrives, += packet size).
    /* 10 */ s32 mReceivedSize;
    // Total size of the message being sent (the size argument of DWCi_SendReliable); 0 when no send is running.
    /* 14 */ s32 mSendSize;
    // Total size of the message being received, from the header; 0 after the message is complete.
    /* 18 */ s32 mReceiveSize;
    /* 1c */ u8 mSendState;
    // Receive state, switched on once per received packet in DWCs_HandleReliableMessage (through
    // the getter DWCs_GetRecvState): 0 initial (only a control header, kind 2 to 4, is accepted); 1 expecting a header
    // (DWC_SetRecvBuffer, end of a message); 2 header of a data message (kind 1) accepted, body packets are copied
    // into the buffer; 3 control header (kind 2 to 4) taken, the next packet is the control body (state restored from
    // mUnk_1e); 4 data header refused (no buffer or too small): the next packet is dropped and the state returns to 1.
    // Not a per-frame switch.
    /* 1d */ u8 mReceiveState;
    /* 1e */ u8 mLastReceiveState;
    /* 1f */ u8 pad_1f[3];
    // Kind from the header of the current message: 1 for a data message, 2 to 4 for the messages
    // DWCi_ProcessMatchSynPacket takes.
    /* 22 */ u16 mMessageKind;
    /* 24 */ u64 mPreviousReceiveTick;
    /* 2c */ u32 mReceiveTimeoutTime;
} WiFiPeerMessage;

// Message framing on top of the Gt2 socket, embedded in WiFiConnection at 0x7a0 (0x614 bytes = sizeof, zeroed by
// DWCi_InitTransport), reached through gWiFiMessageLayer: one WiFiPeerMessage per peer index (32), an 8-byte header
// (size, kind, 2 more bytes) before each message, bodies cut into chunks of at most mSendChunkSize that
// DWCi_TransportProcess continues every frame in connection state 6; completed messages go to mReceiveCallback.
typedef struct WiFiMessageLayer {
    /* 000 */ WiFiPeerMessage mPeers[32];
    // Called after a send was queued or finished, with (size, index).
    /* 600 */ void (*mSendCallback)(s32 size, u32 aid);
    // Called with (index, buffer, size) when a received message is complete.
    /* 604 */ void (*mReceiveCallback)(u32 aid, u8 *buffer, s32 size);
    /* 608 */ void (*mReceiveTimeoutCallback)(u32 aid);
    /* 60c */ void (*mPingCallback)(u32 latency, u32 aid);
    // u16 0x5b9 (1465), set by DWCi_InitTransport: the most the layer hands the socket in one call. A message is cut
    // into chunks of at most this size; a size equal to it is
    // allowed, the last chunk is shorter and a single-packet send above it is refused.
    /* 610 */ u16 mSendChunkSize;
    /* 612 */ u8 pad_612[2];
} WiFiMessageLayer;

// Local of DWCs_DecodeHeader, filled by a copy of eight bytes.
typedef struct DWCTransportHeader {
    /* 00 */ u32 mSize;
    /* 04 */ u16 mType;
    /* 06 */ char mMagicStrings[2];
} DWCTransportHeader;

// Points at WiFiConnection.mMessageLayer: set by DWCi_InitTransport, set to NULL by DWCi_ShutdownTransport
// (DWC_ShutdownFriendsMatch).
extern WiFiMessageLayer *gWiFiMessageLayer;

BOOL DWC_RegisterMatchingStatus(void);
s32 DWCs_GetOutgoingBufferFreeSize(u32 aid);
void DWCs_RecvSystemDataBody(u32 aid, void *message, s32 size);
void DWCs_RecvDataBody(int aid, void *message, s32 size);
void DWCs_RecvDataHeader(int aid, void *message, s32 size);
void DWCs_HandleUnreliableMessage(Gt2Connection *connection, const void *message, int size);
void DWCs_HandleReliableMessage(Gt2Connection *connection, void *message, s32 size);
void DWCs_Send(u32 aid, void *buffer, u32 size, u32 reliable);
u8 DWCs_GetRecvState(int aid);
u8 DWCs_GetSendState(int aid);
WiFiPeerMessage *DWCs_GetTransConnection(int aid);
void DWCi_ShutdownTransport(void);
void DWCi_ClearTransConnection(int aid);
void DWCi_TransportProcess(void);
void DWCi_PingCallback(Gt2Connection *connection, u32 latency);
void DWCi_RecvCallback(Gt2Connection *connection, void *message, s32 size, u32 reliable);
void DWCi_InitTransport(WiFiMessageLayer *state);
s32 DWCs_GetRequiredHeaderSize(s32 type);
u16 DWCs_DecodeHeader(const void *message);
void DWCs_EncodeHeader(DWCTransportHeader *header, u16 type, u32 size);
void DWC_SetUserRecvCallback(void (*callback)(u32, void *, u32));
void DWC_SetUserSendCallback(u32 (*callback)(void));

extern char gDwcMagicStrings[3];
