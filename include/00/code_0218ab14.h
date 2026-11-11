#pragma once

#include "types.h"

typedef struct SbServer SbServer;
typedef struct SBQueryEngine SBQueryEngine;

BOOL ParseSingleICMPReply(SBQueryEngine *engine, SbServer *server, s8 *buf, s32 length);
