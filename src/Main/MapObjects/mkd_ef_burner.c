#include "Main/MapObjects/mkd_ef_burner.h"
#include "fx_mtx33.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"

#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "frameheap.h"
#include "os_thread.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/ns_killer2.h"

MapObjectModel *gMkdEfBurner;

MapObjectKindDescriptor gMkdEfBurnerKindDescriptor = {0,
                                                      {0, 0},
                                                      0xf4,
                                                      InitMkdEfBurner,
                                                      CreateMkdEfBurnerKindData,
                                                      CreateMkdEfBurnerDrawList,
                                                      0,
                                                      0,
                                                      CreateMkdEfBurnerUpdateList};

void InitMkdEfBurner(MapObject *mapObject) {
    MapObject *burnerMapObject = mapObject;
    u32 unused;
    CreateMapObjectSoundSourceFalloff2(burnerMapObject);
}

u8 CollideKartWithMkdEfBurner(MkdEfBurner *mkdEfBurner, Kart *kart, u8 *firstResponse, u8 *response) {
    u8 responseValue;

    responseValue = *response;
    if (mkdEfBurner->mKartTimers[kart->mIndex] == 0 &&
        StartSoundIfKartStarOrKiller(&mkdEfBurner->mMapObject, kart) != 0) {
        mkdEfBurner->mMapObject.mDistanceSquaredAndFlags |= gMkdEfBurnerSkipSoundFlag;
        mkdEfBurner->mKartTimers[kart->mIndex] = MKD_EF_BURNER_KART_HIT_FRAMES;
    }
    return responseValue;
}

void CreateMkdEfBurner(MapObjectList *mapObjectList) {
    gMkdEfBurner = CreateMapObjectModelAnimated(mapObjectList, "mkd_ef_burner.nsbmd");
    CreateMapObjectModelNsbtaAnimation(gMkdEfBurner, "mkd_ef_burner.nsbta");
    SetMapObjectModelPolygonId(gMkdEfBurner, 0x3f);
    mapObjectList->mSortByDistance = 1;
}

void SetupDrawMkdEfBurner(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gMkdEfBurner);
}

void DrawMkdEfBurner(void *mapObjectList, MkdEfBurner *mkdEfBurner) {
    s32 gxParam;
    Vec3 gxTranslation;
    Vec3 gxScale;

    if (mkdEfBurner->mScaleFixed12 <= 0) {
        return;
    }
    SetMapObjectModelPolygonId(gMkdEfBurner, AllocPolygonIdWrapping());
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&mkdEfBurner->mMapObject.mPos), 0xc);
    gxTranslation.y = mkdEfBurner->mMapObject.mExtent.y >> 4;
    gxTranslation.x = 0;
    gxTranslation.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &gxTranslation, 3);
    gxScale.x = mkdEfBurner->mScaleFixed12;
    gxScale.y = gxScale.x;
    gxScale.z = gxScale.x;
    NNS_G3dGeBufferOP_N(0x1b, &gxScale, 3);
    NNS_G3dGeBufferOP_N(0x1b, &mkdEfBurner->mMapObject.mScale, 3);
    SetMapObjectModelNsbtaFrameIndex(gMkdEfBurner, mkdEfBurner->mNsbtaFrameIndex);
    DrawMapObjectModel(mapObjectList, gMkdEfBurner, mkdEfBurner);
}

void InitMkdEfBurnerObjects(MapObjectList *mapObjectList) {
    BOOL followerSpeed;
    s32 mapObjectIndex;
    MkdEfBurner *mkdEfBurner;
    u16 mapObjectFlag;
    s32 speed;

    if (mapObjectList == NULL) {
        return;
    }
    followerSpeed = FALSE;
    mapObjectFlag = gMkdEfBurnerDisabledFlag;
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (mkdEfBurner = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        mkdEfBurner->mMapObject.mPos.y =
            mkdEfBurner->mMapObject.mCourseMapRow->mPosition.y - mkdEfBurner->mMapObject.mExtent.y;
        if (mkdEfBurner->mMapObject.mCourseMapRow->mGroupIndex < 0) {
            mkdEfBurner->mFollower.mGroupIndex = GROUP_FOLLOWER_NO_GROUP;
        } else {
            InitGroupFollower(&mkdEfBurner->mFollower, mkdEfBurner->mMapObject.mCourseMapRow, followerSpeed);
            speed = TO_FIXED12(mkdEfBurner->mMapObject.mCourseMapRow->mSettings[3]) / 100;
            mkdEfBurner->mFollower.mSpeed = speed;
            mkdEfBurner->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                speed,
                mkdEfBurner->mFollower.mPath->mSegments[mkdEfBurner->mFollower.mSegmentIndex].mInverseProgressLength);
        }
        if (mkdEfBurner->mMapObject.mCourseMapRow->mSettings[0] == 0 &&
            mkdEfBurner->mMapObject.mCourseMapRow->mSettings[1] == 0 &&
            mkdEfBurner->mMapObject.mCourseMapRow->mSettings[2] == 0) {
            mkdEfBurner->mScaleFixed12 = TO_FIXED12(1);
            mkdEfBurner->mState = MKD_EF_BURNER_STATE_STEADY;
            mkdEfBurner->mMapObject.mFlags &= ~1;
        } else {
            mkdEfBurner->mStateFrames++;
            if (mkdEfBurner->mStateFrames >= mkdEfBurner->mMapObject.mCourseMapRow->mSettings[2]) {
                mkdEfBurner->mStateFrames = 0;
                mkdEfBurner->mState = MKD_EF_BURNER_STATE_GROW;
                mkdEfBurner->mMapObject.mFlags |= mapObjectFlag;
                mkdEfBurner->mMapObject.mExtent.y = 0;
            }
        }
    }
}

void UpdateMkdEfBurner(void *mapObjectList, MkdEfBurner *mkdEfBurner) {
    u16 nsbtaFrameCount;
    s32 kartIndex;
    u8 kartCount;

    switch (mkdEfBurner->mState) {
        case MKD_EF_BURNER_STATE_OFF:
            mkdEfBurner->mStateFrames++;
            if (mkdEfBurner->mStateFrames >= mkdEfBurner->mMapObject.mCourseMapRow->mSettings[1]) {
                mkdEfBurner->mStateFrames = 0;
                mkdEfBurner->mState = MKD_EF_BURNER_STATE_GROW;
                mkdEfBurner->mMapObject.mFlags &= ~1;
            }
            break;
        case MKD_EF_BURNER_STATE_GROW:
            mkdEfBurner->mScaleFixed12 += MKD_EF_BURNER_GROW_STEP;
            if (mkdEfBurner->mScaleFixed12 >= TO_FIXED12(1)) {
                mkdEfBurner->mScaleFixed12 = TO_FIXED12(1);
                mkdEfBurner->mState = MKD_EF_BURNER_STATE_FULL;
            }
            mkdEfBurner->mMapObject.mExtent.y =
                MUL_FIXED12_NO_ROUND(mkdEfBurner->mMapObject.mKindData->mExtentY, mkdEfBurner->mScaleFixed12);
            break;
        case MKD_EF_BURNER_STATE_FULL:
            mkdEfBurner->mStateFrames++;
            if (mkdEfBurner->mStateFrames >= mkdEfBurner->mMapObject.mCourseMapRow->mSettings[0]) {
                mkdEfBurner->mStateFrames = 0;
                mkdEfBurner->mState = MKD_EF_BURNER_STATE_SHRINK;
            }
            StartMapObjectSoundWhileRequested(&mkdEfBurner->mMapObject, 0x170);
            break;
        case MKD_EF_BURNER_STATE_SHRINK:
            mkdEfBurner->mScaleFixed12 -= MKD_EF_BURNER_SHRINK_STEP;
            if (mkdEfBurner->mScaleFixed12 <= 0) {
                mkdEfBurner->mScaleFixed12 = 0;
                mkdEfBurner->mState = MKD_EF_BURNER_STATE_OFF;
                mkdEfBurner->mMapObject.mFlags |= gMkdEfBurnerDisabledFlag;
            }
            mkdEfBurner->mMapObject.mExtent.y =
                MUL_FIXED12_NO_ROUND(mkdEfBurner->mMapObject.mKindData->mExtentY, mkdEfBurner->mScaleFixed12);
            break;
        case MKD_EF_BURNER_STATE_STEADY:
            StartMapObjectSoundWhileRequested(&mkdEfBurner->mMapObject, 0x170);
            break;
    }
    nsbtaFrameCount = GetMapObjectModelNsbtaFrameCount(gMkdEfBurner);
    mkdEfBurner->mNsbtaFrameIndex++;
    if (mkdEfBurner->mNsbtaFrameIndex >= nsbtaFrameCount) {
        mkdEfBurner->mNsbtaFrameIndex = 0;
    }
    if (mkdEfBurner->mFollower.mGroupIndex != GROUP_FOLLOWER_NO_GROUP) {
        AdvanceGroupFollower(&mkdEfBurner->mFollower);
        GetGroupFollowerLinearPosition(&mkdEfBurner->mFollower, &mkdEfBurner->mMapObject.mPos);
        mkdEfBurner->mMapObject.mPos.y = mkdEfBurner->mMapObject.mPos.y - mkdEfBurner->mMapObject.mExtent.y;
    } else {
        mkdEfBurner->mMapObject.mPos.y =
            mkdEfBurner->mMapObject.mCourseMapRow->mPosition.y - mkdEfBurner->mMapObject.mExtent.y;
    }
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        if (mkdEfBurner->mKartTimers[kartIndex] > 0) {
            mkdEfBurner->mKartTimers[kartIndex]--;
        }
    }
}

MapObjectKindData *CreateMkdEfBurnerKindData(void) {
    return CreateMapObjectKindDataWithSound(&CollideKartWithMkdEfBurner, NULL, NULL, 2, 0, (0x0000018du));
}

MapObjectList *CreateMkdEfBurnerDrawList(void) {
    return CreateMapObjectDrawList1(&CreateMkdEfBurner, &DrawMkdEfBurner, &SetupDrawMkdEfBurner);
}

MapObjectList *CreateMkdEfBurnerUpdateList(void) {
    return CreateMapObjectUpdateList(&InitMkdEfBurnerObjects, &UpdateMkdEfBurner, NULL);
}

u16 CountMkdEfBurnerScaleThresholds(MkdEfBurner *burner) {
    if (burner->mScaleFixed12 >= TO_FIXED12(1)) {
        return 3;
    }
    if (burner->mScaleFixed12 >= MKD_EF_BURNER_MEDIUM_SCALE) {
        return 2;
    }
    return burner->mScaleFixed12 >= MKD_EF_BURNER_SMALL_SCALE;
}

const u16 gMkdEfBurnerDisabledFlag = 1;
const u32 gMkdEfBurnerSkipSoundFlag = 0x40000000;

const MapObjectKindDescriptor gNsKiller2KindDescriptor = {0,
                                                          {0, 0},
                                                          0xac,
                                                          InitNsKiller2,
                                                          (MapObjectKindData * (*) (void) ) CreateNsKiller2KindData,
                                                          (MapObjectList * (*) (void) ) CreateNsKiller2DrawList,
                                                          0,
                                                          0,
                                                          (MapObjectList * (*) (void) ) CreateNsKiller2UpdateList};
