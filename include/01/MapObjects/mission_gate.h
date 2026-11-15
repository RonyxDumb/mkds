#pragma once

#include "types.h"

typedef struct MissionGateObject MissionGateObject;
typedef struct Kart Kart;
typedef struct MapObjectList MapObjectList;
typedef struct MapObjectModel MapObjectModel;

#include "01/code_0218b9b4.h"

// First course setting the two side objects of a mission gate are created with.
#define MISSION_GATE_SIDE_OBJECT_SETTING 0x12

MapObjectList *CreateMissionGateUpdateList(void);
MapObjectList *CreateMissionGateDrawList(void);
MapObjectKindData *CreateMissionGateKindData(void);
void UpdateMissionGate(
    void *unused, MissionGateObject *missionGateObject); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitMissionGateObjects(MapObjectList *missionGateList);
void DrawMissionGate(void *mapObjectList, MissionGateObject *missionGateObject);
void MissionGateNop(void);
void LoadMissionGate(void *mapObjectList);
u32 CollideKartWithMissionGate(MissionGateObject *missionGateObject, Kart *kart, u8 *firstResponsePointer,
                               u8 *responsePointer);
void InitMissionGate(MissionGateObject *missionGateObject);

extern MapObjectKindDescriptor gMissionGateKindDescriptor;
