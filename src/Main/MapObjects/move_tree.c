#include "Main/MapObjects/move_tree.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/bakubaku.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
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
#include "Main/MapObjects/data_0217c000.h"
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

MapObjectModel *gMoveTree;

MapObjectKindDescriptor gMoveTreeKindDescriptor = {0,
                                                   {0, 0},
                                                   0x110,
                                                   InitMoveTree,
                                                   CreateMoveTreeKindData,
                                                   CreateMoveTreeDrawList,
                                                   0,
                                                   0,
                                                   CreateMoveTreeUpdateList};

void InitMoveTree(MoveTree *moveTree) {
    InitGroupFollower(&moveTree->mFollower, moveTree->mMapObject.mCourseMapRow, 0);
}

u8 CollideKartWithMoveTree(MoveTree *moveTree, Kart *kart, u8 *firstResponse, u8 *response) {
    u8 responseValue;

    responseValue = *response;
    if (moveTree->mState <= 1) {
        moveTree->mKartHitFramesLeft = 30;
    }
    return responseValue;
}

void CreateMoveTree(void *mapObjectList) {
    gMoveTree = CreateMapObjectModelAnimated(mapObjectList, "move_tree.nsbmd");
    CreateMapObjectModelNsbcaAnimation(gMoveTree, "move_tree.nsbca");
    SetMapObjectModelPolygonId(gMoveTree, 0x3f);
}

void DrawMoveTree(void *mapObjectList, MoveTree *moveTree, u32 unused, u32 alpha) {
    s32 gxParam;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&moveTree->mMapObject.mPos), 12);
    NNS_G3dGeBufferOP_N(0x1b, &moveTree->mMapObject.mScale, 3);
    if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) < 0xc5c10) {
        SetMapObjectModelNsbcaFrameIndex(gMoveTree, moveTree->mNsbcaFrameIndex);
        DrawMapObjectModel(mapObjectList, gMoveTree, moveTree);
    } else {
        DrawMapObjectModel1Mat1Shp(mapObjectList, gMoveTree, moveTree);
    }
    if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) >= 0x27100) {
        return;
    }
    SetShadowPositionXZ(&moveTree->mShadowMatrix, &moveTree->mMapObject.mPos);
    DrawObjShadow(&moveTree->mShadowMatrix, NULL, unused, alpha);
}

void InitMoveTreeObjects(MapObjectList *mapObjectList) {
    s32 mapObjectIndex;
    MoveTree *moveTree;

    if (mapObjectList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < mapObjectList->mMapObjectCount &&
                             (moveTree = mapObjectList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        moveTree->mFollowerSpeed = TO_FIXED12(moveTree->mMapObject.mCourseMapRow->mSettings[0]) / 100;
        RefreshShadowMatrix(&moveTree->mShadowMatrix, &moveTree->mMapObject.mPos, 0x54666, 14);
    }
}

void UpdateMoveTree(void *mapObjectList, MoveTree *moveTree) {
    SoundStartParams firstSoundParams;
    SoundStartParams secondSoundParams;
    u32 falloffIndex;
    s32 speed;

    switch (moveTree->mState) {
        case 0:
            moveTree->mFollower.mSpeed = 0;
            moveTree->mFollower.mProgressStep = 0;
            if (moveTree->mState0Timer-- <= 0) {
                moveTree->mState = 1;
            }
            if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (moveTree->mKartHitFramesLeft-- > 0) {
                moveTree->mNsbcaFrameStep = 2;
                moveTree->mNsbcaFrameIndex += moveTree->mNsbcaFrameStep;
                if (moveTree->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gMoveTree)) {
                    moveTree->mNsbcaFrameIndex = 0;
                }
                return;
            }
            if (moveTree->mNsbcaFrameIndex == 0) {
                return;
            }
            moveTree->mNsbcaFrameIndex += moveTree->mNsbcaFrameStep;
            if (moveTree->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gMoveTree)) {
                moveTree->mNsbcaFrameIndex = 0;
            }
            if (moveTree->mNsbcaFrameIndex != 0 && moveTree->mNsbcaFrameIndex != 0x1e) {
                return;
            }
            if ((moveTree->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) != 0) {
                return;
            }
            if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            firstSoundParams.mSoundId = 0x11f;
            firstSoundParams.mPositionSource = &moveTree->mMapObject.mPos;
            firstSoundParams.mFalloffIndex = falloffIndex;
            firstSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&moveTree->mMapObject.mPos);
            StartSoundFromParams(&firstSoundParams);
            break;
        case 1:
            speed = moveTree->mFollowerSpeed;
            moveTree->mFollower.mSpeed = speed;
            moveTree->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
                speed, moveTree->mFollower.mPath->mSegments[moveTree->mFollower.mSegmentIndex].mInverseProgressLength);
            if (AdvanceGroupFollower(&moveTree->mFollower) != FALSE) {
                moveTree->mState0Timer = (u16) moveTree->mFollower.mFromEntry->mValue;
                moveTree->mState = 0;
            }
            GetGroupFollowerLinearXz(&moveTree->mFollower, &moveTree->mMapObject.mPos);
            if ((s32) (moveTree->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (moveTree->mKartHitFramesLeft-- > 0) {
                moveTree->mNsbcaFrameStep = 2;
            } else {
                moveTree->mNsbcaFrameStep = 1;
            }
            moveTree->mNsbcaFrameIndex += moveTree->mNsbcaFrameStep;
            if (moveTree->mNsbcaFrameIndex >= GetMapObjectModelNsbcaFrameCount(gMoveTree)) {
                moveTree->mNsbcaFrameIndex = 0;
            }
            if (moveTree->mNsbcaFrameIndex != 0 && moveTree->mNsbcaFrameIndex != 0x1e) {
                return;
            }
            if ((moveTree->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) != 0) {
                return;
            }
            if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                falloffIndex = 2;
            } else if (moveTree->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            secondSoundParams.mSoundId = 0x11f;
            secondSoundParams.mPositionSource = &moveTree->mMapObject.mPos;
            secondSoundParams.mFalloffIndex = falloffIndex;
            secondSoundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&moveTree->mMapObject.mPos);
            StartSoundFromParams(&secondSoundParams);
    }
}

MapObjectKindData *CreateMoveTreeKindData(void) {
    return CreateMapObjectKindDataWithSound(CollideKartWithMoveTree, NULL, NULL, 2, 1, 0x125);
}

MapObjectList *CreateMoveTreeDrawList(void) {
    return CreateMapObjectDrawList1(CreateMoveTree, DrawMoveTree, NULL);
}

MapObjectList *CreateMoveTreeUpdateList(void) {
    return CreateMapObjectUpdateList(InitMoveTreeObjects, UpdateMoveTree, NULL);
}
