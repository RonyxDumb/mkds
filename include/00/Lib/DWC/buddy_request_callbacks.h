#pragma once

#include "types.h"


#include "00/Lib/DWC/login_process.h"
#include "00/Lib/GameSpy/peer_connection.h"

void DWCi_SetPersistDataValuesAsync(u32 profileId, u32 type, const char *valueString, u32 param);
void BuddySyncStatsAuthCallback(u32 localId, u32 profileId, u32 authenticated, const void *data, u32 instance);
void DWCi_GPGetInfoCallback_RecvAuthMessage(GpConnection *connection, GetInfoReply *arg, u32 param);
void DWCi_GPGetInfoCallback_RecvBuddyRequest(GpConnection *connection, GetInfoReply *arg, u32 param);
void DWCi_GPProfileSearchCallback(GpConnection *connection, ProfileSearchReply *arg, u32 friendIdx);
