#pragma once

#include "types.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Item/item_objects_and_race_progress.h" // ItemObject
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/shine16.h" // KartBalloons
#include "Main/MapObjects/map_object_kind_update_list.h"

// A map object that plays a sound by distance: its sound ids, centre and radius, the distance level (and whether it is
// inverted), the volumes, and the timers of the distance level check and of the sound start.
typedef struct DistanceSound {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mSoundVolumeFixed12;
    /* a4 */ s32 mDistanceVolumeFixed12;
    // Radius in whole units: the outer distance test squares TO_FIXED12(mRadius), the inner test squares mRadius / 2
    // without TO_FIXED12.
    /* a8 */ s32 mRadius;
    /* ac */ s32 mCenterX;
    /* b0 */ s32 mCenterY;
    /* b4 */ s32 mCenterZ;
    /* b8 */ BOOL mDistanceLevelInverted;
    /* bc */ u16 mSoundId;
    /* be */ u16 mSecondSoundId;
    /* c0 */ s32 mDistanceLevelTimer;
    /* c4 */ s32 mDistanceLevel;
    /* c8 */ s32 mSoundTimer;
} DistanceSound;

#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h" // CourseMapPoint

MapObjectList *CreateDistanceSoundUpdateList(void);
extern MapObjectKindDescriptor gDistanceSoundKindDescriptor;
void UpdateDistanceSound(void *mapObjectList, DistanceSound *mapObject);
void InitDistanceSoundObjects(MapObjectList *mapObjectList);
void InitDistanceSound(DistanceSound *mapObject);
// Called once per UpdateRace in battle and mission run. While no winner is set, for each kart it marks a
// just-eliminated kart eliminated (and queues its own sound) and, for a kart with a count above 0, updates the
// select-key and mic inflate state, the hit callbacks and mPos. Once mWinnerTeamId is set it only counts mEndTimer down
// to the end callback and marks just-eliminated karts.
void UpdateStandings(void);
// Sets Standings.mEndTimer to -1 and calls mEndCallback when it is set; AdvanceMissionRunEnd calls it in mission run
// once the goal or failure wait is over.
void FinishStandings(void);
void InitStandings(void);
CourseMapPoint *MoveToRandomForwardBattlePoint(void);
Vec3 *GetKartStandingPos(int kartIndex);
void CallKartHitCallbackForSelf(u16 kartIndex);
void SetWinnerIfOneTeamLeft(void);
void EliminateKart(u16 kartIndex);
void MoveKartTowardLastRank(u16 kartIndex);
void MoveKartTowardFirstRank(u16 kartIndex);
u16 GetBattleItemRank(s32 kartIndex);
void ClearStandingsHitSeenFromKart(s32 kartIndex);
void StandingsNop(s32 entryIndex);

BOOL IsKartLastByBalloonOrShineCount(u16 kartIndex);
BOOL IsKartEliminated(int kartIndex);
void AddBalloonsLeftToMake(u16 kartIndex, s32 amount);
// TRUE when the kart's mTeamId equals Standings.mWinnerTeamId and mEndTimer is below 0, the end being reached.
BOOL IsKartOnWinningTeamAtEnd(s32 kartIndex);

u16 GetBalloonsLeftToMake(u16 kartIndex);

void AddBalloonOrShineCountAndMoveRank(u16 kartIndex, s32 amount);
u16 GetBalloonOrShineCount(u16 kartIndex);
u16 GetHighestBalloonOrShineCount(void);
u16 GetTotalBalloonOrShineCount(void);

void AddShineCount(short amount);
unsigned int GetShineCount(void);
u16 GetKartStandingRankIndex(int kartIndex);

BOOL IsWinnerDecided(void);

u32 IsWinnerDecidedAndEndReached(void);

u16 AdvanceShineBattleTimeLimit(void);
void EliminateKartAndCheckWinner(u16 kartIndex);
void EliminateKartsUntilWinnerDecided(void);

void ClearStandingEliminationStatus(int kartIndex);

void CallStandingsKartOffsetCallback(u16 kartIndex, Vec3 *offset);
s32 CallKartCollisionCallbacks(s32 firstKartIndex, s32 secondKartIndex);
void SetKartHitByKartIndexFromItem(s32 kartIndex, ItemObject *itemObject);

u32 IsKartInflatingBalloon(u16 kartIndex);

void SetKartInflatingBalloon(u16 kartIndex, u32 inflating);

s32 GetKartSelectKeyInflate(u16 kartIndex);
s32 GetKartMicInflateTimer(u16 kartIndex);

void StopKartMicInflate(int kartIndex);

void StartKartMicInflate(u16 kartIndex);

void SetStandingsKartOffsetCallback(void (*callback)(u16, Vec3 *));
void SetStandingsEndCallback(void (*callback)(void));
void SetStandingsKartEliminatedCallback(void (*callback)(u16 kartIndex));
void SetStandingsKartHitCallback(s32 (*callback)(u16 kartIndex, u16 hitByKartIndex));
void SetStandingsKartsHitEachOtherCallback(void (*callback)(s32, s32));
void SetStandingsKartHitByKartCallback(s32 (*callback)(s32, s32));
// Returns Standings.mKartBalloons, the pointer stored by SetStandingsKartBalloons.
KartBalloons *GetStandingsKartBalloons(void);
// Stores the pointer to the KartBalloons array of the balloon object in Standings.mKartBalloons.
void SetStandingsKartBalloons(KartBalloons *kartBalloons);

extern const u32 gShineBattleTimeLimits[4];
// The Standings object, allocated by InitStandings in battle and mission run.
extern Standings *gStandings;

// Standings.mKarts[].mMicInflateTimer: the frames it is set to when an inflate starts, and the value (all bits set)
// that StopKartMicInflate, and a not normal kart or an A or B press, store to cancel it; otherwise it counts down to 0.
#define STANDINGS_MIC_INFLATE_FRAMES 10
#define STANDINGS_MIC_INFLATE_STOPPED 0xffffffff
// Standings.mLowestBalloonOrShineCount before any kart was counted, and the frames mEndTimer waits when a battle ends.
#define STANDINGS_LOWEST_COUNT_START 0xffff
#define STANDINGS_END_FRAMES 0x5a
// KartStanding.mTeamId of the first and the second battle team (a kart without a team uses its kart index).
#define STANDINGS_TEAM_ID_FIRST_TEAM 1
#define STANDINGS_TEAM_ID_SECOND_TEAM 3
// Distance sound of a course: the sound ids and the radius of the area it covers, the frames between distance level
// checks, and the volume limits (fixed-point volume 0 to SOUND_VOLUME_MAX).
#define DISTANCE_SOUND_ID_MANSION 0x121
#define DISTANCE_SOUND_ID_BEACH 0x111
#define DISTANCE_SOUND_ID_BEACH_SECOND 0x10a
#define DISTANCE_SOUND_ID_DEFAULT 0x20d
#define DISTANCE_SOUND_RADIUS_WIDE 0xa28
#define DISTANCE_SOUND_RADIUS_BEACH 0x546
#define DISTANCE_SOUND_LEVEL_FRAMES 0xf
#define DISTANCE_SOUND_SOUND_VOLUME_MIN 0xc000
