#include "Main/MapObjects/earthen_pipe.h"
#include "Main/Menu/second_menu_scene.h"

#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/code_020e6a74.h"
#include "Main/MapObjects/code_020ec1fc.h"
#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/data_0216b000.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/earthen_pipe_create.h"
#include "Main/MapObjects/wanwan_chain.h"

const MapObjectKindDescriptor gEarthenPipeKindDescriptor = {0,
                                                            {0, 0},
                                                            0xb8,
                                                            (void (*)(void *, CourseMapRow *, void *)) InitEarthenPipe,
                                                            CreateEarthenPipeKindData,
                                                            (MapObjectList *(*)(void)) CreateEarthenPipeDrawList,
                                                            0,
                                                            0,
                                                            CreateEarthenPipeUpdateList};

MapObjectList *gEarthenPipeUpdateList;
MapObjectDrawList *gEarthenPipeDrawList;
struct NsbmdModel *gEarthenPipe1;
NsbmdModel *gEarthenPipe2;

void DrawEarthenPipe(u32 unused0, PushedObject *pipe, u32 unused1, u16 maxAlpha) {
    MtxFx43 *matrix;
    if (pipe->mMapObject.mStateMachine.mState == 0) {
        matrix = SetViewRotatedMatrixPos(&pipe->mMapObject.mPos);
        DrawNsbmdModelWithMatrixAndMaxAlpha(gEarthenPipe1, matrix, &pipe->mMapObject.mScale, 0, maxAlpha);
        return;
    }
    QueueNsbmdModelMaterial(gEarthenPipe2);
    matrix = SetViewRotatedMatrixPos(&pipe->mMapObject.mPos);
    DrawNsbmdModelWithMatrixAndAngle(gEarthenPipe2, matrix, pipe->mMotion.mAngle, &pipe->mMapObject.mScale, 0,
                                     maxAlpha);
    QueueNsbmdModelMaterial(gEarthenPipe1);
}

void UpdateEarthenPipe(u32 unused, PushedObject *pipe) {
    AdvanceStateMachine(&pipe->mMapObject.mStateMachine);
}

u8 CollideKartWithEarthenPipe(PushedObject *pipe, void *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    if (HitPushedObjectByKart(pipe, kart, firstResponsePtr) != FALSE) {
        StartSoundIfKartStarOrKiller(&pipe->mMapObject, kart);
    }
    return *secondResponsePtr;
}

u8 CollideItemObjectWithEarthenPipe(PushedObject *pipe, void *itemObject, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    HitPushedObjectByItemObject(pipe, itemObject, firstResponsePtr);
    return *secondResponsePtr;
}

#pragma thumb on

void CreateEarthenPipe1AndEarthenPipe2(void) {
    void *nsbmdFile;
    nsbmdFile = FindCourseMapObjFile("earthen_pipe1.nsbmd");
    CreateNsbmdModel(&gEarthenPipe1, nsbmdFile, 0, 0);
    nsbmdFile = FindCourseMapObjFile("earthen_pipe2.nsbmd");
    CreateNsbmdModel(&gEarthenPipe2, nsbmdFile, 0, 0);
    SetNsbmdModelFixedAttributes(gEarthenPipe1);
    SetNsbmdModelFixedAttributes(gEarthenPipe2);
}

#pragma thumb off
