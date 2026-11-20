#pragma once

#include "types.h"

typedef struct MatchingServerList MatchingServerList;
typedef struct SBServer SBServer;

void DWCi_SBPrintServerData(SBServer *server);
void DWCi_SBCallback(MatchingServerList *list, s32 event, SBServer *server, u32 instance);
u32 ReportMatchingConnectResult(u32 result);
s32 DWCi_HandleNNResult(s32 result);
s32 DWCi_HandleNNError(s32 error);
