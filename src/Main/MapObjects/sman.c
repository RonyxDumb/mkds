#include "Main/MapObjects/sman.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/System/archive_slots.h"
#include "Main/Kart/kart_effects_ahead.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/point_link_cursor_first_next.h"
#include "Main/Kart/point_link_cursor_advance.h"
#include "Main/Kart/kart_ai_item_throw.h"
#include "Main/Save/backup_reset.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Scene/run_scenes.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "matrix_3x3_basic.h"
#include "Main/Course/course_map_group_entry.h"
#include "touch_panel_sampling.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/view_matrix_setters.h"
#include "Main/Item/item_pool.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "card_rom_backup_access.h"
#include "Main/MapObjects/sman_collision.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Kart/kart_ai_follow.h"
#include "fixed_vector_math.h"

MapObjectModel *gSmanTop;
MapObjectModel *gSmanBottom;

MapObjectKindDescriptor gSmanKindDescriptor = {0,
                                               {0, 0},
                                               0xcc,
                                               InitSman,
                                               CreateSmanKindData,
                                               CreateSmanTopDrawList,
                                               CreateSmanBottomDrawList,
                                               0,
                                               CreateSmanUpdateList};

void CreateSmanTop(void *mapObjectList) {
    MapObjectModel *mapObjectModelNsbmd;
    mapObjectModelNsbmd = CreateMapObjectModelNsbmd(mapObjectList, "sman_top.nsbmd");
    gSmanTop = mapObjectModelNsbmd;
    SetMapObjectModelPolygonId(mapObjectModelNsbmd, 0x3f);
}

void SetupDrawSmanTop(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gSmanTop);
}

void DrawSmanTop(void *mapObjectList, Sman *sman) {
    s32 commandArg;
    MtxFx33 matrix;
    s32 topOffset[3];
    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&sman->mMapObject.mPos), 0xc);
    topOffset[1] = sman->mTopHeight >> 4;
    topOffset[0] = 0;
    topOffset[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, topOffset, 3);
    NNS_G3dGeBufferOP_N(0x1b, &sman->mMapObject.mScale, 3);
    MTX_RotZ33_(&matrix, FX_SinIdx((u16) sman->mAngleZ), FX_CosIdx((u16) sman->mAngleZ));
    NNS_G3dGeBufferOP_N(0x1a, &matrix, 9);
    DrawMapObjectModel(mapObjectList, gSmanTop, sman);
}

void CreateSmanBottom(void *mapObjectList) {
    MapObjectModel *mapObjectModelNsbmd;
    mapObjectModelNsbmd = CreateMapObjectModelNsbmd(mapObjectList, "sman_bottom.nsbmd");
    gSmanBottom = mapObjectModelNsbmd;
    SetMapObjectModelPolygonId(mapObjectModelNsbmd, 0x3f);
}

void SetupDrawSmanBottom(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gSmanBottom);
}

void DrawSmanBottom(void *mapObjectList, Sman *sman) {
    s32 commandArg;
    s32 scale[3];
    s32 bottomScale;
    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&sman->mMapObject.mPos), 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &sman->mMapObject.mScale, 3);
    bottomScale = sman->mBottomScale;
    scale[0] = bottomScale;
    scale[1] = bottomScale;
    scale[2] = bottomScale;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    DrawMapObjectModel(mapObjectList, gSmanBottom, sman);
}

void InitSmanObjects(SmanList *smanList) {
    s32 index;
    Sman *sman;
    if (smanList == NULL) {
        return;
    }
    index = 0;
    while (index < smanList->mSmanCount && (sman = smanList->mSmans[index]) != NULL) {
        sman->mTopRiseProgress = FIXED12_UNIT;
        sman->mBottomScale = FIXED12_UNIT;
        index++;
        sman->mTopStartHeight = MUL_FIXED12_NO_ROUND(sman->mMapObject.mScale.y, SMAN_TOP_HEIGHT);
        sman->mTopLowHeight = MUL_FIXED12_NO_ROUND(sman->mMapObject.mScale.y, 0x2000);
        sman->mTopHeight = sman->mTopStartHeight;
    }
}

void UpdateSman(void *mapObjectList, Sman *sman) {
    SoundStartParams soundRequest;
    s32 falloffIndex;
    switch (sman->mState) {
        case SMAN_STATE_REST:
            sman->mAngleZEnabled = 1;
            break;
        case SMAN_STATE_TOP_FLIGHT:
            sman->mTopHeight = sman->mTopHeight + sman->mTopHeightPerFrame;
            sman->mTopHeightPerFrame = sman->mTopHeightPerFrame - 0x400;
            if (sman->mTopHeightPerFrame < -0x6000) {
                sman->mTopHeightPerFrame = -0x6000;
            }
            if (sman->mMapObject.mCourseMapRow->mSettings[0] > 0) {
                if (sman->mTopHeight < 0) {
                    ParkMapObject(&sman->mMapObject);
                }
            } else if (sman->mTopHeight < sman->mTopLowHeight) {
                sman->mTopHeight = sman->mTopLowHeight;
                sman->mTopHeightPerFrame = 0;
                sman->mState = SMAN_STATE_WAIT_LOW;
                falloffIndex = SOUND_FALLOFF_SHORT_RANGE;
                if ((sman->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
                    if (sman->mMapObject.mFarDistanceSquared !=
                        gSoundFalloffs[SOUND_FALLOFF_SHORT_RANGE].mFarDistanceSquared) {
                        if (sman->mMapObject.mFarDistanceSquared ==
                            gSoundFalloffs[SOUND_FALLOFF_MEDIUM_RANGE].mFarDistanceSquared) {
                            falloffIndex = SOUND_FALLOFF_MEDIUM_RANGE;
                        } else {
                            falloffIndex = SOUND_FALLOFF_LONG_RANGE;
                        }
                    }
                    soundRequest.mSoundId = SMAN_SOUND_ID;
                    soundRequest.mPositionSource = &sman->mMapObject.mPos;
                    soundRequest.mFalloffIndex = falloffIndex;
                    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sman->mMapObject.mPos);
                    StartSoundFromParams(&soundRequest);
                }
            }
            sman->mAngleZEnabled = 0;
            break;
        case SMAN_STATE_WAIT_LOW:
            sman->mStateFrames = sman->mStateFrames + 1;
            if (sman->mStateFrames >= SMAN_WAIT_LOW_FRAMES) {
                sman->mStateFrames = 0;
                sman->mTopHeightPerFrame = ((sman->mTopStartHeight - sman->mTopLowHeight) * 0x40) / 0x1000;
                sman->mState = SMAN_STATE_COME_BACK;
            }
            sman->mAngleZEnabled = 0;
            break;
        case SMAN_STATE_COME_BACK:
            if (sman->mTopRiseProgress >= FIXED12_UNIT) {
                sman->mTopRiseProgress = FIXED12_UNIT;
                sman->mTopHeight = sman->mTopStartHeight;
            } else {
                sman->mTopRiseProgress = sman->mTopRiseProgress + 0x40;
                sman->mTopHeight = sman->mTopHeight + sman->mTopHeightPerFrame;
            }
            sman->mStateFrames = sman->mStateFrames + 1;
            if (sman->mStateFrames > SMAN_COME_BACK_FRAMES) {
                sman->mBottomScale = sman->mBottomScale + 0x40;
                if (sman->mBottomScale >= FIXED12_UNIT) {
                    sman->mStateFrames = 0;
                    sman->mBottomScale = FIXED12_UNIT;
                    sman->mMapObject.mFlags = sman->mMapObject.mFlags & ~MAP_OBJECT_FLAG_DISABLED;
                    sman->mState = SMAN_STATE_REST;
                }
            }
            sman->mAngleZEnabled = 1;
            break;
    }
    if (sman->mAngleZEnabled == 0) {
        return;
    }
    sman->mAngleZ = sman->mAngleZ + sman->mAngleZPerFrame;
    if (sman->mAngleZ >= 0) {
        if (sman->mAngleZPerFrame < 0) {
            sman->mAngleZPerFrame = -SMAN_ANGLE_Z_PER_FRAME;
        } else {
            sman->mAngleZPerFrame = sman->mAngleZPerFrame - 8;
        }
    } else {
        if (sman->mAngleZPerFrame >= 0) {
            sman->mAngleZPerFrame = SMAN_ANGLE_Z_PER_FRAME;
        } else {
            sman->mAngleZPerFrame = sman->mAngleZPerFrame + 8;
        }
    }
}

// Creates the kind record of Sman with two functions that put it into state 1 when their third argument points to 1.
MapObjectKindData *CreateSmanKindData(void) {
    return CreateMapObjectKindDataWithSound(CollideKartWithSman, CollideItemObjectWithSman, NULL, 0, 1, 0x161);
}

MapObjectList *CreateSmanTopDrawList(void) {
    return CreateMapObjectDrawList2(CreateSmanTop, DrawSmanTop, SetupDrawSmanTop);
}

MapObjectList *CreateSmanBottomDrawList(void) {
    return CreateMapObjectDrawList2(CreateSmanBottom, DrawSmanBottom, SetupDrawSmanBottom);
}

MapObjectList *CreateSmanUpdateList(void) {
    return CreateMapObjectUpdateList(InitSmanObjects, UpdateSman, NULL);
}
