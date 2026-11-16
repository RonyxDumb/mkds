#pragma once

#include "types.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/Menu/multi_select_member_group.h"

void InitMultiSelectNS(void *parentHeap, void *scene, void *oamList);
void MultiSelectNSMI_CpuClearFast(void *destination, u32 size);
void MultiSelectNSMI_CpuFillFast(void *destination, u32 value, u32 size);
void RefreshMultiSelectNS(s32 showSelected);
void SetMultiSelectNSCellTableOffsetY(void);

extern const u16 gMultiSelectNSRowCellIndices[2][3];
extern const MultiSelectNSLabelMessageRow gMultiSelectNSLabelMessageRows[2];
extern u32 gMultiSelectNSLabelValues[2];
// Frames of the slide in and out, frames the press waits before the slide out.
#define MULTI_SELECT_NS_SLIDE_FRAMES 10
#define MULTI_SELECT_NS_PRESS_FRAMES 5

extern struct WLMenuCallbacks gMultiSelectNSCallbacks;
extern struct MultiSelectNS *gMultiSelectNS;
