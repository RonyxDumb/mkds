#pragma once

#include "types.h"

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
