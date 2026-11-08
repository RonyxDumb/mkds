#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_020e6fd4.h"

void StartMapObjectSound(MapObject *mapObject, u32 soundId) {
    StartSound(&mapObject->mSound->mSoundSource, soundId, 0x7f, 0);
}

void StartMapObjectSoundWhileRequested(MapObject *mapObject, u32 soundId) {
    StartSoundWhileRequested(&mapObject->mSound->mSoundSource, soundId, 0x7f, 0);
}
