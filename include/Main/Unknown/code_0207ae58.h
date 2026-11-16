#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207adf8.h" // ShadowModel

struct KartModelsEntry;

void driver_renderShadow(ShadowModel *shadowModel);
void DrawShadowWithMatrix(void *shadowModel, const void *matrix, Vec3 *extraVector);
NNSG3dResMdl *InitShadowModel(void *shadowModel, NNSG3dResFileHeader *resFileHeader, u32 polygonId);
void InitShadowModelFromResMdl(Nsbmd *nsbmd, void *resFile, u32 polygonId);
void driver_setAnimation(Kart *kart, s32 animationIndex, s32 nextAnimationIndex);
void driver_disableSlipStreamToonMode(Kart *kart);
void driver_enableSlipStreamToonMode(Kart *kart);
void driver_disableStarToonMode(Kart *kart);
void driver_enableStarToonMode(Kart *kart);
void AdvanceKartAnimationChangeTimer(Kart *kart);
void StartKartWinOrLoseAnimation(Kart *p);
void driver_setAnim(struct KartModelsEntry *kartModelsEntry, s32 animationIndex, s32 useBlend);
void driver_setFaceExpression(struct KartModelsEntry *kartModelsEntry, s32 faceFrameIndex);
void AdvanceKartCharacterAnimation(Kart *animationState);
void ClearCharacterTurnAndNextAnimation(struct KartModelsEntry *kartModelsEntry);
u32 GetCharacterAnimationLoopFlag(int animationIndex);
char *GetCharacterNsbcaPath(u16 characterIndex, s32 animationIndex);
