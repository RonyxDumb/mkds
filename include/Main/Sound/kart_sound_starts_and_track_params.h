#pragma once

#include "types.h"
#include "Main/Sound/kart_sound_queue_and_kart_sound_starts.h"

typedef struct SoundDistanceSquaredChange SoundDistanceSquaredChange;

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

unsigned int GetZeroSoundDistanceChange(SoundDistanceSquaredChange *change);

void StartKartPlayingSoundSeq(Kart *kart, PlayingSound *playingSound, s32 playerPrio);

void SetKartStartSeqNop(Kart *kart);
void RemovedKartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused);
void GhostKartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused);

typedef struct SoundSource SoundSource;

void StartSurfaceSound(SoundSource *source, int entryIndex, u32 surfaceKind, u32 surfaceVariant, u32 waterDepth);

void UpdateSoundPitchSwing(void);

u32 InitSoundPitchSwing(void);

extern s32 gKartPitchPerWaterDepth;
extern vu32 gSoundPitchSwingAngle;
extern s32 gSoundPitchSwing;
extern KartSoundQueue gKartSoundQueue;
extern s32 gKouraPitchPerWaterDepth;

// StartKartCollisionSound starts no sound before this many race frames.
#define KART_COLLISION_SOUND_MIN_RACE_FRAMES 0x78
