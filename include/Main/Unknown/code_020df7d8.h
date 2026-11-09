#pragma once

#include "types.h"

typedef struct MkdEfBubbleObject MkdEfBubbleObject;
typedef struct Kart Kart;

u8 CollideKartWithMkdEfBubble(MkdEfBubbleObject *bubble, Kart *kart, void *unused, u8 *secondResponsePtr);
void UpdateMkdEfBubbleState1(MkdEfBubbleObject *bubble);
