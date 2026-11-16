#pragma once

#include "types.h"

typedef struct ThreadFunctionQueue ThreadFunctionQueue;

void bgwkr_init(void *heap);
void (*bgwkr_dequeueTask(ThreadFunctionQueue *a))(void);
