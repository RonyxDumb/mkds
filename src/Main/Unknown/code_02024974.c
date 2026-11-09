#include "Main/Unknown/code_02024974.h"

#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210bafc.h"
#include "code_02147cd8.h"

u32 InitKartSoundPitchFactors(void) {
    u32 quotient;
    u32 divisor;

    divisor = *(const u32 *) &data_02161ae4;
    quotient = FX_Div(0x1000, divisor);
    divisor = *(const u32 *) &data_02161ae0;
    gPitchRiseFactor = quotient;
    quotient = FX_Div(0x1000, divisor);
    divisor = *(const u32 *) &data_02161adc;
    gPitchFallFactor = quotient;
    quotient = FX_Div(0x1000, divisor);
    gPitchRiseFactorAboveLimit = quotient;
    return quotient;
}

void func_0202506c(Kart *kart, KartSound *soundRecord) {
    PlayingSound *playingSound;

    playingSound = StartSoundWhileRequested(&kart->mSoundSource, soundRecord->mSoundId, soundRecord->mVolume,
                                            (soundRecord->mPitch << 4) >> 16);
    if (playingSound != NULL) {
        playingSound->mFlags |= 0x80;
    }
}

void func_02025030(Kart *kart, KartSound *soundRecord) {
    PlayingSound *playingSound;

    playingSound = StartSoundWhileRequested(&kart->mSoundSource, soundRecord->mUnk_40.mLowRatioSoundId,
                                            soundRecord->mVolume, (soundRecord->mPitch << 4) >> 16);
    if (playingSound != NULL) {
        playingSound->mFlags |= 0x80;
    }
}

void func_02024fe8(Kart *kart, KartSound *soundRecord) {
    u32 soundId;

    soundId = GetSurfaceSoundId(3, kart->mSurfaceKind, kart->mSurfaceVariant);
    StartSoundWhileRequested(&kart->mSoundSource, soundId, soundRecord->mVolume, (soundRecord->mPitch << 4) >> 16);
}

void func_02024fc0(Kart *kart, KartSound *soundRecord) {
    s32 clampedValue;

    clampedValue = soundRecord->mPitch;
    if (clampedValue > 0x440000) {
        clampedValue = 0x440000;
    }
    StartSoundWhileRequested(&kart->mSoundSource, soundRecord->mUnk_40.mUnk_1c, soundRecord->mVolume,
                             (clampedValue << 4) >> 16);
}

s32 func_02024eec(KartSound *soundRecord, s32 b, s32 aboveSpeedLimit) {
    s32 currentValue;
    s32 previousTarget;
    s32 step;
    s32 targetHighBits;
    s32 factor;

    currentValue = soundRecord->mPitch;
    previousTarget = soundRecord->mTargetPitch;
    step = soundRecord->mPitchPerCall;
    if (currentValue == -1) {
        b = 0;
        step = b;
        soundRecord->mTargetPitch = b;
    } else {
        targetHighBits = b & 0x7fff0000;
        if ((currentValue & 0x7fff0000) == targetHighBits) {
            soundRecord->mTargetPitch = b;
            step = 0;
        } else if ((previousTarget & 0x7fff0000) != targetHighBits) {
            soundRecord->mTargetPitch = b;
            if (b < currentValue) {
                factor = gPitchFallFactor;
            } else if (aboveSpeedLimit != 0) {
                factor = gPitchRiseFactorAboveLimit;
            } else {
                factor = gPitchRiseFactor;
            }
            step = MUL_FIXED12_ROUNDED(factor, b - currentValue);
            b = step + currentValue;
        } else if (step != 0) {
            b = step + currentValue;
        }
    }
    if (b > 0x880000) {
        b = 0x880000;
    }
    if (b < 0) {
        b = 0;
    }
    soundRecord->mPitchPerCall = step;
    return b;
}

void func_02024a88(Kart *kart) {
    KartSound *soundRecord;
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 baseSpeedLimit;
    s32 velocityLength;
    s32 aboveSpeedLimit;
    s32 kartFlags;

    soundRecord = &kart->mUnk_450;
    kartFlags = kart->mUnk_48;
    f = (kartFlags & 2) != 0 ? 1 : 0;
    g = (kartFlags & 4) != 0 ? 1 : 0;
    if ((kart->mUnk_4c & 0x10000000) != 0) {
        soundRecord->mPitch = 0x6c0000;
        soundRecord->mTargetPitch = 0x6c0000;
        soundRecord->mPitchPerCall = 0;
        if (f != 0) {
            soundRecord->mSoundId = soundRecord->mUnk_40.mUnk_20;
        } else {
            soundRecord->mSoundId = soundRecord->mUnk_40.mHighRatioSoundId;
        }
        soundRecord->mUnk_14 = f;
        soundRecord->mVolume = 0x46;
        StartSoundWhileRequested(&kart->mSoundSource, 0xfc, 0x7f, 0);
        return;
    }
    if ((s32) GetRaceUpdateFrames() < 5) {
        return;
    }
    if (gSceneSoundState.mRaceState == 0) {
        h = kart->mUnk_4d4;
        if (h > 0xcd && gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_CPU) {
            if (f != 0) {
                if ((kart->mUnk_4c & KART_4C_HEADING_SWING) != 0) {
                    i = 0;
                } else {
                    i = MUL_FIXED12_ROUNDED(h, 0x580000);
                }
                g = func_02024eec(&kart->mUnk_450, i, 0);
                soundRecord->mVolume = 0x7f;
                soundRecord->mSoundId = soundRecord->mUnk_40.mUnk_04;
                AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                                (void (*)(void *, int)) func_02024fc0, kart, (s32) soundRecord);
            } else {
                i = MUL_FIXED12_ROUNDED(h, 0x480000);
                g = func_02024eec(&kart->mUnk_450, i, 0);
                soundRecord->mVolume = 0x46;
                soundRecord->mSoundId = soundRecord->mUnk_40.mUnk_04;
                AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                                (void (*)(void *, int)) func_02024fc0, kart, (s32) soundRecord);
            }
        } else {
            soundRecord->mTargetPitch = 0;
            soundRecord->mPitchPerCall = 0;
            soundRecord->mVolume = 0x3c;
            AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                            (void (*)(void *, int)) func_02025030, kart, (s32) soundRecord);
            g = -1;
        }
        soundRecord->mPitch = g;
        soundRecord->mUnk_14 = f;
        return;
    }
    baseSpeedLimit = kart->mPhysicalParam->mBaseSpeedLimit;
    velocityLength = kart->mVelocityLength;
    h = velocityLength - baseSpeedLimit;
    aboveSpeedLimit = h > 0 ? 1 : 0;
    if (g != 0 && kart->mForwardSpeed > 0 && (kart->mUnk_44 & KART_44_ON_GROUND) != 0) {
        g = MUL_FIXED12_ROUNDED(soundRecord->mUnk_24, velocityLength);
        if (g > 0x280000) {
            g = 0x280000;
        }
        soundRecord->mVolume = data_02153158[(kart->mVelocityLengthRatio >> 8) & 0xff];
        AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                        (void (*)(void *, int)) func_02024fe8, kart, (s32) soundRecord);
    } else if (f != 0 || (g != 0 && kart->mForwardSpeed < 0)) {
        if (aboveSpeedLimit != 0) {
            i = MUL_FIXED12_ROUNDED(h, soundRecord->mPitchPerSpeedOverLimit) + 0x580000;
        } else {
            i = MUL_FIXED12_ROUNDED(soundRecord->mUnk_1c, velocityLength);
        }
        g = func_02024eec(&kart->mUnk_450, i, aboveSpeedLimit);
        soundRecord->mVolume = 0x7f;
        if (soundRecord->mUnk_14 == 0) {
            soundRecord->mSoundId =
                kart->mVelocityLengthRatio < 0x333 ? soundRecord->mUnk_40.mUnk_24 : soundRecord->mUnk_40.mUnk_20;
        }
        AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                        (void (*)(void *, int)) func_0202506c, kart, (s32) soundRecord);
    } else {
        if (aboveSpeedLimit != 0) {
            i = MUL_FIXED12_ROUNDED(h, soundRecord->mPitchPerSpeedOverLimit) + 0x480000;
        } else {
            i = MUL_FIXED12_ROUNDED(soundRecord->mUnk_20, velocityLength);
        }
        g = func_02024eec(&kart->mUnk_450, i, aboveSpeedLimit);
        soundRecord->mVolume = 0x32;
        if (kart->mVelocityLengthRatio < 0x19a) {
            soundRecord->mSoundId = soundRecord->mUnk_40.mLowRatioSoundId;
        } else if (kart->mVelocityLengthRatio < 0x4cd) {
            soundRecord->mSoundId = soundRecord->mUnk_40.mMidRatioSoundId;
        } else {
            soundRecord->mSoundId = soundRecord->mUnk_40.mHighRatioSoundId;
        }
        AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                        (void (*)(void *, int)) func_0202506c, kart, (s32) soundRecord);
    }
    soundRecord->mPitch = g;
    soundRecord->mUnk_14 = f;
}

void func_02024a28(SoundSource *soundSource, u16 soundId, s32 b, s32 c) {
    u8 t;
    u8 volume;

    if (c == 2) {
        t = (b << 7) >> 12;
        volume = t + 0x14;
        if (volume > 0x7f) {
            volume = 0x7f;
        } else if (volume < 0x32) {
            volume = 0x32;
        }
    } else {
        volume = 0x7f;
    }
    StartSoundEx(soundSource, 0, soundId, volume, 0);
}

void func_020249b8(Kart *kart, s32 b, s32 c) {
    s32 pitch;
    u8 volume;

    if (b <= 0) {
        return;
    }
    if (b >= 0x1000) {
        return;
    }
    pitch = (b << 14) >> 16;
    volume = (b << 7) >> 12;
    if (pitch > 0x400) {
        pitch = 0x400;
    }
    if (volume > 0x7f) {
        volume = 0x7f;
    }
    StartSoundWhileRequested(&kart->mSoundSource, c > 0 ? 0x150 : 0x151, volume, pitch);
}

s32 func_02024974(s32 a, s32 b, u32 c, u32 d) {
    s32 soundOffset;
    s32 t;

    soundOffset = b != 0 ? 4 : 0;
    if (a == 0) {
        if (c == d) {
            t = 0;
        } else if (c == d + 1) {
            t = 1;
        } else {
            t = 2;
        }
        soundOffset += t;
    } else {
        soundOffset += 3;
    }
    return soundOffset + 0x130;
}
