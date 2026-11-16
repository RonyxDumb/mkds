#pragma once

#include "types.h"

typedef struct MissionGateObject MissionGateObject;
typedef struct Kart Kart;
typedef struct MissionGateList MissionGateList;
typedef struct Unk0219b250 Unk0219b250;

void mgat_setupLogicPart(void);
void mgat_setupRenderPart(void);
void mgat_setupCollision(void);
void mgat_update(
    void *a, MissionGateObject *missionGateObject); /* skipped for objects with mFlags & 4 (parked pool objects) */
void mgat_globalInitLogic(MissionGateList *missionGateList);
void mgat_render(void *mapObjectList, MissionGateObject *missionGateObject);
void mgat_globalPreRender(void);
void mgat_loadModel(void *a);
u32 mgat_onDriverCollide(MissionGateObject *missionGateObject, Kart *kart, u8 *e, u8 *f);
void mgat_init(MissionGateObject *missionGateObject);
