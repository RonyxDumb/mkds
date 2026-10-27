#pragma once

#include "types.h"

// 0x10-byte elements of data_021691ec (49 of them): four function pointers. func_020beb9c finds the element
// whose mUnk_00 is a given function and stores the other three in the object behind data_0217b3dc.
typedef struct Unk021691ec {
    /* 00 */ s32 (*mUnk_00)(void);
    /* 04 */ void (*mUnk_04)(void);
    /* 08 */ void (*mUnk_08)(void);
    /* 0c */ void (*mUnk_0c)(void *);
} Unk021691ec;

void func_020beb9c(void);
