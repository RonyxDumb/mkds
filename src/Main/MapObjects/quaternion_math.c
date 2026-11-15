#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Menu/choises_s.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "01/Race/mission_run_state.h"
#include "matrix_3x3_basic.h"
#include "vector_math.h"
#include "Main/MapObjects/quaternion_math.h"
#include "Main/MapObjects/group_paths.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "fixed_arctangent.h"
#include "registers.h"
#include "particle_instance.h"
#include "Main/MapObjects/rock_kind_data.h"

#pragma thumb on

void InitGroupFollowerWithSpeeds(GroupFollowerWithSpeeds *follower, struct CourseMapRow *courseRow, s32 speed,
                                 s32 speedPercent) {
    InitGroupFollower(&follower->mGroupFollower, courseRow, speed);
    follower->mSpeedPerEntryUnit = speed / 100;
    follower->mDefaultSpeed = (speed * speedPercent) / 100;
    SetupGroupFollowerWithSpeeds(follower, 0, 1);
}

void InitSegmentProgress(SegmentProgress *segmentProgress, s32 useStraightLength, Vec3 **points, s32 rate) {
    BuildSegment(&segmentProgress->mSegment, useStraightLength, 0, points[0], points[1], points[2], points[3]);
    SetSegmentProgressRate(segmentProgress, rate);
    segmentProgress->mProgress = 0;
}

BOOL BuildNextSegmentProgress(SegmentProgress *segmentProgress, s32 useStraightLength, Vec3 **points) {
    s32 value;
    segmentProgress->mProgress = segmentProgress->mProgress - SEGMENT_PROGRESS_END;
    segmentProgress->mProgress =
        MUL_FIXED12_NO_ROUND(segmentProgress->mProgress, segmentProgress->mSegment.mProgressLength);
    BuildSegment(&segmentProgress->mSegment, useStraightLength, 0, points[0], points[1], points[2], points[3]);
    value = segmentProgress->mSegment.mInverseProgressLength;
    if (value != 0) {
        segmentProgress->mProgress = ((s64) segmentProgress->mProgress * (s64) value) >> 24;
    }
    if (value != 0) {
        value = MUL_FIXED12_NO_ROUND(segmentProgress->mRate, value);
    } else {
        value = SEGMENT_PROGRESS_END;
    }
    segmentProgress->mProgressStep = value;
    if (segmentProgress->mProgress >= SEGMENT_PROGRESS_END) {
        return TRUE;
    }
    return FALSE;
}

#pragma thumb off

void SetViewYawQuaternion(MtxFx43 *viewMatrix) {
    s32 angle;
    angle = FX_Atan2(viewMatrix->mRows[0].z, viewMatrix->mRows[2].z);
    angle = (((s64) angle * 0x28BE60DB9391LL) + 0x80000000000LL) >> 44;
    gViewYawQuaternion.mComponents[0] = 0;
    gViewYawQuaternion.mComponents[1] = SIN_OF_ANGLE((u16) ((u16) angle >> 1));
    gViewYawQuaternion.mComponents[2] = 0;
    gViewYawQuaternion.mComponents[3] = COS_OF_ANGLE((u16) ((u16) angle >> 1));
}

void QuaternionFromYAxisToVec3(Vec3 *direction, Quaternion *quaternion) {
    s32 root = FX_Sqrt((direction->y + 0x1000) << 1);
    FX_DivAsync(direction->z, root);
    quaternion->mComponents[1] = 0;
    quaternion->mComponents[0] = FX_GetDivResult();
    FX_DivAsync(-direction->x, root);
    quaternion->mComponents[3] = root >> 1;
    quaternion->mComponents[2] = FX_GetDivResult();
}

void QuaternionFromAngleAroundY(u16 angle, Quaternion *quaternion) {
    quaternion->mComponents[0] = 0;
    quaternion->mComponents[1] = SIN_OF_ANGLE((u16) (angle >> 1));
    quaternion->mComponents[2] = 0;
    quaternion->mComponents[3] = COS_OF_ANGLE((u16) (angle >> 1));
}

void QuaternionFromVec3AndAngleAroundY(Vec3 *direction, s32 angle, Quaternion *quaternion) {
    s32 root;
    s32 quotient;
    s32 pairFirst;
    s32 pairSecond;
    s64 radicand = (s64) ((direction->y + 0x1000) << 1) << 32;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = radicand;
    root = FX_GetSqrtResult();
    FX_DivAsync(direction->z, root);
    pairFirst = SIN_OF_ANGLE((u16) (angle >> 1));
    pairSecond = COS_OF_ANGLE((u16) (angle >> 1));
    quaternion->mComponents[1] = ((root >> 1) * pairFirst) >> 12;
    quaternion->mComponents[3] = ((root >> 1) * pairSecond) >> 12;
    quotient = FX_GetDivResult();
    FX_DivAsync(-direction->x, root);
    quaternion->mComponents[0] = (quotient * pairSecond) >> 12;
    quaternion->mComponents[2] = (quotient * pairFirst) >> 12;
    quotient = FX_GetDivResult();
    quaternion->mComponents[0] = quaternion->mComponents[0] - ((quotient * pairFirst) >> 12);
    quaternion->mComponents[2] = quaternion->mComponents[2] + ((quotient * pairSecond) >> 12);
}

void QuaternionMultiplyAngleAroundYIgnoreY(Quaternion *quaternion, u16 angle, Quaternion *result) {
    s32 pairFirst = SIN_OF_ANGLE((u16) (angle >> 1));
    s32 pairSecond = COS_OF_ANGLE((u16) (angle >> 1));
    result->mComponents[0] = (quaternion->mComponents[0] * pairSecond - quaternion->mComponents[2] * pairFirst) >> 12;
    result->mComponents[1] = (quaternion->mComponents[3] * pairFirst) >> 12;
    result->mComponents[2] = (quaternion->mComponents[2] * pairSecond + quaternion->mComponents[0] * pairFirst) >> 12;
    result->mComponents[3] = (quaternion->mComponents[3] * pairSecond) >> 12;
}

void QuaternionMultiplyByYawIgnoreY(Quaternion *first, Quaternion *second, Quaternion *result) {
    result->mComponents[0] =
        (first->mComponents[0] * second->mComponents[3] - first->mComponents[2] * second->mComponents[1]) >> 12;
    result->mComponents[1] = (first->mComponents[3] * second->mComponents[1]) >> 12;
    result->mComponents[2] =
        (first->mComponents[2] * second->mComponents[3] + first->mComponents[0] * second->mComponents[1]) >> 12;
    result->mComponents[3] = (first->mComponents[3] * second->mComponents[3]) >> 12;
}

void QuaternionMultiplyAngleAroundX(Quaternion *quaternion, u16 angle, Quaternion *result) {
    Quaternion source = *quaternion;
    s32 pairFirst = SIN_OF_ANGLE((u16) (angle >> 1));
    s32 pairSecond = COS_OF_ANGLE((u16) (angle >> 1));
    result->mComponents[0] = (source.mComponents[3] * pairFirst + source.mComponents[0] * pairSecond) >> 12;
    result->mComponents[1] = (source.mComponents[1] * pairSecond + source.mComponents[2] * pairFirst) >> 12;
    result->mComponents[2] = (source.mComponents[2] * pairSecond - source.mComponents[1] * pairFirst) >> 12;
    result->mComponents[3] = (source.mComponents[3] * pairSecond - source.mComponents[0] * pairFirst) >> 12;
}

void QuaternionMultiplyAngleAroundY(Quaternion *quaternion, s32 angle, Quaternion *result) {
    Quaternion source = *quaternion;
    s32 pairFirst = SIN_OF_ANGLE((u16) (angle >> 1));
    s32 pairSecond = COS_OF_ANGLE((u16) (angle >> 1));
    result->mComponents[0] = (source.mComponents[0] * pairSecond - source.mComponents[2] * pairFirst) >> 12;
    result->mComponents[1] = (source.mComponents[3] * pairFirst + source.mComponents[1] * pairSecond) >> 12;
    result->mComponents[2] = (source.mComponents[2] * pairSecond + source.mComponents[0] * pairFirst) >> 12;
    result->mComponents[3] = (source.mComponents[3] * pairSecond - source.mComponents[1] * pairFirst) >> 12;
}

void QuaternionMultiplyAngleAroundZ(Quaternion *quaternion, s32 angle, Quaternion *result) {
    Quaternion source = *quaternion;
    s32 pairFirst = SIN_OF_ANGLE((u16) (angle >> 1));
    s32 pairSecond = COS_OF_ANGLE((u16) (angle >> 1));
    result->mComponents[0] = (source.mComponents[0] * pairSecond + source.mComponents[1] * pairFirst) >> 12;
    result->mComponents[1] = (source.mComponents[1] * pairSecond - source.mComponents[0] * pairFirst) >> 12;
    result->mComponents[2] = (source.mComponents[3] * pairFirst + source.mComponents[2] * pairSecond) >> 12;
    result->mComponents[3] = (source.mComponents[3] * pairSecond - source.mComponents[2] * pairFirst) >> 12;
}

void QuaternionMultiplyAngleAroundXIgnoreXZ(Quaternion *quaternion, u16 angle, Quaternion *result) {
    Quaternion source = *quaternion;
    s32 pairFirst = SIN_OF_ANGLE((u16) (angle >> 1));
    s32 pairSecond = COS_OF_ANGLE((u16) (angle >> 1));
    result->mComponents[0] = (source.mComponents[3] * pairFirst) >> 12;
    result->mComponents[1] = (source.mComponents[1] * pairSecond) >> 12;
    result->mComponents[2] = (-source.mComponents[1] * pairFirst) >> 12;
    result->mComponents[3] = (source.mComponents[3] * pairSecond) >> 12;
}

void QuaternionBlendTowardNearerSign(Quaternion *from, Quaternion *to, Quaternion *result, s32 amount) {
    s32 dot = from->mComponents[0] * to->mComponents[0] + from->mComponents[1] * to->mComponents[1] +
              from->mComponents[2] * to->mComponents[2] + from->mComponents[3] * to->mComponents[3];
    if (dot < 0) {
        result->mComponents[0] = from->mComponents[0] + ((amount * -(to->mComponents[0] + from->mComponents[0])) >> 12);
        result->mComponents[1] = from->mComponents[1] + ((amount * -(to->mComponents[1] + from->mComponents[1])) >> 12);
        result->mComponents[2] = from->mComponents[2] + ((amount * -(to->mComponents[2] + from->mComponents[2])) >> 12);
        result->mComponents[3] = from->mComponents[3] + ((amount * -(to->mComponents[3] + from->mComponents[3])) >> 12);
    } else {
        result->mComponents[0] = from->mComponents[0] + ((amount * (to->mComponents[0] - from->mComponents[0])) >> 12);
        result->mComponents[1] = from->mComponents[1] + ((amount * (to->mComponents[1] - from->mComponents[1])) >> 12);
        result->mComponents[2] = from->mComponents[2] + ((amount * (to->mComponents[2] - from->mComponents[2])) >> 12);
        result->mComponents[3] = from->mComponents[3] + ((amount * (to->mComponents[3] - from->mComponents[3])) >> 12);
    }
}

void QuaternionNormalizeUnlessNearOne(Quaternion *input, Quaternion *output) {
    s64 lengthSquared;
    s32 root;
    s64 quotient;
    s64 factor;
    lengthSquared = input->mComponents[0] * input->mComponents[0] + input->mComponents[1] * input->mComponents[1] +
                    input->mComponents[2] * input->mComponents[2] + input->mComponents[3] * input->mComponents[3];
    if (lengthSquared > 0xE66666 && lengthSquared < 0x119999A) {
        *output = *input;
        return;
    }
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = lengthSquared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = lengthSquared << 2;
    while (reg_CP_SQRTCNT & REG_CP_SQRTCNT_BUSY_MASK) {
    }
    root = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & REG_CP_DIVCNT_BUSY_MASK) {
    }
    quotient = reg_CP_DIV_RESULT;
    factor = quotient * root;
    output->mComponents[0] = (factor * input->mComponents[0] + 0x100000000000LL) >> 45;
    output->mComponents[1] = (factor * input->mComponents[1] + 0x100000000000LL) >> 45;
    output->mComponents[2] = (factor * input->mComponents[2] + 0x100000000000LL) >> 45;
    output->mComponents[3] = (factor * input->mComponents[3] + 0x100000000000LL) >> 45;
}

void QuaternionFromVec3Degrees(Vec3 *degrees, Quaternion *result) {
    Quaternion partial;
    Quaternion afterX;
    Quaternion afterXY;
    s32 pairFirst;
    s32 pairSecond;
    s32 angle;
    angle = ((s64) degrees->x * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    partial.mComponents[0] = SIN_OF_ANGLE((u16) ((u16) angle >> 1));
    partial.mComponents[3] = COS_OF_ANGLE((u16) ((u16) angle >> 1));
    partial.mComponents[1] = 0;
    partial.mComponents[2] = 0;
    afterX = partial;
    angle = ((s64) degrees->y * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    pairFirst = SIN_OF_ANGLE((u16) ((u16) angle >> 1));
    pairSecond = COS_OF_ANGLE((u16) ((u16) angle >> 1));
    partial.mComponents[0] = (afterX.mComponents[0] * pairSecond - afterX.mComponents[2] * pairFirst) >> 12;
    partial.mComponents[2] = (afterX.mComponents[2] * pairSecond + afterX.mComponents[0] * pairFirst) >> 12;
    partial.mComponents[1] = (afterX.mComponents[3] * pairFirst + afterX.mComponents[1] * pairSecond) >> 12;
    partial.mComponents[3] = (afterX.mComponents[3] * pairSecond - afterX.mComponents[1] * pairFirst) >> 12;
    afterXY = partial;
    angle = ((s64) degrees->z * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    pairFirst = SIN_OF_ANGLE((u16) ((u16) angle >> 1));
    pairSecond = COS_OF_ANGLE((u16) ((u16) angle >> 1));
    result->mComponents[0] = (afterXY.mComponents[0] * pairSecond + afterXY.mComponents[1] * pairFirst) >> 12;
    result->mComponents[1] = (afterXY.mComponents[1] * pairSecond - afterXY.mComponents[0] * pairFirst) >> 12;
    result->mComponents[2] = (afterXY.mComponents[3] * pairFirst + afterXY.mComponents[2] * pairSecond) >> 12;
    result->mComponents[3] = (afterXY.mComponents[3] * pairSecond - afterXY.mComponents[2] * pairFirst) >> 12;
}

s32 Vec3NormalizeAndGetLengthOrZero(Vec3 *vector, Vec3 *result) {
    s64 lengthSquared;
    s32 root;
    s64 quotient;
    s64 factor;
    lengthSquared = (s64) vector->x * vector->x;
    lengthSquared += (s64) vector->y * vector->y;
    lengthSquared += (s64) vector->z * vector->z;
    if (lengthSquared < 16) {
        return 0;
    }
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = lengthSquared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = lengthSquared << 2;
    while (reg_CP_SQRTCNT & REG_CP_SQRTCNT_BUSY_MASK) {
    }
    root = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & REG_CP_DIVCNT_BUSY_MASK) {
    }
    quotient = reg_CP_DIV_RESULT;
    factor = quotient * root;
    result->x = (factor * vector->x + 0x100000000000LL) >> 45;
    result->y = (factor * vector->y + 0x100000000000LL) >> 45;
    result->z = (factor * vector->z + 0x100000000000LL) >> 45;
    return (root + 1) >> 1;
}

s32 Vec3NormalizeXZAndGetLengthOrZero(Vec3 *vector, Vec3 *result) {
    s64 lengthSquared;
    s32 root;
    s64 quotient;
    s64 factor;
    s32 vectorX = vector->x;
    s32 vectorZ = vector->z;
    lengthSquared = SQUARE_SUM2(vectorX, vectorZ);
    if (lengthSquared < 16) {
        return 0;
    }
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = lengthSquared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = lengthSquared << 2;
    while (reg_CP_SQRTCNT & REG_CP_SQRTCNT_BUSY_MASK) {
    }
    root = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & REG_CP_DIVCNT_BUSY_MASK) {
    }
    quotient = reg_CP_DIV_RESULT;
    factor = quotient * root;
    result->x = (factor * vector->x + 0x100000000000LL) >> 45;
    result->z = (factor * vector->z + 0x100000000000LL) >> 45;
    return (root + 1) >> 1;
}

void Vec3RotateAroundY(Vec3 *vector, s32 angle, Vec3 *result) {
    MtxFx33 matrix;
    MTX_RotY33_(&matrix, SIN_OF_ANGLE(angle), COS_OF_ANGLE(angle));
    MTX_MultVec33(vector, &matrix, result);
}

void Matrix3x3FromVec3Degrees(Vec3 *degrees, MtxFx33 *matrix) {
    MtxFx33 rotation;
    s32 angleX;
    s32 angleY;
    s32 angleZ;
    angleX = DEG_TO_ANGLE(degrees->x);
    angleY = DEG_TO_ANGLE(degrees->y);
    angleZ = DEG_TO_ANGLE(degrees->z);
    MTX_RotX33_(matrix, FX_SinIdx(angleX), FX_CosIdx(angleX));
    MTX_RotY33_(&rotation, FX_SinIdx(angleY), FX_CosIdx(angleY));
    MTX_Concat33(matrix, &rotation, matrix);
    MTX_RotZ33_(&rotation, FX_SinIdx(angleZ), FX_CosIdx(angleZ));
    MTX_Concat33(matrix, &rotation, matrix);
}

u32 GetKartMapObjectResponseByKind(s32 flagBit, s32 itemEffect, s32 kindHundreds, s32 kindRemainder) {
    u32 response = gKartResponsesByKind[kindHundreds][itemEffect][kindRemainder];
    if (response == 1) {
        response = flagBit != 0 ? 2 : 0;
    }
    return response;
}

u32 GetItemObjectFirstResponseByKind(u32 zeroResultFlag, u32 itemKind, u32 kindHundreds, u32 kindRemainder) {
    u32 response = gItemObjectFirstResponsesByKind[kindHundreds][itemKind][kindRemainder];
    if (zeroResultFlag != 0) {
        response = 0;
    }
    return response;
}

u32 GetItemObjectResponseByKind(s32 flagBit, s32 itemKind, s32 kindHundreds, s32 kindRemainder, s32 kindDataValue) {
    u32 response = gItemObjectResponsesByKind[kindHundreds][itemKind][kindRemainder];
    if (flagBit != 0 && response == 1 && kindDataValue != 0) {
        response = 2;
    }
    return response;
}

s32 CollideKartWithMapObject(Kart *kart, MapObject *mapObject) {
    s32 kindRemainder = mapObject->mKind;
    s32 kindHundreds = 0;
    s32 flagBit;
    s32 response;
    s32 responses[2];
    flagBit = mapObject->mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    if (mapObject->mKindData->mCollideKartCallback != NULL) {
        response = gKartFirstResponsesByKind[kindHundreds][kart->mItemEffect][kindRemainder];
        if (flagBit != 0 && response != 2 && response != 4) {
            response = 0;
        }
        responses[0] = response;
        response = gKartResponsesByKind[kindHundreds][kart->mItemEffect][kindRemainder];
        if (response == 1) {
            response = flagBit != 0 ? 2 : 0;
        }
        responses[1] = response;
        if ((mapObject->mFlags & MAP_OBJECT_FLAG_NUMBER_OVERFLOW) == 0) {
            responses[1] = mapObject->mKindData->mCollideKartCallback(mapObject, kart, &responses[0], &responses[1]);
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN && responses[0] == 1 && gRaceSetup->mMode == MODE_MISSION_RUN) {
            AddMissionRunCountForMapObjectKind(mapObject->mKind);
        }
        return responses[1];
    }
    response = gKartResponsesByKind[kindHundreds][kart->mItemEffect][kindRemainder];
    if (response != 1) {
        return response;
    }
    return flagBit != 0 ? 2 : 0;
}

s32 CollideItemObjectWithMapObject(ItemObject *itemObject, MapObject *mapObject, s32 *firstResponseOut) {
    s32 kindRemainder = mapObject->mKind;
    s32 kindHundreds = 0;
    s32 flagBit = mapObject->mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI;
    s32 response;
    s32 responses[2];
    s32 kindDataValue;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    if (mapObject->mKindData->mCollideItemObjectCallback != NULL) {
        response = gItemObjectFirstResponsesByKind[kindHundreds][itemObject->mKind][kindRemainder];
        if (flagBit != 0) {
            response = 0;
        }
        responses[0] = response;
        kindDataValue = mapObject->mKindData->mPosStepMode;
        response = gItemObjectResponsesByKind[kindHundreds][itemObject->mKind][kindRemainder];
        if (flagBit != 0 && response == 1 && kindDataValue != 0) {
            response = 2;
        }
        responses[1] = response;
        if ((mapObject->mFlags & MAP_OBJECT_FLAG_NUMBER_OVERFLOW) == 0) {
            responses[1] =
                mapObject->mKindData->mCollideItemObjectCallback(mapObject, itemObject, &responses[0], &responses[1]);
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN && responses[0] == 1 && gRaceSetup->mMode == MODE_MISSION_RUN) {
            AddMissionRunCountForMapObjectKind(mapObject->mKind);
        }
        if (firstResponseOut != NULL) {
            *firstResponseOut = responses[0];
        }
        return responses[1];
    }
    if (firstResponseOut != NULL) {
        *firstResponseOut = 0;
    }
    kindDataValue = mapObject->mKindData->mPosStepMode;
    response = gItemObjectResponsesByKind[kindHundreds][itemObject->mKind][kindRemainder];
    if (flagBit != 0 && response == 1 && kindDataValue != 0) {
        response = 2;
    }
    return response;
}

s32 DoesKartRespondToMapObject(s32 itemEffect, MapObject *mapObject) {
    s32 kindRemainder = mapObject->mKind;
    s32 kindHundreds = 0;
    s32 response;
    s32 flagBit;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    flagBit = mapObject->mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI;
    response = gKartResponsesByKind[kindHundreds][itemEffect][kindRemainder];
    if (response == 1) {
        response = flagBit != 0 ? 2 : 0;
    }
    return response != 0 ? 1 : 0;
}

s32 DoesItemObjectRespondToMapObject(s32 itemKind, MapObject *mapObject) {
    s32 kindRemainder = mapObject->mKind;
    s32 kindHundreds = 0;
    s32 response;
    s32 flagBit;
    s32 kindDataValue;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    flagBit = mapObject->mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI;
    kindDataValue = mapObject->mKindData->mPosStepMode;
    response = gItemObjectResponsesByKind[kindHundreds][itemKind][kindRemainder];
    if (flagBit != 0 && response == 1 && kindDataValue != 0) {
        response = 2;
    }
    return response != 0 ? 1 : 0;
}

s32 GetItemObjectFirstResponse(s32 itemKind, MapObject *mapObject) {
    MapObject *object = mapObject;
    s32 kindRemainder = object->mKind;
    s32 kindHundreds = 0;
    s32 response;
    s32 flagBit;
    while (kindRemainder >= 100) {
        kindRemainder -= 100;
        kindHundreds++;
    }
    flagBit = object->mFlags & MAP_OBJECT_FLAG_TIME_ATTACK_OR_WIFI;
    response = gItemObjectFirstResponsesByKind[kindHundreds][itemKind][kindRemainder];
    if (flagBit != 0) {
        response = 0;
    }
    return response;
}
