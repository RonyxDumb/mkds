#pragma once

#include "types.h"

typedef struct MtxFx43 MtxFx43;

// Object behind oshd_sJgModel; only the field at 0x6e is used here.
typedef struct Unk020e5348 {
    /* 000 */ u8 field0[0x6e];
    /* 06e */ u16 field6E;
} Unk020e5348;

extern Unk020e5348 *oshd_sJgModel;

// Object behind Unk020e52bc.field4: byte offsets at 0x08 and 0x0c, a word at 0x1c.
typedef struct Unk020e52bc_4 {
    /* 000 */ u8 field0[8];
    /* 008 */ u32 field8;
    /* 00c */ u32 fieldC;
    /* 010 */ u8 field10[0xc];
    /* 01c */ u32 field1C;
} Unk020e52bc_4;

// Object at Unk020e52bc_4.field8: a halfword at 0x0a, a table of byte offsets at 0x08.
typedef struct Unk020e52bc_8 {
    /* 000 */ u8 field0[0xa];
    /* 00a */ u16 fieldA;
    /* 00c */ u8 fieldC[4];
} Unk020e52bc_8;

// Object at Unk020e52bc_4.fieldC: a halfword at 0x06, a table of byte offsets at 0x04.
typedef struct Unk020e52bc_c {
    /* 000 */ u8 field0[6];
    /* 006 */ u16 field6;
    /* 008 */ u8 field8[4];
} Unk020e52bc_c;

// Object behind oshd_sModel; only the field at 0x04 is used here.
typedef struct Unk020e52bc {
    /* 000 */ u32 field0;
    /* 004 */ Unk020e52bc_4 *field4;
} Unk020e52bc;

extern Unk020e52bc *oshd_sModel;

// Object behind oshd_sModelMat.
typedef struct Unk020e53ac {
    /* 000 */ u8 field0[4];
    /* 004 */ u32 field4;
    /* 008 */ u32 field8;
    /* 00c */ u32 fieldC;
    /* 010 */ u8 field10[4];
    /* 014 */ u32 field14;
    /* 018 */ u8 field18[4];
    /* 01c */ u16 field1C;
} Unk020e53ac;

// Object behind oshd_sModelShp.
typedef struct Unk020e54e4 {
    /* 000 */ u8 field0[8];
    /* 008 */ u32 field8;
    /* 00c */ u32 fieldC;
} Unk020e54e4;

extern Unk020e54e4 *oshd_sModelShp;

// Destination of oshd_setParams.
typedef struct ShadowMatrix {
    /* 000 */ s32 field0[12];
    /* 030 */ u16 field30;
} ShadowMatrix;

void oshd_renderJgShadow(u32 a, u32 b);
void oshd_renderJgShadowTransformed(Vec3 *scale, MtxFx43 *matrix, u32 c, u32 d);
void oshd_renderMat(ShadowMatrix *shadow, void *wordPointer, u32 unused, u32 alpha);
void oshd_render(void *shadowData, void *wordPointer, u32 unused, u32 alpha);
s32 oshd_setParams(void *shadow, Vec3 *position, s32 scale, u32 alphaCap);
void oshd_init(void);
