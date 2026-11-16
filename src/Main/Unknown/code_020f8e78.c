#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02109038.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_020e337c.h"

BOOL sub_20F9290(void *itemParam, Vec3 *normal) {
    ItemObject *item = itemParam;
    if ((item->mFlags & 0x2000000) != 0 && vec_dotProduct(normal, &item->field108) < 0 && (item->mFlags & 8) == 0) {
        sub_20F6FC4(item, 1);
        return TRUE;
    }
    return FALSE;
}

void it_20F91FC(void *itemParam, s32 soundId) {
    ItemObject *item = itemParam;
    Unk0210b7a8 request;

    if (soundId == 1) {
        return;
    }
    if ((s32) (item->mDistanceSquaredAndFlags & ~0xc000001f) >= gSfxParams[1].field20) {
        return;
    }
    if (soundId == 1) {
        return;
    }
    request = data_0216c698;
    request.mPositionSource = &item->mPos;
    request.mSoundId = soundId;
    request.mDistanceSquared = item->mDistanceSquaredAndFlags & ~0xc000001f;
    sub_210B7A8(&request);
}

BOOL sub_20F91E0(ItemObject *itemParam) {
    ItemObject *item = itemParam;

    return item->mScale.z >= 0xccd;
}

BOOL IsItemObjectFartherFromCameraThan(ItemObject *item, s32 distance) {
    return (s32) (item->mDistanceSquaredAndFlags & ~0xc000001f) > distance * distance;
}

BOOL sub_20F9160(ItemObject *c) {
    BOOL a;
    BOOL b;

    a = FALSE;
    if ((c->mFlags & 0x10000) == 0) {
        a = TRUE;
    }
    if (a != FALSE && (s32) (c->mDistanceSquaredAndFlags & ~0xc000001f) <= 0x3d0900) {
        b = TRUE;
    } else {
        b = FALSE;
    }
    if (b == FALSE && (s32) (c->mDistanceSquaredAndFlags & ~0xc000001f) > 0x3d090) {
        return TRUE;
    }
    return FALSE;
}

void sub_20F9114(void *itemParam) {
    ItemObject *item = itemParam;
    enum { K0 } kind = item->mKind;

    sfx_2109038(item, it_sItemParams[kind].fieldA0, &item->mPos);
    sfx_210CF9C(&item->mSoundSource, 1);
    item->mFlags |= 0x400000;
}

void sub_20F90DC(ItemObject *itemParam) {
    ItemObject *item = itemParam;
    if ((item->mFlags & 0x400000) == 0) {
        return;
    }
    sub_2109054(&item->mSoundSource);
    item->mSoundSource.mTrackParamsFunction = NULL;
    item->mFlags &= ~0x400000;
}

void sub_20F90BC(ItemObject *itemParam) {
    ItemObject *item = itemParam;

    item->mSoundSource.mDistanceSquared = item->mDistanceSquaredAndFlags & ~0xc000001f;
    StructMQRacerEntry_SomeFn_91(item, &item->mPos, item->mDistanceSquaredAndFlags);
}

void ResetItemObjectFromData(ItemObject *itemParam, s32 kind, void *buffer, s32 d) {
    ItemObject *item = itemParam;
    void *(*copyData)(void *, void *, s32);

    copyData = d != 0 ? func_020fe4c0 : it_sItemParams[kind].mCopyData;
    it_initInstance(item, kind);
    copyData(buffer, item, 0);
    item->mFlags &= ~0x400000;
    item->mFlags |= 0x10000000;
}

void sub_20F8E78(void *itemParam) {
    ItemObject *item = itemParam;
    ItemKind *kindInfo;
    BOOL hasCollisionSlot;
    s32 kindRadius;
    enum { K0 } kind;
    void (*advance)(struct ItemObject *);

    item->mScale.z = 0xccd;
    kind = item->mKind;
    item->mFlags |= 0x40;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &it_sItemParams[kind];
    kindRadius = kindInfo->field6C;
    item->fieldDC = ((s64) item->mScale.y * kindInfo->field64) >> 12;
    item->mRadius = ((s64) item->mScale.y * kindRadius) >> 12;
    col_setBoundingSphereRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
    light_init(&item->mColorBlend, 1);
    item->field90 = NULL;
    item->mNormal = data_02159ca0;
    item->mCollisionBits = 0;
    item->field100 = 0;
    item->field104->field0 = NULL;
    item->field108.x = 0;
    item->field108.y = 0;
    item->field108.z = 0;
    item->field114 = 5;
    item->field116 = 0;
    item->field118 = 0;
    item->field11A = 0;
    item->mAgeFrames = 1;
    if ((item->mFlags & 0x400000) == 0) {
        kind = item->mKind;
        sfx_2109038(item, it_sItemParams[kind].fieldA0, &item->mPos);
        sfx_210CF9C(&item->mSoundSource, 1);
        item->mFlags |= 0x400000;
    }
    kind = item->mKind;
    advance = it_sItemParams[kind].mAdvance;
    if ((item->mFlags & 0x180000) == 0) {
        item->mAdvance = advance;
    }
    if ((item->field78 & 0xf00) != 0) {
        return;
    }
    kind = item->mKind;
    if (it_sItemParams[kind].field54 != 0) {
        return;
    }
    hasCollisionSlot = item->mCollisionSlotIndex != -1;
    if (hasCollisionSlot != FALSE) {
        return;
    }
    if (hasCollisionSlot != FALSE) {
        return;
    }
    item->mCollisionSlotIndex = col_createColEntry(&item->mPos, item->mRadius + 0xa000, 0x4000, item);
}
