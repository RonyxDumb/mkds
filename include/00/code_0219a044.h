#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;

void gti2SocketError(Gt2Socket *socket);
void gti2FreeClosedConnections(Gt2Socket *socket);
