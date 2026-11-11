#pragma once

#include "types.h"

typedef struct ObPakkunSf ObPakkunSf;

u8 CollideItemObjectWithObPakkunSf(ObPakkunSf *obPakkunSf, void *itemObject, u8 *firstResponse, u8 *response);
u8 CollideKartWithObPakkunSf(ObPakkunSf *obPakkunSf, void *kart, u8 *firstResponse, u8 *response);
void UpdateObPakkunSf(u32 unused, ObPakkunSf *obPakkunSf);
