#pragma once

#include "types.h"
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
#include "Main/MapObjects/map_object_park.h"

void LoadWiFiVSCourseSelectFiles(void);

s32 AdvanceWiFiVSCourseSelect(void);

void InitWiFiVSCourseSelect(void *parentHeap, void *mainOam, void *subOam);

void WriteWiFiVSCourseSelectRegisters(void);

void ReleaseWiFiVSCourseSelect(void);

s32 PickRandomCourseIndexNotRaced(void);

void AdvanceWiFiVSCourseSelectTimer(void);

void AdvancePickedCourseRows(void);

void AdvanceSubCellsOffsetY(void);

void ShowWiFiSessionCourse(void);

void SetWiFiVSCourseSelectRowsOffsetY(void);

void RefreshCourseListRows(s32 action, s32 slot, s32 row, s32 selectedSlot);

void WriteKartPositionAndCount(s32 position, s32 kartCount);
