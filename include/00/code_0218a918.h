#pragma once

#include "types.h"

typedef struct SbServer SbServer;
typedef struct SBQueryEngine SBQueryEngine;
typedef struct MatchingServerList MatchingServerList;

void SBQueryEngineRemoveServerFromFIFOs(MatchingServerList *matchingServerList, SbServer *server);
void SBQueryEngineAddQueryKey(SBQueryEngine *engine, u8 keyId);
void SBQueryEngineThink(MatchingServerList *matchingServerList);
void QueueNextQueries(SBQueryEngine *engine);
