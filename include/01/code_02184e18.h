#pragma once

#include "types.h"
#include "01/code_02184000.h"
#include "01/code_02187000.h"
#include "01/code_02185ef4.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_020d2000.h"

void SetDonketuStepEffectCallbacks(u16 *mapObject);
void SetDonketuStepSoundCallbacks(MissionRunMapObject *mapObject);
void StartKingIceDonketuStepEffectSecond(MissionRunMapObject *mapObject);
void StartKingIceDonketuStepEffectFirst(MissionRunMapObject *mapObject);
void StartBossDonketuStepEffectSecond(MissionRunMapObject *mapObject);
void StartBossDonketuStepEffectFirst(MissionRunMapObject *mapObject);
