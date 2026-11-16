#pragma once

#include "types.h"

// 0xf0 bytes; the object at data_ov003_021da270 holds four of them at a stride of 0x100.
typedef struct Unk021cd5e0_entry {
    /* 00 */ u8 field0[0x40];
    /* 40 */ u8 field40[0x20];
    /* 60 */ u8 field60[0x20];
    /* 80 */ u8 field80[4][0x10];
    /* c0 */ u8 fieldC0[4];
    /* c4 */ u8 fieldC4[4];
    /* c8 */ u8 fieldC8[8];
    /* d0 */ u8 fieldD0;
    /* d1 */ u8 fieldD1[0x15];
    /* e6 */ u8 fieldE6_0 : 2;
    /* e6 */ u8 fieldE6_2 : 6;
    /* e7 */ u8 fieldE7;
    /* e8 */ u8 fieldE8[8];
} Unk021cd5e0_entry;

// Entry at offset 0x400 of the object at data_ov003_021da270, and the bytes after it.
typedef struct Unk021cd5e0_400 {
    /* 00 */ Unk021cd5e0_entry field0;
    /* f0 */ u8 fieldF0[4];
    /* f4 */ u8 fieldF4;
    /* f5 */ u8 fieldF5;
    /* f6 */ u8 fieldF6;
    /* f7 */ u8 pad_f7;
    /* f8 */ u16 fieldF8;
} Unk021cd5e0_400;

// Object at data_ov003_021da270, as far as func_ov003_021cd5e0 through func_ov003_021cd790 use it.
typedef struct Unk021cd5e0 {
    /* 000 */ struct {
        Unk021cd5e0_entry field0;
        u8 fieldF0[0xe];
        u16 fieldFE;
    } field0[4];
    /* 400 */ Unk021cd5e0_400 field400;
} Unk021cd5e0;

// Argument of func_ov003_021cd5e0.
typedef struct Unk021cd5e0_arg {
    /* 00 */ u8 field0[0x20];
    /* 20 */ u32 field20;
    /* 24 */ u8 field24[4];
    /* 28 */ u8 field28[4][0x20];
} Unk021cd5e0_arg;

extern u8 data_ov003_021d6684[];

void func_ov003_021cd2e0(const char *input, u8 *output);
void func_ov003_021cd338(s32 param_1);
void func_ov003_021cd42c(void);
void func_ov003_021cd4ac(int a);
struct Unk021cd5e0 *func_ov003_021cd4dc(void);
void func_ov003_021cd4e8(int arg0);
void func_ov003_021cd5e0(const Unk021cd5e0_arg *a);
void func_ov003_021cd6d0(void);
void func_ov003_021cd790(s32 a);
u8 func_ov003_021cd844(int a);
void func_ov003_021cd858(char *p0);
void func_ov003_021cd888(char *p0);
void func_ov003_021cd8b8(char *p0);
void func_ov003_021cd8e8(char *p0);
void func_ov003_021cd918(char *p0);
void func_ov003_021cd948(void *output);
void func_ov003_021cd964(const char *input);
void func_ov003_021cd97c(const char *input);
void func_ov003_021cd994(const char *input);
void func_ov003_021cd9ac(const char *input);
void func_ov003_021cd9c4(const char *input);
void func_ov003_021cd9dc(const u8 *a);
void func_ov003_021cdb14(const u8 *a);
void func_ov003_021cdb44(u32 a);
void func_ov003_021cdb58(u32 a);
Unk021cd5e0_400 *func_ov003_021cdb6c(void);
void func_ov003_021cdb80(void);
void func_ov003_021cdb90(void);
