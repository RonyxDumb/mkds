#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

typedef struct Unk021990f8Entry {
    /* 00 */ s32 field0;
    /* 04 */ s32 field4;
    /* 08 */ u16 field8;
    /* 0a */ u8 fieldA[2];
    /* 0c */ u32 fieldC;
} Unk021990f8Entry;

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;


BOOL func_ov000_0219903c(Gt2Connection *a, u32 b, int c, int *d);
u32 func_ov000_021990f8(Gt2Connection *a, u16 b, s32 c);
u32 func_ov000_0219914c(Gt2Socket *a);
u32 func_ov000_0219922c(Gt2Socket *a, u32 b, u32 c);
u32 func_ov000_021992d4(Gt2Socket *a, u8 *b, s32 c, u32 d, u32 e);
u32 func_ov000_021994c4(Gt2Connection *a, u32 b, u8 *c, s32 d);
u32 func_ov000_02199554(Gt2Connection *a);
u32 func_ov000_0219958c(Gt2Connection *a, u8 *b, s32 c);
