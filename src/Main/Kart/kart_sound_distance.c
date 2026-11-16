#include "Main/Kart/kart_sound_distance.h"
#include "Main/Kart/kart_drift.h"

void SetKartSoundDistanceSquared(Kart *kart) {
    kart->mSoundSource.mDistanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
}
