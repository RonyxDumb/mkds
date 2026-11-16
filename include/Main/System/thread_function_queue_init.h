#pragma once

#include "types.h"

typedef struct ThreadFunctionQueue ThreadFunctionQueue;

void InitializeWorker(void *heap);
void (*WorkerGetNextTaskFn(ThreadFunctionQueue *queue))(void);
