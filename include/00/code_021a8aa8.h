#pragma once

#include "types.h"
#include "00/code_021a6fa8.h"

// One entry of the array func_ov000_021a8b20 takes: an object, the bits asked for and the bits found.
typedef struct Unk021a8b20 {
    /* 00 */ Unk021a6fa8 *field0;
    /* 04 */ s16 field4;
    /* 06 */ u16 field6;
} Unk021a8b20;

typedef struct Unk021a8c94 {
    /* 00 */ u8 field0[4];
    /* 04 */ void *(*field4)(u32 a, u32 b);
    /* 08 */ void (*field8)(u32 a, void *b, u32 c);
    /* 0c */ s32 fieldC;
    /* 10 */ u32 field10[5];
    /* 24 */ u8 field24[8];
    /* 2c */ s32 field2C;
    /* 30 */ s32 field30;
} Unk021a8c94;

extern void *(*data_ov000_021b6014)(u32 a, u32 b);

typedef struct Unk021a8e18 {
    /* 0 */ u8 field0;
    /* 1 */ u8 field1;
    /* 2 */ u16 field2;
    /* 4 */ u32 field4;
} Unk021a8e18;

#include "00/types_021a8ab8.h"
#include "00/unk_021b5000.h"
#include "00/unk_021b4000.h"

extern Unk021b49b8 data_0216e204;
extern const char data_ov000_021b49e8[];
extern u32 data_ov000_021b600c;
extern u32 *data_ov000_021b6018[2];
extern Unk021a8f84 data_ov000_021b6020;
extern char data_ov000_021b6030[16];
extern Unk021b5f94 data_ov000_021b6040;
extern s8 data_ov000_021b6078[0x104];

void func_ov000_021a8aa8(Unk021a6fa8 *arg0);
Unk021a8ab8 **func_ov000_021a8ab8(Unk021a8ab8 **head, Unk021a8ab8 *node);
void func_ov000_021a8ad0(Unk021a8ab8 **head, Unk021a8ab8 *node);
void func_ov000_021a8ae8(Unk021a6fa8 *arg0);
void aMgSelect_battle_stage_s_nce_ncer_0(Unk021a6fa8 *arg0);
void func_ov000_021a8b08(u32 arg0, u32 arg1);
void func_ov000_021a8b10(void *arg0);
s32 func_ov000_021a8b20(void *a, s32 b, s64 c);
void func_ov000_021a8bb0(u32 a, u8 *b);
char *func_ov000_021a8bc0(s32 a, const void *b, char *c, u32 d);
u32 func_ov000_021a8c1c(u32 b, u32 *c);
char *func_ov000_021a8c6c(Unk021b5dfc a);
s32 aMgSelect_battle_stage_s_nce_ncer(void);
s32 func_ov000_021a8c94(void *b);
void func_ov000_021a8d98(int a);
void *func_ov000_021a8db8(u32 a);
s32 func_ov000_021a8dd8(Unk021a6fa8 *a, s32 b, u32 c);
s32 func_ov000_021a8e18(Unk021a6fa8 *a, Unk021a8e18 *b, s32 f);
s32 func_ov000_021a8e70(s32 descriptor);
void aThanksyouMBg00(unsigned int *p0, unsigned int *p1);
unsigned int func_ov000_021a8ed4(void);
unsigned int func_ov000_021a8f0c(unsigned int f, void *g);
s32 aEndingThanks01(s32 descriptor);
s32 func_ov000_021a9010(s32 descriptor);
s32 func_ov000_021a9018(s32 id, void *buffer, s32 length, s32 flags, void *addr);
s32 func_ov000_021a9088(s32 p0, void *p1, s32 p2, s32 p3);
s32 func_ov000_021a90a0(s32 id, void *buffer, s32 length, s32 flags, void *addr);
s32 func_ov000_021a9104(s32 p0, void *p1, s32 p2, s32 p3);
s32 func_ov000_021a911c(Unk021a6fa8 *a, Unk021a8e18 *b);
s32 func_ov000_021a918c(s32 domain, s32 type, s32 protocol);
