#include "01/code_021a6430.h"

#include "types.h"
#include "01/code_021a5140.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02180ce8.h"
#include "01/code_02180cb4.h"
#include "01/unk_021ca000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a7000.h"
#include "code_0212df7c.h"

void LoadMissionRunBossIconData(void) {
    void *v1;
    Ncgr *v2;
    Unk02021dc8 *v3;
    Nclr *v4[1];
    v2 = NULL;
    v3 = NULL;
    v4[0] = NULL;
    v1 = arc_getSceneArcFile(gMissionRunBossIconSNcgrName);
    g2du_unpackCharacterDataBG(&v2, v1);
    v1 = arc_getSceneArcFile(gMissionRunBossIconSNcerName);
    g2du_unpackCellBankData(&v3, v1);
    v1 = arc_getSceneArcFile(gMissionRunBossIconSONclrName);
    g2du_unpackPaletteData(v4, v1);
}

void CreateMissionRunBossIcon(void *a) {
    gMissionRunBossIcon = heap_alloc(a, 0x10);
    g2du_getCharacterData(&gMissionRunBossIcon->mNcgr, arc_getSceneArcFile(gMissionRunBossIconSNcgrName));
    g2du_getCellBankData(&gMissionRunBossIcon->mNcer, arc_getSceneArcFile(gMissionRunBossIconSNcerName));
    g2du_getPaletteData((Nclr **) &gMissionRunBossIcon->mNclr, arc_getSceneArcFile(gMissionRunBossIconSONclrName));
    gMissionRunBossIcon->mBncl = arc_getSceneArcFile(gMissionRunBossIconSBnclName);
}

void func_ov001_021a64a0(void) {
    *(u32 *) &gMissionRunBossIcon = 0;
}

void QueueMissionRunBossIcon(s32 a, s32 flagB, void *c, void *d, u32 e, u16 f, s32 flagG) {
    s32 v0 = 14;
    MissionRunBossIcon *p;
    u8 *dst;
    s32 v1;

    if (flagG != 0) {
        if (flagG == 1) {
            v0 = 30;
        }
    }
    p = gMissionRunBossIcon;
    jn_ui_fillPlaceholder(data_ov001_021a7664[a], p->mNcer, p->mNcgr, p->mBncl, flagG, e, (c), (d));
    dst = gMissionRunBossIcon->mNclr->mUnk_0c;
    if (flagB != 0) {
        v1 = data_ov001_021a7674[a];
    } else {
        v1 = 7;
    }
    NNS_GfdRegisterNewVramTransferTask(v0, f << 5, dst + (v1 << 5), 32);
}
