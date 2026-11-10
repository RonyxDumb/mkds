#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct PlayingSound PlayingSound;

void SetKartStartSeqNop(Kart *kart);
void RemovedKartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused);
void GhostKartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused);
