#include "Main/Menu/select_character.h"
#include "Main/Unknown/code_0202719c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Graphics/cell_layout_entry.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/System/interpolation.h"
#include "Main/Menu/player_entry_list.h"
#include "Main/Kart/karts.h"
#include "registers.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Unknown/code_0211f498.h"
#include "g2.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Sound/character_seq_pair.h"
#include "Main/System/interpolation_value.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Save/backup_reset.h"
#include "Main/Scene/display_settings.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Graphics/oam_matrix_count.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Menu/picks_holder.h"
#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/player_character_cell_file_set.h"
#include "Main/Race/race_setup.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Menu/select_return.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/System/interpolation_state.h"
#include "code_0214d018.h"
#include "Main/Kart/kart_table_index.h"

#pragma thumb on

void SetSelectCharacterKeyTargets8Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215377c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215377c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215377c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215377c[3];
            break;
        case 1:
            if (selectCharacter->mPreviousTableIndex == 4) {
                selectCharacter->mTableIndexByKey[0] = data_usa_02153784[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_02153784[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_02153784[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_02153784[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_0215378c[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_0215378c[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_0215378c[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_0215378c[3];
            }
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153794[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153794[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153794[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153794[3];
            break;
        case 3:
            if (selectCharacter->mPreviousTableIndex == 1 || selectCharacter->mPreviousTableIndex == 6) {
                selectCharacter->mTableIndexByKey[0] = data_usa_0215379c[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_0215379c[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_0215379c[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_0215379c[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537a4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537a4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537a4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537a4[3];
            }
            break;
        case 4:
            if (selectCharacter->mPreviousTableIndex == 2 || selectCharacter->mPreviousTableIndex == 7) {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537ac[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537ac[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537ac[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537ac[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537b4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537b4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537b4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537b4[3];
            }
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = data_usa_021537bc[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021537bc[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021537bc[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021537bc[3];
            break;
        case 6:
            if (selectCharacter->mPreviousTableIndex == 4) {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537c4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537c4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537c4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537c4[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021537cc[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021537cc[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021537cc[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021537cc[3];
            }
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_021537d4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021537d4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021537d4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021537d4[3];
            break;
    }
}

void SetSelectCharacterKeyTargets9Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153734[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153734[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153734[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153734[3];
            break;
        case 1:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215373c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215373c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215373c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215373c[3];
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153744[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153744[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153744[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153744[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215374c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215374c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215374c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215374c[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153754[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153754[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153754[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153754[3];
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215375c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215375c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215375c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215375c[3];
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153764[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153764[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153764[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153764[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215376c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215376c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215376c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215376c[3];
            break;
        case 8:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153774[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153774[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153774[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153774[3];
            break;
    }
}

void SetSelectCharacterKeyTargets10Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536d4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536d4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536d4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536d4[3];
            break;
        case 1:
            if (selectCharacter->mPreviousTableIndex == 5) {
                selectCharacter->mTableIndexByKey[0] = data_usa_021536dc[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021536dc[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021536dc[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021536dc[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021536e4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021536e4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021536e4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021536e4[3];
            }
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536ec[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536ec[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536ec[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536ec[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536f4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536f4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536f4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536f4[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536fc[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536fc[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536fc[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536fc[3];
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153704[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153704[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153704[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153704[3];
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215370c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215370c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215370c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215370c[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153714[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153714[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153714[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153714[3];
            break;
        case 8:
            if (selectCharacter->mPreviousTableIndex == 5) {
                selectCharacter->mTableIndexByKey[0] = data_usa_0215371c[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_0215371c[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_0215371c[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_0215371c[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_02153724[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_02153724[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_02153724[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_02153724[3];
            }
            break;
        case 9:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215372c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215372c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215372c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215372c[3];
            break;
    }
}

void SetSelectCharacterKeyTargets11Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153674[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153674[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153674[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153674[3];
            break;
        case 1:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215367c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215367c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215367c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215367c[3];
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153684[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153684[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153684[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153684[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215368c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215368c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215368c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215368c[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153694[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153694[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153694[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153694[3];
            break;
        case 5:
            if (selectCharacter->mPreviousTableIndex == 2 || selectCharacter->mPreviousTableIndex == 9) {
                selectCharacter->mTableIndexByKey[0] = data_usa_0215369c[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_0215369c[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_0215369c[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_0215369c[3];
            } else {
                selectCharacter->mTableIndexByKey[0] = data_usa_021536a4[0];
                selectCharacter->mTableIndexByKey[1] = data_usa_021536a4[1];
                selectCharacter->mTableIndexByKey[2] = data_usa_021536a4[2];
                selectCharacter->mTableIndexByKey[3] = data_usa_021536a4[3];
            }
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536ac[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536ac[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536ac[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536ac[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536b4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536b4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536b4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536b4[3];
            break;
        case 8:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536bc[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536bc[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536bc[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536bc[3];
            break;
        case 9:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536c4[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536c4[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536c4[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536c4[3];
            break;
        case 10:
            selectCharacter->mTableIndexByKey[0] = data_usa_021536cc[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_021536cc[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_021536cc[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_021536cc[3];
            break;
    }
}

void SetSelectCharacterKeyTargets12Rows(void) {
    SelectCharacter *selectCharacter;

    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mTableIndex) {
        case 0:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153614[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153614[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153614[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153614[3];
            break;
        case 1:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215361c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215361c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215361c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215361c[3];
            break;
        case 2:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153624[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153624[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153624[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153624[3];
            break;
        case 3:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215362c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215362c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215362c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215362c[3];
            break;
        case 4:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153634[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153634[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153634[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153634[3];
            break;
        case 5:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215363c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215363c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215363c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215363c[3];
            break;
        case 6:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153644[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153644[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153644[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153644[3];
            break;
        case 7:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215364c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215364c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215364c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215364c[3];
            break;
        case 8:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153654[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153654[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153654[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153654[3];
            break;
        case 9:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215365c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215365c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215365c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215365c[3];
            break;
        case 10:
            selectCharacter->mTableIndexByKey[0] = data_usa_02153664[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_02153664[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_02153664[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_02153664[3];
            break;
        case 11:
            selectCharacter->mTableIndexByKey[0] = data_usa_0215366c[0];
            selectCharacter->mTableIndexByKey[1] = data_usa_0215366c[1];
            selectCharacter->mTableIndexByKey[2] = data_usa_0215366c[2];
            selectCharacter->mTableIndexByKey[3] = data_usa_0215366c[3];
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
    gSelectCharacter->mState = 8;
    RequestSelectReturnState3WithSound(0);
    StartPlayerEntryListKindIfUsed(3);
    SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[0], 2);
    SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1], 2);
    SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[2], 2);
    StartKartModelMenuBg0Decrease();
}

void SetSelectCharacterRowCellsVisible(s32 visible) {
    SelectCharacter *selectCharacter;
    s32 rowIndex;
    CellFileSet *sParts;

    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mSParts;
    if (gBootInfo->mBootType != 2) {
        for (rowIndex = 0; rowIndex < gSelectCharacter->mTableRowCount; rowIndex++) {
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_04].mVisible = visible;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mVisible =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_04].mVisible;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_00].mVisible =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mVisible;
        }
        sParts->mCellTable[25].mVisible = visible;
    }
}

void SetSelectCharacterBracketsResting(void) {
    s32 rowIndex;
    CellFileSet *sParts;
    SelectCharacterRowCellIndices *tableRow;

    if (gBootInfo->mBootType != 2) {
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

    if (gBootInfo->mBootType != 2) {
        selectCharacter = gSelectCharacter;
        if (selectCharacter->mUsePlayerEntryList == FALSE) {
            selectCharacter->mGpMParts.mCellTable[0].mOffsetY = firstOffsetY;
            selectCharacter->mGpMParts.mCellTable[3].mOffsetY = secondOffsetY;
        }
    }
}

void SetSelectCharacterNameOffsetX(s16 offsetX) {
    SelectCharacter *selectCharacter;

    if (gBootInfo->mBootType != 2) {
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

    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mSParts;
    tableIndex = selectCharacter->mTableIndex;
    CopyCellLayoutEntryPosition(0x18, gSelectCharacterRowCellIndices[tableIndex].mUnk_00, sParts->mCellLayout);
    CopyCellLayoutEntryPosition(0x19, gSelectCharacterRowCellIndices[tableIndex].mUnk_00, sParts->mCellLayout);
}

void SetSelectCharacterBracketsMoving(void) {
    SelectCharacter *selectCharacter;
    CellFileSet *sParts;
    SelectCharacterRowCellIndices *tableRow;

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
    SetInterpolationState(&gSelectCharacter->mInterpolations[0], 0);
    gSelectCharacter->mCharacterIndex = gSelectCharacter->mRows[gSelectCharacter->mTableIndex].mCharacterIndex;
    gSelectCharacter->mKartIndex = GetCharacterKartIndexByMode(gSelectCharacter->mCharacterIndex);
}

#pragma thumb off

#pragma thumb on

u32 IsSelectCharacterModeAndTimerZero(void) {
    int result;
    if ((gSelectCharacter->mMode != 0) && (result = IsPlayerEntryListTimerZero(), result != 0)) {
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
    if (gBootInfo->mBootType != 2) {
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
    SelectCharacterRowPosition *positions;
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
            if (gBootInfo->mBootType != 2) {
                StartKartModelMenuBg0Increase();
            }
            break;
        case 2:
            SetupInterpolation(&gSelectCharacter->mInterpolations[0], 1, 10, -0x80, 0);
            SetupInterpolation(&gSelectCharacter->mInterpolations[2], 1, 10, 0x60, 0);
            switch (gSelectCharacter->mMode) {
                case 1:
                    if (gConnectionWork->mState == 8) {
                        gConnectionWork->mDataSharingSendByte = 0xff;
                    }
                    break;
                case 2:
                    SetWiFiSessionOwnCharacterIndexNone();
                    break;
            }
            break;
    }
    SetupInterpolation(&gSelectCharacter->mInterpolations[1], 0, 10, -0x40, 0);
    gSelectCharacter->mMainOam = mainOam;
    gSelectCharacter->mSubOam = subOam;
    if (gSelectCharacter->mMode != 0 || GetRaceSetupCopy()->mMode == 3 || GetRaceSetupCopy()->mMode == 2) {
        usePlayerEntryList = TRUE;
    } else {
        usePlayerEntryList = FALSE;
    }
    gSelectCharacter->mUsePlayerEntryList = usePlayerEntryList;
    if (gSelectCharacter->mUsePlayerEntryList != FALSE) {
        switch (gSelectCharacter->mMode) {
            case 0:
                modeValue = 0;
                break;
            case 1:
                modeValue = 1;
                break;
            case 2:
                modeValue = 2;
                break;
        }
        SetupPlayerEntryList(modeValue, PLAYER_ENTRY_LIST_CHARACTER);
    }
    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mMode) {
        case 0:
            selectCharacter->mEntryIndex = 0;
            break;
        case 1:
            selectCharacter->mEntryIndex =
                GetParticipantPosByIndex(gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0)
                    ->mEntryIndex;
            break;
        case 2:
            gSelectCharacter->mEntryIndex = GetRaceSetupCopyEntryIndex();
            break;
    }
    selectCharacter = gSelectCharacter;
    if (selectCharacter->mUsePlayerEntryList == FALSE) {
        LocateCellFileSet(&selectCharacter->mGpMParts, gSelectCharacterGpMNcgrName, gSelectCharacterGpMNcerName,
                          gSelectCharacterGpMONclrName, gSelectCharacterGpMBnclName, NULL, NULL,
                          FindFileInLoadedArchives);
        SetupCellFileSet(0, gSelectCharacter->mHeap, &selectCharacter->mGpMParts);
        LocateCellFileSet(&titleParts, gSelectCharacterGpTitleMNcgrName, gSelectCharacterGpTitleMNcerName, NULL,
                          gSelectCharacterGpTitleMBnclName, NULL, NULL, FindFileInLoadedArchives);
        QueueCellChars(0, titleParts.mCells, titleParts.mChars, titleParts.mCellLayout, 0, 0,
                       selectCharacter->mGpMParts.mCells, selectCharacter->mGpMParts.mCellLayout);
        LocateCellFileSet(&gSelectCharacter->mGpNameMParts, gSelectCharacterGpNameMNcgrName,
                          gSelectCharacterGpNameMNcerName, NULL, gSelectCharacterGpNameMBnclName, NULL, NULL,
                          FindFileInLoadedArchives);
        selectCharacter->mGpMParts.mCellTable[9].mVisible = 0;
        selectCharacter->mGpMParts.mCellTable[8].mVisible = selectCharacter->mGpMParts.mCellTable[9].mVisible;
        selectCharacter->mGpMParts.mCellTable[7].mVisible = selectCharacter->mGpMParts.mCellTable[8].mVisible;
        selectCharacter->mGpMParts.mCellTable[6].mVisible = selectCharacter->mGpMParts.mCellTable[7].mVisible;
        selectCharacter->mGpMParts.mCellTable[5].mVisible = selectCharacter->mGpMParts.mCellTable[6].mVisible;
        selectCharacter->mGpMParts.mCellTable[4].mVisible = selectCharacter->mGpMParts.mCellTable[5].mVisible;
    }
    if (gBootInfo->mBootType != 2) {
        sParts = &gSelectCharacter->mSParts;
        LocateCellFileSet(sParts, gSelectCharacterSNcgrName, gSelectCharacterSNcerName, gSelectCharacterSONclrName,
                          gSelectCharacterSBnclName, NULL, gSelectCharacterSBnblName, FindFileInLoadedArchives);
        SetupCellFileSet(1, gSelectCharacter->mHeap, sParts);
        sParts->mCellTable[24].mVisible = 0;
        for (rowIndex = 0; rowIndex < 12; rowIndex++) {
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_04].mUseMatrix = 1;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mUseMatrix =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_04].mUseMatrix;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_00].mUseMatrix =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mUseMatrix;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_04].mDoubleAffine = 0;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mDoubleAffine =
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_04].mDoubleAffine;
            sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_00].mDoubleAffine =
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
        gSelectCharacter->mRows[rowIndex] = data_021535b4[rowIndex];
    }
    if (IsBackupFlagSet(0x15) != 0) {
        gSelectCharacter->mRows[rowIndex] = data_021535b4[8];
        rowIndex++;
        gSelectCharacter->mTableRowCount++;
    }
    if (IsBackupFlagSet(0x14) != 0) {
        gSelectCharacter->mRows[rowIndex] = data_021535b4[9];
        rowIndex++;
        gSelectCharacter->mTableRowCount++;
    }
    if (IsBackupFlagSet(0x16) != 0) {
        gSelectCharacter->mRows[rowIndex] = data_021535b4[10];
        rowIndex++;
        gSelectCharacter->mTableRowCount++;
    }
    if (IsBackupFlagSet(0x17) != 0) {
        gSelectCharacter->mRows[rowIndex] = data_021535b4[11];
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
        gSelectCharacter->mCharacterIndex = 0;
    }
    gSelectCharacter->mKartIndex = GetCharacterKartIndexByMode(gSelectCharacter->mCharacterIndex);
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartStored = 0;
    if (gBootInfo->mBootType != 2) {
        sParts = &gSelectCharacter->mSParts;
        SetPlayerCharacterCellFileSet(0, &cellFileSet);
        for (rowIndex = 0; rowIndex < gSelectCharacter->mTableRowCount; rowIndex++) {
            QueueCellCharsAndCopyPalettes(gSelectCharacter->mRows[rowIndex].mCharacterIndex, cellFileSet.mCells,
                                          cellFileSet.mChars, cellFileSet.mPalette, cellFileSet.mCellLayout, 1,
                                          gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex, sParts->mCells,
                                          sParts->mCellLayout);
        }
    }
    if (gBootInfo->mBootType != 2) {
        positions = NULL;
        sParts = &gSelectCharacter->mSParts;
        switch (gSelectCharacter->mTableRowCount) {
            case 8:
                positions = data_021534bc;
                SetSelectCharacterKeyTargets8Rows();
                break;
            case 9:
                positions = data_021534dc;
                SetSelectCharacterKeyTargets9Rows();
                break;
            case 10:
                positions = data_02153500;
                SetSelectCharacterKeyTargets10Rows();
                break;
            case 11:
                positions = data_02153528;
                SetSelectCharacterKeyTargets11Rows();
                break;
            case 12:
                SetSelectCharacterKeyTargets12Rows();
                break;
        }
        if (positions != NULL) {
            for (rowIndex = 0; rowIndex < gSelectCharacter->mTableRowCount; rowIndex++) {
                SetCellLayoutEntryXY(gSelectCharacterRowCellIndices[rowIndex].mUnk_00, positions[rowIndex].mEntryX,
                                     positions[rowIndex].mEntryY, sParts->mCellLayout);
                SetCellLayoutEntryXY(gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex,
                                     positions[rowIndex].mEntryX, positions[rowIndex].mEntryY, sParts->mCellLayout);
                RectTableSetEntryXY(gSelectCharacterRowCellIndices[rowIndex].mRectEntryId, positions[rowIndex].mEntryX,
                                    positions[rowIndex].mEntryY, sParts->mRects);
                SetCellLayoutEntryXY(gSelectCharacterRowCellIndices[rowIndex].mUnk_04,
                                     (s16) (positions[rowIndex].mEntryX + 3), (s16) (positions[rowIndex].mEntryY + 3),
                                     sParts->mCellLayout);
            }
            for (; rowIndex < 12; rowIndex++) {
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_00].mVisible = 0;
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mCharacterCellIndex].mVisible = 0;
                sParts->mCellTable[gSelectCharacterRowCellIndices[rowIndex].mUnk_04].mVisible = 0;
                RectTableSetEntryXY(gSelectCharacterRowCellIndices[rowIndex].mRectEntryId, 0x400, 0x400,
                                    sParts->mRects);
            }
        }
        MoveSelectCharacterBracketsToRow();
        QueueSelectCharacterNameChars();
    }
    if (gSelectCharacter->mMode == 0) {
        ClearNonParticipantCharacterIndices();
        SetSelectReturnSoundId(0xe);
        RequestSelectReturnState1();
    }
    if (AreBrightnessFadesClear() != 0) {
        gSelectCharacter->mState = 1;
    } else {
        StartFadeToClear(10);
        SetSelectCharacterRowCellsVisible(0);
    }
    if (gBootInfo->mBootType != 2) {
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
        case 0:
            if (AreBrightnessFadesClear() != 0) {
                gSelectCharacter->mState = 1;
            }
            break;
        case 1:
            if (selectCharacter->mStateFrames == 0) {
                SetSelectCharacterRowCellsVisible(1);
            }
            gSelectCharacter->mStateFrames++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mStateFrames < 10) {
                selectCharacterReload->mScale = TO_FIXED12(selectCharacterReload->mStateFrames) / 10;
            } else {
                selectCharacterReload->mScale = 0x1000;
                gSelectCharacter->mStateFrames = 0;
                if (gBootInfo->mBootType == 2) {
                    nextState = 2;
                } else {
                    nextState = 3;
                }
                gSelectCharacter->mState = nextState;
            }
            SetSelectCharacterAngleAndScale();
            break;
        case 2:
            selectCharacter->mCharacterIndex = 0xc;
            gSelectCharacter->mKartIndex = 0x24;
            gSelectCharacter->mStateFrames = 0;
            gSelectCharacter->mResult = 1;
            if (GetRaceSetupCopy()->mMode == 3) {
                flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0x40;
                if (gConnectionWork->mState == 8) {
                    gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                }
                StartPlayerEntryListKindIfUsed(1);
                gSelectCharacter->mState = 8;
            } else if (GetRaceSetupCopy()->mMode == 2) {
                flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0xc0;
                if (gConnectionWork->mState == 8) {
                    gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                }
                gSelectCharacter->mState = 6;
            }
            break;
        case 3:
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
                    gSelectCharacter->mState = 5;
                } else if (gSelectCharacter->mMode == 0 &&
                           IsSelectReturnState2NoState3Or4RequestAndInRect(pointX, pointY) != FALSE) {
                    StartSelectCharacterReturn();
                }
            } else if (IsSelectCharacterModeAndTimerZero() != 0) {
                gSelectCharacter->mStateFrames = 0;
                gSelectCharacter->mResult = 3;
                gSelectCharacter->mState = 6;
                StartSeqPair(GetCharacterSeqPairNo(gSelectCharacter->mCharacterIndex), 0);
                SetKartModelMenuSpinStopped(1);
                selectCharacterReload = gSelectCharacter;
                switch (selectCharacterReload->mMode) {
                    case 2:
                        SetWiFiSessionOwnCharacterIndex(selectCharacterReload->mCharacterIndex);
                        SetWiFiSessionOwnKartIndex(gSelectCharacter->mKartIndex);
                        break;
                    case 1:
                        flaggedCharacterIndex = selectCharacterReload->mCharacterIndex | 0xc0;
                        if (gConnectionWork->mState == 8) {
                            gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                        }
                        break;
                }
            } else {
                keyBits = gInputSlots[inputSlot].mPressedBits;
                if ((u16) (keyBits & PAD_KEY_A) != 0) {
                    gSelectCharacter->mStateFrames = 0;
                    gSelectCharacter->mState = 5;
                    RefreshSelectCharacterRowCells();
                    StartSeqPair(GetCharacterSeqPairNo(gSelectCharacter->mCharacterIndex), 0);
                } else if (gSelectCharacter->mMode == 0 && (u16) (keyBits & PAD_KEY_B) != 0) {
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
                        gSelectCharacter->mState = 4;
                    }
                }
            }
            break;
        case 4:
            selectCharacter->mStateFrames++;
            if (gSelectCharacter->mStateFrames > 5) {
                SetSelectCharacterBracketsResting();
                gSelectCharacter->mStateFrames = 0;
                gSelectCharacter->mState = 3;
            }
            break;
        case 5:
            selectCharacter->mStateFrames++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mStateFrames > 5) {
                selectCharacterReload->mStateFrames = 0;
                gSelectCharacter->mResult = 1;
                SetSelectCharacterBracketsResting();
                selectCharacterReload = gSelectCharacter;
                switch (selectCharacterReload->mMode) {
                    case 0:
                        GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex =
                            selectCharacterReload->mCharacterIndex;
                        GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartIndex =
                            gSelectCharacter->mKartIndex;
                        FillRandomCharacterIndices();
                        if (GetRaceSetupCopy()->mMode == 2) {
                            GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartStored = 1;
                            SetKartModelMenuSpinStopped(1);
                            gSelectCharacter->mState = 7;
                            ClearNonParticipantKartIndices();
                            SetKartIndicesFromCharacters();
                        } else {
                            StartPlayerEntryListKindIfUsed(1);
                            StartKartModelMenuTimedSpinStop();
                            gSelectCharacter->mState = 8;
                            SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1], 2);
                        }
                        break;
                    case 1:
                        if (GetRaceSetupCopy()->mMode == 3) {
                            flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0x40;
                            if (gConnectionWork->mState == 8) {
                                gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                            }
                            SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1], 2);
                            StartPlayerEntryListKindIfUsed(1);
                            gSelectCharacter->mState = 8;
                            StartKartModelMenuTimedSpinStop();
                        } else if (GetRaceSetupCopy()->mMode == 2) {
                            flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0xc0;
                            if (gConnectionWork->mState == 8) {
                                gConnectionWork->mDataSharingSendByte = flaggedCharacterIndex;
                            }
                            SetKartModelMenuSpinStopped(1);
                            gSelectCharacter->mState = 6;
                        }
                        break;
                    case 2:
                        SetWiFiSessionOwnCharacterIndex(selectCharacterReload->mCharacterIndex);
                        SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1], 2);
                        StartPlayerEntryListKindIfUsed(1);
                        gSelectCharacter->mState = 8;
                        StartKartModelMenuTimedSpinStop();
                        break;
                }
            }
            break;
        case 6:
            if ((selectCharacter->mMode == 1 && IsEveryPlayerKartStored() != 0) ||
                (gSelectCharacter->mMode == 2 && IsWiFiSessionStep7Reached() != 0)) {
                if (gSelectCharacter->mMode == 2) {
                    WriteWiFiSessionToRaceSetupCopy();
                }
                if (GetRaceSetupCopy()->mMode == 2 || IsSelectCharacterModeAndTimerZero() != 0) {
                    gSelectCharacter->mState = 7;
                } else {
                    StartPlayerEntryListKindIfUsed(1);
                    SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1], 2);
                    gSelectCharacter->mState = 8;
                }
            }
            break;
        case 7:
            selectCharacter->mStateFrames++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mStateFrames > 60) {
                if (selectCharacterReload->mMode == 2) {
                    StartPlayerEntryListKindIfUsed(3);
                } else {
                    StartPlayerEntryListKindIfUsed(2);
                }
                SetInterpolationStateIfOpposite(&gSelectCharacter->mInterpolations[1], 2);
                if (gBootInfo->mBootType != 2) {
                    StartKartModelMenuBg0Decrease();
                } else if (GetRaceSetupCopy()->mMode == 2) {
                    SlideOutSelectRaceRuleWait();
                }
                gSelectCharacter->mStateFrames = 0;
                gSelectCharacter->mState = 8;
            }
            break;
        case 8:
            selectCharacter->mStateFrames++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mStateFrames < 10) {
                selectCharacterReload->mScale = TO_FIXED12(10 - selectCharacterReload->mStateFrames) / 10;
            } else {
                GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex =
                    selectCharacterReload->mCharacterIndex;
                GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartIndex = gSelectCharacter->mKartIndex;
                gSelectCharacter->mState = 9;
            }
            gSelectCharacter->mAngle += 0x1000;
            SetSelectCharacterAngleAndScale();
            break;
        case 9:
            result = selectCharacter->mResult;
            break;
    }

    AdvanceInterpolation(&gSelectCharacter->mInterpolations[0]);
    AdvanceInterpolation(&gSelectCharacter->mInterpolations[1]);
    AdvanceInterpolation(&gSelectCharacter->mInterpolations[2]);
    SetSelectCharacterNameOffsetX(GetInterpolatedValue(&gSelectCharacter->mInterpolations[0]));
    interpolatedValue = GetInterpolatedValue(&gSelectCharacter->mInterpolations[1]);
    SetSelectCharacterCellOffsetsY(interpolatedValue, GetInterpolatedValue(&gSelectCharacter->mInterpolations[2]));
    if (gBootInfo->mBootType != 2) {
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
    if (gBootInfo->mBootType != 2) {
        DrawLayoutTableKeepMatrixCount(sParts->mCellLayout, sParts->mCells, NULL, gSelectCharacter->mSubOam,
                                       sParts->mCellTable);
        IncrementOamMatrixCount(gSelectCharacter->mSubOam);
    } else if (GetRaceSetupCopy()->mMode == 2) {
        AdvanceSelectRaceRuleWait();
    }
    if (gBootInfo->mBootType != 2) {
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
            if (gBootInfo->mBootType != 2) {
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
    if (gBootInfo->mBootType == 2) {
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
    if (!(gSelectCharacter->mState == 9 && gSelectCharacter->mResult == 2)) {
        displayBits |= 1;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    if (gSelectCharacter->mUsePlayerEntryList != FALSE) {
        WritePlayerEntryListRegisters();
    }
}

void LoadSelectCharacterData(void) {
    Ncgr *chars = NULL;
    Nclr *palette = NULL;
    Unk02021dc8 *cells = NULL;

    LoadNcgrData2(&chars, FindFileInLoadedArchives(data_usa_02161b3c));
    LoadNcerData(&cells, FindFileInLoadedArchives(data_usa_02161b5c));
    LoadNclrData(&palette, FindFileInLoadedArchives(data_usa_02161b7c));
    LoadNcgrData2(&chars, FindFileInLoadedArchives(data_usa_02161b9c));
    LoadNcerData(&cells, FindFileInLoadedArchives(data_usa_02161bb8));
    LoadNclrData(&palette, FindFileInLoadedArchives(data_usa_02161bd4));
    LoadNcgrData2(&chars, FindFileInLoadedArchives(data_usa_02161bf0));
    LoadNcerData(&cells, FindFileInLoadedArchives(data_usa_02161c14));
    LoadNcgrData2(&chars, FindFileInLoadedArchives(data_usa_02161c38));
    LoadNcerData(&cells, FindFileInLoadedArchives(data_usa_02161c60));
}

void SetupInterpolation(Interpolation *interpolation, s32 state, s32 counterLimit, s16 startValue, s32 endValue) {
    interpolation->mCounterLimit = counterLimit;
    interpolation->mStartValue = startValue;
    interpolation->mEndValue = endValue;
    SetInterpolationStateIfOpposite(interpolation, state);
}

#pragma thumb off
