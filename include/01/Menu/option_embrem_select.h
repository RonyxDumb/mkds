#pragma once

#include "types.h"

#include "01/Menu/menu_screen_states_and_file_names.h"
#include "01/Menu/option_states.h"
#include "01/Menu/option_nickname_scenes.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/System/backup_net_camera_work.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/oam.h"
#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/Scene/display_settings.h"
#include "01/Menu/record_gpx_grade_text.h"
#include "Main/System/result_archive_path.h"

void RegisterOptionEmbremSelectCallbacks(void);
void WriteOptionEmbremSelectRegisters(void);
void AdvanceOptionEmbremSelect(void);
void AdvanceOptionEmbremSelectTimers(void);
void UpdateOptionEmbremSelectHighlight(void);
void UpdateOptionEmbremSelectIndexCells(void);
void UpdateOptionEmbremSelectCellOffsets(void);
void AdvanceOptionEmbremSelectWaitMessage(void);
void AdvanceOptionEmbremSelectSlideOut(void);
void AdvanceOptionEmbremSelectHoldChosen(void);
void AdvanceOptionEmbremSelectSelect(void);
void AdvanceOptionEmbremSelectWaitSelectReturn(void);
void AdvanceOptionEmbremSelectSlideIn(void);
void AdvanceOptionEmbremSelectWaitFade(void);
BOOL IsBackupEmblemOff(void);
void LocateAndQueueOptionEmbremSelect(void);
/* slot mRelease of OptionStateCallbacks; only clears the global. On a state change AdvanceOptionStates destroys the
   state heap after it returns */
void ClearOptionEmbremSelectPointer(void);
void InitOptionEmbremSelect(void *heap);

#include "00/Menu/wi_fi_vs_matching.h"

extern const s32 gOptionEmbremSelectCellCounts[2];
extern const s32 gOptionEmbremSelectSTableCounts[2];
extern OptionStateCallbacks gOptionEmbremSelectCallbacks;
extern const u8 gOptionEmbremSelectSTableIndices[2][11];
extern const u8 gOptionEmbremSelectTimerCellIndices[3][2];
extern const u8 gOptionEmbremSelectCellIndices[2][2];
