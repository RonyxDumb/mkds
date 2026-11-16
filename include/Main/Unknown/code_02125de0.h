#pragma once

#include "types.h"

// Argument block of gmenu_init (ten words read from it).
typedef struct Unk02125de0Arg {
    /* 00 */ BOOL field0;
    /* 04 */ void *field4;
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 field10;
    /* 14 */ BOOL field14;
    /* 18 */ void *field18;
    /* 1c */ BOOL field1C;
    /* 20 */ BOOL field20;
    /* 24 */ s32 field24;
} Unk02125de0Arg;

void gmenu_init(void *heap, Unk02125de0Arg *config);
