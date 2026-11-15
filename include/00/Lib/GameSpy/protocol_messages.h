#pragma once

#include "types.h"
#include "00/Lib/GameSpy/connection_events.h"

typedef struct GTI2OutgoingBufferMessage {
    /* 00 */ s32 mStart;
    /* 04 */ s32 mLen;
    /* 08 */ u16 mSerialNumber;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ u32 mLastSend;
} GTI2OutgoingBufferMessage;

void gt2Think(Gt2Socket *socket);
void gt2CloseSocket(Gt2Socket *socket);
u32 gt2CreateSocket(Gt2Socket **socket, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                    void (*callback)(Gt2Socket *));
int gti2Send(Gt2Connection *connection, u8 *message, int len, int reliable);
BOOL gti2ResendMessage(Gt2Connection *connection, GTI2OutgoingBufferMessage *message);
BOOL gti2SendClosedOnSocket(Gt2Socket *socket, u32 address, int port);
int gti2SendClosed(Gt2Connection *connection);
u32 gti2SendPong(Gt2Connection *connection, u8 *message, u32 len);
BOOL gti2SendNack(Gt2Connection *connection, u16 firstNumber, u16 lastNumber);
BOOL gti2SendAck(Gt2Connection *connection);
BOOL gti2SendAppUnreliable(Gt2Connection *connection, u8 *message, int len);

u32 gti2SendKeepAlive(Gt2Connection *connection);
u32 gti2SendClose(Gt2Connection *connection);
u32 gti2SendReject(Gt2Connection *connection, const void *message, int len);
u32 gti2SendAccept(Gt2Connection *connection);
u32 gti2SendClientResponse(Gt2Connection *connection, const u8 *response, const u8 *message, int len);
u32 gti2SendServerChallenge(Gt2Connection *connection, const u8 *response, const u8 *challenge);
u32 gti2SendClientChallenge(Gt2Connection *connection, const void *challenge);
u32 gti2SendAppReliable(Gt2Connection *connection, const u8 *message, int len);
u32 gti2EndReliableMessage(Gt2Connection *connection);

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

BOOL gti2BeginReliableMessage(Gt2Connection *connection, u32 type, int len, int *overflow);
u32 gti2StoreOutgoingReliableMessageInfo(Gt2Connection *connection, u16 serialNumber, s32 len);
u32 gti2ReceiveMessages(Gt2Socket *socket);
u32 gti2HandleConnectionReset(Gt2Socket *socket, u32 address, u32 port);
u32 gti2HandleMessage(Gt2Socket *socket, u8 *message, s32 len, u32 address, u32 port);
u32 gti2HandleUnreliableMessage(Gt2Connection *connection, u32 type, u8 *message, s32 len);
u32 gti2HandleClosed(Gt2Connection *connection);
u32 gti2HandlePong(Gt2Connection *connection, u8 *message, s32 len);

typedef struct Gt2Connection Gt2Connection;

u32 gti2HandlePing(Gt2Connection *connection, u8 *message, u32 len);

typedef struct Gt2Connection Gt2Connection;

u32 gti2HandleNack(Gt2Connection *connection, const u8 *message, s32 len);
u32 gti2HandleAck(Gt2Connection *connection, const u8 *message, s32 len);
u32 gti2HandleReliableMessage(Gt2Connection *connection, u32 type, const u8 *message, s32 len);

typedef struct Gt2Connection Gt2Connection;

void gti2SetPendingAck(Gt2Connection *connection);

typedef struct Gt2Connection Gt2Connection;

typedef struct GTI2IncomingBufferMessage {
    /* 00 */ s32 mStart;
    /* 04 */ s32 mLen;
    /* 08 */ s32 mType;
    /* 0c */ u16 mSerialNumber;
} GTI2IncomingBufferMessage;

u32 gti2DeliverHoldMessages(Gt2Connection *connection);
void gti2RemoveHoldMessage(Gt2Connection *connection, GTI2IncomingBufferMessage *message, s32 index);
u32 gti2BufferIncomingMessage(Gt2Connection *connection, s32 type, u32 serialNumber, const u8 *message, s32 len,
                              s32 *overflow);

s32 gti2IncomingBufferMessageCompare(const void *elem1, const void *elem2);

typedef struct Gt2Connection Gt2Connection;

u32 gti2DeliverReliableMessage(Gt2Connection *connection, int type, const u8 *message, u32 len);

typedef struct Gt2Connection Gt2Connection;

u32 gti2HandleClose(Gt2Connection *connection);
u32 gti2HandleReject(Gt2Connection *connection, void *message, u32 length);
u32 gti2HandleAccept(Gt2Connection *connection);
u32 gti2HandleClientResponse(Gt2Connection *connection, const u8 *message, int length);
u32 gti2HandleServerChallenge(Gt2Connection *connection, const u8 *message, int length);
u32 gti2HandleClientChallenge(Gt2Connection *connection, const u8 *message, int length);
u32 gti2HandleAppReliable(Gt2Connection *connection, const u8 *message, u32 length);
u32 gti2HandleAppUnreliable(Gt2Connection *connection, const u8 *message, s32 length);
u32 gti2HandleESN(Gt2Connection *connection, u32 esn);

typedef struct Gt2Connection Gt2Connection;

u32 gti2ConnectionMemoryError(Gt2Connection *connection);

typedef struct Gt2Connection Gt2Connection;

u32 gti2ConnectionCommunicationError(Gt2Connection *connection);

typedef struct Gt2Connection Gt2Connection;

u32 gti2ConnectionError(Gt2Connection *connection, u32 result, u32 reason);

int gti2SNDiff(int serialNumber1, int serialNumber2);

void gti2UShortToBuffer(u8 *buffer, s32 offset, u16 value);

u32 gti2UShortFromBuffer(const u8 *buffer, s32 offset);
