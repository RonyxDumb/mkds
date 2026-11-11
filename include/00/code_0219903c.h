#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

typedef struct GTI2OutgoingBufferMessage {
    /* 00 */ s32 mStart;
    /* 04 */ s32 mLen;
    /* 08 */ u16 mSerialNumber;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ u32 mLastSend;
} GTI2OutgoingBufferMessage;

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

extern const u8 gPingTimeId[];

BOOL gti2BeginReliableMessage(Gt2Connection *connection, u32 type, int len, int *overflow);
u32 gti2StoreOutgoingReliableMessageInfo(Gt2Connection *connection, u16 serialNumber, s32 len);
u32 gti2ReceiveMessages(Gt2Socket *socket);
u32 gti2HandleConnectionReset(Gt2Socket *socket, u32 address, u32 port);
u32 gti2HandleMessage(Gt2Socket *socket, u8 *message, s32 len, u32 address, u32 port);
u32 gti2HandleUnreliableMessage(Gt2Connection *connection, u32 type, u8 *message, s32 len);
u32 gti2HandleClosed(Gt2Connection *connection);
u32 gti2HandlePong(Gt2Connection *connection, u8 *message, s32 len);
