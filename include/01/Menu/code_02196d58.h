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
void RequestRecordTAttState1AndSetup(void);
void RequestRecordTAttState2(void);
void RequestRecordTAttState3(void);
void RequestRecordTAttState4AndMoveIndex(void);
void RequestRecordTAttState5(void);
void RequestRecordTAttState6(void);
void RequestRecordTAttState7(void);
void RequestRecordTAttState8(void);
void RequestRecordTAttState9(void);
void RequestRecordTAttState10(void);
void RequestRecordTAttState11(void);
void RequestRecordTAttState12(void);
void RequestRecordTAttState13(void);
void RequestRecordTAttState14(void);
void RequestRecordTAttState15(void);
void RequestRecordTAttState16(void);
void RequestRecordTAttState17(void);
