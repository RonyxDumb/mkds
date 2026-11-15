#pragma once

#include "types.h"

#include "01/code_02192000.h"
#include "01/unk_021a9000.h"
#include "01/Menu/option_states.h"
#include "01/Menu/option_nickname_scenes.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/MapObjects/data_0217a000.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/oam.h"
#include "01/unk_021a6000.h"
#include "Main/Scene/display_settings.h"
#include "01/unk_021a8000.h"
#include "Main/System/result_archive_path.h"

void RegisterOptionEmbremSelectCallbacks(void);
void WriteOptionEmbremSelectRegisters(void);
void AdvanceOptionEmbremSelect(void);
void AdvanceOptionEmbremSelectTimers(void);
void UpdateOptionEmbremSelectHighlight(void);
void UpdateOptionEmbremSelectIndexCells(void);
void UpdateOptionEmbremSelectCellOffsets(void);
void AdvanceOptionEmbremSelectState6(void);
void AdvanceOptionEmbremSelectState5(void);
void AdvanceOptionEmbremSelectState4(void);
void AdvanceOptionEmbremSelectState3(void);
void AdvanceOptionEmbremSelectState2(void);
void AdvanceOptionEmbremSelectState1(void);
void AdvanceOptionEmbremSelectState0(void);
BOOL IsBackupEmblemOff(void);
void LocateAndQueueOptionEmbremSelect(void);
/* slot mRelease of OptionStateCallbacks; only clears the global, the state heap is destroyed by
   AdvanceOptionStates after it returns */
void ReleaseOptionEmbremSelect(void);
void InitOptionEmbremSelect(void *heap);

#include "00/Menu/wi_fi_vs_matching.h"

extern const s32 gOptionEmbremSelectCellCounts[2];
extern const s32 gOptionEmbremSelectSTableCounts[2];
extern OptionStateCallbacks gOptionEmbremSelectCallbacks;
extern const u8 gOptionEmbremSelectSTableIndices[2][11];
extern const u8 gOptionEmbremSelectTimerCellIndices[3][2];
extern const u8 gOptionEmbremSelectCellIndices[2][2];
