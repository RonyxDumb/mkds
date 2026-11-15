#pragma once

#include "types.h"
#include "code_02147cd8.h" // Vec3s16

// Sixteen bytes; gCourseCollision.mUnk_08 points to an array of these, which CollideSphereWithCourse indexes by
// halfwords.
typedef struct CourseTriangle {
    /* 00 */ s32 mThirdEdgeOffset;
    /* 04 */ u16 mPointIndex;
    /* 06 */ u16 mPlaneNormalIndex;
    /* 08 */ u16 mFirstEdgeNormalIndex;
    /* 0a */ u16 mSecondEdgeNormalIndex;
    /* 0c */ u16 mThirdEdgeNormalIndex;
    /* 0e */ u16 mHitValue;
} CourseTriangle;

// Object at gCourseCollision (0x3c bytes): three tables, a tree of word offsets, three words, three masks and three
// shift counts.
typedef struct CourseCollision {
    /* 00 */ Vec3 *mPoints;
    /* 04 */ Vec3s16 *mNormals;
    /* 08 */ CourseTriangle *mTriangles;
    /* 0c */ u8 *mTree;
    /* 10 */ u8 mUnk_10[4];
    /* 14 */ s32 mOriginX;
    /* 18 */ s32 mOriginY;
    /* 1c */ s32 mOriginZ;
    /* 20 */ u32 mOutsideMaskX;
    /* 24 */ u32 mOutsideMaskY;
    /* 28 */ u32 mOutsideMaskZ;
    /* 2c */ u32 mTopShift;
    /* 30 */ u32 mYIndexShift;
    /* 34 */ u32 mZIndexShift;
    /* 38 */ u8 mUnk_38[4];
} CourseCollision;

// Bit of the queryFlags argument of CollideSphereWithCourse: skip the triangles whose hit value has bit 0x2000.
#define COURSE_QUERY_SKIP_TAGGED_TRIANGLES 4

// Groups of bits in the collision bits CollideSphereWithCourse stores.
// Floor hits (the bits the kart code reads as the ground attribute).
#define COURSE_HIT_GROUND 0x1e34ef
// Wall hits.
#define COURSE_HIT_WALL 0x214300
// Surfaces that make a hitting item fade out.
#define COURSE_HIT_FADES_ITEMS 0x8000
// Boost surface (items set ITEM_OBJECT_FLAG_ON_BOOST_SURFACE from it).
#define COURSE_HIT_BOOST_SURFACE 0x80000

BOOL CollideSphereWithCourse(Vec3 *position, Vec3 *prevPosition, Vec3 *vector, int radius, u16 queryFlags,
                             short collisionSlotIndex, Vec3 *pushOut, Vec3 *normal, Vec3 *secondNormal,
                             u32 *collisionBits, Vec3 *lowestOffset, Vec3 *pointMotion, u16 *angleChange,
                             u32 *hitObjects);
