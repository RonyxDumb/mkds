#pragma once

#include "types.h"
#include "thread_scheduler.h"

void ThreadInitContext(OSThread *thread, void (*entry)(void *), u32 value);
