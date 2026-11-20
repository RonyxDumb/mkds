#pragma once
#include "types.h"

// Values of ModelAnimationFrameLoop.mLoopMode: 0 stops on the last frame, 1 wraps, 2 wraps mLoopCount times then stops.
typedef enum {
    MODEL_ANIMATION_LOOP_MODE_CLAMP,
    MODEL_ANIMATION_LOOP_MODE_WRAP,
    MODEL_ANIMATION_LOOP_MODE_LOOP_COUNT
} ModelAnimationLoopMode;
