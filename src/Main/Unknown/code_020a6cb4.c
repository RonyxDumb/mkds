#include "Main/Unknown/code_020a6cb4.h"
#include "Main/Unknown/code_020a10f0.h"

#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a3f2c.h"
#include "Main/Course/ShineBalloon.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020a7148.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_02077bc0.h"

void shinc_init(MapObject *a) {
    if (mobj_getInstanceCountWithId(MAP_OBJECT_KIND_SHINE16) == 0) {
        mobj_createSubObjects(MAP_OBJECT_KIND_SHINE16, 0x14, a);
        mobj_createSubObjects(MAP_OBJECT_KIND_SHINE_BALLOON, gRaceMultiConfig->mKartCount, a);
        mgcnt_setOnDamageFunc(shinc_onDriverDamage);
        mgcnt_setOnKillFunc(shinc_onDriverKill);
        mgcnt_setOnEndFunc(shinc_onMgEnd);
        return;
    }
    mobj_setInvisible(a);
}

BOOL shinc_spawnShine(MapObjectList *a) {
    s32 i;
    s32 v1;
    Unk020a6cb4 *e;
    BOOL f;
    u32 n;
    u32 m;
    u32 r;
    u16 v2;
    u32 k;
    RandomState64 *g;

    v1 = 0;
    if (a != NULL) {
        for (i = 0; i < a->mMapObjectCount && (e = a->mMapObjects[i]) != NULL; i++) {
            f = FALSE;
            if (e->mHasShine == FALSE) {
                if (e->fieldA4 == FALSE) {
                    f = TRUE;
                }
            }
            v1 += f;
        }
    }
    if (v1 > 0) {
        n = (u16) v1;
        if (n == 0x10000) {
            g = mobj_getRng1();
            g->mValue = (s64) g->mMultiplier * (s64) g->mValue + g->mIncrement;
            v2 = ((u64) (u32) (g->mValue >> 32) * 0x10000) >> 32;
        } else {
            g = mobj_getRng1();
            if ((u16) n == 0) {
                r = 0;
            } else {
                g->mValue = (s64) g->mMultiplier * (s64) g->mValue + g->mIncrement;
                m = (u16) n;
                if (m == 0) {
                    r = g->mValue >> 32;
                } else {
                    r = ((g->mValue >> 32) * m) >> 32;
                }
            }
            v2 = r;
        }
        k = v2;
        if (a != NULL) {
            for (i = 0; i < a->mMapObjectCount && (e = a->mMapObjects[i]) != NULL; i++) {
                if (e->mHasShine == FALSE && e->fieldA4 == FALSE) {
                    if (k-- == 0) {
                        shine_spawn(&e->field0.mPos, i, 1);
                        e->mHasShine = TRUE;
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

void shinc_globalLogicInit(MapObjectList *a) {
    s32 i;
    s32 n;
    s32 j;
    s32 v;
    BOOL f;
    Unk020a6cb4 *e;

    n = gRaceMultiConfig->mKartCount;
    for (i = 0; i < n; i++) {
        if (i == gRaceMultiConfig->mEntryIndex) {
            f = FALSE;
            v = gRaceMultiConfig->mCurrentEntries[(u16) i].mPlayer.mKind;
            if ((u32) v <= 3) {
                if ((1 << v) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                continue;
            }
        }
        sblln_spawn(driver_getById((u16) i));
    }
    if (a == NULL) {
        return;
    }
    for (j = 0; j < a->mMapObjectCount && (e = a->mMapObjects[j]) != NULL; j++) {
        e->fieldA4 = TRUE;
        if (e->field0.mCourseMapRow->field28 != 0) {
            n = gRaceMultiConfig->mKartCount;
            v = mgcnt_getCollectableShineCount();
            if (v + mgcnt_getTotalOwnedShineCount() < n + 1) {
                shine_spawn(&e->field0.mPos, j, race_isCamAnimMode());
                e->mHasShine = TRUE;
            }
        }
    }
}

void shinc_update(MapObjectList *a, Unk020a6cb4 *b) {
    s32 n;
    s32 v;

    if (mgcnt_getCollectableShineCount() >= 3) {
        return;
    }
    n = gRaceMultiConfig->mKartCount;
    v = mgcnt_getCollectableShineCount();
    if (v + mgcnt_getTotalOwnedShineCount() >= n + 1) {
        return;
    }
    b->mShineStartFrames += 1;
    if (b->mShineStartFrames <= 0x5a) {
        return;
    }
    b->mShineStartFrames = 0;
    while (mgcnt_getCollectableShineCount() < 3 &&
           (n = gRaceMultiConfig->mKartCount, v = mgcnt_getCollectableShineCount(), v + mgcnt_getTotalOwnedShineCount() < n + 1)) {
        if (shinc_spawnShine(a) == FALSE) {
            return;
        }
    }
}

s32 shinc_setupConfig(void) {
    if (gRaceMultiConfig->mMode == MODE_BATTLE && gRaceMultiConfig->mBattleKind == BATTLE_KIND_SHINE) {
        return mobj_createDummyConfig();
    }
    return 0;
}

void *shinc_setupLogicPart(void) {
    return mobj_createLogicPart(shinc_globalLogicInit, shinc_update, NULL);
}

void func_020a6cb4(s32 a) {
    MapObjectList *v1;
    Unk020a6cb4 *e;
    s32 i;

    v1 = mobj_getLogicPartForObjectId(0x6b);
    if (v1 == NULL) {
        return;
    }
    for (i = 0; i < v1->mMapObjectCount && (e = v1->mMapObjects[i]) != NULL; i++) {
        if (i == a) {
            e->mHasShine = FALSE;
            e->fieldA4 = TRUE;
        } else {
            e->fieldA4 = FALSE;
        }
    }
}
