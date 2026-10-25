#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_020b502c.h"

// One element of the list at mUnk_00.
typedef struct Unk021a9ba4_00 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0x6e];
    /* 7e */ u16 mUnk_7e;
} Unk021a9ba4_00;

// One entry of the table at mUnk_10.
typedef struct Unk021a9ba4_10 {
    /* 00 */ UnkPair020b502c mUnk_00;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
} Unk021a9ba4_10;

// Object behind data_ov001_021a9ba4 and data_ov001_021a9ba8.
typedef struct Unk021a9ba4 {
    /* 00 */ Unk021a9ba4_00 **mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ UnkPair020b502c *mUnk_0c;
    /* 10 */ Unk021a9ba4_10 *mUnk_10;
} Unk021a9ba4;

extern Unk021a9ba4 *data_ov001_021a9ba4;
extern Unk021a9ba4 *data_ov001_021a9ba8;

void func_ov001_02188e88(Unk02188950 *param_1);
void func_ov001_02188e94(u32 param_1, void (**param_2)());
u32 func_ov001_02188eac(Unk02188950 *param_1, s32 param_2, Vec3 *param_3, s32 param_4);
u32 func_ov001_02188f04(Unk02188950 *param_1, Vec3 *param_2, s32 param_3);
void func_ov001_02188fdc(void *param_1);
void func_ov001_02188ff8(void);
void func_ov001_02189114(void);
s32 func_ov001_02189128(void);
void func_ov001_02189144(void *param_1);
void func_ov001_02189160(void);
void func_ov001_0218927c(void);
s32 func_ov001_02189290(void);
