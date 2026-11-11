#include "Main/Unknown/code_020641b8.h"
#include "Main/Unknown/code_0206bcb0.h"

void SetKartSoundDistanceSquared(Kart *kart) {
    kart->mSoundSource.mDistanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
}
