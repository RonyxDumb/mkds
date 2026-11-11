#pragma once

#include "types.h"

typedef struct SecondHand SecondHand;
typedef struct Kart Kart;

void UpdateSecondHandState3(SecondHand *secondHand);
s32 CollideKartWithSecondHand(SecondHand *secondHand, Kart *kart, s32 unused, u8 *response);
