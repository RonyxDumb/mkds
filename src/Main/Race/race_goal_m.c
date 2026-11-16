#include "Main/Race/race_goal_m.h"
#include "Main/Race/race_end_condition.h"

#include "Main/Graphics/oam.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_accessors.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/input_slots.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "cell_animation.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/System/heap.h"
#include "arena_cache_init.h"
#include "thread_scheduler.h"
#include "Main/System/heap_call.h"
#include "dma_copy_fill_wait.h"
#include "Main/Menu/keyboard_buttons.h"
#include "char_canvas_text_draw.h"
#include "vram_load_2d_graphics.h"
#include "Main/System/file_in_loaded.h"
#include "cell_data_unpack.h"
#include "Main/Graphics/text_canvas.h"
#include "Main/Graphics/message_index.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/backup_net_camera_work.h"
#include "sound_player_control.h"
#include "Main/Net/wifi_session.h"
#include "wireless_link_control.h"
#include "sound_archive_load_result.h"
#include "Main/Race/race_m_ncer_entry.h"
#include "Main/Race/cup_records.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/System/low_byte.h"
#include "Main/Kart/shadow_model_draw.h"
#include "Main/Save/buddy_record_time.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "registers.h"
#include "fixed_vector_math.h"
#include "Main/Sound/sound_system.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const Vec3 gVec3Zero = {0, 0, 0};
struct RaceTaPositions *gRaceTaPositions;
struct RaceGoalM *gRaceGoalM;
struct RaceStartGp *gRaceStartGp;
struct RaceLinkLevel *gRaceLinkLevel;

BOOL IsRaceGoalMReady(void) {
    return (gRaceGoalM->mReady);
}

u32 GetRaceGoalMUpdateFrames(void) {
    return (gRaceGoalM->mUpdateFrames);
}

void InitRaceGoalM(void) {
    gRaceGoalM = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceGoalM));
    gRaceGoalM->mReady = 1;
    gRaceGoalM->mUpdateFrames = 0;
    gRaceGoalM->mRankIndex = 0;
    gRaceGoalM->mPointsGained = 0;
    gRaceGoalM->mFirstPlaceKartIndex = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (GetMissionRecordValue(gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : -1,
                                  gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1,
                                  &gRaceGoalM->mMissionRecordValue) == 0) {
            gRaceGoalM->mMissionRecordValue = MISSION_RECORD_VALUE_NONE;
        }
    } else {
        gRaceGoalM->mMissionRecordValue = MISSION_RECORD_VALUE_NONE;
    }
    gRaceGoalM->mComputedMissionRecordValue = MISSION_RECORD_VALUE_NONE;
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
        if ((IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind
                                                             : RACE_END_KIND_NOT_ENDED) != 0 &&
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
            if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind
                                                                : RACE_END_KIND_NOT_ENDED) {
                gRaceGoalM->mComputedMissionRecordValue = MISSION_RECORD_VALUE_NONE;
            } else {
                gRaceGoalM->mComputedMissionRecordValue = ComputeMissionRecordValue();
            }
            if ((IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind
                                                                 : RACE_END_KIND_NOT_ENDED) == 0) {
                if (frame == 1) {
                    switch (gRaceGoalM->mComputedMissionRecordValue) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            break;
                        case MISSION_RECORD_VALUE_THIRD_BEST:
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1b);
                            break;
                        case MISSION_RECORD_VALUE_SECOND_BEST:
                            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1c);
                            break;
                        case MISSION_RECORD_VALUE_BEST:
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
    if (gRaceGoalM->mMissionRecordValue != MISSION_RECORD_VALUE_NONE &&
        gRaceGoalM->mComputedMissionRecordValue > gRaceGoalM->mMissionRecordValue && frames >= 0x1e) {
        blinkFrame = frames - 10;
        if (blinkFrame < 0x54) {
            frames = blinkFrame % 12;
            if (frames >= 8) {
                return;
            }
        }
    }
    switch (gRaceGoalM->mComputedMissionRecordValue) {
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
        case MISSION_RECORD_VALUE_THIRD_BEST:
            cellIndex = 2;
            break;
        case MISSION_RECORD_VALUE_SECOND_BEST:
            cellIndex = 1;
            break;
        case MISSION_RECORD_VALUE_BEST:
            cellIndex = 0;
            break;
    }
    if (gRaceGoalM->mComputedMissionRecordValue >= MISSION_RECORD_VALUE_COUNT) {
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
    gRaceLinkLevel = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceLinkLevel));
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
    if (gStartupWork->mConnectionKind == CONNECTION_KIND_NONE) {
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
            if (gRaceLinkLevel->mFriendOnFrames >= RACE_LINK_FRIEND_ON_CYCLE_FRAMES) {
                gRaceLinkLevel->mFriendOnFrames = 0;
            }
        } else {
            gRaceLinkLevel->mFriendOnFrames = 0;
            gRaceLinkLevel->mPrevFriendOn = 0;
            gRaceLinkLevel->mFriendOn = 0;
        }
    } else {
        gRaceLinkLevel->mLinkLevel = gConnectionWork->mState == CONNECTION_STATE_IDLE ? 0 : WM_GetLinkLevel();
    }
}

void DrawRaceLinkLevel(RaceHudOamBuffer *oamBuffer) {
    void *levelCell = NULL;
    void *extraCell = NULL;

    if (gRaceLinkLevel == NULL) {
        return;
    }
    if (gStartupWork->mConnectionKind != CONNECTION_KIND_NONE) {
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
            gRaceLinkLevel->mFriendOnFrames < RACE_LINK_FRIEND_ON_SHOWN_FRAMES) {
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
            oam->mObjMode = RACE_HUD_OBJ_MODE_WINDOW;
            oam->mPriority = 1;
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
            oam->mObjMode = RACE_HUD_OBJ_MODE_WINDOW;
            oam->mPriority = 1;
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
            displayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((displayBits | 0x10) << 8);
        }
    } else {
        displayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((displayBits & ~0x10) << 8);
    }
}

void InitRaceStartGp(void) {
    NNSG2dCellDataBank *ncer;
    u8 charCanvas[0x20];
    TextCanvas textCanvas;
    void *font;
    s32 messageIndex;
    s32 index;

    gRaceStartGp = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceStartGp));
    for (index = 0; index < 0x80; index++) {
        RaceHudOamBits *oamBits = &gRaceStartGp->mMainOam.mOamBits[index];
        oamBits->mObjMode = RACE_HUD_OBJ_MODE_BITMAP;
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
    for (sampleIndex = 0; sampleIndex < RACE_TA_SAMPLE_COUNT; sampleIndex++) {
        gRaceTaPositions->mSamples[kartIndex][sampleIndex].mKind = RACE_TA_SAMPLE_KIND_NONE;
    }
    for (pointIndex = 0; pointIndex < gRaceTaPositions->mKinokoBoostPoints[kartIndex].mPointCount; pointIndex++) {
        gRaceTaPositions->mKinokoBoostPoints[kartIndex].mAgeSamples[pointIndex] = RACE_TA_SAMPLE_COUNT;
    }
    gRaceTaPositions->mKartVisible[kartIndex] = 1;
}

void InitRaceTaPositions(void) {
    s32 index;
    s32 j;
    Vec3 position;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceTaPositions = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gRaceTaPositions));
    gRaceTaPositions->mVisible = 1;
    for (index = 0; index < gRaceSetup->mKartCount; index++) {
        gRaceTaPositions->mKartVisible[index] = 1;
    }
    gRaceTaPositions->mSampleFrames = 0;
    for (index = 0; index < gRaceSetup->mKartCount; index++) {
        u16 angle = (u32) GetRaceHudSubScreenKartAngle(index);
        GetKartPosFromPosSourceCopy(&position, index);
        for (j = 0; j < RACE_TA_SAMPLE_COUNT; j++) {
            gRaceTaPositions->mSamples[index][j].mPos = position;
            gRaceTaPositions->mSamples[index][j].mAngle = angle;
            gRaceTaPositions->mSamples[index][j].mKind = RACE_TA_SAMPLE_KIND_NONE;
            gRaceTaPositions->mSamples[index][j].mPriority = RACE_HUD_PRIORITY_BACK;
        }
    }
    index = 0;
    if (index < gRaceSetup->mKartCount) {
        Vec3 zeroVector = gVec3Zero;
        do {
            gRaceTaPositions->mKinokoBoostPoints[index].mPointCount = 0;
            for (j = 0; j < 3; j++) {
                gRaceTaPositions->mKinokoBoostPoints[index].mPositions[j] = zeroVector;
                gRaceTaPositions->mKinokoBoostPoints[index].mAgeSamples[j] = -1;
                gRaceTaPositions->mKinokoBoostPoints[index].mPriorities[j] = RACE_HUD_PRIORITY_BACK;
            }
            index++;
        } while (index < gRaceSetup->mKartCount);
    }
    for (index = 0; index < 16; index++) {
        s32 pairFirst = SIN_OF_ANGLE((u16) (index * 0x10000 / 16));
        s32 pairSecond = COS_OF_ANGLE((u16) (index * 0x10000 / 16));
        gRaceTaPositions->mRotations[index].mElements[0] = pairSecond;
        gRaceTaPositions->mRotations[index].mElements[1] = pairFirst;
        gRaceTaPositions->mRotations[index].mElements[2] = -pairFirst;
        gRaceTaPositions->mRotations[index].mElements[3] = pairSecond;
    }
}

void ClearRaceTaPositionsPointer(void) {
    gRaceTaPositions = NULL;
}

void UpdateRaceTaPositions(void) {
    Kart *kart;
    RaceTaPositions *positions;
    u16 j;
    s32 count;
    u32 kartIndex;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (IsRaceStartSequenceDone() == 0) {
        return;
    }
    if ((u16) (gInputSlots[GetPadInputSlot()].mPressedBits & PAD_KEY_SELECT) != 0) {
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
                    ? RACE_HUD_PRIORITY_MIDDLE
                    : RACE_HUD_PRIORITY_BACK;
        }
    }
    gRaceTaPositions->mSampleFrames++;
    if (gRaceTaPositions->mSampleFrames > RACE_TA_AGE_INTERVAL_FRAMES) {
        gRaceTaPositions->mSampleFrames = 0;
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            for (j = 0; j < gRaceTaPositions->mKinokoBoostPoints[kartIndex].mPointCount;
                 j = j + 1) {
                if (gRaceTaPositions->mKinokoBoostPoints[kartIndex].mAgeSamples[j] < RACE_TA_SAMPLE_COUNT) {
                    gRaceTaPositions->mKinokoBoostPoints[kartIndex].mAgeSamples[j]++;
                }
            }
        }
        GetRaceHudSubScreenCourseScale();
        GetRaceHudSubScreenCourseScale();
        for (kartIndex = 0; kartIndex < gRaceSetup->mKartCount; kartIndex = (u16) (kartIndex + 1)) {
            kart = GetKart(kartIndex);
            positions = gRaceTaPositions;
            for (j = 0x27; j != 0; j--) {
                positions->mSamples[kartIndex][j] = positions->mSamples[kartIndex][j - 1];
            }
            GetKartPosFromPosSourceCopy(&gRaceTaPositions->mSamples[kartIndex][0].mPos, kartIndex);
            gRaceTaPositions->mSamples[kartIndex][0].mPriority =
                IsPositionOutsideBox(&gRaceTaPositions->mSamples[kartIndex][0].mPos) != 0 ? RACE_HUD_PRIORITY_MIDDLE
                                                                                          : RACE_HUD_PRIORITY_BACK;
            gRaceTaPositions->mSamples[kartIndex][0].mAngle = GetRaceHudSubScreenKartAngle(kartIndex);
            if ((kart->mMotionFlags & (KART_MOTION_HOPPING | KART_MOTION_DRIFTING)) != 0) {
                gRaceTaPositions->mSamples[kartIndex][0].mKind = RACE_TA_SAMPLE_KIND_HOPPING_OR_DRIFTING;
            } else if ((kart->mDriveFlags & (KART_DRIVE_BOOST | KART_DRIVE_MINI_TURBO)) != 0) {
                gRaceTaPositions->mSamples[kartIndex][0].mKind = RACE_TA_SAMPLE_KIND_BOOSTING;
            } else {
                gRaceTaPositions->mSamples[kartIndex][0].mKind = RACE_TA_SAMPLE_KIND_PLAIN;
            }
            if (gRaceProgress->mRaceDone != 0) {
                gRaceTaPositions->mSamples[kartIndex][0].mKind = RACE_TA_SAMPLE_KIND_NONE;
                gRaceTaPositions->mKartVisible[kartIndex] = 0;
            }
        }
    }
}

void DrawRaceTaPositions(RaceHudOamBuffer *oamBuffer) {
    IntPair trailPosition;
    IntPair samplePosition;
    s32 trailCellPosition[2];
    s32 sampleCellPosition[2];
    u16 firstRotationSlot;
    void *sampleCell;
    float productWithHalf;
    s32 roundedProduct;
    s32 scale;
    s32 index;
    s32 j;
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
                for (j = 0; j < gRaceTaPositions->mKinokoBoostPoints[index].mPointCount;
                     j++) {
                    if (gRaceTaPositions->mKinokoBoostPoints[index].mAgeSamples[j] < RACE_TA_SAMPLE_COUNT) {
                        if (ComputeRaceHudSubScreenPosition(
                                &gRaceTaPositions->mKinokoBoostPoints[index].mPositions[j], &trailPosition,
                                scale, 1, 1) != FALSE) {
                            trailPriority = gRaceTaPositions->mKinokoBoostPoints[index].mPriorities[j];
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
                                    trailOam->mPriority = trailPriority;
                                }
                            }
                        }
                    }
                }
            }
            for (j = 0; j < RACE_TA_SAMPLE_COUNT; j++) {
                u16 angle = (u16) (gRaceTaPositions->mSamples[index][j].mAngle +
                                   GetSubScreenAngleAndClearScrollTimer()) +
                            0x800;
                u16 rotationIndex = ((angle << 4) / 0x10000) % 16;
                if (ComputeRaceHudSubScreenPosition(&gRaceTaPositions->mSamples[index][j].mPos,
                                                    &samplePosition, scale, 1, 1) != FALSE) {
                    switch (gRaceTaPositions->mSamples[index][j].mKind) {
                        case RACE_TA_SAMPLE_KIND_NONE:
                            sampleCell = NULL;
                            break;
                        case RACE_TA_SAMPLE_KIND_PLAIN:
                            sampleCell = GetRaceSNcerEntry(0x51);
                            break;
                        case RACE_TA_SAMPLE_KIND_HOPPING_OR_DRIFTING:
                            sampleCell = GetRaceSNcerEntry(0x52);
                            break;
                        case RACE_TA_SAMPLE_KIND_BOOSTING:
                            sampleCell = GetRaceSNcerEntry(0x53);
                            break;
                    }
                    if (sampleCell != NULL) {
                        priority = gRaceTaPositions->mSamples[index][j].mPriority;
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
                                sampleOam->mObjMode = index != 0 ? RACE_HUD_OBJ_MODE_TRANSLUCENT : -1;
                            }
                            if (priority != -1) {
                                sampleOam->mPriority = priority;
                            }
                        }
                    }
                }
            }
        }
    }
    for (index = 0; index < 16; index++) {
        MtxFx22 *rotation = &gRaceTaPositions->mRotations[index];
        (oamBuffer->mMatrices + firstRotationSlot)[index].mPA = rotation->mElements[0] >> 4;
        (oamBuffer->mMatrices + firstRotationSlot)[index].mPB = rotation->mElements[1] >> 4;
        (oamBuffer->mMatrices + firstRotationSlot)[index].mPC = rotation->mElements[2] >> 4;
        (oamBuffer->mMatrices + firstRotationSlot)[index].mPD = rotation->mElements[3] >> 4;
    }
}
