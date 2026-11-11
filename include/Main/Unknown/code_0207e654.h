#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct KartAi KartAi;

#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02080b1c.h"

BOOL IsTargetKartSet(KartAi *kartAi);
void AdvanceKartAiContactStages(KartAi *kartAi);
void SetKartAiSideOffsetFromKart(KartAi *kartAi);
void AdvanceKartAiSideOffset(KartAi *kartAi);
s32 ComputeAngleToPositionDegrees(Vec3 *targetPos, Vec3 *originPos, Vec3 *planeNormal, Vec3 *forward);
void AdvanceKartAiDrift(KartAi *kartAi);
void PickKartAiDriftAtLink(KartAi *kartAi);
void PickKartAiTargetKart(KartAi *kartAi);
s32 ShouldKartAiTargetKart(u32 kartIndex, u32 targetIndex);
BOOL IsKartTargetable(s32 kartIndex);
void SetKartAiLinkPosAndClearSideOffset(KartAi *kartAi, PointLinkCursor *linkCursor, Kart *kart);
void SetKartAiLinkPosAndAddSideOffset(KartAi *kartAi, PointLinkCursor *linkCursor, Kart *kart);
void AdvanceKartAiAlongLinks(KartAi *kartAi, PointLinkCursor *linkCursor, Kart *kart, RacePointLink *requestedLink,
                             Vec3 *kartPos, Vec3 *kartForward);
void AdvanceRaceKartAi(KartAi *kartAi);
void ResetRaceKartAiAtPointLink(KartAi *kartAi);
void ResetKartAi(KartAi *kartAi, s32 value);
void SetupRaceKartAi(KartAi *kartAi, Kart *kart, s32 useDefaultTable);
void SetupKartAiGlobals(void);
void AdvanceStaffRollPointLinkCursor(PointLinkCursor *pointLinkCursor);
s32 GetPointLinkSpeedRatio(PointLinkCursor *pointLinkCursor);
void AdvanceAwardPointLinkCursor(PointLinkCursor *pointLinkCursor);
