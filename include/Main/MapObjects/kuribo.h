#pragma once

#include "types.h"

void CreateKuribo(void);

typedef struct ItemObject ItemObject;
typedef struct Kart Kart;
typedef struct Kuribo Kuribo;

void UpdateKuriboState4(Kuribo *kuribo);
void EnterKuriboState5(Kuribo *kuribo);
void UpdateKuriboState5(Kuribo *kuribo);
void StartItemKinokoFromKuribo(Kuribo *kuribo, Vec3 *hitVector);
u32 CollideKartWithKuribo(Kuribo *kuribo, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr);
u32 CollideItemObjectWithKuribo(Kuribo *kuribo, ItemObject *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr);
void ResetKuriboForItemBomb(Kuribo *kuribo);

unsigned int EnterKuriboState4(unsigned int value);

void UpdateKuriboState3(Kuribo *kuribo);

unsigned int EnterKuriboState3(unsigned int value);

void UpdateKuriboState2(Kuribo *kuribo);

void EnterKuriboState2(Kuribo *kuribo);

void UpdateKuriboState1(Kuribo *kuribo);

void EnterKuriboState1(Kuribo *kuribo);

void UpdateKuriboState0(Kuribo *kuribo);

void EnterKuriboState0(Kuribo *kuribo);
