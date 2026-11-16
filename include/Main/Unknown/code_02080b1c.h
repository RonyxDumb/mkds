#pragma once

#include "types.h"

// Object at 0x20 of an Unk02080b1c_00: halfwords at 0x02, 0x04 and 0x06.
typedef struct Unk02080b1c_20 {
    /* 00 */ u8 field0[2];
    /* 02 */ s16 field2;
    /* 04 */ s16 field4;
    /* 06 */ s16 field6;
} Unk02080b1c_20;

// Entries reached through PointLinkCursor: a table of pointers to further entries at 0x00 (the count is the halfword at
// 0x24), a vector pointer at 0x18, a word at 0x1c and an Unk02080b1c_20 pointer at 0x20.
typedef struct Unk02080b1c_00 {
    /* 00 */ struct Unk02080b1c_00 *field0[6];
    /* 18 */ Vec3 *field18;
    /* 1c */ s32 field1C;
    /* 20 */ Unk02080b1c_20 *field20;
    /* 24 */ u16 mNextCount;
    /* 26 */ u8 field26[2];
} Unk02080b1c_00;

typedef struct PointLinkCursor {
    /* 00 */ Unk02080b1c_00 *mLink;
    /* 04 */ Unk02080b1c_00 *mPreviousLink;
    /* 08 */ Vec3 mDirection;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ u16 mKartIndex;
    /* 1e */ u8 field1E;
} PointLinkCursor;

// Object of 0x2a bytes: an PointLinkCursor at 0x00, a word at 0x20, the halfword at 0x24 given to driver_getById and
// halfwords at 0x26 and 0x28.
typedef struct KartKillerCursor {
    /* 00 */ PointLinkCursor mPointLinkCursor;
    /* 20 */ s32 mAngleToLinkDegrees;
    /* 24 */ u16 mKillerKartIndex;
    /* 26 */ s16 field26;
    /* 28 */ s16 field28;
} KartKillerCursor;

void AdvancePointLinkCursor(PointLinkCursor *pointLinkCursor);
BOOL IsPastPointLink(PointLinkCursor *pointLinkCursor, Vec3 *position);
BOOL IsWithinPointLinkDistance(PointLinkCursor *pointLinkCursor, Vec3 *position);
