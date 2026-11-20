#pragma once

#include "types.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Kart/camera.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"

// Values of CourseMap.mVersion that change the file layout.
#define COURSE_MAP_VERSION_KEYED_PLACEMENTS 0x1f
#define COURSE_MAP_VERSION_ITEM_POINT_SIZE 0x21
#define COURSE_MAP_VERSION_RACE_END_PLACEMENTS 0x24

// Values of CourseMapShape.mKind.
#define COURSE_MAP_SHAPE_KIND_CAMERA 1
#define COURSE_MAP_SHAPE_KIND_MISSION_END 2
#define COURSE_MAP_SHAPE_KIND_ZONE 3
#define COURSE_MAP_SHAPE_KIND_POINT_LINK 4
#define COURSE_MAP_SHAPE_KIND_MAP_OBJECT_COUNT 5

// Values of CourseMapShape.mShapeKind.
#define COURSE_MAP_SHAPE_FORM_BOX 0
#define COURSE_MAP_SHAPE_FORM_CYLINDER 1

// No route in a slot of CourseMapRoute.mNextRoutes and mPreviousRoutes, or of the battle route point lists; the second
// spelling is the same byte read as an s8.
#define COURSE_MAP_ROUTE_NONE 0xff
#define COURSE_MAP_ROUTE_NONE_S8 -1

// CourseMapCheckpoint.mForwardLink and mBackwardLink: none.
#define COURSE_MAP_CHECKPOINT_NO_LINK -1

// CourseMapCheckpoint.mNumber: none.
#define COURSE_MAP_CHECKPOINT_NO_NUMBER -1

// Bit 0 of CourseMapCheckpoint.mFlags: the progress of a kart in it is set to 0x1000 minus 0x190 per kart slot (per
// Wi-Fi player number in Wi-Fi mode).
#define COURSE_MAP_CHECKPOINT_FLAG_STAGGER 0x1

// Unused entry of CourseMap.mRespawnIndexBySlot.
#define COURSE_MAP_RESPAWN_SLOT_NONE 0xffff

// The course map view of the sub screen: the position it centres on and its angle in degrees (mPos, mAngleDegrees).
typedef struct {
    /* 00 */ Vec3 mPos;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ s32 mAngleDegrees;
} CourseMapSubScreenView;

// One entry of the table at CourseMap.mEntryGroups.
typedef struct CourseMapEntryGroup {
    /* 00 */ u8 mUnk_00[1];
    /* 01 */ u8 mWraps;
    /* 02 */ u16 mEntryCount;
} CourseMapEntryGroup;

// Per-course values of CourseMap.mSettings: fog, the course color, four colors, the lap count or battle time, whether
// the start side is flipped, and the map object draw distance and camera far distances.
typedef struct CourseMapSettings {
    /* 00 */ u8 mUnk_00[2];
    // Lap count; in battle mode the same halfword is the time limit in seconds (times 60 frames into
    // RaceProgress.mTimeLimitFrameCount when RaceSetup.mBattleKind is BATTLE_KIND_SHINE).
    /* 02 */ u16 mLapCountOrBattleSeconds;
    /* 04 */ u8 mStartSideFlipped;
    /* 05 */ u8 mFogEnabled;
    // 0, 1 or 2 when mFogEnabled is set: which of three formulas InitRaceFog uses to fill the 32-entry fog table (8
    // words, gCourseFogTable); other values leave it unfilled.
    /* 06 */ u8 mFogTableMode;
    /* 07 */ u8 mFogSlope;
    /* 08 */ u8 mUnk_08[8];
    // Divided by 512 it is the offset written to reg_G3X_FOG_OFFSET (scaled by the fade factor while fading).
    /* 10 */ s32 mFogOffset;
    // Bits 0 to 14: the course colour, the fog colour when mFogEnabled is not 0 and colour 0 of the main screen palette
    // in SetupRaceHudScreens (not for RACE_KIND_START_GP, RACE_KIND_AWARD or RACE_KIND_STAFF_ROLL); bits 15 to 19: the
    // fog alpha (the fog colour register gets colour | alpha << 16).
    /* 14 */ s32 mColorAndFogAlpha;
    // Four 15-bit colours (5-5-5); InitCourseColorBlend, SetCourseColorBlendColor and AdvanceCourseColorBlend pick one
    // by the lowest set bit of a 4-bit mask (1 at set-up, bits 26 to 29 of the collision flags afterwards; colour in
    // use
    // is skipped by AdvanceCourseColorBlend) and blend the colour of a kart model entry, item object or vehicle toward
    // it.
    /* 18 */ u16 mColors[4];
    // Upper limit for the mDrawDistance of every map object (SetMapObjectDrawDistance); 0 means no limit; not applied
    // when RaceSetup.mRaceKind is 3.
    /* 20 */ s32 mMapObjectDrawDistanceMax;
    // Far plane distance of the cameras of this course; SetupCamera copies it to Camera.mFar and uses 0x640000 when it
    // is below 0x1000.
    /* 24 */ s32 mCameraFar;
} CourseMapSettings;

// A shape of the course map: its position, scale, three axes, box or cylinder form, kind and kind value, and the point
// link, camera or increase limit it refers to.
typedef struct CourseMapShape {
    /* 00 */ Vec3 mPos;
    /* 0c */ Vec3 mScale;
    /* 18 */ Vec3 mAxisX;
    /* 24 */ Vec3 mAxisY;
    /* 30 */ Vec3 mAxisZ;
    /* 3c */ u16 mKindParam;
    /* 3e */ s16 mIncreaseCountLimit;
    // For a shape of mKind 4: index of the point link that belongs to it, in CourseMap.mRacePointLinks (races) or
    // CourseMap.mBattlePointLinks (battles).
    /* 40 */ s16 mPointIndex;
    /* 42 */ u8 mShapeKind;
    // For a shape of mKind 1: index into CourseMap.mCameras of the camera entry used while a kart is inside the shape
    // (the only reader is GetCourseMapCameraIndexAtPos).
    /* 43 */ u8 mCameraIndex;
    /* 44 */ u8 mKind;
    /* 45 */ u8 mUnk_45[3];
} CourseMapShape;

// A point of a route: mPos, mRadius and mValues (entries of CourseMap.mBattlePoints and mRacePoints;
// MoveToRandomForwardBattlePoint returns one).
typedef struct {
    /* 00 */ Vec3 mPos;
    /* 0c */ s32 mRadius;
    /* 10 */ s16 mValues[4];
} CourseMapPoint;

// A battle point link: up to eight links to neighbouring point links and their count, a point with its radius and
// values, and the route link mask.
typedef struct BattlePointLink {
    /* 00 */ struct BattlePointLink *mLinks[3];
    /* 0c */ struct BattlePointLink *mUnk_0c;
    /* 10 */ u8 mUnk_10[8];
    /* 18 */ Vec3 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ Vec3 *mPoint;
    /* 24 */ s32 mRadius;
    /* 28 */ s16 *mValues;
    /* 2c */ u16 mLinkCount;
    /* 2e */ u8 mRouteLinkMask;
    /* 2f */ u8 mUnk_2f;
} BattlePointLink;

struct CourseMapRow;

// A position, rotation, point index and key where a kart is put (CourseMap.mStartPlacements and mKeyedPlacements).
typedef struct CourseMapPlacement {
    /* 00 */ Vec3 mPos;
    /* 0c */ Vec3 mRotation;
    /* 18 */ s16 mPointIndex;
    // Key that selects the record: in mStartPlacements GetCourseMapStartPlacementWithOffsets compares it with its key
    // argument (only with several start placements); in mKeyedPlacements it is the index in mKeyedPlacementIndexByKey
    // that holds the record's index.
    /* 1a */ u16 mKey;
} CourseMapPlacement;

// Where a kart is put back after it falls or is flagged by the surface (CourseMap.mRespawns).
typedef struct CourseMapRespawn {
    /* 00 */ Vec3 mPos;
    /* 0c */ Vec3 mRotation;
    // Index of the point link of this respawn spot, in CourseMap.mRacePointLinks (races) or CourseMap.mBattlePointLinks
    // (battles); the respawn getters return it as a pointer.
    /* 18 */ u16 mPointIndex;
    // Index of the item point link of this respawn spot in CourseMap.mItemPointLinks; ResetKartToRespawnPoint reads it
    // only outside MODE_BATTLE and when mItemRouteCount is not 0.
    /* 1a */ u16 mItemPointIndex;
    // Key of the record in mRespawnIndexBySlot (built in the loader; unused in mode 2).
    /* 1c */ s16 mSlot;
    /* 1e */ u8 mUnk_1e[2];
} CourseMapRespawn;

// A gate across the course (CourseMap.mCheckpoints): its two end points, direction, neighbours and respawn slot.
typedef struct CourseMapCheckpoint {
    // End points A and B of a checkpoint line are mPointAX/mPointAZ and mPointBX/mPointBZ;
    // IsPointBetweenCheckpointLines compares a kart position with the line through the A ends of two checkpoints and
    // the line through their B ends.
    /* 00 */ s32 mPointAX;
    /* 04 */ s32 mPointAZ;
    /* 08 */ s32 mPointBX;
    /* 0c */ s32 mPointBZ;
    // X and z of the direction the course runs through this checkpoint: the progress between two checkpoints is
    // measured along it, and in UpdateRaceProgressKarts a kart that is not on a boost surface and whose forward vector
    // has a dot product with it below -1394 gets RACE_PROGRESS_KART_FLAG_AGAINST_CHECKPOINT in RaceProgressKart.mFlags.
    /* 10 */ IntPair mDirection;
    /* 18 */ s32 mSumValue;
    /* 1c */ s16 mForwardLink;
    /* 1e */ s16 mBackwardLink;
    // Number of this checkpoint among the numbered ones (COURSE_MAP_CHECKPOINT_NO_NUMBER = none);
    // EnterRaceProgressKartCheckpoint stores it in the kart's mCheckpointNumber and, when it is at most one above, in
    // mInOrderCheckpointNumber.
    /* 20 */ s16 mNumber;
    /* 22 */ u8 mRespawnSlot;
    /* 23 */ u8 mFlags;
} CourseMapCheckpoint;

// A run of consecutive table entries with links to other runs: the checkpoint, item and race routes of CourseMap.
typedef struct CourseMapRoute {
    /* 00 */ u16 mFirstEntry;
    /* 02 */ u16 mEntryCount;
    // Numbers of up to three routes that follow this route (255 = none); the last route of a lap names route 0.
    /* 04 */ u8 mNextRoutes[3];
    // Numbers of up to three routes that come before this route (255 = none).
    /* 07 */ u8 mPreviousRoutes[3];
    // Whole-number offset of this route along the lap: added to the position inside the route and scaled by
    // RaceProgress.mLapProgressScale (1 / (CourseMap.mLapProgressBaseMax + 1)).
    /* 0a */ u8 mLapProgressBase;
    /* 0b */ u8 mUnk_0b;
} CourseMapRoute;

// An item point: mPos, mRadius and mLinkIndex (entries of CourseMap.mItemPoints from
// COURSE_MAP_VERSION_ITEM_POINT_SIZE; CourseMapOldItemPoint before).
typedef struct {
    /* 00 */ Vec3 mPos;
    /* 0c */ s32 mRadius;
    /* 10 */ u8 mLinkIndex;
    /* 11 */ u8 mUnk_11[3];
} CourseMapItemPoint;

// The item point of format versions below COURSE_MAP_VERSION_ITEM_POINT_SIZE: mPos and mRadius without mLinkIndex
// (entries of CourseMap.mItemPoints).
typedef struct {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
} CourseMapOldItemPoint;

// A battle route: mFirstEntry, mEntryCount, mNextPoints and mPreviousPoints (entries of CourseMap.mBattleRoutes).
typedef struct {
    /* 00 */ u16 mFirstEntry;
    /* 02 */ u16 mEntryCount;
    /* 04 */ u8 mNextPoints[8];
    /* 0c */ u8 mPreviousPoints[8];
} CourseMapBattleRoute;

// A row of CourseMap.mEntryGroupTable: mGroup and mEntries (the group and its first entry in mGroupEntries).
typedef struct {
    /* 00 */ CourseMapEntryGroup *mGroup;
    /* 04 */ CourseMapGroupEntry *mEntries;
} CourseMapEntryGroupTableRow;

// A race point link: the next and previous point links, and a point with its radius and values.
typedef struct RacePointLink {
    /* 00 */ struct RacePointLink *mNextLinks[3];
    /* 0c */ struct RacePointLink *mPreviousLinks[3];
    /* 18 */ Vec3 *mPoint;
    /* 1c */ s32 mRadius;
    /* 20 */ s16 *mValues;
    /* 24 */ u16 mNextCount;
    /* 26 */ u16 mPreviousCount;
} RacePointLink;

// Node of the lists at CourseMap.mZoneShapeLists: an entry of the table at mShapes and the next node.
typedef struct CourseMapZoneShapeNode {
    /* 00 */ CourseMapShape *mShape;
    /* 04 */ struct CourseMapZoneShapeNode *mNext;
} CourseMapZoneShapeNode;

// The race end placement of the course map: mPos, mRotation and mKeepSpeedFlag.
typedef struct CourseMapRaceEndPlacement {
    /* 00 */ Vec3 mPos;
    /* 0c */ Vec3 mRotation;
    /* 18 */ u8 mUnk_18[2];
    /* 1a */ s16 mKeepSpeedFlag;
} CourseMapRaceEndPlacement;

// The course map: its rows, groups, settings, start placements, respawns, checkpoints, item points and their routes.
typedef struct CourseMap {
    /* 00 */ struct CourseMapRow *mRows;
    /* 04 */ u16 mRowCount;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ CourseMapEntryGroup *mEntryGroups;
    /* 0c */ u16 mEntryGroupCount;
    /* 00e */ u8 mUnk_00e[0x2];
    /* 010 */ CourseMapGroupEntry *mGroupEntries;
    /* 014 */ u16 mGroupEntryCount;
    /* 016 */ u8 mUnk_016[0x2];
    /* 018 */ CourseMapSettings *mSettings;
    /* 01c */ CourseMapPlacement *mStartPlacements;
    // Count of records of mStartPlacements; four of the five reads only test > 1 (several start spots: battle) or <= 1.
    /* 020 */ u16 mStartPlacementCount;
    /* 022 */ u8 mUnk_022[0x2];
    /* 024 */ CourseMapRespawn *mRespawns;
    /* 028 */ u16 mRespawnCount;
    /* 02a */ u8 mUnk_02a[0x2];
    /* 2c */ CourseMapSubScreenView *mSubScreenView;
    /* 30 */ u16 mSubScreenViewCount;
    /* 32 */ u8 mUnk_32[0x2];
    // Records (CourseMapPlacement: position, rotation, battle point index, key) where PlaceKartAtKeyedPlacement puts a
    // kart and AdvanceKartToKeyedPlacement (key 0) moves one toward; found by key through mKeyedPlacementIndexByKey;
    // loaded
    // from COURSE_MAP_VERSION_KEYED_PLACEMENTS on, empty in older files.
    /* 34 */ CourseMapPlacement *mKeyedPlacements;
    /* 38 */ u16 mKeyedPlacementCount;
    /* 3a */ u8 mUnk_3a[0x2];
    /* 3c */ CourseMapRaceEndPlacement *mRaceEndPlacements;
    /* 40 */ u16 mRaceEndPlacementCount;
    /* 42 */ u8 mUnk_42[0x2];
    /* 44 */ CourseMapCheckpoint *mCheckpoints;
    /* 48 */ u16 mCheckpointCount;
    /* 4a */ u8 mUnk_4a[0x2];
    /* 4c */ CourseMapRoute *mCheckpointRoutes;
    /* 50 */ u16 mCheckpointRouteCount;
    /* 52 */ u8 mUnk_52[0x2];
    // Item points (CourseMapItemPoint, CourseMapOldItemPoint before COURSE_MAP_VERSION_ITEM_POINT_SIZE);
    // mItemPointLinks is built from them.
    /* 54 */ CourseMapItemPoint *mItemPoints;
    // Number of mItemPoints, and of mItemPointLinks.
    /* 58 */ u16 mItemPointCount;
    /* 5a */ u8 mUnk_5a[0x2];
    // Item routes: runs of consecutive item points (first point, count, up to three next and three previous routes).
    /* 5c */ CourseMapRoute *mItemRoutes;
    // Number of mItemRoutes; when it is not 0 CreateCourseMap builds mItemPointLinks, InitKartItems stores
    // mItemRoute0FirstLink as the kart's item link, and ResetKartToRespawnPoint stores the respawn's item point link
    // outside MODE_BATTLE.
    /* 60 */ u16 mItemRouteCount;
    /* 62 */ u8 mUnk_62[0x2];
    // Race points (CourseMapPoint), stored here instead of mBattlePoints when mStartPlacementCount is 1 or less;
    // mRacePointLinks is built from them.
    /* 64 */ CourseMapPoint *mRacePoints;
    // Number of mRacePoints, and of mRacePointLinks.
    /* 68 */ u16 mRacePointCount;
    /* 6a */ u8 mUnk_6a[0x2];
    // Race routes over mRacePoints (first point, count, up to three next and three previous routes).
    /* 6c */ CourseMapRoute *mRaceRoutes;
    // Number of mRaceRoutes; the kart code tests it together with mBattleRouteCount (InitKartResources, AdvanceKartAi,
    // StartKartRaceEnd).
    /* 70 */ u16 mRaceRouteCount;
    /* 72 */ u8 mUnk_72[0x2];
    /* 74 */ CourseMapShape *mShapes;
    /* 78 */ u16 mShapeCount;
    /* 7a */ u8 mUnk_7a[0x2];
    /* 7c */ CourseMapCamera *mCameras;
    /* 80 */ u16 mCameraCount;
    /* 82 */ u8 mUnk_82[0x2];
    // Battle points (CourseMapPoint), stored here instead of mRacePoints when mStartPlacementCount is more than 1;
    // mBattlePointLinks is built from them.
    /* 84 */ CourseMapPoint *mBattlePoints;
    // Number of mBattlePoints, and of mBattlePointLinks.
    /* 88 */ u16 mBattlePointCount;
    /* 8a */ u8 mUnk_8a[2];
    // Battle routes over mBattlePoints (first point, count, two lists of up to eight point indices, one for each end of
    // the route).
    /* 8c */ CourseMapBattleRoute *mBattleRoutes;
    // Number of mBattleRoutes; see mRaceRouteCount for the course test.
    /* 90 */ u16 mBattleRouteCount;
    /* 92 */ u8 mUnk_92[2];
    // One 8-byte record per element of mEntryGroups: the group record and the address of its first 0x14-byte entry in
    // mGroupEntries; built by BuildCourseMapEntryGroupTable, read through
    // GetCourseMapEntryGroupTableRow.
    /* 94 */ CourseMapEntryGroupTableRow *mEntryGroupTable;
    /* 98 */ u16 mNumberedCheckpointCount;
    // Last entry of the run that comes just before entry 0: first entry + count - 1 of the run named by the first
    // mPreviousRoutes of the run whose mFirstEntry is 0 (0 when there are no runs). EnterRaceProgressKartCheckpoint
    // takes a lap off when a kart goes from entry 0 back onto it. With branches only the first previous route is
    // followed.
    /* 9a */ u16 mLastCheckpoint;
    // Largest CourseMapRoute.mLapProgressBase of mCheckpointRoutes, set once by CreateCourseMap;
    // RaceProgress.mLapProgressScale is 1 / (it + 1).
    /* 9c */ u16 mLapProgressBaseMax;
    /* 9e */ u8 mUnk_9e[2];
    // One 0x28-byte link per race point (up to three next and three previous links, a pointer to the point, two
    // values), built from mRacePoints and mRaceRoutes; read by FindCourseMapPointLinkShapeRacePointLink and
    // GetCourseMapRespawnRacePointLink.
    /* a0 */ RacePointLink *mRacePointLinks;
    // Link of the first point of mRaceRoutes[0].
    /* a4 */ RacePointLink *mRaceRoute0FirstLink;
    // Link of the last point of the route before mRaceRoutes[0].
    /* a8 */ s32 mRaceRoute0PreviousLastLink;
    // One 0x28-byte link per item point (up to three next and three previous links, a pointer to the point, two
    // values), built from mItemPoints and mItemRoutes; followed by the kart item code and the item objects.
    /* ac */ struct ItemPointLink *mItemPointLinks;
    // Link of the first point of mItemRoutes[0]; the link indices of the item objects count from it.
    /* b0 */ struct ItemPointLink *mItemRoute0FirstLink;
    // Link of the last point of the route before mItemRoutes[0].
    /* b4 */ s32 mItemRoute0PreviousLastLink;
    // One 0x30-byte link per battle point (up to eight neighbour links, a pointer to the point, two values, a link
    // count and a bit mask), built from mBattlePoints and mBattleRoutes; read by
    // FindCourseMapPointLinkShapeBattlePointLink, GetCourseMapRespawnBattlePointLink and
    // GetKeyedPlacementBattlePointLink.
    /* b8 */ BattlePointLink *mBattlePointLinks;
    // Address of the first element of mBattlePointLinks.
    /* bc */ BattlePointLink *mFirstBattlePointLink;
    // Address one past the last element of mBattlePointLinks.
    /* c0 */ BattlePointLink *mBattlePointLinksEnd;
    // The first entry whose mChainStart is 1.
    /* c4 */ CourseMapCamera *mFirstChainStartEntry;
    /* c8 */ CourseMapCamera *mSecondChainStartEntry;
    /* cc */ CourseMapCamera *mFirstAngleStartCamera;
    /* d0 */ CourseMapCamera *mFirstBattleSequenceCamera;
    // The first entry of mKind 8, set only when the mode is 4; the loader does not set it to NULL first.
    /* d4 */ CourseMapCamera *mFirstMissionRunCamera;
    /* d8 */ struct CourseMapZoneShapeNode *mZoneShapeLists[8];
    /* f8 */ u16 *mRespawnIndexBySlot;
    // Record index of mKeyedPlacements for each key, one halfword per record (BuildCourseMapKeyedPlacementIndexByKey).
    /* fc */ u16 *mKeyedPlacementIndexByKey;
    // Mode 2 only: the slot GetCourseMapRespawnSlot hands out next; counts up modulo mRespawnCount.
    /* 100 */ u16 mNextRespawnSlot;
    /* 102 */ u16 mPointLinkShapeCount;
    // Sum of the checkpoint values along the route chain from route 0 (0 when the course has several start placements).
    /* 104 */ u32 mCheckpointSum;
    // mCheckpointSum / 15000, a 1.12 fixed-point factor for the kart race progress.
    /* 108 */ s32 mCheckpointSumQuotient;
    // Format version, CourseMapHeader.mVersion of the course map file; COURSE_MAP_VERSION_KEYED_PLACEMENTS adds the
    // mKeyedPlacements section, COURSE_MAP_VERSION_ITEM_POINT_SIZE makes the mItemPoints entries 0x14 bytes,
    // COURSE_MAP_VERSION_RACE_END_PLACEMENTS adds the mRaceEndPlacements section.
    /* 10c */ u16 mVersion;
    /* 10e */ u8 mUnk_10e;
    /* 10f */ u8 mMissionEndShapeCount;
} CourseMap;

// Scrolling of the sub screen view in RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL: a held direction key moves mScrollPosition
// by the step when mScrollTimer is not 0 (otherwise it first puts it at the followed kart) and sets mScrollTimer to the
// start.
#define RACE_HUD_SUB_SCREEN_SCROLL_STEP 0xa000
#define RACE_HUD_SUB_SCREEN_SCROLL_TIMER_START 600
// The scroll timer counts down from the start value; when it would go below this value it is held here while the view
// moves one step per call toward the followed kart, and it is set to 0 on arrival.
#define RACE_HUD_SUB_SCREEN_SCROLL_TIMER_FOLLOW 300

// How the course maps onto the sub screen: centers, angle pairs, the kart icons, course and bg3 min and max with their
// inverses, and the scroll position and timer.
typedef struct RaceHudSubScreenProjection {
    /* 00 */ IntPair mCenter;
    /* 08 */ s32 mCenterRemainderX;
    /* 0c */ s32 mCenterRemainderY;
    /* 10 */ IntPair mCenterWhole;
    /* 18 */ s32 mHalfSize;
    /* 1c */ s16 mAnglePairSecond;
    /* 1e */ s16 mAnglePairFirst;
    /* 20 */ s32 mAnglePairSecondScaled;
    /* 24 */ s32 mAnglePairFirstScaled;
    /* 28 */ s32 mCourseWidthScaled;
    /* 2c */ IntPair mKartIconsMin;
    /* 34 */ IntPair mKartIconsMax;
    /* 3c */ s64 mKartIconsInverseFirst;
    /* 44 */ s64 mKartIconsInverseSecond;
    /* 4c */ IntPair mCourseMin;
    /* 54 */ IntPair mCourseMax;
    /* 5c */ s64 mCourseInverseX;
    /* 64 */ s64 mCourseInverseZ;
    /* 6c */ IntPair mBg3Min;
    /* 74 */ IntPair mBg3Max;
    /* 7c */ s64 mBg3InverseX;
    /* 84 */ s64 mBg3InverseZ;
    /* 8c */ s32 mScrollTimer;
    /* 90 */ Vec3 mScrollPosition;
} RaceHudSubScreenProjection;

extern struct CourseMap *gCourseMap;

static inline CourseMapRoute *GetCheckpointRoute(u16 routeIndex) {
    return &gCourseMap->mCheckpointRoutes[routeIndex];
}

static inline CourseMapEntryGroup *GetCourseMapEntryGroup(u16 groupIndex) {
    return &gCourseMap->mEntryGroups[groupIndex];
}

static inline CourseMapCamera *GetCourseMapCamera(u16 cameraIndex) {
    return &gCourseMap->mCameras[cameraIndex];
}

#include "Main/System/input_slots.h"

extern u16 GetPadInputSlot(void);
s32 MulFixed12NoRound(s32 multiplicand, s32 multiplier);
void UpdateRaceHudSubScreenProjectionAndBgAffine(RaceHudSubScreenBgAffine *bgAffines, s32 scale);
s32 RaceHudSubScreenGetCurrentMirrorMode(void);
s32 GetFixed12Whole(s32 value);
s32 RaceHudSubScreenFX_SinIdx(s32 angle);
s32 RaceHudSubScreenFX_CosIdx(s32 angle);
void UpdateRaceHudSubScreenScroll(void);
u16 RaceHudSubScreenGetDownBits(s32 slotIndex, s32 mask);
u16 RaceHudSubScreenGetSlotDownBits(InputSlot *inputSlot, s32 mask);
void UpdateRaceHudSubScreenBg3CenterByFrames(RaceHudSubScreenBgAffine *out);
s32 MulFx64c(s32 value, s64 factor);
CourseMapSubScreenView *GetCourseMapSubScreenView(void);
void UpdateRaceHudSubScreenBg3Center(RaceHudSubScreenBgAffine *out);
void UpdateRaceHudSubScreenCenter(RaceHudSubScreenBgAffine *out);
BOOL ComputeRaceHudSubScreenPosition(const Vec3 *pos, IntPair *out, s32 subScreenScale, s32 requireNearCenter,
                                     s32 exactCenter);
void ComputeRaceHudSubScreenKartPosition(s32 kartIndex, IntPair *out, s32);
BOOL IsRaceHudSubScreenPairNearCenter(const IntPair *position);
void ComputeRaceHudSubScreenCoursePosition(const Vec3 *pos, IntPair *out);
void ComputeSubScreenKartIconsKartPosition(s32 kartIndex, IntPair *out);
u16 GetRaceHudSubScreenKartAngle(s32 kartIndex);
u16 GetSubScreenAngleAndClearScrollTimer(void);
BOOL IsCourseWithSubBg3CntBit13(void);
BOOL IsCourseWithMap2DLocal3(void);
void ClearRaceHudSubScreenProjection(void);

void InitRaceHudSubScreenProjection(void);
extern const Vec3 gRaceHudSubScreenInitialScrollPosition;

extern RaceHudSubScreenProjection *gRaceHudSubScreenProjection;
