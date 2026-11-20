#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"

typedef struct GPIConnectData GPIConnectData;

int gpiCheckConnect(GPConnection *connection);
u32 gpiProcessConnect(GPConnection *connection, GPIOperation *operation, const char *input);
u32 gpiSendNewuser(GPConnection *connection, GPIConnectData *data);
