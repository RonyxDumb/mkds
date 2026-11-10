#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct PlayingSound PlayingSound;

void SetKartStartSeqNop(Kart *kart);
void RemovedKartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused);
void EntryKind2KartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused);
