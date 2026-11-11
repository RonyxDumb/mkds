#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Zeroed by GpConnectPreAuthenticatedA and passed to the callback.
typedef struct Unk0218f15cArg {
    /* 00 */ u32 mUnk_00[8];
} Unk0218f15cArg;

typedef void (*Unk0218f15cCb)(GpConnection *a, Unk0218f15cArg *b, u32 c);

u32 GpConnectPreAuthenticatedA(GpConnection *connection, s8 *authtoken, s8 *partnerchallenge, s32 firewall,
                               s32 blocking, Unk0218f15cCb callback, u32 param);
u32 GpSetCallback(GpConnection *connection, s32 func, void (*callback)(void *connection, void *func, u32 callback),
                  u32 param);
u32 GpUpdate(GpConnection *connection);
void GpDestroy(GpConnection *connection);
u32 GpInitialize(GpConnection *connection, s32 productID, s32 namespaceID);
int GpiUpdateConnection(void *connectionArgument, int blockingOperationID);
u32 gpiProcessConnectionManager(GpConnection *connection);
u32 GpiResetConnection(GpConnection *connection);
