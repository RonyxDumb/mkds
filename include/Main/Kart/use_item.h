#pragma once

#include "types.h"
#include "Main/Kart/kart_ai_battle.h"

void UseItemAfterHeldIfTurnUnder10(KartAiItemUse *itemUse, KartAi *kartAi);
void UseItemAfterHeldOrOnTargetIfTurnUnder10(KartAiItemUse *itemUse, KartAi *kartAi);
void EasyUseItemAfterHeld(KartAiItemUse *itemUse, KartAi *kartAi);
void UseItemAfterHeldOrOnTarget(KartAiItemUse *itemUse, KartAi *kartAi);
void UseItemWhenHasTarget(KartAiItemUse *itemUse, KartAi *kartAi);
void SetupBattleHeldItemEntry(KartAiItemUse *itemUse, KartAi *kartAi);
void AdvanceBattleItemBitRequests(KartAiItemUse *itemUse, KartAi *kartAi);
