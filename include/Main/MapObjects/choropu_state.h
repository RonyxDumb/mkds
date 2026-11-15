#pragma once

#include "types.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/data_02158000.h" // MapObjectDrawList

void CreateChoropu(void);

void UpdateChoropuState7(void *stateObject);
u8 CollideKartWithChoropu(Choropu *choropu, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideItemObjectWithChoropu(Choropu *choropu, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);

void ChoropuState7Nop(void *stateObject);

typedef struct Choropu Choropu;

void UpdateChoropuState6(void *stateObject);

void EnterChoropuState6(void *stateObject);

void UpdateChoropuState5(void *stateObject);

void EnterChoropuState5(void *stateObject);

void UpdateChoropuState3(void *stateObject);
void EnterChoropuState4(void *stateObject);
void UpdateChoropuState4(void *stateObject);

void EnterChoropuState3(void *stateObject);

void UpdateChoropuState2(void *stateObject);

void EnterChoropuState2(void *stateObject);

void UpdateChoropuState1(void *stateObject);

void EnterChoropuState1(void *stateObject);

void UpdateChoropuState0(void *stateObject);

void EnterChoropuState0(void *stateObject);

void UpdateChoropu(u32 unused, Choropu *choropu);

void DrawChoropuShadow(void *unused0, Choropu *choropu, u32 unused1, u32 alpha);

void SetupDrawChoropuShadow(void);

extern const u16 gChoropuFlag;
extern const u16 gChoropuSecondFlag;
extern const MapObjectList gChoropuUpdateListData;
extern const MapObjectDrawList gChoropuShadowDrawListData;
extern const MapObjectDrawList gChoropuDrawListData;
extern const MapObjectKindData gChoropuKindData;
extern StateCallbacks gChoropuStateTable[8];
