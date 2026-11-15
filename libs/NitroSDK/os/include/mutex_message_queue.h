#pragma once

#include "types.h"
#include "thread_scheduler.h"

BOOL OS_SaveContext(OSThread *thread);
void OS_LoadContext(OSThread *thread);
