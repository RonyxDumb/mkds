#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h" // Unk021a9034
#include "Main/Unknown/code_02086098.h" // Unk02086098

extern const char data_02165048[];
extern const char data_02165050[];

// Objects whose layout isn't known yet.
// A function and three numbers; func_02050650 takes the address of data_021652a0.
typedef struct Unk021652a0 {
    /* 00 */ void (*mUnk_00)();
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ s32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[2];
} Unk021652a0;

extern Unk021652a0 data_0216523c;
extern const s32 data_02165510[2];
extern const Vec3 data_02165524;
extern const Vec3 data_0216553c;
extern const Vec3 data_02165548;
extern const Unk021a9034 data_0216524c;
extern const Unk021a9034 data_02165280;
extern Unk021652a0 data_021652a0;
extern UnkFunc *const data_021652b0[];
extern UnkFunc *const data_02165388[];
struct Unk0206bcb0;
extern void (*const data_usa_021655c4[])(struct Unk0206bcb0 *);
extern const Unk021a9034 data_02165368;
extern u8 data_02165074[];
extern u8 data_02165080[];
extern u8 data_02165098[];
extern u8 data_021650a0[];
extern u8 data_021650b4[];
extern u8 data_021650bc[];
extern u8 data_021650d8[];
extern u8 data_0216512c[];
extern u8 data_02165140[];
extern u8 data_02165148[];
extern u8 data_0216515c[];
extern u8 data_0216526c[];
extern const char *data_02165ac4;
extern const char *data_02165ac8;
extern const char *data_02165e80[13];
extern u16 data_021659d4[12];
extern Unk02086098 data_021659ec;
extern Unk02086098 data_02165a10;
extern Unk02086098 data_02165a34;
extern Unk02086098 data_02165a58;
extern u8 data_02165ef0[];
extern u8 data_02165fd4[];
extern u8 data_02165fec[];

extern s16 data_021653b8[];
extern const Unk021a9034 data_021653c0;
extern u8 data_0216569c[];
extern Vec3 data_02165530;
extern s32 data_02165948;
extern s32 data_0216593c;
extern s32 data_02165944;
extern s32 data_0216594c;
extern s32 data_02165950;
extern u32 data_02165978[];

// Three words, three more words and two halfwords; data_02165ff0, data_0216600c and data_02166028 are one each.
typedef struct Unk02165ff0 {
    /* 00 */ s32 mUnk_00[3];
    /* 0c */ s32 mUnk_0c[3];
    /* 18 */ s16 mUnk_18;
    /* 1a */ s16 mUnk_1a;
} Unk02165ff0;

extern Unk02165ff0 data_02165ff0;

extern u8 data_021651d4[];
extern const s32 data_02166048;
extern const Vec3 data_0216608c;
extern u8 data_021651d8[];
extern const char data_usa_02165990[];
extern const char *const data_02165e4c[];
extern const char data_02165eb4[];
extern const char data_02165ed4[];
extern s32 data_021659a0;
extern s32 data_021659a4;
extern s32 data_021659a8;
extern s32 data_021659ac;
extern s32 data_021659b0;
extern s32 data_021659b4;
extern s32 data_021659b8;
extern s32 data_021659bc;
extern s32 data_021659c0;
extern s32 data_021659c4;
extern s32 data_021659c8;
extern s32 data_021659cc;
extern s32 data_021659d0;
extern const char data_02165a7c[];
extern s32 data_usa_021654ec;
extern s32 data_021654f4;
// Three words.
typedef struct Unk02165560 {
    /* 00 */ u32 mUnk_00[3];
} Unk02165560;

extern const Unk02165560 data_usa_02165560;
extern const s32 data_usa_02165504;
