#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "Main/Race/data_020f36d8.h" // ItemObject
#include "Main/MapObjects/data_0217b000.h"
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

#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
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
