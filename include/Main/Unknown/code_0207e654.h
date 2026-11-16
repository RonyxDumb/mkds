#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct KartAi KartAi;

#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02080b1c.h"

BOOL enmy_hasTargetDriver(KartAi *kartAi);
void sub_207E668(KartAi *kartAi);
void SetKartAiSideOffsetFromKart(KartAi *kartAi);
void AdvanceKartAiSideOffset(KartAi *kartAi);
s32 ComputeAngleToPositionDegrees(Vec3 *targetPos, Vec3 *originPos, Vec3 *planeNormal, Vec3 *forward);
void enmy_updateDrift1(KartAi *kartAi);
void enmy_updateDrift2(KartAi *kartAi);
void PickKartAiTargetKart(KartAi *kartAi);
s32 ShouldKartAiTargetKart(u32 kartIndex, u32 targetIndex);
BOOL GetSomeMQRacerAnotherFlags(s32 kartIndex);
void SetKartAiLinkPosAndClearSideOffset(KartAi *kartAi, LinkCursor *linkCursor, Kart *kart);
void SetKartAiLinkPosAndAddSideOffset(KartAi *kartAi, LinkCursor *linkCursor, Kart *kart);
void sub_207F6F0(KartAi *kartAi, LinkCursor *linkCursor, Kart *kart, PointLink *requestedLink, Vec3 *kartPos,
                   Vec3 *kartForward);
void AdvanceRaceKartAi(KartAi *kartAi);
void ResetRaceKartAiAtPointLink(KartAi *kartAi);
void ResetKartAi(KartAi *kartAi, s32 a);
void SetupRaceKartAi(KartAi *kartAi, Kart *kart, s32 a);
void sub_207FBA0(void);
void AdvanceStaffRollPointLinkCursor(PointLinkCursor *pointLinkCursor);
s32 GetPointLinkSpeedRatio(PointLinkCursor *pointLinkCursor);
void AdvanceAwardPointLinkCursor(PointLinkCursor *pointLinkCursor);
