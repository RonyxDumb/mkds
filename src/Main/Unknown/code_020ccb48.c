#include "Main/Unknown/code_020ccb48.h"
#include "Main/Unknown/code_020467d0.h"

#include "Main/Unknown/code_020ccb78.h"
#include "Main/Unknown/code_020ccbb8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0203ba70.h"
#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on
void SetNextGrandPrixEntries(void) {
    u8 i;
    s32 a;
    s32 b;
    u32 characterIndex;
    u32 kartIndex;

    a = func_020ae3b4(7) + 1;
    b = func_020ae3b4(6) + 1;
    if (a <= b) {
        b++;
    }
    SetGivenCharacterAndKart(gMenuSceneState->mUnk_954, 0, menu_getRaceConfig()->mEntries[0].mCharacterIndex,
                             menu_getRaceConfig()->mEntries[0].mKartIndex);
    PickRandomCharactersAndKarts(gMenuSceneState->mUnk_954);
    rconf_setDriverConfigNext(0, menu_getRaceConfig()->mEntries[0].mCharacterIndex, menu_getRaceConfig()->mEntries[0].mKartIndex, 0,
                     -1, 3);
    for (i = 1; i < 8; i++) {
        GetEntryCharacterAndKart(gMenuSceneState->mUnk_954, i, &characterIndex, &kartIndex);
        rconf_setDriverConfigNext(i, characterIndex, kartIndex, 1, -1, i == a ? 0 : i == b ? 1 : 3);
    }
}
#pragma thumb off

#pragma thumb on

void SetNextTimeAttackEntries(void) {
    u8 entryIndex;
    RaceSetupCopy *setupCopy;
    RaceSetupCopy *setupCopyForKart;
    setupCopy = menu_getRaceConfig();
    setupCopyForKart = menu_getRaceConfig();
    rconf_setDriverConfigNext(0, setupCopy->mEntries[0].mCharacterIndex, setupCopyForKart->mEntries[0].mKartIndex, 0, 0xffffffff,
                     3);
    entryIndex = 1;
    do {
        SetNextRaceEntryNone(entryIndex);
        entryIndex = entryIndex + 1;
    } while (entryIndex < 8);
}

#pragma thumb off

void SetNextRaceEntryNone(u32 entryIndex) {
    rconf_setDriverConfigNext(entryIndex, 0xffffffff, 0xffffffff, 4, 0xffffffff, 3);
}
