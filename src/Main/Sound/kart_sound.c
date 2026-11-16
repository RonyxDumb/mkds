#include "Main/Sound/kart_sound.h"

#include "Main/Race/race.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_start.h"
#include "Main/Sound/playing_sounds.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "Main/Sound/surface_sound_ids.h"
#include "fixed_vector_math.h"

u32 gPitchRiseAboveLimitDivisor = 0x19000;
u32 gPitchRiseDivisor = 0x8000;
u32 gPitchFallDivisor = 0x28000;
s32 gKartSoundRowSoundIds[3][7] = {{0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2},
                                   {0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9},
                                   {0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0}};
const u8 gSurfaceSoundVolumeByRatio[20] = {0,    0,    0x1e, 0x28, 0x32, 0x3c, 0x46, 0x50, 0x5a, 0x64,
                                           0x6e, 0x78, SOUND_VOLUME_MAX, SOUND_VOLUME_MAX, SOUND_VOLUME_MAX, SOUND_VOLUME_MAX, SOUND_VOLUME_MAX, 0,    0,    0};
s32 gPitchFallFactor;
s32 gPitchRiseFactor;
s32 gPitchRiseFactorAboveLimit;

u32 InitKartSoundPitchFactors(void) {
    u32 quotient;
    u32 divisor;

    divisor = gPitchRiseDivisor;
    quotient = FX_Div(0x1000, divisor);
    divisor = gPitchFallDivisor;
    gPitchRiseFactor = quotient;
    quotient = FX_Div(0x1000, divisor);
    divisor = gPitchRiseAboveLimitDivisor;
    gPitchFallFactor = quotient;
    quotient = FX_Div(0x1000, divisor);
    gPitchRiseFactorAboveLimit = quotient;
    return quotient;
}

void StartKartSound(Kart *kart, KartSound *soundRecord) {
    PlayingSound *playingSound;

    playingSound = StartSoundWhileRequested(&kart->mSoundSource, soundRecord->mSoundId, soundRecord->mVolume,
                                            (soundRecord->mPitch << 4) >> 16);
    if (playingSound != NULL) {
        playingSound->mFlags |= PLAYING_SOUND_FLAG_KART_SOUND_RECORD;
    }
}

void StartKartLowRatioSound(Kart *kart, KartSound *soundRecord) {
    PlayingSound *playingSound;

    playingSound = StartSoundWhileRequested(&kart->mSoundSource, soundRecord->mSoundRow.mLowRatioSoundId,
                                            soundRecord->mVolume, (soundRecord->mPitch << 4) >> 16);
    if (playingSound != NULL) {
        playingSound->mFlags |= PLAYING_SOUND_FLAG_KART_SOUND_RECORD;
    }
}

void StartKartSurfaceSoundWithPitch(Kart *kart, KartSound *soundRecord) {
    u32 soundId;

    soundId = GetSurfaceSoundId(3, kart->mSurfaceKind, kart->mSurfaceVariant);
    StartSoundWhileRequested(&kart->mSoundSource, soundId, soundRecord->mVolume, (soundRecord->mPitch << 4) >> 16);
}

void StartKartClampedPitchSound(Kart *kart, KartSound *soundRecord) {
    s32 clampedValue;

    clampedValue = soundRecord->mPitch;
    if (clampedValue > 0x440000) {
        clampedValue = 0x440000;
    }
    StartSoundWhileRequested(&kart->mSoundSource, soundRecord->mSoundRow.mClampedPitchSoundId, soundRecord->mVolume,
                             (clampedValue << 4) >> 16);
}

s32 AdvanceKartSoundPitch(KartSound *soundRecord, s32 pitch, s32 aboveSpeedLimit) {
    s32 currentValue;
    s32 previousTarget;
    s32 step;
    s32 targetHighBits;
    s32 factor;

    currentValue = soundRecord->mPitch;
    previousTarget = soundRecord->mTargetPitch;
    step = soundRecord->mPitchPerCall;
    if (currentValue == -1) {
        pitch = 0;
        step = pitch;
        soundRecord->mTargetPitch = pitch;
    } else {
        targetHighBits = pitch & 0x7fff0000;
        if ((currentValue & 0x7fff0000) == targetHighBits) {
            soundRecord->mTargetPitch = pitch;
            step = 0;
        } else if ((previousTarget & 0x7fff0000) != targetHighBits) {
            soundRecord->mTargetPitch = pitch;
            if (pitch < currentValue) {
                factor = gPitchFallFactor;
            } else if (aboveSpeedLimit != 0) {
                factor = gPitchRiseFactorAboveLimit;
            } else {
                factor = gPitchRiseFactor;
            }
            step = MUL_FIXED12_ROUNDED(factor, pitch - currentValue);
            pitch = step + currentValue;
        } else if (step != 0) {
            pitch = step + currentValue;
        }
    }
    if (pitch > 0x880000) {
        pitch = 0x880000;
    }
    if (pitch < 0) {
        pitch = 0;
    }
    soundRecord->mPitchPerCall = step;
    return pitch;
}

void UpdateKartSound(Kart *kart) {
    KartSound *soundRecord;
    s32 accelHeld;
    s32 pitch;
    s32 value;
    s32 targetPitch;
    s32 baseSpeedLimit;
    s32 velocityLength;
    s32 aboveSpeedLimit;
    s32 kartFlags;

    soundRecord = &kart->mSound;
    kartFlags = kart->mDriveFlags;
    accelHeld = (kartFlags & KART_DRIVE_ACCEL_HELD) != 0 ? 1 : 0;
    pitch = (kartFlags & KART_DRIVE_BRAKE_HELD) != 0 ? 1 : 0;
    if ((kart->mEffectFlags & KART_EFFECT_KILLER) != 0) {
        soundRecord->mPitch = KART_SOUND_PITCH_KILLER;
        soundRecord->mTargetPitch = KART_SOUND_PITCH_KILLER;
        soundRecord->mPitchPerCall = 0;
        if (accelHeld != 0) {
            soundRecord->mSoundId = soundRecord->mSoundRow.mKeyAHighRatioSoundId;
        } else {
            soundRecord->mSoundId = soundRecord->mSoundRow.mHighRatioSoundId;
        }
        soundRecord->mPrevKeyADown = accelHeld;
        soundRecord->mVolume = KART_SOUND_VOLUME_KILLER;
        StartSoundWhileRequested(&kart->mSoundSource, 0xfc, SOUND_VOLUME_MAX, 0);
        return;
    }
    if ((s32) GetRaceUpdateFrames() < 5) {
        return;
    }
    if (gSceneSoundState.mRaceState == SCENE_RACE_STATE_BEFORE_START) {
        value = kart->mRevLevel;
        if (value > 0xcd && gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_CPU) {
            if (accelHeld != 0) {
                if ((kart->mEffectFlags & KART_EFFECT_HEADING_SWING) != 0) {
                    targetPitch = 0;
                } else {
                    targetPitch = MUL_FIXED12_ROUNDED(value, 0x580000);
                }
                pitch = AdvanceKartSoundPitch(&kart->mSound, targetPitch, 0);
                soundRecord->mVolume = SOUND_VOLUME_MAX;
                soundRecord->mSoundId = soundRecord->mSoundRow.mRevSoundId;
                AddSoundRequest(&gSoundRequestQueues[1], GetKartCameraDistanceSquared(kart->mIndex),
                                (void (*)(void *, int)) StartKartClampedPitchSound, kart, (s32) soundRecord);
            } else {
                targetPitch = MUL_FIXED12_ROUNDED(value, 0x480000);
                pitch = AdvanceKartSoundPitch(&kart->mSound, targetPitch, 0);
                soundRecord->mVolume = KART_SOUND_VOLUME_REV_NO_ACCEL;
                soundRecord->mSoundId = soundRecord->mSoundRow.mRevSoundId;
                AddSoundRequest(&gSoundRequestQueues[1], GetKartCameraDistanceSquared(kart->mIndex),
                                (void (*)(void *, int)) StartKartClampedPitchSound, kart, (s32) soundRecord);
            }
        } else {
            soundRecord->mTargetPitch = 0;
            soundRecord->mPitchPerCall = 0;
            soundRecord->mVolume = KART_SOUND_VOLUME_LOW_RATIO_BEFORE_START;
            AddSoundRequest(&gSoundRequestQueues[1], GetKartCameraDistanceSquared(kart->mIndex),
                            (void (*)(void *, int)) StartKartLowRatioSound, kart, (s32) soundRecord);
            pitch = -1;
        }
        soundRecord->mPitch = pitch;
        soundRecord->mPrevKeyADown = accelHeld;
        return;
    }
    baseSpeedLimit = kart->mPhysicalParam->mBaseSpeedLimit;
    velocityLength = kart->mVelocityLength;
    value = velocityLength - baseSpeedLimit;
    aboveSpeedLimit = value > 0 ? 1 : 0;
    if (pitch != 0 && kart->mForwardSpeed > 0 && (kart->mMotionFlags & KART_MOTION_ON_GROUND) != 0) {
        pitch = MUL_FIXED12_ROUNDED(soundRecord->mPitchPerSpeedKeyB, velocityLength);
        if (pitch > 0x280000) {
            pitch = 0x280000;
        }
        soundRecord->mVolume = gSurfaceSoundVolumeByRatio[(kart->mVelocityLengthRatio >> 8) & 0xff];
        AddSoundRequest(&gSoundRequestQueues[1], GetKartCameraDistanceSquared(kart->mIndex),
                        (void (*)(void *, int)) StartKartSurfaceSoundWithPitch, kart, (s32) soundRecord);
    } else if (accelHeld != 0 || (pitch != 0 && kart->mForwardSpeed < 0)) {
        if (aboveSpeedLimit != 0) {
            targetPitch = MUL_FIXED12_ROUNDED(value, soundRecord->mPitchPerSpeedOverLimit) + 0x580000;
        } else {
            targetPitch = MUL_FIXED12_ROUNDED(soundRecord->mPitchPerSpeedKeyA, velocityLength);
        }
        pitch = AdvanceKartSoundPitch(&kart->mSound, targetPitch, aboveSpeedLimit);
        soundRecord->mVolume = SOUND_VOLUME_MAX;
        if (soundRecord->mPrevKeyADown == 0) {
            soundRecord->mSoundId = kart->mVelocityLengthRatio < KART_SOUND_KEY_A_LOW_RATIO_LIMIT
                                        ? soundRecord->mSoundRow.mKeyALowRatioSoundId
                                        : soundRecord->mSoundRow.mKeyAHighRatioSoundId;
        }
        AddSoundRequest(&gSoundRequestQueues[1], GetKartCameraDistanceSquared(kart->mIndex),
                        (void (*)(void *, int)) StartKartSound, kart, (s32) soundRecord);
    } else {
        if (aboveSpeedLimit != 0) {
            targetPitch = MUL_FIXED12_ROUNDED(value, soundRecord->mPitchPerSpeedOverLimit) + 0x480000;
        } else {
            targetPitch = MUL_FIXED12_ROUNDED(soundRecord->mPitchPerSpeedNoKeyA, velocityLength);
        }
        pitch = AdvanceKartSoundPitch(&kart->mSound, targetPitch, aboveSpeedLimit);
        soundRecord->mVolume = KART_SOUND_VOLUME_COAST;
        if (kart->mVelocityLengthRatio < KART_SOUND_LOW_RATIO_LIMIT) {
            soundRecord->mSoundId = soundRecord->mSoundRow.mLowRatioSoundId;
        } else if (kart->mVelocityLengthRatio < KART_SOUND_MID_RATIO_LIMIT) {
            soundRecord->mSoundId = soundRecord->mSoundRow.mMidRatioSoundId;
        } else {
            soundRecord->mSoundId = soundRecord->mSoundRow.mHighRatioSoundId;
        }
        AddSoundRequest(&gSoundRequestQueues[1], GetKartCameraDistanceSquared(kart->mIndex),
                        (void (*)(void *, int)) StartKartSound, kart, (s32) soundRecord);
    }
    soundRecord->mPitch = pitch;
    soundRecord->mPrevKeyADown = accelHeld;
}

void StartSoundVolumeFromFractionIfTwo(SoundSource *soundSource, u16 soundId, s32 fraction, s32 value) {
    u8 scaledVolume;
    u8 volume;

    if (value == 2) {
        scaledVolume = (fraction << 7) >> 12;
        volume = scaledVolume + 0x14;
        if (volume > SOUND_VOLUME_MAX) {
            volume = SOUND_VOLUME_MAX;
        } else if (volume < KART_SOUND_VOLUME_COAST) {
            volume = KART_SOUND_VOLUME_COAST;
        }
    } else {
        volume = SOUND_VOLUME_MAX;
    }
    StartSoundEx(soundSource, 0, soundId, volume, 0);
}

void StartBalloonScaleSound(Kart *kart, s32 scale, s32 scalePerFrame) {
    s32 pitch;
    u8 volume;

    if (scale <= 0) {
        return;
    }
    if (scale >= 0x1000) {
        return;
    }
    pitch = (scale << 14) >> 16;
    volume = (scale << 7) >> 12;
    if (pitch > 0x400) {
        pitch = 0x400;
    }
    if (volume > SOUND_VOLUME_MAX) {
        volume = SOUND_VOLUME_MAX;
    }
    StartSoundWhileRequested(&kart->mSoundSource, scalePerFrame > 0 ? 0x150 : 0x151, volume, pitch);
}

s32 GetShine16SoundId(s32 value, s32 isEntryKart, u32 highestBalloonOrShineCount, u32 balloonOrShineCount) {
    s32 soundOffset;
    s32 countGap;

    soundOffset = isEntryKart != 0 ? 4 : 0;
    if (value == 0) {
        if (highestBalloonOrShineCount == balloonOrShineCount) {
            countGap = 0;
        } else if (highestBalloonOrShineCount == balloonOrShineCount + 1) {
            countGap = 1;
        } else {
            countGap = 2;
        }
        soundOffset += countGap;
    } else {
        soundOffset += 3;
    }
    return soundOffset + SHINE16_SOUND_BASE;
}
