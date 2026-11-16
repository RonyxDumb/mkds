#include "Main/Unknown/code_0208b484.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/System/Heap.h"
#include "Main/System/ArchiveFiles.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Kart/KartTurnEffects.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02077bc0.h"

u32 ptcm_alloc(u32 size) {
    u32 value0 = size;
    u32 sizeCopy;
    u32 heapGlobalAddress;
    u32 heapAllocAddress;
    heapGlobalAddress = (u32) &ptcm_sParticleHeap;
    heapAllocAddress = (u32) &heap_alloc;
    sizeCopy = value0;
    value0 = *(const u32 *) ((heapGlobalAddress) + (0));
    value0 = (u32) heap_alloc((void *) value0, sizeCopy);
    return value0;
}

void ptcm_init(void *defaultHeap) {
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

    *(u32 *) &ptcm_sGetParticleSetByIdFunc = (u32) ptcm_getParticleSetByIdNormal;
    if (scproc_getCurrentScene() == 2) {
        raceSetup = gRaceMultiConfig;
        if (raceSetup->mMode == MODE_MISSION_RUN) {
            *(u32 *) &ptcm_sGetParticleSetByIdFunc = (u32) ptcm_getParticleSetByIdMr;
            effectHeap = gOverlayData->mExpHeap;
            maxParticles = 0x96;
        }
        if (raceSetup->mCourseId == COURSE_ID_AWARD) {
            maxParticles = 0x12c;
            maxEmitters = 0x32;
        }
    }
    ptcm_sParticleHeap = effectHeap;
    ptcm_sRaceEffectParticleSet =
        spa_createParticleSet((void *(*) (u32)) ptcm_alloc, maxEmitters, maxParticles, 3, 0xe, race_getLastParticlePolygonId());
    raceEffectFile = arc_getMainRaceMainEffectArcFile(aRaceeffect_spa);
    spa_initParticleSet(ptcm_sRaceEffectParticleSet, raceEffectFile);
    spa_defaultUploadTextures(ptcm_sRaceEffectParticleSet);
    spa_defaultUploadPalettes(ptcm_sRaceEffectParticleSet);
    arc_resizeMainEffectArc(raceEffectFile, *OFFSET_PTR(u32, raceEffectFile, 0x18));
    ptcm_sRaceEffectFogOffParticleSet = spa_createParticleSet((void *(*) (u32)) ptcm_alloc, 0x1e, 0x64, 3, 0xe, 0x1e);
    raceEffectFogOffFile = arc_getMainRaceMainEffectArcFile(aEffectRaceeffe);
    spa_initParticleSet(ptcm_sRaceEffectFogOffParticleSet, raceEffectFogOffFile);
    spa_defaultUploadTextures(ptcm_sRaceEffectFogOffParticleSet);
    spa_defaultUploadPalettes(ptcm_sRaceEffectFogOffParticleSet);
    ptcm_sMissionEffectParticleSet = NULL;
    ptcm_sSpecialParticleUpdateFunc = NULL;
    ptcm_sCamFlashes = NULL;
    if (scproc_getCurrentScene() != 2) {
        return;
    }
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        missionEffectFile = NULL;
        ptcm_sMissionEffectParticleSet = spa_createParticleSet((void *(*) (u32)) ptcm_alloc, 0x32, 0xc8, 3, 0xe, 0x1e);
        arc_loadFile(aDataMissionrun, effectHeap, &missionEffectFile);
        spa_initParticleSet(ptcm_sMissionEffectParticleSet, missionEffectFile);
        spa_defaultUploadTextures(ptcm_sMissionEffectParticleSet);
        spa_defaultUploadPalettes(ptcm_sMissionEffectParticleSet);
        ptcm_sMissionEffectParticleSet->mMiscPolygonAttr = 0x8000;
    }
    ptcm_sRaceEffectParticleSet->mPolygonIDDrawOrder = 1;
    ptcm_sRaceEffectFogOffParticleSet->mPolygonIDDrawOrder = 1;
    if (ptcm_sMissionEffectParticleSet != NULL) {
        ptcm_sMissionEffectParticleSet->mPolygonIDDrawOrder = 1;
    }
    dptc_init(defaultHeap);
    if (gRaceMultiConfig->mCourseId != COURSE_ID_RAINBOW) {
        ptcm_sRaceEffectParticleSet->mMiscPolygonAttr = 0x8000;
    } else {
        ptcm_sRaceEffectParticleSet->mMiscPolygonAttr = 0;
    }
    rptc_initWeather();
    switch (gRaceMultiConfig->mCourseId) {
        case COURSE_ID_STADIUM:
            directionOrigin = data_021660fc;
            ptcm_sCamFlashes = heap_alloc(effectHeap, 0x64);
            for (emitterIndex = 0; emitterIndex < 6; emitterIndex++) {
                ptcm_sCamFlashes->mEmitters[emitterIndex] = NULL;
                VEC_Subtract(&ptcm_sCamFlashesPositions[emitterIndex], &directionOrigin, &offset);
                emitterDirection = &ptcm_sCamFlashes->mDirections[emitterIndex];
                if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z >= 0x10) {
                    vec_normalize(&offset, emitterDirection);
                }
            }
            ptcm_sCamFlashes->mEmitterTimer = 1;
            ptcm_sSpecialParticleUpdateFunc = (UnkFunc *) ptcm_updateCameraFlashes;
            break;
        case COURSE_ID_AWARD:
            ptcm_initAwardEmitters();
            break;
    }
}

void ptcm_update(void) {
    if (ptcm_sSpecialParticleUpdateFunc != NULL) {
        ptcm_sSpecialParticleUpdateFunc();
    }
    spa_updateSet(ptcm_sRaceEffectParticleSet);
    spa_updateSet(ptcm_sRaceEffectFogOffParticleSet);
    if (ptcm_sMissionEffectParticleSet != NULL) {
        spa_updateSet(ptcm_sMissionEffectParticleSet);
    }
}

void ptcm_render(MtxFx43 *viewMatrix) {
    spa_renderSet(ptcm_sRaceEffectParticleSet, viewMatrix);
    spa_renderSet(ptcm_sRaceEffectFogOffParticleSet, viewMatrix);
    if (ptcm_sMissionEffectParticleSet != NULL) {
        spa_renderSet(ptcm_sMissionEffectParticleSet, viewMatrix);
    }
}

void *ptcm_createEmitter(u32 effectId, const Vec3 *position) {
    s32 resourceId;
    Vec3 emitterPosition;
    Unk0201ca6c *emitter;
    SPLManager *splManager = ptcm_sGetParticleSetByIdFunc(&resourceId, effectId);
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    emitter = spa_createEmitter(splManager, resourceId, &emitterPosition);
    if (emitter != NULL) {
        if (emitter->field20->field0->field54 & 0x80) {
            emitter->field80_16 = 1;
        } else if (emitter->field20->field0->field54 & 0x40) {
            emitter->field80_16 = 2;
        }
    }
    return emitter;
}

void ptcm_createEmitterNoUpdateSkip(u32 effectId, const Vec3 *position, void *callbackParam, void (*initCallback)()) {
    s32 resourceId;
    Vec3 emitterPosition;
    SPLManager *splManager = ptcm_sGetParticleSetByIdFunc(&resourceId, effectId);
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    spa_createEmitterWithCallback(splManager, resourceId, &emitterPosition, (s32) callbackParam,
                                           (void (*)(Unk0201ca6c *, s32)) initCallback);
}

void ptcm_killEmitterDirect(Unk0201ca6c *emitter) {
    u32 splManager;
    u8 indexBuffer[8];
    splManager = (*(UnkWordFunc *) (u32) ptcm_sGetParticleSetByIdFunc)(indexBuffer, 0);
    spa_removeEmitter((SPLManager *) splManager, emitter);
}

void ptcm_killEmitterDirectSafe(Unk0201ca6c **emitterSlot) {
    u32 splManager;
    u8 indexBuffer[8];
    splManager = (*(UnkWordFunc *) (u32) ptcm_sGetParticleSetByIdFunc)(indexBuffer, 0);
    spa_removeEmitter((SPLManager *) splManager, *emitterSlot);
    *emitterSlot = NULL;
}

void ptcm_killEmitter(void **emitterSlot) {
    Unk0201ca6c *effect = *emitterSlot;
    effect->field24.field0_0 = 1;
    *emitterSlot = NULL;
}

Unk0201ca6c *ptcm_createFogOffEmitter(s32 resourceId, Vec3 *position) {
    Vec3 emitterPosition;
    Unk0201ca6c *emitter;
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    emitter = spa_createEmitter(ptcm_sRaceEffectFogOffParticleSet, resourceId, &emitterPosition);
    if (emitter != NULL) {
        if (emitter->field20->field0->field54 & 0x80) {
            emitter->field80_16 = 1;
        } else if (emitter->field20->field0->field54 & 0x40) {
            emitter->field80_16 = 2;
        }
    }
    return emitter;
}

void ptcm_setEmitterPosition(void *effectHandle, const Vec3 *position) {
    Unk0201ca6c *emitter = effectHandle;
    s32 positionX = position->x;
    s32 positionY = position->y;
    s32 positionZ = position->z;
    emitter->field28.x = (positionX >> 4) + emitter->field20->field0->field4.x;
    emitter->field28.y = (positionY >> 4) + emitter->field20->field0->field4.y;
    emitter->field28.z = (positionZ >> 4) + emitter->field20->field0->field4.z;
}

void *ptcm_208B498(u32 effectId, Vec3 *position, u32 kartIndex, s32 velocityScale) {
    s32 resourceId;
    Vec3 velocity;
    Vec3 emitterPosition;
    Unk0201ca6c *emitter;
    SPLManager *splManager = ptcm_sGetParticleSetByIdFunc(&resourceId, effectId);
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    emitter = spa_createEmitter(splManager, resourceId, &emitterPosition);
    if (emitter != NULL) {
        if (emitter->field20->field0->field54 & 0x80) {
            emitter->field80_16 = 1;
        } else if (emitter->field20->field0->field54 & 0x40) {
            emitter->field80_16 = 2;
        }
    }
    if (emitter != NULL) {
        velocity = driver_getById(kartIndex)->mEffectVelocity;
        velocity.x = ((s64) velocity.x * velocityScale) >> 12;
        velocity.y = ((s64) velocity.y * velocityScale) >> 12;
        velocity.z = ((s64) velocity.z * velocityScale) >> 12;
        emitter->field40 = velocity;
    }
    return emitter;
}

u32 ptcm_getParticleSetByIdNormal(u32 outIndex, u32 effectId) {
    u32 value0 = outIndex;
    u32 effectIdCopy = effectId;
    u32 managerGlobalAddress;
    managerGlobalAddress = (u32) &ptcm_sRaceEffectParticleSet;
    *(u32 *) ((value0) + (0)) = effectIdCopy;
    value0 = *(const u32 *) ((managerGlobalAddress) + (0));
    return value0;
}
