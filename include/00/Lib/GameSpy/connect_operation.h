#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"

typedef struct GPIConnectData GPIConnectData;

int gpiCheckConnect(GpConnection *connection);
u32 gpiProcessConnect(GpConnection *connection, GpiOperation *operation, const char *input);
u32 gpiSendNewuser(GpConnection *connection, GPIConnectData *data);
