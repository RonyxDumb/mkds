#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct SoundSource SoundSource;

// Ten words at 0x40 of a KartSound, built on the stack by func_020719d0.
typedef struct Unk02024eec_40 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mHighRatioSoundId;
    /* 14 */ s32 mMidRatioSoundId;
    /* 18 */ s32 mLowRatioSoundId;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
} Unk02024eec_40;

// The bytes from 0x450 of an Kart, which func_02024a88 and func_02024eec read and write.
typedef struct KartSound {
    /* 00 */ s32 mSoundId;
    /* 04 */ u8 mVolume;
    /* 05 */ u8 mUnk_05[3];
    /* 08 */ s32 mPitch;
    /* 0c */ s32 mTargetPitch;
    /* 10 */ s32 mPitchPerCall;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mPitchPerSpeedOverLimit;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mLapProgressAtLastSound;
    /* 2c */ u8 mLapProgressSoundCount;
    /* 2d */ u8 mUnk_2d[3];
    /* 30 */ s32 mLastSeqArcSoundRaceFrame;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ UnkWordFunc *mUnk_3c;
    /* 40 */ Unk02024eec_40 mUnk_40;
    /* 68 */ s32 mUnk_68;
} KartSound;

typedef struct Kart Kart;
typedef struct KartSound KartSound;

s32 func_02024974(s32 a, s32 b, u32 c, u32 d);
void func_020249b8(Kart *kart, s32 b, s32 c);
void func_02024a28(SoundSource *soundSource, u16 soundId, s32 b, s32 c);
void func_02024a88(Kart *kart);
s32 func_02024eec(KartSound *soundRecord, s32 b, s32 c);
void func_02024fc0(Kart *kart, KartSound *soundRecord);
void func_02024fe8(Kart *kart, KartSound *soundRecord);
void func_02025030(Kart *kart, KartSound *soundRecord);
void func_0202506c(Kart *kart, KartSound *soundRecord);
u32 func_020250a8(void);
