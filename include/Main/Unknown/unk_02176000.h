#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_02003024.h"

// Objects whose layout isn't known yet.
extern RomArchiveParentView data_02176300;

// Object at data_02176300; the word at 0x46c8 is a pointer, the bytes at 0x340 and the halfword at 0x4c4 are used
// by WFS_Start.
typedef struct Unk021762e0 {
    /* 0000 */ u8 field0[0x340];
    /* 0340 */ u8 field340[0x184];
    /* 04c4 */ u16 field4C4;
    /* 04c6 */ u8 field4C6[0x4202];
    /* 46c8 */ struct RomArchiveFileNode *field46C8;
} Unk021762e0;

// The part of Unk021762e0 from 0x4000.
typedef struct Unk021762e0_4000 {
    /* 000 */ u8 field0[0x6c8];
    /* 6c8 */ struct RomArchiveFileNode *field6C8;
} Unk021762e0_4000;
