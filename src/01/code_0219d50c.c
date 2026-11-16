#include "01/code_0219d50c.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b47d8.h"

void LoadSelectBattleStageData(void) {
    void *v1;
    LoadedPartPointer v;
    v1 = arc_getSceneArcFile("mg/select_battle_stage_m_b.ncgr");
    g2du_unpackCharacterDataBG(&v.mNcgr, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_m_00.nscr");
    g2du_unpackScreenData(&v.mNscr, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_m_01.nscr");
    g2du_unpackScreenData(&v.mNscr, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_m_02.nscr");
    g2du_unpackScreenData(&v.mNscr, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_m_b.nclr");
    g2du_unpackPaletteData(&v.mNclr, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_m.nce.ncgr");
    g2du_unpackCharacterData(&v.mNcgr, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_m.nce.ncer");
    g2du_unpackCellBankData(&v.mNcer, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_m_o.nclr");
    g2du_unpackPaletteData(&v.mNclr, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_s.nce.ncgr");
    g2du_unpackCharacterData(&v.mNcgr, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_s.nce.ncer");
    g2du_unpackCellBankData(&v.mNcer, v1);
    v1 = arc_getSceneArcFile("mg/select_battle_stage_s_o.nclr");
    g2du_unpackPaletteData(&v.mNclr, v1);
}
