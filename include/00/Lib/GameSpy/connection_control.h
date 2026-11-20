#pragma once

#include "types.h"
#include "00/Lib/GameSpy/connection_events.h"

void gt2CloseAllConnectionsHard(GTI2Socket *socket);
void gti2CloseAllConnectionsHardMap(GTI2Connection **elem);
void gt2CloseConnectionHard(GTI2Connection *connection);
void gt2Send(GTI2Connection *connection, u8 *message, int len, int reliable);
int gt2Connect(void *socket, GTI2Connection **connection, const char *remoteAddress, void *message, int len, u32 timeout,
               GT2ConnectionCallbacks *callbacks, int blocking);
void gt2Reject(GTI2Connection *connection, void *message, u32 len);
int gt2Accept(GTI2Connection *connection, GT2ConnectionCallbacks *callbacks);

void gt2Listen(void *socket, void *callback);
