#pragma once

#include "types.h"
#include "00/code_021a6fb4.h"

typedef struct Unk021a71c0 Unk021a71c0;
typedef struct Unk021a6fa8 Unk021a6fa8;

typedef s32 (*Unk021a78a4Func)(void *param_1, u32 param_2, Unk021a6fa8 *param_3);

// Entry of the list behind field100 and field104 of an Unk021a71c0; the data follows at fieldC.
typedef struct Unk021a78a4 {
    /* 00 */ struct Unk021a78a4 *field0;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u32 field8;
    /* 0c */ u8 fieldC[4];
} Unk021a78a4;

// An Unk021a7064 entry as func_ov000_021a7af0 reads it.
typedef struct Unk021a7af0 {
    /* 00 */ Unk021a7064Func field0;
    /* 04 */ Unk021a6fa8 *field4;
    /* 08 */ OSMessageQueue *field8;
    /* 0c */ s8 fieldC;
    /* 0d */ s8 fieldD;
    /* 0e */ u8 fieldE[2];
    /* 10 */ u8 *field10;
    /* 14 */ s32 field14;
    /* 18 */ u16 *field18;
    /* 1c */ u32 *field1C;
} Unk021a7af0;

extern s32 data_ov000_021b5ffc[2];

s32 func_ov000_021a78a4(void *param_1, u32 param_2, Unk021a6fa8 *param_3);
s32 func_ov000_021a797c(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e, s32 f);
s32 func_ov000_021a7a6c(Unk021a6fa8 *a);
s32 func_ov000_021a7a9c(Unk021a7064 *a);
s32 func_ov000_021a7aa8(Unk021a6fa8 *a);
s32 func_ov000_021a7af0(Unk021a7064 *a);
