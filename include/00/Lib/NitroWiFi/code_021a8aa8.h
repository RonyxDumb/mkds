#pragma once

#include "types.h"
#include "00/Lib/NitroWiFi/code_021a6fa8.h"

// One entry of the array SOC_Poll takes: an object, the bits asked for and the bits found.
typedef struct SocketPollEntry {
    /* 00 */ SOCLSocket *mFd;
    /* 04 */ s16 mEvents;
    /* 06 */ u16 mRevents;
} SocketPollEntry;

typedef struct SOCSockAddrIn SOCSockAddrIn;

#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/wifi_library_globals.h"

void SOCLi_SocketUnregisterTrash(SOCLSocket *socket);
SOCLSocket **SOCLi_SocketGetNextPtr(SOCLSocket **head, SOCLSocket *node);
void SOCLi_SocketUnregisterList(SOCLSocket **head, SOCLSocket *node);
void SOCLi_SocketUnregister(SOCLSocket *socket);
void SOCLi_SocketRegisterTrash(SOCLSocket *socket);
void SOCLi_SocketRegisterList(u32 listAddress, u32 socketAddress);
void SOCLi_SocketRegister(void *socket);
s32 SOC_Poll(void *entries, s32 entryCount, s64 ticksLeft);
void SOC_U32to4U8(u32 word, u8 *bytes);
char *SOC_InetNtoP(s32 family, const void *source, char *destination, u32 length);
BOOL SOC_InetAtoN(const char *addressString, u32 *addressOut);
char *SOC_InetNtoA(SOCInAddr address);
s32 SOC_Cleanup(void);
s32 SOC_Startup(void *configPointer);
void FreeFunc_SOCL(u32 *memory);
void *AllocFunc_SOCL(u32 size);
// Commands of SOC_Fcntl and the bit of the flags that makes a socket not block.
#define SOC_F_GETFL 3
#define SOC_F_SETFL 4
#define SOC_O_NONBLOCK 4

s32 SOC_Fcntl(SOCLSocket *socket, s32 command, u32 mode);
s32 SOC_Accept(SOCLSocket *socket, SOCSockAddrIn *sockAddr, s32 unusedFlags);
s32 SOC_Listen(s32 descriptor);
void SOC_SetResolver(unsigned int *firstDns, unsigned int *secondDns);
unsigned int SOC_GetHostID(void);
s32 SOC_GetSockName(unsigned int socketHandle, void *sockAddr);
s32 SOC_Close(s32 descriptor);
s32 SOC_Shutdown(s32 descriptor);
s32 SOC_SendTo(s32 id, void *buffer, s32 length, s32 flags, void *addr);
s32 SOC_Send(s32 sockObj, void *buffer, s32 length, s32 flags);
s32 SOC_RecvFrom(s32 id, void *buffer, s32 length, s32 flags, void *addr);
s32 SOC_Recv(s32 sockObj, void *buffer, s32 length, s32 flags);
s32 SOC_Connect(SOCLSocket *socket, SOCSockAddrIn *sockAddr);
s32 SOC_Socket(s32 domain, s32 type, s32 protocol);
