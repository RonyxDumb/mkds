#pragma once

#include "types.h"

void InitIndexLinks(u8 *usedHead, u8 *freeHead, u8 (*entries)[2]);
void InitItemDataQueueLinks(void);
void InitItemDataDelayedLinks(void);
