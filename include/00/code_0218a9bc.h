#pragma once

#include "types.h"

struct Unk0218a9bc;

// 0x24 bytes allocated by func_ov000_0218af28.
typedef struct SbServer {
    /* 00 */ u32 field0;
    /* 04 */ u16 field4;
    /* 08 */ u32 field8;
    /* 0c */ u16 fieldC;
    /* 10 */ u32 field10;
    /* 14 */ u8 field14;
    /* 15 */ u8 field15;
    /* 18 */ struct Hashtable *mKeyValues;
    /* 1c */ u32 mPing;
    /* 20 */ struct SbServer *field20;
} SbServer;

typedef struct Unk0218ae68 {
    /* 00 */ SbServer *field0;
    /* 04 */ SbServer *field4;
    /* 08 */ s32 field8;
} Unk0218ae68;

typedef struct Unk0218a9bc {
    /* 00 */ u32 field0;
    /* 04 */ s32 field4;
    /* 08 */ Unk0218ae68 field8;
    /* 14 */ Unk0218ae68 field14;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ u32 field28;
    /* 2c */ u8 field2C[0x14];
    /* 40 */ s32 field40;
    /* 44 */ UnkFunc *field44;
    /* 48 */ void *field48;
} Unk0218a9bc;

typedef struct Unk0218aa14 {
    /* 0 */ u8 field0;
    /* 1 */ u8 field1;
    /* 2 */ u16 field2;
    /* 4 */ u32 field4;
} Unk0218aa14;

void func_ov000_0218a9bc(Unk0218a9bc *p);
void func_ov000_0218aa14(Unk0218a9bc *p, s32 q);
