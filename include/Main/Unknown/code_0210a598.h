#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct KartSound KartSound;

void InitKartSoundCallbacks(Kart *kart, KartSound *b);
void func_0210a598(Kart *kart, s32 soundIndex);
