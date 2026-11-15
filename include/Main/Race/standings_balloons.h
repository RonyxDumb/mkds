#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Item/item_objects_and_race_progress.h" // ItemObject
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/shine16.h" // KartBalloons
#include "Main/MapObjects/map_object_kind_update_list.h"

// Object with the MapObject base at 0x00 (UpdateDistanceSound, InitDistanceSoundObjects, InitDistanceSound).
typedef struct DistanceSound {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mSoundVolumeFixed12;
    /* a4 */ s32 mDistanceVolumeFixed12;
    // Radius in whole units; the inner half-radius test uses w / 2 without the << 12.
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
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h" // CourseMapPoint

MapObjectList *CreateDistanceSoundUpdateList(void);
extern MapObjectKindDescriptor gDistanceSoundKindDescriptor;
void UpdateDistanceSound(void *mapObjectList, DistanceSound *mapObject);
void InitDistanceSoundObjects(MapObjectList *mapObjectList);
void InitDistanceSound(DistanceSound *mapObject);
// Steps Standings once per UpdateRace call in battle and mission run: the end timer and end callback, the hand- over of
// eliminated karts, the hit tracking, and the copy of each kart's position.
void UpdateStandings(void);
// Ends the Standings end timer (mEndTimer = -1) and runs mEndCallback when it is set; the mode 4 end step of the race
// progress calls it.
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
// The Standings object, allocated by InitStandings in modes 2 and 4.
extern Standings *gStandings;

// Frames Standings.mKarts[].mMicInflateTimer is set to, and its value while the kart does not inflate (all bits set).
#define STANDINGS_MIC_INFLATE_FRAMES 10
#define STANDINGS_MIC_INFLATE_NONE 0xffffffff
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
#define DISTANCE_SOUND_VOLUME_MIN 0xc000
