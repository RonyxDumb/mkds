#include "Main/MapObjects/ns_killer2.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Kart/karts.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/map_objects_get.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/snd_handle_start.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Sound/sound_distance_change_reset.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/data_02166000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_02147cd8.h"
#include "player.h"
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
            nsKiller1->mFollower.mSpeed = 0x2000;
            nsKiller1->mFollower.mProgressStep =
                ((s64) nsKiller1->mFollower.mPath->mSegments[nsKiller1->mFollower.mSegmentIndex].mInverseProgressLength
                 << 13) >>
                12;
            nsKiller1->mState = NS_KILLER1_STATE_FOLLOW_PATH;
            break;
        case NS_KILLER1_STATE_FOLLOW_PATH:
            if (AdvanceGroupFollower(&nsKiller1->mFollower) != FALSE) {
                nsKiller1->mStateTimer = 0x2d;
                nsKiller1->mState = NS_KILLER1_STATE_PAUSE;
            }
            GetGroupFollowerLinearXz(&nsKiller1->mFollower, &nsKiller1->mMapObject.mPos);
            break;
        case NS_KILLER1_STATE_PAUSE:
            if (nsKiller1->mStateTimer == 0x2d) {
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
            nsKiller1->mStateTimer = 0x4b;
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
