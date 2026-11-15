#pragma once

#include "types.h"
#include "player.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "code_0212df7c.h"

typedef struct SoundSource SoundSource;

void InitAndRegisterSoundSource(SoundSource *source, Vec3 *positionSource);

void SetSoundSourceFlagBit(SoundSource *source, s32 bit, s32 value);
void SetSoundSourceEnabled(SoundSource *source, s32 enabled);

typedef struct PlayingSound PlayingSound;

void ResetPlayingSound(PlayingSound *sound);

typedef struct SoundParams SoundParams;

void SetSoundVolumeFunction(s32 (*volumeFunction)(SoundParams *));
void SetSoundDistanceFunction(u32 (*distanceFunction)(SoundParams *));
void SetSoundPanFunction(s32 (*panFunction)(SoundParams *));
void StartSoundSeqArc(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 soundId, u32 priority);

void SetPlayingSoundTrackParams(u32 unused, PlayingSound *sound);

void StartPlayingSoundSeqArc(u32 unused, PlayingSound *sound, u32 priority);
void ReleaseAllSoundSources(void);

void UpdateSoundSources(void);
void StopSoundsOnAllSources(u32 fadeSteps);
void StartPlayingSoundsFade(s32 volume, s32 steps);
void StopAllPlayingSounds(u32 fadeSteps);

void SoundNop(void *address);

void InitPlayingSoundPool(PlayingSound *sounds, s32 count);

extern NNSFndList gSoundSourceSecondUpdateList;
extern NNSFndList gSoundSourceUpdateLists[1];
