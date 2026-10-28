#pragma once

#include "types.h"

struct Unk020748b8_218;
struct Unk0208fd8c;
struct Unk020888b4;
struct Unk0208fd8c_08;

// Four vectors and words at 0x30, 0x34 and 0x38.
typedef struct Unk0207b960 {
    /* 00 */ Vec3 mUnk_00[4];
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
} Unk0207b960;

void func_0207b960(Vec3 *a, Unk0207b960 *b);
void func_0207bc9c(Vec3 *a, Unk0207b960 *b, struct Unk020748b8_218 *c, s32 d);
void func_0207bd6c(Unk0207b960 *a, struct Unk020748b8_218 *b);
void func_0207be40(Unk0207b960 *a, struct Unk020748b8_218 *b);
void func_0207becc(struct Unk0208fd8c *a, struct Unk020888b4 *b);
s32 func_0207bfac(struct Unk0208fd8c *a);
void func_0207bfd4(struct Unk0208fd8c *a, struct Unk0208fd8c_08 *b);
s32 func_0207c078(struct Unk0208fd8c *a);
void func_0207c0a0(struct Unk0208fd8c *a);
void func_0207c144(struct Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c270(struct Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c2ec(struct Unk0208fd8c *a, struct Unk020888b4 *b);
