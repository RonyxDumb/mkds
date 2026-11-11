#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;

u32 gti2DeliverReliableMessage(Gt2Connection *connection, int type, const u8 *message, u32 len);
