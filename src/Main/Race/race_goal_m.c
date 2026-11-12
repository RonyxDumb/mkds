#include "Main/Race/race_goal_m.h"

#include "Main/Graphics/oam.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/code_020b1cf4.h"
#include "Main/Item/item_pool.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Menu/data_02175628.h"
#include "Main/Item/data_027e0000.h"
#include "Main/Race/data_020b837c.h"
#include "g2d_Animation.h"
#include "code_020222ec.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/System/heap.h"
#include "code_0200eddc.h"
#include "os_thread.h"
#include "Main/System/heap_call.h"
#include "code_0214c778.h"
#include "Main/Menu/keyboard_buttons.h"
#include "g2d_CharCanvas.h"
#include "gx_load2d.h"
#include "Main/System/file_in_loaded.h"
#include "g2d_NOB_load.h"
#include "Main/Menu/data_02180728.h"
#include "Main/Graphics/message_index.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Menu/data_0217d068.h"
#include "player.h"
#include "Main/Net/wifi_session.h"
#include "code_02142eac.h"
#include "code_0212df7c.h"
#include "Main/Race/data_020b85dc.h"
#include "Main/Race/cup_records.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/System/low_byte.h"
#include "Main/Kart/code_0207a000.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "registers.h"
#include "code_02147cd8.h"

BOOL IsRaceGoalMReady(void) {
    return (gRaceGoalM->mReady);
}

u32 GetRaceGoalMUpdateFrames(void) {
    return (gRaceGoalM->mUpdateFrames);
}

void InitRaceGoalM(void) {
    gRaceGoalM = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x1c);
    gRaceGoalM->mReady = 1;
    gRaceGoalM->mUpdateFrames = 0;
    gRaceGoalM->mRankIndex = 0;
    gRaceGoalM->mPointsGained = 0;
    gRaceGoalM->mFirstPlaceKartIndex = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (GetMissionRecordValue(gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : -1,
                                  gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1,
                                  &gRaceGoalM->mUnk_14) == 0) {
            gRaceGoalM->mUnk_14 = 9;
        }
    } else {
        gRaceGoalM->mUnk_14 = 9;
    }
    gRaceGoalM->mUnk_18 = 9;
}

void ClearRaceGoalMPointer(void) {
    gRaceGoalM = NULL;
}

void UpdateRaceGoalM(void) {
    u32 kartIndex;
    s32 value;
    u16 scanKartIndex;
    s32 frame;
    u16 followedKartIndex;
    s32 *updateFramesPointer;
    KartCourseResult *record;

    frame = gRaceGoalM->mUpdateFrames;
    followedKartIndex = GetFollowedKartOrEntryIndex();
    if (gRaceProgress->mKarts[followedKartIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED ||
        gRaceProgress->mRaceDone != 0) {
        gRaceGoalM->mReady = 0;
    }
    if (IsRaceHudGoalMEnabled() == 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if ((IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind : 6) != 0 &&
            IsEntryKartNormalOrNotMissionRun() == 0 && frame == 0) {
            return;
        }
    }
    updateFramesPointer = &gRaceGoalM->mUpdateFrames;
    if (*updateFramesPointer < 0x7fffffff) {
        *updateFramesPointer = *updateFramesPointer + 1;
    }
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
            gRaceGoalM->mRankIndex = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            kartIndex = GetLowByte(GetFollowedKartOrEntryIndex());
            value = GetCourseIndexInCup();
            record = &gCupRecords->mKartResults[value][GetLowByte(kartIndex)];
            value = record->mTotalPoints;
            gRaceGoalM->mPointsGained = value - GetKartPreviousTotalPoints(GetFollowedKartOrEntryIndex());
            if (frame > 0x14) {
                gRaceGoalM->mReady = 1;
            }
            break;
        case MODE_TIME_ATTACK:
            if (frame > 0x14) {
                gRaceGoalM->mReady = 1;
            }
            break;
        case MODE_VS:
        case MODE_WIFI:
            gRaceGoalM->mRankIndex = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            for (scanKartIndex = 0; scanKartIndex < (u32) gRaceSetup->mKartCount; scanKartIndex++) {
                if (GetKartRank(scanKartIndex) == 1) {
                    break;
                }
            }
            gRaceGoalM->mFirstPlaceKartIndex = scanKartIndex;
            if (frame > 0x14) {
                gRaceGoalM->mReady = 1;
            }
            break;
        case MODE_MISSION_RUN:
            if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind : 6) {
                gRaceGoalM->mUnk_18 = 9;
            } else {
                gRaceGoalM->mUnk_18 = ComputeMissionRecordValue();
            }
            if ((IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind : 6) == 0) {
                if (frame == 1) {
                    switch (gRaceGoalM->mUnk_18) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            break;
                        case 5:
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1b);
                            break;
                        case 6:
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1c);
                            break;
                        case 7:
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1d);
                            break;
                    }
                } else if (frame > 0x1e) {
                    gRaceGoalM->mReady = 1;
                }
            } else if (frame > 0x4b) {
                gRaceGoalM->mReady = 1;
            }
            break;
        default:
            gRaceGoalM->mReady = 1;
            break;
    }
}

void DrawRaceGoalM(RaceHudOamBuffer *oamBuffer) {
    s32 offsetY;
    s32 oamIndex;
    s32 position[2];
    void *cell;

    if (gRaceSetup->mRaceKind != RACE_KIND_NORMAL) {
        return;
    }
    if (IsRaceHudGoalMEnabled() == 0) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
            DrawRaceGoalMGrandPrix(oamBuffer);
            break;
        case MODE_VS:
        case MODE_WIFI:
            offsetY = InterpolateS16(1, 0x40, 0, gRaceGoalM->mUpdateFrames, 0x14);
            cell = GetRaceGoalMNcerEntry(gRaceGoalM->mRankIndex);
            position[0] = 0x18000;
            position[1] = TO_FIXED12(offsetY + 0xa8);
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
    s32 unusedValue;
    void *cell;

    offsetY = InterpolateS16(1, 0x40, 0, gRaceGoalM->mUpdateFrames, 0x14);
    cell = GetRaceGoalMNcerEntry(gRaceGoalM->mRankIndex);
    rankPosition[0] = 0x18000;
    rankPosition[1] = TO_FIXED12(offsetY + 0xa8);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, rankPosition, 0, 1);

    cell = GetRaceGoalMNcerEntry(gRaceGoalM->mPointsGained + 8);
    pointsPosition[0] = 0x48000;
    pointsPosition[1] = TO_FIXED12(offsetY + 0xb0);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, pointsPosition, 0, 1);

    cell = GetRaceGoalMNcerEntry(IsPointsLabelPlural(gRaceGoalM->mPointsGained) != FALSE ? 0x13 : 0x14);
    cell13Or14Position[0] = 0x48000;
    cell13Or14Position[1] = TO_FIXED12(offsetY + 0xb0);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, cell13Or14Position, 0, 1);

    cell = GetRaceGoalMNcerEntry(0x40);
    cell40Position[0] = 0xda000;
    cell40Position[1] = TO_FIXED12(offsetY + 0xa6);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, cell40Position, 0, 1);

    cell = GetRaceGoalMNcerEntry(0x41);
    cell41Position[0] = 0xda000;
    cell41Position[1] = TO_FIXED12(offsetY + 0xa6);
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, cell41Position, 0, 1);
}

void DrawRaceGoalMMissionRun(RaceHudOamBuffer *oamBuffer) {
    s32 frames;
    s32 offsetY;
    s32 oamIndex;
    s32 cellIndex;
    s32 blinkFrame;
    s32 position[2];
    void *cell;

    frames = gRaceGoalM->mUpdateFrames;
    offsetY = InterpolateS16(1, -0x80, 0, frames, 0x14);
    if (gRaceGoalM->mUnk_14 != 9 && gRaceGoalM->mUnk_18 > gRaceGoalM->mUnk_14 && frames >= 0x1e) {
        blinkFrame = frames - 10;
        if (blinkFrame < 0x54) {
            frames = blinkFrame % 12;
            if (frames >= 8) {
                return;
            }
        }
    }
    switch (gRaceGoalM->mUnk_18) {
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
    if (gRaceGoalM->mUnk_18 >= 8) {
        return;
    }
    cell = GetRaceGoalMrMNcerEntry(cellIndex);
    position[0] = TO_FIXED12(offsetY + 0x80);
    position[1] = 0x60000;
    oamIndex = oamBuffer->mOamCount;
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, position, 0, 1);
}

void InitRaceLinkLevel(void) {
    gRaceLinkLevel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x14);
    gRaceLinkLevel->mLinkLevel = 0;
    gRaceLinkLevel->mWiFiLinkLevel = 0;
    gRaceLinkLevel->mFriendOnFrames = 0;
    gRaceLinkLevel->mPrevFriendOn = 0;
    gRaceLinkLevel->mFriendOn = 0;
}

void ClearRaceLinkLevelPointer(void) {
    gRaceLinkLevel = NULL;
}

void UpdateRaceLinkLevel(void) {
    if (gRaceLinkLevel == NULL) {
        return;
    }
    if (gStartupWork->mConnectionKind == 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_WIFI) {
        gRaceLinkLevel->mWiFiLinkLevel = GetWiFiLinkLevel();
        gRaceLinkLevel->mPrevFriendOn = gRaceLinkLevel->mFriendOn;
        gRaceLinkLevel->mFriendOn = IsLocateFriendOnWithBuddyStatus4();
        if (gRaceLinkLevel->mFriendOn != 0 && gRaceLinkLevel->mPrevFriendOn == 0) {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x26);
        }
        if (gRaceLinkLevel->mFriendOn != 0) {
            gRaceLinkLevel->mFriendOnFrames++;
            if (gRaceLinkLevel->mFriendOnFrames >= 0x78) {
                gRaceLinkLevel->mFriendOnFrames = 0;
            }
        } else {
            gRaceLinkLevel->mFriendOnFrames = 0;
            gRaceLinkLevel->mPrevFriendOn = 0;
            gRaceLinkLevel->mFriendOn = 0;
        }
    } else {
        gRaceLinkLevel->mLinkLevel = gConnectionWork->mState == 0 ? 0 : WM_GetLinkLevel();
    }
}

void DrawRaceLinkLevel(RaceHudOamBuffer *oamBuffer) {
    void *levelCell = NULL;
    void *extraCell = NULL;

    if (gRaceLinkLevel == NULL) {
        return;
    }
    if (gStartupWork->mConnectionKind != 0) {
        if (IsRaceHudGoalMUploaded() == 0) {
            if (gRaceSetup->mMode == MODE_WIFI) {
                levelCell = GetRaceMNcerEntry(gRaceLinkLevel->mWiFiLinkLevel + 0x28);
            } else {
                levelCell = GetRaceMNcerEntry(gRaceLinkLevel->mLinkLevel + 0x28);
            }
        } else {
            if (gRaceSetup->mMode == MODE_WIFI) {
                levelCell = GetRaceGoalMNcerEntry(gRaceLinkLevel->mWiFiLinkLevel + 0x3c);
            } else {
                levelCell = GetRaceGoalMNcerEntry(gRaceLinkLevel->mLinkLevel + 0x3c);
            }
        }
        if (gRaceSetup->mMode == MODE_WIFI && gRaceLinkLevel->mFriendOn != 0 &&
            gRaceLinkLevel->mFriendOnFrames < 0x69) {
            if (IsRaceHudGoalMUploaded() != 0) {
                extraCell = GetRaceGoalMNcerEntry(0x42);
            } else {
                extraCell = GetRaceMNcerEntry(0x2c);
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
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, levelCell, NULL, firstPosition, 0, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
            oam->mUnk_0a = 2;
            oam->mUnk_0e = 1;
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
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, extraCell, NULL, firstPosition, 0, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
            oam->mUnk_0a = 2;
            oam->mUnk_0e = 1;
        }
        secondPosition[0] = 0xf8000;
        secondPosition[1] = 0xa7000;
        oamIndex = oamBuffer->mOamCount;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, extraCell, NULL, secondPosition, 0, 1);
    }
}

void UploadRaceStartGpOam(void) {
    u32 powerBit;
    u32 displayBits;

    DC_FlushRange(&gRaceStartGp->mMainOam, 0x400);
    GX_LoadOAM(&gRaceStartGp->mMainOam, 0, 0x400);
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

void InitRaceStartGp(void) {
    Unk02021dc8 *ncer;
    u8 charCanvas[0x20];
    TextCanvas textCanvas;
    void *font;
    s32 messageIndex;
    s32 index;

    gRaceStartGp = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x41c);
    for (index = 0; index < 0x80; index++) {
        RaceHudOamBits *oamBits = &gRaceStartGp->mMainOam.mOamBits[index];
        oamBits->mUnk_0a = 3;
    }
    gRaceStartGp->mUpdateFrames = 0;
    LoadNclrData(&gRaceStartGp->mRaceStartGpMONclr, FindSceneFileWrapper("race_start_gp_m_o.NCLR"));
    LoadNcgrData2(&gRaceStartGp->mRaceStartGpMONcgr, FindSceneFileWrapper("race_start_gp_m_o.NCGR"));
    ncer = NULL;
    LoadNcerData(&ncer, FindSceneFileWrapper("race_start_gp_m.NCER"));
    for (index = 0; index < 3; index++) {
        gRaceStartGp->mRaceStartGpMNcerEntries[index] = NNS_G2dGetCellDataByIdx(ncer, (u16) index);
    }
    font = GetFontByIndex(2);
    messageIndex = -1;
    NNS_G2dCharCanvasInitForBG(charCanvas, gRaceStartGp->mRaceStartGpMONcgr->mData, 0x20, 4, 4);
    textCanvas.mCharCanvas = charCanvas;
    textCanvas.mFont = font;
    textCanvas.mCharSpacing = 1;
    textCanvas.mLineSpacing = 0;
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        messageIndex = GetCourseMessageIndex(gRaceSetup->mCourseId);
        textCanvas.mCharSpacing = GetLanguageCharSpacing();
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        messageIndex = (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : messageIndex) + 0x55;
        textCanvas.mCharSpacing = RaceStartIsLanguageJa();
    }
    NNSi_G2dTextCanvasDrawText(&textCanvas, 0, 9, 0xe, 0x40a,
                               GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), messageIndex));
    NNSi_G2dTextCanvasDrawText(&textCanvas, 0, 8, 0xe, 0x40a,
                               GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), messageIndex));
    DC_FlushRange(gRaceStartGp->mRaceStartGpMONcgr->mData, gRaceStartGp->mRaceStartGpMONcgr->mDataSize);
    GX_LoadOBJPltt(gRaceStartGp->mRaceStartGpMONclr->mData, 0, gRaceStartGp->mRaceStartGpMONclr->mDataSize);
    GX_LoadOBJ(gRaceStartGp->mRaceStartGpMONcgr->mData, 0, gRaceStartGp->mRaceStartGpMONcgr->mDataSize);
}

void ClearRaceStartGpPointer(void) {
    gRaceStartGp = NULL;
}

u16 UpdateRaceStartGp(void) {
    gRaceStartGp->mUpdateFrames = gRaceStartGp->mUpdateFrames + 1;
    return reg_GX_POWCNT;
}

const Vec3 gVec3Zero = {0, 0, 0};

void DrawRaceStartGp(void) {
    RaceHudOamBuffer *oamBuffer;
    NNSG2dCellDataWithBR *cell;
    s32 position[2];

    gRaceStartGp->mMainOam.mOamCount = 0;
    cell = gRaceStartGp->mRaceStartGpMNcerEntries[0];
    oamBuffer = &gRaceStartGp->mMainOam;
    position[0] = 0x80000;
    position[1] = 0x60000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, position, 0, 1);
    DC_FlushRange(&gRaceStartGp->mMainOam, 0x400);
    MI_DmaFill32(3, &gRaceStartGp->mMainOam.mOams[gRaceStartGp->mMainOam.mOamCount], 0xc0,
                 (0x80 - gRaceStartGp->mMainOam.mOamCount) * 8);
}

void HideRaceTaKartPositions(s32 kartIndex) {
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        gRaceTaPositions->mKartVisible[kartIndex] = 0;
    }
}

void ResetRaceTaKartPositions(s32 kartIndex) {
    s32 sampleIndex;
    s32 pointIndex;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    for (sampleIndex = 0; sampleIndex < 0x28; sampleIndex++) {
        gRaceTaPositions->mSamples[kartIndex][sampleIndex].mKind = 0;
    }
    for (pointIndex = 0; pointIndex < gRaceTaPositions->mKinokoBoostPoints[kartIndex].mPointCount; pointIndex++) {
        gRaceTaPositions->mKinokoBoostPoints[kartIndex].mAgeSamples[pointIndex] = 0x28;
    }
    gRaceTaPositions->mKartVisible[kartIndex] = 1;
}

void InitRaceTaPositions(void) {
    s32 index;
    s32 sampleIndex;
    Vec3 position;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceTaPositions = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x910);
    gRaceTaPositions->mVisible = 1;
    for (index = 0; index < gRaceSetup->mKartCount; index++) {
        gRaceTaPositions->mKartVisible[index] = 1;
    }
    gRaceTaPositions->mSampleFrames = 0;
    for (index = 0; index < gRaceSetup->mKartCount; index++) {
        u16 angle = (u32) GetRaceHudSubScreenKartAngle(index);
        GetKartPosFromPosSourceCopy(&position, index);
        for (sampleIndex = 0; sampleIndex < 0x28; sampleIndex++) {
            gRaceTaPositions->mSamples[index][sampleIndex].mPos = position;
            gRaceTaPositions->mSamples[index][sampleIndex].mAngle = angle;
            gRaceTaPositions->mSamples[index][sampleIndex].mKind = 0;
            gRaceTaPositions->mSamples[index][sampleIndex].mPriority = 3;
        }
    }
    index = 0;
    if (index < gRaceSetup->mKartCount) {
        Vec3 zeroVector = gVec3Zero;
        do {
            gRaceTaPositions->mKinokoBoostPoints[index].mPointCount = 0;
            for (sampleIndex = 0; sampleIndex < 3; sampleIndex++) {
                gRaceTaPositions->mKinokoBoostPoints[index].mPositions[sampleIndex] = zeroVector;
                gRaceTaPositions->mKinokoBoostPoints[index].mAgeSamples[sampleIndex] = -1;
                gRaceTaPositions->mKinokoBoostPoints[index].mPriorities[sampleIndex] = 3;
            }
            index++;
        } while (index < gRaceSetup->mKartCount);
    }
    for (index = 0; index < 16; index++) {
        s32 pairFirst = SIN_OF_ANGLE((u16) (index * 0x10000 / 16));
        s32 pairSecond = COS_OF_ANGLE((u16) (index * 0x10000 / 16));
        gRaceTaPositions->mRotations[index].mUnk_00[0] = pairSecond;
        gRaceTaPositions->mRotations[index].mUnk_00[1] = pairFirst;
        gRaceTaPositions->mRotations[index].mUnk_00[2] = -pairFirst;
        gRaceTaPositions->mRotations[index].mUnk_00[3] = pairSecond;
    }
}

void ClearRaceTaPositionsPointer(void) {
    gRaceTaPositions = NULL;
}

void UpdateRaceTaPositions(void) {
    Kart *kart;
    RaceTaPositions *positions;
    u16 sampleIndex;
    s32 count;
    u32 kartIndex;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (IsRaceStartSequenceDone() == 0) {
        return;
    }
    if ((u16) (gInputSlots[GetPadInputSlot()].mPressedBits & 4) != 0) {
        gRaceTaPositions->mVisible = gRaceTaPositions->mVisible == 0 ? 1 : 0;
    }
    for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
        if ((gKartItems)[kartIndex].mKinokoBoostStarted != FALSE) {
            count = gRaceTaPositions->mKinokoBoostPoints[kartIndex].mPointCount;
            gRaceTaPositions->mKinokoBoostPoints[kartIndex].mPointCount = count + 1;
            ((void (*)(Vec3 *, s32)) GetKartPosFromPosSourceCopy)(
                &gRaceTaPositions->mKinokoBoostPoints[kartIndex].mPositions[count], kartIndex);
            gRaceTaPositions->mKinokoBoostPoints[kartIndex].mPriorities[count] =
                IsPositionOutsideBox(&gRaceTaPositions->mKinokoBoostPoints[kartIndex].mPositions[count]) != 0
                    ? RACE_HUD_PRIORITY_OUTSIDE_BOX
                    : RACE_HUD_PRIORITY_INSIDE_BOX;
        }
    }
    gRaceTaPositions->mSampleFrames++;
    if (gRaceTaPositions->mSampleFrames > 0xf) {
        gRaceTaPositions->mSampleFrames = 0;
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            for (sampleIndex = 0; sampleIndex < gRaceTaPositions->mKinokoBoostPoints[kartIndex].mPointCount;
                 sampleIndex = sampleIndex + 1) {
                if (gRaceTaPositions->mKinokoBoostPoints[kartIndex].mAgeSamples[sampleIndex] < 0x28) {
                    gRaceTaPositions->mKinokoBoostPoints[kartIndex].mAgeSamples[sampleIndex]++;
                }
            }
        }
        GetRaceHudSubScreenCourseScale();
        GetRaceHudSubScreenCourseScale();
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            kart = GetKart(kartIndex);
            positions = gRaceTaPositions;
            for (sampleIndex = 0x27; sampleIndex != 0; sampleIndex--) {
                positions->mSamples[kartIndex][sampleIndex] = positions->mSamples[kartIndex][sampleIndex - 1];
            }
            GetKartPosFromPosSourceCopy(&gRaceTaPositions->mSamples[kartIndex][0].mPos, kartIndex);
            gRaceTaPositions->mSamples[kartIndex][0].mPriority =
                IsPositionOutsideBox(&gRaceTaPositions->mSamples[kartIndex][0].mPos) != 0
                    ? RACE_HUD_PRIORITY_OUTSIDE_BOX
                    : RACE_HUD_PRIORITY_INSIDE_BOX;
            gRaceTaPositions->mSamples[kartIndex][0].mAngle = GetRaceHudSubScreenKartAngle(kartIndex);
            if ((kart->mMotionFlags & (KART_MOTION_HOPPING | KART_MOTION_DRIFTING)) != 0) {
                gRaceTaPositions->mSamples[kartIndex][0].mKind = 2;
            } else if ((kart->mDriveFlags & (KART_DRIVE_BOOST | KART_DRIVE_MINI_TURBO)) != 0) {
                gRaceTaPositions->mSamples[kartIndex][0].mKind = 3;
            } else {
                gRaceTaPositions->mSamples[kartIndex][0].mKind = 1;
            }
            if (gRaceProgress->mRaceDone != 0) {
                gRaceTaPositions->mSamples[kartIndex][0].mKind = 0;
                gRaceTaPositions->mKartVisible[kartIndex] = 0;
            }
        }
    }
}

void DrawRaceTaPositions(RaceHudOamBuffer *oamBuffer) {
    UnkPair020b502c trailPosition;
    UnkPair020b502c samplePosition;
    s32 trailCellPosition[2];
    s32 sampleCellPosition[2];
    u16 firstRotationSlot;
    void *sampleCell;
    float productWithHalf;
    s32 roundedProduct;
    s32 scale;
    s32 index;
    s32 sampleIndex;
    u32 trailPriority;
    s32 trailOamIndex;
    RaceHudOamBits *trailOam;
    void *trailCell;
    u32 priority;
    s32 sampleOamIndex;
    RaceHudOamBits *sampleOam;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceTaPositions->mVisible == 0) {
        return;
    }
    firstRotationSlot = AllocOamMatrixIndex(oamBuffer);
    for (index = 1; index < 16; index++) {
        AllocOamMatrixIndex(oamBuffer);
    }
    if ((GetRaceHudSubScreenCourseScale() * 3) > 0) {
        productWithHalf = (GetRaceHudSubScreenCourseScale() * 0x3000) + 0.5f;
    } else {
        productWithHalf = (GetRaceHudSubScreenCourseScale() * 0x3000) - 0.5f;
    }
    roundedProduct = productWithHalf;
    scale = MUL_FIXED12_NO_ROUND(roundedProduct, 20);
    for (index = 0; index < gRaceSetup->mKartCount; index++) {
        if (gRaceTaPositions->mKartVisible[index] != 0) {
            if (gRaceProgress->mRaceDone == 0) {
                for (sampleIndex = 0; sampleIndex < gRaceTaPositions->mKinokoBoostPoints[index].mPointCount;
                     sampleIndex++) {
                    if (gRaceTaPositions->mKinokoBoostPoints[index].mAgeSamples[sampleIndex] < 0x28) {
                        if (ComputeRaceHudSubScreenPosition(
                                &gRaceTaPositions->mKinokoBoostPoints[index].mPositions[sampleIndex], &trailPosition,
                                scale, 1, 1) != FALSE) {
                            trailPriority = gRaceTaPositions->mKinokoBoostPoints[index].mPriorities[sampleIndex];
                            trailCell = GetRaceSNcerEntry(0x4f);
                            trailOamIndex = oamBuffer->mOamCount;
                            trailCellPosition[0] = TO_FIXED12(trailPosition.mFirst);
                            trailCellPosition[1] = TO_FIXED12(trailPosition.mSecond);
                            trailOam = &oamBuffer->mOamBits[trailOamIndex];
                            oamBuffer->mOamCount +=
                                NNS_G2dMakeCellToOams(&oamBuffer->mOams[trailOamIndex], 0x80 - trailOamIndex, trailCell,
                                                      NULL, trailCellPosition, 0, 1);
                            for (; trailOamIndex < oamBuffer->mOamCount; trailOamIndex++, trailOam++) {
                                if (trailPriority != -1) {
                                    trailOam->mUnk_0e = trailPriority;
                                }
                            }
                        }
                    }
                }
            }
            for (sampleIndex = 0; sampleIndex < 0x28; sampleIndex++) {
                u16 angle = (u16) (gRaceTaPositions->mSamples[index][sampleIndex].mAngle +
                                   GetSubScreenAngleAndClearScrollTimer()) +
                            0x800;
                u16 rotationIndex = ((angle << 4) / 0x10000) % 16;
                if (ComputeRaceHudSubScreenPosition(&gRaceTaPositions->mSamples[index][sampleIndex].mPos,
                                                    &samplePosition, scale, 1, 1) != FALSE) {
                    switch (gRaceTaPositions->mSamples[index][sampleIndex].mKind) {
                        case 0:
                            sampleCell = NULL;
                            break;
                        case 1:
                            sampleCell = GetRaceSNcerEntry(0x51);
                            break;
                        case 2:
                            sampleCell = GetRaceSNcerEntry(0x52);
                            break;
                        case 3:
                            sampleCell = GetRaceSNcerEntry(0x53);
                            break;
                    }
                    if (sampleCell != NULL) {
                        priority = gRaceTaPositions->mSamples[index][sampleIndex].mPriority;
                        sampleOamIndex = oamBuffer->mOamCount;
                        sampleCellPosition[0] = TO_FIXED12(samplePosition.mFirst);
                        sampleCellPosition[1] = TO_FIXED12(samplePosition.mSecond);
                        sampleOam = &oamBuffer->mOamBits[sampleOamIndex];
                        oamBuffer->mOamCount +=
                            NNS_G2dMakeCellToOams(&oamBuffer->mOams[sampleOamIndex], 0x80 - sampleOamIndex, sampleCell,
                                                  &gRaceTaPositions->mRotations[rotationIndex], sampleCellPosition,
                                                  rotationIndex + firstRotationSlot, 1);
                        for (; sampleOamIndex < oamBuffer->mOamCount; sampleOamIndex++, sampleOam++) {
                            if ((index != 0 ? 1 : -1) != -1) {
                                sampleOam->mUnk_0a = index != 0 ? 1 : -1;
                            }
                            if (priority != -1) {
                                sampleOam->mUnk_0e = priority;
                            }
                        }
                    }
                }
            }
        }
    }
    for (index = 0; index < 16; index++) {
        MtxFx22 *rotation = &gRaceTaPositions->mRotations[index];
        (oamBuffer->mMatrices + firstRotationSlot)[index].mPA = rotation->mUnk_00[0] >> 4;
        (oamBuffer->mMatrices + firstRotationSlot)[index].mPB = rotation->mUnk_00[1] >> 4;
        (oamBuffer->mMatrices + firstRotationSlot)[index].mPC = rotation->mUnk_00[2] >> 4;
        (oamBuffer->mMatrices + firstRotationSlot)[index].mPD = rotation->mUnk_00[3] >> 4;
    }
}
