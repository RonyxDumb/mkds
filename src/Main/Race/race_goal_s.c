#include "Main/Race/race_goal_s.h"

#include "Main/Race/cup_records.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/data_020b837c.h"
#include "g2d_Animation.h"
#include "Main/System/low_byte.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Race/race_goal_s_finish.h"
#include "Main/Race/race_goal_s_numbers.h"
#include "code_020222ec.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/choises_s_list_chars.h"
#include "Main/System/heap_call.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Race/race_goal_s_rows.h"

// Object not known yet; it only sets the order of the tables below
u8 data_020c214c_pad[12];

void WriteRaceGoalSRowTiles(s32 row, s32 style) {
    UnkPair020b502c spans[8] = {{2, 5}, {5, 8}, {8, 10}, {10, 13}, {13, 16}, {15, 18}, {18, 21}, {21, 23}};
    UnkPair020b502c fullSpan = {0, 0x1f};
    s32 nscrIndex;
    s32 copyIndex;
    u32 spanStart;
    u32 spanLength;
    u32 fullStart;
    u32 fullLength;

    nscrIndex = row % 2;
    copyIndex = nscrIndex != 0 ? 1 : 0;
    nscrIndex = nscrIndex != 0 ? 2 : 1;
    switch (style) {
        case 0:
            spanStart = spans[row].mFirst;
            spanLength = spans[row].mSecond - spanStart + 1;
            fullStart = fullSpan.mFirst;
            fullLength = fullSpan.mSecond - fullStart + 1;
            CopyScreenMapBlock(gRaceGoalS->mRaceGoalSSpaceNscrCopies[copyIndex], fullStart, spanStart, fullLength,
                               spanLength, gRaceGoalS->mRaceGoalSNscrs[nscrIndex]->mData, fullStart, spanStart);
            SetScreenMapBlockTopBits(gRaceGoalS->mRaceGoalSNscrs[nscrIndex]->mData, fullStart, spanStart, fullLength,
                                     spanLength, 9);
            break;
        case 1:
            spanStart = spans[row].mFirst;
            spanLength = spans[row].mSecond - spanStart + 1;
            fullStart = fullSpan.mFirst;
            fullLength = fullSpan.mSecond - fullStart + 1;
            CopyScreenMapBlock(gRaceGoalS->mRaceGoalSSpaceNscrCopies[copyIndex], fullStart, spanStart, fullLength,
                               spanLength, gRaceGoalS->mRaceGoalSNscrs[nscrIndex]->mData, fullStart, spanStart);
            SetScreenMapBlockTopBits(gRaceGoalS->mRaceGoalSNscrs[nscrIndex]->mData, fullStart, spanStart, fullLength,
                                     spanLength, 8);
            break;
        case 2:
            spanStart = spans[row].mFirst;
            spanLength = spans[row].mSecond - spanStart + 1;
            fullLength = fullSpan.mSecond - fullSpan.mFirst + 1;
            SetScreenMapBlockLowBits(gRaceGoalS->mRaceGoalSNscrs[nscrIndex]->mData, fullSpan.mFirst, spanStart,
                                     fullLength, spanLength, 0);
            break;
    }
}

void UpdateRaceGoalSOffset(void) {
    s32 frame;

    frame = gRaceGoalS->mOffsetStateFrames;
    gRaceGoalS->mOffsetStateFrames = frame + 1;
    switch (gRaceGoalS->mOffsetState) {
        case 0:
            gRaceGoalS->mOffset = -0x20;
            if (gRaceGoalS->mUpdate == SlideInRaceGoalS) {
                gRaceGoalS->mOffsetState = 1;
                gRaceGoalS->mOffsetStateFrames = 0;
            } else {
                gRaceGoalS->mOffsetState = 10;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 1:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, -0x20, 0, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 2;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 2:
            gRaceGoalS->mOffset = 0;
            if (gRaceSetup->mMode == MODE_WIFI && IsChoisesSPickLocked() != 0) {
                gRaceGoalS->mOffsetState = 3;
                gRaceGoalS->mOffsetStateFrames = 0;
                return;
            }
            if (HideRaceGoalSRows == gRaceGoalS->mUpdate) {
                gRaceGoalS->mOffsetState = 3;
                gRaceGoalS->mOffsetStateFrames = 0;
            } else if (SlideOutRaceGoalS == gRaceGoalS->mUpdate) {
                gRaceGoalS->mOffsetState = 9;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 3:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, 0, -0x20, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = -0x20;
                if (gRaceSetup->mMode == MODE_WIFI && IsChoisesSPickLocked() != 0) {
                    gRaceGoalS->mOffsetState = 7;
                    gRaceGoalS->mOffsetStateFrames = 0;
                } else {
                    gRaceGoalS->mOffsetState = 4;
                    gRaceGoalS->mOffsetStateFrames = 0;
                }
            }
            break;
        case 4:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, -0x20, 0, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 5;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 5:
            gRaceGoalS->mOffset = 0;
            if (gRaceSetup->mMode != MODE_WIFI) {
                return;
            }
            if (IsChoisesSPickLocked() == 0) {
                return;
            }
            gRaceGoalS->mOffsetState = 6;
            gRaceGoalS->mOffsetStateFrames = 0;
            break;
        case 6:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, 0, -0x20, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = -0x20;
                gRaceGoalS->mOffsetState = 7;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 7:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, -0x20, 0, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 8;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 8:
        case 10:
            gRaceGoalS->mOffset = 0;
            break;
        case 9:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, 0, -0x20, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 10;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
    }
}

void InitRaceGoalS(void) {
    s32 sortKeys[8];
    u16 rowIndex;
    u32 kartIndex;
    u32 sortIndex;
    s32 firstValue;
    s32 secondValue;
    s32 playerKind;

    gRaceGoalS = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x20e4);
    for (rowIndex = 0; rowIndex < 8; rowIndex++) {
        gRaceGoalS->mRowVisible[rowIndex] = 1;
        gRaceGoalS->mShownNumbers[rowIndex] = 0;
        gRaceGoalS->mRowKartIndex[rowIndex] = 0;
        gRaceGoalS->mRankComparison[rowIndex] = 1;
    }
    gRaceGoalS->mRunning = 0;
    gRaceGoalS->mHiddenRowCount = 0;
    gRaceGoalS->mUpdate = StartRaceGoalS;
    gRaceGoalS->mUpdateFrames = 0;
    gRaceGoalS->mCourseCountReached = 0;
    gRaceGoalS->mOffsetX = -0x100;
    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
        if (gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            playerKind = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
            firstValue =
                playerKind == PLAYER_KIND_HUMAN || playerKind == PLAYER_KIND_GHOST || playerKind == PLAYER_KIND_PEER
                    ? 1
                    : 0;
            secondValue = GetKartPreviousWinCount(kartIndex);
            sortKeys[kartIndex] = secondValue * 16 + firstValue * 8;
            if (gRaceSetup->mMode == MODE_VS || gRaceSetup->mMode == MODE_WIFI) {
                sortKeys[kartIndex] = sortKeys[kartIndex] + (8 - GetKartStartRank(kartIndex));
            } else {
                sortKeys[kartIndex] += 8 - kartIndex;
            }
            gRaceGoalS->mShownNumbers[kartIndex] = GetKartPreviousWinCount(kartIndex);
        } else {
            playerKind = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
            secondValue =
                playerKind == PLAYER_KIND_HUMAN || playerKind == PLAYER_KIND_GHOST || playerKind == PLAYER_KIND_PEER
                    ? 1
                    : 0;
            firstValue = GetKartPreviousTotalPoints(kartIndex);
            sortKeys[kartIndex] = firstValue * 16 + secondValue * 8 + 8 - GetKartStartRank(kartIndex);
            gRaceGoalS->mShownNumbers[kartIndex] = GetKartPreviousTotalPoints(kartIndex);
        }
    }
    for (sortIndex = 0; sortIndex < gRaceSetup->mKartCount; sortIndex = (u16) (sortIndex + 1)) {
        gRaceGoalS->mRowKartIndex[sortIndex] = sortIndex;
        sortKeys[sortIndex] *= -1;
    }
    SortIndicesByKey(gRaceGoalS->mRowKartIndex, sortKeys, gRaceSetup->mKartCount);
    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
        gRaceGoalS->mPreviousRowKartIndex[kartIndex] = gRaceGoalS->mRowKartIndex[kartIndex];
    }
    gRaceGoalS->mOffsetState = 0;
    gRaceGoalS->mOffsetStateFrames = 0;
    gRaceGoalS->mOffset = -0x20;
    LoadNclrData(&gRaceGoalS->mRaceGoalSBNclr, FindSceneFileWrapper("race_goal_s_b.NCLR"));
    LoadNcgrData(&gRaceGoalS->mRaceGoalSBNcgr, FindSceneFileWrapper("race_goal_s_b.NCGR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[0], FindSceneFileWrapper("race_goal_s_bg.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[1], FindSceneFileWrapper("race_goal_s_space1.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[2], FindSceneFileWrapper("race_goal_s_space2.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[3], FindSceneFileWrapper("race_goal_s_team_bg.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[4], FindSceneFileWrapper("race_goal_s_teamB.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[5], FindSceneFileWrapper("race_goal_s_teamR.NSCR"));
    for (rowIndex = 0; rowIndex < 0x800; rowIndex++) {
        gRaceGoalS->mRaceGoalSSpaceNscrCopies[0][rowIndex] = gRaceGoalS->mRaceGoalSNscrs[1]->mData[rowIndex];
        gRaceGoalS->mRaceGoalSSpaceNscrCopies[1][rowIndex] = gRaceGoalS->mRaceGoalSNscrs[2]->mData[rowIndex];
    }
}

void ClearRaceGoalSPointer(void) {
    gRaceGoalS = NULL;
}

void UpdateRaceGoalS(void) {
    gRaceGoalS->mUpdate();
    UpdateRaceGoalSOffset();
}

void DrawRaceGoalSKarts(RaceHudOamBuffer *oamBuffer) {
    s32 ones;
    u16 rowIndex;
    s32 kartIndex;
    s32 number;
    s32 hundreds;
    s32 tens;
    RaceGoalS *goal = gRaceGoalS;
    s32 offsetX = goal->mOffsetX;
    s32 cycleFrame;
    s32 cellIndex;
    s32 oamIndex;
    s32 offset;
    RaceHudOamBits *oam;
    void *cell;
    s32 cell21Position[2];
    s32 cell22Position[2];
    s32 cell2bPosition[2];
    s32 hundredsPosition[2];
    s32 tensPosition[2];
    s32 onesPosition[2];
    s32 cell1aOr1bPosition[2];
    s32 teamPosition[2];
    s32 rankChangePosition[2];
    s32 placePosition[2];
    s32 kartPosition[2];
    s32 kartExtraPosition[2];
    s32 rowYs[8] = {0x22, 0x37, 0x4c, 0x61, 0x76, 0x8b, 0xa0, 0xb5};

    switch (goal->mOffsetState) {
        case 1:
        case 2:
        case 3:
        case 9:
            cell = GetRaceGoalSNcerEntry(0x21);
            oamIndex = oamBuffer->mOamCount;
            cell21Position[1] = TO_FIXED12(gRaceGoalS->mOffset + 0xb);
            cell21Position[0] = 0;
            oam = &oamBuffer->mOamBits[oamIndex];
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, cell21Position, 0, 1);
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                oam->mUnk_0e = 1;
            }
            break;
        case 4:
        case 5:
        case 6:
            cell = GetRaceGoalSNcerEntry(0x22);
            oamIndex = oamBuffer->mOamCount;
            cell22Position[1] = TO_FIXED12(gRaceGoalS->mOffset + 0xb);
            cell22Position[0] = 0;
            oam = &oamBuffer->mOamBits[oamIndex];
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, cell22Position, 0, 1);
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                oam->mUnk_0e = 1;
            }
            break;
        case 7:
        case 8:
            cycleFrame = gRaceGoalS->mOffsetStateFrames % 40;
            if (cycleFrame < 0x20) {
                cell = GetRaceGoalSNcerEntry(0x2b);
                oamIndex = oamBuffer->mOamCount;
                offset = gRaceGoalS->mOffset;
                cell2bPosition[0] = 0x80000;
                cell2bPosition[1] = TO_FIXED12(offset + 0x60);
                oam = &oamBuffer->mOamBits[oamIndex];
                oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL,
                                                              cell2bPosition, 0, 1);
                for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                    oam->mUnk_0e = 1;
                }
            }
            break;
    }
    for (rowIndex = 0; rowIndex < (u32) gRaceSetup->mKartCount; rowIndex++) {
        kartIndex = gRaceGoalS->mRowKartIndex[rowIndex];
        number = gRaceGoalS->mShownNumbers[kartIndex];
        hundreds = number / 100;
        tens = (number - hundreds * 100) / 10;
        ones = number % 10;
        if (hundreds >= 10) {
            ones = 9;
            tens = ones;
            hundreds = ones;
        }
        if (gRaceGoalS->mRowVisible[rowIndex] == 0) {
            WriteRaceGoalSRowTiles(rowIndex, 2);
        } else if (kartIndex == GetFollowedKartOrEntryIndex()) {
            WriteRaceGoalSRowTiles(rowIndex, 0);
        } else {
            WriteRaceGoalSRowTiles(rowIndex, 1);
        }
        if (gRaceGoalS->mRowVisible[rowIndex] != 0) {
            if (hundreds != 0) {
                cell = GetRaceGoalSNcerEntry(hundreds + 0x10);
                hundredsPosition[0] = TO_FIXED12(offsetX + 0xba);
                hundredsPosition[1] = TO_FIXED12(rowYs[rowIndex]);
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          NULL, hundredsPosition, 0, 1);
            }
            if (hundreds != 0 || tens != 0) {
                cell = GetRaceGoalSNcerEntry(tens + 0x10);
                tensPosition[0] = TO_FIXED12(offsetX + 0xc3);
                tensPosition[1] = TO_FIXED12(rowYs[rowIndex]);
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          NULL, tensPosition, 0, 1);
            }
            cell = GetRaceGoalSNcerEntry(ones + 0x10);
            onesPosition[0] = TO_FIXED12(offsetX + 0xcc);
            onesPosition[1] = TO_FIXED12(rowYs[rowIndex]);
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                          0x80 - oamBuffer->mOamCount, cell, NULL, onesPosition, 0, 1);
            if (!(gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE)) {
                cellIndex = IsPointsLabelPlural(number) != FALSE ? 0x1a : 0x1b;
                cell = GetRaceGoalSNcerEntry(cellIndex);
                cell1aOr1bPosition[0] = TO_FIXED12(offsetX + 0xd1);
                cell1aOr1bPosition[1] = TO_FIXED12(rowYs[rowIndex]);
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          NULL, cell1aOr1bPosition, 0, 1);
            }
            if (gRaceSetup->mUseTeams != 0) {
                cellIndex = GetCurrentEntry(kartIndex)->mPlayer.mTeamIndex == 0 ? 0x1f : 0x20;
                cell = GetRaceGoalSNcerEntry(cellIndex);
                teamPosition[0] = TO_FIXED12(offsetX + 0xec);
                teamPosition[1] = TO_FIXED12(rowYs[rowIndex]);
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          NULL, teamPosition, 0, 1);
            }
            if (!(gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mCourseNumber == 1)) {
                if (gRaceGoalS->mUpdate == ShowRaceGoalSRows || gRaceGoalS->mUpdate == HoldRaceGoalSRows ||
                    gRaceGoalS->mUpdate == FinishRaceGoalS) {
                    cell = GetRaceGoalSNcerEntry(gRaceGoalS->mRankComparison[kartIndex] + 0x1c);
                    rankChangePosition[0] = TO_FIXED12(offsetX + 0xc);
                    rankChangePosition[1] = TO_FIXED12(rowYs[rowIndex]);
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                              cell, NULL, rankChangePosition, 0, 1);
                }
            }
            cell = GetRaceGoalSNcerEntry(rowIndex + 8);
            placePosition[0] = TO_FIXED12(offsetX + 0x1d);
            placePosition[1] = TO_FIXED12(rowYs[rowIndex]);
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                          0x80 - oamBuffer->mOamCount, cell, NULL, placePosition, 0, 1);
            cell = GetRaceGoalSNcerEntry(kartIndex);
            kartPosition[0] = TO_FIXED12(offsetX + 0x2e);
            kartPosition[1] = TO_FIXED12(rowYs[rowIndex]);
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                          0x80 - oamBuffer->mOamCount, cell, NULL, kartPosition, 0, 1);
            cell = GetRaceGoalSNcerEntry(kartIndex + 0x23);
            kartExtraPosition[0] = TO_FIXED12(offsetX + 0x3b);
            kartExtraPosition[1] = TO_FIXED12(rowYs[rowIndex]);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      kartExtraPosition, 0, 1);
        }
    }
}

void DrawRaceGoalSTeamKart(RaceHudOamBuffer *oamBuffer, u32 kartIndex, s32 positionX, s32 positionY) {
    s32 kartPosition[2];
    s32 kartExtraPosition[2];
    s32 teamPosition[2];
    s32 hundredsPosition[2];
    s32 tensPosition[2];
    s32 onesPosition[2];
    s32 number;
    s32 hundreds;
    s32 tens;
    s32 ones;
    s32 cellIndex;
    void *cell;

    number = gRaceGoalS->mShownNumbers[kartIndex];
    hundreds = number / 100;
    tens = number / 10 % 10;
    ones = number % 10;
    cell = GetRaceGoalTeamSNcerEntry(kartIndex);
    kartPosition[0] = TO_FIXED12(positionX + 0xc);
    kartPosition[1] = TO_FIXED12(positionY);
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, kartPosition, 0, 1);
    cell = GetRaceGoalTeamSNcerEntry(kartIndex + 0x20);
    kartExtraPosition[0] = TO_FIXED12(positionX + 0x16);
    kartExtraPosition[1] = TO_FIXED12(positionY);
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, kartExtraPosition, 0, 1);
    if (kartIndex == GetFollowedKartOrEntryIndex()) {
        cellIndex = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 0 ? 0x1e : 0x1f;
    } else {
        cellIndex = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 0 ? 0x1c : 0x1d;
    }
    cell = GetRaceGoalTeamSNcerEntry(cellIndex);
    teamPosition[0] = TO_FIXED12(positionX);
    teamPosition[1] = TO_FIXED12(positionY);
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, teamPosition, 0, 1);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    if (hundreds >= 10) {
        ones = 9;
        hundreds = ones;
        tens = ones;
    }
    if (hundreds != 0) {
        cell = GetRaceGoalTeamSNcerEntry(hundreds + 8);
        hundredsPosition[0] = TO_FIXED12(positionX + 0x57);
        hundredsPosition[1] = TO_FIXED12(positionY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, hundredsPosition, 0, 1);
    }
    if (hundreds != 0 || tens != 0) {
        cell = GetRaceGoalTeamSNcerEntry(tens + 8);
        tensPosition[0] = TO_FIXED12(positionX + 0x60);
        tensPosition[1] = TO_FIXED12(positionY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, tensPosition, 0, 1);
    }
    cell = GetRaceGoalTeamSNcerEntry(ones + 8);
    onesPosition[0] = TO_FIXED12(positionX + 0x69);
    onesPosition[1] = TO_FIXED12(positionY);
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, onesPosition, 0, 1);
}

void DrawRaceGoalSTeamNumber(RaceHudOamBuffer *oamBuffer, s32 number, s32 positionX, s32 positionY) {
    s32 thousandsPosition[2];
    s32 hundredsPosition[2];
    s32 tensPosition[2];
    s32 onesPosition[2];
    s32 thousands;
    s32 hundreds;
    s32 tens;
    s32 ones;
    void *cell;

    thousands = number / 1000;
    hundreds = number / 100 % 10;
    tens = number / 10 % 10;
    ones = number % 10;
    if (thousands != 0) {
        cell = GetRaceGoalTeamSNcerEntry(thousands + 0x12);
        thousandsPosition[0] = TO_FIXED12(positionX);
        thousandsPosition[1] = TO_FIXED12(positionY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, thousandsPosition, 0, 1);
    }
    if (thousands != 0 || hundreds != 0) {
        cell = GetRaceGoalTeamSNcerEntry(hundreds + 0x12);
        hundredsPosition[0] = TO_FIXED12(positionX + 0xf);
        hundredsPosition[1] = TO_FIXED12(positionY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, hundredsPosition, 0, 1);
    }
    if (thousands != 0 || hundreds != 0 || tens != 0) {
        cell = GetRaceGoalTeamSNcerEntry(tens + 0x12);
        tensPosition[0] = TO_FIXED12(positionX + 0x1e);
        tensPosition[1] = TO_FIXED12(positionY);
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, tensPosition, 0, 1);
    }
    cell = GetRaceGoalTeamSNcerEntry(ones + 0x12);
    onesPosition[0] = TO_FIXED12(positionX + 0x2d);
    onesPosition[1] = TO_FIXED12(positionY);
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, onesPosition, 0, 1);
}

void DrawRaceGoalSTeams(RaceHudOamBuffer *oamBuffer) {
    s32 rowCounts[2];
    s32 teamX[2] = {0xa, 0x89};
    s32 numberX[2] = {0x43, 0xc2};
    s32 offsetX;
    s32 teamIndex;
    u16 index;
    BOOL showWinCount;
    s32 number;
    CourseTeamResults *courseRecords;

    offsetX = gRaceGoalS->mOffsetX;
    for (index = 0; index < 2; index++) {
        rowCounts[index] = 0;
    }
    for (index = 0; index < (u32) gRaceSetup->mKartCount; index++) {
        teamIndex = gRaceSetup->mCurrentEntries[index].mPlayer.mTeamIndex;
        DrawRaceGoalSTeamKart(oamBuffer, index, teamX[teamIndex] + (teamIndex == 0 ? -offsetX : offsetX),
                              rowCounts[teamIndex] * 0x17 + 0x11);
        rowCounts[teamIndex]++;
    }
    for (index = 0; index < 2; index++) {
        showWinCount = TRUE;
        if (!(gRaceSetup->mRuleKind == 1 || gRaceSetup->mMode == MODE_BATTLE)) {
            showWinCount = FALSE;
        }
        if (showWinCount != FALSE) {
            courseRecords = &gCupRecords->mTeamResults[GetCourseIndexInCup()];
            number = courseRecords->mTeams[index].mWinCount;
        } else {
            courseRecords = &gCupRecords->mTeamResults[GetCourseIndexInCup()];
            number = courseRecords->mTeams[index].mTotalPoints;
        }
        DrawRaceGoalSTeamNumber(oamBuffer, number, numberX[index] + (index == 0 ? -offsetX : offsetX), 0xb6);
    }
}
