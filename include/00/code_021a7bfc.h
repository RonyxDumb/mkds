#pragma once

#include "types.h"
#include "00/code_021a6fb4.h"

typedef struct SOCLiSocketCommandPipe SOCLiSocketCommandPipe;
typedef struct SOCLSocket SOCLSocket;

// An SOCLiCommandPacket entry as SOCLi_MemCpy and the functions after it see it.
typedef struct SOCLiCommandWrite {
    /* 00 */ Unk021a7064Func mUnk_00;
    /* 04 */ SOCLSocket *mUnk_04;
    /* 08 */ OSMessageQueue *mUnk_08;
    /* 0c */ s8 mUnk_0c;
    /* 0d */ s8 mUnk_0d;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ u8 *mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
    /* 28 */ u16 *mUnk_28;
} SOCLiCommandWrite;

u8 *SOCLi_ReadCPSBuffer(SOCLSocket *socket, s32 *lengthOut, u16 *localPortOut, u16 *remotePortOut, u32 *remoteIpOut);
s32 SOCLi_CopyCPSBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr);
s32 SOCLi_ReadBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr, s32 isBlocking);
s32 SOCLi_ReadAndConsumeBuffer(SOCLSocket *socket, void *buffer, s32 length, u16 *remotePort, u32 *peerAddr,
                               s32 isBlocking, s32 flags);
s32 SOCL_ReadFrom(unsigned int socketHandle, void *buffer, unsigned int length, unsigned int remotePort, u32 *peerAddr,
                  unsigned int flags);
s32 SOCLi_MemCpy(const void *destination, s32 capacity, SOCLiCommandWrite *command);
s32 SOCLi_WriteCallBack(SOCLiCommandPacket *command);
s32 SOCLi_ExecWriteCommand(SOCLSocket *socket, u8 *buffer, s32 length, s32 ringIn, u16 remotePort, u16 *peerAddr,
                           s32 isBlocking);
s32 SOCLi_GetWriteBufferFreeSize(SOCLSocket *socket);
s32 SOCLi_AllocWriteBuffer(SOCLSocket *socket, s32 maxSize, s32 lowestSize, u32 *ringInPtr, s32 isBlocking);
s32 SOCLi_WriteBuffer(SOCLSocket *socket, u8 *buffer, s32 length, u16 remotePort, u16 *peerAddr, s32 isBlocking);
s32 SOCL_WriteTo(u32 socketHandle, void *buffer, u32 length, u16 remotePort, u32 peerAddr, u32 flags);
s32 SOCLi_ShutdownCallBack(SOCLiCommandPacket *command);
s32 SOCL_Shutdown(s32 sockObj);
void SOCLi_FreeCommandPipe(SOCLiSocketCommandPipe *pipe);
void SOCLi_CleanupSocket(SOCLSocket *socket);
s32 SOCLi_CloseCallBack(SOCLiCommandPacket *command);
s32 SOCL_Close(s32 sockObj);
