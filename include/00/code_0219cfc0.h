#pragma once

#include "types.h"

typedef struct GpBuddyStatus GpBuddyStatus;

int ReportBuddySyncStatsResult(int error);
int ReportBuddySyncGpResult(int result);
u32 DWCi_GetFriendBuddyStatus(void *friendData, GpBuddyStatus *status);
