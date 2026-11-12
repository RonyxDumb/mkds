#include "Main/Menu/keyboard_buttons.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/data_0215d000.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Menu/keyboard_keys.h"
#include "Main/Menu/txt_system.h"
#include "os_thread.h"
#include "Main/Save/buddy_records_write.h"
#include "Main/Menu/message_screen.h"
#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/keyboard_scene.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "code_0214cfe4.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Graphics/scene_text.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/scene_text_init.h"
#include "code_0200eddc.h"
#include "gfd_VramTransferManager.h"
#include "gx_bgcnt.h"
#include "gx_load2d.h"
#include "Main/Menu/data_0216e000.h"
#include "code_02134398.h"
#include "output_effect.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Graphics/back_screen.h"
#include "Main/System/result_archive_path.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"

Keyboard *gKeyboard;

BOOL IsLocateFriendOnWithBuddyStatus4(void) {
    BOOL result = FALSE;
    if (!gBackupBuffers->mFirstBlock->mLocateFriendOff) {
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
    s32 i;
    s32 j;
    s32 bufferIndex;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            remaining[1] -=
                InitLabelCanvas(gKeyboard->mHeap, gKeyboardButtonLabelIndices[i][j], gKeyboard->mBnlls[i],
                                buttonSizes[i][j][0], buttonSizes[i][j][1], gKeyboardButtonEntryIndices[i][j][0],
                                gKeyboard->mNcer, gKeyboard->mBncls[i], gKeyboard->mTables[i][1], remaining[1]);
        }
    }
    for (j = 0; j < 2; j++) {
        for (bufferIndex = 0; bufferIndex < 2; bufferIndex++) {
            for (i = 0; i < gKeyboardTextLimits[j]; i++) {
                remaining[bufferIndex] -= InitLabelCanvas(
                    gKeyboard->mHeap, gKeyboardTextCharLabelIndices[j][i], gKeyboard->mBnlls[j], charSizes[j][i][0],
                    charSizes[j][i][1], gKeyboardTextIndexEntryIndices[j][i], gKeyboard->mNcer, gKeyboard->mBncls[j],
                    gKeyboard->mTables[j][bufferIndex], remaining[bufferIndex]);
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
const u8 gKeyboardTextLimits[2] = {0xc, 0xa};
const u8 gKeyboardTextSlotEntryIndices[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void SetKeyboardButtonCorners(void) {
    SetKeyboardButton0Corners(0x24, 0x7a, 0x7e, 0x8e);
    SetKeyboardButton1Corners(0x82, 0x7a, 0xdc, 0x8e);
}

#pragma thumb off

#pragma thumb on

void PrintKeyboardButtonTexts(void) {
    s32 kindIndex;
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        Keyboard *keyboard = gKeyboard;
        PrintLabelLayoutTextNoFixedAdvance(1, gKeyboardButtonLabelIndices[kindIndex][0], gKeyboard->mBnlls[kindIndex],
                                           GetBmgEntry(keyboard->mCommonMessages, 4), keyboard->mBncls[kindIndex],
                                           keyboard->mTables[kindIndex][1]);
        keyboard = gKeyboard;
        PrintLabelLayoutTextNoFixedAdvance(1, gKeyboardButtonLabelIndices[kindIndex][1], gKeyboard->mBnlls[kindIndex],
                                           GetBmgEntry(keyboard->mCommonMessages, 5), keyboard->mBncls[kindIndex],
                                           keyboard->mTables[kindIndex][1]);
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
                    &gKeyboard
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
                gKeyboard->mTables[kindIndex][0][gKeyboardButtonEntryIndices[kindIndex][itemIndex][entryIndex]]
                    .mVisible = 0;
            }
            gKeyboard
                ->mTables[kindIndex][0]
                         [gKeyboardButtonLabelIndices[kindIndex][itemIndex] + gKeyboard->mBncls[kindIndex]->mCount]
                .mVisible = 0;
        }
    }
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        for (itemIndex = 0; itemIndex < gKeyboardTextLimits[kindIndex]; itemIndex++) {
            gKeyboard->mTables[kindIndex][0][gKeyboardTextIndexEntryIndices[kindIndex][itemIndex]].mVisible = 0;
        }
    }
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        for (entryIndex = 0; entryIndex < 4; entryIndex++) {
            gKeyboard->mTables[kindIndex][0][gKeyboardCursorCornerEntryIndices[kindIndex][entryIndex]].mVisible = 0;
        }
    }
    for (itemIndex = 0; itemIndex < 10; itemIndex++) {
        gKeyboard->mTables[1][0][gKeyboardTextSlotEntryIndices[itemIndex]].mVisible = 0;
    }
}

void SetKeyboardTextFromFriendKey(void) {
    u16 text[12];
    text[0] = 0;
    MIi_CpuClear16(text[0], &text[1], 0x1a);
    MIi_CpuCopy16(&gKeyboard->mRecords[0], &text[1], 0x18);
    SetKeyboardText(&text[1]);
}

void SetKeyboardTextFromName(void) {
    u16 text[12];
    text[0] = 0;
    MIi_CpuClear16(text[0], &text[1], 0x16);
    MIi_CpuCopy16(&gKeyboard->mRecords[1], &text[1], 0x14);
    SetKeyboardText(&text[1]);
}

void SetKeyboardTextFromPlayerName(void) {
    u16 text[12];
    text[0] = 0;
    MIi_CpuClear16(text[0], &text[1], 0x16);
    MIi_CpuCopy16(gBackupBuffers->mFirstBlock->mPlayerName, &text[1], 0x14);
    SetKeyboardText(&text[1]);
}

void CopyKeyboardTextAsBytes(void) {
    s32 charIndex;
    MI_CpuFill8(&gKeyboard->mRecords[2], 0, 0xd);
    for (charIndex = 0; charIndex < 12; charIndex++) {
        ((u8 *) &gKeyboard->mRecords[2])[charIndex] = gKeyboard->mRecords[0].mChars[charIndex];
    }
}

void InitKeyboard(void *heap, s32 mode) {
    volatile u16 zero;
    SceneTextInitParams config;
    s32 index;
    s32 screenIndex;
    gKeyboard = HeapAlloc(heap, 0xc4);
    gKeyboard->mHeap = heap;
    gKeyboard->mDisplaySettings = CreateSceneDisplaySettings(heap);
    InitLinkLevelIcons(heap, GetKeyboardFirstBuffer());
    config.mUseTxtSystem = 1;
    config.mTxtSystemFont = GetFontByIndex(1);
    config.mUseCanvas1 = 0;
    config.mUseCanvas2 = 1;
    config.mUseCanvas3 = 0;
    config.mUseSelectChoises = 0;
    config.mSelectChoisesFont = NULL;
    config.mUseSelectReturn = 0;
    config.mUseBackScreen = 1;
    if (mode == 0xc) {
        config.mBackScreenKind = 1;
    } else {
        config.mBackScreenKind = 0;
    }
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &config);
    InitKeyboardDisplay();
    LoadKeyboardFiles();
    ResetOamLists(GetKeyboardFirstBuffer(), GetKeyboardSecondBuffer());
    InitKeyboardTextEntry(0x20, 0x40, 0xc);
    SetKeyboardOffset(0, 0x28);
    SetKeyboardButtonCorners();
    SetKeyboardScreenMapTopBitsWrapper(0);
    gKeyboard->mRecords[2].mMode = mode;
    gKeyboard->mRecords[2].mNextScene = -1;
    if (mode == 0xc) {
        gKeyboard->mKind = 0;
        gKeyboard->mState = 0;
        gKeyboard->mButtonEnabled[0] = 0;
        gKeyboard->mButtonEnabled[1] = 1;
    } else {
        gKeyboard->mKind = 1;
        gKeyboard->mState = 5;
        gKeyboard->mButtonEnabled[0] = 1;
        if (mode == 0xb) {
            gKeyboard->mButtonEnabled[1] = 0;
        } else {
            gKeyboard->mButtonEnabled[1] = 1;
        }
        SetKeyboardTextFromPlayerName();
    }
    if (gKeyboard->mKind == 0) {
        gKeyboard->mLayout = 0;
        SetKeyboardTextLimit(gKeyboardTextLimits[0]);
    } else {
        if (gStartupWork->mRegion == 0) {
            gKeyboard->mLayout = 1;
        } else {
            gKeyboard->mLayout = 2;
        }
        SetKeyboardTextLimit(gKeyboardTextLimits[1]);
    }
    SelectKeyboardLayout(gKeyboard->mLayout);
    QueueKeyboardScreenMap();
    for (index = 0; index < 2; index++) {
        gKeyboard->mCursorOnButton[index] = 0;
    }
    gKeyboard->mTextEntryEnabled = FALSE;
    gKeyboard->mNextState = gKeyboard->mState;
    gKeyboard->mStateFrames = 0;
    gKeyboard->mOffsetY = 0xc0;
    for (index = 0; index < 2; index++) {
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            gKeyboard->mTextOffsetY[index][screenIndex] = gKeyboardTextOffsetYInitial[index][screenIndex];
        }
    }
    gKeyboard->mCommonMessages = FindFileInLoadedArchives(gKeyboardCommonBmgName);
    for (index = 0; index < 2; index++) {
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            InitLayoutTable(heap, gKeyboard->mBncls[index], gKeyboard->mBnlls[index],
                            &gKeyboard->mTables[index][screenIndex]);
        }
    }
    InitKeyboardCursorCorners();
    for (index = 0; index < 2; index++) {
        zero = 0;
        MIi_CpuClear16(zero, &gKeyboard->mRecords[index], 0x18);
    }
    InitKeyboardLabelCanvases();
    PrintKeyboardButtonTexts();
    HideKeyboardFirstBufferObjects();
    WriteKeyboardObjectOffsets();
}
#pragma thumb off

#pragma thumb on

void ReleaseKeyboard(void) {
    ClearLinkLevelIconsPointer();
    ReleaseSceneText();
    *(u32 *) &gKeyboard = 0;
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
        cellCounts[kindIndex] = gKeyboard->mBncls[kindIndex]->mCount;
        for (screenIndex = 0; screenIndex < 2; screenIndex++) {
            offsetY = -500;
            if (kindIndex == 1 || gKeyboard->mRecords[2].mMode == 0xc) {
                offsetY = gKeyboard->mTextOffsetY[kindIndex][screenIndex];
            }
            for (entryIndex = 0; entryIndex < gKeyboardKindEntryCounts[kindIndex]; entryIndex++) {
                gKeyboard->mTables[kindIndex][screenIndex][gKeyboardKindEntryIndices[kindIndex][entryIndex]].mOffsetY = offsetY;
            }
            for (entryIndex = 0; entryIndex < gKeyboardTextLimits[kindIndex]; entryIndex++) {
                gKeyboard->mTables[kindIndex][screenIndex][gKeyboardTextIndexEntryIndices[kindIndex][entryIndex]]
                    .mOffsetY = offsetY;
                (gKeyboard->mTables[kindIndex][screenIndex] +
                 cellCounts[kindIndex])[gKeyboardTextCharLabelIndices[kindIndex][entryIndex]]
                    .mOffsetY = offsetY;
            }
            offsetY = gKeyboard->mOffsetY;
            for (buttonIndex = 0; buttonIndex < 2; buttonIndex++) {
                for (entryIndex = 0; entryIndex < 3; entryIndex++) {
                    gKeyboard
                        ->mTables[kindIndex][screenIndex]
                                 [gKeyboardButtonEntryIndices[kindIndex][buttonIndex][entryIndex]]
                        .mOffsetY = offsetY;
                }
                (gKeyboard->mTables[kindIndex][screenIndex] +
                 cellCounts[kindIndex])[gKeyboardButtonLabelIndices[kindIndex][buttonIndex]]
                    .mOffsetY = offsetY;
            }
            keyboardOffsetY = gKeyboard->mOffsetY;
            GetKeyboardCursorBoundsRelative(&cursorLeft, &cursorTop, &cursorRight, &cursorBottom);
            gKeyboard->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][0]].mPositionX =
                cursorLeft;
            gKeyboard->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][0]].mPositionY =
                keyboardOffsetY + cursorTop + 0x28;
            gKeyboard->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][1]].mPositionX =
                cursorLeft;
            gKeyboard->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][1]].mPositionY =
                keyboardOffsetY + cursorBottom + 0x28;
            gKeyboard->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][2]].mPositionX =
                cursorRight;
            gKeyboard->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][2]].mPositionY =
                keyboardOffsetY + cursorTop + 0x28;
            gKeyboard->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][3]].mPositionX =
                cursorRight;
            gKeyboard->mTables[kindIndex][screenIndex][gKeyboardCursorCornerEntryIndices[kindIndex][3]].mPositionY =
                keyboardOffsetY + cursorBottom + 0x28;
        }
    }
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        offsetY = -500;
        if (gKeyboard->mKind == 1 && kindIndex == 1) {
            offsetY = gKeyboard->mOffsetY;
        }
        for (entryIndex = 0; entryIndex < 10; entryIndex++) {
            gKeyboard->mTables[1][kindIndex][gKeyboardTextSlotEntryIndices[entryIndex]].mOffsetY = offsetY;
        }
        offsetY = -500;
        if (gKeyboard->mKind == 1) {
            offsetY = gKeyboard->mTextOffsetY[1][kindIndex];
        }
        for (entryIndex = 0; entryIndex < 6; entryIndex++) {
            gKeyboard->mTables[1][kindIndex][gKeyboardRemainingEntryIndices[entryIndex]].mOffsetY = offsetY;
        }
    }
}
#pragma thumb off

#pragma thumb on

void QueueKeyboardScreenMap(void) {
    Nscr *screenMap;
    screenMap = gKeyboard->mNscrs[gKeyboard->mKind];
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, screenMap->mData, screenMap->mDataSize);
}

void LoadKeyboardFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    file = FindSceneFile("Keyboard_s_10key.bnbl");
    gKeyboard->mBnbls[0] = file;
    file = FindSceneFile("Keyboard_s_10key.bncl");
    gKeyboard->mBncls[0] = file;
    file = FindSceneFile("Keyboard_s_10key.bnll");
    gKeyboard->mBnlls[0] = file;
    file = FindSceneFile(gKeyboardSBnblName);
    gKeyboard->mBnbls[1] = file;
    file = FindSceneFile(gKeyboardSBnclName);
    gKeyboard->mBncls[1] = file;
    file = FindSceneFile(gKeyboardSBnllName);
    gKeyboard->mBnlls[1] = file;
    file = FindSceneFile(gKeyboardSONceNcgrName);
    LoadNcgrData2(&gKeyboard->mNcgr, file);
    file = FindSceneFile(gKeyboardSONceNcerName);
    LoadNcerData(&gKeyboard->mNcer, file);
    file = FindSceneFile(gKeyboardSONclrName);
    LoadNclrData(&gKeyboard->mNclr, file);
    DC_FlushRange(gKeyboard->mNcgr->mData, gKeyboard->mNcgr->mDataSize);
    GX_LoadOBJ(gKeyboard->mNcgr->mData, 0, gKeyboard->mNcgr->mDataSize);
    GXS_LoadOBJ(gKeyboard->mNcgr->mData, 0, gKeyboard->mNcgr->mDataSize);
    DC_FlushRange(gKeyboard->mNclr->mData, gKeyboard->mNclr->mDataSize);
    GX_LoadOBJPltt(gKeyboard->mNclr->mData, 0, (0x000001a0u));
    GX_LoadOBJPltt(&gKeyboard->mNclr->mData[0xe0], 0x1c0, 0x40);
    GXS_LoadOBJPltt(gKeyboard->mNclr->mData, 0, gKeyboard->mNclr->mDataSize);
    file = FindSceneFile(gKeyboardSBFlameNcgrName);
    LoadNcgrData(&chars, file);
    DC_FlushRange(chars->mData, chars->mDataSize);
    GXS_LoadBG3Char(chars->mData, 0, chars->mDataSize);
    file = FindSceneFile(gKeyboardSBFlame02NscrName);
    LoadNscrData(&gKeyboard->mNscrs[0], file);
    file = FindSceneFile(gKeyboardSBFlame01NscrName);
    LoadNscrData(&gKeyboard->mNscrs[1], file);
    file = FindSceneFile(gKeyboardSBNclrName);
    LoadNclrData(&palette, file);
    DC_FlushRange(palette->mData, 0x80);
    GXS_LoadBGPltt(palette->mData, 0, 0x80);
}

#pragma thumb off

#pragma thumb on
void InitKeyboardDisplay(void) {
    u32 subDisplayBits;
    reg_G2S_DB_BLDCNT = 0;
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    subDisplayBits |= 0xc;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (subDisplayBits << 8);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x8018;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x9010;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
    MemFillWordsByBlock_inline((void *) G2_GetBG2ScrPtr(), 0x1000);
    MemFillWordsByBlock_inline((void *) G2_GetBG3ScrPtr(), 0x1000);
}

void AdvanceKeyboardState0(void) {
    if (AreBrightnessFadesClear() != 0) {
        gKeyboard->mNextState = 1;
        SetupTxtSystemMainTextEx(GetBmgEntry(gKeyboard->mCommonMessages, 7), 0, 0, 0, 0, 0, 0);
    }
}

void UpdateKeyboardFriendKeyButtons(void) {
    s32 lastCharIndex;
    lastCharIndex = gKeyboardTextLimits[0] - 1;
    if (lastCharIndex == GetKeyboardTextIndex() && gKeyboard->mRecords[gKeyboard->mKind].mChars[lastCharIndex] != 0) {
        gKeyboard->mButtonEnabled[0] = 1;
    } else {
        gKeyboard->mButtonEnabled[0] = 0;
    }
    if (GetKeyboardCursorValueWrapper() == 1) {
        gKeyboard->mCursorOnButton[0] = 1;
    } else {
        gKeyboard->mCursorOnButton[0] = 0;
    }
    if (GetKeyboardCursorValueWrapper() == 2) {
        gKeyboard->mCursorOnButton[1] = 1;
    } else {
        gKeyboard->mCursorOnButton[1] = 0;
    }
}

void AdvanceKeyboardState1(void) {
    gKeyboard->mStateFrames++;
    gKeyboard->mOffsetY = InterpolateS16(1, 0xc0, 0, gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[0][1] = InterpolateS16(1, gKeyboardTextOffsetYInitial[0][1],
                                                   gKeyboardTextOffsetYTarget[0][1], gKeyboard->mStateFrames, 0xf);
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf && IsTxtSystemState2NoCloseRequest() != 0) {
        gKeyboard->mNextState = 2;
        gKeyboard->mTextEntryEnabled = TRUE;
        gKeyboard->mStateFrames = 0;
    }
    UpdateKeyboardFriendKeyButtons();
}

void AdvanceKeyboardState2(void) {
    InputSlotIndex inputSlotIndex = UNK_02175628_INDEX_8;
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
    hasPair = gInputSlots[inputSlotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        result = TRUE;
    }
    if (result != FALSE) {
        touchedRectIndex = RectTableFindContaining(gKeyboard->mBnbls[0], gInputSlots[inputSlotIndex].mPair.mPairX,
                                                   gInputSlots[inputSlotIndex].mPair.mPairY);
    }
    keyboard = gKeyboard;
    textRecord = &keyboard->mRecords[keyboard->mKind];
    text = GetKeyboardText();
    MIi_CpuCopy16(text, textRecord, 0x18);
    UpdateKeyboardFriendKeyButtons();
    if (touchedRectIndex == 1 ||
        (GetKeyboardCursorValueWrapper() == 1 && (u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0)) {
        keyboard = gKeyboard;
        if (keyboard->mButtonEnabled[0] != 0) {
            keyboard->mNextState = 3;
            gKeyboard->mRecords[2].mFirstButtonChosen = 1;
            RequestTxtSystemClose();
            MoveKeyboardCursorToValueWrapper(1);
            gKeyboard->mTextEntryEnabled = FALSE;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
        } else {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
        }
    } else if (touchedRectIndex == 0 || (GetKeyboardCursorValueWrapper() == 2 &&
                                         (u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0)) {
        gKeyboard->mNextState = 3;
        gKeyboard->mRecords[2].mFirstButtonChosen = 0;
        RequestTxtSystemClose();
        MoveKeyboardCursorToValueWrapper(2);
        gKeyboard->mTextEntryEnabled = FALSE;
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xe);
    }
}

void AdvanceKeyboardState3(void) {
    Keyboard *keyboard;
    gKeyboard->mStateFrames++;
    gKeyboard->mOffsetY = InterpolateS16(1, 0, 0xc0, gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[0][1] = InterpolateS16(1, gKeyboardTextOffsetYTarget[0][1],
                                                   gKeyboardTextOffsetYInitial[0][1], gKeyboard->mStateFrames, 0xf);
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf && IsTxtSystemState0NoOpenRequest() != 0) {
        keyboard = gKeyboard;
        if (keyboard->mRecords[2].mFirstButtonChosen != 0) {
            CopyKeyboardTextAsBytes();
            switch (CheckFriendKeyString(&gKeyboard->mRecords[2])) {
                case 1:
                    gKeyboard->mNextState = 4;
                    SetupTxtSystemSubText(GetBmgEntry(gKeyboard->mCommonMessages, 0xa));
                    gKeyboard->mStateFrames = 0;
                    return;
                case 2:
                    gKeyboard->mNextState = 4;
                    SetupTxtSystemSubText(GetBmgEntry(gKeyboard->mCommonMessages, 0xb));
                    gKeyboard->mStateFrames = 0;
                    return;
                default:
                    gKeyboard->mNextState = 6;
                    SetupTxtSystemMainTextEx(GetBmgEntry(gKeyboard->mCommonMessages, 8), 0, 0, 0, 0, 0, 0);
                    gKeyboard->mStateFrames = 0;
                    gKeyboard->mKind = 1;
                    if (gStartupWork->mRegion == 0) {
                        gKeyboard->mLayout = 1;
                    } else {
                        gKeyboard->mLayout = 2;
                    }
                    SelectKeyboardLayout(gKeyboard->mLayout);
                    SetKeyboardTextLimit(gKeyboardTextLimits[1]);
                    SetKeyboardTextFromName();
                    QueueKeyboardScreenMap();
                    ShowKeyboardLayoutObject();
                    return;
            }
        } else {
            keyboard->mRecords[2].mNextScene = 0xc;
        }
    }
}

void AdvanceKeyboardState4(void) {
    Keyboard *keyboard;
    gKeyboard->mStateFrames++;
    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x15);
    }
    keyboard = gKeyboard;
    if (keyboard->mStateFrames >= 0x78) {
        keyboard->mNextState = 1;
        SetupTxtSystemMainTextEx(GetBmgEntry(gKeyboard->mCommonMessages, 7), 0, 0, 0, 0, 0, 0);
        gKeyboard->mStateFrames = 0;
    }
}

void AdvanceKeyboardState5(void) {
    if (AreBrightnessFadesClear() != 0) {
        gKeyboard->mNextState = 6;
        SetupTxtSystemMainTextEx(GetBmgEntry(gKeyboard->mCommonMessages, 0xf), 0, 0, 0, 0, 0, 0);
        gKeyboard->mRecords[2].mFirstButtonChosen = 1;
    }
}
#pragma thumb off

#pragma thumb on

void UpdateKeyboardNameButtons(void) {
    s32 charIndex;
    u8 textLimit;
    charIndex = 0;
    gKeyboard->mButtonEnabled[0] = 0;
    for (; charIndex < GetKeyboardTextIndex(); charIndex++) {
        if (GetKeyboardText()[charIndex] != 0x20 && GetKeyboardText()[charIndex] != 0x3000) {
            gKeyboard->mButtonEnabled[0] = 1;
        }
    }
    textLimit = gKeyboardTextLimits[1];
    if (textLimit - 1 == GetKeyboardTextIndex()) {
        if ((GetKeyboardText() + textLimit)[-1] != 0x20 && (GetKeyboardText() + textLimit)[-1] != 0x3000 &&
            (GetKeyboardText() + textLimit)[-1] != 0) {
            gKeyboard->mButtonEnabled[0] = 1;
        }
    }
    if (GetKeyboardCursorValueWrapper() == 1) {
        gKeyboard->mCursorOnButton[0] = 1;
    } else {
        gKeyboard->mCursorOnButton[0] = 0;
    }
    if (GetKeyboardCursorValueWrapper() == 2) {
        gKeyboard->mCursorOnButton[1] = 1;
        return;
    }
    gKeyboard->mCursorOnButton[1] = 0;
}

#pragma thumb off

#pragma thumb on
void AdvanceKeyboardState6(void) {
    Keyboard *keyboard;
    gKeyboard->mStateFrames++;
    gKeyboard->mOffsetY = InterpolateS16(1, 0xc0, 0, gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[1][1] = InterpolateS16(1, gKeyboardTextOffsetYInitial[1][1],
                                                   gKeyboardTextOffsetYTarget[1][1], gKeyboard->mStateFrames, 0xf);
    keyboard = gKeyboard;
    if (keyboard->mRecords[2].mFirstButtonChosen != 0) {
        gKeyboard->mTextOffsetY[0][0] = InterpolateS16(1, gKeyboardTextOffsetYInitial[0][0],
                                                       gKeyboardTextOffsetYTarget[0][0], keyboard->mStateFrames, 0xf);
    }
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf && IsTxtSystemState2NoCloseRequest() != 0) {
        gKeyboard->mNextState = 7;
        gKeyboard->mTextEntryEnabled = TRUE;
        gKeyboard->mStateFrames = 0;
    }
    UpdateKeyboardNameButtons();
    ShowKeyboardLayoutObject();
}

void AdvanceKeyboardState7(void) {
    InputSlotIndex inputSlotIndex = UNK_02175628_INDEX_8;
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
    hasPair = gInputSlots[inputSlotIndex].mPair.mHasPair;
    if (hasPair == 0 && gInputSlots[inputSlotIndex].mPair.mNoPairCount < 5) {
        pairRecentlyLost = TRUE;
    }
    if (pairRecentlyLost == FALSE && gInputSlots[inputSlotIndex].mPair.mPrevHasPair == 0 && hasPair != 0) {
        touched = TRUE;
    }
    if (touched != FALSE) {
        touchedRectIndex = RectTableFindContaining(gKeyboard->mBnbls[1], gInputSlots[inputSlotIndex].mPair.mPairX,
                                                   gInputSlots[inputSlotIndex].mPair.mPairY);
    }
    keyboard = gKeyboard;
    textRecord = &keyboard->mRecords[keyboard->mKind];
    text = GetKeyboardText();
    MIi_CpuCopy16(text, textRecord, 0x18);
    UpdateKeyboardNameButtons();
    if (touchedRectIndex == 5 ||
        (GetKeyboardCursorValueWrapper() == 1 && (u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0)) {
        keyboard = gKeyboard;
        if (keyboard->mButtonEnabled[0] != 0) {
            keyboard->mNextState = 8;
            gKeyboard->mRecords[2].mFirstButtonChosen = 1;
            RequestTxtSystemClose();
            MoveKeyboardCursorToValueWrapper(1);
            gKeyboard->mTextEntryEnabled = FALSE;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
        } else {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
        }
    } else if (touchedRectIndex == 6 || (GetKeyboardCursorValueWrapper() == 2 &&
                                         (u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0)) {
        keyboard = gKeyboard;
        if (keyboard->mButtonEnabled[1] != 0) {
            keyboard->mNextState = 8;
            gKeyboard->mRecords[2].mFirstButtonChosen = 0;
            RequestTxtSystemClose();
            MoveKeyboardCursorToValueWrapper(2);
            gKeyboard->mTextEntryEnabled = FALSE;
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0xe);
        } else {
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x16);
        }
    } else if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_Y) != 0) {
        if (gStartupWork->mRegion == 0) {
            gKeyboard->mLayout = gKeyboardNextLayoutRegion0[gKeyboard->mLayout];
        } else {
            gKeyboard->mLayout = gKeyboardNextLayoutOtherRegion[gKeyboard->mLayout];
        }
        SelectKeyboardLayout(gKeyboard->mLayout);
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1e5);
    } else {
        keyboard = gKeyboard;
        previousLayout = keyboard->mLayout;
        touched = FALSE;
        switch (touchedRectIndex) {
            case 0:
                keyboard->mLayout = 1;
                SelectKeyboardLayout(gKeyboard->mLayout);
                touched = TRUE;
                break;
            case 1:
                keyboard->mLayout = 2;
                SelectKeyboardLayout(gKeyboard->mLayout);
                touched = TRUE;
                break;
            case 2:
                keyboard->mLayout = 3;
                SelectKeyboardLayout(gKeyboard->mLayout);
                touched = TRUE;
                break;
            case 3:
                keyboard->mLayout = 4;
                SelectKeyboardLayout(gKeyboard->mLayout);
                touched = TRUE;
                break;
            case 4:
                keyboard->mLayout = 5;
                SelectKeyboardLayout(gKeyboard->mLayout);
                touched = TRUE;
                break;
        }
        if (touched != FALSE) {
            if (previousLayout != gKeyboard->mLayout) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1e5);
            } else {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x1ed);
            }
        }
    }
    ShowKeyboardLayoutObject();
}

void AdvanceKeyboardState8(void) {
    u16 nameChars[10];
    u16 formattedText[0xfe];
    Keyboard *keyboard;
    s32 charCount;
    void *message;
    void *buttonText;
    void *secondButtonText;
    gKeyboard->mStateFrames++;
    gKeyboard->mOffsetY = InterpolateS16(1, 0, 0xc0, gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[1][1] = InterpolateS16(1, gKeyboardTextOffsetYTarget[1][1],
                                                   gKeyboardTextOffsetYInitial[1][1], gKeyboard->mStateFrames, 0xf);
    keyboard = gKeyboard;
    if (keyboard->mRecords[2].mFirstButtonChosen == 0) {
        gKeyboard->mTextOffsetY[0][0] = InterpolateS16(1, gKeyboardTextOffsetYTarget[0][0],
                                                       gKeyboardTextOffsetYInitial[0][0], keyboard->mStateFrames, 0xf);
    }
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf && IsTxtSystemState0NoOpenRequest() != 0) {
        keyboard = gKeyboard;
        if (keyboard->mRecords[2].mFirstButtonChosen != 0) {
            if (keyboard->mRecords[2].mMode == 0xc) {
                message = GetBmgEntry(keyboard->mCommonMessages, 0x11);
                buttonText = GetBmgEntry(gKeyboard->mCommonMessages, 0);
                secondButtonText = GetBmgEntry(keyboard->mCommonMessages, 1);
                SetupTxtSystemSubTextTwoButtonsEx(message, buttonText, secondButtonText, 0, 0, 1, 1, 0);
            } else {
                message = GetBmgEntry(keyboard->mCommonMessages, 0xe);
                charCount = CopyTextWithinWidth(gKeyboard->mRecords[1].mChars, nameChars);
                nameChars[charCount] = 0;
                FormatMessageWithText(nameChars, message, &formattedText[1], 0x1f4);
                buttonText = GetBmgEntry(gKeyboard->mCommonMessages, 0);
                secondButtonText = GetBmgEntry(gKeyboard->mCommonMessages, 1);
                SetupTxtSystemSubTextTwoButtonsEx(&formattedText[1], buttonText, secondButtonText, 0, 0, 1, 1, 0);
            }
            gKeyboard->mNextState = 9;
            gKeyboard->mStateFrames = 0;
        } else if (keyboard->mRecords[2].mMode == 0xc) {
            keyboard->mKind = 0;
            gKeyboard->mLayout = 0;
            SelectKeyboardLayout(gKeyboard->mLayout);
            SetKeyboardTextLimit(gKeyboardTextLimits[0]);
            QueueKeyboardScreenMap();
            SetKeyboardTextFromFriendKey();
            gKeyboard->mNextState = 1;
            gKeyboard->mStateFrames = 0;
            SetupTxtSystemMainTextEx(GetBmgEntry(gKeyboard->mCommonMessages, 7), 0, 0, 0, 0, 0, 0);
        } else {
            keyboard->mRecords[2].mNextScene = 7;
        }
    }
}

void AdvanceKeyboardState9(void) {
    s16 targetOffsetY;
    gKeyboard->mStateFrames++;
    targetOffsetY = gKeyboardTextOffsetYTarget[1][0];
    gKeyboard->mTextOffsetY[0][0] =
        InterpolateS16(1, gKeyboardTextOffsetYTarget[0][0], gKeyboardTextOffsetYTarget[0][0] - (0xc0 - targetOffsetY),
                       gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[1][0] =
        InterpolateS16(1, gKeyboardTextOffsetYInitial[1][0], targetOffsetY, gKeyboard->mStateFrames, 0xf);
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf) {
        if (IsTxtSystemState2NoCloseRequest() != 0) {
            gKeyboard->mNextState = 0xa;
            gKeyboard->mStateFrames = 0;
        }
    }
}

void AdvanceKeyboardState10(void) {
    Keyboard *keyboard;
    s16 targetOffsetY;
    void *message;
    void *buttonText;
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (GetTxtSystemDone() != 0 && GetTxtSystemSelectedIndex() == 1) {
        targetOffsetY = gKeyboardTextOffsetYTarget[1][0];
        gKeyboard->mTextOffsetY[1][0] =
            InterpolateS16(1, targetOffsetY, gKeyboardTextOffsetYInitial[1][0], gKeyboard->mStateFrames, 0xf);
        gKeyboard->mTextOffsetY[0][0] = InterpolateS16(1, gKeyboardTextOffsetYTarget[0][0] - (0xc0 - targetOffsetY),
                                                       gKeyboardTextOffsetYTarget[0][0], gKeyboard->mStateFrames, 0xf);
    }
    if (IsTxtSystemState0NoOpenRequest() != 0 && gKeyboard->mStateFrames >= 0xf) {
        if (GetTxtSystemSelectedIndex() == 0) {
            keyboard = gKeyboard;
            if (keyboard->mRecords[2].mMode == 0xc) {
                AddBuddyFromFriendKey(&keyboard->mRecords[2], &keyboard->mRecords[1]);
                WriteBackupBuddyRecords();
                message = GetBmgEntry(gKeyboard->mCommonMessages, 0x81);
                SetupTxtSystemSubTextEx(message, 0, 1, 1, 0, 1);
                gKeyboard->mNextState = 0xb;
            } else {
                gBackupBuffers->mFirstBlock->mHasPlayerName = 1;
                MI_CpuFill8(gBackupBuffers->mFirstBlock->mPlayerName, 0, 0x14);
                MI_CpuCopy8(&keyboard->mRecords[1], gBackupBuffers->mFirstBlock->mPlayerName, 0x14);
                WriteBackupFirstBlockWrapper();
                SetTxtSystemOpenSoundId(0x21);
                message = GetBmgEntry(gKeyboard->mCommonMessages, 0x10);
                buttonText = GetBmgEntry(gKeyboard->mCommonMessages, 4);
                SetupTxtSystemSubTextButtonEx(message, buttonText, 0, 1, 1, 0);
                gKeyboard->mNextState = 0xc;
            }
            gKeyboard->mStateFrames = 0;
        } else {
            gKeyboard->mNextState = 6;
            gKeyboard->mRecords[2].mFirstButtonChosen = 0;
            gKeyboard->mStateFrames = 0;
            SetupTxtSystemMainTextEx(GetBmgEntry(gKeyboard->mCommonMessages, 0xf), 0, 0, 0, 0, 0, 0);
        }
    } else {
        if (GetTxtSystemDone() != 0 || IsTxtSystemState0NoOpenRequest() != 0) {
            RequestTxtSystemClose();
            gKeyboard->mStateFrames++;
        }
    }
}

void AdvanceKeyboardState11(void) {
    Keyboard *keyboard;
    void *message;
    s32 backupBusy;
    void *buttonText;
    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x22);
    }
    gKeyboard->mStateFrames++;
    if (IsTxtSystemState2NoCloseRequest() != 0) {
        keyboard = gKeyboard;
        if (keyboard->mStateFrames > 0x5a) {
            backupBusy = (gBackupBuffers->mBusy == 0)
                             ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0)
                             : 1;
            if (backupBusy == 0) {
                keyboard->mNextState = 0xc;
                gKeyboard->mStateFrames = 0;
                SetTxtSystemOpenSoundId(0x21);
                message = GetBmgEntry(gKeyboard->mCommonMessages, 9);
                buttonText = GetBmgEntry(gKeyboard->mCommonMessages, 4);
                SetupTxtSystemSubTextButtonEx(message, buttonText, 0, 1, 1, 0);
            }
        }
    }
}

void AdvanceKeyboardState12(void) {
    void *message;
    s32 backupBusy;
    void *buttonText;
    void *secondButtonText;
    s32 mode;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        backupBusy = (gBackupBuffers->mBusy == 0)
                         ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0)
                         : 1;
        if (backupBusy == 0) {
            SetTxtSystemOpenSoundId(0x23);
            mode = gKeyboard->mRecords[2].mMode;
            if (mode == 0xc || mode == 7) {
                gKeyboard->mRecords[2].mNextScene = mode;
                return;
            }
            if (mode == 0xb) {
                gKeyboard->mNextState = 0xd;
                gKeyboard->mStateFrames = 0;
                message = GetBmgEntry(gKeyboard->mCommonMessages, 0x13);
                buttonText = GetBmgEntry(gKeyboard->mCommonMessages, 0);
                secondButtonText = GetBmgEntry(gKeyboard->mCommonMessages, 1);
                SetupTxtSystemSubTextTwoButtonsEx(message, buttonText, secondButtonText, 0, 0, 1, 1, 0);
            }
        }
    }
}

void AdvanceKeyboardState13(void) {
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            gKeyboard->mRecords[2].mNextScene = 3;
        } else {
            gKeyboard->mRecords[2].mNextScene = 0;
        }
    } else {
        if (GetTxtSystemDone() != 0) {
            RequestTxtSystemClose();
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
            for (charIndex = 0; charIndex < gKeyboardTextLimits[kindIndex]; charIndex++) {
                charString[0] = 0;
                charString[1] = 0;
                charString[0] = gKeyboard->mRecords[kindIndex].mChars[charIndex];
                PrintLabelLayoutTextNoFixedAdvance(
                    screenIndex, gKeyboardTextCharLabelIndices[kindIndex][charIndex], gKeyboard->mBnlls[kindIndex],
                    charString, gKeyboard->mBncls[kindIndex], gKeyboard->mTables[kindIndex][screenIndex]);
            }
        }
    }
}

void ShowKeyboardCursorButtonObjects(void) {
    s32 buttonIndex;
    s32 kind;
    for (buttonIndex = 0; buttonIndex < 2; buttonIndex++) {
        if (gKeyboard->mCursorOnButton[buttonIndex] != 0) {
            kind = gKeyboard->mKind;
            gKeyboard->mTables[kind][1][gKeyboardButtonEntryIndices[kind][buttonIndex][0]].mVisible = 1;
        } else {
            kind = gKeyboard->mKind;
            gKeyboard->mTables[kind][1][gKeyboardButtonEntryIndices[kind][buttonIndex][0]].mVisible = 0;
        }
    }
}

void ShowKeyboardDisabledButtonObjects(void) {
    s32 buttonIndex;
    s32 kind;
    for (buttonIndex = 0; buttonIndex < 2; buttonIndex++) {
        if (gKeyboard->mButtonEnabled[buttonIndex] != 0) {
            kind = gKeyboard->mKind;
            gKeyboard->mTables[kind][1][gKeyboardButtonEntryIndices[kind][buttonIndex][1]].mVisible = 0;
        } else {
            kind = gKeyboard->mKind;
            gKeyboard->mTables[kind][1][gKeyboardButtonEntryIndices[kind][buttonIndex][1]].mVisible = 1;
        }
    }
}

void ShowKeyboardTextIndexObject(void) {
    s32 charIndex;
    for (charIndex = 0; charIndex < gKeyboardTextLimits[gKeyboard->mKind]; charIndex++) {
        gKeyboard->mTables[gKeyboard->mKind][1][gKeyboardTextIndexEntryIndices[gKeyboard->mKind][charIndex]].mVisible =
            0;
    }
    gKeyboard->mTables[gKeyboard->mKind][1][gKeyboardTextIndexEntryIndices[gKeyboard->mKind][GetKeyboardTextIndex()]]
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
    if (gKeyboard->mKind == 1) {
        charCount = CopyTextWithinWidth(gKeyboard->mRecords[1].mChars, nameChars);
        remaining = 6;
        if (charCount > 4) {
            remaining = 10 - charCount;
        }
        slotIndex = 0;
        entryIndexPointer = gKeyboardRemainingEntryIndices;
        firstShown = 6 - remaining;
        for (; slotIndex < 6; slotIndex++) {
            for (screenIndex = 0; screenIndex < 2; screenIndex++) {
                if (slotIndex >= firstShown && gKeyboard->mRecords[2].mMode != 0xc) {
                    gKeyboard->mTables[1][screenIndex][*entryIndexPointer].mVisible = 1;
                } else {
                    gKeyboard->mTables[1][screenIndex][*entryIndexPointer].mVisible = 0;
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
            gKeyboard->mTables[1][1][entryIndex].mVisible = hiddenValue;
        }
        entryIndexPointer++;
    }
    gKeyboard->mTables[1][1][gKeyboardLayoutEntryIndices[gKeyboard->mLayout]].mVisible = 1;
}

void AdvanceKeyboard(void) {
    s32 kindIndex;
    Keyboard *keyboard;
    AdvanceLinkLevelIcons();
    AdvanceSceneText();
    gKeyboard->mState = gKeyboard->mNextState;
    if (gKeyboard->mTextEntryEnabled != FALSE) {
        AdvanceKeyboardTextEntry();
    }
    switch (gKeyboard->mState) {
        case 0:
            AdvanceKeyboardState0();
            break;
        case 1:
            AdvanceKeyboardState1();
            break;
        case 2:
            AdvanceKeyboardState2();
            break;
        case 3:
            AdvanceKeyboardState3();
            break;
        case 4:
            AdvanceKeyboardState4();
            break;
        case 5:
            AdvanceKeyboardState5();
            break;
        case 6:
            AdvanceKeyboardState6();
            break;
        case 7:
            AdvanceKeyboardState7();
            break;
        case 8:
            AdvanceKeyboardState8();
            break;
        case 9:
            AdvanceKeyboardState9();
            break;
        case 10:
            AdvanceKeyboardState10();
            break;
        case 11:
            AdvanceKeyboardState11();
            break;
        case 12:
            AdvanceKeyboardState12();
            break;
        case 13:
            AdvanceKeyboardState13();
            break;
    }
    PrintKeyboardTextChars();
    ShowKeyboardTextIndexObject();
    ShowKeyboardRemainingCharObjects();
    ShowKeyboardCursorButtonObjects();
    ShowKeyboardDisabledButtonObjects();
    WriteKeyboardObjectOffsets();
    for (kindIndex = 0; kindIndex < 2; kindIndex++) {
        keyboard = gKeyboard;
        DrawLayoutTable(keyboard->mBncls[kindIndex], keyboard->mNcer, keyboard->mBnlls[kindIndex],
                        GetKeyboardFirstBuffer(), keyboard->mTables[kindIndex][0]);
    }
    keyboard = gKeyboard;
    DrawLayoutTable(keyboard->mBncls[keyboard->mKind], keyboard->mNcer, keyboard->mBnlls[keyboard->mKind],
                    GetKeyboardSecondBuffer(), keyboard->mTables[keyboard->mKind][1]);
}

void WriteKeyboardRegisters(void) {
    SetKeyboardOffset(0, gKeyboard->mOffsetY + 0x28);
    reg_G2S_DB_BG3OFS = (-gKeyboard->mOffsetY << 16) & 0x1ff0000;
    UploadKeyboardBg2Data();
    WriteSceneTextRegisters();
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardNextScene(void) {
    return gKeyboard->mRecords[2].mNextScene;
}
#pragma thumb off
