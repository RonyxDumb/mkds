#pragma once

#include "types.h"

u32 DWCi_RetryReserving();
u32 DWCi_SendResvCommandToFriend(s32 delay, s32 init);
u32 DWCi_SendResvCommand(u32 profileId, s32 delay);
u32 DWCi_HandleMatchCommandError(u32 result);
void DWCi_MakeBackupServerData(u32 senderProfileId, u32 *values);
u32 DWCi_ProcessResvOK(u32 profileId, u32 address, u16 port);
s32 DWCi_CheckResvCommand(s32 profileId, u32 senderMode, s32 priorFlag);
