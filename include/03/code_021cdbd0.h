#pragma once

#include "types.h"
#include "player.h"

typedef struct NNSSndArc NNSSndArc;

typedef struct SoundData {
    /* 00 */ NNSSndArc mArc;
    /* 90 */ NNSSndSeqPlayer *mSeqPlayer;
    /* 94 */ void *mFileData;
    /* 98 */ u32 mTask;
} SoundData;

void StopSoundSeq(void);
void SetSoundSeqTrackPitch(u32 tracks, u32 pitch);
u32 SetSoundSeqVolume(u32 volume);
void StartSoundSeq(u32 index);
void ReleaseSoundData(void);
void CreateSoundData(void);
