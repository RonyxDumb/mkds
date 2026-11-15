#pragma once

#include "types.h"
#include "00/code_0218d000.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_02190000.h"
#include "00/code_021a3000.h"

s32 gpiResetProfile(GpConnection *connection, GpiProfile *profile, void *data);

void gpiDestroy(GpConnection *connection);

typedef struct GpConnection GpConnection;

u32 GpiInitialize(GpConnection *connection, s32 titleNumber, s32 spaceId);
