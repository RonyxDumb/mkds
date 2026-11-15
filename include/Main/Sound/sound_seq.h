#pragma once

#include "types.h"
#include "sound_player_control.h"
#include "Main/Sound/sound_set_load.h"

extern const Vec3 gVec3Ones;
extern const Vec3 gPooledMapObjectVec3Zero;

void StopMissionRunMSselSeqsAtOnce();
void StopMissionRunMSselSeqsWithSteps();

void StartSceneSeqAfterMissionRunLVsel(u32 mode);
void LoadMissionRunMSselSoundData(u32 mode, u32 missionRow);
void UpdateMissionRunMSselSounds(s32 stepId);

void StopMissionRunLVselSeqsWithSteps(int mode, u32 fadeSteps);

void LowerSndHandleVolumes(void);
void RaiseSndHandleVolumes(void);
void StartChoisesSValueSeq(s32 valueIndex);
void StopAllSeqPlayers(void);
void SetSndHandleTrackVolume(NNSSndSeqPlayer **handle, u32 volume);
void SetSndHandleTrackPitch(NNSSndSeqPlayer **handle, u32 pitch);
void StartSoundOncePerFrame(s32 seqNo);
void StartMissionRunLVselSeq(u32 mode);
void StartSceneSeqIfIdle(void);

void StopSceneSeqWithFadeSteps(void);

typedef struct NNSSndSeqPlayer NNSSndSeqPlayer;

// 0x08-byte entries behind gCourseSurfaceSoundEntries; GetSurfaceSoundId reads one as a sound id array, so the variant
// is also the id for entry index 1.
typedef struct CourseSurfaceSoundEntry {
    /* 00 */ u32 mSoundId;
    /* 04 */ u32 mSurfaceVariant;
} CourseSurfaceSoundEntry;

extern CourseSurfaceSoundEntry gCourseSurfaceSoundEntries[14];

// Object behind gOldLuigiAgbSurfaceSoundSetup.
typedef struct SurfaceSoundSetup {
    /* 00 */ u32 mSoundIds[4];
    /* 10 */ u32 mRowIndex;
    /* 14 */ u32 mColumnIndex;
} SurfaceSoundSetup;

// Object behind gLoadedSoundBanks.
typedef struct LoadedSoundBanks {
    /* 00 */ u16 mBankMask;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u32 mLoadMarker;
} LoadedSoundBanks;

// Values of ScenePlayers.mProgress: released, set up by InitScenePlayers, then the scene and the race started.
#define SCENE_PLAYERS_PROGRESS_RELEASED 0
#define SCENE_PLAYERS_PROGRESS_INITIALIZED 1
#define SCENE_PLAYERS_PROGRESS_SCENE_STARTED 2
#define SCENE_PLAYERS_PROGRESS_RACE_STARTED 3
// ScenePlayersSeqInfo.mSeqStartProgress that never starts the sequence.
#define SCENE_PLAYERS_SEQ_START_NEVER 0xff

// Values of LoadedSoundBanks.mLoadMarker: no banks loaded, and the banks of mBankMask loaded.
// LOADED_SOUND_BANKS_MENU_SET is the mBankMask stored after InitSceneSounds loaded bank 0x2c and seq arc 3 for the menu
// scenes.
#define LOADED_SOUND_BANKS_NONE 0xff00
#define LOADED_SOUND_BANKS_LOADED 0xfe00
#define LOADED_SOUND_BANKS_MENU_SET 0xffff

// Values of SceneSoundState.mRaceState.
#define SCENE_RACE_STATE_BEFORE_START 0
#define SCENE_RACE_STATE_RUNNING 1
#define SCENE_RACE_STATE_ENDED 2

// Values of SceneSoundState.mLastLapSeqState: no last lap sequence, it plays, and it plays while the sound mode is
// paused (bit 0 stays set).
#define SCENE_LAST_LAP_SEQ_NONE 0
#define SCENE_LAST_LAP_SEQ_PLAYING 1
#define SCENE_LAST_LAP_SEQ_PAUSED 3

// SceneSoundState.mRankIndex and mRankIndexAtSeq before a place was stored.
#define SCENE_RANK_INDEX_NONE 0xff
// Pinball: SetSceneSoundRank starts no rank sequence while slot 7 plays this seq arc entry (seq number 0).
#define SCENE_RANK_PINBALL_BLOCKING_SEQ_ARC_INDEX 0x1cc

// Frames after which the scene sound steps run: the course sequence of a scene starts (most courses; the two later
// ones), the airship one stops and restarts, the logo scene sequence stops, the race sequence starts, and the stored
// place stops counting. SCENE_RANK_START_DELAY_FRAMES is the race frame from which a better place can start a sequence.
#define SCENE_COURSE_SEQ_START_FRAMES 0xa
#define SCENE_COURSE_SEQ_START_LATE_FRAMES 0x28
#define SCENE_AIRSHIP_SEQ_STOP_FRAMES 0xa0
#define SCENE_AIRSHIP_SEQ_RESTART_FRAMES 0x122
#define SCENE_LOGO_SEQ_STOP_FRAMES 0x5d
#define SCENE_RACE_SEQ_START_FRAMES 0x28
#define SCENE_RANK_SEQ_FRAMES 0x3c
#define SCENE_RANK_START_DELAY_FRAMES 0xf0

// PlayerVolumeFade.mPlayerMask...: bit n is the library sound player n; all of them, and all but the highest.
#define SOUND_PLAYER_MASK_ALL 0xff
#define SOUND_PLAYER_MASK_ALL_BUT_HIGHEST 0x7f

// Rows of the mission table (GetMissionTableRow) whose sequence and bank LoadMissionRunMSselSoundData picks, named by
// the mission whose bank (SOUND_BANK_MISSION_*) the row loads.
#define MISSION_TABLE_ROW_DONKETU 1
#define MISSION_TABLE_ROW_IWANTE 2
#define MISSION_TABLE_ROW_KURIKING 3
#define MISSION_TABLE_ROW_KING_TERESA 4
#define MISSION_TABLE_ROW_BOMB_KING 5
#define MISSION_TABLE_ROW_KING_ICE_DONKETU 6
// The last of the seven rows of the mission select; its bank is 0x17.
#define MISSION_TABLE_ROW_HANACHAN 7

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
    union {
        struct {
            /* 0c */ u32 mTargetVolumeBeforeRaceStart;
            /* 10 */ u32 mTargetVolumeAfterRaceStart;
        };
        /* 0c */ u32 mTargetVolumes[2]; // indexed by mRaceStarted
    };
    union {
        struct {
            /* 14 */ u32 mPlayerMaskBeforeRaceStart;
            /* 18 */ u32 mPlayerMaskAfterRaceStart;
        };
        /* 14 */ u32 mPlayerMasks[2];
    };
    union {
        struct {
            /* 1c */ u32 mVolumePerFrameBeforeRaceStart;
            /* 20 */ u32 mVolumePerFrameAfterRaceStart;
        };
        /* 1c */ u32 mVolumePerFrames[2];
    };
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

// Values of the two switches in InitSound.
typedef enum { SND_HEAP_SIZE_LARGE = 0, SND_HEAP_SIZE_MEDIUM = 1, SND_HEAP_SIZE_SMALL = 2 } SndHeapSizeKind;

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
void SetSceneSoundRank(u8 rankIndex);
void UpdateRaceSounds(void);
void UpdateCourseSeqAtSceneFrames(void);
void UpdateSceneSoundState(void);
void StopSceneSounds(void);
void StopSceneSoundsAtOnce(void);

LoadedSoundSet *GetLoadedSoundSet(void);

void StartWiFiNoOpponentsSeq(void);
void StopBothSeqHandles(void);

void StartWiFiLoginErrorSeq(void);

void StartWiFiSessionMatchingSeq(void);
void StartWiFiMatchingEntryShowSeq(void);
void StartWiFiMatchingEntryHideSeq(void);
void StartPlayerEntryListSetupSeq(void);

void StartWiFiSessionLoginResult1Seq(void);
void StartWiFiSessionLoginSeq(void);

void StopTimeAttackGhostSendSeq(void);

void StartTimeAttackGhostSendSeq(void);
void StartMessageScreenSeq(void);
void BootInfoStartMessageScreenSeq(void);
void StopSeqZeroLoop(void);
void StartSeqZeroLoop(void);

extern s32 gSndHeapSizeKind;
extern LoadedSoundBanks gLoadedSoundBanks;
extern SurfaceSoundSetup gOldLuigiAgbSurfaceSoundSetup;
extern s32 gSndBankIdsByBit[13];
extern s32 gSndWaveArcIdsByBit[13];

extern const u16 gChoisesSValueSeqNos[6];

extern u16 gMissionRunLimitSeqNo[1];
extern u16 gMissionRunCountSeqNo[1];

extern SoundHandlePool gSoundHandlePool;
extern u8 gSoundHandlePoolEntries[21];
