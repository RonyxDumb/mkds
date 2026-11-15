#pragma once
#include "types.h"

struct KartItems;

// Element 8 is used by kart_contact.c for an owner flagged 0x8000
extern struct KartItems *gKartItems;

extern s32 gCollisionHitCount;

extern u16 gCollisionHitValues[16];

extern u32 gCollisionHitBits[16];

extern u16 gKartItemsCount;
