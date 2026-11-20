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

// A surface sound of a course: a sound id and a surface variant (GetSurfaceSoundId reads both as an id array).
typedef struct CourseSurfaceSoundEntry {
    /* 00 */ u32 mSoundId;
    /* 04 */ u32 mSurfaceVariant;
} CourseSurfaceSoundEntry;

extern CourseSurfaceSoundEntry gCourseSurfaceSoundEntries[14];

// A surface sound setup: four sound ids and the row and column index they are set for.
typedef struct SurfaceSoundSetup {
    /* 00 */ u32 mSoundIds[4];
    /* 10 */ u32 mRowIndex;
    /* 14 */ u32 mColumnIndex;
} SurfaceSoundSetup;

// The loaded sound banks: a bank mask and a load marker.
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
// ScenePlayersSeqInfo.mSeqStartProgress that matches neither the scene start nor the race start, so those starts skip
// the sequence (most gSoundRowTable rows).
#define SCENE_PLAYERS_SEQ_START_UNMATCHED 0xff

// Values of LoadedSoundBanks.mLoadMarker: no banks loaded, and the banks of mBankMask loaded or being loaded (it is
// stored before LoadSndBanksAndWaveArcs runs). LOADED_SOUND_BANKS_MENU_SET is the mBankMask stored after
// InitSceneSounds loaded bank 0x2c and seq arc 3 for the menu scenes.
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
#define PINBALL_COURSE_SEQ_ARC_INDEX 0x1cc

// Scene frames at which the scene sound steps run: the course sequence of a scene starts (most courses; the two later
// ones), the airship one stops and restarts, the logo scene sequence stops. Race frames: the race sequence starts at
// SCENE_RACE_SEQ_START_FRAMES and the frame count of a started rank sequence is dropped at SCENE_RANK_SEQ_FRAMES; a
// better place can start a sequence only after more than SCENE_RANK_START_DELAY_FRAMES.
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

// Rows of the mission table (GetMissionTableRow), named by the mission shown for the row on the mission select;
// LoadMissionRunMSselSoundData picks the sequence and bank of the row.
#define MISSION_TABLE_ROW_DONKETU 1
#define MISSION_TABLE_ROW_IWANTE 2
#define MISSION_TABLE_ROW_KURIKING 3
#define MISSION_TABLE_ROW_KING_TERESA 4
#define MISSION_TABLE_ROW_BOMB_KING 5
#define MISSION_TABLE_ROW_KING_ICE_DONKETU 6
// The last of the seven rows of the mission select; its bank is 0x17.
#define MISSION_TABLE_ROW_HANACHAN 7

// The sequence info of the scene players: the scene progress at which the sequence starts, and its id.
typedef struct ScenePlayersSeqInfo {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mSeqStartProgress;
    /* 02 */ u8 mSeqId;
} ScenePlayersSeqInfo;

// The player volume fade: the volume and its step per frame, with the target volumes and player masks per race phase.
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

// A pool of sound handle entries: the entry count, the index and address of the entry tried next, and the entry storage
// and size.
typedef struct SoundHandlePool {
    /* 00 */ s32 mCount;
    /* 04 */ s32 mNextIndex;
    /* 08 */ u8 *mNextEntry;
    /* 0c */ u8 *mEntries;
    /* 10 */ s32 mEntrySize;
} SoundHandlePool;

// One sound handle of a pool: the sequence player and its age.
typedef struct SoundHandleEntry {
    /* 00 */ NNSSndSeqPlayer *mSeqPlayer;
    /* 04 */ s32 mAge;
} SoundHandleEntry;

// The sound state of a scene: race and scene frames, the kart star sequence, lap and rank state and lowered volumes.
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

// A sound set with the sequence player that plays it and the loaded set it was loaded into.
typedef struct SoundSetPlayer {
    /* 00 */ SoundSet mSoundSet;
    /* 0c */ NNSSndSeqPlayer *mSeqPlayer;
    /* 10 */ LoadedSoundSet *mLoadedSet;
} SoundSetPlayer;

extern SoundSetPlayer *gCurrentSoundSetPlayer;

// A volume fade: the volume and its step per frame.
typedef struct VolumeFade {
    /* 00 */ u32 mVolumePerFrame;
    /* 04 */ s32 mVolume;
} VolumeFade;

// Values of gSndHeapSizeKind and of the heapSizeKind arguments (CreateSndHeaps, InitSound, GetSndHeapsBufferSize,
// GetSndInitBufferSize).
typedef enum { SOUND_HEAP_SIZE_LARGE = 0, SOUND_HEAP_SIZE_MEDIUM = 1, SOUND_HEAP_SIZE_SMALL = 2 } SndHeapSizeKind;

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
