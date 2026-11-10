#pragma once

#include "types.h"

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
