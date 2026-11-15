#include "01/MapObjects/map_object_model_load.h"
#include "01/MapObjects/map_object_model_animation_load.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/MapObjects/attractor.h"
#include "Main/System/heap.h"
#include "Main/System/archive_slots.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "animation_lookup.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/model_animation_loop_modes.h"
#include "print_memory_functions.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "01/MapObjects/map_object_model_nsbca_playing.h"
#include "01/Menu/select_ghost.h"
#include "Main/Graphics/model_animation_loop_mode.h"

const Vec3 gMapObjectModelShadowScale = {0x1000, 0x1000, 0x1000};
const Vec3 gMapObjectModelAnimatedScale = {0x1000, 0x1000, 0x1000};

void *CreateMapObjectKindDataWithSoundIds(void *collideKartCallback, void *collideItemObjectCallback,
                                          void *sphereHitCallback, u32 posStepMode, u16 collidable, u16 soundId,
                                          u16 collideItemObjectSoundId) {
    MapObjectKindData *kindData = CreateMapObjectKindData(collideKartCallback, collideItemObjectCallback,
                                                          sphereHitCallback, posStepMode, collidable);
    kindData->mSoundId = soundId;
    kindData->mCollideItemObjectSoundId = collideItemObjectSoundId;
    kindData->mHeightRangeMax = MAP_OBJECT_HEIGHT_RANGE_MAX;
    kindData->mHeightRangeMin = MAP_OBJECT_HEIGHT_RANGE_MIN;
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
    MapObjectModel *mapObjectModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectModel));
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 1;
    }
    mapObjectModel->mNsbmdFile = LoadMissionRunFile((nsbmdName));
    mapObjectModel->mAnimatedModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(Nsbmd));
    InitNsbmd(mapObjectModel->mAnimatedModel, mapObjectModel->mNsbmdFile);
    SetMapObjectModelFogEnabled(mapObjectModel, 0);
    mapObjectModel->mScale = gMapObjectModelAnimatedScale;
    return mapObjectModel;
}

// Overlay-1 version of CreateMapObjectModelShadow; the file comes from LoadMissionRunFile.
MapObjectModel *LoadMapObjectModelShadow(MapObjectList *mapObjectList, const char *shadowFileName) {
    MapObjectModel *mapObjectModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectModel));
    void *missionRunFile = LoadMissionRunFile((shadowFileName));
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 1;
    }
    mapObjectModel->mShadowModel = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(ShadowModel));
    InitShadowModel(mapObjectModel->mShadowModel, missionRunFile, 0x3f);
    SetMapObjectModelFogEnabled(mapObjectModel, 0);
    mapObjectModel->mScale = gMapObjectModelShadowScale;
    return mapObjectModel;
}

void LoadMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    u8 entryCount;
    mapObjectModel->mAnimations[0] = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(ModelAnimation));
    entryCount = NNS_G3dGetJntAnmSet(missionRunFile)->mDict.mNumEntry;
    InitModelAnimation(0, mapObjectModel->mAnimations[0], mapObjectModel->mAnimatedModel, entryCount,
                       GetHeap(GetCurrentHeapCall()), mapObjectModel->mNsbmdFile);
    InitModelAnimationEntries(mapObjectModel->mAnimations[0], missionRunFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(mapObjectModel->mAnimations[0], 0);
}

void LoadMapObjectModelNsbmaAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    mapObjectModel->mAnimations[2] = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(ModelAnimation));
    InitModelAnimationWithEntries(4, (mapObjectModel->mAnimatedModel), (mapObjectModel->mAnimations[2]),
                                  (mapObjectModel->mNsbmdFile), (missionRunFile));
}

void LoadMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    u8 entryCount;
    mapObjectModel->mAnimations[3] = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(ModelAnimation));
    entryCount = NNS_G3dGetTexSRTAnmSet(missionRunFile)->mDict.mNumEntry;
    InitModelAnimation(1, mapObjectModel->mAnimations[3], mapObjectModel->mAnimatedModel, entryCount,
                       GetHeap(GetCurrentHeapCall()), mapObjectModel->mNsbmdFile);
    InitModelAnimationEntries(mapObjectModel->mAnimations[3], missionRunFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(mapObjectModel->mAnimations[3], 0);
}

void LoadMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    mapObjectModel->mAnimations[1] = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(ModelAnimation));
    InitModelAnimationWithEntries(2, (mapObjectModel->mAnimatedModel), (mapObjectModel->mAnimations[1]),
                                  (mapObjectModel->mNsbmdFile), (missionRunFile));
}

void InitMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, void *nsbcaFile) {
    u8 entryCount;
    mapObjectModel->mAnimations[0] = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(ModelAnimation));
    entryCount = NNS_G3dGetJntAnmSet(nsbcaFile)->mDict.mNumEntry;
    InitModelAnimation(0, mapObjectModel->mAnimations[0], mapObjectModel->mAnimatedModel, entryCount,
                       GetHeap(GetCurrentHeapCall()), mapObjectModel->mNsbmdFile);
    InitModelAnimationEntries(mapObjectModel->mAnimations[0], nsbcaFile, GetHeap(GetCurrentHeapCall()));
    SetModelAnimation(mapObjectModel->mAnimations[0], 0);
}

void InitMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, void *nsbtpFile) {
    mapObjectModel->mAnimations[1] = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(ModelAnimation));
    InitModelAnimationWithEntries(2, (mapObjectModel->mAnimatedModel), (mapObjectModel->mAnimations[1]),
                                  (mapObjectModel->mNsbmdFile), (nsbtpFile));
}

void AdvanceMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel) {
    AdvanceModelAnimation(mapObjectModel->mAnimations[0]);
}

u32 IsMapObjectModelNsbcaPlaying(MapObjectModel *mapObjectModel) {
    if (mapObjectModel->mAnimations[0]->mHead.mDone != 1) {
        return 1;
    }
    return 0;
}

void StartMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop) {
    StartModelAnimationBlend(mapObjectModel->mAnimations[0], entryIndex);
    mapObjectModel->mAnimations[0]->mHead.mFrameStep = frameStep;
    SetModelAnimationEntryLoopMode(mapObjectModel->mAnimations[0], ((u16) entryIndex),
                                   (clampLoop != 0 ? MODEL_ANIMATION_LOOP_MODE_CLAMP : MODEL_ANIMATION_LOOP_MODE_WRAP));
}

void AdvanceMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel) {
    AdvanceModelAnimation(mapObjectModel->mAnimations[3]);
}

void StartMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop) {
    StartModelAnimationBlend(mapObjectModel->mAnimations[3], entryIndex);
    mapObjectModel->mAnimations[1]->mHead.mFrameStep = frameStep;
    SetModelAnimationEntryLoopMode(mapObjectModel->mAnimations[3], ((u16) entryIndex),
                                   (clampLoop != 0 ? MODEL_ANIMATION_LOOP_MODE_CLAMP : MODEL_ANIMATION_LOOP_MODE_WRAP));
}
