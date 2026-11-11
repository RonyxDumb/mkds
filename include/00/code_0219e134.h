#pragma once

#include "types.h"

typedef struct MatchingServerList MatchingServerList;


void DWCi_SBPrintServerData(s32 server);
void WiFiMatchingServerListCallback(MatchingServerList *list, s32 event, s32 server);
u32 ReportMatchingConnectResult(u32 result);
s32 DWCi_HandleNNResult(s32 result);
s32 DWCi_HandleNNError(s32 error);
