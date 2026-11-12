#include "01/code_0219b250.h"

#include "01/unk_021a6000.h"
#include "Main/MapObjects/attractor.h"
#include "Main/System/heap.h"
#include "Main/System/archive_slots.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0209b634.h"
#include "fx_mtx33.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/MapObjects/bound.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/unk_021a9000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/MapObjects/model_animation_entries.h"

void *CreateMapObjectKindDataWithSoundIds(void *collideKartCallback, void *collideItemObjectCallback,
                                          void *sphereHitCallback, u32 p3, u16 p4, u16 soundId,
                                          u16 collideItemObjectSoundId) {
    MapObjectKindData *kindData =
        CreateMapObjectKindData(collideKartCallback, collideItemObjectCallback, sphereHitCallback, p3, p4);
    kindData->mSoundId = soundId;
    kindData->mCollideItemObjectSoundId = collideItemObjectSoundId;
    kindData->mHeightRangeMax = 0x270f000;
    kindData->mHeightRangeMin = 0xfd8f1000;
    return kindData;
}

void *LoadMissionRunFile(const char *fileName) {
    char buf[0x100];
    void *out = NULL;
    snprintf(buf, 0x100, "data/MissionRun/%s", fileName);
    LoadFileIntoHeap(buf, GetHeap(GetCurrentHeapCall()), &out);
    return out;
}

// Overlay-1 version of CreateMapObjectModelAnimated; the file comes from LoadMissionRunFile.
MapObjectModel *LoadMapObjectModelAnimated(MapObjectList *mapObjectList, const char *nsbmdName) {
    MapObjectModel *mapObjectModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 1;
    }
    mapObjectModel->mNsbmdFile = LoadMissionRunFile((nsbmdName));
    mapObjectModel->mAnimatedModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x6c);
    InitNsbmd(mapObjectModel->mAnimatedModel, mapObjectModel->mNsbmdFile);
    SetMapObjectModelFogEnabled(mapObjectModel, 0);
    mapObjectModel->mScale = gMapObjectModelAnimatedScale;
    return mapObjectModel;
}

// Overlay-1 version of CreateMapObjectModelShadow; the file comes from LoadMissionRunFile.
MapObjectModel *LoadMapObjectModelShadow(MapObjectList *mapObjectList, const char *shadowFileName) {
    MapObjectModel *mapObjectModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    void *missionRunFile = LoadMissionRunFile((shadowFileName));
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 1;
    }
    mapObjectModel->mShadowModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x74);
    InitShadowModel(mapObjectModel->mShadowModel, missionRunFile, 0x3f);
    SetMapObjectModelFogEnabled(mapObjectModel, 0);
    mapObjectModel->mScale = gMapObjectModelShadowScale;
    return mapObjectModel;
}

void LoadMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    u8 entryCount;
    mapObjectModel->mAnimations[0] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    entryCount = NNS_G3dGetJntAnmSet(missionRunFile)->mDict.mNumEntry;
    InitModelAnimation(0, mapObjectModel->mAnimations[0], mapObjectModel->mAnimatedModel, entryCount,
                       GetHeap(GetCurrentHeapCall()), mapObjectModel->mNsbmdFile);
    InitModelAnimationEntries(mapObjectModel->mAnimations[0], missionRunFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(mapObjectModel->mAnimations[0], 0);
}

void LoadMapObjectModelNsbmaAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    mapObjectModel->mAnimations[2] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(4, (mapObjectModel->mAnimatedModel), (mapObjectModel->mAnimations[2]),
                                  (mapObjectModel->mNsbmdFile), (missionRunFile));
}

void LoadMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    u8 entryCount;
    mapObjectModel->mAnimations[3] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    entryCount = NNS_G3dGetTexSRTAnmSet(missionRunFile)->mDict.mNumEntry;
    InitModelAnimation(1, mapObjectModel->mAnimations[3], mapObjectModel->mAnimatedModel, entryCount,
                       GetHeap(GetCurrentHeapCall()), mapObjectModel->mNsbmdFile);
    InitModelAnimationEntries(mapObjectModel->mAnimations[3], missionRunFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(mapObjectModel->mAnimations[3], 0);
}

void LoadMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    mapObjectModel->mAnimations[1] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(2, (mapObjectModel->mAnimatedModel), (mapObjectModel->mAnimations[1]),
                                  (mapObjectModel->mNsbmdFile), (missionRunFile));
}

void InitMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, void *nsbcaFile) {
    u8 entryCount;
    mapObjectModel->mAnimations[0] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    entryCount = NNS_G3dGetJntAnmSet(nsbcaFile)->mDict.mNumEntry;
    InitModelAnimation(0, mapObjectModel->mAnimations[0], mapObjectModel->mAnimatedModel, entryCount,
                       GetHeap(GetCurrentHeapCall()), mapObjectModel->mNsbmdFile);
    InitModelAnimationEntries(mapObjectModel->mAnimations[0], nsbcaFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(mapObjectModel->mAnimations[0], 0);
}

void InitMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, void *nsbtpFile) {
    mapObjectModel->mAnimations[1] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    InitModelAnimationWithEntries(2, (mapObjectModel->mAnimatedModel), (mapObjectModel->mAnimations[1]),
                                  (mapObjectModel->mNsbmdFile), (nsbtpFile));
}

void AdvanceMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel) {
    AdvanceModelAnimation(mapObjectModel->mAnimations[0]);
}
