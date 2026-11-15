#include "Main/MapObjects/chandelier_rain_star.h"
#include "Main/MapObjects/chandelier.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/chandelier_draw.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/start_sound_from_params.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "touch_panel_sampling.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/bound.h"
#include "Main/System/init_after_startup.h"

MapObjectModel *gRainStar;

MapObjectKindDescriptor gRainStarKindDescriptor = {
    0, {0, 0}, 0xa4, 0, CreateEmptyMapObjectKindData, CreateRainStarDrawList, 0, 0, CreateRainStarUpdateList};

void InitChandelierObjects(MapObjectList *objectList) {
    s32 objectIndex;
    Chandelier *chandelier;
    RandomState64 *random;

    if (objectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < objectList->mMapObjectCount && (chandelier = objectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        random = &gRaceProgress->mLocalRandom;
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        chandelier->mTimer = (u16) (((u64) (u32) (random->mValue >> 32) * 0x3c) >> 32) + 0x3c;
    }
}

void UpdateChandelier(void *mapObjectList, Chandelier *chandelier) {
    SoundStartParams firstSoundParams;
    SoundStartParams secondSoundParams;
    SoundStartParams thirdSoundParams;
    s32 falloffIndex;
    s32 nextFrameIndex;

    switch (chandelier->mState) {
        case CHANDELIER_STATE_WAIT:
            if (chandelier->mTimer-- <= 0) {
                chandelier->mState = CHANDELIER_STATE_ANIMATE;
            }
            return;
        case CHANDELIER_STATE_ANIMATE:
            break;
        default:
            return;
    }
    if (chandelier->mFrameIndex == CHANDELIER_FIRST_SOUND_EARLY_FRAME ||
        chandelier->mFrameIndex == CHANDELIER_FIRST_SOUND_LATE_FRAME) {
        if ((chandelier->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
            if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            firstSoundParams.mSoundId = CHANDELIER_FIRST_SOUND_ID;
            firstSoundParams.mPositionSource = &chandelier->mMapObject.mPos;
            firstSoundParams.mFalloffIndex = falloffIndex;
            firstSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&chandelier->mMapObject.mPos);
            StartSoundFromParams(&firstSoundParams);
        }
    } else if (chandelier->mFrameIndex == CHANDELIER_SECOND_SOUND_EARLY_FRAME ||
               chandelier->mFrameIndex == CHANDELIER_SECOND_SOUND_LATE_FRAME) {
        if ((chandelier->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
            if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            secondSoundParams.mSoundId = CHANDELIER_SECOND_SOUND_ID;
            secondSoundParams.mPositionSource = &chandelier->mMapObject.mPos;
            secondSoundParams.mFalloffIndex = falloffIndex;
            secondSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&chandelier->mMapObject.mPos);
            StartSoundFromParams(&secondSoundParams);
        }
    } else if (chandelier->mFrameIndex == CHANDELIER_THIRD_SOUND_FRAME) {
        if ((chandelier->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
            if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (chandelier->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            thirdSoundParams.mSoundId = CHANDELIER_THIRD_SOUND_ID;
            thirdSoundParams.mPositionSource = &chandelier->mMapObject.mPos;
            thirdSoundParams.mFalloffIndex = falloffIndex;
            thirdSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&chandelier->mMapObject.mPos);
            StartSoundFromParams(&thirdSoundParams);
        }
    }
    nextFrameIndex = chandelier->mFrameIndex + 1;
    if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gChandelier)) {
        nextFrameIndex = 0;
    }
    chandelier->mFrameIndex = nextFrameIndex;
    if (chandelier->mFrameIndex == 0) {
        chandelier->mState = CHANDELIER_STATE_WAIT;
    }
}

MapObjectList *CreateChandelierDrawList(void) {
    return CreateMapObjectDrawList1(CreateChandelier, DrawChandelier, NULL);
}

MapObjectList *CreateChandelierUpdateList(void) {
    return CreateMapObjectUpdateList(InitChandelierObjects, UpdateChandelier, NULL);
}

void CreateRainStar(void *mapObjectList) {
    CreateMapObjectModelNsbtaAnimation(gRainStar = CreateMapObjectModelAnimated(mapObjectList, "RainStar.nsbmd"),
                                       "RainStar.nsbta");
    SetMapObjectModelPolygonId(gRainStar, 0x3f);
}

void DrawRainStar(void *mapObjectList, RainStar *rainStar) {
    u32 commandParam;
    MtxFx33 rotationMatrix;

    commandParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandParam, 1);
    rainStar->mMapObject.mMatrix.mRows[3].x = rainStar->mMapObject.mPos.x >> 4;
    rainStar->mMapObject.mMatrix.mRows[3].y = rainStar->mMapObject.mPos.y >> 4;
    rainStar->mMapObject.mMatrix.mRows[3].z = rainStar->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &rainStar->mMapObject.mMatrix, 0xc);
    if (rainStar->mMapObject.mAngle != 0) {
        MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE(rainStar->mMapObject.mAngle),
                    COS_OF_ANGLE(rainStar->mMapObject.mAngle));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &rainStar->mMapObject.mScale, 3);
    SetMapObjectModelNsbtaFrameIndex(gRainStar, rainStar->mFrameIndex);
    DrawMapObjectModel(mapObjectList, gRainStar, rainStar);
}

void UpdateRainStar(void *mapObjectList, RainStar *rainStar) {
    u16 frameCount;

    frameCount = GetMapObjectModelNsbtaFrameCount(gRainStar);
    rainStar->mFrameIndex += 1;
    if (rainStar->mFrameIndex >= frameCount) {
        rainStar->mFrameIndex = 0;
    }
    rainStar->mMapObject.mAngle += 0x111;
}

MapObjectList *CreateRainStarDrawList(void) {
    return CreateMapObjectDrawList1(CreateRainStar, DrawRainStar, NULL);
}

MapObjectList *CreateRainStarUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateRainStar, NULL);
}
