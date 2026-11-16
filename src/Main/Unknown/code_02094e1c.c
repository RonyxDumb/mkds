#include "Main/Unknown/code_02094e1c.h"
#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ac000.h"

#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_021000d0.h"

void tsacnt_init(u32 mapObject) {
    u32 value0 = mapObject;
    u32 value1;
    u32 value2;
    value2 = value0;
    value1 = *(const u32 *) ((value2) + (156));
    value0 = MAP_OBJECT_KIND_TERESA;
    value1 = *(const s16 *) ((value1) + (42));
    mobj_createSubObjects(value0, value1, (void *) value2);
}

static inline u32 func_02095228_inline(RandomState64 *randomState64, u32 n) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    if (n == 0) {
        return randomState64->mValue >> 32;
    }
    return ((randomState64->mValue >> 32) * n) >> 32;
}

static inline u16 func_020952dc_inline(u32 n) {
    RandomState64 *randomState64;
    u32 t;
    u32 m;
    if (n == 0x10000) {
        randomState64 = &gRaceStatus->mLocalRandom;
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        return (randomState64->mValue >> 32) * 0x10000 >> 32;
    }
    randomState64 = &gRaceStatus->mLocalRandom;
    m = (u16) n;
    if (m == 0) {
        t = 0;
    } else {
        randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
        if (m == 0) {
            t = randomState64->mValue >> 32;
        } else {
            t = ((randomState64->mValue >> 32) * m) >> 32;
        }
    }
    return t;
}

void func_020952dc(Unk02094e8c *a, s32 teresaCountLimit, s32 spawnCount, s32 distanceLimit, s32 timerLimit) {
    s32 i;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    float f;
    u32 distance;
    u16 angle;
    Vec3 position;

    if (tesa_getActiveInstanceCount() < teresaCountLimit) {
        k = i = 0;
        for (; i < spawnCount; i++) {
            if (distanceLimit > 0) {
                f = 0.5f + (distanceLimit << 12);
            } else {
                f = (distanceLimit << 12) - 0.5f;
            }
            z = 0;
            y = a->field0.mPos.y;
            x = 0;
            distance = kan64_mobj_getRandom32(GetRaceLocalRandom(), (s32) f);
            angle = func_020951b4(GetRaceLocalRandom());
            position.x = x + tsacnt_FX_TRUNC_MUL(distance, tsacnt_FX_GetSinIdx(angle));
            position.y = y + kan64_mobj_getRandom32(GetRaceLocalRandom(), k);
            position.z = z + tsacnt_FX_TRUNC_MUL(distance, tsacnt_FX_GetCosIdx(angle));
            tesa_spawn(&position);
        }
        a->fieldA8 = func_020952dc_inline((u16) timerLimit);
    }
}

void tsacnt_globalLogicInit(MapObjectList *mapObjectList) {
    s32 i;
    Unk02094e8c *o;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (o = mapObjectList->mMapObjects[i]) != NULL; i++) {
        o->fieldA0 = (u16) func_02095228_inline(&gRaceStatus->mLocalRandom, 0xf);
    }
}

RandomState64 *GetRaceLocalRandom(void) {
    return &gRaceStatus->mLocalRandom;
}

u16 func_020951b4(RandomState64 *randomState64) {
    randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
    return ((randomState64->mValue >> 32) * 0x10000) >> 32;
}

s16 tsacnt_FX_GetSinIdx(s32 a) {
    return FX_SinCosTable_[(a >> 4) * 2];
}

s32 tsacnt_FX_TRUNC_MUL(s32 a, s32 b) {
    return ((s64) a * b) >> 12;
}

s16 tsacnt_FX_GetCosIdx(s32 a) {
    return FX_SinCosTable_[(a >> 4) * 2 + 1];
}

void tsacnt_update(void *a, Unk02094e8c *o) {
    s32 t;
    s32 c;
    s32 e;
    s32 deltaX;
    s32 deltaZ;
    s32 i;
    BOOL k;
    s32 x;
    s32 y;
    s32 z;
    float f;
    u32 distance;
    u16 angle;
    Kart *kart;
    Vec3 position;
    Vec3 *kartPos;

    t = o->fieldA0;
    o->fieldA0 = t - 1;
    if (t <= 0) {
        o->fieldA0 = 0xf;
        c = o->field0.mCourseMapRow->field28;
        kart = driver_getById((u16) gRaceMultiConfig->mEntryIndex);
        e = c << 12;
        kartPos = &kart->mPos;
        deltaX = kartPos->x - o->field0.mPos.x;
        deltaZ = kartPos->z - o->field0.mPos.z;
        if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ < (s64) e * e) {
            o->fieldA4 = TRUE;
        } else {
            o->fieldA4 = FALSE;
        }
    }
    switch (o->fieldAC) {
        case 0:
            k = FALSE;
            if (race_getCameraField250() == 2) {
                for (i = 0; i < o->field0.mCourseMapRow->field2A; i++) {
                    if (o->field0.mCourseMapRow->field28 > 0) {
                        f = 0.5f + (o->field0.mCourseMapRow->field28 << 12);
                    } else {
                        f = (o->field0.mCourseMapRow->field28 << 12) - 0.5f;
                    }
                    z = o->field0.mPos.z;
                    y = o->field0.mPos.y;
                    x = o->field0.mPos.x;
                    distance = kan64_mobj_getRandom32(GetRaceLocalRandom(), (s32) f);
                    angle = func_020951b4(GetRaceLocalRandom());
                    position.x = x + tsacnt_FX_TRUNC_MUL(distance, tsacnt_FX_GetSinIdx(angle));
                    position.y = y + kan64_mobj_getRandom32(GetRaceLocalRandom(), k);
                    position.z = z + tsacnt_FX_TRUNC_MUL(distance, tsacnt_FX_GetCosIdx(angle));
                    tesa_spawn(&position);
                }
            }
            o->fieldAC = 1;
        case 1:
            if (race_getCameraField250() == 2) {
                break;
            }
            if (o->fieldA4 == FALSE) {
                break;
            }
            if (race_getCameraField250() != 0) {
                func_020952dc(o, 0x1e, 0x14, 0x1f4, 4);
            } else {
                func_020952dc(o, 6, 4, 0xa, 0x14);
            }
            o->fieldAC = 2;
            break;
        case 2:
            t = o->fieldA8;
            o->fieldA8 = t - 1;
            if (t > 0) {
                break;
            }
            if (o->fieldA4 != FALSE) {
                if (race_getCameraField250() != 0) {
                    func_020952dc(o, 0x1e, 1, 0x1f4, 4);
                } else {
                    func_020952dc(o, 6, 1, 0xa, 0x14);
                }
            } else {
                tesa_20946B8();
                o->fieldAC = 1;
            }
            break;
    }
    if (tesa_getActiveInstanceCount() > 0) {
        mobj_driverEmitSfx(driver_getById((u16) gRaceMultiConfig->mEntryIndex), 0x11e);
    }
}

u32 tsacnt_setupConfig(void) {
    s32 mode;

    mode = gRaceMultiConfig->mMode;
    if (mode == MODE_VS || mode == 5) {
        if (race_getCameraField250() == 0) {
            return 0;
        }
    }
    return mobj_createDummyConfig();
}

void tsacnt_setupLogicPart(void) {
    mobj_createLogicPart(tsacnt_globalLogicInit, tsacnt_update, NULL);
}
