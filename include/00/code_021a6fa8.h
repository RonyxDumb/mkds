#pragma once

#include "types.h"
#include "os_thread.h"

typedef struct OSThreadQueue OSThreadQueue;
typedef struct OSMutex OSMutex;
typedef struct OSMessageQueue OSMessageQueue;

struct SOCLSocket;
struct SOCLiSocketUdpData;

// Four bytes read by SOCLi_GetSizeCommandPipe: a size, a count and a byte.
typedef struct SOCLSocketCommandPipeParam {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} SOCLSocketCommandPipeParam;

// Start address and size of a part of an SOCLSocket or of its blocks, set by SOCLi_InitSocketBuffer.
typedef struct SizedBuffer {
    /* 00 */ s32 mSize;
    /* 04 */ u8 *mStart;
} SizedBuffer;

// Shared start of the two blocks SOCLi_InitSocket sets up behind an SOCLSocket.
typedef struct SOCLiSocketCommandPipe {
    /* 00 */ OSMessageQueue mUnk_00;
    /* 20 */ OSThread mUnk_20;
    /* d8 */ u8 mUnk_d8[8];
    /* e0 */ OSMutex mUnk_e0;
} SOCLiSocketCommandPipe;

typedef struct SOCLiSocketRecvCommandPipe {
    /* 000 */ SOCLiSocketCommandPipe mUnk_00;
    /* 0f8 */ s32 mUnk_f8;
    /* 0fc */ u16 mUnk_fc;
    /* 0fe */ s8 mUnk_fe;
    /* 100 */ struct SOCLiSocketUdpData *mUnk_100;
    /* 104 */ struct SOCLiSocketUdpData *mUnk_104;
    /* 108 */ u16 mUnk_108;
    /* 10a */ u16 mUnk_10a;
    /* 10c */ OSThreadQueue mUnk_10c;
    /* 114 */ u8 mUnk_114[4];
} SOCLiSocketRecvCommandPipe;

typedef struct SOCLiSocketSendCommandPipe {
    /* 000 */ SOCLiSocketCommandPipe mUnk_00;
    /* 0f8 */ SizedBuffer mUnk_f8;
    /* 100 */ u16 mUnk_100;
    /* 102 */ u16 mUnk_102;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ struct SOCLSocket *mUnk_10c;
    /* 110 */ u8 mUnk_110[4];
} SOCLiSocketSendCommandPipe;

typedef struct SOCLSocket {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u8 mState;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mCpsLocalPort;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ u16 mCpsRemotePort;
    /* 1a */ u16 mCpsRemotePortBound;
    /* 1c */ u32 mCpsRemoteIp;
    /* 20 */ u32 mCpsRemoteIpBound;
    /* 24 */ u8 mUnk_24[0x18];
    /* 3c */ SizedBuffer mReceiveBuffer;
    /* 44 */ s32 mReceiveBufferLength;
    /* 48 */ SizedBuffer mSendBuffer;
    /* 50 */ SizedBuffer mUnk_50;
    /* 58 */ SizedBuffer mUnk_58;
    /* 60 */ u8 mUnk_60[4];
    /* 64 */ SOCLiSocketRecvCommandPipe *mReceiveBlock;
    /* 68 */ SOCLiSocketSendCommandPipe *mSendBlock;
    /* 6c */ s32 mEntryResult;
    /* 70 */ s16 mStatusFlags;
    /* 72 */ s8 mFlagBlock;
    /* 73 */ s8 mFlagMode;
    /* 74 */ u16 mLocalPort;
    /* 76 */ u16 mRemotePort;
    /* 78 */ u16 *mRemoteIp;
    /* 7c */ struct SOCLSocket *mNext;
    /* 80 */ SOCLiSocketRecvCommandPipe mUnk_80;
} SOCLSocket;

s32 SOCLi_ExecCommandPacketInSendPipe(SOCLSocket *socket, void *packet);
