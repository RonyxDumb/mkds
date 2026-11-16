#pragma once
#include "types.h"
#include "Main/Race/mission_file_row.h" // MissionFileRow
#include "touch_panel_sampling.h"

typedef struct MicBuffer MicBuffer;

typedef struct DWCAccFriendData DWCAccFriendData;

// A time as three parts, minute, second and millisecond; IsTimeLessThanStaffGhostTime sums them in milliseconds.
typedef struct MinuteSecondMillisecondTime {
    /* 00 */ u16 mMillisecond;
    /* 02 */ u8 mMinute;
    /* 03 */ u8 mSecond;
} MinuteSecondMillisecondTime;

// What drives an entry's kart: the player, the game's CPU, a recorded ghost, a player on another console, or nothing.
typedef enum { PLAYER_KIND_HUMAN, PLAYER_KIND_CPU, PLAYER_KIND_GHOST, PLAYER_KIND_PEER, PLAYER_KIND_NONE } PlayerKind;

// Values of the mGhostRecordIndex members: the saved record a ghost entry is read from. NONE is set on entries that are
// not ghosts.
typedef enum {
    GHOST_RECORD_INDEX_COURSE,
    GHOST_RECORD_INDEX_FIRST_SLOT,
    GHOST_RECORD_INDEX_SECOND_SLOT,
    GHOST_RECORD_INDEX_NONE,
} GhostRecordIndex;

// Values of the mCourseListMode members: one course, the course list in order, or the course list shuffled.
enum {
    COURSE_LIST_MODE_SINGLE,
    COURSE_LIST_MODE_IN_ORDER,
    COURSE_LIST_MODE_SHUFFLED,
};

// Bit set of the kinds 0, 2 and 3 (human, ghost, peer): the entries the mask tests pick out.
#define PLAYER_KIND_MASK_HUMAN_GHOST_PEER 0xd

// Bit 0 of KartEntryPlayer.mListedCpuFlags: the entry fills a listed CPU slot.
#define KART_ENTRY_LISTED_CPU_FLAG 1
// KartEntryPlayer.mListedCpuSlot of an entry that fills no listed CPU slot.
#define KART_ENTRY_LISTED_CPU_SLOT_NONE 3
// Courses in a cup; KartEntry.mCourseNumber counts them from 1.
#define COURSES_PER_CUP 4

// The player of a kart entry: kind, team, index, name, emblem, friend data and region.
typedef struct KartEntryPlayer {
    /* 00 */ u32 mKind;
    /* 04 */ s32 mTeamIndex;
    /* 08 */ s32 mListedCpuSlot;
    /* 0c */ s32 mIndex;
    /* 10 */ s32 mGhostRecordIndex;
    /* 14 */ u16 mListedCpuFlags;
// Running number among the kind-1 entries; -1 when the entry has none.
    /* 16 */ s8 mNumber;
    /* 17 */ u8 mUnk_17;
    /* 18 */ void *mName;
    /* 1c */ void *mEmblemData;
    /* 20 */ DWCAccFriendData *mFriendData;
    /* 24 */ u8 mHasEmblem;
    /* 25 */ u8 mRegion;
    /* 26 */ u8 mLowestGrandPrixRecordValue;
    /* 27 */ u8 mUnk_27;
} KartEntryPlayer;

// Character index values (KartEntry.mCharacterIndex and the same-named members of the select screens), in the order of
// gCharacterSubDirNames (the folders of the character models).
enum {
    CHARACTER_MARIO,
    CHARACTER_DONKEY,
    CHARACTER_KINOPIO,
    CHARACTER_KOOPA,
    CHARACTER_PEACH,
    CHARACTER_WARIO,
    CHARACTER_YOSHI,
    CHARACTER_LUIGI,
    CHARACTER_KARON,
    CHARACTER_DAISY,
    CHARACTER_WALUIGI,
    CHARACTER_ROBO,
    CHARACTER_HEYHO,
};

// One kart of the race setup: its character and kart indices and its player (mPlayer).
typedef struct KartEntry {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    // The 0x28-byte record of the entry's player: kind, team, index, name, emblem.
    /* 08 */ KartEntryPlayer mPlayer;
} KartEntry;

// Values of the mMode member of RaceSetup and of RaceSetupHeader. The member is set
// when the race is confirmed and is 0 in the menus before that.
// Grand Prix (also the value in the menus before a race is confirmed): stored as the next mode.
#define MODE_GRAND_PRIX 0

// Time attack: the end handling below is not run in this mode.
#define MODE_TIME_ATTACK 1

// Battle: reads the balloon or shine count of every kart only in this mode.
#define MODE_BATTLE 2

// Versus: shares the case with battle and reads the team setting mUseTeams.
#define MODE_VS 3

// Mission run: the mission row and column are read only while the mode has this value.
#define MODE_MISSION_RUN 4

#define MISSION_RUN_BIT_END_IN_CONTACT 4

#define MISSION_RUN_BIT_END_KART_FLAG_1000 8

#define MISSION_RUN_BIT_END_NOT_NORMAL 2

#define MISSION_RUN_BIT_FLIP_FOLLOW_DIRECTION 0x20

#define MISSION_RUN_BIT_SWAP_LEFT_RIGHT 0x10

// Bits of RaceSetup.mMissionRunBits; each switches on one mission run rule.
#define MISSION_RUN_BIT_INPUT_MASK 1

// WiFi race: the WiFi session and the synced ranks are read only in this mode.
#define MODE_WIFI 5

// Values of the mCourseId member of RaceSetup and of RaceSetupHeader, and of the course id stored in the race
// Values of the mRaceKind member of RaceSetup and of RaceSetupHeader.
// Normal race.
#define RACE_KIND_NORMAL 0

// Demo race that SetNextDemoRace sets up from the title screen.
#define RACE_KIND_DEMO 1

// Replay of the race just finished: the REPLAY entry of the end-of-race menu sets it (SetNextSceneFromPickedValue case
// 8).
#define RACE_KIND_REPLAY 2

// Start scene: it creates RaceStartGp instead of the race HUD; set before each Grand Prix course and for mission
// column 9.
#define RACE_KIND_START_GP 3

// Offline Battle stage fly-over: it creates RaceStartBattle; the kind is 0 once the race starts.
#define RACE_KIND_START_BATTLE 4

// Award scene: the course is COURSE_ID_AWARD.
#define RACE_KIND_AWARD 5

// Staff roll: the course is COURSE_ID_STAFFROLL or COURSE_ID_STAFFROLLTRUE.
#define RACE_KIND_STAFF_ROLL 6

// setup. The value is the row of the course name table gCourseArchiveNames (8 byte rows, the string pointer first):
// BuildCourseArchivePath formats the row's string as the first %s of "/data/Course/%s%s%s.carc". Each name below is
// that row's string without a trailing "_course", upper-cased, and the comment after it quotes the row index and the
// string. Only the values that occur at a compare, case label or store of the member are defined;
// the other rows stay literals.
#define COURSE_ID_OLD_YOSHI_GC 1  // row 1: "old_yoshi_gc"

#define COURSE_ID_OLD_BABY_GC 9  // row 9: "old_baby_gc"

#define COURSE_ID_OLD_MARIO_SFC 10  // row 10: "old_mario_sfc"

#define COURSE_ID_OLD_MOMO_64 11  // row 11: "old_momo_64"

#define COURSE_ID_OLD_KOOPA_AGB 0xc  // row 12: "old_koopa_agb"

#define COURSE_ID_OLD_PEACH_AGB 0xd  // row 13: "old_peach_agb"

#define COURSE_ID_OLD_LUIGI_GC 0xe  // row 14: "old_luigi_gc"

#define COURSE_ID_OLD_NOKO_SFC 0xf  // row 15: "old_noko_sfc"

#define COURSE_ID_OLD_FRAPPE_64 16  // row 16: "old_frappe_64"

#define COURSE_ID_CLOCK 0x11  // row 17: "clock_course"

#define COURSE_ID_MANSION 0x12  // row 18: "mansion_course"

#define COURSE_ID_AIRSHIP 0x13  // row 19: "airship_course"

#define COURSE_ID_CROSS 0x14  // row 20: "cross_course"

#define COURSE_ID_BANK 0x16  // row 22: "bank_course"

#define COURSE_ID_OLD_HYUDORO_64 23  // row 23: "old_hyudoro_64"

#define COURSE_ID_RIDGE 24  // row 24: "ridge_course"

#define COURSE_ID_MARIO 0x19  // row 25: "mario_course"

#define COURSE_ID_GARDEN 26  // row 26: "garden_course"

#define COURSE_ID_DESERT 27  // row 27: "desert_course"

#define COURSE_ID_TOWN 0x1c  // row 28: "town_course"

#define COURSE_ID_RAINBOW 0x1d  // row 29: "rainbow_course"

#define COURSE_ID_SNOW 0x1e  // row 30: "snow_course"

#define COURSE_ID_BEACH 0x1f  // row 31: "beach_course"

#define COURSE_ID_KOOPA 0x20  // row 32: "koopa_course"

#define COURSE_ID_PINBALL 0x21  // row 33: "pinball_course"

#define COURSE_ID_STADIUM 0x22  // row 34: "stadium_course"

#define COURSE_ID_OLD_DONUT_SFC 35  // row 35: "old_donut_sfc"

#define COURSE_ID_OLD_CHOCO_64 36  // row 36: "old_choco_64"

#define COURSE_ID_OLD_LUIGI_AGB 0x25  // row 37: "old_luigi_agb"

#define COURSE_ID_OLD_KINOKO_GC 0x26  // row 38: "old_kinoko_gc"

#define COURSE_ID_OLD_CHOCO_SFC 39  // row 39: "old_choco_sfc"

#define COURSE_ID_OLD_SKY_AGB 40  // row 40: "old_sky_agb"

#define COURSE_ID_MINI_BLOCK 41  // row 41: "mini_block_course"

#define COURSE_ID_MINI_BLOCK_64 0x2a  // row 42: "mini_block_64"

#define COURSE_ID_MINI_DOKAN_GC 0x2b  // row 43: "mini_dokan_gc"

#define COURSE_ID_MINI_STAGE1 0x2c  // row 44: "mini_stage1"

#define COURSE_ID_MINI_STAGE2 0x2d  // row 45: "mini_stage2"

#define COURSE_ID_MINI_STAGE3 0x2e  // row 46: "mini_stage3"

#define COURSE_ID_MINI_STAGE4 0x2f  // row 47: "mini_stage4"

#define COURSE_ID_MR_STAGE1 48  // row 48: "mr_stage1"

#define COURSE_ID_MR_STAGE2 0x31  // row 49: "mr_stage2"

#define COURSE_ID_MR_STAGE3 0x32  // row 50: "mr_stage3"

#define COURSE_ID_MR_STAGE4 0x33  // row 51: "mr_stage4"

#define COURSE_ID_AWARD 0x34  // row 52: "Award"

#define COURSE_ID_STAFFROLL 0x35  // row 53: "StaffRoll"

#define COURSE_ID_STAFFROLLTRUE 0x36  // row 54: "StaffRollTrue"

// The 0x68 bytes at 0x1e8 of the object behind gRaceSetup.
// Values of the mBattleKind member of RaceSetup and of RaceSetupHeader.
typedef enum { BATTLE_KIND_BALLOON, BATTLE_KIND_SHINE } BattleKind;

// Values of the mEngineIndex member, slowest to fastest: the base speed limit scales by 0xb33, 0xd9a, 0x1000.
typedef enum { ENGINE_CLASS_SLOW, ENGINE_CLASS_MEDIUM, ENGINE_CLASS_FAST } EngineClass;

// Values of the mRuleKind member: how a multiplayer race series is scored and ends. WIN_COUNT counts wins (the menu's
// win counter), RACE_COUNT sums the points of a set number of races (the race counter), FREE has no counter.
enum {
    RULE_KIND_FREE,
    RULE_KIND_WIN_COUNT,
    RULE_KIND_RACE_COUNT,
};

// The header of a race setup: course, cup, mode, race kind, rules, mission row, seed and lap count.
typedef struct RaceSetupHeader {
    /* 00 */ s32 mCourseId;
    /* 04 */ s32 mCupIndex;
    /* 08 */ s32 mMode;
    /* 0c */ s32 mRaceKind;
    /* 10 */ s32 mEngineIndex;
    /* 14 */ s32 mCpuDifficulty;
    /* 18 */ s32 mBattleKind;
    /* 1c */ s32 mRuleKind;
    /* 20 */ s32 mCourseListMode;
    /* 24 */ s32 mGhostRecordIndex;
    /* 28 */ MissionFileRow mMissionFileRow;
    /* 54 */ s8 mMissionTableRow;
    /* 55 */ s8 mMissionTableColumn;
    /* 56 */ u8 mUnk_56[0x1];
    /* 57 */ s8 mMirrorMode;
    /* 58 */ u8 mUseTeams;
    /* 59 */ u8 mUnk_59[0x3];
    /* 5c */ s32 mSeed;
    /* 60 */ u16 mCourseNumber;
    /* 62 */ s8 mEntryIndex;
    /* 63 */ u8 mFollowedKartIndex;
    /* 64 */ s8 mLapCount;
    /* 65 */ u8 mUnk_65[0x3];
} RaceSetupHeader;

// Mission run kinds (MissionSettings.mMissionKind): what finishes the mission and what the count tracks.
// Counts a kart entering the finish shape of the course map; also counts the map objects of the mission.
#define MISSION_KIND_COUNT_SHAPE_ENTRIES 0
// Counts through the pending count-up from the coin and boss transfers; has its own count sound.
#define MISSION_KIND_COUNT_PENDING_WITH_SEQ 1
// Lap race without a count.
#define MISSION_KIND_LAPS 2
// Counts the map objects hit (the mission map object kinds).
#define MISSION_KIND_COUNT_MAP_OBJECTS 3
// Lap race that also counts the mini-turbos of the followed kart against the count limit.
#define MISSION_KIND_LAPS_MINI_TURBO_COUNT 4
// Counts through the pending count-up from the coin and boss transfers.
#define MISSION_KIND_COUNT_PENDING 5
// Lap race that fails unless the kart finishes in first place.
#define MISSION_KIND_LAPS_FIRST_PLACE 6
// Counts the hits of the mission map objects.
#define MISSION_KIND_COUNT_HITS 7
// Lap race like MISSION_KIND_LAPS that the lap progress of a kart (race_progress_kart) skips.
#define MISSION_KIND_LAPS_NO_LAP_PROGRESS 10

// Values of MissionSettings.mMissionTableValue: the Mission Run mission number. All but Garden have a boss map object.
enum {
    MISSION_NUMBER_GARDEN = 4,
    MISSION_NUMBER_DONKETU = 9,
    MISSION_NUMBER_KING_ICE_DONKETU = 0xa,
    MISSION_NUMBER_BOMB_KING = 0x11,
    MISSION_NUMBER_KURIKING = 0x15,
    MISSION_NUMBER_HANACHAN = 0x31,
    MISSION_NUMBER_IWANTE = 0x32,
    MISSION_NUMBER_KING_TERESA = 0x33,
};

// The mission rules of a race: time limit, time score, mission kind, camera table index and run count limit.
typedef struct MissionSettings {
    /* 00 */ u16 mMissionTimeLimitFrameCount;
    /* 02 */ u16 mTimeScoreFrameCount;
    /* 04 */ s16 mTimeScoreWeight;
    /* 06 */ u8 mMissionTableValue;
    /* 07 */ u8 mMissionKind;
    /* 08 */ u8 mUnk_08[6];
    /* 0e */ u8 mMissionCameraTableIndex;
    /* 0f */ u8 mMissionRunCountLimit;
} MissionSettings;

#define CPU_DIFFICULTY_HARD 3

#define CPU_DIFFICULTY_NORMAL 2

// Difficulty of the CPU karts, the value of the CPU KART row (RaceSetup.mUnk_014 and the setup copy); 0 is not named.
#define CPU_DIFFICULTY_EASY 1

// A race setup header with its eight kart entries; RaceSetup holds the current one and the next one.
typedef struct RaceSetupBlock {
    RaceSetupHeader mHeader;
    KartEntry mEntries[8];
} RaceSetupBlock;

// The setup of a race: course, cup, mode, race kind, engine, CPU difficulty, battle kind and rule kind.
typedef struct RaceSetup {
    union {
        RaceSetupBlock mCurrent;
        struct {
            /* 00 */ s32 mCourseId;
            /* 004 */ s32 mCupIndex;
            /* 08 */ s32 mMode;
            // Which kind of race scene this is (RACE_KIND_*): the display table and the scene code are chosen by it.
            // RACE_KIND_REPLAY is 2; the value 4 is RACE_KIND_START_BATTLE.
            /* 00c */ u32 mRaceKind;
            /* 010 */ s32 mEngineIndex;
            /* 014 */ s32 mCpuDifficulty;
            // Which battle this is (BattleKind): the end handling, the timer and the item tables differ.
            /* 018 */ s32 mBattleKind;
            /* 01c */ s32 mRuleKind;
            /* 020 */ s32 mCourseListMode;
            /* 024 */ u8 mUnk_024[0x4];
            union {
                MissionSettings mMissionSettings;
                struct {
                    /* 028 */ u16 mMissionTimeLimitFrameCount;
                    /* 02a */ u16 mTimeScoreFrameCount;
                    /* 02c */ s16 mTimeScoreWeight;
                    /* 02e */ u8 mMissionTableValue;
                    /* 2f */ u8 mMissionKind;
                    /* 030 */ u8 mUnk_030[0x6];
                    /* 036 */ u8 mMissionCameraTableIndex;
                    /* 37 */ u8 mMissionRunCountLimit;
                };
            };
            /* 038 */ u16 mFinishWaitFrameCount;
            /* 03a */ u8 mUnk_03a[0x2];
            /* 3c */ u16 mMissionCountMapObjectKinds[4];
            /* 044 */ u16 mMissionRunBits;
            /* 046 */ u8 mUnk_046[0x2];
            /* 048 */ char mMissionRunStem[0xc];
            /* 54 */ s8 mMissionTableRow;
            /* 55 */ s8 mMissionTableColumn;
            /* 056 */ u8 mUnk_056[0x1];
            // Nonzero in mirror mode: the side distance of the camera and the map object models are flipped.
            /* 57 */ s8 mMirrorMode;
            /* 58 */ s8 mUseTeams;
            /* 059 */ u8 mUnk_059[0x3];
            /* 05c */ s32 mSeed;
            /* 60 */ u16 mCourseNumber;
            /* 62 */ s8 mEntryIndex;
            /* 063 */ u8 mFollowedKartIndex;
            // Laps to run; 0 or less means the count of the course setting.
            /* 064 */ s8 mLapCount;
            /* 065 */ u8 mUnk_065[0x3];
            /* 68 */ KartEntry mCurrentEntries[8];
        };
    };
    union {
        RaceSetupBlock mNext;
        struct {
            /* 1e8 */ RaceSetupHeader mNextHeader;
            /* 250 */ KartEntry mNextEntries[8];
        };
    };
    /* 3d0 */ u8 mKartCount;
    /* 3d1 */ u8 mHumanAndPeerKartCount;
    /* 3d2 */ u8 mTeamKartCounts[2];
    /* 3d4 */ u8 mListedCpuCount;
    /* 3d5 */ s8 mListedCpuEntryIndices[3];
    /* 3d8 */ u16 mCourseCount;
    /* 3da */ u8 mUnk_3da[0x2];
    /* 3dc */ u8 *mCourseList;
    /* 3e0 */ u8 mCourseListIndex;
    /* 3e1 */ u8 mNextCpuNumber;
    /* 3e2 */ u16 mFirstGhostRecordMillisecond;
    /* 3e4 */ u8 mFirstGhostRecordMinute;
    /* 3e5 */ u8 mFirstGhostRecordSecond;
    /* 3e6 */ s8 mFirstGhostRecordFilled;
    /* 3e7 */ u8 mUnk_3e7[0x1];
    /* 3e8 */ MinuteSecondMillisecondTime mGhostTime;
    /* 3ec */ MinuteSecondMillisecondTime mGhostLapTimes[5];
} RaceSetup;
// Entries of the course list that RaceSetup.mCourseList points to.
#define RACE_SETUP_COURSE_LIST_LENGTH 0x21

extern RaceSetup *gRaceSetup;

static inline KartEntry *GetCurrentEntry(u16 entryIndex) {
    return &gRaceSetup->mCurrentEntries[entryIndex];
}

static inline void SetListedCpuEntryIndex(u8 listedCpuSlot, s8 entryIndex) {
    gRaceSetup->mListedCpuEntryIndices[listedCpuSlot] = entryIndex;
}

// The touch and microphone input: touch samples, the calibrated point, the sampling flags and the microphone buffer.
typedef struct TouchMicInput {
    /* 00 */ TPData mAutoSamples[5];
    /* 28 */ TPData mCalibratedPoint;
    /* 30 */ union {
        u32 mUnk_30;
        struct {
            s32 mTouchAutoSampling : 1;
            s32 mMicAutoSampling : 1;
            s32 mMicPreSleepDone : 1;
            s32 mMicOverThreshold : 1;
        };
    };
    /* 34 */ u8 mUnk_34[0x8];
    /* 3c */ MicBuffer *mMicBuffer;
} TouchMicInput;

extern TouchMicInput *gTouchMicInput;
