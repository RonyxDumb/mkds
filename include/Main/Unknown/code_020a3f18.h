#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

void InitBalloon(
    Balloon *balloon); /* marks the balloon unowned (mUnk_a4 = -1) and parks the pooled object (ParkMapObject) */
