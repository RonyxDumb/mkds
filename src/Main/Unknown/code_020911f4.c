#include "Main/MapObjects/sman.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/System/archive_slots.h"
#include "Main/Kart/kart_effects_ahead.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_0207ff5c.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Kart/kart_ai_item_throw.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Save/backup_reset.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/MapObjects/sun.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Item/item_pool.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_021458c4.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/MapObjects/sman_with.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0207e654.h"
#include "code_02147cd8.h"

void CreateSmanTop(void *mapObjectList) {
    MapObjectModel *mapObjectModelNsbmd;
    mapObjectModelNsbmd = CreateMapObjectModelNsbmd(mapObjectList, gSmanTopNsbmdName);
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
    mapObjectModelNsbmd = CreateMapObjectModelNsbmd(mapObjectList, gSmanBottomNsbmdName);
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
        sman->mTopRiseProgress = 0x1000;
        sman->mBottomScale = 0x1000;
        index++;
        sman->mTopStartHeight = MUL_FIXED12_NO_ROUND(sman->mMapObject.mScale.y, 0xf333);
        sman->mTopLowHeight = MUL_FIXED12_NO_ROUND(sman->mMapObject.mScale.y, 0x2000);
        sman->mTopHeight = sman->mTopStartHeight;
    }
}

void UpdateSman(void *mapObjectList, Sman *sman) {
    SoundStartParams soundRequest;
    s32 falloffIndex;
    switch (sman->mState) {
        case 0:
            sman->mAngleZEnabled = 1;
            break;
        case 1:
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
                sman->mState = 2;
                falloffIndex = 2;
                if ((sman->mMapObject.mDistanceSquaredAndFlags & 4) == 0) {
                    if (sman->mMapObject.mFarDistanceSquared != gSoundFalloffs[2].mFarDistanceSquared) {
                        if (sman->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                            falloffIndex = 3;
                        } else {
                            falloffIndex = 4;
                        }
                    }
                    soundRequest.mSoundId = 0x162;
                    soundRequest.mPositionSource = &sman->mMapObject.mPos;
                    soundRequest.mFalloffIndex = falloffIndex;
                    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sman->mMapObject.mPos);
                    StartSoundFromParams(&soundRequest);
                }
            }
            sman->mAngleZEnabled = 0;
            break;
        case 2:
            sman->mStateFrames = sman->mStateFrames + 1;
            if (sman->mStateFrames >= 0x12b) {
                sman->mStateFrames = 0;
                sman->mTopHeightPerFrame = ((sman->mTopStartHeight - sman->mTopLowHeight) * 0x40) / 0x1000;
                sman->mState = 3;
            }
            sman->mAngleZEnabled = 0;
            break;
        case 3:
            if (sman->mTopRiseProgress >= 0x1000) {
                sman->mTopRiseProgress = 0x1000;
                sman->mTopHeight = sman->mTopStartHeight;
            } else {
                sman->mTopRiseProgress = sman->mTopRiseProgress + 0x40;
                sman->mTopHeight = sman->mTopHeight + sman->mTopHeightPerFrame;
            }
            sman->mStateFrames = sman->mStateFrames + 1;
            if (sman->mStateFrames > 10) {
                sman->mBottomScale = sman->mBottomScale + 0x40;
                if (sman->mBottomScale >= 0x1000) {
                    sman->mStateFrames = 0;
                    sman->mBottomScale = 0x1000;
                    sman->mMapObject.mFlags = sman->mMapObject.mFlags & ~1;
                    sman->mState = 0;
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
            sman->mAngleZPerFrame = -0xf0;
        } else {
            sman->mAngleZPerFrame = sman->mAngleZPerFrame - 8;
        }
    } else {
        if (sman->mAngleZPerFrame >= 0) {
            sman->mAngleZPerFrame = 0xf0;
        } else {
            sman->mAngleZPerFrame = sman->mAngleZPerFrame + 8;
        }
    }
}

// Creates the kind record of Sman with two functions that put it into state 1 when their third argument points to 1.
void CreateSmanKindData(void) {
    CreateMapObjectKindDataWithSound(CollideKartWithSman, CollideItemObjectWithSman, NULL, 0, 1, 0x161);
}

void *CreateSmanTopDrawList(void) {
    return CreateMapObjectDrawList2(CreateSmanTop, DrawSmanTop, SetupDrawSmanTop);
}

void *CreateSmanBottomDrawList(void) {
    return CreateMapObjectDrawList2(CreateSmanBottom, DrawSmanBottom, SetupDrawSmanBottom);
}

void *CreateSmanUpdateList(void) {
    return CreateMapObjectUpdateList(InitSmanObjects, UpdateSman, NULL);
}
