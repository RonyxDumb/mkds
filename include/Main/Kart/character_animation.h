#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/shadow_model.h" // ShadowModel

struct KartModelsEntry;

void DrawShadowWithoutMatrix(ShadowModel *shadowModel);
void DrawShadowWithMatrix(ShadowModel *shadowModel, const void *matrix, Vec3 *extraVector);
NNSG3dResMdl *StructAD00Sh_SomeFn_2(ShadowModel *shadowModel, NNSG3dResFileHeader *resFileHeader, u32 polygonId);
void StructAD00Sh_SomeFn(ShadowModel *shadowModel, void *resFile, u32 polygonId);
void StructMQRacerEntry_SomeFn_7(Kart *kart, s32 animationIndex, s32 nextAnimationIndex);
void StructMQRacerEntry_SomeFn_2(Kart *kart);
void StructMQRacerEntry_SomeFn_36(Kart *kart);
void StopKartStarModels(Kart *kart);
void StructMQRacerEntry_SomeFn_67(Kart *kart);
void AdvanceKartAnimationChangeTimer(Kart *kart);
void StructMQRacerEntry_SomeFn_37(Kart *kart);
void StructAD00Sub_SomeFn_0(struct KartModelsEntry *kartModelsEntry, s32 animationIndex, s32 useBlend);
void StructAD00Sub_SomeFn_1(struct KartModelsEntry *kartModelsEntry, s32 faceFrameIndex);
void StructMQRacerEntry_SomeFn_20(Kart *animationState);
void StructAD00Sub_SomeFn_2(struct KartModelsEntry *kartModelsEntry);
u32 GetRacerAnimationIndex(int animationIndex);
char *FormatCharacterEmblemNsbcaPath(u16 characterIndex, s32 animationIndex);

extern char g_SomeNsbcaFormatBuffer[256];

extern const s32 gCharacterFaceFrames[2];
