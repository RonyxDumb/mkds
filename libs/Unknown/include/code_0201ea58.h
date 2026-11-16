#pragma once

#include "types.h"

// Two bytes: a signed 12-bit number, a 2-bit selector at bit 12, and two more bits.
typedef struct Unk0201ea84 {
    /* 00 */ s16 field0_0 : 12;
    /* 00 */ u16 field0_12 : 2;
    /* 00 */ u16 field0_14 : 2;
} Unk0201ea84;

// 6-byte entry of the array RectTableGetEntry indexes: two Unk0201ea84 and the two sizes added to what sub_201EBE8
// and sub_201EBA0 return for them.
typedef struct Unk0201eb54 {
    /* 00 */ Unk0201ea84 field0;
    /* 02 */ Unk0201ea84 field2;
    /* 04 */ u8 field4;
    /* 05 */ u8 field5;
} Unk0201eb54;

// Header of an array: a count at 6, then the entries from 8 (sub_201EA30 indexes 8-byte entries, sub_201EA58
// 12-byte ones, RectTableGetEntry and RectTableFindContaining 6-byte ones).
typedef struct Unk0201ea30 {
    /* 00 */ u8 field0[6];
    /* 06 */ u16 field6;
} Unk0201ea30;

void *sub_201EA58(Unk0201ea30 *a, s32 b);
s32 RectTableFindContaining(Unk0201ea30 *a, s32 b, s32 c);
Unk0201eb54 *RectTableGetEntry(Unk0201ea30 *a, s32 b);
u16 sub_201EB98(Unk0201ea30 *a);
s32 sub_201EBA0(Unk0201ea84 a, s32 b);
s32 sub_201EBE8(Unk0201ea84 a, s32 b);
