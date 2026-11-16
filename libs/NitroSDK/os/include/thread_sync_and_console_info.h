#pragma once

#include "types.h"
#include "thread_scheduler.h"

BOOL Arm_Context_Save(OSThread *thread);
void Arm_Context_Load(OSThread *thread);
