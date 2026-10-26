#pragma once

#include "Main/Unknown/code_0200f168.h"

#include "types.h"

// 0x2c bytes, on the stack of func_0200dc3c; func_0200fb08 is the first call made on it there, then
// func_0200f950 stores its third and fourth arguments at mUnk_00 and mUnk_04 (func_0200f8b8 takes it too).
typedef struct Unk0200fb08 {
    /* 00 */ u32 mUnk_00[0xb];
} Unk0200fb08;

// Declared here until the code that defines them is decompiled.
void func_0200f35c(u32 v);
void func_0200f364(u32 v);
void func_0200f36c(void);
void func_0200f3f4(u32 v);
void func_0200f484(void);
void func_0200f4f0(void);
u64 func_0200f5ac(void);
void func_0200f8b8(Unk0200fb08 *a);
void func_0200f950(Unk0200fb08 *a, u64 n, void (*f)(void *), void *p);
void func_0200fb08(Unk0200fb08 *a);
void func_0200fc1c(void);
u32 func_0200fc8c(void);
u32 func_0200fca0(void);
u32 func_0200fcb4(u32 v);
u32 func_0200fccc(void);
u32 func_0200fce0(u32 a);
u32 func_0200fcf8(void);
void func_0200fd04(void);
void func_0200fd10(u32 param_1);
void func_0200fd1c(void);
void func_0200fd74(void);
unsigned int func_0200fe58(void);
void func_0200ffd8(void);
