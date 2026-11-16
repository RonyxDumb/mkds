#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/send_buffer.h"

u32 gpiProcessCallbacks(GPConnection *connection, s32 operationId);
void gpiCallCallback(GPConnection *connection, QueuedCallback *data);
u32 gpiAddCallback(GPConnection *connection, GPICallback callback, void *arg, GPIOperation *operation, s32 type);
void gpiCallErrorCallback(GPConnection *connection, s32 result, s32 fatal);
