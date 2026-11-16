#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct SoundSource SoundSource;

// Ten words at 0x40 of an KartSound, built on the stack by driver_initField450.
typedef struct Unk02024eec_40 {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
} Unk02024eec_40;

// The bytes from 0x450 of an Kart, which sub_2024A88 and sub_2024EEC read and write.
typedef struct KartSound {
    /* 00 */ s32 field0;
    /* 04 */ u8 field4;
    /* 05 */ u8 field5[3];
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ s32 field28;
    /* 2c */ u8 field2C;
    /* 2d */ u8 field2D[3];
    /* 30 */ s32 field30;
    /* 34 */ s32 field34;
    /* 38 */ s32 field38;
    /* 3c */ u8 field3C[4];
    /* 40 */ union {
        struct {
            u8 field40[4];
            s32 field44;
            u8 field48[8];
            s32 field50;
            s32 field54;
            s32 field58;
            s32 field5C;
            s32 field60;
            s32 field64;
        };
        Unk02024eec_40 mUnk_40_m;
    };
    /* 68 */ s32 field68;
} KartSound;

typedef struct Kart Kart;
typedef struct KartSound KartSound;

s32 snd_getShineLoseSfxId(s32 a, s32 b, u32 c, u32 d);
void snd_emitBalloonInflationSfx(Kart *kart, s32 b, s32 c);
void snd_emitDriverMObjHitSfx(SoundSource *soundSource, u16 soundId, s32 b, s32 c);
void sub_2024A88(Kart *kart);
s32 sub_2024EEC(KartSound *soundRecord, s32 b, s32 c);
void func_02024fc0(Kart *kart, KartSound *soundRecord);
void func_02024fe8(Kart *kart, KartSound *soundRecord);
void func_02025030(Kart *kart, KartSound *soundRecord);
void func_0202506c(Kart *kart, KartSound *soundRecord);
u32 sub_20250A8(void);
