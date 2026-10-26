#pragma once

#include "00/code_02180638.h"
#include "00/code_021806e0.h"

#include "types.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0212426c.h"

// Allocated by func_ov000_02182fdc and held in data_ov000_021b4c70.
typedef struct Unk021b4c70 {
    /* 0000 */ s32 mUnk_00;
    /* 0004 */ s32 mUnk_04;
    /* 0008 */ s32 mUnk_08;
    /* 000c */ s32 mUnk_0c;
    /* 0010 */ s32 mUnk_10;
    /* 0014 */ s16 mUnk_14[3][2];
    /* 0020 */ s32 mUnk_20;
    /* 0024 */ s32 mUnk_24;
    /* 0028 */ u8 pad_28[4];
    /* 002c */ s32 mUnk_2c;
    /* 0030 */ s32 mUnk_30;
    /* 0034 */ u8 pad_34[0x1004];
    /* 1038 */ void *mUnk_1038;
    /* 103c */ void *mUnk_103c;
    /* 1040 */ void *mUnk_1040;
    /* 1044 */ u8 pad_1044[4];
    /* 1048 */ void *mUnk_1048;
    /* 104c */ void *mUnk_104c;
    /* 1050 */ u8 pad_1050[4];
    /* 1054 */ void *mUnk_1054;
    /* 1058 */ void *mUnk_1058;
    /* 105c */ void *mUnk_105c;
} Unk021b4c70;

// 0x40-byte element of the table behind Unk021b4c74::mUnk_10d4.
typedef struct Unk02124b1c {
    /* 0000 */ s32 mUnk_00;
    /* 0004 */ s16 mUnk_04;
    /* 0006 */ s16 mUnk_06;
    /* 0008 */ u8 mUnk_0008[0x38];
} Unk02124b1c;

// Object behind Unk021b4c74::mUnk_16f0; the u16 at 6 is a count.
typedef struct Unk021b4c74_16f0 {
    /* 0000 */ u8 pad_00[6];
    /* 0006 */ u16 mUnk_06;
} Unk021b4c74_16f0;

// Objects returned by func_020b47d8, func_020b4934, func_020b49bc and func_020b4a44.
typedef struct Unk020b4934 {
    /* 0000 */ u8 pad_00[0x10];
    /* 0010 */ u32 mUnk_10;
    /* 0014 */ void *mUnk_14;
} Unk020b4934;

typedef struct Unk020b47d8 {
    /* 0000 */ u8 pad_00[8];
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u8 mUnk_0c[1];
} Unk020b47d8;

typedef struct Unk020b4a44 {
    /* 0000 */ u8 pad_00[8];
    /* 0008 */ u32 mUnk_08;
    /* 000c */ u16 *mUnk_0c;
} Unk020b4a44;

// Object behind data_ov000_021b4c74; mUnk_00 selects the handler run by func_ov000_0218338c.
typedef struct Unk021b4c74 {
    /* 0000 */ s32 mUnk_00;
    /* 0004 */ s32 mUnk_04;
    /* 0008 */ s32 mUnk_08;
    /* 000c */ s32 mUnk_0c;
    /* 0010 */ s16 mUnk_10;
    /* 0012 */ u8 pad_12[6];
    /* 0018 */ s16 mUnk_18[4];
    /* 0020 */ s32 mUnk_20;
    /* 0024 */ s32 mUnk_24[3];
    /* 0030 */ s32 mUnk_30;
    /* 0034 */ u8 mUnk_34[3];
    /* 0037 */ u8 pad_37;
    /* 0038 */ s32 mUnk_38;
    /* 003c */ s32 mUnk_3c;
    /* 0040 */ s32 mUnk_40;
    /* 0044 */ s32 mUnk_44;
    /* 0048 */ s32 mUnk_48;
    /* 004c */ u16 mUnk_4c[5];
    /* 0056 */ u8 pad_56[2];
    /* 0058 */ s32 mUnk_58[5][3];
    /* 0094 */ s32 mUnk_94[5][3];
    /* 00d0 */ u8 pad_d0[4];
    /* 00d4 */ u8 mUnk_d4[0x1000];
    /* 10d4 */ Unk02124b1c *mUnk_10d4;
    /* 10d8 */ u8 mUnk_10d8[3][0x200];
    /* 16d8 */ s32 mUnk_16d8[3];
    /* 16e4 */ void *mUnk_16e4;
    /* 16e8 */ Unk020b4934 *mUnk_16e8;
    /* 16ec */ Unk020b4a44 *mUnk_16ec;
    /* 16f0 */ Unk021b4c74_16f0 *mUnk_16f0;
    /* 16f4 */ void *mUnk_16f4;
    /* 16f8 */ void *mUnk_16f8;
    /* 16fc */ void *mUnk_16fc;
} Unk021b4c74;

// Four callbacks, passed to func_ov000_021806ec by func_ov000_0218330c.
typedef struct Unk021b0cd4 {
    /* 0000 */ void (*mUnk_00)(void *);
    /* 0004 */ void (*mUnk_04)(void);
    /* 0008 */ void (*mUnk_08)(void);
    /* 000c */ void (*mUnk_0c)(void);
} Unk021b0cd4;

typedef struct Unk0217b488 {
    /* 0000 */ u8 mUnk_0000[0x4];
    /* 0004 */ s32 mUnk_04;
    /* 0008 */ s32 mUnk_08;
    /* 000c */ s32 mUnk_0c;
    /* 0010 */ u8 mUnk_0010[0x4];
    /* 0014 */ s32 mUnk_14;
    /* 0018 */ s32 mUnk_18;
    /* 001c */ u8 mUnk_001c[0x38];
    /* 0054 */ u8 mUnk_54;
    /* 0055 */ u8 mUnk_0055[0x1b];
    /* 0070 */ s32 mUnk_70;
} Unk0217b488;

typedef struct Unk0217d384 {
    /* 0000 */ u8 pad_00[0x1f52];
    /* 1f52 */ u8 mUnk_1f52;
} Unk0217d384;

typedef struct Unk0217ad04 {
    /* 0000 */ u8 pad_00[0xc];
    /* 000c */ void *mUnk_0c;
} Unk0217ad04;

extern u8 data_ov000_021b05e8[3];
extern u8 data_ov000_021b05f0[];
extern u8 data_ov000_021b060c[3][9];
extern s32 data_ov000_021b0628[3][4];
extern u8 data_ov000_021b0658[2];
extern u8 data_ov000_021b065c[3];
extern u8 data_ov000_021b0660[3];
extern u8 data_ov000_021b0664[3];
extern u8 data_ov000_021b0668[3];
extern u8 data_ov000_021b0670[3][2];
extern u8 data_ov000_021b0678[3][2];
extern s32 data_ov000_021b0680[3];
extern u8 data_ov000_021b068c[3][5];
extern s8 data_ov000_021b069c[30];
extern u8 data_ov000_021b0ce4[30];
extern u8 data_ov000_021b0d04[40];
extern Unk021b4c70 *data_ov000_021b4c70;
extern Unk021b4c74 *data_ov000_021b4c74;
extern Unk0217b488 *data_0217b488;
extern Unk0217d384 *data_0217d384;

void func_ov000_02182fdc(void *heap);
s32 func_ov000_021832f0(void);
void func_ov000_0218330c(void);
void func_ov000_02183330(void);
void func_ov000_0218338c(void);
void func_ov000_02183444(void);
void func_ov000_021834b0(s32 t);
void func_ov000_02183548(void);
void func_ov000_0218364c(void);
void func_ov000_02183674(void);
void func_ov000_021836f4(void);
void func_ov000_021837b8(void);
void func_ov000_0218381c(void);
void func_ov000_02183858(void);
void func_ov000_021839d0(void);
void func_ov000_02183a0c(void);
void func_ov000_02183b80(void);
void func_ov000_0218401c(void);
void func_ov000_021840c8(void);
void func_ov000_02184130(void);

s32 func_02036d08(void);
void func_02036f10(s16);
u8 func_0205e548(void);
Unk0217ad04 *func_02077f00(void);
void func_020ac2fc(void *, void *, s32);
void func_020b47d8(Unk020b47d8 **, void *);
void func_020b48b4(void **, void *);
void func_020b4934(Unk020b4934 **, void *);
void func_020b49bc(Unk020b4934 **, void *);
void func_020b4a44(Unk020b4a44 **, void *);
void func_0210895c(void);
void func_02108990(void);
void func_02108a40(void);
void func_02108a8c(void);
void func_02108adc(void);
void func_02108b2c(void);
s32 func_0212111c(void);
void *func_02120294(u32);
void *func_021202b0(u32);
void func_02121190(u32, s32, s32);
s32 func_0212137c(void);
s32 func_021213a0(void);
void func_021213e8(void);
u8 func_02121418(void);
s32 func_02121434(void);
void func_02124a98(u32, s32, void *, void *);
void func_02124b1c(Unk02124b1c *, u32, s32);
u16 func_0212497c(u32, void *, void *);
void func_02124c30(void *, void *, void *, void *, void *);
void func_02124fac(u32, u16 *);
void func_02126638(void *, s32, s32, s32, s32, s32, s32);
void func_021282c8(void);
void func_02128374(void);
void func_0212b928(void *, void *, u32);
s32 func_02016468(u32, u32, void *, u32);

void *func_ov000_021804e0(void);
void *func_ov000_021804f4(void);
u32 func_ov000_02180668(u32);
void func_ov000_021806ec(const Unk021b0cd4 *);
void func_ov000_02182e18(void);
void func_ov000_02184354(void);
void func_ov000_021843a8(void *heap);
u8 func_ov000_0219bb50(void);

#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_0212a910.h"
#include "code_0212df7c.h"
