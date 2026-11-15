#include "Main/MapObjects/pakkun.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/group_paths.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "fx_mtx33.h"
#include "code_02148538.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/bound.h"

const u16 gFlipperMirrorFlag = 0x400;
const u32 gFlipperSkipSoundFlag = 0x40000000;

MapObjectKindDescriptor gPakkunKindDescriptor = {0,
                                                 {0, 0},
                                                 0x200,
                                                 InitPakkun,
                                                 CreateEmptyMapObjectKindData,
                                                 CreatePakkunMouthDrawList,
                                                 CreatePakkunBodyDrawList,
                                                 CreatePakkunZHeadDrawList,
                                                 CreatePakkunUpdateList};
MapObjectList *gPakkunMouthDrawList;
MapObjectList *gPakkunZHeadDrawList;
MapObjectList *gPakkunUpdateList;
MapObjectModel *gPakkunMouth;
void *gPakkunZHead;
void *gPakkunBodyDrawList;
void *gPakkunBody;

MapObjectList *CreatePakkunSpitUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdatePakkunSpit, NULL);
}

void StartPakkunSpit(GroupFollower *groupFollower, s32 heightOffset) {
    PakkunSpit *pakkunSpit;
    pakkunSpit = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(0x1ab));
    if (pakkunSpit == NULL) {
        return;
    }
    pakkunSpit->mMapObject.mFlags = pakkunSpit->mMapObject.mFlags & ~1;
    pakkunSpit->mMapObject.mFlags = pakkunSpit->mMapObject.mFlags & ~8;
    pakkunSpit->mMapObject.mFlags = pakkunSpit->mMapObject.mFlags & ~2;
    pakkunSpit->mMapObject.mFlags = pakkunSpit->mMapObject.mFlags & ~8;
    pakkunSpit->mMapObject.mAlpha = MAP_OBJECT_ALPHA_MAX;
    pakkunSpit->mFollower.mGroupIndex = groupFollower->mGroupIndex;
    pakkunSpit->mFollower.mPath = groupFollower->mPath;
    SetupGroupFollowerAtEntry(&pakkunSpit->mFollower, 0, 1);
    pakkunSpit->mFollower.mSpeed = 0x7800;
    pakkunSpit->mFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
        pakkunSpit->mFollower.mPath->mSegments[pakkunSpit->mFollower.mSegmentIndex].mInverseProgressLength, 0x7800);
    pakkunSpit->mHeightOffset = heightOffset;
    pakkunSpit->mHeightSpeed = -0x5000;
    pakkunSpit->mState = 0;
    pakkunSpit->mEmitter = StartEffect(0x33, &pakkunSpit->mMapObject.mPos);
}

void InitPakkun(Pakkun *pakkun) {
    s32 setting;
    s32 angleDelta;
    Vec3 position;
    Vec3 step;
    s32 followerIndex;
    pakkun->mBaseYaw =
        (u32) (((s64) pakkun->mMapObject.mCourseMapRow->mRotationDegrees.y * 0xb60b60b60bLL + 0x80000000000LL) >>
               32 << 4) >>
        16;
    pakkun->mBodyStretchActive = TRUE;
    pakkun->mBodyStretch = 0x1000;
    pakkun->mBodyStretchSpeed = 0;
    pakkun->mHeadScale = 0x1000;
    pakkun->mHeadScaleSpeed = 0;
    pakkun->mHeadHeight = 0x46000;
    for (followerIndex = 0; followerIndex < 7; followerIndex++) {
        pakkun->mFollowers[followerIndex].mGroupIndex = GROUP_FOLLOWER_NO_GROUP;
    }
    for (followerIndex = 0; followerIndex < 7; followerIndex++) {
        if (followerIndex == 0) {
            setting = pakkun->mMapObject.mCourseMapRow->mSettings[0];
        } else if (followerIndex == 1) {
            setting = pakkun->mMapObject.mCourseMapRow->mSettings[1];
        } else if (followerIndex == 2) {
            setting = pakkun->mMapObject.mCourseMapRow->mSettings[2];
        } else if (followerIndex == 3) {
            setting = pakkun->mMapObject.mCourseMapRow->mSettings[3];
        } else if (followerIndex == 4) {
            setting = pakkun->mMapObject.mCourseMapRow->mSettings[4];
        } else if (followerIndex == 5) {
            setting = pakkun->mMapObject.mCourseMapRow->mSettings[5];
        } else {
            setting = pakkun->mMapObject.mCourseMapRow->mSettings[6];
        }
        if (setting >= 0) {
            InitGroupFollowerForGroup(&pakkun->mFollowers[pakkun->mFollowerCount], setting, 100);
            GetGroupFollowerLinearPosStep(&pakkun->mFollowers[pakkun->mFollowerCount], &position, &step);
            angleDelta = FX_Atan2Idx(step.x, step.z) - pakkun->mBaseYaw;
            if (angleDelta > 0x8000) {
                angleDelta -= 0x10000;
            }
            pakkun->mFollowerYawOffsets[pakkun->mFollowerCount] = angleDelta;
            pakkun->mHeightAboveFollowerPath = pakkun->mMapObject.mPos.y - position.y;
            pakkun->mFollowerCount++;
        }
    }
    pakkun->mPolygonId = AllocPolygonId();
    CreateParkedMapObjects(0x1ab, 0x14, pakkun);
}

void CreatePakkunMouth(void *mapObjectList) {
    gPakkunMouth = CreateMapObjectModelAnimated(mapObjectList, "PakkunMouth.nsbmd");
    CreateMapObjectModelNsbcaAnimation(gPakkunMouth, "PakkunMouth.nsbca");
    SetMapObjectModelAlpha(gPakkunMouth, 0x1f);
}

static inline u32 PakkunMapObjectRandomBelowU16(u32 limit) {
    RandomState64 *mapObjectRandom;
    u32 value;
    u32 limitU16;
    if (limit == 0x10000) {
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue =
            mapObjectRandom->mIncrement + (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue;
        return (u16) ((mapObjectRandom->mValue >> 32) * 0x10000 >> 32);
    }
    mapObjectRandom = GetMapObjectRandom();
    limitU16 = (u16) limit;
    if (limitU16 == 0) {
        value = 0;
    } else {
        mapObjectRandom->mValue =
            mapObjectRandom->mIncrement + (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue;
        if (limitU16 == 0) {
            value = mapObjectRandom->mValue >> 32;
        } else {
            value = ((mapObjectRandom->mValue >> 32) * limitU16) >> 32;
        }
    }
    return (u16) value;
}

void DrawPakkunMouth(void *mapObjectList, Pakkun *pakkun) {
    s32 gxParam;
    MtxFx33 yawMatrix;
    MtxFx33 pitchMatrix;
    s32 translation[3];
    s32 scale[3];
    s32 scaleValue;
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    pakkun->mMapObject.mMatrix.mRows[3].x = pakkun->mMapObject.mPos.x >> 4;
    pakkun->mMapObject.mMatrix.mRows[3].y = pakkun->mMapObject.mPos.y >> 4;
    pakkun->mMapObject.mMatrix.mRows[3].z = pakkun->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &pakkun->mMapObject.mMatrix, 12);
    translation[1] = pakkun->mHeadHeight >> 4;
    translation[0] = 0;
    translation[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, translation, 3);
    if (pakkun->mHeadYaw != 0) {
        MTX_RotY33_(&yawMatrix, FX_SinIdx((u16) pakkun->mHeadYaw), FX_CosIdx((u16) pakkun->mHeadYaw));
        NNS_G3dGeBufferOP_N(0x1a, &yawMatrix, 9);
    }
    if (pakkun->mHeadPitch != 0) {
        MTX_RotX33_(&pitchMatrix, FX_SinIdx((u16) pakkun->mHeadPitch), FX_CosIdx((u16) pakkun->mHeadPitch));
        NNS_G3dGeBufferOP_N(0x1a, &pitchMatrix, 9);
    }
    scaleValue = pakkun->mHeadScale;
    scale[0] = scaleValue;
    scale[1] = scaleValue;
    scale[2] = scaleValue;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    NNS_G3dGeBufferOP_N(0x1b, &pakkun->mMapObject.mScale, 3);
    SetMapObjectModelPolygonId(gPakkunMouth, pakkun->mPolygonId);
    SetMapObjectModelNsbcaFrameIndex(gPakkunMouth, FROM_FIXED12(pakkun->mMouthFrame));
    DrawMapObjectModel(mapObjectList, gPakkunMouth, pakkun);
}

void CreatePakkunZHead(void *mapObjectList) {
    gPakkunZHead = CreateMapObjectModelNsbmd(mapObjectList, "PakkunZHead.nsbmd");
    SetMapObjectModelAlpha(gPakkunZHead, 0x1e);
}

void SetupDrawPakkunZHead(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gPakkunZHead);
}

void DrawPakkunZHead(void *mapObjectList, Pakkun *pakkun) {
    s32 gxParam;
    Vec3 position;
    s32 scale[3];
    s32 scaleValue;
    position.x = pakkun->mMapObject.mPos.x;
    position.y = pakkun->mMapObject.mPos.y + pakkun->mHeadHeight;
    position.z = pakkun->mMapObject.mPos.z;
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&position), 12);
    scaleValue = pakkun->mHeadScale;
    scale[0] = scaleValue;
    scale[1] = scaleValue;
    scale[2] = scaleValue;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    NNS_G3dGeBufferOP_N(0x1b, &pakkun->mMapObject.mScale, 3);
    SetMapObjectModelPolygonId(gPakkunZHead, pakkun->mPolygonId);
    DrawMapObjectModel(mapObjectList, gPakkunZHead, pakkun);
}

void CreatePakkunBody(void *mapObjectList) {
    gPakkunBody = CreateMapObjectModelNsbmd(mapObjectList, "PakkunBody.nsbmd");
    SetMapObjectModelPolygonId(gPakkunBody, 0x3f);
    SetMapObjectModelAlpha(gPakkunBody, 0x1f);
}

void SetupDrawPakkunBody(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gPakkunBody);
}

void DrawPakkunBody(void *mapObjectList, Pakkun *pakkun) {
    s32 gxParam;
    s32 scale[3];
    s32 sideScale;
    s32 secondValue;
    s32 firstValue;
    firstValue = pakkun->mBodyStretch;
    secondValue = pakkun->mHeadScale;
    sideScale = 0x3000 - firstValue - secondValue;
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewRotatedMatrixPos(&pakkun->mMapObject.mPos), 12);
    scale[0] = sideScale;
    scale[1] = firstValue + secondValue - 0x1000;
    scale[2] = sideScale;
    NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    NNS_G3dGeBufferOP_N(0x1b, &pakkun->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gPakkunBody, pakkun);
}

void InitPakkunObjects(void) {
    s32 mapObjectIndex;
    Pakkun *pakkun;
    float frame;
    if (gPakkunUpdateList == NULL) {
        return;
    }
    for (mapObjectIndex = 0; mapObjectIndex < gPakkunUpdateList->mMapObjectCount &&
                             (pakkun = gPakkunUpdateList->mMapObjects[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        if (GetMapObjectModelNsbcaFrameCount(gPakkunMouth) - 1 > 0) {
            frame = 0.5f + TO_FIXED12(GetMapObjectModelNsbcaFrameCount(gPakkunMouth) - 1);
        } else {
            frame = TO_FIXED12(GetMapObjectModelNsbcaFrameCount(gPakkunMouth) - 1) - 0.5f;
        }
        pakkun->mMouthFrame = 0;
        pakkun->mMouthFrameStep = 0x1000;
        pakkun->mMouthLoopFrame = 0;
        pakkun->mMouthEndFrame = frame;
        pakkun->mHeadPitch = -0xa4;
    }
}

void UpdatePakkun(void *mapObjectList, Pakkun *pakkun) {
    BOOL flag;
    s32 falloffIndex;
    s32 firstOffset;
    s32 secondOffset;
    SoundStartParams soundParams;
    switch (pakkun->mState) {
        case PAKKUN_STATE_PICK_TARGET:
            pakkun->mFollowerIndex += PakkunMapObjectRandomBelowU16((u16) (pakkun->mFollowerCount - 1)) + 1;
            if (pakkun->mFollowerIndex >= pakkun->mFollowerCount) {
                pakkun->mFollowerIndex -= pakkun->mFollowerCount;
            }
            pakkun->mState = PAKKUN_STATE_TURN_HEAD;
        case PAKKUN_STATE_TURN_HEAD:
            flag = FALSE;
            if (pakkun->mHeadYaw < pakkun->mFollowerYawOffsets[pakkun->mFollowerIndex]) {
                pakkun->mHeadYaw = pakkun->mHeadYaw + 0x6d;
                if (pakkun->mHeadYaw >= pakkun->mFollowerYawOffsets[pakkun->mFollowerIndex]) {
                    flag = TRUE;
                }
            } else {
                pakkun->mHeadYaw = pakkun->mHeadYaw - 0x6d;
                if (pakkun->mHeadYaw <= pakkun->mFollowerYawOffsets[pakkun->mFollowerIndex]) {
                    flag = TRUE;
                }
            }
            if (flag != FALSE) {
                if (PakkunMapObjectRandomBelowU16(2) == 0) {
                    pakkun->mState = PAKKUN_STATE_WAIT_BODY_SETTLE;
                } else {
                    pakkun->mState = PAKKUN_STATE_PICK_TARGET;
                }
            }
            break;
        case PAKKUN_STATE_WAIT_BODY_SETTLE:
            if (pakkun->mBodyStretchSpeed >= -4 && pakkun->mBodyStretchSpeed <= 4) {
                pakkun->mTimer = 0x1e;
                pakkun->mState = PAKKUN_STATE_LEAN_BACK;
            }
            break;
        case PAKKUN_STATE_LEAN_BACK:
            if (pakkun->mTimer-- <= 0) {
                pakkun->mTimer = 0;
                if (pakkun->mBodyStretch >= 0xffc) {
                    pakkun->mBodyStretch = 0x1000;
                    pakkun->mBodyStretchActive = FALSE;
                    pakkun->mHeadScaleSpeed = 0x7b;
                    pakkun->mState = PAKKUN_STATE_GROW_HEAD;
                }
            } else {
                pakkun->mHeadPitch = pakkun->mHeadPitch + 0xa4;
            }
            break;
        case PAKKUN_STATE_GROW_HEAD:
            pakkun->mHeadScale = pakkun->mHeadScale + pakkun->mHeadScaleSpeed;
            pakkun->mHeadScaleSpeed = pakkun->mHeadScaleSpeed - 8;
            if (pakkun->mHeadScaleSpeed <= 0) {
                if (pakkun->mHeadScale <= 0x119a) {
                    pakkun->mState = PAKKUN_STATE_SPIT;
                }
            }
            break;
        case PAKKUN_STATE_SPIT:
            pakkun->mHeadScale = pakkun->mHeadScale + pakkun->mHeadScaleSpeed;
            pakkun->mHeadScaleSpeed = pakkun->mHeadScaleSpeed - 8;
            if (pakkun->mHeadScale <= 0x1000) {
                pakkun->mHeadScale = 0x1000;
                pakkun->mBodyStretchActive = TRUE;
            }
            pakkun->mMouthFrame = pakkun->mMouthFrame + pakkun->mMouthFrameStep;
            if (pakkun->mMouthFrame >= pakkun->mMouthEndFrame) {
                pakkun->mMouthFrame = pakkun->mMouthLoopFrame;
            }
            if (FROM_FIXED12(pakkun->mMouthFrame) == 10) {
                StartPakkunSpit(&pakkun->mFollowers[pakkun->mFollowerIndex],
                                pakkun->mHeightAboveFollowerPath + 0x46000);
                if ((pakkun->mMapObject.mDistanceSquaredAndFlags & MAP_OBJECT_VIEW_BEYOND_FAR_DISTANCE) == 0) {
                    if (pakkun->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                        falloffIndex = 2;
                    } else if (pakkun->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                        falloffIndex = 3;
                    } else {
                        falloffIndex = 4;
                    }
                    soundParams.mSoundId = PAKKUN_SPIT_SOUND_ID;
                    soundParams.mPositionSource = &pakkun->mMapObject.mPos;
                    soundParams.mFalloffIndex = falloffIndex;
                    soundParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(&pakkun->mMapObject.mPos);
                    StartSoundFromParams(&soundParams);
                }
            } else if (pakkun->mMouthFrame == 0) {
                pakkun->mTimer = 0x1e;
                pakkun->mState = PAKKUN_STATE_LEAN_FORWARD;
            }
            break;
        case PAKKUN_STATE_LEAN_FORWARD:
            if (pakkun->mTimer-- <= 0) {
                pakkun->mTimer = 0;
                pakkun->mState = PAKKUN_STATE_PICK_TARGET;
            } else {
                pakkun->mHeadPitch = pakkun->mHeadPitch - 0xa4;
            }
            break;
    }
    if (pakkun->mBodyStretchActive != FALSE) {
        pakkun->mBodyStretch = pakkun->mBodyStretch + pakkun->mBodyStretchSpeed;
        pakkun->mBodyStretchSpeed = pakkun->mBodyStretchSpeed + 4;
        if (pakkun->mBodyStretch >= 0x1000) {
            pakkun->mBodyStretchSpeed = -0x52;
        }
    }
    firstOffset = MUL_FIXED12_NO_ROUND(pakkun->mBodyStretch + pakkun->mHeadScale - 0x1000, 0x2f000);
    secondOffset = MUL_FIXED12_NO_ROUND(pakkun->mHeadScale, 0x17000);
    pakkun->mHeadHeight = firstOffset + secondOffset;
}

MapObjectList *CreatePakkunMouthDrawList(void) {
    gPakkunMouthDrawList = CreateMapObjectDrawList1(CreatePakkunMouth, DrawPakkunMouth, NULL);
    gPakkunMouthDrawList->mSortByDistance = TRUE;
    SetDrawListSlot(&gPakkunMouthDrawList);
    return gPakkunMouthDrawList;
}

MapObjectList *CreatePakkunBodyDrawList(void) {
    gPakkunBodyDrawList = CreateMapObjectDrawList2(CreatePakkunBody, DrawPakkunBody, SetupDrawPakkunBody);
    SetDrawListSlot(&gPakkunBodyDrawList);
    return gPakkunBodyDrawList;
}

MapObjectList *CreatePakkunZHeadDrawList(void) {
    gPakkunZHeadDrawList = CreateMapObjectDrawList2(CreatePakkunZHead, DrawPakkunZHead, SetupDrawPakkunZHead);
    gPakkunZHeadDrawList->mSortByDistance = TRUE;
    SetDrawListSlot(&gPakkunZHeadDrawList);
    return gPakkunZHeadDrawList;
}

MapObjectList *CreatePakkunUpdateList(void) {
    gPakkunUpdateList = CreateMapObjectUpdateList(InitPakkunObjects, UpdatePakkun, NULL);
    SetUpdateListSlot(&gPakkunUpdateList);
    return gPakkunUpdateList;
}
