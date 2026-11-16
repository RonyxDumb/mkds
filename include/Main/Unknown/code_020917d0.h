#pragma once

#include "types.h"

typedef struct Sman Sman;
typedef struct Kart Kart;

typedef struct Unk0209188c {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} Unk0209188c;

u8 sman_onItemCollide(Sman *sman, u32 b, unsigned char *c, u8 *d);
u8 sman_onDriverCollide(Sman *sman, Kart *kart, u8 *c, u8 *d);
void sman_init(Unk0209188c *mapObject);
