#include "Main/Menu/wl_menu_common_message.h"
#include "Main/Menu/wl_menu_message.h"
#include "thread_scheduler.h"
#include "Main/Sound/seq_zero_loop_wrapper.h"
#include "Main/Menu/wl_menu_mb_child_message.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"
#include "arena_cache_init.h"
#include "char_canvas_text_draw.h"
#include "bg_screen_char_pointers.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Menu/multi_select_member_group.h"
#include "touch_panel_sampling.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/backup_net_camera_work.h"
#include "vram_load_2d_graphics.h"
#include "Main/Menu/time_attack_ghost_get_scan.h"

#pragma optimize_for_size on

#pragma thumb on

void SetupWLMenuCommonMessage(void *heap) {
    void *text;
    u32 charBase;
    s32 column;
    s32 row;
    u16 entry;

    InitWLMenuMessage(heap);
    gWLMenuMessage->mState = WL_MENU_MESSAGE_STATE_RUN_MP_STATE_MACHINE;
    gWLMenuMessage->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gWLMenuMessage->mFont = GetFontByIndex(0);
    charBase = G2S_GetBG1CharPtr();
    text = GetBmgEntry(gWLMenuMessage->mCommonMessages, 0x79);
    NNS_G2dCharCanvasInitForBG(gWLMenuMessage->mCharCanvas, (void *) (charBase + 0x400), 0x20, 4, 4);
    WLMenuInitTextCanvas(&gWLMenuMessage->mTextCanvas, gWLMenuMessage->mCharCanvas, gWLMenuMessage->mFont, 1, 4);
    WLMenuDrawTextOnCanvas(&gWLMenuMessage->mTextCanvas, 8, 0, 3, 0x209, text);
    for (row = 0x16; row < 0x18; row++) {
        for (column = 0; column < 0x20; column++) {
            entry = (((column + row + 1) & 1) << 12) | 1;
            gWLMenuMessage->mScreenMap[column + row * 0x20] = entry;
        }
    }
    DC_StoreRange(gWLMenuMessage->mScreenMap, 0x600);
    GXS_LoadBG3Scr(gWLMenuMessage->mScreenMap, 0, 0x600);
    WLMenuMessageMI_CpuClearFast(gWLMenuMessage->mScreenMap, 0x600);
    for (row = 0x14; row < 0x16; row++) {
        for (column = 0; column < 0x20; column++) {
            gWLMenuMessage->mScreenMap[column + row * 0x20] = column + (row - 0x14) * 0x20 + 0x20;
        }
    }
    DC_StoreRange(gWLMenuMessage->mScreenMap, 0x600);
    GXS_LoadBG1Scr(gWLMenuMessage->mScreenMap, 0, 0x600);
    if (HasGroupSendMask() != 0) {
        StartSeqZeroLoopWrapper();
    }
    FrmHeapShrinkInParent(gWLMenuMessage->mHeap);
}

#pragma thumb off

u32 WLMenuIsMultiBootSetupStarted(void) {
    return (gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0;
}
