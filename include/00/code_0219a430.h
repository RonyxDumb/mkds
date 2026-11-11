#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

u32 gti2CreateSocket(Gt2Socket **socketOut, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                     u32 errorCallback);
Gt2Connection *gti2SocketFindConnection(Gt2Socket *socket, u32 address, u32 port);
void gti2ConnectionFree(Gt2Connection **element);
