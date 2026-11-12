#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_02197e58.h"

u32 gti2ConnectionThink(Gt2Connection *connection, u32 now);

BOOL gti2CheckKeepAlive(Gt2Connection *connection, u32 now);
BOOL gti2CheckPendingAck(Gt2Connection *connection, u32 now);
BOOL gti2SendRetries(Gt2Connection *connection, u32 now);
BOOL gti2CheckTimeout(Gt2Connection *connection, u32 now);

u32 SendConnectionBytes(Gt2Connection *a, u8 *b, u32 c);

void gti2RejectConnection(Gt2Connection *connection, void *message, u32 len, ...);
BOOL gti2AcceptConnection(Gt2Connection *connection, Gt2ConnectionCallbacks *callbacks);
BOOL gti2StartConnectionAttempt(Gt2Connection *connection, void *message, int len, Gt2ConnectionCallbacks *callbacks);
int gti2NewIncomingConnection(void *socket, Gt2Connection **connection, int address, u32 port);
int gti2NewOutgoingConnection(void *socket, Gt2Connection **connection, int address, u32 port);
