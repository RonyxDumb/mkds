#include "Main/Menu/message_screen.h"
#include "registers.h"

#include "Main/Menu/menu_screens_work.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Graphics/text_canvas.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/back_screen_keyboard_tables.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/multiboot_child_files.h"
#include "Main/Net/search_icon_mb_child_and.h"
#include "code_02142eac.h"
#include "gfd_VramTransferManager.h"
#include "code_0214cfe4.h"
#include "Main/Graphics/cell_layout.h"
#include "Main/System/heap.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/System/input_slots.h"
#include "Main/System/input_keys.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_draw.h"
#include "Main/Graphics/text_draw.h"
#include "code_0200eddc.h"
#include "g2d_CharCanvas.h"
#include "g2.h"
#include "gx_load2d.h"
#include "code_0214d018.h"
#include "Main/System/stdio_files.h"
#include "code_02134398.h"
#include "output_effect.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "gx.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

char gKeyboardCommonBmgName[11] = "common.bmg";
const u8 gLinkLevelIconSlotCellEntryIndices[4] = {0, 1, 0, 0};
const u8 gLinkLevelIconCharCounts[8] = {4, 4, 1, 1, 1, 0, 0, 0};
const u8 gLinkLevelIconCharCellEntryIndices[5][4] = {
    {4, 5, 6, 7}, {0, 1, 2, 3}, {8, 0, 0, 0}, {9, 0, 0, 0}, {0xa, 0, 0, 0}};
LinkLevelIcons *gLinkLevelIcons;
MessageScreen *gMessageScreen;

void InitMessageScreen(void *heap) {
    MessageScreen *messageScreen;
    TextCanvas *textCanvas;
    messageScreen = HeapAlloc(heap, sizeof(*messageScreen));
    gMessageScreen = messageScreen;
    NNS_G2dCharCanvasInitForBG(messageScreen->mCharCanvas, messageScreen->mCharBuffer, 0x20, 5, 4);
    messageScreen = gMessageScreen;
    textCanvas = &messageScreen->mTextCanvas;
    messageScreen->mTextCanvas.mCharCanvas = messageScreen->mCharCanvas;
    textCanvas->mFont = NULL;
    textCanvas->mCharSpacing = 1;
    textCanvas->mLineSpacing = 2;
    ResetMessageScreen();
}

void ResetMessageScreen(void) {
    gMessageScreen->mOpen = FALSE;
    gMessageScreen->mResult = -1;
}

s32 UpdateMessageScreen(void) {
    MessageScreen *messageScreen;
    if (gMessageScreen->mOpen == FALSE) {
        return -1;
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0);
    if ((u16) (gKeysInputSlot.mPressedBits & PAD_KEY_A) != 0) {
        messageScreen = gMessageScreen;
        if (messageScreen->mInputEnabled != 0) {
            if ((u32) (messageScreen->mKind - MESSAGE_KIND_WIFI_ERROR) <= 1) {
                gMenuShared->mWiFiTopMenuRequested = TRUE;
                gMessageScreen->mResult = 1;
            } else if (messageScreen->mKind == MESSAGE_KIND_WIFI_OPPONENT_LEFT) {
                gMenuShared->mWiFiMenuStartKind = 1;
                gMessageScreen->mResult = 1;
                ClearWiFiDisconnectStatus();
            } else {
                messageScreen->mResult = 0;
            }
        }
    }
    return gMessageScreen->mResult;
}
#pragma thumb off

#pragma thumb on
void ClearMessageScreenChars(void) {
    MI_CpuFill8(gMessageScreen->mCharBuffer, 0u, 0x1400u);
}
#pragma thumb off

#pragma thumb on

void *GetMessageScreenCharBuffer(void) {
    return gMessageScreen->mCharBuffer;
}

#pragma thumb off

#pragma thumb on
void ClearMessageScreenMap(void) {
    volatile u16 zero;
    zero = 0;
    MIi_CpuClear16(zero, gMessageScreen->mScreenMap, 0x600);
}

void *GetMessageScreenText(void) {
    void *messages;
    s32 kind;
    messages = NULL;
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        messages = FindFileInLoadedArchives("common.bmg");
    }
    kind = gMessageScreen->mKind;
    if (kind == MESSAGE_KIND_WIFI_ERROR) {
        return GetBmgEntry(messages, 0x86);
    }
    if (kind == MESSAGE_KIND_WIFI_NO_INPUT) {
        return GetBmgEntry(messages, 0x87);
    }
    if (kind == MESSAGE_KIND_WIFI_OPPONENT_LEFT) {
        return GetBmgEntry(messages, 0x88);
    }
    if (kind == MESSAGE_KIND_BACKUP_ERROR_OTHER_STATUS) {
        return GetBmgEntry(messages, 0x83);
    }
    if (kind == MESSAGE_KIND_BACKUP_ERROR_WHILE_WRITING) {
        return GetBmgEntry(messages, 0x84);
    }
    if (kind == MESSAGE_KIND_CARD_PULLED_OUT) {
        return GetBmgEntry(messages, 0x85);
    }
    if (kind == MESSAGE_KIND_CONNECTION_ERROR) {
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            return GetBmgEntry(GetDownloadScreenFiles()->mMBChildMessages, 0);
        }
        return GetBmgEntry(messages, 0x82);
    }
    return NULL;
}

void PrintMessageScreenText(void) {
    s32 mapIndex;
    ClearMessageScreenChars();
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        gMessageScreen->mTextCanvas.mFont = &GetDownloadScreenFiles()->mMBChildFont;
    } else {
        gMessageScreen->mTextCanvas.mFont = GetFontByIndex(0);
    }
    NNSi_G2dTextCanvasDrawText(&gMessageScreen->mTextCanvas, 0x80, 0x14, 0xe, 0x412, gMessageScreen->mText);
    ClearMessageScreenMap();
    for (mapIndex = 0; mapIndex < 0x300; mapIndex++) {
        if (mapIndex >= 0x120 && mapIndex < 0x1c0) {
            gMessageScreen->mScreenMap[mapIndex] = (mapIndex - 0x120) | 0xf000;
        } else {
            gMessageScreen->mScreenMap[mapIndex] = 0xf09f;
        }
    }
    *(vu16 *) 0x50001fc = 0xffff;
    *(vu16 *) 0x5000000 = 0;
    reg_G2_BG1OFS = 0;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~REG_G2_BG1CNT_MOSAIC_MASK;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & (REG_G2_BG1CNT_PRIORITY_MASK | REG_G2_BG1CNT_MOSAIC_MASK)) | 0x400;
    DC_FlushRange(gMessageScreen->mCharBuffer, 0x1400);
    DC_FlushRange(gMessageScreen->mScreenMap, 0x600);
    GX_LoadBG1Char(gMessageScreen->mCharBuffer, 0, 0x1400);
    GX_LoadBG1Scr(gMessageScreen->mScreenMap, 0, 0x600);
}

void FormatMessageScreenErrorCode(void) {
    u16 text[11];
    text[0] = 0;
    MIi_CpuClear16(text[0], &text[1], 0x14);
    FormatAsciiNumber(GetWiFiSessionErrorCodeNegated(), &text[1]);
    FormatMessageWithText(&text[1], gMessageScreen->mText, gMessageScreen->mScreenMap, 0x600);
    gMessageScreen->mText = gMessageScreen->mScreenMap;
}

void OpenMessageScreen(s32 messageKind, s32 inputEnabled) {
    u32 bits8To12;
    if (gMessageScreen->mOpen == FALSE && messageKind != -1) {
        gMessageScreen->mOpen = TRUE;
        gMessageScreen->mInputEnabled = inputEnabled;
        gMessageScreen->mKind = messageKind;
        gMessageScreen->mText = GetMessageScreenText();
        if (gMessageScreen->mKind == MESSAGE_KIND_WIFI_ERROR) {
            FormatMessageScreenErrorCode();
        }
        PrintMessageScreenText();
        if (GetCurrentSceneNumber() == 2) {
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
            G2x_SetBlendBrightnessExt_(&reg_G2_BLDCNT, 0x1d, 0, 8, 8, -11);
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

void InitLinkLevelIcons(void *heap, void *oamList) {
    s32 index;
    LinkLevelIcons *linkLevelIcons;
    LinkLevelIconOam *oam;
    gLinkLevelIcons = HeapAlloc(heap, sizeof(*gLinkLevelIcons));
    gLinkLevelIcons->mOamList = oamList;
    MI_CpuFill8(gLinkLevelIcons->mZeroChars, 0, sizeof(gLinkLevelIcons->mZeroChars));
    gLinkLevelIcons->mCycleFrames = 0;
    for (index = 0; index < 5; index++) {
        gLinkLevelIcons->mIconEnabled[index] = 0;
    }
    switch (GetCurrentSceneNumber()) {
        case SCENE_MENU_1:
            if ((u32) (gStartupWork->mConnectionKind - CONNECTION_KIND_MEMBER_SELECT) <=
                CONNECTION_KIND_WL_MENU - CONNECTION_KIND_MEMBER_SELECT) {
                gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIRELESS] = 1;
            }
            break;
        case SCENE_WL_MENU:
        case SCENE_GHOST:
            gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIRELESS] = 1;
            break;
        case SCENE_WIFI_MENU:
            gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIFI_BUDDY] = 1;
            break;
        case SCENE_RESULT:
            if (gStartupWork->mConnectionKind == CONNECTION_KIND_WIFI_MENU) {
                gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIFI] = 1;
                gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIFI_BUDDY] = 1;
            } else if ((u32) (gStartupWork->mConnectionKind - CONNECTION_KIND_MEMBER_SELECT) <=
                       CONNECTION_KIND_WL_MENU - CONNECTION_KIND_MEMBER_SELECT) {
                gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIRELESS] = 1;
            }
            break;
        case SCENE_RECORD:
            if (gStartupWork->mConnectionKind == CONNECTION_KIND_WIFI_MENU) {
                gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIFI] = 1;
                gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIFI_BUDDY] = 1;
            }
            break;
    }
    for (index = 0; index < 2; index++) {
        gLinkLevelIcons->mIconKind[index] = -1;
    }
    SetupLinkLevelIcons();
    for (index = 0; index < 2; index++) {
        linkLevelIcons = gLinkLevelIcons;
        oam = &linkLevelIcons->mOamRecords[index];
        oam->mPositionAndSizeBits = ((linkLevelIcons->mIconPositions[index].mX & 0x1ff) << 16) |
                                    ((linkLevelIcons->mIconPositions[index].mY & 0xff) | 0x40000000);
        oam->mCharAndPaletteBits = (0x400 - (index + 1) * 4) | 0xd000;
    }
}
#pragma thumb off

#pragma thumb on
void ClearLinkLevelIconsPointer(void) {
    gLinkLevelIcons = NULL;
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
    loadedFiles = GetDownloadScreenFiles();
    searchIconCellLayout = loadedFiles->mSearchIconCellLayout;
    cellLayout = loadedFiles->mSearchIconLayoutCellLayout;
    chars = loadedFiles->mSearchIconChars;
    cells = loadedFiles->mSearchIconCells;
    palette = loadedFiles->mSearchIconPalette;
    for (iconIndex = 0; iconIndex < 5; iconIndex++) {
        for (charIndex = 0; charIndex < gLinkLevelIconCharCounts[iconIndex]; charIndex++) {
            gLinkLevelIcons->mIconChars[iconIndex][charIndex] =
                chars->mTiles +
                GetCellCharIndex(gLinkLevelIconCharCellEntryIndices[iconIndex][charIndex], cells, searchIconCellLayout);
        }
    }
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        cellEntry = GetCellLayoutEntry(cellLayout, gLinkLevelIconSlotCellEntryIndices[iconIndex]);
        gLinkLevelIcons->mIconPositions[iconIndex].mX = GetLayoutAxisStartX(cellEntry->mAxisX, 0x10);
        gLinkLevelIcons->mIconPositions[iconIndex].mY = GetLayoutAxisStartY(cellEntry->mAxisY, 0x10);
    }
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_TILES, (0x400 - (iconIndex + 1) * 4) << 5,
                                           gLinkLevelIcons->mZeroChars, 0x80);
    }
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0x1a0, palette->mData + 0xd0, 0x20);
}

void UpdateLinkLevelIconTiles(void) {
    s32 slotCount;
    s32 iconIndex;
    s32 linkLevel;
    BOOL flag;
    slotCount = 0;
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        gLinkLevelIcons->mIconKind[iconIndex] = -1;
        gLinkLevelIcons->mIconLevel[iconIndex] = 0;
    }
    if (gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIFI] != 0) {
        gLinkLevelIcons->mIconKind[0] = LINK_LEVEL_ICON_WIFI;
        gLinkLevelIcons->mIconLevel[0] = GetWiFiLinkLevel();
        slotCount = 1;
    }
    if (gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIRELESS] != 0) {
        gLinkLevelIcons->mIconKind[slotCount] = LINK_LEVEL_ICON_WIRELESS;
        linkLevel = 0;
        if (gConnectionWork->mState != CONNECTION_STATE_IDLE) {
            linkLevel = WM_GetLinkLevel();
        }
        gLinkLevelIcons->mIconLevel[slotCount] = linkLevel;
    } else if (gLinkLevelIcons->mIconEnabled[LINK_LEVEL_ICON_WIFI_BUDDY] != 0) {
        flag = FALSE;
        if (!gBackupBuffers->mFirstBlock->mLocateFriendOff) {
            if (HasWiFiBuddyStatus4() != FALSE) {
                flag = TRUE;
            }
        }
        if (flag != FALSE) {
            gLinkLevelIcons->mIconKind[slotCount] = LINK_LEVEL_ICON_WIFI_BUDDY;
        }
    }
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        if (gLinkLevelIcons->mIconKind[iconIndex] == -1) {
            NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_TILES, (0x400 - (iconIndex + 1) * 4) << 5,
                                               gLinkLevelIcons->mZeroChars, 0x80);
        } else {
            NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_TILES, (0x400 - (iconIndex + 1) * 4) << 5,
                                               gLinkLevelIcons->mIconChars[gLinkLevelIcons->mIconKind[iconIndex]]
                                                                          [gLinkLevelIcons->mIconLevel[iconIndex]],
                                               0x80);
        }
    }
}

void AdvanceLinkLevelIcons(void) {
    s32 iconIndex;
    u32 iconKind;
    gLinkLevelIcons->mCycleFrames++;
    if (gLinkLevelIcons->mCycleFrames > LINK_LEVEL_ICON_CYCLE_FRAMES) {
        gLinkLevelIcons->mCycleFrames = 0;
    }
    UpdateLinkLevelIconTiles();
    for (iconIndex = 0; iconIndex < 2; iconIndex++) {
        iconKind = gLinkLevelIcons->mIconKind[iconIndex];
        if (gLinkLevelIcons->mCycleFrames < LINK_LEVEL_ICON_HIDDEN_FROM_FRAME || iconKind <= LINK_LEVEL_ICON_WIFI) {
            MIi_CpuCopy16(&gLinkLevelIcons->mOamRecords[iconIndex],
                          &gLinkLevelIcons->mOamList->mOams[gLinkLevelIcons->mOamList->mOamCount], 6);
            gLinkLevelIcons->mOamList->mOamCount++;
        }
    }
}
#pragma thumb off

#pragma thumb on
void SetLinkLevelIconEnabled(u32 index, u32 enabled) {
    gLinkLevelIcons->mIconEnabled[index] = enabled;
}
#pragma thumb off
