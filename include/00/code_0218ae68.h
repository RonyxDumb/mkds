#pragma once

#include "types.h"

typedef struct SbServer SbServer;
typedef struct SBServerFIFO SBServerFIFO;

BOOL FIFORemove(SBServerFIFO *fifo, SbServer *server);
