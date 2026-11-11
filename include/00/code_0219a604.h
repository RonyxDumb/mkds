#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;

typedef struct Gt2ConnectionEntry {
    /* 00 */ Gt2Connection *mValue;
} Gt2ConnectionEntry;

u32 gti2ConnectionHash(const Gt2ConnectionEntry *object, u32 modulus);
