#pragma once

#include "types.h"

// A root certificate authority entry the TLS code checks server certificates against. Each authority is one
// data-only file (ca_info_*.c): the exponent bytes, this entry, the distinguished name and the modulus.
typedef struct CPSCaInfo {
    /* 00 */ char *mDn;
    /* 04 */ s32 mModulusLen;
    /* 08 */ u8 *mModulus;
    /* 0c */ s32 mExponentLen;
    /* 10 */ u8 *mExponent;
} CPSCaInfo;
