#pragma once

#include "types.h"
#include "03/code_021cdd28.h"
#include "03/unk_021da000.h"
#include "03/System/tasks.h"

void AdvanceMenuPairObjectSlideIn4(TaskEntry *taskEntry, void *arg);
void AdvanceMenuPairObjectSlideIn3(TaskEntry *taskEntry, void *arg);
void AdvanceMenuPairObjectSlideIn2(TaskEntry *taskEntry, void *arg);
void AdvanceMenuPairObjectSlideIn1(TaskEntry *taskEntry, void *arg);
void AdvanceMenuPairObjectSlideIn0(TaskEntry *taskEntry, void *arg);

void CreateMenuPairObjects(u32 row);
void AdvanceUsbScanReport(TaskEntry *task, void *arg);
