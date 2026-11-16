#pragma once

#include "types.h"

typedef struct Kart Kart;

// Frame counts in AdvanceKartByVelocity above which the ahead boost (mAheadBoostFrames) and the star effect
// (mStarFrames) end and the sinking (mSinkFrames) ends, and the mRevLevel under which the selected kart's start-done
// rev is set to 0 after its per-frame decay.
#define KART_AHEAD_BOOST_MAX_FRAMES 0xb4
#define KART_STAR_MAX_FRAMES 0x1c2
#define KART_SINK_MAX_FRAMES 0x41
#define KART_REV_LEVEL_MIN 0xcd

void AdvanceKartByVelocity(Kart *kart);
