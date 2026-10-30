#pragma once

#include "types.h"
#include "Main/Unknown/code_02000000.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_02007478.h"
#include "Main/Unknown/code_020075f8.h"
#include "Main/Unknown/code_0200aeec.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02008908.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"

// Filled by func_0200806c.
typedef struct Unk020072c0_buf {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d[3];
} Unk020072c0_buf;

int func_020071b4(void);
u32 func_020072c0(void);
