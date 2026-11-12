#include "Main/MapObjects/bakubaku.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/MapObjects/bound.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Graphics/model_effects.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/shadow_position_raised.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_02166000.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Kart/karts.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

MapObjectModel *gBakubaku;
MapObjectModel *gBakuShadow;

MapObjectKindDescriptor gBakubakuKindDescriptor = {
    0, {0, 0}, 0xb8, 0, CreateEmptyMapObjectKindData, CreateBakubakuDrawList, 0, 0, CreateBakubakuUpdateList};

void CreateBakubakuAndBakuShadow(void *mapObjectList) {
    gBakubaku = CreateMapObjectModelAnimated(mapObjectList, "bakubaku.nsbmd");
    gBakuShadow = CreateMapObjectModelShadow(mapObjectList, "baku_shadow.nsbmd");
    SetMapObjectModelPolygonId(gBakubaku, 0x3f);
    SetMapObjectModelPolygonId(gBakuShadow, 0x3f);
}

void DrawBakubaku(void *mapObjectList, Bakubaku *bakubaku) {
    s32 gxParam;
    MtxFx33 rotation;
    s32 angle;

    if (bakubaku->mState != 2) {
        return;
    }
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    bakubaku->mMapObject.mMatrix.mRows[3].x = bakubaku->mMapObject.mPos.x >> 4;
    bakubaku->mMapObject.mMatrix.mRows[3].y = bakubaku->mMapObject.mPos.y >> 4;
    bakubaku->mMapObject.mMatrix.mRows[3].z = bakubaku->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &bakubaku->mMapObject.mMatrix, 12);
    NNS_G3dGeBufferOP_N(0x1b, &bakubaku->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gBakuShadow, bakubaku);
    angle = (u16) (u32) FX_Atan2Idx(-bakubaku->mMapObject.mPosStep.y, 0xc000);
    MTX_RotX33_(&rotation, SIN_OF_ANGLE(angle), COS_OF_ANGLE(angle));
    NNS_G3dGeBufferOP_N(0x1a, &rotation, 9);
    DrawMapObjectModel(mapObjectList, gBakubaku, bakubaku);
}

void InitBakubakuObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    Bakubaku *bakubaku;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (bakubaku = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        VEC_MultAdd(0x320000, &bakubaku->mMapObject.mMatrix.mRows[2], &bakubaku->mMapObject.mCourseMapRow->mPosition,
                    &bakubaku->mUnk_a4);
    }
}

void UpdateBakubaku(void *mapObjectList, Bakubaku *bakubaku) {
    SoundStartParams firstSoundParams;
    SoundStartParams secondSoundParams;
    Kart *kart;
    Vec3 *kartPos;
    s64 distanceSquared;
    s32 deltaZ;
    s32 deltaX;

    switch (bakubaku->mState) {
        case 0:
            if (GetCurrentCameraKind() != 2) {
                kart = GetKart((u16) gRaceSetup->mEntryIndex);
                kartPos = &kart->mPos;
                deltaX = kartPos->x - bakubaku->mUnk_a4.x;
                deltaZ = kartPos->z - bakubaku->mUnk_a4.z;
                distanceSquared = (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
                if (distanceSquared >= (s64) 0x9c4 << 32) {
                    return;
                }
            }
            bakubaku->mMapObject.mPos.x = bakubaku->mMapObject.mCourseMapRow->mPosition.x;
            bakubaku->mMapObject.mPos.y = bakubaku->mMapObject.mCourseMapRow->mPosition.y - 0x32000;
            bakubaku->mMapObject.mPos.z = bakubaku->mMapObject.mCourseMapRow->mPosition.z;
            bakubaku->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(bakubaku->mMapObject.mMatrix.mRows[2].x, 0xc000);
            bakubaku->mMapObject.mPosStep.y = 0xc000;
            bakubaku->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(bakubaku->mMapObject.mMatrix.mRows[2].z, 0xc000);
            bakubaku->mState = 1;
            break;
        case 1:
            bakubaku->mMapObject.mPosStep.y -= 0x400;
            VEC_Add(&bakubaku->mMapObject.mPos, &bakubaku->mMapObject.mPosStep, &bakubaku->mMapObject.mPos);
            if (bakubaku->mMapObject.mPos.y < bakubaku->mMapObject.mCourseMapRow->mPosition.y) {
                return;
            }
            StartModelEffect(3, &bakubaku->mMapObject.mPos, 1);
            firstSoundParams.mSoundId = 0x186;
            firstSoundParams.mPositionSource = &bakubaku->mMapObject.mPos;
            firstSoundParams.mFalloffIndex = 4;
            firstSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bakubaku->mMapObject.mPos);
            StartSoundFromParams(&firstSoundParams);
            bakubaku->mState = 2;
            break;
        case 2:
            bakubaku->mMapObject.mPosStep.y -= 0x400;
            VEC_Add(&bakubaku->mMapObject.mPos, &bakubaku->mMapObject.mPosStep, &bakubaku->mMapObject.mPos);
            if (bakubaku->mMapObject.mPos.y > bakubaku->mMapObject.mCourseMapRow->mPosition.y) {
                return;
            }
            StartModelEffect(3, &bakubaku->mMapObject.mPos, 1);
            secondSoundParams.mSoundId = 0x187;
            secondSoundParams.mPositionSource = &bakubaku->mMapObject.mPos;
            secondSoundParams.mFalloffIndex = 2;
            secondSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bakubaku->mMapObject.mPos);
            StartSoundFromParams(&secondSoundParams);
            bakubaku->mState = 3;
            break;
        case 3:
            bakubaku->mMapObject.mPosStep.y -= 0x400;
            VEC_Add(&bakubaku->mMapObject.mPos, &bakubaku->mMapObject.mPosStep, &bakubaku->mMapObject.mPos);
            if (bakubaku->mMapObject.mPos.y <= bakubaku->mMapObject.mCourseMapRow->mPosition.y - 0x32000) {
                bakubaku->mState4Timer = 0x708;
                bakubaku->mState = 4;
            }
            break;
        case 4:
            if (bakubaku->mState4Timer-- <= 0) {
                bakubaku->mState = 0;
            }
            break;
    }
}

MapObjectList *CreateBakubakuDrawList(void) {
    return CreateMapObjectDrawList1(CreateBakubakuAndBakuShadow, DrawBakubaku, NULL);
}

MapObjectList *CreateBakubakuUpdateList(void) {
    return CreateMapObjectUpdateList(InitBakubakuObjects, UpdateBakubaku, NULL);
}
