#include "Main/Unknown/code_02028864.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b928.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

#pragma thumb on
void SPM_LoadKartSelectionMenu(void *a, s32 b, void *c, void *d) {
    void *h;
    Unk02174e50_24 *p;
    Unk02174e50_24 e;
    Unk02174e50_24 f;
    SelectKart *g;
    s32 i;
    s32 m;
    s32 n;
    u32 v;
    void *w;
    h = heap_createSubFrmHeap(a);
    gSelectKart = heap_alloc(h, 0x118);
    func_02028e00(gSelectKart, 0x118);
    gSelectKart->mHeap = h;
    gSelectKart->mMode = b;
    gSelectKart->mTouchRect = -1;
    switch (menu_getRaceConfig()->field108) {
        case 1:
            interp_init(&gSelectKart->mInterpolations[0], 1, 10, -0x80, 0);
            interp_init(&gSelectKart->mInterpolations[2], 1, 10, 0x60, 0);
            break;
        case 0:
            interp_init(&gSelectKart->mInterpolations[0], 0, 10, -0x80, 0);
            interp_init(&gSelectKart->mInterpolations[2], 0, 10, 0x60, 0);
            if (func_020280dc() == 0) {
                StartKartModelMenuBg0Increase();
                func_02077f48(0);
            }
            break;
    }
    interp_init(&gSelectKart->mInterpolations[1], 0, 10, -0x40, 0);
    interp_init(&gSelectKart->mInterpolations[3], 0, 10, 0x40, 0);
    interp_init(&gSelectKart->mInterpolations[4], 0, 10, -0xc0, 0);
    gSelectKart->field80 = c;
    gSelectKart->field84 = d;
    if (gSelectKart->mMode != 0 || menu_getRaceConfig()->mMode == 3 || menu_getRaceConfig()->mMode == 2) {
        v = 1;
    } else {
        v = 0;
    }
    gSelectKart->field104 = v;
    if (gSelectKart->field104 != FALSE) {
        switch (gSelectKart->mMode) {
            case 0:
                m = 0;
                break;
            case 1:
                m = 1;
                break;
            case 2:
                m = 2;
                break;
        }
        SetupPlayerEntryList(m, PLAYER_ENTRY_LIST_KART);
    }
    switch (gSelectKart->mMode) {
        case 0:
            gSelectKart->mEntryIndex = 0;
            break;
        case 1:
            gSelectKart->mEntryIndex = GetOwnEntryIndex();
            break;
        case 2:
            gSelectKart->mEntryIndex = menu_getRaceConfigField10C();
            break;
    }
    if (func_020280dc() == 0) {
        gSelectKart->mKartSelectMessages = arc_get2dArcFile(aKart_select_bmg);
        gSelectKart->field98 = CreateKartAppear(gSelectKart->mHeap);
    }
    g = gSelectKart;
    g->mCharacterIndex = menu_getRaceConfig()->mEntries[g->mEntryIndex].mCharacterIndex;
    g = gSelectKart;
    g->mKartIndex = menu_getRaceConfig()->mEntries[g->mEntryIndex].mKartIndex;
    if (gSelectKart->mCharacterIndex == -1) {
        gSelectKart->mCharacterIndex = 0;
    }
    if (gSelectKart->mKartIndex == -1) {
        gSelectKart->mKartIndex = 0;
    }
    menu_getRaceConfig()->mEntries[gSelectKart->mEntryIndex].mKartIndex = -1;
    menu_getRaceConfig()->mEntries[gSelectKart->mEntryIndex].field14 = 0;
    gSelectKart->mKartTableIndex = FindKartTableIndex(gSelectKart->mKartIndex);
    if (func_020280dc() == 0) {
        g = gSelectKart;
        if (g->field104 == FALSE) {
            p = &g->mSelectCharacterGpMParts;
            mutil2_loadLayout(p, aSelect_character_gp_m_nce_ncgr_1, aSelect_character_gp_m_nce_ncer_1,
                              aSelect_character_gp_m_o_nclr_1, aSelect_character_gp_m_bncl_0, NULL, NULL,
                              arc_get2dArcFile);
            mutil2_initLayout(0, gSelectKart->mHeap, p);
            mutil2_loadLayout(&e, aSelect_character_gp_title_m_nce_ncg_1, aSelect_character_gp_title_m_nce_nce_1, NULL,
                              aSelect_character_gp_title_m_bncl_0, NULL, NULL, arc_get2dArcFile);
            jn_ui_fillPlaceholder(1, e.field8, e.field0, e.fieldC, 0, 0, p->field8, p->fieldC);
            mutil2_loadLayout(&f, aSelect_character_gp_name_m_nce_ncgr_1, aSelect_character_gp_name_m_nce_ncer_1, NULL,
                              aSelect_character_gp_name_m_bncl_0, NULL, NULL, arc_get2dArcFile);
            jn_ui_fillPlaceholder(data_021537dc[gSelectKart->mCharacterIndex], f.field8, f.field0, f.fieldC, 0, 2,
                           p->field8, p->fieldC);
            jn_ui_fillPlaceholder(data_021537dc[gSelectKart->mCharacterIndex], f.field8, f.field0, f.fieldC, 0, 1,
                           p->field8, p->fieldC);
        }
    }
    if (func_020280dc() == 0) {
        mutil2_initBgGraphics(1, &gSelectKart->mSelectKartSBParts, aSelect_kart_s_b_ncgr_0, aSelect_kart_s_b_nclr_0,
                      aSelect_kart_s_nscr_0, 3, arc_get2dArcFile);
    }
    if (func_020280dc() == 0) {
        n = GX_GetSizeOfSubOBJ();
        p = &gSelectKart->mSelectKartSParts;
        mutil2_loadLayout(p, aSelect_kart_s_nce_ncgr_0, aSelect_kart__3, aSelect_kart__2, aSelect_kart__1,
                          aSelect_kart__0, aSelect_kart_s_, arc_get2dArcFile);
        mutil2_initLayout(1, gSelectKart->mHeap, p);
        for (i = 0; i < 9; i++) {
            n -= mutil2_initLabel(1, gSelectKart->mHeap, p, &data_021537f4[i], n);
        }
        for (i = 0; i < 6; i++) {
            w = jn_msg_getMessage(gSelectKart->mKartSelectMessages, data_021537f4[i].field8);
            n = data_021537f4[i].field0;
            jn_ui_212426C(1, n, p->field14, w, p->fieldC, p->field18);
            jn_ui_setLabelPriority(n, 1, p->field14, p->field18, p->fieldC);
        }
        w = jn_msg_getMessage(arc_get2dArcFile(aCommon_bmg_14), data_021537f4[6].field8);
        i = data_02153834[4];
        jn_ui_212426C(1, i, p->field14, w, p->fieldC, p->field18);
        jn_ui_setLabelColorParam(i, 1, p->field14, p->field18, p->fieldC);
        InitPaletteBlend(gSelectKart->mHeap, (Nclr *) p->field4, 1);
        p->field18[2].mVisible = 0;
        p->field18[3].mVisible = p->field18[2].mVisible;
    } else {
        InitSelectRaceRuleWait(gSelectKart->mHeap, gSelectKart->field84);
        func_0211f394();
    }
    RefreshKartMenuParamElements();
    func_02029330();
    func_02028f20();
    if (func_020280dc() == 0) {
        RequestSelectReturnState1();
    }
    if (func_0202811c() == 2) {
        SetSelectReturnDisplayBitOn();
    }
    if (gSelectKart->mMode == 0) {
        func_02117060();
    }
    heap_adjustSubFrmHeap(h);
}
#pragma thumb off
