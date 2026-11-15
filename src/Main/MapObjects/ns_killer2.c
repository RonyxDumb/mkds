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
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/MapObjects/data_02166000.h"
#include "Main/MapObjects/data_02165000.h"
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
        nsKiller2->mParkTimer = 0x78;
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
    gNsKiller2 = CreateMapObjectModelAnimated(mapObjectList, "NsKiller2.nsbmd");
    gNsKiller2S = CreateMapObjectModelShadow(mapObjectList, "NsKiller2_s.nsbmd");
    SetMapObjectModelPolygonId(gNsKiller2S, 0x3f);
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
    MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE(nsKiller2->mMapObject.mAngle),
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
                if ((nsKiller2->mMapObject.mFlags & 2) == 0 &&
                    (nsKiller2->mMapObject.mDistanceSquaredAndFlags & 8) != 0) {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      nsKiller2->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f);
                } else {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      GetHorizontalCameraDistanceSquared(&nsKiller2->mMapObject.mPos));
                }
                VEC_Add(&nsKiller2->mMapObject.mPos, &nsKiller2->mMapObject.mPosStep, &nsKiller2->mMapObject.mPos);
                if (nsKiller2->mParkTimer < 0x24e) {
                    StartMapObjectSoundWhileRequested(&nsKiller2->mMapObject, 0x17d);
                }
            } else {
                ParkMapObject(&nsKiller2->mMapObject);
            }
            break;
        case 1:
            if (nsKiller2->mParkTimer-- > 0) {
                nsKiller2->mMapObject.mPosStep.y -= 0x400;
                VEC_Add(&nsKiller2->mMapObject.mPos, &nsKiller2->mMapObject.mPosStep, &nsKiller2->mMapObject.mPos);
            } else {
                ParkMapObject(&nsKiller2->mMapObject);
            }
            break;
    }
}

void CreateNsKiller2KindData(void) {
    MapObjectKindData *mapObjectKindDataWithSound;

    mapObjectKindDataWithSound = CreateMapObjectKindDataWithSound(CollideKartWithNsKiller2, NULL, NULL, 1, 1, 0x17b);
    mapObjectKindDataWithSound->mHeightRangeMax = 0x32000;
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
    nsKiller2->mParkTimer = 600;
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
