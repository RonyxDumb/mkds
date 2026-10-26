#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.
void func_0214d02c(u32 *param_1, u32 *param_2, int param_3);
void func_0214d344();
void func_0214d05c(u32 param_1, void *param_2, u32 param_3);

// Calls func_0214d05c with 0, passed through a stack slot of its own.
static inline void func_0214d05c_inline(void *p, u32 n) {
    volatile u32 v = 0;
    func_0214d05c(v, p, n);
}
void func_0214d0a8(const void *src, void *dst, u32 size);
