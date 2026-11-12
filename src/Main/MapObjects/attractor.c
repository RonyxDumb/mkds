#include "Main/MapObjects/attractor.h"
#include "fx_mtx33.h"

#include "Main/System/heap.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/sound_sources.h"
#include "Main/MapObjects/data_02159000.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "code_02147cd8.h"
#include "Main/System/heap_call.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Race/race_entries.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/jg.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_drift.h"
#include "player.h"
#include "Main/System/state_machine_init.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/model_animation_loop_mode.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Item/item_in_use.h"
#include "Main/Kart/karts.h"

void SetJgState4(void) {
    u32 raceKindValue;
    u32 raceKind;
    u32 staffRollKind;
    raceKindValue = gRaceSetup->mRaceKind;
    raceKind = raceKindValue;
    staffRollKind = 6u;
    if (raceKind == staffRollKind) {
    }
    if (raceKind == staffRollKind) {
    }
    if (raceKind == staffRollKind) {
        return;
    }
    SetStateMachineState(&gJgStateMachine, 4);
}

#pragma thumb off
void SetJgState4Countdown(void) {
    if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        gJgStateCounter = 0x14;
    }
}

void ReleaseJg(void) {
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    NNS_SndPlayerStopSeq(GetSndHandleSlot(4), 1);
    gJgKart = NULL;
}

#pragma thumb on
void InitJg(void) {
    Kart *kart;
    Vec3 *point;
    s32 pointIndex;
    Vec3 *sourcePoint;
    BOOL flag;

    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP) {
        gJgKart = NULL;
        return;
    }
    if (gRaceSetup->mEntryIndex < 0) {
        gJgKart = NULL;
        return;
    }
    gJgKartIndex = gRaceSetup->mEntryIndex;
    kart = GetKart(gJgKartIndex);
    gJgKart = kart;
    data_0217b8c0 = &kart->mKartModelsEntry->mCourseColorBlend.mColor;
    gJgTargetPos.x = 0;
    gJgTargetPos.y = 0;
    gJgTargetPos.z = 0;
    gJgProbeCenter = gJgTargetPos;
    gJgPreviousCollisionCenter = gJgProbeCenter;
    gJgCollisionCenter = gJgPreviousCollisionCenter;
    gJgPreviousPos = gJgCollisionCenter;
    gJgPos = gJgPreviousPos;
    gJgKartMove.x = 0;
    gJgKartMove.y = 0;
    gJgKartMove.z = 0;
    gJgVelocity.x = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    gJgProbeStep = 0;
    gJgShiftSpeedX = 0;
    gJgShiftX = 0;
    gJgHeightOffsetSpeed = 0;
    gJgHeightOffset = 0;
    gJgEasedPos = gJgPos;
    flag = TRUE;
    gJgInView = flag;
    gJgNearKart = flag;
    gJgState1AngleActive = 0;
    if (gCourseMap->mSettings->mStartSideFlipped != 0) {
        flag = FALSE;
    }
    gJgStartSideNotFlipped = flag;
    gJgKind = 4;
    gJgHighestLap = 1;
    gJgFinalLap = GetLapCount();
    InitJgOffsets();
    gJgPoints[0].x = 0;
    gJgPoints[0].y = 0;
    gJgPoints[0].z = 0;
    sourcePoint = data_02159440;
    for (pointIndex = 0; pointIndex < 7; pointIndex++) {
        point = &gJgPoints[pointIndex + 1];
        *point = *sourcePoint;
        if (gJgStartSideNotFlipped != 0) {
            point->x = -point->x;
            point->y = -point->y;
            point->z = -point->z;
        }
        sourcePoint++;
    }
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            gJgLapAndReverseEnabled = 0;
            break;
        case MODE_MISSION_RUN: {
            BOOL enabled;

            enabled = FALSE;
            if ((u8) (gRaceSetup->mMissionKind + 0xfe) <= 8 &&
                (0x115 & (1 << (u8) (gRaceSetup->mMissionKind + 0xfe))) != 0) {
                enabled = TRUE;
            }
            gJgLapAndReverseEnabled = enabled;
            break;
        }
        default:
            gJgLapAndReverseEnabled = 1;
            break;
    }
    switch (gRaceSetup->mEngineIndex) {
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
    data_0217b9dc.mFalloffIndex = 1;
    InitStateMachine(&gJgStateMachine, gJgStateTable, 7, NULL);
    SetStateMachineState(&gJgStateMachine, 0);
}

void CreateJg(void) {
    s32 angle;
    s32 rowIndex;
    s32 index;
    void *heap;
    JgKindFileNames *sourceRow;
    JgKindRow *kindRow;
    void *file;
    s32 light;
    s32 tableAngle;

    heap = GetHeap(GetCurrentHeapCall());
    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    InitNsbmdModel(&gJgMain, FindSceneFile(gJgMainNsbmdName), FindSceneFile(gJgMainNsbtpName), 0);
    SetNsbmdModelFixedAttributes(&gJgMain);
    gJgMain.mPolygonAttributes |= 0xc0;
    InitNsbmdModel(&gJgCloud, FindSceneFile(gJgCloudNsbmdName), NULL, 0);
    SetNsbmdModelFixedAttributes(&gJgCloud);
    gJgCloud.mPolygonAttributes |= 0xc0;
    data_0217b8a4 = HeapAlloc(heap, 0x78);
    data_0217b8a8 = HeapAlloc(heap, 0x78);
    data_0217b8a0 = HeapAlloc(heap, 0x78);
    data_0217b8e0 = HeapAlloc(heap, 0x78);
    data_0217b904 = HeapAlloc(heap, 0x78);
    for (index = 0, angle = 0; index < 0x3c; index++) {
        data_0217b8a4[index] = (u16) MUL_FIXED12_NO_ROUND(FX_SinIdx(angle), 0x4c);
        tableAngle = (u16) (((u64) (s64) SIN_OF_ANGLE((u16) (angle + 0xa218)) * 0xb60b60b60b + 0x80000000000) >> 44);
        data_0217b8a8[index] = SIN_OF_ANGLE(tableAngle);
        data_0217b8a0[index] = COS_OF_ANGLE(tableAngle);
        data_0217b8e0[index] = (u32) MUL_FIXED12_NO_ROUND(SIN_OF_ANGLE((u16) (angle + 0x1554)), 0x19a) + 0xe66;
        data_0217b904[index] = (u32) MUL_FIXED12_NO_ROUND(SIN_OF_ANGLE((u16) (angle + 0xbbb0)), 0x19a) + 0x119a;
        angle += 0x444;
    }
    gJgTableIndex = 0;
    light = 2;
    for (rowIndex = light, sourceRow = data_0216c324, kindRow = data_0217bb08; rowIndex < 4; rowIndex++) {
        if (sourceRow->mNsbmdName != NULL) {
            kindRow->mModel = HeapAlloc(heap, 0x6c);
            file = FindSceneFile(sourceRow->mNsbmdName);
            InitNsbmd(kindRow->mModel, file);
            SetNsbmdPolygonIdLightEmiAll(kindRow->mModel, 0x3f, light, 0x294a);
            SetNsbmdCullModeAll(kindRow->mModel, 3);
        } else {
            kindRow->mModel = NULL;
        }
        if (sourceRow->mNsbcaName != NULL) {
            kindRow->mNsbcaAnimation = HeapAlloc(heap, 0x38);
            InitModelAnimationWithEntries(0, kindRow->mModel, kindRow->mNsbcaAnimation, file,
                                          FindSceneFile(sourceRow->mNsbcaName));
            SetModelAnimationEntryLoopMode(kindRow->mNsbcaAnimation, 0, 1);
        } else {
            kindRow->mNsbcaAnimation = NULL;
        }
        if (sourceRow->mNsbmaName != NULL) {
            kindRow->mNsbmaAnimation = HeapAlloc(heap, 0x38);
            InitModelAnimationWithEntries(4, kindRow->mModel, kindRow->mNsbmaAnimation, file,
                                          FindSceneFile(sourceRow->mNsbmaName));
            SetModelAnimationEntryLoopMode(kindRow->mNsbmaAnimation, 0, 1);
        } else {
            kindRow->mNsbmaAnimation = NULL;
        }
        sourceRow++;
        kindRow++;
    }
    CreateNsbmdModel(&gJgKindRows[0].mLapModel, FindSceneFile(gLapCountNsbmdName), FindSceneFile(gLapCountNsbtpName),
                     0);
    SetNsbmdModelFixedAttributes(gJgKindRows[0].mLapModel);
    gJgKindRows[0].mLapModel->mPolygonAttributes |= 0xc0;
    CreateNsbmdModel(&gJgKindRows[1].mLapModel, FindSceneFile(gLapFinalNsbmdName), 0, 0);
    SetNsbmdModelFixedAttributes(gJgKindRows[1].mLapModel);
    gJgKindRows[1].mLapModel->mPolygonAttributes |= 0xc0;
}
#pragma thumb off

MapObjectKindData *CreateAttractorKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = gAttractorKindData;
    return kindData;
}

MapObjectList *CreateAttractorUpdateList(void) {
    MapObjectList *list;

    list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gAttractorUpdateList = list;
    *list = gAttractorUpdateListData;
    SetUpdateListSlot(&gAttractorUpdateList);
    return gAttractorUpdateList;
}

Vec3 *GetAttractorPosition(u32 index) {
    return gAttractorPositions[index];
}

u16 GetAttractorStrength(int index) {
    return gAttractorStrengths[index];
}

#pragma thumb on
void BuildAttractorTables(void) {
    AttractorMapObject *object;
    s32 objectCount;
    s32 objectIndex;

    objectCount = gAttractorUpdateList->mMapObjectCount;
    gAttractorPositions = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 4);
    gAttractorStrengths = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 2);
    for (objectIndex = 0; objectIndex < gAttractorUpdateList->mMapObjectCount; objectIndex++) {
        s32 tableIndex;

        object = gAttractorUpdateList->mMapObjects[objectIndex];
        tableIndex = object->mTableIndex;
        gAttractorPositions[tableIndex] = &object->mMapObject.mPos;
        gAttractorStrengths[tableIndex] = object->mStrength;
    }
}

void InitAttractorMapObject(AttractorMapObject *object, struct CourseMapRow *courseRow) {
    object->mTableIndex = courseRow->mSettings[0];
    switch (gRaceSetup->mEngineIndex) {
        case 0:
            object->mStrength = courseRow->mSettings[1];
            break;
        case 1:
            object->mStrength = courseRow->mSettings[2];
            break;
        case 2:
            object->mStrength = courseRow->mSettings[3];
            break;
    }
}
#pragma thumb off

void UpdateMapObjectSoundSource(MapObject *object) {
    MapObjectSound *sound;
    BOOL resultIsFalse;
    BOOL hasSoundBit0;

    sound = object->mSound;
    if ((object->mFlags & 2) == 0) {
        sound->mSoundSource.mDistanceSquared = object->mDistanceSquaredAndFlags & ~0xc000001f;
        resultIsFalse = (IsMapObjectOutOfRange(object) == FALSE);
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

        distanceSquared = GetHorizontalCameraDistanceSquared(&object->mPos);
        sound->mSoundSource.mDistanceSquared = distanceSquared;
        if (IsMapObjectOutOfRangeOrMaskedAtDistance(object, distanceSquared) != FALSE) {
            object->mDistanceSquaredAndFlags |= data_02159310;
            if ((sound->mSoundSource.mSourceFlags & 1) != 0) {
                SetSoundSourceFlagBit(&sound->mSoundSource, 2, 1);
            }
        } else if ((sound->mSoundSource.mSourceFlags & 1) == 0) {
            SetSoundSourceFlagBit(&sound->mSoundSource, 2, 1);
        }
    }
}

void UpdateMapObjectList(MapObjectList *list) {
    MapObject *object;
    Vec3 previousPos;
    void (*callback)(void *list, MapObject *object);
    s32 count;
    void **objects;

    callback = list->mForEachObject;
    count = list->mMapObjectCount;
    objects = list->mMapObjects;
    if (callback == NULL) {
        s32 objectIndex;

        for (objectIndex = 0; objectIndex < count; objectIndex++) {
            object = objects[objectIndex];
            if (object->mSound != NULL) {
                UpdateMapObjectSoundSource(object);
            }
        };
        return;
    }
    if (list->mPassOrPosStepMode == 2) {
        s32 objectIndex;

        for (objectIndex = 0; objectIndex < count; objectIndex++) {
            object = objects[objectIndex];
            if ((object->mFlags & 4) == 0) {
                previousPos = object->mPos;
                callback(list, object);
                VEC_Subtract(&object->mPos, &previousPos, &object->mPosStep);
                if (object->mSound != NULL) {
                    UpdateMapObjectSoundSource(object);
                }
            }
        };
        return;
    }
    {
        s32 objectIndex;

        for (objectIndex = 0; objectIndex < count; objectIndex++) {
            object = objects[objectIndex];
            if ((object->mFlags & 4) == 0) {
                callback(list, object);
                if (object->mSound != NULL) {
                    UpdateMapObjectSoundSource(object);
                }
            }
        }
    }
}

void CallMapObjectListCallback(MapObjectList *list) {
    MapObject *object;
    u8 callbackArgs[2];
    s32 objectIndex;
    s32 count;
    void **objects;
    s32 (*callback)(MapObject *, void *, void *, void *);

    count = list->mMapObjectCount;
    callback = list->mUnk_1c;
    objects = list->mMapObjects;
    callbackArgs[0] = list->mItemFirstResponse;
    callbackArgs[1] = 0;
    if (callback == NULL) {
        return;
    }
    for (objectIndex = 0; objectIndex < count; objectIndex++) {
        object = objects[objectIndex];
        if ((object->mFlags & 0x88) == 0) {
            callback(object, NULL, &callbackArgs[0], &callbackArgs[1]);
        }
    }
}
