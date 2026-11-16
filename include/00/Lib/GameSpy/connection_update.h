#pragma once

#include "types.h"

typedef struct GPConnection GPConnection;

int gpiProcess(void *connectionArgument, int blockingOperationID);
u32 gpiProcessConnectionManager(GPConnection *connection);
u32 gpiReset(GPConnection *connection);
