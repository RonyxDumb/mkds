#pragma once

#include "types.h"
#include "thread_scheduler.h"

// Bits of SOCLSocket.mStatusFlags.
#define SOCKET_STATUS_CREATED 0x0001
#define SOCKET_STATUS_CONNECTING 0x0002
#define SOCKET_STATUS_CONNECTED 0x0004
#define SOCKET_STATUS_CLOSING 0x0008
#define SOCKET_STATUS_CLOSE_REQUESTED 0x0010
#define SOCKET_STATUS_TRASHED 0x0020
#define SOCKET_STATUS_CONNECT_FAILED 0x0040

typedef struct OSThreadQueue OSThreadQueue;
typedef struct OSMutex OSMutex;
typedef struct OSMessageQueue OSMessageQueue;

struct SOCLSocket;
struct SOCLiSocketUdpData;

// Settings of a command pipe: stack size, thread priority and the message queue length.
typedef struct SOCLSocketCommandPipeParam {
    /* 00 */ u16 mStackSize;
    /* 02 */ u8 mPriority;
    /* 03 */ u8 mQueueMax;
} SOCLSocketCommandPipeParam;

// Start address and size of one buffer: the four buffers of a CPSSoc and the write buffer area of the send pipe, set by
// SOCLi_InitSocketBuffer.
typedef struct SizedBuffer {
    /* 00 */ s32 mSize;
    /* 04 */ u8 *mStart;
} SizedBuffer;

typedef struct HttpsState HttpsState;

struct CPSSoc;
typedef s32 (*ConnectionReceiveFn)(void *data, u32 length, struct CPSSoc *socket);

// Values of CPSSoc.mState: the TCP connection states, then the two modes that carry single packets (DATAGRAM, PING).
// Value 5 is never set. LAST_ACK is after the peer closed and the answering FIN went out, FIN_SENT after our own FIN,
// FIN_ACKED once it was acknowledged, CLOSING when the peer's FIN arrived before that acknowledgement.
enum {
    SOCKET_STATE_CLOSED = 0,
    SOCKET_STATE_LISTENING = 1,
    SOCKET_STATE_SYN_SENT = 2,
    SOCKET_STATE_SYN_RECEIVED = 3,
    SOCKET_STATE_ESTABLISHED = 4,
    SOCKET_STATE_LAST_ACK = 6,
    SOCKET_STATE_FIN_SENT = 7,
    SOCKET_STATE_FIN_ACKED = 8,
    SOCKET_STATE_CLOSING = 9,
    SOCKET_STATE_DATAGRAM = 10,
    SOCKET_STATE_PING = 11,
};

// Values of CPSSoc.mBlockType: what the thread of the socket sleeps for (0 when it is not sleeping): the connection to
// be made, received TCP data, or a received datagram.
enum {
    SOCKET_BLOCK_NONE = 0,
    SOCKET_BLOCK_CONNECT = 1,
    SOCKET_BLOCK_TCP_DATA = 2,
    SOCKET_BLOCK_DATAGRAM = 3,
};

// One TCP or UDP connection of the network stack: state, ports, addresses, sequence numbers, buffers; head of
// SOCLSocket.
typedef struct CPSSoc {
    /* 00 */ struct OSThread *mThread;
    /* 04 */ u32 mBlockType;
    // SOCKET_STATE_*
    /* 08 */ u8 mState;
    /* 09 */ u8 mUseHttps;
    /* 0a */ u16 mLocalPort;
    /* 0c */ HttpsState *mHttpsState;
    /* 10 */ u32 mHandshakeStartTime;
    /* 14 */ u32 mLocalIpReal;
    /* 18 */ u16 mRemotePort;
    /* 1a */ u16 mRemotePortBound;
    /* 1c */ u32 mRemoteIp;
    /* 20 */ u32 mRemoteIpBound;
    /* 24 */ u32 mAckNo;
    /* 28 */ u32 mSeqNo;
    /* 2c */ u16 mRemoteWin;
    /* 2e */ u16 mRemoteMss;
    /* 30 */ u32 mRemoteAckNo;
    /* 34 */ u32 mAckrcvd;
    /* 38 */ ConnectionReceiveFn mUdpreadCallback;
    /* 3c */ SizedBuffer mReceiveBuffer;
    /* 44 */ u32 mReceiveBufferLength;
    /* 48 */ SizedBuffer mSendBuffer;
    /* 50 */ SizedBuffer mLinbuf;
    /* 58 */ SizedBuffer mOutBuffer;
    /* 60 */ u32 mOutBufferLength;
} CPSSoc;

// The command pipe of a socket: the message queue, the thread that runs the commands and the in-use mutex.
typedef struct SOCLiSocketCommandPipe {
    /* 00 */ OSMessageQueue mQueue;
    /* 20 */ OSThread mThread;
    /* e0 */ OSMutex mInUse;
} SOCLiSocketCommandPipe;

typedef struct SOCLiSocketRecvCommandPipe {
    /* 000 */ SOCLiSocketCommandPipe mCommandPipe;
    /* 0f8 */ s32 mConsumed;
    /* 0fc */ u16 mConsumedMin;
    /* 0fe */ s8 mNoConsume;
    /* 100 */ struct SOCLiSocketUdpData *mUdpDataIn;
    /* 104 */ struct SOCLiSocketUdpData *mUdpDataOut;
    /* 108 */ u16 mUdpDataSize;
    /* 10a */ u16 mUdpDataSizeMax;
    /* 10c */ OSThreadQueue mUdpDataWaiting;
    /* 114 */ u8 mCommandMessages[4];
} SOCLiSocketRecvCommandPipe;

typedef struct SOCLiSocketSendCommandPipe {
    /* 000 */ SOCLiSocketCommandPipe mCommandPipe;
    /* 0f8 */ SizedBuffer mBufferArea;
    /* 100 */ u16 mBufferIn;
    /* 102 */ u16 mBufferOut;
    /* 104 */ s32 mBufferWaitingHead;
    /* 108 */ s32 mBufferWaitingTail;
    /* 10c */ struct SOCLSocket *mExeSocket;
    /* 110 */ u8 mCommandMessages[4];
} SOCLiSocketSendCommandPipe;

// Values of SOCLSocket.mFlagMode, also held by SOCLSocketParam and SOCLiCommandPacket: a stream socket, a datagram
// socket that receives (bound, with the datagram callback), one that only sends, one that is only registered, and a
// stream socket whose reads go through the read command. The parameter tables only set the first three.
enum {
    SOCKET_MODE_STREAM = 0,
    SOCKET_MODE_DATAGRAM_RECEIVE = 1,
    SOCKET_MODE_DATAGRAM_SEND = 2,
    SOCKET_MODE_REGISTER_ONLY = 3,
    SOCKET_MODE_STREAM_READ_COMMAND = 4,
};

typedef struct SOCLSocket {
    /* 00 */ CPSSoc mCps;
    /* 64 */ SOCLiSocketRecvCommandPipe *mReceiveBlock;
    /* 68 */ SOCLiSocketSendCommandPipe *mSendBlock;
    /* 6c */ s32 mEntryResult;
    /* 70 */ s16 mStatusFlags;
    /* 72 */ s8 mFlagBlock;
    /* 73 */ s8 mFlagMode;
    /* 74 */ u16 mLocalPort;
    /* 76 */ u16 mRemotePort;
    /* 78 */ u32 mRemoteIp;
    /* 7c */ struct SOCLSocket *mNext;
    // First byte behind the socket header, where SOCLi_InitSocket lays out the receive pipe when a receive buffer is
    // asked for, otherwise the send pipe.
    /* 80 */ SOCLiSocketRecvCommandPipe mBlockArea;
} SOCLSocket;

s32 SOCLi_ExecCommandPacketInSendPipe(SOCLSocket *socket, void *packet);
