#pragma once

#include "types.h"

typedef struct MtxFx43 MtxFx43;

// Object behind oshd_sJgModel; only the field at 0x6e is used here.
typedef struct Unk020e5348 {
    /* 000 */ u8 mUnk_000[0x6e];
    /* 06e */ u16 mUnk_06e;
} Unk020e5348;

extern Unk020e5348 *oshd_sJgModel;

// Object behind Unk020e52bc.mUnk_004: byte offsets at 0x08 and 0x0c, a word at 0x1c.
typedef struct Unk020e52bc_4 {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ u32 mUnk_008;
    /* 00c */ u32 mUnk_00c;
    /* 010 */ u8 mUnk_010[0xc];
    /* 01c */ u32 mUnk_01c;
} Unk020e52bc_4;

// Object at Unk020e52bc_4.mUnk_008: a halfword at 0x0a, a table of byte offsets at 0x08.
typedef struct Unk020e52bc_8 {
    /* 000 */ u8 mUnk_000[0xa];
    /* 00a */ u16 mUnk_00a;
    /* 00c */ u8 mUnk_00c[4];
} Unk020e52bc_8;

// Object at Unk020e52bc_4.mUnk_00c: a halfword at 0x06, a table of byte offsets at 0x04.
typedef struct Unk020e52bc_c {
    /* 000 */ u8 mUnk_000[6];
    /* 006 */ u16 mUnk_006;
    /* 008 */ u8 mUnk_008[4];
} Unk020e52bc_c;

// Object behind oshd_sModel; only the field at 0x04 is used here.
typedef struct Unk020e52bc {
    /* 000 */ u32 mUnk_000;
    /* 004 */ Unk020e52bc_4 *mUnk_004;
} Unk020e52bc;

extern Unk020e52bc *oshd_sModel;

// Object behind oshd_sModelMat.
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

// Object behind oshd_sModelShp.
typedef struct Unk020e54e4 {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ u32 mUnk_008;
    /* 00c */ u32 mUnk_00c;
} Unk020e54e4;

extern Unk020e54e4 *oshd_sModelShp;

// Destination of oshd_setParams.
typedef struct ShadowMatrix {
    /* 000 */ s32 mUnk_000[12];
    /* 030 */ u16 mUnk_030;
} ShadowMatrix;

void oshd_renderJgShadow(u32 a, u32 b);
void oshd_renderJgShadowTransformed(Vec3 *scale, MtxFx43 *matrix, u32 c, u32 d);
void oshd_renderMat(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha);
void oshd_render(void *shadowData, void *wordPointer, u32 unused, u32 alpha);
s32 oshd_setParams(void *shadow, Vec3 *position, s32 scale, u32 alphaCap);
void oshd_init(void);
