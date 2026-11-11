#pragma once

#include "types.h"
#include "00/code_021a6fb4.h"

typedef struct SOCLiSocketRecvCommandPipe SOCLiSocketRecvCommandPipe;
typedef struct SOCLSocket SOCLSocket;

typedef s32 (*Unk021a78a4Func)(void *param_1, u32 param_2, SOCLSocket *param_3);

// Entry of the list behind mUnk_100 and mUnk_104 of an SOCLiSocketRecvCommandPipe; the data follows at mUnk_0c.
typedef struct SOCLiSocketUdpData {
    /* 00 */ struct SOCLiSocketUdpData *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
} SOCLiSocketUdpData;

// An SOCLiCommandPacket entry as SOCLi_ReadCallBack reads it.
typedef struct SOCLiCommandRead {
    /* 00 */ Unk021a7064Func mUnk_00;
    /* 04 */ SOCLSocket *mUnk_04;
    /* 08 */ OSMessageQueue *mUnk_08;
    /* 0c */ s8 mUnk_0c;
    /* 0d */ s8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u8 *mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u16 *mUnk_18;
    /* 1c */ u32 *mUnk_1c;
} SOCLiCommandRead;

extern s32 SOCLi_CheckCount[2];

s32 SOCLi_UdpRecvCallback(void *data, u32 length, SOCLSocket *socket);
s32 SOCLi_ReadUdpBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr, s32 isBlocking);
s32 SOCLi_ConsumeCPSBuffer(SOCLSocket *socket);
s32 SOCLi_ConsumeCallBack(SOCLiCommandPacket *command);
s32 SOCLi_ConsumeBuffer(SOCLSocket *socket);
s32 SOCLi_ReadCallBack(SOCLiCommandPacket *command);
