#include "01/code_02188260.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_020a12b8.h"

u32 IncrementHitCountAndCheckLimit(MissionRunMapObject *mapObject) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunCountForKind7();
    }
    mapObject->mUnk_0ac++;
    if (mapObject->mUnk_0ac >= mapObject->mPrm->mUnk_000) {
        mapObject->mUnk_0ac = mapObject->mPrm->mUnk_000;
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            EliminateKartsUntilWinnerDecided();
        }
        return 1;
    }
    return 0;
}
