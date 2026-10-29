#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h"

void *func_02079bcc(u32 arg0);

// 0xb4-byte entry: a word at 0x00.
typedef struct Unk02079bf0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xb0];
} Unk02079bf0;

Unk02079bf0 *func_02079bf0(u32 arg0);
