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

u32 sub_20250A8(void) {
    u32 quotient;
    u32 divisor;

    divisor = *(const u32 *) &data_02161ae4;
    quotient = FX_Div(0x1000, divisor);
    divisor = *(const u32 *) &data_02161ae0;
    data_02174e10 = quotient;
    quotient = FX_Div(0x1000, divisor);
    divisor = *(const u32 *) &data_02161adc;
    data_02174e0c = quotient;
    quotient = FX_Div(0x1000, divisor);
    data_02174e08 = quotient;
    return quotient;
}

void func_0202506c(Kart *kart, KartSound *soundRecord) {
    PlayingSound *playingSound;

    playingSound = StartSoundWhileRequested(&kart->mSoundSource, soundRecord->field0, soundRecord->field4,
                                            (soundRecord->field8 << 4) >> 16);
    if (playingSound != NULL) {
        playingSound->mFlags |= 0x80;
    }
}

void func_02025030(Kart *kart, KartSound *soundRecord) {
    PlayingSound *playingSound;

    playingSound = StartSoundWhileRequested(&kart->mSoundSource, soundRecord->field58, soundRecord->field4,
                                            (soundRecord->field8 << 4) >> 16);
    if (playingSound != NULL) {
        playingSound->mFlags |= 0x80;
    }
}

void func_02024fe8(Kart *kart, KartSound *soundRecord) {
    u32 soundId;

    soundId = csfx_getFloorSfx(3, kart->mSurfaceKind, kart->mSurfaceVariant);
    StartSoundWhileRequested(&kart->mSoundSource, soundId, soundRecord->field4, (soundRecord->field8 << 4) >> 16);
}

void func_02024fc0(Kart *kart, KartSound *soundRecord) {
    s32 clampedValue;

    clampedValue = soundRecord->field8;
    if (clampedValue > 0x440000) {
        clampedValue = 0x440000;
    }
    StartSoundWhileRequested(&kart->mSoundSource, soundRecord->field5C, soundRecord->field4,
                             (clampedValue << 4) >> 16);
}

s32 sub_2024EEC(KartSound *soundRecord, s32 b, s32 c) {
    s32 currentValue;
    s32 previousTarget;
    s32 step;
    s32 targetHighBits;
    s32 factor;

    currentValue = soundRecord->field8;
    previousTarget = soundRecord->fieldC;
    step = soundRecord->field10;
    if (currentValue == -1) {
        b = 0;
        step = b;
        soundRecord->fieldC = b;
    } else {
        targetHighBits = b & 0x7fff0000;
        if ((currentValue & 0x7fff0000) == targetHighBits) {
            soundRecord->fieldC = b;
            step = 0;
        } else if ((previousTarget & 0x7fff0000) != targetHighBits) {
            soundRecord->fieldC = b;
            if (b < currentValue) {
                factor = data_02174e0c;
            } else if (c != 0) {
                factor = data_02174e08;
            } else {
                factor = data_02174e10;
            }
            step = ((s64) factor * (b - currentValue) + 0x800) >> 12;
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
    soundRecord->field10 = step;
    return b;
}

void sub_2024A88(Kart *kart) {
    KartSound *soundRecord;
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 baseSpeedLimit;
    s32 velocityLength;
    s32 aboveSpeedLimit;
    s32 kartFlags;

    soundRecord = (KartSound *) &kart->field450;
    kartFlags = kart->field48;
    f = (kartFlags & 2) != 0 ? 1 : 0;
    g = (kartFlags & 4) != 0 ? 1 : 0;
    if ((kart->field4C & 0x10000000) != 0) {
        soundRecord->field8 = 0x6c0000;
        soundRecord->fieldC = 0x6c0000;
        soundRecord->field10 = 0;
        if (f != 0) {
            soundRecord->field0 = soundRecord->field60;
        } else {
            soundRecord->field0 = soundRecord->field50;
        }
        soundRecord->field14 = f;
        soundRecord->field4 = 0x46;
        StartSoundWhileRequested(&kart->mSoundSource, 0xfc, 0x7f, 0);
        return;
    }
    if ((s32) race_getFrameCounter() < 5) {
        return;
    }
    if (gSceneSoundState.mRaceState == 0) {
        h = kart->field4D4;
        if (h > 0xcd && gRaceMultiConfig->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_CPU) {
            if (f != 0) {
                if ((kart->field4C & KART_4C_HEADING_SWING) != 0) {
                    i = 0;
                } else {
                    i = ((s64) h * 0x580000 + 0x800) >> 12;
                }
                g = sub_2024EEC((KartSound *) &kart->field450, i, 0);
                soundRecord->field4 = 0x7f;
                soundRecord->field0 = soundRecord->field44;
                AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                                (void (*)(void *, int)) func_02024fc0, kart, (s32) soundRecord);
            } else {
                i = ((s64) h * 0x480000 + 0x800) >> 12;
                g = sub_2024EEC((KartSound *) &kart->field450, i, 0);
                soundRecord->field4 = 0x46;
                soundRecord->field0 = soundRecord->field44;
                AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                                (void (*)(void *, int)) func_02024fc0, kart, (s32) soundRecord);
            }
        } else {
            soundRecord->fieldC = 0;
            soundRecord->field10 = 0;
            soundRecord->field4 = 0x3c;
            AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                            (void (*)(void *, int)) func_02025030, kart, (s32) soundRecord);
            g = -1;
        }
        soundRecord->field8 = g;
        soundRecord->field14 = f;
        return;
    }
    baseSpeedLimit = kart->mPhysicalParam->mBaseSpeedLimit;
    velocityLength = kart->mVelocityLength;
    h = velocityLength - baseSpeedLimit;
    aboveSpeedLimit = h > 0 ? 1 : 0;
    if (g != 0 && kart->mForwardSpeed > 0 && (kart->field44 & KART_44_ON_GROUND) != 0) {
        g = ((s64) soundRecord->field24 * velocityLength + 0x800) >> 12;
        if (g > 0x280000) {
            g = 0x280000;
        }
        soundRecord->field4 = data_02153158[(kart->mVelocityLengthRatio >> 8) & 0xff];
        AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                        (void (*)(void *, int)) func_02024fe8, kart, (s32) soundRecord);
    } else if (f != 0 || (g != 0 && kart->mForwardSpeed < 0)) {
        if (aboveSpeedLimit != 0) {
            i = (s32) (((s64) h * soundRecord->field18 + 0x800) >> 12) + 0x580000;
        } else {
            i = ((s64) soundRecord->field1C * velocityLength + 0x800) >> 12;
        }
        g = sub_2024EEC((KartSound *) &kart->field450, i, aboveSpeedLimit);
        soundRecord->field4 = 0x7f;
        if (soundRecord->field14 == 0) {
            soundRecord->field0 = kart->mVelocityLengthRatio < 0x333 ? soundRecord->field64 : soundRecord->field60;
        }
        AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                        (void (*)(void *, int)) func_0202506c, kart, (s32) soundRecord);
    } else {
        if (aboveSpeedLimit != 0) {
            i = (s32) (((s64) h * soundRecord->field18 + 0x800) >> 12) + 0x480000;
        } else {
            i = ((s64) soundRecord->field20 * velocityLength + 0x800) >> 12;
        }
        g = sub_2024EEC((KartSound *) &kart->field450, i, aboveSpeedLimit);
        soundRecord->field4 = 0x32;
        if (kart->mVelocityLengthRatio < 0x19a) {
            soundRecord->field0 = soundRecord->field58;
        } else if (kart->mVelocityLengthRatio < 0x4cd) {
            soundRecord->field0 = soundRecord->field54;
        } else {
            soundRecord->field0 = soundRecord->field50;
        }
        AddSoundRequest(&data_0217d274, GetKartCameraDistanceSquared(kart->mIndex),
                        (void (*)(void *, int)) func_0202506c, kart, (s32) soundRecord);
    }
    soundRecord->field8 = g;
    soundRecord->field14 = f;
}

void snd_emitDriverMObjHitSfx(SoundSource *soundSource, u16 soundId, s32 b, s32 c) {
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
    sfx_emitSfx(soundSource, 0, soundId, volume, 0);
}

void snd_emitBalloonInflationSfx(Kart *kart, s32 b, s32 c) {
    s32 d;
    u8 volume;

    if (b <= 0) {
        return;
    }
    if (b >= 0x1000) {
        return;
    }
    d = (b << 14) >> 16;
    volume = (b << 7) >> 12;
    if (d > 0x400) {
        d = 0x400;
    }
    if (volume > 0x7f) {
        volume = 0x7f;
    }
    StartSoundWhileRequested(&kart->mSoundSource, c > 0 ? 0x150 : 0x151, volume, d);
}

s32 snd_getShineLoseSfxId(s32 a, s32 b, u32 c, u32 d) {
    s32 r;
    s32 t;

    r = b != 0 ? 4 : 0;
    if (a == 0) {
        if (c == d) {
            t = 0;
        } else if (c == d + 1) {
            t = 1;
        } else {
            t = 2;
        }
        r += t;
    } else {
        r += 3;
    }
    return r + 0x130;
}
