#pragma once

#include "types.h"
#include "Main/System/thread_function_queue.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/select_return.h"
#include "sound_player_control.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "sound_archive_load_result.h"
#include "Main/Save/buddy_record.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/record_scene.h"
#include "card_rom_backup_access.h"
#include "00/Menu/wi_fi_vs_matching.h"

extern const s32 gRecordTAttCommonMessageIndices[RECORD_TATT_COURSE_COUNT];
extern const u16 gRecordTAttCharacterCells[13];
// row 0: character palette slots, row 1: kart palette slots
extern const u16 gRecordTAttPaletteSlots[2][5];
extern const s32 gRecordTAttGhostMessageIndices[RECORD_TATT_COURSE_COUNT];

void LocateAndQueueRecordTAtt(void);
void SetupRecordTAttRowValues(u16 row);
void SetupRecordTAttRowDashes(u16 row);
void SetupRecordTAtt(void);
void IncrementRecordTAttIndex(void);
void DecrementRecordTAttIndex(void);
BOOL CheckRecordTAttFirstRecordFormat(void);
void ResetRecordTAtt(void);
void RequestRecordTAttSlideInRightAndSetup(void);
void RequestRecordTAttWaitInput(void);
void RequestRecordTAttSlideOutSide(void);
void RequestRecordTAttSlideInSideAndMoveIndexAndSetup(void);
void RequestRecordTAttSlideOutRight(void);
void RequestRecordTAttSlideOutTop(void);
void RequestRecordTAttPressButton(void);
void RequestRecordTAttSlideOutForAskClear(void);
void RequestRecordTAttWaitAskClearOpen(void);
void RequestRecordTAttWaitClearAnswer(void);
void RequestRecordTAttWaitAskClearClose(void);
void RequestRecordTAttSlideInAfterAskClearAndSetup(void);
void RequestRecordTAttSlideOutForTimeRecordChars(void);
void RequestRecordTAttWaitTimeRecordCharsOpen(void);
void RequestRecordTAttWaitTimeRecordCharsInput(void);
void RequestRecordTAttWaitTimeRecordCharsClose(void);
void RequestRecordTAttSlideInAfterTimeRecordChars(void);
