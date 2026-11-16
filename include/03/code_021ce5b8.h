#pragma once

#include "types.h"
#include "code_02142eac.h"

typedef struct Unk021da280_1300 {
    /* 0 */ u8 field0[6];
    /* 6 */ u8 field6;
} Unk021da280_1300;

// Object behind data_ov003_021da280.
struct Unk021da280 {
    /* 0000 */ u8 field0[0xf00];
    /* 0f00 */ u8 fieldF00[0x400];
    /* 1300 */ Unk021da280_1300 field1300[16];
    /* 1370 */ void (*field1370)(u32);
    /* 1374 */ Unk021438f0 field1374;
    /* 13ac */ u8 field13AC[0xc];
    /* 13b8 */ Unk02142988 field13B8;
    /* 1b74 */ u32 field1B74;
    /* 1b78 */ u32 field1B78;
    /* 1b7c */ u32 field1B7C;
    /* 1b80 */ u8 field1B80;
    /* 1b81 */ u8 field1B81;
    /* 1b82 */ u8 field1B82;
};

typedef struct Unk021ce5b8_10 {
    /* 00 */ u8 field0[4];
    /* 04 */ u8 field4[6];
    /* 0a */ u8 fieldA[2];
    /* 0c */ u8 fieldC[8];
    /* 14 */ u8 field14;
    /* 15 */ u8 field15;
} Unk021ce5b8_10;

typedef struct Unk021ce5b8 {
    /* 00 */ u8 field0[0xe];
    /* 0e */ u16 fieldE;
    /* 10 */ Unk021ce5b8_10 *field10[1];
} Unk021ce5b8;

#include "03/unk_021da000.h"

void func_ov003_021ce5b8(Unk021ce5b8 *a);
void func_ov003_021ce6ac(Unk021ce5b8 *a);
void func_ov003_021ce7c0(Unk021425e8 *a);
void func_ov003_021ce834(u32 a);
u32 func_ov003_021ce848(void);
u32 func_ov003_021ce8ec(void);
u32 func_ov003_021ce920(void (*a)(u32));
