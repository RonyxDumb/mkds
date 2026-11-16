#include "Main/Unknown/code_020c3e44.h"

#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b837c.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/System/Heap.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020c4bd8.h"
#include "Main/Unknown/code_0212a724.h"
#include "g2d_CharCanvas.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b47b4.h"
#include "g2d_NOB_load.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0212030c.h"
#include "code_02142eac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020c5ccc.h"
#include "Main/Unknown/code_020c5ce0.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Race/RaceStartSequence.h"
#include "Main/Kart/KartTimes.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"
#include "registers.h"

u32 func_020c5dc4(void) {
    return (gRaceGoalM->field0);
}

u32 GetRaceGoalMUpdateFrames(void) {
    return (gRaceGoalM->mUpdateFrames);
}

void InitRaceGoalM(void) {
    gRaceGoalM = heap_alloc(proc_getHeap(proc_getCurrent()), 0x1c);
    gRaceGoalM->field0 = 1;
    gRaceGoalM->mUpdateFrames = 0;
    gRaceGoalM->mRankIndex = 0;
    gRaceGoalM->mPointsGained = 0;
    gRaceGoalM->mFirstPlaceKartIndex = 0;
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        if (GetMissionRecordValue(gRaceMultiConfig->mMode == MODE_MISSION_RUN ? gRaceMultiConfig->mMissionTableRow : -1,
                                  gRaceMultiConfig->mMode == MODE_MISSION_RUN ? gRaceMultiConfig->mMissionTableColumn : -1,
                                  &gRaceGoalM->field14) == 0) {
            gRaceGoalM->field14 = 9;
        }
    } else {
        gRaceGoalM->field14 = 9;
    }
    gRaceGoalM->field18 = 9;
}

u32 ClearRaceGoalMPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceGoalM;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void UpdateRaceGoalM(void) {
    u32 kartIndex;
    s32 a;
    u16 i;
    s32 frame;
    u16 followedKartIndex;
    s32 *updateFramesPointer;
    KartCourseResult *record;

    frame = gRaceGoalM->mUpdateFrames;
    followedKartIndex = Race_GetPlayerId();
    if (gRaceStatus->field0[followedKartIndex].mStatus == 1 || gRaceStatus->mRaceDone != 0) {
        gRaceGoalM->field0 = 0;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        if ((rstat_hasDriverFinished((u16) gRaceMultiConfig->mEntryIndex) != 0 ? gRaceStatus->mEntryEndKind : 6) != 0 &&
            func_0207a218() == 0 && frame == 0) {
            return;
        }
    }
    updateFramesPointer = &gRaceGoalM->mUpdateFrames;
    if (*updateFramesPointer < 0x7fffffff) {
        *updateFramesPointer = *updateFramesPointer + 1;
    }
    switch (gRaceMultiConfig->mMode) {
        case MODE_GRAND_PRIX:
            gRaceGoalM->mRankIndex = rstat_getPlace(Race_GetPlayerId()) - 1;
            kartIndex = rres_205DC7C(Race_GetPlayerId());
            a = rres_205DB28();
            record = &rres_sRaceResults->mKartResults[a][rres_205DC7C(kartIndex)];
            a = record->mTotalPoints;
            gRaceGoalM->mPointsGained = a - rres_getTotalRankPoints(Race_GetPlayerId());
            if (frame > 0x14) {
                gRaceGoalM->field0 = 1;
            }
            break;
        case MODE_TIME_ATTACK:
            if (frame > 0x14) {
                gRaceGoalM->field0 = 1;
            }
            break;
        case MODE_VS:
        case 5:
            gRaceGoalM->mRankIndex = rstat_getPlace(Race_GetPlayerId()) - 1;
            for (i = 0; i < (u32) gRaceMultiConfig->mKartCount; i++) {
                if (rstat_getPlace(i) == 1) {
                    break;
                }
            }
            gRaceGoalM->mFirstPlaceKartIndex = i;
            if (frame > 0x14) {
                gRaceGoalM->field0 = 1;
            }
            break;
        case MODE_MISSION_RUN:
            if (rstat_hasDriverFinished((u16) gRaceMultiConfig->mEntryIndex) != 0 ? gRaceStatus->mEntryEndKind : 6) {
                gRaceGoalM->field18 = 9;
            } else {
                gRaceGoalM->field18 = rres_calculateMrRank();
            }
            if ((rstat_hasDriverFinished((u16) gRaceMultiConfig->mEntryIndex) != 0 ? gRaceStatus->mEntryEndKind : 6) == 0) {
                if (frame == 1) {
                    switch (gRaceGoalM->field18) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            break;
                        case 5:
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1b);
                            break;
                        case 6:
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1c);
                            break;
                        case 7:
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1d);
                            break;
                    }
                } else if (frame > 0x1e) {
                    gRaceGoalM->field0 = 1;
                }
            } else if (frame > 0x4b) {
                gRaceGoalM->field0 = 1;
            }
            break;
        default:
            gRaceGoalM->field0 = 1;
            break;
    }
}

void DrawRaceGoalM(RaceHudOamBuffer *oamBuffer) {
    s32 offsetY;
    s32 oamIndex;
    s32 position[2];
    void *cell;

    if (gRaceMultiConfig->mRaceKind != RACE_KIND_NORMAL) {
        return;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    switch (gRaceMultiConfig->mMode) {
        case MODE_GRAND_PRIX:
            DrawRaceGoalMGrandPrix(oamBuffer);
            break;
        case MODE_VS:
        case 5:
            offsetY = mutil_interpolate(1, 0x40, 0, gRaceGoalM->mUpdateFrames, 0x14);
            cell = r2d_getRaceGoalMCell(gRaceGoalM->mRankIndex);
            position[0] = 0x18000;
            position[1] = (offsetY + 0xa8) << 12;
            oamIndex = oamBuffer->mOamCount;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, position, 0, 1);
            break;
        case MODE_MISSION_RUN:
            DrawRaceGoalMMissionRun(oamBuffer);
            break;
    }
}

void DrawRaceGoalMGrandPrix(RaceHudOamBuffer *oamBuffer) {
    s32 offsetY;
    s32 oamIndex;
    s32 rankPosition[2];
    s32 pointsPosition[2];
    s32 cell13Or14Position[2];
    s32 cell40Position[2];
    s32 cell41Position[2];
    s32 z;
    void *cell;

    offsetY = mutil_interpolate(1, 0x40, 0, gRaceGoalM->mUpdateFrames, 0x14);
    cell = r2d_getRaceGoalMCell(gRaceGoalM->mRankIndex);
    rankPosition[0] = 0x18000;
    rankPosition[1] = (offsetY + 0xa8) << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, rankPosition, 0, 1);

    cell = r2d_getRaceGoalMCell(gRaceGoalM->mPointsGained + 8);
    pointsPosition[0] = 0x48000;
    pointsPosition[1] = (offsetY + 0xb0) << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, pointsPosition, 0, 1);

    cell = r2d_getRaceGoalMCell(r2d_shouldUsePointsPlural(gRaceGoalM->mPointsGained) != FALSE ? 0x13 : 0x14);
    cell13Or14Position[0] = 0x48000;
    cell13Or14Position[1] = (offsetY + 0xb0) << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, cell13Or14Position, 0, 1);

    cell = r2d_getRaceGoalMCell(0x40);
    cell40Position[0] = 0xda000;
    cell40Position[1] = (offsetY + 0xa6) << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, cell40Position, 0, 1);

    cell = r2d_getRaceGoalMCell(0x41);
    cell41Position[0] = 0xda000;
    cell41Position[1] = (offsetY + 0xa6) << 12;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, cell41Position, 0, 1);
}

void DrawRaceGoalMMissionRun(RaceHudOamBuffer *oamBuffer) {
    s32 n;
    s32 offsetY;
    s32 oamIndex;
    s32 cellIndex;
    s32 blinkFrame;
    s32 position[2];
    void *cell;

    n = gRaceGoalM->mUpdateFrames;
    offsetY = mutil_interpolate(1, -0x80, 0, n, 0x14);
    if (gRaceGoalM->field14 != 9 && gRaceGoalM->field18 > gRaceGoalM->field14 && n >= 0x1e) {
        blinkFrame = n - 10;
        if (blinkFrame < 0x54) {
            n = blinkFrame % 12;
            if (n >= 8) {
                return;
            }
        }
    }
    switch (gRaceGoalM->field18) {
        case 0:
            cellIndex = 7;
            break;
        case 1:
            cellIndex = 6;
            break;
        case 2:
            cellIndex = 5;
            break;
        case 3:
            cellIndex = 4;
            break;
        case 4:
            cellIndex = 3;
            break;
        case 5:
            cellIndex = 2;
            break;
        case 6:
            cellIndex = 1;
            break;
        case 7:
            cellIndex = 0;
            break;
    }
    if (gRaceGoalM->field18 >= 8) {
        return;
    }
    cell = r2d_getRaceGoalMrMCell(cellIndex);
    position[0] = (offsetY + 0x80) << 12;
    position[1] = 0x60000;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, position, 0, 1);
}

void InitRaceLinkLevel(void) {
    gRaceLinkLevel = heap_alloc(proc_getHeap(proc_getCurrent()), 0x14);
    gRaceLinkLevel->field0 = 0;
    gRaceLinkLevel->field4 = 0;
    gRaceLinkLevel->field8 = 0;
    gRaceLinkLevel->fieldC = 0;
    gRaceLinkLevel->field10 = 0;
}

u32 ClearRaceLinkLevelPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceLinkLevel;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void UpdateRaceLinkLevel(void) {
    if (gRaceLinkLevel == NULL) {
        return;
    }
    if (gSystemData->field20 == 0) {
        return;
    }
    if (gRaceMultiConfig->mMode == 5) {
        gRaceLinkLevel->field4 = func_021205e8();
        gRaceLinkLevel->fieldC = gRaceLinkLevel->field10;
        gRaceLinkLevel->field10 = func_0212a8d0();
        if (gRaceLinkLevel->field10 != 0 && gRaceLinkLevel->fieldC == 0) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x26);
        }
        if (gRaceLinkLevel->field10 != 0) {
            gRaceLinkLevel->field8++;
            if (gRaceLinkLevel->field8 >= 0x78) {
                gRaceLinkLevel->field8 = 0;
            }
        } else {
            gRaceLinkLevel->field8 = 0;
            gRaceLinkLevel->fieldC = 0;
            gRaceLinkLevel->field10 = 0;
        }
    } else {
        gRaceLinkLevel->field0 = gStruct217AA00->field4 == 0 ? 0 : WM_GetLinkLevel();
    }
}

void DrawRaceLinkLevel(RaceHudOamBuffer *oamBuffer) {
    void *levelCell = NULL;
    void *extraCell = NULL;

    if (gRaceLinkLevel == NULL) {
        return;
    }
    if (gSystemData->field20 != 0) {
        if (func_020b1d20() == 0) {
            if (gRaceMultiConfig->mMode == 5) {
                levelCell = r2d_getRaceMCell(gRaceLinkLevel->field4 + 0x28);
            } else {
                levelCell = r2d_getRaceMCell(gRaceLinkLevel->field0 + 0x28);
            }
        } else {
            if (gRaceMultiConfig->mMode == 5) {
                levelCell = r2d_getRaceGoalMCell(gRaceLinkLevel->field4 + 0x3c);
            } else {
                levelCell = r2d_getRaceGoalMCell(gRaceLinkLevel->field0 + 0x3c);
            }
        }
        if (gRaceMultiConfig->mMode == 5 && gRaceLinkLevel->field10 != 0 && gRaceLinkLevel->field8 < 0x69) {
            if (func_020b1d20() != 0) {
                extraCell = r2d_getRaceGoalMCell(0x42);
            } else {
                extraCell = r2d_getRaceMCell(0x2c);
            }
        }
    }
    if (levelCell != NULL) {
        s32 firstPosition[2];
        s32 secondPosition[2];
        s32 oamIndex;
        RaceHudOamBits *oam;

        oamIndex = oamBuffer->mOamCount;
        firstPosition[0] = 0xf8000;
        firstPosition[1] = 0xb8000;
        oam = &oamBuffer->mOamBits[oamIndex];
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, levelCell, NULL, firstPosition, 0, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
            oam->fieldA = 2;
            oam->fieldE = 1;
        }
        secondPosition[0] = 0xf8000;
        secondPosition[1] = 0xb8000;
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, levelCell, NULL, secondPosition, 0, 1);
    }
    if (extraCell != NULL) {
        s32 firstPosition[2];
        s32 secondPosition[2];
        s32 oamIndex;
        RaceHudOamBits *oam;

        oamIndex = oamBuffer->mOamCount;
        firstPosition[0] = 0xf8000;
        firstPosition[1] = 0xa7000;
        oam = &oamBuffer->mOamBits[oamIndex];
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, extraCell, NULL, firstPosition, 0, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
            oam->fieldA = 2;
            oam->fieldE = 1;
        }
        secondPosition[0] = 0xf8000;
        secondPosition[1] = 0xa7000;
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, extraCell, NULL, secondPosition, 0, 1);
    }
}

void cint_vblank(void) {
    u32 powerBit;
    u32 displayBits;

    DC_FlushRange(&cint_sStatus->mMainOam, 0x400);
    GX_LoadOAM(&cint_sStatus->mMainOam, 0, 0x400);
    powerBit = (reg_GX_POWCNT & 0x8000) >> 15;
    if (powerBit != 0) {
        if (powerBit == 1) {
            displayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((displayBits | 0x10) << 8);
        }
    } else {
        displayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((displayBits & ~0x10) << 8);
    }
}

void cint_init(void) {
    Unk02021dc8 *ncer;
    u8 charCanvas[0x20];
    TextCanvas textCanvas;
    void *r;
    s32 messageIndex;
    s32 i;

    cint_sStatus = heap_alloc(proc_getHeap(proc_getCurrent()), 0x41c);
    for (i = 0; i < 0x80; i++) {
        RaceHudOamBits *e = &cint_sStatus->mMainOam.mOamBits[i];
        e->fieldA = 3;
    }
    cint_sStatus->mUpdateFrames = 0;
    g2du_unpackPaletteData(&cint_sStatus->mRaceStartGpMONclr, m2d_getSceneArcFile("race_start_gp_m_o.NCLR"));
    g2du_unpackCharacterData(&cint_sStatus->mRaceStartGpMONcgr, m2d_getSceneArcFile("race_start_gp_m_o.NCGR"));
    ncer = NULL;
    g2du_unpackCellBankData(&ncer, m2d_getSceneArcFile("race_start_gp_m.NCER"));
    for (i = 0; i < 3; i++) {
        cint_sStatus->mRaceStartGpMNcerEntries[i] = NNS_G2dGetCellDataByIdx(ncer, (u16) i);
    }
    r = m2d_getFont(2);
    messageIndex = -1;
    NNS_G2dCharCanvasInitForBG(charCanvas, cint_sStatus->mRaceStartGpMONcgr->mData, 0x20, 4, 4);
    textCanvas.mCharCanvas = charCanvas;
    textCanvas.mFont = r;
    textCanvas.mCharSpacing = 1;
    textCanvas.mLineSpacing = 0;
    if (gRaceMultiConfig->mMode == MODE_GRAND_PRIX) {
        messageIndex = mutil2_getCourseNameCommonMsgId(gRaceMultiConfig->mCourseId);
        textCanvas.mCharSpacing = GetLanguageCharSpacing();
    } else if (gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
        messageIndex = (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? gRaceMultiConfig->mMissionTableRow : messageIndex) + 0x55;
        textCanvas.mCharSpacing = RaceStartIsLanguageJa();
    }
    NNSi_G2dTextCanvasDrawText(&textCanvas, 0, 9, 0xe, 0x40a,
                               jn_msg_getMessage(m2d_get2dArcFile("common.bmg"), messageIndex));
    NNSi_G2dTextCanvasDrawText(&textCanvas, 0, 8, 0xe, 0x40a,
                               jn_msg_getMessage(m2d_get2dArcFile("common.bmg"), messageIndex));
    DC_FlushRange(cint_sStatus->mRaceStartGpMONcgr->mData, cint_sStatus->mRaceStartGpMONcgr->mDataSize);
    GX_LoadOBJPltt(cint_sStatus->mRaceStartGpMONclr->mData, 0, cint_sStatus->mRaceStartGpMONclr->mDataSize);
    GX_LoadOBJ(cint_sStatus->mRaceStartGpMONcgr->mData, 0, cint_sStatus->mRaceStartGpMONcgr->mDataSize);
}

u32 cint_finalize(void) {
    u32 address;
    u32 zero;
    address = (u32) &cint_sStatus;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

u16 cint_update(void) {
    u16 *powerControl;
    int *startGp;
    powerControl = ((u16 *) &reg_GX_POWCNT);
    startGp = (s32 *) cint_sStatus;
    *startGp = (*(u32 *) startGp) + 1;
    return *powerControl;
}

const Vec3 gVec3Zero = {0, 0, 0};

void cint_render2d(void) {
    RaceHudOamBuffer *oamBuffer;
    Unk020224e0_c *cell;
    s32 position[2];

    cint_sStatus->mMainOam.mOamCount = 0;
    cell = cint_sStatus->mRaceStartGpMNcerEntries[0];
    oamBuffer = &cint_sStatus->mMainOam;
    position[0] = 0x80000;
    position[1] = 0x60000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, position, 0, 1);
    DC_FlushRange(&cint_sStatus->mMainOam, 0x400);
    MI_DmaFill32(3, &cint_sStatus->mMainOam.mOams[cint_sStatus->mMainOam.mOamCount], 0xc0,
                 (0x80 - cint_sStatus->mMainOam.mOamCount) * 8);
}

void r2d_hideMapPathForDriver(s32 kartIndex) {
    if (gRaceMultiConfig->mMode == MODE_TIME_ATTACK) {
        r2d_sMapPath->mKartVisible[kartIndex] = 0;
    }
}

void r2d_showMapPathForDriver(s32 kartIndex) {
    s32 i;
    s32 j;

    if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
        return;
    }
    for (i = 0; i < 0x28; i++) {
        r2d_sMapPath->mSamples[kartIndex][i].mKind = 0;
    }
    for (j = 0; j < r2d_sMapPath->field790[kartIndex].field0; j++) {
        r2d_sMapPath->field790[kartIndex].field34[j] = 0x28;
    }
    r2d_sMapPath->mKartVisible[kartIndex] = 1;
}

void r2d_initMapPath(void) {
    s32 a;
    s32 j;
    Vec3 position;

    if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
        return;
    }
    r2d_sMapPath = heap_alloc(proc_getHeap(proc_getCurrent()), 0x910);
    r2d_sMapPath->mVisible = 1;
    for (a = 0; a < gRaceMultiConfig->mKartCount; a++) {
        r2d_sMapPath->mKartVisible[a] = 1;
    }
    r2d_sMapPath->mSampleFrames = 0;
    for (a = 0; a < gRaceMultiConfig->mKartCount; a++) {
        u16 angle = (u32) m2d_20B6338(a);
        GetKartPosFromPosSourceCopy(&position, a);
        for (j = 0; j < 0x28; j++) {
            r2d_sMapPath->mSamples[a][j].mPos = position;
            r2d_sMapPath->mSamples[a][j].mAngle = angle;
            r2d_sMapPath->mSamples[a][j].mKind = 0;
            r2d_sMapPath->mSamples[a][j].field14 = 3;
        }
    }
    a = 0;
    if (a < gRaceMultiConfig->mKartCount) {
        Vec3 zeroVector = gVec3Zero;
        do {
            r2d_sMapPath->field790[a].field0 = 0;
            for (j = 0; j < 3; j++) {
                r2d_sMapPath->field790[a].field4[j] = zeroVector;
                r2d_sMapPath->field790[a].field34[j] = -1;
                r2d_sMapPath->field790[a].field28[j] = 3;
            }
            a++;
        } while (a < gRaceMultiConfig->mKartCount);
    }
    for (a = 0; a < 16; a++) {
        s32 pairFirst = FX_SinCosTable_[((u16) (a * 0x10000 / 16) >> 4) * 2];
        s32 pairSecond = FX_SinCosTable_[((u16) (a * 0x10000 / 16) >> 4) * 2 + 1];
        r2d_sMapPath->mRotations[a].field0 = pairSecond;
        r2d_sMapPath->mRotations[a].field4 = pairFirst;
        r2d_sMapPath->mRotations[a].field8 = -pairFirst;
        r2d_sMapPath->mRotations[a].fieldC = pairSecond;
    }
}

u32 r2d_finalizeMapPath(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &r2d_sMapPath;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void r2d_updateMapPath(void) {
    Kart *kart;
    RaceTaPositions *positions;
    u16 j;
    s32 count;
    u32 i;

    if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (IsRaceStartSequenceDone() == 0) {
        return;
    }
    if ((u16) (gInputUnits[input_getDirectInputUnitId()].mPressedBits & 4) != 0) {
        r2d_sMapPath->mVisible = r2d_sMapPath->mVisible == 0 ? 1 : 0;
    }
    for (i = 0; i < gRaceMultiConfig->mKartCount; i = (u16) (i + 1)) {
        if ((it_sDriverItemStatus)[i].mKinokoBoostStarted != FALSE) {
            count = r2d_sMapPath->field790[i].field0;
            r2d_sMapPath->field790[i].field0 = count + 1;
            ((void (*)(Vec3 *, s32)) GetKartPosFromPosSourceCopy)(&r2d_sMapPath->field790[i].field4[count], i);
            r2d_sMapPath->field790[i].field28[count] =
                m2d_isPointOnLowerMap(&r2d_sMapPath->field790[i].field4[count]) != 0 ? 2 : 3;
        }
    }
    r2d_sMapPath->mSampleFrames++;
    if (r2d_sMapPath->mSampleFrames > 0xf) {
        r2d_sMapPath->mSampleFrames = 0;
        for (i = 0; i < gRaceMultiConfig->mKartCount; i = (u16) (i + 1)) {
            for (j = 0; j < r2d_sMapPath->field790[i].field0; j = j + 1) {
                if (r2d_sMapPath->field790[i].field34[j] < 0x28) {
                    r2d_sMapPath->field790[i].field34[j]++;
                }
            }
        }
        GetRaceHudSubScreenCourseScale();
        GetRaceHudSubScreenCourseScale();
        for (i = 0; i < gRaceMultiConfig->mKartCount; i = (u16) (i + 1)) {
            kart = driver_getById(i);
            positions = r2d_sMapPath;
            for (j = 0x27; j != 0; j--) {
                positions->mSamples[i][j] = positions->mSamples[i][j - 1];
            }
            GetKartPosFromPosSourceCopy(&r2d_sMapPath->mSamples[i][0].mPos, i);
            r2d_sMapPath->mSamples[i][0].field14 =
                m2d_isPointOnLowerMap(&r2d_sMapPath->mSamples[i][0].mPos) != 0 ? 2 : 3;
            r2d_sMapPath->mSamples[i][0].mAngle = m2d_20B6338(i);
            if ((kart->field44 & 0xa) != 0) {
                r2d_sMapPath->mSamples[i][0].mKind = 2;
            } else if ((kart->field48 & 0x80020) != 0) {
                r2d_sMapPath->mSamples[i][0].mKind = 3;
            } else {
                r2d_sMapPath->mSamples[i][0].mKind = 1;
            }
            if (gRaceStatus->mRaceDone != 0) {
                r2d_sMapPath->mSamples[i][0].mKind = 0;
                r2d_sMapPath->mKartVisible[i] = 0;
            }
        }
    }
}

void r2d_renderMapPath(RaceHudOamBuffer *oamBuffer) {
    UnkPair020b502c trailPosition;
    UnkPair020b502c samplePosition;
    s32 trailCellPosition[2];
    s32 sampleCellPosition[2];
    u16 firstRotationSlot;
    void *sampleCell;
    float f;
    s32 v;
    s32 s;
    s32 i;
    s32 j;
    u32 m;
    s32 trailOamIndex;
    RaceHudOamBits *trailOam;
    void *trailCell;
    u32 h;
    s32 sampleOamIndex;
    RaceHudOamBits *sampleOam;

    if (gRaceMultiConfig->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (r2d_sMapPath->mVisible == 0) {
        return;
    }
    firstRotationSlot = oam_getAffineId(oamBuffer);
    for (i = 1; i < 16; i++) {
        oam_getAffineId(oamBuffer);
    }
    if ((GetRaceHudSubScreenCourseScale() * 3) > 0) {
        f = (GetRaceHudSubScreenCourseScale() * 0x3000) + 0.5f;
    } else {
        f = (GetRaceHudSubScreenCourseScale() * 0x3000) - 0.5f;
    }
    v = f;
    s = ((s64) v * 20) >> 12;
    for (i = 0; i < gRaceMultiConfig->mKartCount; i++) {
        if (r2d_sMapPath->mKartVisible[i] != 0) {
            if (gRaceStatus->mRaceDone == 0) {
                for (j = 0; j < r2d_sMapPath->field790[i].field0; j++) {
                    if (r2d_sMapPath->field790[i].field34[j] < 0x28) {
                        if (lmap_20B5AE8(&r2d_sMapPath->field790[i].field4[j], &trailPosition,
                                                            s, 1, 1) != FALSE) {
                            m = r2d_sMapPath->field790[i].field28[j];
                            trailCell = r2d_getRaceSCell(0x4f);
                            trailOamIndex = oamBuffer->mOamCount;
                            trailCellPosition[0] = trailPosition.field0 << 12;
                            trailCellPosition[1] = trailPosition.field4 << 12;
                            trailOam = &oamBuffer->mOamBits[trailOamIndex];
                            oamBuffer->mOamCount += NNS_G2dMakeCellToOams((GXOamAttr *) trailOam, 0x80 - trailOamIndex,
                                                                          trailCell, NULL, trailCellPosition, 0, 1);
                            for (; trailOamIndex < oamBuffer->mOamCount; trailOamIndex++, trailOam++) {
                                if (m != -1) {
                                    trailOam->fieldE = m;
                                }
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 0x28; j++) {
                u16 angle =
                    (u16) (r2d_sMapPath->mSamples[i][j].mAngle + m2d_20B6368()) + 0x800;
                u16 rotationIndex = ((angle << 4) / 0x10000) % 16;
                if (lmap_20B5AE8(&r2d_sMapPath->mSamples[i][j].mPos, &samplePosition, s, 1, 1) !=
                    FALSE) {
                    switch (r2d_sMapPath->mSamples[i][j].mKind) {
                        case 0:
                            sampleCell = NULL;
                            break;
                        case 1:
                            sampleCell = r2d_getRaceSCell(0x51);
                            break;
                        case 2:
                            sampleCell = r2d_getRaceSCell(0x52);
                            break;
                        case 3:
                            sampleCell = r2d_getRaceSCell(0x53);
                            break;
                    }
                    if (sampleCell != NULL) {
                        h = r2d_sMapPath->mSamples[i][j].field14;
                        sampleOamIndex = oamBuffer->mOamCount;
                        sampleCellPosition[0] = samplePosition.field0 << 12;
                        sampleCellPosition[1] = samplePosition.field4 << 12;
                        sampleOam = &oamBuffer->mOamBits[sampleOamIndex];
                        oamBuffer->mOamCount +=
                            NNS_G2dMakeCellToOams((GXOamAttr *) sampleOam, 0x80 - sampleOamIndex, sampleCell,
                                                  &r2d_sMapPath->mRotations[rotationIndex].field0,
                                                  sampleCellPosition, rotationIndex + firstRotationSlot, 1);
                        for (; sampleOamIndex < oamBuffer->mOamCount; sampleOamIndex++, sampleOam++) {
                            if ((i != 0 ? 1 : -1) != -1) {
                                sampleOam->fieldA = i != 0 ? 1 : -1;
                            }
                            if (h != -1) {
                                sampleOam->fieldE = h;
                            }
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 16; i++) {
        Matrix2x2 *rotation = &r2d_sMapPath->mRotations[i];
        (oamBuffer->mMatrices + firstRotationSlot)[i].field6 = rotation->field0 >> 4;
        (oamBuffer->mMatrices + firstRotationSlot)[i].fieldE = rotation->field4 >> 4;
        (oamBuffer->mMatrices + firstRotationSlot)[i].field16 = rotation->field8 >> 4;
        (oamBuffer->mMatrices + firstRotationSlot)[i].field1E = rotation->fieldC >> 4;
    }
}
