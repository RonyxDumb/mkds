#include "01/code_0219d50c.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b47d8.h"

void LoadSelectBattleStageData(void) {
    void *v1;
    LoadedPartPointer v;
    v1 = FindSceneFile("mg/select_battle_stage_m_b.ncgr");
    LoadNcgrData(&v.mNcgr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_00.nscr");
    LoadNscrData(&v.mNscr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_01.nscr");
    LoadNscrData(&v.mNscr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_02.nscr");
    LoadNscrData(&v.mNscr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_b.nclr");
    LoadNclrData(&v.mNclr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m.nce.ncgr");
    LoadNcgrData2(&v.mNcgr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m.nce.ncer");
    LoadNcerData(&v.mNcer, v1);
    v1 = FindSceneFile("mg/select_battle_stage_m_o.nclr");
    LoadNclrData(&v.mNclr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_s.nce.ncgr");
    LoadNcgrData2(&v.mNcgr, v1);
    v1 = FindSceneFile("mg/select_battle_stage_s.nce.ncer");
    LoadNcerData(&v.mNcer, v1);
    v1 = FindSceneFile("mg/select_battle_stage_s_o.nclr");
    LoadNclrData(&v.mNclr, v1);
}
