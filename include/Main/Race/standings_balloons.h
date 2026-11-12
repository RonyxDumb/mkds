#pragma once

#include "types.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject

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

#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h" // CourseMapPoint

void *CreateDistanceSoundUpdateList(void);
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
unsigned int StandingsReturnArgument(unsigned int value);
