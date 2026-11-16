#pragma once

#include "types.h"
#include "Main/Unknown/code_020888b4.h"

void enmy_notifyDragItemChanged(KartAi *kartAi);
void enmy_notifySlotItemChanged(KartAi *kartAi);
void enmy_getTargetPosDir(Vec3 *position, Vec3 *direction, KartAi *kartAi);
void enmy_recalculateRoute(KartAi *kartAi);
void enmy_update(KartAi *kartAi);
void enmy_208C23C(KartAi *kartAi, PointLink *link);
void enmy_init(KartAi *kartAi, s32 kartIndex);
void enmy_setupFunctions(void);
