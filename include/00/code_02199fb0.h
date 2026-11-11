#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;

u32 gti2ConnectionError(Gt2Connection *connection, u32 result, u32 reason);
