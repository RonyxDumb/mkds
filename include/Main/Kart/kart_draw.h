#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart

BOOL StructMQRacerEntry_SomeFn_68(Kart *kart);
void StructMQRacerEntry_SomeFn_50(Kart *kart);
// Slot 2 of the other Karts: stores the squared distance in the sound source and passes it to
// mSoundDistanceSquaredChange, which keeps its change since the previous call.
void MQ_FnPtr2_Replay(Kart *kart);
