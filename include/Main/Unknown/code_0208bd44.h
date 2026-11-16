#pragma once

#include "types.h"
#include "Main/Unknown/code_020888b4.h"

void enmy_initStaffRollEnemy(KartAi *kartAi, s32 kartIndex);
void enmy_updateAwardEnemy(KartAi *kartAi);
void sub_208BDE0(KartAi *kartAi, PointLink *pointLink);
void enmy_initAwardEnemy(KartAi *kartAi, s32 kartIndex);
void enmy_notifyDragItemChangedForMg(KartAi *kartAi);
void enmy_notifySlotItemChangedForMg(KartAi *kartAi);
void enmy_getTargetMepoPosDir(Vec3 *position, Vec3 *direction, KartAi *kartAi);
BOOL enmy_getIsAreaMepoNotNull(KartAi *kartAi);
void enmy_recalculateMepoRoute(KartAi *kartAi);
void enmy_updateMgEnemy(KartAi *kartAi);
