#pragma once

#include "types.h"

// A certificate authority entry the HTTPS code looks up by name (mDn) and uses with mModulus and mExponent to check a
// certificate. Each authority is one data-only file (ca_info_*.c): exponent bytes, modulus bytes and this entry, which
// holds the name text.
typedef struct CPSCaInfo {
    /* 00 */ char *mDn;
    /* 04 */ s32 mModulusLen;
    /* 08 */ u8 *mModulus;
    /* 0c */ s32 mExponentLen;
    /* 10 */ u8 *mExponent;
} CPSCaInfo;
