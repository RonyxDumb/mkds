#include "Main/Unknown/code_0208bf6c.h"
#include "Main/Unknown/code_02090348.h"
#include "Main/Unknown/code_02077bc0.h"

void enmy_initMgEnemy(KartAi *kartAi, s32 kartIndex) {
    Kart *kart;
    kart = driver_getById(kartIndex);
    mgen_init(kartAi, kart);
    SetupBattleKartAiSpeedLimit(&kartAi->mAiSpeedLimit, kartAi);
    mgenit_init(&kartAi->mItemUse);
    PickBattleKartAiRaceStart(kartAi, &kartAi->fieldE8);
}

void ResetKartAiForBattle(KartAi *kartAi, PointLink *link) {
    ResetBattleKartAiAtPointLink(kartAi, link);
    SetupBattleKartAiSpeedLimit(&kartAi->mAiSpeedLimit, kartAi);
    mgenit_init(&kartAi->mItemUse);
}
