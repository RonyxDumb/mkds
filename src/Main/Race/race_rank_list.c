#include "Main/Race/race_rank_list.h"

#include "Main/System/heap.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/System/heap_call.h"
#include "Main/Race/kart_highest_lap.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "g2d_Animation.h"
#include "Main/Race/race_m_ncer_entry.h"
#include "code_020222ec.h"
#include "player.h"
#include "code_0212df7c.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Race/race_hud_accessors.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/Race/race_ncer_tables.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "Main/Race/race_time_digits.h"

// Diagonal of the rank list matrix (fixed point 12 bits, about 0.77).
#define RACE_RANK_LIST_MATRIX_SCALE 0xc4e

RaceLapNumber *gRaceLapNumber;
RaceRankList *gRaceRankList;

void StopRaceRankListItemInUse(int kartIndex) {
    gRaceRankList->mItemsInUse[kartIndex].mInUseFrames = 0;
}

// Starts the 0x24-frame display of the item kart kartIndex has just put in use; its cell blinks.
void StartRaceRankListItemInUse(s32 kartIndex, s32 itemId, s32 objectCount) {
    gRaceRankList->mItemsInUse[kartIndex].mInUseFrames = 1;
    gRaceRankList->mItemsInUse[kartIndex].mItemInfoIndex = itemId;
    gRaceRankList->mItemsInUse[kartIndex].mObjectCount = objectCount;
}

void InitRaceRankList(void) {
    u8 kartIndex;

    gRaceRankList = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceRankList));
    for (kartIndex = 0; kartIndex < (s32) gRaceSetup->mKartCount; kartIndex++) {
        gRaceRankList->mRanks[kartIndex] = 1;
        gRaceRankList->mPrevRanks[kartIndex] = gRaceRankList->mRanks[kartIndex];
        gRaceRankList->mKartsByRank[kartIndex] = 0;
        gRaceRankList->mBalloonOrShineCounts[kartIndex] = 0;
    }
    gRaceRankList->mSlideX = 0;
    gRaceRankList->mOamMatrixIndex = 0;
    gRaceRankList->mMatrix.mElements[0] = RACE_RANK_LIST_MATRIX_SCALE;
    gRaceRankList->mMatrix.mElements[1] = 0;
    gRaceRankList->mMatrix.mElements[2] = 0;
    gRaceRankList->mMatrix.mElements[3] = RACE_RANK_LIST_MATRIX_SCALE;
    gRaceRankList->mMoveFrames = 0;
}

void ClearRaceRankListPointer(void) {
    gRaceRankList = NULL;
}

// Every 0x1c calls it re-reads each kart's rank and slides its row from the old rank slot to the new one.
void UpdateRaceRankList(void) {
    RaceRankListPos slotPositions[9] = {{0x1b, 0xf},  {0x1b, 0xf},  {0x1b, 0x26}, {0x1b, 0x3d}, {0x1b, 0x54},
                                        {0x1b, 0x6b}, {0x1b, 0x82}, {0x1b, 0x99}, {0x1b, 0xb0}};
    RaceRankListPos fromPosition;
    RaceRankListPos toPosition;
    RaceRankListPos position;
    s32 rankKeys[8];
    s32 moveFrames;
    s32 middleFrames;
    u8 kartIndex;
    KartItems *kartItems;

    moveFrames = gRaceRankList->mMoveFrames;
    if (GetRaceStartSequenceFrames() <= 0x188) {
        gRaceRankList->mSlideX = (0x20 - (GetRaceStartSequenceFrames() - 0x168)) * 4;
    } else {
        gRaceRankList->mSlideX = 0;
    }
    if (GetRaceStartSequenceFrames() < 0x168) {
        return;
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        for (kartIndex = 0; kartIndex < (s32) gRaceSetup->mKartCount; kartIndex++) {
            gRaceRankList->mBalloonOrShineCounts[kartIndex] = GetBalloonOrShineCount(kartIndex);
        }
    }
    for (kartIndex = 0; kartIndex < (s32) gRaceSetup->mKartCount; kartIndex++) {
        kartItems = &gKartItems[kartIndex];
        gRaceRankList->mShownItems[kartIndex] = kartItems->mHeldItem.mItemInfoIndex == ITEM_INFO_NONE
                                                    ? kartItems->mActiveItem
                                                    : kartItems->mHeldItem.mItemInfoIndex;
        if (gRaceRankList->mMoveFrames % 0x1c == 0) {
            gRaceRankList->mPrevRanks[kartIndex] = gRaceRankList->mRanks[kartIndex];
            gRaceRankList->mRanks[kartIndex] = GetKartRank(kartIndex);
        }
        fromPosition = slotPositions[gRaceRankList->mPrevRanks[kartIndex]];
        toPosition = slotPositions[gRaceRankList->mRanks[kartIndex]];
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            if (moveFrames < 10) {
                position.mX = fromPosition.mX + (moveFrames * 16) / 10;
                position.mY = fromPosition.mY;
            } else if (moveFrames < 0x12) {
                middleFrames = moveFrames - 10;
                position.mX = fromPosition.mX + (toPosition.mX - fromPosition.mX) * middleFrames / 8 + 0x10;
                position.mY = fromPosition.mY + (toPosition.mY - fromPosition.mY) * middleFrames / 8;
            } else {
                position.mX = fromPosition.mX + 0x10 - ((moveFrames - 0x12) * 16) / 10;
                position.mY = toPosition.mY;
            }
        } else {
            position.mX = fromPosition.mX + moveFrames * (toPosition.mX - fromPosition.mX) / 0x1c;
            position.mY = fromPosition.mY + moveFrames * (toPosition.mY - fromPosition.mY) / 0x1c;
        }
        gRaceRankList->mRowPositions[kartIndex] = position;
    }
    for (kartIndex = 0; kartIndex < (s32) gRaceSetup->mKartCount; kartIndex++) {
        gRaceRankList->mKartsByRank[kartIndex] = kartIndex;
        rankKeys[kartIndex] = gRaceRankList->mRanks[kartIndex];
    }
    SortIndicesByKey(gRaceRankList->mKartsByRank, rankKeys, gRaceSetup->mKartCount);
    gRaceRankList->mMoveFrames++;
    if (gRaceRankList->mMoveFrames >= RACE_RANK_LIST_MOVE_FRAMES) {
        gRaceRankList->mMoveFrames = 0;
    }
    for (kartIndex = 0; kartIndex < (s32) gRaceSetup->mKartCount; kartIndex++) {
        if (gRaceRankList->mItemsInUse[kartIndex].mInUseFrames != 0) {
            gRaceRankList->mItemsInUse[kartIndex].mInUseFrames++;
            if (gRaceRankList->mItemsInUse[kartIndex].mInUseFrames > RACE_RANK_LIST_ITEM_IN_USE_FRAMES) {
                gRaceRankList->mItemsInUse[kartIndex].mInUseFrames = 0;
            }
        }
    }
}

void DrawRaceRankList(RaceHudOamBuffer *oamBuffer) {
    MtxFx22 *matrix;
    GXOamAttr *oams;

    if (GetRaceStartSequenceFrames() < 0x168) {
        return;
    }
    gRaceRankList->mOamMatrixIndex = AllocOamMatrixIndex(oamBuffer);
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_VS:
        case MODE_WIFI:
            DrawRaceRankListNonBattleRows(oamBuffer);
            break;
        case MODE_BATTLE:
            switch (GetRaceHudSubScreenState()) {
                case RACE_HUD_SUB_SCREEN_KART_ICONS:
                    DrawRaceRankListBattleKartIconsRows(oamBuffer);
                    break;
                case RACE_HUD_SUB_SCREEN_MAP_TURNING:
                case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
                case RACE_HUD_SUB_SCREEN_MAP_VIEW:
                    DrawRaceRankListBattleMapRows(oamBuffer);
                    break;
            }
            break;
    }
    matrix = &gRaceRankList->mMatrix;
    oams = &oamBuffer->mOams[gRaceRankList->mOamMatrixIndex * 4];
    oams[0].mAttrs[3] = matrix->mElements[0] >> 4;
    oams[1].mAttrs[3] = matrix->mElements[1] >> 4;
    oams[2].mAttrs[3] = matrix->mElements[2] >> 4;
    oams[3].mAttrs[3] = matrix->mElements[3] >> 4;
}

// Returns the cell index beside the kart (0xc9 = none): cell 0x24 or 0x25, the item just used, the held item or 0x16.
u32 GetRaceRankListSNcerIndex(u16 kartIndex) {
    u32 cellIndex;
    RaceRankList *rankList;
    RaceRankListItemInUse *itemIndexView;
    s32 framesSinceStart;

    if (GetRaceHudKartRemoved(kartIndex) != 0) {
        cellIndex = 0x25;
    } else if (gRaceSetup->mMode == MODE_BATTLE && IsKartOnWinningTeamAtEnd(kartIndex) != 0) {
        cellIndex = 0x24;
    } else if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated(kartIndex) != FALSE) {
        cellIndex = 0xc9;
    } else if (gRaceSetup->mMode != MODE_BATTLE && IsKartEnded(kartIndex) != 0) {
        cellIndex = 0x24;
    } else if ((rankList = gRaceRankList)->mItemsInUse[kartIndex].mInUseFrames != 0) {
// itemIndexView starts at mItemsInUse[0].mItemInfoIndex, so its [k].mInUseFrames is kart k's item index.
        framesSinceStart = rankList->mItemsInUse[kartIndex].mInUseFrames - 1;
        if (framesSinceStart % 12 < 6) {
            cellIndex = 0xc9;
        } else if ((itemIndexView = (RaceRankListItemInUse *) &rankList->mItemsInUse[0].mItemInfoIndex)[kartIndex]
                       .mInUseFrames == RACE_RANK_LIST_ITEM_COUNT_FRAME) {
            switch (rankList->mItemsInUse[kartIndex].mObjectCount) {
                case 1:
                    cellIndex = 0x11;
                    break;
                case 2:
                    cellIndex = 0x12;
                    break;
                case 3:
                    cellIndex = 0x13;
                    break;
            }
        } else {
            cellIndex = LookupRaceSNcerIndex(kartIndex, itemIndexView[kartIndex].mInUseFrames);
        }
    } else if (rankList->mShownItems[kartIndex] != ITEM_INFO_NONE) {
        cellIndex = LookupRaceSNcerIndex(kartIndex, rankList->mShownItems[kartIndex]);
    } else if (gKartItems[kartIndex].mSlotState == KART_ITEMS_SLOT_SPINNING) {
        cellIndex = 0x16;
    } else {
        cellIndex = 0xc9;
    }
    return cellIndex;
}

void DrawRaceRankListRankCells(RaceHudOamBuffer *oamBuffer) {
    s32 slotPositions[8][2] = {{8, 0xf}, {8, 0x26}, {8, 0x3d}, {8, 0x54}, {8, 0x6b}, {8, 0x82}, {8, 0x99}, {8, 0xb0}};
    u16 kartIndex;
    s32 slideX;
    s32 rankSlot;
    s32 markerIndex;
    s32 slotY;
    s32 rankDrawPosition[2];
    s32 markerDrawPosition[2];
    NNSG2dCellDataWithBR *cell;

    slideX = gRaceRankList->mSlideX;
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        rankSlot = gRaceRankList->mPrevRanks[kartIndex] - 1;
        cell = GetRaceSNcerEntry(rankSlot + 0x35);
        rankDrawPosition[0] = TO_FIXED12(slotPositions[rankSlot][0] - slideX - 1);
        slotY = slotPositions[rankSlot][1];
        rankDrawPosition[1] = TO_FIXED12(slotY - 4);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, rankDrawPosition, 0, 1);
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated(kartIndex) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved(kartIndex) != 0 || IsKartRemovedWrapper(kartIndex) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if (kartIndex == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x75);
        markerDrawPosition[0] = -slideX << 12;
        markerDrawPosition[1] = TO_FIXED12(slotY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void DrawRaceRankListKartIconsRows(RaceHudOamBuffer *oamBuffer) {
    u16 rankIndex;
    s32 kartIndex;
    RaceRankListPos position;
    s32 itemCellIndex;
    u16 matrixIndex;
    MtxFx22 *matrix;
    s32 secondKartCellBase;
    s32 itemDrawPosition[2];
    s32 kartDrawPosition[2];
    s32 secondKartDrawPosition[2];
    s32 markerDrawPosition[2];
    s32 markerIndex;
    NNSG2dCellDataWithBR *cell;

    for (rankIndex = 0; rankIndex < (u32) gRaceSetup->mKartCount; rankIndex++) {
        kartIndex = gRaceRankList->mKartsByRank[rankIndex];
        position = gRaceRankList->mRowPositions[kartIndex];
        itemCellIndex = GetRaceRankListSNcerIndex(kartIndex);
        position.mX -= gRaceRankList->mSlideX;
        if (itemCellIndex != 0xc9) {
            cell = GetRaceSNcerEntry(itemCellIndex);
            itemDrawPosition[0] = TO_FIXED12(position.mX + 0x45);
            itemDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      itemDrawPosition, 0, 1);
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrixIndex = gRaceRankList->mOamMatrixIndex;
        } else {
            matrixIndex = 0;
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrix = &gRaceRankList->mMatrix;
        } else {
            matrix = NULL;
        }
        cell = GetRaceSNcerEntry(kartIndex + 8);
        kartDrawPosition[0] = TO_FIXED12(position.mX);
        kartDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  kartDrawPosition, matrixIndex, 1);
        secondKartCellBase = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            secondKartCellBase = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || IsKartRemovedWrapper(kartIndex) != 0)) {
            secondKartCellBase = 1;
        }
        secondKartCellBase = secondKartCellBase != 0 ? 0x6d : 0x65;
        cell = GetRaceSNcerEntry(secondKartCellBase + kartIndex);
        secondKartDrawPosition[0] = TO_FIXED12(position.mX + 0xa);
        secondKartDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  secondKartDrawPosition, 0, 1);
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || IsKartRemovedWrapper(kartIndex) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if ((u16) kartIndex == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x79);
        markerDrawPosition[0] = TO_FIXED12(position.mX - 0xb);
        markerDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void DrawRaceRankListMapRows(RaceHudOamBuffer *oamBuffer) {
    u16 rankIndex;
    s32 kartIndex;
    RaceRankListPos position;
    s32 itemCellIndex;
    MtxFx22 *matrix;
    u16 matrixIndex;
    s32 itemDrawPosition[2];
    s32 kartDrawPosition[2];
    s32 markerDrawPosition[2];
    s32 markerIndex;
    NNSG2dCellDataWithBR *cell;

    for (rankIndex = 0; rankIndex < (u32) gRaceSetup->mKartCount; rankIndex++) {
        kartIndex = gRaceRankList->mKartsByRank[rankIndex];
        position = gRaceRankList->mRowPositions[kartIndex];
        itemCellIndex = GetRaceRankListSNcerIndex(kartIndex);
        position.mX -= gRaceRankList->mSlideX;
        if (itemCellIndex != 0xc9) {
            cell = GetRaceSNcerEntry(itemCellIndex);
            itemDrawPosition[0] = TO_FIXED12(position.mX + 0x12);
            itemDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      itemDrawPosition, 0, 1);
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrixIndex = gRaceRankList->mOamMatrixIndex;
        } else {
            matrixIndex = 0;
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrix = &gRaceRankList->mMatrix;
        } else {
            matrix = NULL;
        }
        cell = GetRaceSNcerEntry(kartIndex + 8);
        kartDrawPosition[0] = TO_FIXED12(position.mX);
        kartDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  kartDrawPosition, matrixIndex, 1);
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || IsKartRemovedWrapper(kartIndex) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if ((u16) kartIndex == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x7d);
        markerDrawPosition[0] = TO_FIXED12(position.mX - 0xb);
        markerDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void DrawRaceRankListNonBattleRows(RaceHudOamBuffer *oamBuffer) {
    switch (GetRaceHudSubScreenState()) {
        case RACE_HUD_SUB_SCREEN_KART_ICONS:
            DrawRaceRankListRankCells(oamBuffer);
            DrawRaceRankListKartIconsRows(oamBuffer);
            break;
        case RACE_HUD_SUB_SCREEN_MAP_TURNING:
        case RACE_HUD_SUB_SCREEN_MAP_FIXED_SCROLL:
        case RACE_HUD_SUB_SCREEN_MAP_VIEW:
            DrawRaceRankListRankCells(oamBuffer);
            DrawRaceRankListMapRows(oamBuffer);
            break;
    }
}

void DrawRaceRankListBattleKartIconsRows(RaceHudOamBuffer *oamBuffer) {
    s32 secondKartCellBase;
    u16 rankIndex;
    u16 matrixIndex;
    RaceRankListPos position;
    MtxFx22 *matrix;
    s32 kartIndex;
    s32 itemDrawPosition[2];
    s32 kartDrawPosition[2];
    s32 secondKartDrawPosition[2];
    s32 balloonCellDrawPosition[2];
    s32 itemCellIndex;
    s32 balloonCountDrawPosition[2];
    s32 shineCellDrawPosition[2];
    s32 shineTensDrawPosition[2];
    s32 shineOnesDrawPosition[2];
    s32 markerDrawPosition[2];
    s32 markerIndex;
    NNSG2dCellDataWithBR *cell;

    for (rankIndex = 0; rankIndex < (u32) gRaceSetup->mKartCount; rankIndex++) {
        kartIndex = gRaceRankList->mKartsByRank[rankIndex];
        position = gRaceRankList->mRowPositions[kartIndex];
        itemCellIndex = GetRaceRankListSNcerIndex(kartIndex);
        position.mX -= gRaceRankList->mSlideX + 0x13;
        if (itemCellIndex != 0xc9) {
            cell = GetRaceSNcerEntry(itemCellIndex);
            itemDrawPosition[0] = TO_FIXED12(position.mX + 0x45);
            itemDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      itemDrawPosition, 0, 1);
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrixIndex = gRaceRankList->mOamMatrixIndex;
        } else {
            matrixIndex = 0;
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrix = &gRaceRankList->mMatrix;
        } else {
            matrix = NULL;
        }
        cell = GetRaceSNcerEntry(kartIndex + 8);
        kartDrawPosition[0] = TO_FIXED12(position.mX + 1);
        kartDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  kartDrawPosition, matrixIndex, 1);
        secondKartCellBase = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            secondKartCellBase = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || IsKartRemovedWrapper(kartIndex) != 0)) {
            secondKartCellBase = 1;
        }
        secondKartCellBase = secondKartCellBase != 0 ? 0x6d : 0x65;
        cell = GetRaceSNcerEntry(secondKartCellBase + kartIndex);
        secondKartDrawPosition[0] = TO_FIXED12(position.mX + 0xb);
        secondKartDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  secondKartDrawPosition, 0, 1);
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            s32 balloonCount = gRaceRankList->mBalloonOrShineCounts[kartIndex];

            cell = GetRaceSNcerEntry(0xc3);
            balloonCellDrawPosition[0] = TO_FIXED12(position.mX + 0x57);
            balloonCellDrawPosition[1] = TO_FIXED12(position.mY - 2);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      balloonCellDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(balloonCount + 0xb9);
            balloonCountDrawPosition[0] = TO_FIXED12(position.mX + 0x5c);
            balloonCountDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      balloonCountDrawPosition, 0, 1);
        } else {
            s32 shineTens = gRaceRankList->mBalloonOrShineCounts[kartIndex] / 10;
            s32 shineOnes = gRaceRankList->mBalloonOrShineCounts[kartIndex] % 10;

            cell = GetRaceSNcerEntry(0xc4);
            shineCellDrawPosition[0] = TO_FIXED12(position.mX + 0x57);
            shineCellDrawPosition[1] = TO_FIXED12(position.mY - 2);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineCellDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(shineTens + 0xb9);
            shineTensDrawPosition[0] = TO_FIXED12(position.mX + 0x54);
            shineTensDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineTensDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(shineOnes + 0xb9);
            shineOnesDrawPosition[0] = TO_FIXED12(position.mX + 0x5c);
            shineOnesDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineOnesDrawPosition, 0, 1);
        }
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || IsKartRemovedWrapper(kartIndex) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if ((u16) kartIndex == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x81);
        markerDrawPosition[0] = TO_FIXED12(position.mX - 0xb);
        markerDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void DrawRaceRankListBattleMapRows(RaceHudOamBuffer *oamBuffer) {
    u16 rankIndex;
    u16 matrixIndex;
    RaceRankListPos position;
    MtxFx22 *matrix;
    s32 kartIndex;
    s32 itemDrawPosition[2];
    s32 kartDrawPosition[2];
    s32 balloonCellDrawPosition[2];
    s32 balloonCountDrawPosition[2];
    s32 itemCellIndex;
    s32 shineCellDrawPosition[2];
    s32 shineTensDrawPosition[2];
    s32 shineOnesDrawPosition[2];
    s32 markerDrawPosition[2];
    s32 markerIndex;
    NNSG2dCellDataWithBR *cell;

    for (rankIndex = 0; rankIndex < (u32) gRaceSetup->mKartCount; rankIndex++) {
        kartIndex = gRaceRankList->mKartsByRank[rankIndex];
        position = gRaceRankList->mRowPositions[kartIndex];
        itemCellIndex = GetRaceRankListSNcerIndex(kartIndex);
        position.mX -= gRaceRankList->mSlideX + 0x13;
        if (itemCellIndex != 0xc9) {
            cell = GetRaceSNcerEntry(itemCellIndex);
            itemDrawPosition[0] = TO_FIXED12(position.mX + 0x12);
            itemDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      itemDrawPosition, 0, 1);
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrixIndex = gRaceRankList->mOamMatrixIndex;
        } else {
            matrixIndex = 0;
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrix = &gRaceRankList->mMatrix;
        } else {
            matrix = NULL;
        }
        cell = GetRaceSNcerEntry(kartIndex + 8);
        kartDrawPosition[0] = TO_FIXED12(position.mX + 1);
        kartDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  kartDrawPosition, matrixIndex, 1);
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            s32 balloonCount = gRaceRankList->mBalloonOrShineCounts[kartIndex];

            cell = GetRaceSNcerEntry(0xc3);
            balloonCellDrawPosition[0] = TO_FIXED12(position.mX + 0x25);
            balloonCellDrawPosition[1] = TO_FIXED12(position.mY - 2);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      balloonCellDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(balloonCount + 0xb9);
            balloonCountDrawPosition[0] = TO_FIXED12(position.mX + 0x2a);
            balloonCountDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      balloonCountDrawPosition, 0, 1);
        } else {
            s32 shineTens = gRaceRankList->mBalloonOrShineCounts[kartIndex] / 10;
            s32 shineOnes = gRaceRankList->mBalloonOrShineCounts[kartIndex] % 10;

            cell = GetRaceSNcerEntry(0xc4);
            shineCellDrawPosition[0] = TO_FIXED12(position.mX + 0x25);
            shineCellDrawPosition[1] = TO_FIXED12(position.mY - 2);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineCellDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(shineTens + 0xb9);
            shineTensDrawPosition[0] = TO_FIXED12(position.mX + 0x22);
            shineTensDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineTensDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(shineOnes + 0xb9);
            shineOnesDrawPosition[0] = TO_FIXED12(position.mX + 0x2a);
            shineOnesDrawPosition[1] = TO_FIXED12(position.mY);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineOnesDrawPosition, 0, 1);
        }
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || IsKartRemovedWrapper(kartIndex) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if ((u16) kartIndex == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x85);
        markerDrawPosition[0] = TO_FIXED12(position.mX - 0xb);
        markerDrawPosition[1] = TO_FIXED12(position.mY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void InitRaceLapNumber(void) {
    gRaceLapNumber = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceLapNumber));
    gRaceLapNumber->mLapIndex = 0;
    gRaceLapNumber->mPrevLapIndex = 0;
    gRaceLapNumber->mLastLapIndex = (u16) (GetLapCount() - 1);
    gRaceLapNumber->mBlinkFrames = 0;
    gRaceLapNumber->mBlinkShown = 1;
}

void ClearRaceLapNumberPointer(void) {
    gRaceLapNumber = NULL;
}

// Cell DrawRaceLapAndTimeDifference draws for a non-zero or a zero mTimeDifferenceSign.
typedef enum { RACE_TA_M_SIGN_CELL_FLAG_SET, RACE_TA_M_SIGN_CELL_FLAG_CLEAR } RaceTaMSignCell;

// Plays a sound when the displayed kart starts a lap before the last, and counts 0x78 frames for the lap number blink.
void UpdateRaceLapNumber(void) {
    RaceLapNumber *lapNumber;
    NNSSndSeqPlayer **seqPlayerHandle;
    u32 seqIndex;

    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        switch (gRaceSetup->mMissionKind) {
            case MISSION_KIND_LAPS:
            case MISSION_KIND_LAPS_MINI_TURBO_COUNT:
            case MISSION_KIND_LAPS_FIRST_PLACE:
            case MISSION_KIND_LAPS_NO_LAP_PROGRESS:
                break;
            default:
                return;
        }
    }
    gRaceLapNumber->mPrevLapIndex = gRaceLapNumber->mLapIndex;
    gRaceLapNumber->mLapIndex = GetKartHighestLap(GetFollowedKartOrEntryIndex()) - 1;
    if (gRaceLapNumber->mLapIndex != gRaceLapNumber->mPrevLapIndex && gRaceLapNumber->mLastLapIndex > 0) {
        if (gRaceLapNumber->mLapIndex < gRaceLapNumber->mLastLapIndex) {
            seqIndex = 0x41;
            if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
                seqIndex = 0x1c7;
            }
            if (gRaceSoundKind & 1) {
                seqPlayerHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                if (gSoundModeHolder.mSeqStartEnabled != 0) {
                    if (*seqPlayerHandle != NULL) {
                        NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
                    }
                    if (*seqPlayerHandle != NULL) {
                        NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(seqPlayerHandle, 0, seqIndex);
                }
            }
        }
        gRaceLapNumber->mBlinkFrames = 1;
    }
    lapNumber = gRaceLapNumber;
    if (lapNumber->mBlinkFrames != 0) {
        if ((lapNumber->mBlinkFrames - 1) % 12 < 8) {
            lapNumber->mBlinkShown = 1;
        } else {
            lapNumber->mBlinkShown = 0;
        }
        gRaceLapNumber->mBlinkFrames++;
        if (gRaceLapNumber->mBlinkFrames > RACE_LAP_NUMBER_BLINK_FRAMES) {
            gRaceLapNumber->mBlinkFrames = 0;
        }
    } else {
        lapNumber->mBlinkShown = 1;
    }
}

// Draws the lap label, the lap number while the blink shows it, a cell for last lap index 2 or 4, the time difference.
void DrawRaceLapAndTimeDifference(RaceHudOamBuffer *oamBuffer) {
    s32 lapPosition[2] = {0xf8, 0x10};
    s32 *timeDifferenceSign;
    TimeDigits *timeDifferenceDigits;
    s32 lapLabelDrawPosition[2];
    s32 lapNumberDrawPosition[2];
    s32 lastLapIndexTwoDrawPosition[2];
    s32 lastLapIndexFourDrawPosition[2];
    s32 showLapTimeFrames;
    NNSG2dCellDataWithBR *cell;

    if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        switch (gRaceSetup->mMissionKind) {
            case MISSION_KIND_LAPS:
            case MISSION_KIND_LAPS_MINI_TURBO_COUNT:
            case MISSION_KIND_LAPS_FIRST_PLACE:
            case MISSION_KIND_LAPS_NO_LAP_PROGRESS:
                if (gRaceLapNumber->mLastLapIndex < 2) {
                    return;
                }
                break;
            default:
                return;
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    cell = GetRaceMNcerEntry(0x20);
    lapLabelDrawPosition[0] = TO_FIXED12(lapPosition[0]);
    lapLabelDrawPosition[1] = TO_FIXED12(lapPosition[1]);
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, lapLabelDrawPosition, 0, 1);
    if (gRaceLapNumber->mBlinkShown != 0) {
        cell = GetRaceMNcerEntry(gRaceLapNumber->mLapIndex + 0x21);
        lapNumberDrawPosition[0] = TO_FIXED12(lapPosition[0]);
        lapNumberDrawPosition[1] = TO_FIXED12(lapPosition[1]);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  lapNumberDrawPosition, 0, 1);
    }
    switch (gRaceLapNumber->mLastLapIndex) {
        case 2:
            cell = GetRaceMNcerEntry(0x26);
            lastLapIndexTwoDrawPosition[0] = TO_FIXED12(lapPosition[0]);
            lastLapIndexTwoDrawPosition[1] = TO_FIXED12(lapPosition[1]);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      lastLapIndexTwoDrawPosition, 0, 1);
            break;
        case 4:
            cell = GetRaceMNcerEntry(0x27);
            lastLapIndexFourDrawPosition[0] = TO_FIXED12(lapPosition[0]);
            lastLapIndexFourDrawPosition[1] = TO_FIXED12(lapPosition[1]);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      lastLapIndexFourDrawPosition, 0, 1);
            break;
    }
    if (GetUseTimeDifference() == 0) {
        return;
    }
    if (GetShowLapTime() == 0) {
        return;
    }
    showLapTimeFrames = GetShowLapTimeFrames();
    if (showLapTimeFrames % 0x24 >= 0x18) {
        return;
    }
    {
        s32 signDrawPosition[2];
        s32 digit0DrawPosition[2];
        s32 digit1DrawPosition[2];
        s32 firstSeparatorDrawPosition[2];
        s32 digit2DrawPosition[2];
        s32 digit3DrawPosition[2];
        s32 secondSeparatorDrawPosition[2];
        s32 digit4DrawPosition[2];
        s32 digit5DrawPosition[2];
        s32 digit6DrawPosition[2];
        s32 cellXs[10] = {0x57, 0x61, 0x6a, 0x72, 0x7c, 0x85, 0x8e, 0x98, 0xa1, 0xaa};

        GetRaceHudTimeDifference(&timeDifferenceSign, &timeDifferenceDigits);
        cell = GetRaceTaMNcerEntry(*timeDifferenceSign != 0 ? RACE_TA_M_SIGN_CELL_FLAG_SET
                                                            : RACE_TA_M_SIGN_CELL_FLAG_CLEAR);
        signDrawPosition[0] = TO_FIXED12(cellXs[0]);
        signDrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, signDrawPosition, 0, 1);
        if (timeDifferenceDigits->mDigits[0] != 0) {
            cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[0] + 2);
            digit0DrawPosition[0] = TO_FIXED12(cellXs[1]);
            digit0DrawPosition[1] = 0x58000;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      digit0DrawPosition, 0, 1);
        }
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[1] + 2);
        digit1DrawPosition[0] = TO_FIXED12(cellXs[2]);
        digit1DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit1DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(0xc);
        firstSeparatorDrawPosition[0] = TO_FIXED12(cellXs[3]);
        firstSeparatorDrawPosition[1] = 0x58000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  firstSeparatorDrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[2] + 2);
        digit2DrawPosition[0] = TO_FIXED12(cellXs[4]);
        digit2DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit2DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[3] + 2);
        digit3DrawPosition[0] = TO_FIXED12(cellXs[5]);
        digit3DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit3DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(0xc);
        secondSeparatorDrawPosition[0] = TO_FIXED12(cellXs[6]);
        secondSeparatorDrawPosition[1] = 0x58000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  secondSeparatorDrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[4] + 2);
        digit4DrawPosition[0] = TO_FIXED12(cellXs[7]);
        digit4DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit4DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[5] + 2);
        digit5DrawPosition[0] = TO_FIXED12(cellXs[8]);
        digit5DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit5DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[6] + 2);
        digit6DrawPosition[0] = TO_FIXED12(cellXs[9]);
        digit6DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit6DrawPosition, 0, 1);
    }
}

void InitRaceTimeDigits(void) {
    s32 digitIndex;

    gRaceTimeDigits = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceTimeDigits));
    gRaceTimeDigits->mTime.mDigits[0] = 0;
    gRaceTimeDigits->mTime.mDigits[1] = 0;
    gRaceTimeDigits->mTime.mDigits[2] = 0;
    gRaceTimeDigits->mTime.mDigits[3] = 0;
    gRaceTimeDigits->mTime.mDigits[4] = 0;
    gRaceTimeDigits->mTime.mDigits[5] = 0;
    gRaceTimeDigits->mTime.mDigits[6] = 0;
    gRaceTimeDigits->mUseLastSecondsSound = FALSE;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            gRaceTimeDigits->mUseLastSecondsSound = TRUE;
        }
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (gRaceSetup->mMissionKind != MISSION_KIND_LAPS_FIRST_PLACE) {
            gRaceTimeDigits->mUseLastSecondsSound = TRUE;
        }
    }
    for (digitIndex = 0; digitIndex < 6; digitIndex++) {
        gRaceTimeDigits->mLastSecondsReached[digitIndex] = 0;
    }
}
