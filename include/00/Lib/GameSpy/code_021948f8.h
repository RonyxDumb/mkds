#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"
#include "00/Lib/GameSpy/code_0218e0e0.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/Lib/GameSpy/code_0219210c.h"

void GpiRemoveProfile(GpConnection *connection, GpiProfile *profile);
void GpiRemoveProfileById(GpConnection *connection, u32 profileid);
u32 GpiFindProfile(GpConnection *connection, u32 profileid, GpiProfile **profile);
GpiProfile *GpiFindOrAddProfile(GpConnection *connection, s32 id);
s32 gpiProcessNewProfile(GpConnection *connection, GpiOperation *operation, const char *input);
BOOL GpiInitProfileList(GpConnection *connection);
void GpiReleaseProfile(GpiProfile *profile);
