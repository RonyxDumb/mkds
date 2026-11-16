#pragma once

#include "types.h"

u32 scproc_getNextScene(void);
int scproc_getCurrentScene(void);
void scproc_overlay_205E0B0(void);
void scproc_init(void *heap);
s32 area_updateMissionRivalPassAreas(void);
u32 area_finalizeMissionRivalPassAreas(void);
