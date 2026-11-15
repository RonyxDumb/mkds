#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/GameSpy/code_021906e4.h"

u32 GpiCallQueuedCallbacks(GpConnection *connection, s32 operationId);
void GpiCallAndFreeCallback(GpConnection *connection, GpiQueuedCallback *data);
u32 GpiQueueCallback(GpConnection *connection, GpiCallback callback, void *arg, GpiOperation *operation, s32 type);
void GpiQueueErrorCallback(GpConnection *connection, s32 result, s32 fatal);
