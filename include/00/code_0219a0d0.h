#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

u32 gti2SocketConnectionsThinkMap(Gt2Connection **element, u32 *clientData);
u32 gti2SocketSend(u32 *socketPointer, u32 address, int port, u32 message, u32 length);
void gti2FreeSocketConnection(Gt2Connection *connection);
u32 CreateConnection(Gt2Socket *socket, Gt2Connection **connectionOut, u32 address, u32 port);
