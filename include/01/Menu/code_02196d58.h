#pragma once

#include "types.h"
#include "Main/System/thread_function_queue.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/select_return.h"
#include "player.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "code_0212df7c.h"
#include "Main/Save/buddy_record.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/record_scene.h"
#include "code_021458c4.h"
#include "00/Menu/wi_fi_vs_matching.h"

extern const s32 gRecordTAttCommonMessageIndices[32];
extern const u16 gRecordTAttCharacterCells[13];
// row 0: character palette slots, row 1: kart palette slots
extern const u16 gRecordTAttPaletteSlots[2][5];
extern const s32 gRecordTAttGhostMessageIndices[32];

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
void RequestRecordTAttSlideInSideAndMoveIndex(void);
void RequestRecordTAttSlideOutRight(void);
void RequestRecordTAttSlideOutTop(void);
void RequestRecordTAttPressButton(void);
void RequestRecordTAttSlideOutForClearPrompt(void);
void RequestRecordTAttWaitClearPromptOpen(void);
void RequestRecordTAttWaitClearAnswer(void);
void RequestRecordTAttWaitClearPromptClose(void);
void RequestRecordTAttSlideInAfterClearPrompt(void);
void RequestRecordTAttSlideOutForTimeText(void);
void RequestRecordTAttWaitTimeTextOpen(void);
void RequestRecordTAttWaitTimeTextInput(void);
void RequestRecordTAttWaitTimeTextClose(void);
void RequestRecordTAttSlideInAfterTimeText(void);
