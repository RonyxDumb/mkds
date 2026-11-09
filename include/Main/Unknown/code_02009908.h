#pragma once

#include "types.h"

void SetScanBssidCallbacks(void (*setCallback)(const u8 *), void (*clearCallback)(void));
void SetEntryTable(void *entryTable);
