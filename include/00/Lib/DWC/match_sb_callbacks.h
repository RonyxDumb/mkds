#pragma once

#include "types.h"

typedef struct MatchingServerList MatchingServerList;
typedef struct SbServer SbServer;

void DWCi_SBPrintServerData(SbServer *server);
void DWCi_SBCallback(MatchingServerList *list, s32 event, SbServer *server, u32 instance);
u32 ReportMatchingConnectResult(u32 result);
s32 DWCi_HandleNNResult(s32 result);
s32 DWCi_HandleNNError(s32 error);
