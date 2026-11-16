#pragma once

#include "types.h"
#include "00/Lib/GameSpy/connection_events.h"

// Milliseconds: an incoming connection that has not reached GT2_CONNECTION_AWAIT_DECISION is dropped after
// GTI2_SERVER_TIMEOUT (an outgoing one uses its own mTimeSinceCreateLimit), an unconfirmed message is sent
// again after GTI2_RESEND_TIME, an acknowledgement still unsent GTI2_PENDING_ACK_TIME after it was noted is sent by
// itself, and a connection that sent nothing for GTI2_KEEP_ALIVE_TIME gets a keep-alive message.
#define GTI2_SERVER_TIMEOUT 60000
#define GTI2_RESEND_TIME 1000
#define GTI2_PENDING_ACK_TIME 100
#define GTI2_KEEP_ALIVE_TIME 30000

u32 gti2ConnectionThink(GTI2Connection *connection, u32 now);

BOOL gti2CheckKeepAlive(GTI2Connection *connection, u32 now);
BOOL gti2CheckPendingAck(GTI2Connection *connection, u32 now);
BOOL gti2SendRetries(GTI2Connection *connection, u32 now);
BOOL gti2CheckTimeout(GTI2Connection *connection, u32 now);

u32 gti2ConnectionSendData(GTI2Connection *gt2Connection, u8 *data, u32 length);

void gti2RejectConnection(GTI2Connection *connection, void *message, u32 len, ...);
BOOL gti2AcceptConnection(GTI2Connection *connection, GT2ConnectionCallbacks *callbacks);
BOOL gti2StartConnectionAttempt(GTI2Connection *connection, void *message, int len, GT2ConnectionCallbacks *callbacks);
int gti2NewIncomingConnection(void *socket, GTI2Connection **connection, int address, u32 port);
int gti2NewOutgoingConnection(void *socket, GTI2Connection **connection, int address, u32 port);
