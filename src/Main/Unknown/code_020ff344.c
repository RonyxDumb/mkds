#include "Main/Unknown/code_020ff344.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Ui/ChoisesS.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_021052f0.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_020ee684.h"
#include "01/code_02187d14.h" // data_0217c600

#pragma thumb on

void dram_loadModel(void) {
    model2_createFromNsbmd(&dram_sModel, mobj_getMapObjFile(aDram_nsbmd), NULL);
    model_setPolyIdLightFlagsEmi(dram_sModel, 0x3f, 2, 0x294a);
}

void dram_init(Dram *dram, struct CourseMapRow *courseRow) {
    sm_init(&dram->field0.mStateMachine, (UnkFunc *const *) dram_sStates, 6, dram);
    dram->fieldB4[0] = courseRow->field28 * 0x80 / 100;
    dram->fieldB4[2] = courseRow->field30 * 0x80 / 100;
    dram->fieldB4[1] = (dram->fieldB4[0] + dram->fieldB4[2]) / 2;
    dram->fieldA2 = courseRow->field2A;
    dram->fieldA0 = courseRow->field2C;
    dram->fieldA4 = courseRow->field2E;
    dram->fieldA6 = 0;
    if (dram->fieldA0 != 0) {
        dram->fieldB0 = 0x1000 / dram->fieldA0;
    } else {
        dram->fieldB0 = 0;
    }
    dram->fieldAC = 0;
    dram->field0.mStateMachine.mNextState = 1;
    dram->field0.mStateMachine.mNextStateRequested = 1;
}

#pragma thumb off

Unk02100004 *func_020ffacc(void) {
    Unk02100004 *p;

    p = proc_getHeap(proc_getCurrent());
    p = heap_alloc(p, 0x40);
    *p = data_0215a068;
    return p;
}

BOOL IsWall(u32 kind) {
    return kind == 0xb;
}

#pragma thumb on

void func_020ff97c(Unk020ff97c *object) {
    object->fieldA0 = *(MtxFx33 *) &object->field0.mMatrix;
    object->field124 = 0;
    object->field128 = 0;
    object->field12C = 0;
    object->field130 = 0;
    object->field100 = ((s64) object->field0.mScale.x * 0x190000) >> 12;
    object->field104 = (s32) (((s64) object->field0.mScale.y * 0x64000) >> 12) >> 1;
    object->field108 = ((s64) object->field0.mScale.z * 0xaf000) >> 12;
    object->field10C = ((s64) object->field0.mScale.z * 0xaf000) >> 12;
    object->field110 = 0;
    object->field114 = 1;
    object->field118 = 0;
    object->field11C = 0;
    object->field120 = 0x800;
    object->fieldE8 = object->field0.mPos;
    object->field0.field10.x = 0;
    object->field0.field10.y = 0;
    object->field0.field10.z = 0;
    VEC_MultAdd(-object->field104, &object->field0.mMatrix.field0[1], &object->field0.mPos, &object->fieldF4);
    object->field134 = 0;
    object->field138 = 0;
    object->field13C = 1;
    object->field0.mFlags |= data_0215a030;
}

#pragma thumb off

void SetItemFBoxDrawMatrix(ItemFBox *fbox, MtxFx43 *out) {
    Vec3 *position;

    position = fbox->field0.mItemObject.fieldD0;
    fbox->field0.mItemObject.field94.field0[3].x = position->x >> 4;
    fbox->field0.mItemObject.field94.field0[3].y = position->y >> 4;
    fbox->field0.mItemObject.field94.field0[3].z = position->z >> 4;
    *out = fbox->field0.mItemObject.field94;
    MTX_Concat33((const s32 *) &data_0217c600, (const s32 *) out, (s32 *) out);
}

void func_020ff6d8(ItemFBox *fbox, MtxFx43 *out) {
    s32 scaledX, scaledZ;
    Vec3 *position;

    if ((fbox->field0.mItemObject.mFlags & 0x80000) && rchoi_getIsRacePaused() == 0) {
        s32 row0Dot, row2Dot;

        row0Dot = ((s64) fbox->field0.mItemObject.field94.field0[0].x * fbox->field130.x +
                   (s64) fbox->field0.mItemObject.field94.field0[0].z * fbox->field130.z) >>
                  12;
        scaledX = ((s64) fbox->field130.x * 0xa4) >> 12;
        row2Dot = ((s64) fbox->field0.mItemObject.field94.field0[2].x * fbox->field130.x +
                   (s64) fbox->field0.mItemObject.field94.field0[2].z * fbox->field130.z) >>
                  12;
        scaledZ = ((s64) fbox->field130.z * 0xa4) >> 12;
        fbox->field0.mItemObject.field94.field0[1].x =
            (s32) (fbox->field0.mItemObject.field94.field0[1].x + scaledX);
        fbox->field0.mItemObject.field94.field0[1].z += scaledZ;
        if ((s64) fbox->field0.mItemObject.field94.field0[1].x * fbox->field0.mItemObject.field94.field0[1].x +
                (s64) fbox->field0.mItemObject.field94.field0[1].y *
                    fbox->field0.mItemObject.field94.field0[1].y +
                (s64) fbox->field0.mItemObject.field94.field0[1].z *
                    fbox->field0.mItemObject.field94.field0[1].z >=
            0x10) {
            vec_normalize(&fbox->field0.mItemObject.field94.field0[1],
                                               &fbox->field0.mItemObject.field94.field0[1]);
        }
        if (row0Dot * row0Dot > row2Dot * row2Dot) {
            fbox->field0.mItemObject.field94.field0[2].x =
                (s32) (fbox->field0.mItemObject.field94.field0[2].x - scaledX);
            fbox->field0.mItemObject.field94.field0[2].z -= scaledZ;
            vec_crossProduct(&fbox->field0.mItemObject.field94.field0[1],
                               &fbox->field0.mItemObject.field94.field0[2],
                               &fbox->field0.mItemObject.field94.field0[0]);
            if ((s64) fbox->field0.mItemObject.field94.field0[0].x *
                        fbox->field0.mItemObject.field94.field0[0].x +
                    (s64) fbox->field0.mItemObject.field94.field0[0].y *
                        fbox->field0.mItemObject.field94.field0[0].y +
                    (s64) fbox->field0.mItemObject.field94.field0[0].z *
                        fbox->field0.mItemObject.field94.field0[0].z >=
                0x10) {
                vec_normalize(&fbox->field0.mItemObject.field94.field0[0],
                                                   &fbox->field0.mItemObject.field94.field0[0]);
            }
            vec_crossProduct(&fbox->field0.mItemObject.field94.field0[0],
                               &fbox->field0.mItemObject.field94.field0[1],
                               &fbox->field0.mItemObject.field94.field0[2]);
        } else {
            fbox->field0.mItemObject.field94.field0[0].x -= scaledX;
            fbox->field0.mItemObject.field94.field0[0].z -= scaledZ;
            vec_crossProduct(&fbox->field0.mItemObject.field94.field0[0],
                               &fbox->field0.mItemObject.field94.field0[1],
                               &fbox->field0.mItemObject.field94.field0[2]);
            if ((s64) fbox->field0.mItemObject.field94.field0[2].x *
                        fbox->field0.mItemObject.field94.field0[2].x +
                    (s64) fbox->field0.mItemObject.field94.field0[2].y *
                        fbox->field0.mItemObject.field94.field0[2].y +
                    (s64) fbox->field0.mItemObject.field94.field0[2].z *
                        fbox->field0.mItemObject.field94.field0[2].z >=
                0x10) {
                vec_normalize(&fbox->field0.mItemObject.field94.field0[2],
                                                   &fbox->field0.mItemObject.field94.field0[2]);
            }
            vec_crossProduct(&fbox->field0.mItemObject.field94.field0[1],
                               &fbox->field0.mItemObject.field94.field0[2],
                               &fbox->field0.mItemObject.field94.field0[0]);
        }
    }
    position = fbox->field0.mItemObject.fieldD0;
    fbox->field0.mItemObject.field94.field0[3].x = position->x >> 4;
    fbox->field0.mItemObject.field94.field0[3].y = position->y >> 4;
    fbox->field0.mItemObject.field94.field0[3].z = position->z >> 4;
    *out = fbox->field0.mItemObject.field94;
}

void itfbox_initInstance(ItemFBox *fbox) {
    *(MtxFx33 *) &fbox->field0.mItemObject.field94 = *(MtxFx33 *) &data_0217c600;
    ResetPooledMapObject(fbox->mPooledMapObject);
    fbox->mPooledMapObject->fieldB0 = 2;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, SetItemFBoxDrawMatrix, fbox);
}

void itfbox_20FF654(ItemFBox *fbox) {
    fbox->mPooledMapObject->fieldB0 = 1;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, func_020ff6d8, fbox);
}

void itfbox_20FF638(ItemInUse *inUse, ItemFBox *fbox) {
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->field0.mItemObject.mAlpha,
                               &fbox->field0.mItemObject.mScale);
}

u32 itfbox_20FF538(ItemInUse *inUse, ItemFBox *fbox) {
    func_020f9114(fbox);
    fbox->field0.mItemObject.field78 |= data_0215a02c;
    MTX_Concat33((const s32 *) &data_0217c600, (const s32 *) &fbox->field0.mItemObject.field94,
                 (s32 *) &fbox->field0.mItemObject.field94);
    fbox->field130.x = 0;
    fbox->field130.y = 0;
    fbox->field130.z = 0;
    if ((inUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) != 0) {
        ThrowBouncingItem(&fbox->field0, inUse, 0, 1, 0x4000, 0x3000, 0x59a);
        sfx_21090C4(&fbox->field0.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        fbox->mThrownForward = 1;
        return fbox->mThrownForward;
    }
    ThrowBouncingItem(&fbox->field0, inUse, 0, 0, 0x4000, 0x3000, 0x59a);
    fbox->mThrownForward = 0;
    return fbox->mThrownForward;
}

void itfbox_20FF438(ItemFBox *fbox) {
    s32 unusedOutput;

    if (fbox->field0.mItemObject.mFlags & 0x180000) {
        if (fbox->field0.mItemObject.mFlags & 0x80000) {
            func_020f6e58(&fbox->field0.mItemObject);
        } else if (fbox->field0.mItemObject.mFlags & 0x100000) {
            AdvanceItemObjectReleaseTimer(&fbox->field0.mItemObject);
        }
    } else if (fbox->field0.mItemObject.mFlags & 0x8000) {
        AdvanceRestingItemObject(&fbox->field0.mItemObject);
    } else if (fbox->field0.mItemObject.mFlags & 0x4000) {
        AdvanceFallingItemObject(&fbox->field0.mItemObject);
    } else {
        if (fbox->mThrownForward != 0) {
            AdvanceBouncingItem(&fbox->field0, 0x1ec, 0xfec, 0, (u32 *) &unusedOutput);
        } else {
            AdvanceBouncingItem(&fbox->field0, 0x2e1, 0xf85, 0, (u32 *) &unusedOutput);
        }
        if ((fbox->field0.mItemObject.mFlags & 8) && (fbox->field0.mItemObject.mFlags & 3) == 0) {
            if (fbox->mThrownForward != 0) {
                fbox->field0.mItemObject.mVelocity.y *= 2;
            }
            StopSound(&fbox->field0.mItemObject.mSoundSource, 0xda);
            StartRestingItemObject(&fbox->field0.mItemObject, &unusedOutput);
        }
    }
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->field0.mItemObject.mAlpha,
                               &fbox->field0.mItemObject.mScale);
}

s32 itfbox_20FF3C4(ItemFBox *fbox) {
    Vec3 *vector;

    vector = gItemPushVector;
    if ((s64) vector->x * vector->x + (s64) vector->y * vector->y + (s64) vector->z * vector->z >= 0x10) {
        vec_normalize(vector, &fbox->field130);
    }
    fbox->mPooledMapObject->fieldB0 = 2;
    if ((fbox->field0.mItemObject.mFlags & 0x180000) == 0) {
        fbox->field0.mItemObject.mAdvance = (void (*)(ItemObject *)) itfbox_20FF438;
    }
    return 2;
}

void itfbox_20FF344(ItemFBox *fbox) {
    if ((s64) fbox->field0.mItemObject.field94.field0[0].x * fbox->field0.mItemObject.field94.field0[0].x +
            (s64) fbox->field0.mItemObject.field94.field0[0].y * fbox->field0.mItemObject.field94.field0[0].y +
            (s64) fbox->field0.mItemObject.field94.field0[0].z * fbox->field0.mItemObject.field94.field0[0].z >=
        0x10) {
        vec_normalize(&fbox->field0.mItemObject.field94.field0[0],
                                           &fbox->field0.mItemObject.field94.field0[0]);
    }
    vec_crossProduct(&fbox->field0.mItemObject.field94.field0[0], &fbox->field0.mItemObject.field94.field0[1],
                       &fbox->field0.mItemObject.field94.field0[2]);
    MTX_Concat33((const s32 *) &data_0217c600, (const s32 *) &fbox->field0.mItemObject.field94,
                 (s32 *) &fbox->field0.mItemObject.field94);
    if ((fbox->field0.mItemObject.mFlags & 0x180000) == 0) {
        fbox->field0.mItemObject.mAdvance = (void (*)(ItemObject *)) itfbox_20FF438;
    }
}
