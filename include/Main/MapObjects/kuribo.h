#pragma once

#include "types.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/code_020d6dc0.h"

void CreateKuribo(void);

typedef struct ItemObject ItemObject;
typedef struct Kart Kart;
typedef struct Kuribo Kuribo;

void UpdateKuriboState4(void *stateObject);
void EnterKuriboState5(void *stateObject);
void UpdateKuriboState5(void *stateObject);
void StartItemKinokoFromKuribo(Kuribo *kuribo, Vec3 *hitVector);
u32 CollideKartWithKuribo(Kuribo *kuribo, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u32 CollideItemObjectWithKuribo(Kuribo *kuribo, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);
void ResetKuriboForItemBomb(Kuribo *kuribo);

unsigned int EnterKuriboState4(unsigned int value);

void UpdateKuriboState3(void *stateObject);

unsigned int EnterKuriboState3(unsigned int value);

void UpdateKuriboState2(void *stateObject);

void EnterKuriboState2(void *stateObject);

void UpdateKuriboState1(void *stateObject);

void EnterKuriboState1(void *stateObject);

void UpdateKuriboState0(void *stateObject);

void EnterKuriboState0(void *stateObject);

extern StateCallbacks gKuriboStateTable[6];
extern const struct Quaternion gKuriboBombResetOrientation;
extern const struct Quaternion gKuriboBombResetTargetOrientation;
