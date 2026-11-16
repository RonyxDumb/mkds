#include "Main/Unknown/code_02099020.h"

#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/unk_02156000.h"

void pknf_init(u32 mapObject) {
    u32 addedFlagsAddress = ((u32) (&data_02156598));
    u32 flags = (*(u16 *) ((mapObject) + (2)));
    u32 addedFlags = (*(u16 *) ((addedFlagsAddress) + (0)));
    u32 newFlags = ((flags) | (addedFlags));
    u32 v7;
    u32 v9;
    *(u16 *) ((mapObject) + (2)) = newFlags;
    mobj_setInvisible((void *) mapObject);
    mobj_initSoundEmitterForObjectSfxParam2((MapObject *) mapObject);
}

u32 pknf_onDriverCollide(Unk0209905c *a, Kart *kart, u8 *c, u8 *d) {
    u32 v1 = *c;
    u8 result = *d;
    if (v1 == 1) {
        a->field0.mFlags = a->field0.mFlags | data_02156590;
        a->mState = 1;
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
            a->field0.mDistanceSquaredAndFlags = a->field0.mDistanceSquaredAndFlags | data_02156594;
        }
        mobj_tryDestroyByDriver(&a->field0, kart);
    }
    return result;
}

void pknf_update(void *a, Unk0209905c *p) {
    s32 falloffIndex;
    Unk0210b7a8 soundRequest;
    Unk0209905c_d0_08 *entry;
    switch (p->mState) {
        case 0:
            p->mHeightOffset = p->mHeightOffset + p->fieldC8;
            p->fieldC8 = p->fieldC8 - 0x1000;
            if (p->mHeightOffset <= 0) {
                p->mHeightOffset = 0;
                p->fieldC8 = 0x5800;
                if ((p->field0.mDistanceSquaredAndFlags & 4) == 0) {
                    if (p->field0.mFarDistanceSquared == gSfxParams[2].field20) {
                        falloffIndex = 2;
                    } else if (p->field0.mFarDistanceSquared == gSfxParams[3].field20) {
                        falloffIndex = 3;
                    } else {
                        falloffIndex = 4;
                    }
                    soundRequest.mSoundId = 0x1af;
                    soundRequest.mPositionSource = &p->field0.mPos;
                    soundRequest.field8 = falloffIndex;
                    soundRequest.mDistanceSquared = mobj_calcXZCamDist(&p->field0.mPos);
                    sub_210B7A8(&soundRequest);
                }
            }
            if (pw_update(&p->mFollower) != FALSE && p->mFollower.mForward == 0) {
                p->mState = 1;
            } else {
                pw_calcCurrentPointLinearXYZSpecial(&p->mFollower, &p->field0.mPos, &p->field0.field10);
                p->field0.mPos.y = p->field0.mPos.y + (p->mHeightOffset + 0xf000);
            }
            if (p->mEmitter == NULL) {
                return;
            }
            if ((p->field0.mFlags & 0x12) != 0) {
                p->mEmitter->field24 |= 2;
                return;
            }
            ptcm_setEmitterPosition(p->mEmitter, &p->field0.mPos);
            p->mEmitter->field24 &= ~2;
            return;
        case 1:
            if (p->mEmitter != NULL) {
                for (entry = p->mEmitter->field8; entry != NULL; entry = entry->field0) {
                    entry->field26 = entry->field24;
                }
                ptcm_killEmitter((void **) &p->mEmitter);
            }
            mobj_setInvisible(&p->field0);
            return;
    }
}

void pknf_setupConfig(void) {
    mobj_createConfigEx(&pknf_onDriverCollide, NULL, NULL, 1, 1, (0x0000018du));
}
