#pragma once

#include "types.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"

int gpiCheckConnect(GpConnection *connection);
u32 GpiProcessConnectOperation(GpConnection *connection, GpiOperation *operation, const char *input);
u32 GpiWriteNewuser(GpConnection *connection, Unk02191284Data *data);
