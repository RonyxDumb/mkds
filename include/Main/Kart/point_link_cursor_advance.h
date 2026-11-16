#pragma once

#include "types.h"

typedef struct RacePointLink RacePointLink;

// A position on race point links: the current link, the previous link and the direction from one to the other.
typedef struct PointLinkCursor {
    /* 00 */ RacePointLink *mLink;
    /* 04 */ RacePointLink *mPreviousLink;
    /* 08 */ Vec3 mDirection;
    /* 14 */ RacePointLink *mRequestedLink;
    /* 18 */ BOOL mRequestedLinkFound;
    /* 1c */ u16 mKartIndex;
    /* 1e */ u8 mBranchChoiceCount;
} PointLinkCursor;

// A cursor that moves a killer along a point link path: the angle to the next link, its kart and the end count.
typedef struct KartKillerCursor {
    /* 00 */ PointLinkCursor mPointLinkCursor;
    /* 20 */ s32 mAngleToLinkDegrees;
    /* 24 */ u16 mKillerKartIndex;
    /* 26 */ s16 mEndCount;
    /* 28 */ s16 mEndCountHoldTimer;
} KartKillerCursor;

void AdvancePointLinkCursor(PointLinkCursor *pointLinkCursor);
BOOL IsPastPointLink(PointLinkCursor *pointLinkCursor, Vec3 *position);
BOOL IsWithinPointLinkDistance(PointLinkCursor *pointLinkCursor, Vec3 *position);
