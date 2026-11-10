#pragma once

#include "types.h"
#include "Main/Unknown/code_020888b4.h"

void SetupKartAiForStaffRoll(KartAi *kartAi, s32 kartIndex);
void AdvanceKartAiForAwardMissionRun(KartAi *kartAi);
void ResetKartAiForAwardMissionRun(KartAi *kartAi, RacePointLink *pointLink);
void SetupKartAiForAwardMissionRun(KartAi *kartAi, s32 kartIndex);
void SetupBattleKartAiItemInUseEntry(KartAi *kartAi);
void SetupBattleKartAiHeldItemEntry(KartAi *kartAi);
void CopyBattleKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi);
BOOL IsBattleKartAiLinkRequested(KartAi *kartAi);
void RequestBattleKartAiPointLink(KartAi *kartAi);
void AdvanceKartAiForBattle(KartAi *kartAi);
