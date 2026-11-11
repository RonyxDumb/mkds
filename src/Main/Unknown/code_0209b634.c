#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea618.h"
#include "Main/Unknown/code_020ea670.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020109c4.h"
#include "code_02012b30.h"

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
