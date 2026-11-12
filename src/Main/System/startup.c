#include "Main/System/startup.h"
#include "Main/System/heap_call.h"
#include "code_02152ac8.h"

#include "Main/Scene/display_settings.h"
#include "code_0200eddc.h"
#include "Main/System/heap_exp_over_block.h"
#include "Main/System/input_keys.h"
#include "unk_02000000.h"
#include "Main/Race/data_02164000.h"
#include "Main/Menu/data_02175000.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "code_02148950.h"
#include "os_tick.h"
#include "code_0200f790.h"
#include "gx.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_02004dc0.h"
#include "registers.h"

DisplaySettings *gDisplaySettings;

void VBlankIrqHandler(void) {
    if (gDisplaySettings != NULL) {
        ClearFrameFinishedFlag();
        if (gDisplaySettings->mIrqCallback != NULL) {
            gDisplaySettings->mIrqCallback();
        }
    }
    *OFFSET_PTR(u32, &gDtcmData, 0x3ff8) |= 1;
}

void EnableVBlankIrq(void) {
    OS_SetIrqFunction(1, VBlankIrqHandler);
    OS_EnableIrqMask(1);
    reg_OS_IME;
    reg_OS_IME = 1;
    OS_EnableInterrupts();
    GX_VBlankIntr(1);
}

void InitStartupLibraries(void) {
    OS_DisableMainExArena();
    OS_Init();
    data_02174e78.mUnk_00 = 0;
    OS_InitTick();
    OS_InitAlarm();
    FX_Init();
    GX_Init();
    InitWvrState();
    ClearLcdcBanksByState();
    GX_DispOff();
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0x10000;
    OS_SetIrqFunction(1, VBlankIrqHandler);
    OS_EnableIrqMask(1);
    reg_OS_IME;
    reg_OS_IME = 1;
    OS_EnableInterrupts();
    GX_VBlankIntr(1);
    FS_Init(-1);
    InitUnreadHalfwordGroups();
    data_usa_02174e54 = DWC_Init(data_usa_02174e80);
    ClearLcdcBankAndStartWvrAndWait();
}

void GetArenaLoHiNop(void) {
    OS_GetArenaLo(0);
    OS_GetArenaHi(0);
    OS_GetArenaLo(3);
    OS_GetArenaHi(3);
    OS_GetArenaLo(4);
    OS_GetArenaHi(4);
}

void InitStartup(void) {
    u8 *arenaLo;
    InitStartupLibraries();
    InitBrightnessFades();
    data_02174e78.mArm9TextStart = (u32) ARM9_TEXT_START;
    data_02174e78.mArenaLo = OS_GetArenaLo(0);
    GetArenaLoHiNop();
    arenaLo = OS_GetArenaLo(0);
    data_02174e78.mHeap = CreateExpHeapOverBlock(arenaLo, (u8 *) OS_GetArenaHi(0) - arenaLo);
    InitHeapCall(&gRootHeapCall, 0);
    data_02174e78.mUnk_10 = "MainProc";
    StartupResetKeysInputSlot();
}

void RunRootHeapCall(u32 func) {
    SetHeapCallFunc(&gRootHeapCall, func);
    RunHeapCall(&gRootHeapCall, 0xbeef);
}

void *GetArenaHeap(void) {
    return data_02174e78.mHeap;
}
