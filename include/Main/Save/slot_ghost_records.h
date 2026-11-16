#pragma once

#include "types.h"

void RunSomeATFunction(void *records);
void Task_StructFXRelated(void);

typedef struct GhostListEntry GhostListEntry;

GhostListEntry *AllocateFX(void *heap);
