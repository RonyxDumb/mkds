#include "03/code_021c7d30.h"

#include "03/code_021bf000.h"
#include "03/code_021c209c.h"
#include "03/code_021c7000.h"
#include "03/code_021c2000.h"
#include "03/code_021cd2e0.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021c7844.h"
#include "03/code_021c8000.h"
#include "03/code_021c9000.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cd000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021cca74.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3488.h"
#include "03/unk_021d6000.h"
#include "code_021510a4.h"
#include "code_02133048.h"
#include "Main/Unknown/code_02147000.h"
#include "03/code_021d2940.h"
#include "03/code_021cea3c.h"
#include "code_02147cd8.h"
#include "03/code_021cb11c.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cb8d8.h"
#include "03/code_021d1440.h"
#include "03/code_021d1c18.h"
#include "03/code_021c97c0.h"
#include "03/code_021cb000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214cfe4.h"
#include "03/code_021b94b8.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3254.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213c9f8.h"
#include "code_0214d018.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d3000.h"
#include "03/code_021bf810.h"
#include "03/code_021c6764.h"
#include "03/code_021c6f08.h"
#include "03/code_021cce78.h"
#include "registers.h"

void CreateJb3List(void) {
    int a;
    ApWorkCopy *record;
    int i;
    Jb3List *jb3List;
    record = GetApWorkCopy();
    jb3List = AllocZeroedExpHeapBlock(0x48, 4);
    gJb3List = jb3List;
    jb3List->mUnk_43 = record->mDnsNone;
    gJb3List->mReturnId = 0xc;
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
    gJb3List->mUnk_14 = InitBgTextCanvas(0, 1);
    for (i = 0; i < 7; i++) {
        gJb3List->mUnk_18[i] = CreateOamEntryFromNceImage(0, gJb3ListCellImageIds[0][1]);
    }
    switch (record->mEntry.mSetType) {
        case 1:
            gJb3List->mUnk_34 = CreateOamEntryFromNceImage(0, 0x50);
            gJb3List->mUnk_34->mAttr2 = (gJb3List->mUnk_34->mAttr2 & ~0xc00) | 0xc00;
            break;
        case 2:
            gJb3List->mUnk_34 = CreateOamEntryFromNceImage(0, 0x51);
            gJb3List->mUnk_34->mAttr2 = (gJb3List->mUnk_34->mAttr2 & ~0xc00) | 0xc00;
            break;
    }
    gJb3List->mBgOffsetTask = AddTask(1, WriteJb3ListBgOffset, NULL, 0x6e);
    gJb3List->mIdTimerTask = AddTask(0, AdvanceJb3ListIdTimers, NULL, 0x78);
    RefreshJb3List();
    PlaceJb3ListSelectionPair();
    SetUpdateFunction(StartJb3ListFadeIn);
}

void LoadJb3ListFilesAndSetBgCnt(void) {
    Bytes23 jb3ListBackNscName;
    Bytes21 ybBgStep2NclName;
    Bytes22 ybBgStep21NclName;
    jb3ListBackNscName = gJb3ListBackNscName;
    ybBgStep2NclName = gYbBgStep2NclName;
    ybBgStep21NclName = gYbBgStep21NclName;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0xe18;
    LoadFileToVram(gYbObjKbNclName3, GX_LoadOBJPltt);
    LoadFileToVram(gJbBgStep2NcgName, GX_LoadBG3Char);
    LoadFileToVram(gJbBgStep21NcgName, GX_LoadBG2Char);
    LoadFileToVram(&ybBgStep2NclName, GX_LoadBGPltt);
    LoadFileToVram(gJb3ListNscName, GX_LoadBG3Scr);
    gJb3List->mJb3ListBackNsc = LoadFile(BuildFilePathWithLanguage((u8 *) &jb3ListBackNscName), NULL, 4);
    CreateBg2ScrBuffer(gJb3List->mJb3ListBackNsc);
    RequestBg2ScrUpload();
    gJb3List->mYbBgStep2NclFiles[0] = LoadFile(BuildFilePathWithLanguage((u8 *) &ybBgStep2NclName), NULL, 4);
    gJb3List->mYbBgStep2NclFiles[1] = LoadFile(BuildFilePathWithLanguage((u8 *) &ybBgStep21NclName), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~0x3) | 0x3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~0x3) | 0x3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~0x3) | 0x3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~0x3) | 0x2;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~0x3) | 0x3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~0x3) | 0x2;
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
    if (jb3List->mUnk_45 != 0) {
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
        gJb3List->mUnk_40 = 0xd;
        SetUpdateFunction(StartJb3ListClose);
        return;
    }
    if (AreKeysPressedOrRepeated(0x200) != 0) {
        if (gJb3ListScrollY == 0x91) {
            if (gJb3List->mUnk_47 != 0) {
                return;
            }
            StartSoundSeq(9);
            gJb3List->mUnk_47 = 1;
            return;
        }
        StartSoundSeq(0x13);
        gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
        return;
    }
    if (AreKeysReleased(0x200) != 0) {
        gJb3List->mUnk_47 = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x100) != 0) {
        if (gJb3ListScrollY == 0) {
            if (gJb3List->mUnk_47 != 0) {
                return;
            }
            StartSoundSeq(9);
            gJb3List->mUnk_47 = 1;
            return;
        }
        StartSoundSeq(0x13);
        gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
        return;
    }
    if (AreKeysReleased(0x100) != 0) {
        gJb3List->mUnk_47 = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveJb3ListSelection(1);
        return;
    }
    if (AreKeysReleased(0x40) != 0) {
        gJb3List->mUnk_47 = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveJb3ListSelection(3);
        return;
    }
    if (AreKeysReleased(0x80) != 0) {
        gJb3List->mUnk_47 = 0;
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
    if (hitId == 0xe) {
        return 0;
    }
    idEnabled = IsJb3ListIdEnabled(hitId);
    if (idEnabled == 0) {
        StartSoundSeq(9);
        return 1;
    }
    SetJb3ListSelectedId(hitId);
    switch (hitId) {
        case 2:
        case 3:
        case 7:
        case 8:
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
        case 2:
        case 3:
            StartSoundSeq(6);
            SetJb3ListIpNone(((listId - 2) ^ 1) != 0);
            return;
        case 7:
        case 8:
            StartSoundSeq(6);
            SetJb3ListDnsNone(((listId - 7) ^ 1) != 0);
            return;
    }
    gJb3List->mUnk_40 = listId;
    if (listId - 0xb <= 1) {
        RequestJb3ListPaletteRowCopy();
        if (IsJb3ListRecordValid() == 0) {
            StartSoundSeq(9);
            CreateMessageBox(0x2f, 1, 1, -1, 0);
            SetUpdateFunction(UpdateJb3ListMessageResult);
            return;
        }
        if (listId == 0xb) {
            StartSoundSeq(6);
        } else {
            StartSoundSeq(0xe);
        }
    } else if (listId == 0xd) {
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
            if (gJb3List->mUnk_43 != 0) {
                otherValue = TRUE;
            } else {
                otherValue = FALSE;
            }
        } else {
            gJb3List->mUnk_43 = record->mDnsNone;
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
        gJb3List->mUnk_43 = (s8) newValue;
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
            case 1:
                gJb3List->mUnk_45 = 1;
                break;
            case 2:
                if (gJb3List->mScrollTimer != 0) {
                    return;
                }
                ReleaseSelectionObjectSlots();
                gJb3ListScrollY = _s32_div_f(GetScrollBarOffset() * 0x91, 0x37);
                RefreshJb3List();
                gJb3List->mScrollTimer = 4;
                break;
            case 3:
                gJb3List->mUnk_45 = 0;
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
            case 4:
                if (gJb3ListScrollY == 0) {
                    if (gJb3List->mUnk_46 != 0) {
                        return;
                    }
                    StartSoundSeq(9);
                    gJb3List->mUnk_46 = 1;
                } else {
                    StartSoundSeq(0x13);
                    gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
                }
                break;
            case 6:
                if (gJb3ListScrollY == 0x91) {
                    if (gJb3List->mUnk_46 != 0) {
                        return;
                    }
                    StartSoundSeq(9);
                    gJb3List->mUnk_46 = 1;
                } else {
                    StartSoundSeq(0x13);
                    gJb3List->mScrollTask = AddTask(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
                }
                break;
            case 5:
            case 7:
                gJb3List->mUnk_46 = 0;
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
    *x = (oamEntry->mAttr01 & 0x1ff0000) >> 16;
    *y = oamEntry->mAttr01 & 0xff;
}

void UpdateJb3ListRelease(void) {
    int i;
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
    for (i = 0; i < 7; i++) {
        DeleteOamEntry((u32 *) gJb3List->mUnk_18[i]);
    }
    if (gJb3List->mUnk_34 != NULL) {
        DeleteOamEntry((u32 *) gJb3List->mUnk_34);
    }
    ReleaseScrollBar();
    ReleaseBgTextCanvasOfScreen(0);
    ReleaseSelectionObjectSlots();
    if (gJb3List->mUnk_40 != 0xc) {
        HideSubScreenMessage();
    }
    ReleaseBg2ScrBuffer();
    DeleteLoadedFile(gJb3List->mJb3ListBackNsc);
    for (i = 0; i < 2; i++) {
        DeleteLoadedFile(gJb3List->mYbBgStep2NclFiles[i]);
    }
    LoadFileToVram(gYbObjMainNclName4, GX_LoadOBJPltt);
    ClearDispcntBits(1, 1);
    ClearDispcntBits(0, 0x1d);
    reg_G2_BG0OFS = 0;
    reg_G2_BG2OFS = 0;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0xe10;
    chosenId = gJb3List->mUnk_40;
    switch (chosenId) {
        case 0:
        case 1:
            SetSecondaryMenuPair(chosenId, 0);
            SetPrimaryMenuPair(2, 0);
            SetUpdateFunction(CreateEdit);
            break;
        case 4:
        case 5:
        case 6:
        case 9:
        case 10:
            i = chosenId - 4;
            if (chosenId >= 9) {
                i -= 2;
            }
            SetPrimaryMenuPair(2, 0);
            SetSecondaryMenuPair(i, 0);
            SetUpdateFunction(CreateEditAddr);
            break;
        case 11:
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
        case 12:
            SetPrimaryMenuPair(0, 0);
            SetUpdateFunction(SetupRecordSaved);
            break;
        case 13:
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
    int i;
    int entryIndex;
    firstEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    ClearBgTextCanvas(gJb3List->mUnk_14, 0);
    for (i = 0, entryIndex = firstEntryIndex; i < 5; i++, entryIndex++) {
        PrintJb3ListEntryText(entryIndex, i);
    }
    CopyBg2ScrBufferRect((s32) (gJb3List->mJb3ListBackNsc + gJb3ListBackNscOffsets[firstEntryIndex]), 0, 0x1e, 0x13);
    for (i = 0; i < 5; i++, firstEntryIndex++) {
        SetupJb3ListEntryCells(firstEntryIndex, i);
    }
    RequestBg2ScrUpload();
    RequestBgTextCanvasUpload(gJb3List->mUnk_14);
    RefreshJb3ListRowPositions();
}

void PrintJb3ListEntryText(u32 entryIndex, int row) {
    ApWorkCopy *record;
    int starCount;
    u8 starText[0x21];
    record = GetApWorkCopy();
    switch (entryIndex) {
        case 0:
            PrintJb3ListEntryString(record->mEntry.mSsid, row);
            return;
        case 1:
            switch (record->mEntry.mWepMode) {
                case 0:
                    return;
                case 1:
                    starCount = 10;
                    break;
                case 2:
                    starCount = 0x1a;
                    break;
                case 3:
                    starCount = 0x20;
                    break;
            }
            if (record->mEntry.mWepNotation == 1) {
                starCount = _s32_div_f(starCount, 2);
            }
            MI_CpuFill8(starText, 0, 0x21);
            memset(starText, 0x2a, starCount);
            PrintJb3ListEntryString(starText, row);
            return;
        case 3:
            if (record->mIpNone == 0) {
                PrintJb3ListEntryBytes(record->mEntry.mIp, row);
            }
            break;
        case 4:
            if (record->mIpNone == 0) {
                PrintJb3ListEntryBytes(record->mNetmask, row);
            }
            break;
        case 5:
            if (record->mIpNone == 0) {
                PrintJb3ListEntryBytes(record->mEntry.mGateway, row);
            }
            break;
        case 7:
            if (record->mDnsNone == 0) {
                PrintJb3ListEntryBytes(record->mEntry.mDns, row);
            }
            break;
        case 8:
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
        case 0:
        case 1:
            cellKind = 0;
            cellState = 0;
            if (IsJb3ListIdEnabled(cellKind) == 0) {
                cellState = 2;
            }
            break;
        case 2:
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
        case 3:
        case 4:
        case 5:
            cellKind = 0;
            if (record->mIpNone != 0) {
                cellState = 2;
            } else {
                cellState = cellKind;
            }
            break;
        case 6:
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
        case 7:
        case 8:
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
        case 7:
            if (record->mIpNone == 0) {
                enabled = 0;
            }
            break;
        case 0:
        case 1:
            if ((u8) (record->mEntry.mSetType + 0xff) <= 1) {
                enabled = 0;
            }
            break;
        case 4:
        case 5:
        case 6:
            if (record->mIpNone != 0) {
                enabled = 0;
            }
            break;
        case 9:
        case 10:
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
    cellXPositions[0] = gJb3ListCellRect.mUnk_00;
    secondXPosition = gJb3ListRightButtonRect.mUnk_00;
    cellXPositions[1] = secondXPosition;
    cellXPositions[2] = secondXPosition;
    secondXPosition = gJb3ListLeftButtonRect.mUnk_00;
    cellXPositions[3] = secondXPosition;
    cellXPositions[4] = secondXPosition;
    entryPointer = &gJb3List->mUnk_18[row];
    if ((u32) (cellKind - 1) <= 1) {
        if (GetJb3ListEntryIndexOfRow(row) == 2) {
            entryPointer = &gJb3List->mUnk_18[5];
        } else {
            entryPointer = &gJb3List->mUnk_18[6];
        }
    }
    if (gJb3ListCellImageIds[cellKind][cellState] != 0) {
        CopyNceImageToOamEntries(0, gJb3ListCellImageIds[cellKind][cellState], *entryPointer);
        xBits = (cellXPositions[cellKind] & 0x1ff) << 16;
        (*entryPointer)->mAttr01 = xBits | ((*entryPointer)->mAttr01 & 0xfe00ff00);
        (*entryPointer)->mAttr2 = ((*entryPointer)->mAttr2 & ~0xc00) | 0xc00;
    } else {
        (*entryPointer)->mAttr01 = ((*entryPointer)->mAttr01 & 0xfe00ff00) | 0x1000000;
    }
}

void PrintJb3ListEntryString(const u8 *bytes, int row) {
    u16 text[17];
    int length;
    int shownLength;
    int character;
    int i;
    int yPosition;
    int secondLineLength;
    MI_CpuFill8(text, 0, 0x22);
    length = GetStringLengthWithLimit(bytes, 0x20);
    if (length <= 0x10) {
        shownLength = length;
    } else {
        shownLength = 0x10;
    }
    for (i = 0; i < shownLength; i++) {
        character = bytes[i];
        if (character == 0x20) {
            text[i] = 0xe01d;
        } else {
            text[i] = character;
        }
    }
    yPosition = row * 0x1d + 2;
    if (length <= 0x10) {
        yPosition += 5;
    }
    DrawCharsCentered(gJb3List->mUnk_14, 0x48, yPosition, 2, 8, text, 1);
    if (length > 0x10) {
        MI_CpuFill8(text, 0, 0x22);
        secondLineLength = length - 0x10;
        for (i = 0; i < secondLineLength; i++) {
            character = bytes[i + 0x10];
            if (character == 0x20) {
                text[i] = 0xe01d;
            } else {
                text[i] = character;
            }
        }
        DrawCharsCentered(gJb3List->mUnk_14, 0x48, yPosition + 0xc, 2, 8, text, 1);
    }
}

void PrintJb3ListEntryBytes(const u8 *bytes, int row) {
    u16 text[16];
    swprintf(text, 0x10, gDotSeparatedBytesFormat, bytes[0], bytes[1], bytes[2], bytes[3]);
    DrawCharsCentered(gJb3List->mUnk_14, 0x5f, row * 0x1d + 8, 2, 7, text, 1);
}

void RefreshJb3ListRowPositions(void) {
    int firstEntryIndex;
    int firstRowY;
    OamEntry *oamEntry;
    int rowY;
    int i;
    u32 xPosition;
    u32 yPosition;
    firstEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    firstRowY = 0x34 - FX_ModS32(gJb3ListScrollY, 0x1d);
    if (gJb3List->mUnk_34 != NULL) {
        if (firstEntryIndex == 0) {
            xPosition = 0x26;
        } else {
            xPosition = 0x100;
        }
        gJb3List->mUnk_34->mAttr01 =
            ((xPosition & 0x1ff) << 16) | ((gJb3List->mUnk_34->mAttr01 & 0xfe00ff00) | (firstRowY & 0xff));
    }
    for (i = 0, rowY = firstRowY; i < 5; i++, rowY += 0x1d) {
        Jb3ListG2_GetOBJPosition(gJb3List->mUnk_18[i], (u32 *) &xPosition, &yPosition);
        oamEntry = gJb3List->mUnk_18[i];
        oamEntry->mAttr01 = ((xPosition & 0x1ff) << 16) | ((oamEntry->mAttr01 & 0xfe00ff00) | (rowY & 0xff));
    }
    if (firstEntryIndex <= 2) {
        Jb3ListG2_GetOBJPosition(gJb3List->mUnk_18[5], &xPosition, (u32 *) &yPosition);
        gJb3List->mUnk_18[5]->mAttr01 =
            ((xPosition & 0x1ff) << 16) |
            ((gJb3List->mUnk_18[5]->mAttr01 & 0xfe00ff00) | ((firstRowY + (2 - firstEntryIndex) * 0x1d) & 0xff));
    } else {
        gJb3List->mUnk_18[5]->mAttr01 = (gJb3List->mUnk_18[5]->mAttr01 & 0xfe00ff00) | 0x1000000;
    }
    if (firstEntryIndex >= 2 && firstEntryIndex <= 6) {
        Jb3ListG2_GetOBJPosition(gJb3List->mUnk_18[6], &xPosition, (u32 *) &yPosition);
        gJb3List->mUnk_18[6]->mAttr01 =
            ((xPosition & 0x1ff) << 16) |
            ((gJb3List->mUnk_18[6]->mAttr01 & 0xfe00ff00) | ((firstRowY + (6 - firstEntryIndex) * 0x1d) & 0xff));
    } else {
        gJb3List->mUnk_18[6]->mAttr01 = (gJb3List->mUnk_18[6]->mAttr01 & 0xfe00ff00) | 0x1000000;
    }
    gJb3List->mBgOffsetPending = 1;
}

u32 GetJb3ListHitId(void) {
    Rect cellRect;
    Rect *cellRectPointer;
    s32 firstEntryIndex;
    s32 rowIndex;
    s32 searchEntryIndex;
    Rect *fixedRect;
    if (IsTouchPressedInRect(&gTouchScreenRect) == 0) {
        return 0xe;
    }
    firstEntryIndex = FX_DivS32(gJb3ListScrollY, 0x1d);
    cellRectPointer = &cellRect;
    cellRect = gJb3ListCellRect;
    for (rowIndex = 0; rowIndex < 4; rowIndex++, firstEntryIndex++, cellRect.mUnk_02 += 0x1d) {
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
            cellRect.mUnk_02 = cellRect.mUnk_02 + rowIndex;
            if (IsTouchPressedInOriginSizeRect(&cellRect) != 0) {
                return 2;
            }
            cellRect = gJb3ListLeftButtonRect;
            cellRect.mUnk_02 = cellRect.mUnk_02 + rowIndex;
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
            cellRect.mUnk_02 = cellRect.mUnk_02 + rowIndex;
            if (IsTouchPressedInOriginSizeRect(&cellRect) != 0) {
                return 7;
            }
            cellRect = gJb3ListLeftButtonRect;
            cellRect.mUnk_02 = cellRect.mUnk_02 + rowIndex;
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
            return rowIndex + 0xb;
        }
        fixedRect++;
    }
    return 0xe;
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

void AdvanceJb3ListScrollYDecrease(u32 taskEntry) {
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

void AdvanceJb3ListScrollYIncrease(u32 taskEntry) {
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

void WriteJb3ListBgOffset(void) {
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
    rectIndex = selectionRectIndices.mUnk_00[gJb3ListSelectedId];
    if (rectIndex >= 3) {
        PlaceSelectionPair(3, gJb3ListSelectionRects[rectIndex].mUnk_00, gJb3ListSelectionRects[rectIndex].mUnk_04,
                           gJb3ListSelectionRects[rectIndex].mUnk_02);
        return;
    }
    selectionRect = gJb3ListSelectionRects[rectIndex];
    selectionRect.mUnk_02 = selectionRect.mUnk_02 + gJb3ListSelectedRow * 0x1d;
    PlaceSelectionPair(1, selectionRect.mUnk_00, selectionRect.mUnk_04, selectionRect.mUnk_02);
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
        case 2:
            if (record->mIpNone != 0) {
                gJb3ListSelectedId = 2;
            } else {
                gJb3ListSelectedId = 3;
            }
            break;
        case 6:
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
    if (selectedId == 8 && record->mIpNone == 0) {
        if (direction == 0) {
            return;
        }
        if (direction == 2) {
            return;
        }
    }
    switch (selectedId) {
        case 0:
            if (direction == 1) {
                gJb3ListSelectedId = 0xb;
            } else if (direction == 3) {
                gJb3ListSelectedRow = gJb3ListSelectedRow + 1;
            } else {
                moveResult = 2;
            }
            break;
        case 0xa:
            if (direction == 1) {
                gJb3ListSelectedRow = gJb3ListSelectedRow - 1;
            } else if (direction == 3) {
                gJb3ListSelectedId = gJb3List->mReturnId;
            } else {
                moveResult = 2;
            }
            break;
        case 0xb:
            if (direction == 1) {
                if (gJb3List->mUnk_47 != 0) {
                    return;
                }
                StartSoundSeq(9);
                gJb3List->mUnk_47 = 1;
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
        case 0xc:
        case 0xd:
            gJb3List->mReturnId = selectedId;
            if (direction == 1) {
                gJb3ListSelectedId = 0xa;
                gJb3ListSelectedRow = 3;
                gJb3ListScrollY = 0x91;
                RefreshJb3List();
                PlaceScrollBarWrapper(0x37);
            } else if (direction == 3) {
                if (gJb3List->mUnk_47 != 0) {
                    return;
                }
                StartSoundSeq(9);
                gJb3List->mUnk_47 = 1;
                return;
            } else if (selectedId == 0xc) {
                gJb3ListSelectedId = 0xd;
            } else {
                gJb3ListSelectedId = 0xc;
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
    paletteRow = gJb3ListPaletteRows[gJb3ListSelectedId - 0xb];
    RequestBgPaletteRowCopy(gJb3List->mYbBgStep2NclFiles[1], paletteRow, paletteRow);
}

void AdvanceJb3ListIdTimers(void) {
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
            gJb3List->mIdTimer[timerIndex] = 0x14;
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
        RequestBgPaletteCopy((u32) gJb3List->mYbBgStep2NclFiles[0]);
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
