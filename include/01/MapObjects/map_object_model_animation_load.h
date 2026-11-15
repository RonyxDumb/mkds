#pragma once

#include "types.h"
#include "01/MapObjects/map_object_model.h" // MapObjectModel

typedef struct MapObjectList MapObjectList;

void AdvanceMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel);
void InitMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, void *nsbtpFile);
void InitMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, void *nsbcaFile);
void LoadMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, const char *fileName);
void LoadMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, const char *fileName);
void LoadMapObjectModelNsbmaAnimation(MapObjectModel *mapObjectModel, const char *fileName);
void LoadMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, const char *fileName);
MapObjectModel *LoadMapObjectModelShadow(MapObjectList *mapObjectList, const char *shadowFileName);
MapObjectModel *LoadMapObjectModelAnimated(MapObjectList *mapObjectList, const char *nsbmdName);
void *LoadMissionRunFile(const char *fileName);
void *CreateMapObjectKindDataWithSoundIds(void *collideKartCallback, void *collideItemObjectCallback,
                                          void *sphereHitCallback, u32 posStepMode, u16 collidable, u16 soundId,
                                          u16 collideItemObjectSoundId);
