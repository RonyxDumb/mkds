#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218f960.h"

typedef struct GPIConnectData GPIConnectData;

int gpiCheckConnect(GpConnection *connection);
u32 GpiProcessConnectOperation(GpConnection *connection, GpiOperation *operation, const char *input);
u32 GpiWriteNewuser(GpConnection *connection, GPIConnectData *data);
