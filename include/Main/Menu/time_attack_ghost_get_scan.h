#pragma once

#include "types.h"
#include "Main/Menu/data_02174000.h" // GhostRecordInfo
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"

typedef struct SceneNumbers SceneNumbers;

void ReleaseTimeAttackGhostGetScan(void);
s32 AdvanceTimeAttackGhostGetScan(SceneNumbers *sceneNumbers);

void InitTimeAttackGhostGetScan(void *parentHeap, void *mainOam, void *subOam);
BOOL AreGhostRecordInfosDifferent(GhostRecordInfo *storedInfo, GhostRecordInfo *newInfo);
void RefreshScanEntryPalettes(void);
void RefreshScanSelectedGhostInfo(void);
void UpdateScanSlideOffsets(void);
void UpdateScanEntryOffsetX(void);
void UpdateScanSelectedIndex(void);

void SetupGhostSubTextTwoButtons(void);
void SetScanSelectedEntryHighlight(s32 cursorVisible);
void MoveSelectedGhostDown(s32 wrap);
void MoveSelectedGhostUp(s32 wrap);
void SetupGhostMainTextShort(void);
void StartTimeAttackGhostGetScanState15(void);
void WriteGhostGetSlotRegisters(void);
void ReleaseTimeAttackGhostGetSlot(void);
s32 AdvanceTimeAttackGhostGetSlot(u16 *sceneNumbers);
void InitTimeAttackGhostGetSlot(void *parentHeap, void *mainOam, void *subOam);
void PrintSelectedGhostRecord(void);
void UpdateSlotSlideOffsets(void);
void SetupGhostNameSubTextTwoButtons(void);
void SetupGhostMainTextEx(void);
void RefreshSlotGhostListRows(s32 action, s32 slot, s32 listIndex, s32 selectedSlot);

extern const s16 gTimeAttackGhostGetScanMLabelTextRows[3][4];
extern GhostSceneCallbacks gTimeAttackGhostGetScanCallbacks;
extern s16 gTimeAttackGhostGetScanSSelLabelTextRows[8][4];
extern struct TimeAttackGhostGetScan *gTimeAttackGhostGetScan;

extern const s16 gTimeAttackGhostGetSlotMLabelTextRows[3][4];
