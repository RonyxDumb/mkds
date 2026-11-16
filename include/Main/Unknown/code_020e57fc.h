#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;

// Second parameter of shand_onDriverCollide; the word at 0x29c is the only field read.
typedef struct KartItemEffectView {
    /* 000 */ u8 field0[0x29c];
    /* 29c */ u32 field29C;
} KartItemEffectView;

void shand_waitStateUpdate(Unk020e43a8 *secondHand);
s32 shand_onDriverCollide(Unk020e43a8 *secondHand, KartItemEffectView *kart, s32 a, u8 *b);
