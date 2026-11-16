#pragma once

#include "types.h"
#include "Main/MapObjects/map_object_park.h" // RandomState64

RandomState64 *GetRandomState(void);
BOOL TrySetBackLights(s32 firstRequest, s32 secondRequest);
void StopSceneSoundSetSeqWithSteps(u32 fadeSteps);
void ReleaseSceneSoundSetPlayer(void);
void StopSceneSoundSetSeq(void);
void StartSceneSoundSetSeq(void);
void SetSomeSceneSseqId(s32 seqId);
