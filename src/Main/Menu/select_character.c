#include "Main/Menu/select_character.h"
#include "Main/System/data_02025000.h"
#include "Main/Graphics/cell_layout_entry.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/data_02153000.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/System/interpolation.h"
#include "Main/Menu/player_entry_list.h"
#include "Main/Kart/karts.h"
#include "registers.h"
#include "Main/Race/race_setup.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "g2.h"
#include "Main/Graphics/message_index.h"
#include "Main/Menu/data_0202bb80.h"
#include "Main/Save/backup_reset.h"
#include "Main/Scene/display_settings.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/oam_matrix_count.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Menu/picks_holder.h"
#include "Main/Net/wifi_session.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/player_character_cell_file_set.h"
#include "Main/Kart/data_02161000.h"
#include "Main/System/interpolation_state.h"
#include "code_0214d018.h"
#include "Main/Menu/select_kart_data.h"
#include "Main/System/init_after_startup.h"
#include "Main/Race/data_021759c0.h"

#pragma thumb on

SelectCharacter *gSelectCharacter;

void SetSelectCharacterKeyTargets8Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow0[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow0[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow0[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow0[3];
            break;
        case 1:
            if (selectCharacter->mPreviousTableIndex == 4) {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow1Previous4[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow1Previous4[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow1Previous4[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow1Previous4[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow1Else[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow1Else[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow1Else[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow1Else[3];
            }
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow2[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow2[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow2[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow2[3];
            break;
        case 3:
            if (selectCharacter->mPreviousTableIndex == 1 || selectCharacter->mPreviousTableIndex == 6) {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow3Previous1Or6[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow3Previous1Or6[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow3Previous1Or6[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow3Previous1Or6[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow3Else[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow3Else[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow3Else[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow3Else[3];
            }
            break;
        case 4:
            if (selectCharacter->mPreviousTableIndex == 2 || selectCharacter->mPreviousTableIndex == 7) {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow4Previous2Or7[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow4Previous2Or7[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow4Previous2Or7[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow4Previous2Or7[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow4Else[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow4Else[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow4Else[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow4Else[3];
            }
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow5[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow5[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow5[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow5[3];
            break;
        case 6:
            if (selectCharacter->mPreviousTableIndex == 4) {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow6Previous4[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow6Previous4[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow6Previous4[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow6Previous4[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow6Else[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow6Else[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow6Else[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow6Else[3];
            }
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets8RowsRow7[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets8RowsRow7[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets8RowsRow7[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets8RowsRow7[3];
            break;
    }
}

void SetSelectCharacterKeyTargets9Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets9RowsRow0[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets9RowsRow0[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets9RowsRow0[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets9RowsRow0[3];
            break;
        case 1:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets9RowsRow1[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets9RowsRow1[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets9RowsRow1[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets9RowsRow1[3];
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets9RowsRow2[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets9RowsRow2[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets9RowsRow2[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets9RowsRow2[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets9RowsRow3[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets9RowsRow3[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets9RowsRow3[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets9RowsRow3[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets9RowsRow4[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets9RowsRow4[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets9RowsRow4[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets9RowsRow4[3];
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets9RowsRow5[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets9RowsRow5[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets9RowsRow5[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets9RowsRow5[3];
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets9RowsRow6[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets9RowsRow6[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets9RowsRow6[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets9RowsRow6[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets9RowsRow7[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets9RowsRow7[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets9RowsRow7[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets9RowsRow7[3];
            break;
        case 8:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets9RowsRow8[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets9RowsRow8[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets9RowsRow8[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets9RowsRow8[3];
            break;
    }
}

void SetSelectCharacterKeyTargets10Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow0[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow0[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow0[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow0[3];
            break;
        case 1:
            if (selectCharacter->mPreviousTableIndex == 5) {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow1Previous5[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow1Previous5[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow1Previous5[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow1Previous5[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow1Else[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow1Else[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow1Else[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow1Else[3];
            }
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow2[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow2[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow2[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow2[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow3[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow3[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow3[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow3[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow4[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow4[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow4[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow4[3];
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow5[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow5[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow5[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow5[3];
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow6[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow6[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow6[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow6[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow7[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow7[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow7[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow7[3];
            break;
        case 8:
            if (selectCharacter->mPreviousTableIndex == 5) {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow8Previous5[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow8Previous5[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow8Previous5[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow8Previous5[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow8Else[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow8Else[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow8Else[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow8Else[3];
            }
            break;
        case 9:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets10RowsRow9[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets10RowsRow9[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets10RowsRow9[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets10RowsRow9[3];
            break;
    }
}

void SetSelectCharacterKeyTargets11Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow0[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow0[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow0[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow0[3];
            break;
        case 1:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow1[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow1[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow1[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow1[3];
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow2[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow2[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow2[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow2[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow3[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow3[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow3[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow3[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow4[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow4[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow4[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow4[3];
            break;
        case 5:
            if (selectCharacter->mPreviousTableIndex == 2 || selectCharacter->mPreviousTableIndex == 9) {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow5Previous2Or9[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow5Previous2Or9[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow5Previous2Or9[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow5Previous2Or9[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow5Else[0];
                selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow5Else[1];
                selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow5Else[2];
                selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow5Else[3];
            }
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow6[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow6[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow6[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow6[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow7[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow7[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow7[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow7[3];
            break;
        case 8:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow8[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow8[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow8[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow8[3];
            break;
        case 9:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow9[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow9[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow9[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow9[3];
            break;
        case 10:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets11RowsRow10[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets11RowsRow10[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets11RowsRow10[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets11RowsRow10[3];
            break;
    }
}

void SetSelectCharacterKeyTargets12Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow0[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow0[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow0[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow0[3];
            break;
        case 1:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow1[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow1[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow1[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow1[3];
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow2[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow2[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow2[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow2[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow3[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow3[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow3[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow3[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow4[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow4[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow4[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow4[3];
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow5[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow5[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow5[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow5[3];
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow6[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow6[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow6[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow6[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow7[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow7[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow7[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow7[3];
            break;
        case 8:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow8[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow8[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow8[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow8[3];
            break;
        case 9:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow9[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow9[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow9[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow9[3];
            break;
        case 10:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow10[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow10[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow10[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow10[3];
            break;
        case 11:
            selectCharacter->mTableIndexByKey[0] = gKeyTargets12RowsRow11[0];
            selectCharacter->mTableIndexByKey[1] = gKeyTargets12RowsRow11[1];
            selectCharacter->mTableIndexByKey[2] = gKeyTargets12RowsRow11[2];
            selectCharacter->mTableIndexByKey[3] = gKeyTargets12RowsRow11[3];
            break;
    }
}

void StartPlayerEntryListKindIfUsed(s32 kind) {
    if (gSelectCharacter->mUsePlayerEntryList != FALSE) {
        StartPlayerEntryListKind(kind);
    }
}

void StartSelectCharacterReturn(void) {
    gSelectCharacter->mStateFrames = 0;
    gSelectCharacter->mResult = 2;
    gSelectCharacter->mState = SELECT_CHARACTER_STATE_SCALE_OUT;
    RequestSelectReturnState3WithSound(0);
    StartPlayerEntryListKindIfUsed(3);
    SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[0], INTERPOLATION_STATE_FALLING);
    SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1], INTERPOLATION_STATE_FALLING);
    SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[2], INTERPOLATION_STATE_FALLING);
    StartKartModelMenuBg0Decrease();
}

void SetSelectCharacterRowCellsVisible(s32 visible) {
    SelectCharacter *selectCharacter;
    s32 rowIndex;
    CellFileSet *sParts;

    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mSParts;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        for (rowIndex = 0; rowIndex < gSelectCharacter->mTableRowCount; rowIndex++) {
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mOffsetCellIndex].mVisible = visible;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mVisible =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mOffsetCellIndex].mVisible;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mBracketCellIndex].mVisible =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mVisible;
        }
        sParts->mCellTable[25].mVisible = visible;
    }
}

void SetSelectCharacterBracketsResting(void) {
    s32 rowIndex;
    CellFileSet *sParts;
    const SelectCharacterRowCellIndices *tableRow;

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        sParts = &gSelectCharacter->mSParts;
        sParts->mCellTable[24].mVisible = 0;
        sParts->mCellTable[25].mVisible = 1;
        tableRow = gSelectCharacterRowCellIndices;
        for (rowIndex = 0; rowIndex < 12; rowIndex++) {
            sParts->mCellTable[tableRow->mCharacterCellIndex].mOffsetX = 0;
            sParts->mCellTable[tableRow->mCharacterCellIndex].mOffsetY = 0;
            tableRow++;
        }
    }
}

void SetSelectCharacterCellOffsetsY(s16 firstOffsetY, s16 secondOffsetY) {
    SelectCharacter *selectCharacter;

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        selectCharacter = gSelectCharacter;
        if (selectCharacter->mUsePlayerEntryList == FALSE) {
            selectCharacter->mGpMParts.mCellTable[0].mOffsetY = firstOffsetY;
            selectCharacter->mGpMParts.mCellTable[3].mOffsetY = secondOffsetY;
        }
    }
}

void SetSelectCharacterNameOffsetX(s16 offsetX) {
    SelectCharacter *selectCharacter;

    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        selectCharacter = gSelectCharacter;
        if (selectCharacter->mUsePlayerEntryList == FALSE) {
            selectCharacter->mGpMParts.mCellTable[1].mOffsetX = offsetX;
            selectCharacter->mGpMParts.mCellTable[2].mOffsetX = selectCharacter->mGpMParts.mCellTable[1].mOffsetX;
        }
    }
}

void QueueSelectCharacterNameChars(void) {
    SelectCharacter *selectCharacter;
    CellFileSet *nameParts;

    selectCharacter = gSelectCharacter;
    if (selectCharacter->mUsePlayerEntryList == FALSE) {
        nameParts = &selectCharacter->mGpNameMParts;
        QueueCellChars(*(s16 *) &selectCharacter->mRows[selectCharacter->mTableIndex].mNameLayoutEntryIndex,
                       nameParts->mCells, selectCharacter->mGpNameMParts.mChars, nameParts->mCellLayout, 0, 2,
                       selectCharacter->mGpMParts.mCells, selectCharacter->mGpMParts.mCellLayout);
        QueueCellChars(*(s16 *) &gSelectCharacter->mRows[gSelectCharacter->mTableIndex].mNameLayoutEntryIndex,
                       nameParts->mCells, selectCharacter->mGpNameMParts.mChars, nameParts->mCellLayout, 0, 1,
                       selectCharacter->mGpMParts.mCells, selectCharacter->mGpMParts.mCellLayout);
    }
}

void MoveSelectCharacterBracketsToRow(void) {
    SelectCharacter *selectCharacter;
    CellFileSet *sParts;
    s32 tableIndex;
    SelectCharacterRowCellIndices *tableRow;

    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mSParts;
    tableIndex = selectCharacter->mTableIndex;
    tableRow = (SelectCharacterRowCellIndices *) gSelectCharacterRowCellIndices;
    CopyCellLayoutEntryPosition(0x18, tableRow[tableIndex].mBracketCellIndex, sParts->mCellLayout);
    CopyCellLayoutEntryPosition(0x19, tableRow[tableIndex].mBracketCellIndex, sParts->mCellLayout);
}

void SetSelectCharacterBracketsMoving(void) {
    SelectCharacter *selectCharacter;
    CellFileSet *sParts;
    const SelectCharacterRowCellIndices *tableRow;

    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mSParts;
    tableRow = &gSelectCharacterRowCellIndices[selectCharacter->mTableIndex];
    sParts->mCellTable[24].mVisible = 1;
    sParts->mCellTable[25].mVisible = 0;
    sParts->mCellTable[tableRow->mCharacterCellIndex].mOffsetX = 1;
    sParts->mCellTable[tableRow->mCharacterCellIndex].mOffsetY = 1;
}

#pragma thumb off

#pragma thumb on

void RefreshSelectCharacterRowCells(void) {
    SetSelectCharacterBracketsMoving();
    MoveSelectCharacterBracketsToRow();
}

#pragma thumb off

#pragma thumb on

void SetupSelectCharacterRow(s32 previousTableIndex) {
    gSelectCharacter->mPreviousTableIndex = previousTableIndex;
    switch (gSelectCharacter->mTableRowCount) {
        case 8:
            SetSelectCharacterKeyTargets8Rows();
            break;
        case 9:
            SetSelectCharacterKeyTargets9Rows();
            break;
        case 10:
            SetSelectCharacterKeyTargets10Rows();
            break;
        case 11:
            SetSelectCharacterKeyTargets11Rows();
            break;
        case 12:
            SetSelectCharacterKeyTargets12Rows();
            break;
    }
    RefreshSelectCharacterRowCells();
    QueueSelectCharacterNameChars();
    SetInterpolationState(&gSelectCharacter->mInterpolations[0], INTERPOLATION_STATE_RISING);
    gSelectCharacter->mCharacterIndex = gSelectCharacter->mRows[gSelectCharacter->mTableIndex].mCharacterIndex;
    gSelectCharacter->mKartIndex = GetCharacterKartIndexByMode(gSelectCharacter->mCharacterIndex);
}

#pragma thumb off

#pragma thumb on

u32 IsSelectCharacterModeAndTimerZero(void) {
    int result;
    if ((gSelectCharacter->mMode != SELECT_CHARACTER_MODE_NO_CONNECTION) &&
        (result = IsPlayerEntryListTimerZero(), result != 0)) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void SetSelectCharacterAngleAndScale(void) {
    CellFileSet *sParts = &gSelectCharacter->mSParts;
    s32 cellIndex;
    s32 elementCount;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        elementCount = sParts->mCellLayout->mCount;
        for (cellIndex = 0; cellIndex < elementCount; cellIndex++) {
            SetLayoutEntryAngleAndScale(&sParts->mCellTable[cellIndex], gSelectCharacter->mAngle,
                                        gSelectCharacter->mScale);
        }
    }
}

#pragma thumb off

#pragma thumb on

void InitSelectCharacter(void *parentHeap, s32 mode, void *mainOam, void *subOam) {
    void *heap;
    SelectCharacter *selectCharacter;
    CellFileSet *sParts;
    const SelectCharacterRowPosition *positions;
    s32 rowIndex;
    s32 tableIndex;
    s32 modeValue;
    BOOL usePlayerEntryList;
    CellFileSet titleParts;
    CellFileSet cellFileSet;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectCharacter = HeapAlloc(heap, 0x12c);
    MemFillWordsByBlock_inline(gSelectCharacter, 0x12c);
    gSelectCharacter->mHeap = heap;
    gSelectCharacter->mMode = mode;
    switch (GetRaceSetupCopy()->mEntryTransition) {
        case 0:
            SetupInterpolation(&gSelectCharacter->mInterpolations[0], 0, 10, -0x80, 0);
            SetupInterpolation(&gSelectCharacter->mInterpolations[2], 0, 10, 0x60, 0);
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                StartKartModelMenuBg0Increase();
            }
            break;
        case 2:
            SetupInterpolation(&gSelectCharacter->mInterpolations[0], 1, 10, -0x80, 0);
            SetupInterpolation(&gSelectCharacter->mInterpolations[2], 1, 10, 0x60, 0);
            switch (gSelectCharacter->mMode) {
                case SELECT_CHARACTER_MODE_CONNECTION:
                    if (gConnectionWork->mState == CONNECTION_STATE_SYNCED) {
                        gConnectionWork->mDataSharingSendByte = 0xff;
                    }
                    break;
                case SELECT_CHARACTER_MODE_WIFI_SESSION:
                    SetWiFiSessionOwnCharacterIndexNone();
                    break;
            }
            break;
    }
    SetupInterpolation(&gSelectCharacter->mInterpolations[1], 0, 10, -0x40, 0);
    gSelectCharacter->mMainOam = mainOam;
    gSelectCharacter->mSubOam = subOam;
    if (gSelectCharacter->mMode != SELECT_CHARACTER_MODE_NO_CONNECTION || GetRaceSetupCopy()->mMode == 3 ||
        GetRaceSetupCopy()->mMode == 2) {
        usePlayerEntryList = TRUE;
    } else {
        usePlayerEntryList = FALSE;
    }
    gSelectCharacter->mUsePlayerEntryList = usePlayerEntryList;
    if (gSelectCharacter->mUsePlayerEntryList != FALSE) {
        switch (gSelectCharacter->mMode) {
            case SELECT_CHARACTER_MODE_NO_CONNECTION:
                modeValue = 0;
                break;
            case SELECT_CHARACTER_MODE_CONNECTION:
                modeValue = 1;
                break;
            case SELECT_CHARACTER_MODE_WIFI_SESSION:
                modeValue = 2;
                break;
        }
        SetupPlayerEntryList(modeValue, PLAYER_ENTRY_LIST_CHARACTER);
    }
    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mMode) {
        case SELECT_CHARACTER_MODE_NO_CONNECTION:
            selectCharacter->mEntryIndex = 0;
            break;
        case SELECT_CHARACTER_MODE_CONNECTION:
            selectCharacter->mEntryIndex =
                GetParticipantPosByIndex(
                    gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0)
                    ->mEntryIndex;
            break;
        case SELECT_CHARACTER_MODE_WIFI_SESSION:
            gSelectCharacter->mEntryIndex = GetRaceSetupCopyEntryIndex();
            break;
    }
    selectCharacter = gSelectCharacter;
    if (selectCharacter->mUsePlayerEntryList == FALSE) {
        LocateCellFileSet(&selectCharacter->mGpMParts, "select_character_gp_m.nce.ncgr",
                          "select_character_gp_m.nce.ncer", "select_character_gp_m_o.NCLR",
                          "select_character_gp_m.bncl", NULL, NULL, FindFileInLoadedArchives);
        SetupCellFileSet(SCREEN_SIDE_MAIN, gSelectCharacter->mHeap, &selectCharacter->mGpMParts);
        LocateCellFileSet(&titleParts, "select_character_gp_title_m.nce.ncgr", "select_character_gp_title_m.nce.ncer",
                          NULL, "select_character_gp_title_m.bncl", NULL, NULL, FindFileInLoadedArchives);
        QueueCellChars(0, titleParts.mCells, titleParts.mChars, titleParts.mCellLayout, 0, 0,
                       selectCharacter->mGpMParts.mCells, selectCharacter->mGpMParts.mCellLayout);
        LocateCellFileSet(&gSelectCharacter->mGpNameMParts, "select_character_gp_name_m.nce.ncgr",
                          "select_character_gp_name_m.nce.ncer", NULL, "select_character_gp_name_m.bncl", NULL, NULL,
                          FindFileInLoadedArchives);
        selectCharacter->mGpMParts.mCellTable[9].mVisible = 0;
        selectCharacter->mGpMParts.mCellTable[8].mVisible = selectCharacter->mGpMParts.mCellTable[9].mVisible;
        selectCharacter->mGpMParts.mCellTable[7].mVisible = selectCharacter->mGpMParts.mCellTable[8].mVisible;
        selectCharacter->mGpMParts.mCellTable[6].mVisible = selectCharacter->mGpMParts.mCellTable[7].mVisible;
        selectCharacter->mGpMParts.mCellTable[5].mVisible = selectCharacter->mGpMParts.mCellTable[6].mVisible;
        selectCharacter->mGpMParts.mCellTable[4].mVisible = selectCharacter->mGpMParts.mCellTable[5].mVisible;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        sParts = &gSelectCharacter->mSParts;
        LocateCellFileSet(sParts, "select_character_s.nce.ncgr", "select_character_s.nce.ncer",
                          "select_character_s_o.NCLR", "select_character_s.bncl", NULL, "select_character_s.bnbl",
                          FindFileInLoadedArchives);
        SetupCellFileSet(SCREEN_SIDE_SUB, gSelectCharacter->mHeap, sParts);
        sParts->mCellTable[24].mVisible = 0;
        for (rowIndex = 0; rowIndex < 12; rowIndex++) {
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mOffsetCellIndex].mUseMatrix = 1;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mUseMatrix =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mOffsetCellIndex].mUseMatrix;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mBracketCellIndex].mUseMatrix =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mUseMatrix;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mOffsetCellIndex].mDoubleAffine = 0;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mDoubleAffine =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mOffsetCellIndex].mDoubleAffine;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mBracketCellIndex].mDoubleAffine =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mDoubleAffine;
        }
        sParts->mCellTable[25].mUseMatrix = 1;
        sParts->mCellTable[24].mUseMatrix = sParts->mCellTable[25].mUseMatrix;
        sParts->mCellTable[25].mDoubleAffine = 0;
        sParts->mCellTable[24].mDoubleAffine = sParts->mCellTable[25].mDoubleAffine;
    } else if (GetRaceSetupCopy()->mMode == 2) {
        InitSelectRaceRuleWait(gSelectCharacter->mHeap, gSelectCharacter->mSubOam);
        SlideInSelectRaceRuleWait();
    }
    gSelectCharacter->mTableRowCount = 8;
    for (rowIndex = 0; rowIndex < 8; rowIndex++) {
        gSelectCharacter->mRows[rowIndex] = gSelectCharacterRows[rowIndex];
    }
    if (IsBackupFlagSet(0x15) != 0) {
        gSelectCharacter->mRows[rowIndex] = gSelectCharacterRows[8];
        rowIndex++;
        gSelectCharacter->mTableRowCount++;
    }
    if (IsBackupFlagSet(0x14) != 0) {
        gSelectCharacter->mRows[rowIndex] = gSelectCharacterRows[9];
        rowIndex++;
        gSelectCharacter->mTableRowCount++;
    }
    if (IsBackupFlagSet(0x16) != 0) {
        gSelectCharacter->mRows[rowIndex] = gSelectCharacterRows[10];
        rowIndex++;
        gSelectCharacter->mTableRowCount++;
    }
    if (IsBackupFlagSet(0x17) != 0) {
        gSelectCharacter->mRows[rowIndex] = gSelectCharacterRows[11];
        rowIndex++;
        gSelectCharacter->mTableRowCount++;
    }
    for (; rowIndex < 12; rowIndex++) {
        gSelectCharacter->mRows[rowIndex].mCharacterIndex = -1;
    }
    for (tableIndex = 0; tableIndex < gSelectCharacter->mTableRowCount; tableIndex++) {
        if (gSelectCharacter->mRows[tableIndex].mCharacterIndex ==
            GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex) {
            gSelectCharacter->mTableIndex = tableIndex;
        }
    }
    gSelectCharacter->mPreviousTableIndex = gSelectCharacter->mTableIndex;
    selectCharacter = gSelectCharacter;
    selectCharacter->mCharacterIndex = GetRaceSetupCopy()->mEntries[selectCharacter->mEntryIndex].mCharacterIndex;
    if (gSelectCharacter->mCharacterIndex == -1) {
        gSelectCharacter->mCharacterIndex = CHARACTER_MARIO;
    }
    gSelectCharacter->mKartIndex = GetCharacterKartIndexByMode(gSelectCharacter->mCharacterIndex);
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartStored = 0;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        sParts = &gSelectCharacter->mSParts;
        SetPlayerCharacterCellFileSet(0, &cellFileSet);
        for (rowIndex = 0; rowIndex < gSelectCharacter->mTableRowCount; rowIndex++) {
            QueueCellCharsAndCopyPalettes(gSelectCharacter->mRows[rowIndex].mCharacterIndex, cellFileSet.mCells,
                                          cellFileSet.mChars, cellFileSet.mPalette, cellFileSet.mCellLayout, 1,
                                          gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex, sParts->mCells,
                                          sParts->mCellLayout);
        }
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        positions = NULL;
        sParts = &gSelectCharacter->mSParts;
        switch (gSelectCharacter->mTableRowCount) {
            case 8:
                positions = gSelectCharacterPositions8Rows;
                SetSelectCharacterKeyTargets8Rows();
                break;
            case 9:
                positions = gSelectCharacterPositions9Rows;
                SetSelectCharacterKeyTargets9Rows();
                break;
            case 10:
                positions = gSelectCharacterPositions10Rows;
                SetSelectCharacterKeyTargets10Rows();
                break;
            case 11:
                positions = gSelectCharacterPositions11Rows;
                SetSelectCharacterKeyTargets11Rows();
                break;
            case 12:
                SetSelectCharacterKeyTargets12Rows();
                break;
        }
        if (positions != NULL) {
            for (rowIndex = 0; rowIndex < gSelectCharacter->mTableRowCount; rowIndex++) {
                SetCellLayoutEntryXY(gSelectCharacterRowCellIndices[rowIndex].mBracketCellIndex,
                                     positions[rowIndex].mEntryX, positions[rowIndex].mEntryY, sParts->mCellLayout);
                SetCellLayoutEntryXY(gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex,
                                     positions[rowIndex].mEntryX, positions[rowIndex].mEntryY, sParts->mCellLayout);
                RectTableSetEntryXY(gSelectCharacterRowCellIndices[rowIndex].mRectEntryId, positions[rowIndex].mEntryX,
                                    positions[rowIndex].mEntryY, sParts->mRects);
                SetCellLayoutEntryXY(gSelectCharacterRowCellIndices[rowIndex].mOffsetCellIndex,
                                     (s16) (positions[rowIndex].mEntryX + 3), (s16) (positions[rowIndex].mEntryY + 3),
                                     sParts->mCellLayout);
            }
            for (; rowIndex < 12; rowIndex++) {
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mBracketCellIndex].mVisible = 0;
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mVisible = 0;
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mOffsetCellIndex].mVisible = 0;
                RectTableSetEntryXY(gSelectCharacterRowCellIndices[rowIndex].mRectEntryId, 0x400, 0x400,
                                    sParts->mRects);
            }
        }
        MoveSelectCharacterBracketsToRow();
        QueueSelectCharacterNameChars();
    }
    if (gSelectCharacter->mMode == SELECT_CHARACTER_MODE_NO_CONNECTION) {
        ClearNonParticipantCharacterIndices();
        SetSelectReturnSoundId(0xe);
        RequestSelectReturnState1();
    }
    if (AreBrightnessFadesClear() != 0) {
        gSelectCharacter->mState = SELECT_CHARACTER_STATE_SCALE_IN;
    } else {
        StartFadeToClear(10);
        SetSelectCharacterRowCellsVisible(0);
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        SetKartModelMenuSpinStopped(0);
    }
    FrmHeapShrinkInParent(gSelectCharacter->mHeap);
}

#pragma thumb off

#pragma thumb on

static inline s32 SelectCharacterIsPairRecentlyLost(u16 inputSlot) {
    BOOL result = FALSE;
    if (gInputSlots[inputSlot].mPair.mHasPair == 0 && gInputSlots[inputSlot].mPair.mNoPairCount < 5) {
        result = TRUE;
    }
    return result;
}

static inline s32 SelectCharacterIsPairNewUnlessLost(u16 inputSlot) {
    BOOL result = FALSE;
    if (SelectCharacterIsPairRecentlyLost(inputSlot) == 0 && gInputSlots[inputSlot].mPair.mPrevHasPair == 0 &&
        gInputSlots[inputSlot].mPair.mHasPair != 0) {
        result = TRUE;
    }
    return result;
}

int AdvanceSelectCharacter(void) {
    int result;
    SelectCharacter *selectCharacter;
    CellFileSet *sParts;
    s32 previousTableIndex;
    SelectCharacter *selectCharacterReload;
    u16 inputSlot;
    s32 nextState;
    s32 tableIndex;
    s32 rectEntryId;
    s32 pointX;
    s32 pointY;
    u16 keyBits;
    u8 flaggedCharacterIndex;
    s16 targetTableIndex;
    s16 interpolatedValue;

    result = 0;
    inputSlot = GetPadInputSlot();
    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mSParts;
    switch (selectCharacter->mState) {
        case SELECT_CHARACTER_STATE_WAIT_FADE:
            if (AreBrightnessFadesClear() != 0) {
                gSelectCharacter->mState = SELECT_CHARACTER_STATE_SCALE_IN;
            }
            break;
        case SELECT_CHARACTER_STATE_SCALE_IN:
            if (selectCharacter->mStateFrames == 0) {
                SetSelectCharacterRowCellsVisible(1);
            }
            gSelectCharacter->mStateFrames++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mStateFrames < SELECT_CHARACTER_SCALE_STEPS) {
                selectCharacterReload->mScale =
                    TO_FIXED12(selectCharacterReload->mStateFrames) / SELECT_CHARACTER_SCALE_STEPS;
            } else {
                selectCharacterReload->mScale = TO_FIXED12(1);
                gSelectCharacter->mStateFrames = 0;
                if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                    nextState = 2;
                } else {
                    nextState = 3;
                }
                gSelectCharacter->mState = nextState;
            }
            SetSelectCharacterAngleAndScale();
            break;
        case SELECT_CHARACTER_STATE_PICK_FIXED:
            selectCharacter->mCharacterIndex = CHARACTER_HEYHO;
            gSelectCharacter->mKartIndex = 0x24;
            gSelectCharacter->mStateFrames = 0;
            gSelectCharacter->mResult = 1;
            if (GetRaceSetupCopy()->mMode == 3) {
                flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0x40;
                if (gConnectionWork->mState == CONNECTION_STATE_SYNCED) {
                    gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                }
                StartPlayerEntryListKindIfUsed(1);
                gSelectCharacter->mState = SELECT_CHARACTER_STATE_SCALE_OUT;
            } else if (GetRaceSetupCopy()->mMode == 2) {
                flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0xc0;
                if (gConnectionWork->mState == CONNECTION_STATE_SYNCED) {
                    gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                }
                gSelectCharacter->mState = SELECT_CHARACTER_STATE_WAIT_OTHERS;
            }
            break;
        case SELECT_CHARACTER_STATE_CHOOSE:
            previousTableIndex = selectCharacter->mTableIndex;
            if (SelectCharacterIsPairNewUnlessLost(inputSlot) != 0) {
                pointX = gInputSlots[inputSlot].mPair.mPairX;
                pointY = gInputSlots[inputSlot].mPair.mPairY;
                rectEntryId = RectTableFindContaining(sParts->mRects, pointX, pointY);
                if (rectEntryId >= 0) {
                    for (tableIndex = 0; tableIndex < gSelectCharacter->mTableRowCount; tableIndex++) {
                        if (rectEntryId == gSelectCharacterRowCellIndices[tableIndex].mRectEntryId) {
                            gSelectCharacter->mTableIndex = tableIndex;
                            break;
                        }
                    }
                    SetupSelectCharacterRow(previousTableIndex);
                    StartSeqPair(GetCharacterSeqPairNo(gSelectCharacter->mCharacterIndex), 0);
                    gSelectCharacter->mStateFrames = 0;
                    gSelectCharacter->mState = SELECT_CHARACTER_STATE_WAIT_PICK;
                } else if (gSelectCharacter->mMode == SELECT_CHARACTER_MODE_NO_CONNECTION &&
                           IsSelectReturnState2NoState3Or4RequestAndInRect(pointX, pointY) != FALSE) {
                    StartSelectCharacterReturn();
                }
            } else if (IsSelectCharacterModeAndTimerZero() != 0) {
                gSelectCharacter->mStateFrames = 0;
                gSelectCharacter->mResult = 3;
                gSelectCharacter->mState = SELECT_CHARACTER_STATE_WAIT_OTHERS;
                StartSeqPair(GetCharacterSeqPairNo(gSelectCharacter->mCharacterIndex), 0);
                SetKartModelMenuSpinStopped(1);
                selectCharacterReload = gSelectCharacter;
                switch (selectCharacterReload->mMode) {
                    case SELECT_CHARACTER_MODE_WIFI_SESSION:
                        SetWiFiSessionOwnCharacterIndex(selectCharacterReload->mCharacterIndex);
                        SetWiFiSessionOwnKartIndex(gSelectCharacter->mKartIndex);
                        break;
                    case SELECT_CHARACTER_MODE_CONNECTION:
                        flaggedCharacterIndex = selectCharacterReload->mCharacterIndex | 0xc0;
                        if (gConnectionWork->mState == CONNECTION_STATE_SYNCED) {
                            gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                        }
                        break;
                }
            } else {
                keyBits = gInputSlots[inputSlot].mPressedBits;
                if ((u16) (keyBits & PAD_KEY_A) != 0) {
                    gSelectCharacter->mStateFrames = 0;
                    gSelectCharacter->mState = SELECT_CHARACTER_STATE_WAIT_PICK;
                    RefreshSelectCharacterRowCells();
                    StartSeqPair(GetCharacterSeqPairNo(gSelectCharacter->mCharacterIndex), 0);
                } else if (gSelectCharacter->mMode == SELECT_CHARACTER_MODE_NO_CONNECTION &&
                           (u16) (keyBits & PAD_KEY_B) != 0) {
                    StartSelectCharacterReturn();
                } else {
                    if (GetNewOrRepeatBits(inputSlot, PAD_KEY_UP) != 0) {
                        selectCharacterReload = gSelectCharacter;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[0];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mTableIndex = targetTableIndex;
                        }
                    } else if (GetNewOrRepeatBits(inputSlot, PAD_KEY_DOWN) != 0) {
                        selectCharacterReload = gSelectCharacter;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[1];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mTableIndex = targetTableIndex;
                        }
                    } else if (GetNewOrRepeatBits(inputSlot, PAD_KEY_RIGHT) != 0) {
                        selectCharacterReload = gSelectCharacter;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[2];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mTableIndex = targetTableIndex;
                        }
                    } else if (GetNewOrRepeatBits(inputSlot, PAD_KEY_LEFT) != 0) {
                        selectCharacterReload = gSelectCharacter;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[3];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mTableIndex = targetTableIndex;
                        }
                    }
                    if (gSelectCharacter->mTableIndex != previousTableIndex) {
                        StartCursorMoveSound();
                        SetupSelectCharacterRow(previousTableIndex);
                        gSelectCharacter->mState = SELECT_CHARACTER_STATE_WAIT_MOVE;
                    }
                }
            }
            break;
        case SELECT_CHARACTER_STATE_WAIT_MOVE:
            selectCharacter->mStateFrames++;
            if (gSelectCharacter->mStateFrames > SELECT_CHARACTER_SETTLE_STEPS) {
                SetSelectCharacterBracketsResting();
                gSelectCharacter->mStateFrames = 0;
                gSelectCharacter->mState = SELECT_CHARACTER_STATE_CHOOSE;
            }
            break;
        case SELECT_CHARACTER_STATE_WAIT_PICK:
            selectCharacter->mStateFrames++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mStateFrames > SELECT_CHARACTER_SETTLE_STEPS) {
                selectCharacterReload->mStateFrames = 0;
                gSelectCharacter->mResult = 1;
                SetSelectCharacterBracketsResting();
                selectCharacterReload = gSelectCharacter;
                switch (selectCharacterReload->mMode) {
                    case SELECT_CHARACTER_MODE_NO_CONNECTION:
                        GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex =
                            selectCharacterReload->mCharacterIndex;
                        GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartIndex =
                            gSelectCharacter->mKartIndex;
                        FillRandomCharacterIndices();
                        if (GetRaceSetupCopy()->mMode == 2) {
                            GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartStored = 1;
                            SetKartModelMenuSpinStopped(1);
                            gSelectCharacter->mState = SELECT_CHARACTER_STATE_WAIT_HOLD;
                            ClearNonParticipantKartIndices();
                            SetKartIndicesFromCharacters();
                        } else {
                            StartPlayerEntryListKindIfUsed(1);
                            StartKartModelMenuTimedSpinStop();
                            gSelectCharacter->mState = SELECT_CHARACTER_STATE_SCALE_OUT;
                            SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1],
                                                            INTERPOLATION_STATE_FALLING);
                        }
                        break;
                    case SELECT_CHARACTER_MODE_CONNECTION:
                        if (GetRaceSetupCopy()->mMode == 3) {
                            flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0x40;
                            if (gConnectionWork->mState == CONNECTION_STATE_SYNCED) {
                                gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                            }
                            SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1],
                                                            INTERPOLATION_STATE_FALLING);
                            StartPlayerEntryListKindIfUsed(1);
                            gSelectCharacter->mState = SELECT_CHARACTER_STATE_SCALE_OUT;
                            StartKartModelMenuTimedSpinStop();
                        } else if (GetRaceSetupCopy()->mMode == 2) {
                            flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0xc0;
                            if (gConnectionWork->mState == CONNECTION_STATE_SYNCED) {
                                gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                            }
                            SetKartModelMenuSpinStopped(1);
                            gSelectCharacter->mState = SELECT_CHARACTER_STATE_WAIT_OTHERS;
                        }
                        break;
                    case SELECT_CHARACTER_MODE_WIFI_SESSION:
                        SetWiFiSessionOwnCharacterIndex(selectCharacterReload->mCharacterIndex);
                        SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1],
                                                        INTERPOLATION_STATE_FALLING);
                        StartPlayerEntryListKindIfUsed(1);
                        gSelectCharacter->mState = SELECT_CHARACTER_STATE_SCALE_OUT;
                        StartKartModelMenuTimedSpinStop();
                        break;
                }
            }
            break;
        case SELECT_CHARACTER_STATE_WAIT_OTHERS:
            if ((selectCharacter->mMode == SELECT_CHARACTER_MODE_CONNECTION && IsEveryPlayerKartStored() != 0) ||
                (gSelectCharacter->mMode == SELECT_CHARACTER_MODE_WIFI_SESSION && IsWiFiSessionStep7Reached() != 0)) {
                if (gSelectCharacter->mMode == SELECT_CHARACTER_MODE_WIFI_SESSION) {
                    WriteWiFiSessionToRaceSetupCopy();
                }
                if (GetRaceSetupCopy()->mMode == 2 || IsSelectCharacterModeAndTimerZero() != 0) {
                    gSelectCharacter->mState = SELECT_CHARACTER_STATE_WAIT_HOLD;
                } else {
                    StartPlayerEntryListKindIfUsed(1);
                    SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1], INTERPOLATION_STATE_FALLING);
                    gSelectCharacter->mState = SELECT_CHARACTER_STATE_SCALE_OUT;
                }
            }
            break;
        case SELECT_CHARACTER_STATE_WAIT_HOLD:
            selectCharacter->mStateFrames++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mStateFrames > SELECT_CHARACTER_HOLD_STEPS) {
                if (selectCharacterReload->mMode == SELECT_CHARACTER_MODE_WIFI_SESSION) {
                    StartPlayerEntryListKindIfUsed(3);
                } else {
                    StartPlayerEntryListKindIfUsed(2);
                }
                SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1], INTERPOLATION_STATE_FALLING);
                if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                    StartKartModelMenuBg0Decrease();
                } else if (GetRaceSetupCopy()->mMode == 2) {
                    SlideOutSelectRaceRuleWait();
                }
                gSelectCharacter->mStateFrames = 0;
                gSelectCharacter->mState = SELECT_CHARACTER_STATE_SCALE_OUT;
            }
            break;
        case SELECT_CHARACTER_STATE_SCALE_OUT:
            selectCharacter->mStateFrames++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mStateFrames < SELECT_CHARACTER_SCALE_STEPS) {
                selectCharacterReload->mScale =
                    TO_FIXED12(SELECT_CHARACTER_SCALE_STEPS - selectCharacterReload->mStateFrames) /
                    SELECT_CHARACTER_SCALE_STEPS;
            } else {
                GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex =
                    selectCharacterReload->mCharacterIndex;
                GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartIndex = gSelectCharacter->mKartIndex;
                gSelectCharacter->mState = SELECT_CHARACTER_STATE_DONE;
            }
            gSelectCharacter->mAngle += 0x1000;
            SetSelectCharacterAngleAndScale();
            break;
        case SELECT_CHARACTER_STATE_DONE:
            result = selectCharacter->mResult;
            break;
    }

    AdvanceInterpolation(&gSelectCharacter->mInterpolations[0]);
    AdvanceInterpolation(&gSelectCharacter->mInterpolations[1]);
    AdvanceInterpolation(&gSelectCharacter->mInterpolations[2]);
    SetSelectCharacterNameOffsetX(GetInterpolatedValue(&gSelectCharacter->mInterpolations[0]));
    interpolatedValue = GetInterpolatedValue(&gSelectCharacter->mInterpolations[1]);
    SetSelectCharacterCellOffsetsY(interpolatedValue, GetInterpolatedValue(&gSelectCharacter->mInterpolations[2]));
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        selectCharacterReload = gSelectCharacter;
        if (selectCharacterReload->mResult != 2) {
            RequestKartModelMenuCharacter(selectCharacterReload->mCharacterIndex);
            RequestKartModelMenuKart(gSelectCharacter->mKartIndex);
        }
        AdvanceKartModelMenu(GetRaceSetupCopy()->mMirrorMode);
    }
    if (gSelectCharacter->mUsePlayerEntryList != FALSE) {
        AdvancePlayerEntryList();
    } else {
        DrawLayoutTable(selectCharacter->mGpMParts.mCellLayout, selectCharacter->mGpMParts.mCells, NULL,
                        gSelectCharacter->mMainOam, selectCharacter->mGpMParts.mCellTable);
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        DrawLayoutTableKeepMatrixCount(sParts->mCellLayout, sParts->mCells, NULL, gSelectCharacter->mSubOam,
                                       sParts->mCellTable);
        IncrementOamMatrixCount(gSelectCharacter->mSubOam);
    } else if (GetRaceSetupCopy()->mMode == 2) {
        AdvanceSelectRaceRuleWait();
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        DrawKartModelMenu();
    }
    switch (result) {
        case 1:
            if (GetRaceSetupCopy()->mMode == 2) {
                GetRaceSetupCopy()->mEntryTransition = 0;
            } else {
                GetRaceSetupCopy()->mEntryTransition = 1;
            }
            break;
        case 2:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                RequestKartModelMenuCharacter(-1);
                RequestKartModelMenuKart(-1);
            }
            GetRaceSetupCopy()->mEntryTransition = 0;
            break;
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseSelectCharacter(void) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        if (GetRaceSetupCopy()->mMode == 2) {
            ClearSelectRaceRuleWaitPointer();
        }
    }
    HeapDestroy(gSelectCharacter->mHeap);
    gSelectCharacter = NULL;
}

void WriteSelectCharacterRegisters(void) {
    u32 displayBits = 0x18;

    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    if (!(gSelectCharacter->mState == SELECT_CHARACTER_STATE_DONE && gSelectCharacter->mResult == 2)) {
        displayBits |= 1;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (displayBits << 8);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | 0x1600;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 1;
    if (gSelectCharacter->mUsePlayerEntryList != FALSE) {
        WritePlayerEntryListRegisters();
    }
}

void LoadSelectCharacterData(void) {
    Ncgr *chars = NULL;
    Nclr *palette = NULL;
    NNSG2dCellDataBank *cells = NULL;

    LoadNcgrData2(&chars, FindFileInLoadedArchives("select_character_gp_m.nce.ncgr"));
    LoadNcerData(&cells, FindFileInLoadedArchives("select_character_gp_m.nce.ncer"));
    LoadNclrData(&palette, FindFileInLoadedArchives("select_character_gp_m_o.NCLR"));
    LoadNcgrData2(&chars, FindFileInLoadedArchives("select_character_s.nce.ncgr"));
    LoadNcerData(&cells, FindFileInLoadedArchives("select_character_s.nce.ncer"));
    LoadNclrData(&palette, FindFileInLoadedArchives("select_character_s_o.NCLR"));
    LoadNcgrData2(&chars, FindFileInLoadedArchives("select_character_gp_name_m.nce.ncgr"));
    LoadNcerData(&cells, FindFileInLoadedArchives("select_character_gp_name_m.nce.ncer"));
    LoadNcgrData2(&chars, FindFileInLoadedArchives("select_character_gp_title_m.nce.ncgr"));
    LoadNcerData(&cells, FindFileInLoadedArchives("select_character_gp_title_m.nce.ncer"));
}

void SetupInterpolation(Interpolation *interpolation, s32 state, s32 counterLimit, s16 startValue, s32 endValue) {
    interpolation->mCounterLimit = counterLimit;
    interpolation->mStartValue = startValue;
    interpolation->mEndValue = endValue;
    SetInterpolationStateIfOpposite(interpolation, state);
}

#pragma thumb off

const SelectCharacterRowCellIndices gSelectCharacterRowCellIndices[12] = {
    {0xc, 0x1a, 0, 0},  {0xd, 0x1b, 1, 1},  {0xe, 0x1c, 2, 2},      {0xf, 0x1d, 3, 3},
    {0x10, 0x1e, 4, 4}, {0x11, 0x1f, 5, 5}, {0x12, 0x20, 6, 6},     {0x13, 0x21, 7, 7},
    {0x14, 0x22, 8, 8}, {0x15, 0x23, 9, 9}, {0x16, 0x24, 0xa, 0xa}, {0x17, 0x25, 0xb, 0xb}};
const SelectCharacterRow gSelectCharacterRows[12] = {{0, 0}, {7, 1}, {4, 2}, {6, 3}, {2, 4},     {1, 5},
                                                     {5, 6}, {3, 7}, {9, 8}, {8, 9}, {0xa, 0xa}, {0xb, 0xb}};
const SelectCharacterRowPosition gSelectCharacterPositions11Rows[11] = {
    {0x27, 0x1d}, {0x63, 0x1d}, {0x9f, 0x1d}, {0xdb, 0x1d}, {0x3b, 0x51}, {0x80, 0x51},
    {0xc7, 0x51}, {0x27, 0x85}, {0x63, 0x85}, {0x9f, 0x85}, {0xdb, 0x85}};
const SelectCharacterRowPosition gSelectCharacterPositions10Rows[10] = {
    {0x3a, 0x1d}, {0x80, 0x1d}, {0xc6, 0x1d}, {0x27, 0x51}, {0x63, 0x51},
    {0x9f, 0x51}, {0xdb, 0x51}, {0x3a, 0x85}, {0x80, 0x85}, {0xc6, 0x85}};
const SelectCharacterRowPosition gSelectCharacterPositions9Rows[9] = {{0x44, 0x1d}, {0x80, 0x1d}, {0xbc, 0x1d},
                                                                      {0x44, 0x51}, {0x80, 0x51}, {0xbc, 0x51},
                                                                      {0x44, 0x85}, {0x80, 0x85}, {0xbc, 0x85}};
const SelectCharacterRowPosition gSelectCharacterPositions8Rows[8] = {
    {0x30, 0x1d}, {0x80, 0x1d}, {0xd0, 0x1d}, {0x57, 0x51}, {0xa8, 0x51}, {0x30, 0x85}, {0x80, 0x85}, {0xd0, 0x85}};
