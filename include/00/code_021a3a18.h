#pragma once

#include "types.h"

typedef struct Unk021b5df4 Unk021b5df4;

typedef struct Unk021a3a18 {
    /* 000 */ u32 field0;
    /* 004 */ char field4[0x80];
    /* 084 */ s8 field84[0x18];
    /* 09c */ void (*field9C)(s8 a, u8 *b, u32 c);
    /* 0a0 */ void (*fieldA0)(u32 a, u32 b);
    /* 0a4 */ void (*fieldA4)(s8 *a, s32 b, u32 c);
    /* 0a8 */ s32 fieldA8;
    /* 0ac */ u32 fieldAC;
    /* 0b0 */ u32 fieldB0;
    /* 0b4 */ u32 fieldB4;
    /* 0b8 */ s32 fieldB8;
    /* 0bc */ s32 fieldBC;
    /* 0c0 */ u32 fieldC0;
    /* 0c4 */ u8 pad_c4[4];
    /* 0c8 */ s32 fieldC8;
    /* 0cc */ u8 fieldCC[8];
    /* 0d4 */ void (*fieldD4)(s8 *a, s32 b, void *c);
    /* 0d8 */ s32 fieldD8[10];
    /* 100 */ s32 field100;
    /* 104 */ u32 field104;
    /* 108 */ u16 field108;
    /* 10a */ u8 pad_10a[2];
    /* 10c */ u32 field10C;
} Unk021a3a18;

// A buffer and its length, which follows the 0x800 bytes of the buffer.
typedef struct Unk021a4480 {
    /* 000 */ u8 field0[0x800];
    /* 800 */ s32 field800;
} Unk021a4480;

typedef struct Unk021a3a18 Unk021a3a18;

typedef struct Unk021a3a18 Unk021a3a18;

typedef struct Unk021a3eb0 {
    /* 0 */ u8 field0[6];
} Unk021a3eb0;

typedef struct Unk021a471c Unk021a471c;
typedef struct Unk021a4a08 Unk021a4a08;

typedef struct Unk021a8f84 Unk021a8f84;

// Output buffer the string writers append to: bytes at field0, used length at field800.
typedef struct Unk021a471c {
    /* 000 */ u8 field0[0x800];
    /* 800 */ s32 field800;
} Unk021a471c;

// Address record filled by func_ov000_021a4654.
typedef struct Unk021a4654 {
    /* 0 */ u8 field0;
    /* 1 */ u8 field1;
    /* 2 */ u16 field2;
    /* 4 */ u32 field4;
} Unk021a4654;

// Four-byte entry moved by func_ov000_021a46d4.
typedef struct Unk021a46d4 {
    /* 0 */ u8 field0[4];
} Unk021a46d4;

typedef struct Unk021a4a08 Unk021a4a08;

// List of values and their count; filled by the callback at field94 of an Unk021a4a08.
typedef struct MatchingKeyIds {
    /* 000 */ u8 field0[0x100];
    /* 100 */ s32 field100;
} MatchingKeyIds;

typedef void (*Unk021a4a08Func88)(u8 a, Unk021a471c *b, void *c);
typedef void (*Unk021a4a08Func8c)(u8 a, s32 b, Unk021a471c *c, void *d);
typedef void (*Unk021a4a08Func94)(s32 a, MatchingKeyIds *b, void *c);
typedef s32 (*Unk021a4a08Func98)(s32 a, void *b);
typedef void (*Unk021a4a08Func9c)(s32 a, const u8 *b, void *c);
typedef void (*Unk021a4a08Funca8)(u32 a, u16 b, void *c);

// 0x110 bytes; func_ov000_021a4a08 fills it, data_ov000_021b426c points at the one in use.
typedef struct Unk021a4a08 {
    /* 000 */ s32 field0;
    /* 004 */ u8 field4[0x40];
    /* 044 */ u8 field44[0x40];
    /* 084 */ u8 field84[4];
    /* 088 */ Unk021a4a08Func88 field88;
    /* 08c */ Unk021a4a08Func8c field8C;
    /* 090 */ Unk021a4a08Func8c field90;
    /* 094 */ Unk021a4a08Func94 field94;
    /* 098 */ Unk021a4a08Func98 field98;
    /* 09c */ Unk021a4a08Func9c field9C;
    /* 0a0 */ UnkFunc *fieldA0;
    /* 0a4 */ UnkFunc *fieldA4;
    /* 0a8 */ Unk021a4a08Funca8 fieldA8;
    /* 0ac */ u32 fieldAC;
    /* 0b0 */ u32 fieldB0;
    /* 0b4 */ BOOL fieldB4;
    /* 0b8 */ s32 fieldB8;
    /* 0bc */ s32 fieldBC;
    /* 0c0 */ s32 fieldC0;
    /* 0c4 */ BOOL fieldC4;
    /* 0c8 */ s32 fieldC8;
    /* 0cc */ Unk021a4654 fieldCC;
    /* 0d4 */ s32 fieldD4;
    /* 0d8 */ s32 fieldD8[10];
    /* 100 */ s32 field100;
    /* 104 */ u32 field104;
    /* 108 */ u16 field108;
    /* 10c */ void *field10C;
} Unk021a4a08;

s32 func_ov000_021a4a08(Unk021a4a08 **a, s32 b, s32 c, const char *d, const char *e, s32 f, s32 g, Unk021a4a08Func88 h,
                        Unk021a4a08Func8c i, Unk021a4a08Func8c j, Unk021a4a08Func94 k, Unk021a4a08Func98 l,
                        Unk021a4a08Func9c m, void *n);

extern Unk021a4a08 data_ov000_021b4278;
extern s32 data_ov000_021b5df8;
extern u8 data_ov000_021b5dfc[5 * 4];
extern char data_ov000_021b5e10[];
extern s8 data_ov000_021b5e50[];

void func_ov000_021a3a18(Unk021a3a18 *a, s32 b);
void func_ov000_021a3bbc(Unk021a3a18 *a);
void func_ov000_021a3c14(Unk021a3a18 *a, s8 *b, s32 c, void *d);
u32 func_ov000_021a3e5c(Unk021a3a18 *a, int b);
void func_ov000_021a3eb0(Unk021a3a18 *a, u8 *b, s32 c);
void func_ov000_021a3f78(Unk021a4a08 *a, Unk021a471c *b);
void func_ov000_021a3fc8(Unk021a4a08 *a, Unk021a471c *b, s32 c);
void func_ov000_021a412c(Unk021a4a08 *a, Unk021a471c *b, const u8 *c, s32 d);
void func_ov000_021a41a0(Unk021a4a08 *a, Unk021a471c *b, s32 c, const u8 *d, s32 e, const u8 *f, s32 g, const u8 *h);
void func_ov000_021a41dc(Unk021a4a08 *a, Unk021a471c *b, s32 c, s32 d, const u8 *e);
void func_ov000_021a438c(Unk021a4a08 *a, const char *b);
void func_ov000_021a4418(Unk021a4a08 *a, Unk021a471c *b, const char *c, s32 d);
void func_ov000_021a4480(unsigned int p0, unsigned int p1, unsigned int p2);
void func_ov000_021a44a0(u8 *a, s32 b, u8 *c, s32 d);
void func_ov000_021a4578(const u8 *a, s32 b, u8 *c);
unsigned char func_ov000_021a4610(u32 a);
void func_ov000_021a4648(u8 *a, u8 *b);
BOOL func_ov000_021a4654(const char *a, u32 b, Unk021a4654 *c, Unk021a8f84 **d);
void func_ov000_021a46d4(void);
void func_ov000_021a471c(Unk021a471c *a, const char *b);
void func_ov000_021a4760(Unk021a471c *a, s32 b);
void func_ov000_021a4784(MatchingKeyIds *a, int b);
void func_ov000_021a47ac(Unk021a4a08 *a);
void func_ov000_021a4818(Unk021a4a08 *a);
void func_ov000_021a4868(Unk021a4a08 *a);
void func_ov000_021a4940(Unk021a4a08 *a);
void func_ov000_021a49a0(Unk021a4a08 *a);
void func_ov000_021a49cc(void *a, void (*b)(void *, u16));
void func_ov000_021a49e0(Unk021a4a08 *a, UnkFunc *b);
void func_ov000_021a49f4(Unk021a4a08 *a, UnkFunc *b);
// Declared here until the code that defines it is decompiled.
