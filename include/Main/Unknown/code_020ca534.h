#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

void mpicn_updateShine16Icon(void);
void mpicn_renderShine16Icon(RaceHudOamBuffer *a);
s32 mpicn_createCrabIcon(void);
