#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/table_create.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/GameSpy/info_cache_free.h"

void GpiRemoveProfile(GpConnection *connection, GpiProfile *profile);
void GpiRemoveProfileById(GpConnection *connection, u32 profileid);
u32 GpiFindProfile(GpConnection *connection, u32 profileid, GpiProfile **profile);
GpiProfile *GpiFindOrAddProfile(GpConnection *connection, s32 id);
s32 gpiProcessNewProfile(GpConnection *connection, GpiOperation *operation, const char *input);
BOOL GpiInitProfileList(GpConnection *connection);
void GpiReleaseProfile(GpiProfile *profile);
