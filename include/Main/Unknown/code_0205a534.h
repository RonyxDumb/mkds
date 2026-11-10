#pragma once

#include "types.h"

typedef struct SlotResultSyncState SlotResultSyncState;

void CopySlotResultToPending(SlotResultSyncState *syncState);
