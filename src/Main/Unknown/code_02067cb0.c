#include "Main/Unknown/code_02067cb0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02081120.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Kart/KartStates.h"
#include "Main/Unknown/code_02077bc0.h"

int driver_initSingleSpinOutReaction(Kart *p, s32 *a, MapObject *c) {
    if (p->mVelocityLength > 0x3000 || (c->mFlags & 0x200)) {
        if (driver_tryStartSpinOut(p, 1, 0)) {
            if (p->mKartModelsEntry->mUnk_058 == 0) {
                ptcm_createEmitter(0xc, &p->mPos);
                ptcm_createEmitter(0xd, &p->mPos);
                ptcm_createEmitter(0xe, &p->mPos);
            }
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                driver_getPlayerStatistics()->mUnk_14++;
            }
        }
        *a = 3;
    } else {
        *a = 2;
    }
    return 0xb;
}

int driver_initDoubleSpinOutReaction(Kart *p, s32 *a, MapObject *c) {
    if (p->mVelocityLength > 0x3000 || (c->mFlags & 0x200)) {
        if (driver_tryStartSpinOut(p, 2, 0)) {
            if (p->mKartModelsEntry->mUnk_058 == 0) {
                ptcm_createEmitter(0xc, &p->mPos);
                ptcm_createEmitter(0xd, &p->mPos);
                ptcm_createEmitter(0xe, &p->mPos);
            }
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                driver_getPlayerStatistics()->mUnk_14++;
            }
        }
        *a = 4;
    } else {
        *a = 2;
    }
    return 0xb;
}

int driver_initDoubleSpinOutWaterReaction(Kart *p, s32 *a, MapObject *c) {
    if (p->mVelocityLength > 0x3000 || (c->mFlags & 0x200)) {
        if (driver_tryStartSpinOut(p, 2, 0)) {
            if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                driver_getPlayerStatistics()->mUnk_14++;
            }
            rptc_startWaterEffect(p->mIndex);
        }
        *a = 4;
    } else {
        *a = 0;
    }
    return 0;
}

int driver_initDoubleSpinOutFireReaction(Kart *p, s32 *a) {
    if (driver_tryStartSpinOut(p, 2, 0)) {
        if (p->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
            rptc_2081E3C(ptcm_createEmitter(0x4f, &p->mPos), p->mIndex, 0x46);
        }
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            driver_getPlayerStatistics()->mUnk_14++;
        }
    }
    *a = 5;
    return 0;
}

int driver_initForwardFlipReaction(Kart *p, s32 *a) {
    if (driver_tryStartForwardFlip(p)) {
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            driver_getPlayerStatistics()->mUnk_14++;
        }
        p->mUnk_48 |= 0x20000;
    }
    *a = 7;
    return 2;
}
