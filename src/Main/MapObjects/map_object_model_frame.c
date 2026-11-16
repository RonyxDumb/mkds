#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/attractor.h"
#include "01/MapObjects/map_object_model.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/Graphics/model_animation.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/shadow_model_alpha.h"
#include "Main/MapObjects/woodbox.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "render_object_callback_link.h"
#include "model_material_set.h"

#pragma thumb on
const Vec3 gMapObjectModelFrameShadowScale = {0x1000, 0x1000, 0x1000};
const Vec3 gMapObjectModelFrameNsbmdScale = {0x1000, 0x1000, 0x1000};
const Vec3 gMapObjectModelFrameNsbmdNsbtpScale = {0x1000, 0x1000, 0x1000};
const Vec3 gMapObjectModelFrameAnimatedScale = {0x1000, 0x1000, 0x1000};

void *CreateMapObjectUpdateList(void *StructDC_SomeFn_from_thumb, void *forEachObject, void *beforeObjects) {
    MapObjectList *list = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), 40);
    list->mInit = StructDC_SomeFn_from_thumb;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off

#pragma thumb on
// The 1 in the name is the value stored at +0x18, not a slot of the kind row.
void *CreateMapObjectDrawList1(void *StructDC_SomeFn_from_thumb, void *forEachObject, void *beforeObjects) {
    MapObjectList *list = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), 44);
    list->mPassOrPosStepMode = MAP_OBJECT_LIST_PASS_FIRST;
    list->mInit = StructDC_SomeFn_from_thumb;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off

#pragma thumb on
void *CreateAllocateMapObject_from_thumb(void *StructDC_SomeFn_from_thumb, void *forEachObject, void *beforeObjects) {
    MapObjectList *list = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), 44);
    list->mPassOrPosStepMode = MAP_OBJECT_LIST_PASS_SECOND;
    list->mInit = StructDC_SomeFn_from_thumb;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off

#pragma thumb on
MapObjectModel *CreateMapObjectFromModel_from_thumb(MapObjectList *mapObjectList, const char *name) {
    MapObjectModel *mapObjectModel;

    mapObjectModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*mapObjectModel));
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = MAP_OBJECT_LIST_PASS_FIRST;
    }
    mapObjectModel->mNsbmdFile = FormatFindMapObjFileBuffer_from_thumb(name);
    mapObjectModel->mAnimatedModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(Nsbmd));
    StructML_LoadModel2(mapObjectModel->mAnimatedModel, mapObjectModel->mNsbmdFile);
    StructML_SomeFn_7(mapObjectModel->mAnimatedModel, 0x294a);
    StructML_SomeFn_8(mapObjectModel->mAnimatedModel, 2);
    mapObjectModel->mScale = gMapObjectModelFrameAnimatedScale;
    return mapObjectModel;
}
#pragma thumb off

#pragma thumb on
void StructMapObject_AddAnimationNsbca_from_thumb(MapObjectModel *mapObjectModel, const char *name) {
    void *courseMapObjFile;

    courseMapObjFile = FormatFindMapObjFileBuffer_from_thumb(name);
    mapObjectModel->mAnimations[0] = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*mapObjectModel->mAnimations[0]));
    SomeAnimationLoadWrapper_from_thumb(0, mapObjectModel->mAnimatedModel, mapObjectModel->mAnimations[0],
                                  mapObjectModel->mNsbmdFile, courseMapObjFile);
}
#pragma thumb off

#pragma thumb on
void StructMapObject_AddAnimationNsbta_from_thumb(MapObjectModel *mapObjectModel, const char *name) {
    void *courseMapObjFile;

    courseMapObjFile = FormatFindMapObjFileBuffer_from_thumb(name);
    mapObjectModel->mAnimations[3] = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*mapObjectModel->mAnimations[3]));
    SomeAnimationLoadWrapper_from_thumb(1, mapObjectModel->mAnimatedModel, mapObjectModel->mAnimations[3],
                                  mapObjectModel->mNsbmdFile, courseMapObjFile);
}
#pragma thumb off

#pragma thumb on
void StructMapObject_AddAnimationNsbtp_from_thumb(MapObjectModel *mapObjectModel, const char *name) {
    void *courseMapObjFile;

    courseMapObjFile = FormatFindMapObjFileBuffer_from_thumb(name);
    mapObjectModel->mAnimations[1] = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*mapObjectModel->mAnimations[1]));
    SomeAnimationLoadWrapper_from_thumb(2, mapObjectModel->mAnimatedModel, mapObjectModel->mAnimations[1],
                                  mapObjectModel->mNsbmdFile, courseMapObjFile);
}
#pragma thumb off

#pragma thumb on
MapObjectModel *CreateMapObjectModelShadow(MapObjectList *mapObjectList, const char *name) {
    MapObjectModel *mapObjectModel;
    void *courseMapObjFile;

    mapObjectModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*mapObjectModel));
    courseMapObjFile = FormatFindMapObjFileBuffer_from_thumb(name);
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = MAP_OBJECT_LIST_PASS_FIRST;
    }
    mapObjectModel->mShadowModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(ShadowModel));
    StructAD00Sh_SomeFn_2(mapObjectModel->mShadowModel, courseMapObjFile, 0x3f);
    mapObjectModel->mScale = gMapObjectModelFrameShadowScale;
    return mapObjectModel;
}
#pragma thumb off

#pragma thumb on
MapObjectModel *CreateMapObjectFromModel_2_from_thumb(MapObjectList *mapObjectList, const char *name) {
    MapObjectModel *mapObjectModel;
    void *courseMapObjFile;
    NsbmdModel *nsbmdModel;

    mapObjectModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*mapObjectModel));
    courseMapObjFile = FormatFindMapObjFileBuffer_from_thumb(name);
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = MAP_OBJECT_LIST_PASS_SECOND;
    }
    mapObjectModel->mNsbmdModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(NsbmdModel));
    StructMapObjectSub_SomeFn_from_thumb(mapObjectModel->mNsbmdModel, courseMapObjFile, NULL, 0);
    nsbmdModel = mapObjectModel->mNsbmdModel;
    nsbmdModel->mSpecEmi &= 0x8000ffff;
    nsbmdModel->mSpecEmi |= 0x294a0000;
    nsbmdModel = mapObjectModel->mNsbmdModel;
    nsbmdModel->mPolygonAttributes &= ~0xf;
    nsbmdModel->mPolygonAttributes |= 2;
    mapObjectModel->mScale = gMapObjectModelFrameNsbmdScale;
    return mapObjectModel;
}
#pragma thumb off

#pragma thumb on
// Like CreateMapObjectFromModel_2_from_thumb with a second file, the .nsbtp (named like Init<Kind><Kind>).
MapObjectModel *CreateMapObjectFromModelAndAnimation_from_thumb(MapObjectList *mapObjectList, const char *modelName,
                                               const char *animationName) {
    MapObjectModel *mapObjectModel;
    void *modelFile;
    void *animationFile;
    NsbmdModel *nsbmdModel;

    mapObjectModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*mapObjectModel));
    modelFile = FormatFindMapObjFileBuffer_from_thumb(modelName);
    animationFile = FormatFindMapObjFileBuffer_from_thumb(animationName);
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = MAP_OBJECT_LIST_PASS_SECOND;
    }
    mapObjectModel->mNsbmdModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(NsbmdModel));
    StructMapObjectSub_SomeFn_from_thumb(mapObjectModel->mNsbmdModel, modelFile, animationFile, 0);
    nsbmdModel = mapObjectModel->mNsbmdModel;
    nsbmdModel->mSpecEmi &= 0x8000ffff;
    nsbmdModel->mSpecEmi |= 0x294a0000;
    nsbmdModel = mapObjectModel->mNsbmdModel;
    nsbmdModel->mPolygonAttributes &= ~0xf;
    nsbmdModel->mPolygonAttributes |= 2;
    mapObjectModel->mScale = gMapObjectModelFrameNsbmdNsbtpScale;
    return mapObjectModel;
}
#pragma thumb off

void *GetMapObjectFromList(MapObjectList *list, s32 index) {
    return GetMapObjects(list)[index];
}

// Unparks and returns the first parked map object of the list, or NULL if the list is NULL or has none.
void *UnparkFirstParkedMapObject(MapObjectList *mapObjectList) {
    MapObject *mapObject;
    s32 objectIndex;

    if (mapObjectList != NULL) {
        for (objectIndex = 0; objectIndex < mapObjectList->mMapObjectCount &&
                              (mapObject = mapObjectList->mMapObjects[objectIndex]) != NULL;
             objectIndex++) {
            if ((mapObject->mFlags & MAP_OBJECT_FLAG_PARKED) != 0) {
                UnparkMapObject(mapObject);
                return mapObject;
            }
        }
    }
    return NULL;
}

void StructMapObject_SomeFn_9(void *mapObjectList, MapObjectModel *mapObjectModel) {

    if (mapObjectModel->mNsbmdModel == NULL) {
        return;
    }
    QueueNsbmdModelMaterial(mapObjectModel->mNsbmdModel);
}

void DrawMapObjectModel(MapObjectList *mapObjectList, MapObjectModel *mapObjectModel, void *rawMapObject) {
    MapObject *mapObject = rawMapObject;

    NNS_G3dGeBufferOP_N(0x1b, mapObjectModel, 3);
    if (mapObjectModel->mNsbmdModel != NULL) {
        DrawNsbmdModelWithMaxAlphaMapObjectPos(mapObjectModel->mNsbmdModel, mapObject->mAlpha, NULL);
    }
    if (mapObjectModel->mAnimatedModel == NULL && mapObjectModel->mShadowModel == NULL) {
        return;
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        if (mapObjectModel->mAnimations[2] != NULL) {
            DrawNsbmdWithMaxAlphaAndMaterial(mapObjectModel->mAnimatedModel, mapObject->mAlpha);
        } else {
            DrawNsbmdWithMaxAlpha(mapObjectModel->mAnimatedModel, mapObject->mAlpha);
        }
    }
    if (mapObjectModel->mShadowModel == NULL) {
        return;
    }
    DrawShadowModelWithMaxAlpha(mapObjectModel->mShadowModel, mapObject->mAlpha);
}

// Like DrawMapObjectModel but passes the object's position to the model draw, which lowers the alpha of an object whose
// camera depth is below its alpha level (near fade) and picks a polygon id for it.
void DrawMapObjectModelWithPos(u32 unusedMapObjectList, MapObjectModel *mapObjectModel, MapObject *mapObject) {
    MapObjectModel *model = mapObjectModel;

    NNS_G3dGeBufferOP_N(0x1b, model, 3);
    if (model->mNsbmdModel != NULL) {
        DrawNsbmdModelWithMaxAlphaMapObjectPos(model->mNsbmdModel, mapObject->mAlpha, &mapObject->mPos);
    }
    if (model->mAnimatedModel == NULL && model->mShadowModel == NULL) {
        return;
    }
    if (model->mAnimatedModel != NULL) {
        if (model->mAnimations[2] != NULL) {
            DrawNsbmdWithMaxAlphaAndMaterial(model->mAnimatedModel, mapObject->mAlpha);
        } else {
            DrawNsbmdWithMaxAlpha(model->mAnimatedModel, mapObject->mAlpha);
        }
    }
    if (model->mShadowModel == NULL) {
        return;
    }
    DrawShadowModelWithMaxAlpha(model->mShadowModel, mapObject->mAlpha);
}

void DrawMapObjectModel1Mat1Shp(void *mapObjectList, MapObjectModel *mapObjectModel, void *rawMapObject) {

    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    DrawNsbmd1Mat1ShpWithMaxAlpha(mapObjectModel->mAnimatedModel, ((MapObject *) rawMapObject)->mAlpha);
}

void SetMapObjectModelLightEnableFlag(MapObjectModel *mapObjectModel, u32 light) {
    NsbmdModel *nsbmdModel = mapObjectModel->mNsbmdModel;

    if (nsbmdModel != NULL) {
        nsbmdModel->mPolygonAttributes &= ~0xf;
        nsbmdModel->mPolygonAttributes |= light;
    }
    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    StructML_SomeFn_8(mapObjectModel->mAnimatedModel, light);
}

void StructMapObject_SomeFn_6(MapObjectModel *mapObjectModel, u16 alpha) {
    NsbmdModel *nsbmdModel = mapObjectModel->mNsbmdModel;

    if (nsbmdModel != NULL) {
        nsbmdModel->mPolygonAttributes &= ~0x1f0000;
        nsbmdModel->mPolygonAttributes |= alpha << 16;
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        NNS_G3dMdlSetMdlAlphaAll(mapObjectModel->mAnimatedModel->mResMdl, alpha);
    }
    if (mapObjectModel->mShadowModel != NULL) {
        mapObjectModel->mShadowModel->mAlpha = alpha;
    }
}

// Stores a polygon id (6 bits at bit 24 of the polygon attribute) in every model the bundle holds; 0x3f at creation,
// The draw may replace this polygon id.
void StructMapObject_MaybeSetPolygonId(MapObjectModel *mapObjectModel, u32 polygonId) {
    NsbmdModel *nsbmdModel = mapObjectModel->mNsbmdModel;

    if (nsbmdModel != NULL) {
        nsbmdModel->mPolygonAttributes &= ~0x3f000000;
        nsbmdModel->mPolygonAttributes |= polygonId << 24;
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        ModelBlock_SomeFn(mapObjectModel->mAnimatedModel->mResMdl, polygonId);
    }
    if (mapObjectModel->mShadowModel != NULL) {
        mapObjectModel->mShadowModel->mPolygonId = polygonId;
    }
}

void SetMapObjectModelMaterialPolygonId(MapObjectModel *mapObjectModel, u32 polygonId, u16 matId) {

    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    ModelBlock_SomeTexPltFn_3(mapObjectModel->mAnimatedModel->mResMdl, matId, polygonId);
}

void StructMapObject_SomeFn_7(MapObjectModel *mapObjectModel, u32 fogEnabled) {
    NsbmdModel *nsbmdModel = mapObjectModel->mNsbmdModel;

    if (nsbmdModel != NULL) {
        if (fogEnabled != 0) {
            nsbmdModel->mPolygonAttributes |= 0x8000;
        } else {
            nsbmdModel->mPolygonAttributes &= ~0x8000;
        }
    }
    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    NNS_G3dMdlSetMdlFogEnableFlagAll(mapObjectModel->mAnimatedModel->mResMdl, fogEnabled);
}

void StructMapObject_SomeFn_8(MapObjectModel *mapObjectModel, s32 mirrorX, s32 mirrorY) {
    NsbmdModel *nsbmdModel;
    s32 mirrored;

    if (mapObjectModel->mNsbmdModel != NULL) {
        nsbmdModel = mapObjectModel->mNsbmdModel;
        mirrored = mirrorX != 0 || mirrorY != 0 ? 1 : 0;
        if (mirrored ^ g_GlobalCO->mMirrorMode) {
            nsbmdModel->mPolygonAttributes &= ~0x80;
            mapObjectModel->mNsbmdModel->mPolygonAttributes |= 0x40;
        } else {
            nsbmdModel->mPolygonAttributes |= 0x80;
            mapObjectModel->mNsbmdModel->mPolygonAttributes &= ~0x40;
        }
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        mirrored = mirrorX != 0 || mirrorY != 0 ? 1 : 0;
        if (mirrored ^ g_GlobalCO->mMirrorMode) {
            StructML_SomeFn_0(mapObjectModel->mAnimatedModel, 1);
        } else {
            StructML_SomeFn_0(mapObjectModel->mAnimatedModel, 2);
        }
    }
    mapObjectModel->mScale.x = mirrorX != 0 ? -0x1000 : 0x1000;
    mapObjectModel->mScale.y = mirrorY != 0 ? -0x1000 : 0x1000;
}

// Sets the current frame of slot 0 in 20.12 fixed point (the track frame follows).
void StructMapObject_MaybeSetNsbcaFrame(MapObjectModel *mapObjectModel, u16 frameIndex) {
    MapObjectModel *model = mapObjectModel;
    ModelAnimation *animation = model->mAnimations[0];

    animation->mHead.mFrameIndex = TO_FIXED12(frameIndex);
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
}

// Number of frames of the animation in slot 0 (its length, not the current frame).
u16 StructMapObject_GetAnimationBCAFrameCount(MapObjectModel *mapObjectModel) {
    MapObjectModel *model = mapObjectModel;

    return (u32) StructAM_GetFrameCount_Times4096(model->mAnimations[0]) >> 12;
}

// Sets the current frame of slot 2 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbmaFrameIndex(MapObjectModel *mapObjectModel, u32 frameIndex) {
    ModelAnimation *animation = mapObjectModel->mAnimations[2];

    animation->mHead.mFrameIndex = TO_FIXED12(frameIndex);
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
}

// Number of frames of the animation in slot 2 (its length, not the current frame).
s32 GetMapObjectModelNsbmaFrameCount(MapObjectModel *mapObjectModel) {

    return (u16) ((u32) StructAM_GetFrameCount_Times4096(mapObjectModel->mAnimations[2]) >> 12);
}

// Number of frames of the animation in slot 3 (its length, not the current frame).
u16 StructMapObject_SomeFn_2(MapObjectModel *mapObjectModel) {
    MapObjectModel *model = mapObjectModel;

    return (u32) StructAM_GetFrameCount_Times4096(model->mAnimations[3]) >> 12;
}

// Sets the current frame of slot 3 in 20.12 fixed point (the track frame follows).
void StructMapObject_SomeFn_3(MapObjectModel *mapObjectModel, s32 frameIndex) {
    ModelAnimation *animation = mapObjectModel->mAnimations[3];

    animation->mHead.mFrameIndex = TO_FIXED12(frameIndex);
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
}

void StructMapObject_SomeFn_0(MapObjectModel *mapObjectModel, u16 frameIndex) {
    ModelAnimation *animation;

    if (mapObjectModel->mNsbmdModel != NULL) {
        mapObjectModel->mNsbmdModel->mFrameIndex = frameIndex;
        return;
    }
    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    animation = mapObjectModel->mAnimations[1];
    animation->mHead.mFrameIndex = TO_FIXED12(frameIndex);
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
}

u16 StructMapObject_SomeFn_1(MapObjectModel *mapObjectModel) {

    if (mapObjectModel->mNsbmdModel != NULL) {
        return mapObjectModel->mNsbmdModel->mFrameCount;
    }
    if (mapObjectModel->mAnimatedModel == NULL) {
        return 0;
    }
    return (u32) StructAM_GetFrameCount_Times4096(mapObjectModel->mAnimations[1]) >> 12;
}

// Current frame of the .nsbca animation in slot 0: the whole-frame part of its 20.12 position.
u32 GetMapObjectModelNsbcaFrameIndex(MapObjectModel *model) {
    u32 frameIndex = model->mAnimations[0]->mHead.mFrameIndex;
    frameIndex = (frameIndex << 4);
    frameIndex = (frameIndex >> 16);
    return frameIndex;
}

u32 GetMapObjectModelNsbtpFrameIndex(MapObjectModel *model) {
    u32 frameIndex = model->mAnimations[1]->mHead.mFrameIndex;
    frameIndex = (frameIndex << 4);
    frameIndex = (frameIndex >> 16);
    return frameIndex;
}
