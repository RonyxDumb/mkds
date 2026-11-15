#include "ITCM/sphere_collision.h"
#include "ITCM/collision_slots.h"
#include "Main/MapObjects/rock.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Item/kart_items_collision_hits.h"

#include "Main/MapObjects/choropu.h"
#include "ITCM/kart_items_update.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "fixed_vector_math.h"
#include "registers.h"
#include "Main/MapObjects/sphere_collision_data.h"
#include "Main/MapObjects/course_collision_data.h"

BOOL CollideSphereWithCourse(Vec3 *position, Vec3 *prevPosition, Vec3 *vector, int radius, u16 queryFlags,
                             short collisionSlotIndex, Vec3 *pushOut, Vec3 *normal, Vec3 *secondNormal,
                             u32 *collisionBits, Vec3 *lowestOffset, Vec3 *pointMotion, u16 *angleChange,
                             u32 *hitObjects) {
    u16 *triangleIndexCursor;
    CourseTriangle *triangles;
    s64 radiusSquared;
    Vec3 *points;
    Vec3s16 *normals;
    u16 hitBitIndex;
    s64 remainingSquared;
    s64 sqrtInput;
    CourseTriangle triangle;
    Vec3 positionCopy;
    Vec3 prevPositionCopy;
    Vec3 relativePosition;
    Vec3 relativeVector;
    BOOL anyHit = FALSE;
    Vec3 offset = {0, 0, 0};
    BOOL wantsHitRecords = pushOut != NULL || normal != NULL || secondNormal != NULL;
    u32 hitBits = 0;
    CollisionHitRecord firstHitRecord = gFirstHitRecordInitial;
    CollisionHitRecord secondHitRecord = gSecondHitRecordInitial;
    Vec3 extraMaxOffset = {0, 0, 0};
    Vec3 extraMinOffset = {0, 0, 0};
    Vec3 maxXZOffset = {0, 0, 0};
    Vec3 minXZOffset = {0, 0, 0};
    Vec3 trianglePoint;
    Vec3 triangleNormals[4];
    Vec3 lowestOffsetValue;
    CourseCollision *courseCollision;
    u32 cellX;
    u32 cellY;
    u32 cellZ;
    u32 shift;
    u8 *treeCursor;
    s32 value;
    u16 triangleIndex;
    s32 penetration;
    s32 planeDistance;
    s32 firstEdgeDistance;
    s32 secondEdgeDistance;
    s32 thirdEdgeDistance;
    u16 triangleFlags;
    s32 dot;
    u32 triangleHitBits;
    s32 foundObjectIndex;
    s32 hitObjectCount;
    void *foundObject;
    u32 hitObjectBit;

    if (lowestOffset != NULL) {
        lowestOffsetValue.x = 0;
        lowestOffsetValue.z = 0;
        lowestOffsetValue.y = radius * 2;
    }
    gCollisionHitCount = 0;
    courseCollision = &gCourseCollision;
    positionCopy = *position;
    if (prevPosition != NULL) {
        prevPositionCopy = *prevPosition;
    }
    cellX = FROM_FIXED12(positionCopy.x - courseCollision->mOriginX);
    radiusSquared = (s64) radius * radius;
    if (cellX & courseCollision->mOutsideMaskX) {
        return FALSE;
    }
    cellY = FROM_FIXED12(positionCopy.y - courseCollision->mOriginY);
    if (cellY & courseCollision->mOutsideMaskY) {
        return FALSE;
    }
    cellZ = FROM_FIXED12(positionCopy.z - courseCollision->mOriginZ);
    if (cellZ & courseCollision->mOutsideMaskZ) {
        return FALSE;
    }
    shift = courseCollision->mTopShift;
    value = ((cellZ >> shift) << courseCollision->mZIndexShift) | ((cellY >> shift) << courseCollision->mYIndexShift) |
            (cellX >> shift);
    treeCursor = courseCollision->mTree;
    value = ((s32 *) treeCursor)[value];
    while (value >= 0) {
        treeCursor += value;
        shift--;
        value =
            ((s32 *)
                 treeCursor)[((cellX >> shift) & 1) | ((((cellZ >> shift) & 1) << 2) | (((cellY >> shift) & 1) << 1))];
    }
    treeCursor += value & 0x7fffffff;
    triangles = courseCollision->mTriangles;
    points = courseCollision->mPoints;
    normals = courseCollision->mNormals;
    triangleIndexCursor = (u16 *) treeCursor;
    while ((triangleIndex = *++triangleIndexCursor) != 0) {
        triangle = triangles[triangleIndex];
        trianglePoint = points[triangle.mPointIndex];
        VEC_Subtract(&positionCopy, &trianglePoint, &relativePosition);
        triangleNormals[3].x = normals[triangle.mThirdEdgeNormalIndex].x;
        triangleNormals[3].y = normals[triangle.mThirdEdgeNormalIndex].y;
        triangleNormals[3].z = normals[triangle.mThirdEdgeNormalIndex].z;
        dot = Vec3DotUnrounded(&relativePosition, &triangleNormals[3]);
        if (dot < -radius) {
            continue;
        }
        thirdEdgeDistance = dot - triangle.mThirdEdgeOffset;
        if (thirdEdgeDistance >= radius) {
            continue;
        }
        triangleNormals[1].x = normals[triangle.mFirstEdgeNormalIndex].x;
        triangleNormals[1].y = normals[triangle.mFirstEdgeNormalIndex].y;
        triangleNormals[1].z = normals[triangle.mFirstEdgeNormalIndex].z;
        firstEdgeDistance = Vec3DotUnrounded(&relativePosition, &triangleNormals[1]);
        if (firstEdgeDistance >= radius) {
            continue;
        }
        triangleNormals[2].x = normals[triangle.mSecondEdgeNormalIndex].x;
        triangleNormals[2].y = normals[triangle.mSecondEdgeNormalIndex].y;
        triangleNormals[2].z = normals[triangle.mSecondEdgeNormalIndex].z;
        secondEdgeDistance = Vec3DotUnrounded(&relativePosition, &triangleNormals[2]);
        if (secondEdgeDistance >= radius) {
            continue;
        }
        triangleNormals[0].x = normals[triangle.mPlaneNormalIndex].x;
        triangleNormals[0].y = normals[triangle.mPlaneNormalIndex].y;
        triangleNormals[0].z = normals[triangle.mPlaneNormalIndex].z;
        planeDistance = Vec3DotUnrounded(&relativePosition, &triangleNormals[0]);
        penetration = radius - planeDistance;
        if (penetration >= 0 && penetration <= 0x1e000) {
            triangleFlags = triangle.mHitValue;
            if (triangleFlags & 0x2010) {
                if ((queryFlags & 4) && (triangleFlags & 0x2000)) {
                    continue;
                }
                if ((queryFlags & 1) && (triangleFlags & 0x10)) {
                    continue;
                }
            }
            if ((queryFlags & 0x10) && (triangleFlags & 0xa000)) {
                continue;
            }
            offset.y = -MUL_FIXED12_NO_ROUND(planeDistance, triangleNormals[0].y);
            offset.x = -MUL_FIXED12_NO_ROUND(planeDistance, triangleNormals[0].x);
            offset.z = -MUL_FIXED12_NO_ROUND(planeDistance, triangleNormals[0].z);
            value = 1;
            if (firstEdgeDistance > secondEdgeDistance) {
                if (firstEdgeDistance > thirdEdgeDistance) {
                    goto la;
                } else {
                    goto lc;
                }
            } else {
                if (secondEdgeDistance > thirdEdgeDistance) {
                    goto lb;
                } else {
                    goto lc;
                }
            }
        la:
            if (firstEdgeDistance <= 0) {
                goto lm;
            }
            if (planeDistance < 0) {
                if (prevPosition == NULL) {
                    continue;
                }
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &relativeVector);
                if (Vec3DotUnrounded(&relativeVector, &triangleNormals[0]) < 0) {
                    continue;
                }
                if (Vec3DotUnrounded(&relativeVector, &triangleNormals[1]) > 0) {
                    continue;
                }
            }
            if (secondEdgeDistance > thirdEdgeDistance) {
                dot = Vec3DotUnrounded(&triangleNormals[1], &triangleNormals[2]);
                if (MUL_FIXED12_NO_ROUND(dot, firstEdgeDistance) > secondEdgeDistance) {
                    goto ld;
                } else {
                    goto lg;
                }
            } else {
                dot = Vec3DotUnrounded(&triangleNormals[1], &triangleNormals[3]);
                if (MUL_FIXED12_NO_ROUND(dot, firstEdgeDistance) > thirdEdgeDistance) {
                    goto ld;
                } else {
                    goto li;
                }
            }
        lb:
            if (secondEdgeDistance <= 0) {
                goto lm;
            }
            if (planeDistance < 0) {
                if (prevPosition == NULL) {
                    continue;
                }
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &relativeVector);
                if (Vec3DotUnrounded(&relativeVector, &triangleNormals[0]) < 0) {
                    continue;
                }
                if (Vec3DotUnrounded(&relativeVector, &triangleNormals[2]) > 0) {
                    continue;
                }
            }
            if (thirdEdgeDistance > firstEdgeDistance) {
                dot = Vec3DotUnrounded(&triangleNormals[2], &triangleNormals[3]);
                if (MUL_FIXED12_NO_ROUND(dot, secondEdgeDistance) > thirdEdgeDistance) {
                    goto le;
                } else {
                    goto lh;
                }
            } else {
                dot = Vec3DotUnrounded(&triangleNormals[2], &triangleNormals[1]);
                if (MUL_FIXED12_NO_ROUND(dot, secondEdgeDistance) > firstEdgeDistance) {
                    goto le;
                } else {
                    goto lg;
                }
            }
        lc:
            if (thirdEdgeDistance <= 0) {
                goto lm;
            }
            if (planeDistance < 0) {
                if (prevPosition == NULL) {
                    continue;
                }
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &relativeVector);
                if (Vec3DotUnrounded(&relativeVector, &triangleNormals[0]) < 0) {
                    continue;
                }
                if (Vec3DotUnrounded(&relativeVector, &triangleNormals[3]) > triangle.mThirdEdgeOffset) {
                    continue;
                }
            }
            if (firstEdgeDistance > secondEdgeDistance) {
                dot = Vec3DotUnrounded(&triangleNormals[3], &triangleNormals[1]);
                if (MUL_FIXED12_NO_ROUND(dot, thirdEdgeDistance) > firstEdgeDistance) {
                    goto lf;
                } else {
                    goto li;
                }
            } else {
                dot = Vec3DotUnrounded(&triangleNormals[3], &triangleNormals[2]);
                if (MUL_FIXED12_NO_ROUND(dot, thirdEdgeDistance) > secondEdgeDistance) {
                    goto lf;
                } else {
                    goto lh;
                }
            }
        ld:
            remainingSquared = radiusSquared - (s64) firstEdgeDistance * firstEdgeDistance;
            if (triangleNormals[1].y > 0x424 || triangleNormals[1].y < -0x424) {
                value = 0;
            }
            if (lowestOffset != NULL) {
                VEC_MultAdd(-firstEdgeDistance, &triangleNormals[1], &offset, &offset);
            }
            goto lk;
        le:
            remainingSquared = radiusSquared - (s64) secondEdgeDistance * secondEdgeDistance;
            if (triangleNormals[2].y > 0x424 || triangleNormals[2].y < -0x424) {
                value = 0;
            }
            if (lowestOffset != NULL) {
                VEC_MultAdd(-secondEdgeDistance, &triangleNormals[2], &offset, &offset);
            }
            goto lk;
        lf:
            remainingSquared = radiusSquared - (s64) thirdEdgeDistance * thirdEdgeDistance;
            if (triangleNormals[3].y > 0x424 || triangleNormals[3].y < -0x424) {
                value = 0;
            }
            if (lowestOffset != NULL) {
                VEC_MultAdd(-thirdEdgeDistance, &triangleNormals[3], &offset, &offset);
            }
            goto lk;
        lg:
            ComputeVec3FromDotProducts(dot, secondEdgeDistance, firstEdgeDistance, &relativePosition,
                                       &triangleNormals[1], &triangleNormals[2], &remainingSquared);
            goto lj;
        lh:
            ComputeVec3FromDotProducts(dot, thirdEdgeDistance, secondEdgeDistance, &relativePosition,
                                       &triangleNormals[2], &triangleNormals[3], &remainingSquared);
            goto lj;
        li:
            ComputeVec3FromDotProducts(dot, firstEdgeDistance, thirdEdgeDistance, &relativePosition,
                                       &triangleNormals[3], &triangleNormals[1], &remainingSquared);
        lj:
            remainingSquared = radiusSquared - remainingSquared;
            if (remainingSquared <= 0) {
                continue;
            }
            if (lowestOffset != NULL) {
                VEC_Subtract(&offset, &relativePosition, &offset);
            }
            value = 0;
        lk:
            sqrtInput = remainingSquared;
            reg_CP_SQRTCNT = 1;
            reg_CP_SQRT_PARAM = sqrtInput;
            while (reg_CP_SQRTCNT & REG_CP_SQRTCNT_BUSY_MASK) {
            }
            penetration = reg_CP_SQRT_RESULT - planeDistance;
            if (penetration < 0) {
                continue;
            }
            goto ln;
        lm:
            if (planeDistance < 0 && prevPosition != NULL) {
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &relativeVector);
                if (Vec3DotUnrounded(&relativeVector, &triangleNormals[0]) < 0) {
                    if (queryFlags & 0x20) {
                        continue;
                    }
                    if (Vec3DotUnrounded(&relativeVector, &triangleNormals[1]) > 0) {
                        continue;
                    }
                    if (Vec3DotUnrounded(&relativeVector, &triangleNormals[2]) > 0) {
                        continue;
                    }
                    if (Vec3DotUnrounded(&relativeVector, &triangleNormals[3]) > triangle.mThirdEdgeOffset) {
                        continue;
                    }
                }
            }
            value = 0;
        ln:
            triangleHitBits = 1 << ((triangleFlags & 0x1f00) >> 8);
            triangleHitBits |= 1 << (((triangleFlags & 0xc) >> 2) + 0x1a);
            triangleHitBits |= (triangleFlags & 2) << 0x17;
            if (prevPosition != NULL) {
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &relativeVector);
                dot = Vec3DotUnrounded(&relativeVector, &triangleNormals[0]);
                if (dot < 0) {
                    if (value && (triangleHitBits & 0x214300) && vector != 0) {
                        relativePosition.x = ((s64) penetration * triangleNormals[0].x) >> 2;
                        relativePosition.z = ((s64) penetration * triangleNormals[0].z) >> 2;
                        if (relativePosition.x > maxXZOffset.x) {
                            maxXZOffset.x = relativePosition.x;
                        } else if (relativePosition.x < minXZOffset.x) {
                            minXZOffset.x = relativePosition.x;
                        }
                        if (relativePosition.z > maxXZOffset.z) {
                            maxXZOffset.z = relativePosition.z;
                        } else if (relativePosition.z < minXZOffset.z) {
                            minXZOffset.z = relativePosition.z;
                        }
                    }
                    if (queryFlags & 0x3b) {
                        continue;
                    }
                    if (dot < -0xa000) {
                        continue;
                    }
                }
                VEC_Subtract(&positionCopy, &prevPositionCopy, &relativeVector);
                if (Vec3DotUnrounded(&relativeVector, &triangleNormals[0]) > 0x333) {
                    if (value && (triangleHitBits & 0x214300) && vector != 0) {
                        relativePosition.x = ((s64) penetration * triangleNormals[0].x) >> 2;
                        relativePosition.z = ((s64) penetration * triangleNormals[0].z) >> 2;
                        if (relativePosition.x > maxXZOffset.x) {
                            maxXZOffset.x = relativePosition.x;
                        } else if (relativePosition.x < minXZOffset.x) {
                            minXZOffset.x = relativePosition.x;
                        }
                        if (relativePosition.z > maxXZOffset.z) {
                            maxXZOffset.z = relativePosition.z;
                        } else if (relativePosition.z < minXZOffset.z) {
                            minXZOffset.z = relativePosition.z;
                        }
                    }
                    continue;
                }
            }
            if ((queryFlags & 2) && (triangleHitBits & 0x200)) {
                continue;
            }
            if (lowestOffset != NULL && offset.y < lowestOffsetValue.y) {
                lowestOffsetValue = offset;
            }
            if (wantsHitRecords) {
                offset.x = ((s64) penetration * triangleNormals[0].x) >> 2;
                offset.y = ((s64) penetration * triangleNormals[0].y) >> 2;
                offset.z = ((s64) penetration * triangleNormals[0].z) >> 2;
                if (triangleHitBits & 0x1e34ef) {
                    if (offset.x > firstHitRecord.mMaxOffset.x) {
                        firstHitRecord.mMaxOffset.x = offset.x;
                    } else if (offset.x < firstHitRecord.mMinOffset.x) {
                        firstHitRecord.mMinOffset.x = offset.x;
                    }
                    if (offset.y > firstHitRecord.mMaxOffset.y) {
                        firstHitRecord.mMaxOffset.y = offset.y;
                    } else if (offset.y < firstHitRecord.mMinOffset.y) {
                        firstHitRecord.mMinOffset.y = offset.y;
                    }
                    if (offset.z > firstHitRecord.mMaxOffset.z) {
                        firstHitRecord.mMaxOffset.z = offset.z;
                    } else if (offset.z < firstHitRecord.mMinOffset.z) {
                        firstHitRecord.mMinOffset.z = offset.z;
                    }
                    if (normal != NULL && penetration >= firstHitRecord.mDeepestDepth) {
                        firstHitRecord.mDeepestDepth = penetration;
                        firstHitRecord.mDeepestNormal.x = triangleNormals[0].x;
                        firstHitRecord.mDeepestNormal.y = triangleNormals[0].y;
                        firstHitRecord.mDeepestNormal.z = triangleNormals[0].z;
                    }
                } else if (triangleHitBits & 0x214300) {
                    if (triangleHitBits & 0x10000) {
                        triangleHitBits |= gSphereHitTriangleBitsFlag;
                        if (offset.x > extraMaxOffset.x) {
                            extraMaxOffset.x = offset.x;
                        } else if (offset.x < extraMinOffset.x) {
                            extraMinOffset.x = offset.x;
                        }
                        if (offset.y > extraMaxOffset.y) {
                            extraMaxOffset.y = offset.y;
                        } else if (offset.y < extraMinOffset.y) {
                            extraMinOffset.y = offset.y;
                        }
                        if (offset.z > extraMaxOffset.z) {
                            extraMaxOffset.z = offset.z;
                        } else if (offset.z < extraMinOffset.z) {
                            extraMinOffset.z = offset.z;
                        }
                    } else {
                        if (offset.x > secondHitRecord.mMaxOffset.x) {
                            secondHitRecord.mMaxOffset.x = offset.x;
                        } else if (offset.x < secondHitRecord.mMinOffset.x) {
                            secondHitRecord.mMinOffset.x = offset.x;
                        }
                        if (offset.y > secondHitRecord.mMaxOffset.y) {
                            secondHitRecord.mMaxOffset.y = offset.y;
                        } else if (offset.y < secondHitRecord.mMinOffset.y) {
                            secondHitRecord.mMinOffset.y = offset.y;
                        }
                        if (offset.z > secondHitRecord.mMaxOffset.z) {
                            secondHitRecord.mMaxOffset.z = offset.z;
                        } else if (offset.z < secondHitRecord.mMinOffset.z) {
                            secondHitRecord.mMinOffset.z = offset.z;
                        }
                    }
                    if (secondNormal != NULL && penetration >= secondHitRecord.mDeepestDepth) {
                        secondHitRecord.mDeepestDepth = penetration;
                        secondHitRecord.mDeepestNormal.x = triangleNormals[0].x;
                        secondHitRecord.mDeepestNormal.y = triangleNormals[0].y;
                        secondHitRecord.mDeepestNormal.z = triangleNormals[0].z;
                    }
                    if (vector != 0) {
                        if (((s32 *) &offset)[0] > maxXZOffset.x) {
                            maxXZOffset.x = ((s32 *) &offset)[0];
                        } else if (((s32 *) &offset)[0] < minXZOffset.x) {
                            minXZOffset.x = ((s32 *) &offset)[0];
                        }
                        if (((s32 *) &offset)[2] > maxXZOffset.z) {
                            maxXZOffset.z = ((s32 *) &offset)[2];
                        } else if (((s32 *) &offset)[2] < minXZOffset.z) {
                            minXZOffset.z = ((s32 *) &offset)[2];
                        }
                    }
                }
            }
            hitBits |= gSphereHitBitsFlag;
            hitBits |= triangleHitBits;
            if (gCollisionHitCount == 16) {
                gCollisionHitCount--;
            }
            gCollisionHitBits[gCollisionHitCount] = triangleHitBits;
            anyHit = TRUE;
            gCollisionHitValues[gCollisionHitCount] = triangleFlags;
            gCollisionHitCount++;
        }
    }
    if (pointMotion != NULL) {
        pointMotion->x = 0;
        pointMotion->y = 0;
        pointMotion->z = 0;
    }
    if (angleChange != NULL) {
        *angleChange = 0;
    }
    if (hitObjects != NULL) {
        *(void ***) hitObjects = gSphereHitObjects;
        gSphereHitObjects[1] = NULL;
        gSphereHitObjects[0] = NULL;
    }
    if (gSearchCollisionSlots != 0 && collisionSlotIndex != -2) {
        hitObjectCount = 0;
        if (collisionSlotIndex == -1) {
            FindCollisionSlotsAroundPos(position, radius, 0x1000);
        } else {
            FindCollisionSlotsOverlappingSlot(collisionSlotIndex, 0x1000);
        }
        for (foundObjectIndex = 0; foundObjectIndex < gFoundCollisionSlotCount; foundObjectIndex++) {
            foundObject = gFoundCollisionSlotObjects[foundObjectIndex];
            if (ComputeSphereHitOnCollisionData(foundObject, position, radius, queryFlags, &firstHitRecord,
                                                &secondHitRecord, lowestOffset != NULL ? &lowestOffsetValue : 0,
                                                &hitBitIndex, pointMotion, angleChange)) {
                hitBits |= gSphereHitObjectBitsFlag;
                BIT_SET(hitBits, hitBitIndex);
                if (gCollisionHitCount == 16) {
                    gCollisionHitCount--;
                }
                hitObjectBit = 1 << hitBitIndex;
                gCollisionHitBits[gCollisionHitCount] = hitObjectBit;
                gCollisionHitValues[gCollisionHitCount] = hitBitIndex << 8;
                gCollisionHitCount++;
                if (hitObjects != NULL) {
                    if (hitObjectBit & 0x1e34ef) {
                        gSphereHitObjects[hitObjectCount++] = gSphereHitObjects[0];
                        gSphereHitObjects[0] = foundObject;
                    } else {
                        gSphereHitObjects[hitObjectCount++] = foundObject;
                    }
                    gSphereHitObjects[hitObjectCount] = NULL;
                    if (hitObjectCount >= 15) {
                        hitObjectCount--;
                    }
                }
                anyHit = TRUE;
            }
        }
    }
    if (anyHit == FALSE) {
        return anyHit;
    }
    if (normal != NULL) {
        *normal = firstHitRecord.mDeepestNormal;
    }
    if (secondNormal != NULL) {
        *secondNormal = secondHitRecord.mDeepestNormal;
    }
    if (lowestOffset != NULL) {
        *lowestOffset = lowestOffsetValue;
    }
    if (pushOut != NULL) {
        offset.y = firstHitRecord.mMaxOffset.y > secondHitRecord.mMaxOffset.y ? firstHitRecord.mMaxOffset.y
                                                                              : secondHitRecord.mMaxOffset.y;
        offset.y += firstHitRecord.mMinOffset.y < secondHitRecord.mMinOffset.y ? firstHitRecord.mMinOffset.y
                                                                               : secondHitRecord.mMinOffset.y;
        if (hitBits & 0x10000) {
            if (lowestOffset != NULL && (hitBits & 0x1e34ef) && !(hitBits & 0x400) && !(hitBits & 0x800)) {
                lowestOffsetValue.x >>= 4;
                lowestOffsetValue.y >>= 4;
                lowestOffsetValue.z >>= 4;
                if (lowestOffsetValue.y * lowestOffsetValue.y <
                    lowestOffsetValue.x * lowestOffsetValue.x + lowestOffsetValue.z * lowestOffsetValue.z) {
                    offset.y = 0;
                    hitBits = (hitBits & 0xffe1cb10) | gSphereHitBitsMaskedFlag;
                    if (normal != NULL) {
                        normal->x = 0;
                        normal->y = 0;
                        normal->z = 0;
                    }
                } else {
                    hitBits &= ~0x10000;
                    goto lo;
                }
            } else {
                hitBits = (hitBits & ~0x10000) | gSphereHitBitsMaskedFlag;
            }
            if (extraMaxOffset.y > offset.y) {
                offset.y = extraMaxOffset.y;
            }
            if (extraMaxOffset.x > secondHitRecord.mMaxOffset.x) {
                secondHitRecord.mMaxOffset.x = extraMaxOffset.x;
            }
            if (extraMinOffset.x < secondHitRecord.mMinOffset.x) {
                secondHitRecord.mMinOffset.x = extraMinOffset.x;
            }
            if (extraMaxOffset.z > secondHitRecord.mMaxOffset.z) {
                secondHitRecord.mMaxOffset.z = extraMaxOffset.z;
            }
            if (extraMinOffset.z < secondHitRecord.mMinOffset.z) {
                secondHitRecord.mMinOffset.z = extraMinOffset.z;
            }
        }
    lo:
        offset.x = firstHitRecord.mMaxOffset.x > secondHitRecord.mMaxOffset.x ? firstHitRecord.mMaxOffset.x
                                                                              : secondHitRecord.mMaxOffset.x;
        offset.x += firstHitRecord.mMinOffset.x < secondHitRecord.mMinOffset.x ? firstHitRecord.mMinOffset.x
                                                                               : secondHitRecord.mMinOffset.x;
        offset.z = firstHitRecord.mMaxOffset.z > secondHitRecord.mMaxOffset.z ? firstHitRecord.mMaxOffset.z
                                                                              : secondHitRecord.mMaxOffset.z;
        offset.z += firstHitRecord.mMinOffset.z < secondHitRecord.mMinOffset.z ? firstHitRecord.mMinOffset.z
                                                                               : secondHitRecord.mMinOffset.z;
        pushOut->x = offset.x >> 10;
        pushOut->y = offset.y >> 10;
        pushOut->z = offset.z >> 10;
        if ((hitBits & 0x214300) && vector != 0 && pointMotion != NULL && secondNormal != NULL) {
            maxXZOffset.x = maxXZOffset.x + minXZOffset.x;
            maxXZOffset.z = maxXZOffset.z + minXZOffset.z;
            remainingSquared = (s64) maxXZOffset.x * secondNormal->z - (s64) maxXZOffset.z * secondNormal->x;
            if (remainingSquared < -16 || remainingSquared > 16) {
                minXZOffset.x = MUL_FIXED12_NO_ROUND(maxXZOffset.x, (vector)->x);
                minXZOffset.z = MUL_FIXED12_NO_ROUND(maxXZOffset.z, (vector)->z);
                maxXZOffset.x = maxXZOffset.x - MUL_FIXED12_NO_ROUND(minXZOffset.x, (vector)->x);
                maxXZOffset.z = maxXZOffset.z - MUL_FIXED12_NO_ROUND(minXZOffset.z, (vector)->z);
                VEC_Add(&firstHitRecord.mMaxOffset, &firstHitRecord.mMinOffset, &relativePosition);
                if (Vec3DotUnrounded(&maxXZOffset, &relativePosition) >= 0) {
                    if (LENGTH_SQUARED(maxXZOffset) >= 16) {
                        Vec3NormalizeAndGetLengthUnchecked(&maxXZOffset, &maxXZOffset);
                    }
                    maxXZOffset.x = MUL_FIXED12_NO_ROUND(maxXZOffset.x, radius >> 5);
                    maxXZOffset.y = MUL_FIXED12_NO_ROUND(maxXZOffset.y, radius >> 5);
                    maxXZOffset.z = MUL_FIXED12_NO_ROUND(maxXZOffset.z, radius >> 5);
                    pointMotion->x += maxXZOffset.x;
                    pointMotion->z += maxXZOffset.z;
                }
            }
        }
    }
    if (collisionBits != NULL) {
        *collisionBits = hitBits;
    }
    return anyHit;
}
