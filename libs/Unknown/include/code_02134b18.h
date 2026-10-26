#pragma once

#include "types.h"

// Two conversion functions called through data_0216eccc.mUnk_08: mUnk_00 has the shape of func_02134ccc,
// mUnk_04 that of func_02134c94.
typedef struct Unk02134c94 {
    /* 00 */ int (*mUnk_00)(u16 *dst, const u8 *src, u32 n);
    /* 04 */ int (*mUnk_04)(u8 *dst, u16 c);
} Unk02134c94;

// func_02134c6c and func_02134d08 read the pointer at 0x08.
typedef struct Unk0216eccc {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk02134c94 *mUnk_08;
} Unk0216eccc;

extern Unk0216eccc data_0216eccc;

int func_02134b18(u8 *dst, const u16 *src, u32 n);
int func_02134bd4(u16 *dst, const u8 *src, u32 n);
int func_02134c6c(u8 *dst, u16 c);
int func_02134c94(u8 *dst, u16 c);
int func_02134ccc(u16 *dst, const u8 *src, u32 n);
int func_02134d08(u16 *dst, const u8 *src, u32 n);
