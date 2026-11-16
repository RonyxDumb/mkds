#include "Main/Sound/seq_row.h"
#include "Main/Race/results_team.h"

#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h"
#include "sound_archive_load_result.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/Sound/sound_set_load.h"

u32 g_MissionRunBossResultSseqIdTable[6] = {0x37, 0xff, 0x31, 0x3b, 0x3d, 0xc};
u32 g_PerRaceModeResultSseqIdTable[6][6] = {{0x2e, 0x2f, 0x30, 0x38, 0x39, 7},   {0x36, 0x35, 0x31, 0x3c, 0x3d, 0xb},
                          {0x32, 0xff, 0x31, 0x3a, 0x3d, 0xc}, {0x32, 0x33, 0x31, 0x3a, 0x3d, 0xb},
                          {0x34, 0xff, 0x31, 0x3b, 0x3d, 0xc}, {0x32, 0x33, 0x31, 0x3a, 0x3d, 0xb}};

void SetEntryKartFinishResult(u32 finishResult) {
    u32 copy = finishResult;
    u32 unused;
    g_GlobalCX.mFinishResult = copy;
}

u32 GetResultSceneSeqId(void) {
    u32 selector;
    u32 result;
    result = 0xffffffff;
    selector = GetResultSceneSeqKind();
    switch (selector) {
        case RESULT_SCENE_SEQ_KIND_GP_HIGH_RANK:
            result = 0x43;
            break;
        case RESULT_SCENE_SEQ_KIND_GP_LOW_RANK:
            result = 0x44;
            break;
        case RESULT_SCENE_SEQ_KIND_WON:
            result = 0x3f;
            break;
        case RESULT_SCENE_SEQ_KIND_LOST:
            result = 0x41;
            break;
        case RESULT_SCENE_SEQ_KIND_DRAW:
            result = 0x40;
            break;
        case RESULT_SCENE_SEQ_KIND_TEAM_WON:
            result = 0x3f;
            break;
        case RESULT_SCENE_SEQ_KIND_TEAM_LOST:
            result = 0x41;
            break;
        case RESULT_SCENE_SEQ_KIND_TEAM_DRAW:
            result = 0x40;
    }
    return result;
}

void CreateSetGlobalCX(void *heapMemory, u32 heapSize) {
    g_GlobalCX.mSeqHeap = Sound_InitializeContext(heapMemory, heapSize);
    g_GlobalCX.mSeqRow = NULL;
}

// Loads the sequences of the row for index unless that row is already loaded; returns 0 if a load fails.
u32 LoadPerRaceModeResultSseqs(s32 index) {
    SeqRowState *state;
    u32 *row;
    NNSSndHeap *savedHeap;
    s32 seqIndex;
    savedHeap = g_SoundContext;
    state = &g_GlobalCX;
    if (index == 4 && (g_GlobalCO->mMode == MODE_MISSION_RUN ? g_GlobalCO->mMissionTableColumn : -1) == 9) {
        row = g_MissionRunBossResultSseqIdTable;
    } else {
        row = g_PerRaceModeResultSseqIdTable[index];
    }
    if (state->mSeqRow == row) {
        return 1;
    }
    g_SoundContext = g_GlobalCX.mSeqHeap;
    Sound_Context_DisposeLoadedStuff(state->mSeqHeap);
    for (seqIndex = 0; seqIndex < 6; seqIndex++) {
        if (row[seqIndex] != SOUND_ID_NONE) {
            if (CheckMaybeLoadSseqOk(row[seqIndex], g_SoundContext) == 0) {
                g_SoundContext = savedHeap;
                return 0;
            }
        }
    }
    state->mLoadedIndex = index;
    state->mSeqRow = row;
    g_SoundContext = savedHeap;
    return 1;
}

u32 GetSomeCXSseqId(void) {
    return g_GlobalCX.mSeqRow[5];
}

s32 *ResetRaceEndSeqState(void) {
    gRaceEndNextSeqPending = 0;
    gRaceEndSeqStarted = 0;
    gRaceEndSeqCallCount = 0;
    return &gRaceEndSeqCallCount;
}
