#pragma once

#include "types.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/map_object_draw_list_flags.h" // MapObjectDrawList

#define CHOROPU_HOLD_TOP_FRAMES 0x14
#define CHOROPU_KART_RESPONSE_FALL_SPIN 2

#define CHOROPU_SINK_SOUND_ID 0x128

void CreateChoropu(void);

void UpdateChoropuFallSpin(void *stateObject);
u8 CollideKartWithChoropu(Choropu *choropu, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u8 CollideItemObjectWithChoropu(Choropu *choropu, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);

void ChoropuFallSpinNop(void *stateObject);

typedef struct Choropu Choropu;

void UpdateChoropuLaunchedSpin(void *stateObject);

void EnterChoropuLaunchedSpin(void *stateObject);

void UpdateChoropuWaitRepeat(void *stateObject);

void EnterChoropuWaitRepeat(void *stateObject);

void UpdateChoropuSink(void *stateObject);
void EnterChoropuLeap(void *stateObject);
void UpdateChoropuLeap(void *stateObject);

void EnterChoropuSink(void *stateObject);

void UpdateChoropuHoldTop(void *stateObject);

void EnterChoropuHoldTop(void *stateObject);

void UpdateChoropuRise(void *stateObject);

void EnterChoropuRise(void *stateObject);

void UpdateChoropuWaitStart(void *stateObject);

void EnterChoropuWaitStart(void *stateObject);

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
