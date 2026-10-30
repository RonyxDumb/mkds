#pragma once

#include "types.h"
#include "00/code_0218d000.h"
#include "00/code_0219a3f4.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"

// Object with the callbacks that the functions of this file call.
typedef struct Unk02197e8c {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[4];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u8 mUnk_20[8];
    /* 28 */ UnkWordFunc *mUnk_28;
    /* 2c */ UnkWordFunc *mUnk_2c;
    /* 30 */ UnkWordFunc *mUnk_30;
    /* 34 */ UnkWordFunc *mUnk_34;
} Unk02197e8c;

typedef struct Unk02197fe8Entry {
    /* 00 */ UnkWordFunc *mUnk_00;
} Unk02197fe8Entry;

typedef struct Unk02197fe8 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk02197e8c *mUnk_08;
    /* 0c */ u8 mUnk_0c[0x18];
    /* 24 */ s32 mUnk_24;
    /* 28 */ u8 mUnk_28[0xc];
    /* 34 */ UnkWordFunc *mUnk_34;
    /* 38 */ u8 mUnk_38[0x60];
    /* 98 */ int *mUnk_98;
    /* 9c */ int *mUnk_9c;
} Unk02197fe8;

extern const u8 data_ov000_021b3f50[];
extern const u8 data_ov000_021b3f58[];
extern const u8 data_ov000_021b3f68[];

s32 func_ov000_02197e8c(Unk02197e8c *a, s32 b, s32 c, void *d, s32 e, s32 *f);
u32 func_ov000_02197f28(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, int param_6, int param_7,
                        int param_8);
s32 func_ov000_02197fe8(Unk02197fe8 *a, s32 b, s32 c, void *d, s32 e);
s32 func_ov000_02198098(Unk02197fe8 *a, s32 b, s32 c, void *d, s32 e);
s32 func_ov000_02198148(Unk02197fe8 *a, s32 b);
