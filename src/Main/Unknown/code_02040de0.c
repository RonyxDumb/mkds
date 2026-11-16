#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

// Position of the start placement with key c (the only one when there are not several) moved by d along the negated
// first and e along the negated third axis of its rotation, and the rotation angles in b.
void mdat_calculateStartPosition(Vec3 *outPos, Vec3 *outRotation, s32 key, s32 firstAxisOffset,
                                           s32 thirdAxisOffset) {
    CourseMapPlacement *placement = NULL;
    CourseMapPlacement *candidate;
    s32 i;
    u16 angleX;
    u16 angleY;
    u16 angleZ;
    MtxFx43 rotationMatrix;
    MtxFx43 rotationMatrixX;
    MtxFx43 rotationMatrixY;
    MtxFx43 rotationMatrixZ;
    s32 negatedFirstAxisX;
    s32 negatedFirstAxisY;
    s32 negatedFirstAxisZ;
    s32 negatedThirdAxisX;
    s32 negatedThirdAxisY;
    s32 negatedThirdAxisZ;

    if (gMapData->mSettings->field4 != 0) {
        firstAxisOffset = 0x1000 - firstAxisOffset;
    }
    if (gMapData->mStartPlacementCount > 1) {
        for (i = 0; i < gMapData->mStartPlacementCount; i++) {
            candidate = &(gMapData->mStartPlacements)[i];
            if (key == (s16) candidate->mKey) {
                placement = candidate;
                break;
            }
        }
    } else {
        placement = gMapData->mStartPlacements;
    }
    angleX = (placement->fieldC.x >> 12) * 0xb6;
    angleY = (placement->fieldC.y >> 12) * 0xb6;
    angleZ = (placement->fieldC.z >> 12) * 0xb6;
    MTX_RotX43_((s32 *) &rotationMatrixX, FX_SinCosTable_[(angleX >> 4) * 2], FX_SinCosTable_[(angleX >> 4) * 2 + 1]);
    MTX_RotY43_(&rotationMatrixY, FX_SinCosTable_[(angleY >> 4) * 2], FX_SinCosTable_[(angleY >> 4) * 2 + 1]);
    MTX_RotZ43_((s32 *) &rotationMatrixZ, FX_SinCosTable_[(angleZ >> 4) * 2], FX_SinCosTable_[(angleZ >> 4) * 2 + 1]);
    MTX_Concat43(&rotationMatrixX, &rotationMatrixZ, &rotationMatrix);
    MTX_Concat43(&rotationMatrixY, &rotationMatrix, &rotationMatrix);
    negatedFirstAxisX = -rotationMatrix.field0[0].x;
    negatedFirstAxisY = -rotationMatrix.field0[0].y;
    negatedFirstAxisZ = -rotationMatrix.field0[0].z;
    negatedThirdAxisX = -rotationMatrix.field0[2].x;
    negatedThirdAxisY = -rotationMatrix.field0[2].y;
    negatedThirdAxisZ = -rotationMatrix.field0[2].z;
    outPos->x = placement->mPos.x + (s32) (((s64) negatedFirstAxisX * firstAxisOffset + 0x800) >> 12) +
                (s32) (((s64) negatedThirdAxisX * thirdAxisOffset + 0x800) >> 12);
    outPos->y = placement->mPos.y + (s32) (((s64) negatedFirstAxisY * firstAxisOffset + 0x800) >> 12) +
                (s32) (((s64) negatedThirdAxisY * thirdAxisOffset + 0x800) >> 12);
    outPos->z = placement->mPos.z + (s32) (((s64) negatedFirstAxisZ * firstAxisOffset + 0x800) >> 12) +
                (s32) (((s64) negatedThirdAxisZ * thirdAxisOffset + 0x800) >> 12);
    outRotation->x = placement->fieldC.x;
    outRotation->y = placement->fieldC.y;
    outRotation->z = placement->fieldC.z;
}

// Position and rotation of the start spot of kart c by mode: a staggered grid by rank in a race, by key
// (kart + mStartPlacementOffset) % 8 in battle.
void mdat_getStartPosition(Vec3 *outPos, Vec3 *outRotation, s32 kartIndex) {
    u16 lastKartIndex = gRaceMultiConfig->mKartCount - 1;
    s32 rankIndex = (u16) (rres_getPlace(kartIndex) - 1);
    s32 k;
    s32 l;
    s32 n;
    s32 t;
    s32 d;

    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        mdat_calculateStartPosition(outPos, outRotation, 0, 0, 0);
        return;
    }
    switch (gRaceMultiConfig->mMode) {
        case MODE_BATTLE:
            mdat_calculateStartPosition(outPos, outRotation,
                                                  (u16) ((rankIndex + gRaceStatus->mStartPlacementOffset) % 8), 0, 0);
            break;
        case MODE_TIME_ATTACK:
            mdat_calculateStartPosition(outPos, outRotation, 0, 0x800, 0);
            break;
        case MODE_MISSION_RUN:
            if (gRaceMultiConfig->mKartCount <= 1) {
                mdat_calculateStartPosition(outPos, outRotation, 0, 0x800, 0);
            } else {
                mdat_calculateStartPosition(outPos, outRotation, kartIndex,
                                                      (1 - kartIndex * 2) * 0x14000 + 0x800, 0);
            }
            break;
        default:
            k = mdat_sDriverPlacements[lastKartIndex * 2];
            l = k;
            n = rankIndex;
            if (rankIndex >= k) {
                l = data_0215406d[lastKartIndex * 2];
                n = rankIndex - k;
            }
            if ((l & 1) == 1) {
                n = (n - l / 2) * 2;
            } else {
                n = n * 2 + 1 - l;
            }
            if (rankIndex >= k) {
                if (k == data_0215406d[(u32) lastKartIndex * 2]) {
                    n = n + 1;
                }
            }
            d = n * 0x11000;
            t = 0;
            if (rankIndex >= k) {
                t = 1;
            }
            mdat_calculateStartPosition(outPos, outRotation, 0, d, rankIndex * 0x19000 + t * 0x14000);
            break;
    }
}

BOOL mdat_isPointInsideBoxArea(Vec3 *pos, CourseMapShape *shape) {
    Vec3 offset;
    s32 distance;
    s32 extent;

    VEC_Subtract(pos, &shape->mPos, &offset);
    distance = VEC_DotProduct(&offset, &shape->mAxisY);
    if (distance > (s32) (((s64) shape->mScale.y * 0x64000 + 0x800) >> 12) || distance < 0) {
        return FALSE;
    }
    distance = VEC_DotProduct(&offset, &shape->mAxisX);
    extent = ((s64) shape->mScale.x * 0x32000 + 0x800) >> 12;
    if (distance < -extent || distance > extent) {
        return FALSE;
    }
    distance = VEC_DotProduct(&offset, &shape->mAxisZ);
    extent = ((s64) shape->mScale.z * 0x32000 + 0x800) >> 12;
    if (distance < -extent || distance > extent) {
        return FALSE;
    }
    return TRUE;
}

s32 mdat_isPointInsideArea(Vec3 *pos, CourseMapShape *shape) {
    Vec3 offset;
    s32 inside = 0;
    s32 x;
    s32 y;
    s32 radius;

    switch (shape->mShapeKind) {
        case 0:
            inside = mdat_isPointInsideBoxArea(pos, shape);
            break;
        case 1:
            VEC_Subtract(pos, &shape->mPos, &offset);
            if (VEC_DotProduct(&offset, &shape->mAxisY) > (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                inside = 0;
            } else {
                x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                inside = (s32) (((s64) radius * radius + 0x800) >> 12) >=
                         (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12);
            }
            break;
    }
    return inside;
}

s32 mdat_isInsideMissionEndArea(Vec3 *pos, s32 *outFlag) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    BOOL found = FALSE;
    s32 x;
    s32 y;
    s32 radius;
    s32 inside;

    for (shapeIndex = 0; shapeIndex < gMapData->mShapeCount; shapeIndex++) {
        shape = mdat_getAreaEntryByIndex(shapeIndex);
        if (shape->mKind == 2) {
            inside = 0;
            switch (shape->mShapeKind) {
                case 0:
                    inside = mdat_isPointInsideBoxArea(pos, shape);
                    break;
                case 1:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) <=
                        (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                        x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) radius * radius + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                if ((s16) shape->field3C == 0) {
                    *outFlag = 1;
                } else {
                    *outFlag = 0;
                }
                found = TRUE;
                break;
            }
        }
    }
    return found;
}

void *mdat_findEnemyPoint(Vec3 *pos) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    s32 x;
    s32 y;
    s32 radius;
    void *link = NULL;
    s32 inside;

    if (gMapData->mKind4ShapeCount == 0) {
        return link;
    }
    for (shapeIndex = 0; shapeIndex < gMapData->mShapeCount; shapeIndex++) {
        shape = mdat_getAreaEntryByIndex(shapeIndex);
        if (shape->mKind == 4) {
            inside = 0;
            switch (shape->mShapeKind) {
                case 0:
                    inside = mdat_isPointInsideBoxArea(pos, shape);
                    break;
                case 1:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) <=
                        (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                        x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) radius * radius + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                link = (u8 *) gMapData->mRacePointLinks + shape->mPointIndex * 0x28;
                break;
            }
        }
    }
    return link;
}

PointLink *mdat_findMgEnemyPoint(Vec3 *pos) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    s32 x;
    s32 y;
    s32 radius;
    PointLink *link = NULL;
    s32 inside;

    if (gMapData->mKind4ShapeCount == 0) {
        return link;
    }
    for (shapeIndex = 0; shapeIndex < gMapData->mShapeCount; shapeIndex++) {
        shape = mdat_getAreaEntryByIndex(shapeIndex);
        if (shape->mKind == 4) {
            inside = 0;
            switch (shape->mShapeKind) {
                case 0:
                    inside = mdat_isPointInsideBoxArea(pos, shape);
                    break;
                case 1:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) <=
                        (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                        x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) radius * radius + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                link = &gMapData->mBattlePointLinks[shape->mPointIndex];
                break;
            }
        }
    }
    return link;
}

s32 mdat_findCameraId(Vec3 *pos) {
    u16 shapeIndex;
    CourseMapShape *shape;
    Vec3 offset;
    s32 x;
    s32 y;
    s32 radius;
    s32 cameraIndex = -1;
    s32 inside;

    for (shapeIndex = 0; shapeIndex < gMapData->mShapeCount; shapeIndex++) {
        shape = mdat_getAreaEntryByIndex(shapeIndex);
        if (shape->mKind == 1) {
            inside = 0;
            switch (shape->mShapeKind) {
                case 0:
                    inside = mdat_isPointInsideBoxArea(pos, shape);
                    break;
                case 1:
                    VEC_Subtract(pos, &shape->mPos, &offset);
                    if (VEC_DotProduct(&offset, &shape->mAxisY) >
                        (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                        inside = 0;
                    } else {
                        x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                        y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                        radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) radius * radius + 0x800) >> 12) <
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            inside = 0;
                        } else {
                            inside = 1;
                        }
                    }
                    break;
            }
            if (inside != 0) {
                cameraIndex = shape->mCameraIndex;
                break;
            }
        }
    }
    return cameraIndex;
}

// Mode 2: returns mNextRespawnSlot and advances it modulo mRespawnCount (the argument is ignored); otherwise returns
// mCheckpoints[a].mRespawnSlot, a = the kart's current entry.
u16 mdat_getRespawnId(u32 checkpointIndex) {
    u16 respawnSlot;
    CourseMap *courseMap;

    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        courseMap = gMapData;
        respawnSlot = courseMap->mNextRespawnSlot;
        courseMap->mNextRespawnSlot = (respawnSlot + 1) % courseMap->mRespawnCount;
    } else {
        respawnSlot = gMapData->mCheckpoints[checkpointIndex].mRespawnSlot;
    }
    return respawnSlot;
}

void *mdat_getRespawnData(u32 slot, Vec3 *outPos, Vec3 *outRotation) {
    CourseMapRespawn *respawn;
    s32 pointIndex;

    if (gMapData->mCheckpoints == NULL && gMapData->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &gMapData->mRespawns[gMapData->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        outPos->x = 0;
        outPos->y = 0;
        outPos->z = 0;
        outRotation->x = 0x1000;
        outRotation->y = 0;
        outRotation->z = 0;
        pointIndex = -1;
    } else {
        outPos->x = respawn->mPos.x;
        outPos->y = respawn->mPos.y;
        outPos->z = respawn->mPos.z;
        outRotation->x = respawn->fieldC.x;
        outRotation->y = respawn->fieldC.y;
        outRotation->z = respawn->fieldC.z;
        pointIndex = respawn->mPointIndex;
    }
    if (pointIndex == -1) {
        return NULL;
    }
    return (u8 *) gMapData->mRacePointLinks + pointIndex * 0x28;
}

PointLink *mdat_getMgRespawnData(u32 slot, Vec3 *outPos, Vec3 *outRotation) {
    CourseMapRespawn *respawn;
    s32 pointIndex;

    if (gMapData->mCheckpoints == NULL && gMapData->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &gMapData->mRespawns[gMapData->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        outPos->x = 0;
        outPos->y = 0;
        outPos->z = 0;
        outRotation->x = 0x1000;
        outRotation->y = 0;
        outRotation->z = 0;
        pointIndex = -1;
    } else {
        outPos->x = respawn->mPos.x;
        outPos->y = respawn->mPos.y;
        outPos->z = respawn->mPos.z;
        outRotation->x = respawn->fieldC.x;
        outRotation->y = respawn->fieldC.y;
        outRotation->z = respawn->fieldC.z;
        pointIndex = respawn->mPointIndex;
    }
    if (pointIndex == -1) {
        return NULL;
    }
    return &gMapData->mBattlePointLinks[pointIndex];
}

struct ItemPointLink *mdat_getItemPointForRespawn(u32 slot) {
    CourseMapRespawn *respawn;

    if (gMapData->mCheckpoints == NULL && gMapData->mRespawns == NULL) {
        respawn = NULL;
    } else {
        respawn = &gMapData->mRespawns[gMapData->mRespawnIndexBySlot[slot]];
    }
    if (respawn == NULL) {
        return NULL;
    }
    return &gMapData->mItemPointLinks[respawn->mItemPointIndex];
}

s32 mdat_isDriverInClipArea(s32 kartIndex, u32 listIndex) {
    CourseMapKind3ShapeNode *node;
    s32 inside;
    CourseMapShape *shape;
    Vec3 kartPos;
    Vec3 offset;
    s32 x;
    s32 y;
    s32 radius;
    BOOL found = FALSE;

    node = gMapData->mKind3ShapeLists[listIndex];
    driver_getPosition(&kartPos, kartIndex);
    for (; found == FALSE && node != NULL; node = node->field4) {
        shape = node->field0;
        inside = 0;
        switch (shape->mShapeKind) {
            case 0:
                inside = mdat_isPointInsideBoxArea(&kartPos, shape);
                break;
            case 1:
                VEC_Subtract(&kartPos, &shape->mPos, &offset);
                if (VEC_DotProduct(&offset, &shape->mAxisY) <=
                    (s32) (((s64) shape->mScale.y * 0x32000 + 0x800) >> 12)) {
                    x = VEC_DotProduct(&offset, &shape->mAxisX) >> 4;
                    y = VEC_DotProduct(&offset, &shape->mAxisZ) >> 4;
                    radius = (s32) (((s64) shape->mScale.x * 0x32000 + 0x800) >> 12) >> 4;
                    if ((s32) (((s64) radius * radius + 0x800) >> 12) >=
                        (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                        inside = 1;
                    }
                }
                break;
        }
        if (inside != 0) {
            found = TRUE;
        }
    }
    return found;
}
