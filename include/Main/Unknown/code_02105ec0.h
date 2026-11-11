#pragma once

#include "types.h"
#include "Main/Unknown/code_0210e33c.h"

typedef struct NNSSndSeqPlayer NNSSndSeqPlayer;

// 0x08-byte entries behind gCourseSurfaceSoundEntries; GetSurfaceSoundId reads one as a sound id array, so the variant
// is also the id for entry index 1.
typedef struct CourseSurfaceSoundEntry {
    /* 00 */ u32 mSoundId;
    /* 04 */ u32 mSurfaceVariant;
} CourseSurfaceSoundEntry;

extern CourseSurfaceSoundEntry gCourseSurfaceSoundEntries[];

// Object behind data_0216c7e0.
typedef struct SurfaceSoundSetup {
    /* 00 */ u32 mSoundIds[4];
    /* 10 */ u32 mRowIndex;
    /* 14 */ u32 mColumnIndex;
} SurfaceSoundSetup;

extern SurfaceSoundSetup data_0216c7e0;

// Object behind gLoadedSoundBanks.
typedef struct LoadedSoundBanks {
    /* 00 */ u16 mBankMask;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u32 mLoadMarker;
} LoadedSoundBanks;

extern LoadedSoundBanks gLoadedSoundBanks;

// 0x03-byte argument of InitSceneSoundState and InitSceneSounds.
typedef struct ScenePlayersSeqInfo {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mSeqStartProgress;
    /* 02 */ u8 mSeqId;
} ScenePlayersSeqInfo;

// Object behind gPlayerVolumeFade.
typedef struct PlayerVolumeFade {
    /* 00 */ u32 mVolumePerFrame;
    /* 04 */ s32 mVolume;
    /* 08 */ u32 mRaceStarted;
    /* 0c */ u32 mTargetVolumeBeforeRaceStart;
    /* 10 */ u32 mTargetVolumeAfterRaceStart;
    /* 14 */ u32 mPlayerMaskBeforeRaceStart;
    /* 18 */ u32 mPlayerMaskAfterRaceStart;
    /* 1c */ u32 mVolumePerFrameBeforeRaceStart;
    /* 20 */ u32 mVolumePerFrameAfterRaceStart;
} PlayerVolumeFade;

extern PlayerVolumeFade gPlayerVolumeFade;

// View of gSoundHandlePool; IncrementSoundHandleAges takes it.
typedef struct SoundHandlePool {
    /* 00 */ s32 mCount;
    /* 04 */ s32 mNextIndex;
    /* 08 */ u8 *mNextEntry;
    /* 0c */ u8 *mEntries;
    /* 10 */ s32 mEntrySize;
} SoundHandlePool;

extern SoundHandlePool gSoundHandlePool;

// The first eight bytes of each element of the table a SoundHandlePool describes: a handle at 0 and a word at 4.
typedef struct SoundHandleEntry {
    /* 00 */ NNSSndSeqPlayer *mSeqPlayer;
    /* 04 */ s32 mAge;
} SoundHandleEntry;

// Object behind gSceneSoundState.
typedef struct SceneSoundState {
    /* 00 */ u32 mRaceFrames;
    /* 04 */ u32 mSceneFrames;
    /* 08 */ NNSSndSeqPlayer *mKartStarSeq;
    /* 0c */ u32 mRaceState;
    /* 10 */ u32 mOnLastLap;
    /* 14 */ u8 mLapCount;
    /* 15 */ u8 mLapsDone;
    /* 16 */ u8 mLastLapSeqState;
    /* 17 */ u8 mKartStarSeqOn;
    /* 18 */ u8 mRankIndex;
    /* 19 */ u8 mRankIndexAtSeq;
    /* 1a */ u8 mUnk_1a[2];
    /* 1c */ s32 mRankSeqFrames;
    /* 20 */ u32 mVolumesLowered;
} SceneSoundState;

extern SceneSoundState gSceneSoundState;

extern NNSSndSeqPlayer *gRaceSeqHandle;

// Object gCurrentSoundSetPlayer points to.
typedef struct SoundSetPlayer {
    /* 00 */ SoundSet mSoundSet;
    /* 0c */ NNSSndSeqPlayer *mSeqPlayer;
    /* 10 */ LoadedSoundSet *mLoadedSet;
} SoundSetPlayer;

extern SoundSetPlayer *gCurrentSoundSetPlayer;

// Object behind gVolumeFade.
typedef struct VolumeFade {
    /* 00 */ u32 mVolumePerFrame;
    /* 04 */ s32 mVolume;
} VolumeFade;

extern VolumeFade gVolumeFade;

// Values of the two switches in InitSound.
typedef enum { E0 = 0, E1 = 1, E2 = 2 } SndHeapSizeKind;

BOOL LoadSndBanksAndWaveArcs(s32 bankMask);
BOOL LoadSndBanksAndWaveArcsIfChanged(s32 bankMask);
int GetSndHeapsBufferSize(int heapSizeKind);
int GetSndInitBufferSize(int heapSizeKind);
void ReleaseSndHeaps(void);
void CreateSndHeaps(u32 heapSizeKind, u32 buffer);
void InitSound(void *buffer, u32 bufferSize, u32 useFileArchive);
void UpdateSounds(void);
void InitSceneSounds(s32 unused);
void InitSceneSoundState(u32 sceneSoundRowIndex, ScenePlayersSeqInfo seqInfo, SceneSoundState *sceneSoundState);
void StartSceneSounds(void);
void StartRaceSounds(void);
void StartKartStarSeq(void);
void StopKartStarSeq(void);
void EndRaceSounds(void);
void AdvanceSceneSoundLap(void);
void SetSceneSoundRank(u32 rankIndex);
void UpdateRaceSounds(void);
void UpdateCourseSeqAtSceneFrames(void);
void UpdateSceneSoundState(void);
void StopSceneSounds(void);
void StopSceneSoundsAtOnce(void);
