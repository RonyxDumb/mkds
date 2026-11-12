#include "Main/Sound/map_object_sound_counter.h"

#include "Main/Sound/sound_start.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_source_list.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/map_start_sound_full_volume.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"

SoundStartParams gBalloonSoundStartParams = {0x154, NULL, 2, 0};

void ResetMapObjectSoundCounter(void) {
    gMapObjectSoundCounter = 0;
}

void StartMapObjectCounterSound(void *mapSound, s32 baseSoundId) {
    MapObjectSound *mapSoundCopy;
    s32 counter;

    mapSoundCopy = mapSound;
    counter = gMapObjectSoundCounter;
    StartSound(&mapSoundCopy->mSoundSource, baseSoundId + counter, (0x7f - (counter >> 1)) & 0xff, 0);
    gMapObjectSoundCounter = gMapObjectSoundCounter + 0xa;
}

void QueueShine16SoundWhileRequested(struct MapObjectSound *mapSound, s32 soundId) {
    AddSoundRequest(&data_0217d29c, mapSound->mSoundSource.mDistanceSquared + 0x15f90,
                    MapStartSoundWhileRequestedFullVolume, mapSound, soundId);
}

void QueueShine16Sound(struct MapObjectSound *mapSound, s32 soundId) {
    s32 distanceOffset;

    distanceOffset = 0;
    switch (soundId - 0x130) {
        case 0:
            distanceOffset = 0x640;
            break;
        case 1:
            distanceOffset = 0x1900;
            break;
        case 2:
            distanceOffset = 0x3840;
            break;
        case 8:
            distanceOffset = 0x6400;
            break;
        case 9:
            distanceOffset = 0xe100;
            break;
        case 3:
            distanceOffset = 0x9c40;
            break;
        case 7:
            distanceOffset = 0x19;
            break;
    }
    AddSoundRequest(&data_0217d29c, mapSound->mSoundSource.mDistanceSquared + distanceOffset,
                    StartMapObjectCounterSound, mapSound, soundId);
}

void StartBalloonSound(void *position, s32 distanceSquared) {
    SoundStartParams requestCopy;
    SoundStartParams *request;

    request = &requestCopy;
    *request = gBalloonSoundStartParams;
    request->mPositionSource = position;
    request->mDistanceSquared = distanceSquared;
    if (gRaceSoundKind & 1) {
        StartSoundOnPoolEntry(0, request->mSoundId, request->mPositionSource, request);
    }
}

void QueueBalloonSound(void *position, s32 distanceSquared) {
    AddSoundRequest(&data_0217d29c, distanceSquared, StartBalloonSound, position, distanceSquared);
}

void StartIronBallBounceSound(struct MapObjectSound *soundSource, s32 fixedValue) {
    s32 clampedValue;

    clampedValue = FROM_FIXED12(fixedValue);
    if (clampedValue > 0x1e) {
        clampedValue = 0x1e;
    }
    StartSound(&soundSource->mSoundSource, 0x1ce, ((clampedValue * 2) + 0x3c) & 0xff, clampedValue - 0xa);
}

void StartIronBallSpeedSound(struct MapObjectSound *mapSound, s32 fixedValue) {
    s32 pitchAndModSpeed;
    PlayingSound *sound;

    pitchAndModSpeed = FROM_FIXED12(fixedValue) + 5;
    sound = StartSoundWhileRequested(&mapSound->mSoundSource, 0x1cd, 0x7f, (s16) pitchAndModSpeed);
    if (sound != NULL) {
        NNS_SndPlayerSetTrackModSpeed(&sound->mSeqPlayer, 0xffff, pitchAndModSpeed);
    }
}

void InitSceneSoundsNop(void) {}
