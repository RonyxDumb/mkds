#pragma once

#include "types.h"

typedef struct KartAi KartAi;

void enmy_notifyDragItemChangedForRace(KartAi *kartAi);
void enmy_notifySlotItemChangedForRace(KartAi *kartAi);
void enmy_getTargetEpoiPosDir(Vec3 *position, Vec3 *direction, KartAi *kartAi);
BOOL enmy_getIsAreaEpoiNotNull(KartAi *kartAi);
void enmy_recalculateEpoiRoute(KartAi *kartAi);
void enmy_updateRaceEnemy(KartAi *kartAi);
void ResetKartAiForRace(KartAi *kartAi);
void enmy_initRaceEnemy(KartAi *kartAi, s32 kartIndex);
