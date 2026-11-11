#include "Main/Unknown/code_0208b484.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_0208c534.h"
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
    data_0217b054 = NULL;
    data_0217b048 = NULL;
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
            directionOrigin = data_usa_021660fc;
            data_0217b048 = HeapAlloc(effectHeap, 0x64);
            for (emitterIndex = 0; emitterIndex < 6; emitterIndex++) {
                data_0217b048->mEmitters[emitterIndex] = NULL;
                VEC_Subtract(&data_usa_02155f78[emitterIndex], &directionOrigin, &offset);
                emitterDirection = &data_0217b048->mDirections[emitterIndex];
                if (LENGTH_SQUARED(offset) >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&offset, emitterDirection);
                }
            }
            data_0217b048->mEmitterTimer = 1;
            data_0217b054 = AdvanceStadiumEmitters;
            break;
        case COURSE_ID_AWARD:
            CreateAwardEmitters();
            break;
    }
}

void UpdateEffects(void) {
    if (data_0217b054 != NULL) {
        data_0217b054();
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
    Unk0201ca6c *emitter;
    SPLManager *splManager = gGetSPLManagerFunction(&resourceId, effectId);
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    emitter = SPLManager_CreateEmitter(splManager, resourceId, &emitterPosition);
    if (emitter != NULL) {
        if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            emitter->mUnk_80_16 = 1;
        } else if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            emitter->mUnk_80_16 = 2;
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
                                           (void (*)(Unk0201ca6c *, s32)) initCallback);
}

void DeleteEffect(Unk0201ca6c *emitter) {
    SPLManager *splManager;
    s32 indexBuffer[2];
    splManager = gGetSPLManagerFunction(indexBuffer, 0);
    SPLManager_DeleteEmitter(splManager, emitter);
}

void DeleteEffectAndClearPointer(Unk0201ca6c **emitterSlot) {
    SPLManager *splManager;
    s32 indexBuffer[2];
    splManager = gGetSPLManagerFunction(indexBuffer, 0);
    SPLManager_DeleteEmitter(splManager, *emitterSlot);
    *emitterSlot = NULL;
}

void StopEffectAndClearPointer(void **emitterSlot) {
    Unk0201ca6c *effect = *emitterSlot;
    effect->mUnk_24.mUnk_00_0 = 1;
    *emitterSlot = NULL;
}

Unk0201ca6c *StartRaceFogOffEffect(s32 resourceId, Vec3 *position) {
    Vec3 emitterPosition;
    Unk0201ca6c *emitter;
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    emitter = SPLManager_CreateEmitter(gRaceEffectFogOffSPLManager, resourceId, &emitterPosition);
    if (emitter != NULL) {
        if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            emitter->mUnk_80_16 = 1;
        } else if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            emitter->mUnk_80_16 = 2;
        }
    }
    return emitter;
}

void PlaceEffect(void *effectHandle, const Vec3 *position) {
    Unk0201ca6c *emitter = effectHandle;
    s32 positionX = position->x;
    s32 positionY = position->y;
    s32 positionZ = position->z;
    emitter->mUnk_28.x = (positionX >> 4) + emitter->mUnk_20->mUnk_00->mUnk_04.x;
    emitter->mUnk_28.y = (positionY >> 4) + emitter->mUnk_20->mUnk_00->mUnk_04.y;
    emitter->mUnk_28.z = (positionZ >> 4) + emitter->mUnk_20->mUnk_00->mUnk_04.z;
}

void *StartEffectWithKartVelocity(u32 effectId, Vec3 *position, u32 kartIndex, s32 velocityScale) {
    s32 resourceId;
    Vec3 velocity;
    Vec3 emitterPosition;
    Unk0201ca6c *emitter;
    SPLManager *splManager = gGetSPLManagerFunction(&resourceId, effectId);
    emitterPosition.x = position->x >> 4;
    emitterPosition.y = position->y >> 4;
    emitterPosition.z = position->z >> 4;
    emitter = SPLManager_CreateEmitter(splManager, resourceId, &emitterPosition);
    if (emitter != NULL) {
        if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            emitter->mUnk_80_16 = 1;
        } else if (emitter->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            emitter->mUnk_80_16 = 2;
        }
    }
    if (emitter != NULL) {
        velocity = GetKart(kartIndex)->mEffectVelocity;
        velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, velocityScale);
        velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, velocityScale);
        velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, velocityScale);
        emitter->mUnk_40 = velocity;
    }
    return emitter;
}

SPLManager *GetRaceEffectSPLManager(s32 *outIndex, s32 effectId) {
    *outIndex = effectId;
    return gRaceEffectSPLManager;
}
