#include "Main/Unknown/code_020c214c.h"

#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_020c13e8.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_020c3000.h"
#include "Main/Unknown/code_020c31ec.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020c0dd8.h"

// placeholder: an object of the original file that is not known yet; it only sets the order of the tables below
u8 data_020c214c_pad[12];

void sub_20C3B6C(s32 row, s32 style) {
    UnkPair020b502c spans[8] = {{2, 5}, {5, 8}, {8, 10}, {10, 13}, {13, 16}, {15, 18}, {18, 21}, {21, 23}};
    UnkPair020b502c fullSpan = {0, 0x1f};
    s32 m;
    s32 copyIndex;
    u32 spanStart;
    u32 spanLength;
    u32 fullStart;
    u32 fullLength;

    m = row % 2;
    copyIndex = m != 0 ? 1 : 0;
    m = m != 0 ? 2 : 1;
    switch (style) {
        case 0:
            spanStart = spans[row].field0;
            spanLength = spans[row].field4 - spanStart + 1;
            fullStart = fullSpan.field0;
            fullLength = fullSpan.field4 - fullStart + 1;
            m2d_copyCharMapTiles2d(r2d_sResults->mRaceGoalSSpaceNscrCopies[copyIndex], fullStart, spanStart, fullLength,
                               spanLength, r2d_sResults->mRaceGoalSNscrs[m]->mData, fullStart, spanStart);
            m2d_setCharMapPalette2d(r2d_sResults->mRaceGoalSNscrs[m]->mData, fullStart, spanStart, fullLength,
                                     spanLength, 9);
            break;
        case 1:
            spanStart = spans[row].field0;
            spanLength = spans[row].field4 - spanStart + 1;
            fullStart = fullSpan.field0;
            fullLength = fullSpan.field4 - fullStart + 1;
            m2d_copyCharMapTiles2d(r2d_sResults->mRaceGoalSSpaceNscrCopies[copyIndex], fullStart, spanStart, fullLength,
                               spanLength, r2d_sResults->mRaceGoalSNscrs[m]->mData, fullStart, spanStart);
            m2d_setCharMapPalette2d(r2d_sResults->mRaceGoalSNscrs[m]->mData, fullStart, spanStart, fullLength,
                                     spanLength, 8);
            break;
        case 2:
            spanStart = spans[row].field0;
            spanLength = spans[row].field4 - spanStart + 1;
            fullLength = fullSpan.field4 - fullSpan.field0 + 1;
            m2d_setCharMapCharName2d(r2d_sResults->mRaceGoalSNscrs[m]->mData, fullSpan.field0, spanStart, fullLength,
                                     spanLength, 0);
            break;
    }
}

void UpdateRaceGoalSOffset(void) {
    s32 frame;

    frame = r2d_sResults->mOffsetStateFrames;
    r2d_sResults->mOffsetStateFrames = frame + 1;
    switch (r2d_sResults->mOffsetState) {
        case 0:
            r2d_sResults->mOffset = -0x20;
            if (r2d_sResults->mUpdate == SlideInRaceGoalS) {
                r2d_sResults->mOffsetState = 1;
                r2d_sResults->mOffsetStateFrames = 0;
            } else {
                r2d_sResults->mOffsetState = 10;
                r2d_sResults->mOffsetStateFrames = 0;
            }
            break;
        case 1:
            if (frame < 0x14) {
                r2d_sResults->mOffset = mutil_interpolate(1, -0x20, 0, frame, 0x14);
            } else {
                r2d_sResults->mOffset = 0;
                r2d_sResults->mOffsetState = 2;
                r2d_sResults->mOffsetStateFrames = 0;
            }
            break;
        case 2:
            r2d_sResults->mOffset = 0;
            if (gRaceMultiConfig->mMode == 5 && rchoi_getIsExittingRace() != 0) {
                r2d_sResults->mOffsetState = 3;
                r2d_sResults->mOffsetStateFrames = 0;
                return;
            }
            if (func_020c1728 == r2d_sResults->mUpdate) {
                r2d_sResults->mOffsetState = 3;
                r2d_sResults->mOffsetStateFrames = 0;
            } else if (func_020c0fd0 == r2d_sResults->mUpdate) {
                r2d_sResults->mOffsetState = 9;
                r2d_sResults->mOffsetStateFrames = 0;
            }
            break;
        case 3:
            if (frame < 0x14) {
                r2d_sResults->mOffset = mutil_interpolate(1, 0, -0x20, frame, 0x14);
            } else {
                r2d_sResults->mOffset = -0x20;
                if (gRaceMultiConfig->mMode == 5 && rchoi_getIsExittingRace() != 0) {
                    r2d_sResults->mOffsetState = 7;
                    r2d_sResults->mOffsetStateFrames = 0;
                } else {
                    r2d_sResults->mOffsetState = 4;
                    r2d_sResults->mOffsetStateFrames = 0;
                }
            }
            break;
        case 4:
            if (frame < 0x14) {
                r2d_sResults->mOffset = mutil_interpolate(1, -0x20, 0, frame, 0x14);
            } else {
                r2d_sResults->mOffset = 0;
                r2d_sResults->mOffsetState = 5;
                r2d_sResults->mOffsetStateFrames = 0;
            }
            break;
        case 5:
            r2d_sResults->mOffset = 0;
            if (gRaceMultiConfig->mMode != 5) {
                return;
            }
            if (rchoi_getIsExittingRace() == 0) {
                return;
            }
            r2d_sResults->mOffsetState = 6;
            r2d_sResults->mOffsetStateFrames = 0;
            break;
        case 6:
            if (frame < 0x14) {
                r2d_sResults->mOffset = mutil_interpolate(1, 0, -0x20, frame, 0x14);
            } else {
                r2d_sResults->mOffset = -0x20;
                r2d_sResults->mOffsetState = 7;
                r2d_sResults->mOffsetStateFrames = 0;
            }
            break;
        case 7:
            if (frame < 0x14) {
                r2d_sResults->mOffset = mutil_interpolate(1, -0x20, 0, frame, 0x14);
            } else {
                r2d_sResults->mOffset = 0;
                r2d_sResults->mOffsetState = 8;
                r2d_sResults->mOffsetStateFrames = 0;
            }
            break;
        case 8:
        case 10:
            r2d_sResults->mOffset = 0;
            break;
        case 9:
            if (frame < 0x14) {
                r2d_sResults->mOffset = mutil_interpolate(1, 0, -0x20, frame, 0x14);
            } else {
                r2d_sResults->mOffset = 0;
                r2d_sResults->mOffsetState = 10;
                r2d_sResults->mOffsetStateFrames = 0;
            }
            break;
    }
}

void r2dres_init(void) {
    s32 sortKeys[8];
    u16 i;
    u32 j;
    u32 g;
    s32 k;
    s32 l;
    s32 playerKind;

    r2d_sResults = heap_alloc(proc_getHeap(proc_getCurrent()), 0x20e4);
    for (i = 0; i < 8; i++) {
        r2d_sResults->mRowVisible[i] = 1;
        r2d_sResults->mShownNumbers[i] = 0;
        r2d_sResults->mRowKartIndex[i] = 0;
        r2d_sResults->mRankComparison[i] = 1;
    }
    r2d_sResults->fieldA4 = 0;
    r2d_sResults->mHiddenRowCount = 0;
    r2d_sResults->mUpdate = func_020c1ef8;
    r2d_sResults->mUpdateFrames = 0;
    r2d_sResults->fieldB4 = 0;
    r2d_sResults->mOffsetX = -0x100;
    for (j = 0; j < gRaceMultiConfig->mKartCount; j = (u16) (j + 1)) {
        if (gRaceMultiConfig->mRuleKind == 1 || gRaceMultiConfig->mMode == MODE_BATTLE) {
            playerKind = gRaceMultiConfig->mCurrentEntries[j].mPlayer.mKind;
            k = playerKind == PLAYER_KIND_HUMAN || playerKind == PLAYER_KIND_GHOST || playerKind == PLAYER_KIND_PEER
                    ? 1
                    : 0;
            l = rres_getWinCount(j);
            sortKeys[j] = l * 16 + k * 8;
            if (gRaceMultiConfig->mMode == MODE_VS || gRaceMultiConfig->mMode == 5) {
                sortKeys[j] = sortKeys[j] + (8 - rres_getPlace(j));
            } else {
                sortKeys[j] += 8 - j;
            }
            r2d_sResults->mShownNumbers[j] = rres_getWinCount(j);
        } else {
            playerKind = gRaceMultiConfig->mCurrentEntries[j].mPlayer.mKind;
            l = playerKind == PLAYER_KIND_HUMAN || playerKind == PLAYER_KIND_GHOST || playerKind == PLAYER_KIND_PEER
                    ? 1
                    : 0;
            k = rres_getTotalRankPoints(j);
            sortKeys[j] = k * 16 + l * 8 + 8 - rres_getPlace(j);
            r2d_sResults->mShownNumbers[j] = rres_getTotalRankPoints(j);
        }
    }
    for (g = 0; g < gRaceMultiConfig->mKartCount; g = (u16) (g + 1)) {
        r2d_sResults->mRowKartIndex[g] = g;
        sortKeys[g] *= -1;
    }
    SortIndicesByKey(r2d_sResults->mRowKartIndex, sortKeys, gRaceMultiConfig->mKartCount);
    for (j = 0; j < gRaceMultiConfig->mKartCount; j = (u16) (j + 1)) {
        r2d_sResults->mPreviousRowKartIndex[j] = r2d_sResults->mRowKartIndex[j];
    }
    r2d_sResults->mOffsetState = 0;
    r2d_sResults->mOffsetStateFrames = 0;
    r2d_sResults->mOffset = -0x20;
    g2du_unpackPaletteData(&r2d_sResults->mRaceGoalSBNclr, m2d_getSceneArcFile("race_goal_s_b.NCLR"));
    g2du_unpackCharacterDataBG(&r2d_sResults->mRaceGoalSBNcgr, m2d_getSceneArcFile("race_goal_s_b.NCGR"));
    g2du_unpackScreenData(&r2d_sResults->mRaceGoalSNscrs[0], m2d_getSceneArcFile("race_goal_s_bg.NSCR"));
    g2du_unpackScreenData(&r2d_sResults->mRaceGoalSNscrs[1], m2d_getSceneArcFile("race_goal_s_space1.NSCR"));
    g2du_unpackScreenData(&r2d_sResults->mRaceGoalSNscrs[2], m2d_getSceneArcFile("race_goal_s_space2.NSCR"));
    g2du_unpackScreenData(&r2d_sResults->mRaceGoalSNscrs[3], m2d_getSceneArcFile("race_goal_s_team_bg.NSCR"));
    g2du_unpackScreenData(&r2d_sResults->mRaceGoalSNscrs[4], m2d_getSceneArcFile("race_goal_s_teamB.NSCR"));
    g2du_unpackScreenData(&r2d_sResults->mRaceGoalSNscrs[5], m2d_getSceneArcFile("race_goal_s_teamR.NSCR"));
    for (i = 0; i < 0x800; i++) {
        r2d_sResults->mRaceGoalSSpaceNscrCopies[0][i] = r2d_sResults->mRaceGoalSNscrs[1]->mData[i];
        r2d_sResults->mRaceGoalSSpaceNscrCopies[1][i] = r2d_sResults->mRaceGoalSNscrs[2]->mData[i];
    }
}

u32 r2dres_finalize(void) {
    u32 address;
    u32 zero;
    address = (u32) &r2d_sResults;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void r2dres_update(void) {
    u32 address = ((u32) (&r2d_sResults));
    u32 goal = (*(u32 *) ((address) + (0)));
    u32 step = (*(u32 *) ((goal) + (172)));
    u32 v5 = ((u32(*)(void))(step))();
    UpdateRaceGoalSOffset();
}

void r2dres_renderResults(RaceHudOamBuffer *oamBuffer) {
    s32 ones;
    u16 i;
    s32 kartIndex;
    s32 number;
    s32 hundreds;
    s32 tens;
    RaceGoalS *goal = r2d_sResults;
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
            cell = r2d_getRaceGoalSCell(0x21);
            oamIndex = oamBuffer->mOamCount;
            cell21Position[1] = (r2d_sResults->mOffset + 0xb) << 12;
            cell21Position[0] = 0;
            oam = &oamBuffer->mOamBits[oamIndex];
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, cell, NULL, cell21Position, 0, 1);
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                oam->fieldE = 1;
            }
            break;
        case 4:
        case 5:
        case 6:
            cell = r2d_getRaceGoalSCell(0x22);
            oamIndex = oamBuffer->mOamCount;
            cell22Position[1] = (r2d_sResults->mOffset + 0xb) << 12;
            cell22Position[0] = 0;
            oam = &oamBuffer->mOamBits[oamIndex];
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, cell, NULL, cell22Position, 0, 1);
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                oam->fieldE = 1;
            }
            break;
        case 7:
        case 8:
            cycleFrame = r2d_sResults->mOffsetStateFrames % 40;
            if (cycleFrame < 0x20) {
                cell = r2d_getRaceGoalSCell(0x2b);
                oamIndex = oamBuffer->mOamCount;
                offset = r2d_sResults->mOffset;
                cell2bPosition[0] = 0x80000;
                cell2bPosition[1] = (offset + 0x60) << 12;
                oam = &oamBuffer->mOamBits[oamIndex];
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, cell, NULL, cell2bPosition, 0, 1);
                for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                    oam->fieldE = 1;
                }
            }
            break;
    }
    for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
        kartIndex = r2d_sResults->mRowKartIndex[i];
        number = r2d_sResults->mShownNumbers[kartIndex];
        hundreds = number / 100;
        tens = (number - hundreds * 100) / 10;
        ones = number % 10;
        if (hundreds >= 10) {
            ones = 9;
            tens = ones;
            hundreds = ones;
        }
        if (r2d_sResults->mRowVisible[i] == 0) {
            sub_20C3B6C(i, 2);
        } else if (kartIndex == Race_GetPlayerId()) {
            sub_20C3B6C(i, 0);
        } else {
            sub_20C3B6C(i, 1);
        }
        if (r2d_sResults->mRowVisible[i] != 0) {
            if (hundreds != 0) {
                cell = r2d_getRaceGoalSCell(hundreds + 0x10);
                hundredsPosition[0] = (offsetX + 0xba) << 12;
                hundredsPosition[1] = rowYs[i] << 12;
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          NULL, hundredsPosition, 0, 1);
            }
            if (hundreds != 0 || tens != 0) {
                cell = r2d_getRaceGoalSCell(tens + 0x10);
                tensPosition[0] = (offsetX + 0xc3) << 12;
                tensPosition[1] = rowYs[i] << 12;
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          NULL, tensPosition, 0, 1);
            }
            cell = r2d_getRaceGoalSCell(ones + 0x10);
            onesPosition[0] = (offsetX + 0xcc) << 12;
            onesPosition[1] = rowYs[i] << 12;
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                          0x80 - oamBuffer->mOamCount, cell, NULL, onesPosition, 0, 1);
            if (!(gRaceMultiConfig->mRuleKind == 1 || gRaceMultiConfig->mMode == MODE_BATTLE)) {
                cellIndex = r2d_shouldUsePointsPlural(number) != FALSE ? 0x1a : 0x1b;
                cell = r2d_getRaceGoalSCell(cellIndex);
                cell1aOr1bPosition[0] = (offsetX + 0xd1) << 12;
                cell1aOr1bPosition[1] = rowYs[i] << 12;
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          NULL, cell1aOr1bPosition, 0, 1);
            }
            if (gRaceMultiConfig->mUseTeams != 0) {
                cellIndex = gRaceMultiConfig->mCurrentEntries[(u16) kartIndex].mPlayer.mTeamIndex == 0 ? 0x1f : 0x20;
                cell = r2d_getRaceGoalSCell(cellIndex);
                teamPosition[0] = (offsetX + 0xec) << 12;
                teamPosition[1] = rowYs[i] << 12;
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          NULL, teamPosition, 0, 1);
            }
            if (!(gRaceMultiConfig->mRuleKind == 1 || gRaceMultiConfig->mMode == MODE_BATTLE || gRaceMultiConfig->mCourseNumber == 1)) {
                if (r2d_sResults->mUpdate == func_020c155c || r2d_sResults->mUpdate == func_020c13e8 ||
                    r2d_sResults->mUpdate == func_020c13d0) {
                    cell = r2d_getRaceGoalSCell(r2d_sResults->mRankComparison[kartIndex] + 0x1c);
                    rankChangePosition[0] = (offsetX + 0xc) << 12;
                    rankChangePosition[1] = rowYs[i] << 12;
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                              cell, NULL, rankChangePosition, 0, 1);
                }
            }
            cell = r2d_getRaceGoalSCell(i + 8);
            placePosition[0] = (offsetX + 0x1d) << 12;
            placePosition[1] = rowYs[i] << 12;
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                          0x80 - oamBuffer->mOamCount, cell, NULL, placePosition, 0, 1);
            cell = r2d_getRaceGoalSCell(kartIndex);
            kartPosition[0] = (offsetX + 0x2e) << 12;
            kartPosition[1] = rowYs[i] << 12;
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                          0x80 - oamBuffer->mOamCount, cell, NULL, kartPosition, 0, 1);
            cell = r2d_getRaceGoalSCell(kartIndex + 0x23);
            kartExtraPosition[0] = (offsetX + 0x3b) << 12;
            kartExtraPosition[1] = rowYs[i] << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      kartExtraPosition, 0, 1);
        }
    }
}

void r2dres_renderTeamDriverResult(RaceHudOamBuffer *oamBuffer, u32 kartIndex, s32 x, s32 y) {
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

    number = r2d_sResults->mShownNumbers[kartIndex];
    hundreds = number / 100;
    tens = number / 10 % 10;
    ones = number % 10;
    cell = r2d_getRaceGoalTeamSCell(kartIndex);
    kartPosition[0] = (x + 0xc) << 12;
    kartPosition[1] = y << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, kartPosition, 0, 1);
    cell = r2d_getRaceGoalTeamSCell(kartIndex + 0x20);
    kartExtraPosition[0] = (x + 0x16) << 12;
    kartExtraPosition[1] = y << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, kartExtraPosition, 0, 1);
    if (kartIndex == Race_GetPlayerId()) {
        cellIndex = gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 0 ? 0x1e : 0x1f;
    } else {
        cellIndex = gRaceMultiConfig->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 0 ? 0x1c : 0x1d;
    }
    cell = r2d_getRaceGoalTeamSCell(cellIndex);
    teamPosition[0] = x << 12;
    teamPosition[1] = y << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, teamPosition, 0, 1);
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        return;
    }
    if (hundreds >= 10) {
        ones = 9;
        hundreds = ones;
        tens = ones;
    }
    if (hundreds != 0) {
        cell = r2d_getRaceGoalTeamSCell(hundreds + 8);
        hundredsPosition[0] = (x + 0x57) << 12;
        hundredsPosition[1] = y << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, hundredsPosition, 0, 1);
    }
    if (hundreds != 0 || tens != 0) {
        cell = r2d_getRaceGoalTeamSCell(tens + 8);
        tensPosition[0] = (x + 0x60) << 12;
        tensPosition[1] = y << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, tensPosition, 0, 1);
    }
    cell = r2d_getRaceGoalTeamSCell(ones + 8);
    onesPosition[0] = (x + 0x69) << 12;
    onesPosition[1] = y << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, onesPosition, 0, 1);
}

void r2dres_renderTeamTotalPoints(RaceHudOamBuffer *oamBuffer, s32 number, s32 x, s32 y) {
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
        cell = r2d_getRaceGoalTeamSCell(thousands + 0x12);
        thousandsPosition[0] = x << 12;
        thousandsPosition[1] = y << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, thousandsPosition, 0, 1);
    }
    if (thousands != 0 || hundreds != 0) {
        cell = r2d_getRaceGoalTeamSCell(hundreds + 0x12);
        hundredsPosition[0] = (x + 0xf) << 12;
        hundredsPosition[1] = y << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, hundredsPosition, 0, 1);
    }
    if (thousands != 0 || hundreds != 0 || tens != 0) {
        cell = r2d_getRaceGoalTeamSCell(tens + 0x12);
        tensPosition[0] = (x + 0x1e) << 12;
        tensPosition[1] = y << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, tensPosition, 0, 1);
    }
    cell = r2d_getRaceGoalTeamSCell(ones + 0x12);
    onesPosition[0] = (x + 0x2d) << 12;
    onesPosition[1] = y << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, onesPosition, 0, 1);
}

void r2dres_renderTeamResults(RaceHudOamBuffer *oamBuffer) {
    s32 rowCounts[2];
    s32 teamX[2] = {0xa, 0x89};
    s32 numberX[2] = {0x43, 0xc2};
    s32 offsetX;
    s32 teamIndex;
    u16 i;
    BOOL f;
    s32 number;
    CourseTeamResults *courseRecords;

    offsetX = r2d_sResults->mOffsetX;
    for (i = 0; i < 2; i++) {
        rowCounts[i] = 0;
    }
    for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
        teamIndex = gRaceMultiConfig->mCurrentEntries[i].mPlayer.mTeamIndex;
        r2dres_renderTeamDriverResult(oamBuffer, i, teamX[teamIndex] + (teamIndex == 0 ? -offsetX : offsetX),
                              rowCounts[teamIndex] * 0x17 + 0x11);
        rowCounts[teamIndex]++;
    }
    for (i = 0; i < 2; i++) {
        f = TRUE;
        if (!(gRaceMultiConfig->mRuleKind == 1 || gRaceMultiConfig->mMode == MODE_BATTLE)) {
            f = FALSE;
        }
        if (f != FALSE) {
            courseRecords = &rres_sRaceResults->mTeamResults[rres_205DB28()];
            number = courseRecords->mTeams[i].field2;
        } else {
            courseRecords = &rres_sRaceResults->mTeamResults[rres_205DB28()];
            number = courseRecords->mTeams[i].field0;
        }
        r2dres_renderTeamTotalPoints(oamBuffer, number, numberX[i] + (i == 0 ? -offsetX : offsetX), 0xb6);
    }
}
