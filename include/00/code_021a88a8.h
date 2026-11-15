#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"

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

// One TCP or UDP connection of the network stack, 0x64 bytes; mHttpsState is the https layer's own state.
typedef struct CPSSoc {
    /* 00 */ struct OSThread *mThread;
    /* 04 */ u32 mBlockType;
    // TCP_SOCKET_STATE_*
    /* 08 */ u8 mState;
    /* 09 */ u8 mUseHttps;
    /* 0a */ u16 mLocalPort;
    /* 0c */ HttpsState *mHttpsState;
    /* 10 */ u32 mStateStartTime;
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
    /* 34 */ u32 mAckRcvd;
    /* 38 */ ConnectionReceiveFn mReceiveCallback;
    /* 3c */ u32 mReceiveBufferSize;
    /* 40 */ u8 *mReceiveBuffer;
    /* 44 */ u32 mReceiveBufferLength;
    /* 48 */ u32 mSendBufferSize;
    /* 4c */ u8 *mSendBuffer;
    /* 50 */ u8 mUnk_50[0xc];
    /* 5c */ u8 *mOutBuffer;
    /* 60 */ u32 mOutBufferLength;
} CPSSoc;

s32 SOCL_InetAtoH(const char *hostname);
s32 SOCL_Resolve(const char *hostname);
s32 SOCLi_GetReadBufferOccpiedSize(SOCLSocket *socket);
u32 SOCL_GetStatus(SOCLSocket *socket);
u32 SOCLi_RoundUp4(int size);
BOOL SOCL_SocketIsInTrash(SOCLSocket *node);
