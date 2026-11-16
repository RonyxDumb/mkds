#include "Main/Unknown/code_020e6fd4.h"
#include "code_02146d78.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_0210c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e73a0.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ea000.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_02077bc0.h"

void jg_startRespawning(void) {
    u32 value0;
    u32 requestedState;
    u32 raceKind;
    u32 staffRollKind;
    value0 = gRaceMultiConfig->mRaceKind;
    raceKind = value0;
    staffRollKind = 6u;
    if (raceKind == staffRollKind) {
    }
    if (raceKind == staffRollKind) {
    }
    if (raceKind == staffRollKind) {
        return;
    }
    value0 = (u32) &jg_sStateMachine;
    requestedState = 4u;
    sm_gotoState((void *) value0, requestedState);
}

#pragma thumb off
void jg_finishRespawning(void) {
    if (gRaceMultiConfig->mRaceKind != RACE_KIND_STAFF_ROLL) {
        data_0217b8b4 = 0x14;
    }
}

void func_020e79c4(void) {
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    NNS_SndPlayerStopSeq(GetSndHandleSlot(4), 1);
    jg_sTargetDriver = NULL;
}

#pragma thumb on
void jg_init(void) {
    Kart *kart;
    Vec3 *point;
    s32 i;
    Vec3 *sourcePoint;
    BOOL flag;

    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_START_GP) {
        jg_sTargetDriver = NULL;
        return;
    }
    if (gRaceMultiConfig->mEntryIndex < 0) {
        jg_sTargetDriver = NULL;
        return;
    }
    jg_sTargetDriverId = gRaceMultiConfig->mEntryIndex;
    kart = driver_getById(jg_sTargetDriverId);
    jg_sTargetDriver = kart;
    jg_sLight = &kart->mKartModelsEntry->mUnk_040;
    gJgTargetPos.x = 0;
    gJgTargetPos.y = 0;
    gJgTargetPos.z = 0;
    data_0217b90c = gJgTargetPos;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    gJgPos = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    gJgVelocity.x = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    gJgEasedPos = gJgPos;
    flag = TRUE;
    data_0217b8f0 = flag;
    data_0217b8bc = flag;
    data_0217b894 = 0;
    if (gMapData->mSettings->mUnk_04 != 0) {
        flag = FALSE;
    }
    data_0217b8f8 = flag;
    LukituObject = 4;
    gJgHighestLap = 1;
    jg_sLapCount = rconf_getLapCount();
    InitJgOffsets();
    gJgPoints[0].x = 0;
    gJgPoints[0].y = 0;
    gJgPoints[0].z = 0;
    sourcePoint = data_02159440;
    for (i = 0; i < 7; i++) {
        point = &gJgPoints[i + 1];
        *point = *sourcePoint;
        if (data_0217b8f8 != 0) {
            point->x = -point->x;
            point->y = -point->y;
            point->z = -point->z;
        }
        sourcePoint++;
    }
    switch (gRaceMultiConfig->mMode) {
        case MODE_BATTLE:
            gJgLapAndReverseEnabled = 0;
            break;
        case MODE_MISSION_RUN: {
            BOOL enabled;

            enabled = FALSE;
            if ((u8) (gRaceMultiConfig->mMissionKind + 0xfe) <= 8 &&
                (0x115 & (1 << (u8) (gRaceMultiConfig->mMissionKind + 0xfe))) != 0) {
                enabled = TRUE;
            }
            gJgLapAndReverseEnabled = enabled;
            break;
        }
        default:
            gJgLapAndReverseEnabled = 1;
            break;
    }
    switch (gRaceMultiConfig->mEngineIndex) {
        case 0:
            gJgState2FrameCount = 0x50;
            break;
        case 1:
            gJgState2FrameCount = 0x3c;
            break;
        case 2:
        default:
            gJgState2FrameCount = 0x2d;
            break;
    }
    data_0217b9dc.mSoundId = 0x101;
    data_0217b9dc.mPositionSource = &gJgPos;
    data_0217b9dc.mUnk_08 = 1;
    sm_init(&jg_sStateMachine, (UnkFunc *const *) jg_sStates, 7, NULL);
    sm_gotoState(&jg_sStateMachine, 0);
}

void jg_load(void) {
    s32 angle;
    s32 j;
    s32 i;
    void *heap;
    Unk0216c324 *sourceRow;
    JgKindRow *kindRow;
    void *file;
    s32 n;
    s32 angleIndex;

    heap = proc_getHeap(proc_getCurrent());
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    bbm_initFromNsbmd(&jg_sMainModel, arc_getSceneArcFile(aJg_main_nsbmd), arc_getSceneArcFile(aJg_main_nsbtp), 0);
    bbm_setDefaultMatParams(&jg_sMainModel);
    jg_sMainModel.mUnk_14 |= 0xc0;
    bbm_initFromNsbmd(&jg_sCloudModel, arc_getSceneArcFile(aJg_cloud_nsbmd), NULL, 0);
    bbm_setDefaultMatParams(&jg_sCloudModel);
    jg_sCloudModel.mUnk_14 |= 0xc0;
    data_0217b8a4 = heap_alloc(heap, 0x78);
    data_0217b8a8 = heap_alloc(heap, 0x78);
    data_0217b8a0 = heap_alloc(heap, 0x78);
    data_0217b8e0 = heap_alloc(heap, 0x78);
    data_0217b904 = heap_alloc(heap, 0x78);
    for (i = 0, angle = 0; i < 0x3c; i++) {
        data_0217b8a4[i] = (u16) (((s64) FX_SinCosTable_[(angle >> 4) * 2] * 0x4c) >> 12);
        angleIndex =
            (u16) (((u64) (s64) FX_SinCosTable_[((u16) (angle + 0xa218) >> 4) * 2] * 0xb60b60b60b + 0x80000000000) >>
                   44) >>
            4;
        data_0217b8a8[i] = FX_SinCosTable_[angleIndex * 2];
        data_0217b8a0[i] = FX_SinCosTable_[angleIndex * 2 + 1];
        data_0217b8e0[i] = (u32) (((s64) FX_SinCosTable_[((u16) (angle + 0x1554) >> 4) * 2] * 0x19a) >> 12) + 0xe66;
        data_0217b904[i] = (u32) (((s64) FX_SinCosTable_[((u16) (angle + 0xbbb0) >> 4) * 2] * 0x19a) >> 12) + 0x119a;
        angle += 0x444;
    }
    gJgTableIndex = 0;
    n = 2;
    for (j = n, sourceRow = data_0216c324, kindRow = data_0217bb08; j < 4; j++) {
        if (sourceRow->mUnk_00 != NULL) {
            kindRow->mModel = heap_alloc(heap, 0x6c);
            file = arc_getSceneArcFile(sourceRow->mUnk_00);
            model_initFromNsbmd(kindRow->mModel, file);
            model_setPolyIdLightFlagsEmi(kindRow->mModel, 0x3f, n, 0x294a);
            model_setCullMode(kindRow->mModel, 3);
        } else {
            kindRow->mModel = NULL;
        }
        if (sourceRow->mUnk_04 != NULL) {
            kindRow->mNsbcaAnimation = heap_alloc(heap, 0x38);
            anim_20EA514(0, kindRow->mModel, kindRow->mNsbcaAnimation, file,
                                          arc_getSceneArcFile(sourceRow->mUnk_04));
            anim_setLoop(kindRow->mNsbcaAnimation, 0, 1);
        } else {
            kindRow->mNsbcaAnimation = NULL;
        }
        if (sourceRow->mUnk_08 != NULL) {
            kindRow->mNsbmaAnimation = heap_alloc(heap, 0x38);
            anim_20EA514(4, kindRow->mModel, kindRow->mNsbmaAnimation, file,
                                          arc_getSceneArcFile(sourceRow->mUnk_08));
            anim_setLoop(kindRow->mNsbmaAnimation, 0, 1);
        } else {
            kindRow->mNsbmaAnimation = NULL;
        }
        sourceRow++;
        kindRow++;
    }
    bbm_createFromNsbmd((NsbmdModel **) gJgKindRowLapModels, arc_getSceneArcFile(aLap_count_nsbm), arc_getSceneArcFile(aLap_count_nsbt), 0);
    bbm_setDefaultMatParams(gJgKindRows[0].mLapModel);
    gJgKindRows[0].mLapModel->mUnk_14 |= 0xc0;
    bbm_createFromNsbmd((NsbmdModel **) data_0217bb04, arc_getSceneArcFile(aLap_final_nsbm), 0, 0);
    bbm_setDefaultMatParams(gJgKindRows[1].mLapModel);
    gJgKindRows[1].mLapModel->mUnk_14 |= 0xc0;
}
#pragma thumb off

Unk020e7410 *fwdst_setupConfig(void) {
    Unk020e7410 *kindData;

    kindData = heap_alloc(proc_getHeap(proc_getCurrent()), 0x40);
    *kindData = *(Unk020e7410 *) data_02159370;
    return kindData;
}

MapObjectList *fwdst_setupLogicPart(void) {
    MapObjectList *list;

    list = heap_alloc(proc_getHeap(proc_getCurrent()), 0x28);
    fwdst_sLogicPart = list;
    *list = *(MapObjectList *) data_02159348;
    mobj_logicPartSetThisPointer(&fwdst_sLogicPart);
    return fwdst_sLogicPart;
}

Vec3 *fwdst_getPosition(u32 index) {
    return (*(Vec3 ***) fwdst_sPositions)[index];
}

u16 fwdst_getCCDependentSetting(int index) {
    u32 value0 = index;
    u32 value1;
    value1 = (u32) &fwdst_sCCDependentSettings;
    value0 = (value0 << 1);
    value1 = *(const u32 *) ((value1) + (0));
    value0 = *(const u16 *) ((value1) + (value0));
    return value0;
}

#pragma thumb on
void fwdst_globalInitLogic(void) {
    Unk020e730c *object;
    s32 objectCount;
    s32 i;

    objectCount = ((MapObjectList *) fwdst_sLogicPart)->mMapObjectCount;
    *(void **) fwdst_sPositions = heap_alloc(proc_getHeap(proc_getCurrent()), objectCount * 4);
    fwdst_sCCDependentSettings = heap_alloc(proc_getHeap(proc_getCurrent()), objectCount * 2);
    for (i = 0; i < ((MapObjectList *) fwdst_sLogicPart)->mMapObjectCount; i++) {
        s32 tableIndex;

        object = ((MapObjectList *) fwdst_sLogicPart)->mMapObjects[i];
        tableIndex = object->mTableIndex;
        (*(Vec3 ***) fwdst_sPositions)[tableIndex] = &object->mUnk_00.mPos;
        fwdst_sCCDependentSettings[tableIndex] = object->mEntryValue;
    }
}

void fwdst_init(Unk020e730c *object, struct CourseMapRow *courseRow) {
    object->mTableIndex = courseRow->mUnk_28;
    switch (gRaceMultiConfig->mEngineIndex) {
        case 0:
            object->mEntryValue = courseRow->mUnk_2a;
            break;
        case 1:
            object->mEntryValue = courseRow->mUnk_2c;
            break;
        case 2:
            object->mEntryValue = courseRow->mUnk_2e;
            break;
    }
}
#pragma thumb off

void mobj_logicPartUpdateSoundEmitter(MapObject *object) {
    MapObjectSound *sound;
    BOOL resultIsFalse;
    BOOL hasSoundBit0;

    sound = object->mSound;
    if ((object->mFlags & 2) == 0) {
        sound->mSoundSource.mDistanceSquared = object->mDistanceSquaredAndFlags & ~0xc000001f;
        resultIsFalse = (mobj_isInaudible(object) == FALSE);
        hasSoundBit0 = (sound->mSoundSource.mSourceFlags & 1) != 0;
        if (resultIsFalse != FALSE) {
            if (hasSoundBit0 != FALSE) {
                goto ret;
            }
            goto call;
        }
    ret:
        if (resultIsFalse != FALSE) {
            return;
        }
        if (hasSoundBit0 == FALSE) {
            return;
        }
    call:
        SetSoundSourceFlagBit(&sound->mSoundSource, 2, 1);
    } else {
        s32 distanceSquared;

        distanceSquared = mobj_calcXZCamDist(&object->mPos);
        sound->mSoundSource.mDistanceSquared = distanceSquared;
        if (mobj_calcInaudible(object, distanceSquared) != FALSE) {
            object->mDistanceSquaredAndFlags |= data_02159310;
            if ((sound->mSoundSource.mSourceFlags & 1) != 0) {
                SetSoundSourceFlagBit(&sound->mSoundSource, 2, 1);
            }
        } else if ((sound->mSoundSource.mSourceFlags & 1) == 0) {
            SetSoundSourceFlagBit(&sound->mSoundSource, 2, 1);
        }
    }
}

void mobj_logicPartExecute(MapObjectList *list) {
    MapObject *object;
    Vec3 previousPos;
    void (*callback)(void *list, MapObject *object);
    s32 count;
    void **objects;

    callback = list->mForEachObject;
    count = list->mMapObjectCount;
    objects = list->mMapObjects;
    if (callback == NULL) {
        s32 i;

        for (i = 0; i < count; i++) {
            object = objects[i];
            if (object->mSound != NULL) {
                mobj_logicPartUpdateSoundEmitter(object);
            }
        };
        return;
    }
    if (list->mUnk_18 == 2) {
        s32 i;

        for (i = 0; i < count; i++) {
            object = objects[i];
            if ((object->mFlags & 4) == 0) {
                previousPos = object->mPos;
                callback(list, object);
                VEC_Subtract(&object->mPos, &previousPos, &object->mUnk_10);
                if (object->mSound != NULL) {
                    mobj_logicPartUpdateSoundEmitter(object);
                }
            }
        };
        return;
    }
    {
        s32 i;

        for (i = 0; i < count; i++) {
            object = objects[i];
            if ((object->mFlags & 4) == 0) {
                callback(list, object);
                if (object->mSound != NULL) {
                    mobj_logicPartUpdateSoundEmitter(object);
                }
            }
        }
    }
}

void mobj_logicPartExecuteThunderLogic(MapObjectList *list) {
    MapObject *object;
    u8 callbackArgs[2];
    s32 i;
    s32 count;
    void **objects;
    s32 (*callback)(MapObject *, void *, void *, void *);

    count = list->mMapObjectCount;
    callback = list->mUnk_1c;
    objects = list->mMapObjects;
    callbackArgs[0] = list->mUnk_20;
    callbackArgs[1] = 0;
    if (callback == NULL) {
        return;
    }
    for (i = 0; i < count; i++) {
        object = objects[i];
        if ((object->mFlags & 0x88) == 0) {
            callback(object, NULL, &callbackArgs[0], &callbackArgs[1]);
        }
    }
}
