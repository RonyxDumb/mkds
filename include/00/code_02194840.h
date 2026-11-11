#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Argument block of the walk over the list at 0x428: the object, the function to call and its argument.
typedef struct GPIProfileMapData {
    /* 00 */ GpConnection *mConnection;
    /* 04 */ void *mFunc;
    /* 08 */ void *mData;
} GPIProfileMapData;

BOOL GpiForEachProfileWhileNonZero(GpConnection *a, void *b, void *c);
