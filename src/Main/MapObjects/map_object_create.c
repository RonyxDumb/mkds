#include "Main/MapObjects/map_object_create.h"
#include "Main/System/heap.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Race/race.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/map_objects_work.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/group_paths.h"
#include "Main/MapObjects/koopa_block_hit_link.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "Main/Item/bouncing_item_box.h"
#include "Main/Item/pooled_item_box.h"
#include "Main/MapObjects/rotary.h"
#include "Main/MapObjects/bridge.h"
#include "Main/Item/dram_box.h"
#include "Main/MapObjects/view_matrices.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/MapObjects/map_object_list_count.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/MapObjects/koopa_block.h"
#include "Main/MapObjects/water.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"
#include "Main/MapObjects/course_collision_data.h"

u16 gMapObjectLastPolygonId;
u16 gWrappingPolygonIdBase;
u16 gNextPolygonId;
u16 gWrappingPolygonId;
u16 gMapObjectFirstPolygonId;
s32 gMapObjectsTimeAttackOrWiFi;
GrpconfTblRow *gGrpconfTbl;
struct MapObjects *gMapObjects;
s32 gMapObjectKindCount;
MapObject **gFoundMapObjects;
struct Water *gCourseWater;
Vec3 *gFoundMapObjectVectors;
WaterEfct *gCourseWaterEfct;

#pragma thumb on

static inline GrpconfTblRow *FindGrpconfTblRowByKind(u16 kind) {
    s32 rowIndex;
    for (rowIndex = 0; rowIndex < 1000; rowIndex++) {
        if (kind == gGrpconfTbl[rowIndex].mKind) {
            return &gGrpconfTbl[rowIndex];
        }
    }
    return NULL;
}

// Map objects the game can hold at once, and the most one area query can return.
#define MAP_OBJECT_CAPACITY 0x100
#define FOUND_MAP_OBJECT_CAPACITY 0x20

MapObject *CreateMapObject(u32 kind, CourseMapRow *courseRow, MapObject *source) {
    s32 kindIndex;
    s32 index;
    MapObjectKindRow *row;
    MapObjectKindDescriptor *descriptor;
    MapObjectKindDescriptor *otherDescriptor;
    MapObjectKindData *kindData;
    GrpconfTblRow *grpconfRow;
    MapObject *object;
    s32 tableValue;
    u32 slotFlags;
    for (kindIndex = 0; kindIndex < gMapObjectKindCount; kindIndex++) {
        {
            row = &gMapObjectKindRows[kindIndex];
            if (kind != row->mKind) {
                continue;
            }
            descriptor = row->mDescriptor;
            if (descriptor->mObjectCount == 0) {
                for (index = 0; index < gMapObjectKindCount; index++) {
                    otherDescriptor = gMapObjectKindRows[index].mDescriptor;
                    if (otherDescriptor == NULL) {
                        continue;
                    }
                    if (otherDescriptor->mCreateDrawList0 == descriptor->mCreateDrawList0 &&
                        otherDescriptor->mLists[0] != NULL) {
                        descriptor->mLists[0] = otherDescriptor->mLists[0];
                    }
                    if (otherDescriptor->mCreateDrawList0 == descriptor->mCreateDrawList1 &&
                        otherDescriptor->mLists[0] != NULL) {
                        descriptor->mLists[1] = otherDescriptor->mLists[0];
                    }
                    if (otherDescriptor->mCreateDrawList0 == descriptor->mCreateDrawList2 &&
                        otherDescriptor->mLists[0] != NULL) {
                        descriptor->mLists[2] = otherDescriptor->mLists[0];
                    }
                    if (otherDescriptor->mCreateDrawList1 == descriptor->mCreateDrawList0 &&
                        otherDescriptor->mLists[1] != NULL) {
                        descriptor->mLists[0] = otherDescriptor->mLists[1];
                    }
                    if (otherDescriptor->mCreateDrawList1 == descriptor->mCreateDrawList1 &&
                        otherDescriptor->mLists[1] != NULL) {
                        descriptor->mLists[1] = otherDescriptor->mLists[1];
                    }
                    if (otherDescriptor->mCreateDrawList1 == descriptor->mCreateDrawList2 &&
                        otherDescriptor->mLists[1] != NULL) {
                        descriptor->mLists[2] = otherDescriptor->mLists[1];
                    }
                    if (otherDescriptor->mCreateDrawList2 == descriptor->mCreateDrawList0 &&
                        otherDescriptor->mLists[2] != NULL) {
                        descriptor->mLists[0] = otherDescriptor->mLists[2];
                    }
                    if (otherDescriptor->mCreateDrawList2 == descriptor->mCreateDrawList1 &&
                        otherDescriptor->mLists[2] != NULL) {
                        descriptor->mLists[1] = otherDescriptor->mLists[2];
                    }
                    if (otherDescriptor->mCreateDrawList2 == descriptor->mCreateDrawList2 &&
                        otherDescriptor->mLists[2] != NULL) {
                        descriptor->mLists[2] = otherDescriptor->mLists[2];
                    }
                    if (otherDescriptor->mCreateUpdateList == descriptor->mCreateUpdateList &&
                        otherDescriptor->mLists[3] != NULL) {
                        descriptor->mLists[3] = otherDescriptor->mLists[3];
                    }
                }
                if (descriptor->mKindData == NULL && descriptor->mCreateKindData != NULL) {
                    descriptor->mKindData = descriptor->mCreateKindData();
                    if (descriptor->mKindData == NULL) {
                        return NULL;
                    }
                    if (descriptor->mKindData->mSoundId == 0) {
                        descriptor->mKindData->mSoundId = -1;
                    }
                    if (descriptor->mKindData->mCollideItemObjectSoundId == 0) {
                        descriptor->mKindData->mCollideItemObjectSoundId = -1;
                    }
                    if (descriptor->mKindData->mHeightRangeMax == 0) {
                        descriptor->mKindData->mHeightRangeMax = MAP_OBJECT_HEIGHT_RANGE_DEFAULT;
                    }
                    if (descriptor->mKindData->mHeightRangeMin == 0) {
                        descriptor->mKindData->mHeightRangeMin = -MAP_OBJECT_HEIGHT_RANGE_DEFAULT;
                    }
                    if (gRaceSetup->mRaceKind == RACE_KIND_REPLAY) {
                        if (descriptor->mKindData->mHeightRangeMax < MAP_OBJECT_HEIGHT_RANGE_REPLAY_MAX) {
                            descriptor->mKindData->mHeightRangeMax = MAP_OBJECT_HEIGHT_RANGE_REPLAY_MAX;
                        }
                    }
                }
                grpconfRow = FindGrpconfTblRowByKind(row->mKind);
                if (grpconfRow->mViewTestKind != 0) {
                    descriptor->mKindData->mUseTwoPlaneViewTest =
                        grpconfRow->mViewTestKind >= MAP_OBJECT_VIEW_TEST_KIND_PAIRED_PLANES ? 1 : 0;
                    tableValue = grpconfRow->mViewRadius;
                    descriptor->mKindData->mViewRadius =
                        tableValue != 0 ? TO_FIXED12(tableValue) + 0.5f : TO_FIXED12(tableValue) - 0.5f;
                    tableValue = grpconfRow->mDrawDistance;
                    descriptor->mKindData->mDrawDistance =
                        tableValue != 0 ? TO_FIXED12(tableValue) + 0.5f : TO_FIXED12(tableValue) - 0.5f;
                }
                if (grpconfRow->mShapeKind != MAP_OBJECT_SHAPE_NONE) {
                    descriptor->mKindData->mShapeKind = grpconfRow->mShapeKind;
                    tableValue = grpconfRow->mExtentX;
                    descriptor->mKindData->mExtentX =
                        tableValue != 0 ? TO_FIXED12(tableValue) + 0.5f : TO_FIXED12(tableValue) - 0.5f;
                    tableValue = grpconfRow->mExtentY;
                    descriptor->mKindData->mExtentY =
                        tableValue != 0 ? TO_FIXED12(tableValue) + 0.5f : TO_FIXED12(tableValue) - 0.5f;
                    tableValue = grpconfRow->mExtentZ;
                    descriptor->mKindData->mExtentZ =
                        tableValue != 0 ? TO_FIXED12(tableValue) + 0.5f : TO_FIXED12(tableValue) - 0.5f;
                }
                if (descriptor->mLists[0] == NULL && descriptor->mCreateDrawList0 != NULL) {
                    descriptor->mLists[0] = descriptor->mCreateDrawList0();
                }
                if (descriptor->mLists[1] == NULL && descriptor->mCreateDrawList1 != NULL) {
                    descriptor->mLists[1] = descriptor->mCreateDrawList1();
                }
                if (descriptor->mLists[2] == NULL && descriptor->mCreateDrawList2 != NULL) {
                    descriptor->mLists[2] = descriptor->mCreateDrawList2();
                }
                if (descriptor->mLists[3] == NULL && descriptor->mCreateUpdateList != NULL) {
                    descriptor->mLists[3] = descriptor->mCreateUpdateList();
                }
            }
            if (descriptor == NULL) {
                continue;
            }
            kindData = descriptor->mKindData;
            object = HeapAlloc(GetHeap(GetCurrentHeapCall()), descriptor->mObjectSize);
            descriptor->mObjectCount++;
            if (courseRow != NULL) {
                object->mCourseMapRow = courseRow;
            } else if (source != NULL) {
                object->mCourseMapRow = source->mCourseMapRow;
            }
            object->mKind = kind;
            object->mFlags = 0;
            if (gMapObjectsTimeAttackOrWiFi != 0) {
                object->mFlags |= gMapObjectTimeAttackOrWiFiFlag;
            }
            object->mCollisionSlotIndex = -1;
            if (courseRow != NULL) {
                object->mPos.x = courseRow->mPosition.x;
                object->mPos.y = courseRow->mPosition.y;
                object->mPos.z = courseRow->mPosition.z;
            } else if (source != NULL) {
                object->mPos.x = source->mPos.x;
                object->mPos.y = source->mPos.y;
                object->mPos.z = source->mPos.z;
            }
            if (kindData->mPosStepMode == 0 || kindData->mPosStepMode == MAP_OBJECT_LIST_POS_STEP_MEASURED) {
                object->mPosStep.x = 0;
                object->mPosStep.y = 0;
                object->mPosStep.z = 0;
            } else {
                object->mPosStep.x = MAP_OBJECT_FAR_VALUE;
                object->mPosStep.y = MAP_OBJECT_FAR_VALUE;
                object->mPosStep.z = MAP_OBJECT_FAR_VALUE;
            }
            if (courseRow != NULL) {
                object->mAngle = DEG_TO_ANGLE(courseRow->mRotationDegrees.y);
                Matrix3x3FromVec3Degrees(&courseRow->mRotationDegrees, &object->mMatrix.mAxes);
            } else if (source != NULL) {
                object->mAngle = source->mAngle;
                object->mMatrix = source->mMatrix;
            }
            object->mKindData = kindData;
            if (courseRow != NULL) {
                SetMapObjectScale(object, &courseRow->mScale);
            } else {
                SetMapObjectScale(object, &source->mScale);
            }
            SetMapObjectDrawDistance(object, kindData->mDrawDistance);
            object->mUseTwoPlaneViewTest = kindData->mUseTwoPlaneViewTest;
            if (kindData->mShapeKind != MAP_OBJECT_SHAPE_NONE) {
                object->mFlags &= ~1;
            } else {
                object->mFlags |= gMapObjectNoShapeFlag;
            }
            if (kindData->mCollidable != 0) {
                object->mFlags &= ~0x40;
            } else {
                object->mFlags |= gMapObjectNotCollidableFlag;
            }
            if ((descriptor->mLists[0] != NULL && descriptor->mLists[0]->mForEachObject != NULL) ||
                (descriptor->mLists[1] != NULL && descriptor->mLists[1]->mForEachObject != NULL) ||
                (descriptor->mLists[2] != NULL && descriptor->mLists[2]->mForEachObject != NULL)) {
                object->mFlags &= ~2;
                object->mFlags &= ~8;
                object->mAlpha = MAP_OBJECT_ALPHA_MAX;
            } else {
                object->mFlags |= gMapObjectNoDrawListFlag;
                object->mFlags |= gMapObjectNoDrawListSecondFlag;
            }
            if (source != NULL) {
                object->mDigitMask = source->mDigitMask;
                object->mFlags |= source->mFlags & MAP_OBJECT_FLAG_NUMBER_OVERFLOW;
            } else if (courseRow != NULL) {
                if (courseRow->mSettings[7] != 0) {
                    SetMapObjectMaskAndFlagFromNumber(courseRow->mSettings[7], object);
                }
            }
            if (descriptor->mLists[3] != NULL && descriptor->mLists[3]->mForEachObject != NULL) {
                object->mFlags &= ~4;
            } else {
                object->mFlags |= gMapObjectNoUpdateListFlag;
            }
            object->mFarDistanceSquared = gSoundFalloffs[2].mFarDistanceSquared;
            if (courseRow != NULL) {
                if (descriptor->mInitObject != NULL) {
                    descriptor->mInitObject(object, courseRow, gMapObjectKindRows[kindIndex].mInitData);
                }
            } else if (source != NULL) {
                if (descriptor->mInitObject != NULL) {
                    descriptor->mInitObject(object, NULL, source);
                }
            }
            if (kindData->mShapeKind != MAP_OBJECT_SHAPE_NONE) {
                slotFlags = COLLISION_SLOT_FLAG_MAP_OBJECT;
                if (kindData->mPosStepMode == 0) {
                    slotFlags |= gCollisionSlotPosStepFlag;
                }
                if (IsKoopaBlockKind(object->mKind) != 0 || IsRotaryKind(object->mKind) != FALSE ||
                    IsBridgeKind(object->mKind) != FALSE || IsMissionRunBoxKind(object->mKind) != FALSE) {
                    slotFlags |= gCollisionSlotKindFlag;
                }
                object->mCollisionSlotIndex =
                    CreateCollisionSlot(&object->mPos, GetMapObjectCollisionRadius(object), slotFlags, object);
            }
            index = gMapObjects->mMapObjectCount;
            gMapObjects->mMapObjectCount = index + 1;
            gMapObjects->mMapObjects[index] = object;
            if (gMapObjects->mMapObjectCount >= MAP_OBJECT_CAPACITY) {
                gMapObjects->mMapObjectCount = MAP_OBJECT_CAPACITY - 1;
            }
            return object;
        }
    }
    return NULL;
}

MapObject *CreateMapObjectFromObject(MapObject *source, s32 kind) {
    return CreateMapObject(kind, NULL, source);
}

MapObject *CreateMapObjectFromCourseMapRow(CourseMapRow *courseRow, s32 kind) {
    return CreateMapObject(kind, courseRow, NULL);
}

void InitMapObjects(void) {
    void *heap;
    s32 index;
    s32 count;
    s32 innerIndex;
    s32 slotIndex;
    s32 firstCount;
    s32 secondCount;
    s32 firstIndex;
    s32 secondIndex;
    s32 listIndex;
    s32 drawListIndex;
    s32 isNewList;
    u32 value;
    MapObjectKindRow *row;
    MapObjectKindDescriptor *descriptor;
    CourseMapRow *courseRow;
    MapObject *mapObject;
    MapObjectList *kindLists[3];
    MapObjectList *list;
    MapObjectList **listArray;
    MapObjects *mapObjects;
    heap = GetHeap(GetCurrentHeapCall());
    SetRaceRandomPointers();
    gMapObjectFirstPolygonId = GetMapObjectFirstPolygonId();
    gMapObjectLastPolygonId = gMapObjectFirstPolygonId + 9;
    gWrappingPolygonIdBase = gMapObjectLastPolygonId + 1;
    count = gCourseMap->mRowCount;
    gMapObjects = HeapAlloc(heap, sizeof(*gMapObjects));
    gMapObjects->mMapObjects = HeapAlloc(heap, MAP_OBJECT_CAPACITY * sizeof(*gMapObjects->mMapObjects));
    gFoundMapObjects = HeapAlloc(heap, FOUND_MAP_OBJECT_CAPACITY * sizeof(*gFoundMapObjects));
    gFoundMapObjectVectors = HeapAlloc(heap, FOUND_MAP_OBJECT_CAPACITY * sizeof(*gFoundMapObjectVectors));
    gMapObjects->mMapObjectCount = 0;
    gMapObjects->mDrawListsBuilt = FALSE;
    gMapObjects->mUpdateListsBuilt = FALSE;
    value = 0;
    if (gRaceSetup->mMode != MODE_WIFI) {
        value = 1;
    }
    gMapObjects->mRunUpdateLists = value;
    gMapObjectKindCount = 0;
    do {
        row = &gMapObjectKindRows[gMapObjectKindCount];
        descriptor = row->mDescriptor;
        if (row->mKind == 0) {
            break;
        }
        if (gOverlayLoader->mCurrentOverlay != OVERLAY_SLOT_OV001 && IsInOverlayRange(descriptor) != 0) {
            break;
        }
        if (descriptor != NULL) {
            descriptor->mKindData = NULL;
            descriptor->mLists[0] = NULL;
            descriptor->mLists[1] = NULL;
            descriptor->mLists[2] = NULL;
            descriptor->mLists[3] = NULL;
        }
        gMapObjectKindCount++;
    } while (gMapObjectKindCount < 0x85);
    gGrpconfTbl = FindMainRaceOrMainEffectFile("MapObj/grpconf.tbl");
    value = 1;
    if (gRaceSetup->mMode != MODE_TIME_ATTACK && gRaceSetup->mMode != MODE_WIFI) {
        value = 0;
    }
    gMapObjectsTimeAttackOrWiFi = value;
    gMapObjects->mHasKoopaBlock = 0;
    gMapObjects->mHasRotary = 0;
    gMapObjects->mHasBridge = 0;
    gMapObjects->mHasMissionRunBox = 0;
    gCourseWater = NULL;
    gCourseWaterEfct = NULL;
    ClearOrthoQuadCreamEffectPointer();
    InitGroupPaths();
    InitMatrices();
    InitMapObjectViewState();
    gWrappingPolygonId = gWrappingPolygonIdBase;
    gNextPolygonId = gMapObjectFirstPolygonId;
    for (index = 0; index < gMapObjectKindCount; index++) {
        if (gMapObjectKindRows[index].mDescriptor != NULL) {
            gMapObjectKindRows[index].mDescriptor->mObjectCount = 0;
        }
    }
    for (index = 0; index < count; index++) {
        courseRow = OFFSET_PTR(CourseMapRow, gCourseMap->mRows, index * sizeof(CourseMapRow));
        if (gRaceSetup->mMode == MODE_TIME_ATTACK && (courseRow->mTimeAttackFlags & 1) == 0) {
            continue;
        }
        CreateMapObject(courseRow->mKind, courseRow, NULL);
        gMapObjects->mHasKoopaBlock |= IsKoopaBlockKind(courseRow->mKind);
        gMapObjects->mHasRotary |= IsRotaryKind(courseRow->mKind);
        gMapObjects->mHasBridge |= IsBridgeKind(courseRow->mKind);
        gMapObjects->mHasMissionRunBox |= IsMissionRunBoxKind(courseRow->mKind);
    }
    if (gMapObjects->mHasKoopaBlock != 0 || gMapObjects->mHasRotary != 0 || gMapObjects->mHasBridge != 0 ||
        gMapObjects->mHasMissionRunBox != 0) {
        gSearchCollisionSlots = 1;
    }
    CreatePooledMapObjects();
    gMapObjects->mDrawListCount = 0;
    for (slotIndex = 0; slotIndex < 24; slotIndex++) {
        gMapObjects->mDrawLists[slotIndex] = NULL;
    }
    for (index = 0; index < gMapObjectKindCount; index++) {
        if (gMapObjectKindRows[index].mDescriptor == NULL) {
            continue;
        }
        value = gMapObjectKindRows[index].mDescriptor->mObjectCount;
        kindLists[0] = gMapObjectKindRows[index].mDescriptor->mLists[0];
        kindLists[1] = gMapObjectKindRows[index].mDescriptor->mLists[1];
        kindLists[2] = gMapObjectKindRows[index].mDescriptor->mLists[2];
        for (innerIndex = 0; innerIndex < 3; innerIndex++) {
            s32 isNewList;
            if (kindLists[innerIndex] == NULL) {
                continue;
            }
            isNewList = 1;
            for (slotIndex = 0; slotIndex < gMapObjects->mDrawListCount; slotIndex++) {
                if (gMapObjects->mDrawLists[slotIndex] == kindLists[innerIndex]) {
                    DrawListAddToMapObjectListCount(kindLists[innerIndex], value);
                    isNewList = 0;
                }
            }
            if (isNewList != 0) {
                ClearMapObjectList(kindLists[innerIndex]);
                if (value != 0) {
                    DrawListAddToMapObjectListCount(kindLists[innerIndex], value);
                    gMapObjects->mDrawLists[gMapObjects->mDrawListCount++] = kindLists[innerIndex];
                }
            }
        }
    }
    for (index = 0; index < gMapObjects->mDrawListCount; index++) {
        InitMapObjectDrawList(gMapObjects->mDrawLists[index]);
    }
    for (index = 0; index < gMapObjects->mMapObjectCount; index++) {
        mapObject = gMapObjects->mMapObjects[index];
        for (innerIndex = 0; innerIndex < gMapObjectKindCount; innerIndex++) {
            if (mapObject->mKind == gMapObjectKindRows[innerIndex].mKind) {
                kindLists[0] = gMapObjectKindRows[innerIndex].mDescriptor->mLists[0];
                kindLists[1] = gMapObjectKindRows[innerIndex].mDescriptor->mLists[1];
                kindLists[2] = gMapObjectKindRows[innerIndex].mDescriptor->mLists[2];
                if (kindLists[0] != NULL) {
                    AddMapObjectToDrawList(kindLists[0], mapObject);
                }
                if (kindLists[1] != NULL) {
                    AddMapObjectToDrawList(kindLists[1], mapObject);
                }
                if (kindLists[2] != NULL) {
                    AddMapObjectToDrawList(kindLists[2], mapObject);
                }
            }
        }
    }
    for (index = 0; index < gMapObjects->mDrawListCount; index++) {
        InitMapObjectDrawOrder(gMapObjects->mDrawLists[index]);
    }
    gMapObjects->mDrawListsBuilt = TRUE;
    RunMapObjectDrawListInits();
    count = gMapObjects->mDrawListCount;
    firstCount = 0;
    secondCount = 0;
    firstIndex = 0;
    secondIndex = 0;
    for (drawListIndex = 0; drawListIndex < count; drawListIndex++) {
        list = gMapObjects->mDrawLists[drawListIndex];
        if (list->mItemFirstResponse != 0) {
            if (list->mPassOrPosStepMode == MAP_OBJECT_LIST_PASS_FIRST) {
                firstCount++;
            } else if (list->mPassOrPosStepMode == MAP_OBJECT_LIST_PASS_SECOND) {
                secondCount++;
            }
        }
    }
    slotIndex = 0;
    for (index = 0; index < count; index++) {
        list = gMapObjects->mDrawLists[index];
        if (list->mPassOrPosStepMode == MAP_OBJECT_LIST_PASS_FIRST) {
            listArray = gMapObjects->mFirstPassDrawLists;
            gMapObjects->mFirstPassDrawListCount++;
            if (list->mItemFirstResponse != 0) {
                listIndex = firstIndex++;
            } else {
                listIndex = firstCount++;
            }
        } else if (list->mPassOrPosStepMode == MAP_OBJECT_LIST_PASS_SECOND) {
            listArray = gMapObjects->mSecondPassDrawLists;
            gMapObjects->mSecondPassDrawListCount++;
            if (list->mItemFirstResponse != 0) {
                listIndex = secondIndex++;
            } else {
                listIndex = secondCount++;
            }
        }
        listArray[listIndex] = list;
    }
    gMapObjects->mUpdateListCount = 0;
    for (index = 0; index < 16; index++) {
        gMapObjects->mUpdateLists[index] = NULL;
    }
    for (index = 0; index < gMapObjectKindCount; index++) {
        if (gMapObjectKindRows[index].mDescriptor == NULL) {
            continue;
        }
        value = gMapObjectKindRows[index].mDescriptor->mObjectCount;
        list = gMapObjectKindRows[index].mDescriptor->mLists[3];
        if (list == NULL) {
            continue;
        }
        isNewList = 1;
        for (innerIndex = 0; innerIndex < gMapObjects->mUpdateListCount; innerIndex++) {
            if (gMapObjects->mUpdateLists[innerIndex] == list) {
                AddToMapObjectListCount(list, value);
                isNewList = 0;
            }
        }
        if (isNewList != 0) {
            ClearMapObjectListCount(list);
            if (value != 0) {
                AddToMapObjectListCount(list, value);
                gMapObjects->mUpdateLists[gMapObjects->mUpdateListCount++] = list;
            }
        }
    }
    for (index = 0; index < gMapObjects->mUpdateListCount; index++) {
        InitMapObjectUpdateList(gMapObjects->mUpdateLists[index]);
    }
    for (index = 0; index < gMapObjects->mMapObjectCount; index++) {
        mapObject = gMapObjects->mMapObjects[index];
        for (innerIndex = 0; innerIndex < gMapObjectKindCount; innerIndex++) {
            if (mapObject->mKind == gMapObjectKindRows[innerIndex].mKind &&
                gMapObjectKindRows[innerIndex].mDescriptor->mLists[3] != NULL) {
                AddMapObjectToUpdateList(gMapObjectKindRows[innerIndex].mDescriptor->mLists[3], mapObject);
            }
        }
    }
    gMapObjects->mUpdateListsBuilt = TRUE;
    RunMapObjectUpdateListInits();
}

void RunMapObjectDrawListInits(void) {
    s32 listIndex;
    s32 drawListCount;
    MapObjectList **listCursor;
    drawListCount = gMapObjects->mDrawListCount;
    listCursor = gMapObjects->mDrawLists;
    if (gCourseWater != NULL) {
        InitWaterModels(gCourseWater);
    }
    CreateObjShadowAndJgShadow();
    for (listIndex = 0; listIndex < drawListCount; listCursor++, listIndex++) {
        if ((*listCursor)->mInit != NULL) {
            (*listCursor)->mInit(*listCursor);
        }
    }
}

void RunMapObjectUpdateListInits(void) {
    s32 listIndex;
    s32 updateListCount;
    MapObjectList **listCursor;
    updateListCount = gMapObjects->mUpdateListCount;
    listCursor = gMapObjects->mUpdateLists;
    for (listIndex = 0; listIndex < updateListCount; listCursor++, listIndex++) {
        if ((*listCursor)->mInit != NULL) {
            (*listCursor)->mInit(*listCursor);
        }
    }
}

#pragma thumb off

const u16 gMapObjectNoUpdateListFlag = 4;
const u16 gMapObjectNotCollidableFlag = 0x40;
const u16 gMapObjectTimeAttackOrWiFiFlag = 0x800;
const u16 gCollisionSlotPosStepFlag = 0x400;
const u16 gMapObjectNoDrawListFlag = 2;
const u16 gMapObjectNoDrawListSecondFlag = 8;
const u16 gMapObjectNoShapeFlag = 1;
const u16 gCollisionSlotKindFlag = 0x1000;
