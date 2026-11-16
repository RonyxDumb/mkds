#include "Main/MapObjects/ns_killer1.h"
#include "Main/MapObjects/ns_killer2.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/map_objects_get.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/sound_handle_start.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "fixed_vector_math.h"
#include "sound_player_control.h"
#include "Main/MapObjects/ns_killer1_init.h"

SoundStartParams gNsKiller1SoundStartParams = {0x17c, NULL, 9, 0};

MapObjectModel *gNsKiller1;

MapObjectKindDescriptor gNsKiller1KindDescriptor = {0,
                                                    {0, 0},
                                                    0xd0,
                                                    InitNsKiller1,
                                                    CreateEmptyMapObjectKindData,
                                                    CreateNsKiller1DrawList,
                                                    0,
                                                    0,
                                                    CreateNsKiller1UpdateList};

void CreateNsKiller1(void *mapObjectList) {
    gNsKiller1 = CreateMapObjectModelAnimated(mapObjectList, "NsKiller1.nsbmd");
}

void DrawNsKiller1(void *mapObjectList, NsKiller1 *nsKiller1) {
    s32 gxParam;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x1b, &nsKiller1->mMapObject.mScale, 3);
    nsKiller1->mMapObject.mMatrix.mRows[3].x = nsKiller1->mMapObject.mPos.x >> 4;
    nsKiller1->mMapObject.mMatrix.mRows[3].y = nsKiller1->mMapObject.mPos.y >> 4;
    nsKiller1->mMapObject.mMatrix.mRows[3].z = nsKiller1->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &nsKiller1->mMapObject.mMatrix, 12);
    DrawMapObjectModel(mapObjectList, gNsKiller1, nsKiller1);
}

void InitNsKiller1Objects(MapObjectList *mapObjectList) {
    s32 objectIndex;
    NsKiller1 *nsKiller1;

    if (mapObjectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < mapObjectList->mMapObjectCount && (nsKiller1 = mapObjectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        nsKiller1->mStateTimer = 0;
    }
}

void UpdateNsKiller1(void *mapObjectList, NsKiller1 *nsKiller1) {
    SoundStartParams soundParams;

    switch (nsKiller1->mState) {
        case NS_KILLER1_STATE_WAIT:
            if (nsKiller1->mStateTimer-- > 0) {
                return;
            }
            nsKiller1->mFollower.mSpeed = NS_KILLER1_SPEED;
            nsKiller1->mFollower.mProgressStep =
                ((s64) nsKiller1->mFollower.mPath->mSegments[nsKiller1->mFollower.mSegmentIndex].mInverseProgressLength
                 << 13) >>
                12;
            nsKiller1->mState = NS_KILLER1_STATE_FOLLOW_PATH;
            break;
        case NS_KILLER1_STATE_FOLLOW_PATH:
            if (AdvanceGroupFollower(&nsKiller1->mFollower) != FALSE) {
                nsKiller1->mStateTimer = NS_KILLER1_STATE_FRAMES;
                nsKiller1->mState = NS_KILLER1_STATE_PAUSE;
            }
            GetGroupFollowerLinearXz(&nsKiller1->mFollower, &nsKiller1->mMapObject.mPos);
            break;
        case NS_KILLER1_STATE_PAUSE:
            if (nsKiller1->mStateTimer == NS_KILLER1_STATE_FRAMES) {
                if ((nsKiller1->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
                    NNS_SndPlayerStopSeq(GetSndHandleSlot(8), 0);
                    soundParams = gNsKiller1SoundStartParams;
                    soundParams.mPositionSource = &nsKiller1->mMapObject.mPos;
                    soundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&nsKiller1->mMapObject.mPos);
                    StartSndHandleSoundEx(&soundParams, GetSndHandleSlot(8));
                }
            } else if (nsKiller1->mStateTimer <= 0) {
                nsKiller1->mStateTimer = 0;
                nsKiller1->mState = NS_KILLER1_STATE_LAUNCH;
            }
            nsKiller1->mStateTimer--;
            break;
        case NS_KILLER1_STATE_LAUNCH:
            StartNsKiller2(&nsKiller1->mMapObject.mPos, &nsKiller1->mMapObject.mMatrix.mRows[2],
                           nsKiller1->mMapObject.mAngle);
            if ((nsKiller1->mMapObject.mFlags & MAP_OBJECT_FLAGS_NOT_DRAWN) == 0) {
                StartEffect(0x4b, &nsKiller1->mMapObject.mPos);
                StartEffect(0x4c, &nsKiller1->mMapObject.mPos);
                StartEffect(0x4d, &nsKiller1->mMapObject.mPos);
            }
            nsKiller1->mStateTimer = NS_KILLER1_LONG_STATE_FRAMES;
            nsKiller1->mState = NS_KILLER1_STATE_WAIT;
            break;
    }
}

MapObjectList *CreateNsKiller1DrawList(void) {
    return CreateMapObjectDrawList1(CreateNsKiller1, DrawNsKiller1, NULL);
}

MapObjectList *CreateNsKiller1UpdateList(void) {
    return CreateMapObjectUpdateList(InitNsKiller1Objects, UpdateNsKiller1, NULL);
}
