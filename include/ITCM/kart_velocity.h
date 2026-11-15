#pragma once

#include "types.h"

typedef struct Kart Kart;

// Frames the ahead boost and the star effect last, frames the kart sinks before the effect ends, and the rev level
// under which the start rev drops to nothing.
#define KART_AHEAD_BOOST_MAX_FRAMES 0xb4
#define KART_STAR_MAX_FRAMES 0x1c2
#define KART_SINK_MAX_FRAMES 0x41
#define KART_REV_LEVEL_MIN 0xcd

void AdvanceKartByVelocity(Kart *kart);
