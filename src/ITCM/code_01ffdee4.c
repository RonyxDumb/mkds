#include "ITCM/code_01ffdee4.h"
#include "ITCM/code_01ffcf7c.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "ITCM/code_01fff000.h"

#include "Main/Unknown/code_020e0680.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/code_01fff434.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "registers.h"

BOOL CollideSphereWithCourse(Vec3 *position, Vec3 *prevPosition, Vec3 *c, int radius, u16 queryFlags,
                             short collisionSlotIndex, Vec3 *pushOut, Vec3 *normal, Vec3 *secondNormal,
                             u32 *collisionBits, Vec3 *lowestOffset, Vec3 *pointMotion, u16 *angleChange,
                             u32 *hitObjects) {
    u16 *triangleIndexCursor;
    CourseTriangle *triangles;
    s64 radiusSquared;
    Vec3 *points;
    Vec3s16 *normals;
    u16 hw;
    s64 qq;
    s64 tq;
    CourseTriangle triangle;
    Vec3 positionCopy;
    Vec3 prevPositionCopy;
    Vec3 ua;
    Vec3 ub;
    BOOL anyHit = FALSE;
    Vec3 offset = {0, 0, 0};
    BOOL wantsHitRecords = pushOut != NULL || normal != NULL || secondNormal != NULL;
    u32 hitBits = 0;
    CollisionHitRecord firstHitRecord = data_0216b8c4;
    CollisionHitRecord secondHitRecord = data_0216b8ec;
    Vec3 ca = {0, 0, 0};
    Vec3 cb = {0, 0, 0};
    Vec3 cc = {0, 0, 0};
    Vec3 cd = {0, 0, 0};
    Vec3 trianglePoint;
    Vec3 triangleNormals[4];
    Vec3 lowestOffsetValue;
    CourseCollision *courseCollision;
    u32 cellX;
    u32 cellY;
    u32 cellZ;
    u32 shift;
    u8 *treeCursor;
    s32 v;
    u16 triangleIndex;
    s32 penetration;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;
    u16 triangleFlags;
    s32 dot;
    u32 triangleHitBits;
    s32 i;
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
    cellX = (positionCopy.x - courseCollision->mOriginX) >> 12;
    radiusSquared = (s64) radius * radius;
    if (cellX & courseCollision->mOutsideMaskX) {
        return FALSE;
    }
    cellY = (positionCopy.y - courseCollision->mOriginY) >> 12;
    if (cellY & courseCollision->mOutsideMaskY) {
        return FALSE;
    }
    cellZ = (positionCopy.z - courseCollision->mOriginZ) >> 12;
    if (cellZ & courseCollision->mOutsideMaskZ) {
        return FALSE;
    }
    shift = courseCollision->mTopShift;
    v = ((cellZ >> shift) << courseCollision->mZIndexShift) | ((cellY >> shift) << courseCollision->mYIndexShift) |
        (cellX >> shift);
    treeCursor = courseCollision->mTree;
    v = ((s32 *) treeCursor)[v];
    while (v >= 0) {
        treeCursor += v;
        shift--;
        v = ((s32 *)
                 treeCursor)[((cellX >> shift) & 1) | ((((cellZ >> shift) & 1) << 2) | (((cellY >> shift) & 1) << 1))];
    }
    treeCursor += v & 0x7fffffff;
    triangles = courseCollision->mTriangles;
    points = courseCollision->mPoints;
    normals = courseCollision->mNormals;
    triangleIndexCursor = (u16 *) treeCursor;
    while ((triangleIndex = *++triangleIndexCursor) != 0) {
        triangle = triangles[triangleIndex];
        trianglePoint = points[triangle.mPointIndex];
        VEC_Subtract(&positionCopy, &trianglePoint, &ua);
        triangleNormals[3].x = normals[triangle.mThirdEdgeNormalIndex].x;
        triangleNormals[3].y = normals[triangle.mThirdEdgeNormalIndex].y;
        triangleNormals[3].z = normals[triangle.mThirdEdgeNormalIndex].z;
        dot = Vec3DotUnrounded(&ua, &triangleNormals[3]);
        if (dot < -radius) {
            continue;
        }
        d3 = dot - triangle.mThirdEdgeOffset;
        if (d3 >= radius) {
            continue;
        }
        triangleNormals[1].x = normals[triangle.mFirstEdgeNormalIndex].x;
        triangleNormals[1].y = normals[triangle.mFirstEdgeNormalIndex].y;
        triangleNormals[1].z = normals[triangle.mFirstEdgeNormalIndex].z;
        d1 = Vec3DotUnrounded(&ua, &triangleNormals[1]);
        if (d1 >= radius) {
            continue;
        }
        triangleNormals[2].x = normals[triangle.mSecondEdgeNormalIndex].x;
        triangleNormals[2].y = normals[triangle.mSecondEdgeNormalIndex].y;
        triangleNormals[2].z = normals[triangle.mSecondEdgeNormalIndex].z;
        d2 = Vec3DotUnrounded(&ua, &triangleNormals[2]);
        if (d2 >= radius) {
            continue;
        }
        triangleNormals[0].x = normals[triangle.mPlaneNormalIndex].x;
        triangleNormals[0].y = normals[triangle.mPlaneNormalIndex].y;
        triangleNormals[0].z = normals[triangle.mPlaneNormalIndex].z;
        d0 = Vec3DotUnrounded(&ua, &triangleNormals[0]);
        penetration = radius - d0;
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
            offset.y = -MUL_FIXED12_NO_ROUND(d0, triangleNormals[0].y);
            offset.x = -MUL_FIXED12_NO_ROUND(d0, triangleNormals[0].x);
            offset.z = -MUL_FIXED12_NO_ROUND(d0, triangleNormals[0].z);
            v = 1;
            if (d1 > d2) {
                if (d1 > d3) {
                    goto la;
                } else {
                    goto lc;
                }
            } else {
                if (d2 > d3) {
                    goto lb;
                } else {
                    goto lc;
                }
            }
        la:
            if (d1 <= 0) {
                goto lm;
            }
            if (d0 < 0) {
                if (prevPosition == NULL) {
                    continue;
                }
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &ub);
                if (Vec3DotUnrounded(&ub, &triangleNormals[0]) < 0) {
                    continue;
                }
                if (Vec3DotUnrounded(&ub, &triangleNormals[1]) > 0) {
                    continue;
                }
            }
            if (d2 > d3) {
                dot = Vec3DotUnrounded(&triangleNormals[1], &triangleNormals[2]);
                if (MUL_FIXED12_NO_ROUND(dot, d1) > d2) {
                    goto ld;
                } else {
                    goto lg;
                }
            } else {
                dot = Vec3DotUnrounded(&triangleNormals[1], &triangleNormals[3]);
                if (MUL_FIXED12_NO_ROUND(dot, d1) > d3) {
                    goto ld;
                } else {
                    goto li;
                }
            }
        lb:
            if (d2 <= 0) {
                goto lm;
            }
            if (d0 < 0) {
                if (prevPosition == NULL) {
                    continue;
                }
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &ub);
                if (Vec3DotUnrounded(&ub, &triangleNormals[0]) < 0) {
                    continue;
                }
                if (Vec3DotUnrounded(&ub, &triangleNormals[2]) > 0) {
                    continue;
                }
            }
            if (d3 > d1) {
                dot = Vec3DotUnrounded(&triangleNormals[2], &triangleNormals[3]);
                if (MUL_FIXED12_NO_ROUND(dot, d2) > d3) {
                    goto le;
                } else {
                    goto lh;
                }
            } else {
                dot = Vec3DotUnrounded(&triangleNormals[2], &triangleNormals[1]);
                if (MUL_FIXED12_NO_ROUND(dot, d2) > d1) {
                    goto le;
                } else {
                    goto lg;
                }
            }
        lc:
            if (d3 <= 0) {
                goto lm;
            }
            if (d0 < 0) {
                if (prevPosition == NULL) {
                    continue;
                }
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &ub);
                if (Vec3DotUnrounded(&ub, &triangleNormals[0]) < 0) {
                    continue;
                }
                if (Vec3DotUnrounded(&ub, &triangleNormals[3]) > triangle.mThirdEdgeOffset) {
                    continue;
                }
            }
            if (d1 > d2) {
                dot = Vec3DotUnrounded(&triangleNormals[3], &triangleNormals[1]);
                if (MUL_FIXED12_NO_ROUND(dot, d3) > d1) {
                    goto lf;
                } else {
                    goto li;
                }
            } else {
                dot = Vec3DotUnrounded(&triangleNormals[3], &triangleNormals[2]);
                if (MUL_FIXED12_NO_ROUND(dot, d3) > d2) {
                    goto lf;
                } else {
                    goto lh;
                }
            }
        ld:
            qq = radiusSquared - (s64) d1 * d1;
            if (triangleNormals[1].y > 0x424 || triangleNormals[1].y < -0x424) {
                v = 0;
            }
            if (lowestOffset != NULL) {
                VEC_MultAdd(-d1, &triangleNormals[1], &offset, &offset);
            }
            goto lk;
        le:
            qq = radiusSquared - (s64) d2 * d2;
            if (triangleNormals[2].y > 0x424 || triangleNormals[2].y < -0x424) {
                v = 0;
            }
            if (lowestOffset != NULL) {
                VEC_MultAdd(-d2, &triangleNormals[2], &offset, &offset);
            }
            goto lk;
        lf:
            qq = radiusSquared - (s64) d3 * d3;
            if (triangleNormals[3].y > 0x424 || triangleNormals[3].y < -0x424) {
                v = 0;
            }
            if (lowestOffset != NULL) {
                VEC_MultAdd(-d3, &triangleNormals[3], &offset, &offset);
            }
            goto lk;
        lg:
            func_01fff434(dot, d2, d1, &ua, &triangleNormals[1], &triangleNormals[2], &qq);
            goto lj;
        lh:
            func_01fff434(dot, d3, d2, &ua, &triangleNormals[2], &triangleNormals[3], &qq);
            goto lj;
        li:
            func_01fff434(dot, d1, d3, &ua, &triangleNormals[3], &triangleNormals[1], &qq);
        lj:
            qq = radiusSquared - qq;
            if (qq <= 0) {
                continue;
            }
            if (lowestOffset != NULL) {
                VEC_Subtract(&offset, &ua, &offset);
            }
            v = 0;
        lk:
            tq = qq;
            reg_CP_SQRTCNT = 1;
            reg_CP_SQRT_PARAM = tq;
            while (reg_CP_SQRTCNT & 0x8000) {
            }
            penetration = reg_CP_SQRT_RESULT - d0;
            if (penetration < 0) {
                continue;
            }
            goto ln;
        lm:
            if (d0 < 0 && prevPosition != NULL) {
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &ub);
                if (Vec3DotUnrounded(&ub, &triangleNormals[0]) < 0) {
                    if (queryFlags & 0x20) {
                        continue;
                    }
                    if (Vec3DotUnrounded(&ub, &triangleNormals[1]) > 0) {
                        continue;
                    }
                    if (Vec3DotUnrounded(&ub, &triangleNormals[2]) > 0) {
                        continue;
                    }
                    if (Vec3DotUnrounded(&ub, &triangleNormals[3]) > triangle.mThirdEdgeOffset) {
                        continue;
                    }
                }
            }
            v = 0;
        ln:
            triangleHitBits = 1 << ((triangleFlags & 0x1f00) >> 8);
            triangleHitBits |= 1 << (((triangleFlags & 0xc) >> 2) + 0x1a);
            triangleHitBits |= (triangleFlags & 2) << 0x17;
            if (prevPosition != NULL) {
                VEC_Subtract(&prevPositionCopy, &trianglePoint, &ub);
                dot = Vec3DotUnrounded(&ub, &triangleNormals[0]);
                if (dot < 0) {
                    if (v && (triangleHitBits & 0x214300) && c != 0) {
                        ua.x = ((s64) penetration * triangleNormals[0].x) >> 2;
                        ua.z = ((s64) penetration * triangleNormals[0].z) >> 2;
                        if (ua.x > cc.x) {
                            cc.x = ua.x;
                        } else if (ua.x < cd.x) {
                            cd.x = ua.x;
                        }
                        if (ua.z > cc.z) {
                            cc.z = ua.z;
                        } else if (ua.z < cd.z) {
                            cd.z = ua.z;
                        }
                    }
                    if (queryFlags & 0x3b) {
                        continue;
                    }
                    if (dot < -0xa000) {
                        continue;
                    }
                }
                VEC_Subtract(&positionCopy, &prevPositionCopy, &ub);
                if (Vec3DotUnrounded(&ub, &triangleNormals[0]) > 0x333) {
                    if (v && (triangleHitBits & 0x214300) && c != 0) {
                        ua.x = ((s64) penetration * triangleNormals[0].x) >> 2;
                        ua.z = ((s64) penetration * triangleNormals[0].z) >> 2;
                        if (ua.x > cc.x) {
                            cc.x = ua.x;
                        } else if (ua.x < cd.x) {
                            cd.x = ua.x;
                        }
                        if (ua.z > cc.z) {
                            cc.z = ua.z;
                        } else if (ua.z < cd.z) {
                            cd.z = ua.z;
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
                        triangleHitBits |= data_02156904;
                        if (offset.x > ca.x) {
                            ca.x = offset.x;
                        } else if (offset.x < cb.x) {
                            cb.x = offset.x;
                        }
                        if (offset.y > ca.y) {
                            ca.y = offset.y;
                        } else if (offset.y < cb.y) {
                            cb.y = offset.y;
                        }
                        if (offset.z > ca.z) {
                            ca.z = offset.z;
                        } else if (offset.z < cb.z) {
                            cb.z = offset.z;
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
                    if (c != 0) {
                        if (((s32 *) &offset)[0] > cc.x) {
                            cc.x = ((s32 *) &offset)[0];
                        } else if (((s32 *) &offset)[0] < cd.x) {
                            cd.x = ((s32 *) &offset)[0];
                        }
                        if (((s32 *) &offset)[2] > cc.z) {
                            cc.z = ((s32 *) &offset)[2];
                        } else if (((s32 *) &offset)[2] < cd.z) {
                            cd.z = ((s32 *) &offset)[2];
                        }
                    }
                }
            }
            hitBits |= data_02156908;
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
        *(void ***) hitObjects = data_0217b5d0;
        data_0217b5d0[1] = NULL;
        data_0217b5d0[0] = NULL;
    }
    if (data_0217b610 != 0 && collisionSlotIndex != -2) {
        hitObjectCount = 0;
        if (collisionSlotIndex == -1) {
            FindCollisionSlotsAroundPos(position, radius, 0x1000);
        } else {
            FindCollisionSlotsOverlappingSlot(collisionSlotIndex, 0x1000);
        }
        for (i = 0; i < gFoundCollisionSlotCount; i++) {
            foundObject = gFoundCollisionSlotObjects[i];
            if (ComputeSphereHitOnCollisionData(foundObject, position, radius, queryFlags, &firstHitRecord,
                                                &secondHitRecord, lowestOffset != NULL ? &lowestOffsetValue : 0, &hw,
                                                pointMotion, angleChange)) {
                hitBits |= data_0215690c;
                hitBits |= 1 << hw;
                if (gCollisionHitCount == 16) {
                    gCollisionHitCount--;
                }
                hitObjectBit = 1 << hw;
                gCollisionHitBits[gCollisionHitCount] = hitObjectBit;
                gCollisionHitValues[gCollisionHitCount] = hw << 8;
                gCollisionHitCount++;
                if (hitObjects != NULL) {
                    if (hitObjectBit & 0x1e34ef) {
                        data_0217b5d0[hitObjectCount++] = data_0217b5d0[0];
                        data_0217b5d0[0] = foundObject;
                    } else {
                        data_0217b5d0[hitObjectCount++] = foundObject;
                    }
                    data_0217b5d0[hitObjectCount] = NULL;
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
                    hitBits = (hitBits & 0xffe1cb10) | data_02156910;
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
                hitBits = (hitBits & ~0x10000) | data_02156910;
            }
            if (ca.y > offset.y) {
                offset.y = ca.y;
            }
            if (ca.x > secondHitRecord.mMaxOffset.x) {
                secondHitRecord.mMaxOffset.x = ca.x;
            }
            if (cb.x < secondHitRecord.mMinOffset.x) {
                secondHitRecord.mMinOffset.x = cb.x;
            }
            if (ca.z > secondHitRecord.mMaxOffset.z) {
                secondHitRecord.mMaxOffset.z = ca.z;
            }
            if (cb.z < secondHitRecord.mMinOffset.z) {
                secondHitRecord.mMinOffset.z = cb.z;
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
        if ((hitBits & 0x214300) && c != 0 && pointMotion != NULL && secondNormal != NULL) {
            cc.x = cc.x + cd.x;
            cc.z = cc.z + cd.z;
            qq = (s64) cc.x * secondNormal->z - (s64) cc.z * secondNormal->x;
            if (qq < -16 || qq > 16) {
                cd.x = MUL_FIXED12_NO_ROUND(cc.x, (c)->x);
                cd.z = MUL_FIXED12_NO_ROUND(cc.z, (c)->z);
                cc.x = cc.x - MUL_FIXED12_NO_ROUND(cd.x, (c)->x);
                cc.z = cc.z - MUL_FIXED12_NO_ROUND(cd.z, (c)->z);
                VEC_Add(&firstHitRecord.mMaxOffset, &firstHitRecord.mMinOffset, &ua);
                if (Vec3DotUnrounded(&cc, &ua) >= 0) {
                    if (LENGTH_SQUARED(cc) >= 16) {
                        Vec3NormalizeAndGetLengthUnchecked(&cc, &cc);
                    }
                    cc.x = MUL_FIXED12_NO_ROUND(cc.x, radius >> 5);
                    cc.y = MUL_FIXED12_NO_ROUND(cc.y, radius >> 5);
                    cc.z = MUL_FIXED12_NO_ROUND(cc.z, radius >> 5);
                    pointMotion->x += cc.x;
                    pointMotion->z += cc.z;
                }
            }
        }
    }
    if (collisionBits != NULL) {
        *collisionBits = hitBits;
    }
    return anyHit;
}
