#pragma once

#include "types.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h" // PointLink

// A position on point links: the current link, the previous link and the direction from one to the other.
typedef struct LinkCursor {
    /* 00 */ PointLink *mLink;
    /* 04 */ PointLink *mPreviousLink;
    /* 08 */ Vec3 mDirection;
    /* 14 */ PointLink *mRequestedLink;
    /* 18 */ BOOL mUnk_18;
} LinkCursor;

#include "Main/Kart/code_02080b1c.h"

void SetupPointLinkCursor(PointLinkCursor *cursor, u32 kartIndex, struct RacePointLink *link);
void AdvanceBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink);
s32 GetBattlePointLinkSpeedLimit(LinkCursor *linkCursor);

void AdvanceBattlePointLinkCursor(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 kartIndex,
                                  MapObject *targetShine, s32 targetKartIndex);

void SetRequestedLinkToPreviousIfNone(PointLinkCursor *linkCursor);
void ResetBattlePointLinkCursorNear(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 unused);
void ResetBattlePointLinkCursorTo(LinkCursor *linkCursor, PointLink *pointLink);

typedef struct PointLinkCursor PointLinkCursor;
typedef struct RacePointLink RacePointLink;

void AdvancePointLinkCursorTo(PointLinkCursor *linkCursor, RacePointLink *pointLink);

s16 GetPointLinkFirstValue(PointLinkCursor *linkCursor);

extern const Vec3 gPointLinkVec3Zero;
