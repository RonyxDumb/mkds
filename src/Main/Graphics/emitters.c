#include "Main/Graphics/emitters.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/result_archive_path.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_0214d018.h"
#include "Main/Graphics/effects.h"
#include "Main/Graphics/stem_names.h"
#include "Main/System/init_after_startup.h"

const StemSetParams gWinStems = {1, 1, 0, 0, {gStemNameWin, NULL}};
const StemSetParams gFailedStems = {1, 1, 1, 0, {gStemNameFailed, NULL}};
const StemSetParams gGoalStems = {1, 1, 1, 0, {gStemNameGoal, NULL}};
const StemSetParams gLoseStems = {1, 1, 0, 0, {gStemNameLose, NULL}};
const StemSetParams gCompleteStems = {1, 1, 1, 0, {gStemNameComplete, NULL}};

const s32 gStadiumEmitterEffectIds[12] = {0x6f, 0x6e, 0x6d, 0x64, 0x6b, 0x6a, 0x69, 0x68, 0x67, 0x66, 0x65, 0x6c};
const Vec3 gStadiumEmitterPositions[6] = {{0xba000, 0x67000, 0x2e000},  {0x34000, 0x67000, 0x119000},
                                          {-909312, 0x67000, 0x119000}, {-1466368, 0x67000, 0x2e000},
                                          {-909312, 0x67000, -774144},  {0x34000, 0x67000, -774144}};

KartPhysicalParamTable *gKartPhysicalParamTable;

static inline u32 StadiumEmittersNextRandomBelow(RandomState64 *randomState, u32 limit) {
    randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
    if (limit == 0) {
        return randomState->mValue >> 32;
    }
    return ((randomState->mValue >> 32) * limit) >> 32;
}

// Ids from 1000 up belong to the second manager (Mission Run); the id inside the manager goes to *a.
SPLManager *GetSPLManagerForEffectId(s32 *outIndex, s32 effectId) {
    if (effectId >= 0x3e8) {
        effectId -= 0x3e8;
        *outIndex = effectId;
        return gMissionRunSPLManager;
    }
    *outIndex = effectId;
    return gRaceEffectSPLManager;
}

void AdvanceStadiumEmitters(void) {
    s16 slotIndex;
    s32 bestIndex;
    Vec3 cameraForward;
    s32 effectIds[6];
    s32 emitterDirectionIndices[6];
    s32 bestDot;
    s32 previousIndex;
    s32 nextIndex;
    s32 emitterIndex;
    s32 randomDraw;
    GetSPLManagerFunc *getManager;
    Camera *camera;

    gStadiumEmitters->mEmitterTimer--;
    if (gStadiumEmitters->mEmitterTimer > 0) {
        return;
    }
    bestDot = -0x1000;
    bestIndex = -1;
    camera = GetCurrentCamera();
    cameraForward = camera->mForward;
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        StadiumEmitters *stadiumEmitters = gStadiumEmitters;
        if (stadiumEmitters->mEmitters[slotIndex] != NULL) {
            s32 effectIndex;
            ParticleEmitter **emitterSlot = &stadiumEmitters->mEmitters[slotIndex];
            SPLManager_DeleteEmitter(gGetSPLManagerFunction(&effectIndex, 0), *emitterSlot);
            *emitterSlot = NULL;
        }
    }
    for (slotIndex = 0; slotIndex < 6; slotIndex++) {
        s32 dot = VEC_DotProduct(&cameraForward, &gStadiumEmitters->mDirections[slotIndex]);
        if (dot >= bestDot) {
            bestDot = dot;
            bestIndex = slotIndex;
        }
    }
    previousIndex = bestIndex - 1;
    if (previousIndex < 0) {
        previousIndex = 5;
    }
    nextIndex = bestIndex + 1;
    if (nextIndex >= 6) {
        nextIndex = 0;
    }
    effectIds[0] = gStadiumEmitterEffectIds[previousIndex * 2];
    effectIds[1] = gStadiumEmitterEffectIds[previousIndex * 2 + 1];
    effectIds[2] = gStadiumEmitterEffectIds[bestIndex * 2];
    effectIds[3] = gStadiumEmitterEffectIds[bestIndex * 2 + 1];
    effectIds[4] = gStadiumEmitterEffectIds[nextIndex * 2];
    effectIds[5] = gStadiumEmitterEffectIds[nextIndex * 2 + 1];
    emitterDirectionIndices[0] = emitterDirectionIndices[1] = previousIndex;
    emitterDirectionIndices[2] = emitterDirectionIndices[3] = bestIndex;
    emitterDirectionIndices[4] = emitterDirectionIndices[5] = nextIndex;
    for (emitterIndex = 0; emitterIndex < 6; emitterIndex++) {
        s32 effectIndex;
        Vec3 position;
        ParticleEmitter *emitter;
        SPLManager *manager;
        const Vec3 *tablePosition = &gStadiumEmitterPositions[emitterDirectionIndices[emitterIndex]];
        getManager = gGetSPLManagerFunction;
        manager = getManager(&effectIndex, effectIds[emitterIndex]);
        position.x = tablePosition->x >> 4;
        position.y = tablePosition->y >> 4;
        position.z = tablePosition->z >> 4;
        emitter = SPLManager_CreateEmitter(manager, effectIndex, &position);
        if (emitter != NULL) {
            if (emitter->mResource->mHeader->mUpdateCycleBits & PARTICLE_UPDATE_CYCLE_BIT_FIRST) {
                emitter->mUpdateCycle = PARTICLE_UPDATE_CYCLE_FIRST;
            } else if (emitter->mResource->mHeader->mUpdateCycleBits & PARTICLE_UPDATE_CYCLE_BIT_SECOND) {
                emitter->mUpdateCycle = PARTICLE_UPDATE_CYCLE_SECOND;
            }
        }
        gStadiumEmitters->mEmitters[emitterIndex] = emitter;
    }
    randomDraw = StadiumEmittersNextRandomBelow(&gRaceProgress->mLocalRandom, 0x19);
    gStadiumEmitters->mEmitterTimer = (u16) randomDraw + 0x14;
}

void CreateAwardEmitters(void) {
    AwardEmitterEffectIds secondEffectIds = gAwardEmitterEffectIds;
    AwardFirstEffectIds firstEffectIds = gAwardFirstEffectIds;
    s32 baseX = gAwardEmitterPosition.x;
    s32 baseY = gAwardEmitterPosition.y;
    s32 baseZ = gAwardEmitterPosition.z;
    u16 emitterIndex;
    s32 emitX = baseX >> 4;
    s32 emitY = baseY >> 4;
    s32 emitZ = baseZ >> 4;

    for (emitterIndex = 0; emitterIndex < 2; emitterIndex++) {
        s32 effectIndex;
        Vec3 position;
        ParticleEmitter *emitter;
        SPLManager *manager = gGetSPLManagerFunction(&effectIndex, firstEffectIds.mEffectIds[emitterIndex]);
        position.x = emitX;
        position.y = emitY;
        position.z = emitZ;
        emitter = SPLManager_CreateEmitter(manager, effectIndex, &position);
        if (emitter != NULL) {
            if (emitter->mResource->mHeader->mUpdateCycleBits & PARTICLE_UPDATE_CYCLE_BIT_FIRST) {
                emitter->mUpdateCycle = PARTICLE_UPDATE_CYCLE_FIRST;
            } else if (emitter->mResource->mHeader->mUpdateCycleBits & PARTICLE_UPDATE_CYCLE_BIT_SECOND) {
                emitter->mUpdateCycle = PARTICLE_UPDATE_CYCLE_SECOND;
            }
        }
    }
    for (emitterIndex = 0; emitterIndex < 0x18; emitterIndex++) {
        s32 effectIndex;
        Vec3 position;
        ParticleEmitter *emitter;
        SPLManager *manager = gGetSPLManagerFunction(&effectIndex, secondEffectIds.mUnk_00[emitterIndex]);
        position.x = baseX >> 4;
        position.y = emitY;
        position.z = emitZ;
        emitter = SPLManager_CreateEmitter(manager, effectIndex, &position);
        if (emitter != NULL) {
            if (emitter->mResource->mHeader->mUpdateCycleBits & PARTICLE_UPDATE_CYCLE_BIT_FIRST) {
                emitter->mUpdateCycle = PARTICLE_UPDATE_CYCLE_FIRST;
            } else if (emitter->mResource->mHeader->mUpdateCycleBits & PARTICLE_UPDATE_CYCLE_BIT_SECOND) {
                emitter->mUpdateCycle = PARTICLE_UPDATE_CYCLE_SECOND;
            }
        }
    }
}

void CreateKartPhysicalParamTable(void *heap, u32 entryCount) {
    gKartPhysicalParamTable = HeapAlloc(heap, 0x14);
    gKartPhysicalParamTable->mKartParams = HeapAlloc(heap, entryCount * sizeof(KartPhysicalParam));
    gKartPhysicalParamTable->mCharParams = HeapAlloc(heap, entryCount * 8);
    gKartPhysicalParamTable->mKartParamFile = FindKartModelFile("kartphysicalparam.bin");
    gKartPhysicalParamTable->mCharParamFile = FindKartModelFile("charphysicalparam.bin");
    gKartPhysicalParamTable->mFirstBaseSpeedLimit = gKartPhysicalParamTable->mKartParamFile->mBaseSpeedLimit;
}

// Copies the kart row and the character row of the files to the slot after choosing the rows (rows 0 when
// IsRaceAwardOrStaffRoll() != 0; character + 0x25 in mode 2).
void CopyKartPhysicalParams(u32 slot, u32 kartRow, u32 characterRow) {
    KartPhysicalParam *kartParamFile = gKartPhysicalParamTable->mKartParamFile;
    s32 *characterParamFile = gKartPhysicalParamTable->mCharParamFile;
    if (IsRaceAwardOrStaffRoll() != 0) {
        characterRow = 0;
        kartRow = characterRow;
    } else if (gRaceSetup->mMode == MODE_BATTLE) {
        kartRow = (u16) (characterRow + 0x25);
    }
    MI_CpuCopy8(&kartParamFile[kartRow], &gKartPhysicalParamTable->mKartParams[slot], sizeof(KartPhysicalParam));
    MI_CpuCopy8(&characterParamFile[characterRow * 2], &gKartPhysicalParamTable->mCharParams[slot * 2], 8);
}
