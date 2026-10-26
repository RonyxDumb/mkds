#pragma once

#include "types.h"
#include "code_02003024.h"

// Two words read as a pair: data_0216f35c, data_0216f364 and the blocks func_02004e1c and func_020055f0 read at fixed
// addresses.
typedef struct Unk02005704 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02005704;

// Record of 0x2c bytes: the first 0x20 bytes are read from a table entry of 0x20 bytes.
typedef struct Unk020055f0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void (**mUnk_10)(void);
    /* 14 */ void (**mUnk_14)(void);
    /* 18 */ s32 mUnk_18;
    /* 1c */ union {
        struct {
            u32 mUnk_00_0 : 24;
        } f;
        u8 b[4];
    } mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
} Unk020055f0;

// Node of the list at data_0217eeb0 that func_02005210 walks.
typedef struct Unk02005210 {
    /* 00 */ struct Unk02005210 *mUnk_00;
    /* 04 */ void (*mUnk_04)(void *);
    /* 08 */ void *mUnk_08;
} Unk02005210;

extern u32 data_0216f350;
extern u32 data_0216f354;
extern u32 data_0216f358;
extern Unk02005704 data_0216f35c;
extern Unk02005704 data_0216f364;
extern Unk02003a6c data_0216f36c;
extern u8 data_02161764[];
extern void *data_02161768;
extern u32 data_0216176c;

void func_02004dc0(u32 arg);
u32 func_02004dfc(u32 a, u32 b);
void func_02004e1c(u32 arg);
s32 func_02004fbc(Unk02003024 *p0, u32 p1);
s32 func_02004fc4(Unk02003a6c *p0, void *p1, u32 p2, u32 p3);
s32 func_02004fcc(Unk02003024 *p, u32 cmd);
s32 func_0200505c(Unk02003a6c *p0, void *p1, u32 p2, u32 p3);
s32 func_02005064(Unk02003a6c *p, void *buf, u32 off, u32 n);
void func_020050b0(Unk02003a6c *p);
void func_020050c0(u32 sel, u8 *data, u32 n);
u32 func_02005144(u32 sel, u32 idx);
u32 func_02005198(u32 sel, u32 idx);
u32 func_020051f4(Unk020055f0 *rec);
void func_02005210(Unk020055f0 *rec);
void func_02005314(Unk020055f0 *rec);
u32 func_02005414(const u8 *expected, const u8 *data, u32 n);
u32 func_020054b8(Unk020055f0 *rec);
u32 func_02005558(Unk020055f0 *rec, Unk02003024 *o);
u32 func_020055f0(Unk020055f0 *dst, u32 sel, u32 idx);
u32 func_02005704(Unk020055f0 *dst, u32 sel, u32 idx, Unk02003a6c *owner, u8 *base0, u32 size0, u8 *base1, u32 size1);
void func_02005814(Unk02005814 *dst, Unk020055f0 *src);
void func_0200583c(Unk020055f0 *p);
s32 func_02005880(Unk020055f0 *p);
