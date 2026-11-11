#pragma once

#include "00/code_02197e58.h"
#include "types.h"

void gti2RejectConnection(Gt2Connection *connection, void *message, u32 len, ...);
BOOL gti2AcceptConnection(Gt2Connection *connection, Gt2ConnectionCallbacks *callbacks);
BOOL gti2StartConnectionAttempt(Gt2Connection *connection, void *message, int len, Gt2ConnectionCallbacks *callbacks);
int gti2NewIncomingConnection(void *socket, Gt2Connection **connection, int address, u32 port);
int gti2NewOutgoingConnection(void *socket, Gt2Connection **connection, int address, u32 port);
