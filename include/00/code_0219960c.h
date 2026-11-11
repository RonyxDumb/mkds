#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;

u32 gti2HandlePing(Gt2Connection *connection, u32 message, u32 len);
