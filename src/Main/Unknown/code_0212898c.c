#include "Main/Unknown/code_0212898c.h"

#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_020ab748.h"
#include "Main/Unknown/code_020ab758.h"
#include "Main/Unknown/code_020ab8c4.h"
#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126248.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02129ea4.h"
#include "Main/Unknown/code_0212a1e0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02128884.h"
#include "Main/Unknown/code_02129000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020ab798.h"
#include "Main/Unknown/code_0201ea58.h"
#include "code_0214cfe4.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_02129cbc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02129788.h"
#include "Main/Unknown/code_020aba9c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ab7a4.h"
#include "Main/Unknown/code_020ab8d4.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_0212abd0.h"
#include "code_0200eddc.h"
#include "code_02016468.h"
#include "Main/Unknown/code_021262f0.h"
#include "code_0214a054.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020ab848.h"
#include "Main/Unknown/code_0212a1c4.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_0212a700.h"
#include "Main/Unknown/code_0212a724.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_02047104.h"
#include "registers.h"

#pragma thumb on

void SetKeyboardButtonCorners(void) {
    SetKeyboardButton0Corners(0x24, 0x7a, 0x7e, 0x8e);
    SetKeyboardButton1Corners(0x82, 0x7a, 0xdc, 0x8e);
}

#pragma thumb off

#pragma thumb on

void PrintKeyboardButtonTexts(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        Keyboard *keyboard = gKeyboard;
        PrintLabelLayoutTextNoFixedAdvance(1, gKeyboardButtonLabelIndices[i][0], gKeyboard->mBnlls[i],
                                           GetBmgEntry(keyboard->mCommonMessages, 4), keyboard->mBncls[i],
                                           keyboard->mTables[i][1]);
        keyboard = gKeyboard;
        PrintLabelLayoutTextNoFixedAdvance(1, gKeyboardButtonLabelIndices[i][1], gKeyboard->mBnlls[i],
                                           GetBmgEntry(keyboard->mCommonMessages, 5), keyboard->mBncls[i],
                                           keyboard->mTables[i][1]);
    }
}

void InitKeyboardCursorCorners(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 4; k++) {
                LayoutTableEntry *entry = &gKeyboard->mTables[i][j][gKeyboardCursorCornerEntryIndices[i][k]];
                entry->mUsePosition = TRUE;
                entry->mPositionX = 0;
                entry->mPositionY = 0;
            }
        }
    }
}

void HideKeyboardFirstBufferObjects(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                gKeyboard->mTables[i][0][gKeyboardButtonEntryIndices[i][j][k]].mVisible = 0;
            }
            gKeyboard->mTables[i][0][gKeyboardButtonLabelIndices[i][j] + gKeyboard->mBncls[i]->mCount].mVisible = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gKeyboardTextLimits[i]; j++) {
            gKeyboard->mTables[i][0][gKeyboardTextIndexEntryIndices[i][j]].mVisible = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (k = 0; k < 4; k++) {
            gKeyboard->mTables[i][0][gKeyboardCursorCornerEntryIndices[i][k]].mVisible = 0;
        }
    }
    for (j = 0; j < 10; j++) {
        gKeyboard->mTables[1][0][data_0215d110[j]].mVisible = 0;
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
    MIi_CpuCopy16(data_0217aa08->mFirstBlock->mPlayerName, &text[1], 0x14);
    SetKeyboardText(&text[1]);
}

void CopyKeyboardTextAsBytes(void) {
    s32 i;
    MI_CpuFill8(&gKeyboard->mRecords[2], 0, 0xd);
    for (i = 0; i < 12; i++) {
        ((u8 *) &gKeyboard->mRecords[2])[i] = gKeyboard->mRecords[0].mChars[i];
    }
}

void InitKeyboard(void *heap, s32 mode) {
    volatile u16 zero;
    SceneTextInitParams config;
    s32 i;
    s32 j;
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
    for (i = 0; i < 2; i++) {
        gKeyboard->mCursorOnButton[i] = 0;
    }
    gKeyboard->mTextEntryEnabled = FALSE;
    gKeyboard->mNextState = gKeyboard->mState;
    gKeyboard->mStateFrames = 0;
    gKeyboard->mOffsetY = 0xc0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gKeyboard->mTextOffsetY[i][j] = gKeyboardTextOffsetYInitial[i][j];
        }
    }
    gKeyboard->mCommonMessages = FindFileInLoadedArchives(data_0216ea60);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            InitLayoutTable(heap, gKeyboard->mBncls[i], gKeyboard->mBnlls[i], &gKeyboard->mTables[i][j]);
        }
    }
    InitKeyboardCursorCorners();
    for (i = 0; i < 2; i++) {
        zero = 0;
        MIi_CpuClear16(zero, &gKeyboard->mRecords[i], 0x18);
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
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s16 offsetY;
    s16 keyboardOffsetY;
    for (i = 0; i < 2; i++) {
        cellCounts[i] = gKeyboard->mBncls[i]->mCount;
        for (j = 0; j < 2; j++) {
            offsetY = -500;
            if (i == 1 || gKeyboard->mRecords[2].mMode == 0xc) {
                offsetY = gKeyboard->mTextOffsetY[i][j];
            }
            for (k = 0; k < data_0215d0d8[i]; k++) {
                gKeyboard->mTables[i][j][data_0215d0dc[i][k]].mOffsetY = offsetY;
            }
            for (k = 0; k < gKeyboardTextLimits[i]; k++) {
                gKeyboard->mTables[i][j][gKeyboardTextIndexEntryIndices[i][k]].mOffsetY = offsetY;
                (gKeyboard->mTables[i][j] + cellCounts[i])[gKeyboardTextCharLabelIndices[i][k]].mOffsetY = offsetY;
            }
            offsetY = gKeyboard->mOffsetY;
            for (m = 0; m < 2; m++) {
                for (k = 0; k < 3; k++) {
                    gKeyboard->mTables[i][j][gKeyboardButtonEntryIndices[i][m][k]].mOffsetY = offsetY;
                }
                (gKeyboard->mTables[i][j] + cellCounts[i])[gKeyboardButtonLabelIndices[i][m]].mOffsetY = offsetY;
            }
            keyboardOffsetY = gKeyboard->mOffsetY;
            GetKeyboardCursorBoundsRelative(&cursorLeft, &cursorTop, &cursorRight, &cursorBottom);
            gKeyboard->mTables[i][j][gKeyboardCursorCornerEntryIndices[i][0]].mPositionX = cursorLeft;
            gKeyboard->mTables[i][j][gKeyboardCursorCornerEntryIndices[i][0]].mPositionY =
                keyboardOffsetY + cursorTop + 0x28;
            gKeyboard->mTables[i][j][gKeyboardCursorCornerEntryIndices[i][1]].mPositionX = cursorLeft;
            gKeyboard->mTables[i][j][gKeyboardCursorCornerEntryIndices[i][1]].mPositionY =
                keyboardOffsetY + cursorBottom + 0x28;
            gKeyboard->mTables[i][j][gKeyboardCursorCornerEntryIndices[i][2]].mPositionX = cursorRight;
            gKeyboard->mTables[i][j][gKeyboardCursorCornerEntryIndices[i][2]].mPositionY =
                keyboardOffsetY + cursorTop + 0x28;
            gKeyboard->mTables[i][j][gKeyboardCursorCornerEntryIndices[i][3]].mPositionX = cursorRight;
            gKeyboard->mTables[i][j][gKeyboardCursorCornerEntryIndices[i][3]].mPositionY =
                keyboardOffsetY + cursorBottom + 0x28;
        }
    }
    for (i = 0; i < 2; i++) {
        offsetY = -500;
        if (gKeyboard->mKind == 1 && i == 1) {
            offsetY = gKeyboard->mOffsetY;
        }
        for (k = 0; k < 10; k++) {
            gKeyboard->mTables[1][i][data_0215d110[k]].mOffsetY = offsetY;
        }
        offsetY = -500;
        if (gKeyboard->mKind == 1) {
            offsetY = gKeyboard->mTextOffsetY[1][i];
        }
        for (k = 0; k < 6; k++) {
            gKeyboard->mTables[1][i][data_0215d0f0[k]].mOffsetY = offsetY;
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
    file = FindSceneFile(gKeyboardS10KeyBnblName);
    gKeyboard->mBnbls[0] = file;
    file = FindSceneFile(gKeyboardS10KeyBnclName);
    gKeyboard->mBncls[0] = file;
    file = FindSceneFile(gKeyboardS10KeyBnllName);
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
    BOOL g;
    u16 c;
    result = FALSE;
    touchedRectIndex = -1;
    g = FALSE;
    c = data_02175674[inputSlotIndex].mPressedBits;
    if (c == 0 && data_02175680[inputSlotIndex].mPressedBits < 5) {
        g = TRUE;
    }
    if (g == FALSE && data_0217567c[inputSlotIndex].mPressedBits == 0 && c != 0) {
        result = TRUE;
    }
    if (result != FALSE) {
        touchedRectIndex = RectTableFindContaining(gKeyboard->mBnbls[0], data_02175670[inputSlotIndex].mPressedBits,
                                                   data_02175672[inputSlotIndex].mPressedBits);
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
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
        }
    } else if (touchedRectIndex == 0 || (GetKeyboardCursorValueWrapper() == 2 &&
                                         (u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_A) != 0)) {
        gKeyboard->mNextState = 3;
        gKeyboard->mRecords[2].mFirstButtonChosen = 0;
        RequestTxtSystemClose();
        MoveKeyboardCursorToValueWrapper(2);
        gKeyboard->mTextEntryEnabled = FALSE;
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xe);
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
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
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
    s32 i;
    u8 textLimit;
    i = 0;
    gKeyboard->mButtonEnabled[0] = 0;
    for (; i < GetKeyboardTextIndex(); i++) {
        if (GetKeyboardText()[i] != 0x20 && GetKeyboardText()[i] != 0x3000) {
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
    BOOL f;
    BOOL g;
    s32 previousLayout;
    u16 c;
    f = FALSE;
    touchedRectIndex = -1;
    g = FALSE;
    c = data_02175674[inputSlotIndex].mPressedBits;
    if (c == 0 && data_02175680[inputSlotIndex].mPressedBits < 5) {
        g = TRUE;
    }
    if (g == FALSE && data_0217567c[inputSlotIndex].mPressedBits == 0 && c != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        touchedRectIndex = RectTableFindContaining(gKeyboard->mBnbls[1], data_02175670[inputSlotIndex].mPressedBits,
                                                   data_02175672[inputSlotIndex].mPressedBits);
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
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
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
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xe);
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
        }
    } else if ((u16) (gInputSlots[inputSlotIndex].mPressedBits & PAD_KEY_Y) != 0) {
        if (gStartupWork->mRegion == 0) {
            gKeyboard->mLayout = gKeyboardNextLayoutRegion0[gKeyboard->mLayout];
        } else {
            gKeyboard->mLayout = gKeyboardNextLayoutOtherRegion[gKeyboard->mLayout];
        }
        SelectKeyboardLayout(gKeyboard->mLayout);
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e5);
    } else {
        keyboard = gKeyboard;
        previousLayout = keyboard->mLayout;
        f = FALSE;
        switch (touchedRectIndex) {
            case 0:
                keyboard->mLayout = 1;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
            case 1:
                keyboard->mLayout = 2;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
            case 2:
                keyboard->mLayout = 3;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
            case 3:
                keyboard->mLayout = 4;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
            case 4:
                keyboard->mLayout = 5;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
        }
        if (f != FALSE) {
            if (previousLayout != gKeyboard->mLayout) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e5);
            } else {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ed);
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
                data_0217aa08->mFirstBlock->mHasPlayerName = 1;
                MI_CpuFill8(data_0217aa08->mFirstBlock->mPlayerName, 0, 0x14);
                MI_CpuCopy8(&keyboard->mRecords[1], data_0217aa08->mFirstBlock->mPlayerName, 0x14);
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
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x22);
    }
    gKeyboard->mStateFrames++;
    if (IsTxtSystemState2NoCloseRequest() != 0) {
        keyboard = gKeyboard;
        if (keyboard->mStateFrames > 0x5a) {
            backupBusy = (data_0217aa08->mBusy == 0)
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
        backupBusy =
            (data_0217aa08->mBusy == 0) ? (gBackupAccess->mBackupEnabled != 0 ? gBackupAccess->mCommandRunning : 0) : 1;
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
    s32 i;
    s32 j;
    s32 k;
    u16 charString[2];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < gKeyboardTextLimits[i]; k++) {
                charString[0] = 0;
                charString[1] = 0;
                charString[0] = gKeyboard->mRecords[i].mChars[k];
                PrintLabelLayoutTextNoFixedAdvance(j, gKeyboardTextCharLabelIndices[i][k], gKeyboard->mBnlls[i],
                                                   charString, gKeyboard->mBncls[i], gKeyboard->mTables[i][j]);
            }
        }
    }
}

void ShowKeyboardCursorButtonObjects(void) {
    s32 i;
    s32 kind;
    for (i = 0; i < 2; i++) {
        if (gKeyboard->mCursorOnButton[i] != 0) {
            kind = gKeyboard->mKind;
            gKeyboard->mTables[kind][1][gKeyboardButtonEntryIndices[kind][i][0]].mVisible = 1;
        } else {
            kind = gKeyboard->mKind;
            gKeyboard->mTables[kind][1][gKeyboardButtonEntryIndices[kind][i][0]].mVisible = 0;
        }
    }
}

void ShowKeyboardDisabledButtonObjects(void) {
    s32 i;
    s32 kind;
    for (i = 0; i < 2; i++) {
        if (gKeyboard->mButtonEnabled[i] != 0) {
            kind = gKeyboard->mKind;
            gKeyboard->mTables[kind][1][gKeyboardButtonEntryIndices[kind][i][1]].mVisible = 0;
        } else {
            kind = gKeyboard->mKind;
            gKeyboard->mTables[kind][1][gKeyboardButtonEntryIndices[kind][i][1]].mVisible = 1;
        }
    }
}

void ShowKeyboardTextIndexObject(void) {
    s32 i;
    for (i = 0; i < gKeyboardTextLimits[gKeyboard->mKind]; i++) {
        gKeyboard->mTables[gKeyboard->mKind][1][gKeyboardTextIndexEntryIndices[gKeyboard->mKind][i]].mVisible = 0;
    }
    gKeyboard->mTables[gKeyboard->mKind][1][gKeyboardTextIndexEntryIndices[gKeyboard->mKind][GetKeyboardTextIndex()]]
        .mVisible = 1;
}

void ShowKeyboardRemainingCharObjects(void) {
    u16 nameChars[10];
    s32 charCount;
    s32 k;
    s32 l;
    s32 i;
    s32 j;
    u8 *entryIndexPointer;
    if (gKeyboard->mKind == 1) {
        charCount = CopyTextWithinWidth(gKeyboard->mRecords[1].mChars, nameChars);
        k = 6;
        if (charCount > 4) {
            k = 10 - charCount;
        }
        i = 0;
        entryIndexPointer = data_0215d0f0;
        l = 6 - k;
        for (; i < 6; i++) {
            for (j = 0; j < 2; j++) {
                if (i >= l && gKeyboard->mRecords[2].mMode != 0xc) {
                    gKeyboard->mTables[1][j][*entryIndexPointer].mVisible = 1;
                } else {
                    gKeyboard->mTables[1][j][*entryIndexPointer].mVisible = 0;
                }
            }
            entryIndexPointer++;
        }
    }
}

void ShowKeyboardLayoutObject(void) {
    s32 i;
    BOOL hiddenValue;
    u8 *entryIndexPointer;
    u8 entryIndex;
    i = 0;
    entryIndexPointer = gKeyboardLayoutEntryIndices;
    hiddenValue = FALSE;
    for (; i < 6; i++) {
        entryIndex = *entryIndexPointer;
        if (entryIndex != 0xff) {
            gKeyboard->mTables[1][1][entryIndex].mVisible = hiddenValue;
        }
        entryIndexPointer++;
    }
    gKeyboard->mTables[1][1][gKeyboardLayoutEntryIndices[gKeyboard->mLayout]].mVisible = 1;
}

void AdvanceKeyboard(void) {
    s32 i;
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
    for (i = 0; i < 2; i++) {
        keyboard = gKeyboard;
        DrawLayoutTable(keyboard->mBncls[i], keyboard->mNcer, keyboard->mBnlls[i], GetKeyboardFirstBuffer(),
                        keyboard->mTables[i][0]);
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
