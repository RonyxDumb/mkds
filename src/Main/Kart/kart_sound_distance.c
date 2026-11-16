#include "Main/Kart/kart_sound_distance.h"
#include "Main/Kart/kart_drift.h"

void MQ_FnPtr2_Default(Kart *kart) {
    kart->mSoundSource.mDistanceSquared = GetAED0PlayerUnk(kart->mIndex);
}
