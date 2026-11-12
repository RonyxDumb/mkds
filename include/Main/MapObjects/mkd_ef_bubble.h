#pragma once

#include "types.h"

unsigned int CollideItemObjectWithMkdEfBubble(unsigned int unused0, unsigned int unused1, unsigned int unused2,
                                              unsigned int secondResponsePtr);

typedef struct MkdEfBubbleObject MkdEfBubbleObject;
typedef struct Kart Kart;

u8 CollideKartWithMkdEfBubble(MkdEfBubbleObject *bubble, Kart *kart, void *unused, u8 *secondResponsePtr);
void UpdateMkdEfBubbleState1(MkdEfBubbleObject *bubble);

void EnterMkdEfBubbleState1(MkdEfBubbleObject *bubble);

