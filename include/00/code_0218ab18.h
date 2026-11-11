#pragma once

#include "types.h"

typedef struct SbServer SbServer;
typedef struct SBQueryEngine SBQueryEngine;

extern char gGoaFinalMarker[];

void ParseSingleGOAReply(SBQueryEngine *engine, SbServer *server, s8 *buf, s32 length);
void ParseSingleQR2Reply(SBQueryEngine *engine, SbServer *server, s8 *buf, s32 length);
void SBQueryEngineUpdateServer(SBQueryEngine *engine, SbServer *server, s32 atFront, s32 updateKind);
