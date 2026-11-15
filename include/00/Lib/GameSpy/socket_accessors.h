#pragma once

#include "types.h"
#include "00/Lib/GameSpy/connection_close.h"

typedef struct Gt2Connection Gt2Connection;
typedef struct Gt2Socket Gt2Socket;

u8 *gt2GetConnectionData(Gt2Connection *object);
void gt2SetConnectionData(Gt2Connection *connection, void *data);
void SetUnmatchedDataCallback(Gt2Socket *socket, Gt2UnmatchedDataCallback callback);
u32 GetSocketDescriptor(Gt2Socket *socket);
int gt2GetOutgoingBufferFreeSpace(Gt2Connection *connection);
u16 GetSocketPort(Gt2Socket *socket);
