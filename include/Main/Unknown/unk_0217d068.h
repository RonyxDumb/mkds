#pragma once

#include "types.h"
#include "player.h"

// Passed by address to NNS_SndArcPlayerStartSeqArc, SetSndHandleTrackVolume and NNS_SndHandleInit; UpdateSeqQueue tests
// it for null.
extern NNSSndSeqPlayer *gSharedSeqHandle;
