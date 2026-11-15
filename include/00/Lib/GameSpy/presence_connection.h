#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"

s32 gpiResetProfile(GpConnection *connection, GpiProfile *profile, void *data);

void gpiDestroy(GpConnection *connection);

typedef struct GpConnection GpConnection;

u32 GpiInitialize(GpConnection *connection, s32 titleNumber, s32 spaceId);
