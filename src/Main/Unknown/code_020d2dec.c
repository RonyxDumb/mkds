#include "Main/Unknown/code_020d2dec.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3ae0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d4a10.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02103598.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020ff344.h"
#include "Main/Unknown/code_020e662c.h"
#include "Main/Unknown/code_020e6f58.h"
#include "Main/Unknown/code_020d49e0.h"
#include "Main/Unknown/code_020d4a18.h"
#include "Main/Unknown/code_020e6f9c.h"
#include "Main/Unknown/code_020e6fc4.h"
#include "Main/Unknown/code_020d4bf0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020df890.h"
#include "Main/Course/WaterEfct.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline GrpconfTblRow *func_020d34e4_inline(u16 kind) {
    s32 j;
    for (j = 0; j < 1000; j++) {
        if (kind == mobj_sGrpconfTbl[j].field0) {
            return &mobj_sGrpconfTbl[j];
        }
    }
    return NULL;
}

MapObject *mobj_createObject(u32 kind, CourseMapRow *courseRow, MapObject *source) {
    s32 i;
    s32 j;
    MapObjectKindRow *row;
    MapObjectKindDescriptor *descriptor;
    MapObjectKindDescriptor *otherDescriptor;
    MapObjectKindData *kindData;
    GrpconfTblRow *grpconfRow;
    MapObject *object;
    s32 tableValue;
    u32 slotFlags;
    for (i = 0; i < mobj_sAvailableObjectCount; i++) {
        {
            row = &gMapObjTable[i];
            if (kind != row->mKind) {
                continue;
            }
            descriptor = row->field4;
            if (descriptor->mObjectCount == 0) {
                for (j = 0; j < mobj_sAvailableObjectCount; j++) {
                    otherDescriptor = gMapObjTable[j].field4;
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
                    if (descriptor->mKindData->field24 == 0) {
                        descriptor->mKindData->field24 = -1;
                    }
                    if (descriptor->mKindData->field28 == 0) {
                        descriptor->mKindData->field28 = -1;
                    }
                    if (descriptor->mKindData->field38 == 0) {
                        descriptor->mKindData->field38 = 0x64000;
                    }
                    if (descriptor->mKindData->field3C == 0) {
                        descriptor->mKindData->field3C = -0x64000;
                    }
                    if (gRaceMultiConfig->mRaceKind == 2) {
                        if (descriptor->mKindData->field38 < 0x44c000) {
                            descriptor->mKindData->field38 = 0x44c000;
                        }
                    }
                }
                grpconfRow = func_020d34e4_inline(row->mKind);
                if (grpconfRow->field2 != 0) {
                    descriptor->mKindData->field34 = grpconfRow->field2 >= 2 ? 1 : 0;
                    tableValue = grpconfRow->field4;
                    descriptor->mKindData->field2C =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
                    tableValue = grpconfRow->field6;
                    descriptor->mKindData->field30 =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
                }
                if (grpconfRow->field8 != 0) {
                    descriptor->mKindData->mShapeKind = grpconfRow->field8;
                    tableValue = grpconfRow->fieldA;
                    descriptor->mKindData->fieldC =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
                    tableValue = grpconfRow->fieldC;
                    descriptor->mKindData->field10 =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
                    tableValue = grpconfRow->fieldE;
                    descriptor->mKindData->field14 =
                        tableValue != 0 ? (tableValue << 12) + 0.5f : (tableValue << 12) - 0.5f;
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
            object = heap_alloc(proc_getHeap(proc_getCurrent()), descriptor->mObjectSize);
            descriptor->mObjectCount++;
            if (courseRow != NULL) {
                object->mCourseMapRow = courseRow;
            } else if (source != NULL) {
                object->mCourseMapRow = source->mCourseMapRow;
            }
            object->mKind = kind;
            object->mFlags = 0;
            if (mobj_sUseSimpleHitResponses != 0) {
                object->mFlags |= data_021568c8;
            }
            object->mCollisionSlotIndex = -1;
            if (courseRow != NULL) {
                object->mPos.x = courseRow->field0.x;
                object->mPos.y = courseRow->field0.y;
                object->mPos.z = courseRow->field0.z;
            } else if (source != NULL) {
                object->mPos.x = source->mPos.x;
                object->mPos.y = source->mPos.y;
                object->mPos.z = source->mPos.z;
            }
            if (kindData->field20 == 0 || kindData->field20 == 2) {
                object->field10.x = 0;
                object->field10.y = 0;
                object->field10.z = 0;
            } else {
                object->field10.x = 0x270f000;
                object->field10.y = 0x270f000;
                object->field10.z = 0x270f000;
            }
            if (courseRow != NULL) {
                object->mAngle = ((s64) courseRow->fieldC.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44;
                mtx_eulerAnglesToMtx33(&courseRow->fieldC, (s32 *) &object->mMatrix);
            } else if (source != NULL) {
                object->mAngle = source->mAngle;
                object->mMatrix = source->mMatrix;
            }
            object->mKindData = kindData;
            if (courseRow != NULL) {
                mobj_setScale(object, &courseRow->field18);
            } else {
                mobj_setScale(object, &source->mScale);
            }
            mobj_setFarClip(object, kindData->field30);
            object->mUseTwoPlaneViewTest = kindData->field34;
            if (kindData->mShapeKind != 0) {
                object->mFlags &= ~1;
            } else {
                object->mFlags |= data_021568cc;
            }
            if (kindData->field1C != 0) {
                object->mFlags &= ~0x40;
            } else {
                object->mFlags |= data_021568d0;
            }
            if ((descriptor->mLists[0] != NULL && descriptor->mLists[0]->mForEachObject != NULL) ||
                (descriptor->mLists[1] != NULL && descriptor->mLists[1]->mForEachObject != NULL) ||
                (descriptor->mLists[2] != NULL && descriptor->mLists[2]->mForEachObject != NULL)) {
                object->mFlags &= ~2;
                object->mFlags &= ~8;
                object->mAlpha = 0x1f;
            } else {
                object->mFlags |= data_021568d4;
                object->mFlags |= data_021568d8;
            }
            if (source != NULL) {
                object->mDigitMask = source->mDigitMask;
                object->mFlags |= source->mFlags & 0x80;
            } else if (courseRow != NULL) {
                if (courseRow->field36 != 0) {
                    mobj_parseObjiFlags(courseRow->field36, object);
                }
            }
            if (descriptor->mLists[3] != NULL && descriptor->mLists[3]->mForEachObject != NULL) {
                object->mFlags &= ~4;
            } else {
                object->mFlags |= data_021568dc;
            }
            object->mFarDistanceSquared = gSfxParams[2].field20;
            if (courseRow != NULL) {
                if (descriptor->mInitObject != NULL) {
                    descriptor->mInitObject(object, courseRow, gMapObjTable[i].field8);
                }
            } else if (source != NULL) {
                if (descriptor->mInitObject != NULL) {
                    descriptor->mInitObject(object, NULL, source);
                }
            }
            if (kindData->mShapeKind != 0) {
                slotFlags = 0x2000;
                if (kindData->field20 == 0) {
                    slotFlags |= data_021568e0;
                }
                if (kblock_isKoopaBlock(object->mKind) != 0 || rotcyl_isRotatingCylinder(object->mKind) != FALSE ||
                    bridge_isBridge(object->mKind) != FALSE || IsWall(object->mKind) != FALSE) {
                    slotFlags |= data_021568e4;
                }
                object->mCollisionSlotIndex =
                    col_createColEntry(&object->mPos, mobj_getBoundingSphereSize(object), slotFlags, object);
            }
            j = gMapObjState->mMapObjectCount;
            gMapObjState->mMapObjectCount = j + 1;
            gMapObjState->mMapObjects[j] = object;
            if (gMapObjState->mMapObjectCount >= 0x100) {
                gMapObjState->mMapObjectCount = 0xff;
            }
            return object;
        }
    }
    return NULL;
}

MapObject *mobj_createSubObject(MapObject *source, s32 kind) {
    return mobj_createObject(kind, NULL, source);
}

MapObject *mobj_createObjectFromObji(CourseMapRow *courseRow, s32 kind) {
    return mobj_createObject(kind, courseRow, NULL);
}

void mobj_init(void) {
    void *heap;
    s32 i;
    s32 n;
    s32 j;
    s32 m;
    s32 c1;
    s32 c2;
    s32 s1;
    s32 s2;
    s32 listIndex;
    s32 t;
    s32 isNewList;
    u32 v;
    MapObjectKindRow *row;
    MapObjectKindDescriptor *descriptor;
    CourseMapRow *courseRow;
    MapObject *mapObject;
    MapObjectList *kindLists[3];
    MapObjectList *list;
    MapObjectList **listArray;
    MapObjects *q;
    heap = proc_getHeap(proc_getCurrent());
    mobj_initRng();
    mobj_sMinStaticPolygonId = race_getFirstObjectPolygonId();
    mobj_sMaxStaticPolygonId = mobj_sMinStaticPolygonId + 9;
    mobj_sMinCyclicPolygonId = mobj_sMaxStaticPolygonId + 1;
    n = gMapData->mRowCount;
    gMapObjState = heap_alloc(heap, 0x2bc);
    gMapObjState->mMapObjects = heap_alloc(heap, 0x400);
    mobj_sQueryResult = heap_alloc(heap, 0x80);
    mobj_sQueryPushbacks = heap_alloc(heap, 0x180);
    gMapObjState->mMapObjectCount = 0;
    gMapObjState->field130 = FALSE;
    gMapObjState->field178 = FALSE;
    v = 0;
    if (gRaceMultiConfig->mMode != 5) {
        v = 1;
    }
    gMapObjState->mRunUpdateLists = v;
    mobj_sAvailableObjectCount = 0;
    do {
        row = &gMapObjTable[mobj_sAvailableObjectCount];
        descriptor = row->field4;
        if (row->mKind == 0) {
            break;
        }
        if (gOverlayData->mCurrentOverlay != 1 && overlay_isAddressInOverlay(descriptor) != 0) {
            break;
        }
        if (descriptor != NULL) {
            descriptor->mKindData = NULL;
            descriptor->mLists[0] = NULL;
            descriptor->mLists[1] = NULL;
            descriptor->mLists[2] = NULL;
            descriptor->mLists[3] = NULL;
        }
        mobj_sAvailableObjectCount++;
    } while (mobj_sAvailableObjectCount < 0x85);
    mobj_sGrpconfTbl = arc_getMainRaceMainEffectArcFile("MapObj/grpconf.tbl");
    v = 1;
    if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK && gRaceMultiConfig->mMode != 5) {
        v = 0;
    }
    mobj_sUseSimpleHitResponses = v;
    gMapObjState->mHasKoopaBlock = 0;
    gMapObjState->field180 = 0;
    gMapObjState->field184 = 0;
    gMapObjState->field188 = 0;
    gMObjWaterState = NULL;
    gMObjSplashState = NULL;
    cspl_unloadCustomSplashModel();
    pw_setupPaths();
    bbm_init();
    mobj_20D4BF0();
    mobj_sCurCyclicPolygonId = mobj_sMinCyclicPolygonId;
    mobj_sCurStaticPolygonId = mobj_sMinStaticPolygonId;
    for (i = 0; i < mobj_sAvailableObjectCount; i++) {
        if (gMapObjTable[i].field4 != NULL) {
            gMapObjTable[i].field4->mObjectCount = 0;
        }
    }
    for (i = 0; i < n; i++) {
        courseRow = OFFSET_PTR(CourseMapRow, gMapData->mRows, i * sizeof(CourseMapRow));
        if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK && (courseRow->field38 & 1) == 0) {
            continue;
        }
        mobj_createObject(courseRow->mKind, courseRow, NULL);
        gMapObjState->mHasKoopaBlock |= kblock_isKoopaBlock(courseRow->mKind);
        gMapObjState->field180 |= rotcyl_isRotatingCylinder(courseRow->mKind);
        gMapObjState->field184 |= bridge_isBridge(courseRow->mKind);
        gMapObjState->field188 |= IsWall(courseRow->mKind);
    }
    if (gMapObjState->mHasKoopaBlock != 0 || gMapObjState->field180 != 0 || gMapObjState->field184 != 0 ||
        gMapObjState->field188 != 0) {
        gUsesDynamicCollision = 1;
    }
    CreatePooledMapObjects();
    gMapObjState->mDrawListCount = 0;
    for (m = 0; m < 24; m++) {
        gMapObjState->mDrawLists[m] = NULL;
    }
    for (i = 0; i < mobj_sAvailableObjectCount; i++) {
        if (gMapObjTable[i].field4 == NULL) {
            continue;
        }
        v = gMapObjTable[i].field4->mObjectCount;
        kindLists[0] = gMapObjTable[i].field4->mLists[0];
        kindLists[1] = gMapObjTable[i].field4->mLists[1];
        kindLists[2] = gMapObjTable[i].field4->mLists[2];
        for (j = 0; j < 3; j++) {
            s32 isNewList;
            if (kindLists[j] == NULL) {
                continue;
            }
            isNewList = 1;
            for (m = 0; m < gMapObjState->mDrawListCount; m++) {
                if (gMapObjState->mDrawLists[m] == kindLists[j]) {
                    mobj_renderPartIncreaseInstanceCount(kindLists[j], v);
                    isNewList = 0;
                }
            }
            if (isNewList != 0) {
                mobj_renderPartInitInstanceList(kindLists[j]);
                if (v != 0) {
                    mobj_renderPartIncreaseInstanceCount(kindLists[j], v);
                    gMapObjState->mDrawLists[gMapObjState->mDrawListCount++] = kindLists[j];
                }
            }
        }
    }
    for (i = 0; i < gMapObjState->mDrawListCount; i++) {
        mobj_renderPartAllocInstanceList(gMapObjState->mDrawLists[i]);
    }
    for (i = 0; i < gMapObjState->mMapObjectCount; i++) {
        mapObject = gMapObjState->mMapObjects[i];
        for (j = 0; j < mobj_sAvailableObjectCount; j++) {
            if (mapObject->mKind == gMapObjTable[j].mKind) {
                kindLists[0] = gMapObjTable[j].field4->mLists[0];
                kindLists[1] = gMapObjTable[j].field4->mLists[1];
                kindLists[2] = gMapObjTable[j].field4->mLists[2];
                if (kindLists[0] != NULL) {
                    mobj_renderPartAddInstance(kindLists[0], mapObject);
                }
                if (kindLists[1] != NULL) {
                    mobj_renderPartAddInstance(kindLists[1], mapObject);
                }
                if (kindLists[2] != NULL) {
                    mobj_renderPartAddInstance(kindLists[2], mapObject);
                }
            }
        }
    }
    for (i = 0; i < gMapObjState->mDrawListCount; i++) {
        mobj_renderPartCreateAlphaSortList(gMapObjState->mDrawLists[i]);
    }
    gMapObjState->field130 = TRUE;
    mobj_initAllRenderParts();
    n = gMapObjState->mDrawListCount;
    c1 = 0;
    c2 = 0;
    s1 = 0;
    s2 = 0;
    for (t = 0; t < n; t++) {
        list = gMapObjState->mDrawLists[t];
        if (list->field20 != 0) {
            if (list->field18 == 1) {
                c1++;
            } else if (list->field18 == 2) {
                c2++;
            }
        }
    }
    m = 0;
    for (i = 0; i < n; i++) {
        list = gMapObjState->mDrawLists[i];
        if (list->field18 == 1) {
            listArray = gMapObjState->field68;
            gMapObjState->field12A++;
            if (list->field20 != 0) {
                listIndex = s1++;
            } else {
                listIndex = c1++;
            }
        } else if (list->field18 == 2) {
            listArray = gMapObjState->fieldC8;
            gMapObjState->field12C++;
            if (list->field20 != 0) {
                listIndex = s2++;
            } else {
                listIndex = c2++;
            }
        }
        listArray[listIndex] = list;
    }
    gMapObjState->mUpdateListCount = 0;
    for (i = 0; i < 16; i++) {
        gMapObjState->mUpdateLists[i] = NULL;
    }
    for (i = 0; i < mobj_sAvailableObjectCount; i++) {
        if (gMapObjTable[i].field4 == NULL) {
            continue;
        }
        v = gMapObjTable[i].field4->mObjectCount;
        list = gMapObjTable[i].field4->mLists[3];
        if (list == NULL) {
            continue;
        }
        isNewList = 1;
        for (j = 0; j < gMapObjState->mUpdateListCount; j++) {
            if (gMapObjState->mUpdateLists[j] == list) {
                mobj_logicPartIncreaseInstanceCount(list, v);
                isNewList = 0;
            }
        }
        if (isNewList != 0) {
            mobj_logicPartResetInstanceCount(list);
            if (v != 0) {
                mobj_logicPartIncreaseInstanceCount(list, v);
                gMapObjState->mUpdateLists[gMapObjState->mUpdateListCount++] = list;
            }
        }
    }
    for (i = 0; i < gMapObjState->mUpdateListCount; i++) {
        mobj_logicPartInit(gMapObjState->mUpdateLists[i]);
    }
    for (i = 0; i < gMapObjState->mMapObjectCount; i++) {
        mapObject = gMapObjState->mMapObjects[i];
        for (j = 0; j < mobj_sAvailableObjectCount; j++) {
            if (mapObject->mKind == gMapObjTable[j].mKind && gMapObjTable[j].field4->mLists[3] != NULL) {
                mobj_logicPartAddInstance(gMapObjTable[j].field4->mLists[3], mapObject);
            }
        }
    }
    gMapObjState->field178 = TRUE;
    mobj_initAllLogicParts();
}

void mobj_initAllRenderParts(void) {
    s32 i;
    s32 n;
    MapObjectList **listCursor;
    n = gMapObjState->mDrawListCount;
    listCursor = gMapObjState->mDrawLists;
    if (gMObjWaterState != NULL) {
        water_initModels(gMObjWaterState);
    }
    oshd_init();
    for (i = 0; i < n; listCursor++, i++) {
        if ((*listCursor)->mInit != NULL) {
            (*listCursor)->mInit(*listCursor);
        }
    }
}

void mobj_initAllLogicParts(void) {
    s32 i;
    s32 n;
    MapObjectList **listCursor;
    n = gMapObjState->mUpdateListCount;
    listCursor = gMapObjState->mUpdateLists;
    for (i = 0; i < n; listCursor++, i++) {
        if ((*listCursor)->mInit != NULL) {
            (*listCursor)->mInit(*listCursor);
        }
    }
}

#pragma thumb off
