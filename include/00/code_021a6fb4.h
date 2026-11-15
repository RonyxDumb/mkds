#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"

typedef struct SOCLSocketParam SOCLSocketParam;

struct SOCLiCommandPacket;

typedef s32 (*SOCLiCommandHandler)(struct SOCLiCommandPacket *packet);

// Entry of the queue behind SOCLiCommandPacketQueue.
typedef struct SOCLiCommandPacket {
    /* 00 */ SOCLiCommandHandler mHandler;
    /* 04 */ SOCLSocket *mSocket;
    /* 08 */ OSMessageQueue *mResponse;
    /* 0c */ s8 mFlagMode;
    /* 0d */ s8 mFlagBlock;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u16 mLocalPort;
    /* 12 */ u16 mRemotePort;
    // Bind command: the remote IP address; listen-accept command: pointer to the caller's remote port output.
    /* 14 */ union {
        u32 mRemoteIp;
        u16 *mRemotePortOut;
    };
    /* 18 */ u32 *mRemoteIpOut;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u8 mUnk_20[0xc];
} SOCLiCommandPacket;

s32 SOCLi_ExecCommandPacketInRecvPipe(SOCLSocket *socket, SOCLiCommandPacket *packet);
s32 SOCLi_ExecCommandPacket(SOCLiSocketCommandPipe *pipe, SOCLiCommandPacket *packet);
s32 SOCLi_SendCommandPacket(SOCLiSocketCommandPipe *pipe, SOCLiCommandPacket *packet);
void SOCLi_FreeCommandPacket(SOCLiCommandPacket *packet);
SOCLiCommandPacket *SOCLi_CreateCommandPacket(SOCLiCommandHandler handler, SOCLSocket *socket, s32 flag);
SOCLiCommandPacket *SOCLi_AllocCommandPacket(s32 flag);
s32 SOCLi_CleanupCommandPacketQueue(void);
s32 SOCLi_StartupCommandPacketQueue(s32 count);
u8 *SOCLi_InitCommandPipe(u8 *messages, SOCLiSocketCommandPipe *pipe, SOCLSocketCommandPipeParam *param);
u8 *SOCLi_InitSocketBuffer(u8 *cursor, SizedBuffer *buffer, s32 size);
u8 *SOCLi_InitSocket(SOCLSocket *socket, SOCLSocketParam *param);
int SOCLi_GetSizeCommandPipe(SOCLSocketCommandPipeParam *param);
