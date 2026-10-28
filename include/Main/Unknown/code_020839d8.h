#pragma once

#include "types.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_0206bcb0.h"

// Twelve bytes: a count and two values.
typedef struct Unk02155908_00 {
    /* 00 */ u16 mUnk_00;
    /* 04 */ s32 mUnk_04[2];
} Unk02155908_00;

// 0x20 bytes: two entries, a function and its argument.
typedef struct Unk02155908 {
    /* 00 */ Unk02155908_00 mUnk_00[2];
    /* 18 */ s32 (*mUnk_18)(Unk02155908_00 *a, s32 b, Unk0206bcb0 *p);
    /* 1c */ s32 mUnk_1c;
} Unk02155908;

extern Unk02155908 data_02155908[];
extern Unk02155908 data_02155928;
extern Unk02155908 data_02155968;
extern Unk02155908 data_02155988;
extern Unk02155908 data_021559a8;
extern Unk02155908 data_021559c8;
extern Unk02155908 data_021559e8;

void func_020839d8(Unk0206bcb0 *p);
s32 func_02083a24(Unk02155908_00 *a, s32 b, Unk0206bcb0 *p);
s32 func_02083ae0(Unk02155908_00 *a, s32 b, Unk0206bcb0 *p);
s32 func_02083c18(Unk02155908_00 *a, s32 b, Unk0206bcb0 *p);
s32 func_02083d4c(Unk02155908_00 *a, s32 b, Unk0206bcb0 *p);
void func_02083de8(s32 a, Unk0206bcb0 *p);
void func_02083ec4(Unk0206bcb0 *p);
void func_02083f6c(s32 a, Unk0206bcb0 *p);
void func_02084034(u32 a, Unk0206bcb0 *p);
void func_020840c0(Unk0206bcb0 *p);
void func_02084114(Unk0206bcb0 *p);
void func_0208419c(Unk0206bcb0 *p);
void func_02084224(Unk0206bcb0 *p);
void func_020842ac(Unk0206bcb0 *p);
void func_02084334(Unk0206bcb0 *p);
void func_02084384(Unk0206bcb0 *p);
void func_020843d8(Unk0206bcb0 *p);
void func_0208442c(Unk0206bcb0 *p);
void func_02084478(Unk0206bcb0 *p);
void func_020845cc(u32 a);
