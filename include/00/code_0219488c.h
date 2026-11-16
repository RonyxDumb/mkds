#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Argument block of the search of func_ov000_021948bc.
typedef struct Unk0219488cArg {
    /* 00 */ const char *field0;
    /* 04 */ const char *field4;
    /* 08 */ void **field8;
    /* 0c */ BOOL fieldC;
} Unk0219488cArg;

s32 func_ov000_0219488c(GpConnection *a, const char *b, const char *c, void **d);
