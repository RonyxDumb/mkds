#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/attractor.h"
#include "01/MapObjects/data_0209bc74.h"
#include "Main/Kart/code_0207a000.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "Main/Graphics/model_animation.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/shadow_model_alpha.h"
#include "Main/MapObjects/woodbox.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_020109c4.h"
#include "code_02012b30.h"

#pragma thumb on
const Vec3 gMapObjectModelFrameShadowScale = {0x1000, 0x1000, 0x1000};
const Vec3 gMapObjectModelFrameNsbmdScale = {0x1000, 0x1000, 0x1000};
const Vec3 gMapObjectModelFrameNsbmdNsbtpScale = {0x1000, 0x1000, 0x1000};
const Vec3 gMapObjectModelFrameAnimatedScale = {0x1000, 0x1000, 0x1000};

void *CreateMapObjectUpdateList(void *init, void *forEachObject, void *beforeObjects) {
    MapObjectList *list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 40);
    list->mInit = init;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off

#pragma thumb on
// The 1 in the name is the value stored at +0x18, not a slot of the kind row.
void *CreateMapObjectDrawList1(void *init, void *forEachObject, void *beforeObjects) {
    MapObjectList *list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 44);
    list->mPassOrPosStepMode = 1;
    list->mInit = init;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off

#pragma thumb on
void *CreateMapObjectDrawList2(void *init, void *forEachObject, void *beforeObjects) {
    MapObjectList *list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 44);
    list->mPassOrPosStepMode = 2;
    list->mInit = init;
    list->mBeforeObjects = beforeObjects;
    list->mForEachObject = forEachObject;
    list->mAfterObjects = 0;
    return list;
}
#pragma thumb off

#pragma thumb on
MapObjectModel *CreateMapObjectModelAnimated(MapObjectList *mapObjectList, const char *name) {
    MapObjectModel *mapObjectModel;

    mapObjectModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 1;
    }
    mapObjectModel->mNsbmdFile = FindCourseMapObjFile(name);
    mapObjectModel->mAnimatedModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x6c);
    InitNsbmd(mapObjectModel->mAnimatedModel, mapObjectModel->mNsbmdFile);
    SetNsbmdEmiAll(mapObjectModel->mAnimatedModel, 0x294a);
    SetNsbmdLightEnableFlagAll(mapObjectModel->mAnimatedModel, 2);
    mapObjectModel->mScale = gMapObjectModelFrameAnimatedScale;
    return mapObjectModel;
}
#pragma thumb off

#pragma thumb on
void CreateMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, const char *name) {
    void *courseMapObjFile;

    courseMapObjFile = FindCourseMapObjFile(name);
    mapObjectModel->mAnimations[0] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(0, mapObjectModel->mAnimatedModel, mapObjectModel->mAnimations[0],
                                  mapObjectModel->mNsbmdFile, courseMapObjFile);
}
#pragma thumb off

#pragma thumb on
void CreateMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, const char *name) {
    void *courseMapObjFile;

    courseMapObjFile = FindCourseMapObjFile(name);
    mapObjectModel->mAnimations[3] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(1, mapObjectModel->mAnimatedModel, mapObjectModel->mAnimations[3],
                                  mapObjectModel->mNsbmdFile, courseMapObjFile);
}
#pragma thumb off

#pragma thumb on
void CreateMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, const char *name) {
    void *courseMapObjFile;

    courseMapObjFile = FindCourseMapObjFile(name);
    mapObjectModel->mAnimations[1] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(2, mapObjectModel->mAnimatedModel, mapObjectModel->mAnimations[1],
                                  mapObjectModel->mNsbmdFile, courseMapObjFile);
}
#pragma thumb off

#pragma thumb on
MapObjectModel *CreateMapObjectModelShadow(MapObjectList *mapObjectList, const char *name) {
    MapObjectModel *mapObjectModel;
    void *courseMapObjFile;

    mapObjectModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    courseMapObjFile = FindCourseMapObjFile(name);
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 1;
    }
    mapObjectModel->mShadowModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x74);
    InitShadowModel(mapObjectModel->mShadowModel, courseMapObjFile, 0x3f);
    mapObjectModel->mScale = gMapObjectModelFrameShadowScale;
    return mapObjectModel;
}
#pragma thumb off

#pragma thumb on
MapObjectModel *CreateMapObjectModelNsbmd(MapObjectList *mapObjectList, const char *name) {
    MapObjectModel *mapObjectModel;
    void *courseMapObjFile;
    NsbmdModel *nsbmdModel;

    mapObjectModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    courseMapObjFile = FindCourseMapObjFile(name);
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 2;
    }
    mapObjectModel->mNsbmdModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    InitNsbmdModel(mapObjectModel->mNsbmdModel, courseMapObjFile, NULL, 0);
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
// Like CreateMapObjectModelNsbmd with a second file, the .nsbtp (named like Init<Kind><Kind>).
MapObjectModel *CreateMapObjectModelNsbmdNsbtp(MapObjectList *mapObjectList, const char *modelName,
                                               const char *animationName) {
    MapObjectModel *mapObjectModel;
    void *modelFile;
    void *animationFile;
    NsbmdModel *nsbmdModel;

    mapObjectModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    modelFile = FindCourseMapObjFile(modelName);
    animationFile = FindCourseMapObjFile(animationName);
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 2;
    }
    mapObjectModel->mNsbmdModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    InitNsbmdModel(mapObjectModel->mNsbmdModel, modelFile, animationFile, 0);
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
            if ((mapObject->mFlags & 0x100) != 0) {
                UnparkMapObject(mapObject);
                return mapObject;
            }
        }
    }
    return NULL;
}

void QueueMapObjectModelMaterial(void *mapObjectList, MapObjectModel *mapObjectModel) {

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
void DrawMapObjectModelWithPos(u32 unusedArg1, MapObjectModel *mapObjectModel, MapObject *mapObject) {
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
    SetNsbmdLightEnableFlagAll(mapObjectModel->mAnimatedModel, light);
}

void SetMapObjectModelAlpha(MapObjectModel *mapObjectModel, u16 alpha) {
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
void SetMapObjectModelPolygonId(MapObjectModel *mapObjectModel, u32 polygonId) {
    NsbmdModel *nsbmdModel = mapObjectModel->mNsbmdModel;

    if (nsbmdModel != NULL) {
        nsbmdModel->mPolygonAttributes &= ~0x3f000000;
        nsbmdModel->mPolygonAttributes |= polygonId << 24;
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        NNS_G3dMdlSetMdlPolygonIDAll(mapObjectModel->mAnimatedModel->mResMdl, polygonId);
    }
    if (mapObjectModel->mShadowModel != NULL) {
        mapObjectModel->mShadowModel->mPolygonId = polygonId;
    }
}

void SetMapObjectModelMaterialPolygonId(MapObjectModel *mapObjectModel, u32 polygonId, u16 matId) {

    if (mapObjectModel->mAnimatedModel == NULL) {
        return;
    }
    NNS_G3dMdlSetMdlPolygonID(mapObjectModel->mAnimatedModel->mResMdl, matId, polygonId);
}

void SetMapObjectModelFogEnabled(MapObjectModel *mapObjectModel, u32 fogEnabled) {
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

void SetMapObjectModelMirror(MapObjectModel *mapObjectModel, s32 mirrorX, s32 mirrorY) {
    NsbmdModel *nsbmdModel;
    s32 mirrored;

    if (mapObjectModel->mNsbmdModel != NULL) {
        nsbmdModel = mapObjectModel->mNsbmdModel;
        mirrored = mirrorX != 0 || mirrorY != 0 ? 1 : 0;
        if (mirrored ^ gRaceSetup->mMirrorMode) {
            nsbmdModel->mPolygonAttributes &= ~0x80;
            mapObjectModel->mNsbmdModel->mPolygonAttributes |= 0x40;
        } else {
            nsbmdModel->mPolygonAttributes |= 0x80;
            mapObjectModel->mNsbmdModel->mPolygonAttributes &= ~0x40;
        }
    }
    if (mapObjectModel->mAnimatedModel != NULL) {
        mirrored = mirrorX != 0 || mirrorY != 0 ? 1 : 0;
        if (mirrored ^ gRaceSetup->mMirrorMode) {
            SetNsbmdCullModeAll(mapObjectModel->mAnimatedModel, 1);
        } else {
            SetNsbmdCullModeAll(mapObjectModel->mAnimatedModel, 2);
        }
    }
    mapObjectModel->mScale.x = mirrorX != 0 ? -0x1000 : 0x1000;
    mapObjectModel->mScale.y = mirrorY != 0 ? -0x1000 : 0x1000;
}

// Sets the current frame of slot 0 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbcaFrameIndex(MapObjectModel *mapObjectModel, u16 frameIndex) {
    MapObjectModel *model = mapObjectModel;
    ModelAnimation *animation = model->mAnimations[0];

    animation->mHead.mFrameIndex = TO_FIXED12(frameIndex);
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
}

// Number of frames of the animation in slot 0 (its length, not the current frame).
u16 GetMapObjectModelNsbcaFrameCount(MapObjectModel *mapObjectModel) {
    MapObjectModel *model = mapObjectModel;

    return (u32) GetModelAnimationFrameCountFixed(model->mAnimations[0]) >> 12;
}

// Sets the current frame of slot 2 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbmaFrameIndex(MapObjectModel *mapObjectModel, u32 frameIndex) {
    ModelAnimation *animation = mapObjectModel->mAnimations[2];

    animation->mHead.mFrameIndex = TO_FIXED12(frameIndex);
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
}

// Number of frames of the animation in slot 2 (its length, not the current frame).
s32 GetMapObjectModelNsbmaFrameCount(MapObjectModel *mapObjectModel) {

    return (u16) ((u32) GetModelAnimationFrameCountFixed(mapObjectModel->mAnimations[2]) >> 12);
}

// Number of frames of the animation in slot 3 (its length, not the current frame).
u16 GetMapObjectModelNsbtaFrameCount(MapObjectModel *mapObjectModel) {
    MapObjectModel *model = mapObjectModel;

    return (u32) GetModelAnimationFrameCountFixed(model->mAnimations[3]) >> 12;
}

// Sets the current frame of slot 3 in 20.12 fixed point (the track frame follows).
void SetMapObjectModelNsbtaFrameIndex(MapObjectModel *mapObjectModel, s32 frameIndex) {
    ModelAnimation *animation = mapObjectModel->mAnimations[3];

    animation->mHead.mFrameIndex = TO_FIXED12(frameIndex);
    animation->mAnmObjs[animation->mCurrentIndex]->mFrame = animation->mHead.mFrameIndex;
}

void SetMapObjectModelNsbtpFrameIndex(MapObjectModel *mapObjectModel, u16 frameIndex) {
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

u16 GetMapObjectModelNsbtpFrameCount(MapObjectModel *mapObjectModel) {

    if (mapObjectModel->mNsbmdModel != NULL) {
        return mapObjectModel->mNsbmdModel->mFrameCount;
    }
    if (mapObjectModel->mAnimatedModel == NULL) {
        return 0;
    }
    return (u32) GetModelAnimationFrameCountFixed(mapObjectModel->mAnimations[1]) >> 12;
}

// Current frame of the .nsbca animation in slot 0: the whole-frame part of its 20.12 position.
u32 GetMapObjectModelNsbcaFrameIndex(MapObjectModel *model) {
    u32 value0 = model->mAnimations[0]->mHead.mFrameIndex;
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}

u32 GetMapObjectModelNsbtpFrameIndex(MapObjectModel *model) {
    u32 value0 = model->mAnimations[1]->mHead.mFrameIndex;
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}
