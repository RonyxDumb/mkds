#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct SoundSource SoundSource;

// Ten words at 0x40 of a KartSound, built on the stack by InitKartSoundParams.
typedef struct KartSoundRow {
    /* 00 */ s32 mSoundRowIndex;
    /* 04 */ s32 mPitchedSoundId;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
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

// The bytes from 0x450 of an Kart, which UpdateKartSound and AdvanceKartSoundPitch read and write.
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
    /* 3c */ UnkWordFunc *mDistanceChangeFunction;
    /* 40 */ KartSoundRow mSoundRow;
    /* 68 */ s32 mSoundIndex;
} KartSound;

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
