#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "sound_player_control.h"

typedef struct NNSSndArc NNSSndArc;

// The sound data: the sound archive, sequence player, file data and the task that drives it.
typedef struct SoundData {
    /* 00 */ NNSSndArc mArc;
    /* 90 */ NNSSndSeqPlayer *mSeqPlayer;
    /* 94 */ void *mFileData;
    /* 98 */ TaskEntry *mTask;
} SoundData;

void StopSoundSeq(void);
void SetSoundSeqTrackPitch(u32 tracks, u32 pitch);
u32 SetSoundSeqVolume(u32 volume);
void StartSoundSeq(u32 index);
void ReleaseSoundData(void);
void CreateSoundData(void);
