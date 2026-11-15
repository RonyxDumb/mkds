#pragma once

#include "types.h"


#include "00/Lib/DWC/code_0219c3e4.h"
#include "00/Lib/GameSpy/code_02193b88.h"

void DWCi_SetPersistDataValuesAsync(u32 profileId, u32 type, const char *valueString, u32 param);
void BuddySyncStatsAuthCallback(u32 localId, u32 profileId, u32 authenticated);
void DWCi_GPGetInfoCallback_RecvAuthMessage(GpConnection *connection, GetInfoReply *arg, u32 param);
void DWCi_GPGetInfoCallback_RecvBuddyRequest(GpConnection *connection, GetInfoReply *arg, u32 param);
void DWCi_GPProfileSearchCallback(GpConnection *connection, ProfileSearchReply *arg, u32 friendIdx);
