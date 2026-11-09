#pragma once

#include "types.h"

// Object with a halfword at 0x04 that RequestRaceOrWLMenuScene, RequestGhostScene and RequestTitleScene set.
typedef struct Unk020cadf4 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk020cadf4;

void RequestRaceOrWLMenuScene(Unk020cadf4 *sceneNumbers);
