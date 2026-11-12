#pragma once

#include "types.h"
#include "Main/MapObjects/balloon.h" // Balloon

void InitBalloon(
    Balloon *balloon); /* marks the balloon unowned (mUnk_a4 = -1) and parks the pooled object (ParkMapObject) */
