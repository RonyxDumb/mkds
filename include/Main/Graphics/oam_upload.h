#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

u16 GetOamMatrixCount(const RaceHudOamBuffer *oamList);
void UploadOamLists(void *mainOamList, void *subOamList);
