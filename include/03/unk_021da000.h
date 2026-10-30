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
#include "03/code_021d34e0.h"

// Objects whose layout isn't known yet.
typedef struct Unk021da280 Unk021da280;
typedef struct Unk021cf260 Unk021cf260;
extern Unk021da108 *data_ov003_021da108;
extern u8 data_ov003_021da10c;
extern u8 data_ov003_021da150[];
// Object with a word and a halfword at its start.
typedef struct Unk021bf920 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021bf920;

// Object behind data_ov003_021da158.
typedef struct Unk021da158 {
    /* 00 */ Unk021bf920 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s8 mUnk_08;
} Unk021da158;

extern Unk021da158 *data_ov003_021da158;

// Object behind data_ov003_021da15c.
typedef struct Unk021da15c {
    /* 000 */ void *mUnk_000[3][4];
    /* 030 */ Unk021bf920 *mUnk_030[0x2f];
    /* 0ec */ Unk021bf920 *mUnk_0ec[4];
    /* 0fc */ Unk021d1770 *mUnk_0fc[2];
    /* 104 */ void *mUnk_104[4];
    /* 114 */ Unk021d1770 *mUnk_114;
    /* 118 */ Unk021d34e0 *mUnk_118;
    /* 11c */ u8 mUnk_11c;
    /* 11d */ u8 mUnk_11d;
    /* 11e */ s8 mUnk_11e;
    /* 11f */ s8 mUnk_11f;
    /* 120 */ s8 mUnk_120;
    /* 121 */ s8 mUnk_121;
    /* 122 */ u8 mUnk_122;
    /* 123 */ u8 mUnk_123;
    /* 124 */ u8 mUnk_124;
    /* 125 */ u8 mUnk_125;
} Unk021da15c;

extern Unk021da15c *data_ov003_021da15c;
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
extern Unk021da280 *data_ov003_021da280;
// Object behind data_ov003_021da284: func_ov003_021ceaf8 passes 0x00 to func_ov003_021d1770 and reads the byte at
// 0x1e; func_ov003_021cef80 reads the byte at 0x1b.
typedef struct Unk021da284 {
    /* 00 */ Unk021d1770 *mUnk_00;
    /* 04 */ Unk021d1770 *mUnk_04;
    /* 08 */ Unk021d1770 *mUnk_08[2];
    /* 10 */ void *mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 mUnk_18;
    /* 1a */ s8 mUnk_1a;
    /* 1b */ s8 mUnk_1b;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 mUnk_1e;
} Unk021da284;

extern Unk021da284 *data_ov003_021da284;
extern Unk021cf260 *data_ov003_021da288;
extern u16 *data_ov003_021da28c[];
extern u8 data_ov003_021da2a4[];
extern u8 data_ov003_021da2ac[];
extern u8 data_ov003_021da2c0[];
extern u8 data_ov003_021da2c4[];
extern u8 data_ov003_021da2d4[];
extern u8 data_ov003_021da2f0[];
extern u8 data_ov003_021da32c[];
