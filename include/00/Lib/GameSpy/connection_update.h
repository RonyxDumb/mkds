#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

int GpiUpdateConnection(void *connectionArgument, int blockingOperationID);
u32 gpiProcessConnectionManager(GpConnection *connection);
u32 GpiResetConnection(GpConnection *connection);
