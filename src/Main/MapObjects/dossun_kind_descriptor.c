#include "Main/MapObjects/dossun_kind_descriptor.h"
#include "Main/MapObjects/dossun.h"
#include "Main/System/heap.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_create.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/MapObjects/rock.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "fx_mtx33.h"
#include "code_02148538.h"
#include "Main/MapObjects/nsbmd_model_draw.h"
#include "Main/MapObjects/shadow_model_create.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/data_02158000.h"
#include "Main/MapObjects/choropu.h"
#include "Main/Sound/data_0210b000.h"
#include "Main/MapObjects/wanwan_chain_object.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "code_02147cd8.h"
#include "tp.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/camera.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/MapObjects/code_020d6dc0.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/segment_curve.h"
#include "Main/MapObjects/group_follower_init.h"
#include "Main/MapObjects/update_list_slot.h"
#include "Main/System/heap_call.h"
#include "Main/MapObjects/code_020e66e4.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/MapObjects/kuribo.h"
#include "Main/System/init_after_startup.h"

const Vec3 gKuriboItemNormal = {0, 0x1000, 0};
const MapObjectKindDescriptor gDossunKindDescriptor = {
    0, {0, 0}, 0x10c, InitDossun, CreateDossunKindData, CreateDossunDrawList, 0, 0, CreateDossunUpdateList};

#pragma thumb off

void DrawDossun(void *unused0, Dossun *dossun, void *unused1, s32 maxAlpha) {
    MtxFx43 *drawMatrix;
    drawMatrix = &dossun->mMapObject.mMatrix;
    if (dossun->mHitState != DOSSUN_HIT_NONE) {
        drawMatrix = &gDossunDrawMatrix;
        MTX_RotY33_(&gDossunDrawMatrix.mAxes, FX_SinIdx((u16) dossun->mSpinAngle), FX_CosIdx((u16) dossun->mSpinAngle));
        MTX_Concat33(&gDossunDrawMatrix.mAxes, &dossun->mMapObject.mMatrix.mAxes, &gDossunDrawMatrix.mAxes);
    }
    drawMatrix->mRows[3].x = dossun->mMapObject.mPos.x >> 4;
    drawMatrix->mRows[3].y = dossun->mMapObject.mPos.y >> 4;
    drawMatrix->mRows[3].z = dossun->mMapObject.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gDossun, drawMatrix, &dossun->mMapObject.mScale, maxAlpha);
    DrawShadowWithMaxAlpha(gDossunShadow, drawMatrix, &dossun->mMapObject.mScale, maxAlpha);
}

void UpdateDossun(void *unused, Dossun *dossun) {
    SoundStartParams soundRequest;
    GroupFollower *follower;
    CourseMapGroupEntry *fromEntry;
    s32 stateValue;
    s32 speed;
    s32 followerSpeed;
    s32 sine;
    dossun->mEnteredWaitBeforeFollow = FALSE;
    follower = &dossun->mFollower;
    if (dossun->mHitState != DOSSUN_HIT_NONE) {
        dossun->mSpinAngle += dossun->mSpinSpeed;
        stateValue = dossun->mSpinSpeed;
        if (stateValue > 0x3e8 || stateValue < -0x3e8) {
            if (dossun->mState < DOSSUN_STATE_FOLLOW_ACCELERATING) {
                dossun->mSpinSpeed = (stateValue * 0xfa00) >> 16;
            } else {
                dossun->mSpinSpeed = (stateValue * 0xf80c) >> 16;
            }
        } else if (dossun->mHitState == DOSSUN_HIT_SPIN_SETTLING) {
            if (stateValue * dossun->mSpinAngle <= 0) {
                return;
            }
            if (stateValue * stateValue <= dossun->mSpinAngle * dossun->mSpinAngle) {
                return;
            }
            dossun->mSpinSpeed = 0;
            dossun->mSpinAngle = dossun->mSpinSpeed;
            dossun->mHitState = DOSSUN_HIT_NONE;
            dossun->mKartMask = 0;
            dossun->mTimer = 0x1e;
            dossun->mState = DOSSUN_STATE_WAIT_START;
            return;
        }
        if (dossun->mHitState != DOSSUN_HIT_SLIDING) {
            return;
        }
        speed = follower->mSpeed;
        if (dossun->mState < DOSSUN_STATE_FOLLOW_ACCELERATING) {
            if (speed > 0x4000) {
                followerSpeed = MUL_FIXED12_NO_ROUND(speed, 0xf85);
                follower->mSpeed = followerSpeed;
                follower->mProgressStep = MUL_FIXED12_NO_ROUND(
                    followerSpeed, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            }
        } else {
            if (speed > 0x800) {
                followerSpeed = MUL_FIXED12_NO_ROUND(speed, 0xe66);
                follower->mSpeed = followerSpeed;
                follower->mProgressStep = MUL_FIXED12_NO_ROUND(
                    followerSpeed, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            }
        }
        if (AdvanceGroupFollower(follower) != FALSE) {
            dossun->mMapObject.mPos = follower->mFromEntry->mPos;
            dossun->mMapObject.mPos.y += dossun->mHeightOffset;
            if (follower->mForward != 0) {
                follower->mProgress = 0;
            } else {
                ReverseGroupFollower(follower);
                SetGroupFollowerSegmentEnd(follower);
            }
            dossun->mHitState = DOSSUN_HIT_SPIN_SETTLING;
            return;
        }
        GetGroupFollowerLinearPosition(follower, &dossun->mMapObject.mPos);
        dossun->mMapObject.mPos.y += dossun->mHeightOffset;
        return;
    }
    switch (dossun->mState) {
        case DOSSUN_STATE_WAIT_START:
            dossun->mTimer--;
            if (dossun->mTimer >= 0) {
                return;
            }
            dossun->mState++;
            followerSpeed = dossun->mIsSlowVariant != 0 ? 0xc00 : 0x3000;
            follower->mSpeed = followerSpeed;
            follower->mProgressStep = MUL_FIXED12_NO_ROUND(
                followerSpeed, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            return;
        case DOSSUN_STATE_FOLLOW:
            if (dossun->mIsSlowVariant != 0) {
                StartMapObjectSoundWhileRequested(&dossun->mMapObject, 0x18b);
            }
            break;
        case DOSSUN_STATE_HOVER:
            dossun->mTimer--;
            if (dossun->mTimer < 0 && dossun->mSineAngle < 0x1555) {
                dossun->mState++;
                dossun->mDownSpeedOrFollowerSpeed = -dossun->mInitialUpSpeed;
                return;
            }
            dossun->mSineAngle += 0x1555;
            dossun->mMapObject.mPos.y = dossun->mSineBaseY;
            sine = FX_SinIdx(dossun->mSineAngle);
            dossun->mMapObject.mPos.y += MUL_FIXED12_NO_ROUND(sine, dossun->mSineAmplitude);
            return;
        case DOSSUN_STATE_DROP:
            dossun->mDownSpeedOrFollowerSpeed += dossun->mDownSpeedStep;
            dossun->mMapObject.mPos.y -= dossun->mDownSpeedOrFollowerSpeed;
            if (dossun->mMapObject.mPos.y < dossun->mSineBaseY) {
                dossun->mState++;
            }
            return;
        case DOSSUN_STATE_FOLLOW_ACCELERATING:
            if (dossun->mDownSpeedOrFollowerSpeed < 0x14000) {
                dossun->mDownSpeedOrFollowerSpeed += 0x1000;
                followerSpeed = dossun->mDownSpeedOrFollowerSpeed;
                follower->mSpeed = followerSpeed;
                follower->mProgressStep = MUL_FIXED12_NO_ROUND(
                    followerSpeed, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            }
            break;
        case DOSSUN_STATE_WAIT_BEFORE_FOLLOW:
            dossun->mTimer--;
            if (dossun->mTimer >= 0) {
                return;
            }
            dossun->mState++;
            followerSpeed = dossun->mFollowerSetSpeed;
            follower->mSpeed = followerSpeed;
            follower->mProgressStep = MUL_FIXED12_NO_ROUND(
                followerSpeed, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            return;
        case DOSSUN_STATE_FOLLOW_AT_SET_SPEED:
            break;
    }
    if (AdvanceGroupFollower(follower) != FALSE) {
        switch (follower->mFromEntry->mExtraValue) {
            case DOSSUN_PATH_ENTRY_WAIT_START:
                stateValue = DOSSUN_STATE_WAIT_START;
                break;
            case DOSSUN_PATH_ENTRY_HOVER:
                stateValue = DOSSUN_STATE_HOVER;
                break;
            case DOSSUN_PATH_ENTRY_WAIT_BEFORE_FOLLOW:
                stateValue = DOSSUN_STATE_WAIT_BEFORE_FOLLOW;
                break;
            default:
                stateValue = DOSSUN_STATE_WAIT_START;
                break;
        }
        dossun->mState = stateValue;
        if (dossun->mState == DOSSUN_STATE_HOVER) {
            dossun->mSineBaseY = dossun->mMapObject.mPos.y;
            dossun->mSineAngle = 0;
        }
        if (dossun->mState == DOSSUN_STATE_WAIT_BEFORE_FOLLOW) {
            fromEntry = follower->mFromEntry;
            if (IsMapObjectOutOfRange(&dossun->mMapObject) == FALSE) {
                if (dossun->mMapObject.mFarDistanceSquared == gSoundFalloffs[2].mFarDistanceSquared) {
                    stateValue = 2;
                } else if (dossun->mMapObject.mFarDistanceSquared == gSoundFalloffs[3].mFarDistanceSquared) {
                    stateValue = 3;
                } else {
                    stateValue = 4;
                }
                soundRequest.mSoundId = 0x166;
                soundRequest.mPositionSource = &dossun->mMapObject.mPos;
                soundRequest.mFalloffIndex = stateValue;
                soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&dossun->mMapObject.mPos);
                StartSoundFromParams(&soundRequest);
            }
            StartCameraWobbleAtDistance(dossun->mMapObject.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
            if ((dossun->mMapObject.mDistanceSquaredAndFlags & 3) == 0) {
                StartEffect(0x59, &fromEntry->mPos);
                StartEffect(0x5a, &fromEntry->mPos);
            }
            dossun->mEnteredWaitBeforeFollow = TRUE;
        }
        dossun->mTimer = follower->mFromEntry->mValue;
        if (dossun->mTimer != 0) {
            dossun->mMapObject.mPos = follower->mPath->mSegments[follower->mSegmentIndex].mPoints[0];
            dossun->mMapObject.mPos.y += dossun->mHeightOffset;
            follower->mProgress = 0;
            return;
        }
    }
    GetGroupFollowerLinearPosition(follower, &dossun->mMapObject.mPos);
    dossun->mMapObject.mPos.y += dossun->mHeightOffset;
}

u32 CollideKartWithDossun(Dossun *dossun, Kart *kart, u8 *firstResponsePtr, u8 *secondResponsePtr) {
    Vec3 kartOffset;
    Vec3 toNextEntry;
    Vec3 centerOffset;
    GroupFollower *follower;
    s32 speed;
    s64 verticalScaledSquared;
    s32 verticalOffset;
    s64 horizontalScaledSquared;
    follower = &dossun->mFollower;
    if (*firstResponsePtr == 1) {
        if ((dossun->mKartMask & (1 << kart->mIndex)) == 0 || dossun->mLastHitFrame + 0xf < GetRaceUpdateFrames()) {
            VEC_Subtract(&kart->mCollisionCenter, &dossun->mMapObject.mPos, &kartOffset);
            VEC_Subtract(&follower->mToEntry->mPos, &dossun->mMapObject.mPos, &toNextEntry);
            toNextEntry.y += dossun->mHeightOffset;
            if (Vec3DotUnrounded(&kartOffset, &toNextEntry) > 0) {
                ReverseGroupFollower(follower);
            }
            if (dossun->mState < DOSSUN_STATE_FOLLOW_ACCELERATING) {
                speed = 0xa800;
            } else {
                speed = 0x8000;
            }
            speed = speed - MUL_FIXED12_NO_ROUND(0x1000 - dossun->mMapObject.mScale.y, 0x2000);
            follower->mSpeed = speed;
            follower->mProgressStep =
                MUL_FIXED12_NO_ROUND(speed, follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength);
            dossun->mHitState = DOSSUN_HIT_SLIDING;
            dossun->mSpinSpeed = 0x1b58;
            if ((s64) kartOffset.z * kart->mVelocity.x - (s64) kartOffset.x * kart->mVelocity.z < 0) {
                dossun->mSpinSpeed = -dossun->mSpinSpeed;
            }
            StartSoundIfKartStarOrKiller(&dossun->mMapObject, kart);
            dossun->mKartMask |= 1 << kart->mIndex;
            dossun->mLastHitFrame = GetRaceUpdateFrames();
        }
    }
    if (dossun->mState == DOSSUN_STATE_FOLLOW_ACCELERATING || dossun->mEnteredWaitBeforeFollow != FALSE) {
        VEC_Subtract(&kart->mCollisionCenter, &dossun->mMapObject.mPos, &centerOffset);
        horizontalScaledSquared = (HORIZONTAL_LENGTH_SQUARED(centerOffset)) * 5;
        verticalOffset = centerOffset.y;
        verticalScaledSquared = ((s64) verticalOffset * verticalOffset) << 2;
        if (verticalOffset < 0 && horizontalScaledSquared < verticalScaledSquared) {
            return GetKartMapObjectResponseByKind(dossun->mMapObject.mFlags & 0x800, kart->mItemEffect, 4, 4);
        }
    }
    return *secondResponsePtr;
}

s32 GetDossunMapDotOffset(Dossun *dossun) {
    s32 progress;
    s32 state;
    progress = GetGroupFollowerProgress(&dossun->mFollower);
    state = dossun->mState;
    if (state < DOSSUN_STATE_FOLLOW_ACCELERATING) {
        if (dossun->mIsSlowVariant != 0) {
            return 0;
        }
        return 0x1000;
    }
    switch (dossun->mHitState) {
        case DOSSUN_HIT_NONE:
            switch (state) {
                case DOSSUN_STATE_FOLLOW_ACCELERATING:
                    progress = 0x1000 - progress;
                    break;
                case DOSSUN_STATE_WAIT_BEFORE_FOLLOW:
                    progress = 0;
                    break;
                case DOSSUN_STATE_FOLLOW_AT_SET_SPEED:
                    break;
            }
            break;
        case DOSSUN_HIT_SPIN_SETTLING:
            progress = 0x1000;
            break;
    }
    return progress;
}

#pragma thumb on
void SetupDossunAtStartEntry(Dossun *dossun) {
    GroupFollower *follower;
    s32 state;
    follower = &dossun->mFollower;
    SetupGroupFollowerAtEntry(follower, dossun->mStartEntryIndex, 1);
    GetGroupFollowerLinearPosition(follower, &dossun->mMapObject.mPos);
    dossun->mMapObject.mPos.y += dossun->mHeightOffset;
    switch (follower->mFromEntry->mExtraValue) {
        case DOSSUN_PATH_ENTRY_WAIT_START:
            state = DOSSUN_STATE_WAIT_START;
            break;
        case DOSSUN_PATH_ENTRY_HOVER:
            state = DOSSUN_STATE_HOVER;
            break;
        case DOSSUN_PATH_ENTRY_WAIT_BEFORE_FOLLOW:
            state = DOSSUN_STATE_WAIT_BEFORE_FOLLOW;
            break;
        default:
            state = DOSSUN_STATE_WAIT_START;
            break;
    }
    dossun->mState = state;
    dossun->mTimer = follower->mFromEntry->mValue;
    dossun->mHitState = DOSSUN_HIT_NONE;
    dossun->mSpinAngle = 0;
    dossun->mSpinSpeed = dossun->mSpinAngle;
    dossun->mKartMask = 0;
    dossun->mSineBaseY = dossun->mMapObject.mPos.y;
    dossun->mEnteredWaitBeforeFollow = FALSE;
}
#pragma thumb off

#pragma thumb on
void CreateDossunAndDossunShadow(void) {
    CreateNsbmd(&gDossun, FindCourseMapObjFile("dossun.nsbmd"), NULL);
    CreateShadowModel(&gDossunShadow, FindCourseMapObjFile("dossun_shadow.nsbmd"), 0x3f);
    SetNsbmdPolygonIdLightEmiAll(gDossun, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void InitDossun(Dossun *dossun, CourseMapRow *row) {
    dossun->mIsSlowVariant = row->mSettings[0];
    InitGroupFollower(&dossun->mFollower, row, dossun->mIsSlowVariant != 0 ? 0xc00 : 0x3000);
    dossun->mStartEntryIndex = row->mSettings[1];
    dossun->mXOffset = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.x, 0x28000);
    dossun->mHeightOffset = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0x2d000);
    dossun->mZOffset = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.z, 0x1e000);
    dossun->mInitialUpSpeed = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0xf000);
    dossun->mDownSpeedStep = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0x1000);
    dossun->mFollowerSetSpeed = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0x2000);
    dossun->mSineAmplitude = MUL_FIXED12_NO_ROUND(dossun->mMapObject.mScale.y, 0x3000);
    SetupDossunAtStartEntry(dossun);
    if (dossun->mIsSlowVariant != 0) {
        CreateMapObjectSoundSourceFalloff3(&dossun->mMapObject);
    } else {
        dossun->mMapObject.mFarDistanceSquared = gSoundFalloffs[3].mFarDistanceSquared;
    }
}
#pragma thumb off
