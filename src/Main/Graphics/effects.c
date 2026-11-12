#include "Main/Graphics/effects.h"

#include "Main/MapObjects/data_0217b000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/System/heap.h"
#include "Main/System/archive_slots.h"
#include "Main/Race/race.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/emitters.h"
#include "Main/Kart/kart_level.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_effects.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_02147cd8.h"
#include "Main/Kart/karts.h"
#include "Main/Graphics/model_effects.h"

Vec3 gStadiumEmitterDirectionOrigin = {-348160, 0x67000, 0x2e000};
AwardEmitterEffectIds gAwardEmitterEffectIds = {{0x83, 0x84, 0x85, 0x86, 0x81, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a}};
AwardFirstEffectIds gAwardFirstEffectIds = {{0x87, 0x82}};
struct StadiumEmitters *gStadiumEmitters;
void *gSPLManagerHeap;
struct SPLManager *gRaceEffectSPLManager;
void (*gAdvanceEmittersFunction)(void);
struct SPLManager *gRaceEffectFogOffSPLManager;
GetSPLManagerFunc *gGetSPLManagerFunction;

void *HeapAllocForSPLManager(u32 size) {
    return HeapAlloc(gSPLManagerHeap, size);
}

void InitEffects(void *defaultHeap) {
    s32 maxParticles = 0x78;
    s32 maxEmitters = 0x28;
    void *effectHeap = defaultHeap;
    void *raceEffectFile;
    void *raceEffectFogOffFile;
    void *missionEffectFile;
    u8 emitterIndex;
    Vec3 directionOrigin;
    Vec3 offset;
    RaceSetup *raceSetup;
    Vec3 *emitterDirection;

    gGetSPLManagerFunction = GetRaceEffectSPLManager;
    if (GetCurrentSceneNumber() == 2) {
        raceSetup = gRaceSetup;
        if (raceSetup->mMode == MODE_MISSION_RUN) {
            gGetSPLManagerFunction = GetSPLManagerForEffectId;
            effectHeap = gOverlayLoader->mExpHeap;
            maxParticles = 0x96;
        }
        if (raceSetup->mCourseId == COURSE_ID_AWARD) {
            maxParticles = 0x12c;
            maxEmitters = 0x32;
        }
    }
    gSPLManagerHeap = effectHeap;
    gRaceEffectSPLManager =
        SPLManager_New(HeapAllocForSPLManager, maxEmitters, maxParticles, 3, 0xe, GetSplMaxPolyId());
    raceEffectFile = FindMainRaceOrMainEffectFile(gRaceEffectSpaName);
    SPLManager_LoadResources(gRaceEffectSPLManager, raceEffectFile);
    SPLManager_UploadTextures(gRaceEffectSPLManager);
    SPLManager_UploadPalettes(gRaceEffectSPLManager);
    ResizeMainEffectArchiveBlock(raceEffectFile, *OFFSET_PTR(u32, raceEffectFile, 0x18));
    gRaceEffectFogOffSPLManager = SPLManager_New(HeapAllocForSPLManager, 0x1e, 0x64, 3, 0xe, 0x1e);
    raceEffectFogOffFile = FindMainRaceOrMainEffectFile(gRaceEffectFogOffSpaName);
    SPLManager_LoadResources(gRaceEffectFogOffSPLManager, raceEffectFogOffFile);
    SPLManager_UploadTextures(gRaceEffectFogOffSPLManager);
    SPLManager_UploadPalettes(gRaceEffectFogOffSPLManager);
    gMissionRunSPLManager = NULL;
    gAdvanceEmittersFunction = NULL;
    gStadiumEmitters = NULL;
    if (GetCurrentSceneNumber() != 2) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        missionEffectFile = NULL;
        gMissionRunSPLManager = SPLManager_New(HeapAllocForSPLManager, 0x32, 0xc8, 3, 0xe, 0x1e);
        LoadFileIntoHeap(gMissionEffectSpaName, effectHeap, &missionEffectFile);
        SPLManager_LoadResources(gMissionRunSPLManager, missionEffectFile);
        SPLManager_UploadTextures(gMissionRunSPLManager);
        SPLManager_UploadPalettes(gMissionRunSPLManager);
        gMissionRunSPLManager->mMiscPolygonAttr = 0x8000;
    }
    gRaceEffectSPLManager->mPolygonIDDrawOrder = 1;
    gRaceEffectFogOffSPLManager->mPolygonIDDrawOrder = 1;
    if (gMissionRunSPLManager != NULL) {
        gMissionRunSPLManager->mPolygonIDDrawOrder = 1;
    }
    InitKartTurnEffects(defaultHeap);
    if (gRaceSetup->mCourseId != COURSE_ID_RAINBOW) {
        gRaceEffectSPLManager->mMiscPolygonAttr = 0x8000;
    } else {
        gRaceEffectSPLManager->mMiscPolygonAttr = 0;
    }
    InitCourseCameraEffects();
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_STADIUM:
            directionOrigin = gStadiumEmitterDirectionOrigin;
            gStadiumEmitters = HeapAlloc(effectHeap, 0x64);
            for (emitterIndex = 0; emitterIndex < 6; emitterIndex++) {
                gStadiumEmitters->mEmitters[emitterIndex] = NULL;
                VEC_Subtract(&gStadiumEmitterPositions[emitterIndex], &directionOrigin, &offset);
                emitterDirection = &gStadiumEmitters->mDirections[emitterIndex];
                if (LENGTH_SQUARED(offset) >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&offset, emitterDirection);
                }
            }
            gStadiumEmitters->mEmitterTimer = 1;
            gAdvanceEmittersFunction = AdvanceStadiumEmitters;
            break;
        case COURSE_ID_AWARD:
            CreateAwardEmitters();
            break;
    }
}

void UpdateEffects(void) {
    if (gAdvanceEmittersFunction != NULL) {
        gAdvanceEmittersFunction();
    }
    SPLManager_Update(gRaceEffectSPLManager);
    SPLManager_Update(gRaceEffectFogOffSPLManager);
    if (gMissionRunSPLManager != NULL) {
        SPLManager_Update(gMissionRunSPLManager);
    }
}

void DrawEffects(MtxFx43 *viewMatrix) {
    SPLManager_Draw(gRaceEffectSPLManager, viewMatrix);
    SPLManager_Draw(gRaceEffectFogOffSPLManager, viewMatrix);
    if (gMissionRunSPLManager != NULL) {
        SPLManager_Draw(gMissionRunSPLManager, viewMatrix);
    }
}

void *StartEffect(u32 effectId, const Vec3 *position) {
    s32 resourceId;
    Vec3 emitterPosition;
    ParticleEmitter *emitter;
    SPLManager *splManager = gGetSPLManagerFunction(&resourceId, effectId);
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    emitter = SPLManager_CreateEmitter(splManager, resourceId, &emitterPosition);
    if (emitter != NULL) {
        if (emitter->mResource->mHeader->mUpdateCycleBits & 0x80) {
            emitter->mUpdateCycle = 1;
        } else if (emitter->mResource->mHeader->mUpdateCycleBits & 0x40) {
            emitter->mUpdateCycle = 2;
        }
    }
    return emitter;
}

void StartEffectWithCallback(u32 effectId, const Vec3 *position, void *callbackParam, void (*initCallback)()) {
    s32 resourceId;
    Vec3 emitterPosition;
    SPLManager *splManager = gGetSPLManagerFunction(&resourceId, effectId);
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    SPLManager_CreateEmitterWithCallbackEx(splManager, resourceId, &emitterPosition, (s32) callbackParam,
                                           (void (*)(ParticleEmitter *, s32)) initCallback);
}

void DeleteEffect(ParticleEmitter *emitter) {
    SPLManager *splManager;
    s32 indexBuffer[2];
    splManager = gGetSPLManagerFunction(indexBuffer, 0);
    SPLManager_DeleteEmitter(splManager, emitter);
}

void DeleteEffectAndClearPointer(ParticleEmitter **emitterSlot) {
    SPLManager *splManager;
    s32 indexBuffer[2];
    splManager = gGetSPLManagerFunction(indexBuffer, 0);
    SPLManager_DeleteEmitter(splManager, *emitterSlot);
    *emitterSlot = NULL;
}

void StopEffectAndClearPointer(void **emitterSlot) {
    ParticleEmitter *effect = *emitterSlot;
    effect->mFlags.mEnding = 1;
    *emitterSlot = NULL;
}

ParticleEmitter *StartRaceFogOffEffect(s32 resourceId, Vec3 *position) {
    Vec3 emitterPosition;
    ParticleEmitter *emitter;
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    emitter = SPLManager_CreateEmitter(gRaceEffectFogOffSPLManager, resourceId, &emitterPosition);
    if (emitter != NULL) {
        if (emitter->mResource->mHeader->mUpdateCycleBits & 0x80) {
            emitter->mUpdateCycle = 1;
        } else if (emitter->mResource->mHeader->mUpdateCycleBits & 0x40) {
            emitter->mUpdateCycle = 2;
        }
    }
    return emitter;
}

void PlaceEffect(void *effectHandle, const Vec3 *position) {
    ParticleEmitter *emitter = effectHandle;
    s32 positionX = position->x;
    s32 positionY = position->y;
    s32 positionZ = position->z;
    emitter->mPosition.x = (positionX >> 4) + emitter->mResource->mHeader->mPositionOffset.x;
    emitter->mPosition.y = (positionY >> 4) + emitter->mResource->mHeader->mPositionOffset.y;
    emitter->mPosition.z = (positionZ >> 4) + emitter->mResource->mHeader->mPositionOffset.z;
}

void *StartEffectWithKartVelocity(u32 effectId, Vec3 *position, u32 kartIndex, s32 velocityScale) {
    s32 resourceId;
    Vec3 velocity;
    Vec3 emitterPosition;
    ParticleEmitter *emitter;
    SPLManager *splManager = gGetSPLManagerFunction(&resourceId, effectId);
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    emitter = SPLManager_CreateEmitter(splManager, resourceId, &emitterPosition);
    if (emitter != NULL) {
        if (emitter->mResource->mHeader->mUpdateCycleBits & 0x80) {
            emitter->mUpdateCycle = 1;
        } else if (emitter->mResource->mHeader->mUpdateCycleBits & 0x40) {
            emitter->mUpdateCycle = 2;
        }
    }
    if (emitter != NULL) {
        velocity = GetKart(kartIndex)->mEffectVelocity;
        velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, velocityScale);
        velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, velocityScale);
        velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, velocityScale);
        emitter->mVelocity = velocity;
    }
    return emitter;
}

SPLManager *GetRaceEffectSPLManager(s32 *outIndex, s32 effectId) {
    *outIndex = effectId;
    return gRaceEffectSPLManager;
}
