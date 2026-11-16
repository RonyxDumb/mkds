#include "03/Menu/edit_addr.h"

#include "03/System/application.h"
#include "03/Menu/edit_text.h"
#include "03/Sound/sound_seq.h"
#include "03/Menu/message_box.h"
#include "03/Menu/message_box_create.h"
#include "03/Net/ap_entries.h"
#include "03/Menu/wifi_menu_shared.h"
#include "wifi_settings_nvram_backup.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Menu/jb3_list.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Menu/wifi_menu_strings.h"
#include "vram_load_2d_graphics.h"
#include "03/Menu/edit_addr_keyboard.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Graphics/text_canvas.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/oam_buffer_entries.h"
#include "text_to_number.h"
#include "cpu_copy_fill.h"
#include "03/System/wifi_utility_archive.h"
#include "03/Graphics/hl_scr.h"
#include "03/Graphics/nce_file.h"
#include "string.h"
#include "print_memory_multibyte_write.h"

const u16 gEditAddrCharSize[2] = {0xb, 0x10};
const u8 gEditAddrCharX[12] = {0x31, 0x3d, 0x49, 0x5a, 0x66, 0x72, 0x83, 0x8f, 0x9b, 0xac, 0xb8, 0xc4};
u8 gEditAddrGroupMax[3] = {0x32, 0x35, 0x35};
u8 gEditAddrSubScreenMessageIndices[5] = {0x91, 0x92, 0x93, 0x94, 0x95};
u16 gEditAddrCharRect[3] = {0, 0x29, 0};
EditAddrTextFuncs gEditAddrFormatFuncs = {
    {(void (*)(u8 *)) FormatApWorkIpText, (void (*)(u8 *)) FormatApWorkNetmaskText,
     (void (*)(u8 *)) FormatApWorkGatewayText, (void (*)(u8 *)) FormatApWorkDnsFirstText,
     (void (*)(u8 *)) FormatApWorkDnsSecondText}};
EditAddrTextFuncs gEditAddrStoreFuncs = {{(void (*)(u8 *)) StoreApWorkIpText, (void (*)(u8 *)) StoreApWorkNetmaskText,
                                          (void (*)(u8 *)) StoreApWorkGatewayText,
                                          (void (*)(u8 *)) StoreApWorkDnsFirstText,
                                          (void (*)(u8 *)) StoreApWorkDnsSecondText}};
struct EditAddr *gEditAddr;

void CreateEditAddr(void) {
    EditAddrTextFuncs textFuncs;
    u8 subScreenMessageIndices[5];
    s32 secondaryPairFirst;
    EditAddr *editAddr;
    textFuncs = gEditAddrFormatFuncs;
    subScreenMessageIndices[0] = gEditAddrSubScreenMessageIndices[0];
    subScreenMessageIndices[1] = gEditAddrSubScreenMessageIndices[1];
    subScreenMessageIndices[2] = gEditAddrSubScreenMessageIndices[2];
    subScreenMessageIndices[3] = gEditAddrSubScreenMessageIndices[3];
    subScreenMessageIndices[4] = gEditAddrSubScreenMessageIndices[4];
    gEditAddr = AllocZeroedExpHeapBlock(0x18, 4);
    GetSecondaryMenuPair(&secondaryPairFirst, NULL);
    textFuncs.mUnk_00[secondaryPairFirst](gEditAddr->mText);
    editAddr = gEditAddr;
    if (memcmp(editAddr->mText, "  0", 3) != 0) {
        editAddr->mGroupIndex = EDIT_ADDR_LAST_GROUP;
    } else {
        MI_CpuFill8(editAddr->mText, 0, 0xc);
        gEditAddr->mGroupIndex = 0;
    }
    LoadEditAddrFilesAndSetBgCnt();
    LoadHlScr(secondaryPairFirst + 0xb);
    ShowSubScreenMessage(subScreenMessageIndices[secondaryPairFirst], -1, 0);
    CreateObjectsForMenuPair(2);
    gEditAddr->mBgTextCanvas = InitBgTextCanvas(0, 0);
    gEditAddr->mOamEntry = CreateOamEntryFromNceImage(0, 0x3f);
    gEditAddr->mOamEntry->mAttr2 = (gEditAddr->mOamEntry->mAttr2 & OAM_ATTR2_NOT_PRIORITY_MASK) | 0xc00;
    PlaceEditAddrGroupOam();
    PrintEditAddrText();
    SetUpdateFunction(StartEditAddrFadeIn);
}

void LoadEditAddrFilesAndSetBgCnt(void) {
    void *ybObjKbNclName = &"char/ybObjKb.ncl.l";
    void *objPlttLoader = &GX_LoadOBJPltt;
    u32 objPlttLoadResult = LoadFileToVram(ybObjKbNclName, objPlttLoader);
    void *jbBgStep3NcgName = &"char/jbBgStep3.ncg.l";
    void *bg2CharLoader = &GX_LoadBG2Char;
    u32 bg2CharLoadResult = LoadFileToVram(jbBgStep3NcgName, bg2CharLoader);
    void *ybBgStep3NclName = &"char/ybBgStep3.ncl.l";
    void *bgPlttLoader = &GX_LoadBGPltt;
    u32 bgPlttLoadResult = LoadFileToVram(ybBgStep3NclName, bgPlttLoader);
    void *xb4EditAddrNscName = &"char/xb4EditAddr.nsc.l";
    void *bg2ScrLoader = &GX_LoadBG2Scr;
    u32 bg2ScrLoadResult = LoadFileToVram(xb4EditAddrNscName, bg2ScrLoader);
    u32 subBg0CntAddress = 0x4001008u;
    u32 subBg0CntValue = (*(u16 *) ((subBg0CntAddress) + (0)));
    u32 subBg0CntCleared = ((subBg0CntValue) & ~(0x3u));
    u32 subBg0CntNew = ((subBg0CntCleared) | (0x3u));
    u32 subBg1CntAddress;
    u32 subBg1CntValue;
    u32 subBg1CntCleared;
    u32 subBg1CntNew;
    u32 mainBg0CntAddress;
    u32 mainBg0CntValue;
    u32 mainBg0CntCleared;
    u32 mainBg0CntNew;
    u32 mainBg1CntAddress;
    u32 mainBg1CntValue;
    u32 mainBg1CntCleared;
    u32 mainBg1CntNew;
    u32 mainBg2CntAddress;
    u32 mainBg2CntValue;
    u32 mainBg2CntCleared;
    u32 mainBg2CntNew;
    *(u16 *) ((subBg0CntAddress) + (0)) = subBg0CntNew;
    subBg1CntAddress = 0x400100au;
    subBg1CntValue = (*(u16 *) ((subBg1CntAddress) + (0)));
    subBg1CntCleared = ((subBg1CntValue) & ~(0x3u));
    subBg1CntNew = ((subBg1CntCleared) | (0x3u));
    *(u16 *) ((subBg1CntAddress) + (0)) = subBg1CntNew;
    mainBg0CntAddress = 0x4000008u;
    mainBg0CntValue = (*(u16 *) ((mainBg0CntAddress) + (0)));
    mainBg0CntCleared = ((mainBg0CntValue) & ~(0x3u));
    mainBg0CntNew = ((mainBg0CntCleared) | (0x2u));
    *(u16 *) ((mainBg0CntAddress) + (0)) = mainBg0CntNew;
    mainBg1CntAddress = 0x400000au;
    mainBg1CntValue = (*(u16 *) ((mainBg1CntAddress) + (0)));
    mainBg1CntCleared = ((mainBg1CntValue) & ~(0x3u));
    mainBg1CntNew = ((mainBg1CntCleared) | (0x3u));
    *(u16 *) ((mainBg1CntAddress) + (0)) = mainBg1CntNew;
    mainBg2CntAddress = 0x400000cu;
    mainBg2CntValue = (*(u16 *) ((mainBg2CntAddress) + (0)));
    mainBg2CntCleared = ((mainBg2CntValue) & ~(0x3u));
    mainBg2CntNew = ((mainBg2CntCleared) | (0x3u));
    *(u16 *) ((mainBg2CntAddress) + (0)) = mainBg2CntNew;
}

void StartEditAddrFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(UpdateEditAddrFadeIn);
}

void UpdateEditAddrFadeIn(void) {
    int checkResult;
    checkResult = IsBlendBrightnessFadeSlotBusy(1);
    if ((checkResult == 0) && (checkResult = IsBlendBrightnessFadeSlotBusy(0), checkResult == 0)) {
        CreateEditAddrKeyboard();
        StartSoundSeq(0x14);
        if (gEditAddr->mGroupIndex == 0) {
            SetEditAddrKeyboardRemoveCharEnabled(0);
            SetEditAddrKeyboardNextGroupEnabled(0);
        } else {
            checkResult = IsEditAddrGroupFull(0x1a);
            if (checkResult != 0) {
                SetEditAddrKeyboardAddCharEnabled(0);
            }
            SetEditAddrKeyboardNextGroupEnabled(0);
        }
        SetUpdateFunction(UpdateEditAddrKeyboardIn);
    }
}

void UpdateEditAddrKeyboardIn(void) {
    if (GetEditAddrKeyboardInput() != 31) {
        SetUpdateFunction(UpdateEditAddr);
    }
}

void UpdateEditAddr(void) {
    UpdateEditAddrInput();
    UpdateEditAddrNop();
}

void UpdateEditAddrInput(void) {
    s32 keyboardInput;
    u8 *text;
    s32 groupOffset;
    EditAddr *editAddr;
    EditAddr **editAddrPointer;
    u8 groupIndex;
    keyboardInput = GetEditAddrKeyboardInput();
    switch (keyboardInput) {
        case EDIT_ADDR_KEYBOARD_INPUT_NONE:
            return;
        case EDIT_ADDR_KEYBOARD_INPUT_REMOVE_CHAR:
            if (gEditAddr->mGroupIndex == 0 && gEditAddr->mText[2] == 0) {
                break;
            }
            StartSoundSeq(3);
            if (gEditAddr->mText[gEditAddr->mGroupIndex * 3 + 2] == 0) {
                gEditAddr->mGroupIndex--;
            }
            MI_CpuFill8(gEditAddr->mText + gEditAddr->mGroupIndex * 3, 0, 3);
            if (gEditAddr->mGroupIndex == 0 && gEditAddr->mText[2] == 0) {
                SetEditAddrKeyboardRemoveCharEnabled(0);
            }
            SetEditAddrKeyboardAddCharEnabled(1);
            SetEditAddrKeyboardNextGroupEnabled(0);
            break;
        case EDIT_ADDR_KEYBOARD_INPUT_NEXT_GROUP:
            groupIndex = gEditAddr->mGroupIndex;
            if (groupIndex >= 3) {
                break;
            }
            if (gEditAddr->mText[groupIndex * 3 + 2] == 0) {
                break;
            }
            StartSoundSeq(1);
            gEditAddr->mGroupIndex = gEditAddr->mGroupIndex + 1;
            SetEditAddrKeyboardNextGroupEnabled(0);
            break;
        case EDIT_ADDR_KEYBOARD_INPUT_CANCEL:
            gEditAddr->mResult = EDIT_RESULT_CANCELED;
            StartSoundSeq(7);
            SetUpdateFunction(StartEditAddrClose);
            return;
        case EDIT_ADDR_KEYBOARD_INPUT_OK:
            if (IsEditAddrTextValid() != FALSE) {
                StartSoundSeq(6);
                gEditAddr->mResult = EDIT_RESULT_CONFIRMED;
            } else {
                gEditAddr->mResult = EDIT_RESULT_INVALID;
                StartSoundSeq(9);
            }
            gEditAddr->mGroupIndex = EDIT_ADDR_LAST_GROUP;
            gEditAddr->mOamEntry->mAttr01 =
                (gEditAddr->mOamEntry->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK) | OAM_ATTR01_EFFECT_HIDDEN;
            PlaceEditAddrGroupOam();
            WriteEditAddrGroupPadding();
            SetUpdateFunction(StartEditAddrClose);
            return;
        default:
            if (gEditAddr->mGroupIndex == EDIT_ADDR_LAST_GROUP) {
                if (IsEditAddrGroupFull(0x1a) != 0) {
                    break;
                }
            }
            StartSoundSeq(1);
            editAddrPointer = &gEditAddr;
            text = (*editAddrPointer)->mText;
            groupOffset = (*editAddrPointer)->mGroupIndex * 3;
            if (text[groupOffset + 2] == 0) {
                text[groupOffset + 2] = keyboardInput;
            } else if (text[groupOffset + 1] == 0) {
                text[groupOffset + 1] = text[groupOffset + 2];
                text[groupOffset + 2] = keyboardInput;
                if (IsEditAddrGroupFull(0x1a) != 0) {
                    editAddr = gEditAddr;
                    if (editAddr->mGroupIndex < EDIT_ADDR_LAST_GROUP) {
                        editAddr->mGroupIndex = editAddr->mGroupIndex + 1;
                    }
                }
            } else {
                text[groupOffset] = text[groupOffset + 1];
                text[groupOffset + 1] = text[groupOffset + 2];
                text[groupOffset + 2] = keyboardInput;
                if ((*editAddrPointer)->mGroupIndex < EDIT_ADDR_LAST_GROUP) {
                    (*editAddrPointer)->mGroupIndex = (*editAddrPointer)->mGroupIndex + 1;
                }
            }
            SetEditAddrKeyboardRemoveCharEnabled(1);
            if (gEditAddr->mGroupIndex < EDIT_ADDR_LAST_GROUP) {
                SetEditAddrKeyboardNextGroupEnabled(1);
            } else {
                SetEditAddrKeyboardNextGroupEnabled(0);
            }
            if (gEditAddr->mGroupIndex == EDIT_ADDR_LAST_GROUP) {
                if (IsEditAddrGroupFull(0x1a) != 0) {
                    SetEditAddrKeyboardAddCharEnabled(0);
                }
            }
            break;
    }
    PrintEditAddrText();
    PlaceEditAddrGroupOam();
}

BOOL IsEditAddrGroupFull(s32 groupLimit) {
    u8 groupText[4];
    u8 *group;
    u8 *text;
    s32 charIndex;
    u8 firstChar;
    text = gEditAddr->mText;
    group = text + gEditAddr->mGroupIndex * 3;
    firstChar = *group;
    if (firstChar != 0 && firstChar != 0x20) {
        return 1;
    }
    MI_CpuCopy8(group, groupText, 3);
    groupText[3] = 0;
    group = groupText;
    for (charIndex = 0; charIndex < 3; charIndex++) {
        if (*group != 0) {
            break;
        }
        *group = 0x20;
        group++;
    }
    if (StrtolBase10((const char *) groupText) >= groupLimit) {
        return 1;
    }
    return 0;
}

void UpdateEditAddrNop(void) {}

void StartEditAddrClose(void) {
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateEditAddrSlideOut);
}

void UpdateEditAddrSlideOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartEditAddrKeyboardSlideOut();
        StartSoundSeq(0x15);
        SetUpdateFunction(UpdateEditAddrResult);
    }
}

void UpdateEditAddrResult(void) {
    u8 result;
    if (HasEditAddrKeyboard() == 0) {
        result = gEditAddr->mResult;
        if (result == EDIT_RESULT_CANCELED) {
            SetUpdateFunction(ReleaseEditAddr);
            return;
        }
        if (result == EDIT_RESULT_INVALID) {
            CreateMessageBox(0x2f, 3, 1, -1, 0);
            SetUpdateFunction(UpdateEditAddrInvalidMessageResult);
            return;
        }
        CreateMessageBox(0x9b, 2, 1, -1, 0);
        SetUpdateFunction(UpdateEditAddrMessageResult);
    }
}

void ReleaseEditAddr(void) {
    int secondaryPair[1];
    HideSubScreenMessage();
    DeleteOamEntry(gEditAddr->mOamEntry);
    ReleaseBgTextCanvasOfScreen(0);
    LoadFileToVram(&"char/ybObjMain.ncl.l", &GX_LoadOBJPltt);
    ClearDispcntBits(1, 1);
    ClearDispcntBits(0, 0x15);
    GetSecondaryMenuPair(secondaryPair, NULL);
    if (3 <= secondaryPair[0]) {
        secondaryPair[0] = secondaryPair[0] + 1;
    }
    SetPrimaryMenuPair(2, 1);
    SetSecondaryMenuPair(0, secondaryPair[0] + 3);
    SetUpdateFunction(CreateJb3List);
    FreeExpHeapBlockAndClearPointer(&gEditAddr);
}

void PrintEditAddrText(void) {
    u16 rectAndChar[6];
    s32 charIndex;
    const u8 *charX;
    EditAddr *editAddr;
    u16 charXPosition;
    rectAndChar[0] = gEditAddrCharRect[0];
    rectAndChar[1] = gEditAddrCharRect[1];
    rectAndChar[2] = gEditAddrCharRect[2];
    rectAndChar[3] = gEditAddrCharRect[3];
    rectAndChar[2] = gEditAddrCharSize[0];
    rectAndChar[3] = gEditAddrCharSize[1];
    ClearBgTextCanvas(gEditAddr->mBgTextCanvas, 0);
    charIndex = 0;
    rectAndChar[5] = 0;
    charX = gEditAddrCharX;
    do {
        editAddr = gEditAddr;
        rectAndChar[4] = editAddr->mText[charIndex];
        charXPosition = *charX;
        rectAndChar[0] = charXPosition;
        DrawCanvasTextRect(editAddr->mBgTextCanvas, charXPosition, rectAndChar[1], rectAndChar[2], rectAndChar[3], 2,
                           0x480, &rectAndChar[4]);
        charX++;
        charIndex++;
    } while (charIndex < 12);
    RequestBgTextCanvasUpload(gEditAddr->mBgTextCanvas);
}

void PlaceEditAddrGroupOam(void) {
    EditAddr *editAddr;
    OamEntry *oamEntry;
    u32 xBits;
    s32 groupIndex;
    editAddr = gEditAddr;
    groupIndex = editAddr->mGroupIndex;
    if (groupIndex > 3) {
        groupIndex = 3;
    }
    oamEntry = editAddr->mOamEntry;
    xBits = (gEditAddrCharX[groupIndex * 3 + 2] & 0x1ff) << 16;
    oamEntry->mAttr01 = xBits | ((oamEntry->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | 0x28);
}

void UpdateEditAddrMessageResult(void) {
    gEditAddr->mResult = GetMessageBoxResult();
    switch (gEditAddr->mResult) {
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
    SetUpdateFunction(UpdateEditAddrMessageClose);
}

void UpdateEditAddrMessageClose(void) {
    EditAddrTextFuncs storeFuncs;
    s32 secondaryPairFirst;
    storeFuncs = gEditAddrStoreFuncs;
    if (IsMessageBoxOpen() == 0) {
        if (gEditAddr->mResult == EDIT_RESULT_CANCELED) {
            gEditAddr->mOamEntry->mAttr01 = gEditAddr->mOamEntry->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK;
            SetUpdateFunction(UpdateEditAddrFadeIn);
            return;
        }
        GetSecondaryMenuPair(&secondaryPairFirst, NULL);
        storeFuncs.mUnk_00[secondaryPairFirst](gEditAddr->mText);
        SetUpdateFunction(ReleaseEditAddr);
    }
}

void WriteEditAddrGroupPadding(void) {
    int groupCounter;
    int group;
    int charIndex;
    int groupOffset;
    u8 fillChar;
    u8 currentChar;
    groupCounter = 0;
    groupOffset = 0;
    do {
        group = (s32) gEditAddr + 8 + groupOffset;
        charIndex = 0;
        do {
            currentChar = *(s8 *) (group + charIndex);
            if (((currentChar != '0') && (currentChar != ' ')) && (currentChar != 0)) {
                break;
            }
            if (charIndex == 2) {
                fillChar = 0x30;
            } else {
                fillChar = 0x20;
            }
            *(u8 *) (group + charIndex) = fillChar;
            charIndex = charIndex + 1;
        } while (charIndex < 3);
        groupOffset = groupOffset + 3;
        groupCounter = groupCounter + 1;
    } while (groupCounter < 4);
    PrintEditAddrText();
}

BOOL IsEditAddrTextValid(void) {
    u8 groupMax[4];
    u8 *text;
    u8 *group;
    s32 groupCounter;
    s32 charIndex;
    s32 groupOffset;
    u8 *maxChar;
    s32 secondaryPair;
    u8 addressBytes[4];
    BOOL zeroSeen;
    s32 byteCounter;
    u8 *bytePointer;
    groupMax[0] = gEditAddrGroupMax[0];
    groupMax[1] = gEditAddrGroupMax[1];
    groupMax[2] = gEditAddrGroupMax[2];
    groupMax[3] = gEditAddrGroupMax[3];
    groupCounter = 0;
    groupOffset = 0;
    text = (u8 *) gEditAddr;
    do {
        group = text + 8 + groupOffset;
        if (*group != 0x20) {
            for (charIndex = 0, maxChar = groupMax; charIndex < 3; charIndex++) {
                if (group[charIndex] > *maxChar) {
                    return FALSE;
                }
                if (group[charIndex] < *maxChar) {
                    break;
                }
                maxChar++;
            }
        }
        groupOffset += 3;
        groupCounter++;
    } while (groupCounter < 4);
    text += 8;
    ParseAddressText((char *) text, addressBytes);
    GetSecondaryMenuPair(&secondaryPair, NULL);
    if (secondaryPair == 1) {
        zeroSeen = FALSE;
        byteCounter = 0;
        bytePointer = addressBytes;
        do {
            for (charIndex = 0; charIndex < 8; charIndex++) {
                if (zeroSeen != FALSE) {
                    if ((*bytePointer & (1 << (7 - charIndex))) != 0) {
                        return FALSE;
                    }
                } else if ((*bytePointer & (1 << (7 - charIndex))) == 0) {
                    zeroSeen = TRUE;
                }
            }
            bytePointer++;
            byteCounter++;
        } while (byteCounter < 4);
        return TRUE;
    }
    if (DWC_BACKUPlCheckAddress(addressBytes) != 0) {
        return TRUE;
    }
    return FALSE;
}

void UpdateEditAddrInvalidMessageResult(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        SetUpdateFunction(UpdateEditAddrInvalidMessageClose);
    }
}

void UpdateEditAddrInvalidMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        gEditAddr->mOamEntry->mAttr01 = gEditAddr->mOamEntry->mAttr01 & (0xc1fffcffu);
        SetUpdateFunction(UpdateEditAddrFadeIn);
    }
}
