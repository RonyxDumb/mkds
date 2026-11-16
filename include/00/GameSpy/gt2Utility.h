#pragma once

#include "types.h"
#include "00/code_0219b1d4.h" // Unk0219b1d4
#include "00/GameSpy/nonport.h"
#include "00/code_021a3a18.h"

// Six bytes at data_ov000_021b400c, written at the start of each buffer.
typedef struct Unk021b400c {
    /* 0 */ u8 field0[6];
} Unk021b400c;

// Message of 0x14 bytes; made of bytes so a copy of it is bytewise.
typedef struct Unk0219ade4 {
    /* 00 */ Unk021b400c field0;
    /* 06 */ u8 field6;
    /* 07 */ u8 field7;
    /* 08 */ u8 field8[4];
    /* 0c */ u8 fieldC[4];
    /* 10 */ u8 field10[2];
    /* 12 */ u8 field12;
    /* 13 */ u8 field13;
} Unk0219ade4;

// Message of 0x15 bytes.
typedef struct Unk0219aa64 {
    /* 00 */ Unk021b400c field0;
    /* 06 */ u8 field6;
    /* 07 */ u8 field7;
    /* 08 */ u8 field8[4];
    /* 0c */ u8 fieldC;
    /* 0d */ u8 fieldD;
    /* 0e */ u8 fieldE;
    /* 0f */ u8 fieldF;
    /* 10 */ u8 field10;
    /* 11 */ u8 field11;
    /* 12 */ u8 field12;
    /* 13 */ u8 field13;
    /* 14 */ u8 field14;
} Unk0219aa64;

// Message of 0x15 bytes followed by a string.
typedef struct Unk0219aeb0 {
    /* 00 */ Unk021b400c field0;
    /* 06 */ u8 field6;
    /* 07 */ u8 field7;
    /* 08 */ u8 field8[4];
    /* 0c */ u8 fieldC;
    /* 0d */ u8 fieldD;
    /* 0e */ u8 fieldE;
    /* 0f */ u8 fieldF;
    /* 10 */ u8 field10;
    /* 11 */ u8 field11;
    /* 12 */ u8 field12;
    /* 13 */ u8 field13;
    /* 14 */ u8 field14;
    /* 15 */ char field15[0x40];
} Unk0219aeb0;

// Declared here until the code that defines them is decompiled.

BOOL Gt2ParseAddress(const char *a, u32 *b, u16 *c);
u32 Gt2FormatAddress(u32 a, u32 b, char *c);
void func_ov000_0219a7e4(u8 *a, s32 b, void *c);
void func_ov000_0219a8bc(Unk0219b1d4 *a, Unk0219aa64 *b, Unk021a4654 *c);
void func_ov000_0219a958(Unk0219b1d4 *a, Unk0219ade4 *b, Unk021a4654 *c);
void func_ov000_0219a9e4(Unk0219b1d4 *a, Unk0219ade4 *b, Unk021a4654 *c);
void func_ov000_0219aa64(Unk0219b1d4 *a, Unk021a4654 *b);
void func_ov000_0219aaec(void);
void func_ov000_0219ab24(Unk0219b1d4 *a);
void func_ov000_0219ac50(u32 a);
s32 func_ov000_0219ac7c(u32 a, u32 b, u32 c, void (*d)(s32 a, void *b), void (*e)(s32 a, s32 b, void *c, void *d),
                        void *f);
BOOL func_ov000_0219ad20(void);
u32 func_ov000_0219ad88(char *a, const char *b);
u32 func_ov000_0219adb4(const char *a);
void func_ov000_0219ade4(Unk0219b1d4 *a);
void func_ov000_0219aeb0(Unk0219b1d4 *a);
u16 func_ov000_0219b038(u32 a);
u32 func_ov000_0219b05c(void);
void func_ov000_0219b0b0(u32 a, u32 b, u16 c, void *d, s32 e);
BOOL func_ov000_0219b0ec(const u8 *a);
void func_ov000_0219b110(void);
void func_ov000_0219b130(Unk0219b1d4 *a);
Unk0219b1d4 *func_ov000_0219b178(void);
