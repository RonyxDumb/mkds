#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/shadow_model.h" // ShadowModel

struct KartModelsEntry;

void DrawShadowWithoutMatrix(ShadowModel *shadowModel);
void DrawShadowWithMatrix(ShadowModel *shadowModel, const void *matrix, Vec3 *extraVector);
NNSG3dResMdl *InitShadowModel(ShadowModel *shadowModel, NNSG3dResFileHeader *resFileHeader, u32 polygonId);
void InitShadowModelFromResMdl(ShadowModel *shadowModel, void *resFile, u32 polygonId);
void StartKartCharacterAnimationOnce(Kart *kart, s32 animationIndex, s32 nextAnimationIndex);
void ResetKartModelsCourseColors(Kart *kart);
void SetKartModelsGrayColors(Kart *kart);
void StopKartStarModels(Kart *kart);
void StartKartStarModels(Kart *kart);
void AdvanceKartAnimationChangeTimer(Kart *kart);
void StartKartWinOrLoseAnimation(Kart *p);
void SetCharacterAnimation(struct KartModelsEntry *kartModelsEntry, s32 animationIndex, s32 useBlend);
void SetCharacterFaceFrameIndex(struct KartModelsEntry *kartModelsEntry, s32 faceFrameIndex);
void AdvanceKartCharacterAnimation(Kart *animationState);
void ClearCharacterTurnAndNextAnimation(struct KartModelsEntry *kartModelsEntry);
u32 GetCharacterAnimationLoopFlag(int animationIndex);
char *BuildCharacterNsbcaPath(u16 characterIndex, s32 animationIndex);

extern char gCharacterNsbcaPathBuffer[256];

extern const s32 gCharacterFaceFrames[3];
