#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

u16 GetOamMatrixCount(const RaceHudOamBuffer *oamList);
void CopyOamBuffersToMemory_from_thumb(void *mainOamList, void *subOamList);
