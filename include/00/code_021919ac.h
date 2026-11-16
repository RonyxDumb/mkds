#pragma once

#include "types.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/GameSpy/gpiBuffer.h"
#include "00/code_021947e4.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "00/unk_021b4000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/GameSpy/gpiUtility.h"
#include "00/code_021965a0.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_0213a460.h"
#include "00/GameSpy/gpiProfile.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/GameSpy/darray.h"
#include "00/code_02196000.h"
#include "00/GameSpy/gpiBuddy.h"
#include "00/GameSpy/nonport.h"
#include "00/code_021a3a18.h"
#include "00/code_0219488c.h"

// Object of 0x308 bytes that GpiStartConnect allocates and fills.
typedef struct Unk021919ac_q {
    /* 000 */ char field0[0x80];
    /* 080 */ char field80[0x21];
    /* 0a1 */ char fieldA1[0x21];
    /* 0c2 */ s8 fieldC2[0x100];
    /* 1c2 */ s8 field1C2[0x100];
    /* 2c2 */ char field2C2[0x41];
    /* 303 */ u8 field303;
    /* 304 */ s32 field304;
} Unk021919ac_q;

// Object of 0xf0 bytes that func_ov000_0219218c copies.
typedef struct Unk021919ac_f0 {
    /* 00 */ void *field0[6];
    /* 18 */ u8 field18[0xb0];
    /* c8 */ void *fieldC8;
    /* cc */ u8 fieldCC[0x24];
} Unk021919ac_f0;

// Object that GpiCreateOperation returns through its fourth argument.
typedef struct Unk021919ac_node {
    /* 00 */ u32 mType;
    /* 04 */ u32 field4;
    /* 08 */ void *field8;
    /* 0c */ Unk021919ac_f0 *fieldC;
    /* 10 */ u32 field10;
    /* 14 */ s32 field14;
    /* 18 */ s32 mId;
    /* 1c */ u32 field1C;
} Unk021919ac_node;

// Object of 0x204 bytes that func_ov000_0219222c allocates.
typedef struct Unk021919ac_m {
    /* 000 */ u32 field0;
    /* 004 */ u32 field4;
    /* 008 */ u8 field8[0x1fc];
} Unk021919ac_m;

// Two words that func_ov000_0219488c returns through its last argument.
typedef struct Unk021919ac_h {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
} Unk021919ac_h;

// Address of 8 bytes that GpiOpenSockets passes on.
typedef union Unk021919ac_sa {
    struct {
        /* 00 */ u8 field0;
        /* 01 */ u8 field1;
        /* 02 */ u16 field2;
        /* 04 */ u32 field4;
    } f;
    u32 w[2];
} Unk021919ac_sa;

// Declared here until the code that defines them is decompiled.

void func_ov000_021920d8(s8 *p, s32 n);
u32 GpiWriteLogin(GpConnection *p, Unk021919ac_q *q);
u32 GpiStartConnect(GpConnection *p, const char *a, const char *b, const char *c, const char *d, const s8 *e,
                    const s8 *f, const char *g, s32 h, s32 i, s32 j, s32 k, s32 l);
u32 GpiOpenSockets(GpConnection *p, Unk021919ac_node *n);
