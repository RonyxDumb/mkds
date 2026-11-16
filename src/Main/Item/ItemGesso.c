#include "Main/Item/ItemGesso.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020fe4b4.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02102000.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02102eb8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077bc0.h"

void itgsso_210298C(ItemGesso *p) {
    Kart *kart;
    Camera *camera;
    s32 ageFrames;
    s32 i;
    s32 kartCount;
    Kart *kartAtIndex;
    s32 v;
    Vec3 viewOffset;
    s32 m;
    s32 n;
    s32 factor;

    kart = p->mKart;
    camera = cam_getPlayerCamera();
    ageFrames = p->field0.mAgeFrames;
    if (ageFrames == 0x3f) {
        itgsso_21031F4(p);
    }
    if (ageFrames == 0x8f) {
        kartCount = gRaceMultiConfig->mKartCount;
        for (i = 0; i < kartCount; i++) {
            if (p->mOrthoQuadCounts[i] == 0) {
                continue;
            }
            kartAtIndex = driver_getById(i);
            if (kartAtIndex->field7C & 0x402020) {
                continue;
            }
            if (kartAtIndex->field4C & 0x10000840) {
                continue;
            }
            if (kartAtIndex->field48 & 0x10000) {
                continue;
            }
            driver_startGessoInk(kartAtIndex, p->mOrthoQuadCounts[i]);
            func_020f8e3c((u32) kartAtIndex, 0xf0);
        }
    }
    if (p->field160 != FALSE) {
        if (ageFrames <= gItemGessoFrameCount) {
            return;
        }
        it_itemsetDestroyItem(it_sItemsets + p->field0.mKind, &p->field0);
        return;
    }
    if (p->mStepIndex >= 4 && p->mStepIndex < 0xd) {
        if ((kart->field7C & 0x402020) || (kart->field4C & 0x10000840) || (kart->field48 & 0x10000)) {
            p->mStepIndex = 0xd;
            itgsso_210300C(p);
            if (p->mVisible != FALSE) {
                func_020f8e3c((u32) kart, 0xf3);
            }
        }
    }
    if (kart->field4C & 0x800) {
        p->field160 = TRUE;
        p->mVisible = FALSE;
    }
    v = p->mVelocityX;
    if (p->field0.mAlpha < 0x1f && p->field194 == 0 && p->mVisible != FALSE) {
        p->field0.mAlpha = p->field0.mAlpha + 7;
        if (p->field0.mAlpha > 0x1f) {
            p->field0.mAlpha = 0x1f;
        }
    }
    p->mStepTimer = p->mStepTimer - 1;
    if (p->mStepTimer > 0) {
        factor = p->mApproachRate;
        m = p->mTargetVelocityX - p->mVelocityX;
        n = p->mTargetVelocityY - p->mVelocityY;
        p->mVelocityX += (s32) (((s64) factor * m) >> 12);
        p->mVelocityY += (s32) (((s64) factor * n) >> 12);
    } else {
        factor = p->mDamping;
        p->mVelocityX = ((s64) p->mVelocityX * factor) >> 12;
        p->mVelocityY = ((s64) p->mVelocityY * factor) >> 12;
        if (p->field194 != 0) {
            p->field0.mAlpha = p->field0.mAlpha - p->field170;
            if (p->field0.mAlpha >= 1) {
                p->mStepTimer = 0;
            } else {
                p->mStepTimer = -1 - p->field170;
                p->mVisible = FALSE;
                p->field0.mAlpha = 1;
            }
        }
        if (p->mStepTimer < -p->field170) {
            if (itgsso_210300C(p) != FALSE) {
                p->field160 = TRUE;
                p->mVisible = FALSE;
                return;
            }
        }
    }
    p->mViewOffset.x += p->mVelocityX;
    p->mViewOffset.y += p->mVelocityY;
    v = ((s64) (p->mVelocityX - (s32) (((s64) v * 0xccd) >> 12)) * 0x19a) >> 12;
    if (v > 0x19a) {
        v = 0x19a;
    } else if (v < -0x19a) {
        v = -0x19a;
    }
    p->field19C += v;
    p->field19C = ((s64) p->field19C * 0xeb8) >> 12;
    if (p->field19C > 0x266) {
        p->field19C = 0x266;
    } else if (p->field19C < -0x266) {
        p->field19C = -0x266;
    }
    factor = p->field184.z;
    m = p->field174 - p->field180;
    n = p->field178 - p->field184.x;
    p->field180 += (s32) (((s64) factor * m) >> 12);
    p->field184.x += (s32) (((s64) factor * n) >> 12);
    viewOffset = p->mViewOffset;
    v = ((s64) p->field19C * 0x800) >> 12;
    viewOffset.x -= (s32) (((s64) v * viewOffset.x) >> 12);
    p->field0.mPos.x = ((s64) camera->mSide.x * -viewOffset.x) >> 12;
    p->field0.mPos.y = ((s64) camera->mSide.y * -viewOffset.x) >> 12;
    p->field0.mPos.z = ((s64) camera->mSide.z * -viewOffset.x) >> 12;
    VEC_MultAdd(viewOffset.y, &camera->mUp, &p->field0.mPos, &p->field0.mPos);
    VEC_MultAdd(-viewOffset.z, &camera->mForward, &p->field0.mPos, &p->field0.mPos);
    VEC_Add(&camera->mPos, &p->field0.mPos, &p->field0.mPos);
}

void itgsso_21027AC(ItemGesso *p, s32 param_2, NsbmdModel *t) {
    Vec3 scale;
    MtxFx43 matrix;
    s32 scaleFactor;
    s32 d;

    if (p->mKart == NULL) {
        return;
    }
    if (p->mVisible == FALSE) {
        return;
    }
    matrix = *bbm_getBillboardAtPos(&p->field0.mPos);
    d = p->field19C;
    if (d <= 0) {
        d = -d;
    }
    d = 0x1000 - (s32) (((s64) d * 0xa4) >> 12);
    matrix.field0[1].x = ((s64) matrix.field0[1].x * d) >> 12;
    matrix.field0[1].y = ((s64) matrix.field0[1].y * d) >> 12;
    matrix.field0[1].z = ((s64) matrix.field0[1].z * d) >> 12;
    VEC_MultAdd(p->field19C, &matrix.field0[0], &matrix.field0[1], &matrix.field0[1]);
    scale.x = ((s64) p->field180 * p->field0.mScale.x) >> 12;
    scale.y = ((s64) p->field184.x * p->field0.mScale.y) >> 12;
    scale.z = p->field0.mScale.z;
    scaleFactor = rstat_getUncontrollable() != 0 ? 0xccd : 0x119a;
    scale.x = ((s64) scale.x * scaleFactor) >> 12;
    scale.y = ((s64) scale.y * scaleFactor) >> 12;
    d = p->field0.mAlpha;
    if (d != 0x1f) {
        t->field14 = t->field14 & ~0x1f0000;
        t->field14 = t->field14 | ((u16) d << 16);
    }
    bbm_applyMaterial(t);
    bbm_renderTransformedScaled(t, &matrix, &scale, 0, 0x1f);
    if (p->field0.mAlpha == 0x1f) {
        return;
    }
    t->field14 = t->field14 & ~0x1f0000;
    t->field14 = t->field14 | 0x1f0000;
}

void itgsso_2102764(void *data, ItemGesso *gesso, void *toData) {
    CopyItemObjectData(data, gesso, toData);
    if (gesso == NULL) {
        return;
    }
    if (toData == NULL) {
        return;
    }
    func_020fe8ac(gesso->field0.mKind);
}

void itgsso_2102744(ItemGesso *gesso) {
    func_020f8e78(gesso);
    itgsso_2102EB8((u32) gesso, 1);
}

#pragma thumb on
void itgsso_2102718(void) {
    s32 i;
    ItemGessoStep *step;

    gItemGessoFrameCount = 0xf;
    for (i = 0, step = gItemGessoSteps; i < 0x11; i++) {
        gItemGessoFrameCount += step->field8 + step->fieldA;
        step++;
    }
}
#pragma thumb off

void CreateItemTeresaFrameScaleTable(void) {
    s32 i;

    gItemTeresaFrameScales = heap_alloc(proc_getHeap(proc_getCurrent()), 0x52);
    for (i = 0; i <= 0x28; i++) {
        gItemTeresaFrameScales[i] = ((0x28 - i) << 12) / (0x29 - i);
    }
    for (i -= 5; i <= 0x28; i++) {
        gItemTeresaFrameScales[i] = (gItemTeresaFrameScales[i] + gItemTeresaFrameScales[i - 1]) >> 1;
    }
}
