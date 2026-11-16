#pragma once

#include "types.h"

typedef struct SoundDistanceSquaredChange SoundDistanceSquaredChange;
typedef struct Kart Kart;
typedef struct SoundSource SoundSource;

// One row of sound ids of a kart: the table row index, the pitched and clamped pitch sounds, and the sounds chosen by
// speed ratio and accelerator.
typedef struct KartSoundRow {
    /* 00 */ s32 mSoundRowIndex;
    /* 04 */ s32 mPitchedSoundId;
    /* 08 */ s32 mSecondSoundColumn;
    /* 0c */ s32 mThirdSoundColumn;
    /* 10 */ s32 mHighRatioSoundId;
    /* 14 */ s32 mMidRatioSoundId;
    /* 18 */ s32 mLowRatioSoundId;
    /* 1c */ s32 mClampedPitchSoundId;
    /* 20 */ s32 mKeyAHighRatioSoundId;
    /* 24 */ s32 mKeyALowRatioSoundId;
} KartSoundRow;

// KartSound.mSoundIndex values (also Kart.mSoundIndex): one voice set per character, set by InitKartSoundParams.
enum {
    KART_SOUND_SET_DONKEY,
    KART_SOUND_SET_KINOPIO,
    KART_SOUND_SET_KOOPA,
    KART_SOUND_SET_LUIGI,
    KART_SOUND_SET_MARIO,
    KART_SOUND_SET_PEACH,
    KART_SOUND_SET_WARIO,
    KART_SOUND_SET_YOSHI,
    KART_SOUND_SET_DAISY,
    KART_SOUND_SET_WALUIGI,
    KART_SOUND_SET_KARON,
    KART_SOUND_SET_ROBO,
    KART_SOUND_SET_HEYHO,
};

// KartSound.mWhileRequestedSoundId that StopKartSoundWhileRequested compares with and stores once the sound is stopped.
#define KART_SOUND_WHILE_REQUESTED_STOPPED 0xffff

// Values of KartSound.mVolume below SOUND_VOLUME_MAX; KART_SOUND_VOLUME_COAST is also the lowest volume
// StartSoundVolumeFromFractionIfTwo allows.
#define KART_SOUND_VOLUME_PITCHED_NO_ACCEL 0x46
#define KART_SOUND_VOLUME_LOW_REV 0x3c
#define KART_SOUND_VOLUME_COAST 0x32
//  Limits of Kart.mVelocityLengthRatio (1.0 is 0x1000) that UpdateKartSound picks the sound by after the race start,
// except with KART_EFFECT_KILLER and while braking forward on the ground. Without the accelerator: below
// KART_SOUND_LOW_RATIO_LIMIT the low ratio sound, below KART_SOUND_MID_RATIO_LIMIT the mid ratio sound, else the high
// ratio one. With the accelerator held (or the brake held while reversing) and mPrevKeyADown 0: below
// KART_SOUND_KEY_A_LOW_RATIO_LIMIT the key A low ratio sound, else the key A high ratio one.
#define KART_SOUND_LOW_RATIO_LIMIT 0x19a
#define KART_SOUND_KEY_A_LOW_RATIO_LIMIT 0x333
#define KART_SOUND_MID_RATIO_LIMIT 0x4cd

// KartSound.mPitch and mTargetPitch while KART_EFFECT_KILLER is set.
#define KART_SOUND_PITCH_KILLER 0x6c0000

// Sound ids of a Shine16: SHINE16_SOUND_BASE plus these offsets. GetShine16SoundId adds 4 for the entry kart and 3 for
// a hit, else 0, 1 or 2 by how far the kart's count is below the highest count.
#define SHINE16_SOUND_BASE 0x130
enum {
    SHINE16_SOUND_OTHER_AT_HIGHEST,
    SHINE16_SOUND_OTHER_ONE_BELOW_HIGHEST,
    SHINE16_SOUND_OTHER_MORE_BELOW_HIGHEST,
    SHINE16_SOUND_OTHER_HIT,
    SHINE16_SOUND_ENTRY_AT_HIGHEST,
    SHINE16_SOUND_ENTRY_ONE_BELOW_HIGHEST,
    SHINE16_SOUND_ENTRY_MORE_BELOW_HIGHEST,
    SHINE16_SOUND_ENTRY_HIT,
    SHINE16_SOUND_SPAWNED,
    SHINE16_SOUND_BOUNCED,
};

// The sound state of a kart: mSoundId, volume, current and target pitch, pitch rates and the mSoundRow in use.
typedef struct KartSound {
    /* 00 */ s32 mSoundId;
    /* 04 */ u8 mVolume;
    /* 05 */ u8 mUnk_05[3];
    /* 08 */ s32 mPitch;
    /* 0c */ s32 mTargetPitch;
    /* 10 */ s32 mPitchPerCall;
    /* 14 */ s32 mPrevKeyADown;
    /* 18 */ s32 mPitchPerSpeedOverLimit;
    /* 1c */ s32 mPitchPerSpeedKeyA;
    /* 20 */ s32 mPitchPerSpeedNoKeyA;
    /* 24 */ s32 mPitchPerSpeedKeyB;
    /* 28 */ s32 mLapProgressAtLastSound;
    /* 2c */ u8 mLapProgressSoundCount;
    /* 2d */ u8 mUnk_2d[3];
    /* 30 */ s32 mLastSeqArcSoundRaceFrame;
    /* 34 */ s32 mThunderShrinkRaceFrame;
    /* 38 */ s32 mWhileRequestedSoundId;
    /* 3c */ u32 (*mDistanceChangeFunction)(SoundDistanceSquaredChange *change);
    /* 40 */ KartSoundRow mSoundRow;
    /* 68 */ s32 mSoundIndex;
} KartSound;

typedef struct SoundDistanceSquaredChange SoundDistanceSquaredChange;
typedef struct Kart Kart;
typedef struct KartSound KartSound;

s32 GetShine16SoundId(s32 value, s32 isEntryKart, u32 highestBalloonOrShineCount, u32 balloonOrShineCount);
void StartBalloonScaleSound(Kart *kart, s32 scale, s32 scalePerFrame);
void StartSoundVolumeFromFractionIfTwo(SoundSource *soundSource, u16 soundId, s32 fraction, s32 value);
void UpdateKartSound(Kart *kart);
s32 AdvanceKartSoundPitch(KartSound *soundRecord, s32 pitch, s32 aboveSpeedLimit);
void StartKartClampedPitchSound(Kart *kart, KartSound *soundRecord);
void StartKartSurfaceSoundWithPitch(Kart *kart, KartSound *soundRecord);
void StartKartLowRatioSound(Kart *kart, KartSound *soundRecord);
void StartKartSound(Kart *kart, KartSound *soundRecord);
u32 InitKartSoundPitchFactors(void);

extern u32 gPitchRiseDivisor;
extern u32 gPitchFallDivisor;
extern u32 gPitchRiseAboveLimitDivisor;
extern const u8 gSurfaceSoundVolumeByRatio[20];
extern s32 gPitchRiseFactorAboveLimit;
extern s32 gPitchRiseFactor;
extern s32 gPitchFallFactor;
