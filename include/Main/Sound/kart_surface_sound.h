#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct PlayingSound PlayingSound;
struct MapObjectSound;

void SetKartPlayingSoundVolumePitch(Kart *kart, PlayingSound *playingSound, s32 pitchOffset);
void SetItemKouraSoundTrackParams(Kart *kartArg, PlayingSound *playingSound);
void UpdateKartPlayingSound(Kart *kart, PlayingSound *playingSound);
void SetKartThunderShrinkSoundTrackParams(Kart *kart, PlayingSound *playingSound);
void SetVehicleSoundTrackParams(struct MapObjectSound *soundSource, PlayingSound *playingSound);
void SetNsKiller2SoundTrackParams(struct MapObjectSound *soundSource, PlayingSound *playingSound);
void SetItemKouraWSoundTrackParams(Kart *kart, PlayingSound *playingSound);

unsigned int GetZeroSoundDistanceChange(void);

void StartKartPlayingSoundSeq(Kart *kart, PlayingSound *playingSound, s32 playerPrio);

void SetKartStartSeqNop(Kart *kart);
void RemovedKartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused);
void GhostKartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused);

typedef struct SoundSource SoundSource;

void StartSurfaceSound(SoundSource *source, int entryIndex, u32 surfaceKind, u32 surfaceVariant, u32 waterDepth);

void UpdateSoundPitchSwing(void);

u32 InitSoundPitchSwing(void);
