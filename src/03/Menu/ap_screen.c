#include "03/Menu/ap_screen.h"
#include "03/Menu/way_select.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/slide_buttons.h"
#include "03/Menu/message_box.h"
#include "03/System/application.h"
#include "03/Menu/way_ap_setup.h"
#include "sound_archive_load_result.h"
#include "03/Sound/sound_seq.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/selection_objects.h"
#include "03/System/task_input.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/System/dwc_archive.h"
#include "03/Menu/wifi_menu_strings.h"
#include "03/Graphics/text_canvas.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Net/essid_packet_steps.h"
#include "03/Net/ap_entries.h"
#include "03/Graphics/hl_scr.h"
#include "vram_load_2d_graphics.h"
#include "registers.h"
#include "03/Menu/jb3_list.h"
#include "03/Menu/ap_scan_screen.h"
#include "03/Menu/value_records.h"
#include "03/Menu/exchange_search.h"
#include "03/Graphics/oam_range_set.h"
#include "03/Graphics/oam_range.h"
#include "formatted_text_to_buffer.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/bg2_scr_buffer.h"
#include "03/Menu/jb2_menu.h"
#include "03/Menu/menu_pair_objects_slide_out.h"
#include "03/Menu/message_box_create.h"
#include "03/Graphics/nce_file.h"
#include "03/Menu/xb3_multi.h"
#include "03/Graphics/oam_range_entry.h"
#include "03/Menu/main_menu_fade_out.h"

YbBgStep11NclName gYbBgStep11NclName2 = {{0x63, 0x68, 0x61, 0x72, 0x2f, 0x79, 0x62, 0x42, 0x67, 0x53, 0x74,
                                          0x65, 0x70, 0x31, 0x31, 0x2e, 0x6e, 0x63, 0x6c, 0x2e, 0x6c, 0}};
ApEntryIconPalettes gApEntryIconPalettes = {{0xa, 9, 0xb, 6}};
ApPaletteRows gApPaletteRows = {{3, 4, 5, 7}};
const u8 gApRects[56] = {8,    0, 0x20, 0, 0x54, 0, 0x56, 0, 0x5a, 0, 0x20, 0, 0xa6, 0, 0x56, 0, 0xac, 0, 0x20, 0,
                         0xf8, 0, 0x56, 0, 8,    0, 0x78, 0, 0xf8, 0, 0xa0, 0, 8,    0, 0x54, 0, 0x54, 0, 0x70, 0,
                         0x5a, 0, 0x54, 0, 0xa6, 0, 0x70, 0, 0xac, 0, 0x54, 0, 0xf8, 0, 0x70, 0};
const Rect gApSelectionRects[7] = {{6, 0x1e, 0x46, 0x48},   {0x58, 0x1e, 0x98, 0x48}, {0xaa, 0x1e, 0xea, 0x48},
                                   {6, 0x76, 0xea, 0x92},   {9, 0x54, 0x43, 0x70},    {0x5b, 0x54, 0x95, 0x70},
                                   {0xad, 0x54, 0xe7, 0x70}};
const ApObjectPosition gApObjectPositions[6] = {{8, 0x30},   {0x5a, 0x30}, {0xac, 0x30},
                                                {0xc, 0x58}, {0x5e, 0x58}, {0xb0, 0x58}};
const s8 gApMessageDigitColumns[6] = {3, 0x2d, 0x27, 0x1d, 0x32, 0x30};
const u8 gApEntryImageIndices[4] = {0x13, 0x14, 0x12, 0x56};
u8 gApSelectedIndex;
struct Ap *gAp;

void CreateAp(void) {
    Ap *apObject = AllocZeroedExpHeapBlock(0x20, 4);
    gAp = apObject;
    apObject->mCloseKind = AP_CLOSE_KIND_NONE;
    LoadApFilesAndSetBgCnt();
    LoadHlScr(1);
    ShowSubScreenMessage(0x7b, -1, 0);
    CreateObjectsForMenuPair(0);
    CreateApEntryObjects();
    PlaceApSelection();
    SetUpdateFunction(StartApFadeIn);
}

void LoadApFilesAndSetBgCnt(void) {
    YbBgStep11NclName ybBgStep11NclName = gYbBgStep11NclName2;
    LoadFileToVram("char/ybObjWay.ncl.l", GX_LoadOBJPltt);
    LoadFileToVram("char/jbBgStep1.ncg.l", GX_LoadBG2Char);
    LoadFileToVram("char/jbBgStep1.ncl.l", GX_LoadBGPltt);
    LoadFileToVram("char/jb2Ap.nsc.l", GX_LoadBG2Scr);
    gAp->mYbBgStep11Ncl = LoadFile(BuildFilePathWithLanguage((u8 *) &ybBgStep11NclName), NULL, 4);
    CombineDispcntBits(1, 0x10);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 3;
}

void CreateApEntryObjects(void) {
    s32 entryIndex;
    u32 entryStatus;
    for (entryIndex = 0; entryIndex < 3; entryIndex++) {
        entryStatus = GetApEntrySetType(entryIndex);
        if (entryStatus == 0xff) {
            entryStatus = 3;
        } else {
            gAp->mResetButtonObjects[entryIndex] = CreateOamRangeFromNceImage(0, 0x11, 1);
            SetOamRangePosition(gAp->mResetButtonObjects[entryIndex], -1, gApObjectPositions[entryIndex + 3].mX,
                                gApObjectPositions[entryIndex + 3].mY);
            SetOamRangePriority(gAp->mResetButtonObjects[entryIndex], -1, 3);
        }
        gAp->mEntryIconObjects[entryIndex] = CreateOamRangeFromNceImage(0, gApEntryImageIndices[entryStatus], 1);
        SetOamRangePosition(gAp->mEntryIconObjects[entryIndex], -1, gApObjectPositions[entryIndex].mX,
                            gApObjectPositions[entryIndex].mY);
        SetOamRangePriority(gAp->mEntryIconObjects[entryIndex], -1, 3);
    }
}

void StartApFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x14, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x14);
    SetUpdateFunction(UpdateApFadeIn);
}

void UpdateApFadeIn(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if ((fadeSlotBusy == 0) && (fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0), fadeSlotBusy == 0)) {
        CreateSlideButtonsForMenuPair(0);
        SetUpdateFunction(UpdateApButtonsIn);
    }
}

void UpdateApButtonsIn(void) {
    if (GetButtonResult() != -2 && IsMenuPairObjectsSliding() != 1) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateAp);
    }
}

void UpdateAp(void) {
    UpdateApInput();
    UpdateApNop();
    UpdateApResult();
}

void UpdateApInput(void) {
    int touchPressed;
    u32 rectIndex;
    int keysPressed;
    const u8 *rect;
    rectIndex = 0;
    rect = gApRects;
    do {
        touchPressed = IsTouchPressedInRect((const Rect *) rect);
        if (touchPressed != 0) {
            SetButtonResultIfNone(1);
            gApSelectedIndex = (s8) rectIndex;
            PlaceApSelection();
            return;
        }
        rect = rect + 8;
        rectIndex = rectIndex + 1;
    } while (rectIndex < 7);
    keysPressed = AreKeysPressed(1);
    if (keysPressed != 0) {
        SetButtonResultIfNone(1);
        return;
    }
    keysPressed = AreKeysPressed(2);
    if (keysPressed != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    keysPressed = AreKeysPressedOrRepeated(0x40);
    if (keysPressed != 0) {
        MoveApSelection(1);
        return;
    }
    keysPressed = AreKeysPressedOrRepeated(0x80);
    if (keysPressed != 0) {
        MoveApSelection(3);
        return;
    }
    keysPressed = AreKeysPressedOrRepeated(0x20);
    if (keysPressed != 0) {
        MoveApSelection(0);
        return;
    }
    keysPressed = AreKeysPressedOrRepeated(0x10);
    if (keysPressed != 0) {
        MoveApSelection(2);
    }
}

void UpdateApNop(void) {}

void UpdateApResult(void) {
    s32 entryIndex;
    u8 selectedIndex;
    switch (GetButtonResult()) {
        case 0:
            switch (GetMode()) {
                case 0:
                    StartSoundSeq(7);
                    gAp->mCloseKind = AP_CLOSE_KIND_BACK;
                    break;
                case 1:
                    DisableButtonTouch();
                    SetUpdateFunction(StartMainFadeOut);
                    return;
            }
            break;
        case 1:
            gAp->mCloseKind = AP_CLOSE_KIND_SELECTED;
            selectedIndex = gApSelectedIndex;
            if (selectedIndex >= 4) {
                entryIndex = selectedIndex - 4;
                if (GetApEntrySetType(entryIndex) == 0xff) {
                    StartSoundSeq(9);
                    SetButtonResult(-1);
                    return;
                }
                StartSoundSeq(6);
                CreateMessageBox(0x98, 0, 1, gApMessageDigitColumns[GetLanguageIndex()], entryIndex + 1);
                SetApSelectedButtonImage();
                DisableButtonTouch();
                SetUpdateFunction(UpdateApMessageResult);
                return;
            }
            if (selectedIndex <= 2) {
                CopyApEntryToWorkCopy(selectedIndex);
            }
            StartSoundSeq(6);
            RequestApSelectionPalette();
            break;
        default:
            return;
    }
    SetUpdateFunction(StartApClose);
}

void StartApClose(void) {
    if (gAp->mCloseKind == AP_CLOSE_KIND_BACK) {
        StartMenuPairObjectsSlideOut();
    }
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateApFadeOut);
}

void UpdateApFadeOut(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0) {
        if (gAp->mCloseKind == AP_CLOSE_KIND_SELECTED) {
            if (gApSelectedIndex == AP_SELECTED_MULTI || GetApWorkCopy()->mEntry.mSetType != AP_SET_TYPE_EMPTY) {
                StartSlideButtonsOut();
            }
        }
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x14, 8);
        SetUpdateFunction(UpdateApRelease);
    }
}

void UpdateApRelease(void) {
    u32 entryIndex;
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0 &&
        IsMenuPairObjectsNotSlidingOut() != 0 && IsSlideButtonsNotSlidingOut() != 0) {
        for (entryIndex = 0; entryIndex < 3; entryIndex++) {
            if (gAp->mEntryIconObjects[entryIndex] != NULL) {
                DeleteOamRange(gAp->mEntryIconObjects[entryIndex]);
            }
        }
        for (entryIndex = 0; entryIndex < 3; entryIndex++) {
            if (gAp->mResetButtonObjects[entryIndex] != NULL) {
                DeleteOamRange(gAp->mResetButtonObjects[entryIndex]);
            }
        }
        ReleaseSelectionObjectSlots();
        HideSubScreenMessage();
        DeleteLoadedFile(gAp->mYbBgStep11Ncl);
        LoadFileToVram("char/ybObjMain.ncl.l", GX_LoadOBJPltt);
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x14);
        if (gAp->mCloseKind == AP_CLOSE_KIND_BACK) {
            SetPrimaryMenuPair(0, 0);
            SetUpdateFunction(SetupJb2Menu);
        } else {
            switch (gApSelectedIndex) {
                case AP_SELECTED_FIRST_ENTRY:
                case AP_SELECTED_SECOND_ENTRY:
                case AP_SELECTED_THIRD_ENTRY:
                    SetPrimaryMenuPair(2, 0);
                    if (GetApWorkCopy()->mEntry.mSetType == AP_SET_TYPE_EMPTY) {
                        SetUpdateFunction(SetupWay);
                    } else {
                        SetSecondaryMenuPair(0, 0);
                        SetJb3ListMode(0);
                        SetUpdateFunction(CreateJb3List);
                    }
                    break;
                case AP_SELECTED_MULTI:
                    SetPrimaryMenuPair(2, 1);
                    SetUpdateFunction(SetupXb3Multi);
                    break;
            }
        }
        FreeExpHeapBlockAndClearPointer(&gAp);
    }
}

void PlaceApSelection(void) {
    u8 selectedIndex = gApSelectedIndex;
    if (selectedIndex < 4) {
        PlaceSelectionCorners(gApSelectionRects[selectedIndex].mX, gApSelectionRects[selectedIndex].mRight,
                              gApSelectionRects[selectedIndex].mY, gApSelectionRects[selectedIndex].mBottom);
    } else {
        PlaceSelectionPair(0, gApSelectionRects[selectedIndex].mX, gApSelectionRects[selectedIndex].mRight,
                           gApSelectionRects[selectedIndex].mY);
    }
}

void MoveApSelection(int direction) {
    u32 moved = 1;
    switch (gApSelectedIndex) {
        case AP_SELECTED_FIRST_ENTRY:
            gAp->mRememberedEntryIndex = AP_SELECTED_FIRST_ENTRY;
            if (direction == 0) {
                gApSelectedIndex = AP_SELECTED_THIRD_ENTRY;
            } else if (direction == 2) {
                gApSelectedIndex = AP_SELECTED_SECOND_ENTRY;
            } else if (direction == 1) {
                gApSelectedIndex = AP_SELECTED_MULTI;
            } else {
                gApSelectedIndex = AP_SELECTED_FIRST_RESET;
            }
            break;
        case AP_SELECTED_SECOND_ENTRY:
            gAp->mRememberedEntryIndex = AP_SELECTED_SECOND_ENTRY;
            if (direction == 0) {
                gApSelectedIndex = AP_SELECTED_FIRST_ENTRY;
            } else if (direction == 2) {
                gApSelectedIndex = AP_SELECTED_THIRD_ENTRY;
            } else if (direction == 1) {
                gApSelectedIndex = AP_SELECTED_MULTI;
            } else {
                gApSelectedIndex = AP_SELECTED_SECOND_RESET;
            }
            break;
        case AP_SELECTED_THIRD_ENTRY:
            gAp->mRememberedEntryIndex = AP_SELECTED_THIRD_ENTRY;
            if (direction == 0) {
                gApSelectedIndex = AP_SELECTED_SECOND_ENTRY;
            } else if (direction == 2) {
                gApSelectedIndex = AP_SELECTED_FIRST_ENTRY;
            } else if (direction == 1) {
                gApSelectedIndex = AP_SELECTED_MULTI;
            } else {
                gApSelectedIndex = AP_SELECTED_THIRD_RESET;
            }
            break;
        case AP_SELECTED_MULTI: {
            u8 rememberedIndex = gAp->mRememberedEntryIndex;
            s32 targetIndex = rememberedIndex + 4;
            if (direction == 1) {
                gApSelectedIndex = targetIndex;
            } else if (direction == 3) {
                gApSelectedIndex = rememberedIndex;
            } else {
                moved = 0;
            }
            break;
        }
        case AP_SELECTED_FIRST_RESET:
            gAp->mRememberedEntryIndex = AP_SELECTED_FIRST_ENTRY;
            if (direction == 0) {
                gApSelectedIndex = AP_SELECTED_THIRD_RESET;
            } else if (direction == 2) {
                gApSelectedIndex = AP_SELECTED_SECOND_RESET;
            } else if (direction == 1) {
                gApSelectedIndex = AP_SELECTED_FIRST_ENTRY;
            } else {
                gApSelectedIndex = AP_SELECTED_MULTI;
            }
            break;
        case AP_SELECTED_SECOND_RESET:
            gAp->mRememberedEntryIndex = AP_SELECTED_SECOND_ENTRY;
            if (direction == 0) {
                gApSelectedIndex = AP_SELECTED_FIRST_RESET;
            } else if (direction == 2) {
                gApSelectedIndex = AP_SELECTED_THIRD_RESET;
            } else if (direction == 1) {
                gApSelectedIndex = AP_SELECTED_SECOND_ENTRY;
            } else {
                gApSelectedIndex = AP_SELECTED_MULTI;
            }
            break;
        case AP_SELECTED_THIRD_RESET:
            gAp->mRememberedEntryIndex = AP_SELECTED_THIRD_ENTRY;
            if (direction == 0) {
                gApSelectedIndex = AP_SELECTED_SECOND_RESET;
            } else if (direction == 2) {
                gApSelectedIndex = AP_SELECTED_FIRST_RESET;
            } else if (direction == 1) {
                gApSelectedIndex = AP_SELECTED_THIRD_ENTRY;
            } else {
                gApSelectedIndex = AP_SELECTED_MULTI;
            }
            break;
    }
    if (moved != 0) {
        StartSoundSeq(8);
        PlaceApSelection();
    }
}

void SetApSelectedButtonImage(void) {
    s32 entryIndex = gApSelectedIndex - 4;
    CopyNceImageToOamEntries(0, 0x32, GetOamRangeEntry(gAp->mResetButtonObjects[entryIndex], 0));
    SetOamRangePosition(gAp->mResetButtonObjects[entryIndex], -1, gApObjectPositions[entryIndex + 3].mX,
                        gApObjectPositions[entryIndex + 3].mY);
    SetOamRangePriority(gAp->mResetButtonObjects[entryIndex], -1, 3);
}

void UpdateApMessageResult(void) {
    s32 entryIndex = gApSelectedIndex - 4;
    switch (GetMessageBoxResult()) {
        case 1:
            StartSoundSeq(0xe);
            ResetApEntry(entryIndex);
            CopyNceImageToOamEntries(0, gApEntryImageIndices[3],
                                     GetOamRangeEntry(gAp->mEntryIconObjects[entryIndex], 0));
            SetOamRangePosition(gAp->mEntryIconObjects[entryIndex], -1, gApObjectPositions[entryIndex].mX,
                                gApObjectPositions[entryIndex].mY);
            SetOamRangePriority(gAp->mEntryIconObjects[entryIndex], -1, 3);
            DeleteOamRange(gAp->mResetButtonObjects[entryIndex]);
            gAp->mResetButtonObjects[entryIndex] = NULL;
            break;
        case 0:
            StartSoundSeq(7);
            CopyNceImageToOamEntries(0, 0x11, GetOamRangeEntry(gAp->mResetButtonObjects[entryIndex], 0));
            SetOamRangePosition(gAp->mResetButtonObjects[entryIndex], -1, gApObjectPositions[entryIndex + 3].mX,
                                gApObjectPositions[entryIndex + 3].mY);
            SetOamRangePriority(gAp->mResetButtonObjects[entryIndex], -1, 3);
            break;
        default:
            return;
    }
    CloseMessageBox();
    SetUpdateFunction(UpdateApMessageClose);
}

void UpdateApMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateAp);
    }
}

void RequestApSelectionPalette(void) {
    ApPaletteRows paletteRows;
    ApEntryIconPalettes iconPalettes;
    int statusIndex;
    paletteRows = gApPaletteRows;
    iconPalettes = gApEntryIconPalettes;
    if (gApSelectedIndex <= 3) {
        RequestBgPaletteRowCopy(gAp->mYbBgStep11Ncl, paletteRows.mRowIndices[gApSelectedIndex],
                                paletteRows.mRowIndices[gApSelectedIndex]);
        if (gApSelectedIndex != AP_SELECTED_MULTI) {
            statusIndex = GetApEntrySetType(gApSelectedIndex);
            if (statusIndex > 2) {
                statusIndex = 3;
            }
            SetOamRangeMode(gAp->mEntryIconObjects[gApSelectedIndex], -1, 0, iconPalettes.mPaletteIndices[statusIndex]);
        }
    }
}
