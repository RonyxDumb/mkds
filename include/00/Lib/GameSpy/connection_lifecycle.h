#pragma once

#include "types.h"
#include "00/Lib/GameSpy/connection_events.h"

// Milliseconds: a connection that has not finished connecting is dropped after SERVER_TIMEOUT, an unconfirmed message
// is sent again after RESEND_TIME, an acknowledgement waits PENDING_ACK_TIME for company, and a connection that sent
// nothing for KEEP_ALIVE_TIME gets a keep-alive message.
#define GTI2_SERVER_TIMEOUT 60000
#define GTI2_RESEND_TIME 1000
#define GTI2_PENDING_ACK_TIME 100
#define GTI2_KEEP_ALIVE_TIME 30000

u32 gti2ConnectionThink(Gt2Connection *connection, u32 now);

BOOL gti2CheckKeepAlive(Gt2Connection *connection, u32 now);
BOOL gti2CheckPendingAck(Gt2Connection *connection, u32 now);
BOOL gti2SendRetries(Gt2Connection *connection, u32 now);
BOOL gti2CheckTimeout(Gt2Connection *connection, u32 now);

u32 SendConnectionBytes(Gt2Connection *gt2Connection, u8 *data, u32 length);

void gti2RejectConnection(Gt2Connection *connection, void *message, u32 len, ...);
BOOL gti2AcceptConnection(Gt2Connection *connection, Gt2ConnectionCallbacks *callbacks);
BOOL gti2StartConnectionAttempt(Gt2Connection *connection, void *message, int len, Gt2ConnectionCallbacks *callbacks);
int gti2NewIncomingConnection(void *socket, Gt2Connection **connection, int address, u32 port);
int gti2NewOutgoingConnection(void *socket, Gt2Connection **connection, int address, u32 port);
