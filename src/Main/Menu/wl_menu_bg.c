#include "Main/Menu/wl_menu_bg.h"
#include "Main/Scene/display_settings.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "cpu_copy_fill.h"

void WLMenuMI_CpuFillFast(void *dest, u32 fillValue, u32 size) {
    volatile u32 value = fillValue;

    Mem_CpuFastMemorySet(value, dest, size);
}

void WLMenuMI_CpuClearFast(void *dest, u32 size) {
    WLMenuMI_CpuFillFast(dest, 0, size);
}

void DisplayConfig_SetTopEngineBg1Config_0(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                            u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    DisplayEngineConfig_SetBg1Config(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void DisplayConfig_SetBottomEngineBg3Config_0(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    DisplayEngineConfig_SetBg3Config(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}
