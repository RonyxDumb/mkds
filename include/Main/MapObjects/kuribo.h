#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/code_020d6dc0.h"

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

unsigned int EnterKuriboFlatWait(unsigned int value);

void UpdateKuriboShrink(void *stateObject);

unsigned int EnterKuriboShrink(unsigned int value);

void UpdateKuriboStretch(void *stateObject);

void EnterKuriboStretch(void *stateObject);

void UpdateKuriboFallToSurface(void *stateObject);

void EnterKuriboFallToSurface(void *stateObject);

void UpdateKuriboWalkPath(void *stateObject);

void EnterKuriboWalkPath(void *stateObject);

extern StateCallbacks gKuriboStateTable[6];
extern const struct Quaternion gKuriboBombResetOrientation;
extern const struct Quaternion gKuriboBombResetTargetOrientation;
