#pragma once

#include "types.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_020e005c.h" // Unk020e005c_080
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange

struct MapObject;
struct CourseMapRow;

// Object behind MapObject.field94, passed to SetSoundSourceFlagBit (which reads its halfword at 0x34).
typedef struct MapObjectSound {
    // Sound source of the map object (the sounds started on it).
    /* 00 */ SoundSource mSoundSource;
    /* 44 */ SoundDistanceSquaredChange field44;
    /* 54 */ u8 field54[0xc];
} MapObjectSound;

// Object behind MapObject.mKindData; kinds whose rows point at the same record share it.
typedef struct MapObjectKindData {
    /* 00 */ s32 (*field0)(struct MapObject *e, void *a, s32 *b, s32 *c);
    /* 04 */ s32 (*field4)(struct MapObject *e, void *a, void *b, void *c);
    /* 08 */ s32 mShapeKind;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 (*mSphereHitTest)(struct MapObject *a, Vec3 *b, s32 c, Vec3 *d);
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ s32 field28;
    /* 2c */ s32 field2C;
    /* 30 */ s32 field30;
    /* 34 */ s32 field34;
    /* 38 */ s32 field38;
    /* 3c */ s32 field3C;
} MapObjectKindData;

// Element object up to 0xa0, which every kind shares: mobj_logicPartExecute and mobj_logicPartUpdateSoundEmitter read 0x78 and 0x94 of every
// object, mobj_getCollidesWithItem reads 0x00, 0x02 and 0x98. kuribo_init and dram_init pass the Unk020e005c_080
// at 0x80 to sm_init. From 0xa0 on, the objects of fwdst_init (Unk020e730c), dram_init (Dram), func_020ff97c
// (Unk020ff97c) and AdvancePooledMapObject (PooledMapObject) use the bytes in different ways.
typedef struct MapObject {
    /* 00 */ u16 mKind;
    /* 02 */ u16 mFlags;
    /* 04 */ Vec3 mPos;
    /* 10 */ Vec3 field10;
    /* 1c */ Vec3 mScale;
    /* 28 */ MtxFx43 mMatrix;
    // Size of the collision shape along the object's local axes: the kind's size times mScale (a few kinds set a
    // component directly). x is the radius given to the collision slot, and the Vec3 length is the bounding radius.
    /* 58 */ Vec3 mExtent;
    // Index of the object's entry in the table of collision shapes (0x100 entries of position, radius, mask and
    // object), or -1 when its kind record word at 0x08 is 0 or the table was full. puku_renderMain also reads its lowest
    // bit as a mirror flag for the model.
    /* 64 */ s16 mCollisionSlotIndex;
    // Alpha of the object, 0 to 0x1f. The visibility pass lowers it by 1 per call while mDistanceSquaredAndFlags bit 0
    // is set and raises it by 1 up to 0x1f otherwise (mobj_updateVisibilityNoFade sets 0 or 0x1f at once); the draw group
    // skips the object at 0, the view test counts 1 or less as not drawn, and the model draw lowers the model's polygon
    // alpha to it.
    /* 66 */ u16 mAlpha;
    // Radius of the sphere that the view test checks against the view planes and adds to mDrawDistance: the kind's
    // value times the largest of mScale x, y, z (two kinds use their own factor).
    /* 68 */ s32 mViewRadius;
    // Horizontal distance from the camera, plus mViewRadius, beyond which the view test sets mDistanceSquaredAndFlags
    // bit 0 (the object fades out). The kind's value, capped by the course settings, and 0x270f000 when the game
    // record's fieldC is 3.
    /* 6c */ s32 mDrawDistance;
    // Squared horizontal distance from the camera beyond which the view test sets mDistanceSquaredAndFlags bit 2.
    // Copied from the word at 0x20 of a volume curve of gSfxParams (curve 2 at creation); the kinds compare it with
    // the words of curves 2 and 3 to find which curve they use.
    /* 70 */ s32 mFarDistanceSquared;
    // Mask of the non-zero decimal digits of the course row's number (bit d is digit d; a number of 10000 or more first
    // sets flag 0x80 in mFlags), or copied from the source object. The visibility pass and the kinds that test it treat
    // the object as out of view while a bit is shared with the word driver_getClipAreaMask returns.
    /* 74 */ u32 mDigitMask;
    // Result of the last view test of the object plus bits added by kinds. Bit 0: beyond mDrawDistance; bit 1: outside
    // the view planes (set with bit 0 when mAlpha is 1 or less); bit 2: beyond mFarDistanceSquared (mobj_logicPartUpdateSoundEmitter also
    // sets it); bit 3: set when the object was tested in this pass; bit 4: set by kinds and kept by the test. Bits 5 to
    // 29: the squared horizontal distance to the camera in whole units (read with the mask 0x3fffffe0; a far constant
    // while mDigitMask is shared). Bit 30 is set by kinds and makes mobj_emitDriverHitSfx skip the kind's sound; bit
    // 31 is set by kinds and cleared by ItemObject code, which passes the object on as the one hit.
    /* 78 */ u32 mDistanceSquaredAndFlags;
    // Non-zero when the view test of the object uses only two view planes (mobj_calcVisibilityFlags3d) instead of five
    // (mobj_calcVisibilityFlags2d). Copied from the kind's data at creation.
    /* 7c */ u16 mUseTwoPlaneViewTest;
    /* 7e */ u16 mAngle;
    // State machine of the kind: the table of state handlers, its size and the owner, with the current state, the next
    // state and the frames spent in the state.
    /* 80 */ Unk020e005c_080 mStateMachine;
    // The sound object of the map object, tested against NULL before use: a SoundSource at 0 (so the pointer also
    // serves as the source) and, in the 0x60-byte variant, an SoundDistanceSquaredChange behind it.
    /* 94 */ MapObjectSound *mSound;
    /* 98 */ MapObjectKindData *mKindData;
    /* 9c */ struct CourseMapRow *mCourseMapRow;
} MapObject;

// Object of fwdst_init and fwdst_globalInitLogic: two u16s after the shared part.
typedef struct Unk020e730c {
    /* 00 */ MapObject field0;
    /* a0 */ u16 mTableIndex;
    /* a2 */ u16 mEntryValue;
} Unk020e730c;

// Objects drawn or updated together: mInit runs once when the lists are set up, mBeforeObjects and mAfterObjects run
// around the loop over the objects, mForEachObject runs for each object.
typedef struct MapObjectList {
    /* 00 */ void **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
    /* 06 */ u8 field6[2];
    /* 08 */ void (*mInit)(struct MapObjectList *p);
    /* 0c */ void (*mBeforeObjects)(struct MapObjectList *p);
    /* 10 */ UnkFunc *mForEachObject;
    /* 14 */ void (*mAfterObjects)(struct MapObjectList *p);
    /* 18 */ s32 field18;
    /* 1c */ s32 (*field1C)(MapObject *e, void *a, void *b, void *c);
    /* 20 */ s32 field20;
    /* 24 */ void **field24;
} MapObjectList;

typedef struct NsbmdModel NsbmdModel;
typedef struct MapObjectList MapObjectList;
typedef struct Unk0210b7a8 Unk0210b7a8;

// 0x40-byte block that fwdst_setupConfig takes from data_02159370.
typedef struct Unk020e7410 {
    /* 00 */ u32 field0[0x10];
} Unk020e7410;

// Source rows read by the second loop of jg_load, 0x0c bytes each; a
// row's non-zero words are names looked up by arc_getSceneArcFile.
typedef struct Unk0216c324 {
    /* 00 */ const char *field0;
    /* 04 */ const char *field4;
    /* 08 */ const char *field8;
} Unk0216c324;

// A row of gJgKindRows, by LukituObject: rows 2 and 3 hold a model and one animation, rows 0 and 1 only mLapModel.
typedef struct JgKindRow {
    /* 00 */ void *mModel;
    /* 04 */ void *mNsbcaAnimation;
    /* 08 */ void *mNsbmaAnimation;
    /* 0c */ NsbmdModel *mLapModel;
} JgKindRow;

extern Unk0216c324 data_0216c324[];
// Filled in by jg_init; jg_state1Update stores mobj_calcXZCamDist's return value
// at 0x0c and hands it to func_0210b760.
extern Unk0210b7a8 data_0217b9dc;
extern JgKindRow gJgKindRows[];
extern JgKindRow gJgKindRowLapModels[];
extern JgKindRow data_0217bb08[];

void mobj_logicPartExecuteThunderLogic(MapObjectList *list);
void mobj_logicPartExecute(MapObjectList *list);
void mobj_logicPartUpdateSoundEmitter(MapObject *object);
void fwdst_init(Unk020e730c *object, struct CourseMapRow *courseRow);
void fwdst_globalInitLogic(void);
u16 fwdst_getCCDependentSetting(int index);
MapObjectList *fwdst_setupLogicPart(void);
Unk020e7410 *fwdst_setupConfig(void);
void jg_load(void);
void jg_init(void);
void func_020e79c4(void);
void jg_finishRespawning(void);
void jg_startRespawning(void);
