#include "Main/Race/race_item_slot.h"

#include "Main/System/wvr_state.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/key_recording.h"
#include "Main/Race/standings_balloons.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "g2d_Animation.h"
#include "Main/Race/race_m_ncer_entry.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "01/Race/mission_run_state.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/input_slots.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "cell_animation.h"
#include "Main/System/heap.h"
#include "Main/Item/item_pool.h"
#include "Main/Race/race_m_ncer_index.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/System/heap_call.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_type.h"
#include "stream.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Race/race_ncer_tables.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "sound_archive_load_result.h"
#include "vector_math.h"
#include "Main/Race/kart.h"
#include "Main/Race/race_clock.h"
#include "Main/System/init_after_startup.h"

RaceItemSlot *gRaceItemSlot;
RaceModeCount *gRaceModeCount;

void InitRaceItemSlot(void) {
    RaceItemSlot *itemSlot;

    itemSlot = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(RaceItemSlot));
    gRaceItemSlot = itemSlot;
    itemSlot->mScrollY = 0;
    gRaceItemSlot->mSlotFrames = 0;
    gRaceItemSlot->mUpperItem = ITEM_INFO_NONE;
    gRaceItemSlot->mLowerItem = ITEM_INFO_NONE;
    gRaceItemSlot->mSlotRunning = FALSE;
    gRaceItemSlot->mPrevSlotRunning = FALSE;
    gRaceItemSlot->mScale.mScaleFrames = 0;
    gRaceItemSlot->mScale.mScaleX = RACE_ITEM_SLOT_SCALE_NORMAL;
    gRaceItemSlot->mScale.mScaleY = RACE_ITEM_SLOT_SCALE_NORMAL;
    gRaceItemSlot->mScale.mScaleYPerFrame = RACE_ITEM_SLOT_SCALE_START_STEP;
    gRaceItemSlot->mScale.mScaleYTarget = RACE_ITEM_SLOT_SCALE_START_TARGET;
}

void ClearRaceItemSlotPointer(void) {
    gRaceItemSlot = NULL;
}

static inline KartItems *GetKartItemsAtOffset(u32 offset) {
    return (KartItems *) ((u32) gKartItems + offset);
}

void UpdateRaceItemSlot(void) {
    s32 finalScrollFrameCount;
    u32 kartOffset;
    s32 slotFrames;
    s32 upperItem;
    s32 scrollY;
    u32 endSeqNo;
    NNSSndSeqPlayer **entryHandle;
    NNSSndSeqPlayer **sndHandle;
    u32 startSeqNo;
    RaceItemSlotScale *scale;
    KartItems *kartItems;

    slotFrames = gRaceItemSlot->mSlotFrames;
    kartOffset = GetFollowedKartOrEntryIndex() * 0x210;
    finalScrollFrameCount = GetKartItemsAtOffset(kartOffset)->mSlotFinalScrollFrameCount;
    gRaceItemSlot->mPrevSlotRunning = gRaceItemSlot->mSlotRunning;
    upperItem = ITEM_INFO_NONE;
    kartItems = GetKartItemsAtOffset(kartOffset);
    if (kartItems->mSlotState == KART_ITEMS_SLOT_SPINNING) {
        gRaceItemSlot->mSlotFrames = kartItems->mSlotFrames;
        slotFrames = gRaceItemSlot->mSlotFrames;
        gRaceItemSlot->mSlotRunning = TRUE;
    } else if (slotFrames == 0) {
        gRaceItemSlot->mSlotRunning = FALSE;
    } else if (slotFrames > 0 && slotFrames < RACE_ITEM_SLOT_FINAL_SCROLL_START_FRAME) {
        gRaceItemSlot->mSlotFrames += 1;
        slotFrames = gRaceItemSlot->mSlotFrames;
        switch (slotFrames) {
            RACE_ITEM_SLOT_CHANGE_FRAME_CASES
            gRaceItemSlot->mSlotFrames = RACE_ITEM_SLOT_FINAL_SCROLL_START_FRAME;
            slotFrames = gRaceItemSlot->mSlotFrames;
            break;
        }
        gRaceItemSlot->mSlotRunning = TRUE;
    } else if (slotFrames >= RACE_ITEM_SLOT_FINAL_SCROLL_START_FRAME &&
               slotFrames < finalScrollFrameCount + RACE_ITEM_SLOT_FINAL_SCROLL_START_FRAME - 1) {
        gRaceItemSlot->mSlotFrames += 1;
        slotFrames = gRaceItemSlot->mSlotFrames;
        gRaceItemSlot->mSlotRunning = TRUE;
    } else {
        NNS_SndPlayerStopSeq(GetSndHandles(), 0);
        gRaceItemSlot->mSlotFrames = 0;
        slotFrames = gRaceItemSlot->mSlotFrames;
        if (GetKartItemsAtOffset(kartOffset)->mSlotShownItem >= ITEM_INFO_KOURA_G_THREE) {
            if (gRaceSetup->mRaceKind != RACE_KIND_REPLAY) {
                endSeqNo = 0x40;
                if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
                    endSeqNo = 0x1c6;
                }
                if ((gRaceSoundKind & 1) != 0) {
                    entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                    if (gSoundModeHolder.mSeqStartEnabled != 0) {
                        if (*entryHandle != NULL) {
                            NNS_SndPlayerStopSeq(entryHandle, 0);
                        }
                        if (*entryHandle != NULL) {
                            NNS_SndPlayerStopSeq(entryHandle, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(entryHandle, 0, endSeqNo);
                    }
                }
            }
        } else {
            if (gRaceSetup->mRaceKind != RACE_KIND_REPLAY) {
                endSeqNo = 0x3f;
                if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
                    endSeqNo = 0x1c5;
                }
                if ((gRaceSoundKind & 1) != 0) {
                    entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                    if (gSoundModeHolder.mSeqStartEnabled != 0) {
                        if (*entryHandle != NULL) {
                            NNS_SndPlayerStopSeq(entryHandle, 0);
                        }
                        if (*entryHandle != NULL) {
                            NNS_SndPlayerStopSeq(entryHandle, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(entryHandle, 0, endSeqNo);
                    }
                }
            }
        }
        gRaceItemSlot->mSlotRunning = FALSE;
    }
    if (gRaceItemSlot->mPrevSlotRunning == FALSE && gRaceItemSlot->mSlotRunning != FALSE &&
        gRaceSetup->mRaceKind != RACE_KIND_REPLAY) {
        sndHandle = GetSndHandles();
        startSeqNo = 0x3e;
        if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
            startSeqNo = 0x1c4;
        }
        if ((gRaceSoundKind & 1) != 0) {
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (*sndHandle != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                if (*sndHandle != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(sndHandle, 0, startSeqNo);
            }
        }
    }
    kartItems = GetKartItemsAtOffset(kartOffset);
    if (kartItems->mSlotState == KART_ITEMS_SLOT_IDLE) {
        gRaceItemSlot->mLowerItem = kartItems->mHeldItem.mItemInfoIndex == ITEM_INFO_NONE
                                        ? kartItems->mActiveItem
                                        : kartItems->mHeldItem.mItemInfoIndex;
    } else {
        switch (slotFrames) {
            case 0:
                RACE_ITEM_SLOT_CHANGE_FRAME_CASES
                gRaceItemSlot->mLowerItem = kartItems->mSlotShownItem;
                PickItemSlotShownItem(GetKartItemsAtOffset(kartOffset));
                break;
        }
        upperItem = GetKartItemsAtOffset(kartOffset)->mSlotShownItem;
        gRaceItemSlot->mScale.mScaleFrames = 0;
    }
    if (slotFrames < RACE_ITEM_SLOT_SCROLL_START_FRAME) {
        scrollY = 0;
    } else if (slotFrames < RACE_ITEM_SLOT_STAGE_2_END_FRAME) {
        scrollY = ((slotFrames - RACE_ITEM_SLOT_SCROLL_START_FRAME) & 1) << RACE_ITEM_SLOT_ROW_HEIGHT_SHIFT >> 1;
    } else if (slotFrames < RACE_ITEM_SLOT_STAGE_4_END_FRAME) {
        scrollY = ((slotFrames - RACE_ITEM_SLOT_STAGE_2_END_FRAME) & 3) << RACE_ITEM_SLOT_ROW_HEIGHT_SHIFT >> 2;
    } else if (slotFrames < RACE_ITEM_SLOT_STAGE_8_END_FRAME) {
        scrollY = ((slotFrames - RACE_ITEM_SLOT_STAGE_4_END_FRAME) & 7) << RACE_ITEM_SLOT_ROW_HEIGHT_SHIFT >> 3;
    } else if (slotFrames < RACE_ITEM_SLOT_FINAL_SCROLL_START_FRAME) {
        scrollY = ((slotFrames - RACE_ITEM_SLOT_STAGE_8_END_FRAME) & 0xf) << RACE_ITEM_SLOT_ROW_HEIGHT_SHIFT >> 4;
    } else if (slotFrames >= finalScrollFrameCount + RACE_ITEM_SLOT_FINAL_SCROLL_START_FRAME) {
        scrollY = 0;
    } else {
        scrollY = ((slotFrames - RACE_ITEM_SLOT_FINAL_SCROLL_START_FRAME) &
                   ((s32) GetKartItemsAtOffset(kartOffset)->mSlotFinalScrollFrameCount - 1))
                      << RACE_ITEM_SLOT_ROW_HEIGHT_SHIFT >>
                  GetKartItemsAtOffset(kartOffset)->mSlotFinalScrollFrameShift;
    }
    if (gRaceItemSlot->mScale.mScaleFrames != 0) {
        scale = &gRaceItemSlot->mScale;
        scale->mScaleY += scale->mScaleYPerFrame;
        scale->mScaleYPerFrame +=
            MUL_FIXED12_NO_ROUND(scale->mScaleYTarget - scale->mScaleY, RACE_ITEM_SLOT_SCALE_SPRING);
        scale->mScaleYPerFrame = MUL_FIXED12_NO_ROUND(scale->mScaleYPerFrame, RACE_ITEM_SLOT_SCALE_DAMPING);
        scale->mScaleX = MUL_FIXED12_NO_ROUND(scale->mScaleYTarget, TO_FIXED12(2)) - scale->mScaleY;
        gRaceItemSlot->mScale.mScaleFrames += 1;
        if (gRaceItemSlot->mScale.mScaleYTarget == RACE_ITEM_SLOT_SCALE_POP_TARGET &&
            gRaceItemSlot->mScale.mScaleFrames > RACE_ITEM_SLOT_SCALE_POP_FRAMES) {
            gRaceItemSlot->mScale.mScaleYTarget = RACE_ITEM_SLOT_SCALE_NORMAL;
        } else if (gRaceItemSlot->mScale.mScaleYTarget == RACE_ITEM_SLOT_SCALE_NORMAL &&
                   gRaceItemSlot->mScale.mScaleFrames > RACE_ITEM_SLOT_SCALE_END_FRAME) {
            gRaceItemSlot->mScale.mScaleFrames = 0;
        }
    }
    if (GetKartItemsAtOffset(kartOffset)->mKinokoBoostStarted != FALSE) {
        s32 heldOrActiveItem;
        heldOrActiveItem = GetKartItemsAtOffset(kartOffset)->mHeldItem.mItemInfoIndex == ITEM_INFO_NONE
                               ? GetKartItemsAtOffset(kartOffset)->mActiveItem
                               : GetKartItemsAtOffset(kartOffset)->mHeldItem.mItemInfoIndex;
        if (heldOrActiveItem == ITEM_INFO_KINOKO_P) {
            gRaceItemSlot->mScale.mScaleFrames += 1;
            gRaceItemSlot->mScale.mScaleX = RACE_ITEM_SLOT_SCALE_NORMAL;
            gRaceItemSlot->mScale.mScaleY = RACE_ITEM_SLOT_SCALE_NORMAL;
            gRaceItemSlot->mScale.mScaleYPerFrame = RACE_ITEM_SLOT_SCALE_POP_STEP;
            gRaceItemSlot->mScale.mScaleYTarget = RACE_ITEM_SLOT_SCALE_POP_TARGET;
        }
    }
    gRaceItemSlot->mScrollY = scrollY;
    gRaceItemSlot->mUpperItem = upperItem;
}

void DrawRaceItemSlot(RaceHudOamBuffer *oamBuffer) {
    s32 firstPos[2];
    s32 secondPos[2];
    s32 thirdPos[2];
    s32 upperItemPos[2];
    s32 lowerItemPos[2];
    s32 scaledUpperItemPos[2];
    s32 scaledLowerItemPos[2];
    s32 lastPos[2];
    MtxFx22 matrix;
    s32 scrollY;
    s32 upperItem;
    NNSG2dCellDataWithBR *cell;
    NNSG2dCellDataWithBR *teamCell;
    s32 oamIndex;
    GXOamAttr *oam;
    GXOamAttr *matrixOams;
    u16 matrixIndex;

    scrollY = gRaceItemSlot->mScrollY;
    upperItem = gRaceItemSlot->mUpperItem;
    teamCell = GetRaceMNcerEntry(gRaceSetup->mUseTeams == 0 ? RACE_M_CELL_SLOT_BOX_NO_TEAMS
                                 : gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mPlayer.mTeamIndex == 0
                                     ? RACE_M_CELL_SLOT_BOX_TEAM_0
                                     : RACE_M_CELL_SLOT_BOX_TEAM_1);
    if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    cell = GetRaceMNcerEntry(RACE_M_CELL_SLOT_FRAME);
    firstPos[0] = TO_FIXED12(0x18);
    firstPos[1] = TO_FIXED12(0x18);
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
        &oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell, NULL, firstPos, 0, 1);
    oamIndex = oamBuffer->mOamCount;
    secondPos[0] = TO_FIXED12(0x18);
    secondPos[1] = TO_FIXED12(0x18);
    oam = &oamBuffer->mOams[oamIndex];
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(oam, RACE_HUD_OAM_COUNT - oamIndex, teamCell, NULL, secondPos, 0, 1);
    for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
        ((u32 *) oam)[0] = (((u32 *) oam)[0] & ~RACE_HUD_OAM_MODE_MASK) | RACE_HUD_OAM_MODE_OBJ_WINDOW;
        ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~RACE_HUD_OAM_PRIORITY_MASK) | RACE_HUD_OAM_PRIORITY_1;
    }
    oamIndex = oamBuffer->mOamCount;
    thirdPos[0] = TO_FIXED12(0x18);
    thirdPos[1] = TO_FIXED12(0x18);
    oam = &oamBuffer->mOams[oamIndex];
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(oam, RACE_HUD_OAM_COUNT - oamIndex, teamCell, NULL, thirdPos, 0, 1);
    for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
        ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~RACE_HUD_OAM_PRIORITY_MASK) | RACE_HUD_OAM_PRIORITY_1;
    }
    if (gRaceItemSlot->mScale.mScaleFrames == 0) {
        cell = GetRaceMNcerEntry(LookupRaceMNcerIndex(upperItem));
        upperItemPos[0] = TO_FIXED12(0x18);
        upperItemPos[1] = TO_FIXED12(scrollY - 8);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, upperItemPos, 0, 1);
        cell = GetRaceMNcerEntry(LookupRaceMNcerIndex(gRaceItemSlot->mLowerItem));
        lowerItemPos[0] = TO_FIXED12(0x18);
        lowerItemPos[1] = TO_FIXED12(scrollY + 0x18);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, lowerItemPos, 0, 1);
    } else {
        matrixIndex = AllocOamMatrixIndex(oamBuffer);
        matrix.mElements[0] = FX_Div(TO_FIXED12(1), gRaceItemSlot->mScale.mScaleX);
        matrix.mElements[1] = 0;
        matrix.mElements[2] = 0;
        matrix.mElements[3] = FX_Div(TO_FIXED12(1), gRaceItemSlot->mScale.mScaleY);
        cell = GetRaceMNcerEntry(LookupRaceMNcerIndex(upperItem));
        oamIndex = oamBuffer->mOamCount;
        scaledUpperItemPos[0] = TO_FIXED12(0x18);
        scaledUpperItemPos[1] = TO_FIXED12(scrollY - 8);
        oam = &oamBuffer->mOams[oamIndex];
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(oam, RACE_HUD_OAM_COUNT - oamIndex, cell, &matrix,
                                                      scaledUpperItemPos, matrixIndex, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
            ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~RACE_HUD_OAM_PRIORITY_MASK) | RACE_HUD_OAM_PRIORITY_1;
        }
        cell = GetRaceMNcerEntry(LookupRaceMNcerIndex(gRaceItemSlot->mLowerItem));
        oamIndex = oamBuffer->mOamCount;
        scaledLowerItemPos[0] = TO_FIXED12(0x18);
        scaledLowerItemPos[1] = TO_FIXED12(scrollY + 0x18);
        oam = &oamBuffer->mOams[oamIndex];
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(oam, RACE_HUD_OAM_COUNT - oamIndex, cell, &matrix,
                                                      scaledLowerItemPos, matrixIndex, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
            ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~RACE_HUD_OAM_PRIORITY_MASK) | RACE_HUD_OAM_PRIORITY_1;
        }
        matrixOams = &oamBuffer->mOams[matrixIndex * 4];
        matrixOams[0].mAttrs[3] = matrix.mElements[0] >> 4;
        matrixOams[1].mAttrs[3] = matrix.mElements[1] >> 4;
        matrixOams[2].mAttrs[3] = matrix.mElements[2] >> 4;
        matrixOams[3].mAttrs[3] = matrix.mElements[3] >> 4;
    }
    cell = GetRaceMNcerEntry(RACE_M_CELL_ITEM_EMPTY);
    lastPos[0] = TO_FIXED12(0x18);
    lastPos[1] = TO_FIXED12(0x18);
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                  RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell, NULL, lastPos, 0, 1);
}

BOOL IsRaceKeyRecordingNotFull(void) {
    if (gRaceModeCount != NULL) {
        return gRaceModeCount->mKeyRecordingNotFull;
    }
    return FALSE;
}

void InitRaceModeCount(void) {
    RaceModeCount *modeCount;
    s32 mode;

    modeCount = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0xc);
    gRaceModeCount = modeCount;
    mode = gRaceSetup->mMode;
    switch (mode) {
        case MODE_MISSION_RUN:
            gRaceModeCount->mNumber = mode == MODE_MISSION_RUN ? GetMissionRunCount() : 0;
            gRaceModeCount->mMissionRunCountLimit = gRaceSetup->mMissionRunCountLimit;
            break;
        case MODE_BATTLE:
            switch (gRaceSetup->mBattleKind) {
                case BATTLE_KIND_BALLOON:
                    modeCount->mNumberHalves[0] = 0;
                    gRaceModeCount->mNumberHalves[1] = GetBalloonsLeftToMake(GetFollowedKartOrEntryIndex());
                    break;
                case BATTLE_KIND_SHINE:
                default:
                    gRaceModeCount->mNumberHalves[0] = GetBalloonOrShineCount(GetFollowedKartOrEntryIndex());
                    break;
            }
            break;
        case MODE_TIME_ATTACK:
            break;
        default:
            gRaceModeCount->mNumber = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            break;
    }
    gRaceModeCount->mKeyRecordingNotFull = TRUE;
}

void ClearRaceModeCountPointer(void) {
    gRaceModeCount = NULL;
}

void UpdateRaceModeCount(void) {
    s32 mode;

    mode = gRaceSetup->mMode;
    switch (mode) {
        case MODE_MISSION_RUN:
            gRaceModeCount->mNumber = mode == MODE_MISSION_RUN ? GetMissionRunCount() : 0;
            break;
        case MODE_BATTLE:
            if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
                if (IsKartInflatingBalloon(GetFollowedKartOrEntryIndex()) != 0) {
                    gRaceModeCount->mNumberHalves[0] += 1;
                    if (gRaceModeCount->mNumberHalves[0] >= 9) {
                        gRaceModeCount->mNumberHalves[0] = 0;
                    }
                } else {
                    gRaceModeCount->mNumberHalves[0] = 0;
                }
                gRaceModeCount->mNumberHalves[1] = GetBalloonsLeftToMake(GetFollowedKartOrEntryIndex());
            } else {
                gRaceModeCount->mNumberHalves[0] = GetBalloonOrShineCount(GetFollowedKartOrEntryIndex());
            }
            break;
        case MODE_TIME_ATTACK:
            break;
        default:
            gRaceModeCount->mNumber = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            break;
    }
}

void DrawRaceModeCount(RaceHudOamBuffer *oamBuffer) {
    s32 battleEndPos[2];
    s32 balloonPos[2];
    s32 inflatingBalloonPos[2];
    s32 leadingCellPos[2];
    s32 tensPos[2];
    s32 onesPos[2];
    s32 recordingFullFirstPos[2];
    s32 recordingFullSecondPos[2];
    s32 rankPos[2];
    u16 inflateFrames;
    u16 count;
    s32 value;
    s32 oamIndex;
    GXOamAttr *oam;
    NNSG2dCellDataWithBR *cell;

    if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_MISSION_RUN:
            DrawRaceMissionRunCount(oamBuffer);
            return;
        case MODE_BATTLE:
            if (IsKartEnded(GetFollowedKartOrEntryIndex()) == 0) {
                if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
                    value = 0;
                    count = gRaceModeCount->mNumberHalves[1];
                    inflateFrames = gRaceModeCount->mNumberHalves[0];
                    for (; value < count; value++) {
                        cell = GetRaceBattleMNcerEntry(10);
                        balloonPos[0] = TO_FIXED12(0xfe - value * 0xe);
                        balloonPos[1] = TO_FIXED12(0xc);
                        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                                      RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell,
                                                                      NULL, balloonPos, 0, 1);
                    }
                    if (inflateFrames == 0) {
                        return;
                    }
                    if (inflateFrames >= 6) {
                        return;
                    }
                    cell = GetRaceBattleMNcerEntry(10);
                    inflatingBalloonPos[0] = TO_FIXED12(0xfe - value * 0xe);
                    inflatingBalloonPos[1] = TO_FIXED12(0xc);
                    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                                  RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell, NULL,
                                                                  inflatingBalloonPos, 0, 1);
                } else {
                    value = GetRaceStartSequenceFrames() % 16;
                    if (IsKartLastByBalloonOrShineCount(GetFollowedKartOrEntryIndex()) != 0 && value >= 10) {
                        return;
                    }
                    count = gRaceModeCount->mNumberHalves[0];
                    cell = GetRaceBattleMNcerEntry(0xb);
                    leadingCellPos[0] = TO_FIXED12(0xcd);
                    leadingCellPos[1] = TO_FIXED12(0xf);
                    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                                  RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell, NULL,
                                                                  leadingCellPos, 0, 1);
                    cell = GetRaceBattleMNcerEntry(count / 10);
                    tensPos[0] = TO_FIXED12(0xe1);
                    tensPos[1] = TO_FIXED12(0x10);
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                              RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell, NULL, tensPos, 0, 1);
                    cell = GetRaceBattleMNcerEntry(count % 10);
                    onesPos[0] = TO_FIXED12(0xf0);
                    onesPos[1] = TO_FIXED12(0x10);
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                              RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell, NULL, onesPos, 0, 1);
                }
            } else {
                if (gRaceProgress->mKarts[GetFollowedKartOrEntryIndex()].mStatus !=
                    RACE_PROGRESS_KART_STATUS_BATTLE_LOSER) {
                    return;
                }
                if ((GetKart(GetFollowedKartOrEntryIndex())->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED) == 0) {
                    return;
                }
                cell = GetRaceBattleMNcerEntry(0xc);
                battleEndPos[0] = TO_FIXED12(0x80);
                battleEndPos[1] = TO_FIXED12(0x60);
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                          RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell, NULL, battleEndPos, 0, 1);
            }
            break;
        case MODE_TIME_ATTACK:
            if (gInputSlots[0].mSourceKind != INPUT_SOURCE_PAD_RECORDED) {
                return;
            }
            if (IsKeyRecordingFull(&gInputSlots[0].mKeyRecording) == FALSE) {
                return;
            }
            gRaceModeCount->mKeyRecordingNotFull = FALSE;
            cell = GetRaceTaMNcerEntry(0xd);
            oamIndex = oamBuffer->mOamCount;
            recordingFullFirstPos[0] = TO_FIXED12(0x80);
            recordingFullFirstPos[1] = TO_FIXED12(0x60);
            oam = &oamBuffer->mOams[oamIndex];
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(oam, RACE_HUD_OAM_COUNT - oamIndex, cell, NULL, recordingFullFirstPos, 0, 1);
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                ((u32 *) oam)[0] = (((u32 *) oam)[0] & ~RACE_HUD_OAM_MODE_MASK) | RACE_HUD_OAM_MODE_OBJ_WINDOW;
                ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~RACE_HUD_OAM_PRIORITY_MASK) | RACE_HUD_OAM_PRIORITY_1;
            }
            cell = GetRaceTaMNcerEntry(0xd);
            recordingFullSecondPos[0] = TO_FIXED12(0x80);
            recordingFullSecondPos[1] = TO_FIXED12(0x60);
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                          RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell, NULL,
                                                          recordingFullSecondPos, 0, 1);
            break;
        default:
            cell = GetRaceMNcerEntry(gRaceModeCount->mNumber);
            rankPos[0] = TO_FIXED12(0x18);
            rankPos[1] = TO_FIXED12(0xa8);
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                      RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell, NULL, rankPos, 0, 1);
            break;
    }
}

void DrawRaceMissionRunCount(RaceHudOamBuffer *oamBuffer) {
    s32 leadingCellPos[2];
    s32 countTensPos[2];
    s32 countOnesPos[2];
    s32 middleCellPos[2];
    s32 limitTensPos[2];
    s32 limitOnesPos[2];
    s32 oneDigitCountPos[2];
    s32 oneDigitMiddleCellPos[2];
    s32 oneDigitLimitPos[2];
    s32 count;
    s32 countLimit;
    RaceModeCount *modeCount;
    NNSG2dCellDataWithBR *cell;

    modeCount = gRaceModeCount;
    countLimit = modeCount->mMissionRunCountLimit;
    if (countLimit <= 0) {
        return;
    }
    count = modeCount->mNumber;
    if (count > countLimit) {
        count = countLimit;
    }
    cell = GetRaceMrMNcerEntry(0x15);
    leadingCellPos[0] = TO_FIXED12(0xc);
    leadingCellPos[1] = TO_FIXED12(0xb0);
    oamBuffer->mOamCount +=
        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount, cell,
                              NULL, leadingCellPos, 0, 1);
    if (gRaceModeCount->mMissionRunCountLimit >= 10) {
        cell = GetRaceMrMNcerEntry(count / 10);
        countTensPos[0] = TO_FIXED12(0x1b);
        countTensPos[1] = TO_FIXED12(0xb4);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, countTensPos, 0, 1);
        cell = GetRaceMrMNcerEntry(count % 10);
        countOnesPos[0] = TO_FIXED12(0x2e);
        countOnesPos[1] = TO_FIXED12(0xb4);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, countOnesPos, 0, 1);
        cell = GetRaceMrMNcerEntry(10);
        middleCellPos[0] = TO_FIXED12(0x42);
        middleCellPos[1] = TO_FIXED12(0xb4);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, middleCellPos, 0, 1);
        cell = GetRaceMrMNcerEntry(countLimit / 10 + 0xb);
        limitTensPos[0] = TO_FIXED12(0x4d);
        limitTensPos[1] = TO_FIXED12(0xb4);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, limitTensPos, 0, 1);
        cell = GetRaceMrMNcerEntry(countLimit % 10 + 0xb);
        limitOnesPos[0] = TO_FIXED12(0x5b);
        limitOnesPos[1] = TO_FIXED12(0xb4);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, limitOnesPos, 0, 1);
    } else {
        cell = GetRaceMrMNcerEntry(count % 10);
        oneDigitCountPos[0] = TO_FIXED12(0x1b);
        oneDigitCountPos[1] = TO_FIXED12(0xb4);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, oneDigitCountPos, 0, 1);
        cell = GetRaceMrMNcerEntry(10);
        oneDigitMiddleCellPos[0] = TO_FIXED12(0x2f);
        oneDigitMiddleCellPos[1] = TO_FIXED12(0xb4);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, oneDigitMiddleCellPos, 0, 1);
        cell = GetRaceMrMNcerEntry(countLimit % 10 + 0xb);
        oneDigitLimitPos[0] = TO_FIXED12(0x3a);
        oneDigitLimitPos[1] = TO_FIXED12(0xb4);
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], RACE_HUD_OAM_COUNT - oamBuffer->mOamCount,
                                  cell, NULL, oneDigitLimitPos, 0, 1);
    }
}
