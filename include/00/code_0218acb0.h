#pragma once

#include "types.h"

typedef struct MatchingServerList MatchingServerList;

void SBEngineCleanup(MatchingServerList *matchingServerList);
void SBEngineHaltUpdates(MatchingServerList *matchingServerList);
void SBQueryEngineSetPublicIP(MatchingServerList *matchingServerList, u32 publicIp);
