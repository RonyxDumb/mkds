#include "Main/Menu/select_kart_entry_list.h"
#include "Main/Graphics/message_index.h"
#include "Main/Graphics/cell_layout_entry.h"
#include "Main/Menu/select_kart_data.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "g2d_CellTransferManager.h"
#include "Main/Menu/wifi_vs_course_select_files.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/Menu/player_entry_list.h"

#pragma optimize_for_size on

#pragma thumb on

void StartSelectKartEntryListKindIfUsed(s32 kind) {
    if (gSelectKart->mEntryListUsed != FALSE) {
        StartPlayerEntryListKind(kind);
    }
}

void SetSelectKartPositionDigits(void) {
    s32 kartPosition;
    s32 kartCount;
    SelectKart *selectKart;
    CellFileSet *gpMParts;
    if (SelectKartMB_IsMultiBootChildWrapper() == 0) {
        selectKart = gSelectKart;
        kartPosition = GetKartPositionWithinAppearLimit(selectKart->mKartAppear, selectKart->mCharacterIndex,
                                                        selectKart->mKartIndex);
        kartCount = CountKartsWithinAppearLimit(gSelectKart->mKartAppear, gSelectKart->mCharacterIndex);
        selectKart = gSelectKart;
        if (selectKart->mEntryListUsed != FALSE) {
            WriteKartPositionAndCount(kartPosition, kartCount);
        } else {
            gpMParts = &selectKart->mSelectCharacterGpMParts;
            gpMParts->mCellTable[5].mVisible = (kartPosition >= 10);
            CopyCellLayoutEntryCellIndex(5, kartPosition / 10 % 10 + 10, gpMParts->mCellLayout);
            CopyCellLayoutEntryCellIndex(6, kartPosition % 10 + 10, gpMParts->mCellLayout);
            if (kartCount >= 10) {
                CopyCellLayoutEntryCellIndex(8, kartCount / 10 % 10 + 20, gpMParts->mCellLayout);
                CopyCellLayoutEntryCellIndex(9, kartCount % 10 + 20, gpMParts->mCellLayout);
            } else {
                gpMParts->mCellTable[9].mVisible = 0;
                CopyCellLayoutEntryCellIndex(8, kartCount % 10 + 20, gpMParts->mCellLayout);
            }
        }
    }
}

void MoveSelectKartNext(void) {
    SelectKart *selectKart;
    s32 index;
    index = gSelectKart->mKartTableIndex + 1;
    if (index >= 0x24) {
        index = 0;
    }
    while (selectKart = gSelectKart, index != selectKart->mKartTableIndex) {
        if (IsKartAppearWithinLimit(selectKart->mKartAppear, selectKart->mCharacterIndex,
                                    GetKartIndexAtTableIndex(index)) != 0) {
            gSelectKart->mKartTableIndex = index;
            gSelectKart->mKartIndex = GetKartIndexAtTableIndex(gSelectKart->mKartTableIndex);
        } else {
            index++;
            if (index >= 0x24) {
                index = 0;
            }
        }
    }
    SetSelectKartPositionDigits();
}

void MoveSelectKartPrev(void) {
    SelectKart *selectKart;
    s32 index;
    index = gSelectKart->mKartTableIndex - 1;
    if (index < 0) {
        index = 0x23;
    }
    while (selectKart = gSelectKart, index != selectKart->mKartTableIndex) {
        if (IsKartAppearWithinLimit(selectKart->mKartAppear, selectKart->mCharacterIndex,
                                    GetKartIndexAtTableIndex(index)) != 0) {
            gSelectKart->mKartTableIndex = index;
            gSelectKart->mKartIndex = GetKartIndexAtTableIndex(gSelectKart->mKartTableIndex);
        } else {
            index--;
            if (index < 0) {
                index = 0x23;
            }
        }
    }
    SetSelectKartPositionDigits();
}

#pragma thumb off

u32 SelectKartHasPairOrLost(InputSlotPair *pair) {
    u32 result;

    if (SelectKartIsPairRecentlyLost(pair) != 0 || SelectKartGetPairHasPair(pair) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

u32 SelectKartSlotHasPairOrLost(u32 slot) {
    return SelectKartHasPairOrLost(&gInputSlots[slot].mPair);
}
