#pragma once

#include "types.h"

// Object passed to func_02059920: a word at 4 and a pointer with its size.
typedef struct Unk02059920 {
    /* 00 */ u8 field0[2];
    /* 02 */ u16 field2;
    /* 04 */ u16 field4;
    /* 06 */ u8 field6[6];
    /* 0c */ void *fieldC;
    /* 10 */ u16 field10;
} Unk02059920;

void func_02059920(Unk02059920 *a);
