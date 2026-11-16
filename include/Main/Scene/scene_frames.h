#pragma once

#include "types.h"

// Returns mSceneFrames. Its only caller (StepDataSharing) discards the value.
unsigned int GetSceneFrames(void);
unsigned int AnotherUserCardPulledOutCallback(void);
unsigned int SomeUserCardPulledOutCallback(void);
