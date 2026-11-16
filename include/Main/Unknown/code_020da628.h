#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Kuribo Kuribo;

void kuribo_deadStateUpdate(Kuribo *kuribo);
void kuribo_reappearStateInit(Kuribo *kuribo);
void kuribo_reappearStateUpdate(Kuribo *kuribo);
void kuribo_handleShroomSpawn(Kuribo *kuribo, Vec3 *hitVector);
u32 kuribo_onDriverCollide(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c);
u32 kuribo_onItemCollide(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c);
void kuribo_resetRoaming(Kuribo *kuribo);
