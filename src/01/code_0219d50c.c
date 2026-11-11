#include "01/code_0219d50c.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b47d8.h"

void LoadSelectBattleStageData(void) {
    void *v1;
    LoadedPartPointer v;
    v1 = FindSceneFile(gSelectBattleStageMBNcgrName);
    LoadNcgrData(&v.mNcgr, v1);
    v1 = FindSceneFile(gSelectBattleStageM00NscrName);
    LoadNscrData(&v.mNscr, v1);
    v1 = FindSceneFile(gSelectBattleStageM01NscrName);
    LoadNscrData(&v.mNscr, v1);
    v1 = FindSceneFile(gSelectBattleStageM02NscrName);
    LoadNscrData(&v.mNscr, v1);
    v1 = FindSceneFile(gSelectBattleStageMBNclrName);
    LoadNclrData(&v.mNclr, v1);
    v1 = FindSceneFile(gSelectBattleStageMNcgrName);
    LoadNcgrData2(&v.mNcgr, v1);
    v1 = FindSceneFile(gSelectBattleStageMNcerName);
    LoadNcerData(&v.mNcer, v1);
    v1 = FindSceneFile(gSelectBattleStageMONclrName);
    LoadNclrData(&v.mNclr, v1);
    v1 = FindSceneFile(gSelectBattleStageSNcgrName);
    LoadNcgrData2(&v.mNcgr, v1);
    v1 = FindSceneFile(gSelectBattleStageSNcerName);
    LoadNcerData(&v.mNcer, v1);
    v1 = FindSceneFile(gSelectBattleStageSONclrName);
    LoadNclrData(&v.mNclr, v1);
}
