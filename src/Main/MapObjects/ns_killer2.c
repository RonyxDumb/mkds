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
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Graphics/model_effect_kinds.h"
#include "Main/Kart/kart_effect_param_tables.h"
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
#include "Main/MapObjects/cover_poo_hole_cover_height.h"

MapObjectModel *gNsKiller2S;
MapObjectModel *gNsKiller2;

void InitNsKiller2(NsKiller2 *nsKiller2) {
    nsKiller2->mMapObject.mFlags |= gNsKiller2InitMapObjectFlag;
    ParkMapObject(&nsKiller2->mMapObject);
    nsKiller2->mSoundDistanceSquaredChange = CreateVehicleSoundSource(&nsKiller2->mMapObject);
    ResetSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange);
    nsKiller2->mMapObject.mSound->mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetNsKiller2SoundTrackParams;
}

u8 CollideKartWithNsKiller2(NsKiller2 *nsKiller2, Kart *kart, u8 *flagPtr, u8 *resultPtr) {
    u8 flag;
    u8 result;

    flag = *flagPtr;
    result = *resultPtr;
    if (flag == 1) {
        nsKiller2->mParkTimer = NS_KILLER2_PARK_WAIT_FRAMES;
        nsKiller2->mMode = 1;
        nsKiller2->mMapObject.mPosStep.x = ((s64) nsKiller2->mMapObject.mPosStep.x << 10) >> 12;
        nsKiller2->mMapObject.mPosStep.y = ((s64) nsKiller2->mMapObject.mPosStep.y << 10) >> 12;
        nsKiller2->mMapObject.mPosStep.z = ((s64) nsKiller2->mMapObject.mPosStep.z << 10) >> 12;
        nsKiller2->mMapObject.mPosStep.y = 0x4000;
        nsKiller2->mMapObject.mFlags |= gNsKiller2DisabledFlag;
        if (kart->mItemEffect == KART_ITEM_EFFECT_STAR || kart->mItemEffect == KART_ITEM_EFFECT_KILLER) {
            nsKiller2->mMapObject.mDistanceSquaredAndFlags |= gNsKiller2SkipSoundFlag;
        }
        StartSoundIfKartStarOrKiller(&nsKiller2->mMapObject, kart);
    }
    return result;
}

void CreateNsKiller2AndNsKiller2S(void *mapObjectList) {
    gNsKiller2 = CreateMapObjectFromModel_from_thumb(mapObjectList, "NsKiller2.nsbmd");
    gNsKiller2S = CreateMapObjectModelShadow(mapObjectList, "NsKiller2_s.nsbmd");
    StructMapObject_MaybeSetPolygonId(gNsKiller2S, 0x3f);
}

void DrawNsKiller2(void *mapObjectList, NsKiller2 *nsKiller2) {
    s32 gxParam;
    MtxFx33 rotationMatrix;

    if (nsKiller2->mParkTimer <= 0) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetTranslationMatrixPos(&nsKiller2->mMapObject.mPos), 12);
    MTX_RotY33__from_thumb(&rotationMatrix, SIN_OF_ANGLE(nsKiller2->mMapObject.mAngle),
                COS_OF_ANGLE(nsKiller2->mMapObject.mAngle));
    NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    NNS_G3dGeBufferOP_N(0x1b, &nsKiller2->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gNsKiller2S, nsKiller2);
    DrawMapObjectModel(mapObjectList, gNsKiller2, nsKiller2);
}

void UpdateNsKiller2(void *mapObjectList, NsKiller2 *nsKiller2) {
    if ((GetKartZoneMask() & nsKiller2->mMapObject.mDigitMask) != 0) {
        nsKiller2->mMapObject.mFlags |= gNsKiller2SkipViewTestFlag;
    } else {
        nsKiller2->mMapObject.mFlags &= ~2;
    }
    switch (nsKiller2->mMode) {
        case 0:
            if (nsKiller2->mParkTimer-- > 0) {
                if ((nsKiller2->mMapObject.mFlags & MAP_OBJECT_FLAG_NO_VIEW_TEST) == 0 &&
                    (nsKiller2->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_TESTED) != 0) {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      nsKiller2->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f);
                } else {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      GetHorizontalCameraDistanceSquared(&nsKiller2->mMapObject.mPos));
                }
                VecFx32_Add(&nsKiller2->mMapObject.mPos, &nsKiller2->mMapObject.mPosStep, &nsKiller2->mMapObject.mPos);
                if (nsKiller2->mParkTimer < NS_KILLER2_PARK_TIMER_LIMIT) {
                    StartMapObjectSoundWhileRequested(&nsKiller2->mMapObject, 0x17d);
                }
            } else {
                ParkMapObject(&nsKiller2->mMapObject);
            }
            break;
        case 1:
            if (nsKiller2->mParkTimer-- > 0) {
                nsKiller2->mMapObject.mPosStep.y -= 0x400;
                VecFx32_Add(&nsKiller2->mMapObject.mPos, &nsKiller2->mMapObject.mPosStep, &nsKiller2->mMapObject.mPos);
            } else {
                ParkMapObject(&nsKiller2->mMapObject);
            }
            break;
    }
}

void CreateNsKiller2KindData(void) {
    MapObjectKindData *mapObjectKindDataWithSound;

    mapObjectKindDataWithSound = CreateMapObjectKindDataWithSound(CollideKartWithNsKiller2, NULL, NULL, 1, 1, 0x17b);
    mapObjectKindDataWithSound->mHeightRangeMax = NS_KILLER2_HEIGHT_RANGE_MAX;
    mapObjectKindDataWithSound->mHeightRangeMin = -0x64000;
}

void CreateNsKiller2DrawList(void) {
    CreateMapObjectDrawList1(CreateNsKiller2AndNsKiller2S, DrawNsKiller2, NULL);
}

void CreateNsKiller2UpdateList(void) {
    CreateMapObjectUpdateList(NULL, UpdateNsKiller2, NULL);
}

// Starts a parked NsKiller2 at a (raised), flying along b with angle c.
void StartNsKiller2(Vec3 *startPos, Vec3 *direction, u16 angle) {
    NsKiller2 *nsKiller2;

    nsKiller2 = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_NS_KILLER2));
    if (nsKiller2 == NULL) {
        return;
    }
    nsKiller2->mParkTimer = NS_KILLER2_PARK_FRAMES;
    nsKiller2->mMapObject.mPos.x = startPos->x;
    nsKiller2->mMapObject.mPos.y = startPos->y + 0x2a000;
    nsKiller2->mMapObject.mPos.z = startPos->z;
    nsKiller2->mMapObject.mMatrix.mRows[2].x = direction->x;
    nsKiller2->mMapObject.mMatrix.mRows[2].y = 0;
    nsKiller2->mMapObject.mMatrix.mRows[2].z = direction->z;
    nsKiller2->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(direction->x, 0x6000);
    nsKiller2->mMapObject.mPosStep.y = 0;
    nsKiller2->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(direction->z, 0x6000);
    nsKiller2->mMapObject.mAngle = angle;
    nsKiller2->mMode = 0;
}

const u16 gNsKiller2SkipViewTestFlag = 2;
const u16 gNsKiller2DisabledFlag = 1;
const u32 gNsKiller2SkipSoundFlag = 0x40000000;
