#pragma once

#include "types.h"

typedef struct Unk021b5df4 {
    /* 00 */ s32 field0;
    /* 04 */ u16 field4;
    /* 06 */ u16 field6;
    /* 08 */ u16 field8;
    /* 0a */ u16 fieldA;
} Unk021b5df4;

// Local of func_ov000_021a3910, filled with zeros and then with two function addresses and two bytes.
typedef struct Unk021a3910 {
    /* 00 */ void *(*field0)(u32 a, u32 b);
    /* 04 */ void (*field4)(u32 a, u32 b, u32 c);
    /* 08 */ u8 field8;
    /* 09 */ u8 field9;
    /* 0a */ u8 pad_0a[2];
} Unk021a3910;

#include "00/code_021a3a18.h"

extern Unk021b5df4 *data_ov000_021b5df4;

u32 func_ov000_021a3760(void);
BOOL func_ov000_021a377c(void);
void func_ov000_021a37dc(void);
u32 func_ov000_021a3810(void);
void func_ov000_021a3884(void);
u32 func_ov000_021a38d8(void);
void func_ov000_021a3910(void);
void func_ov000_021a397c(s32 a);
void func_ov000_021a39c4(void *a);
void func_ov000_021a39d8(Unk021b5df4 *a, u16 b, u32 c, u32 d);
