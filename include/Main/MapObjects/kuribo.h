#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/map_object_response_and_quaternion_math.h"

#define KURIBO_ORIENTATION_BLEND_AMOUNT_MAX 0xb4
#define KURIBO_STRETCH_SCALE_Y_LIMIT 0x1800
#define KURIBO_SHRINK_SCALE_Y_LIMIT 0x333
#define KURIBO_FLAT_WAIT_FRAMES 0x12c
#define KURIBO_SPRING_BACK_FRAMES 0x3c
#define KURIBO_TOGGLE_COUNTDOWN_START 3
#define KURIBO_STRETCH_SCALE_Y_SPEED 0x19a

#define KURIBO_SPRING_BACK_SOUND_ID 0x183

void CreateKuribo(void);

typedef struct ItemObject ItemObject;
typedef struct Kart Kart;
typedef struct Kuribo Kuribo;

void UpdateKuriboFlatWait(void *stateObject);
void EnterKuriboSpringBack(void *stateObject);
void UpdateKuriboSpringBack(void *stateObject);
void StartItemKinokoFromKuribo(Kuribo *kuribo, Vec3 *hitVector);
u32 CollideKartWithKuribo(Kuribo *kuribo, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u32 CollideItemObjectWithKuribo(Kuribo *kuribo, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);
void ResetKuriboForItemBomb(Kuribo *kuribo);

void EnterKuriboFlatWait(void *stateObject);

void UpdateKuriboShrink(void *stateObject);

void EnterKuriboShrink(void *stateObject);

void UpdateKuriboStretch(void *stateObject);

void EnterKuriboStretch(void *stateObject);

void UpdateKuriboFallToSurface(void *stateObject);

void EnterKuriboFallToSurface(void *stateObject);

void UpdateKuriboWalkPath(void *stateObject);

void EnterKuriboWalkPath(void *stateObject);

extern StateCallbacks gKuriboStateTable[6];
extern const struct Quaternion gKuriboBombResetOrientation;
extern const struct Quaternion gKuriboBombResetTargetOrientation;
