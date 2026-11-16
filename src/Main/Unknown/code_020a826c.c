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

    if (q->mUnk_00.mUnk_08 == 2) {
        v = gSfxParams[2].mUnk_20;
    } else if (q->mUnk_00.mUnk_08 == 3) {
        v = gSfxParams[3].mUnk_20;
    } else if (q->mUnk_00.mUnk_08 == 4) {
        v = gSfxParams[4].mUnk_20;
    } else if (q->mUnk_00.mUnk_08 == 5) {
        v = gSfxParams[5].mUnk_20;
    } else if (q->mUnk_00.mUnk_08 == 6) {
        v = gSfxParams[6].mUnk_20;
    } else if (q->mUnk_00.mUnk_08 == 8) {
        v = gSfxParams[8].mUnk_20;
    } else {
        v = 0;
    }
    q->mUnk_00.mDistanceSquared = mobj_calcXZCamDist(&q->mSourcePos);
    if (q->mUnk_00.mDistanceSquared < v) {
        q->mUnk_24 = q->mUnk_24 == 0 ? 1 : 2;
        if (race_isCamAnimMode() != 0) {
            func_0210b734(&q->mUnk_00, q->mSndHandleSlot);
        } else {
            func_0210b760(&q->mUnk_00, q->mSndHandleSlot);
        }
    } else {
        q->mUnk_24 = 0;
    }
}

void mobj0008_updateInstanceLogic(void *a, Unk020a826c *p) {
    s32 v;

    switch (p->mState) {
        case 1:
            if (race_getState() == 1) {
                v = p->mUnk_0c8.mUnk_00.mSoundId;
                NNS_SndPlayerStopSeq(p->mUnk_0a0.mSndHandleSlot, 0);
                p->mUnk_0a0.mUnk_00.mSoundId = v;
                p->mState = 2;
            }
            func_020a826c_inline(&p->mUnk_0a0);
            break;
        case 2:
            mobj0008_20A8ED8(&p->mUnk_0a0, &p->mUnk_000.mPos);
            if (gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL && rstat_isDriverInFinalLap(gRaceMultiConfig->mEntryIndex) != FALSE &&
                p->mUnk_0a0.mUnk_24 == 0 && p->mUnk_0a0.mUnk_20 != FALSE) {
                v = func_02110c40();
                NNS_SndPlayerStopSeq(p->mUnk_0a0.mSndHandleSlot, 0);
                p->mUnk_0a0.mUnk_00.mSoundId = v;
                p->mState = 3;
            }
            func_020a826c_inline(&p->mUnk_0a0);
            break;
        case 3:
            mobj0008_20A8ED8(&p->mUnk_0a0, &p->mUnk_000.mPos);
            if (rstat_hasDriverFinished((u16) gRaceMultiConfig->mEntryIndex) != 0) {
                mobj_setInvisible(&p->mUnk_000);
            } else if (p->mUnk_0a0.mUnk_20 == FALSE) {
                v = p->mUnk_0c8.mUnk_00.mSoundId;
                NNS_SndPlayerStopSeq(p->mUnk_0a0.mSndHandleSlot, 0);
                p->mUnk_0a0.mUnk_00.mSoundId = v;
                p->mState = 2;
            }
            func_020a826c_inline(&p->mUnk_0a0);
            break;
        case 4:
            func_020a826c_inline(&p->mUnk_0a0);
            func_020a826c_inline(&p->mUnk_0c8);
            break;
        case 5:
            func_020a826c_inline(&p->mUnk_0a0);
            break;
        case 6:
            func_020a826c_inline(&p->mUnk_0a0);
            func_020a826c_inline(&p->mUnk_0c8);
            break;
    }
}
