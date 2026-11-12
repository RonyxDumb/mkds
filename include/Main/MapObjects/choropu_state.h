#pragma once

#include "types.h"
#include "Main/MapObjects/choropu.h"

void CreateChoropu(void);

void UpdateChoropuState7(Choropu *choropu);
u8 CollideKartWithChoropu(Choropu *choropu, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideItemObjectWithChoropu(Choropu *choropu, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);

unsigned int ChoropuState7ReturnArgument(unsigned int value);

typedef struct Choropu Choropu;

void UpdateChoropuState6(Choropu *choropu);

void EnterChoropuState6(Choropu *choropu);

void UpdateChoropuState5(Choropu *choropu);

void EnterChoropuState5(Choropu *choropu);

void UpdateChoropuState3(Choropu *choropu);
void EnterChoropuState4(Choropu *choropu);
void UpdateChoropuState4(Choropu *choropu);

void EnterChoropuState3(Choropu *choropu);

void UpdateChoropuState2(Choropu *choropu);

void EnterChoropuState2(Choropu *choropu);

void UpdateChoropuState1(Choropu *choropu);

void EnterChoropuState1(Choropu *choropu);

void UpdateChoropuState0(Choropu *choropu);

void EnterChoropuState0(Choropu *choropu);

void UpdateChoropu(u32 unused, Choropu *choropu);

void DrawChoropuShadow(void *unused0, Choropu *choropu, u32 unused1, u32 alpha);

void SetupDrawChoropuShadow(void);
