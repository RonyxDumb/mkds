#pragma once

#include "03/code_021c20c0.h"
#include "03/code_021c20dc.h"
#include "03/code_021c4ad4.h"
#include "03/code_021d079c.h"
#include "types.h"
#include "03/code_021d1770.h" // Unk021d1770
#include "03/code_021bf31c.h"
#include "03/code_021c25b4.h"
#include "03/code_021d28b0.h"

// Objects whose layout isn't known yet.
extern Unk021da108 *data_ov003_021da108;
extern u8 data_ov003_021da10c;
extern u8 data_ov003_021da150[];
extern u8 data_ov003_021da15c[];
extern u8 data_ov003_021da160[];
extern u8 data_ov003_021da164[];
extern u8 data_ov003_021da168[];
extern u8 data_ov003_021da16c[];
extern u8 data_ov003_021da170[];
extern u8 data_ov003_021da194[];
extern u8 data_ov003_021da1a8;
extern u8 data_ov003_021da1b0[];
extern u8 data_ov003_021da1bc[];
extern u8 data_ov003_021da1c0;
extern u8 data_ov003_021da1c4;
extern u8 data_ov003_021da1c8[];
extern u8 data_ov003_021da1cc;
extern u8 data_ov003_021da1d4;
extern u8 data_ov003_021da1d8;
extern u8 data_ov003_021da1dc;
extern u8 data_ov003_021da1e8[];
extern u8 data_ov003_021da1f0[];
extern u8 data_ov003_021da1f4[];
extern u8 data_ov003_021da1f8[];
extern u8 data_ov003_021da1fc[];
extern u8 data_ov003_021da200[];
extern u8 data_ov003_021da204[];
extern u8 data_ov003_021da208[];
extern u8 data_ov003_021da20c[];
extern u8 data_ov003_021da210[];
extern u8 data_ov003_021da214[];
extern u8 data_ov003_021da218;
extern u8 data_ov003_021da21c;
extern u8 data_ov003_021da220[];
extern u8 data_ov003_021da224;
extern u8 data_ov003_021da228[];
extern u8 data_ov003_021da230[];
extern u8 data_ov003_021da234[];
extern u8 data_ov003_021da240[];
extern u8 data_ov003_021da24c[];
extern u8 data_ov003_021da250;
extern u8 data_ov003_021da254;
extern u8 data_ov003_021da258;
extern u8 data_ov003_021da25c[];
extern u8 data_ov003_021da260[];
extern u8 data_ov003_021da268[];
extern u8 data_ov003_021da26c[];
extern u8 data_ov003_021da270[];
extern u8 data_ov003_021da274[];
extern u8 data_ov003_021da278[];
extern u8 data_ov003_021da27c[];
extern u8 data_ov003_021da280[];
// Object behind data_ov003_021da284: func_ov003_021ceaf8 passes 0x00 to func_ov003_021d1770 and reads the byte at
// 0x1e; func_ov003_021cef80 reads the byte at 0x1b.
typedef struct Unk021da284 {
    /* 00 */ Unk021d1770 *mUnk_00;
    /* 04 */ u8 mUnk_04[0x17];
    /* 1b */ s8 mUnk_1b;
    /* 1c */ u8 mUnk_1c[2];
    /* 1e */ u8 mUnk_1e;
} Unk021da284;

extern Unk021da284 *data_ov003_021da284;
extern u8 data_ov003_021da288[];
extern u8 data_ov003_021da2a4[];
extern u8 data_ov003_021da2ac[];
extern u8 data_ov003_021da2c0[];
extern u8 data_ov003_021da2c4[];
extern u8 data_ov003_021da2d4[];
extern u8 data_ov003_021da2f0[];
extern u8 data_ov003_021da32c[];
