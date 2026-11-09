#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "Main/Unknown/code_020846c0.h" // Nsbmd
#include "Main/Unknown/code_0207adf8.h" // ShadowModel

extern ShadowModel *gJgShadow;

extern Nsbmd *gObjShadow;

// Object behind data_0217b814.
typedef struct Unk020e53ac {
    /* 000 */ u8 mUnk_000[4];
    /* 004 */ u32 mUnk_004;
    /* 008 */ u32 mUnk_008;
    /* 00c */ u32 mUnk_00c;
    /* 010 */ u8 mUnk_010[4];
    /* 014 */ u32 mUnk_014;
    /* 018 */ u8 mUnk_018[4];
    /* 01c */ u16 mUnk_01c;
} Unk020e53ac;

// Object behind data_0217b818.
typedef struct Unk020e54e4 {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ u32 mUnk_008;
    /* 00c */ u32 mUnk_00c;
} Unk020e54e4;

extern Unk020e54e4 *data_0217b818;

// Destination of RefreshShadowMatrix.
typedef struct ShadowMatrix {
    /* 000 */ MtxFx43 mMatrix;
    /* 030 */ u16 mAlphaCap;
} ShadowMatrix;

void func_020e5348(u32 a, u32 b);
void DrawJgShadowWithMatrix(Vec3 *scale, MtxFx43 *matrix, u32 c, u32 d);
void func_020e53ac(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha);
void func_020e54e4(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha);
s32 RefreshShadowMatrix(ShadowMatrix *shadowCopy, Vec3 *position, s32 scale, u32 alphaCap);
void CreateObjShadowAndJgShadow(void);
