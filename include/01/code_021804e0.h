#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175628.h"

// Argument of func_ov001_0218052c.
typedef struct Unk0218052c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk0218052c;

int func_ov001_021804e0(void *p0);
void func_ov001_0218050c(Unk0218052c *p0);
void func_ov001_02180514(void);
void func_ov001_0218051c(void);
void func_ov001_02180524(void);
void func_ov001_0218052c(Unk0218052c *p0);
unsigned int func_ov001_021805bc(unsigned int p0, unsigned int p1);
u16 func_ov001_021805d8(Unk02175628 *p0, unsigned int p1);
