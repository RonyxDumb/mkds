#pragma once

#include "types.h"
#include "thread_scheduler.h"

void Arm_Context_Create(OSThread *thread, void (*entry)(void *), u32 value);
