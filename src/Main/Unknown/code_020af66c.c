#include "Main/Unknown/code_020af66c.h"

#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b03bc.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Race/RaceStartSequence.h"
#include "Main/Unknown/code_020b36c8.h"
#include "Main/Race/RaceEnd.h"
#include "Main/Unknown/code_020b3adc.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b85f0.h"
#include "Main/Unknown/code_020b8610.h"
#include "Main/Unknown/code_020b8624.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020ba50c.h"
#include "Main/Unknown/code_020bb5cc.h"
#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Unknown/code_020bc108.h"
#include "Main/Race/RaceRankList.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c214c.h"
#include "Main/Unknown/code_020c31ec.h"
#include "Main/Unknown/code_020c3e00.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020c4bd8.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020c5ccc.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020d129c.h"
#include "Main/Unknown/code_020d12e0.h"
#include "Main/Unknown/code_020d1298.h"
#include "Main/Unknown/code_020d1450.h"
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_020d2094.h"
#include "Main/Unknown/code_0212b1c0.h"
#include "Main/Unknown/code_0212b5d8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0200eddc.h"
#include "gx.h"
#include "code_02148950.h"
#include "code_0214a390.h"
#include "code_0214b338.h"
#include "code_0214b824.h"
#include "registers.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Ui/ChoisesS.h"
#include "Main/Unknown/code_020b36dc.h"
#include "Main/Unknown/code_020b3b08.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b65f0.h"
#include "Main/Unknown/code_020bb530.h"
#include "Main/Unknown/code_020b6d98.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020beb9c.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020cffa0.h"
#include "Main/Unknown/code_020d12b0.h"
#include "Main/Unknown/code_020d1464.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020b6000.h"
#include "Main/Unknown/code_020ba000.h"
#include "Main/Unknown/code_020bb000.h"
#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020c5ce0.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Kart/KartTimes.h"

void InitSubScreenGraphicsMode5(void) {
    if (IsCourseWithMap2DLocal3() != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
    } else {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1400;
    }
    GXS_SetGraphicsMode(5);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
    reg_G2S_DB_BG2CNT &= ~0x40;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x8410;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 3;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8810 | ((IsCourseWithSubBg3CntBit13() != 0) << 13);
}

void InitSubScreenGraphicsMode0(void) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
    GXS_SetGraphicsMode(0);
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT &= ~0x40;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 8;
    reg_G2S_DB_BG2OFS = 0x100;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
    reg_G2S_DB_BG2CNT &= ~0x40;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x4c08;
    reg_G2S_DB_BG3OFS = 0x100;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x4e08;
}

void r2d_vblank(void) {
    s32 i;
    u32 v;
    s32 w;
    s32 a;

    v = gRaceMultiConfig->mRaceKind;
    if (v == RACE_KIND_START_GP) {
        cint_vblank();
        return;
    }
    if (v == RACE_KIND_AWARD) {
        return;
    }
    if (v == RACE_KIND_STAFF_ROLL) {
        *(vu16 *) 0x05000000 = 0;
        r2d_vblankUpdateStaffRoll();
        srol_vblank();
        return;
    }
    if (r2d_sStatus->mEnabled == FALSE) {
        return;
    }
    if (r2d_sStatus->mUnk_840 != FALSE) {
        GXS_LoadBG0Char(rchoi_getCharData()->mData, 0, 0x3000);
        r2d_sStatus->mUnk_840 = FALSE;
        GX_LoadOBJPltt(r2d_getGraphics(1)->mNclr->mData, 0, r2d_getGraphics(1)->mNclr->mDataSize);
        GX_LoadOBJ(r2d_getGraphics(1)->mNcgr->mData, 0, 0x4000);
        r2d_sStatus->mUnk_848 = 1;
        r2d_sStatus->mUnk_844 = 1;
        reg_GX_DISPCNT &= ~0xe000;
    } else if (r2d_sStatus->mUnk_844 != 0) {
        if (rchoi_getIsRacePaused() == 0) {
            if (r2d_sStatus->mUnk_844++ >= r2d_sStatus->mUnk_850) {
                if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
                    w = (reg_GX_DISPCNT & 0x1f00) >> 8;
                    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((w | 8) << 8);
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 1;
                    reg_G2_BG3CNT &= ~0x40;
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & 0x43) | 0x500;
                    GX_LoadBGPltt(r2d_sStatus->mNclrs[0]->mData, 0, r2d_sStatus->mNclrs[0]->mDataSize);
                    GX_LoadBG3Char(r2d_sStatus->mNcgrs[0]->mData, 0, r2d_sStatus->mNcgrs[0]->mDataSize);
                    GX_LoadBG3Scr(r2d_sStatus->mNscrs[1]->mData, 0, 0x600);
                    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 8, 0x27, 5, 9);
                }
                r2d_sStatus->mUnk_844 = 0;
                r2d_sStatus->mUnk_84c = 1;
            }
        }
    }
    v = gRaceMultiConfig->mMode;
    if (v == MODE_GRAND_PRIX && r2d_sStatus->mUnk_84c != 0) {
        reg_G2_BG3OFS = 0x01ff0000 & (mutil_interpolate(1, -64, 0, GetRaceGoalMUpdateFrames(), 20) << 16);
    } else if (v == MODE_MISSION_RUN && r2d_sStatus->mUnk_84c != 0) {
        GXS_LoadBG0Char(rchoi_getCharData()->mData, 0, 0x3000);
        GXS_LoadBG0Scr(rchoi_getMapData(), 0, 0x600);
    }
    DC_FlushRange(r2d_sStatus->mMainOam, 0x400);
    GX_LoadOAM(r2d_sStatus->mMainOam, 0, 0x400);
    DC_FlushRange(r2d_sStatus->mSubOam, 0x400);
    GXS_LoadOAM(r2d_sStatus->mSubOam, 0, 0x400);
    if (r2d_sStatus->mSubScreenEnabled != FALSE) {
        switch (r2d_sStatus->mSubScreenState) {
            case 0:
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
                GXS_SetGraphicsMode(0);
                reg_G2S_DB_BG2OFS = 0;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
                reg_G2S_DB_BG2CNT &= ~0x40;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x208;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
                reg_G2S_DB_BG3CNT &= ~0x40;
                reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x308;
                GXS_LoadBGPltt(data_0217b34c, 0, 0x200);
                break;
            case 1:
            case 2:
            case 3:
                InitSubScreenGraphicsMode5();
                GXS_LoadBGPltt(rchoi_getPalData()->mData, 0, 0x200);
                break;
            case 4:
            case 5:
                reg_G2S_DB_BG0OFS = 0;
                reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
                reg_G2S_DB_BG0CNT &= ~0x40;
                reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x10c;
                InitSubScreenGraphicsMode0();
                GXS_LoadBGPltt(GetRaceGoalSBPaletteAndChars(0)->mUnk_00->mData, 0,
                               GetRaceGoalSBPaletteAndChars(0)->mUnk_00->mDataSize);
                GXS_LoadBG1Char(GetRaceGoalSBPaletteAndChars(0)->mUnk_04->mData, 0,
                                GetRaceGoalSBPaletteAndChars(0)->mUnk_04->mDataSize);
                GXS_LoadOBJPltt(r2d_getGraphics(7)->mNclr->mData, 0, 0x80);
                GXS_LoadOBJ(r2d_getGraphics(7)->mNcgr->mData, 0, 0x4000);
                GXS_LoadBG0Char(rchoi_getCharData()->mData, 0, 0x3000);
                GXS_LoadBG0Scr(rchoi_getMapData(), 0, 0x600);
                break;
            case 6:
                break;
        }
    }
    switch (r2d_sStatus->mSubScreenState) {
        case 0:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
            a = r2d_sStatus->mUpdateFrames / 6;
            reg_G2S_DB_BG3OFS = (a & 0x1ff) | (((0x200 - a) << 16) & 0x01ff0000);
            break;
        case 1:
        case 2:
        case 3:
            if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
                GXS_LoadOBJPltt(r2d_getGraphics(6)->mNclr->mData, 0, r2d_getGraphics(6)->mNclr->mDataSize);
            }
            G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, r2d_sStatus->mUnk_858[0].mUnk_00, r2d_sStatus->mUnk_858[0].mUnk_10,
                              r2d_sStatus->mUnk_858[0].mUnk_14, r2d_sStatus->mUnk_858[0].mUnk_18,
                              r2d_sStatus->mUnk_858[0].mUnk_1c);
            if (IsCourseWithMap2DLocal3() != 0) {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, r2d_sStatus->mUnk_858[1].mUnk_00, r2d_sStatus->mUnk_858[1].mUnk_10,
                                  r2d_sStatus->mUnk_858[1].mUnk_14, r2d_sStatus->mUnk_858[1].mUnk_18,
                                  r2d_sStatus->mUnk_858[1].mUnk_1c);
            }
            UpdateRaceHudSubScreenBgPalette((RaceHudSubScreenBgPalette *) &data_0217b34c[0x100]);
            if (IsCourseWithMap2DLocal3() != 0) {
                if (IsFollowedKartOutsideBox() != 0) {
                    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
                } else {
                    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1800;
                }
            } else {
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1400;
            }
            break;
        case 4:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
            switch (gRaceMultiConfig->mMode) {
                case MODE_BATTLE:
                case MODE_VS:
                    GXS_LoadBG0Char(rchoi_getCharData()->mData, 0, 0x800);
                    break;
            }
            w = GetRaceGoalSOffsetX();
            if (w < 0x100) {
                a = -w & 0x1ff;
                reg_G2S_DB_BG2OFS = a;
                reg_G2S_DB_BG3OFS = a;
                GXS_LoadBG2Scr(GetRaceGoalSNscr(1)->mData, 0, 0x600);
                GXS_LoadBG3Scr(GetRaceGoalSNscr(2)->mData, 0, 0x600);
            }
            break;
        case 5:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
            switch (gRaceMultiConfig->mMode) {
                case MODE_BATTLE:
                case MODE_VS:
                    GXS_LoadBG0Char(rchoi_getCharData()->mData, 0, 0x800);
                    break;
            }
            w = GetRaceGoalSOffsetX();
            if (r2d_sStatus->mSubScreenState5LoadPending != FALSE) {
                GXS_LoadBG1Scr(GetRaceGoalSNscr(3)->mData, 0, GetRaceGoalSNscr(3)->mDataSize);
                GXS_LoadBG2Scr(GetRaceGoalSNscr(4)->mData, 0, GetRaceGoalSNscr(4)->mDataSize);
                GXS_LoadBG3Scr(GetRaceGoalSNscr(5)->mData, 0, GetRaceGoalSNscr(5)->mDataSize);
                GXS_LoadOBJPltt(r2d_getGraphics(8)->mNclr->mData, 0, 0x20);
                GXS_LoadOBJPltt(r2d_getGraphics(8)->mNclr->mData + 0xc0, 0x180, 0x80);
                GXS_LoadOBJ(r2d_getGraphics(8)->mNcgr->mData, 0, 0x4000);
                r2d_sStatus->mSubScreenState5LoadPending = FALSE;
            }
            if (w < 0x100) {
                reg_G2S_DB_BG2OFS = w & 0x1ff;
                reg_G2S_DB_BG3OFS = -w & 0x1ff;
            }
            break;
        case 6:
            if (r2d_sStatus->mSubScreenState6LoadPending != FALSE) {
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1200;
                GXS_SetGraphicsMode(0);
                reg_G2S_DB_BG1OFS = 0;
                reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
                reg_G2S_DB_BG1CNT &= ~0x40;
                reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 8;
                GXS_LoadBGPltt(r2d_sStatus->mNclrs[1]->mData, 0, 0x20);
                GXS_LoadBG1Char(r2d_sStatus->mNcgrs[1]->mData, 0, r2d_sStatus->mNcgrs[1]->mDataSize);
                GXS_LoadBG1Scr(r2d_sStatus->mNscrs[2]->mData, 0, r2d_sStatus->mNscrs[2]->mDataSize);
                GXS_LoadOBJPltt(r2d_getGraphics(9)->mNclr->mData, 0, 0xa0);
                GXS_LoadOBJPltt(r2d_getGraphics(9)->mNclr->mData + 0xb0, 0x160, 0xa0);
                GXS_LoadOBJ(r2d_getGraphics(9)->mNcgr->mData, 0, 0x4000);
                r2d_sStatus->mSubScreenState6LoadPending = FALSE;
            }
            break;
    }
    if (rchoi_isMenuVisible() != 0) {
        if (gRaceStatus->mRaceDone == 0) {
            w = (reg_GX_DISPCNT & 0x1f00) >> 8;
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((w | 4) << 8);
            GX_LoadBG2Scr(r2d_sStatus->mNscrs[0]->mData, 0, 0x600);
        }
        GXS_LoadBG0Scr(rchoi_getMapData(), 0, 0x600);
        w = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((w | 1) << 8);
        G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0x3e, 0x3f, 8, 8, -7);
    } else {
        w = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((w & ~1) << 8);
        w = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((w & ~4) << 8);
        G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    }
    for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
        if (r2d_sStatus->mKartRemoved[i] != 0 && r2d_sStatus->mRemovedSoundPlayed[i] == 0) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x52);
            r2d_sStatus->mRemovedSoundPlayed[i] = 1;
        }
    }
}

void r2d_init(void) {
    s32 i;
    u32 raceKind;
    u16 *choisesSBPalette;
    u32 j;
    u16 paletteColor;

    raceKind = gRaceMultiConfig->mRaceKind;
    if (raceKind == RACE_KIND_START_GP) {
        cint_init();
        return;
    }
    if (raceKind == RACE_KIND_AWARD) {
        return;
    }
    if (raceKind == RACE_KIND_STAFF_ROLL) {
        r2d_initStaffRoll();
        srol_init(proc_getHeap(proc_getCurrent()));
        return;
    }
    r2d_sStatus = heap_alloc(proc_getHeap(proc_getCurrent()), 0x914);
    InitRaceStartSequence();
    InitRaceEnd();
    m2d_init();
    InitRaceNcerNclrNcgrTables();
    func_020cffa0();
    if (gRaceMultiConfig->mRaceKind == 4) {
        r2d_initBattleIntro();
    }
    r2d_initItemSpinner();
    InitRaceLinkLevel();
    InitRaceModeCount();
    InitRaceGoalM();
    InitRaceTimeDigits();
    r2d_initLapAndTimeDiff();
    r2d_initRaceNumber();
    InitRaceGoalTimes();
    InitRaceRankList();
    mpicn_init();
    r2dres_init();
    r2dtar_init();
    r2d_initMapPath();
    r2d_sStatus->mUpdateFrames = 0;
    for (i = 0; i < 7; i++) {
        r2d_sStatus->mNclrs[i] = NULL;
        r2d_sStatus->mNcgrs[i] = NULL;
    }
    r2d_sStatus->mSubScreenState = 1;
    r2d_sStatus->mSubScreenEnabled = FALSE;
    r2d_sStatus->mSubScreenState5LoadPending = FALSE;
    r2d_sStatus->mUnk_838 = FALSE;
    r2d_sStatus->mUnk_83c = FALSE;
    r2d_sStatus->mUnk_840 = FALSE;
    r2d_sStatus->mUnk_844 = 0;
    r2d_sStatus->mUnk_848 = 0;
    r2d_sStatus->mUnk_84c = 0;
    r2d_sStatus->mUnk_850 = 0;
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        switch (gRaceMultiConfig->mCourseId) {
            case COURSE_ID_MINI_STAGE3:
                r2d_sStatus->mSubScreenCourseScale = 0x40;
                break;
            default:
                r2d_sStatus->mSubScreenCourseScale = 0x64;
                break;
        }
    } else if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        switch (gRaceMultiConfig->mCourseId) {
            case COURSE_ID_MR_STAGE1:
            case COURSE_ID_MR_STAGE2:
            case COURSE_ID_MR_STAGE3:
            case COURSE_ID_MR_STAGE4:
                r2d_sStatus->mSubScreenCourseScale = 0x64;
                break;
            default:
                r2d_sStatus->mSubScreenCourseScale = 0x86;
                break;
        }
    } else {
        r2d_sStatus->mSubScreenCourseScale = 0x86;
    }
    r2d_sStatus->mEnabled = FALSE;
    for (i = 0; i < 8; i++) {
        r2d_sStatus->mKartRemoved[i] = 0;
        r2d_sStatus->mRemovedSoundPlayed[i] = 0;
    }
    r2d_sStatus->mShowLapTime = 0;
    r2d_sStatus->mShowLapTimeFrames = -1;
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK && gRaceMultiConfig->mKartCount > 1) {
        r2d_sStatus->mUseTimeDifference = 1;
    } else {
        r2d_sStatus->mUseTimeDifference = 0;
    }
    r2d_sStatus->mStepHasRun = 0;
    r2d_sStatus->mUnk_90c = FALSE;
    r2d_sStatus->mUnk_910 = gRaceMultiConfig->mMode == MODE_MISSION_RUN ? IsMissionRunRecordFilled() : 0;
    MI_DmaFill32(3, r2d_sStatus->mMainOam, 0xc0, 0x400);
    MI_DmaFill32(3, r2d_sStatus->mSubOam, 0xc0, 0x400);
    g2du_unpackPaletteData(&r2d_sStatus->mNclrs[0], m2d_getSceneArcFile("race_m_b.NCLR"));
    g2du_unpackCharacterDataBG(&r2d_sStatus->mNcgrs[0], m2d_getSceneArcFile("race_m_b.NCGR"));
    g2du_unpackScreenData(&r2d_sStatus->mNscrs[0], m2d_getSceneArcFile("race_m_pause.NSCR"));
    g2du_unpackScreenData(&r2d_sStatus->mNscrs[1], m2d_getSceneArcFile("race_m_goal.NSCR"));
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
        g2du_unpackPaletteData(&r2d_sStatus->mNclrs[1], m2d_getSceneArcFile("race_new_record_ta_s_b.NCLR"));
        g2du_unpackCharacterDataBG(&r2d_sStatus->mNcgrs[1], m2d_getSceneArcFile("race_new_record_ta_s_b.NCGR"));
        g2du_unpackScreenData(&r2d_sStatus->mNscrs[2], m2d_getSceneArcFile("race_new_record_ta_s_bg.NSCR"));
        DC_FlushRange(((Ncgr *) r2d_sStatus->mNscrs[0])->mData, ((Ncgr *) r2d_sStatus->mNscrs[0])->mDataSize);
        DC_FlushRange(r2d_sStatus->mNscrs[2]->mData, r2d_sStatus->mNscrs[2]->mDataSize);
    }
    choisesSBPalette = rchoi_getPalData()->mData;
    for (i = 0; i < 0x80; i++) {
        data_0217b34c[i + 0x80] = choisesSBPalette[i + 0x80];
    }
    rchoi_getPalData()->mData[0] = data_0217b34c[0x100];
    DC_FlushRange(rchoi_getPalData()->mData, 0x200);
    for (i = 0; i < 0x20; i++) {
        paletteColor = rchoi_getPalData()->mData[i + 0xe0];
        GetRaceGoalSBPaletteAndChars(0)->mUnk_00->mData[i + 0xe0] = paletteColor;
    }
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX) {
        CopyPlayerCharacterToRaceGoalMO(r2d_getGraphics(1)->mNclr->mData, r2d_getGraphics(1)->mNcgr->mData);
        DC_FlushRange(r2d_getGraphics(1)->mNclr->mData, r2d_getGraphics(1)->mNclr->mDataSize);
        DC_FlushRange(r2d_getGraphics(1)->mNcgr->mData, r2d_getGraphics(1)->mNcgr->mDataSize);
    }
    FillRaceSOPaletteAndChars(r2d_getGraphics(6)->mNclr->mData, r2d_getGraphics(6)->mNcgr->mData);
    DC_FlushRange(r2d_getGraphics(6)->mNclr->mData, r2d_getGraphics(6)->mNclr->mDataSize);
    DC_FlushRange(r2d_getGraphics(6)->mNcgr->mData, r2d_getGraphics(6)->mNcgr->mDataSize);
    m2d_copyTiles2d(r2d_getGraphics(6)->mNcgr->mData, 0x10, 0, 0x10, 2, r2d_getGraphics(7)->mNcgr->mData, 0x10, 0);
    DC_FlushRange(r2d_getGraphics(7)->mNcgr->mData, r2d_getGraphics(7)->mNcgr->mDataSize);
    m2d_copyTiles2d(r2d_getGraphics(6)->mNcgr->mData, 0x10, 0, 0x10, 2, r2d_getGraphics(8)->mNcgr->mData, 0x10, 0);
    DC_FlushRange(r2d_getGraphics(8)->mNcgr->mData, r2d_getGraphics(8)->mNcgr->mDataSize);
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
        m2d_copyTiles2d(r2d_getGraphics(6)->mNcgr->mData, 0x10, 0, 0x10, 2, r2d_getGraphics(9)->mNcgr->mData, 0x10, 0);
        DC_FlushRange(r2d_getGraphics(9)->mNcgr->mData, r2d_getGraphics(9)->mNcgr->mDataSize);
    }
    ResetRaceStartSequenceFrames();
    ResetRaceEndFrames();
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        gStruct217B488->mUnk_10 = 0;
    }
}

static inline void InitMap2D_inline(u16 *screenMap) {
    s32 j;
    s32 i;
    u16 *screenMapCopy = screenMap;

    for (i = 3; i < 24; i++) {
        s32 rowStart = i * 32;
        for (j = 14; j < 32; j++) {
            s32 index = j + rowStart;
            s32 mirroredIndex = rowStart + (45 - j);
            if (index < mirroredIndex) {
                u16 tile = screenMapCopy[mirroredIndex];
                screenMapCopy[mirroredIndex] = screenMapCopy[index];
                screenMapCopy[index] = tile;
            }
            screenMapCopy[index] ^= 0x400;
        }
    }
}

void map2d_load(void) {
    Nclr *nclrs[3];
    Ncgr *ncgrs[3];
    Nscr *nscrs[4];
    BOOL hasGlobalFiles;
    s32 i;
    s32 shineBattleFlag;

    hasGlobalFiles = gRaceMultiConfig->mMode != MODE_MISSION_RUN;
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_START_GP) {
        return;
    }
    if (gRaceMultiConfig->mRaceKind == RACE_KIND_AWARD || gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    data_0217b34c = heap_alloc(proc_getHeap(proc_getCurrent()), 0x400);
    for (i = 0; i < 2; i++) {
        nclrs[i] = NULL;
        ncgrs[i] = NULL;
    }
    for (i = 0; i < 3; i++) {
        nscrs[i] = NULL;
    }

    if (arc_isCourseTexAvailable()) {
        if (hasGlobalFiles) {
            g2du_unpackPaletteData(&nclrs[0], m2d_getCourseArcFile("Map2D/global.NCLR"));
            g2du_unpackPaletteData(&nclrs[1], m2d_getCourseArcFile("Map2D/global2.NCLR"));
        }
        g2du_unpackPaletteData(&nclrs[2], m2d_getCourseArcFile("Map2D/local.NCLR"));
    } else {
        if (hasGlobalFiles) {
            g2du_getPaletteData(&nclrs[0], m2d_getCourseArcFile("Map2D/global.NCLR"));
            g2du_getPaletteData(&nclrs[1], m2d_getCourseArcFile("Map2D/global.NCLR"));
        }
        g2du_getPaletteData(&nclrs[2], m2d_getCourseArcFile("Map2D/local.NCLR"));
    }

    if (arc_isCourseTexAvailable()) {
        if (hasGlobalFiles) {
            g2du_unpackCharacterDataBG(&ncgrs[0], m2d_getCourseArcFile("Map2D/global.NCGR"));
            g2du_unpackCharacterDataBG(&ncgrs[1], m2d_getCourseArcFile("Map2D/global2.NCGR"));
        }
        g2du_unpackCharacterDataBG(&ncgrs[2], m2d_getCourseArcFile("Map2D/local.NCGR"));
    } else {
        if (hasGlobalFiles) {
            g2du_getCharacterDataBG(&ncgrs[0], m2d_getCourseArcFile("Map2D/global.NCGR"));
            g2du_getCharacterDataBG(&ncgrs[1], m2d_getCourseArcFile("Map2D/global2.NCGR"));
        }
        g2du_getCharacterDataBG(&ncgrs[2], m2d_getCourseArcFile("Map2D/local.NCGR"));
    }

    if (arc_isCourseTexAvailable()) {
        if (hasGlobalFiles) {
            g2du_unpackScreenData(&nscrs[0], m2d_getCourseArcFile("Map2D/global1.NSCR"));
            g2du_unpackScreenData(&nscrs[1], m2d_getCourseArcFile("Map2D/global2.NSCR"));
        }
        g2du_unpackScreenData(&nscrs[2], m2d_getCourseArcFile("Map2D/local2.NSCR"));
        if (IsCourseWithMap2DLocal3()) {
            g2du_unpackScreenData(&nscrs[3], m2d_getCourseArcFile("Map2D/local3.NSCR"));
        }
    } else {
        if (hasGlobalFiles) {
            g2du_getScreenData(&nscrs[0], m2d_getCourseArcFile("Map2D/global1.NSCR"));
            g2du_getScreenData(&nscrs[1], m2d_getCourseArcFile("Map2D/global2.NSCR"));
        }
        g2du_getScreenData(&nscrs[2], m2d_getCourseArcFile("Map2D/local2.NSCR"));
        if (IsCourseWithMap2DLocal3()) {
            g2du_getScreenData(&nscrs[3], m2d_getCourseArcFile("Map2D/local3.NSCR"));
        }
    }

    if (hasGlobalFiles) {
        if (gRaceMultiConfig->mMirrorMode != 0) {
            InitMap2D_inline(nscrs[0]->mData);
        }
        shineBattleFlag = 0;
        if (gRaceMultiConfig->mMode == MODE_BATTLE && gRaceMultiConfig->mBattleKind == BATTLE_KIND_SHINE) {
            shineBattleFlag = 1;
        }
        for (i = 0; i < 16; i++) {
            nclrs[0]->mData[i + 16] = nclrs[1]->mData[(shineBattleFlag + 1) * 16 + i];
        }
        for (i = 0; i < 0x400; i++) {
            s32 r = nscrs[1]->mData[i];
            r %= 0x400;
            nscrs[1]->mData[i] = (u16) (nscrs[1]->mData[i] & 0xfc00) | (r + ((shineBattleFlag + 6) << 5));
        }
        DC_StoreAll();
        GXS_SetGraphicsMode(5);
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
        GXS_SetGraphicsMode(0);
        reg_G2S_DB_BG2OFS = 0;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
        reg_G2S_DB_BG2CNT = reg_G2S_DB_BG2CNT & ~0x40;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x208;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
        reg_G2S_DB_BG3CNT = reg_G2S_DB_BG3CNT & ~0x40;
        reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x308;
        GXS_LoadBGPltt(nclrs[0]->mData, 0, nclrs[0]->mDataSize);
        GXS_LoadBG2Char(ncgrs[0]->mData, 0, ncgrs[0]->mDataSize);
        GXS_LoadBG2Char(ncgrs[1]->mData, 0x1800, ncgrs[1]->mDataSize);
        GXS_LoadBG2Scr(nscrs[0]->mData, 0, nscrs[0]->mDataSize);
        GXS_LoadBG3Scr(nscrs[1]->mData, 0, nscrs[1]->mDataSize);
    }

    InitSubScreenGraphicsMode5();
    GXS_LoadBGPltt(nclrs[2]->mData, 0, 0x200);
    GXS_LoadBG3Char(ncgrs[2]->mData, 0, ncgrs[2]->mDataSize);
    GXS_LoadBG2Scr(nscrs[2]->mData, 0, nscrs[2]->mDataSize);
    if (IsCourseWithMap2DLocal3()) {
        GXS_LoadBG3Scr(nscrs[3]->mData, 0, nscrs[3]->mDataSize);
    }
    GX_SetBankForSubBGExtPltt(0x80);
    GXS_BeginLoadBGExtPltt();
    GX_LoadOBJExtPltt(nclrs[2]->mData, 0x4000, 0x200);
    GX_LoadOBJExtPltt(nclrs[2]->mData, 0x6000, 0x200);
    GX_EndLoadOBJExtPltt();
    for (i = 0; i < 0x100; i++) {
        if (hasGlobalFiles) {
            data_0217b34c[i] = nclrs[0]->mData[i];
        }
        (data_0217b34c + i)[0x100] = nclrs[2]->mData[i];
    }
    if (hasGlobalFiles) {
        DC_FlushRange(data_0217b34c, 0x200);
    }
    DC_FlushRange(data_0217b34c + 0x100, 0x200);
}

void func_020af99c(void) {
    u32 raceKind;
    u16 w;

    raceKind = gRaceMultiConfig->mRaceKind;
    if (raceKind == RACE_KIND_START_GP) {
        return;
    }
    if (raceKind == RACE_KIND_AWARD || raceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    w = gMapData->mSettings->mColorAndFogAlpha & 0x7fff;
    *(vu16 *) 0x05000000 = w;
    r2d_sStatus->mNclrs[0]->mData[0] = w;
    DC_FlushRange(r2d_sStatus->mNclrs[0]->mData, r2d_sStatus->mNclrs[0]->mDataSize);
    GX_LoadBGPltt(r2d_sStatus->mNclrs[0]->mData, 0, r2d_sStatus->mNclrs[0]->mDataSize);
    GX_LoadBG2Char(r2d_sStatus->mNcgrs[0]->mData, 0, r2d_sStatus->mNcgrs[0]->mDataSize);
    GX_LoadBG2Scr(r2d_sStatus->mNscrs[0]->mData, 0, r2d_sStatus->mNscrs[0]->mDataSize);
    GX_LoadOBJPltt(r2d_getGraphics(0)->mNclr->mData, 0, r2d_getGraphics(0)->mNclr->mDataSize);
    GX_LoadOBJ(r2d_getGraphics(0)->mNcgr->mData, 0, 0x4000);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0xe000) | 0xe000;
    w = reg_G2_WININ;
    reg_G2_WININ = (u32) ((w & ~0x3f) | 0x1f) | 0x20;
    reg_G2_WIN0H = 0xff;
    reg_G2_WIN0V = 0x60c0;
    reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f00) | 0x1f00) | 0x2000;
    reg_G2_WIN1H = 0x40ff;
    reg_G2_WIN1V = 0x60;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f00) | 0x1200) | 0x2000;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xf) | 0x20;
    reg_GXS_DB_DISPCNT &= ~0xe000;
    GXS_SetGraphicsMode(5);
    GXS_LoadOBJPltt(r2d_getGraphics(6)->mNclr->mData, 0, r2d_getGraphics(6)->mNclr->mDataSize);
    GXS_LoadOBJ(r2d_getGraphics(6)->mNcgr->mData, 0, 0x4000);
    InitSubScreenGraphicsMode0();
    GXS_LoadBG1Scr(GetRaceGoalSNscr(0)->mData, 0, GetRaceGoalSNscr(0)->mDataSize);
    GXS_LoadBG2Scr(GetRaceGoalSNscr(1)->mData, 0, GetRaceGoalSNscr(1)->mDataSize);
    GXS_LoadBG3Scr(GetRaceGoalSNscr(2)->mData, 0, GetRaceGoalSNscr(2)->mDataSize);
    GXS_LoadBGPltt(data_0217b34c + 0x100, 0, 0x200);
    func_020cfca4();
    GX_SetBankForSubBGExtPltt(0x80);
    GXS_BeginLoadBGExtPltt();
    GX_LoadOBJExtPltt(data_0217b34c + 0x100, 0x4000, 0x200);
    GX_LoadOBJExtPltt(data_0217b34c + 0x100, 0x6000, 0x200);
    GX_EndLoadOBJExtPltt();
    GXS_LoadBGPltt(rchoi_getPalData()->mData, 0, 0x200);
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
    reg_G2S_DB_BG0CNT &= ~0x40;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x10c;
    GXS_LoadBG0Char(rchoi_getCharData()->mData, 0, rchoi_getCharData()->mDataSize);
    GXS_LoadBG0Scr(rchoi_getMapData(), 0, 0x600);
    InitSubScreenGraphicsMode5();
    r2d_sStatus->mEnabled = TRUE;
}

void func_020af86c(void) {
    u32 raceKind;

    raceKind = gRaceMultiConfig->mRaceKind;
    if (raceKind == RACE_KIND_START_GP) {
        cint_finalize();
        return;
    }
    if (raceKind == RACE_KIND_AWARD) {
        return;
    }
    if (raceKind == RACE_KIND_STAFF_ROLL) {
        srol_finalize();
        r2d_finalizeStaffRoll();
        return;
    }
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 0, 0, 0x10, 0x10);
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0, 0x10, 0x10);
    r2d_sStatus = NULL;
    ClearRaceStartSequencePointer();
    ClearRaceEndPointer();
    m2d_finalize();
    ClearRaceNcerNclrNcgrTablesPointer();
    if (gRaceMultiConfig->mRaceKind == 4) {
        r2d_finalizeBattleIntro();
    }
    r2d_finalizeItemSpinner();
    ClearRaceLinkLevelPointer();
    ClearRaceModeCountPointer();
    ClearRaceGoalMPointer();
    ClearRaceTimeDigitsPointer();
    r2d_finalizeLapAndTimeDiff();
    r2d_finalizeRaceNumber();
    ClearRaceGoalTimesPointer();
    ClearRaceRankListPointer();
    mpicn_finalize();
    r2dres_finalize();
    r2dtar_finalize();
    r2d_finalizeMapPath();
    reg_GX_DISPCNT &= ~0xe000;
    reg_GXS_DB_DISPCNT &= ~0xe000;
}

void race_update2d(void) {
    u32 v;

    if (r2d_sStatus != NULL) {
        r2d_sStatus->mStepHasRun = 1;
    }
    v = gRaceMultiConfig->mRaceKind;
    if (v == RACE_KIND_START_GP) {
        cint_update();
        return;
    }
    if (v == RACE_KIND_AWARD) {
        return;
    }
    if (v == RACE_KIND_STAFF_ROLL) {
        r2d_updateStaffRoll();
        srol_update();
        return;
    }
    if (r2d_sStatus->mEnabled == FALSE) {
        return;
    }
    if (r2d_sStatus->mShowLapTime != 0) {
        r2d_sStatus->mShowLapTimeFrames++;
        if (r2d_sStatus->mShowLapTimeFrames >= 0x80) {
            r2d_sStatus->mShowLapTime = 0;
            r2d_sStatus->mShowLapTimeFrames = -1;
        }
    }
    UpdateRaceStartSequence();
    UpdateRaceEnd();
    if (gRaceMultiConfig->mRaceKind == 4) {
        r2d_updateBattleIntro();
    }
    v = gRaceMultiConfig->mMode;
    if ((v == MODE_BATTLE ? gRaceStatus->mRaceDone
         : v == MODE_MISSION_RUN
             ? rstat_isMrWinDelayOver()
             : (rstat_hasDriverFinished(Race_GetPlayerId()) != 0 && r2d_sStatus->mShowLapTime == 0)) == 0) {
        r2d_updateItemSpinner();
        r2d_updateLapAndTimeDiff();
        r2d_updateRaceNumber();
        UpdateRaceGoalTimes();
        UpdateRaceModeCount();
        UpdateRaceGoalM();
    } else {
        StopRaceItemSlotSound();
        r2d_updateLapAndTimeDiff();
        UpdateRaceGoalTimes();
        UpdateRaceGoalM();
    }
    UpdateRaceTimeDigits();
    UpdateRaceRankList();
    switch (r2d_sStatus->mSubScreenState) {
        case 0:
        case 1:
        case 2:
        case 3:
            mpicn_update();
            r2d_updateMapPath();
            break;
        case 4:
        case 5:
            r2dres_update();
            break;
        case 6:
            break;
    }
    r2dtar_update();
    r2d_sStatus->mUpdateFrames++;
    if (r2d_sStatus->mUpdateFrames >= 0xc00) {
        r2d_sStatus->mUpdateFrames = 0;
    }
}
