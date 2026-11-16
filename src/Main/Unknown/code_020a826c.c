#include "Main/Unknown/code_020a826c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020a8ed8.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_0203c25c.h"
#include "Main/Kart/KartTimes.h"

static inline void func_020a826c_inline(Unk020a826c_a0 *q) {
    s32 v;

    if (q->field0.field8 == 2) {
        v = gSfxParams[2].field20;
    } else if (q->field0.field8 == 3) {
        v = gSfxParams[3].field20;
    } else if (q->field0.field8 == 4) {
        v = gSfxParams[4].field20;
    } else if (q->field0.field8 == 5) {
        v = gSfxParams[5].field20;
    } else if (q->field0.field8 == 6) {
        v = gSfxParams[6].field20;
    } else if (q->field0.field8 == 8) {
        v = gSfxParams[8].field20;
    } else {
        v = 0;
    }
    q->field0.mDistanceSquared = mobj_calcXZCamDist(&q->mSourcePos);
    if (q->field0.mDistanceSquared < v) {
        q->field24 = q->field24 == 0 ? 1 : 2;
        if (race_isCamAnimMode() != 0) {
            sub_210B734(&q->field0, q->mSndHandleSlot);
        } else {
            sub_210B760(&q->field0, q->mSndHandleSlot);
        }
    } else {
        q->field24 = 0;
    }
}

void mobj0008_updateInstanceLogic(void *a, Unk020a826c *p) {
    s32 v;

    switch (p->mState) {
        case 1:
            if (race_getState() == 1) {
                v = p->fieldC8.field0.mSoundId;
                NNS_SndPlayerStopSeq(p->fieldA0.mSndHandleSlot, 0);
                p->fieldA0.field0.mSoundId = v;
                p->mState = 2;
            }
            func_020a826c_inline(&p->fieldA0);
            break;
        case 2:
            mobj0008_20A8ED8(&p->fieldA0, &p->field0.mPos);
            if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL && rstat_isDriverInFinalLap(gRaceMultiConfig->mEntryIndex) != FALSE &&
                p->fieldA0.field24 == 0 && p->fieldA0.field20 != FALSE) {
                v = sub_2110C40();
                NNS_SndPlayerStopSeq(p->fieldA0.mSndHandleSlot, 0);
                p->fieldA0.field0.mSoundId = v;
                p->mState = 3;
            }
            func_020a826c_inline(&p->fieldA0);
            break;
        case 3:
            mobj0008_20A8ED8(&p->fieldA0, &p->field0.mPos);
            if (rstat_hasDriverFinished((u16) gRaceMultiConfig->mEntryIndex) != 0) {
                mobj_setInvisible(&p->field0);
            } else if (p->fieldA0.field20 == FALSE) {
                v = p->fieldC8.field0.mSoundId;
                NNS_SndPlayerStopSeq(p->fieldA0.mSndHandleSlot, 0);
                p->fieldA0.field0.mSoundId = v;
                p->mState = 2;
            }
            func_020a826c_inline(&p->fieldA0);
            break;
        case 4:
            func_020a826c_inline(&p->fieldA0);
            func_020a826c_inline(&p->fieldC8);
            break;
        case 5:
            func_020a826c_inline(&p->fieldA0);
            break;
        case 6:
            func_020a826c_inline(&p->fieldA0);
            func_020a826c_inline(&p->fieldC8);
            break;
    }
}
