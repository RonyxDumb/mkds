#include "Main/Menu/message_screen.h"
#include "registers.h"

#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Graphics/text_canvas.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/back_screen_keyboard_tables.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/multiboot_child_files.h"
#include "Main/Net/download_screen_files.h"
#include "wireless_link_control.h"
#include "vram_transfer_queue.h"
#include "cpu_copy_clear_16.h"
#include "Main/Graphics/cell_layout.h"
#include "Main/System/heap.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "Main/System/input_keys.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/Graphics/text_draw.h"
#include "arena_cache_init.h"
#include "char_canvas_text_draw.h"
#include "display_blend_affine_setup.h"
#include "vram_load_2d_graphics.h"
#include "cpu_copy_fill.h"
#include "Main/System/stdio_files.h"
#include "print_memory_multibyte_write.h"
#include "capture_output_effect.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "fixed_point_graphics_setup.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

char g_str_common_bmg_7[11] = "common.bmg";
const u8 gLinkLevelIconSlotCellEntryIndices[4] = {0, 1, 0, 0};
const u8 gLinkLevelIconCharCounts[8] = {4, 4, 1, 1, 1, 0, 0, 0};
const u8 gLinkLevelIconCharCellEntryIndices[5][4] = {
    {4, 5, 6, 7}, {0, 1, 2, 3}, {8, 0, 0, 0}, {9, 0, 0, 0}, {0xa, 0, 0, 0}};
LinkLevelIcons *g_GlobalNN;
MessageScreen *g_Global1A44;

void InitializeGlobal1A44_from_thumb(void *heap) {
    MessageScreen *messageScreen;
    TextCanvas *textCanvas;
    messageScreen = Mem_AllocateHeap(heap, sizeof(*messageScreen));
    g_Global1A44 = messageScreen;
    G2d_Sprite_CreateFromTiles(messageScreen->mCharCanvas, messageScreen->mCharBuffer, 0x20, 5, 4);
    messageScreen = g_Global1A44;
    textCanvas = &messageScreen->mTextCanvas;
    messageScreen->mTextCanvas.mCharCanvas = messageScreen->mCharCanvas;
    textCanvas->mFont = NULL;
    textCanvas->mCharSpacing = 1;
    textCanvas->mLineSpacing = 2;
    ResetMultiplayErrors_from_thumb();
}

void ResetMultiplayErrors_from_thumb(void) {
    g_Global1A44->mOpen = FALSE;
    g_Global1A44->mResult = -1;
}

s32 UpdateMessageScreen(void) {
    MessageScreen *messageScreen;
    if (g_Global1A44->mOpen == FALSE) {
        return -1;
    }
    SetBrightness(&reg_GX_MASTER_BRIGHT, 0);
    SetBrightness(&reg_GXS_DB_MASTER_BRIGHT, 0);
    if ((u16) (g_GlobalG.mPressedBits & PAD_KEY_A) != 0) {
        messageScreen = g_Global1A44;
        if (messageScreen->mInputEnabled != 0) {
            if ((u32) (messageScreen->mKind - MESSAGE_KIND_WIFI_ERROR) <= 1) {
                g_GlobalB488->mWiFiTopMenuRequested = TRUE;
                g_Global1A44->mResult = 1;
            } else if (messageScreen->mKind == MESSAGE_KIND_WIFI_OPPONENT_LEFT) {
                g_GlobalB488->mWiFiMenuStartKind = 1;
                g_Global1A44->mResult = 1;
                ClearWiFiDisconnectStatus();
            } else {
                messageScreen->mResult = 0;
            }
        }
    }
    return g_Global1A44->mResult;
}
#pragma thumb off

#pragma thumb on
void Clear1A44SomeTileData_from_thumb(void) {
    Mem_CpuFill8(g_Global1A44->mCharBuffer, 0u, 0x1400u);
}
#pragma thumb off

#pragma thumb on

void *GetSomeBgCanvasTileData_from_thumb(void) {
    return g_Global1A44->mCharBuffer;
}

#pragma thumb off

#pragma thumb on
void CleanTemporaryMultiplayErrorBuffer_from_thumb(void) {
    volatile u16 zero;
    zero = 0;
    Mem_CpuFill16(zero, g_Global1A44->mScreenMap, 0x600);
}

void *GetMultiplayerErrorString_from_thumb(void) {
    void *messages;
    s32 kind;
    messages = NULL;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        messages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("common.bmg");
    }
    kind = g_Global1A44->mKind;
    if (kind == MESSAGE_KIND_WIFI_ERROR) {
        return Bmg_GetRawStringPointer_from_thumb(messages, 0x86);
    }
    if (kind == MESSAGE_KIND_WIFI_NO_INPUT) {
        return Bmg_GetRawStringPointer_from_thumb(messages, 0x87);
    }
    if (kind == MESSAGE_KIND_WIFI_OPPONENT_LEFT) {
        return Bmg_GetRawStringPointer_from_thumb(messages, 0x88);
    }
    if (kind == MESSAGE_KIND_BACKUP_ERROR_OTHER_STATUS) {
        return Bmg_GetRawStringPointer_from_thumb(messages, 0x83);
    }
    if (kind == MESSAGE_KIND_BACKUP_ERROR_WHILE_WRITING) {
        return Bmg_GetRawStringPointer_from_thumb(messages, 0x84);
    }
    if (kind == MESSAGE_KIND_CARD_PULLED_OUT) {
        return Bmg_GetRawStringPointer_from_thumb(messages, 0x85);
    }
    if (kind == MESSAGE_KIND_CONNECTION_ERROR) {
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            return Bmg_GetRawStringPointer_from_thumb(GetGlobal2DObject()->mMBChildMessages, 0);
        }
        return Bmg_GetRawStringPointer_from_thumb(messages, 0x82);
    }
    return NULL;
}

void DrawMultiplayError_from_thumb(void) {
    s32 mapIndex;
    Clear1A44SomeTileData_from_thumb();
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        g_Global1A44->mTextCanvas.mFont = &GetGlobal2DObject()->mMBChildFont;
    } else {
        g_Global1A44->mTextCanvas.mFont = GetLoadedFont_from_thumb(0);
    }
    G2d_Text_PrintString(&g_Global1A44->mTextCanvas, 0x80, 0x14, 0xe, 0x412, g_Global1A44->mText);
    CleanTemporaryMultiplayErrorBuffer_from_thumb();
    for (mapIndex = 0; mapIndex < 0x300; mapIndex++) {
        if (mapIndex >= 0x120 && mapIndex < 0x1c0) {
            g_Global1A44->mScreenMap[mapIndex] = (mapIndex - 0x120) | 0xf000;
        } else {
            g_Global1A44->mScreenMap[mapIndex] = 0xf09f;
        }
    }
    *(vu16 *) 0x50001fc = 0xffff;
    *(vu16 *) 0x5000000 = 0;
    reg_G2_BG1OFS = 0;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~REG_G2_BG1CNT_MOSAIC_MASK;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0x400;
    Arm_FlushRange(g_Global1A44->mCharBuffer, 0x1400);
    Arm_FlushRange(g_Global1A44->mScreenMap, 0x600);
    CopyBgData_Bg1_Top(g_Global1A44->mCharBuffer, 0, 0x1400);
    TEQSub_Fn9Impl(g_Global1A44->mScreenMap, 0, 0x600);
}

void MaybeFormatMultiplayNetErrorCode_from_thumb(void) {
    u16 text[11];
    text[0] = 0;
    Mem_CpuFill16(text[0], &text[1], 0x14);
    FormatIntegerInString16_from_thumb(GetMaybeNetErrorCode(), &text[1]);
    MaybeHandleBmgFormatting_from_thumb(&text[1], g_Global1A44->mText, g_Global1A44->mScreenMap, 0x600);
    g_Global1A44->mText = g_Global1A44->mScreenMap;
}

void DisplayMultiplayError_from_thumb(s32 messageKind, s32 inputEnabled) {
    u32 bits8To12;
    if (g_Global1A44->mOpen == FALSE && messageKind != -1) {
        g_Global1A44->mOpen = TRUE;
        g_Global1A44->mInputEnabled = inputEnabled;
        g_Global1A44->mKind = messageKind;
        g_Global1A44->mText = GetMultiplayerErrorString_from_thumb();
        if (g_Global1A44->mKind == MESSAGE_KIND_WIFI_ERROR) {
            MaybeFormatMultiplayNetErrorCode_from_thumb();
        }
        DrawMultiplayError_from_thumb();
        if (GetCurrentSceneId() == 2) {
            if (GetRaceHudStepHasRun() == 0) {
                reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x200;
                reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
                *(vu16 *) 0x5000400 = 0;
                reg_GX_DISPCNT =
                    reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
            } else {
                bits8To12 = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
                bits8To12 |= 2;
                reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | (bits8To12 << 8);
            }
            UpdateBldcntBldalphaBldy(&reg_G2_BLDCNT, 0x1d, 0, 8, 8, -11);
        } else {
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x200;
            reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
            *(vu16 *) 0x5000400 = 0;
            reg_GX_DISPCNT =
                reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
            reg_G2_BLDCNT = 0;
            reg_G2S_DB_BLDCNT = 0;
        }
    }
}

void CreateGlobalNN_from_thumb(void *heap, void *oamList) {
    s32 index;
    LinkLevelIcons *linkLevelIcons;
    LinkLevelIconOam *oam;
    g_GlobalNN = Mem_AllocateHeap(heap, sizeof(*g_GlobalNN));
    g_GlobalNN->mOamList = oamList;
    Mem_CpuFill8(g_GlobalNN->mZeroChars, 0, sizeof(g_GlobalNN->mZeroChars));
    g_GlobalNN->mCycleFrames = 0;
    for (index = 0; index < 5; index++) {
        g_GlobalNN->mIconEnabled[index] = 0;
    }
    switch (GetCurrentSceneId()) {
        case SCENE_MENU_1:
            if ((u32) (g_GlobalP->mConnectionKind - CONNECTION_KIND_MEMBER_SELECT) <=
                CONNECTION_KIND_WL_MENU - CONNECTION_KIND_MEMBER_SELECT) {
                g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIRELESS] = 1;
            }
            break;
        case SCENE_WL_MENU:
        case SCENE_GHOST:
            g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIRELESS] = 1;
            break;
        case SCENE_WIFI_MENU:
            g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIFI_BUDDY] = 1;
            break;
        case SCENE_RESULT:
            if (g_GlobalP->mConnectionKind == CONNECTION_KIND_WIFI_MENU) {
                g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIFI] = 1;
                g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIFI_BUDDY] = 1;
            } else if ((u32) (g_GlobalP->mConnectionKind - CONNECTION_KIND_MEMBER_SELECT) <=
                       CONNECTION_KIND_WL_MENU - CONNECTION_KIND_MEMBER_SELECT) {
                g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIRELESS] = 1;
            }
            break;
        case SCENE_RECORD:
            if (g_GlobalP->mConnectionKind == CONNECTION_KIND_WIFI_MENU) {
                g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIFI] = 1;
                g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIFI_BUDDY] = 1;
            }
            break;
    }
    for (index = 0; index < 2; index++) {
        g_GlobalNN->mIconKind[index] = -1;
    }
    SetupLinkLevelIcons();
    for (index = 0; index < 2; index++) {
        linkLevelIcons = g_GlobalNN;
        oam = &linkLevelIcons->mOamRecords[index];
        oam->mPositionAndSizeBits = ((linkLevelIcons->mIconPositions[index].mX & 0x1ff) << 16) |
                                    ((linkLevelIcons->mIconPositions[index].mY & 0xff) | 0x40000000);
        oam->mCharAndPaletteBits = (0x400 - (index + 1) * 4) | 0xd000;
    }
}
#pragma thumb off

#pragma thumb on
void ResetGlobalNN_from_thumb(void) {
    g_GlobalNN = NULL;
}
#pragma thumb off

#pragma thumb on
void SetupLinkLevelIcons(void) {
    s32 iconIndex;
    Ncgr *chars;
    NNSG2dCellDataBank *cells;
    Nclr *palette;
    void *searchIconCellLayout;
    LayoutEntryTable *cellLayout;
    DownloadScreenFiles *loadedFiles;
    CellLayoutEntry *cellEntry;
    s32 charIndex;
    loadedFiles = GetGlobal2DObject();
    searchIconCellLayout = loadedFiles->mSearchIconCellLayout;
    cellLayout = loadedFiles->mSearchIconLayoutCellLayout;
    chars = loadedFiles->mSearchIconChars;
    cells = loadedFiles->mSearchIconCells;
    palette = loadedFiles->mSearchIconPalette;
    for (iconIndex = 0; iconIndex < 5; iconIndex++) {
        for (charIndex = 0; charIndex < gLinkLevelIconCharCounts[iconIndex]; charIndex++) {
            g_GlobalNN->mIconChars[iconIndex][charIndex] =
                chars->mTiles +
                GetCellCharIndex(gLinkLevelIconCharCellEntryIndices[iconIndex][charIndex], cells, searchIconCellLayout);
        }
    }
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        cellEntry = GetCellLayoutEntry(cellLayout, gLinkLevelIconSlotCellEntryIndices[iconIndex]);
        g_GlobalNN->mIconPositions[iconIndex].mX = GetLayoutAxisStartX(cellEntry->mAxisX, 0x10);
        g_GlobalNN->mIconPositions[iconIndex].mY = GetLayoutAxisStartY(cellEntry->mAxisY, 0x10);
    }
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_SPRITE_TILES, (0x400 - (iconIndex + 1) * 4) << 5,
                                           g_GlobalNN->mZeroChars, 0x80);
    }
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0x1a0, palette->mData + 0xd0, 0x20);
}

void UpdateLinkLevelIconTiles(void) {
    s32 slotCount;
    s32 iconIndex;
    s32 linkLevel;
    BOOL flag;
    slotCount = 0;
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        g_GlobalNN->mIconKind[iconIndex] = -1;
        g_GlobalNN->mIconLevel[iconIndex] = 0;
    }
    if (g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIFI] != 0) {
        g_GlobalNN->mIconKind[0] = LINK_LEVEL_ICON_WIFI;
        g_GlobalNN->mIconLevel[0] = GetWiFiLinkLevel();
        slotCount = 1;
    }
    if (g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIRELESS] != 0) {
        g_GlobalNN->mIconKind[slotCount] = LINK_LEVEL_ICON_WIRELESS;
        linkLevel = 0;
        if (g_GlobalZE->mState != CONNECTION_STATE_IDLE) {
            linkLevel = WM_GetLinkLevel();
        }
        g_GlobalNN->mIconLevel[slotCount] = linkLevel;
    } else if (g_GlobalNN->mIconEnabled[LINK_LEVEL_ICON_WIFI_BUDDY] != 0) {
        flag = FALSE;
        if (!g_SaveDataHolder->mFirstBlock->mLocateFriendOff) {
            if (HasWiFiBuddyStatus4() != FALSE) {
                flag = TRUE;
            }
        }
        if (flag != FALSE) {
            g_GlobalNN->mIconKind[slotCount] = LINK_LEVEL_ICON_WIFI_BUDDY;
        }
    }
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        if (g_GlobalNN->mIconKind[iconIndex] == -1) {
            AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_SPRITE_TILES, (0x400 - (iconIndex + 1) * 4) << 5,
                                               g_GlobalNN->mZeroChars, 0x80);
        } else {
            AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_SPRITE_TILES, (0x400 - (iconIndex + 1) * 4) << 5,
                                               g_GlobalNN->mIconChars[g_GlobalNN->mIconKind[iconIndex]]
                                                                          [g_GlobalNN->mIconLevel[iconIndex]],
                                               0x80);
        }
    }
}

void AdvanceLinkLevelIcons(void) {
    s32 iconIndex;
    u32 iconKind;
    g_GlobalNN->mCycleFrames++;
    if (g_GlobalNN->mCycleFrames > LINK_LEVEL_ICON_CYCLE_FRAMES) {
        g_GlobalNN->mCycleFrames = 0;
    }
    UpdateLinkLevelIconTiles();
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        iconKind = g_GlobalNN->mIconKind[iconIndex];
        if (g_GlobalNN->mCycleFrames < LINK_LEVEL_ICON_HIDDEN_FROM_FRAME || iconKind <= LINK_LEVEL_ICON_WIFI) {
            CopyMemory16(&g_GlobalNN->mOamRecords[iconIndex],
                          &g_GlobalNN->mOamList->mOams[g_GlobalNN->mOamList->mOamCount], 6);
            g_GlobalNN->mOamList->mOamCount++;
        }
    }
}
#pragma thumb off

#pragma thumb on
void SetLinkLevelIconEnabled(u32 index, u32 enabled) {
    g_GlobalNN->mIconEnabled[index] = enabled;
}
#pragma thumb off
