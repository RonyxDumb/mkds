#pragma once

#include "types.h"

u32 DWCi_AreAllBuddies(u32 *pidList, u32 pidListLen);
void DWCi_PostProcessConnection(s32 type);
u32 DWCi_ChangeToClient(void);
u32 DWCi_CancelPreConnectedClientProcess(u32 serverPid);
u32 DWCi_CancelPreConnectedServerProcess(u32 clientPid);
u32 DWCi_CancelReservation(u32 profileId);
