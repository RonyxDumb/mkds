#include "Main/Unknown/code_02067cb0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_02077bc0.h"

int CollideKartWithMapObjectResponse3(Kart *kart, s32 *result, MapObject *mapObject) {
    if (kart->mVelocityLength > 0x3000 || (mapObject->mFlags & 0x200)) {
        if (TrySpinKart(kart, 1, 0)) {
            if (kart->mKartModelsEntry->mKartModelHidden == 0) {
                StartEffect(0xc, &kart->mPos);
                StartEffect(0xd, &kart->mPos);
                StartEffect(0xe, &kart->mPos);
            }
            if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                GetEntryKartCounters()->mMapObjectHitCount++;
            }
        }
        *result = 3;
    } else {
        *result = 2;
    }
    return 0xb;
}

int CollideKartWithMapObjectResponse4(Kart *kart, s32 *result, MapObject *mapObject) {
    if (kart->mVelocityLength > 0x3000 || (mapObject->mFlags & 0x200)) {
        if (TrySpinKart(kart, 2, 0)) {
            if (kart->mKartModelsEntry->mKartModelHidden == 0) {
                StartEffect(0xc, &kart->mPos);
                StartEffect(0xd, &kart->mPos);
                StartEffect(0xe, &kart->mPos);
            }
            if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                GetEntryKartCounters()->mMapObjectHitCount++;
            }
        }
        *result = 4;
    } else {
        *result = 2;
    }
    return 0xb;
}

int CollideKartWithMapObjectResponse6(Kart *kart, s32 *result, MapObject *mapObject) {
    if (kart->mVelocityLength > 0x3000 || (mapObject->mFlags & 0x200)) {
        if (TrySpinKart(kart, 2, 0)) {
            if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                GetEntryKartCounters()->mMapObjectHitCount++;
            }
            StartKartSpinSideEffects(kart->mIndex);
        }
        *result = 4;
    } else {
        *result = 0;
    }
    return 0;
}

int CollideKartWithMapObjectResponse5(Kart *kart, s32 *result) {
    if (TrySpinKart(kart, 2, 0)) {
        if (kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
            SetupKartFollowEffectWithVelocity(StartEffect(0x4f, &kart->mPos), kart->mIndex, 0x46);
        }
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            GetEntryKartCounters()->mMapObjectHitCount++;
        }
    }
    *result = 5;
    return 0;
}

int CollideKartWithMapObjectResponse7(Kart *kart, s32 *result) {
    if (TryStartKartState3(kart)) {
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            GetEntryKartCounters()->mMapObjectHitCount++;
        }
        kart->mUnk_48 |= 0x20000;
    }
    *result = 7;
    return 2;
}
