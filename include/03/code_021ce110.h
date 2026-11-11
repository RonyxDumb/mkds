#pragma once

#include "types.h"
#include "03/code_021cdd28.h"
#include "03/unk_021da000.h"
#include "03/code_021d3488.h"

extern u8 gMenuPairObjectImageIds[][5];
extern u8 gMenuPairObjectPaletteIds[][5];

void AdvanceMenuPairObjectSlideIn4(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideIn3(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideIn2(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideIn1(TaskEntry *taskEntry);
void AdvanceMenuPairObjectSlideIn0(TaskEntry *taskEntry);

void CreateMenuPairObjects(u32 row);
void AdvanceUsbScanReport(u32 task);
