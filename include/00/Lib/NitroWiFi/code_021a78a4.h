#pragma once

#include "types.h"
#include "00/Lib/NitroWiFi/code_021a6fb4.h"

typedef struct SOCLiSocketRecvCommandPipe SOCLiSocketRecvCommandPipe;
typedef struct SOCLSocket SOCLSocket;

typedef s32 (*CPSUDPReadCallback)(void *data, u32 length, SOCLSocket *socket);

// Entry of the list behind mUnk_100 and mUnk_104 of an SOCLiSocketRecvCommandPipe; the data follows at mUnk_0c.
typedef struct SOCLiSocketUdpData {
    /* 00 */ struct SOCLiSocketUdpData *mNext;
    /* 04 */ u16 mSize;
    /* 06 */ u16 mRemotePort;
    /* 08 */ u32 mRemoteIp;
    /* 0c */ u8 mData[4];
} SOCLiSocketUdpData;

// An SOCLiCommandPacket entry as SOCLi_ReadCallBack reads it.
typedef struct SOCLiCommandRead {
    /* 00 */ SOCLiCommandHandler mUnk_00;
    /* 04 */ SOCLSocket *mSocket;
    /* 08 */ OSMessageQueue *mUnk_08;
    /* 0c */ s8 mUnk_0c;
    /* 0d */ s8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u8 *mBuffer;
    /* 14 */ s32 mBufferLen;
    /* 18 */ u16 *mRemotePort;
    /* 1c */ u32 *mRemoteIp;
} SOCLiCommandRead;

s32 SOCLi_UdpRecvCallback(void *data, u32 length, SOCLSocket *socket);
s32 SOCLi_ReadUdpBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr, s32 isBlocking);
s32 SOCLi_ConsumeCPSBuffer(SOCLSocket *socket);
s32 SOCLi_ConsumeCallBack(SOCLiCommandPacket *command);
s32 SOCLi_ConsumeBuffer(SOCLSocket *socket);
s32 SOCLi_ReadCallBack(SOCLiCommandPacket *command);
