#pragma once

#include "types.h"

// Two words.
typedef struct Unk02021e40 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02021e40;

// Element of an animation sequence: mUnk_00 is the address of the record of the frame, mUnk_04 how long it lasts.
typedef struct Unk02022188 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk02022188;

// 16 bytes: mUnk_00 elements of 8 bytes at mUnk_0c.
typedef struct Unk02021e1c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk02022188 *mUnk_0c;
} Unk02021e1c;

typedef struct Unk020229c8 Unk020229c8;

// Header of an animation bank: mUnk_04, mUnk_08 and mUnk_0c are offsets from the start that NNS_G2dUnpackNAN turns
// into addresses. mUnk_04 holds mUnk_00 sequences.
typedef struct Unk02021db0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ Unk02021e1c *mUnk_04;
    /* 08 */ Unk02022188 *mUnk_08;
    /* 0c */ Unk020229c8 *mUnk_0c;
} Unk02021db0;

// Header of a cell bank: mUnk_04 and mUnk_0c are offsets from the start that NNS_G2dUnpackNCE turns into addresses.
// mUnk_04 holds mUnk_00 entries (16 bytes, or 8 bytes without bit 0 of mUnk_02, see NNS_G2dGetCellDataByIdx).
typedef struct Unk02021dc8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk02021e40 *mUnk_0c;
} Unk02021dc8;

Unk02021e1c *NNS_G2dGetAnimSequenceByIdx(Unk02021db0 *bank, u32 idx);
void NNS_G2dUnpackNAN(Unk02021db0 *bank);
