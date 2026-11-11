#pragma once

#include "types.h"

typedef struct Unk0219a5e8 {
    /* 00 */ s32 mAddress;
    /* 04 */ u16 mPort;
} Unk0219a5e8;

s32 gti2ConnectionCompare(const Unk0219a5e8 *const *left, const Unk0219a5e8 *const *right);
