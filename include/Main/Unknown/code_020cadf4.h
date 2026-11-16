#pragma once

#include "types.h"

// Object with a halfword at 0x04 that menu_gotoRaceStateRender, menu_gotoGhostStateRender and menu_returnTitleStateRender set.
typedef struct Unk020cadf4 {
    /* 00 */ u8 field0[4];
    /* 04 */ u16 field4;
} Unk020cadf4;

void menu_gotoRaceStateRender(Unk020cadf4 *a);
