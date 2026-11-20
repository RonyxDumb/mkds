#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/table_create.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/info_cache_free.h"

void gpiRemoveProfile(GPConnection *connection, GPIProfile *profile);
void gpiRemoveProfileByID(GPConnection *connection, u32 profileid);
u32 gpiGetProfile(GPConnection *connection, u32 profileid, GPIProfile **profile);
GPIProfile *gpiProfileListAdd(GPConnection *connection, s32 id);
s32 gpiProcessNewProfile(GPConnection *connection, GPIOperation *operation, const char *input);
BOOL gpiInitProfiles(GPConnection *connection);
void gpiProfilesTableFree(GPIProfile *profile);
