#include "03/Menu/edit.h"
#include "03/Net/exchange_essid.h"
#include "03/Menu/edit_text.h"
#include "03/Menu/message_box_create.h"
#include "03/types_021d299c.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/sub_screen_message.h"
#include "03/System/application.h"
#include "03/Net/essid_packet_steps.h"
#include "03/Net/ap_entries.h"
#include "sound_archive_load_result.h"
#include "03/Sound/sound_seq.h"
#include "03/Menu/message_box.h"
#include "03/System/string_length.h"
#include "03/Menu/connect_message_setup.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/System/dwc_archive.h"
#include "03/Graphics/hl_scr.h"
#include "03/Graphics/nce_file.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/oam_buffer_entries.h"
#include "03/Menu/edit_keyboard_create.h"
#include "03/Menu/ap_list.h"
#include "03/Menu/jb3_list.h"

const u8 gEditLineY[2] = {0x20, 0x31};
const u16 gEditCharSize[2] = {0xe, 0x10};
const u8 gEditColumnX[16] = {8,    0x17, 0x26, 0x35, 0x44, 0x53, 0x62, 0x71,
                             0x80, 0x8f, 0x9e, 0xad, 0xbc, 0xcb, 0xda, 0xe9};
u8 gEditSubScreenMessages[2] = {0x90, 0x8f};
struct Edit *gEdit;

void CreateEdit(void) {
    u8 subScreenMessages[2];
    s32 secondaryPairFirst;
    s32 secondaryPairSecond;
    subScreenMessages[0] = gEditSubScreenMessages[0];
    subScreenMessages[1] = gEditSubScreenMessages[1];
    gEdit = AllocZeroedExpHeapBlock(0x2c, 4);
    GetSecondaryMenuPair(&secondaryPairFirst, &secondaryPairSecond);
    if (secondaryPairFirst == 0) {
        CopyApWorkSsid(gEdit->mText);
        gEdit->mCharCount = GetStringLengthWithLimit(gEdit->mText, 0x20);
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
    gEdit->mOamEntry->mAttr2 = (gEdit->mOamEntry->mAttr2 & OAM_ATTR2_NOT_PRIORITY_MASK) | 0xc00;
    PlaceEditTextCursor();
    PrintEditText();
    SetUpdateFunction(StartEditFadeIn);
}

void LoadEditFilesAndSetBgCnt(void) {
    void *ybObjKbNclName = &"char/ybObjKb.ncl.l";
    void *loadObjPlttFunc = &GX_LoadOBJPltt;
    u32 objPlttLoadResult = LoadFileToVram(ybObjKbNclName, loadObjPlttFunc);
    void *jbBgStep3NcgName = &"char/jbBgStep3.ncg.l";
    void *loadBg2CharFunc = &GX_LoadBG2Char;
    u32 bg2CharLoadResult = LoadFileToVram(jbBgStep3NcgName, loadBg2CharFunc);
    void *ybBgStep3NclName = &"char/ybBgStep3.ncl.l";
    void *loadBgPlttFunc = &GX_LoadBGPltt;
    u32 bgPlttLoadResult = LoadFileToVram(ybBgStep3NclName, loadBgPlttFunc);
    void *xb4EditNscName = &"char/xb4Edit.nsc.l";
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
        case EDIT_KEYBOARD_INPUT_REMOVE_CHAR:
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
        case EDIT_KEYBOARD_INPUT_CANCEL:
            StartSoundSeq(7);
            gEdit->mResult = EDIT_RESULT_CANCELED;
            SetUpdateFunction(StartEditClose);
            return;
        case EDIT_KEYBOARD_INPUT_OK:
            if (IsEditTextValid() != FALSE) {
                StartSoundSeq(6);
                gEdit->mResult = EDIT_RESULT_CONFIRMED;
            } else {
                gEdit->mResult = EDIT_RESULT_INVALID;
                StartSoundSeq(9);
            }
            gEdit->mOamEntry->mAttr01 =
                (gEdit->mOamEntry->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK) | OAM_ATTR01_EFFECT_HIDDEN;
            SetUpdateFunction(StartEditClose);
            return;
        case 0:
            break;
        case EDIT_TEXT_GLYPH_SPACE:
        default:
            edit = gEdit;
            if (edit->mCharCount != EDIT_TEXT_MAX_CHARS) {
                StartSoundSeq(1);
                edit = gEdit;
                edit->mText[edit->mCharCount] = keyboardInput;
                edit = gEdit;
                edit->mCharCount = edit->mCharCount + 1;
                SetEditKeyboardRemoveCharEnabled(1);
                if (gEdit->mCharCount == EDIT_TEXT_MAX_CHARS) {
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
        if (gEdit->mResult == EDIT_RESULT_CANCELED) {
            SetUpdateFunction(UpdateEditRelease);
        } else if (gEdit->mResult == EDIT_RESULT_INVALID) {
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
    DeleteOamEntry(gEdit->mOamEntry);
    ReleaseBgTextCanvasOfScreen(0);
    LoadFileToVram(&"char/ybObjMain.ncl.l", &GX_LoadOBJPltt);
    ClearDispcntBits(1, 1);
    ClearDispcntBits(0, 0x15);
    GetSecondaryMenuPair(&secondaryPairFirst, secondaryPairSecond);
    if (secondaryPairSecond[0] == 0) {
        SetPrimaryMenuPair(2, 1);
        SetSecondaryMenuPair(0, secondaryPairFirst);
        SetUpdateFunction(CreateJb3List);
    } else if (gEdit->mResult == EDIT_RESULT_CANCELED) {
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
    OriginSizeRect charRect = {0, 0, 0, 0};
    u16 charText[2];
    int column;
    int charIndex;
    u8 secondLineY;
    charRect.mY = gEditLineY[0];
    charRect.mWidth = gEditCharSize[0];
    charRect.mHeight = gEditCharSize[1];
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
            charText[0] = EDIT_TEXT_GLYPH_SPACE;
        } else {
            charText[0] = edit->mText[charIndex];
        }
        charRect.mX = gEditColumnX[column];
        DrawCanvasTextRect(edit->mBgTextCanvas, charRect.mX, charRect.mY, charRect.mWidth, charRect.mHeight, 2, 0x480,
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
    edit->mOamEntry->mAttr01 = ((gEditColumnX[column] & 0x1ff) << 16) |
                               ((edit->mOamEntry->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | (gEditLineY[line] & 0xff));
}

void UpdateEditMessageResult(void) {
    gEdit->mResult = GetMessageBoxResult();
    switch (gEdit->mResult) {
        case EDIT_RESULT_CANCELED:
            StartSoundSeq(7);
            break;
        case EDIT_RESULT_CONFIRMED:
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
        if (gEdit->mResult == EDIT_RESULT_CANCELED) {
            gEdit->mOamEntry->mAttr01 = gEdit->mOamEntry->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK;
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
    int charIndex;
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
        case sizeof(WepKey5):
        case sizeof(WepKey13):
        case sizeof(WepKey16):
            return TRUE;
        case sizeof(WepKey5) * 2:
        case sizeof(WepKey13) * 2:
        case sizeof(WepKey16) * 2:
            for (charIndex = 0; charIndex < textLength; charIndex++) {
                u8 charValue = gEdit->mText[charIndex];
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
