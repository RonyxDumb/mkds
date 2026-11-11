#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d2000.h"

#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02148538.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_02147cd8.h"

void InitTeresa(MapObject *mapObject) {
    ParkMapObject(mapObject);
    gUnparkedTeresaCount = 0;
}

void CreateTeresa(MapObjectList *mapObjectList) {
    gTeresa = CreateMapObjectModelNsbmdNsbtp(mapObjectList, gTeresaNsbmdName, gTeresaNsbtpName);
    SetMapObjectModelPolygonId(gTeresa, 0x3f);
    mapObjectList->mSortByDistance = 1;
}

void SetupDrawTeresa(void *mapObjectList) {
    QueueMapObjectModelMaterial(mapObjectList, gTeresa);
}

void DrawTeresa(void *mapObjectList, Teresa *teresa) {
    s32 gxParam;
    s32 gxScale[3];

    if (teresa->mModelAlpha == 0) {
        return;
    }
    GetKart((u16) gRaceSetup->mEntryIndex);
    SetMapObjectModelPolygonId(gTeresa, AllocPolygonIdWrapping());
    SetMapObjectModelNsbtpFrameIndex(gTeresa, teresa->mNsbtpFrameIndex);
    SetMapObjectModelAlpha(gTeresa, teresa->mModelAlpha);
    SetMapObjectModelFogEnabled(gTeresa, IsFadeFogActive());
    SetMapObjectModelMirror(gTeresa, teresa->mMirror, 0);
    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    NNS_G3dGeBufferOP_N(0x19, SetViewTransposeMatrixPos(&teresa->mMapObject.mPos), 0xc);
    if (GetCurrentCameraKind() == 2) {
        gxScale[0] = 0x2000;
        gxScale[1] = 0x2000;
        gxScale[2] = 0x2000;
        NNS_G3dGeBufferOP_N(0x1b, gxScale, 3);
    }
    NNS_G3dGeBufferOP_N(0x1b, &teresa->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gTeresa, teresa);
}

static inline void AdvanceTeresaAlpha(Teresa *teresa) {
    teresa->mAlphaFixed12 = teresa->mAlphaFixed12 + teresa->mAlphaFixed12PerFrame;
    if (teresa->mAlphaFixed12 >= teresa->mAlphaFixed12Max) {
        teresa->mAlphaFixed12PerFrame = -teresa->mAlphaFixed12PerFrame;
        teresa->mAlphaFixed12 = teresa->mAlphaFixed12Max * 2 - teresa->mAlphaFixed12;
    } else if (teresa->mAlphaFixed12 <= teresa->mAlphaFixed12Min) {
        teresa->mAlphaFixed12PerFrame = -teresa->mAlphaFixed12PerFrame;
        teresa->mAlphaFixed12 = teresa->mAlphaFixed12Min * 2 - teresa->mAlphaFixed12;
    }
    teresa->mModelAlpha = FROM_FIXED12(teresa->mAlphaFixed12);
}

static inline void AdvanceTeresaValueStoppingAtZero(s32 *value, s32 *delta) {
    s32 current = *value;
    if (current > 0) {
        current += *delta;
        if (current <= 0) {
            current = 0;
        }
        *value = current;
    } else if (current < 0) {
        current += *delta;
        if (current >= 0) {
            current = 0;
        }
        *value = current;
    }
}

// Gives each Teresa two values from its place in the list: bit 0 and bit 1 of its index.
void InitTeresaObjects(MapObjectList *mapObjectList) {
    s32 objectIndex;
    Teresa *teresa;

    if (mapObjectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < mapObjectList->mMapObjectCount && (teresa = mapObjectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        teresa->mNsbtpFrameIndex = objectIndex & 1;
        teresa->mMirror = (objectIndex / 2) & 1;
    }
}

s16 TeresaFX_SinIdx(s32 angle) {
    return FX_SinIdx(angle);
}

s32 TeresaFX_MulInline(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_ROUNDED(multiplicand, multiplier);
}

s16 TeresaFX_CosIdx(s32 angle) {
    return FX_CosIdx(angle);
}

void UpdateTeresa(void *mapObjectList, Teresa *teresa) {
    s32 timer;
    s32 wobbleOffset;
    s32 anglePairSecond;
    u16 angleWobbleValue;
    s32 radius;
    s32 yWobbleValue;
    Kart *kart;

    switch (teresa->mState) {
        case 1:
            timer = teresa->mState1Timer;
            teresa->mState1Timer = timer - 1;
            if (timer <= 0) {
                teresa->mState1Timer = 0;
                AdvanceTeresaAlpha(teresa);
                if (teresa->mAlphaFixed12 >= 0x2000) {
                    teresa->mState = 0;
                }
            }
            break;
        case 0:
            timer = teresa->mState0Timer;
            teresa->mState0Timer = timer - 1;
            if (timer <= 0) {
                teresa->mState0Timer = 0;
                teresa->mAlphaFixed12 = teresa->mAlphaFixed12 - 0x1000;
                if (teresa->mAlphaFixed12 > 0) {
                    teresa->mModelAlpha = FROM_FIXED12(teresa->mAlphaFixed12);
                } else {
                    teresa->mModelAlpha = 0;
                    ParkMapObject(&teresa->mMapObject);
                    gUnparkedTeresaCount--;
                }
            } else {
                AdvanceTeresaAlpha(teresa);
            }
            break;
    }
    if (teresa->mState0Timer <= 0) {
        return;
    }
    teresa->mAngleWobble.mAngle = teresa->mAngleWobble.mAngle + teresa->mAngleWobble.mAnglePerFrame;
    wobbleOffset = TeresaFX_MulInline(teresa->mAngleWobble.mAmplitude, TeresaFX_SinIdx(teresa->mAngleWobble.mAngle));
    teresa->mAngleWobble.mValueDelta = teresa->mAngleWobble.mMid + wobbleOffset - teresa->mAngleWobble.mValue;
    teresa->mAngleWobble.mValue = teresa->mAngleWobble.mValue + teresa->mAngleWobble.mValueDelta;
    AdvanceTeresaValueStoppingAtZero(&teresa->mAngleWobble.mAmplitude, &teresa->mAngleWobble.mAmplitudePerFrame);
    AdvanceTeresaValueStoppingAtZero(&teresa->mAngleWobble.mAnglePerFrame, &teresa->mAngleWobble.mUnk_1c);
    angleWobbleValue = teresa->mAngleWobble.mValue;
    teresa->mYWobble.mAngle = teresa->mYWobble.mAngle + teresa->mYWobble.mAnglePerFrame;
    anglePairSecond = TeresaFX_CosIdx(teresa->mYWobble.mAngle);
    wobbleOffset = TeresaFX_MulInline(teresa->mYWobble.mAmplitude / 2, 0x1000 - anglePairSecond);
    teresa->mYWobble.mValueDelta = teresa->mYWobble.mMid + wobbleOffset - teresa->mYWobble.mValue;
    teresa->mYWobble.mValue = teresa->mYWobble.mValue + teresa->mYWobble.mValueDelta;
    AdvanceTeresaValueStoppingAtZero(&teresa->mYWobble.mAmplitude, &teresa->mYWobble.mAmplitudePerFrame);
    AdvanceTeresaValueStoppingAtZero(&teresa->mYWobble.mAnglePerFrame, &teresa->mYWobble.mUnk_1c);
    yWobbleValue = teresa->mYWobble.mValue;
    radius = teresa->mUnk_10c;
    if (GetCurrentCameraKind() == 2) {
        teresa->mMapObject.mPos.x = teresa->mStartPos.x + MUL_FIXED12_NO_ROUND(radius, FX_CosIdx(angleWobbleValue));
        teresa->mMapObject.mPos.y = teresa->mStartPos.y + yWobbleValue;
        teresa->mMapObject.mPos.z = teresa->mStartPos.z + MUL_FIXED12_NO_ROUND(radius, FX_SinIdx(angleWobbleValue));
    } else {
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        teresa->mMapObject.mPos.x =
            kart->mPos.x + (teresa->mStartPos.x + MUL_FIXED12_NO_ROUND(radius, FX_CosIdx(angleWobbleValue)));
        teresa->mMapObject.mPos.y = teresa->mStartPos.y + yWobbleValue;
        teresa->mMapObject.mPos.z =
            kart->mPos.z + (teresa->mStartPos.z + MUL_FIXED12_NO_ROUND(radius, FX_SinIdx(angleWobbleValue)));
    }
}

void CreateTeresaDrawList(void) {
    CreateMapObjectDrawList2(CreateTeresa, DrawTeresa, SetupDrawTeresa);
}

void CreateTeresaUpdateList(void) {
    CreateMapObjectUpdateList(InitTeresaObjects, UpdateTeresa, NULL);
}

void ClearTeresaTimers(void) {
    MapObjectList *mapObjectList;
    Teresa *teresa;
    s32 objectIndex;

    mapObjectList = FindMapObjectKindUpdateList(MAP_OBJECT_KIND_TERESA);
    if (mapObjectList == NULL) {
        return;
    }
    for (objectIndex = 0;
         objectIndex < mapObjectList->mMapObjectCount && (teresa = mapObjectList->mMapObjects[objectIndex]) != NULL;
         objectIndex++) {
        teresa->mState1Timer = 0;
        teresa->mState0Timer = 0;
    }
}

static inline u32 TeresaNextRandomBelow(RandomState64 *randomState64, u32 limit) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (limit == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * limit) >> 32;
}

static inline void SetTeresaWobble(TeresaWobble *teresaWobble, u16 angle, s32 mid, s32 amplitude, s32 amplitudePerFrame,
                                   s32 anglePerFrame, s32 value) {
    teresaWobble->mAngle = angle;
    teresaWobble->mMid = mid;
    teresaWobble->mAmplitude = amplitude;
    teresaWobble->mAmplitudePerFrame = amplitudePerFrame;
    teresaWobble->mAnglePerFrame = anglePerFrame;
    teresaWobble->mUnk_1c = value;
}

void StartTeresa(Vec3 *startPos) {
    Teresa *teresa;
    Camera *chaseCamera;
    s32 alphaFixed12Max;
    s32 alphaFixed12PerFrame;
    s32 angleSpeedRandom;
    s16 amplitudeRandom;
    u16 angleRandom;
    s32 midAngle;
    s32 ySpeedRandom;
    s32 yMidRandom;

    teresa = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_TERESA));
    if (teresa == NULL) {
        return;
    }
    teresa->mModelAlpha = 0;
    teresa->mStartPos = *startPos;
    if (GetCurrentCameraKind() == 0) {
        chaseCamera = GetChaseCamera();
        angleSpeedRandom = TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x30);
        amplitudeRandom = (u16) (TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0) >> 20);
        angleRandom = TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x5555);
        midAngle =
            FX_Atan2Idx(chaseCamera->mLookAt.z - chaseCamera->mPos.z, chaseCamera->mLookAt.x - chaseCamera->mPos.x) +
            angleRandom - 0x2aaa;
        SetTeresaWobble(&teresa->mAngleWobble, TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x10000), midAngle,
                        amplitudeRandom + 0x1000, 0, angleSpeedRandom + 0x60, 0);
    } else {
        angleSpeedRandom = TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x30);
        amplitudeRandom = (u16) (TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0) >> 20);
        SetTeresaWobble(&teresa->mAngleWobble, TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x10000),
                        (u16) TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x10000), amplitudeRandom + 0x1000, 0,
                        angleSpeedRandom + 0x60, 0);
    }
    ySpeedRandom = TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x80);
    yMidRandom = TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0xa000);
    SetTeresaWobble(&teresa->mYWobble, 0, TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x19000) + 0x19000,
                    yMidRandom + 0xa000, 0, ySpeedRandom + 0x100, 0);
    teresa->mUnk_10c = TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x3c000) + 0x3c000;
    alphaFixed12Max = TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0xc000) + 0xe000;
    alphaFixed12PerFrame = TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x200) + 0x400;
    teresa->mAlphaFixed12 = 0;
    teresa->mAlphaFixed12PerFrame = alphaFixed12PerFrame;
    teresa->mAlphaFixed12Min = 0x2000;
    teresa->mAlphaFixed12Max = alphaFixed12Max;
    if (GetCurrentCameraKind() == 2) {
        teresa->mState1Timer = 0;
        teresa->mState0Timer = 0xffff;
        teresa->mState = 0;
    } else {
        teresa->mState1Timer = (u16) TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x4b);
        teresa->mState0Timer = (u16) TeresaNextRandomBelow(&gRaceProgress->mLocalRandom, 0x96) + 0x12c;
        teresa->mState = 1;
    }
    gUnparkedTeresaCount++;
}

s32 GetUnparkedTeresaCount(void) {
    return gUnparkedTeresaCount;
}
