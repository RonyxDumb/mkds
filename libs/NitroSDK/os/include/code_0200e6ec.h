#pragma once

#include "types.h"
#include "os_thread.h"

BOOL OS_SaveContext(OSThread *thread);
void OS_LoadContext(OSThread *thread);
