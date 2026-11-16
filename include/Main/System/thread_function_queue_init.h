#pragma once

#include "types.h"

typedef struct ThreadFunctionQueue ThreadFunctionQueue;

void InitThreadFunctionQueue(void *heap);
void (*DequeueThreadFunction(ThreadFunctionQueue *queue))(void);
