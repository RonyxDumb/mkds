#pragma once

#include "types.h"

void StartReadSlotGhostRecords(void *records);
void ReadSlotGhostRecords(void);

typedef struct GhostListEntry GhostListEntry;

GhostListEntry *CreateSlotGhostRecords(void *heap);
