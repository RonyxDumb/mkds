#pragma once

#include "types.h"
#include "00/Lib/GameSpy/connection_events.h"

typedef struct Gt2Socket Gt2Socket;

void gti2SocketError(Gt2Socket *socket);
void gti2FreeClosedConnections(Gt2Socket *socket);

u32 gti2SocketConnectionsThink(Gt2Socket *socket);

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

u32 gti2SocketConnectionsThinkMap(Gt2Connection **element, u32 *clientData);
u32 gti2SocketSend(Gt2Socket *socket, u32 address, int port, u32 message, u32 length);
void gti2FreeSocketConnection(Gt2Connection *connection);
u32 gti2NewSocketConnection(Gt2Socket *socket, Gt2Connection **connectionOut, u32 address, u32 port);

Gt2Connection *gti2CreateConnectionObject(void);

typedef struct Gt2Socket Gt2Socket;

void SetIncomingConnectionCallback(Gt2Socket *gt2Socket, void *callback);
void DeleteSocket(Gt2Socket *gt2Socket);

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

u32 gti2CreateSocket(Gt2Socket **socketOut, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                     void (*errorCallback)(Gt2Socket *));
Gt2Connection *gti2SocketFindConnection(Gt2Socket *socket, u32 address, u32 port);
void gti2ConnectionFree(Gt2Connection **element);

s32 gti2ConnectionCompare(const Gt2Connection *const *left, const Gt2Connection *const *right);

typedef struct Gt2Connection Gt2Connection;

typedef struct Gt2ConnectionEntry {
    /* 00 */ Gt2Connection *mValue;
} Gt2ConnectionEntry;

u32 gti2ConnectionHash(const Gt2ConnectionEntry *object, u32 modulus);
