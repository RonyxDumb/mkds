#pragma once

#include "types.h"

// Object passed to MPChunkPortCallback: a word at 4 and a pointer with its size.
typedef struct Unk02059920 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ void *mUnk_0c;
    /* 10 */ u16 mUnk_10;
} Unk02059920;

void MPChunkPortCallback(Unk02059920 *event);
