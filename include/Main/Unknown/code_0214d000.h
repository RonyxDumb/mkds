#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.
void func_0214d02c(const void *src, void *dst, u32 size);
void func_0214d344();
void func_0214d05c(u32 param_1, void *param_2, u32 param_3);

// Calls func_0214d05c with 0, passed through a stack slot of its own.
static inline void func_0214d05c_inline(void *p, u32 n) {
    volatile u32 v = 0;
    func_0214d05c(v, p, n);
}
void func_0214d0a8(const void *src, void *dst, u32 size);
void func_0214d168(void *dst, u8 value, u32 size);
void func_0214d1fc(const void *src, void *dst, u32 size);
void func_0214d018(u32 v, void *dst, u32 n);
s32 func_0214d33c(s32 v, s32 *p);
u32 func_0214d5b8(void);
s32 func_0214d6e8(u32 a, u32 b, u32 c);
s32 func_0214d79c(u32 a, u32 b);
void func_0214d7c4(u32 a, UnkFunc *fn);
