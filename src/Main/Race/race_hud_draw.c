#include "Main/Race/race_hud_draw.h"
#include "Main/Race/race_end_condition.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Menu/title_scene.h"
#include "thread_scheduler.h"
#include "Main/Menu/choises_s_list_chars.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/Race/race_end.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_nclr_ncgr.h"
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
#include "Main/Item/item_objects_and_race_progress.h"
#include "arena_cache_init.h"
#include "fixed_point_graphics_setup.h"
#include "vram_bank_display_setup.h"
#include "display_blend_affine_setup.h"
#include "vram_load_2d_graphics.h"
#include "registers.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/oam.h"
#include "Main/System/heap_call.h"
#include "Main/Menu/choises_s.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Race/race_goal_player_character.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "sprite_animation_control.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "dma_copy_fill_wait.h"
#include "Main/Race/kart.h"
#include "Main/Race/standings_balloons.h"
#include "Main/System/input_slots.h"
#include "Main/Race/race_hud_draw_nop.h"
#include "Main/Race/race_goal_s_draw.h"
#include "Main/Race/race_m_number_pair.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/init_after_startup.h"

RaceHud *g_GlobalB350;
u16 *gRaceHudSubScreenPalettes;

BOOL GetShowLapTime(void) {
    return (g_GlobalB350->mShowLapTime);
}

u32 GetShowLapTimeFrames(void) {
    return (g_GlobalB350->mShowLapTimeFrames);
}

u32 GetUseTimeDifference(void) {
    return (g_GlobalB350->mUseTimeDifference);
}

void GetRaceHudTimeDifference(s32 **outSign, TimeDigits **outDigits) {
    *outSign = &g_GlobalB350->mTimeDifferenceSign;
    *outDigits = &g_GlobalB350->mTimeDifferenceDigits;
}

u32 GetRaceHudStepHasRun(void) {
    return (g_GlobalB350->mStepHasRun);
}

void InitSubScreenGraphicsMode5(void) {
    if (MaybeCircuitUsesLocal3() != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1c00;
    } else {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1400;
    }
    SetDispcntSubBgMode(GX_BGMODE_5);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 2;
    reg_G2S_DB_BG2CNT &= ~REG_G2S_DB_BG2CNT_MOSAIC_MASK;
    reg_G2S_DB_BG3CNT &= ~REG_G2S_DB_BG3CNT_MOSAIC_MASK;
    reg_G2S_DB_BG2CNT =
        (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0x8410;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG3CNT &= ~REG_G2S_DB_BG3CNT_MOSAIC_MASK;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) |
                        0x8810 | ((IsCourseWithSubBg3AreaOverflow() != 0) << 13);
}

void InitSubScreenGraphicsMode0(void) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1e00;
    SetDispcntSubBgMode(GX_BGMODE_0);
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT &= ~REG_G2S_DB_BG1CNT_MOSAIC_MASK;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 8;
    reg_G2S_DB_BG2OFS = 0x100;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 2;
    reg_G2S_DB_BG2CNT &= ~REG_G2S_DB_BG2CNT_MOSAIC_MASK;
    reg_G2S_DB_BG2CNT =
        (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0x4c08;
    reg_G2S_DB_BG3OFS = 0x100;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 2;
    reg_G2S_DB_BG3CNT &= ~REG_G2S_DB_BG3CNT_MOSAIC_MASK;
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x4e08;
}

void UploadRaceHud(void) {
    s32 kartIndex;
    u32 kind;
    s32 value;
    s32 scrollOffset;

    kind = g_GlobalCO->mRaceKind;
    if (kind == RACE_KIND_START_GP) {
        LoadRaceIntroDataOam();
        return;
    }
    if (kind == RACE_KIND_AWARD) {
        return;
    }
    if (kind == RACE_KIND_STAFF_ROLL) {
        *(vu16 *) HW_BG_PLTT = 0;
        LoadStaffRollDataOam();
        SetStaffRollScrollAndDrainQueue();
        return;
    }
    if (g_GlobalB350->mEnabled == FALSE) {
        return;
    }
    if (g_GlobalB350->mGoalMUploadPending != FALSE) {
        CopyBgData_Bg0_Bottom(GetSomeBgTileData_from_thumb()->mData, 0, 0x3000);
        g_GlobalB350->mGoalMUploadPending = FALSE;
        CopySomePaletteData(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_M)->mNclr->mData, 0,
                       GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_M)->mNclr->mDataSize);
        CopyTileDataTop_0(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_M)->mNcgr->mData, 0, 0x4000);
        g_GlobalB350->mGoalMUploaded = 1;
        g_GlobalB350->mGoalMUploadFrames = 1;
        reg_GX_DISPCNT &= ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
    } else if (g_GlobalB350->mGoalMUploadFrames != 0) {
        if (IsRaceOptionMenuOn_from_thumb() == 0) {
            if (g_GlobalB350->mGoalMUploadFrames++ >= g_GlobalB350->mGoalMDelayFrameCount) {
                if (g_GlobalCO->mMode == MODE_GRAND_PRIX && g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
                    value = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
                    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((value | 8) << 8);
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~REG_G2_BG3CNT_PRIORITY_MASK) | 1;
                    reg_G2_BG3CNT &= ~REG_G2_BG3CNT_MOSAIC_MASK;
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & (REG_G2_BG3CNT_PRIORITY_MASK | REG_G2_BG3CNT_MOSAIC_MASK)) | 0x500;
                    CopyPaletteTop(g_GlobalB350->mNclrs[0]->mData, 0, g_GlobalB350->mNclrs[0]->mDataSize);
                    CopyBgData_Bg3_Top(g_GlobalB350->mNcgrs[0]->mData, 0, g_GlobalB350->mNcgrs[0]->mDataSize);
                    TEQSub_Fn11Impl_Fn13Impl(g_GlobalB350->mNscrs[1]->mData, 0, 0x600);
                    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 8, 0x27, 5, 9);
                }
                g_GlobalB350->mGoalMUploadFrames = 0;
                g_GlobalB350->mGoalMEnabled = 1;
            }
        }
    }
    kind = g_GlobalCO->mMode;
    if (kind == MODE_GRAND_PRIX && g_GlobalB350->mGoalMEnabled != 0) {
        reg_G2_BG3OFS = 0x01ff0000 & (ComputeValueInterpolation_from_thumb(1, -64, 0, GetB3F0_Beb1(), 20) << 16);
    } else if (kind == MODE_MISSION_RUN && g_GlobalB350->mGoalMEnabled != 0) {
        CopyBgData_Bg0_Bottom(GetSomeBgTileData_from_thumb()->mData, 0, 0x3000);
        TEQSub_Fn24Impl(GetChoisesSListScreenMapData(), 0, 0x600);
    }
    Arm_FlushRange(&g_GlobalB350->mMainOam, 0x400);
    CopyToOamA(&g_GlobalB350->mMainOam, 0, 0x400);
    Arm_FlushRange(&g_GlobalB350->mSubOam, 0x400);
    CopyToOamB(&g_GlobalB350->mSubOam, 0, 0x400);
    if (g_GlobalB350->mSubScreenEnabled != FALSE) {
        switch (g_GlobalB350->mSubScreenState) {
            case RACE_HUD_SUB_SCREEN_KART_ICONS:
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1c00;
                SetDispcntSubBgMode(GX_BGMODE_0);
                reg_G2S_DB_BG2OFS = 0;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 2;
                reg_G2S_DB_BG2CNT &= ~REG_G2S_DB_BG2CNT_MOSAIC_MASK;
                reg_G2S_DB_BG2CNT =
                    (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0x208;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 3;
                reg_G2S_DB_BG3CNT &= ~REG_G2S_DB_BG3CNT_MOSAIC_MASK;
                reg_G2S_DB_BG3CNT =
                    (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x308;
                CopyPaletteBottom(gRaceHudSubScreenPalettes, 0, 0x200);
                break;
            case RACE_HUD_SUB_SCREEN_MAP_TURNING:
            case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
            case RACE_HUD_SUB_SCREEN_MAP_VIEW:
                InitSubScreenGraphicsMode5();
                CopyPaletteBottom(GetChoises_s_b_Pallette_from_thumb()->mData, 0, 0x200);
                break;
            case RACE_HUD_SUB_SCREEN_GOAL_KARTS:
            case RACE_HUD_SUB_SCREEN_GOAL_TEAMS:
                reg_G2S_DB_BG0OFS = 0;
                reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK;
                reg_G2S_DB_BG0CNT &= ~REG_G2S_DB_BG0CNT_MOSAIC_MASK;
                reg_G2S_DB_BG0CNT =
                    (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0x10c;
                InitSubScreenGraphicsMode0();
                CopyPaletteBottom(GetRaceGoalSBPaletteAndChars(0)->mPalette->mData, 0,
                               GetRaceGoalSBPaletteAndChars(0)->mPalette->mDataSize);
                CopyBgData_Bg1_Bottom(GetRaceGoalSBPaletteAndChars(0)->mChars->mData, 0,
                                GetRaceGoalSBPaletteAndChars(0)->mChars->mDataSize);
                TEQSub_Fn30Impl(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_S)->mNclr->mData, 0, 0x80);
                TEQSub_Fn35Impl(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_S)->mNcgr->mData, 0, 0x4000);
                CopyBgData_Bg0_Bottom(GetSomeBgTileData_from_thumb()->mData, 0, 0x3000);
                TEQSub_Fn24Impl(GetChoisesSListScreenMapData(), 0, 0x600);
                break;
            case RACE_HUD_SUB_SCREEN_NEW_RECORD:
                break;
        }
    }
    switch (g_GlobalB350->mSubScreenState) {
        case RACE_HUD_SUB_SCREEN_KART_ICONS:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1c00;
            scrollOffset = g_GlobalB350->mUpdateFrames / 6;
            reg_G2S_DB_BG3OFS = (scrollOffset & 0x1ff) | (((0x200 - scrollOffset) << 16) & 0x01ff0000);
            break;
        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
        case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
        case RACE_HUD_SUB_SCREEN_MAP_VIEW:
            if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
                TEQSub_Fn30Impl(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mData, 0,
                                GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mDataSize);
            }
            G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, &g_GlobalB350->mSubScreenBgAffines[0].mMatrix0,
                              g_GlobalB350->mSubScreenBgAffines[0].mCenterX, g_GlobalB350->mSubScreenBgAffines[0].mCenterY,
                              g_GlobalB350->mSubScreenBgAffines[0].mX1, g_GlobalB350->mSubScreenBgAffines[0].mY1);
            if (MaybeCircuitUsesLocal3() != 0) {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, &g_GlobalB350->mSubScreenBgAffines[1].mMatrix0,
                                  g_GlobalB350->mSubScreenBgAffines[1].mCenterX, g_GlobalB350->mSubScreenBgAffines[1].mCenterY,
                                  g_GlobalB350->mSubScreenBgAffines[1].mX1, g_GlobalB350->mSubScreenBgAffines[1].mY1);
            }
            UpdateRaceHudSubScreenBgPalette(&gRaceHudSubScreenPalettes[0x100]);
            if (MaybeCircuitUsesLocal3() != 0) {
                if (CheckCourseSomeVectorBounds() != 0) {
                    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1c00;
                } else {
                    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1800;
                }
            } else {
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1400;
            }
            break;
        case RACE_HUD_SUB_SCREEN_GOAL_KARTS:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1e00;
            switch (g_GlobalCO->mMode) {
                case MODE_BATTLE:
                case MODE_VS:
                    CopyBgData_Bg0_Bottom(GetSomeBgTileData_from_thumb()->mData, 0, 0x800);
                    break;
            }
            value = GetRaceGoalSOffsetX();
            if (value < 0x100) {
                scrollOffset = -value & 0x1ff;
                reg_G2S_DB_BG2OFS = scrollOffset;
                reg_G2S_DB_BG3OFS = scrollOffset;
                TEQSub_Fn26Impl_Fn28Impl(GetRaceGoalSNscr(1)->mData, 0, 0x600);
                TEQSub_Fn27Impl_Fn29Impl(GetRaceGoalSNscr(2)->mData, 0, 0x600);
            }
            break;
        case RACE_HUD_SUB_SCREEN_GOAL_TEAMS:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1e00;
            switch (g_GlobalCO->mMode) {
                case MODE_BATTLE:
                case MODE_VS:
                    CopyBgData_Bg0_Bottom(GetSomeBgTileData_from_thumb()->mData, 0, 0x800);
                    break;
            }
            value = GetRaceGoalSOffsetX();
            if (g_GlobalB350->mSubScreenGoalTeamsLoadPending != FALSE) {
                TEQSub_Fn25Impl(GetRaceGoalSNscr(3)->mData, 0, GetRaceGoalSNscr(3)->mDataSize);
                TEQSub_Fn26Impl_Fn28Impl(GetRaceGoalSNscr(4)->mData, 0, GetRaceGoalSNscr(4)->mDataSize);
                TEQSub_Fn27Impl_Fn29Impl(GetRaceGoalSNscr(5)->mData, 0, GetRaceGoalSNscr(5)->mDataSize);
                TEQSub_Fn30Impl(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_TEAM_S)->mNclr->mData, 0, 0x20);
                TEQSub_Fn30Impl(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_TEAM_S)->mNclr->mData + 0xc0, 0x180, 0x80);
                TEQSub_Fn35Impl(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_TEAM_S)->mNcgr->mData, 0, 0x4000);
                g_GlobalB350->mSubScreenGoalTeamsLoadPending = FALSE;
            }
            if (value < 0x100) {
                reg_G2S_DB_BG2OFS = value & 0x1ff;
                reg_G2S_DB_BG3OFS = -value & 0x1ff;
            }
            break;
        case RACE_HUD_SUB_SCREEN_NEW_RECORD:
            if (g_GlobalB350->mSubScreenNewRecordLoadPending != FALSE) {
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1200;
                SetDispcntSubBgMode(GX_BGMODE_0);
                reg_G2S_DB_BG1OFS = 0;
                reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
                reg_G2S_DB_BG1CNT &= ~REG_G2S_DB_BG1CNT_MOSAIC_MASK;
                reg_G2S_DB_BG1CNT =
                    (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 8;
                CopyPaletteBottom(g_GlobalB350->mNclrs[1]->mData, 0, 0x20);
                CopyBgData_Bg1_Bottom(g_GlobalB350->mNcgrs[1]->mData, 0, g_GlobalB350->mNcgrs[1]->mDataSize);
                TEQSub_Fn25Impl(g_GlobalB350->mNscrs[2]->mData, 0, g_GlobalB350->mNscrs[2]->mDataSize);
                TEQSub_Fn30Impl(GetRacePaletteBlock(RACE_NCER_PAIR_NEW_RECORD_TA_S)->mNclr->mData, 0, 0xa0);
                TEQSub_Fn30Impl(GetRacePaletteBlock(RACE_NCER_PAIR_NEW_RECORD_TA_S)->mNclr->mData + 0xb0, 0x160, 0xa0);
                TEQSub_Fn35Impl(GetRacePaletteBlock(RACE_NCER_PAIR_NEW_RECORD_TA_S)->mNcgr->mData, 0, 0x4000);
                g_GlobalB350->mSubScreenNewRecordLoadPending = FALSE;
            }
            break;
    }
    if (IsChoisesSOpen() != 0) {
        if (g_GlobalMV->mRaceDone == 0) {
            value = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((value | 4) << 8);
            TEQSub_Fn10Impl_Fn12Impl(g_GlobalB350->mNscrs[0]->mData, 0, 0x600);
        }
        TEQSub_Fn24Impl(GetChoisesSListScreenMapData(), 0, 0x600);
        value = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((value | 1) << 8);
        UpdateBldcntBldalphaBldy(&reg_G2S_DB_BLDCNT, 0x3e, 0x3f, 8, 8, -7);
    } else {
        value = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((value & ~1) << 8);
        value = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((value & ~4) << 8);
        G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    }
    for (kartIndex = 0; kartIndex < g_GlobalCO->mKartCount; kartIndex++) {
        if (g_GlobalB350->mKartRemoved[kartIndex] != 0 && g_GlobalB350->mRemovedSoundPlayed[kartIndex] == 0) {
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x52);
            g_GlobalB350->mRemovedSoundPlayed[kartIndex] = 1;
        }
    }
}

void InitRaceHud(void) {
    s32 index;
    u32 raceKind;
    u16 *choisesSBPalette;
    u32 colorIndex;
    u16 paletteColor;

    raceKind = g_GlobalCO->mRaceKind;
    if (raceKind == RACE_KIND_START_GP) {
        InitializeRaceIntroData();
        return;
    }
    if (raceKind == RACE_KIND_AWARD) {
        return;
    }
    if (raceKind == RACE_KIND_STAFF_ROLL) {
        LoadSomeEndingStaffRollStuff();
        LoadStaffRollStuff(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
        return;
    }
    g_GlobalB350 = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*g_GlobalB350));
    InitializeGlobalB358();
    AnotherAlloc();
    InitRaceHudSubScreenProjection();
    CreateGlobalB3C4();
    SomeAlloc();
    if (g_GlobalCO->mRaceKind == RACE_KIND_START_BATTLE) {
        SomeAlloc2();
    }
    InitRaceItemSlot();
    CreateGlobalB3EC();
    InitRaceModeCount();
    CreateGlobalB3F0();
    YetAlloc();
    InitRaceLapNumber();
    InitRaceMNumberPair();
    InitRaceGoalTimes();
    InitRaceRankList();
    InitRaceHudSubScreenCellGroups();
    SomeAlloc_0();
    CreateGlobalE8();
    InitRaceTaPositions();
    g_GlobalB350->mUpdateFrames = 0;
    for (index = 0; index < 7; index++) {
        g_GlobalB350->mNclrs[index] = NULL;
        g_GlobalB350->mNcgrs[index] = NULL;
    }
    g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_MAP_TURNING;
    g_GlobalB350->mSubScreenEnabled = FALSE;
    g_GlobalB350->mSubScreenGoalTeamsLoadPending = FALSE;
    g_GlobalB350->mRaceGoalSShown = FALSE;
    g_GlobalB350->mGoalMStarted = FALSE;
    g_GlobalB350->mGoalMUploadPending = FALSE;
    g_GlobalB350->mGoalMUploadFrames = 0;
    g_GlobalB350->mGoalMUploaded = 0;
    g_GlobalB350->mGoalMEnabled = 0;
    g_GlobalB350->mGoalMDelayFrameCount = 0;
    if (g_GlobalCO->mMode == MODE_BATTLE) {
        switch (g_GlobalCO->mCourseId) {
            case COURSE_ID_MINI_STAGE3:
                g_GlobalB350->mSubScreenCourseScale = RACE_HUD_COURSE_SCALE_SMALL;
                break;
            default:
                g_GlobalB350->mSubScreenCourseScale = RACE_HUD_COURSE_SCALE_MEDIUM;
                break;
        }
    } else if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        switch (g_GlobalCO->mCourseId) {
            case COURSE_ID_MR_STAGE1:
            case COURSE_ID_MR_STAGE2:
            case COURSE_ID_MR_STAGE3:
            case COURSE_ID_MR_STAGE4:
                g_GlobalB350->mSubScreenCourseScale = RACE_HUD_COURSE_SCALE_MEDIUM;
                break;
            default:
                g_GlobalB350->mSubScreenCourseScale = RACE_HUD_COURSE_SCALE_LARGE;
                break;
        }
    } else {
        g_GlobalB350->mSubScreenCourseScale = RACE_HUD_COURSE_SCALE_LARGE;
    }
    g_GlobalB350->mEnabled = FALSE;
    for (index = 0; index < 8; index++) {
        g_GlobalB350->mKartRemoved[index] = 0;
        g_GlobalB350->mRemovedSoundPlayed[index] = 0;
    }
    g_GlobalB350->mShowLapTime = 0;
    g_GlobalB350->mShowLapTimeFrames = -1;
    if (g_GlobalCO->mMode == MODE_TIME_ATTACK && g_GlobalCO->mKartCount > 1) {
        g_GlobalB350->mUseTimeDifference = 1;
    } else {
        g_GlobalB350->mUseTimeDifference = 0;
    }
    g_GlobalB350->mStepHasRun = 0;
    g_GlobalB350->mUnfilledNotEliminatedSet = FALSE;
    g_GlobalB350->mMissionRunRecordFilled = g_GlobalCO->mMode == MODE_MISSION_RUN ? IsCurrentMissionLevelStageBeaten_from_thumb() : 0;
    Mem_DmaFill32(3, &g_GlobalB350->mMainOam, 0xc0, 0x400);
    Mem_DmaFill32(3, &g_GlobalB350->mSubOam, 0xc0, 0x400);
    Gfx_ReadPalette(&g_GlobalB350->mNclrs[0], j_FindFileBuffer_K2D_LOC_R2D_R2L("race_m_b.NCLR"));
    Gfx_ReadCharGraphicsV2(&g_GlobalB350->mNcgrs[0], j_FindFileBuffer_K2D_LOC_R2D_R2L("race_m_b.NCGR"));
    MaybeReadScreenBlock_0(&g_GlobalB350->mNscrs[0], j_FindFileBuffer_K2D_LOC_R2D_R2L("race_m_pause.NSCR"));
    MaybeReadScreenBlock_0(&g_GlobalB350->mNscrs[1], j_FindFileBuffer_K2D_LOC_R2D_R2L("race_m_goal.NSCR"));
    if (g_GlobalCO->mMode == MODE_TIME_ATTACK) {
        Gfx_ReadPalette(&g_GlobalB350->mNclrs[1], j_FindFileBuffer_K2D_LOC_R2D_R2L("race_new_record_ta_s_b.NCLR"));
        Gfx_ReadCharGraphicsV2(&g_GlobalB350->mNcgrs[1], j_FindFileBuffer_K2D_LOC_R2D_R2L("race_new_record_ta_s_b.NCGR"));
        MaybeReadScreenBlock_0(&g_GlobalB350->mNscrs[2], j_FindFileBuffer_K2D_LOC_R2D_R2L("race_new_record_ta_s_bg.NSCR"));
        Arm_FlushRange(((Ncgr *) g_GlobalB350->mNscrs[0])->mData, ((Ncgr *) g_GlobalB350->mNscrs[0])->mDataSize);
        Arm_FlushRange(g_GlobalB350->mNscrs[2]->mData, g_GlobalB350->mNscrs[2]->mDataSize);
    }
    choisesSBPalette = GetChoises_s_b_Pallette_from_thumb()->mData;
    for (index = 0; index < 0x80; index++) {
        gRaceHudSubScreenPalettes[index + 0x80] = choisesSBPalette[index + 0x80];
    }
    GetChoises_s_b_Pallette_from_thumb()->mData[0] = gRaceHudSubScreenPalettes[0x100];
    Arm_FlushRange(GetChoises_s_b_Pallette_from_thumb()->mData, 0x200);
    for (index = 0; index < 0x20; index++) {
        paletteColor = GetChoises_s_b_Pallette_from_thumb()->mData[index + 0xe0];
        GetRaceGoalSBPaletteAndChars(0)->mPalette->mData[index + 0xe0] = paletteColor;
    }
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    if (g_GlobalCO->mMode == MODE_GRAND_PRIX) {
        CopyPlayerCharacterToRaceGoalMO(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_M)->mNclr->mData,
                                        GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_M)->mNcgr->mData);
        Arm_FlushRange(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_M)->mNclr->mData,
                      GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_M)->mNclr->mDataSize);
        Arm_FlushRange(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_M)->mNcgr->mData,
                      GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_M)->mNcgr->mDataSize);
    }
    FillRaceSOPaletteAndChars(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mData,
                              GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNcgr->mData);
    Arm_FlushRange(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mData,
                  GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mDataSize);
    Arm_FlushRange(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNcgr->mData,
                  GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNcgr->mDataSize);
    CopyCharsBlock(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNcgr->mData, 0x10, 0, 0x10, 2,
                   GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_S)->mNcgr->mData, 0x10, 0);
    Arm_FlushRange(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_S)->mNcgr->mData,
                  GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_S)->mNcgr->mDataSize);
    CopyCharsBlock(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNcgr->mData, 0x10, 0, 0x10, 2,
                   GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_TEAM_S)->mNcgr->mData, 0x10, 0);
    Arm_FlushRange(GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_TEAM_S)->mNcgr->mData,
                  GetRacePaletteBlock(RACE_NCER_PAIR_GOAL_TEAM_S)->mNcgr->mDataSize);
    if (g_GlobalCO->mMode == MODE_TIME_ATTACK) {
        CopyCharsBlock(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNcgr->mData, 0x10, 0, 0x10, 2,
                       GetRacePaletteBlock(RACE_NCER_PAIR_NEW_RECORD_TA_S)->mNcgr->mData, 0x10, 0);
        Arm_FlushRange(GetRacePaletteBlock(RACE_NCER_PAIR_NEW_RECORD_TA_S)->mNcgr->mData,
                      GetRacePaletteBlock(RACE_NCER_PAIR_NEW_RECORD_TA_S)->mNcgr->mDataSize);
    }
    MaybeClearGlobalB358();
    ResetRaceEndFrames();
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        g_GlobalB488->mUnfilledNotEliminated = 0;
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

void LoadMap2DStuff(void) {
    Nclr *nclrs[3];
    Ncgr *ncgrs[3];
    Nscr *nscrs[4];
    BOOL hasGlobalFiles;
    s32 index;
    s32 shineBattleFlag;

    hasGlobalFiles = g_GlobalCO->mMode != MODE_MISSION_RUN;
    if (g_GlobalCO->mRaceKind == RACE_KIND_START_GP) {
        return;
    }
    if (g_GlobalCO->mRaceKind == RACE_KIND_AWARD || g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    gRaceHudSubScreenPalettes = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), 0x200 * sizeof(*gRaceHudSubScreenPalettes));
    for (index = 0; index < 2; index++) {
        nclrs[index] = NULL;
        ncgrs[index] = NULL;
    }
    for (index = 0; index < 3; index++) {
        nscrs[index] = NULL;
    }

    if (GetMountData7FlagBit31_from_thumb()) {
        if (hasGlobalFiles) {
            Gfx_ReadPalette(&nclrs[0], j_FindFileBuffer_CRS_CST("Map2D/global.NCLR"));
            Gfx_ReadPalette(&nclrs[1], j_FindFileBuffer_CRS_CST("Map2D/global2.NCLR"));
        }
        Gfx_ReadPalette(&nclrs[2], j_FindFileBuffer_CRS_CST("Map2D/local.NCLR"));
    } else {
        if (hasGlobalFiles) {
            Gfx_ReadPaletteRelative(&nclrs[0], j_FindFileBuffer_CRS_CST("Map2D/global.NCLR"));
            Gfx_ReadPaletteRelative(&nclrs[1], j_FindFileBuffer_CRS_CST("Map2D/global.NCLR"));
        }
        Gfx_ReadPaletteRelative(&nclrs[2], j_FindFileBuffer_CRS_CST("Map2D/local.NCLR"));
    }

    if (GetMountData7FlagBit31_from_thumb()) {
        if (hasGlobalFiles) {
            Gfx_ReadCharGraphicsV2(&ncgrs[0], j_FindFileBuffer_CRS_CST("Map2D/global.NCGR"));
            Gfx_ReadCharGraphicsV2(&ncgrs[1], j_FindFileBuffer_CRS_CST("Map2D/global2.NCGR"));
        }
        Gfx_ReadCharGraphicsV2(&ncgrs[2], j_FindFileBuffer_CRS_CST("Map2D/local.NCGR"));
    } else {
        if (hasGlobalFiles) {
            MaybeReadCharBlock_1(&ncgrs[0], j_FindFileBuffer_CRS_CST("Map2D/global.NCGR"));
            MaybeReadCharBlock_1(&ncgrs[1], j_FindFileBuffer_CRS_CST("Map2D/global2.NCGR"));
        }
        MaybeReadCharBlock_1(&ncgrs[2], j_FindFileBuffer_CRS_CST("Map2D/local.NCGR"));
    }

    if (GetMountData7FlagBit31_from_thumb()) {
        if (hasGlobalFiles) {
            MaybeReadScreenBlock_0(&nscrs[0], j_FindFileBuffer_CRS_CST("Map2D/global1.NSCR"));
            MaybeReadScreenBlock_0(&nscrs[1], j_FindFileBuffer_CRS_CST("Map2D/global2.NSCR"));
        }
        MaybeReadScreenBlock_0(&nscrs[2], j_FindFileBuffer_CRS_CST("Map2D/local2.NSCR"));
        if (MaybeCircuitUsesLocal3()) {
            MaybeReadScreenBlock_0(&nscrs[3], j_FindFileBuffer_CRS_CST("Map2D/local3.NSCR"));
        }
    } else {
        if (hasGlobalFiles) {
            MaybeReadScreenBlock(&nscrs[0], j_FindFileBuffer_CRS_CST("Map2D/global1.NSCR"));
            MaybeReadScreenBlock(&nscrs[1], j_FindFileBuffer_CRS_CST("Map2D/global2.NSCR"));
        }
        MaybeReadScreenBlock(&nscrs[2], j_FindFileBuffer_CRS_CST("Map2D/local2.NSCR"));
        if (MaybeCircuitUsesLocal3()) {
            MaybeReadScreenBlock(&nscrs[3], j_FindFileBuffer_CRS_CST("Map2D/local3.NSCR"));
        }
    }

    if (hasGlobalFiles) {
        if (g_GlobalCO->mMirrorMode != 0) {
            InitMap2D_inline(nscrs[0]->mData);
        }
        shineBattleFlag = 0;
        if (g_GlobalCO->mMode == MODE_BATTLE && g_GlobalCO->mBattleKind == BATTLE_KIND_SHINE) {
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
        SetDispcntSubBgMode(GX_BGMODE_5);
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1c00;
        SetDispcntSubBgMode(GX_BGMODE_0);
        reg_G2S_DB_BG2OFS = 0;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 2;
        reg_G2S_DB_BG2CNT = reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_MOSAIC_MASK;
        reg_G2S_DB_BG2CNT =
            (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0x208;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 3;
        reg_G2S_DB_BG3CNT = reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_MOSAIC_MASK;
        reg_G2S_DB_BG3CNT =
            (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x308;
        CopyPaletteBottom(nclrs[0]->mData, 0, nclrs[0]->mDataSize);
        CopyBgData_Bg2_Bottom(ncgrs[0]->mData, 0, ncgrs[0]->mDataSize);
        CopyBgData_Bg2_Bottom(ncgrs[1]->mData, 0x1800, ncgrs[1]->mDataSize);
        TEQSub_Fn26Impl_Fn28Impl(nscrs[0]->mData, 0, nscrs[0]->mDataSize);
        TEQSub_Fn27Impl_Fn29Impl(nscrs[1]->mData, 0, nscrs[1]->mDataSize);
    }

    InitSubScreenGraphicsMode5();
    CopyPaletteBottom(nclrs[2]->mData, 0, 0x200);
    CopyBgData_Bg3_Bottom(ncgrs[2]->mData, 0, ncgrs[2]->mDataSize);
    TEQSub_Fn26Impl_Fn28Impl(nscrs[2]->mData, 0, nscrs[2]->mDataSize);
    if (MaybeCircuitUsesLocal3()) {
        TEQSub_Fn27Impl_Fn29Impl(nscrs[3]->mData, 0, nscrs[3]->mDataSize);
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
        Arm_FlushRange(gRaceHudSubScreenPalettes, 0x200);
    }
    Arm_FlushRange(gRaceHudSubScreenPalettes + 0x100, 0x200);
}

void SetupRaceHudScreens(void) {
    u32 raceKind;
    u16 value;

    raceKind = g_GlobalCO->mRaceKind;
    if (raceKind == RACE_KIND_START_GP) {
        return;
    }
    if (raceKind == RACE_KIND_AWARD || raceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    value = g_GlobalPE->mSettings->mColorAndFogAlpha & COLOR15_MASK;
    *(vu16 *) HW_BG_PLTT = value;
    g_GlobalB350->mNclrs[0]->mData[0] = value;
    Arm_FlushRange(g_GlobalB350->mNclrs[0]->mData, g_GlobalB350->mNclrs[0]->mDataSize);
    CopyPaletteTop(g_GlobalB350->mNclrs[0]->mData, 0, g_GlobalB350->mNclrs[0]->mDataSize);
    CopyBgData_Bg2_Top(g_GlobalB350->mNcgrs[0]->mData, 0, g_GlobalB350->mNcgrs[0]->mDataSize);
    TEQSub_Fn10Impl_Fn12Impl(g_GlobalB350->mNscrs[0]->mData, 0, g_GlobalB350->mNscrs[0]->mDataSize);
    CopySomePaletteData(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_M)->mNclr->mData, 0,
                   GetRacePaletteBlock(RACE_NCER_PAIR_RACE_M)->mNclr->mDataSize);
    CopyTileDataTop_0(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_M)->mNcgr->mData, 0, 0x4000);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK)) |
                     (REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
    value = reg_G2_WININ;
    reg_G2_WININ = (u32) ((value & ~0x3f) | 0x1f) | 0x20;
    reg_G2_WIN0H = 0xff;
    reg_G2_WIN0V = 0x60c0;
    reg_G2_WININ = (u32) ((reg_G2_WININ & ~REG_G2_WININ_WIN1IN_MASK) | 0x1f00) | 0x2000;
    reg_G2_WIN1H = 0x40ff;
    reg_G2_WIN1V = 0x60;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~REG_G2_WINOUT_OBJWININ_MASK) | 0x1200) | 0x2000;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~REG_G2_WINOUT_WINOUT_MASK) | 0xf) | 0x20;
    reg_GXS_DB_DISPCNT &= ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK);
    SetDispcntSubBgMode(GX_BGMODE_5);
    TEQSub_Fn30Impl(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mData, 0,
                    GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNclr->mDataSize);
    TEQSub_Fn35Impl(GetRacePaletteBlock(RACE_NCER_PAIR_RACE_S)->mNcgr->mData, 0, 0x4000);
    InitSubScreenGraphicsMode0();
    TEQSub_Fn25Impl(GetRaceGoalSNscr(0)->mData, 0, GetRaceGoalSNscr(0)->mDataSize);
    TEQSub_Fn26Impl_Fn28Impl(GetRaceGoalSNscr(1)->mData, 0, GetRaceGoalSNscr(1)->mDataSize);
    TEQSub_Fn27Impl_Fn29Impl(GetRaceGoalSNscr(2)->mData, 0, GetRaceGoalSNscr(2)->mDataSize);
    CopyPaletteBottom(gRaceHudSubScreenPalettes + 0x100, 0, 0x200);
    CopyRaceHudSubScreenBgColors();
    GX_SetBankForSubBGExtPltt(0x80);
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(gRaceHudSubScreenPalettes + 0x100, 0x4000, 0x200);
    GXS_LoadBGExtPltt(gRaceHudSubScreenPalettes + 0x100, 0x6000, 0x200);
    GXS_EndLoadBGExtPltt();
    CopyPaletteBottom(GetChoises_s_b_Pallette_from_thumb()->mData, 0, 0x200);
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK;
    reg_G2S_DB_BG0CNT &= ~REG_G2S_DB_BG0CNT_MOSAIC_MASK;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & (REG_G2S_DB_BG0CNT_PRIORITY_MASK | REG_G2S_DB_BG0CNT_MOSAIC_MASK)) | 0x10c;
    CopyBgData_Bg0_Bottom(GetSomeBgTileData_from_thumb()->mData, 0, GetSomeBgTileData_from_thumb()->mDataSize);
    TEQSub_Fn24Impl(GetChoisesSListScreenMapData(), 0, 0x600);
    InitSubScreenGraphicsMode5();
    g_GlobalB350->mEnabled = TRUE;
}

// Clears the HUD pointers and display bits; nothing is freed here.
void ReleaseRaceHud(void) {
    u32 raceKind;

    raceKind = g_GlobalCO->mRaceKind;
    if (raceKind == RACE_KIND_START_GP) {
        Reset33();
        return;
    }
    if (raceKind == RACE_KIND_AWARD) {
        return;
    }
    if (raceKind == RACE_KIND_STAFF_ROLL) {
        ResetStaffRollStuffObject();
        ResetStaffRoll();
        return;
    }
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 0, 0, 0x10, 0x10);
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0, 0x10, 0x10);
    g_GlobalB350 = NULL;
    ResetGlobalB358();
    ClearRaceEndPointer();
    ClearRaceHudSubScreenProjection();
    ResetGlobalB3C4();
    if (g_GlobalCO->mRaceKind == RACE_KIND_START_BATTLE) {
        ClearRaceStartBattlePointer();
    }
    ClearRaceItemSlotPointer();
    ResetGlobalB3EC();
    ClearRaceModeCountPointer();
    ResetGlobalB3F0();
    ClearRaceTimeDigitsPointer();
    ClearRaceLapNumberPointer();
    ClearRaceMNumberPairPointer();
    ClearRaceGoalTimesPointer();
    ClearRaceRankListPointer();
    ClearRaceHudSubScreenCellGroups();
    ClearRaceGoalSPointer();
    ResetGlobalE8();
    ClearRaceTaPositionsPointer();
    reg_GX_DISPCNT &= ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
    reg_GXS_DB_DISPCNT &= ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK);
}

void SomeUpdateFn(void) {
    u32 kind;

    if (g_GlobalB350 != NULL) {
        g_GlobalB350->mStepHasRun = 1;
    }
    kind = g_GlobalCO->mRaceKind;
    if (kind == RACE_KIND_START_GP) {
        IncrementRaceIntroFrameCounter();
        return;
    }
    if (kind == RACE_KIND_AWARD) {
        return;
    }
    if (kind == RACE_KIND_STAFF_ROLL) {
        IncrementStaffRollFrameCount();
        AdvanceStaffRollText();
        return;
    }
    if (g_GlobalB350->mEnabled == FALSE) {
        return;
    }
    if (g_GlobalB350->mShowLapTime != 0) {
        g_GlobalB350->mShowLapTimeFrames++;
        if (g_GlobalB350->mShowLapTimeFrames >= RACE_HUD_LAP_TIME_SHOW_FRAMES) {
            g_GlobalB350->mShowLapTime = 0;
            g_GlobalB350->mShowLapTimeFrames = -1;
        }
    }
    IncreaseB358Countdown();
    MaybeWhenFinishFlagpole();
    if (g_GlobalCO->mRaceKind == RACE_KIND_START_BATTLE) {
        nullsub_10();
    }
    kind = g_GlobalCO->mMode;
    if ((kind == MODE_BATTLE ? g_GlobalMV->mRaceDone
         : kind == MODE_MISSION_RUN
             ? IsFramesSinceFinishPastWait()
             : (IsRacerFinishedRace(GetCurrentPlayerRacerId()) != 0 && g_GlobalB350->mShowLapTime == 0)) == 0) {
        UpdateRaceItemSlot();
        MaybeWhenLapIsCompleted();
        nullsub_11();
        UpdateRaceGoalTimes();
        UpdateRaceModeCount();
        UpdateRaceGoalM();
    } else {
        StopRaceItemSlotSound();
        MaybeWhenLapIsCompleted();
        UpdateRaceGoalTimes();
        UpdateRaceGoalM();
    }
    MaybeWhenFewSecondsRemaining();
    UpdateRaceRankList();
    switch (g_GlobalB350->mSubScreenState) {
        case RACE_HUD_SUB_SCREEN_KART_ICONS:
        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
        case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
        case RACE_HUD_SUB_SCREEN_MAP_VIEW:
            UpdateRaceHudSubScreenCellGroups();
            UpdateRaceTaPositions();
            break;
        case RACE_HUD_SUB_SCREEN_GOAL_KARTS:
        case RACE_HUD_SUB_SCREEN_GOAL_TEAMS:
            UpdateRaceGoalS();
            break;
        case RACE_HUD_SUB_SCREEN_NEW_RECORD:
            break;
    }
    InvokeE8Handler();
    g_GlobalB350->mUpdateFrames++;
    if (g_GlobalB350->mUpdateFrames >= RACE_HUD_UPDATE_FRAMES_WRAP) {
        g_GlobalB350->mUpdateFrames = 0;
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
    if (g_GlobalCO->mRaceKind - 3 <= 3) {
        return;
    }
    if (g_GlobalB350->mEnabled == FALSE) {
        return;
    }
    switch (g_GlobalCO->mMode) {
        case MODE_GRAND_PRIX:
            if (IsRacerFinishedRace(GetCurrentPlayerRacerId()) != 0 && g_GlobalB350->mShowLapTime == 0) {
                if (g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
                    if (g_GlobalB350->mGoalMStarted != FALSE) {
                        g_GlobalB350->mSubScreenEnabled = FALSE;
                    } else {
                        g_GlobalB350->mSubScreenEnabled = TRUE;
                        g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_GOAL_KARTS;
                        g_GlobalB350->mGoalMStarted = TRUE;
                        g_GlobalB350->mGoalMUploadPending = TRUE;
                        g_GlobalB350->mGoalMDelayFrameCount = RACE_HUD_GOAL_M_DELAY_SOLO;
                    }
                } else if (g_GlobalB350->mGoalMStarted == FALSE) {
                    g_GlobalB350->mGoalMStarted = TRUE;
                    g_GlobalB350->mGoalMUploadPending = TRUE;
                    g_GlobalB350->mGoalMDelayFrameCount = RACE_HUD_GOAL_M_DELAY_SOLO;
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (g_GlobalCO->mRaceKind != RACE_KIND_DEMO && g_GlobalCO->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (g_GlobalCYT[GetSomeCYId_9()].mClearedBits & PAD_KEY_Y) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (g_GlobalCYT[GetSomeCYId_9()].mPair.mNoPairCount == INPUT_NO_PAIR_BRIEF_FRAMES) {
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
                    g_GlobalB350->mSubScreenEnabled = TRUE;
                    switch (g_GlobalB350->mSubScreenState) {
                        case RACE_HUD_SUB_SCREEN_KART_ICONS:
                            g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_MAP_TURNING;
                            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x18);
                            break;
                        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
                            g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_KART_ICONS;
                            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x17);
                            break;
                    }
                } else {
                    g_GlobalB350->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_TIME_ATTACK:
            if (g_GlobalMV->mRaceDone != 0 && g_GlobalB350->mShowLapTime == 0) {
                if (g_GlobalB350->mGoalMStarted == FALSE) {
                    g_GlobalB350->mGoalMStarted = TRUE;
                    g_GlobalB350->mGoalMUploadPending = TRUE;
                    g_GlobalB350->mGoalMDelayFrameCount = RACE_HUD_GOAL_M_DELAY_SOLO;
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (g_GlobalCO->mRaceKind != RACE_KIND_DEMO && g_GlobalCO->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (g_GlobalCYT[GetSomeCYId_9()].mClearedBits & PAD_KEY_Y) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (g_GlobalCYT[GetSomeCYId_9()].mPair.mNoPairCount == INPUT_NO_PAIR_BRIEF_FRAMES) {
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
                    g_GlobalB350->mSubScreenEnabled = TRUE;
                    if (g_GlobalCO->mRaceKind != RACE_KIND_REPLAY) {
                        switch (g_GlobalB350->mSubScreenState) {
                            case RACE_HUD_SUB_SCREEN_KART_ICONS:
                                g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_MAP_TURNING;
                                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x18);
                                break;
                            case RACE_HUD_SUB_SCREEN_MAP_TURNING:
                                g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_KART_ICONS;
                                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x17);
                                break;
                        }
                    } else {
                        switch (g_GlobalB350->mSubScreenState) {
                            case RACE_HUD_SUB_SCREEN_KART_ICONS:
                                g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_MAP_TURNING;
                                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x18);
                                break;
                            case RACE_HUD_SUB_SCREEN_MAP_TURNING:
                                g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL;
                                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x17);
                                break;
                            case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
                                g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_KART_ICONS;
                                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x17);
                                break;
                        }
                    }
                } else {
                    g_GlobalB350->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_BATTLE:
            if (IsWinnerDecidedAndEndReached() != 0) {
                if (g_GlobalB350->mGoalMStarted != FALSE) {
                    g_GlobalB350->mSubScreenEnabled = FALSE;
                } else {
                    g_GlobalB350->mSubScreenEnabled = TRUE;
                    g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_GOAL_KARTS;
                    g_GlobalB350->mGoalMStarted = TRUE;
                    g_GlobalB350->mGoalMUploadPending = TRUE;
                    g_GlobalB350->mGoalMDelayFrameCount = RACE_HUD_GOAL_M_DELAY_MULTI;
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (g_GlobalCO->mRaceKind != RACE_KIND_DEMO && g_GlobalCO->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (g_GlobalCYT[GetSomeCYId_9()].mClearedBits & PAD_KEY_Y) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (g_GlobalCYT[GetSomeCYId_9()].mPair.mNoPairCount == INPUT_NO_PAIR_BRIEF_FRAMES) {
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
                    g_GlobalB350->mSubScreenEnabled = TRUE;
                    switch (g_GlobalB350->mSubScreenState) {
                        case RACE_HUD_SUB_SCREEN_KART_ICONS:
                            g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_MAP_TURNING;
                            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x18);
                            break;
                        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
                            g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_KART_ICONS;
                            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x17);
                            break;
                    }
                } else {
                    g_GlobalB350->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_VS:
        case MODE_WIFI:
            if (g_GlobalMV->mRaceDone != 0 && g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
                if (g_GlobalB350->mRaceGoalSShown == FALSE) {
                    g_GlobalB350->mSubScreenEnabled = TRUE;
                    g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_GOAL_KARTS;
                    g_GlobalB350->mRaceGoalSShown = TRUE;
                    if (g_GlobalB350->mGoalMStarted == FALSE) {
                        g_GlobalB350->mGoalMStarted = TRUE;
                        g_GlobalB350->mGoalMUploadPending = TRUE;
                        g_GlobalB350->mGoalMDelayFrameCount = RACE_HUD_GOAL_M_DELAY_MULTI;
                    }
                } else {
                    g_GlobalB350->mSubScreenEnabled = FALSE;
                }
            } else if (IsRacerFinishedRace(GetCurrentPlayerRacerId()) != 0 && g_GlobalCO->mRaceKind == RACE_KIND_NORMAL) {
                if (g_GlobalB350->mGoalMStarted == FALSE) {
                    g_GlobalB350->mSubScreenEnabled = TRUE;
                    g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_KART_ICONS;
                    g_GlobalB350->mGoalMStarted = TRUE;
                    g_GlobalB350->mGoalMUploadPending = TRUE;
                    g_GlobalB350->mGoalMDelayFrameCount = RACE_HUD_GOAL_M_DELAY_MULTI;
                } else {
                    subScreenEnabled = FALSE;
                    switchAllowed = FALSE;
                    raceKindAllowsSwitch = FALSE;
                    if (g_GlobalCO->mRaceKind != RACE_KIND_DEMO && g_GlobalCO->mRaceKind != RACE_KIND_START_BATTLE) {
                        raceKindAllowsSwitch = TRUE;
                    }
                    if (raceKindAllowsSwitch != FALSE) {
                        if (IsChoisesSPickLocked() == 0) {
                            switchAllowed = TRUE;
                        }
                    }
                    if (switchAllowed != FALSE) {
                        switchPressed = TRUE;
                        if ((u16) (g_GlobalCYT[GetSomeCYId_9()].mClearedBits & PAD_KEY_Y) == 0) {
                            condition = FALSE;
                            if (IsChoisesSOpen() == 0) {
                                if (g_GlobalCYT[GetSomeCYId_9()].mPair.mNoPairCount == INPUT_NO_PAIR_BRIEF_FRAMES) {
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
                        g_GlobalB350->mSubScreenEnabled = TRUE;
                        switch (g_GlobalB350->mSubScreenState) {
                            case RACE_HUD_SUB_SCREEN_KART_ICONS:
                                g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_MAP_VIEW;
                                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x18);
                                break;
                            case RACE_HUD_SUB_SCREEN_MAP_VIEW:
                                g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_KART_ICONS;
                                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x17);
                                break;
                        }
                    } else {
                        g_GlobalB350->mSubScreenEnabled = FALSE;
                    }
                }
            } else {
                subScreenEnabled = FALSE;
                switchAllowed = FALSE;
                raceKindAllowsSwitch = FALSE;
                if (g_GlobalCO->mRaceKind != RACE_KIND_DEMO && g_GlobalCO->mRaceKind != RACE_KIND_START_BATTLE) {
                    raceKindAllowsSwitch = TRUE;
                }
                if (raceKindAllowsSwitch != FALSE) {
                    if (IsChoisesSPickLocked() == 0) {
                        switchAllowed = TRUE;
                    }
                }
                if (switchAllowed != FALSE) {
                    switchPressed = TRUE;
                    if ((u16) (g_GlobalCYT[GetSomeCYId_9()].mClearedBits & PAD_KEY_Y) == 0) {
                        condition = FALSE;
                        if (IsChoisesSOpen() == 0) {
                            if (g_GlobalCYT[GetSomeCYId_9()].mPair.mNoPairCount == INPUT_NO_PAIR_BRIEF_FRAMES) {
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
                    g_GlobalB350->mSubScreenEnabled = TRUE;
                    switch (g_GlobalB350->mSubScreenState) {
                        case RACE_HUD_SUB_SCREEN_KART_ICONS:
                            g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_MAP_TURNING;
                            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x18);
                            break;
                        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
                            g_GlobalB350->mSubScreenState = RACE_HUD_SUB_SCREEN_KART_ICONS;
                            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x17);
                            break;
                    }
                } else {
                    g_GlobalB350->mSubScreenEnabled = FALSE;
                }
            }
            break;
        case MODE_MISSION_RUN:
            if (IsFramesSinceFinishPastWait() != FALSE) {
                if (g_GlobalB350->mGoalMStarted == FALSE) {
                    g_GlobalB350->mGoalMStarted = TRUE;
                    g_GlobalB350->mGoalMUploadPending = TRUE;
                    if (IsRacerFinishedRace((u16) g_GlobalCO->mEntryIndex) != 0) {
                        value = g_GlobalMV->mEntryEndKind;
                    } else {
                        value = RACE_END_KIND_NOT_ENDED;
                    }
                    if (value == 0) {
                        g_GlobalB350->mGoalMDelayFrameCount = RACE_HUD_GOAL_M_DELAY_MISSION_RUN;
                    }
                }
            } else if (g_GlobalMV->mRaceDone != 0) {
                if (IsRacerFinishedRace((u16) g_GlobalCO->mEntryIndex) != 0) {
                    value = g_GlobalMV->mEntryEndKind;
                } else {
                    value = RACE_END_KIND_NOT_ENDED;
                }
                if (value != 0) {
                    g_GlobalB350->mGoalMEnabled = 1;
                }
            }
            if ((u16) (g_GlobalCYT[GetSomeCYId_9()].mClearedBits & PAD_KEY_Y) != 0) {
                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x19);
            }
            g_GlobalB350->mSubScreenEnabled = FALSE;
            break;
    }
    if (g_GlobalB350->mSubScreenEnabled != FALSE) {
        switch (g_GlobalB350->mSubScreenState) {
            case RACE_HUD_SUB_SCREEN_KART_ICONS:
                UpdateRaceHudSubScreenCellGroups();
                break;
            case RACE_HUD_SUB_SCREEN_MAP_TURNING:
            case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
            case RACE_HUD_SUB_SCREEN_MAP_VIEW:
                UpdateRaceHudSubScreenCellGroups();
                UpdateRaceTaPositions();
                break;
            case RACE_HUD_SUB_SCREEN_GOAL_KARTS:
            case RACE_HUD_SUB_SCREEN_GOAL_TEAMS:
                UpdateRaceGoalS();
                break;
            case RACE_HUD_SUB_SCREEN_NEW_RECORD:
                InvokeE8Handler();
                break;
        }
    }
    if (g_GlobalB350->mUnfilledNotEliminatedSet != FALSE) {
        return;
    }
    if (g_GlobalCO->mMode == MODE_MISSION_RUN) {
        value = (g_GlobalCO->mMode == MODE_MISSION_RUN ? g_GlobalCO->mMissionTableColumn : -1) == 9;
    } else {
        value = 0;
    }
    if (value == 0) {
        return;
    }
    if (g_GlobalCO->mMode != MODE_MISSION_RUN) {
        value = 0;
    } else {
        value = IsWinnerDecidedAndEndReached();
    }
    if (value == 0) {
        return;
    }
    if (g_GlobalCO->mMode != MODE_MISSION_RUN) {
        value = 0;
    } else {
        value = IsKartEliminated(GetCurrentPlayerRacerId());
    }
    if (value != 0) {
        g_GlobalB488->mUnfilledNotEliminated = 0;
    } else {
        g_GlobalB488->mUnfilledNotEliminated = g_GlobalB350->mMissionRunRecordFilled == 0;
    }
    g_GlobalB350->mUnfilledNotEliminatedSet = TRUE;
}

void DrawRaceHud(void) {
    u32 raceKindOrMode;
    s32 subScreenState;

    raceKindOrMode = g_GlobalCO->mRaceKind;
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
    if (g_GlobalB350->mEnabled == FALSE) {
        return;
    }
    UpdateRaceStartSequenceSounds();
    nullsub_9();
    g_GlobalB350->mMainOam.mOamCount = 0;
    g_GlobalB350->mMainOam.mMatrixCount = 0;
    if (g_GlobalCO->mRaceKind == RACE_KIND_START_BATTLE) {
        DrawRaceStartBattle(&g_GlobalB350->mMainOam);
    }
    raceKindOrMode = g_GlobalCO->mMode;
    if ((raceKindOrMode == MODE_BATTLE ? g_GlobalMV->mRaceDone
         : raceKindOrMode == MODE_MISSION_RUN
             ? IsFramesSinceFinishPastWait()
             : (IsRacerFinishedRace(GetCurrentPlayerRacerId()) != 0 && g_GlobalB350->mShowLapTime == 0)) == 0) {
        DrawRaceItemSlot(&g_GlobalB350->mMainOam);
        DrawRaceLapAndTimeDifference(&g_GlobalB350->mMainOam);
        DrawRaceMNumberPair(&g_GlobalB350->mMainOam);
        DrawRaceGoalTimes(&g_GlobalB350->mMainOam);
        DrawRaceLinkLevel(&g_GlobalB350->mMainOam);
        DrawRaceModeCount(&g_GlobalB350->mMainOam);
        DrawRaceGoalM(&g_GlobalB350->mMainOam);
    } else {
        DrawRaceGoalTimes(&g_GlobalB350->mMainOam);
        DrawRaceLinkLevel(&g_GlobalB350->mMainOam);
        DrawRaceGoalM(&g_GlobalB350->mMainOam);
    }
    Arm_FlushRange(&g_GlobalB350->mMainOam, 0x400);
    Mem_DmaFill32(3, &g_GlobalB350->mMainOam.mOams[g_GlobalB350->mMainOam.mOamCount], 0xc0,
                 (0x80 - g_GlobalB350->mMainOam.mOamCount) << 3);
    g_GlobalB350->mSubOam.mOamCount = 0;
    g_GlobalB350->mSubOam.mMatrixCount = 0;
    subScreenState = g_GlobalB350->mSubScreenState;
    if (subScreenState != RACE_HUD_SUB_SCREEN_GOAL_KARTS && subScreenState != RACE_HUD_SUB_SCREEN_GOAL_TEAMS) {
        DrawRaceTimeDigits(&g_GlobalB350->mSubOam);
    }
    DrawRaceRankList(&g_GlobalB350->mSubOam);
    Arm_FlushRange(&g_GlobalB350->mSubOam, 0x400);
    Mem_DmaFill32(3, &g_GlobalB350->mSubOam.mOams[g_GlobalB350->mSubOam.mOamCount], 0xc0,
                 (0x80 - g_GlobalB350->mSubOam.mOamCount) << 3);
    switch (g_GlobalB350->mSubScreenState) {
        case RACE_HUD_SUB_SCREEN_KART_ICONS:
            OamBuffer_SomeFn_0(&g_GlobalB350->mSubOam);
            break;
        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
        case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
        case RACE_HUD_SUB_SCREEN_MAP_VIEW:
            OamBuffer_SomeFn_0(&g_GlobalB350->mSubOam);
            DrawRaceTaPositions(&g_GlobalB350->mSubOam);
            break;
        case RACE_HUD_SUB_SCREEN_GOAL_KARTS:
        case RACE_HUD_SUB_SCREEN_GOAL_TEAMS:
            StructRA_SomeFn_1(&g_GlobalB350->mSubOam);
            break;
        case RACE_HUD_SUB_SCREEN_NEW_RECORD:
            StructRA_SomeFn_4(&g_GlobalB350->mSubOam);
            break;
    }
}
