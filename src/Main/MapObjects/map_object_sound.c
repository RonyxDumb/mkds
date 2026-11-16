#include "Main/MapObjects/map_object_sound.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_start.h"
#include "Main/MapObjects/attractor.h"

void StartMapObjectSound(MapObject *mapObject, u32 soundId) {
    StartSound(&mapObject->mSound->mSoundSource, soundId, SOUND_VOLUME_MAX, 0);
}

void StartMapObjectSoundWhileRequested(MapObject *mapObject, u32 soundId) {
    StartSoundWhileRequested(&mapObject->mSound->mSoundSource, soundId, 0x7f, 0);
}
