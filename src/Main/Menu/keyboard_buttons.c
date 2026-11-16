#include "Main/Menu/keyboard_buttons.h"
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
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/back_screen_keyboard_tables.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Menu/keyboard_keys.h"
#include "Main/Menu/txt_system.h"
#include "thread_scheduler.h"
#include "Main/Save/buddy_records_write.h"
#include "Main/Menu/message_screen.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/keyboard_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "Main/System/input_slots.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "cpu_copy_clear_16.h"
#include "sound_archive_load_result.h"
#include "cpu_copy_fill.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Graphics/scene_text.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/scene_text_init.h"
#include "arena_cache_init.h"
#include "vram_transfer_queue.h"
#include "bg_screen_char_pointers.h"
#include "vram_load_2d_graphics.h"
#include "Main/System/stdio_files.h"
#include "print_memory_multibyte_write.h"
#include "capture_output_effect.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Graphics/back_screen.h"
#include "Main/System/result_archive_path.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

Keyboard *g_KeyboardContext;

BOOL IsLocateFriendOnWithBuddyStatus4(void) {
    BOOL result = FALSE;
    if (!g_SaveDataHolder->mFirstBlock->mLocateFriendOff) {
        if (HasWiFiBuddyStatus4() != FALSE) {
            result = TRUE;
        }
    }
    return result;
}

#pragma thumb on
void InitKeyboardLabelCanvases(void) {
    s32 remaining[2] = {0x4000, 0x4000};
    u8 buttonSizes[2][2][2] = {{{0x50, 0x10}, {0x50, 0x10}}, {{0x50, 0x10}, {0x50, 0x10}}};
    u8 charSizes[2][12][2] = {
        {{8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}, {8, 16}},
        {{16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}, {16, 16}}};
    s32 indexA;
    s32 indexB;
    s32 bufferIndex;
    for (indexA = 0; indexA < 2; indexA++) {
        for (indexB = 0; indexB < 2; indexB++) {
            remaining[1] -= InitLabelCanvas(g_KeyboardContext->mHeap, gKeyboardButtonLabelIndices[indexA][indexB],
                                            g_KeyboardContext->mBnlls[indexA], buttonSizes[indexA][indexB][0],
                                            buttonSizes[indexA][indexB][1],
                                            gKeyboardButtonEntryIndices[indexA][indexB][0], g_KeyboardContext->mNcer,
                                            g_KeyboardContext->mBncls[indexA], g_KeyboardContext->mTables[indexA][1], remaining[1]);
        }
    }
    for (indexB = 0; indexB < 2; indexB++) {
        for (bufferIndex = 0; bufferIndex < 2; bufferIndex++) {
            for (indexA = 0; indexA < g_KeyboardMaxSizeArray[indexB]; indexA++) {
                remaining[bufferIndex] -= InitLabelCanvas(
                    g_KeyboardContext->mHeap, gKeyboardTextCharLabelIndices[indexB][indexA], g_KeyboardContext->mBnlls[indexB],
                    charSizes[indexB][indexA][0], charSizes[indexB][indexA][1],
                    gKeyboardTextIndexEntryIndices[indexB][indexA], g_KeyboardContext->mNcer, g_KeyboardContext->mBncls[indexB],
                    g_KeyboardContext->mTables[indexB][bufferIndex], remaining[bufferIndex]);
            }
        }
    }
}

const u8 gKeyboardKindEntryCounts[2] = {1, 1};
const u8 gKeyboardKindEntryIndices[2][1] = {{0}, {0x10}};
const u8 gKeyboardButtonLabelIndices[2][2] = {{1, 0}, {0, 1}};
const u8 gKeyboardLayoutEntryIndices[6] = {0xff, 5, 6, 7, 8, 9};
const u8 gKeyboardRemainingEntryIndices[6] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16};
const u8 gKeyboardCursorCornerEntryIndices[2][4] = {{0x13, 0x14, 0x15, 0x16}, {0x21, 0x22, 0x23, 0x24}};
const s16 gKeyboardTextOffsetYTarget[2][2] = {{0x82, 0}, {0x96, 0}};
const s16 gKeyboardTextOffsetYInitial[2][2] = {{0xc0, -54}, {0xc0, -54}};
const u8 gKeyboardTextSlotEntryIndices[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
const u8 gKeyboardNextLayouts[2][6] = {{6, 2, 3, 4, 5, 1}, {6, 4, 3, 1, 5, 2}};
const u8 gKeyboardButtonEntryIndices[2][2][3] = {{{4, 6, 2}, {3, 5, 1}}, {{12, 14, 10}, {13, 15, 11}}};
const u8 g_KeyboardMaxSizeArray[2] = {0xc, 0xa};
const u8 gKeyboardTextCharLabelIndices[2][12] = {{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                                                 {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0}};
const u8 gKeyboardTextIndexEntryIndices[2][12] = {{7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                                                  {23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 0, 0}};

void SetKeyboardButtonCorners(void) {
    SetKeyboardButton0Corners(0x24, 0x7a, 0x7e, 0x8e);
    SetKeyboardButton1Corners(0x82, 0x7a, 0xdc, 0x8e);
}

#pragma thumb off

#pragma thumb on

void PrintKeyboardButtonTexts(void) {
    s32 kindIndex;
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        Keyboard *keyboard = g_KeyboardContext;
        PrintLabelLayoutTextNoFixedAdvance(1, gKeyboardButtonLabelIndices[kindIndex][0], g_KeyboardContext->mBnlls[kindIndex],
                                           Bmg_GetRawStringPointer_from_thumb(keyboard->mCommonMessages, KEYBOARD_MESSAGE_OK),
                                           keyboard->mBncls[kindIndex], keyboard->mTables[kindIndex][1]);
        keyboard = g_KeyboardContext;
        PrintLabelLayoutTextNoFixedAdvance(1, gKeyboardButtonLabelIndices[kindIndex][1], g_KeyboardContext->mBnlls[kindIndex],
                                           Bmg_GetRawStringPointer_from_thumb(keyboard->mCommonMessages, KEYBOARD_MESSAGE_CANCEL),
                                           keyboard->mBncls[kindIndex], keyboard->mTables[kindIndex][1]);
    }
}

void InitKeyboardCursorCorners(void) {
    s32 kindIndex;
    s32 screenIndex;
    s32 cornerIndex;
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            for (cornerIndex = 0; cornerIndex < 4; cornerIndex++) {
                LayoutTableEntry *entry =
                    &g_KeyboardContext
                         ->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][cornerIndex]];
                entry->mUsePosition = TRUE;
                entry->mPositionX = 0;
                entry->mPositionY = 0;
            }
        }
    }
}

void HideKeyboardFirstBufferObjects(void) {
    s32 kindIndex;
    s32 itemIndex;
    s32 entryIndex;
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        for (itemIndex = 0; itemIndex < 2; itemIndex++) {
            for (entryIndex = 0; entryIndex < 3; entryIndex++) {
                g_KeyboardContext->mTables[kindIndex][0][gKeyboardButtonEntryIndices[kindIndex][itemIndex][entryIndex]]
                    .mVisible = 0;
            }
            g_KeyboardContext
                ->mTables[kindIndex][0]
                         [gKeyboardButtonLabelIndices[kindIndex][itemIndex] + g_KeyboardContext->mBncls[kindIndex]->mCount]
                .mVisible = 0;
        }
    }
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        for (itemIndex = 0; itemIndex < g_KeyboardMaxSizeArray[kindIndex]; itemIndex++) {
            g_KeyboardContext->mTables[kindIndex][0][gKeyboardTextIndexEntryIndices[kindIndex][itemIndex]].mVisible = 0;
        }
    }
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        for (entryIndex = 0; entryIndex < 4; entryIndex++) {
            g_KeyboardContext->mTables[kindIndex][0][gKeyboardCursorCornerEntryIndices[kindIndex][entryIndex]].mVisible = 0;
        }
    }
    for (itemIndex = 0; itemIndex < 10; itemIndex++) {
        g_KeyboardContext->mTables[1][0][gKeyboardTextSlotEntryIndices[itemIndex]].mVisible = 0;
    }
}

void SetKeyboardTextFromFriendKey(void) {
    u16 text[12];
    text[0] = 0;
    Mem_CpuFill16(text[0], &text[1], 0x1a);
    CopyMemory16(&g_KeyboardContext->mRecords[0], &text[1], 0x18);
    SetKeyboardText(&text[1]);
}

void SetKeyboardTextFromName(void) {
    u16 text[12];
    text[0] = 0;
    Mem_CpuFill16(text[0], &text[1], 0x16);
    CopyMemory16(&g_KeyboardContext->mRecords[1], &text[1], 0x14);
    SetKeyboardText(&text[1]);
}

void SetKeyboardTextFromPlayerName(void) {
    u16 text[12];
    text[0] = 0;
    Mem_CpuFill16(text[0], &text[1], 0x16);
    CopyMemory16(g_SaveDataHolder->mFirstBlock->mPlayerName, &text[1], 0x14);
    SetKeyboardText(&text[1]);
}

void CopyKeyboardTextAsBytes(void) {
    s32 charIndex;
    Mem_CpuFill8(&g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS], 0, 0xd);
    for (charIndex = 0; charIndex < 12; charIndex++) {
        ((u8 *) &g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS])[charIndex] = g_KeyboardContext->mRecords[0].mChars[charIndex];
    }
}

void InitializeKeyboardContext_from_thumb(void *heap, s32 mode) {
    volatile u16 zero;
    SceneTextInitParams config;
    s32 index;
    s32 screenIndex;
    g_KeyboardContext = Mem_AllocateHeap(heap, sizeof(Keyboard));
    g_KeyboardContext->mHeap = heap;
    g_KeyboardContext->mDisplaySettings = CreateLoadSomeDisplayConfig_from_thumb(heap);
    CreateGlobalNN_from_thumb(heap, GetKeyboardOam_from_thumb());
    config.mUseTxtSystem = 1;
    config.mTxtSystemFont = GetLoadedFont_from_thumb(1);
    config.mUseCanvas1 = 0;
    config.mUseCanvas2 = 1;
    config.mUseCanvas3 = 0;
    config.mUseSelectChoises = 0;
    config.mSelectChoisesFont = NULL;
    config.mUseSelectReturn = 0;
    config.mUseBackScreen = 1;
    if (mode == SCENE_WIFI_MENU) {
        config.mBackScreenKind = 1;
    } else {
        config.mBackScreenKind = 0;
    }
    PrepareNavigationContextFiles_from_thumb();
    InitializeNavigationContext_from_thumb(heap, &config);
    InitKeyboardDisplay();
    LoadKeyboardFiles();
    OamBuffer_SomeFn_from_thumb(GetKeyboardOam_from_thumb(), GetKeyboardSecondBuffer());
    CreateGlobal78_from_thumb(0x20, 0x40, 0xc);
    SetKeyboardOffset(0, 0x28);
    SetKeyboardButtonCorners();
    SetKeyboardScreenMapTopBitsWrapper(0);
    g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mMode = mode;
    g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mNextScene = KEYBOARD_NEXT_SCENE_NONE;
    if (mode == SCENE_WIFI_MENU) {
        g_KeyboardContext->mKind = KEYBOARD_KIND_FRIEND_KEY;
        g_KeyboardContext->mState = KEYBOARD_STATE_WAIT_FADE_FRIEND_KEY;
        g_KeyboardContext->mButtonEnabled[0] = FALSE;
        g_KeyboardContext->mButtonEnabled[1] = TRUE;
    } else {
        g_KeyboardContext->mKind = KEYBOARD_KIND_NAME;
        g_KeyboardContext->mState = KEYBOARD_STATE_WAIT_FADE_NAME;
        g_KeyboardContext->mButtonEnabled[0] = TRUE;
        if (mode == SCENE_NICKNAME) {
            g_KeyboardContext->mButtonEnabled[1] = FALSE;
        } else {
            g_KeyboardContext->mButtonEnabled[1] = TRUE;
        }
        SetKeyboardTextFromPlayerName();
    }
    if (g_KeyboardContext->mKind == KEYBOARD_KIND_FRIEND_KEY) {
        g_KeyboardContext->mLayout = KEYBOARD_LAYOUT_DIGITS;
        SetKeyboardTextLimit(g_KeyboardMaxSizeArray[KEYBOARD_KIND_FRIEND_KEY]);
    } else {
        if (g_GlobalP->mRegion == 0) {
            g_KeyboardContext->mLayout = KEYBOARD_LAYOUT_KANA;
        } else {
            g_KeyboardContext->mLayout = KEYBOARD_LAYOUT_ASCII;
        }
        SetKeyboardTextLimit(g_KeyboardMaxSizeArray[KEYBOARD_KIND_NAME]);
    }
    SelectKeyboardLayout(g_KeyboardContext->mLayout);
    QueueKeyboardScreenMap();
    for (index = 0; index < 2; index++) {
        g_KeyboardContext->mCursorOnButton[index] = FALSE;
    }
    g_KeyboardContext->mTextEntryEnabled = FALSE;
    g_KeyboardContext->mNextState = g_KeyboardContext->mState;
    g_KeyboardContext->mStateFrames = 0;
    g_KeyboardContext->mOffsetY = KEYBOARD_OFFSET_HIDDEN;
    for (index = 0; index < 2; index++) {
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            g_KeyboardContext->mTextOffsetY[index][screenIndex] = gKeyboardTextOffsetYInitial[index][screenIndex];
        }
    }
    g_KeyboardContext->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(g_str_common_bmg_7);
    for (index = 0; index < 2; index++) {
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            InitLayoutTable(heap, g_KeyboardContext->mBncls[index], g_KeyboardContext->mBnlls[index],
                            &g_KeyboardContext->mTables[index][screenIndex]);
        }
    }
    InitKeyboardCursorCorners();
    for (index = 0; index < 2; index++) {
        zero = 0;
        Mem_CpuFill16(zero, &g_KeyboardContext->mRecords[index], 0x18);
    }
    InitKeyboardLabelCanvases();
    PrintKeyboardButtonTexts();
    HideKeyboardFirstBufferObjects();
    WriteKeyboardObjectOffsets();
}
#pragma thumb off

#pragma thumb on

void ReleaseKeyboard(void) {
    ResetGlobalNN_from_thumb();
    DisposeNavigationContext_from_thumb();
    g_KeyboardContext = NULL;
}

#pragma thumb off

#pragma thumb on
void WriteKeyboardObjectOffsets(void) {
    u16 cellCounts[2];
    s32 cursorLeft;
    s32 cursorTop;
    s32 cursorRight;
    s32 cursorBottom;
    s32 kindIndex;
    s32 screenIndex;
    s32 entryIndex;
    s32 buttonIndex;
    s16 offsetY;
    s16 keyboardOffsetY;
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        cellCounts[kindIndex] = g_KeyboardContext->mBncls[kindIndex]->mCount;
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            offsetY = KEYBOARD_OBJECT_HIDDEN_OFFSET;
            if (kindIndex == 1 || g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mMode == SCENE_WIFI_MENU) {
                offsetY = g_KeyboardContext->mTextOffsetY[kindIndex][screenIndex];
            }
            for (entryIndex = 0; entryIndex < gKeyboardKindEntryCounts[kindIndex]; entryIndex++) {
                g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardKindEntryIndices[kindIndex][entryIndex]].mOffsetY =
                    offsetY;
            }
            for (entryIndex = 0; entryIndex < g_KeyboardMaxSizeArray[kindIndex]; entryIndex++) {
                g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardTextIndexEntryIndices[kindIndex][entryIndex]]
                    .mOffsetY = offsetY;
                (g_KeyboardContext->mTables[kindIndex][screenIndex] +
                 cellCounts[kindIndex])[gKeyboardTextCharLabelIndices[kindIndex][entryIndex]]
                    .mOffsetY = offsetY;
            }
            offsetY = g_KeyboardContext->mOffsetY;
            for (buttonIndex = 0; buttonIndex < 2; buttonIndex++) {
                for (entryIndex = 0; entryIndex < 3; entryIndex++) {
                    g_KeyboardContext
                        ->mTables[kindIndex][screenIndex]
                                 [gKeyboardButtonEntryIndices[kindIndex][buttonIndex][entryIndex]]
                        .mOffsetY = offsetY;
                }
                (g_KeyboardContext->mTables[kindIndex][screenIndex] +
                 cellCounts[kindIndex])[gKeyboardButtonLabelIndices[kindIndex][buttonIndex]]
                    .mOffsetY = offsetY;
            }
            keyboardOffsetY = g_KeyboardContext->mOffsetY;
            GetKeyboardCursorBoundsRelative(&cursorLeft, &cursorTop, &cursorRight, &cursorBottom);
            g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][0]].mPositionX =
                cursorLeft;
            g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][0]].mPositionY =
                keyboardOffsetY + cursorTop + 0x28;
            g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][1]].mPositionX =
                cursorLeft;
            g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][1]].mPositionY =
                keyboardOffsetY + cursorBottom + 0x28;
            g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][2]].mPositionX =
                cursorRight;
            g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][2]].mPositionY =
                keyboardOffsetY + cursorTop + 0x28;
            g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][3]].mPositionX =
                cursorRight;
            g_KeyboardContext->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][3]].mPositionY =
                keyboardOffsetY + cursorBottom + 0x28;
        }
    }
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        offsetY = KEYBOARD_OBJECT_HIDDEN_OFFSET;
        if (g_KeyboardContext->mKind == KEYBOARD_KIND_NAME && kindIndex == 1) {
            offsetY = g_KeyboardContext->mOffsetY;
        }
        for (entryIndex = 0; entryIndex < 10; entryIndex++) {
            g_KeyboardContext->mTables[1][kindIndex][gKeyboardTextSlotEntryIndices[entryIndex]].mOffsetY = offsetY;
        }
        offsetY = KEYBOARD_OBJECT_HIDDEN_OFFSET;
        if (g_KeyboardContext->mKind == KEYBOARD_KIND_NAME) {
            offsetY = g_KeyboardContext->mTextOffsetY[1][kindIndex];
        }
        for (entryIndex = 0; entryIndex < 6; entryIndex++) {
            g_KeyboardContext->mTables[1][kindIndex][gKeyboardRemainingEntryIndices[entryIndex]].mOffsetY = offsetY;
        }
    }
}
#pragma thumb off

#pragma thumb on

void QueueKeyboardScreenMap(void) {
    Nscr *screenMap;
    screenMap = g_KeyboardContext->mNscrs[g_KeyboardContext->mKind];
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG3_MAP, 0, screenMap->mData, screenMap->mDataSize);
}

void LoadKeyboardFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_10key.bnbl");
    g_KeyboardContext->mBnbls[0] = file;
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_10key.bncl");
    g_KeyboardContext->mBncls[0] = file;
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_10key.bnll");
    g_KeyboardContext->mBnlls[0] = file;
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s.bnbl");
    g_KeyboardContext->mBnbls[1] = file;
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s.bncl");
    g_KeyboardContext->mBncls[1] = file;
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s.bnll");
    g_KeyboardContext->mBnlls[1] = file;
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_o.nce.ncgr");
    Gfx_ReadCharGraphics(&g_KeyboardContext->mNcgr, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_o.nce.ncer");
    LoadCellBankFrom(&g_KeyboardContext->mNcer, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_o.nclr");
    Gfx_ReadPalette(&g_KeyboardContext->mNclr, file);
    Arm_FlushRange(g_KeyboardContext->mNcgr->mData, g_KeyboardContext->mNcgr->mDataSize);
    CopyTileDataTop_0(g_KeyboardContext->mNcgr->mData, 0, g_KeyboardContext->mNcgr->mDataSize);
    TEQSub_Fn35Impl(g_KeyboardContext->mNcgr->mData, 0, g_KeyboardContext->mNcgr->mDataSize);
    Arm_FlushRange(g_KeyboardContext->mNclr->mData, g_KeyboardContext->mNclr->mDataSize);
    CopySomePaletteData(g_KeyboardContext->mNclr->mData, 0, (0x000001a0u));
    CopySomePaletteData(&g_KeyboardContext->mNclr->mData[0xe0], 0x1c0, 0x40);
    TEQSub_Fn30Impl(g_KeyboardContext->mNclr->mData, 0, g_KeyboardContext->mNclr->mDataSize);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b_flame.ncgr");
    Gfx_ReadCharGraphicsV2(&chars, file);
    Arm_FlushRange(chars->mData, chars->mDataSize);
    CopyBgData_Bg3_Bottom(chars->mData, 0, chars->mDataSize);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b_flame02.nscr");
    MaybeReadScreenBlock_0(&g_KeyboardContext->mNscrs[0], file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b_flame01.nscr");
    MaybeReadScreenBlock_0(&g_KeyboardContext->mNscrs[1], file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("Keyboard_s_b.NCLR");
    Gfx_ReadPalette(&palette, file);
    Arm_FlushRange(palette->mData, 0x80);
    CopyPaletteBottom(palette->mData, 0, 0x80);
}

#pragma thumb off

#pragma thumb on
void InitKeyboardDisplay(void) {
    u32 subDisplayBits;
    reg_G2S_DB_BLDCNT = 0;
    subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    subDisplayBits |= 0xc;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (subDisplayBits << 8);
    reg_G2S_DB_BG2CNT =
        (reg_G2S_DB_BG2CNT & (REG_G2S_DB_BG2CNT_PRIORITY_MASK | REG_G2S_DB_BG2CNT_MOSAIC_MASK)) | 0x8018;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~REG_G2S_DB_BG2CNT_PRIORITY_MASK) | 2;
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x9010;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 2;
    MemFillWordsByBlock_inline((void *) G2_GetBG2ScrPtr(), 0x1000);
    MemFillWordsByBlock_inline((void *) G2_GetBG3ScrPtr(), 0x1000);
}

void Keyboard_SwitchFn0_from_thumb(void) {
    if (Bright_IsBothScreensFadedIn() != 0) {
        g_KeyboardContext->mNextState = KEYBOARD_STATE_SLIDE_IN_FRIEND_KEY;
        TextSystem_DisplayProgressDialog_TopScreen_from_thumb(Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_ENTER_FRIEND_CODE), 0, 0, 0,
                                 0, 0, 0);
    }
}

void UpdateKeyboardFriendKeyButtons(void) {
    s32 lastCharIndex;
    lastCharIndex = g_KeyboardMaxSizeArray[KEYBOARD_KIND_FRIEND_KEY] - 1;
    if (lastCharIndex == GetKeyboardTextIndex() && g_KeyboardContext->mRecords[g_KeyboardContext->mKind].mChars[lastCharIndex] != 0) {
        g_KeyboardContext->mButtonEnabled[0] = TRUE;
    } else {
        g_KeyboardContext->mButtonEnabled[0] = FALSE;
    }
    if (GetKeyboardCursorValueWrapper() == KEYBOARD_VALUE_FIRST_BUTTON) {
        g_KeyboardContext->mCursorOnButton[0] = TRUE;
    } else {
        g_KeyboardContext->mCursorOnButton[0] = FALSE;
    }
    if (GetKeyboardCursorValueWrapper() == KEYBOARD_VALUE_SECOND_BUTTON) {
        g_KeyboardContext->mCursorOnButton[1] = TRUE;
    } else {
        g_KeyboardContext->mCursorOnButton[1] = FALSE;
    }
}

void Keyboard_SwitchFn1_from_thumb(void) {
    g_KeyboardContext->mStateFrames++;
    g_KeyboardContext->mOffsetY = ComputeValueInterpolation_from_thumb(1, KEYBOARD_OFFSET_HIDDEN, 0, g_KeyboardContext->mStateFrames, KEYBOARD_SLIDE_FRAMES);
    g_KeyboardContext->mTextOffsetY[0][1] =
        ComputeValueInterpolation_from_thumb(1, gKeyboardTextOffsetYInitial[0][1], gKeyboardTextOffsetYTarget[0][1], g_KeyboardContext->mStateFrames,
                       KEYBOARD_SLIDE_FRAMES);
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES) {
        g_KeyboardContext->mStateFrames = KEYBOARD_SLIDE_FRAMES;
    }
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES && TextSystem_IsDialogIdle_from_thumb() != 0) {
        g_KeyboardContext->mNextState = KEYBOARD_STATE_ENTER_FRIEND_KEY;
        g_KeyboardContext->mTextEntryEnabled = TRUE;
        g_KeyboardContext->mStateFrames = 0;
    }
    UpdateKeyboardFriendKeyButtons();
}

void Keyboard_SwitchFn2_from_thumb(void) {
    InputSlotIndex inputSlotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    Keyboard *keyboard;
    KeyboardRecord *textRecord;
    void *text;
    s32 touchedRectIndex;
    BOOL result;
    BOOL pairRecentlyLost;
    u16 hasPair;
    result = FALSE;
    touchedRectIndex = -1;
    pairRecentlyLost = FALSE;
    hasPair = g_GlobalCYT[inputSlotIndex].mPair.mHasPair;
    if (hasPair == 0 && g_GlobalCYT[inputSlotIndex].mPair.mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && g_GlobalCYT[inputSlotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        result = TRUE;
    }
    if (result != FALSE) {
        touchedRectIndex = RectTableFindContaining(g_KeyboardContext->mBnbls[0], g_GlobalCYT[inputSlotIndex].mPair.mPairX,
                                                   g_GlobalCYT[inputSlotIndex].mPair.mPairY);
    }
    keyboard = g_KeyboardContext;
    textRecord = &keyboard->mRecords[keyboard->mKind];
    text = GetKeyboardText();
    CopyMemory16(text, textRecord, 0x18);
    UpdateKeyboardFriendKeyButtons();
    if (touchedRectIndex == KEYBOARD_FRIEND_KEY_RECT_FIRST_BUTTON ||
        (GetKeyboardCursorValueWrapper() == KEYBOARD_VALUE_FIRST_BUTTON &&
         (u16) (g_GlobalCYT[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0)) {
        keyboard = g_KeyboardContext;
        if (keyboard->mButtonEnabled[0] != 0) {
            keyboard->mNextState = KEYBOARD_STATE_SLIDE_OUT_FRIEND_KEY;
            g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen = 1;
            TextSystem_CloseDialog_from_thumb();
            MoveKeyboardCursorToValueWrapper(KEYBOARD_VALUE_FIRST_BUTTON);
            g_KeyboardContext->mTextEntryEnabled = FALSE;
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 4);
        } else {
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x16);
        }
    } else if (touchedRectIndex == KEYBOARD_FRIEND_KEY_RECT_SECOND_BUTTON ||
               (GetKeyboardCursorValueWrapper() == KEYBOARD_VALUE_SECOND_BUTTON &&
                (u16) (g_GlobalCYT[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0)) {
        g_KeyboardContext->mNextState = KEYBOARD_STATE_SLIDE_OUT_FRIEND_KEY;
        g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen = 0;
        TextSystem_CloseDialog_from_thumb();
        MoveKeyboardCursorToValueWrapper(KEYBOARD_VALUE_SECOND_BUTTON);
        g_KeyboardContext->mTextEntryEnabled = FALSE;
        PlaySseqFromSarc(&gSharedSeqHandle, 0, 0xe);
    }
}

void Keyboard_SwitchFn3_from_thumb(void) {
    Keyboard *keyboard;
    g_KeyboardContext->mStateFrames++;
    g_KeyboardContext->mOffsetY = ComputeValueInterpolation_from_thumb(1, 0, KEYBOARD_OFFSET_HIDDEN, g_KeyboardContext->mStateFrames, KEYBOARD_SLIDE_FRAMES);
    g_KeyboardContext->mTextOffsetY[0][1] =
        ComputeValueInterpolation_from_thumb(1, gKeyboardTextOffsetYTarget[0][1], gKeyboardTextOffsetYInitial[0][1], g_KeyboardContext->mStateFrames,
                       KEYBOARD_SLIDE_FRAMES);
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES) {
        g_KeyboardContext->mStateFrames = KEYBOARD_SLIDE_FRAMES;
    }
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES && TextSystem_IsDialogFinished_from_thumb() != 0) {
        keyboard = g_KeyboardContext;
        if (keyboard->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen != 0) {
            CopyKeyboardTextAsBytes();
            switch (CheckFriendCode(&g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS])) {
                case FRIEND_KEY_CHECK_INCORRECT:
                    g_KeyboardContext->mNextState = KEYBOARD_STATE_SHOW_FRIEND_KEY_ERROR;
                    TextSystem_DisplayProgressDialog_Simple_from_thumb(
                        Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_FRIEND_CODE_INCORRECT));
                    g_KeyboardContext->mStateFrames = 0;
                    return;
                case FRIEND_KEY_CHECK_ALREADY_REGISTERED:
                    g_KeyboardContext->mNextState = KEYBOARD_STATE_SHOW_FRIEND_KEY_ERROR;
                    TextSystem_DisplayProgressDialog_Simple_from_thumb(
                        Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_FRIEND_CODE_ALREADY_REGISTERED));
                    g_KeyboardContext->mStateFrames = 0;
                    return;
                default:
                    g_KeyboardContext->mNextState = KEYBOARD_STATE_SLIDE_IN_NAME;
                    TextSystem_DisplayProgressDialog_TopScreen_from_thumb(
                        Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_ENTER_TEMPORARY_NAME), 0, 0, 0, 0, 0,
                        0);
                    g_KeyboardContext->mStateFrames = 0;
                    g_KeyboardContext->mKind = KEYBOARD_KIND_NAME;
                    if (g_GlobalP->mRegion == 0) {
                        g_KeyboardContext->mLayout = KEYBOARD_LAYOUT_KANA;
                    } else {
                        g_KeyboardContext->mLayout = KEYBOARD_LAYOUT_ASCII;
                    }
                    SelectKeyboardLayout(g_KeyboardContext->mLayout);
                    SetKeyboardTextLimit(g_KeyboardMaxSizeArray[KEYBOARD_KIND_NAME]);
                    SetKeyboardTextFromName();
                    QueueKeyboardScreenMap();
                    ShowKeyboardLayoutObject();
                    return;
            }
        } else {
            keyboard->mRecords[KEYBOARD_RECORD_STATUS].mNextScene = SCENE_WIFI_MENU;
        }
    }
}

void Keyboard_SwitchFn4_from_thumb(void) {
    Keyboard *keyboard;
    g_KeyboardContext->mStateFrames++;
    if (TextSystem_JustFadedIn_from_thumb() != 0) {
        PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x15);
    }
    keyboard = g_KeyboardContext;
    if (keyboard->mStateFrames >= KEYBOARD_ERROR_FRAMES) {
        keyboard->mNextState = KEYBOARD_STATE_SLIDE_IN_FRIEND_KEY;
        TextSystem_DisplayProgressDialog_TopScreen_from_thumb(Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_ENTER_FRIEND_CODE), 0, 0, 0,
                                 0, 0, 0);
        g_KeyboardContext->mStateFrames = 0;
    }
}

void Keyboard_SwitchFn5_from_thumb(void) {
    if (Bright_IsBothScreensFadedIn() != 0) {
        g_KeyboardContext->mNextState = KEYBOARD_STATE_SLIDE_IN_NAME;
        TextSystem_DisplayProgressDialog_TopScreen_from_thumb(Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_ENTER_NICKNAME), 0, 0, 0, 0,
                                 0, 0);
        g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen = 1;
    }
}
#pragma thumb off

#pragma thumb on

void UpdateKeyboardNameButtons(void) {
    s32 charIndex;
    u8 textLimit;
    charIndex = 0;
    g_KeyboardContext->mButtonEnabled[0] = FALSE;
    for (; charIndex < GetKeyboardTextIndex(); charIndex++) {
        if (GetKeyboardText()[charIndex] != 0x20 && GetKeyboardText()[charIndex] != 0x3000) {
            g_KeyboardContext->mButtonEnabled[0] = TRUE;
        }
    }
    textLimit = g_KeyboardMaxSizeArray[KEYBOARD_KIND_NAME];
    if (textLimit - 1 == GetKeyboardTextIndex()) {
        if ((GetKeyboardText() + textLimit)[-1] != 0x20 && (GetKeyboardText() + textLimit)[-1] != 0x3000 &&
            (GetKeyboardText() + textLimit)[-1] != 0) {
            g_KeyboardContext->mButtonEnabled[0] = TRUE;
        }
    }
    if (GetKeyboardCursorValueWrapper() == KEYBOARD_VALUE_FIRST_BUTTON) {
        g_KeyboardContext->mCursorOnButton[0] = TRUE;
    } else {
        g_KeyboardContext->mCursorOnButton[0] = FALSE;
    }
    if (GetKeyboardCursorValueWrapper() == KEYBOARD_VALUE_SECOND_BUTTON) {
        g_KeyboardContext->mCursorOnButton[1] = TRUE;
        return;
    }
    g_KeyboardContext->mCursorOnButton[1] = FALSE;
}

#pragma thumb off

#pragma thumb on
void Keyboard_SwitchFn6_from_thumb(void) {
    Keyboard *keyboard;
    g_KeyboardContext->mStateFrames++;
    g_KeyboardContext->mOffsetY = ComputeValueInterpolation_from_thumb(1, KEYBOARD_OFFSET_HIDDEN, 0, g_KeyboardContext->mStateFrames, KEYBOARD_SLIDE_FRAMES);
    g_KeyboardContext->mTextOffsetY[1][1] =
        ComputeValueInterpolation_from_thumb(1, gKeyboardTextOffsetYInitial[1][1], gKeyboardTextOffsetYTarget[1][1], g_KeyboardContext->mStateFrames,
                       KEYBOARD_SLIDE_FRAMES);
    keyboard = g_KeyboardContext;
    if (keyboard->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen != 0) {
        g_KeyboardContext->mTextOffsetY[0][0] =
            ComputeValueInterpolation_from_thumb(1, gKeyboardTextOffsetYInitial[0][0], gKeyboardTextOffsetYTarget[0][0],
                           keyboard->mStateFrames, KEYBOARD_SLIDE_FRAMES);
    }
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES) {
        g_KeyboardContext->mStateFrames = KEYBOARD_SLIDE_FRAMES;
    }
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES && TextSystem_IsDialogIdle_from_thumb() != 0) {
        g_KeyboardContext->mNextState = KEYBOARD_STATE_ENTER_NAME;
        g_KeyboardContext->mTextEntryEnabled = TRUE;
        g_KeyboardContext->mStateFrames = 0;
    }
    UpdateKeyboardNameButtons();
    ShowKeyboardLayoutObject();
}

void Keyboard_SwitchFn7_from_thumb(void) {
    InputSlotIndex inputSlotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    Keyboard *keyboard;
    KeyboardRecord *textRecord;
    void *text;
    s32 touchedRectIndex;
    BOOL touched;
    BOOL pairRecentlyLost;
    s32 previousLayout;
    u16 hasPair;
    touched = FALSE;
    touchedRectIndex = -1;
    pairRecentlyLost = FALSE;
    hasPair = g_GlobalCYT[inputSlotIndex].mPair.mHasPair;
    if (hasPair == 0 && g_GlobalCYT[inputSlotIndex].mPair.mNoPairCount < INPUT_PAIR_LOSS_SAMPLES) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && g_GlobalCYT[inputSlotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        touched = TRUE;
    }
    if (touched != FALSE) {
        touchedRectIndex = RectTableFindContaining(g_KeyboardContext->mBnbls[1], g_GlobalCYT[inputSlotIndex].mPair.mPairX,
                                                   g_GlobalCYT[inputSlotIndex].mPair.mPairY);
    }
    keyboard = g_KeyboardContext;
    textRecord = &keyboard->mRecords[keyboard->mKind];
    text = GetKeyboardText();
    CopyMemory16(text, textRecord, 0x18);
    UpdateKeyboardNameButtons();
    if (touchedRectIndex == KEYBOARD_NAME_RECT_FIRST_BUTTON ||
        (GetKeyboardCursorValueWrapper() == KEYBOARD_VALUE_FIRST_BUTTON &&
         (u16) (g_GlobalCYT[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0)) {
        keyboard = g_KeyboardContext;
        if (keyboard->mButtonEnabled[0] != 0) {
            keyboard->mNextState = KEYBOARD_STATE_SLIDE_OUT_NAME;
            g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen = 1;
            TextSystem_CloseDialog_from_thumb();
            MoveKeyboardCursorToValueWrapper(KEYBOARD_VALUE_FIRST_BUTTON);
            g_KeyboardContext->mTextEntryEnabled = FALSE;
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 4);
        } else {
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x16);
        }
    } else if (touchedRectIndex == KEYBOARD_NAME_RECT_SECOND_BUTTON ||
               (GetKeyboardCursorValueWrapper() == KEYBOARD_VALUE_SECOND_BUTTON &&
                (u16) (g_GlobalCYT[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0)) {
        keyboard = g_KeyboardContext;
        if (keyboard->mButtonEnabled[1] != 0) {
            keyboard->mNextState = KEYBOARD_STATE_SLIDE_OUT_NAME;
            g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen = 0;
            TextSystem_CloseDialog_from_thumb();
            MoveKeyboardCursorToValueWrapper(KEYBOARD_VALUE_SECOND_BUTTON);
            g_KeyboardContext->mTextEntryEnabled = FALSE;
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0xe);
        } else {
            PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x16);
        }
    } else if ((u16) (g_GlobalCYT[inputSlotIndex].mPressedBits & PAD_KEY_Y) != 0) {
        if (g_GlobalP->mRegion == 0) {
            g_KeyboardContext->mLayout = gKeyboardNextLayouts[0][g_KeyboardContext->mLayout];
        } else {
            g_KeyboardContext->mLayout = gKeyboardNextLayouts[1][g_KeyboardContext->mLayout];
        }
        SelectKeyboardLayout(g_KeyboardContext->mLayout);
        PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1e5);
    } else {
        keyboard = g_KeyboardContext;
        previousLayout = keyboard->mLayout;
        touched = FALSE;
        switch (touchedRectIndex) {
            case KEYBOARD_NAME_RECT_TAB_KANA:
                keyboard->mLayout = KEYBOARD_LAYOUT_KANA;
                SelectKeyboardLayout(g_KeyboardContext->mLayout);
                touched = TRUE;
                break;
            case KEYBOARD_NAME_RECT_TAB_ASCII:
                keyboard->mLayout = KEYBOARD_LAYOUT_ASCII;
                SelectKeyboardLayout(g_KeyboardContext->mLayout);
                touched = TRUE;
                break;
            case KEYBOARD_NAME_RECT_TAB_EURO:
                keyboard->mLayout = KEYBOARD_LAYOUT_EURO;
                SelectKeyboardLayout(g_KeyboardContext->mLayout);
                touched = TRUE;
                break;
            case KEYBOARD_NAME_RECT_TAB_PICTOGRAMS:
                keyboard->mLayout = KEYBOARD_LAYOUT_PICTOGRAMS;
                SelectKeyboardLayout(g_KeyboardContext->mLayout);
                touched = TRUE;
                break;
            case KEYBOARD_NAME_RECT_TAB_PICTOGRAMS_EXTRA:
                keyboard->mLayout = KEYBOARD_LAYOUT_PICTOGRAMS_EXTRA;
                SelectKeyboardLayout(g_KeyboardContext->mLayout);
                touched = TRUE;
                break;
        }
        if (touched != FALSE) {
            if (previousLayout != g_KeyboardContext->mLayout) {
                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1e5);
            } else {
                PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x1ed);
            }
        }
    }
    ShowKeyboardLayoutObject();
}

void Keyboard_SwitchFn8_from_thumb(void) {
    u16 nameChars[10];
    u16 formattedText[0xfe];
    Keyboard *keyboard;
    s32 charCount;
    void *message;
    void *buttonText;
    void *secondButtonText;
    g_KeyboardContext->mStateFrames++;
    g_KeyboardContext->mOffsetY = ComputeValueInterpolation_from_thumb(1, 0, KEYBOARD_OFFSET_HIDDEN, g_KeyboardContext->mStateFrames, KEYBOARD_SLIDE_FRAMES);
    g_KeyboardContext->mTextOffsetY[1][1] =
        ComputeValueInterpolation_from_thumb(1, gKeyboardTextOffsetYTarget[1][1], gKeyboardTextOffsetYInitial[1][1], g_KeyboardContext->mStateFrames,
                       KEYBOARD_SLIDE_FRAMES);
    keyboard = g_KeyboardContext;
    if (keyboard->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen == 0) {
        g_KeyboardContext->mTextOffsetY[0][0] =
            ComputeValueInterpolation_from_thumb(1, gKeyboardTextOffsetYTarget[0][0], gKeyboardTextOffsetYInitial[0][0],
                           keyboard->mStateFrames, KEYBOARD_SLIDE_FRAMES);
    }
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES) {
        g_KeyboardContext->mStateFrames = KEYBOARD_SLIDE_FRAMES;
    }
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES && TextSystem_IsDialogFinished_from_thumb() != 0) {
        keyboard = g_KeyboardContext;
        if (keyboard->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen != 0) {
            if (keyboard->mRecords[KEYBOARD_RECORD_STATUS].mMode == SCENE_WIFI_MENU) {
                message = Bmg_GetRawStringPointer_from_thumb(keyboard->mCommonMessages, KEYBOARD_MESSAGE_CONFIRM_FRIEND_CODE);
                buttonText = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_YES);
                secondButtonText = Bmg_GetRawStringPointer_from_thumb(keyboard->mCommonMessages, KEYBOARD_MESSAGE_NO);
                TextSystem_DisplayDoubleButtonDialog_from_thumb(message, buttonText, secondButtonText, 0, 0, 1, 1, 0);
            } else {
                message = Bmg_GetRawStringPointer_from_thumb(keyboard->mCommonMessages, KEYBOARD_MESSAGE_CONFIRM_NAME);
                charCount = GetClampedString10LengthForFontIndex0_from_thumb(g_KeyboardContext->mRecords[1].mChars, nameChars);
                nameChars[charCount] = 0;
                MaybeHandleBmgFormatting_from_thumb(nameChars, message, &formattedText[1], 0x1f4);
                buttonText = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_YES);
                secondButtonText = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_NO);
                TextSystem_DisplayDoubleButtonDialog_from_thumb(&formattedText[1], buttonText, secondButtonText, 0, 0, 1, 1, 0);
            }
            g_KeyboardContext->mNextState = KEYBOARD_STATE_SLIDE_IN_CONFIRM;
            g_KeyboardContext->mStateFrames = 0;
        } else if (keyboard->mRecords[KEYBOARD_RECORD_STATUS].mMode == SCENE_WIFI_MENU) {
            keyboard->mKind = KEYBOARD_KIND_FRIEND_KEY;
            g_KeyboardContext->mLayout = KEYBOARD_LAYOUT_DIGITS;
            SelectKeyboardLayout(g_KeyboardContext->mLayout);
            SetKeyboardTextLimit(g_KeyboardMaxSizeArray[KEYBOARD_KIND_FRIEND_KEY]);
            QueueKeyboardScreenMap();
            SetKeyboardTextFromFriendKey();
            g_KeyboardContext->mNextState = KEYBOARD_STATE_SLIDE_IN_FRIEND_KEY;
            g_KeyboardContext->mStateFrames = 0;
            TextSystem_DisplayProgressDialog_TopScreen_from_thumb(Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_ENTER_FRIEND_CODE), 0, 0,
                                     0, 0, 0, 0);
        } else {
            keyboard->mRecords[KEYBOARD_RECORD_STATUS].mNextScene = SCENE_OPTION;
        }
    }
}

void Keyboard_SwitchFn9_from_thumb(void) {
    s16 targetOffsetY;
    g_KeyboardContext->mStateFrames++;
    targetOffsetY = gKeyboardTextOffsetYTarget[1][0];
    g_KeyboardContext->mTextOffsetY[0][0] =
        ComputeValueInterpolation_from_thumb(1, gKeyboardTextOffsetYTarget[0][0],
                       gKeyboardTextOffsetYTarget[0][0] - (KEYBOARD_OFFSET_HIDDEN - targetOffsetY),
                       g_KeyboardContext->mStateFrames, KEYBOARD_SLIDE_FRAMES);
    g_KeyboardContext->mTextOffsetY[1][0] = ComputeValueInterpolation_from_thumb(1, gKeyboardTextOffsetYInitial[1][0], targetOffsetY,
                                                   g_KeyboardContext->mStateFrames, KEYBOARD_SLIDE_FRAMES);
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES) {
        g_KeyboardContext->mStateFrames = KEYBOARD_SLIDE_FRAMES;
    }
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES) {
        if (TextSystem_IsDialogIdle_from_thumb() != 0) {
            g_KeyboardContext->mNextState = KEYBOARD_STATE_ANSWER_CONFIRM;
            g_KeyboardContext->mStateFrames = 0;
        }
    }
}

void Keyboard_SwitchFn10_from_thumb(void) {
    Keyboard *keyboard;
    s16 targetOffsetY;
    void *message;
    void *buttonText;
    if (g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES) {
        g_KeyboardContext->mStateFrames = KEYBOARD_SLIDE_FRAMES;
    }
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0 && TextSystem_IsButton2Focused_from_thumb() == 1) {
        targetOffsetY = gKeyboardTextOffsetYTarget[1][0];
        g_KeyboardContext->mTextOffsetY[1][0] = ComputeValueInterpolation_from_thumb(1, targetOffsetY, gKeyboardTextOffsetYInitial[1][0],
                                                       g_KeyboardContext->mStateFrames, KEYBOARD_SLIDE_FRAMES);
        g_KeyboardContext->mTextOffsetY[0][0] =
            ComputeValueInterpolation_from_thumb(1, gKeyboardTextOffsetYTarget[0][0] - (KEYBOARD_OFFSET_HIDDEN - targetOffsetY),
                           gKeyboardTextOffsetYTarget[0][0], g_KeyboardContext->mStateFrames, KEYBOARD_SLIDE_FRAMES);
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0 && g_KeyboardContext->mStateFrames >= KEYBOARD_SLIDE_FRAMES) {
        if (TextSystem_IsButton2Focused_from_thumb() == 0) {
            keyboard = g_KeyboardContext;
            if (keyboard->mRecords[KEYBOARD_RECORD_STATUS].mMode == SCENE_WIFI_MENU) {
                AddBuddyFromFriendKey(&keyboard->mRecords[KEYBOARD_RECORD_STATUS], &keyboard->mRecords[1]);
                WriteFriendListSaveDataSection();
                message = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_SAVING);
                TextSystem_DisplayProgressDialog_from_thumb(message, 0, 1, 1, 0, 1);
                g_KeyboardContext->mNextState = KEYBOARD_STATE_SHOW_SAVING;
            } else {
                g_SaveDataHolder->mFirstBlock->mHasPlayerName = 1;
                Mem_CpuFill8(g_SaveDataHolder->mFirstBlock->mPlayerName, 0,
                            sizeof(g_SaveDataHolder->mFirstBlock->mPlayerName));
                Mem_CpuCopy8(&keyboard->mRecords[1], g_SaveDataHolder->mFirstBlock->mPlayerName,
                            sizeof(g_SaveDataHolder->mFirstBlock->mPlayerName));
                WriteSaveDataSectionHeaderToSaveData_from_thumb();
                TextSystem_SetFadeInSseqId_from_thumb(0x21);
                message = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_NICKNAME_REGISTERED);
                buttonText = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_OK);
                TextSystem_DisplaySingleButtonDialog_from_thumb(message, buttonText, 0, 1, 1, 0);
                g_KeyboardContext->mNextState = KEYBOARD_STATE_WAIT_BACKUP;
            }
            g_KeyboardContext->mStateFrames = 0;
        } else {
            g_KeyboardContext->mNextState = KEYBOARD_STATE_SLIDE_IN_NAME;
            g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mFirstButtonChosen = 0;
            g_KeyboardContext->mStateFrames = 0;
            TextSystem_DisplayProgressDialog_TopScreen_from_thumb(Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_ENTER_NICKNAME), 0, 0, 0,
                                     0, 0, 0);
        }
    } else {
        if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0 || TextSystem_IsDialogFinished_from_thumb() != 0) {
            TextSystem_CloseDialog_from_thumb();
            g_KeyboardContext->mStateFrames++;
        }
    }
}

void Keyboard_SwitchFn11_from_thumb(void) {
    Keyboard *keyboard;
    void *message;
    s32 backupBusy;
    void *buttonText;
    if (TextSystem_JustFadedIn_from_thumb() != 0) {
        PlaySseqFromSarc(&gSharedSeqHandle, 0, 0x22);
    }
    g_KeyboardContext->mStateFrames++;
    if (TextSystem_IsDialogIdle_from_thumb() != 0) {
        keyboard = g_KeyboardContext;
        if (keyboard->mStateFrames > KEYBOARD_SAVING_FRAMES) {
            backupBusy = (g_SaveDataHolder->mBusy == 0)
                             ? (g_SaveDataIoManager->mBackupEnabled != 0 ? g_SaveDataIoManager->mCommandRunning : 0)
                             : 1;
            if (backupBusy == 0) {
                keyboard->mNextState = KEYBOARD_STATE_WAIT_BACKUP;
                g_KeyboardContext->mStateFrames = 0;
                TextSystem_SetFadeInSseqId_from_thumb(0x21);
                message = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_FRIEND_CODE_REGISTERED);
                buttonText = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_OK);
                TextSystem_DisplaySingleButtonDialog_from_thumb(message, buttonText, 0, 1, 1, 0);
            }
        }
    }
}

void Keyboard_SwitchFn12_from_thumb(void) {
    void *message;
    s32 backupBusy;
    void *buttonText;
    void *secondButtonText;
    s32 mode;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
    }
    if (TextSystem_IsDialogFinished_from_thumb() != 0) {
        backupBusy = (g_SaveDataHolder->mBusy == 0)
                         ? (g_SaveDataIoManager->mBackupEnabled != 0 ? g_SaveDataIoManager->mCommandRunning : 0)
                         : 1;
        if (backupBusy == 0) {
            TextSystem_SetFadeInSseqId_from_thumb(0x23);
            mode = g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mMode;
            if (mode == SCENE_WIFI_MENU || mode == SCENE_OPTION) {
                g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mNextScene = mode;
                return;
            }
            if (mode == SCENE_NICKNAME) {
                g_KeyboardContext->mNextState = KEYBOARD_STATE_ASK_EMBLEM;
                g_KeyboardContext->mStateFrames = 0;
                message = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_CREATE_EMBLEM);
                buttonText = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_YES);
                secondButtonText = Bmg_GetRawStringPointer_from_thumb(g_KeyboardContext->mCommonMessages, KEYBOARD_MESSAGE_NO);
                TextSystem_DisplayDoubleButtonDialog_from_thumb(message, buttonText, secondButtonText, 0, 0, 1, 1, 0);
            }
        }
    }
}

void Keyboard_SwitchFn13_from_thumb(void) {
    if (TextSystem_IsDialogFinished_from_thumb() != 0) {
        if (TextSystem_IsButton2Focused_from_thumb() == 0) {
            g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mNextScene = SCENE_EMBLEM;
        } else {
            g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mNextScene = SCENE_TITLE;
        }
    } else {
        if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
            TextSystem_CloseDialog_from_thumb();
        }
    }
}

void PrintKeyboardTextChars(void) {
    s32 kindIndex;
    s32 screenIndex;
    s32 charIndex;
    u16 charString[2];
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            for (charIndex = 0; charIndex < g_KeyboardMaxSizeArray[kindIndex]; charIndex++) {
                charString[0] = 0;
                charString[1] = 0;
                charString[0] = g_KeyboardContext->mRecords[kindIndex].mChars[charIndex];
                PrintLabelLayoutTextNoFixedAdvance(
                    screenIndex, gKeyboardTextCharLabelIndices[kindIndex][charIndex], g_KeyboardContext->mBnlls[kindIndex],
                    charString, g_KeyboardContext->mBncls[kindIndex], g_KeyboardContext->mTables[kindIndex][screenIndex]);
            }
        }
    }
}

void ShowKeyboardCursorButtonObjects(void) {
    s32 buttonIndex;
    s32 kind;
    for (buttonIndex = 0; buttonIndex < 2; buttonIndex++) {
        if (g_KeyboardContext->mCursorOnButton[buttonIndex] != 0) {
            kind = g_KeyboardContext->mKind;
            g_KeyboardContext->mTables[kind][1][gKeyboardButtonEntryIndices[kind][buttonIndex][0]].mVisible = 1;
        } else {
            kind = g_KeyboardContext->mKind;
            g_KeyboardContext->mTables[kind][1][gKeyboardButtonEntryIndices[kind][buttonIndex][0]].mVisible = 0;
        }
    }
}

void ShowKeyboardDisabledButtonObjects(void) {
    s32 buttonIndex;
    s32 kind;
    for (buttonIndex = 0; buttonIndex < 2; buttonIndex++) {
        if (g_KeyboardContext->mButtonEnabled[buttonIndex] != 0) {
            kind = g_KeyboardContext->mKind;
            g_KeyboardContext->mTables[kind][1][gKeyboardButtonEntryIndices[kind][buttonIndex][1]].mVisible = 0;
        } else {
            kind = g_KeyboardContext->mKind;
            g_KeyboardContext->mTables[kind][1][gKeyboardButtonEntryIndices[kind][buttonIndex][1]].mVisible = 1;
        }
    }
}

void ShowKeyboardTextIndexObject(void) {
    s32 charIndex;
    for (charIndex = 0; charIndex < g_KeyboardMaxSizeArray[g_KeyboardContext->mKind]; charIndex++) {
        g_KeyboardContext->mTables[g_KeyboardContext->mKind][1][gKeyboardTextIndexEntryIndices[g_KeyboardContext->mKind][charIndex]].mVisible =
            0;
    }
    g_KeyboardContext->mTables[g_KeyboardContext->mKind][1][gKeyboardTextIndexEntryIndices[g_KeyboardContext->mKind][GetKeyboardTextIndex()]]
        .mVisible = 1;
}

void ShowKeyboardRemainingCharObjects(void) {
    u16 nameChars[10];
    s32 charCount;
    s32 remaining;
    s32 firstShown;
    s32 slotIndex;
    s32 screenIndex;
    const u8 *entryIndexPointer;
    if (g_KeyboardContext->mKind == KEYBOARD_KIND_NAME) {
        charCount = GetClampedString10LengthForFontIndex0_from_thumb(g_KeyboardContext->mRecords[1].mChars, nameChars);
        remaining = 6;
        if (charCount > 4) {
            remaining = 10 - charCount;
        }
        slotIndex = 0;
        entryIndexPointer = gKeyboardRemainingEntryIndices;
        firstShown = 6 - remaining;
        for (; slotIndex < 6; slotIndex++) {
            for (screenIndex = 0; screenIndex < 2; screenIndex++) {
                if (slotIndex >= firstShown && g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mMode != SCENE_WIFI_MENU) {
                    g_KeyboardContext->mTables[1][screenIndex][*entryIndexPointer].mVisible = 1;
                } else {
                    g_KeyboardContext->mTables[1][screenIndex][*entryIndexPointer].mVisible = 0;
                }
            }
            entryIndexPointer++;
        }
    }
}

void ShowKeyboardLayoutObject(void) {
    s32 layoutIndex;
    BOOL hiddenValue;
    const u8 *entryIndexPointer;
    u8 entryIndex;
    layoutIndex = 0;
    entryIndexPointer = gKeyboardLayoutEntryIndices;
    hiddenValue = FALSE;
    for (; layoutIndex < 6; layoutIndex++) {
        entryIndex = *entryIndexPointer;
        if (entryIndex != 0xff) {
            g_KeyboardContext->mTables[1][1][entryIndex].mVisible = hiddenValue;
        }
        entryIndexPointer++;
    }
    g_KeyboardContext->mTables[1][1][gKeyboardLayoutEntryIndices[g_KeyboardContext->mLayout]].mVisible = 1;
}

void AdvanceKeyboard(void) {
    s32 kindIndex;
    Keyboard *keyboard;
    AdvanceLinkLevelIcons();
    NavigationContext_OnSceneUpdate_from_thumb();
    g_KeyboardContext->mState = g_KeyboardContext->mNextState;
    if (g_KeyboardContext->mTextEntryEnabled != FALSE) {
        AdvanceKeyboardTextEntry();
    }
    switch (g_KeyboardContext->mState) {
        case KEYBOARD_STATE_WAIT_FADE_FRIEND_KEY:
            Keyboard_SwitchFn0_from_thumb();
            break;
        case KEYBOARD_STATE_SLIDE_IN_FRIEND_KEY:
            Keyboard_SwitchFn1_from_thumb();
            break;
        case KEYBOARD_STATE_ENTER_FRIEND_KEY:
            Keyboard_SwitchFn2_from_thumb();
            break;
        case KEYBOARD_STATE_SLIDE_OUT_FRIEND_KEY:
            Keyboard_SwitchFn3_from_thumb();
            break;
        case KEYBOARD_STATE_SHOW_FRIEND_KEY_ERROR:
            Keyboard_SwitchFn4_from_thumb();
            break;
        case KEYBOARD_STATE_WAIT_FADE_NAME:
            Keyboard_SwitchFn5_from_thumb();
            break;
        case KEYBOARD_STATE_SLIDE_IN_NAME:
            Keyboard_SwitchFn6_from_thumb();
            break;
        case KEYBOARD_STATE_ENTER_NAME:
            Keyboard_SwitchFn7_from_thumb();
            break;
        case KEYBOARD_STATE_SLIDE_OUT_NAME:
            Keyboard_SwitchFn8_from_thumb();
            break;
        case KEYBOARD_STATE_SLIDE_IN_CONFIRM:
            Keyboard_SwitchFn9_from_thumb();
            break;
        case KEYBOARD_STATE_ANSWER_CONFIRM:
            Keyboard_SwitchFn10_from_thumb();
            break;
        case KEYBOARD_STATE_SHOW_SAVING:
            Keyboard_SwitchFn11_from_thumb();
            break;
        case KEYBOARD_STATE_WAIT_BACKUP:
            Keyboard_SwitchFn12_from_thumb();
            break;
        case KEYBOARD_STATE_ASK_EMBLEM:
            Keyboard_SwitchFn13_from_thumb();
            break;
    }
    PrintKeyboardTextChars();
    ShowKeyboardTextIndexObject();
    ShowKeyboardRemainingCharObjects();
    ShowKeyboardCursorButtonObjects();
    ShowKeyboardDisabledButtonObjects();
    WriteKeyboardObjectOffsets();
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        keyboard = g_KeyboardContext;
        DrawLayoutTable(keyboard->mBncls[kindIndex], keyboard->mNcer, keyboard->mBnlls[kindIndex],
                        GetKeyboardOam_from_thumb(), keyboard->mTables[kindIndex][0]);
    }
    keyboard = g_KeyboardContext;
    DrawLayoutTable(keyboard->mBncls[keyboard->mKind], keyboard->mNcer, keyboard->mBnlls[keyboard->mKind],
                    GetKeyboardSecondBuffer(), keyboard->mTables[keyboard->mKind][1]);
}

void WriteKeyboardRegisters(void) {
    SetKeyboardOffset(0, g_KeyboardContext->mOffsetY + 0x28);
    reg_G2S_DB_BG3OFS = (-g_KeyboardContext->mOffsetY << 16) & 0x1ff0000;
    UploadKeyboardBg2Data();
    NavigationContext_OnSceneVblank_from_thumb();
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardContextNextSceneId_from_thumb(void) {
    return g_KeyboardContext->mRecords[KEYBOARD_RECORD_STATUS].mNextScene;
}
#pragma thumb off
