#pragma once

#include "types.h"

typedef struct KartAi KartAi;

void SetupNonBattleKartAiItemInUseEntry(KartAi *kartAi);
void SetupNonBattleKartAiHeldItemEntry(KartAi *kartAi);
void CopyKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi);
BOOL IsKartAiLinkRequested(KartAi *kartAi);
void RequestKartAiPointLink(KartAi *kartAi);
void AdvanceKartAiForRace(KartAi *kartAi);
void ResetKartAiForRace(KartAi *kartAi);
void SetupKartAiForRace(KartAi *kartAi, s32 kartIndex);
