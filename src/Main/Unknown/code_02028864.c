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
#include "Main/Unknown/code_02036820.h"
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
void InitSelectKart(void *a, s32 b, void *c, void *d) {
    void *h;
    CellFileSet *p;
    CellFileSet e;
    CellFileSet f;
    SelectKart *g;
    s32 i;
    s32 m;
    s32 n;
    u32 v;
    void *w;
    h = CreateFrmHeapFromMaxFree(a);
    gSelectKart = HeapAlloc(h, 0x118);
    func_02028e00(gSelectKart, 0x118);
    gSelectKart->mHeap = h;
    gSelectKart->mMode = b;
    gSelectKart->mTouchRect = -1;
    switch (GetRaceSetupCopy()->mUnk_108) {
        case 1:
            SetupInterpolation(&gSelectKart->mInterpolations[0], 1, 10, -0x80, 0);
            SetupInterpolation(&gSelectKart->mInterpolations[2], 1, 10, 0x60, 0);
            break;
        case 0:
            SetupInterpolation(&gSelectKart->mInterpolations[0], 0, 10, -0x80, 0);
            SetupInterpolation(&gSelectKart->mInterpolations[2], 0, 10, 0x60, 0);
            if (func_020280dc() == 0) {
                StartKartModelMenuBg0Increase();
                func_02077f48(0);
            }
            break;
    }
    SetupInterpolation(&gSelectKart->mInterpolations[1], 0, 10, -0x40, 0);
    SetupInterpolation(&gSelectKart->mInterpolations[3], 0, 10, 0x40, 0);
    SetupInterpolation(&gSelectKart->mInterpolations[4], 0, 10, -0xc0, 0);
    gSelectKart->mUnk_080 = c;
    gSelectKart->mUnk_084 = d;
    if (gSelectKart->mMode != 0 || GetRaceSetupCopy()->mMode == 3 || GetRaceSetupCopy()->mMode == 2) {
        v = 1;
    } else {
        v = 0;
    }
    gSelectKart->mUnk_104 = v;
    if (gSelectKart->mUnk_104 != FALSE) {
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
            gSelectKart->mEntryIndex = GetRaceSetupCopyEntryIndex();
            break;
    }
    if (func_020280dc() == 0) {
        gSelectKart->mKartSelectMessages = FindFileInLoadedArchives(gKartSelectBmgName);
        gSelectKart->mUnk_098 = CreateKartAppear(gSelectKart->mHeap);
    }
    g = gSelectKart;
    g->mCharacterIndex = GetRaceSetupCopy()->mEntries[g->mEntryIndex].mCharacterIndex;
    g = gSelectKart;
    g->mKartIndex = GetRaceSetupCopy()->mEntries[g->mEntryIndex].mKartIndex;
    if (gSelectKart->mCharacterIndex == -1) {
        gSelectKart->mCharacterIndex = 0;
    }
    if (gSelectKart->mKartIndex == -1) {
        gSelectKart->mKartIndex = 0;
    }
    GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mKartIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectKart->mEntryIndex].mUnk_14 = 0;
    gSelectKart->mKartTableIndex = FindKartTableIndex(gSelectKart->mKartIndex);
    if (func_020280dc() == 0) {
        g = gSelectKart;
        if (g->mUnk_104 == FALSE) {
            p = &g->mSelectCharacterGpMParts;
            LocateCellFileSet(p, gSelectCharacterGpMNcgrName2, gSelectCharacterGpMNcerName2,
                              gSelectCharacterGpMONclrName2, gSelectCharacterGpMBnclName2, NULL, NULL,
                              FindFileInLoadedArchives);
            func_02025a50(0, gSelectKart->mHeap, p);
            LocateCellFileSet(&e, gSelectCharacterGpTitleMNcgrName2, gSelectCharacterGpTitleMNcerName2, NULL,
                              gSelectCharacterGpTitleMBnclName2, NULL, NULL, FindFileInLoadedArchives);
            QueueCellChars(1, e.mCells, e.mChars, e.mCellLayout, 0, 0, p->mCells, p->mCellLayout);
            LocateCellFileSet(&f, gSelectCharacterGpNameMNcgrName2, gSelectCharacterGpNameMNcerName2, NULL,
                              gSelectCharacterGpNameMBnclName2, NULL, NULL, FindFileInLoadedArchives);
            QueueCellChars(data_usa_021537dc[gSelectKart->mCharacterIndex], f.mCells, f.mChars, f.mCellLayout, 0, 2,
                           p->mCells, p->mCellLayout);
            QueueCellChars(data_usa_021537dc[gSelectKart->mCharacterIndex], f.mCells, f.mChars, f.mCellLayout, 0, 1,
                           p->mCells, p->mCellLayout);
        }
    }
    if (func_020280dc() == 0) {
        func_020258d4(1, &gSelectKart->mSelectKartSBParts, gSelectKartSBNcgrName, gSelectKartSBNclrName,
                      gSelectKartSNscrName, 3, FindFileInLoadedArchives);
    }
    if (func_020280dc() == 0) {
        n = GX_GetSizeOfSubOBJ();
        p = &gSelectKart->mSelectKartSParts;
        LocateCellFileSet(p, gSelectKartSNcgrName, gSelectKartSNcerName, gSelectKartSONclrName, gSelectKartSBnclName,
                          gSelectKartSBnllName, gSelectKartSBnblName, FindFileInLoadedArchives);
        func_02025a50(1, gSelectKart->mHeap, p);
        for (i = 0; i < 9; i++) {
            n -= func_02025a00(1, gSelectKart->mHeap, p, &data_usa_021537f4[i], n);
        }
        for (i = 0; i < 6; i++) {
            w = GetBmgEntry(gSelectKart->mKartSelectMessages, data_usa_021537f4[i].mUnk_08);
            n = data_usa_021537f4[i].mUnk_00;
            func_0212426c(1, n, p->mLabelLayout, w, p->mCellLayout, p->mCellTable);
            func_02124094(n, 1, p->mLabelLayout, p->mCellTable, p->mCellLayout);
        }
        w = GetBmgEntry(FindFileInLoadedArchives(gCommonBmgName2), data_usa_021537f4[6].mUnk_08);
        i = data_usa_02153834[4];
        func_0212426c(1, i, p->mLabelLayout, w, p->mCellLayout, p->mCellTable);
        SetLabelPaletteIndex(i, 1, p->mLabelLayout, p->mCellTable, p->mCellLayout);
        InitPaletteBlend(gSelectKart->mHeap, p->mPalette, 1);
        p->mCellTable[2].mVisible = 0;
        p->mCellTable[3].mVisible = p->mCellTable[2].mVisible;
    } else {
        InitSelectRaceRuleWait(gSelectKart->mHeap, gSelectKart->mUnk_084);
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
        ClearNonParticipantKartIndices();
    }
    FrmHeapShrinkInParent(h);
}
#pragma thumb off
