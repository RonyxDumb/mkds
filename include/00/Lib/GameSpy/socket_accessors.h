#pragma once

#include "types.h"
#include "00/Lib/GameSpy/connection_events.h"

typedef struct GTI2Connection GTI2Connection;
typedef struct GTI2Socket GTI2Socket;

u8 *gt2GetConnectionData(GTI2Connection *object);
void gt2SetConnectionData(GTI2Connection *connection, void *data);
void gt2SetUnrecognizedMessageCallback(GTI2Socket *socket, UnmatchedDataCallback callback);
u32 gt2GetSocketSOCKET(GTI2Socket *socket);
int gt2GetOutgoingBufferFreeSpace(GTI2Connection *connection);
u16 gt2GetLocalPort(GTI2Socket *socket);
