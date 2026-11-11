#include "01/code_02184e18.h"
#include "01/code_02184f7c.h"

void StartBossDonketuStepEffectFirst(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0x000008cdu, 0, 0x0000119au, 0x00000413u, 0);
}

void StartBossDonketuStepEffectSecond(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0xfffff733u, 0, 0x0000119au, 0x00000413u, 0);
}

void StartKingIceDonketuStepEffectFirst(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0xfffff000u, 0, 0x00001333u, 0x00000444u, 0);
}

void StartKingIceDonketuStepEffectSecond(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x0000020fu);
    ReleaseEffects(mapObject);
    StartEffectAtRowHeight(mapObject, 0x00001000u, 0, 0x00001333u, 0x00000444u, 0);
}

void SetDonketuStepSoundCallbacks(Unk02188950 *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 0x19, StartDonketuStepSoundFirst, 0x36, StartDonketuStepSoundSecond);
}

void SetDonketuStepEffectCallbacks(u16 *mapObject) {
    if (*mapObject == (0x000001f5u)) {
        SetTwoAnimationFrameCallbacks((Unk02188950 *) mapObject, 0x19, StartBossDonketuStepEffectFirst, 0x36,
                                      StartBossDonketuStepEffectSecond);
        return;
    }
    if (*mapObject == (0x000001f6u)) {
        SetTwoAnimationFrameCallbacks((Unk02188950 *) mapObject, 9, StartKingIceDonketuStepEffectFirst, 0x26,
                                      StartKingIceDonketuStepEffectSecond);
    }
}
