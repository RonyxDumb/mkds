#pragma once

#include "types.h"
#include "Main/Unknown/code_0202a820.h"

// 8-byte entries of the tables at data_usa_021539f4 and data_usa_02153a14.
typedef struct Unk021539f4 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk021539f4;

extern u16 data_usa_021539d8[];
extern u16 data_usa_021539e0[];
extern Unk021539f4 data_usa_021539f4[];
extern Unk021539f4 data_usa_02153a14[];
extern s32 data_usa_02153a4c[];
extern char data_usa_02162488[];
extern char data_usa_02162494[];
extern char data_usa_021624a0[];
extern char data_usa_021624c0[];
extern char data_usa_021624e0[];
extern char data_usa_02162500[];
extern char data_usa_02162524[];
extern char data_usa_02162548[];
extern char data_usa_02162568[];
extern char data_usa_02162588[];
extern char data_usa_021625a8[];
extern char data_usa_021625c8[];
extern char data_usa_021625e8[];
extern char data_usa_02162608[];
extern char data_usa_0216262c[];
extern char data_usa_02162650[];
extern char data_usa_02162670[];
extern char data_usa_02162690[];
extern char data_usa_021626b0[];

s32 func_0202a92c(void);
void func_0202ab2c(u32 param_1, u32 param_2, u32 param_3);
s32 func_0202af60(void);
void func_0202afe4(void);
void func_0202b100(void);
void func_0202b264(void);
void func_0202b2bc(void);
void func_0202b3f4(void);
void func_0202b4bc(s32 a, s32 b, s32 c, s32 d);
void func_0202b554(s32 a, s32 b);

// Declared here until the code that defines them is decompiled.
void func_0202cb2c(s32 a);
void func_0202cb68(s32 a);
void func_02036e20(s32 a, s32 b);
void func_02037334(s32 a, s32 b);
