#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;
typedef struct Gt2Socket Gt2Socket;

typedef struct Gt2ConnectionView {
    /* 00 */ u8 mUnk_00[0x40];
    /* 40 */ u8 *mData;
} Gt2ConnectionView;

u8 *gt2GetConnectionData(Gt2ConnectionView *object);
void gt2SetConnectionData(Gt2ConnectionView *connection, void *data);
void SetUnmatchedDataCallback(Gt2Socket *socket, UnkWordFunc *callback);
u32 GetSocketDescriptor(u32 *socket);
int gt2GetOutgoingBufferFreeSpace(Gt2Connection *connection);
u16 GetSocketPort(Gt2Socket *socket);
