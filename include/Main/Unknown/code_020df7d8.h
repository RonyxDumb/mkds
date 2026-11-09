#pragma once

#include "types.h"

typedef struct MkdEfBubbleObject MkdEfBubbleObject;
typedef struct Kart Kart;

u8 func_020df7d8(MkdEfBubbleObject *bubble, Kart *kart, void *unused, u8 *d);
void UpdateMkdEfBubbleState1(MkdEfBubbleObject *bubble);
