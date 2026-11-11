#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;

u32 gti2HandleNack(Gt2Connection *connection, const u8 *message, s32 len);
u32 gti2HandleAck(Gt2Connection *connection, const u8 *message, s32 len);
u32 gti2HandleReliableMessage(Gt2Connection *connection, u32 type, const u8 *message, s32 len);
