#pragma once

#include "types.h"
#include "Main/Unknown/code_0210e33c.h"

typedef struct NNSSndSeqPlayer NNSSndSeqPlayer;

// 0x08-byte entries behind data_0216c860.
typedef struct Unk0216c860 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
} Unk0216c860;

extern Unk0216c860 data_0216c860[];

// Object behind data_0216c7e0.
typedef struct Unk0216c7e0 {
    /* 00 */ u32 field0[4];
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
} Unk0216c7e0;

extern Unk0216c7e0 data_0216c7e0;

// Object behind sLoadedCharacterSounds.
typedef struct Unk0216c7d8 {
    /* 00 */ u16 field0;
    /* 02 */ u8 field2[2];
    /* 04 */ u32 field4;
} Unk0216c7d8;

extern Unk0216c7d8 sLoadedCharacterSounds;

// 0x03-byte argument of InitSceneSoundState and InitSceneSounds.
typedef struct Unk021073ec {
    /* 00 */ u8 field0;
    /* 01 */ u8 field1;
    /* 02 */ u8 field2;
} Unk021073ec;

// Object behind data_0217c7f0.
typedef struct Unk0217c7f0 {
    /* 00 */ u32 field0;
    /* 04 */ s32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u32 field14;
    /* 18 */ u32 field18;
    /* 1c */ u32 field1C;
    /* 20 */ u32 field20;
} Unk0217c7f0;

extern Unk0217c7f0 data_0217c7f0;

// View of sound_sPools; sp_updateAges takes it.
typedef struct Unk0217c7c4 {
    /* 00 */ s32 mCount;
    /* 04 */ s32 mNextIndex;
    /* 08 */ u8 *mNextEntry;
    /* 0c */ u8 *mEntries;
    /* 10 */ s32 mEntrySize;
} Unk0217c7c4;

extern Unk0217c7c4 sound_sPools;

// The first eight bytes of each element of the table an Unk0217c7c4 describes: a handle at 0 and a word at 4.
typedef struct SoundHandleEntry {
    /* 00 */ NNSSndSeqPlayer *mSeqPlayer;
    /* 04 */ s32 mAge;
} SoundHandleEntry;

// Object behind gSceneSoundState.
typedef struct SceneSoundState {
    /* 00 */ u32 mRaceFrames;
    /* 04 */ u32 mSceneFrames;
    /* 08 */ NNSSndSeqPlayer *field8;
    /* 0c */ u32 mRaceState;
    /* 10 */ u32 mOnLastLap;
    /* 14 */ u8 mLapCount;
    /* 15 */ u8 mLapsDone;
    /* 16 */ u8 field16;
    /* 17 */ u8 field17;
    /* 18 */ u8 mRankIndex;
    /* 19 */ u8 mRankIndexAtSeq;
    /* 1a */ u8 field1A[2];
    /* 1c */ s32 mRankSeqFrames;
    /* 20 */ u32 field20;
} SceneSoundState;

extern SceneSoundState gSceneSoundState;

extern NNSSndSeqPlayer *data_0217c854;

// Object data_0217d060 points to.
typedef struct SoundSetPlayer {
    /* 00 */ SoundSet mSoundSet;
    /* 0c */ NNSSndSeqPlayer *mSeqPlayer;
    /* 10 */ LoadedSoundSet *mLoadedSet;
} SoundSetPlayer;

extern SoundSetPlayer *data_0217d060;

// Object behind gVolumeFade.
typedef struct VolumeFade {
    /* 00 */ u32 mVolumePerFrame;
    /* 04 */ s32 mVolume;
} VolumeFade;

extern VolumeFade gVolumeFade;

// Values of the two switches in sound_loadSdat.
typedef enum { E0 = 0, E1 = 1, E2 = 2 } Unk02108344;

BOOL loadCharacterSoundsInternal(s32 bankMask);
BOOL sound_loadCharacterSounds(s32 bankMask);
int sound_getSomeSize2(int a);
int sound_getSomeSize(int a);
void ReleaseSndHeaps(void);
void CreateSndHeaps(u32 a, u32 buffer);
void sound_loadSdat(void *buffer, u32 b, u32 c);
void sound_main(void);
void InitSceneSounds(s32 e);
void InitSceneSoundState(u32 a, Unk021073ec b, SceneSoundState *c);
void snd_handleRaceStart(void);
void StartRaceSounds(void);
void snd_startStarMusic(void);
void snd_stopStarMusic(void);
void EndRaceSounds(void);
void snd_handleLapChange(void);
void snd_handlePositionChangeSfx(u32 a);
void snd_2106580(void);
void snd_handleIntroAmbiance(void);
void UpdateSceneSoundState(void);
void StopSceneSounds(void);
void StopSceneSoundsAtOnce(void);
