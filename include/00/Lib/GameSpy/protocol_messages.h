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

void gt2Think(GTI2Socket *socket);
void gt2CloseSocket(GTI2Socket *socket);
u32 gt2CreateSocket(GTI2Socket **socket, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                    void (*callback)(GTI2Socket *));
int gti2Send(GTI2Connection *connection, u8 *message, int len, int reliable);
BOOL gti2ResendMessage(GTI2Connection *connection, GTI2OutgoingBufferMessage *message);
BOOL gti2SendClosedOnSocket(GTI2Socket *socket, u32 address, int port);
int gti2SendClosed(GTI2Connection *connection);
u32 gti2SendPong(GTI2Connection *connection, u8 *message, u32 len);
BOOL gti2SendNack(GTI2Connection *connection, u16 firstNumber, u16 lastNumber);
BOOL gti2SendAck(GTI2Connection *connection);
BOOL gti2SendAppUnreliable(GTI2Connection *connection, u8 *message, int len);

u32 gti2SendKeepAlive(GTI2Connection *connection);
u32 gti2SendClose(GTI2Connection *connection);
u32 gti2SendReject(GTI2Connection *connection, const void *message, int len);
u32 gti2SendAccept(GTI2Connection *connection);
u32 gti2SendClientResponse(GTI2Connection *connection, const u8 *response, const u8 *message, int len);
u32 gti2SendServerChallenge(GTI2Connection *connection, const u8 *response, const u8 *challenge);
u32 gti2SendClientChallenge(GTI2Connection *connection, const void *challenge);
u32 gti2SendAppReliable(GTI2Connection *connection, const u8 *message, int len);
u32 gti2EndReliableMessage(GTI2Connection *connection);

typedef struct GTI2Socket GTI2Socket;
typedef struct GTI2Connection GTI2Connection;

BOOL gti2BeginReliableMessage(GTI2Connection *connection, u32 type, int len, int *overflow);
u32 gti2StoreOutgoingReliableMessageInfo(GTI2Connection *connection, u16 serialNumber, s32 len);
u32 gti2ReceiveMessages(GTI2Socket *socket);
u32 gti2HandleConnectionReset(GTI2Socket *socket, u32 address, u32 port);
u32 gti2HandleMessage(GTI2Socket *socket, u8 *message, s32 len, u32 address, u32 port);
u32 gti2HandleUnreliableMessage(GTI2Connection *connection, u32 type, u8 *message, s32 len);
u32 gti2HandleClosed(GTI2Connection *connection);
u32 gti2HandlePong(GTI2Connection *connection, u8 *message, s32 len);

typedef struct GTI2Connection GTI2Connection;

u32 gti2HandlePing(GTI2Connection *connection, u8 *message, u32 len);

typedef struct GTI2Connection GTI2Connection;

u32 gti2HandleNack(GTI2Connection *connection, const u8 *message, s32 len);
u32 gti2HandleAck(GTI2Connection *connection, const u8 *message, s32 len);
u32 gti2HandleReliableMessage(GTI2Connection *connection, u32 type, const u8 *message, s32 len);

typedef struct GTI2Connection GTI2Connection;

void gti2SetPendingAck(GTI2Connection *connection);

typedef struct GTI2Connection GTI2Connection;

typedef struct GTI2IncomingBufferMessage {
    /* 00 */ s32 mStart;
    /* 04 */ s32 mLen;
    /* 08 */ s32 mType;
    /* 0c */ u16 mSerialNumber;
} GTI2IncomingBufferMessage;

u32 gti2DeliverHoldMessages(GTI2Connection *connection);
void gti2RemoveHoldMessage(GTI2Connection *connection, GTI2IncomingBufferMessage *message, s32 index);
u32 gti2BufferIncomingMessage(GTI2Connection *connection, s32 type, u32 serialNumber, const u8 *message, s32 len,
                              s32 *overflow);

s32 gti2IncomingBufferMessageCompare(const void *elem1, const void *elem2);

typedef struct GTI2Connection GTI2Connection;

u32 gti2DeliverReliableMessage(GTI2Connection *connection, int type, const u8 *message, u32 len);

typedef struct GTI2Connection GTI2Connection;

u32 gti2HandleClose(GTI2Connection *connection);
u32 gti2HandleReject(GTI2Connection *connection, void *message, u32 length);
u32 gti2HandleAccept(GTI2Connection *connection);
u32 gti2HandleClientResponse(GTI2Connection *connection, const u8 *message, int length);
u32 gti2HandleServerChallenge(GTI2Connection *connection, const u8 *message, int length);
u32 gti2HandleClientChallenge(GTI2Connection *connection, const u8 *message, int length);
u32 gti2HandleAppReliable(GTI2Connection *connection, const u8 *message, u32 length);
u32 gti2HandleAppUnreliable(GTI2Connection *connection, const u8 *message, s32 length);
u32 gti2HandleESN(GTI2Connection *connection, u32 esn);

typedef struct GTI2Connection GTI2Connection;

u32 gti2ConnectionMemoryError(GTI2Connection *connection);

typedef struct GTI2Connection GTI2Connection;

u32 gti2ConnectionCommunicationError(GTI2Connection *connection);

typedef struct GTI2Connection GTI2Connection;

u32 gti2ConnectionError(GTI2Connection *connection, u32 result, u32 reason);

int gti2SNDiff(int serialNumber1, int serialNumber2);

void gti2UShortToBuffer(u8 *buffer, s32 offset, u16 value);

u32 gti2UShortFromBuffer(const u8 *buffer, s32 offset);
