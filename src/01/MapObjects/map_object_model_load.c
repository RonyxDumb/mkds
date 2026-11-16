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
#include "print_memory_multibyte_write.h"
#include "Main/MapObjects/model_animation_entries.h"
#include "01/MapObjects/map_object_model_nsbca_playing.h"
#include "01/Menu/select_ghost.h"
#include "Main/Graphics/model_animation_loop_mode.h"

const Vec3 gMapObjectModelShadowScale = {0x1000, 0x1000, 0x1000};
const Vec3 gMapObjectModelAnimatedScale = {0x1000, 0x1000, 0x1000};

void *CreateMapObjectKindDataWithSoundIds(void *collideKartCallback, void *collideItemObjectCallback,
                                          void *sphereHitCallback, u32 posStepMode, u16 collidable, u16 soundId,
                                          u16 collideItemObjectSoundId) {
    MapObjectKindData *kindData = CreateAllocateSomeObject_from_thumb(collideKartCallback, collideItemObjectCallback,
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
    _snprintf(buf, 0x100, "data/MissionRun/%s", fileName);
    ReadFileFromMountManagerHandle_from_thumb(buf, ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), &out);
    return out;
}

// Overlay-1 version of CreateMapObjectFromModel_from_thumb; the file comes from LoadMissionRunFile.
MapObjectModel *LoadMapObjectModelAnimated(MapObjectList *mapObjectList, const char *nsbmdName) {
    MapObjectModel *mapObjectModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(MapObjectModel));
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 1;
    }
    mapObjectModel->mNsbmdFile = LoadMissionRunFile((nsbmdName));
    mapObjectModel->mAnimatedModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(Nsbmd));
    StructML_LoadModel2(mapObjectModel->mAnimatedModel, mapObjectModel->mNsbmdFile);
    StructMapObject_SomeFn_7(mapObjectModel, 0);
    mapObjectModel->mScale = gMapObjectModelAnimatedScale;
    return mapObjectModel;
}

// Overlay-1 version of CreateMapObjectModelShadow; the file comes from LoadMissionRunFile.
MapObjectModel *LoadMapObjectModelShadow(MapObjectList *mapObjectList, const char *shadowFileName) {
    MapObjectModel *mapObjectModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(MapObjectModel));
    void *missionRunFile = LoadMissionRunFile((shadowFileName));
    if (mapObjectList != NULL) {
        mapObjectList->mPassOrPosStepMode = 1;
    }
    mapObjectModel->mShadowModel = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(ShadowModel));
    StructAD00Sh_SomeFn_2(mapObjectModel->mShadowModel, missionRunFile, 0x3f);
    StructMapObject_SomeFn_7(mapObjectModel, 0);
    mapObjectModel->mScale = gMapObjectModelShadowScale;
    return mapObjectModel;
}

void LoadMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    u8 entryCount;
    mapObjectModel->mAnimations[0] = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(ModelAnimation));
    entryCount = Anim_NSBCA_LoadGetJNT0Block(missionRunFile)->mDict.mNumEntry;
    StructAM_CreateFrom(0, mapObjectModel->mAnimations[0], mapObjectModel->mAnimatedModel, entryCount,
                       ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), mapObjectModel->mNsbmdFile);
    StructAM_MaybeLoadAnimation(mapObjectModel->mAnimations[0], missionRunFile, ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
    StructAM_SomeFn_MaybeLoadFrame(mapObjectModel->mAnimations[0], 0);
}

void LoadMapObjectModelNsbmaAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    mapObjectModel->mAnimations[2] = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(ModelAnimation));
    SomeAnimationLoadWrapper_from_thumb(4, (mapObjectModel->mAnimatedModel), (mapObjectModel->mAnimations[2]),
                                  (mapObjectModel->mNsbmdFile), (missionRunFile));
}

void LoadMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    u8 entryCount;
    mapObjectModel->mAnimations[3] = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(ModelAnimation));
    entryCount = MaybeLoadBTA0Format(missionRunFile)->mDict.mNumEntry;
    StructAM_CreateFrom(1, mapObjectModel->mAnimations[3], mapObjectModel->mAnimatedModel, entryCount,
                       ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), mapObjectModel->mNsbmdFile);
    StructAM_MaybeLoadAnimation(mapObjectModel->mAnimations[3], missionRunFile, ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
    StructAM_SomeFn_MaybeLoadFrame(mapObjectModel->mAnimations[3], 0);
}

void LoadMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, const char *fileName) {
    void *missionRunFile = LoadMissionRunFile((fileName));
    mapObjectModel->mAnimations[1] = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(ModelAnimation));
    SomeAnimationLoadWrapper_from_thumb(2, (mapObjectModel->mAnimatedModel), (mapObjectModel->mAnimations[1]),
                                  (mapObjectModel->mNsbmdFile), (missionRunFile));
}

void InitMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, void *nsbcaFile) {
    u8 entryCount;
    mapObjectModel->mAnimations[0] = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(ModelAnimation));
    entryCount = Anim_NSBCA_LoadGetJNT0Block(nsbcaFile)->mDict.mNumEntry;
    StructAM_CreateFrom(0, mapObjectModel->mAnimations[0], mapObjectModel->mAnimatedModel, entryCount,
                       ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), mapObjectModel->mNsbmdFile);
    StructAM_MaybeLoadAnimation(mapObjectModel->mAnimations[0], nsbcaFile, ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
    StructAM_SomeFn_MaybeLoadFrame(mapObjectModel->mAnimations[0], 0);
}

void InitMapObjectModelNsbtpAnimation(MapObjectModel *mapObjectModel, void *nsbtpFile) {
    mapObjectModel->mAnimations[1] = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(ModelAnimation));
    SomeAnimationLoadWrapper_from_thumb(2, (mapObjectModel->mAnimatedModel), (mapObjectModel->mAnimations[1]),
                                  (mapObjectModel->mNsbmdFile), (nsbtpFile));
}

void AdvanceMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel) {
    StructAM_SomeFn_MaybeMoveNextFrame(mapObjectModel->mAnimations[0]);
}

u32 IsMapObjectModelNsbcaPlaying(MapObjectModel *mapObjectModel) {
    if (mapObjectModel->mAnimations[0]->mHead.mDone != 1) {
        return 1;
    }
    return 0;
}

void StartMapObjectModelNsbcaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop) {
    StructAM_SomeFn_MaybeForceLoadBlock(mapObjectModel->mAnimations[0], entryIndex);
    mapObjectModel->mAnimations[0]->mHead.mFrameStep = frameStep;
    StructAM_SetSomeValueAt(mapObjectModel->mAnimations[0], ((u16) entryIndex),
                                   (clampLoop != 0 ? MODEL_ANIMATION_LOOP_MODE_CLAMP : MODEL_ANIMATION_LOOP_MODE_WRAP));
}

void AdvanceMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel) {
    StructAM_SomeFn_MaybeMoveNextFrame(mapObjectModel->mAnimations[3]);
}

void StartMapObjectModelNsbtaAnimation(MapObjectModel *mapObjectModel, s32 entryIndex, s32 frameStep, s32 clampLoop) {
    StructAM_SomeFn_MaybeForceLoadBlock(mapObjectModel->mAnimations[3], entryIndex);
    mapObjectModel->mAnimations[1]->mHead.mFrameStep = frameStep;
    StructAM_SetSomeValueAt(mapObjectModel->mAnimations[3], ((u16) entryIndex),
                                   (clampLoop != 0 ? MODEL_ANIMATION_LOOP_MODE_CLAMP : MODEL_ANIMATION_LOOP_MODE_WRAP));
}
