#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct PlayingSound PlayingSound;
struct MapObjectSound;

void SetKartPlayingSoundVolumePitch(Kart *kart, PlayingSound *playingSound, s32 pitchOffset);
void func_0210a77c(Kart *kart, PlayingSound *playingSound);
void UpdateKartPlayingSound(Kart *kart, PlayingSound *playingSound);
void SetKartThunderShrinkSoundTrackParams(Kart *kart, PlayingSound *playingSound);
void SetVehicleSoundTrackParams(struct MapObjectSound *soundSource, PlayingSound *playingSound);
void SetNsKiller2SoundTrackParams(struct MapObjectSound *soundSource, PlayingSound *playingSound);
void SetItemKouraWSoundTrackParams(Kart *kart, PlayingSound *playingSound);
