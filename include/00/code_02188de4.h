#pragma once

#include "types.h"

struct ACWORK;

// Bytes handed out by FillApWepKey: a leading byte, then the payload.
typedef struct WCMWepDesc {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[0x50];
} WCMWepDesc;

// One of the 0x100-byte entries at the start of ACWORK.
typedef struct DWCMemPage {
    /* 00 */ u8 pad_00[0x40];
    /* 40 */ u8 mUnk_40[0x20];
    /* 60 */ u8 mUnk_60[0x20];
    /* 80 */ u8 mUnk_80[0x40];
    /* c0 */ u8 mUnk_c0[4];
    /* c4 */ u8 mUnk_c4[4];
    /* c8 */ u8 mUnk_c8[4];
    /* cc */ u8 mUnk_cc[4];
    /* d0 */ u8 mUnk_d0;
    /* d1 */ u8 mUnk_d1[0x14];
    /* e5 */ u8 pad_e5;
    /* e6 */ u8 mUnk_e6 : 2;
    /* e7 */ u8 mUnk_e7;
    /* e8 */ u8 pad_e8[0x18];
} DWCMemPage;


u32 FillApWepKey(struct ACWORK *object, u32 type, WCMWepDesc *out);
