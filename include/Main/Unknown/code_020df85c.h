#pragma once

#include "types.h"

typedef struct MapObjectFlagsView {
    /* 00 */ u8 field0[0x2];
    /* 02 */ u16 field2;
} MapObjectFlagsView;

void efbub_waitStateInit(MapObjectFlagsView *bubble);
