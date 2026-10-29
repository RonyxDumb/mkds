#pragma once

#include "types.h"

// Blocks of words moved by func_0214d0e0, func_0214d0fc, func_0214d118 and func_0214d13c.
typedef struct Unk0214d0e0 {
    /* 00 */ u32 mUnk_00[8];
} Unk0214d0e0;

typedef struct Unk0214d0fc {
    /* 00 */ u32 mUnk_00[9];
} Unk0214d0fc;

typedef struct Unk0214d118 {
    /* 00 */ u32 mUnk_00[12];
} Unk0214d118;

typedef struct Unk0214d13c {
    /* 00 */ u32 mUnk_00[16];
} Unk0214d13c;

void func_0214d018(u32 a, void *b, u32 c);
void func_0214d02c(const void *a, void *b, u32 c);
void func_0214d044(const void *a, vu32 *b, u32 c);
void func_0214d05c(u32 a, void *b, u32 c);
void func_0214d0a8(const void *a, void *b, u32 c);
void func_0214d0e0(const void *a, void *b);
void func_0214d0fc(const void *a, void *b);
void func_0214d118(const void *a, void *b);
void func_0214d13c(const void *a, void *b);
void func_0214d168(void *a, u8 b, u32 c);
void func_0214d1fc(const void *a, void *b, u32 c);
void func_0214d32c(s32 *a);
s32 func_0214d33c(s32 a, s32 *b);
void func_0214d344(const void *a, void *b);

// Calls func_0214d05c with 0, passed through a stack offset of its own.
static inline void func_0214d05c_inline(void *p, u32 n) {
    volatile u32 v = 0;
    func_0214d05c(v, p, n);
}
