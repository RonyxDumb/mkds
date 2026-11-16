#pragma once

#include "types.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Menu/second_menu_scene.h" // StateMachine
#include "Main/MapObjects/segment_group_collision.h"
#include "Main/Sound/sound_distance_squared_change.h" // SoundDistanceSquaredChange

#define JG_GOAL_FRAME_INDEX 2

// Sound that Jg starts at its position.
#define JG_SOUND_ID 0x101

struct MapObject;
struct CourseMapRow;

// The sound of a map object: its sound source and the change of the squared distance to it.
typedef struct MapObjectSound {
    // Sound source of the map object (the sounds started on it).
    /* 00 */ SoundSource mSoundSource;
    /* 44 */ SoundDistanceSquaredChange mSoundDistanceSquaredChange;
} MapObjectSound;

// Values of MapObjectKindData.mShapeKind: the body that kart and item hits are tested against.
#define MAP_OBJECT_SHAPE_NONE 0
#define MAP_OBJECT_SHAPE_SPHERE 1
#define MAP_OBJECT_SHAPE_CYLINDER 2
#define MAP_OBJECT_SHAPE_ROTATED_CYLINDER 3
#define MAP_OBJECT_SHAPE_ROTATED_BOX 4
#define MAP_OBJECT_SHAPE_CUSTOM_HIT_TEST 5

// The per-kind data of map objects: collision callbacks, shape, extents, sound ids and view settings; kinds may share
// it.
typedef struct MapObjectKindData {
    /* 00 */ s32 (*mCollideKartCallback)(struct MapObject *mapObject, void *kart, s32 *firstResponse,
                                         s32 *secondResponse);
    /* 04 */ s32 (*mCollideItemObjectCallback)(struct MapObject *mapObject, void *itemObject, void *firstResponse,
                                               void *secondResponse);
    /* 08 */ s32 mShapeKind;
    /* 0c */ s32 mExtentX;
    /* 10 */ s32 mExtentY;
    /* 14 */ s32 mExtentZ;
    /* 18 */ s32 (*mSphereHitTest)(struct MapObject *mapObject, Vec3 *position, s32 radius, Vec3 *overlapOffset);
    /* 1c */ s32 mCollidable;
    /* 20 */ s32 mPosStepMode;
    /* 24 */ s32 mSoundId;
    /* 28 */ s32 mCollideItemObjectSoundId;
    /* 2c */ s32 mViewRadius;
    /* 30 */ s32 mDrawDistance;
    /* 34 */ s32 mUseTwoPlaneViewTest;
    /* 38 */ s32 mHeightRangeMax;
    /* 3c */ s32 mHeightRangeMin;
} MapObjectKindData;

// A far-away value (9999.0): the draw distance of a GP start race, and the position step of an object whose kind's
// mPosStepMode is neither 0 nor MAP_OBJECT_LIST_POS_STEP_MEASURED.
#define MAP_OBJECT_FAR_VALUE 0x270f000

// Limit of the height difference between the camera and an object, below and above, that a kind gets when its data
// leaves it 0 (a replay raises the upper one).
#define MAP_OBJECT_HEIGHT_RANGE_DEFAULT 0x64000
#define MAP_OBJECT_HEIGHT_RANGE_REPLAY_UPPER_MIN 0x44c000

// View test kind of a grpconf row from which on the kind uses two view planes.
#define MAP_OBJECT_VIEW_TEST_KIND_TWO_PLANE_MIN 2

// Largest value of MapObject.mAlpha (fully opaque).
#define MAP_OBJECT_ALPHA_MAX 0x1f
// MapObject.mFlags: the object is invisible (the map screen draws no cell for it and unparking keeps its alpha);
// the map screen shows a translucent cell; the flipper is mirrored.
#define MAP_OBJECT_FLAG_INVISIBLE 0x2
#define MAP_OBJECT_FLAG_HUD_XLU 0x20
#define MAP_OBJECT_FLAG_FLIPPER_MIRROR 0x400
// MapObject.mFlags: the speed tests of kart hits are skipped for the object (spin hits and touch sounds happen at any
// speed) and its kind sound is started with the full fraction 0x1000.
#define MAP_OBJECT_FLAG_HIT_AT_ANY_SPEED 0x200

// MapObject.mFlags: karts, items and Jg that overlap the object are not pushed out of it; the hit is still found and
// its callback runs.
#define MAP_OBJECT_FLAG_NO_PUSH_OUT 0x40
// The object is parked (ParkMapObject sets it, UnparkMapObject clears it).
#define MAP_OBJECT_FLAG_PARKED 0x100

// MapObject.mDistanceSquaredAndFlags bit 31: set by kinds; a bounce or fade-out item hit clears it, and reports the
// object as the one hit when the bit was set or the first response is 1.
#define MAP_OBJECT_DISTANCE_FLAG_REPORT_HIT 0x80000000

// The part every map object shares: its kind, flags, position and matrix, collision and view-test values, state
// machine, sound and kind data; each kind adds its own members after it.
typedef struct MapObject {
    /* 00 */ u16 mKind;
    /* 02 */ u16 mFlags;
    /* 04 */ Vec3 mPos;
    /* 10 */ Vec3 mPosStep;
    /* 1c */ Vec3 mScale;
    /* 28 */ MtxFx43 mMatrix;
    // Size of the collision shape along the object's local axes: the kind's size times mScale (a few kinds set a
    // component directly). x is the radius given to the collision slot, and the Vec3 length is the bounding radius.
    /* 58 */ Vec3 mExtent;
    // Index of the object's entry in the table of collision shapes (0x100 entries of position, radius, mask and
    // object), or -1 when its kind record word at 0x08 is 0 or the table was full. DrawPukupuku also reads its lowest
    // bit as a mirror flag for the model.
    /* 64 */ s16 mCollisionSlotIndex;
    // Alpha of the object, 0 to MAP_OBJECT_ALPHA_MAX. The visibility pass lowers it by 1 per call while
    // mDistanceSquaredAndFlags bit 0 is set and raises it by 1 up to 0x1f otherwise (RefreshMapObjectViewTests sets 0
    // or 0x1f at once); the draw group skips the object at 0, the view test counts 1 or less as not drawn, and the
    // model draw lowers the model's polygon alpha to it.
    /* 66 */ u16 mAlpha;
    // Radius of the sphere that the view test checks against the view planes and adds to mDrawDistance: the kind's
    // value times the largest of mScale x, y, z (two kinds use their own factor).
    /* 68 */ s32 mViewRadius;
    // Horizontal distance from the camera, plus mViewRadius, beyond which the view test sets mDistanceSquaredAndFlags
    // bit 0 (the object fades out). The kind's value, capped by the course settings, and 0x270f000 when the game
    // record's mRaceKind is 3.
    /* 6c */ s32 mDrawDistance;
    // Squared horizontal distance from the camera beyond which the view test sets mDistanceSquaredAndFlags bit 2.
    // Copied from the word at 0x20 of a volume curve of gSoundFalloffs (curve 2 at creation); the kinds compare it with
    // the words of curves 2 and 3 to find which curve they use.
    /* 70 */ s32 mFarDistanceSquared;
    // Mask of the non-zero decimal digits of the course row's number (bit d is digit d; a number of 10000 or more first
    // sets flag 0x80 in mFlags), or copied from the source object. The visibility pass and the kinds that test it treat
    // the object as out of view while a bit is shared with the word GetEntryKartZoneMask returns.
    /* 74 */ u32 mDigitMask;
    // Result of the last view test of the object plus bits added by kinds. Bit 0: beyond mDrawDistance; bit 1: outside
    // the view planes (set with bit 0 when mAlpha is 1 or less); bit 2: beyond mFarDistanceSquared
    // (UpdateMapObjectSoundSource also sets it); bit 3: set when the object was tested in this pass; bit 4: set by
    // kinds and kept by the test. Bits 5 to 29: the squared horizontal distance to the camera in whole units (read with
    // the mask 0x3fffffe0; a far constant while mDigitMask is shared). Bit 30 is set by kinds and makes
    // StartMapObjectKindSound skip the kind's sound; bit 31 is set by kinds and cleared by ItemObject code, which
    // passes the object on as the one hit.
    /* 78 */ u32 mDistanceSquaredAndFlags;
    // Non-zero when the view test of the object uses only two view planes (ComputeTwoPlaneViewTest) instead of five
    // (ComputeViewTest). Copied from the kind's data at creation.
    /* 7c */ u16 mUseTwoPlaneViewTest;
    /* 7e */ u16 mAngle;
    // State machine of the kind: the table of state handlers, its size and the owner, with the current state, the next
    // state and the frames spent in the state.
    /* 80 */ StateMachine mStateMachine;
    // The sound object of the map object, tested against NULL before use: a SoundSource at 0 (so the pointer also
    // serves as the source) and a SoundDistanceSquaredChange behind it.
    /* 94 */ MapObjectSound *mSound;
    /* 98 */ MapObjectKindData *mKindData;
    /* 9c */ struct CourseMapRow *mCourseMapRow;
} MapObject;

// Bits of MapObject.mFlags. The low nibble (the 1, 2, 4 and 8 bits) is saved in the high nibble while the object is
// parked.
#define MAP_OBJECT_FLAG_INACTIVE 0x1 // hit tests answer FALSE and the race HUD leaves the object out
#define MAP_OBJECT_FLAG_NO_VIEW_TEST 0x2 // the view test and the sound source update skip the object
#define MAP_OBJECT_FLAG_NO_UPDATE 0x4 // the update lists skip the object
#define MAP_OBJECT_FLAG_NO_ITEM_CALLBACK 0x8 // the item hit callback skips the object
#define MAP_OBJECT_FLAG_OUT_OF_VIEW 0x10 // set by the view test while the object is outside the view planes
#define MAP_OBJECT_FLAG_NOT_COLLIDABLE 0x40 // the kind's collidable word was 0: kart and item hits skip the object
#define MAP_OBJECT_FLAG_HUD_XLU 0x20 // the race HUD draws the cell of the object translucent
#define MAP_OBJECT_FLAG_NUMBER_OVERFLOW                                                                                \
    0x80 // the course row's number was 10000 or more; the park pass parks the object
#define MAP_OBJECT_FLAG_PARKED 0x100
#define MAP_OBJECT_FLAG_MIRRORED 0x400 // the model is drawn mirrored
#define MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI 0x800 // set at creation while gMapObjectsTimeAttackOrWiFi is non-zero
#define MAP_OBJECT_FLAGS_NOT_DRAWN (MAP_OBJECT_FLAG_NO_VIEW_TEST | MAP_OBJECT_FLAG_OUT_OF_VIEW)
#define MAP_OBJECT_FLAGS_SKIP_ITEM_CALLBACK (MAP_OBJECT_FLAG_NO_ITEM_CALLBACK | MAP_OBJECT_FLAG_NUMBER_OVERFLOW)
#define MAP_OBJECT_FLAGS_LOW_NIBBLE 0xf
#define MAP_OBJECT_FLAGS_SAVED_NIBBLE 0xf000

// Bits of MapObject.mDistanceSquaredAndFlags (the squared distance sits in the bits of MAP_OBJECT_VIEW_DISTANCE_MASK).
#define MAP_OBJECT_VIEW_BEYOND_DRAW_DISTANCE 0x1
#define MAP_OBJECT_VIEW_OUTSIDE_PLANES 0x2
#define MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE 0x4
#define MAP_OBJECT_VIEW_OUT_OF_SIGHT (MAP_OBJECT_VIEW_BEYOND_DRAW_DISTANCE | MAP_OBJECT_VIEW_OUTSIDE_PLANES)
#define MAP_OBJECT_VIEW_TESTED 0x8
#define MAP_OBJECT_VIEW_FAR_KART_TOUCH 0x10
#define MAP_OBJECT_VIEW_DISTANCE_MASK 0x3fffffe0
#define MAP_OBJECT_VIEW_SKIP_KIND_SOUND 0x40000000

// An invisible attractor map object: a table index and a strength; a Kart on the attractor surface is pulled toward it.
typedef struct AttractorMapObject {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mTableIndex;
    /* a2 */ u16 mStrength;
} AttractorMapObject;

// Values of MapObjectList.mPassOrPosStepMode: the first or second draw pass of a draw list; in an update list the value
// the kind gives (3 = not set yet), where 2 makes the update loop take each object's position change as its step.
#define MAP_OBJECT_LIST_PASS_FIRST 1
#define MAP_OBJECT_LIST_PASS_SECOND 2
#define MAP_OBJECT_LIST_POS_STEP_MEASURED 2
#define MAP_OBJECT_LIST_POS_STEP_UNSET 3
#define MAP_OBJECT_LIST_ITEM_RESPONSE_UNSET 3

// The update and draw lists call mForEachObject with different arguments and the stored functions take their own object
// type, so its type is left unprototyped.
typedef void (*MapObjectForEachCallback)();

// Objects drawn or updated together: mInit runs once when the lists are set up, mBeforeObjects and mAfterObjects run
// around the loop over the objects, mForEachObject runs for each object.
typedef struct MapObjectList {
    /* 00 */ void **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ void (*mInit)(struct MapObjectList *list);
    /* 0c */ void (*mBeforeObjects)(struct MapObjectList *list);
    /* 10 */ MapObjectForEachCallback mForEachObject;
    /* 14 */ void (*mAfterObjects)(struct MapObjectList *list);
    // Update lists: the kind's mPosStepMode (3 = not set yet). Draw lists: 1 or 2, the first or second pass.
    /* 18 */ s32 mPassOrPosStepMode;
    // A callback in the update lists (CallMapObjectListCallback); the draw lists test it for non-zero
    // (InitMapObjectDrawOrder, the draw loop) and the kinds' creators set it to 1.
    /* 1c */ union {
        s32 (*mCollideItemObjectCallback)(MapObject *mapObject, void *itemObject, void *firstResponse,
                                          void *secondResponse);
        s32 mSortByDistance;
    };
    /* 20 */ s32 mItemFirstResponse;
    // Draw lists: the object array the draw loop walks. Update lists keep the address of their global here.
    /* 24 */ void **mDrawOrder;
} MapObjectList;

typedef struct NsbmdModel NsbmdModel;
typedef struct ModelAnimation ModelAnimation;
typedef struct MapObjectList MapObjectList;
typedef struct SoundStartParams SoundStartParams;

// The model and animation file names of a Jg kind; FindSceneFile looks up each non-zero name.
typedef struct JgKindFileNames {
    /* 00 */ const char *mNsbmdName;
    /* 04 */ const char *mNsbcaName;
    /* 08 */ const char *mNsbmaName;
} JgKindFileNames;

// A row of gJgKindRows, by gJgKind: rows 2 and 3 hold a model and one animation, rows 0 and 1 only mLapModel.
typedef struct JgKindRow {
    /* 00 */ void *mModel;
    /* 04 */ ModelAnimation *mNsbcaAnimation;
    /* 08 */ ModelAnimation *mNsbmaAnimation;
    /* 0c */ NsbmdModel *mLapModel;
} JgKindRow;

// InitJg sets mSoundId, mPositionSource and mFalloffIndex; UpdateJgReverse sets mDistanceSquared from
// GetHorizontalCameraDistanceSquared and passes it to StartSndHandleSound.
extern SoundStartParams gJgSoundStartParams;
extern JgKindRow gJgKindRows[];

void CallMapObjectListCallback(MapObjectList *list);
void UpdateMapObjectList(MapObjectList *list);
void UpdateMapObjectSoundSource(MapObject *object);
void InitAttractorMapObject(AttractorMapObject *object, struct CourseMapRow *courseRow);
void BuildAttractorTables(void);
u16 GetAttractorStrength(u16 index);
MapObjectList *CreateAttractorUpdateList(void);
MapObjectKindData *CreateAttractorKindData(void);
void CreateJg(void);
void InitJg(void);
void ReleaseJg(void);
void SetJgFollowKartCountdown(void);
void SetJgFollowKart(void);

Vec3 *GetAttractorPosition(u16 index);

extern StateCallbacks gJgStateTable[7];
extern struct MapObjectList *gAttractorUpdateList;
extern Vec3 **gAttractorPositions;
extern u16 *gAttractorStrengths;

extern JgKindFileNames gJgKindFileNames[4];
