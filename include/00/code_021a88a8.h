#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"

typedef struct HttpsState HttpsState;

struct CPSSoc;
typedef s32 (*ConnectionReceiveFn)(void *param_1, u32 param_2, struct CPSSoc *param_3);

// One TCP or UDP connection of the network stack, 0x64 bytes; mHttpsState is the https layer's own state.
typedef struct CPSSoc {
    /* 00 */ struct OSThread *mThread;
    /* 04 */ u32 mBlockType;
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

s32 SOCL_InetAtoH(u32 hostname);
s32 SOCL_Resolve(const char *hostname);
s32 SOCLi_GetReadBufferOccpiedSize(SOCLSocket *socket);
u32 SOCL_GetStatus(SOCLSocket *socket);
u32 SOCLi_RoundUp4(int size);
BOOL SOCL_SocketIsInTrash(SOCLSocket *node);
