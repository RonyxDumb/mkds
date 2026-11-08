#pragma once

#include "types.h"

typedef struct Unk020e5aec Unk020e5aec;

u8 CollideItemObjectWithObPakkunSf(Unk020e5aec *obPakkunSf, void *itemObject, u8 *b, u8 *c);
u8 CollideKartWithObPakkunSf(Unk020e5aec *obPakkunSf, void *kart, u8 *b, u8 *c);
void UpdateObPakkunSf(u32 a, Unk020e5aec *obPakkunSf);
