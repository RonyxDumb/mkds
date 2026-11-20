#pragma once

#include "types.h"
#include "00/Lib/DWC/match_work.h"

typedef struct WiFiPeerMessage WiFiPeerMessage;
typedef struct GTI2Connection GTI2Connection;

// Values of WiFiPeerMessage.mReceiveState; see the member.
enum {
    WIFI_PEER_RECEIVE_STATE_INITIAL,
    WIFI_PEER_RECEIVE_STATE_EXPECT_HEADER,
    WIFI_PEER_RECEIVE_STATE_DATA_BODY,
    WIFI_PEER_RECEIVE_STATE_CONTROL_BODY,
    WIFI_PEER_RECEIVE_STATE_DROP_BODY,
};

// Values of WiFiPeerMessage.mMessageKind, the kind in the message header. The last three are the control messages of
// the matching sync: the host sends each participant its position and aid, the participant answers with its latency,
// the host sends the go-ahead.
enum {
    WIFI_MESSAGE_KIND_NONE,
    WIFI_MESSAGE_KIND_DATA,
    WIFI_MESSAGE_KIND_SYNC_REQUEST,
    WIFI_MESSAGE_KIND_SYNC_REPLY,
    WIFI_MESSAGE_KIND_SYNC_GO,
};

// The message being sent to, and the one being received from, one peer: buffers, sizes and receive state.
typedef struct WiFiPeerMessage {
    /* 00 */ u8 *mSendBuffer;
    /* 04 */ u8 *mReceiveBuffer;
    /* 08 */ s32 mReceiveBufferSize;
    // Bytes of the current message already handed to the socket (0 at start, += chunk).
    /* 0c */ s32 mSentSize;
    // Bytes of the current message received so far (reset when a data header arrives, += packet size).
    /* 10 */ s32 mReceivedSize;
    // Total size of the message being sent (the size argument of DWCi_SendReliable); 0 when no send is running.
    /* 14 */ s32 mSendSize;
    // Total size of the message being received, from the header; 0 after the message is complete.
    /* 18 */ s32 mReceiveSize;
    /* 1c */ u8 mSendState;
    // Receive state, one of WIFI_PEER_RECEIVE_STATE_*, switched on once per received packet in
    // DWCs_HandleReliableMessage: INITIAL takes only a control header (kinds SYNC_REQUEST to SYNC_GO); EXPECT_HEADER
    // takes any header (set by DWC_SetRecvBuffer and after a finished message); DATA_BODY copies the packets into the
    // buffer; CONTROL_BODY restores mLastReceiveState and takes the next packet as the control body; DROP_BODY
    // drops the next packet and goes back to EXPECT_HEADER.
    /* 1d */ u8 mReceiveState;
    /* 1e */ u8 mLastReceiveState;
    /* 1f */ u8 pad_1f[3];
    // Kind from the header of the current message: 1 for a data message, 2 to 4 for the messages
    // DWCi_ProcessMatchSynPacket takes.
    /* 22 */ u16 mMessageKind;
    /* 24 */ u64 mPreviousReceiveTick;
    /* 2c */ u32 mReceiveTimeoutTime;
} WiFiPeerMessage;

// The message layer: one WiFiPeerMessage per peer; a reliable message goes out in chunks of at most mSendChunkSize, as
// many as the socket has room for when it is sent and the rest one chunk per frame while there is room, and the
// callbacks report sends, receives, receive timeouts and latency.
typedef struct WiFiMessageLayer {
    /* 000 */ WiFiPeerMessage mPeers[WIFI_MATCH_MAX_PARTICIPANTS];
    // Called with (size, aid) once a message was handed to the socket: when the last chunk of a reliable message went
    // out (data kind in DWCi_SendReliable, any kind in DWCi_TransportProcess) and for each unreliable send.
    /* 600 */ void (*mSendCallback)(s32 size, u32 aid);
    // Called with (aid, buffer, size) when a reliable data message is complete and for each unreliable message that
    // fits mReceiveBuffer.
    /* 604 */ void (*mUdpreadCallback)(u32 aid, u8 *buffer, s32 size);
    /* 608 */ void (*mReceiveTimeoutCallback)(u32 aid);
    /* 60c */ void (*mPingCallback)(u32 latency, u32 aid);
    // 0x5b9 (1465), set by DWCi_InitTransport: the most the layer hands the socket in one call. A message is cut into
    // chunks of at most this size (the last may be shorter); an unreliable send above it is refused.
    /* 610 */ u16 mSendChunkSize;
} WiFiMessageLayer;

// The 8-byte header in front of each reliable message: its size, its kind (mType) and two magic characters.
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
void DWCs_HandleUnreliableMessage(GTI2Connection *connection, const void *message, int size);
void DWCs_HandleReliableMessage(GTI2Connection *connection, void *message, s32 size);
void DWCs_Send(u32 aid, void *buffer, u32 size, u32 reliable);
u8 DWCs_GetRecvState(int aid);
u8 DWCs_GetSendState(int aid);
WiFiPeerMessage *DWCs_GetTransConnection(int aid);
void DWCi_ShutdownTransport(void);
void DWCi_ClearTransConnection(int aid);
void DWCi_TransportProcess(void);
void DWCi_PingCallback(GTI2Connection *connection, u32 latency);
void DWCi_RecvCallback(GTI2Connection *connection, void *message, s32 size, u32 reliable);
void DWCi_InitTransport(WiFiMessageLayer *state);
s32 DWCs_GetRequiredHeaderSize(s32 type);
u16 DWCs_DecodeHeader(const void *message);
void DWCs_EncodeHeader(DWCTransportHeader *header, u16 type, u32 size);
void DWC_SetUserRecvCallback(void (*callback)(u32, void *, u32));
void DWC_SetUserSendCallback(u32 (*callback)(void));

extern char gDwcMagicStrings[3];
