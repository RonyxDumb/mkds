#pragma once

#include "types.h"
#include "01/code_02181c3c.h"
#include "01/code_0219b250.h"
#include "Main/Unknown/code_01ff9000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/unk_021759c0.h"

// Object with a flags word at 0x48.
typedef struct Unk0218274c {
    /* 00 */ u8 mUnk_00[0x48];
    /* 48 */ u32 mUnk_48;
} Unk0218274c;

void func_ov001_0218254c(void);
void func_ov001_02182550(Unk02181c3c_list *param_1);
void func_ov001_0218263c(void *param_1, Unk02181c3c *param_2);
void func_ov001_021826fc(Unk0219b250 *param_1);
u8 func_ov001_0218274c(Unk02181c3c *param_1, Unk0218274c *param_2, u8 *param_3, u8 *param_4);
