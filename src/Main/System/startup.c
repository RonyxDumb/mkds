#include "Main/System/startup.h"
#include "Main/System/heap_call.h"
#include "wifi_account_init.h"

#include "Main/Scene/display_settings.h"
#include "arena_cache_init.h"
#include "Main/System/heap_exp_over_block.h"
#include "Main/System/input_keys.h"
#include "build_info_layout.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "vram_bank_display_setup.h"
#include "tick_counter.h"
#include "alarm_timer.h"
#include "fixed_point_graphics_setup.h"
#include "interrupt_control.h"
#include "reset_interrupts_halt.h"
#include "overlay_rom_loader.h"
#include "registers.h"

DisplaySettings *g_GlobalDisplayConfig;

void VblankIRQHandler(void) {
    if (g_GlobalDisplayConfig != NULL) {
        ClearFrameFinishedFlag();
        if (g_GlobalDisplayConfig->mIrqCallback != NULL) {
            g_GlobalDisplayConfig->mIrqCallback();
        }
    }
    IRQ_CHECK_FLAGS |= 1;
}

void EnableVblankIRQ(void) {
    Os_SetIrqHandler(1, VblankIRQHandler);
    Os_EnableIrqHandler(1);
    reg_OS_IME;
    reg_OS_IME = 1;
    Os_EnableIrq();
    GX_VBlankIntr(1);
}

void InitializeSDKModules(void) {
    Os_DisableMainExRegion();
    Os_Initialize();
    g_GlobalGG.mUnk_00 = 0;
    Os_InitializeTick();
    Os_InitializeAlarm();
    FX_Initialize();
    Gfx_Initialize();
    SomeVramInit();
    MaybePrepareVram();
    SomeDispcntInit();
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0x10000;
    Os_SetIrqHandler(1, VblankIRQHandler);
    Os_EnableIrqHandler(1);
    reg_OS_IME;
    reg_OS_IME = 1;
    Os_EnableIrq();
    GX_VBlankIntr(1);
    Fs_Initialize(-1);
    InitializeGlobalHN();
    g_DwcStatus = MaybeInitializeDwc_from_thumb(gDwcInitWork);
    SomeVramConfig();
}

void MemoryRegionAddressAccess(void) {
    Os_GetMemoryRegionStartAddress(0);
    Os_GetMemoryRegionEndAddress(0);
    Os_GetMemoryRegionStartAddress(3);
    Os_GetMemoryRegionEndAddress(3);
    Os_GetMemoryRegionStartAddress(4);
    Os_GetMemoryRegionEndAddress(4);
}

void InitializeEverything(void) {
    u8 *arenaLo;
    InitializeSDKModules();
    InitializeBrightnessContexts();
    g_GlobalGG.mArm9TextStart = (u32) ARM9_TEXT_START;
    g_GlobalGG.mArenaLo = Os_GetMemoryRegionStartAddress(0);
    MemoryRegionAddressAccess();
    arenaLo = Os_GetMemoryRegionStartAddress(0);
    g_GlobalGG.mHeap = Mem_CreateExpHeap(arenaLo, (u8 *) Os_GetMemoryRegionEndAddress(0) - arenaLo);
    ExecutionContext_Create(&g_GlobalGG.mRootHeapCall, 0);
    g_GlobalGG.mRootHeapCall.mName = "MainProc";
    InitializeGlobalG_M1();
}

void SetExecuteStart(u32 func) {
    ExecutionContext_SetFunction(&g_GlobalGG.mRootHeapCall, func);
    ExecutionContext_Execute(&g_GlobalGG.mRootHeapCall, 0xbeef);
}

void *GetGlobalHeapHandle(void) {
    return g_GlobalGG.mHeap;
}
