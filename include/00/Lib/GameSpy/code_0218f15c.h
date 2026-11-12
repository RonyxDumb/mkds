#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

typedef struct ConnectReply ConnectReply;

typedef void (*GpConnectCb)(GpConnection *a, ConnectReply *b, u32 c);

u32 GpConnectPreAuthenticatedA(GpConnection *connection, s8 *authtoken, s8 *partnerchallenge, s32 firewall,
                               s32 blocking, GpConnectCb callback, u32 param);
u32 GpSetCallback(GpConnection *connection, s32 func, void (*callback)(void *connection, void *func, u32 callback),
                  u32 param);
u32 GpUpdate(GpConnection *connection);
void GpDestroy(GpConnection *connection);
u32 GpInitialize(GpConnection *connection, s32 productID, s32 namespaceID);
int GpiUpdateConnection(void *connectionArgument, int blockingOperationID);
u32 gpiProcessConnectionManager(GpConnection *connection);
u32 GpiResetConnection(GpConnection *connection);
