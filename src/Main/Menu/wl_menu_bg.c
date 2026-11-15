#include "Main/Menu/wl_menu_bg.h"
#include "Main/Scene/display_settings.h"
#include "Main/Menu/data_02175000.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "code_0214d018.h"

void WLMenuMI_CpuFillFast(void *dest, u32 fillValue, u32 size) {
    volatile u32 value = fillValue;

    MIi_CpuClearFast(value, dest, size);
}

void WLMenuMI_CpuClearFast(void *dest, u32 size) {
    WLMenuMI_CpuFillFast(dest, 0, size);
}

void WLMenuSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                            u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void WLMenuSetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}
