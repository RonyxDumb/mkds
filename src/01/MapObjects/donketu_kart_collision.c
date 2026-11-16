#include "01/MapObjects/donketu_kart_collision.h"
#include "01/MapObjects/donketu_repeat_jumps.h"
#include "01/MapObjects/map_object_animation.h"
#include "01/MapObjects/mission_run_range_and_collision_callbacks.h"
#include "01/MapObjects/mission_run_motion_setters.h"
#include "01/MapObjects/mission_run_state_callbacks.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/Sound/sound_start_stop_and_release_wrapper.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "01/MapObjects/donketu.h"

void DonketuKartCollisionCallback(MissionRunMapObject *donketu, Kart *kart) {
    s32 scale;

    if ((GetKart(kart->mIndex)->mDriveFlags & KART_DRIVE_BOOST) && kart->mBoostTimer > 0) {
        if (IsStateNumberBelow(donketu, 8)) {
            if (donketu->mPrm->mDonketu.mHitBoostedVelocityY > 0 ||
                donketu->mPrm->mDonketu.mHitBoostedKartVelocityScale > 0) {
                Vec3 velocityWhenBoosted = {0, 0, 0};
                velocityWhenBoosted.x = kart->mVelocity.x;
                velocityWhenBoosted.z = kart->mVelocity.z;
                if ((s64) velocityWhenBoosted.z * velocityWhenBoosted.z +
                        ((s64) velocityWhenBoosted.x * velocityWhenBoosted.x +
                         (s64) velocityWhenBoosted.y * velocityWhenBoosted.y) >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&velocityWhenBoosted, &velocityWhenBoosted);
                }
                scale = donketu->mPrm->mDonketu.mHitBoostedKartVelocityScale;
                velocityWhenBoosted.x = MUL_FIXED12_NO_ROUND(velocityWhenBoosted.x, scale);
                velocityWhenBoosted.y = MUL_FIXED12_NO_ROUND(velocityWhenBoosted.y, scale);
                velocityWhenBoosted.z = MUL_FIXED12_NO_ROUND(velocityWhenBoosted.z, scale);
                velocityWhenBoosted.y = donketu->mPrm->mDonketu.mHitBoostedVelocityY;
                StartMapObjectState(donketu, DONKETU_STATE_LAUNCH_FALL_LAND, NULL);
                StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mHitBoostedAnimationEntry,
                                            donketu->mPrm->mDonketu.mHitBoostedFrameStep);
                SpinAngleStopMoveAngle(donketu, donketu->mPrm->mDonketu.mHitBoostedAnglePerCall, 0x270f000);
                SetVelocity(donketu, &velocityWhenBoosted);
                SetStoppedCallback(donketu, StartDonketuRepeatJumpsAfterHit);
                SetSpeedAndClearTarget(donketu, 0);
            }
            {
                Vec3 effectPosition;

                VEC_Subtract(&donketu->mMapObject.mPos, &kart->mCollisionCenter, &effectPosition);
                if ((s64) effectPosition.z * effectPosition.z + SQUARE_SUM2(effectPosition.x, effectPosition.y) >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&effectPosition, &effectPosition);
                }
                VEC_MultAdd(kart->mRadius, &effectPosition, &kart->mCollisionCenter, &effectPosition);
                if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_BOSS_DONKETU) {
                    donketu->mMapObject.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                    StopSound(&donketu->mMapObject.mSound->mSoundSource, 0x214);
                    StartMapObjectSound(&donketu->mMapObject, 0x211);
                    StartEffect(0x3e9, &effectPosition);
                    StartEffect(0x3e8, &effectPosition);
                    StartEffect(0x3ea, &effectPosition);
                    StartEffectAtRowHeight(donketu, 0x99a, 0, 0x75c, 0x3f3, 0);
                    StartEffectAtRowHeight(donketu, -0x99a, 0, 0x75c, 0x3f3, 0);
                } else if (donketu->mMapObject.mKind == MAP_OBJECT_KIND_KING_ICE_DONKETU) {
                    donketu->mMapObject.mDistanceSquaredAndFlags |= gDonketuSkipKindSoundFlag;
                    StopSound(&donketu->mMapObject.mSound->mSoundSource, 0x245);
                    StartMapObjectSound(&donketu->mMapObject, 0x23f);
                    StartEffect(0x3fa, &effectPosition);
                    StartEffect(0x3fb, &effectPosition);
                    StartEffect(0x3fc, &effectPosition);
                    StartEffectAtRowHeight(donketu, -0x11ec, 0, 0x1800, 0x445, 0);
                    StartEffectAtRowHeight(donketu, 0x11ec, 0, 0x1800, 0x445, 0);
                }
            }
        }
    } else if (IsStateNumberBelow(donketu, DONKETU_STATE_LAUNCH_FALL_LAND)) {
        if (donketu->mPrm->mDonketu.mHitNotBoostedVelocityY > 0 ||
            donketu->mPrm->mDonketu.mHitNotBoostedKartVelocityScale > 0) {
            Vec3 velocityWhenNotBoosted = {0, 0, 0};
            velocityWhenNotBoosted.x = kart->mVelocity.x;
            velocityWhenNotBoosted.z = kart->mVelocity.z;
            if ((s64) velocityWhenNotBoosted.z * velocityWhenNotBoosted.z +
                    ((s64) velocityWhenNotBoosted.x * velocityWhenNotBoosted.x +
                     (s64) velocityWhenNotBoosted.y * velocityWhenNotBoosted.y) >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&velocityWhenNotBoosted, &velocityWhenNotBoosted);
            }
            scale = donketu->mPrm->mDonketu.mHitNotBoostedKartVelocityScale;
            velocityWhenNotBoosted.x = MUL_FIXED12_NO_ROUND(velocityWhenNotBoosted.x, scale);
            velocityWhenNotBoosted.y = MUL_FIXED12_NO_ROUND(velocityWhenNotBoosted.y, scale);
            velocityWhenNotBoosted.z = MUL_FIXED12_NO_ROUND(velocityWhenNotBoosted.z, scale);
            velocityWhenNotBoosted.y = donketu->mPrm->mDonketu.mHitNotBoostedVelocityY;
            StartMapObjectState(donketu, DONKETU_STATE_LAUNCH_FALL_LAND, NULL);
            StartAnimationNoEndCallback(donketu, donketu->mPrm->mDonketu.mHitNotBoostedAnimationEntry,
                                        donketu->mPrm->mDonketu.mHitNotBoostedFrameStep);
            SpinAngleStopMoveAngle(donketu, donketu->mPrm->mDonketu.mHitNotBoostedAnglePerCall, 0x270f000);
            SetVelocity(donketu, &velocityWhenNotBoosted);
            SetStoppedCallback(donketu, NULL);
            SetSpeedAndClearTarget(donketu, 0);
        }
    }
    SetKartCollisionCallback(donketu, DonketuKartCollisionCallback);
    donketu->mKartResponse = KART_MAP_OBJECT_RESPONSE_CARRY_HALT;
}
