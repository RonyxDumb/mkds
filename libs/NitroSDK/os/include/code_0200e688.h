#pragma once

#include "types.h"
#include "os_thread.h"

void ThreadInitContext(OSThread *thread, void (*entry)(void *), u32 value);
