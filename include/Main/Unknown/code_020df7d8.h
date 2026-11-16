#pragma once

#include "types.h"

typedef struct MkdEfBubbleObject MkdEfBubbleObject;
typedef struct Unk020dea50_1 Unk020dea50_1;

u8 efbub_onDriverCollide(MkdEfBubbleObject *bubble, Unk020dea50_1 *kart, void *unused, u8 *d);
void efbub_waitStateUpdate(MkdEfBubbleObject *bubble);
