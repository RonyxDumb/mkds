#pragma once

#include "types.h"

typedef struct MatchingKey {
    /* 00 */ u8 mKeyId;
    /* 01 */ u8 mIsString;
    /* 02 */ u16 mPad;
    /* 04 */ char *mString;
    /* 08 */ void *mValue;
} MatchingKey;

u8 DWCi_GetNewMatchKey(void);
