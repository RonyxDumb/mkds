#include "Main/MapObjects/kuribo_init.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/System/heap_call.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "code_02013740.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/distance_sound_volume.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "tp.h"
#include "Main/Course/code_02042044.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/kuribo.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/dossun.h"

// Object not known yet; it only sets the order of the tables below
u8 gKuriboOrderPad = 0;
const MapObjectKindDescriptor gKuriboKindDescriptor = {0,
                                                   {0, 0},
                                                   0x108,
                                                   InitKuribo,
                                                   CreateKuriboKindData,
                                                   (MapObjectList * (*) (void) ) CreateKuriboDrawList,
                                                   0,
                                                   0,
                                                   CreateKuriboUpdateList};

#pragma thumb on

void InitKuribo(Kuribo *kuribo, CourseMapRow *row) {
    CourseMapGroupEntry *startEntry;
    Vec3 *zeroedVector;
    StateMachine *stateMachine;
    kuribo->mModelAlpha = MAP_OBJECT_ALPHA_MAX;
    if (row != NULL) {
        InitGroupFollower(&kuribo->mFollower, row, (row->mSettings[0] << 11) / 100);
        startEntry = GetCourseMapGroupEntry(row->mGroupIndex, row->mSettings[3]);
        kuribo->mStartY = startEntry->mPos.y;
        kuribo->mOrientationBlendAmount = row->mSettings[0] * 0xb4 / 100;
        kuribo->mReturnsAfterWait = row->mSettings[1] == 0;
        InitStateMachine(&kuribo->mMapObject.mStateMachine, gKuriboStateTable, 6, kuribo);
        SetupGroupFollowerAtEntry(&kuribo->mFollower, kuribo->mMapObject.mCourseMapRow->mSettings[3], 1);
        GetGroupFollowerCurveXz(&kuribo->mFollower, &kuribo->mMapObject.mPos);
        kuribo->mMapObject.mPos.y = kuribo->mStartY;
        zeroedVector = &kuribo->mMapObject.mPosStep;
        zeroedVector->x = 0;
        zeroedVector->y = 0;
        zeroedVector->z = 0;
        {
            Quaternion identityA = {0, 0, 0, 0x1000};
            kuribo->mOrientation = identityA;
        }
        {
            Quaternion identityB = {0, 0, 0, 0x1000};
            kuribo->mTargetOrientation = identityB;
        }
        kuribo->mFrameIndex = 0;
        kuribo->mFrameRandomized = 0;
        stateMachine = &kuribo->mMapObject.mStateMachine;
        stateMachine->mNextState = 0;
        stateMachine->mNextStateRequested = 1;
    } else {
        kuribo->mFollower.mGroupIndex = GROUP_FOLLOWER_NO_GROUP;
        kuribo->mStartY = 0;
        kuribo->mReturnsAfterWait = 0;
        InitStateMachine(&kuribo->mMapObject.mStateMachine, gKuriboStateTable, 6, kuribo);
        kuribo->mOrientationBlendAmount = FIXED12_UNIT;
        {
            Quaternion identityA = {0, 0, 0, 0x1000};
            kuribo->mOrientation = identityA;
        }
        {
            Quaternion identityB = {0, 0, 0, 0x1000};
            kuribo->mTargetOrientation = identityB;
        }
        SetStateMachineState(&kuribo->mMapObject.mStateMachine, KURIBO_STATE_FALL_TO_SURFACE);
        kuribo->mMapObject.mPosStep.x = 0;
        kuribo->mMapObject.mPosStep.y = 0;
        kuribo->mMapObject.mPosStep.z = 0;
    }
}

#pragma thumb off

MapObjectKindData *CreateWaterKindData(void) {
    MapObjectKindData *object;
    object = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(MapObjectKindData));
    {
        MapObjectKindData zeros = {0};
        *object = zeros;
    }
    return object;
}

