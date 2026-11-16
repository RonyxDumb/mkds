#pragma once

#include "types.h"

typedef struct PeerAddress PeerAddress;

// Object func_ov000_0219db18 reads and writes through its last parameter.
typedef struct Unk0219db18 {
    /* 00 */ u8 field0;
    /* 01 */ u8 field1;
    /* 02 */ u8 pad_02[6];
    /* 08 */ u32 field8;
} Unk0219db18;

u32 func_ov000_0219dabc(void);
void func_ov000_0219db18(s32 a, s32 b, PeerAddress *c, void *d);
