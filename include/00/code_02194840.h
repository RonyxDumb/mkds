#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Argument block of the walk over the list at 0x428: the object, the function to call and its argument.
typedef struct Unk02194840Arg {
    /* 00 */ GpConnection *field0;
    /* 04 */ void *field4;
    /* 08 */ void *field8;
} Unk02194840Arg;

BOOL GpiForEachProfileWhileNonZero(GpConnection *a, void *b, void *c);
