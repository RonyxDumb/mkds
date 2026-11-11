#include "01/code_0218affc.h"

void StartBombKingEffectAndSound(Unk02188950 *mapObject) {
    StartEffectAtRowHeight(mapObject, (0x00002000u), 0, (0x000003aeu), (0x00000410u), 0);
    StartMapObjectSound(&mapObject->mUnk_000, (0x00000236u));
}
