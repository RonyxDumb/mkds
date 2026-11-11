#pragma once

#include "types.h"
#include "00/code_02197e58.h"

BOOL gti2CheckKeepAlive(Gt2Connection *connection, u32 now);
BOOL gti2CheckPendingAck(Gt2Connection *connection, u32 now);
BOOL gti2SendRetries(Gt2Connection *connection, u32 now);
BOOL gti2CheckTimeout(Gt2Connection *connection, u32 now);
