#pragma once

#include "types.h"

// 8 bytes, moved one byte at a time.
typedef struct SOCSockAddr {
    /* 00 */ u8 mLen;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mData[6];
} SOCSockAddr;

// Object ServerListConnect builds.
typedef struct SOCSockAddrIn {
    /* 0 */ u8 mLen;
    /* 1 */ u8 mFamily;
    /* 2 */ u16 mPort;
    /* 4 */ u32 mAddr;
} SOCSockAddrIn;

// Object SOC_GetHostByName returns; mUnk_0c points at a table of pointers to a word.
typedef struct SOCHostEnt {
    /* 00 */ char *mName;
    /* 04 */ u8 *mAliases;
    /* 08 */ s16 mAddrType;
    /* 0a */ s16 mLength;
    /* 0c */ u32 **mAddrList;
} SOCHostEnt;

// 8 bytes: descriptor, requested events and returned events.
typedef struct SOCPollFD {
    /* 00 */ s32 mFd;
    /* 04 */ s16 mEvents;
    /* 06 */ s16 mRevents;
} SOCPollFD;

extern u8 gAliases[];
extern s32 gGsiNitroErrno;
extern SOCHostEnt gLocalhost;
extern u32 gIps;
extern u32 *gIpPtrs[2];

u32 nextlongrand(u32 seed);
u32 GetUnixTime(u32 *timer);
u32 GOAGetLastError(s32 sock);
u32 inet_addr(u32 name);
s32 getsockname(u32 sock, void *addr, u32 *len);
u32 setsockopt(s32 sock, s32 level, s32 optname, void *optval, s32 optlen);
s32 getsockopt(s32 sock, s32 level, s32 optname, void *optval, s32 *optlen);
s32 sendto(s32 sock, void *buf, s32 len, s32 flags, void *addr, s32 tolen);
s32 send(s32 sock, void *buf, s32 len, s32 flags);
s32 recvfrom(s32 sock, void *buf, s32 len, s32 flags, void *addr, s32 *fromlen);
s32 recv(s32 sock, void *buf, s32 len, s32 flags);
s32 AcceptConnection(s32 sock, void *addr, s32 *len);
s32 listen();
s32 connect(s32 sock, void *addr, s32 len);
s32 bind(s32 sock, void *addr, s32 len);
s32 shutdown(s32 descriptor, s32 how);
s32 closesocket(s32 descriptor);
s32 OpenNetSocket(s32 domain, s32 type, s32 protocol);
s32 CheckRcode(s32 result, s32 fallback);
BOOL IsPrivateIP(u32 *addr);
SOCHostEnt *getlocalhost(void);
u32 CanSendOnSocket(u32 sock);
u32 CanReceiveOnSocket(u32 sock);
s32 GSISocketSelect(s32 theSocket, u32 *theReadFlag, u32 *theWriteFlag, u32 *theExceptFlag);
s32 GetSendBufferSize(s32 sock);
s32 GetReceiveBufferSize(s32 sock);
s32 SetSendBufferSize(s32 sock, u32 size);
s32 SetReceiveBufferSize(s32 sock, u32 size);
BOOL SetSockBlocking(s32 sock, s32 isblocking);
s8 *_strlwr(s8 *string);
void *goastrdup(const char *src);
void SocketShutDown(void);
void SocketStartUp(void);
void msleep(u32 msec);
u32 GetElapsedMilliseconds(void);
