#include "Main/Sound/sound_row.h"
#include "Main/System/result_archive_path.h"

#include "Main/Item/pooled_item_box_init.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_set_load.h"
#include "Main/Sound/seq_row.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Menu/select_race_rule_state.h"

const SoundRow g_CourseBgmTable[53] = {{2, SOUND_ID_NONE, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 9, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 8, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 0xa, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 8, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 0xd, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 0xe, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {0xff, 0x4a, 0x10, SOUND_ID_NONE},
                                     {0xff, 0x21, 0x1d, SOUND_ID_NONE},
                                     {0xff, 0x21, 0x1a, SOUND_ID_NONE},
                                     {0xff, 0xf, 0x12, SOUND_ID_NONE},
                                     {0xff, 0x10, 0x11, SOUND_ID_NONE},
                                     {0xff, 0x22, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {0xff, 0x1e, 0x1f, SOUND_ID_NONE},
                                     {0xff, 0x1f, 0x18, SOUND_ID_NONE},
                                     {0xff, 0x11, 0x15, SOUND_ID_NONE},
                                     {0xff, 0x12, 0x1b, SOUND_ID_NONE},
                                     {0xff, 0x13, 0x1c, SOUND_ID_NONE},
                                     {0xff, 0x23, 0x17, SOUND_ID_NONE},
                                     {0xff, 0x14, 0x1d, SOUND_ID_NONE},
                                     {0xff, 0x15, 0x13, SOUND_ID_NONE},
                                     {0xff, 0x16, 0x1a, SOUND_ID_NONE},
                                     {0xff, 0x17, 0x12, SOUND_ID_NONE},
                                     {0xff, 0x18, 0x1a, SOUND_ID_NONE},
                                     {0xff, 0x19, 0x1a, SOUND_ID_NONE},
                                     {0xff, 0x1a, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {0xff, 0x1a, 0x21, SOUND_ID_NONE},
                                     {0xff, 0x24, 0x17, SOUND_ID_NONE},
                                     {0xff, 0x1d, 0x18, SOUND_ID_NONE},
                                     {0xff, 0x20, 0x20, SOUND_ID_NONE},
                                     {0xff, 0x25, 0x18, SOUND_ID_NONE},
                                     {0xff, 0x26, 0x14, SOUND_ID_NONE},
                                     {0xff, 0x13, 0x16, SOUND_ID_NONE},
                                     {0xff, 0x27, 0x19, SOUND_ID_NONE},
                                     {0xff, 0x4a, 0x1a, SOUND_ID_NONE},
                                     {0xff, 0x29, 0x30, SOUND_ID_NONE},
                                     {0xff, 0x1b, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {0xff, 0x28, 0x1e, SOUND_ID_NONE},
                                     {0xff, 0x1c, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {0xff, 0x2b, 0x2b, 0x22},
                                     {0xff, 0x2d, SOUND_ID_NONE, 0x22},
                                     {2, 0x3f, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 0x42, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 0x45, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 0x46, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 3, 0x24, SOUND_ID_NONE},
                                     {2, 2, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 6, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 4, 0x23, SOUND_ID_NONE},
                                     {2, 0x4b, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, 1, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {2, SOUND_ID_NONE, SOUND_ID_NONE, SOUND_ID_NONE},
                                     {0xff, 0x4a, SOUND_ID_NONE, SOUND_ID_NONE}};

SoundRow GetCourseBgmEntry(u32 rowIndex) {
    return g_CourseBgmTable[rowIndex];
}

u32 GetCourseBgmInfo(u32 courseId, SoundRow *output) {
    u32 rowIndex;

    rowIndex = 0x36;
    switch (courseId) {
        case COURSE_ID_CROSS:
            rowIndex = 7;
            break;
        case COURSE_ID_MARIO:
            rowIndex = 34;
            break;
        case COURSE_ID_OLD_LUIGI_GC:
            rowIndex = 8;
            break;
        case COURSE_ID_OLD_YOSHI_GC:
            rowIndex = 9;
            break;
        case COURSE_ID_BEACH:
            rowIndex = 10;
            break;
        case COURSE_ID_BANK:
            rowIndex = 11;
            break;
        case COURSE_ID_OLD_BABY_GC:
            rowIndex = 12;
            break;
        case COURSE_ID_OLD_MOMO_64:
            rowIndex = 13;
            break;
        case COURSE_ID_OLD_FRAPPE_64:
            rowIndex = 14;
            break;
        case COURSE_ID_TOWN:
            rowIndex = 15;
            break;
        case COURSE_ID_AIRSHIP:
            rowIndex = 16;
            break;
        case COURSE_ID_STADIUM:
            rowIndex = 17;
            break;
        case COURSE_ID_PINBALL:
            rowIndex = 32;
            break;
        case COURSE_ID_OLD_KINOKO_GC:
            rowIndex = 18;
            break;
        case COURSE_ID_GARDEN:
            rowIndex = 19;
            break;
        case COURSE_ID_MANSION:
            rowIndex = 20;
            break;
        case COURSE_ID_OLD_MARIO_SFC:
            rowIndex = 21;
            break;
        case COURSE_ID_OLD_NOKO_SFC:
            rowIndex = 22;
            break;
        case COURSE_ID_OLD_DONUT_SFC:
            rowIndex = 23;
            break;
        case COURSE_ID_OLD_CHOCO_SFC:
            rowIndex = 24;
            break;
        case COURSE_ID_OLD_PEACH_AGB:
            rowIndex = 25;
            break;
        case COURSE_ID_OLD_LUIGI_AGB:
            rowIndex = 26;
            break;
        case COURSE_ID_RIDGE:
            rowIndex = 27;
            break;
        case COURSE_ID_OLD_HYUDORO_64:
            rowIndex = 29;
            break;
        case COURSE_ID_OLD_CHOCO_64:
            rowIndex = 28;
            break;
        case COURSE_ID_SNOW:
            rowIndex = 30;
            break;
        case COURSE_ID_DESERT:
            rowIndex = 31;
            break;
        case COURSE_ID_CLOCK:
            rowIndex = 33;
            break;
        case COURSE_ID_KOOPA:
            rowIndex = 37;
            break;
        case COURSE_ID_RAINBOW:
            rowIndex = 35;
            break;
        case COURSE_ID_OLD_KOOPA_AGB:
            rowIndex = 36;
            break;
        case COURSE_ID_OLD_SKY_AGB:
            rowIndex = 38;
            break;
        case COURSE_ID_MINI_BLOCK:
        case COURSE_ID_MINI_BLOCK_64:
        case COURSE_ID_MINI_DOKAN_GC:
        case COURSE_ID_MINI_STAGE1:
        case COURSE_ID_MINI_STAGE2:
        case COURSE_ID_MINI_STAGE3:
        case COURSE_ID_MINI_STAGE4:
            rowIndex = 39;
            break;
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE2:
        case COURSE_ID_MR_STAGE3:
        case COURSE_ID_MR_STAGE4:
            rowIndex = 40;
            break;
        case COURSE_ID_AWARD:
            rowIndex = 42;
            break;
        case COURSE_ID_STAFFROLL:
            rowIndex = 51;
            break;
    }
    if (output != NULL) {
        *output = g_CourseBgmTable[rowIndex];
    }
    return rowIndex;
}

u32 MaybeGetMusicForMenu(s32 sceneNumber, SoundRow *output) {
    enum { ROW_INDEX_FIRST } rowIndex;
    BOOL rowWritten;
    s32 raceMode;
    BOOL overridden;
    BOOL matched;
    SoundRow courseRow;
    MissionSettings *mission;

    rowIndex = 0x36;
    rowWritten = FALSE;
    switch (sceneNumber) {
        case SCENE_RACE:
            switch (g_GlobalCO->mRaceKind) {
                case RACE_KIND_NORMAL:
                case RACE_KIND_REPLAY:
                    raceMode = g_GlobalCO->mMode;
                    rowIndex = GetCourseBgmInfo(g_GlobalCO->mCourseId, output);
                    rowWritten = TRUE;
                    if (raceMode == MODE_MISSION_RUN) {
                        mission = &g_GlobalCO->mMissionSettings;
                        overridden = FALSE;
                        if (mission->mMissionTableValue == MISSION_NUMBER_GARDEN) {
                            output->mSeqId = SOUND_SEQ_ID_MISSION_GARDEN;
                            overridden = TRUE;
                        }
                        if (overridden == FALSE) {
                            switch (mission->mMissionKind) {
                                case MISSION_KIND_COUNT_PENDING_WITH_SEQ:
                                    output->mSeqId = SOUND_SEQ_ID_MISSION_COUNT_PENDING;
                                    break;
                                case MISSION_KIND_LAPS:
                                case MISSION_KIND_COUNT_MAP_OBJECTS:
                                case MISSION_KIND_LAPS_NO_LAP_PROGRESS:
                                    break;
                            }
                        }
                        matched = TRUE;
                        switch (mission->mMissionTableValue) {
                            case MISSION_NUMBER_DONKETU:
                            case MISSION_NUMBER_KING_ICE_DONKETU:
                                output->mFirstBankId = SOUND_BANK_MISSION_DONKETU;
                                break;
                            case MISSION_NUMBER_IWANTE:
                                output->mFirstBankId = SOUND_BANK_MISSION_IWANTE;
                                break;
                            case MISSION_NUMBER_KURIKING:
                                output->mFirstBankId = SOUND_BANK_MISSION_KURIKING;
                                break;
                            case MISSION_NUMBER_KING_TERESA:
                                output->mFirstBankId = SOUND_BANK_MISSION_KING_TERESA;
                                break;
                            case MISSION_NUMBER_BOMB_KING:
                                output->mFirstBankId = SOUND_BANK_MISSION_BOMB_KING;
                                break;
                            case MISSION_NUMBER_HANACHAN:
                                break;
                            default:
                                matched = FALSE;
                                break;
                        }
                        if (matched != FALSE) {
                            output->mSecondBankId = SOUND_BANK_MISSION_SECOND;
                        }
                    }
                    break;
                case RACE_KIND_AWARD:
                    rowIndex = 0x2a;
                    break;
                case RACE_KIND_DEMO:
                    rowIndex = 0x33;
                    break;
                case RACE_KIND_START_GP:
                    switch (g_GlobalCO->mCourseId) {
                        case COURSE_ID_OLD_LUIGI_GC:
                        case COURSE_ID_CROSS:
                        case COURSE_ID_MARIO:
                            rowIndex = 2;
                            break;
                        case COURSE_ID_STADIUM:
                            rowIndex = 3;
                            break;
                        case COURSE_ID_PINBALL:
                            rowIndex = 4;
                            break;
                        default:
                            rowIndex = 1;
                            break;
                    }
                    if (IsInBossMissionStage() != 0) {
                        rowIndex = 6;
                    } else {
                        *output = g_CourseBgmTable[rowIndex];
                        rowWritten = TRUE;
                        GetCourseBgmInfo(g_GlobalCO->mCourseId, &courseRow);
                        output->mFirstBankId = courseRow.mFirstBankId;
                    }
                    break;
                case RACE_KIND_START_BATTLE:
                    rowIndex = 5;
                    break;
                case RACE_KIND_STAFF_ROLL:
                    rowIndex = 0x33;
                    break;
            }
            break;
        case SCENE_WIFI_MENU:
            rowIndex = 0x2d;
            break;
        case SCENE_MENU_4:
            rowIndex = 0x33;
            break;
        case SCENE_TEST:
            rowIndex = 0x33;
            break;
        case SCENE_WL_MENU:
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                rowIndex = 0x33;
            } else {
                rowIndex = 0x2e;
            }
            break;
        case SCENE_MENU_1:
            rowIndex = 0x32;
            break;
        case SCENE_RESULT:
            rowIndex = 0x29;
            *output = g_CourseBgmTable[rowIndex];
            rowWritten = TRUE;
            output->mSeqId = GetResultSceneSeqId();
            break;
        case SCENE_RECORD:
            rowIndex = 0x2f;
            break;
        case SCENE_GHOST:
            rowIndex = 0x2e;
            break;
        case SCENE_LOGO:
            rowIndex = 0x31;
            break;
        case SCENE_TITLE:
            rowIndex = 0x33;
            break;
        case SCENE_EMBLEM:
        case SCENE_OPTION:
        case SCENE_NICKNAME:
        case SCENE_KEYBOARD:
            rowIndex = 0x30;
            *output = g_CourseBgmTable[rowIndex];
            rowWritten = TRUE;
            if (gCurrentSoundSetPlayer != NULL) {
                output->mSeqId = SOUND_ID_NONE;
                output->mFirstBankId = SOUND_ID_NONE;
                output->mSecondBankId = SOUND_ID_NONE;
            }
            break;
        case SCENE_ENDING:
            rowIndex = 0x33;
            break;
    }
    if (rowWritten == FALSE && output != NULL) {
        *output = g_CourseBgmTable[rowIndex];
    }
    return rowIndex;
}
