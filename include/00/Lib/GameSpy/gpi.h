#pragma once

#include "types.h"
#include "00/code_0218d000.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/code_02190000.h"
#include "00/code_021a3000.h"

u32 gpiResetProfile(u32 connection, u32 profile);

void gpiDestroy(GpConnection *connection);

typedef struct GpConnection GpConnection;

u32 GpiInitialize(GpConnection *a, s32 b, s32 c);
