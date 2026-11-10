#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct KartSound KartSound;

void InitKartSoundCallbacks(Kart *kart, KartSound *kartSound);
void StartKartSeqArcSoundOffset8(Kart *kart, s32 soundIndex);
