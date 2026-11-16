#include "01/code_02193c5c.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_02111488.h"
#include "code_0201ea58.h"
#include "01/code_02195000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02111494.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Ui/KartIcon.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02117218.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02116000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0205f000.h"
#include "registers.h"

RecordGpx *gRecordGpx;

void LocateAndQueueRecordGpx(void) {
    Nclr *l0 = NULL;
    Ncgr *l4 = NULL;
    Nclr *l8 = NULL;
    Nscr *lc = NULL;
    Nclr *l10 = NULL;
    Ncgr *l14 = NULL;
    Nclr *l18 = NULL;
    u16 *x;

    g2du_getCharacterData(&gRecordGpx->mRecordGpxMNcgr, arc_getSceneArcFile(gRecordGpxMNcgrName));
    g2du_getCellBankData(&gRecordGpx->mRecordGpxMNcer, arc_getSceneArcFile(gRecordGpxMNcerName));
    g2du_getPaletteData(&l0, arc_getSceneArcFile(gRecordGpxMONclrName));
    gRecordGpx->mRecordGpxMBncl = arc_getSceneArcFile(gRecordGpxMBnclName);
    gRecordGpx->mRecordGpxMBnll = arc_getSceneArcFile(gRecordGpxMBnllName);
    g2du_getCharacterData(&gRecordGpx->mRecordGpxSNcgr, arc_getSceneArcFile(gRecordGpxSNcgrName));
    g2du_getCellBankData(&gRecordGpx->mRecordGpxSNcer, arc_getSceneArcFile(gRecordGpxSNcerName));
    g2du_getPaletteData(&l10, arc_getSceneArcFile(gRecordGpxSONclrName));
    gRecordGpx->mRecordGpxSBncl = arc_getSceneArcFile(gRecordGpxSBnclName);
    gRecordGpx->mRecordGpxSBnbl = arc_getSceneArcFile(gRecordGpxSBnblName);
    gRecordGpx->mRecordGpxSBnll = arc_getSceneArcFile(gRecordGpxSBnllName);
    g2du_getCharacterData(&gRecordGpx->mRecordTrophyONcgr, arc_getSceneArcFile(gRecordTrophyONcgrName));
    g2du_getCellBankData(&gRecordGpx->mRecordTrophyONcer, arc_getSceneArcFile(gRecordTrophyONcerName));
    g2du_getPaletteData(&gRecordGpx->mRecordTrophySONclr, arc_getSceneArcFile(gRecordTrophySONclrName));
    gRecordGpx->mRecordTrophySOBncl = arc_getSceneArcFile(gRecordTrophySOBnclName);
    gRecordGpx->mPlayerCharacterMNcgr = m2d_getPortraitNceNcgr(0);
    gRecordGpx->mPlayerCharacterMNcer = m2d_getPortraitNceNcer(0);
    gRecordGpx->mPlayerCharacterMONclr = m2d_getPortraitONclr(0);
    gRecordGpx->mPlayerCharacterMBncl = m2d_getPortraitBncl(0);
    g2du_getCharacterDataBG(&l4, arc_getSceneArcFile(gRecordGpxMBNcgrName));
    g2du_getPaletteData(&l8, arc_getSceneArcFile(gRecordGpxMBNclrName));
    g2du_getScreenData(&lc, arc_getSceneArcFile(gRecordGpxMNscrName));
    g2du_getCharacterDataBG(&l14, arc_getSceneArcFile(gRecordGpxSBNcgrName));
    g2du_getPaletteData(&l18, arc_getSceneArcFile(gRecordGpxSBNclrName));
    g2du_getScreenData(&gRecordGpx->mRecordGpxSNscr, arc_getSceneArcFile(gRecordGpxSNscrName));
    x = l0->mData;
    NNS_GfdRegisterNewVramTransferTask(0x13, 0, gRecordGpx->mRecordGpxMNcgr->mData, gRecordGpx->mRecordGpxMNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0, l0->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(0xe, 0x1c0, (u8 *) x + 0x1c0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, gRecordGpx->mRecordGpxSNcgr->mData, gRecordGpx->mRecordGpxSNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, l10->mData, l10->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(4, 0, l4->mData, l4->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, 0, l8->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(8, 0, lc->mData, lc->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x17, 0, l14->mData, l14->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, l18->mData, 0x40);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, gRecordGpx->mRecordGpxSNscr->mData, gRecordGpx->mRecordGpxSNscr->mDataSize);
    x = gRecordGpx->mRecordTrophySONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(0x1e, data_ov001_021a6604[0] << 5, (u8 *) x + (data_ov001_021a660c[0] << 5), 0x20);
    NNS_GfdRegisterNewVramTransferTask(0x1e, data_ov001_021a6604[1] << 5, (u8 *) x + (data_ov001_021a660c[1] << 5), 0x20);
    NNS_GfdRegisterNewVramTransferTask(0x1e, data_ov001_021a6604[2] << 5, (u8 *) x + (data_ov001_021a660c[2] << 5), 0x20);
}

void SetupRecordGpxValues(s32 a) {
    s32 i;
    s32 k;
    u32 y;
    s32 count;
    s32 z;
    u32 value;
    u16 buf[16];
    u8 *p;

    k = savd_getCupTrophy(data_ov001_021a6740[gRecordGpx->mIndex], data_ov001_021a6694[a]);
    gRecordGpx->mRecordGpxSTable[data_ov001_021a666c[a]].mVisible = 1;
    jn_ui_fillPlaceholder(data_ov001_021a66a4[gRecordGpx->mIndex], (gRecordGpx->mRecordTrophyONcer),
                   (gRecordGpx->mRecordTrophyONcgr), (gRecordGpx->mRecordTrophySOBncl), 1, data_ov001_021a666c[a],
                   (gRecordGpx->mRecordGpxSNcer), (gRecordGpx->mRecordGpxSBncl));
    jn_ui_setCellCparam(data_ov001_021a666c[a], (u8) data_ov001_021a6604[k], gRecordGpx->mRecordGpxSNcer,
                        gRecordGpx->mRecordGpxSBncl);
    k = savd_getCupCharacter(data_ov001_021a6740[gRecordGpx->mIndex], data_ov001_021a6694[a]);
    gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[a][0]].mVisible = 1;
    jn_ui_fillPlaceholder(data_ov001_021a66e4[k], (gRecordGpx->mPlayerCharacterMNcer), (gRecordGpx->mPlayerCharacterMNcgr),
                   (gRecordGpx->mPlayerCharacterMBncl), 1, data_ov001_021a6674[a][0], (gRecordGpx->mRecordGpxSNcer),
                   (gRecordGpx->mRecordGpxSBncl));
    p = gRecordGpx->mPlayerCharacterMONclr->fieldC;
    NNS_GfdRegisterNewVramTransferTask(0x1e, data_ov001_021a6684[a] << 5,
                    p + (GetCellPaletteIndex(data_ov001_021a66e4[k], (gRecordGpx->mPlayerCharacterMNcer),
                                             (gRecordGpx->mPlayerCharacterMBncl))
                         << 5),
                    0x20);
    k = savd_getCupKart(data_ov001_021a6740[gRecordGpx->mIndex], data_ov001_021a6694[a]);
    gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[a][1]].mVisible = 1;
    kic_putIconInLayout(k, gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl, data_ov001_021a6674[a][1],
                  data_ov001_021a668c[a], 1);
    count = gRecordGpx->mRecordGpxSBncl->field6;
    savd_getCupTotalRaceTime(data_ov001_021a6740[gRecordGpx->mIndex], data_ov001_021a6694[a], &value);
    FormatTimeAscii(&value, buf);
    gRecordGpx->mRecordGpxSTable[count + data_ov001_021a6614[a]].mVisible = 1;
    jn_ui_2124224(1, data_ov001_021a6614[a], gRecordGpx->mRecordGpxSBnll, buf, gRecordGpx->mRecordGpxSBncl,
                  gRecordGpx->mRecordGpxSTable, 7);
    y = (u16) savd_getCupRankPoints(data_ov001_021a6740[gRecordGpx->mIndex], data_ov001_021a6694[a]);
    FormatAsciiNumber(y, buf);
    gRecordGpx->mRecordGpxSTable[count + data_ov001_021a662c[a]].mVisible = 1;
    jn_ui_2124248(1, data_ov001_021a662c[a], gRecordGpx->mRecordGpxSBnll, buf, gRecordGpx->mRecordGpxSBncl,
                  gRecordGpx->mRecordGpxSTable, 7);
    for (i = 0; i < 3; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[a][i]].mVisible = 0;
    }
    switch (y) {
        case 0:
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[a][0]].mVisible = 1;
            break;
        case 1:
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[a][1]].mVisible = 1;
            break;
        default:
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[a][2]].mVisible = 1;
            break;
    }
    gRecordGpx->mRecordGpxSTable[count + data_ov001_021a663c[a]].mVisible = 0;
    for (i = 0; i < 3; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a66b4[a][i]].mVisible = 0;
    }
    z = savd_getCupRank(data_ov001_021a6740[gRecordGpx->mIndex], data_ov001_021a6694[a]);
    if (z < 5) {
        gRecordGpx->mRecordGpxSTable[count + data_ov001_021a663c[a]].mVisible = 1;
        jn_ui_212426C(1, data_ov001_021a663c[a], gRecordGpx->mRecordGpxSBnll, data_ov001_021a8280[z],
                      gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSTable);
    } else {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a66b4[a][z - 5]].mVisible = 1;
    }
}

void SetupRecordGpxDashes(s32 a) {
    s32 i;

    gRecordGpx->mRecordGpxSTable[data_ov001_021a666c[a]].mVisible = 0;
    gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[a][0]].mVisible = 0;
    gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[a][1]].mVisible = 0;
    jn_ui_2124224(1, data_ov001_021a6614[a], gRecordGpx->mRecordGpxSBnll, L"--:--:---", gRecordGpx->mRecordGpxSBncl,
                  gRecordGpx->mRecordGpxSTable, 7);
    jn_ui_2124248(1, data_ov001_021a662c[a], gRecordGpx->mRecordGpxSBnll, L"--", gRecordGpx->mRecordGpxSBncl,
                  gRecordGpx->mRecordGpxSTable, 7);
    for (i = 0; i < 3; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[a][i]].mVisible = 0;
    }
    if (a != 3 || func_ov001_02194d04(gRecordGpx->mIndex) != 0) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[a][0]].mVisible = 1;
    }
    for (i = 0; i < 3; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a66b4[a][i]].mVisible = 0;
    }
    jn_ui_212426C(1, data_ov001_021a663c[a], gRecordGpx->mRecordGpxSBnll, L"-", gRecordGpx->mRecordGpxSBncl,
                  gRecordGpx->mRecordGpxSTable);
}

// Stores both offsets and steps both timers; while timer i is above 0 the row data_ov001_021a65fc[i] picks is switched
// on and the row data_ov001_021a6600[i] picks off, and the other way round once it reaches 0.
void AdvanceRecordGpxOffsetTimers(void) {
    s32 i;

    gRecordGpx->mRecordGpxSTable[data_ov001_021a65fc[0]].mOffsetX = -func_020adc64(6 - gRecordGpx->mOffsetTimers[0]);
    gRecordGpx->mRecordGpxSTable[data_ov001_021a65fc[1]].mOffsetX = func_020adc64(6 - gRecordGpx->mOffsetTimers[1]);
    for (i = 0; i < 2; i++) {
        if (gRecordGpx->mOffsetTimers[i] > 0) {
            gRecordGpx->mOffsetTimers[i]--;
            gRecordGpx->mRecordGpxSTable[data_ov001_021a6600[i]].mVisible = 0;
            gRecordGpx->mRecordGpxSTable[data_ov001_021a65fc[i]].mVisible = 1;
        } else {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a6600[i]].mVisible = 1;
            gRecordGpx->mRecordGpxSTable[data_ov001_021a65fc[i]].mVisible = 0;
        }
    }
}

void SetupRecordGpx(void) {
    s32 i;
    s32 n;
    RecordGpx *d;
    void *p;
    u8 v;

    n = gRecordGpx->mRecordGpxSBncl->field6;
    if (func_ov001_02194d04(gRecordGpx->mIndex) != 0) {
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0x3c6, OFFSET_PTR(u8, gRecordGpx->mRecordGpxSNscr, 0xc) + 0x3c6, 0x134);
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[3]].mVisible = 1;
        for (i = 0; i < 3; i++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[3][i]].mVisible = 1;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[3]].mVisible = 1;
        gRecordGpx->mRecordGpxSTable[n + data_ov001_021a6614[3]].mVisible = 1;
        gRecordGpx->mRecordGpxSTable[n + data_ov001_021a662c[3]].mVisible = 1;
        gRecordGpx->mRecordGpxSTable[n + data_ov001_021a663c[3]].mVisible = 1;
    } else {
        NNS_GfdRegisterNewVramTransferTask(0x1b, 0x3c6, (u8 *) gRecordGpx->mZeroBuffer + 0x3c6, 0x134);
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[3]].mVisible = 0;
        for (i = 0; i < 3; i++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[3][i]].mVisible = 0;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[3]].mVisible = 0;
        gRecordGpx->mRecordGpxSTable[n + data_ov001_021a6614[3]].mVisible = 0;
        gRecordGpx->mRecordGpxSTable[n + data_ov001_021a662c[3]].mVisible = 0;
        gRecordGpx->mRecordGpxSTable[n + data_ov001_021a663c[3]].mVisible = 0;
    }
    d = gRecordGpx;
    v = GetCellPaletteIndex(1, (d->mRecordGpxMNcer), (d->mRecordGpxMBncl));
    QueueCupMark(d->mIndex, d->mRecordGpxMNcer, d->mRecordGpxMBncl, 1, v, 0);
    d = gRecordGpx;
    p = jn_msg_getMessage(d->mCommonMessages, data_ov001_021a6720[d->mIndex]);
    jn_ui_212426C(0, 0, gRecordGpx->mRecordGpxMBnll, p, d->mRecordGpxMBncl, d->mRecordGpxMTable);
    for (i = 0; i < 4; i++) {
        if (savd_getIsCupPlayed(data_ov001_021a6740[gRecordGpx->mIndex], data_ov001_021a6694[i]) != 0) {
            SetupRecordGpxValues(i);
        } else {
            SetupRecordGpxDashes(i);
        }
    }
}

void func_ov001_02194d48(void) {
    s32 value;

    gRecordGpx->mIndex++;
    value = gRecordGpx->mIndex;
    if (value >= 8) {
        value = 0;
        gRecordGpx->mIndex = value;
    }
    if (func_ov001_02194c9c(value) == 0) {
        func_ov001_02194d48();
    }
}

void func_ov001_02194d18(void) {
    s32 value;

    gRecordGpx->mIndex--;
    value = gRecordGpx->mIndex;
    if (value < 0) {
        value = 7;
        gRecordGpx->mIndex = value;
    }
    if (func_ov001_02194c9c(value) == 0) {
        func_ov001_02194d18();
    }
}

u32 func_ov001_02194d04(s32 a) {
    return savd_isUnlockBitSet(data_ov001_021a6700[a]);
}

u32 func_ov001_02194c9c(u32 a) {
    u32 result;
    s32 i;

    result = 0;
    switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            return 1;
        case 2:
        case 3:
        case 6:
        case 7:
            for (i = 0; i < 3; i++) {
                result |= savd_isUnlockBitSet(data_ov001_021a6760[a][i]);
            }
            result |= func_ov001_02194d04(a);
            break;
    }
    return result;
}

void func_ov001_02194a50(void) {
    s32 i;
    s32 j;
    s32 count0;
    s32 count1;

    gRecordGpx->mNextState = 0;
    gRecordGpx->mStateFrames = 0;
    gRecordGpx->mBg0Offset = ~0xbf;
    gRecordGpx->mBg3OffsetX = ~0xff;
    count0 = gRecordGpx->mRecordGpxMBncl->field6;
    count1 = gRecordGpx->mRecordGpxSBncl->field6;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = 0x100;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = 0x100;
    gRecordGpx->mRecordGpxMTable[count0].mOffsetX = 0x100;
    gRecordGpx->mRecordGpxSTable[44].mOffsetX = 0x100;
    gRecordGpx->mRecordGpxSTable[45].mOffsetX = 0x100;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a666c[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a666c[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[i][j]].mOffsetX = 0x100;
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[i][j]].mOffsetY = gRecordGpx->mBg3OffsetY;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[count1 + data_ov001_021a6614[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[count1 + data_ov001_021a6614[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[count1 + data_ov001_021a662c[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[count1 + data_ov001_021a662c[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        gRecordGpx->mRecordGpxSTable[count1 + data_ov001_021a663c[i]].mOffsetX = 0x100;
        gRecordGpx->mRecordGpxSTable[count1 + data_ov001_021a663c[i]].mOffsetY = gRecordGpx->mBg3OffsetY;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66b4[i][j]].mOffsetX = 0x100;
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66b4[i][j]].mOffsetY = gRecordGpx->mBg3OffsetY;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[i][j]].mOffsetX = 0x100;
            gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[i][j]].mOffsetY = gRecordGpx->mBg3OffsetY;
        }
    }
    for (i = 0; i < 2; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a65fc[i]].mVisible = 0;
    }
}

void RequestRecordGpxState1AndSetup(void) {
    gRecordGpx->mNextState = 1;
    gRecordGpx->mStateFrames = 0;
    SetupRecordGpx();
}

// Requests state 2: stores mNextState = 2 and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxState2.
void RequestRecordGpxState2(void) {
    gRecordGpx->mNextState = 2;
    gRecordGpx->mStateFrames = 0;
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxState3.
void RequestRecordGpxState3(void) {
    gRecordGpx->mNextState = 3;
    gRecordGpx->mStateFrames = 0;
}

void func_ov001_021949d4(void) {
    gRecordGpx->mNextState = 4;
    gRecordGpx->mStateFrames = 0;
    switch (gRecordGpx->field7C) {
        case 0:
            func_ov001_02194d48();
            break;
        case 1:
            func_ov001_02194d18();
            break;
    }
    SetupRecordGpx();
}

// Requests state 5: stores mNextState = 5 and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxState5.
void RequestRecordGpxState5(void) {
    gRecordGpx->mNextState = 5;
    gRecordGpx->mStateFrames = 0;
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceRecordGpx call copies it to mState
// and runs AdvanceRecordGpxState6.
void RequestRecordGpxState6(void) {
    gRecordGpx->mNextState = 6;
    gRecordGpx->mStateFrames = 0;
}

void InitRecordGpx(void *heap) {
    u32 acc = 0;
    s32 i;
    s32 rem;
    void *p;
    vu16 zero;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x8800;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x5810;
    gRecordGpx = heap_alloc(heap, 0x94);
    gRecordGpx->mHeap = heap;
    gRecordGpx->mState = 0;
    gRecordGpx->mIndex = 0;
    gRecordGpx->field7C = 0;
    gRecordGpx->field88 = FALSE;
    gRecordGpx->field8C = FALSE;
    for (i = 0; i < 2; i++) {
        gRecordGpx->mOffsetTimers[i] = 0;
    }
    LocateAndQueueRecordGpx();
    kic_initForGhost(heap);
    CreateCupMark(heap);
    p = GetRecordMainOam();
    oam_clearResetBuffers(p, GetRecordSubOam());
    jn_ui_initLayout(heap, gRecordGpx->mRecordGpxMBncl, gRecordGpx->mRecordGpxMBnll, &gRecordGpx->mRecordGpxMTable);
    jn_ui_initLayout(heap, gRecordGpx->mRecordGpxSBncl, gRecordGpx->mRecordGpxSBnll, &gRecordGpx->mRecordGpxSTable);
    gRecordGpx->mCommonMessages = arc_get2dArcFile("common.bmg");
    jn_ui_initLabel(heap, 0, gRecordGpx->mRecordGpxMBnll, 200, 16, 0, gRecordGpx->mRecordGpxMNcer,
                    gRecordGpx->mRecordGpxMBncl, gRecordGpx->mRecordGpxMTable, 0x8000);
    rem = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 4; i++) {
        rem -= jn_ui_initLabel(heap, data_ov001_021a6614[i], gRecordGpx->mRecordGpxSBnll, data_ov001_021a661c[i],
                               data_ov001_021a6624[i], i, gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl,
                               gRecordGpx->mRecordGpxSTable, rem);
        rem -= jn_ui_initLabel(heap, data_ov001_021a662c[i], gRecordGpx->mRecordGpxSBnll, data_ov001_021a6664[i],
                               data_ov001_021a6634[i], i + 4, gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl,
                               gRecordGpx->mRecordGpxSTable, rem);
        rem -= jn_ui_initLabel(heap, data_ov001_021a663c[i], gRecordGpx->mRecordGpxSBnll, data_ov001_021a6644[i],
                               data_ov001_021a664c[i], i + 12, gRecordGpx->mRecordGpxSNcer, gRecordGpx->mRecordGpxSBncl,
                               gRecordGpx->mRecordGpxSTable, rem);
    }
    gRecordGpx->mBg3OffsetY = 0;
    for (i = 0; i < 8; i++) {
        acc |= func_ov001_02194d04(i);
    }
    if (acc == 0) {
        gRecordGpx->mBg3OffsetY = 16;
    }
    gRecordGpx->mZeroBuffer = heap_alloc(heap, 0x134);
    zero = 0;
    MIi_CpuClear16(zero, gRecordGpx->mZeroBuffer, 0x134);
    func_ov001_02194a50();
}

void func_ov001_021946d0(void) {
    u32 v;

    kic_free();
    ClearCupMarkPointer();
    gRecordGpx = NULL;
    v = (reg_GX_DISPCNT & 0x1f00) >> 8;
    v &= ~0x11;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (v << 8);
    v = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    v &= ~0x8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (v << 8);
}

void AdvanceRecordGpxState0(void) {
    gRecordGpx->mStateFrames++;
    gRecordGpx->mBg0Offset = mutil_interpolate(1, -192, 0, gRecordGpx->mStateFrames, 10);
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordGpxState1AndSetup();
    }
}

void AdvanceRecordGpxState1(void) {
    s16 v;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    AdvanceRecordGpxOffsetTimers();
    gRecordGpx->mStateFrames++;
    v = mutil_interpolate(1, 0x100, 0, gRecordGpx->mStateFrames, 10);
    gRecordGpx->mBg3OffsetX = v;
    a = gRecordGpx->mRecordGpxMBncl->field6;
    b = gRecordGpx->mRecordGpxSBncl->field6;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = v;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = v;
    gRecordGpx->mRecordGpxMTable[a].mOffsetX = v;
    gRecordGpx->mRecordGpxSTable[0x2c].mOffsetX = v;
    gRecordGpx->mRecordGpxSTable[0x2d].mOffsetX = v;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a666c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = v;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[i][j]].mOffsetX = v;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a6614[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a662c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a663c[i]].mOffsetX = v;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66b4[i][j]].mOffsetX = v;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[i][j]].mOffsetX = v;
        }
    }
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordGpxState2();
    }
}

void AdvanceRecordGpxState2(void) {
    s32 a = -1;
    s32 b = -1;
    InputSlotIndex idx = UNK_02175628_INDEX_8;
    BOOL x1, y1, x2, y2, x3, y3;

    AdvanceRecordGpxOffsetTimers();
    x1 = TRUE;
    y1 = FALSE;
    if (gInputUnits[idx].mHasPair == 0 && gInputUnits[idx].mNoPairCount < 5) {
        y1 = TRUE;
    }
    if (y1 == FALSE && gInputUnits[idx].mHasPair == 0) {
        x1 = FALSE;
    }
    if (x1 != FALSE) {
        a = jn_ui_checkTouch(gRecordGpx->mRecordGpxSBnbl, gInputUnits[idx].mPairX, gInputUnits[idx].mPairY);
    }
    x2 = FALSE;
    y2 = FALSE;
    if (gInputUnits[idx].mHasPair == 0 && gInputUnits[idx].mNoPairCount < 5) {
        y2 = TRUE;
    }
    if (y2 == FALSE && gInputUnits[idx].mPrevHasPair == 0 && gInputUnits[idx].mHasPair != 0) {
        x2 = TRUE;
    }
    if (x2 != FALSE) {
        b = jn_ui_checkTouch(gRecordGpx->mRecordGpxSBnbl, gInputUnits[idx].mPairX, gInputUnits[idx].mPairY);
    }
    if (a != 0) {
        gRecordGpx->field88 = FALSE;
    }
    if (a != 1) {
        gRecordGpx->field8C = FALSE;
    }
    if ((u16) (gInputUnits[idx].mPressedBits & PAD_KEY_B) == 0) {
        x3 = FALSE;
        y3 = FALSE;
        if (gInputUnits[idx].mHasPair == 0 && gInputUnits[idx].mNoPairCount < 5) {
            y3 = TRUE;
        }
        if (y3 == FALSE && gInputUnits[idx].mPrevHasPair == 0 && gInputUnits[idx].mHasPair != 0) {
            x3 = TRUE;
        }
        if (x3 == FALSE || gmenu_checkSelectReturnTouch(gInputUnits[idx].mPairX,
                                                                           gInputUnits[idx].mPairY) == FALSE) {
            goto next;
        }
    }
    RequestRecordGpxState5();
    gRecordGpx->field90 = 0;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    if ((a == 0 && gRecordGpx->field88 != FALSE) || (b == 0 && gRecordGpx->field88 == FALSE) ||
        (u16) (gInputUnits[idx].mBits & PAD_KEY_LEFT) != 0) {
        gRecordGpx->field7C = 1;
        gRecordGpx->mOffsetTimers[0] = 6;
        gRecordGpx->field88 = TRUE;
        RequestRecordGpxState3();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
        return;
    }
    if ((a == 1 && gRecordGpx->field8C != FALSE) || (b == 1 && gRecordGpx->field8C == FALSE) ||
        (u16) (gInputUnits[idx].mBits & PAD_KEY_RIGHT) != 0) {
        gRecordGpx->field7C = 0;
        gRecordGpx->mOffsetTimers[1] = 6;
        gRecordGpx->field8C = TRUE;
        RequestRecordGpxState3();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
    }
}

void AdvanceRecordGpxState3(void) {
    s16 v;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s16 x = 0;

    AdvanceRecordGpxOffsetTimers();
    switch (gRecordGpx->field7C) {
        case 0:
            x = -256;
            break;
        case 1:
            x = 0x100;
            break;
    }
    gRecordGpx->mStateFrames++;
    v = mutil_interpolate(1, 0, x, gRecordGpx->mStateFrames, 10);
    gRecordGpx->mBg3OffsetX = v;
    a = gRecordGpx->mRecordGpxMBncl->field6;
    b = gRecordGpx->mRecordGpxSBncl->field6;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = v;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = v;
    gRecordGpx->mRecordGpxMTable[a].mOffsetX = v;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a666c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = v;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[i][j]].mOffsetX = v;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a6614[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a662c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a663c[i]].mOffsetX = v;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66b4[i][j]].mOffsetX = v;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[i][j]].mOffsetX = v;
        }
    }
    if (gRecordGpx->mStateFrames >= 10) {
        func_ov001_021949d4();
    }
}

void AdvanceRecordGpxState4(void) {
    s16 v;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s16 x = 0;

    AdvanceRecordGpxOffsetTimers();
    switch (gRecordGpx->field7C) {
        case 0:
            x = 0x100;
            break;
        case 1:
            x = -256;
            break;
    }
    gRecordGpx->mStateFrames++;
    v = mutil_interpolate(1, x, 0, gRecordGpx->mStateFrames, 10);
    gRecordGpx->mBg3OffsetX = v;
    a = gRecordGpx->mRecordGpxMBncl->field6;
    b = gRecordGpx->mRecordGpxSBncl->field6;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = v;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = v;
    gRecordGpx->mRecordGpxMTable[a].mOffsetX = v;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a666c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = v;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[i][j]].mOffsetX = v;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a6614[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a662c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a663c[i]].mOffsetX = v;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66b4[i][j]].mOffsetX = v;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[i][j]].mOffsetX = v;
        }
    }
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordGpxState2();
    }
}

void AdvanceRecordGpxState5(void) {
    s16 v;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    gRecordGpx->mStateFrames++;
    v = mutil_interpolate(1, 0, 0x100, gRecordGpx->mStateFrames, 10);
    gRecordGpx->mBg3OffsetX = v;
    a = gRecordGpx->mRecordGpxMBncl->field6;
    b = gRecordGpx->mRecordGpxSBncl->field6;
    gRecordGpx->mRecordGpxMTable[0].mOffsetX = v;
    gRecordGpx->mRecordGpxMTable[1].mOffsetX = v;
    gRecordGpx->mRecordGpxMTable[a].mOffsetX = v;
    gRecordGpx->mRecordGpxSTable[0x2c].mOffsetX = v;
    gRecordGpx->mRecordGpxSTable[0x2d].mOffsetX = v;
    for (i = 0; i < 4; i++) {
        gRecordGpx->mRecordGpxSTable[data_ov001_021a666c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[data_ov001_021a6654[i]].mOffsetX = v;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66cc[i][j]].mOffsetX = v;
        }
        gRecordGpx->mRecordGpxSTable[data_ov001_021a665c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a6614[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a662c[i]].mOffsetX = v;
        gRecordGpx->mRecordGpxSTable[b + data_ov001_021a663c[i]].mOffsetX = v;
        for (j = 0; j < 3; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a66b4[i][j]].mOffsetX = v;
        }
        for (j = 0; j < 2; j++) {
            gRecordGpx->mRecordGpxSTable[data_ov001_021a6674[i][j]].mOffsetX = v;
        }
    }
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordGpxState6();
    }
}

void AdvanceRecordGpxState6(void) {
    gRecordGpx->mStateFrames++;
    gRecordGpx->mBg0Offset = mutil_interpolate(1, 0, -192, gRecordGpx->mStateFrames, 10);
    if (gRecordGpx->mStateFrames >= 10) {
        RequestRecordScreen(gRecordGpx->field90);
    }
}

void AdvanceRecordGpx(void) {
    RecordGpx *d;

    gRecordGpx->mState = gRecordGpx->mNextState;
    switch (gRecordGpx->mState) {
        case 0:
            AdvanceRecordGpxState0();
            break;
        case 1:
            AdvanceRecordGpxState1();
            break;
        case 2:
            AdvanceRecordGpxState2();
            break;
        case 3:
            AdvanceRecordGpxState3();
            break;
        case 4:
            AdvanceRecordGpxState4();
            break;
        case 5:
            AdvanceRecordGpxState5();
            break;
        case 6:
            AdvanceRecordGpxState6();
            break;
    }
    d = gRecordGpx;
    jn_ui_renderElements(d->mRecordGpxMBncl, d->mRecordGpxMNcer, d->mRecordGpxMBnll, GetRecordMainOam(),
                    d->mRecordGpxMTable);
    d = gRecordGpx;
    jn_ui_renderElements(d->mRecordGpxSBncl, d->mRecordGpxSNcer, d->mRecordGpxSBnll, GetRecordSubOam(), d->mRecordGpxSTable);
}

void func_ov001_02193ccc(void) {
    reg_G2_BG0OFS = (-gRecordGpx->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = ((-gRecordGpx->mBg3OffsetX) & 0x1ff) | ((-gRecordGpx->mBg3OffsetY << 16) & 0x1ff0000);
    AdvanceRecordSceneRegistersTimer();
}

void func_ov001_02193c84(void) {
    u32 a = (reg_GX_DISPCNT & 0x1f00) >> 8;
    u32 b;

    a |= 0x11;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (a << 8);
    b = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    b |= 0x8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (b << 8);
}

void RegisterRecordGpxCallbacks(void) {
    RecordScreenCallbacks local = gRecordGpxCallbacks;

    SetRecordScreenCallbacks(&local);
}
