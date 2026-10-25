#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
extern const s32 data_ov001_021a7058[16];
extern const s32 data_ov001_021a710c[3][12];
extern const s32 data_ov001_021a719c[3][12];
extern const s32 data_ov001_021a722c[3][16];
extern const s32 data_ov001_021a72ec[3][16];
typedef struct Unk021a7c08 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Vec3 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk021a7c08;

extern Unk021a7c08 data_ov001_021a7c08;
extern u8 data_ov001_021a7da0[];
extern u8 data_ov001_021a7db4[];
extern u8 data_ov001_021a7dc8[];
extern u8 data_ov001_021a7dd8[];
