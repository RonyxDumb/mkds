#include "03/Menu/edit.h"
#include "03/code_021c6764.h"
#include "03/Menu/message_box_create.h"
#include "03/types_021d299c.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/Menu/sub_screen_message.h"
#include "03/System/application.h"
#include "03/Net/essid_wcm.h"
#include "03/code_021cd2e0.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/Menu/message_box.h"
#include "03/System/string_length.h"
#include "03/code_021bf000.h"
#include "03/code_021c2000.h"
#include "03/code_021c6000.h"
#include "03/code_021c9000.h"
#include "03/code_021cb000.h"
#include "03/code_021cbf60.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d7000.h"
#include "gx_load2d.h"
#include "03/code_021cd000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021c0000.h"
#include "03/System/dwc_archive.h"
#include "03/Graphics/hl_scr.h"
#include "03/code_021d1c18.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/exp_heap.h"
#include "03/code_021d2ecc.h"
#include "03/code_021c04ec.h"
#include "03/Menu/ap_list.h"
#include "03/Menu/jb3_list.h"

void CreateEdit(void) {
    u8 subScreenMessages[2];
    s32 secondaryPairFirst;
    s32 secondaryPairSecond;
    subScreenMessages[0] = gEditSubScreenMessages[0];
    subScreenMessages[1] = gEditSubScreenMessages[1];
    gEdit = AllocZeroedExpHeapBlock(0x2c, 4);
    GetSecondaryMenuPair(&secondaryPairFirst, &secondaryPairSecond);
    if (secondaryPairFirst == 0) {
        CopyApWorkSsid((u8 *) gEdit + 8);
        gEdit->mCharCount = GetStringLengthWithLimit((u8 *) gEdit + 8, 0x20);
    }
    LoadEditFilesAndSetBgCnt();
    LoadHlScr(secondaryPairFirst + 9);
    if (secondaryPairSecond == 1) {
        ShowSubScreenMessage(0x81, -1, 0);
    } else {
        ShowSubScreenMessage(subScreenMessages[secondaryPairFirst], -1, 0);
    }
    CreateObjectsForMenuPair(2);
    gEdit->mBgTextCanvas = InitBgTextCanvas(0, 0);
    gEdit->mOamEntry = CreateOamEntryFromNceImage(0, 0x3e);
    gEdit->mOamEntry->mAttr2 = (gEdit->mOamEntry->mAttr2 & 0xfffff3ff) | 0xc00;
    PlaceEditTextCursor();
    PrintEditText();
    SetUpdateFunction(StartEditFadeIn);
}

void LoadEditFilesAndSetBgCnt(void) {
    void *ybObjKbNclName = &gYbObjKbNclName;
    void *loadObjPlttFunc = &GX_LoadOBJPltt;
    u32 objPlttLoadResult = LoadFileToVram(ybObjKbNclName, loadObjPlttFunc);
    void *jbBgStep3NcgName = &gJbBgStep3NcgName2;
    void *loadBg2CharFunc = &GX_LoadBG2Char;
    u32 bg2CharLoadResult = LoadFileToVram(jbBgStep3NcgName, loadBg2CharFunc);
    void *ybBgStep3NclName = &gYbBgStep3NclName2;
    void *loadBgPlttFunc = &GX_LoadBGPltt;
    u32 bgPlttLoadResult = LoadFileToVram(ybBgStep3NclName, loadBgPlttFunc);
    void *xb4EditNscName = &gXb4EditNscName;
    void *loadBg2ScrFunc = &GX_LoadBG2Scr;
    u32 bg2ScrLoadResult = LoadFileToVram(xb4EditNscName, loadBg2ScrFunc);
    u32 g2sDbBg0CntAddr = 0x4001008u;
    u32 g2sDbBg0CntOld = (*(u16 *) ((g2sDbBg0CntAddr) + (0)));
    u32 g2sDbBg0CntCleared = ((g2sDbBg0CntOld) & ~(0x3u));
    u32 g2sDbBg0CntNew = ((g2sDbBg0CntCleared) | (0x3u));
    u32 g2sDbBg1CntAddr;
    u32 g2sDbBg1CntOld;
    u32 g2sDbBg1CntCleared;
    u32 g2sDbBg1CntNew;
    u32 g2Bg0CntAddr;
    u32 g2Bg0CntOld;
    u32 g2Bg0CntCleared;
    u32 g2Bg0CntNew;
    u32 g2Bg1CntAddr;
    u32 g2Bg1CntOld;
    u32 g2Bg1CntCleared;
    u32 g2Bg1CntNew;
    u32 g2Bg2CntAddr;
    u32 g2Bg2CntOld;
    u32 g2Bg2CntCleared;
    u32 g2Bg2CntNew;
    *(u16 *) ((g2sDbBg0CntAddr) + (0)) = g2sDbBg0CntNew;
    g2sDbBg1CntAddr = 0x400100au;
    g2sDbBg1CntOld = (*(u16 *) ((g2sDbBg1CntAddr) + (0)));
    g2sDbBg1CntCleared = ((g2sDbBg1CntOld) & ~(0x3u));
    g2sDbBg1CntNew = ((g2sDbBg1CntCleared) | (0x3u));
    *(u16 *) ((g2sDbBg1CntAddr) + (0)) = g2sDbBg1CntNew;
    g2Bg0CntAddr = 0x4000008u;
    g2Bg0CntOld = (*(u16 *) ((g2Bg0CntAddr) + (0)));
    g2Bg0CntCleared = ((g2Bg0CntOld) & ~(0x3u));
    g2Bg0CntNew = ((g2Bg0CntCleared) | (0x2u));
    *(u16 *) ((g2Bg0CntAddr) + (0)) = g2Bg0CntNew;
    g2Bg1CntAddr = 0x400000au;
    g2Bg1CntOld = (*(u16 *) ((g2Bg1CntAddr) + (0)));
    g2Bg1CntCleared = ((g2Bg1CntOld) & ~(0x3u));
    g2Bg1CntNew = ((g2Bg1CntCleared) | (0x3u));
    *(u16 *) ((g2Bg1CntAddr) + (0)) = g2Bg1CntNew;
    g2Bg2CntAddr = 0x400000cu;
    g2Bg2CntOld = (*(u16 *) ((g2Bg2CntAddr) + (0)));
    g2Bg2CntCleared = ((g2Bg2CntOld) & ~(0x3u));
    g2Bg2CntNew = ((g2Bg2CntCleared) | (0x3u));
    *(u16 *) ((g2Bg2CntAddr) + (0)) = g2Bg2CntNew;
}

void StartEditFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateEditFadeIn);
}

void UpdateEditFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateEditKeyboard();
        StartSoundSeq(0x14);
        if (gEdit->mCharCount == 0) {
            SetEditKeyboardRemoveCharEnabled(0);
        }
        if (gEdit->mCharCount == ' ') {
            SetEditKeyboardAddCharEnabled(0);
        }
        SetUpdateFunction(UpdateEditKeyboardIn);
    }
}

void UpdateEditKeyboardIn(void) {
    if (GetEditKeyboardInput() != 255) {
        SetUpdateFunction(UpdateEdit);
    }
}

void UpdateEdit(void) {
    UpdateEditInput();
    UpdateEditNop();
}

void UpdateEditInput(void) {
    int keyboardInput;
    Edit *edit;
    keyboardInput = GetEditKeyboardInput();
    switch (keyboardInput) {
        case 0x80:
            edit = gEdit;
            if (edit->mCharCount != 0) {
                StartSoundSeq(3);
                edit = gEdit;
                edit->mCharCount = edit->mCharCount - 1;
                edit = gEdit;
                edit->mText[edit->mCharCount] = 0;
                if (gEdit->mCharCount == 0) {
                    SetEditKeyboardRemoveCharEnabled(0);
                }
                SetEditKeyboardAddCharEnabled(1);
            }
            break;
        case 0x82:
            StartSoundSeq(7);
            gEdit->mResult = 0;
            SetUpdateFunction(StartEditClose);
            return;
        case 0x83:
            if (IsEditTextValid() != FALSE) {
                StartSoundSeq(6);
                gEdit->mResult = 1;
            } else {
                gEdit->mResult = 2;
                StartSoundSeq(9);
            }
            gEdit->mOamEntry->mAttr01 = (gEdit->mOamEntry->mAttr01 & 0xc1fffcff) | 0x200;
            SetUpdateFunction(StartEditClose);
            return;
        case 0:
            break;
        case 0xe01d:
        default:
            edit = gEdit;
            if (edit->mCharCount != 0x20) {
                StartSoundSeq(1);
                edit = gEdit;
                edit->mText[edit->mCharCount] = keyboardInput;
                edit = gEdit;
                edit->mCharCount = edit->mCharCount + 1;
                SetEditKeyboardRemoveCharEnabled(1);
                if (gEdit->mCharCount == 0x20) {
                    SetEditKeyboardAddCharEnabled(0);
                }
            }
            break;
    }
    PrintEditText();
    PlaceEditTextCursor();
}

void UpdateEditNop(void) {}

void StartEditClose(void) {
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateEditFadeOut);
}

void UpdateEditFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartEditKeyboardSlideOut();
        StartSoundSeq(0x15);
        SetUpdateFunction(UpdateEditKeyboardOut);
    }
}

void UpdateEditKeyboardOut(void) {
    s32 messageIds[2] = {0x9b, 0x9c};
    s32 secondaryPairSecond;
    if (HasEditKeyboard() == 0) {
        if (gEdit->mResult == 0) {
            SetUpdateFunction(UpdateEditRelease);
        } else if (gEdit->mResult == 2) {
            CreateMessageBox(0x2f, 3, 1, -1, 0);
            SetUpdateFunction(UpdateEditInvalidMessageResult);
        } else {
            GetSecondaryMenuPair(NULL, &secondaryPairSecond);
            CreateMessageBox(messageIds[secondaryPairSecond], 2, 1, -1, 0);
            SetUpdateFunction(UpdateEditMessageResult);
        }
    }
}

void UpdateEditRelease(void) {
    s32 secondaryPairFirst;
    int secondaryPairSecond[1];
    HideSubScreenMessage();
    DeleteOamEntry((u32 *) (u32) gEdit->mOamEntry);
    ReleaseBgTextCanvasOfScreen(0);
    LoadFileToVram(&gYbObjMainNclName2, &GX_LoadOBJPltt);
    ClearDispcntBits(1, 1);
    ClearDispcntBits(0, 0x15);
    GetSecondaryMenuPair(&secondaryPairFirst, secondaryPairSecond);
    if (secondaryPairSecond[0] == 0) {
        SetPrimaryMenuPair(2, 1);
        SetSecondaryMenuPair(0, secondaryPairFirst);
        SetUpdateFunction(CreateJb3List);
    } else if (gEdit->mResult == 0) {
        SetPrimaryMenuPair(0, 1);
        SetSecondaryMenuPair(1, 0);
        SetUpdateFunction(CreateApList);
    } else {
        SetPrimaryMenuPair(0, 0);
        SetSecondaryMenuPair(0, 1);
        SetUpdateFunction(SetupConnectMessage);
    }
    FreeExpHeapBlockAndClearPointer(&gEdit);
}

void PrintEditText(void) {
    Rect charRect = {0, 0, 0, 0};
    u16 charText[2];
    int column;
    int charIndex;
    u8 secondLineY;
    charRect.mY = gEditLineY[0];
    charRect.mUnk_04 = gEditCharSize[0];
    charRect.mUnk_06 = gEditCharSize[1];
    ClearBgTextCanvas(gEdit->mBgTextCanvas, 0);
    charText[1] = 0;
    charIndex = 0;
    column = charIndex;
    secondLineY = gEditLineY[1];
    for (; charIndex < 0x20; charIndex++, column++) {
        Edit *edit;
        if (charIndex == 0x10) {
            charRect.mY = secondLineY;
            column = 0;
        }
        edit = gEdit;
        if (edit->mText[charIndex] == 0x20) {
            charText[0] = 0xe01d;
        } else {
            charText[0] = edit->mText[charIndex];
        }
        charRect.mX = gEditColumnX[column];
        DrawCanvasTextRect(edit->mBgTextCanvas, charRect.mX, charRect.mY, charRect.mUnk_04, charRect.mUnk_06, 2, 0x480,
                           charText);
    }
    RequestBgTextCanvasUpload(gEdit->mBgTextCanvas);
}

void PlaceEditTextCursor(void) {
    int column;
    int line;
    u8 charCount;
    Edit *edit;
    edit = gEdit;
    charCount = edit->mCharCount;
    column = charCount & 0xf;
    line = charCount >> 4;
    if (charCount >= 0x20u) {
        column = 0xf;
        line = 1;
    }
    edit->mOamEntry->mAttr01 =
        ((gEditColumnX[column] & 0x1ff) << 16) | ((edit->mOamEntry->mAttr01 & 0xfe00ff00) | (gEditLineY[line] & 0xff));
}

void UpdateEditMessageResult(void) {
    gEdit->mResult = GetMessageBoxResult();
    switch (gEdit->mResult) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            StartSoundSeq(0xe);
            break;
        default:
            return;
    }
    CloseMessageBox();
    SetUpdateFunction(UpdateEditMessageClose);
}

void UpdateEditMessageClose(void) {
    void (*storeFuncs[2])(const u8 *) = {StoreApWorkSsid, StoreApWorkWepKey};
    s32 secondaryPairFirst;
    if (IsMessageBoxOpen() == 0) {
        if (gEdit->mResult == 0) {
            gEdit->mOamEntry->mAttr01 = gEdit->mOamEntry->mAttr01 & 0xc1fffcff;
            SetUpdateFunction(UpdateEditFadeIn);
            return;
        }
        GetSecondaryMenuPair(&secondaryPairFirst, NULL);
        storeFuncs[secondaryPairFirst](gEdit->mText);
        SetUpdateFunction(UpdateEditRelease);
    }
}

BOOL IsEditTextValid(void) {
    s32 secondaryPairFirst;
    s32 secondaryPairSecond;
    int textLength;
    int i;
    GetSecondaryMenuPair(&secondaryPairFirst, &secondaryPairSecond);
    if (secondaryPairSecond == 1) {
        ShowSubScreenMessage(0x81, -1, 0);
    }
    GetSecondaryMenuPair(&secondaryPairFirst, &secondaryPairSecond);
    if (secondaryPairFirst == 0) {
        if (gEdit->mText[0] != 0) {
            return TRUE;
        }
        return FALSE;
    }
    if (secondaryPairSecond == 1 && gEdit->mText[0] == 0) {
        return FALSE;
    }
    textLength = GetStringLengthWithLimit(gEdit->mText, 0x20);
    switch (textLength) {
        case 0:
        case 5:
        case 0xd:
        case 0x10:
            return TRUE;
        case 0xa:
        case 0x1a:
        case 0x20:
            for (i = 0; i < textLength; i++) {
                u8 charValue = gEdit->mText[i];
                if (!((charValue >= '0' && charValue <= '9') || (charValue >= 'A' && charValue <= 'F') ||
                      (charValue >= 'a' && charValue <= 'f'))) {
                    return FALSE;
                }
            }
            return TRUE;
        default:
            return FALSE;
    }
}

void UpdateEditInvalidMessageResult(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        SetUpdateFunction(UpdateEditInvalidMessageClose);
    }
}

void UpdateEditInvalidMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        gEdit->mOamEntry->mAttr01 = gEdit->mOamEntry->mAttr01 & (0xc1fffcffu);
        SetUpdateFunction(UpdateEditFadeIn);
    }
}
