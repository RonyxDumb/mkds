#pragma once

#include "types.h"

typedef struct ObPakkunSf ObPakkunSf;

u8 CollideItemObjectWithObPakkunSf(ObPakkunSf *obPakkunSf, void *itemObject, u8 *b, u8 *c);
u8 CollideKartWithObPakkunSf(ObPakkunSf *obPakkunSf, void *kart, u8 *b, u8 *c);
void UpdateObPakkunSf(u32 a, ObPakkunSf *obPakkunSf);
