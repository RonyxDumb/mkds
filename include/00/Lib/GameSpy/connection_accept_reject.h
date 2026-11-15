#pragma once

#include "types.h"
#include "00/Lib/GameSpy/connection_close.h"

void gt2CloseAllConnectionsHard(Gt2Socket *socket);
void gti2CloseAllConnectionsHardMap(Gt2Connection **elem);
void gt2CloseConnectionHard(Gt2Connection *connection);
void gt2Send(Gt2Connection *connection, u8 *message, int len, int reliable);
int gt2Connect(void *socket, Gt2Connection **connection, const char *remoteAddress, void *message, int len, u32 timeout,
               Gt2ConnectionCallbacks *callbacks, int blocking);
void gt2Reject(Gt2Connection *connection, void *message, u32 len);
int gt2Accept(Gt2Connection *connection, Gt2ConnectionCallbacks *callbacks);

void gt2Listen(void *socket, void *callback);
