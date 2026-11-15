#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;
typedef struct Gt2Socket Gt2Socket;

u8 *gt2GetConnectionData(Gt2Connection *object);
void gt2SetConnectionData(Gt2Connection *connection, void *data);
void SetUnmatchedDataCallback(Gt2Socket *socket, UnkWordFunc *callback);
u32 GetSocketDescriptor(u32 *socket);
int gt2GetOutgoingBufferFreeSpace(Gt2Connection *connection);
u16 GetSocketPort(Gt2Socket *socket);
