#include "01/code_021a5140.h"
#include "01/code_02184f7c.h"
#include "01/code_021928c8.h"
#include "01/code_02181000.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02192000.h"
#include "01/code_021a6000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020391d4.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ca6c4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_02180ce8.h"
#include "03/code_021b94b8.h"
#include "code_0214d018.h"

void InitEmblem(void) {
    DisplaySettingsDesc unk;
    EmblemRecord *p;

    gEmblem = heap_alloc(proc_getHeap(proc_getCurrent()), 0x10c0);
    InitDisplaySettingsDesc(&unk);
    unk.mUnk_00[3] = 1;
    unk.mMainBgMode = 0;
    unk.mUnk_0a = 1;
    unk.mUnk_00[1] = 0x11;
    unk.mUnk_0e[4] = 3;
    unk.mUnk_0e[5] = 0x10;
    unk.mUnk_0e[0] = 0x20;
    unk.mUnk_0e[1] = 0x40;
    unk.mSubBgMode = 1;
    unk.mUnk_00[2] = 0x10;
    unk.mUnk_0e[7] = 4;
    unk.mUnk_0e[8] = 8;
    dc_setDisplayConfig(dc_createDisplayConfig(proc_getHeap(proc_getCurrent()), &unk));
    g2du_unpackPaletteData(&gEmblem->mEmblemMONclr, (arc_getSceneArcFile("emblem_m_o.NCLR")));
    g2du_unpackCharacterData(&gEmblem->mEmblemMONcgr, (arc_getSceneArcFile("emblem_m_o.NCGR")));
    g2du_unpackCellBankData(&gEmblem->mEmblemMNcer, arc_getSceneArcFile("emblem_m.NCER"));
    g2du_unpackAnimBank(&gEmblem->mEmblemMNanr, arc_getSceneArcFile("emblem_m.NANR"));
    gEmblem->mEmblemMLld = CreateLld("emblem_m.lld", gEmblem->mEmblemMNcer, gEmblem->mEmblemMNanr);
    g2du_unpackPaletteData(&gEmblem->mEmblemMBNclr, (arc_getSceneArcFile("emblem_m_b.NCLR")));
    g2du_unpackCharacterDataBG(&gEmblem->mEmblemMBNcgr, (arc_getSceneArcFile("emblem_m_b.NCGR")));
    g2du_unpackScreenData(&gEmblem->mEmblemMNscr, (arc_getSceneArcFile("emblem_m.NSCR")));
    g2du_unpackScreenData(&gEmblem->mEmblemMBgNscr, (arc_getSceneArcFile("emblem_m_bg.NSCR")));
    g2du_unpackPaletteData(&gEmblem->mEmblemSONclr, (arc_getSceneArcFile("emblem_s_o.NCLR")));
    g2du_unpackCharacterData(&gEmblem->mEmblemSONcgr, (arc_getSceneArcFile("emblem_s_o.NCGR")));
    g2du_unpackCellBankData(&gEmblem->mEmblemSNcer, arc_getSceneArcFile("emblem_s.NCER"));
    g2du_unpackAnimBank(&gEmblem->mEmblemSNanr, arc_getSceneArcFile("emblem_s.NANR"));
    gEmblem->mEmblemSLld = CreateLld("emblem_s.lld", gEmblem->mEmblemSNcer, gEmblem->mEmblemSNanr);
    gEmblem->mEmblemTemplateSLld = CreateLld("emblem_template_s.lld", gEmblem->mEmblemSNcer, gEmblem->mEmblemSNanr);
    g2du_unpackPaletteData(&gEmblem->mEmblemSBNclr, (arc_getSceneArcFile("emblem_s_b.NCLR")));
    g2du_unpackCharacterDataBG(&gEmblem->mEmblemSBNcgr, (arc_getSceneArcFile("emblem_s_b.NCGR")));
    g2du_unpackCharacterDataBG(&gEmblem->mEmblemTemplateBNcgr, (arc_getSceneArcFile("emblem_template_b.NCGR")));
    g2du_unpackScreenData(&gEmblem->mEmblemSTemplateFrameNscr, (arc_getSceneArcFile("emblem_s_template_frame.NSCR")));
    g2du_unpackScreenData(&gEmblem->mEmblemSToolNscr, (arc_getSceneArcFile("emblem_s_tool.NSCR")));
    g2du_unpackScreenData(&gEmblem->mEmblemSBgNscr, (arc_getSceneArcFile("emblem_s_bg.NSCR")));
    g2du_unpackScreenData(&gEmblem->mEmblemSTemplateDarkNscr, (arc_getSceneArcFile("emblem_s_template_dark.NSCR")));
    g2du_unpackCharacterData(&gEmblem->mEmblemCameraSONcgr, (arc_getSceneArcFile("emblem_camera_s_o.NCGR")));
    g2du_unpackCellBankData(&gEmblem->mEmblemCameraSNcer, arc_getSceneArcFile("emblem_camera_s.NCER"));
    g2du_unpackAnimBank(&gEmblem->mEmblemCameraSNanr, arc_getSceneArcFile("emblem_camera_s.NANR"));
    gEmblem->mEmblemCameraSLld =
        CreateLld("emblem_camera_s.lld", gEmblem->mEmblemCameraSNcer, gEmblem->mEmblemCameraSNanr);
    g2du_unpackCharacterDataBG(&gEmblem->mEmblemCameraSBNcgr, (arc_getSceneArcFile("emblem_camera_s_b.NCGR")));
    g2du_unpackScreenData(&gEmblem->mEmblemCameraSDSNscr, (arc_getSceneArcFile("emblem_camera_s_DS.NSCR")));
    g2du_unpackScreenData(&gEmblem->mEmblemCameraSBgNscr, (arc_getSceneArcFile("emblem_camera_s_bg.NSCR")));
    CreateEmblemInput();
    func_02078c58(proc_getHeap(proc_getCurrent()));
    echoi_init();
    oam_clearResetBuffers(&gEmblem->mUnk_0000, &gEmblem->mUnk_0404);
    func_ov001_021a6238(0x40, 0x10, 0x20, 0x80, 0x10);
    p = gSaveData->mEmblemRecord;
    if (p->mFilled) {
        MI_CpuCopy8(p->mEmblemData, gEmblem->mUnk_087c, 0x200);
        SplitBytesIntoNibbleTiles(gEmblem->mUnk_087c, gEmblem->mUnk_0c7c, GetEmblemGridSide());
        SetEmblemGridCells(gEmblem->mUnk_0c7c);
        SwapEmblemGridCells();
        SetEmblemGridCells(gEmblem->mUnk_0c7c);
        ResetEmblemGridChanges();
    }
    func_ov001_021a63cc(2);
    func_ov001_021a63c0(1);
    func_ov001_021a63a8(0);
    func_ov001_021a6388(0);
    func_ov001_021a6350(GetLldEntryX(GetLldEntry(gEmblem->mEmblemSLld, 0)),
                        GetLldEntryY(GetLldEntry(gEmblem->mEmblemSLld, 0)));
    func_ov001_02185018(GetLldEntry(gEmblem->mEmblemSLld, 14), 1);
    func_ov001_02185018(GetLldEntry(gEmblem->mEmblemSLld, 12), 0);
    func_ov001_02185018(GetLldEntry(gEmblem->mEmblemSLld, 10), 0);
    func_ov001_02185018(GetLldEntry(gEmblem->mEmblemSLld, 23), 2);
    func_ov001_02185018(GetLldEntry(gEmblem->mEmblemSLld, 1), -1);
    func_ov001_02185018(GetLldEntry(gEmblem->mEmblemSLld, 2), -1);
    func_ov001_02185018(GetLldEntry(gEmblem->mEmblemSLld, 3), -1);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 14), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 15), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 16), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 17), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 18), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 19), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 20), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 21), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 22), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 23), -12, -12, 12, 12);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 27), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 28), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 29), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 30), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 31), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 32), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 33), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 34), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 35), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 36), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 37), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 38), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 39), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 40), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 41), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 42), -12, -11, 11, 11);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 25), -32, -20, 32, 20);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemSLld, 26), -32, -20, 32, 20);
    SetLldEntryBounds(GetLldEntry(gEmblem->mEmblemTemplateSLld, 1), -52, -15, 52, 15);
    gEmblem->mUnk_10ac = TRUE;
    gEmblem->mUnk_10b0 = FALSE;
    gEmblem->mUnk_10bc = 6;
}
