#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;
typedef struct Kart Kart;

void UpdateSecondHandState3(Unk020e43a8 *secondHand);
s32 CollideKartWithSecondHand(Unk020e43a8 *secondHand, Kart *kart, s32 a, u8 *b);
