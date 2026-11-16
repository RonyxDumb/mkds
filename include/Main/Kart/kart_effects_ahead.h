#pragma once

#include "types.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h" // BattlePointLink

// A position on point links: the current link, the previous link and the direction from one to the other.
typedef struct LinkCursor {
    /* 00 */ BattlePointLink *mLink;
    /* 04 */ BattlePointLink *mPreviousLink;
    /* 08 */ Vec3 mDirection;
    /* 14 */ BattlePointLink *mRequestedLink;
    /* 18 */ BOOL mRequestPending;
} LinkCursor;

#include "Main/Kart/point_link_cursor_advance.h"

void SetupPointLinkCursor(PointLinkCursor *cursor, u32 kartIndex, struct RacePointLink *link);
void AdvanceBattlePointLinkCursorTo(LinkCursor *linkCursor, BattlePointLink *pointLink);
s32 GetBattlePointLinkSpeedLimit(LinkCursor *linkCursor);

void AdvanceBattlePointLinkCursor(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 kartIndex,
                                  MapObject *targetShine, s32 targetKartIndex);

void SetRequestedLinkToPreviousIfNone(PointLinkCursor *linkCursor);
void ResetBattlePointLinkCursorNear(LinkCursor *linkCursor, Vec3 *position, Vec3 *direction, u16 unused);
void ResetBattlePointLinkCursorTo(LinkCursor *linkCursor, BattlePointLink *pointLink);

typedef struct PointLinkCursor PointLinkCursor;
typedef struct RacePointLink RacePointLink;

void AdvancePointLinkCursorTo(PointLinkCursor *linkCursor, RacePointLink *pointLink);

s16 GetPointLinkFirstValue(PointLinkCursor *linkCursor);

extern const Vec3 gPointLinkVec3Zero;

// mStepLimit given to the ahead effect, and to the near-rank effect, when it is stopped: steps it keeps advancing.
#define KART_AHEAD_EFFECT_STOP_STEPS 3
#define KART_NEAR_RANK_EFFECT_STOP_STEPS 5
