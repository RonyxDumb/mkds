#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"

s32 gpiResetProfile(GPConnection *connection, GPIProfile *profile, void *data);

void gpiDestroy(GPConnection *connection);

typedef struct GPConnection GPConnection;

u32 gpiInitialize(GPConnection *connection, s32 titleNumber, s32 spaceId);
