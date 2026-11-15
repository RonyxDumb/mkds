#include "Main/Race/race_time_digits.h"
#include "Main/Graphics/stem_sets.h"

#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "sound_archive_load_result.h"
#include "cell_animation.h"
#include "Main/Race/race_clock.h"
#include "Main/Race/kart.h"
#include "Main/System/init_after_startup.h"

RaceTimeDigits *gRaceTimeDigits;

void ClearRaceTimeDigitsPointer(void) {
    gRaceTimeDigits = NULL;
}

void UpdateRaceTimeDigits(void) {
    u8 minute;
    u8 second;
    u16 millisecond;
    s32 secondIndex;
    s32 kartIndex;
    NNSSndSeqPlayer **entryHandle;

    if (GetRaceHudSubScreenState() == RACE_HUD_SUB_SCREEN_NEW_RECORD) {
        return;
    }
    if (GetShowLapTime() != 0) {
        kartIndex = GetFollowedKartOrEntryIndex();
        GetKartLapTime(kartIndex, GetFollowedKartLastEndedLap(), &minute, &second, &millisecond);
    } else {
        if (gRaceSetup->mMode != MODE_BATTLE && IsKartEnded(GetFollowedKartOrEntryIndex()) != 0) {
            GetKartFinishTime(GetFollowedKartOrEntryIndex(), &minute, &second, &millisecond);
        } else {
            GetRaceClockTime(&minute, &second, &millisecond);
        }
    }
    SplitTimeDigits(minute, second, millisecond, &gRaceTimeDigits->mTime);
    if (gRaceTimeDigits->mUseLastSecondsSound == FALSE) {
        return;
    }
    if (minute == 0 && second > 6) {
        for (secondIndex = 0; secondIndex < 6; secondIndex++) {
            gRaceTimeDigits->mLastSecondsReached[secondIndex] = 0;
        }
        return;
    }
    if (minute == 0 && ((second == 5 && millisecond == 0) || second < 5) &&
        gRaceTimeDigits->mLastSecondsReached[0] == 0) {
        if (gRaceProgress->mKarts[GetFollowedKartOrEntryIndex()].mStatus != RACE_PROGRESS_KART_STATUS_BATTLE_LOSER) {
            SetStemSet(STEM_SET_COUNT_COPY);
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
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[0] = 1;
        return;
    }
    if (minute == 0 && ((second == 4 && millisecond == 0) || second < 4) &&
        gRaceTimeDigits->mLastSecondsReached[1] == 0) {
        if ((gRaceSoundKind & 1) != 0) {
            entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[1] = 1;
        return;
    }
    if (minute == 0 && ((second == 3 && millisecond == 0) || second < 3) &&
        gRaceTimeDigits->mLastSecondsReached[2] == 0) {
        if ((gRaceSoundKind & 1) != 0) {
            entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[2] = 1;
        return;
    }
    if (minute == 0 && ((second == 2 && millisecond == 0) || second < 2) &&
        gRaceTimeDigits->mLastSecondsReached[3] == 0) {
        if ((gRaceSoundKind & 1) != 0) {
            entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[3] = 1;
        return;
    }
    if (minute == 0 && ((second == 1 && millisecond == 0) || second < 1) &&
        gRaceTimeDigits->mLastSecondsReached[4] == 0) {
        if ((gRaceSoundKind & 1) != 0) {
            entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[4] = 1;
        return;
    }
    if (minute == 0 && second == 0 && millisecond == 0) {
        if (gRaceTimeDigits->mLastSecondsReached[5] == 0) {
            gRaceTimeDigits->mLastSecondsReached[5] = 1;
        }
    }
}

void DrawRaceTimeDigits(RaceHudOamBuffer *oamBuffer) {
    s32 lapTimeFirstCellPos[2];
    s32 firstCellPos[2];
    s32 minuteTensPos[2];
    s32 minuteOnesPos[2];
    s32 afterMinutesPos[2];
    s32 secondTensPos[2];
    s32 secondOnesPos[2];
    s32 afterSecondsPos[2];
    s32 millisecondHundredsPos[2];
    s32 millisecondTensPos[2];
    s32 millisecondOnesPos[2];
    s32 cellXs[10] = {0xa6, 0xad, 0xb6, 0xbf, 0xc8, 0xd1, 0xda, 0xe3, 0xec, 0xf5};
    u32 hasLapTime;
    s32 cellOffset;
    s32 cycleFrame;
    s32 afterCellIndex;

    hasLapTime = GetShowLapTime();
    cellOffset = 0;
    if (GetRaceHudSubScreenState() == RACE_HUD_SUB_SCREEN_NEW_RECORD) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_START_BATTLE) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (gRaceProgress->mKarts[GetFollowedKartOrEntryIndex()].mStatus == RACE_PROGRESS_KART_STATUS_ENDED_NO_GOAL) {
        return;
    }
    if (hasLapTime != 0) {
        cycleFrame = (s32) GetShowLapTimeFrames() % 16;
        if (cycleFrame >= 4) {
            if (cycleFrame < 8) {
                cellOffset = 0xc;
            } else if (cycleFrame < 12) {
                cellOffset = 0x18;
            } else {
                cellOffset = 0xc;
            }
        }
    }
    if (hasLapTime != 0) {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(cellOffset + 0x27);
        lapTimeFirstCellPos[0] = TO_FIXED12(cellXs[0]);
        lapTimeFirstCellPos[1] = 0xc000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  lapTimeFirstCellPos, 0, 1);
    } else {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(0x26);
        firstCellPos[0] = TO_FIXED12(cellXs[0]);
        firstCellPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, firstCellPos, 0, 1);
    }
    if (gRaceTimeDigits->mTime.mDigits[0] != 0) {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[0]);
        minuteTensPos[0] = TO_FIXED12(cellXs[1]);
        minuteTensPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, minuteTensPos, 0, 1);
    }
    {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[1]);
        minuteOnesPos[0] = TO_FIXED12(cellXs[2]);
        minuteOnesPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, minuteOnesPos, 0, 1);
    }
    afterCellIndex = cellOffset + 0x32;
    {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(afterCellIndex);
        afterMinutesPos[0] = TO_FIXED12(cellXs[3]);
        afterMinutesPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, afterMinutesPos, 0, 1);
    }
    {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[2]);
        secondTensPos[0] = TO_FIXED12(cellXs[4]);
        secondTensPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, secondTensPos, 0, 1);
    }
    {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[3]);
        secondOnesPos[0] = TO_FIXED12(cellXs[5]);
        secondOnesPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, secondOnesPos, 0, 1);
    }
    {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(afterCellIndex);
        afterSecondsPos[0] = TO_FIXED12(cellXs[6]);
        afterSecondsPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, afterSecondsPos, 0, 1);
    }
    {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[4]);
        millisecondHundredsPos[0] = TO_FIXED12(cellXs[7]);
        millisecondHundredsPos[1] = 0xc000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  millisecondHundredsPos, 0, 1);
    }
    {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[5]);
        millisecondTensPos[0] = TO_FIXED12(cellXs[8]);
        millisecondTensPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, millisecondTensPos, 0, 1);
    }
    {
        NNSG2dCellDataWithBR *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[6]);
        millisecondOnesPos[0] = TO_FIXED12(cellXs[9]);
        millisecondOnesPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, millisecondOnesPos, 0, 1);
    }
}
