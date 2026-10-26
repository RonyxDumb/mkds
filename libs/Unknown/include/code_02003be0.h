#pragma once

#include "types.h"
#include "code_02003024.h"

// First Unk02003a6c of the list func_02004128 builds through mUnk_04/mUnk_08 (func_020041e8 searches it).
extern Unk02003a6c *data_0216f340;
// Set by func_02004128, func_02004090 and func_020047ec; read by func_02004c20.
extern Unk02003024U data_0216f344;

void func_02003be0(Unk02003a6c *p0, u32 p1);
void func_02003c60(Unk02003a6c *p0, s32 (*p1)(Unk02003024 *, u32), u32 p2);
u32 func_02003c80(Unk02003a6c *p0);
u32 func_02003cfc(Unk02003a6c *p0, u32 p1);
u32 func_02003d8c(Unk02003a6c *p0, u32 p1);
u32 func_02003e24(Unk02003a6c *p0, u32 p1, u32 p2);
u32 func_02003f50(Unk02003a6c *p0);
u32 func_02004018(Unk02003a6c *p0, u8 *p1, u32 p2, u32 p3, u32 p4, u32 p5, s32 (*p6)(Unk02003a6c *, void *, u32, u32),
                  s32 (*p7)(Unk02003a6c *, void *, u32, u32));
void func_02004090(Unk02003a6c *p0);
u32 func_02004128(Unk02003a6c *p0, const u8 *p1, s32 p2);
Unk02003a6c *func_020041e8(const u8 *p0, s32 p1);
