#pragma once

#include "types.h"
#include "Main/Kart/kart_ai_battle.h"
#include "Main/Kart/data_02090000.h"
#include "Main/Race/data_020f36d8.h"

typedef struct KartAi KartAi;

void AdvanceKartAiForStaffRoll(KartAi *kartAi);

void ResetKartAiForStaffRollNop(unsigned int kartAi);

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

void ResetKartAiForBattle(KartAi *kartAi, PointLink *link);
void SetupKartAiForBattle(KartAi *kartAi, s32 kartIndex);

void SetupNonBattleKartAiItemInUseEntry(KartAi *kartAi);
void SetupNonBattleKartAiHeldItemEntry(KartAi *kartAi);
void CopyKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi);
BOOL IsKartAiLinkRequested(KartAi *kartAi);
void RequestKartAiPointLink(KartAi *kartAi);
void AdvanceKartAiForRace(KartAi *kartAi);
void ResetKartAiForRace(KartAi *kartAi);
void SetupKartAiForRace(KartAi *kartAi, s32 kartIndex);

unsigned int GetKartAiRaceStartBoostChoice(KartAi *kartAi);
unsigned int GetKartAiBoostsAtRaceStart(KartAi *kartAi);
unsigned int GetKartAiHeadingSwingAtRaceStart(KartAi *kartAi);

void CallKartAiSetupItemInUseEntry(KartAi *kartAi);
void CallKartAiSetupHeldItemEntry(KartAi *kartAi);
void CallKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi);
void CallKartAiRequestLink(KartAi *kartAi);
void CallKartAiAdvance(KartAi *kartAi);
void CallKartAiReset(KartAi *kartAi, PointLink *link);
void CallKartAiSetup(KartAi *kartAi, s32 kartIndex);
void RegisterKartAiCallbacks(void);

extern s32 (*gKartAiIsLinkRequestedCallback)();
// Function pointers set by RegisterKartAiCallbacks (the reset targets take different parameters).
extern void (*gKartAiAdvanceCallback)(struct KartAi *kartAi);
extern void (*gKartAiSetupCallback)(struct KartAi *kartAi, s32 kartIndex);
extern UnkFunc *gKartAiResetCallback;
extern void (*gKartAiLinkPosAndDirectionCallback)(Vec3 *position, Vec3 *direction, struct KartAi *kartAi);
extern void (*gKartAiSetupHeldItemEntryCallback)(struct KartAi *kartAi);
extern void (*gKartAiSetupItemInUseEntryCallback)(struct KartAi *kartAi);
extern void (*gKartAiRequestLinkCallback)(struct KartAi *kartAi);
