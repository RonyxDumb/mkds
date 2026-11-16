#pragma once

#include "types.h"

// Returns mSceneFrames. Its only caller (StepDataSharing) discards the value.
unsigned int scene_getSceneFrameCounter(void);
unsigned int scene_cardPulledOutCallbackDontStop(void);
unsigned int scene_cardPulledOutCallbackDoStop(void);
