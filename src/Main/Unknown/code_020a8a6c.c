#include "Main/Unknown/code_020a8a6c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020a8ed8.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

void mobj0008_initLogicPart(Unk020a8a6c *a) {
    s32 i;
    Unk020a826c *p;
    CourseMapRow *q;
    s32 x1;
    s32 y1;
    s32 z1;
    s32 x2;
    s32 y2;
    s32 z2;
    s32 x3;
    s32 y3;
    s32 z3;
    s32 x4;
    s32 y4;
    s32 z4;
    s32 x5;
    s32 y5;
    s32 z5;
    s32 v1;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mMapObjectCount && (p = a->mMapObjects[i]) != NULL; i++) {
        if (race_isCamAnimMode() != 0) {
            switch (gRaceMultiConfig->mCourseId) {
                case COURSE_ID_CROSS:
                    p->mState = 4;
                    q = p->field0.mCourseMapRow;
                    z1 = q->field0.z + (-0x4a6000);
                    y1 = q->field0.y;
                    x1 = q->field0.x + (-0x2c6000);
                    p->fieldA0.field0.mSoundId = 0x103;
                    p->fieldA0.field0.field8 = 5;
                    p->fieldA0.field0.mPositionSource = &p->fieldA0.mSourcePos;
                    p->fieldA0.mSndHandleSlot = GetSndHandleSlot(8);
                    p->fieldA0.mSourcePos.x = x1;
                    p->fieldA0.mSourcePos.y = y1;
                    p->fieldA0.mSourcePos.z = z1;
                    q = p->field0.mCourseMapRow;
                    z2 = q->field0.z + 0x726000;
                    y2 = q->field0.y;
                    x2 = q->field0.x + (-0x7ee000);
                    p->fieldC8.field0.mSoundId = 0x103;
                    p->fieldC8.field0.field8 = 5;
                    p->fieldC8.field0.mPositionSource = &p->fieldC8.mSourcePos;
                    p->fieldC8.mSndHandleSlot = GetSndHandleSlot(9);
                    p->fieldC8.mSourcePos.x = x2;
                    p->fieldC8.mSourcePos.y = y2;
                    p->fieldC8.mSourcePos.z = z2;
                    break;
                case COURSE_ID_BANK:
                    p->mState = 5;
                    q = p->field0.mCourseMapRow;
                    z3 = q->field0.z;
                    y3 = q->field0.y;
                    x3 = q->field0.x;
                    p->fieldA0.field0.mSoundId = 0x109;
                    p->fieldA0.field0.field8 = 4;
                    p->fieldA0.field0.mPositionSource = &p->fieldA0.mSourcePos;
                    if (i == 0) {
                        v1 = 8;
                    } else if (i == 1) {
                        v1 = 9;
                    } else {
                        v1 = 10;
                    }
                    p->fieldA0.mSndHandleSlot = GetSndHandleSlot(v1);
                    p->fieldA0.mSourcePos.x = x3;
                    p->fieldA0.mSourcePos.y = y3;
                    p->fieldA0.mSourcePos.z = z3;
                    VEC_MultAdd(((s64) p->field0.mScale.z * 0x5000) >> 12, &p->field0.mMatrix.field0[2],
                                &p->fieldA0.mSourcePos, &p->fieldA0.mSourcePos);
                    break;
                default:
                    if ((p->field0.mFlags & 0x100) == 0) {
                        mobj_setInvisible(&p->field0);
                    }
                    break;
            }
        } else {
            switch (gRaceMultiConfig->mCourseId) {
                case COURSE_ID_CROSS:
                    p->mState = 1;
                    p->fieldA0.field0.mSoundId = 0x108;
                    p->fieldA0.field0.field8 = 8;
                    p->fieldA0.field0.mPositionSource = &p->fieldA0.mSourcePos;
                    p->fieldA0.mSndHandleSlot = GetSndHandleSlot(8);
                    p->fieldA0.mSourcePos.x = 0;
                    p->fieldA0.mSourcePos.y = 0;
                    p->fieldA0.mSourcePos.z = 0;
                    p->fieldC8.field0.mSoundId = 0x107;
                    p->fieldC8.field0.field8 = 8;
                    p->fieldC8.field0.mPositionSource = &p->fieldC8.mSourcePos;
                    p->fieldC8.mSndHandleSlot = GetSndHandleSlot(9);
                    p->fieldC8.mSourcePos.x = 0;
                    p->fieldC8.mSourcePos.y = 0;
                    p->fieldC8.mSourcePos.z = 0;
                    mobj0008_20A8ED8(&p->fieldA0, &p->field0.mPos);
                    break;
                case COURSE_ID_MARIO:
                    p->mState = 1;
                    p->fieldA0.field0.mSoundId = 0x1a0;
                    p->fieldA0.field0.field8 = 8;
                    p->fieldA0.field0.mPositionSource = &p->fieldA0.mSourcePos;
                    p->fieldA0.mSndHandleSlot = GetSndHandleSlot(8);
                    p->fieldA0.mSourcePos.x = 0;
                    p->fieldA0.mSourcePos.y = 0;
                    p->fieldA0.mSourcePos.z = 0;
                    p->fieldC8.field0.mSoundId = 0x19f;
                    p->fieldC8.field0.field8 = 8;
                    p->fieldC8.field0.mPositionSource = &p->fieldC8.mSourcePos;
                    p->fieldC8.mSndHandleSlot = GetSndHandleSlot(9);
                    p->fieldC8.mSourcePos.x = 0;
                    p->fieldC8.mSourcePos.y = 0;
                    p->fieldC8.mSourcePos.z = 0;
                    mobj0008_20A8ED8(&p->fieldA0, &p->field0.mPos);
                    break;
                case COURSE_ID_BANK:
                    p->mState = 6;
                    q = p->field0.mCourseMapRow;
                    z4 = q->field0.z;
                    y4 = q->field0.y;
                    x4 = q->field0.x;
                    p->fieldA0.field0.mSoundId = 0x109;
                    p->fieldA0.field0.field8 = 6;
                    p->fieldA0.field0.mPositionSource = &p->fieldA0.mSourcePos;
                    p->fieldA0.mSndHandleSlot = GetSndHandleSlot(8);
                    p->fieldA0.mSourcePos.x = x4;
                    p->fieldA0.mSourcePos.y = y4;
                    p->fieldA0.mSourcePos.z = z4;
                    VEC_MultAdd(((s64) p->field0.mScale.z * 0x5000) >> 12, &p->field0.mMatrix.field0[2],
                                &p->fieldA0.mSourcePos, &p->fieldA0.mSourcePos);
                    q = p->field0.mCourseMapRow;
                    z5 = q->field0.z;
                    y5 = q->field0.y;
                    x5 = q->field0.x;
                    p->fieldC8.field0.mSoundId = 0x109;
                    p->fieldC8.field0.field8 = 6;
                    p->fieldC8.field0.mPositionSource = &p->fieldC8.mSourcePos;
                    p->fieldC8.mSndHandleSlot = GetSndHandleSlot(9);
                    p->fieldC8.mSourcePos.x = x5;
                    p->fieldC8.mSourcePos.y = y5;
                    p->fieldC8.mSourcePos.z = z5;
                    VEC_MultAdd(((s64) p->field0.mScale.z * -0x5000) >> 12, &p->field0.mMatrix.field0[2],
                                &p->fieldC8.mSourcePos, &p->fieldC8.mSourcePos);
                    break;
                default:
                    if ((p->field0.mFlags & 0x100) == 0) {
                        mobj_setInvisible(&p->field0);
                    }
                    break;
            }
        }
    }
}
