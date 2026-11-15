#include "03/Menu/jb3_list.h"

#include "03/System/application.h"
#include "03/Net/ap_entries.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Menu/message_box_create.h"
#include "03/Graphics/blend_brightness_fade_slots.h"
#include "03/Menu/jb4_error.h"
#include "03/Graphics/bg2_scr_buffer.h"
#include "03/Menu/wifi_menu_strings.h"
#include "03/Menu/wifi_menu_shared.h"
#include "gx_load2d.h"
#include "03/Graphics/text_canvas.h"
#include "03/Menu/sub_screen_message.h"
#include "03/Menu/selection_objects.h"
#include "03/Menu/scroll_bar.h"
#include "code_0212df7c.h"
#include "03/Sound/sound_seq.h"
#include "03/System/tasks.h"
#include "03/Menu/wifi_menu_tables.h"
#include "dwc_backup.h"
#include "code_02133048.h"
#include "code_02012b30.h"
#include "03/System/task_input.h"
#include "03/Menu/message_box.h"
#include "code_02147cd8.h"
#include "03/Menu/way_ap_setup.h"
#include "03/Menu/ap_screen.h"
#include "03/Menu/way_select.h"
#include "03/Menu/connect.h"
#include "03/System/dwc_archive.h"
#include "03/Graphics/nce_file.h"
#include "03/Menu/record_saved.h"
#include "os_thread.h"
#include "code_0214cfe4.h"
#include "03/Net/essid_packet_steps.h"
#include "03/Graphics/dispcnt_window.h"
#include "03/Graphics/oam_buffer_entries.h"
#include "03/System/exp_heap.h"
#include "03/System/string_length.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213c9f8.h"
#include "code_0214d018.h"
#include "03/Graphics/blend_brightness_fade_start.h"
#include "03/Graphics/hl_scr.h"
#include "03/Menu/edit_text.h"
#include "03/Menu/edit_addr.h"
#include "03/Net/ap_scan_callback.h"
#include "registers.h"

u8 gJb3ListSelectedRow;
u8 gJb3ListMode;
u8 gJb3ListSelectedId;
u16 gJb3ListScrollY;
struct Jb3List *gJb3List;
u8 gJb3ListTimerIds[4] = {2, 3, 7, 8};
const u8 gJb3ListPaletteRows[3] = {6, 8, 7};
const u8 gJb3ListEntryIndexById[11] = {0, 1, 2, 2, 3, 4, 5, 6, 6, 7, 8};
const u8 gJb3ListIdByEntryIndex[9] = {0, 1, 0xe, 4, 5, 6, 0xe, 9, 0xa};
const Rect gJb3ListSelectionRects[6] = {{0xc8, 0x31, 0xe0, 0x4d}, {0xbc, 0x31, 0xe0, 0x4d}, {0x8b, 0x31, 0xaf, 0x4d},
                                        {0x82, 0x18, 0xee, 0x2c}, {0x82, 0xa9, 0xee, 0xbd}, {2, 0xa9, 0x6e, 0xbd}};
Jb3ListSelectionRectIndices gJb3ListSelectionRectIndices = {{0, 0, 1, 2, 0, 0, 0, 1, 2, 0, 0, 3, 4, 5}};
const u8 gJb3ListBg2OffsetByEntry[9] = {0, 5, 2, 7, 4, 1, 6, 3, 0};
const OriginSizeRect gJb3ListLeftButtonRect = {0x8f, 0x34, 0x2c, 0x18};
const OriginSizeRect gJb3ListRightButtonRect = {0xc0, 0x34, 0x2c, 0x18};
const OriginSizeRect gJb3ListCellRect = {0xcc, 0x34, 0x1c, 0x18};
const Rect gJb3ListFixedRects[3] = {{0x84, 0x1b, 0xfc, 0x2c}, {0x84, 0xac, 0xfc, 0xbd}, {4, 0xac, 0x7c, 0xbd}};
u16 gDotSeparatedBytesFormat[15] = {0x25, 0x33, 0x64, 0x2e, 0x25, 0x33, 0x64, 0x2e,
                                    0x25, 0x33, 0x64, 0x2e, 0x25, 0x33, 0x64};
const u8 gJb3ListCellImageIds[5][3] = {
    {0, 0x29, 0x2c}, {0x52, 0x53, 0x30}, {0, 0x2a, 0x30}, {0x54, 0x55, 0}, {0, 0x2b, 0}};
const u16 gJb3ListBackNscOffsets[9] = {0, 0x60, 0xe0, 0x140, 0x1c0, 0x240, 0x2a0, 0x320, 0x3a0};
const s8 gJb3ListDigitColumns[6] = {-1, 0x23, 0x27, -1, 0x23, 0x2f};

void CreateJb3List(void) {
    int unusedValue;
    ApWorkCopy *record;
    int cellIndex;
    Jb3List *jb3List;
    record = GetApWorkCopy();
    jb3List = AllocZeroedExpHeapBlock(0x48, 4);
    gJb3List = jb3List;
    jb3List->mDnsNoneCopy = record->mDnsNone;
    gJb3List->mReturnId = JB3_ID_SAVE;
    ResetJb3ListScrollAndSelection();
    LoadJb3ListFilesAndSetBgCnt();
    if (gJb3ListMode == 0) {
        ShowSubScreenMessage(0x7c, gJb3ListDigitColumns[GetLanguageIndex()], record->mEntryIndex + 1);
    } else {
        ShowSubScreenMessage(0x97, -1, 0);
    }
    CreateObjectsForMenuPair(1);
    LoadHlListScr();
    CreateScrollBar(2, 0x55, 0xf1, 0x41, _s32_div_f(gJb3ListScrollY * 0x37, 0x91));
    gJb3List->mBgTextCanvas = InitBgTextCanvas(0, 1);
    for (cellIndex = 0; cellIndex < 7; cellIndex++) {
        gJb3List->mCellOamEntries[cellIndex] = CreateOamEntryFromNceImage(0, gJb3ListCellImageIds[0][1]);
    }
    switch (record->mEntry.mSetType) {
        case 1:
            gJb3List->mSetTypeOamEntry = CreateOamEntryFromNceImage(0, 0x50);
            gJb3List->mSetTypeOamEntry->mAttr2 = (gJb3List->mSetTypeOamEntry->mAttr2 & ~0xc00) | 0xc00;
            break;
        case AP_SET_TYPE_EXCHANGED:
            gJb3List->mSetTypeOamEntry = CreateOamEntryFromNceImage(0, 0x51);
            gJb3List->mSetTypeOamEntry->mAttr2 = (gJb3List->mSetTypeOamEntry->mAttr2 & ~0xc00) | 0xc00;
            break;
    }
    gJb3List->mBgOffsetTask = AddTask(1, WriteJb3ListBgOffset, NULL, 0x6e);
    gJb3List->mIdTimerTask = AddTask(0, AdvanceJb3ListIdTimers, NULL, 0x78);
    RefreshJb3List();
    PlaceJb3ListSelectionPair();
    SetUpdateFunction(StartJb3ListFadeIn);
}

void LoadJb3ListFilesAndSetBgCnt(void) {
    char jb3ListBackNscName[23] = "char/jb3ListBack.nsc.l";
    char ybBgStep2NclName[21] = "char/ybBgStep2.ncl.l";
    char ybBgStep21NclName[22] = "char/ybBgStep21.ncl.l";
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0xe18;
    LoadFileToVram("char/ybObjKb.ncl.l", GX_LoadOBJPltt);
    LoadFileToVram("char/jbBgStep2.ncg.l", GX_LoadBG3Char);
    LoadFileToVram("char/jbBgStep21.ncg.l", GX_LoadBG2Char);
    LoadFileToVram(ybBgStep2NclName, GX_LoadBGPltt);
    LoadFileToVram("char/jb3List.nsc.l", GX_LoadBG3Scr);
    gJb3List->mJb3ListBackNsc = LoadFile(BuildFilePathWithLanguage((u8 *) jb3ListBackNscName), NULL, 4);
    CreateBg2ScrBuffer(gJb3List->mJb3ListBackNsc);
    RequestBg2ScrUpload();
    gJb3List->mYbBgStep2NclFiles[0] = LoadFile(BuildFilePathWithLanguage((u8 *) ybBgStep2NclName), NULL, 4);
    gJb3List->mYbBgStep2NclFiles[1] = LoadFile(BuildFilePathWithLanguage((u8 *) ybBgStep21NclName), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK) | 0x3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 0x3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 0x3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~REG_G2_BG1CNT_PRIORITY_MASK) | 0x2;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~REG_G2_BG2CNT_PRIORITY_MASK) | 0x3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~REG_G2_BG3CNT_PRIORITY_MASK) | 0x2;
}

void ResetJb3ListScrollAndSelection(void) {
    int secondaryPairSecond[1];
    GetApWorkCopy();
    GetSecondaryMenuPair(NULL, secondaryPairSecond);
    if (secondaryPairSecond[0] == 0) {
        gJb3ListScrollY = 0;
        gJb3ListSelectedId = 0;
        gJb3ListSelectedRow = 0;
    }
}

void StartJb3ListFadeIn(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x1d, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x1d);
    SetUpdateFunction(UpdateJb3ListFadeIn);
}

void UpdateJb3ListFadeIn(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0) {
        SetUpdateFunction(UpdateJb3List);
    }
}

void UpdateJb3List(void) {
    UpdateJb3ListInput();
    UpdateJb3ListScrollInput();
}

void UpdateJb3ListInput(void) {
    Jb3List *jb3List;
    jb3List = gJb3List;
    if (jb3List->mScrollTask != 0) {
        return;
    }
    if (jb3List->mScrollBarDragging != 0) {
        return;
    }
    if (UpdateJb3ListHit() != 0) {
        return;
    }
    if (AreKeysPressed(1) != 0) {
        StartJb3ListIdAction(gJb3ListSelectedId);
        return;
    }
    if (AreKeysPressed(2) != 0) {
        StartSoundSeq(7);
        gJb3List->mChosenId = JB3_ID_BACK;
        SetUpdateFunction(StartJb3ListClose);
        return;
    }
    if (AreKeysPressedOrRepeated(0x200) != 0) {
        if (gJb3ListScrollY == 0x91) {
            if (gJb3List->mKeyLimitSoundPlayed != 0) {
                return;
            }
            StartSoundSeq(9);
            gJb3List->mKeyLimitSoundPlayed = 1;
            return;
        }
        StartSoundSeq(0x13);
        gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
        return;
    }
    if (AreKeysReleased(0x200) != 0) {
        gJb3List->mKeyLimitSoundPlayed = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x100) != 0) {
        if (gJb3ListScrollY == 0) {
            if (gJb3List->mKeyLimitSoundPlayed != 0) {
                return;
            }
            StartSoundSeq(9);
            gJb3List->mKeyLimitSoundPlayed = 1;
            return;
        }
        StartSoundSeq(0x13);
        gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
        return;
    }
    if (AreKeysReleased(0x100) != 0) {
        gJb3List->mKeyLimitSoundPlayed = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveJb3ListSelection(1);
        return;
    }
    if (AreKeysReleased(0x40) != 0) {
        gJb3List->mKeyLimitSoundPlayed = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveJb3ListSelection(3);
        return;
    }
    if (AreKeysReleased(0x80) != 0) {
        gJb3List->mKeyLimitSoundPlayed = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x20) != 0) {
        MoveJb3ListSelection(0);
        return;
    }
    if (AreKeysPressedOrRepeated(0x10) != 0) {
        MoveJb3ListSelection(2);
    }
}

BOOL UpdateJb3ListHit(void) {
    int hitId;
    int idEnabled;
    GetApWorkCopy();
    hitId = GetJb3ListHitId();
    if (hitId == JB3_ID_NONE) {
        return 0;
    }
    idEnabled = IsJb3ListIdEnabled(hitId);
    if (idEnabled == 0) {
        StartSoundSeq(9);
        return 1;
    }
    SetJb3ListSelectedId(hitId);
    switch (hitId) {
        case JB3_ID_IP_AUTO:
        case JB3_ID_IP_MANUAL:
        case JB3_ID_DNS_AUTO:
        case JB3_ID_DNS_MANUAL:
            StartJb3ListIdTimer();
    }
    StartJb3ListIdAction(hitId);
    return 1;
}

void StartJb3ListIdAction(u32 listId) {
    if (IsJb3ListIdEnabled(listId) == 0) {
        StartSoundSeq(9);
        return;
    }
    switch (listId) {
        case JB3_ID_IP_AUTO:
        case JB3_ID_IP_MANUAL:
            StartSoundSeq(6);
            SetJb3ListIpNone(((listId - 2) ^ 1) != 0);
            return;
        case JB3_ID_DNS_AUTO:
        case JB3_ID_DNS_MANUAL:
            StartSoundSeq(6);
            SetJb3ListDnsNone(((listId - 7) ^ 1) != 0);
            return;
    }
    gJb3List->mChosenId = listId;
    if (listId - JB3_ID_CONNECT <= 1) {
        RequestJb3ListPaletteRowCopy();
        if (IsJb3ListRecordValid() == 0) {
            StartSoundSeq(9);
            CreateMessageBox(0x2f, 1, 1, -1, 0);
            SetUpdateFunction(UpdateJb3ListMessageResult);
            return;
        }
        if (listId == JB3_ID_CONNECT) {
            StartSoundSeq(6);
        } else {
            StartSoundSeq(0xe);
        }
    } else if (listId == JB3_ID_BACK) {
        RequestJb3ListPaletteRowCopy();
        StartSoundSeq(7);
    } else {
        StartSoundSeq(6);
        SetupJb3ListCell(0, 1, GetJb3ListRowOfEntryIndex(gJb3ListEntryIndexById[listId]));
        RefreshJb3ListRowPositions();
    }
    DisableScrollBarInput();
    SetUpdateFunction(StartJb3ListClose);
}

void SetJb3ListIpNone(u32 newValue) {
    ApWorkCopy *record;
    BOOL otherValue;
    record = GetApWorkCopy();
    if (record->mIpNone != newValue) {
        if (newValue != 0) {
            if (gJb3List->mDnsNoneCopy != 0) {
                otherValue = TRUE;
            } else {
                otherValue = FALSE;
            }
        } else {
            gJb3List->mDnsNoneCopy = record->mDnsNone;
            otherValue = FALSE;
        }
        SetApWorkIpNone(newValue);
        SetApWorkDnsNone(otherValue);
        RefreshJb3List();
    }
}

void SetJb3ListDnsNone(u32 newValue) {
    ApWorkCopy *record;
    record = GetApWorkCopy();
    if (record->mDnsNone != newValue) {
        gJb3List->mDnsNoneCopy = (s8) newValue;
        SetApWorkDnsNone(newValue);
        RefreshJb3List();
    }
}

void UpdateJb3ListScrollInput(void) {
    int scrollRemainder;
    Jb3List *jb3List;
    jb3List = gJb3List;
    if (jb3List->mScrollTask == 0) {
        if (jb3List->mScrollTimer != 0) {
            jb3List->mScrollTimer--;
        }
        switch (GetScrollBarEvent()) {
            case SCROLL_BAR_EVENT_THUMB_PRESSED:
                gJb3List->mScrollBarDragging = 1;
                break;
            case SCROLL_BAR_EVENT_THUMB_MOVED:
                if (gJb3List->mScrollTimer != 0) {
                    return;
                }
                ReleaseSelectionObjectSlots();
                gJb3ListScrollY = _s32_div_f(GetScrollBarOffset() * 0x91, 0x37);
                RefreshJb3List();
                gJb3List->mScrollTimer = JB3_LIST_SCROLL_TIMER_FRAMES;
                break;
            case SCROLL_BAR_EVENT_OFFSET_SETTLED:
                gJb3List->mScrollBarDragging = 0;
                gJb3ListScrollY = _s32_div_f(GetScrollBarOffset() * 0x91, 0x37);
                StartSoundSeq(0x13);
                RefreshJb3List();
                scrollRemainder = FX_ModS32(gJb3ListScrollY, 0x1d);
                if (scrollRemainder == 0) {
                    SetJb3ListSelectedIdFromRow();
                    return;
                }
                if (scrollRemainder < 0x10) {
                    gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
                } else {
                    gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
                }
                break;
            case SCROLL_BAR_EVENT_ARROW_UP_PRESSED:
                if (gJb3ListScrollY == 0) {
                    if (gJb3List->mScrollBarLimitSoundPlayed != 0) {
                        return;
                    }
                    StartSoundSeq(9);
                    gJb3List->mScrollBarLimitSoundPlayed = 1;
                } else {
                    StartSoundSeq(0x13);
                    gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
                }
                break;
            case SCROLL_BAR_EVENT_ARROW_DOWN_PRESSED:
                if (gJb3ListScrollY == 0x91) {
                    if (gJb3List->mScrollBarLimitSoundPlayed != 0) {
                        return;
                    }
                    StartSoundSeq(9);
                    gJb3List->mScrollBarLimitSoundPlayed = 1;
                } else {
                    StartSoundSeq(0x13);
                    gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
                }
                break;
            case SCROLL_BAR_EVENT_ARROW_UP_RELEASED:
            case SCROLL_BAR_EVENT_ARROW_DOWN_RELEASED:
                gJb3List->mScrollBarLimitSoundPlayed = 0;
                break;
        }
    }
}

void StartJb3ListClose(void) {
    DisableScrollBarInput();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(UpdateJb3ListFadeOut);
}

void UpdateJb3ListFadeOut(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x1d, 8);
        SetUpdateFunction(UpdateJb3ListRelease);
    }
}

static inline void Jb3ListG2_GetOBJPosition(OamEntry *oamEntry, u32 *x, u32 *y) {
    *x = (oamEntry->mAttr01 & OAM_ATTR01_X_MASK) >> 16;
    *y = oamEntry->mAttr01 & OAM_ATTR01_Y_MASK;
}

void UpdateJb3ListRelease(void) {
    int index;
    u32 chosenId;
    ApWorkCopy *record;
    if (IsBlendBrightnessFadeSlotBusy(1) != 0) {
        return;
    }
    if (IsBlendBrightnessFadeSlotBusy(0) != 0) {
        return;
    }
    RemoveTaskEntryWrapper(0, gJb3List->mIdTimerTask);
    RemoveTaskEntryWrapper(1, gJb3List->mBgOffsetTask);
    for (index = 0; index < 7; index++) {
        DeleteOamEntry(gJb3List->mCellOamEntries[index]);
    }
    if (gJb3List->mSetTypeOamEntry != NULL) {
        DeleteOamEntry(gJb3List->mSetTypeOamEntry);
    }
    ReleaseScrollBar();
    ReleaseBgTextCanvasOfScreen(0);
    ReleaseSelectionObjectSlots();
    if (gJb3List->mChosenId != JB3_ID_SAVE) {
        HideSubScreenMessage();
    }
    ReleaseBg2ScrBuffer();
    DeleteLoadedFile(gJb3List->mJb3ListBackNsc);
    for (index = 0; index < 2; index++) {
        DeleteLoadedFile(gJb3List->mYbBgStep2NclFiles[index]);
    }
    LoadFileToVram("char/ybObjMain.ncl.l", GX_LoadOBJPltt);
    ClearDispcntBits(1, 1);
    ClearDispcntBits(0, 0x1d);
    reg_G2_BG0OFS = 0;
    reg_G2_BG2OFS = 0;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & (REG_G2_BG2CNT_PRIORITY_MASK | REG_G2_BG2CNT_MOSAIC_MASK)) | 0xe10;
    chosenId = gJb3List->mChosenId;
    switch (chosenId) {
        case JB3_ID_SSID:
        case JB3_ID_KEY:
            SetSecondaryMenuPair(chosenId, 0);
            SetPrimaryMenuPair(2, 0);
            SetUpdateFunction(CreateEdit);
            break;
        case JB3_ID_IP_ADDRESS:
        case JB3_ID_NETMASK:
        case JB3_ID_GATEWAY:
        case JB3_ID_DNS_FIRST:
        case JB3_ID_DNS_SECOND:
            index = chosenId - 4;
            if (chosenId >= 9) {
                index -= 2;
            }
            SetPrimaryMenuPair(2, 0);
            SetSecondaryMenuPair(index, 0);
            SetUpdateFunction(CreateEditAddr);
            break;
        case JB3_ID_CONNECT:
            record = GetApWorkCopy();
            record->mEntry.mNetmaskCidr = DWCi_BACKUPlConvMaskCidr(record->mNetmask);
            if (record->mIpNone != 0) {
                MI_CpuFill8(record->mEntry.mIp, 0, 4);
                MI_CpuFill8(record->mEntry.mGateway, 0, 4);
                MI_CpuFill8(record->mNetmask, 0, 4);
                record->mEntry.mNetmaskCidr = 0;
            }
            if (record->mDnsNone != 0) {
                MI_CpuFill8(record->mEntry.mDns, 0, 8);
            }
            SetPrimaryMenuPair(2, 0);
            SetSecondaryMenuPair(0, 0);
            SetUpdateFunction(SetupConnect);
            break;
        case JB3_ID_SAVE:
            SetPrimaryMenuPair(0, 0);
            SetUpdateFunction(SetupRecordSaved);
            break;
        case JB3_ID_BACK:
            if (gJb3ListMode == 0) {
                SetPrimaryMenuPair(2, 1);
                SetUpdateFunction(CreateAp);
            } else {
                CopyApEntryToWorkCopy((GetApWorkCopy())->mEntryIndex);
                SetPrimaryMenuPair(0, 1);
                SetUpdateFunction(SetupWay);
            }
            break;
    }
    FreeExpHeapBlockAndClearPointer(&gJb3List);
}

void RefreshJb3List(void) {
    int firstEntryIndex;
    int rowIndex;
    int entryIndex;
    firstEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    ClearBgTextCanvas(gJb3List->mBgTextCanvas, 0);
    for (rowIndex = 0, entryIndex = firstEntryIndex; rowIndex < 5; rowIndex++, entryIndex++) {
        PrintJb3ListEntryText(entryIndex, rowIndex);
    }
    CopyBg2ScrBufferRect(gJb3List->mJb3ListBackNsc + gJb3ListBackNscOffsets[firstEntryIndex], 0, 0x1e, 0x13);
    for (rowIndex = 0; rowIndex < 5; rowIndex++, firstEntryIndex++) {
        SetupJb3ListEntryCells(firstEntryIndex, rowIndex);
    }
    RequestBg2ScrUpload();
    RequestBgTextCanvasUpload(gJb3List->mBgTextCanvas);
    RefreshJb3ListRowPositions();
}

void PrintJb3ListEntryText(u32 entryIndex, int row) {
    ApWorkCopy *record;
    int starCount;
    u8 starText[0x21];
    record = GetApWorkCopy();
    switch (entryIndex) {
        case JB3_ENTRY_SSID:
            PrintJb3ListEntryString(record->mEntry.mSsid, row);
            return;
        case JB3_ENTRY_WEP_KEY:
            switch (record->mEntry.mWepMode) {
                case AP_WEP_MODE_NONE:
                    return;
                case AP_WEP_MODE_KEY_5_BYTES:
                    starCount = 10;
                    break;
                case AP_WEP_MODE_KEY_13_BYTES:
                    starCount = 0x1a;
                    break;
                case AP_WEP_MODE_KEY_16_BYTES:
                    starCount = 0x20;
                    break;
            }
            if (record->mEntry.mWepNotation == 1) {
                starCount = _s32_div_f(starCount, 2);
            }
            MI_CpuFill8(starText, 0, sizeof(starText));
            memset(starText, 0x2a, starCount);
            PrintJb3ListEntryString(starText, row);
            return;
        case JB3_ENTRY_IP_ADDRESS:
            if (record->mIpNone == 0) {
                PrintJb3ListEntryBytes(record->mEntry.mIp, row);
            }
            break;
        case JB3_ENTRY_NETMASK:
            if (record->mIpNone == 0) {
                PrintJb3ListEntryBytes(record->mNetmask, row);
            }
            break;
        case JB3_ENTRY_GATEWAY:
            if (record->mIpNone == 0) {
                PrintJb3ListEntryBytes(record->mEntry.mGateway, row);
            }
            break;
        case JB3_ENTRY_DNS_FIRST:
            if (record->mDnsNone == 0) {
                PrintJb3ListEntryBytes(record->mEntry.mDns, row);
            }
            break;
        case JB3_ENTRY_DNS_SECOND:
            if (record->mDnsNone == 0) {
                PrintJb3ListEntryBytes(&record->mEntry.mDns[4], row);
            }
            break;
    }
}

void SetupJb3ListEntryCells(u32 entryIndex, int row) {
    ApWorkCopy *record;
    int cellKind;
    int cellState;
    BOOL secondState;
    int secondKind;
    record = GetApWorkCopy();
    switch (entryIndex) {
        case JB3_ENTRY_SSID:
        case JB3_ENTRY_WEP_KEY:
            cellKind = 0;
            cellState = 0;
            if (IsJb3ListIdEnabled(cellKind) == 0) {
                cellState = 2;
            }
            break;
        case JB3_ENTRY_IP_MODE:
            secondState = FALSE;
            cellState = 0;
            if (record->mIpNone != 0) {
                cellKind = 1;
                secondKind = 4;
            } else {
                cellKind = 2;
                secondKind = 3;
            }
            if (gJb3List->mIdTimer[0] != 0) {
                cellState = 1;
            }
            if (gJb3List->mIdTimer[1] != 0) {
                secondState = TRUE;
            }
            SetupJb3ListCell(secondKind, secondState, row);
            break;
        case JB3_ENTRY_IP_ADDRESS:
        case JB3_ENTRY_NETMASK:
        case JB3_ENTRY_GATEWAY:
            cellKind = 0;
            if (record->mIpNone != 0) {
                cellState = 2;
            } else {
                cellState = cellKind;
            }
            break;
        case JB3_ENTRY_DNS_MODE:
            secondState = FALSE;
            cellState = 0;
            if (record->mDnsNone != 0) {
                cellKind = 1;
                secondKind = 4;
            } else {
                if (record->mIpNone == 0) {
                    cellState = 2;
                }
                cellKind = 2;
                secondKind = 3;
            }
            if (gJb3List->mIdTimer[2] != 0) {
                cellState = 1;
            }
            if (gJb3List->mIdTimer[3] != 0) {
                secondState = TRUE;
            }
            SetupJb3ListCell(secondKind, secondState, row);
            break;
        case JB3_ENTRY_DNS_FIRST:
        case JB3_ENTRY_DNS_SECOND:
            cellKind = 0;
            if (record->mDnsNone != 0) {
                cellState = 2;
            } else {
                cellState = cellKind;
            }
            break;
        default:
            cellKind = 0;
            cellState = 2;
            break;
    }
    SetupJb3ListCell(cellKind, cellState, row);
}

BOOL IsJb3ListIdEnabled(u32 listId) {
    ApWorkCopy *record;
    u32 enabled;
    record = GetApWorkCopy();
    enabled = 1;
    switch (listId) {
        case JB3_ID_DNS_AUTO:
            if (record->mIpNone == 0) {
                enabled = 0;
            }
            break;
        case JB3_ID_SSID:
        case JB3_ID_KEY:
            if ((u8) (record->mEntry.mSetType + 0xff) <= 1) {
                enabled = 0;
            }
            break;
        case JB3_ID_IP_ADDRESS:
        case JB3_ID_NETMASK:
        case JB3_ID_GATEWAY:
            if (record->mIpNone != 0) {
                enabled = 0;
            }
            break;
        case JB3_ID_DNS_FIRST:
        case JB3_ID_DNS_SECOND:
            if (record->mDnsNone != 0) {
                enabled = 0;
            }
            break;
    }
    return enabled;
}

void SetupJb3ListCell(int cellKind, int cellState, int row) {
    u16 cellXPositions[5];
    u16 secondXPosition;
    u32 xBits;
    OamEntry **entryPointer;
    cellXPositions[0] = gJb3ListCellRect.mX;
    secondXPosition = gJb3ListRightButtonRect.mX;
    cellXPositions[1] = secondXPosition;
    cellXPositions[2] = secondXPosition;
    secondXPosition = gJb3ListLeftButtonRect.mX;
    cellXPositions[3] = secondXPosition;
    cellXPositions[4] = secondXPosition;
    entryPointer = &gJb3List->mCellOamEntries[row];
    if ((u32) (cellKind - 1) <= 1) {
        if (GetJb3ListEntryIndexOfRow(row) == 2) {
            entryPointer = &gJb3List->mCellOamEntries[5];
        } else {
            entryPointer = &gJb3List->mCellOamEntries[6];
        }
    }
    if (gJb3ListCellImageIds[cellKind][cellState] != 0) {
        CopyNceImageToOamEntries(0, gJb3ListCellImageIds[cellKind][cellState], *entryPointer);
        xBits = (cellXPositions[cellKind] & 0x1ff) << 16;
        (*entryPointer)->mAttr01 = xBits | ((*entryPointer)->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK);
        (*entryPointer)->mAttr2 = ((*entryPointer)->mAttr2 & ~0xc00) | 0xc00;
    } else {
        (*entryPointer)->mAttr01 = ((*entryPointer)->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | 0x1000000;
    }
}

void PrintJb3ListEntryString(const u8 *bytes, int row) {
    u16 text[17];
    int length;
    int shownLength;
    int character;
    int charIndex;
    int yPosition;
    int secondLineLength;
    MI_CpuFill8(text, 0, sizeof(text));
    length = GetStringLengthWithLimit(bytes, 0x20);
    if (length <= 0x10) {
        shownLength = length;
    } else {
        shownLength = 0x10;
    }
    for (charIndex = 0; charIndex < shownLength; charIndex++) {
        character = bytes[charIndex];
        if (character == 0x20) {
            text[charIndex] = EDIT_TEXT_GLYPH_SPACE;
        } else {
            text[charIndex] = character;
        }
    }
    yPosition = row * 0x1d + 2;
    if (length <= 0x10) {
        yPosition += 5;
    }
    DrawCharsCentered(gJb3List->mBgTextCanvas, 0x48, yPosition, 2, 8, text, 1);
    if (length > 0x10) {
        MI_CpuFill8(text, 0, sizeof(text));
        secondLineLength = length - 0x10;
        for (charIndex = 0; charIndex < secondLineLength; charIndex++) {
            character = bytes[charIndex + 0x10];
            if (character == 0x20) {
                text[charIndex] = EDIT_TEXT_GLYPH_SPACE;
            } else {
                text[charIndex] = character;
            }
        }
        DrawCharsCentered(gJb3List->mBgTextCanvas, 0x48, yPosition + 0xc, 2, 8, text, 1);
    }
}

void PrintJb3ListEntryBytes(const u8 *bytes, int row) {
    u16 text[16];
    swprintf(text, 0x10, gDotSeparatedBytesFormat, bytes[0], bytes[1], bytes[2], bytes[3]);
    DrawCharsCentered(gJb3List->mBgTextCanvas, 0x5f, row * 0x1d + 8, 2, 7, text, 1);
}

void RefreshJb3ListRowPositions(void) {
    int firstEntryIndex;
    int firstRowY;
    OamEntry *oamEntry;
    int rowY;
    int rowIndex;
    u32 xPosition;
    u32 yPosition;
    firstEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    firstRowY = 0x34 - FX_ModS32(gJb3ListScrollY, 0x1d);
    if (gJb3List->mSetTypeOamEntry != NULL) {
        if (firstEntryIndex == 0) {
            xPosition = 0x26;
        } else {
            xPosition = 0x100;
        }
        gJb3List->mSetTypeOamEntry->mAttr01 =
            ((xPosition & 0x1ff) << 16) |
            ((gJb3List->mSetTypeOamEntry->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | (firstRowY & 0xff));
    }
    for (rowIndex = 0, rowY = firstRowY; rowIndex < 5; rowIndex++, rowY += 0x1d) {
        Jb3ListG2_GetOBJPosition(gJb3List->mCellOamEntries[rowIndex], (u32 *) &xPosition, &yPosition);
        oamEntry = gJb3List->mCellOamEntries[rowIndex];
        oamEntry->mAttr01 =
            ((xPosition & 0x1ff) << 16) | ((oamEntry->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | (rowY & 0xff));
    }
    if (firstEntryIndex <= 2) {
        Jb3ListG2_GetOBJPosition(gJb3List->mCellOamEntries[5], &xPosition, (u32 *) &yPosition);
        gJb3List->mCellOamEntries[5]->mAttr01 =
            ((xPosition & 0x1ff) << 16) | ((gJb3List->mCellOamEntries[5]->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) |
                                           ((firstRowY + (2 - firstEntryIndex) * 0x1d) & 0xff));
    } else {
        gJb3List->mCellOamEntries[5]->mAttr01 =
            (gJb3List->mCellOamEntries[5]->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | 0x1000000;
    }
    if (firstEntryIndex >= 2 && firstEntryIndex <= 6) {
        Jb3ListG2_GetOBJPosition(gJb3List->mCellOamEntries[6], &xPosition, (u32 *) &yPosition);
        gJb3List->mCellOamEntries[6]->mAttr01 =
            ((xPosition & 0x1ff) << 16) | ((gJb3List->mCellOamEntries[6]->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) |
                                           ((firstRowY + (6 - firstEntryIndex) * 0x1d) & 0xff));
    } else {
        gJb3List->mCellOamEntries[6]->mAttr01 =
            (gJb3List->mCellOamEntries[6]->mAttr01 & OAM_ATTR01_NOT_POSITION_MASK) | 0x1000000;
    }
    gJb3List->mBgOffsetPending = 1;
}

u32 GetJb3ListHitId(void) {
    OriginSizeRect cellRect;
    OriginSizeRect *cellRectPointer;
    s32 firstEntryIndex;
    s32 rowIndex;
    s32 searchEntryIndex;
    const Rect *fixedRect;
    if (IsTouchPressedInRect(&gTouchScreenRect) == 0) {
        return JB3_ID_NONE;
    }
    firstEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    cellRectPointer = &cellRect;
    cellRect = gJb3ListCellRect;
    for (rowIndex = 0; rowIndex < 4; rowIndex++, firstEntryIndex++, cellRect.mY += 0x1d) {
        if (firstEntryIndex != 2 && firstEntryIndex != 6) {
            if (IsTouchPressedInOriginSizeRect(cellRectPointer) != 0) {
                return gJb3ListIdByEntryIndex[firstEntryIndex];
            }
        }
    }
    searchEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    for (rowIndex = 0; rowIndex < 4; rowIndex++, searchEntryIndex++) {
        if (searchEntryIndex == 2) {
            cellRect = gJb3ListRightButtonRect;
            rowIndex = rowIndex * 0x1d;
            cellRect.mY = cellRect.mY + rowIndex;
            if (IsTouchPressedInOriginSizeRect(&cellRect) != 0) {
                return 2;
            }
            cellRect = gJb3ListLeftButtonRect;
            cellRect.mY = cellRect.mY + rowIndex;
            if (IsTouchPressedInOriginSizeRect(&cellRect) != 0) {
                return 3;
            }
            break;
        }
    }
    searchEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    for (rowIndex = 0; rowIndex < 4; rowIndex++, searchEntryIndex++) {
        if (searchEntryIndex == 6) {
            cellRect = gJb3ListRightButtonRect;
            rowIndex = rowIndex * 0x1d;
            cellRect.mY = cellRect.mY + rowIndex;
            if (IsTouchPressedInOriginSizeRect(&cellRect) != 0) {
                return 7;
            }
            cellRect = gJb3ListLeftButtonRect;
            cellRect.mY = cellRect.mY + rowIndex;
            if (IsTouchPressedInOriginSizeRect(&cellRect) != 0) {
                return 8;
            }
            break;
        }
    }
    rowIndex = 0;
    fixedRect = gJb3ListFixedRects;
    for (; rowIndex < 3; rowIndex++) {
        if (IsTouchPressedInRect(fixedRect) != 0) {
            return rowIndex + JB3_ID_CONNECT;
        }
        fixedRect++;
    }
    return JB3_ID_NONE;
}

int GetJb3ListRowOfEntryIndex(int entryIndex) {
    int firstEntryIndex;
    int row;
    firstEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    row = 0;
    do {
        if (firstEntryIndex == entryIndex) {
            return row;
        }
        row = row + 1;
        firstEntryIndex = firstEntryIndex + 1;
    } while (row < 4);
    return -1;
}

int GetJb3ListEntryIndexOfRow(int row) {
    int firstEntryIndex;
    firstEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    return firstEntryIndex + row;
}

void AdvanceJb3ListScrollYDecrease(TaskEntry *taskEntry, void *arg) {
    s32 scrollRemainder;
    DisableScrollBarInput();
    ReleaseSelectionObjectSlots();
    if (gJb3ListScrollY > 6) {
        gJb3ListScrollY = gJb3ListScrollY - 6;
    } else {
        gJb3ListScrollY = 0;
    }
    scrollRemainder = FX_ModS32(gJb3ListScrollY, 0x1d);
    if (scrollRemainder == 0x17) {
        RefreshJb3List();
        return;
    }
    if (scrollRemainder > 0x17) {
        gJb3ListScrollY = gJb3ListScrollY + (0x1d - scrollRemainder);
        scrollRemainder = 0;
    }
    RefreshJb3ListRowPositions();
    if (scrollRemainder == 0) {
        PlaceScrollBarWrapper(_s32_div_f(gJb3ListScrollY * 0x37, 0x91));
        EnableScrollBarInput();
        SetJb3ListSelectedIdFromRow();
        gJb3List->mScrollTask = 0;
        RequestTaskRemoval(0, taskEntry);
    }
}

void AdvanceJb3ListScrollYIncrease(TaskEntry *taskEntry, void *arg) {
    s32 scrollRemainder;
    DisableScrollBarInput();
    ReleaseSelectionObjectSlots();
    gJb3ListScrollY = gJb3ListScrollY + 6;
    scrollRemainder = FX_ModS32(gJb3ListScrollY, 0x1d);
    if (scrollRemainder >= 6) {
        RefreshJb3ListRowPositions();
        return;
    }
    gJb3ListScrollY = gJb3ListScrollY - scrollRemainder;
    RefreshJb3List();
    PlaceScrollBarWrapper(_s32_div_f(gJb3ListScrollY * 0x37, 0x91));
    EnableScrollBarInput();
    SetJb3ListSelectedIdFromRow();
    gJb3List->mScrollTask = 0;
    RequestTaskRemoval(0, taskEntry);
}

void WriteJb3ListBgOffset(TaskEntry *task, void *arg) {
    u32 firstEntryIndex;
    s32 bgOffsetY;
    if (gJb3List->mBgOffsetPending != 0) {
        firstEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
        bgOffsetY = FX_ModS32(gJb3ListScrollY, 0x1d) - 0x33;
        reg_G2_BG0OFS = (bgOffsetY << 16) & 0x1ff0000;
        reg_G2_BG2OFS = ((bgOffsetY + gJb3ListBg2OffsetByEntry[firstEntryIndex]) << 16) & 0x1ff0000;
        gJb3List->mBgOffsetPending = 0;
    }
}

void PlaceJb3ListSelectionPair(void) {
    Jb3ListSelectionRectIndices selectionRectIndices;
    Rect selectionRect;
    s32 rectIndex;
    selectionRectIndices = gJb3ListSelectionRectIndices;
    rectIndex = selectionRectIndices.mRectIndices[gJb3ListSelectedId];
    if (rectIndex >= 3) {
        PlaceSelectionPair(3, gJb3ListSelectionRects[rectIndex].mX, gJb3ListSelectionRects[rectIndex].mRight,
                           gJb3ListSelectionRects[rectIndex].mY);
        return;
    }
    selectionRect = gJb3ListSelectionRects[rectIndex];
    selectionRect.mY = selectionRect.mY + gJb3ListSelectedRow * 0x1d;
    PlaceSelectionPair(1, selectionRect.mX, selectionRect.mRight, selectionRect.mY);
}

void SetJb3ListSelectedIdFromRow(void) {
    ApWorkCopy *record;
    s32 entryIndex;
    if ((u8) (gJb3ListSelectedId + 0xf5) <= 2) {
        PlaceJb3ListSelectionPair();
        return;
    }
    record = GetApWorkCopy();
    entryIndex = gJb3ListSelectedRow + FX_DivS32(gJb3ListScrollY, 0x1d);
    switch (entryIndex) {
        case JB3_ENTRY_IP_MODE:
            if (record->mIpNone != 0) {
                gJb3ListSelectedId = 2;
            } else {
                gJb3ListSelectedId = 3;
            }
            break;
        case JB3_ENTRY_DNS_MODE:
            if (record->mDnsNone != 0) {
                gJb3ListSelectedId = 7;
            } else {
                gJb3ListSelectedId = 8;
            }
            break;
        default:
            gJb3ListSelectedId = gJb3ListIdByEntryIndex[entryIndex];
            break;
    }
    PlaceJb3ListSelectionPair();
}

void SetJb3ListSelectedId(u32 listId) {
    gJb3ListSelectedId = listId;
    gJb3ListSelectedRow = GetJb3ListRowOfEntryIndex(gJb3ListEntryIndexById[listId]);
    PlaceJb3ListSelectionPair();
}

void MoveJb3ListSelection(s32 direction) {
    ApWorkCopy *record;
    s32 moveResult;
    s32 selectedId;
    record = GetApWorkCopy();
    moveResult = 0;
    selectedId = gJb3ListSelectedId;
    if (selectedId == JB3_ID_DNS_MANUAL && record->mIpNone == 0) {
        if (direction == 0) {
            return;
        }
        if (direction == 2) {
            return;
        }
    }
    switch (selectedId) {
        case JB3_ID_SSID:
            if (direction == 1) {
                gJb3ListSelectedId = JB3_ID_CONNECT;
            } else if (direction == 3) {
                gJb3ListSelectedRow = gJb3ListSelectedRow + 1;
            } else {
                moveResult = 2;
            }
            break;
        case JB3_ID_DNS_SECOND:
            if (direction == 1) {
                gJb3ListSelectedRow = gJb3ListSelectedRow - 1;
            } else if (direction == 3) {
                gJb3ListSelectedId = gJb3List->mReturnId;
            } else {
                moveResult = 2;
            }
            break;
        case JB3_ID_CONNECT:
            if (direction == 1) {
                if (gJb3List->mKeyLimitSoundPlayed != 0) {
                    return;
                }
                StartSoundSeq(9);
                gJb3List->mKeyLimitSoundPlayed = 1;
                return;
            } else if (direction == 3) {
                gJb3ListSelectedId = 0;
                gJb3ListSelectedRow = 0;
                gJb3ListScrollY = 0;
                RefreshJb3List();
                PlaceScrollBarWrapper(0);
            } else {
                moveResult = 2;
            }
            break;
        case JB3_ID_SAVE:
        case JB3_ID_BACK:
            gJb3List->mReturnId = selectedId;
            if (direction == 1) {
                gJb3ListSelectedId = JB3_ID_DNS_SECOND;
                gJb3ListSelectedRow = 3;
                gJb3ListScrollY = 0x91;
                RefreshJb3List();
                PlaceScrollBarWrapper(0x37);
            } else if (direction == 3) {
                if (gJb3List->mKeyLimitSoundPlayed != 0) {
                    return;
                }
                StartSoundSeq(9);
                gJb3List->mKeyLimitSoundPlayed = 1;
                return;
            } else if (selectedId == JB3_ID_SAVE) {
                gJb3ListSelectedId = JB3_ID_BACK;
            } else {
                gJb3ListSelectedId = JB3_ID_SAVE;
            }
            break;
        default:
            if (direction == 1) {
                if (gJb3ListSelectedRow != 0) {
                    gJb3ListSelectedRow = gJb3ListSelectedRow - 1;
                    break;
                }
                StartSoundSeq(0x13);
                gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
                return;
            } else if (direction == 3) {
                if (gJb3ListSelectedRow < 3) {
                    gJb3ListSelectedRow = gJb3ListSelectedRow + 1;
                    break;
                }
                StartSoundSeq(0x13);
                gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
                return;
            } else {
                moveResult = 2;
                if (selectedId == 2) {
                    gJb3ListSelectedId = 3;
                } else if (selectedId == 3) {
                    gJb3ListSelectedId = moveResult;
                } else if (selectedId == 7) {
                    gJb3ListSelectedId = 8;
                } else if (selectedId == 8) {
                    gJb3ListSelectedId = 7;
                } else {
                    break;
                }
                StartSoundSeq(8);
                PlaceJb3ListSelectionPair();
            }
            break;
    }
    if (moveResult != 2) {
        StartSoundSeq(8);
        if (moveResult == 0) {
            SetJb3ListSelectedIdFromRow();
        }
    }
}

void RequestJb3ListPaletteRowCopy(void) {
    u8 paletteRow;
    paletteRow = gJb3ListPaletteRows[gJb3ListSelectedId - JB3_ID_CONNECT];
    RequestBgPaletteRowCopy(gJb3List->mYbBgStep2NclFiles[1], paletteRow, paletteRow);
}

void AdvanceJb3ListIdTimers(TaskEntry *task, void *arg) {
    s32 timerIndex;
    for (timerIndex = 0; timerIndex < 4; timerIndex++) {
        if (gJb3List->mIdTimer[timerIndex] != 0) {
            gJb3List->mIdTimer[timerIndex] = gJb3List->mIdTimer[timerIndex] - 1;
            if (gJb3List->mIdTimer[timerIndex] == 0) {
                RefreshJb3List();
            }
        }
    }
}

void StartJb3ListIdTimer(void) {
    u8 timerIds[4];
    s32 timerIndex;
    u8 *timerIdPointer;
    u8 selectedId;
    timerIdPointer = timerIds;
    timerIds[0] = gJb3ListTimerIds[0];
    timerIds[1] = gJb3ListTimerIds[1];
    timerIds[2] = gJb3ListTimerIds[2];
    timerIds[3] = gJb3ListTimerIds[3];
    timerIndex = 0;
    selectedId = gJb3ListSelectedId;
    for (; timerIndex < 4; timerIndex++) {
        if (selectedId == *timerIdPointer) {
            gJb3List->mIdTimer[timerIndex] = JB3_LIST_ID_PRESSED_FRAMES;
            if ((timerIndex & 1) != 0) {
                gJb3List->mIdTimer[timerIndex - 1] = 0;
            } else {
                gJb3List->mIdTimer[timerIndex + 1] = 0;
            }
            return;
        }
        timerIdPointer++;
    }
}

BOOL IsJb3ListRecordValid(void) {
    ApWorkCopy *record;
    record = GetApWorkCopy();
    if (record->mEntry.mSsid[0] == 0) {
        return 0;
    }
    if (record->mDnsNone == 0) {
        if (DWC_BACKUPlCheckAddress(record->mEntry.mDns) == 0 &&
            DWC_BACKUPlCheckAddress(&record->mEntry.mDns[4]) == 0) {
            return 0;
        }
    }
    if (record->mIpNone == 0) {
        if (DWC_BACKUPlCheckAddress(record->mEntry.mIp) == 0) {
            return 0;
        }
        if (DWC_BACKUPlCheckAddress(record->mEntry.mGateway) == 0) {
            return 0;
        }
        if (DWC_BACKUPlCheckIp(record->mEntry.mIp, record->mNetmask) == 0) {
            return 0;
        }
    }
    return 1;
}

void UpdateJb3ListMessageResult(void) {
    int messageAnswer;
    messageAnswer = GetMessageBoxResult();
    if (messageAnswer == 0) {
        StartSoundSeq(6);
        CloseMessageBox();
        RequestBgPaletteCopy(gJb3List->mYbBgStep2NclFiles[0]);
        SetUpdateFunction(UpdateJb3ListMessageClose);
    }
}

void UpdateJb3ListMessageClose(void) {
    int messageOpen;
    messageOpen = IsMessageBoxOpen();
    if (messageOpen == 0) {
        SetUpdateFunction(UpdateJb3List);
    }
}

void SetJb3ListMode(u8 mode) {
    gJb3ListMode = mode;
}
