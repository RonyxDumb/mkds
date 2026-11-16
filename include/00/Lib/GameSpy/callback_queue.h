#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/GameSpy/send_buffer.h"

u32 gpiProcessCallbacks(GpConnection *connection, s32 operationId);
void gpiCallCallback(GpConnection *connection, GpiQueuedCallback *data);
u32 gpiAddCallback(GpConnection *connection, GpiCallback callback, void *arg, GpiOperation *operation, s32 type);
void gpiCallErrorCallback(GpConnection *connection, s32 result, s32 fatal);
