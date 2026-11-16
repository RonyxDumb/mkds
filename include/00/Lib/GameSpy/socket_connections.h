#pragma once

#include "types.h"
#include "00/Lib/GameSpy/connection_events.h"

typedef struct GTI2Socket GTI2Socket;

void gti2SocketError(GTI2Socket *socket);
void gti2FreeClosedConnections(GTI2Socket *socket);

u32 gti2SocketConnectionsThink(GTI2Socket *socket);

typedef struct GTI2Socket GTI2Socket;
typedef struct GTI2Connection GTI2Connection;

u32 gti2SocketConnectionsThinkMap(GTI2Connection **element, u32 *clientData);
u32 gti2SocketSend(GTI2Socket *socket, u32 address, int port, u32 message, u32 length);
void gti2FreeSocketConnection(GTI2Connection *connection);
u32 gti2NewSocketConnection(GTI2Socket *socket, GTI2Connection **connectionOut, u32 address, u32 port);

GTI2Connection *gti2CreateConnectionObject(void);

typedef struct GTI2Socket GTI2Socket;

void SetIncomingConnectionCallback(GTI2Socket *gt2Socket, void *callback);
void DeleteSocket(GTI2Socket *gt2Socket);

typedef struct GTI2Socket GTI2Socket;
typedef struct GTI2Connection GTI2Connection;

u32 gti2CreateSocket(GTI2Socket **socketOut, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                     void (*errorCallback)(GTI2Socket *));
GTI2Connection *gti2SocketFindConnection(GTI2Socket *socket, u32 address, u32 port);
void gti2ConnectionFree(GTI2Connection **element);

s32 gti2ConnectionCompare(const GTI2Connection *const *left, const GTI2Connection *const *right);

typedef struct GTI2Connection GTI2Connection;

typedef struct Gt2ConnectionEntry {
    /* 00 */ GTI2Connection *mValue;
} Gt2ConnectionEntry;

u32 gti2ConnectionHash(const Gt2ConnectionEntry *object, u32 modulus);
