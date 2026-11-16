#include "Main/Sound/map_object_sound_counter.h"
#include "Main/Sound/kart_sound.h"

#include "Main/Sound/sound_start.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_list.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/map_start_sound_full_volume.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/map_object_sound_counter_state.h"

SoundStartParams gBalloonSoundStartParams = {0x154, NULL, 2, 0};
s32 gKartSurfaceSoundSortOffsets[4] = {0xf4240, 0x64, 0x186a0, 0x64};

void ResetMapObjectSoundCounter(void) {
    gMapObjectSoundCounter = 0;
}

void StartMapObjectCounterSound(void *mapSound, s32 baseSoundId) {
    MapObjectSound *mapSoundCopy;
    s32 counter;

    mapSoundCopy = mapSound;
    counter = gMapObjectSoundCounter;
    StructMQRacerEntry_SomeFn_8(&mapSoundCopy->mSoundSource, baseSoundId + counter, (0x7f - (counter >> 1)) & 0xff, 0);
    gMapObjectSoundCounter = gMapObjectSoundCounter + 0xa;
}

void QueueShine16SoundWhileRequested(struct MapObjectSound *mapSound, s32 soundId) {
    AddSoundRequest(&gSoundRequestQueues[6], mapSound->mSoundSource.mDistanceSquared + 0x15f90,
                    MapStartSoundWhileRequestedFullVolume, mapSound, soundId);
}

void QueueShine16Sound(struct MapObjectSound *mapSound, s32 soundId) {
    s32 distanceOffset;

    distanceOffset = 0;
    switch (soundId - SHINE16_SOUND_BASE) {
        case SHINE16_SOUND_OTHER_LEADS:
            distanceOffset = 0x640;
            break;
        case SHINE16_SOUND_OTHER_JUST_BEHIND:
            distanceOffset = 0x1900;
            break;
        case SHINE16_SOUND_OTHER_FAR_BEHIND:
            distanceOffset = 0x3840;
            break;
        case SHINE16_SOUND_SPAWNED:
            distanceOffset = 0x6400;
            break;
        case SHINE16_SOUND_LANDED:
            distanceOffset = 0xe100;
            break;
        case SHINE16_SOUND_OTHER_HIT:
            distanceOffset = 0x9c40;
            break;
        case SHINE16_SOUND_ENTRY_HIT:
            distanceOffset = 0x19;
            break;
    }
    AddSoundRequest(&gSoundRequestQueues[6], mapSound->mSoundSource.mDistanceSquared + distanceOffset,
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
    AddSoundRequest(&gSoundRequestQueues[6], distanceSquared, StartBalloonSound, position, distanceSquared);
}

void StartIronBallBounceSound(struct MapObjectSound *soundSource, s32 fixedValue) {
    s32 clampedValue;

    clampedValue = FROM_FIXED12(fixedValue);
    if (clampedValue > 0x1e) {
        clampedValue = 0x1e;
    }
    StructMQRacerEntry_SomeFn_8(&soundSource->mSoundSource, 0x1ce, ((clampedValue * 2) + 0x3c) & 0xff, clampedValue - 0xa);
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

void nullsub_13(void) {}
