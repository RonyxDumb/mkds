#include "Main/Race/race_hud_draw.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Menu/title_scene.h"
#include "os_thread.h"
#include "Main/Menu/choises_s_list_chars.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/Race/race_end.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/data_020b85f0.h"
#include "Main/Race/race_ncer_tables.h"
#include "Main/Race/race_item_slot.h"
#include "Main/Race/race_item_slot_sound.h"
#include "Main/Race/race_time_digits.h"
#include "Main/Race/race_rank_list.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Race/race_goal_s.h"
#include "Main/Race/race_goal_s_sb.h"
#include "Main/Race/race_goal_m.h"
#include "Main/Race/race_new_record_ta.h"
#include "Main/Race/race_hud_sub_screen_bomb_koura_w_cells.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Race/race_start_battle.h"
#include "Main/Race/ending_staff_roll.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/Graphics/palette_blend.h"
#include "Main/Race/data_020f36d8.h"
#include "code_0200eddc.h"
#include "gx.h"
#include "code_02148950.h"
#include "g2.h"
#include "gx_load2d.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/oam.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/choises_s_tiles.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Race/race_goal_player_character.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "g2d_Animation.h"
#include "Main/Menu/data_0217d068.h"
#include "player.h"
#include "code_0212df7c.h"
#include "code_0214c778.h"
#include "Main/Race/kart.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Race/race_hud_draw_nop.h"
#include "Main/Race/race_goal_s_draw.h"
#include "Main/Race/race_m_number_pair.h"

BOOL GetShowLapTime(void) {
    return (gRaceHud->mShowLapTime);
}

u32 GetShowLapTimeFrames(void) {
    return (gRaceHud->mShowLapTimeFrames);
}

u32 GetUseTimeDifference(void) {
    return (gRaceHud->mUseTimeDifference);
}

void GetRaceHudTimeDifference(s32 **outSign, TimeDigits **outDigits) {
    *outSign = &gRaceHud->mTimeDifferenceSign;
    *outDigits = &gRaceHud->mTimeDifferenceDigits;
}

u32 GetRaceHudStepHasRun(void) {
    return (gRaceHud->mStepHasRun);
}

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

void UploadRaceHud(void) {
    s32 kartIndex;
    u32 kind;
    s32 value;
    s32 scrollOffset;

    kind = gRaceSetup->mRaceKind;
    if (kind == RACE_KIND_START_GP) {
        UploadRaceStartGpOam();
        return;
    }
    if (kind == RACE_KIND_AWARD) {
        return;
    }
    if (kind == RACE_KIND_STAFF_ROLL) {
        *(vu16 *) HW_BG_PLTT = 0;
        UploadEndingStaffRollOam();
        SetStaffRollScrollAndDrainQueue();
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    if (gRaceHud->mGoalMUploadPending != FALSE) {
        GXS_LoadBG0Char(GetChoisesSBNcgrWithListChars()->mData, 0, 0x3000);
        gRaceHud->mGoalMUploadPending = FALSE;
        GX_LoadOBJPltt(GetRaceNclrNcgr(1)->mNclr->mData, 0, GetRaceNclrNcgr(1)->mNclr->mDataSize);
        GX_LoadOBJ(GetRaceNclrNcgr(1)->mNcgr->mData, 0, 0x4000);
        gRaceHud->mGoalMUploaded = 1;
        gRaceHud->mGoalMUploadFrames = 1;
        reg_GX_DISPCNT &= ~0xe000;
    } else if (gRaceHud->mGoalMUploadFrames != 0) {
        if (GetChoisesSOpenDuringRace() == 0) {
            if (gRaceHud->mGoalMUploadFrames++ >= gRaceHud->mGoalMDelayFrameCount) {
                if (gRaceSetup->mMode == MODE_GRAND_PRIX && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                    value = (reg_GX_DISPCNT & 0x1f00) >> 8;
                    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((value | 8) << 8);
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 1;
                    reg_G2_BG3CNT &= ~0x40;
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & 0x43) | 0x500;
                    GX_LoadBGPltt(gRaceHud->mNclrs[0]->mData, 0, gRaceHud->mNclrs[0]->mDataSize);
                    GX_LoadBG3Char(gRaceHud->mNcgrs[0]->mData, 0, gRaceHud->mNcgrs[0]->mDataSize);
                    GX_LoadBG3Scr(gRaceHud->mNscrs[1]->mData, 0, 0x600);
                    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 8, 0x27, 5, 9);
                }
                gRaceHud->mGoalMUploadFrames = 0;
                gRaceHud->mGoalMEnabled = 1;
            }
        }
    }
    kind = gRaceSetup->mMode;
    if (kind == MODE_GRAND_PRIX && gRaceHud->mGoalMEnabled != 0) {
        reg_G2_BG3OFS = 0x01ff0000 & (InterpolateS16(1, -64, 0, GetRaceGoalMUpdateFrames(), 20) << 16);
    } else if (kind == MODE_MISSION_RUN && gRaceHud->mGoalMEnabled != 0) {
        GXS_LoadBG0Char(GetChoisesSBNcgrWithListChars()->mData, 0, 0x3000);
        GXS_LoadBG0Scr(GetChoisesSListScreenMapData(), 0, 0x600);
    }
    DC_FlushRange(&gRaceHud->mMainOam, 0x400);
    GX_LoadOAM(&gRaceHud->mMainOam, 0, 0x400);
    DC_FlushRange(&gRaceHud->mSubOam, 0x400);
    GXS_LoadOAM(&gRaceHud->mSubOam, 0, 0x400);
    if (gRaceHud->mSubScreenEnabled != FALSE) {
        switch (gRaceHud->mSubScreenState) {
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
                GXS_LoadBGPltt(gRaceHudSubScreenPalettes, 0, 0x200);
                break;
            case 1:
            case 2:
            case 3:
                InitSubScreenGraphicsMode5();
                GXS_LoadBGPltt(GetChoisesSBNclr()->mData, 0, 0x200);
                break;
            case 4:
            case 5:
                reg_G2S_DB_BG0OFS = 0;
                reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
                reg_G2S_DB_BG0CNT &= ~0x40;
                reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x10c;
                InitSubScreenGraphicsMode0();
                GXS_LoadBGPltt(GetRaceGoalSBPaletteAndChars(0)->mPalette->mData, 0,
                               GetRaceGoalSBPaletteAndChars(0)->mPalette->mDataSize);
                GXS_LoadBG1Char(GetRaceGoalSBPaletteAndChars(0)->mChars->mData, 0,
                                GetRaceGoalSBPaletteAndChars(0)->mChars->mDataSize);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(7)->mNclr->mData, 0, 0x80);
                GXS_LoadOBJ(GetRaceNclrNcgr(7)->mNcgr->mData, 0, 0x4000);
                GXS_LoadBG0Char(GetChoisesSBNcgrWithListChars()->mData, 0, 0x3000);
                GXS_LoadBG0Scr(GetChoisesSListScreenMapData(), 0, 0x600);
                break;
            case 6:
                break;
        }
    }
    switch (gRaceHud->mSubScreenState) {
        case 0:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
            scrollOffset = gRaceHud->mUpdateFrames / 6;
            reg_G2S_DB_BG3OFS = (scrollOffset & 0x1ff) | (((0x200 - scrollOffset) << 16) & 0x01ff0000);
            break;
        case 1:
        case 2:
        case 3:
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                GXS_LoadOBJPltt(GetRaceNclrNcgr(6)->mNclr->mData, 0, GetRaceNclrNcgr(6)->mNclr->mDataSize);
            }
            G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, &gRaceHud->mSubScreenBgAffines[0].mMatrix0,
                              gRaceHud->mSubScreenBgAffines[0].mCenterX, gRaceHud->mSubScreenBgAffines[0].mCenterY,
                              gRaceHud->mSubScreenBgAffines[0].mX1, gRaceHud->mSubScreenBgAffines[0].mY1);
            if (IsCourseWithMap2DLocal3() != 0) {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, &gRaceHud->mSubScreenBgAffines[1].mMatrix0,
                                  gRaceHud->mSubScreenBgAffines[1].mCenterX, gRaceHud->mSubScreenBgAffines[1].mCenterY,
                                  gRaceHud->mSubScreenBgAffines[1].mX1, gRaceHud->mSubScreenBgAffines[1].mY1);
            }
            UpdateRaceHudSubScreenBgPalette(&gRaceHudSubScreenPalettes[0x100]);
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
            switch (gRaceSetup->mMode) {
                case MODE_BATTLE:
                case MODE_VS:
                    GXS_LoadBG0Char(GetChoisesSBNcgrWithListChars()->mData, 0, 0x800);
                    break;
            }
            value = GetRaceGoalSOffsetX();
            if (value < 0x100) {
                scrollOffset = -value & 0x1ff;
                reg_G2S_DB_BG2OFS = scrollOffset;
                reg_G2S_DB_BG3OFS = scrollOffset;
                GXS_LoadBG2Scr(GetRaceGoalSNscr(1)->mData, 0, 0x600);
                GXS_LoadBG3Scr(GetRaceGoalSNscr(2)->mData, 0, 0x600);
            }
            break;
        case 5:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
            switch (gRaceSetup->mMode) {
                case MODE_BATTLE:
                case MODE_VS:
                    GXS_LoadBG0Char(GetChoisesSBNcgrWithListChars()->mData, 0, 0x800);
                    break;
            }
            value = GetRaceGoalSOffsetX();
            if (gRaceHud->mSubScreenState5LoadPending != FALSE) {
                GXS_LoadBG1Scr(GetRaceGoalSNscr(3)->mData, 0, GetRaceGoalSNscr(3)->mDataSize);
                GXS_LoadBG2Scr(GetRaceGoalSNscr(4)->mData, 0, GetRaceGoalSNscr(4)->mDataSize);
                GXS_LoadBG3Scr(GetRaceGoalSNscr(5)->mData, 0, GetRaceGoalSNscr(5)->mDataSize);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(8)->mNclr->mData, 0, 0x20);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(8)->mNclr->mData + 0xc0, 0x180, 0x80);
                GXS_LoadOBJ(GetRaceNclrNcgr(8)->mNcgr->mData, 0, 0x4000);
                gRaceHud->mSubScreenState5LoadPending = FALSE;
            }
            if (value < 0x100) {
                reg_G2S_DB_BG2OFS = value & 0x1ff;
                reg_G2S_DB_BG3OFS = -value & 0x1ff;
            }
            break;
        case 6:
            if (gRaceHud->mSubScreenState6LoadPending != FALSE) {
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1200;
                GXS_SetGraphicsMode(0);
                reg_G2S_DB_BG1OFS = 0;
                reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
                reg_G2S_DB_BG1CNT &= ~0x40;
                reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 8;
                GXS_LoadBGPltt(gRaceHud->mNclrs[1]->mData, 0, 0x20);
                GXS_LoadBG1Char(gRaceHud->mNcgrs[1]->mData, 0, gRaceHud->mNcgrs[1]->mDataSize);
                GXS_LoadBG1Scr(gRaceHud->mNscrs[2]->mData, 0, gRaceHud->mNscrs[2]->mDataSize);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(9)->mNclr->mData, 0, 0xa0);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(9)->mNclr->mData + 0xb0, 0x160, 0xa0);
                GXS_LoadOBJ(GetRaceNclrNcgr(9)->mNcgr->mData, 0, 0x4000);
                gRaceHud->mSubScreenState6LoadPending = FALSE;
            }
            break;
    }
    if (IsChoisesSOpen() != 0) {
        if (gRaceProgress->mRaceDone == 0) {
            value = (reg_GX_DISPCNT & 0x1f00) >> 8;
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((value | 4) << 8);
            GX_LoadBG2Scr(gRaceHud->mNscrs[0]->mData, 0, 0x600);
        }
        GXS_LoadBG0Scr(GetChoisesSListScreenMapData(), 0, 0x600);
        value = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((value | 1) << 8);
        G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0x3e, 0x3f, 8, 8, -7);
    } else {
        value = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((value & ~1) << 8);
        value = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((value & ~4) << 8);
        G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    }
    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex++) {
        if (gRaceHud->mKartRemoved[kartIndex] != 0 && gRaceHud->mRemovedSoundPlayed[kartIndex] == 0) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x52);
            gRaceHud->mRemovedSoundPlayed[kartIndex] = 1;
        }
    }
}

void InitRaceHud(void) {
    s32 index;
    u32 raceKind;
    u16 *choisesSBPalette;
    u32 colorIndex;
    u16 paletteColor;

    raceKind = gRaceSetup->mRaceKind;
    if (raceKind == RACE_KIND_START_GP) {
        InitRaceStartGp();
        return;
    }
    if (raceKind == RACE_KIND_AWARD) {
        return;
    }
    if (raceKind == RACE_KIND_STAFF_ROLL) {
        InitEndingStaffRoll();
        InitStaffRollText(GetHeap(GetCurrentHeapCall()));
        return;
    }
    gRaceHud = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x914);
    InitRaceStartSequence();
    InitRaceEnd();
    InitRaceHudSubScreenProjection();
    InitRaceNcerNclrNcgrTables();
    InitRaceHudSubScreenBgColors();
    if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
        InitRaceStartBattle();
    }
    InitRaceItemSlot();
    InitRaceLinkLevel();
    InitRaceModeCount();
    InitRaceGoalM();
    InitRaceTimeDigits();
    InitRaceLapNumber();
    InitRaceMNumberPair();
    InitRaceGoalTimes();
    InitRaceRankList();
    InitRaceHudSubScreenCellGroups();
    InitRaceGoalS();
    InitRaceNewRecordTa();
    InitRaceTaPositions();
    gRaceHud->mUpdateFrames = 0;
    for (index = 0; index < 7; index++) {
        gRaceHud->mNclrs[index] = NULL;
        gRaceHud->mNcgrs[index] = NULL;
    }
    gRaceHud->mSubScreenState = 1;
    gRaceHud->mSubScreenEnabled = FALSE;
    gRaceHud->mSubScreenState5LoadPending = FALSE;
    gRaceHud->mRaceGoalSShown = FALSE;
    gRaceHud->mGoalMStarted = FALSE;
    gRaceHud->mGoalMUploadPending = FALSE;
    gRaceHud->mGoalMUploadFrames = 0;
    gRaceHud->mGoalMUploaded = 0;
    gRaceHud->mGoalMEnabled = 0;
    gRaceHud->mGoalMDelayFrameCount = 0;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        switch (gRaceSetup->mCourseId) {
            case COURSE_ID_MINI_STAGE3:
                gRaceHud->mSubScreenCourseScale = 0x40;
                break;
            default:
                gRaceHud->mSubScreenCourseScale = 0x64;
                break;
        }
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        switch (gRaceSetup->mCourseId) {
            case COURSE_ID_MR_STAGE1:
            case COURSE_ID_MR_STAGE2:
            case COURSE_ID_MR_STAGE3:
            case COURSE_ID_MR_STAGE4:
                gRaceHud->mSubScreenCourseScale = 0x64;
                break;
            default:
                gRaceHud->mSubScreenCourseScale = 0x86;
                break;
        }
    } else {
        gRaceHud->mSubScreenCourseScale = 0x86;
    }
    gRaceHud->mEnabled = FALSE;
    for (index = 0; index < 8; index++) {
        gRaceHud->mKartRemoved[index] = 0;
        gRaceHud->mRemovedSoundPlayed[index] = 0;
    }
    gRaceHud->mShowLapTime = 0;
    gRaceHud->mShowLapTimeFrames = -1;
    if (gRaceSetup->mMode == MODE_TIME_ATTACK && gRaceSetup->mKartCount > 1) {
        gRaceHud->mUseTimeDifference = 1;
    } else {
        gRaceHud->mUseTimeDifference = 0;
    }
    gRaceHud->mStepHasRun = 0;
    gRaceHud->mUnfilledNotEliminatedSet = FALSE;
    gRaceHud->mMissionRunRecordFilled = gRaceSetup->mMode == MODE_MISSION_RUN ? IsMissionRunRecordFilled() : 0;
    MI_DmaFill32(3, &gRaceHud->mMainOam, 0xc0, 0x400);
    MI_DmaFill32(3, &gRaceHud->mSubOam, 0xc0, 0x400);
    LoadNclrData(&gRaceHud->mNclrs[0], FindSceneFileWrapper("race_m_b.NCLR"));
    LoadNcgrData(&gRaceHud->mNcgrs[0], FindSceneFileWrapper("race_m_b.NCGR"));
    LoadNscrData(&gRaceHud->mNscrs[0], FindSceneFileWrapper("race_m_pause.NSCR"));
    LoadNscrData(&gRaceHud->mNscrs[1], FindSceneFileWrapper("race_m_goal.NSCR"));
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        LoadNclrData(&gRaceHud->mNclrs[1], FindSceneFileWrapper("race_new_record_ta_s_b.NCLR"));
        LoadNcgrData(&gRaceHud->mNcgrs[1], FindSceneFileWrapper("race_new_record_ta_s_b.NCGR"));
        LoadNscrData(&gRaceHud->mNscrs[2], FindSceneFileWrapper("race_new_record_ta_s_bg.NSCR"));
        DC_FlushRange(((Ncgr *) gRaceHud->mNscrs[0])->mData, ((Ncgr *) gRaceHud->mNscrs[0])->mDataSize);
        DC_FlushRange(gRaceHud->mNscrs[2]->mData, gRaceHud->mNscrs[2]->mDataSize);
    }
    choisesSBPalette = GetChoisesSBNclr()->mData;
    for (index = 0; index < 0x80; index++) {
        gRaceHudSubScreenPalettes[index + 0x80] = choisesSBPalette[index + 0x80];
    }
    GetChoisesSBNclr()->mData[0] = gRaceHudSubScreenPalettes[0x100];
    DC_FlushRange(GetChoisesSBNclr()->mData, 0x200);
    for (index = 0; index < 0x20; index++) {
        paletteColor = GetChoisesSBNclr()->mData[index + 0xe0];
        GetRaceGoalSBPaletteAndChars(0)->mPalette->mData[index + 0xe0] = paletteColor;
    }
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        CopyPlayerCharacterToRaceGoalMO(GetRaceNclrNcgr(1)->mNclr->mData, GetRaceNclrNcgr(1)->mNcgr->mData);
        DC_FlushRange(GetRaceNclrNcgr(1)->mNclr->mData, GetRaceNclrNcgr(1)->mNclr->mDataSize);
        DC_FlushRange(GetRaceNclrNcgr(1)->mNcgr->mData, GetRaceNclrNcgr(1)->mNcgr->mDataSize);
    }
    FillRaceSOPaletteAndChars(GetRaceNclrNcgr(6)->mNclr->mData, GetRaceNclrNcgr(6)->mNcgr->mData);
    DC_FlushRange(GetRaceNclrNcgr(6)->mNclr->mData, GetRaceNclrNcgr(6)->mNclr->mDataSize);
    DC_FlushRange(GetRaceNclrNcgr(6)->mNcgr->mData, GetRaceNclrNcgr(6)->mNcgr->mDataSize);
    CopyCharsBlock(GetRaceNclrNcgr(6)->mNcgr->mData, 0x10, 0, 0x10, 2, GetRaceNclrNcgr(7)->mNcgr->mData, 0x10, 0);
    DC_FlushRange(GetRaceNclrNcgr(7)->mNcgr->mData, GetRaceNclrNcgr(7)->mNcgr->mDataSize);
    CopyCharsBlock(GetRaceNclrNcgr(6)->mNcgr->mData, 0x10, 0, 0x10, 2, GetRaceNclrNcgr(8)->mNcgr->mData, 0x10, 0);
    DC_FlushRange(GetRaceNclrNcgr(8)->mNcgr->mData, GetRaceNclrNcgr(8)->mNcgr->mDataSize);
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        CopyCharsBlock(GetRaceNclrNcgr(6)->mNcgr->mData, 0x10, 0, 0x10, 2, GetRaceNclrNcgr(9)->mNcgr->mData, 0x10, 0);
        DC_FlushRange(GetRaceNclrNcgr(9)->mNcgr->mData, GetRaceNclrNcgr(9)->mNcgr->mDataSize);
    }
    ResetRaceStartSequenceFrames();
    ResetRaceEndFrames();
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        gMenuShared->mUnfilledNotEliminated = 0;
    }
}

static inline void InitMap2D_inline(u16 *screenMap) {
    s32 columnIndex;
    s32 rowIndex;
    u16 *screenMapCopy = screenMap;

    for (rowIndex = 3; rowIndex < 24; rowIndex++) {
        s32 rowStart = rowIndex * 32;
        for (columnIndex = 14; columnIndex < 32; columnIndex++) {
            s32 index = columnIndex + rowStart;
            s32 mirroredIndex = rowStart + (45 - columnIndex);
            if (index < mirroredIndex) {
                u16 tile = screenMapCopy[mirroredIndex];
                screenMapCopy[mirroredIndex] = screenMapCopy[index];
                screenMapCopy[index] = tile;
            }
            screenMapCopy[index] ^= 0x400;
        }
    }
}

void InitMap2D(void) {
    Nclr *nclrs[3];
    Ncgr *ncgrs[3];
    Nscr *nscrs[4];
    BOOL hasGlobalFiles;
    s32 index;
    s32 shineBattleFlag;

    hasGlobalFiles = gRaceSetup->mMode != MODE_MISSION_RUN;
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD || gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    gRaceHudSubScreenPalettes = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x400);
    for (index = 0; index < 2; index++) {
        nclrs[index] = NULL;
        ncgrs[index] = NULL;
    }
    for (index = 0; index < 3; index++) {
        nscrs[index] = NULL;
    }

    if (ShouldLoadMap2DData()) {
        if (hasGlobalFiles) {
            LoadNclrData(&nclrs[0], FindCourseFileWrapper("Map2D/global.NCLR"));
            LoadNclrData(&nclrs[1], FindCourseFileWrapper("Map2D/global2.NCLR"));
        }
        LoadNclrData(&nclrs[2], FindCourseFileWrapper("Map2D/local.NCLR"));
    } else {
        if (hasGlobalFiles) {
            LocateNclr(&nclrs[0], FindCourseFileWrapper("Map2D/global.NCLR"));
            LocateNclr(&nclrs[1], FindCourseFileWrapper("Map2D/global.NCLR"));
        }
        LocateNclr(&nclrs[2], FindCourseFileWrapper("Map2D/local.NCLR"));
    }

    if (ShouldLoadMap2DData()) {
        if (hasGlobalFiles) {
            LoadNcgrData(&ncgrs[0], FindCourseFileWrapper("Map2D/global.NCGR"));
            LoadNcgrData(&ncgrs[1], FindCourseFileWrapper("Map2D/global2.NCGR"));
        }
        LoadNcgrData(&ncgrs[2], FindCourseFileWrapper("Map2D/local.NCGR"));
    } else {
        if (hasGlobalFiles) {
            LocateNcgr(&ncgrs[0], FindCourseFileWrapper("Map2D/global.NCGR"));
            LocateNcgr(&ncgrs[1], FindCourseFileWrapper("Map2D/global2.NCGR"));
        }
        LocateNcgr(&ncgrs[2], FindCourseFileWrapper("Map2D/local.NCGR"));
    }

    if (ShouldLoadMap2DData()) {
        if (hasGlobalFiles) {
            LoadNscrData(&nscrs[0], FindCourseFileWrapper("Map2D/global1.NSCR"));
            LoadNscrData(&nscrs[1], FindCourseFileWrapper("Map2D/global2.NSCR"));
        }
        LoadNscrData(&nscrs[2], FindCourseFileWrapper("Map2D/local2.NSCR"));
        if (IsCourseWithMap2DLocal3()) {
            LoadNscrData(&nscrs[3], FindCourseFileWrapper("Map2D/local3.NSCR"));
        }
    } else {
        if (hasGlobalFiles) {
            LocateNscr(&nscrs[0], FindCourseFileWrapper("Map2D/global1.NSCR"));
            LocateNscr(&nscrs[1], FindCourseFileWrapper("Map2D/global2.NSCR"));
        }
        LocateNscr(&nscrs[2], FindCourseFileWrapper("Map2D/local2.NSCR"));
        if (IsCourseWithMap2DLocal3()) {
            LocateNscr(&nscrs[3], FindCourseFileWrapper("Map2D/local3.NSCR"));
        }
    }

    if (hasGlobalFiles) {
        if (gRaceSetup->mMirrorMode != 0) {
            InitMap2D_inline(nscrs[0]->mData);
        }
        shineBattleFlag = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            shineBattleFlag = 1;
        }
        for (index = 0; index < 16; index++) {
            nclrs[0]->mData[index + 16] = nclrs[1]->mData[(shineBattleFlag + 1) * 16 + index];
        }
        for (index = 0; index < 0x400; index++) {
            s32 entryLowBits = nscrs[1]->mData[index];
            entryLowBits %= 0x400;
            nscrs[1]->mData[index] =
                (u16) (nscrs[1]->mData[index] & 0xfc00) | (entryLowBits + ((shineBattleFlag + 6) << 5));
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
    GXS_LoadBGExtPltt(nclrs[2]->mData, 0x4000, 0x200);
    GXS_LoadBGExtPltt(nclrs[2]->mData, 0x6000, 0x200);
    GXS_EndLoadBGExtPltt();
    for (index = 0; index < 0x100; index++) {
        if (hasGlobalFiles) {
            gRaceHudSubScreenPalettes[index] = nclrs[0]->mData[index];
        }
        (gRaceHudSubScreenPalettes + index)[0x100] = nclrs[2]->mData[index];
    }
    if (hasGlobalFiles) {
        DC_FlushRange(gRaceHudSubScreenPalettes, 0x200);
    }
    DC_FlushRange(gRaceHudSubScreenPalettes + 0x100, 0x200);
}

void SetupRaceHudScreens(void) {
    u32 raceKind;
    u16 value;

    raceKind = gRaceSetup->mRaceKind;
    if (raceKind == RACE_KIND_START_GP) {
        return;
    }
    if (raceKind == RACE_KIND_AWARD || raceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    value = gCourseMap->mSettings->mColorAndFogAlpha & 0x7fff;
    *(vu16 *) HW_BG_PLTT = value;
    gRaceHud->mNclrs[0]->mData[0] = value;
    DC_FlushRange(gRaceHud->mNclrs[0]->mData, gRaceHud->mNclrs[0]->mDataSize);
    GX_LoadBGPltt(gRaceHud->mNclrs[0]->mData, 0, gRaceHud->mNclrs[0]->mDataSize);
    GX_LoadBG2Char(gRaceHud->mNcgrs[0]->mData, 0, gRaceHud->mNcgrs[0]->mDataSize);
    GX_LoadBG2Scr(gRaceHud->mNscrs[0]->mData, 0, gRaceHud->mNscrs[0]->mDataSize);
    GX_LoadOBJPltt(GetRaceNclrNcgr(0)->mNclr->mData, 0, GetRaceNclrNcgr(0)->mNclr->mDataSize);
    GX_LoadOBJ(GetRaceNclrNcgr(0)->mNcgr->mData, 0, 0x4000);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0xe000) | 0xe000;
    value = reg_G2_WININ;
    reg_G2_WININ = (u32) ((value & ~0x3f) | 0x1f) | 0x20;
    reg_G2_WIN0H = 0xff;
    reg_G2_WIN0V = 0x60c0;
    reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f00) | 0x1f00) | 0x2000;
    reg_G2_WIN1H = 0x40ff;
    reg_G2_WIN1V = 0x60;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f00) | 0x1200) | 0x2000;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xf) | 0x20;
    reg_GXS_DB_DISPCNT &= ~0xe000;
    GXS_SetGraphicsMode(5);
    GXS_LoadOBJPltt(GetRaceNclrNcgr(6)->mNclr->mData, 0, GetRaceNclrNcgr(6)->mNclr->mDataSize);
    GXS_LoadOBJ(GetRaceNclrNcgr(6)->mNcgr->mData, 0, 0x4000);
    InitSubScreenGraphicsMode0();
    GXS_LoadBG1Scr(GetRaceGoalSNscr(0)->mData, 0, GetRaceGoalSNscr(0)->mDataSize);
    GXS_LoadBG2Scr(GetRaceGoalSNscr(1)->mData, 0, GetRaceGoalSNscr(1)->mDataSize);
    GXS_LoadBG3Scr(GetRaceGoalSNscr(2)->mData, 0, GetRaceGoalSNscr(2)->mDataSize);
    GXS_LoadBGPltt(gRaceHudSubScreenPalettes + 0x100, 0, 0x200);
    CopyRaceHudSubScreenBgColors();
    GX_SetBankForSubBGExtPltt(0x80);
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(gRaceHudSubScreenPalettes + 0x100, 0x4000, 0x200);
    GXS_LoadBGExtPltt(gRaceHudSubScreenPalettes + 0x100, 0x6000, 0x200);
    GXS_EndLoadBGExtPltt();
    GXS_LoadBGPltt(GetChoisesSBNclr()->mData, 0, 0x200);
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
    reg_G2S_DB_BG0CNT &= ~0x40;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x10c;
    GXS_LoadBG0Char(GetChoisesSBNcgrWithListChars()->mData, 0, GetChoisesSBNcgrWithListChars()->mDataSize);
    GXS_LoadBG0Scr(GetChoisesSListScreenMapData(), 0, 0x600);
    InitSubScreenGraphicsMode5();
    gRaceHud->mEnabled = TRUE;
}

// Clears the HUD pointers and display bits; nothing is freed here.
void ReleaseRaceHud(void) {
    u32 raceKind;

    raceKind = gRaceSetup->mRaceKind;
    if (raceKind == RACE_KIND_START_GP) {
        ClearRaceStartGpPointer();
        return;
    }
    if (raceKind == RACE_KIND_AWARD) {
        return;
    }
    if (raceKind == RACE_KIND_STAFF_ROLL) {
        ClearStaffRollTextPointer();
        ClearEndingStaffRollPointer();
        return;
    }
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 0, 0, 0x10, 0x10);
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0, 0x10, 0x10);
    gRaceHud = NULL;
    ClearRaceStartSequencePointer();
    ClearRaceEndPointer();
    ClearRaceHudSubScreenProjection();
    ClearRaceNcerNclrNcgrTablesPointer();
    if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
        ClearRaceStartBattlePointer();
    }
    ClearRaceItemSlotPointer();
    ClearRaceLinkLevelPointer();
    ClearRaceModeCountPointer();
    ClearRaceGoalMPointer();
    ClearRaceTimeDigitsPointer();
    ClearRaceLapNumberPointer();
    ClearRaceMNumberPairPointer();
    ClearRaceGoalTimesPointer();
    ClearRaceRankListPointer();
    ClearRaceHudSubScreenCellGroups();
    ClearRaceGoalSPointer();
    ClearRaceNewRecordTaPointer();
    ClearRaceTaPositionsPointer();
    reg_GX_DISPCNT &= ~0xe000;
    reg_GXS_DB_DISPCNT &= ~0xe000;
}

void UpdateRaceHud(void) {
    u32 kind;

    if (gRaceHud != NULL) {
        gRaceHud->mStepHasRun = 1;
    }
    kind = gRaceSetup->mRaceKind;
    if (kind == RACE_KIND_START_GP) {
        UpdateRaceStartGp();
        return;
    }
    if (kind == RACE_KIND_AWARD) {
        return;
    }
    if (kind == RACE_KIND_STAFF_ROLL) {
        UpdateEndingStaffRoll();
        AdvanceStaffRollText();
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    if (gRaceHud->mShowLapTime != 0) {
        gRaceHud->mShowLapTimeFrames++;
        if (gRaceHud->mShowLapTimeFrames >= 0x80) {
            gRaceHud->mShowLapTime = 0;
            gRaceHud->mShowLapTimeFrames = -1;
        }
    }
    UpdateRaceStartSequence();
    UpdateRaceEnd();
    if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
        UpdateRaceStartBattleNop();
    }
    kind = gRaceSetup->mMode;
    if ((kind == MODE_BATTLE ? gRaceProgress->mRaceDone
         : kind == MODE_MISSION_RUN
             ? IsFramesSinceFinishPastWait()
             : (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceHud->mShowLapTime == 0)) == 0) {
        UpdateRaceItemSlot();
        UpdateRaceLapNumber();
        UpdateRaceMNumberPairNop();
        UpdateRaceGoalTimes();
        UpdateRaceModeCount();
        UpdateRaceGoalM();
    } else {
        StopRaceItemSlotSound();
        UpdateRaceLapNumber();
        UpdateRaceGoalTimes();
        UpdateRaceGoalM();
    }
    UpdateRaceTimeDigits();
    UpdateRaceRankList();
    switch (gRaceHud->mSubScreenState) {
        case 0:
        case 1:
        case 2:
        case 3:
            UpdateRaceHudSubScreenCellGroups();
            UpdateRaceTaPositions();
            break;
        case 4:
        case 5:
            UpdateRaceGoalS();
            break;
        case 6:
            break;
    }
    UpdateRaceNewRecordTa();
    gRaceHud->mUpdateFrames++;
    if (gRaceHud->mUpdateFrames >= 0xc00) {
        gRaceHud->mUpdateFrames = 0;
    }
}

void UpdateRaceHudSubScreen(void) {
    BOOL subScreenEnabled;
    BOOL switchPressed;
    BOOL switchAllowed;
    BOOL raceKindAllowsSwitch;
    BOOL condition;
    s32 value;

    UpdateRaceLinkLevel();
    if (gRaceSetup->mRaceKind - 3 <= 3) {
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
            if (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceHud->mShowLapTime == 0) {
                if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                    if (gRaceHud->mGoalMStarted != FALSE) {
                        gRaceHud->mSubScreenEnabled = FALSE;
                    } else {
                        gRaceHud->mSubScreenEnabled = TRUE;
                        gRaceHud->mSubScreenState = 4;
                        gRaceHud->mGoalMStarted = TRUE;
                        gRaceHud->mGoalMUploadPending = TRUE;
                        gRaceHud->mGoalMDelayFrameCount = 0xc;
                    }
                } else if (gRaceHud->mGoalMStarted == FALSE) {
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    gRaceHud->mGoalMDelayFrameCount = 0xc;
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                condition = TRUE;
                            }
                        } else {
                            condition = FALSE;
                        }
                        if (condition == FALSE) {
                            switchPressed = FALSE;
                        }
                    }
                    if (switchPressed != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    switch (gRaceHud->mSubScreenState) {
                        case 0:
                            gRaceHud->mSubScreenState = 1;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                            break;
                        case 1:
                            gRaceHud->mSubScreenState = 0;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                            break;
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_TIME_ATTACK:
            if (gRaceProgress->mRaceDone != 0 && gRaceHud->mShowLapTime == 0) {
                if (gRaceHud->mGoalMStarted == FALSE) {
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    gRaceHud->mGoalMDelayFrameCount = 0xc;
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                condition = TRUE;
                            }
                        } else {
                            condition = FALSE;
                        }
                        if (condition == FALSE) {
                            switchPressed = FALSE;
                        }
                    }
                    if (switchPressed != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    if (gRaceSetup->mRaceKind != RACE_KIND_REPLAY) {
                        switch (gRaceHud->mSubScreenState) {
                            case 0:
                                gRaceHud->mSubScreenState = 1;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                                break;
                            case 1:
                                gRaceHud->mSubScreenState = 0;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                                break;
                        }
                    } else {
                        switch (gRaceHud->mSubScreenState) {
                            case 0:
                                gRaceHud->mSubScreenState = 1;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                                break;
                            case 1:
                                gRaceHud->mSubScreenState = 2;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                                break;
                            case 2:
                                gRaceHud->mSubScreenState = 0;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                                break;
                        }
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_BATTLE:
            if (IsWinnerDecidedAndEndReached() != 0) {
                if (gRaceHud->mGoalMStarted != FALSE) {
                    gRaceHud->mSubScreenEnabled = FALSE;
                } else {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    gRaceHud->mSubScreenState = 4;
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    gRaceHud->mGoalMDelayFrameCount = 0x8c;
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                condition = TRUE;
                            }
                        } else {
                            condition = FALSE;
                        }
                        if (condition == FALSE) {
                            switchPressed = FALSE;
                        }
                    }
                    if (switchPressed != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    switch (gRaceHud->mSubScreenState) {
                        case 0:
                            gRaceHud->mSubScreenState = 1;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                            break;
                        case 1:
                            gRaceHud->mSubScreenState = 0;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                            break;
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_VS:
        case 5:
            if (gRaceProgress->mRaceDone != 0 && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                if (gRaceHud->mRaceGoalSShown == FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    gRaceHud->mSubScreenState = 4;
                    gRaceHud->mRaceGoalSShown = TRUE;
                    if (gRaceHud->mGoalMStarted == FALSE) {
                        gRaceHud->mGoalMStarted = TRUE;
                        gRaceHud->mGoalMUploadPending = TRUE;
                        gRaceHud->mGoalMDelayFrameCount = 0x8c;
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            } else if (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                if (gRaceHud->mGoalMStarted == FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    gRaceHud->mSubScreenState = 0;
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    gRaceHud->mGoalMDelayFrameCount = 0x8c;
                } else {
                    subScreenEnabled = FALSE;
                    switchAllowed = FALSE;
                    raceKindAllowsSwitch = FALSE;
                    if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                        raceKindAllowsSwitch = TRUE;
                    }
                    if (raceKindAllowsSwitch != FALSE) {
                        if (IsChoisesSPickLocked() == 0) {
                            switchAllowed = TRUE;
                        }
                    }
                    if (switchAllowed != FALSE) {
                        switchPressed = TRUE;
                        if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                            condition = FALSE;
                            if (IsChoisesSOpen() == 0) {
                                if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                    condition = TRUE;
                                }
                            } else {
                                condition = FALSE;
                            }
                            if (condition == FALSE) {
                                switchPressed = FALSE;
                            }
                        }
                        if (switchPressed != FALSE) {
                            subScreenEnabled = TRUE;
                        }
                    }
                    if (subScreenEnabled != FALSE) {
                        gRaceHud->mSubScreenEnabled = TRUE;
                        switch (gRaceHud->mSubScreenState) {
                            case 0:
                                gRaceHud->mSubScreenState = 3;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                                break;
                            case 3:
                                gRaceHud->mSubScreenState = 0;
                                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                                break;
                        }
                    } else {
                        gRaceHud->mSubScreenEnabled = FALSE;
                    }
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (gRaceSetup->mRaceKind != RACE_KIND_DEMO && gRaceSetup->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (gInputSlots[GetPadInputSlot()].mPair.mNoPairCount == 5) {
                                condition = TRUE;
                            }
                        } else {
                            condition = FALSE;
                        }
                        if (condition == FALSE) {
                            switchPressed = FALSE;
                        }
                    }
                    if (switchPressed != FALSE) {
                        subScreenEnabled = TRUE;
                    }
                }
                if (subScreenEnabled != FALSE) {
                    gRaceHud->mSubScreenEnabled = TRUE;
                    switch (gRaceHud->mSubScreenState) {
                        case 0:
                            gRaceHud->mSubScreenState = 1;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x18);
                            break;
                        case 1:
                            gRaceHud->mSubScreenState = 0;
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x17);
                            break;
                    }
                } else {
                    gRaceHud->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_MISSION_RUN:
            if (IsFramesSinceFinishPastWait() != FALSE) {
                if (gRaceHud->mGoalMStarted == FALSE) {
                    gRaceHud->mGoalMStarted = TRUE;
                    gRaceHud->mGoalMUploadPending = TRUE;
                    if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0) {
                        value = gRaceProgress->mEntryEndKind;
                    } else {
                        value = 6;
                    }
                    if (value == 0) {
                        gRaceHud->mGoalMDelayFrameCount = 0xaf;
                    }
                }
            } else if (gRaceProgress->mRaceDone != 0) {
                if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0) {
                    value = gRaceProgress->mEntryEndKind;
                } else {
                    value = 6;
                }
                if (value != 0) {
                    gRaceHud->mGoalMEnabled = 1;
                }
            }
            if ((u16) (data_0217562c[GetPadInputSlot()].mPressedBits & 0x800) != 0) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x19);
            }
            gRaceHud->mSubScreenEnabled = FALSE;
            break;
    }
    if (gRaceHud->mSubScreenEnabled != FALSE) {
        switch (gRaceHud->mSubScreenState) {
            case 0:
                UpdateRaceHudSubScreenCellGroups();
                break;
            case 1:
            case 2:
            case 3:
                UpdateRaceHudSubScreenCellGroups();
                UpdateRaceTaPositions();
                break;
            case 4:
            case 5:
                UpdateRaceGoalS();
                break;
            case 6:
                UpdateRaceNewRecordTa();
                break;
        }
    }
    if (gRaceHud->mUnfilledNotEliminatedSet != FALSE) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        value = (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1) == 9;
    } else {
        value = 0;
    }
    if (value == 0) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        value = 0;
    } else {
        value = IsWinnerDecidedAndEndReached();
    }
    if (value == 0) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        value = 0;
    } else {
        value = IsKartEliminated(GetFollowedKartOrEntryIndex());
    }
    if (value != 0) {
        gMenuShared->mUnfilledNotEliminated = 0;
    } else {
        gMenuShared->mUnfilledNotEliminated = gRaceHud->mMissionRunRecordFilled == 0;
    }
    gRaceHud->mUnfilledNotEliminatedSet = TRUE;
}

void DrawRaceHud(void) {
    u32 raceKindOrMode;
    s32 subScreenState;

    raceKindOrMode = gRaceSetup->mRaceKind;
    if (raceKindOrMode == RACE_KIND_START_GP) {
        DrawRaceStartGp();
        return;
    }
    if (raceKindOrMode == RACE_KIND_AWARD) {
        return;
    }
    if (raceKindOrMode == RACE_KIND_STAFF_ROLL) {
        DrawEndingStaffRoll();
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    UpdateRaceStartSequenceSounds();
    RaceHudDrawNop();
    gRaceHud->mMainOam.mOamCount = 0;
    gRaceHud->mMainOam.mMatrixCount = 0;
    if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
        DrawRaceStartBattle(&gRaceHud->mMainOam);
    }
    raceKindOrMode = gRaceSetup->mMode;
    if ((raceKindOrMode == MODE_BATTLE ? gRaceProgress->mRaceDone
         : raceKindOrMode == MODE_MISSION_RUN
             ? IsFramesSinceFinishPastWait()
             : (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceHud->mShowLapTime == 0)) == 0) {
        DrawRaceItemSlot(&gRaceHud->mMainOam);
        DrawRaceLapAndTimeDifference(&gRaceHud->mMainOam);
        DrawRaceMNumberPair(&gRaceHud->mMainOam);
        DrawRaceGoalTimes(&gRaceHud->mMainOam);
        DrawRaceLinkLevel(&gRaceHud->mMainOam);
        DrawRaceModeCount(&gRaceHud->mMainOam);
        DrawRaceGoalM(&gRaceHud->mMainOam);
    } else {
        DrawRaceGoalTimes(&gRaceHud->mMainOam);
        DrawRaceLinkLevel(&gRaceHud->mMainOam);
        DrawRaceGoalM(&gRaceHud->mMainOam);
    }
    DC_FlushRange(&gRaceHud->mMainOam, 0x400);
    MI_DmaFill32(3, &gRaceHud->mMainOam.mOams[gRaceHud->mMainOam.mOamCount], 0xc0,
                 (0x80 - gRaceHud->mMainOam.mOamCount) << 3);
    gRaceHud->mSubOam.mOamCount = 0;
    gRaceHud->mSubOam.mMatrixCount = 0;
    subScreenState = gRaceHud->mSubScreenState;
    if (subScreenState != 4 && subScreenState != 5) {
        DrawRaceTimeDigits(&gRaceHud->mSubOam);
    }
    DrawRaceRankList(&gRaceHud->mSubOam);
    DC_FlushRange(&gRaceHud->mSubOam, 0x400);
    MI_DmaFill32(3, &gRaceHud->mSubOam.mOams[gRaceHud->mSubOam.mOamCount], 0xc0,
                 (0x80 - gRaceHud->mSubOam.mOamCount) << 3);
    switch (gRaceHud->mSubScreenState) {
        case 0:
            DrawRaceHudSubScreenCellGroups(&gRaceHud->mSubOam);
            break;
        case 1:
        case 2:
        case 3:
            DrawRaceHudSubScreenCellGroups(&gRaceHud->mSubOam);
            DrawRaceTaPositions(&gRaceHud->mSubOam);
            break;
        case 4:
        case 5:
            DrawRaceGoalS(&gRaceHud->mSubOam);
            break;
        case 6:
            DrawRaceNewRecordTa(&gRaceHud->mSubOam);
            break;
    }
}
