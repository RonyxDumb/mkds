#include "Main/Unknown/code_0209bc74.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObjectList

#pragma thumb on
MapObjectModel *CreateMapObjectModelAnimated(MapObjectList *mapObjectList, const char *name) {
    MapObjectModel *mapObjectModel;

    mapObjectModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    if (mapObjectList != NULL) {
        mapObjectList->mUnk_18 = 1;
    }
    mapObjectModel->mNsbmdFile = FindCourseMapObjFile(name);
    mapObjectModel->mAnimatedModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x6c);
    InitNsbmd(mapObjectModel->mAnimatedModel, mapObjectModel->mNsbmdFile);
    SetNsbmdEmiAll(mapObjectModel->mAnimatedModel, 0x294a);
    SetNsbmdLightEnableFlagAll(mapObjectModel->mAnimatedModel, 2);
    mapObjectModel->mScale = data_021565c4;
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
        mapObjectList->mUnk_18 = 1;
    }
    mapObjectModel->mShadowModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x74);
    InitShadowModel(mapObjectModel->mShadowModel, courseMapObjFile, 0x3f);
    mapObjectModel->mScale = data_021565b8;
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
        mapObjectList->mUnk_18 = 2;
    }
    mapObjectModel->mNsbmdModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    InitNsbmdModel(mapObjectModel->mNsbmdModel, courseMapObjFile, NULL, 0);
    nsbmdModel = mapObjectModel->mNsbmdModel;
    nsbmdModel->mSpecEmi &= 0x8000ffff;
    nsbmdModel->mSpecEmi |= 0x294a0000;
    nsbmdModel = mapObjectModel->mNsbmdModel;
    nsbmdModel->mPolygonAttributes &= ~0xf;
    nsbmdModel->mPolygonAttributes |= 2;
    mapObjectModel->mScale = data_021565ac;
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
        mapObjectList->mUnk_18 = 2;
    }
    mapObjectModel->mNsbmdModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    InitNsbmdModel(mapObjectModel->mNsbmdModel, modelFile, animationFile, 0);
    nsbmdModel = mapObjectModel->mNsbmdModel;
    nsbmdModel->mSpecEmi &= 0x8000ffff;
    nsbmdModel->mSpecEmi |= 0x294a0000;
    nsbmdModel = mapObjectModel->mNsbmdModel;
    nsbmdModel->mPolygonAttributes &= ~0xf;
    nsbmdModel->mPolygonAttributes |= 2;
    mapObjectModel->mScale = data_021565a0;
    return mapObjectModel;
}
#pragma thumb off
