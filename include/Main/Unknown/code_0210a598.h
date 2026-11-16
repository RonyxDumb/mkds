#pragma once

#include "types.h"

typedef struct Kart Kart;

// Second argument of InitKartSoundCallbacks: a word callback at 0x3c.
typedef struct Unk0210a5a8 {
    /* 00 */ u8 field0[0x3c];
    /* 3c */ UnkWordFunc *field3C;
} Unk0210a5a8;

void InitKartSoundCallbacks(Kart *kart, Unk0210a5a8 *b);
void StructMQRacerEntry_SomeFn_66(Kart *kart, s32 soundIndex);
