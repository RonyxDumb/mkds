#pragma once

#include "types.h"
#include "Main/Unknown/code_0209bc74.h" // MapObjectModel

// First argument of LoadMapObjectModelAnimated and LoadMapObjectModelShadow.
typedef struct Unk0219b478 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} Unk0219b478;

void AdvanceMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel);
void InitMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, void *nsbtpFile);
void InitMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, void *nsbcaFile);
void LoadMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, const char *fileName);
void LoadMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, const char *fileName);
void LoadMapObjectModelNsbmaAnimation(MapObjectModel *mapObjectModel, const char *fileName);
void LoadMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, const char *fileName);
MapObjectModel *LoadMapObjectModelShadow(MapObjectList *mapObjectList, const char *shadowFileName);
MapObjectModel *LoadMapObjectModelAnimated(Unk0219b478 *mapObjectList, const char *nsbmdName);
void *LoadMissionRunFile(const char *fileName);
void *CreateMapObjectKindDataWithSoundIds(void *collideKartCallback, void *collideItemObjectCallback,
                                          void *sphereHitCallback, u32 p3, u16 p4, u16 soundId,
                                          u16 collideItemObjectSoundId);
