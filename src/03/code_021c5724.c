#include "03/code_021c5724.h"

#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/SelectionObjects.h"
#include "03/code_021cca74.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3000.h"
#include "03/Tasks.h"
#include "registers.h"
#include "code_02147cd8.h"
#include "03/code_021d3254.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02147000.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cbf60.h"
#include "03/code_021cef90.h"
#include "03/DwcArchive.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d6000.h"
#include "03/code_021c6000.h"
#include "03/code_021c2000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021c209c.h"
#include "03/code_021cb000.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cd000.h"
#include "03/code_021cd0d0.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "03/TextCanvas.h"
#include "03/ExpHeap.h"
#include "03/code_021bf000.h"
#include "03/code_021c5000.h"
#include "03/code_021ce000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c5548.h"
#include "03/Input.h"
#include "03/HlScr.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214cfe4.h"
#include "03/code_021d1c18.h"
#include "03/code_021c6764.h"
#include "03/code_021ca56c.h"
#include "03/code_021cce78.h"

void CreateApList(void) {
    s32 a;
    gApList = AllocZeroedExpHeapBlock(0x5c, 4);
    func_ov003_021c20dc(&a, NULL);
    if (a == 0) {
        gApListSelectedRow = 0;
        *(u16 *) &gApListScrollY = 0;
    }
    gApList->mEntryCount = func_ov003_021cd0d0((s32 *) gApList);
    LoadApListFilesAndSetBgCnt();
    LoadHlSetScr();
    func_ov003_021bf43c(0x80, -1, 0);
    func_ov003_021bf5ec(2);
    func_ov003_021c6508();
    func_ov003_021c6400();
    gApList->fieldC = InitBgTextCanvas(0, 0);
    gApList->mBgOffsetTask = AddTask(1, WriteApListBgOffset, NULL, 0x6e);
    RefreshApList();
    func_ov003_021c590c();
    SetUpdateFunction(func_ov003_021c63c4);
}

void LoadApListFilesAndSetBgCnt(void) {
    u8 a[0x19] = "char/xb4ApListBack.nsc.l";
    u8 b[0x16] = "char/ybBgStep31.ncl.l";
    LoadFileToVram(gJb4ApListNscName, GX_LoadBG3Scr);
    gApList->mXb4ApListBackNsc = LoadFile(BuildFilePathWithLanguage(a), NULL, 4);
    func_ov003_021cca30(gApList->mXb4ApListBackNsc);
    func_ov003_021cc9fc();
    gApList->mYbBgStep31Ncl = LoadFile(BuildFilePathWithLanguage(b), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 2;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 2;
}

void func_ov003_021c6508(void) {
    int a;
    u32 b;
    b = 0;
    gApList->mScrollYMax = (gApList->mEntryCount - 4) * 0x1c;
    if (gApList->mEntryCount <= 4) {
        a = 0;
        gApList->field53 = 0;
    } else if (gApList->mEntryCount <= 8) {
        a = 1;
        gApList->field53 = 0x1f;
    } else {
        a = 2;
        gApList->field53 = 0x37;
    }
    if (a != 0) {
        b = FX_DivS32(*(u16 *) &gApListScrollY * gApList->field53, gApList->mScrollYMax);
    }
    func_ov003_021ccea4(a, 0x55, 0xec, 0x3f, b);
}

void func_ov003_021c6400(void) {
    int n;
    int i;
    u32 j;
    n = gApList->mEntryCount;
    if (n > 5) {
        n = 5;
    }
    for (i = 0; i < n; i++) {
        gApList->field10[i] = CreateOamEntryFromNceImage(0, data_ov003_021d6388[0]);
        gApList->field24[i] = CreateOamEntryFromNceImage(0, data_ov003_021d638c[0]);
    }
    for (j = 0; j < 3; j++) {
        CopyNceImageToOamEntries(0, data_ov003_021d6388[j], gApList->field10[0]);
        gApList->field42[j] = gApList->field10[0]->field4 & 0x3ff;
    }
    for (j = 0; j < 4; j++) {
        CopyNceImageToOamEntries(0, data_ov003_021d638c[j], gApList->field24[0]);
        gApList->field48[j] = gApList->field24[0]->field4 & 0x3ff;
    }
    for (i = 0; i < n; i++) {
        OamEntry *q;
        q = gApList->field10[i];
        q->field4 = (q->field4 & 0xfffff3ff) | 0xc00;
        q = gApList->field24[i];
        q->field4 = (q->field4 & 0xfffff3ff) | 0xc00;
    }
}

void func_ov003_021c63c4(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x1d, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x1d);
    SetUpdateFunction(func_ov003_021c6394);
}

void func_ov003_021c6394(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if ((v1 == 0) && (v1 = IsBlendBrightnessFadeSlotBusy(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        SetUpdateFunction(func_ov003_021c6370);
    }
}

void func_ov003_021c6370(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateApList);
    }
}

void UpdateApList(void) {
    func_ov003_021c6184();
    func_ov003_021c5f9c();
    func_ov003_021c5ec4();
}

void func_ov003_021c6184(void) {
    int i;
    Rect *p;
    if (gApList->mScrollTask != 0) {
        return;
    }
    if (gApList->field57 != 0) {
        return;
    }
    if (IsTouchPressedInRect(&data_ov003_021d67e8) != 0) {
        i = 0;
        gApList->mHitRow = -1;
        p = gApListRowRects;
        do {
            if (IsTouchPressedInRect(p) != 0) {
                if (i < 4) {
                    gApList->mHitRow = i;
                    break;
                }
                SetButtonResultIfNone(1);
                gApListSelectedRow = i;
                func_ov003_021c590c();
                return;
            }
            p++;
            i++;
        } while ((u32) i < 5);
    }
    if (IsTouchReleasedInRect(&data_ov003_021d67e8) != 0) {
        i = 0;
        p = gApListRowRects;
        do {
            if (IsTouchReleasedInRect(p) != 0) {
                if (gApList->mHitRow != i) {
                    break;
                }
                if (i >= gApList->mEntryCount) {
                    StartSoundSeq(9);
                    break;
                }
                SetButtonResultIfNone(1);
                gApListSelectedRow = i;
                func_ov003_021c590c();
                return;
            }
            p++;
            i++;
        } while (i < 4);
    }
    if (AreKeysPressed(1) != 0) {
        SetButtonResultIfNone(1);
        func_ov003_021cce38();
        return;
    }
    if (AreKeysPressed(2) != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    if (AreKeysPressedOrRepeated(0x200) != 0) {
        StartApListScrollYIncrease();
        return;
    }
    if (AreKeysReleased(0x200) != 0) {
        gApList->field59 = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x100) != 0) {
        StartApListScrollYDecrease();
        return;
    }
    if (AreKeysReleased(0x100) != 0) {
        gApList->field59 = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveApListSelectedRow(1);
        return;
    }
    if (AreKeysReleased(0x40) != 0) {
        gApList->field59 = 0;
        return;
    }
    if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveApListSelectedRow(3);
        return;
    }
    if (AreKeysReleased(0x80) != 0) {
        gApList->field59 = 0;
    }
}

void func_ov003_021c5f9c(void) {
    ApList *s;
    int a;
    s = gApList;
    if (s->mScrollTask != 0) {
        return;
    }
    if (s->mScrollTimer != 0) {
        s->mScrollTimer--;
    }
    switch (func_ov003_021cce60()) {
        case 1:
            gApList->field57 = 1;
            DisableButtonTouch();
            break;
        case 2:
            if (gApList->mScrollTimer == 0) {
                ReleaseSelectionObjectSlots();
                *(u16 *) &gApListScrollY = FX_DivS32(gApList->mScrollYMax * func_ov003_021cce6c(), gApList->field53);
                RefreshApList();
                gApList->mScrollTimer = 4;
            }
            break;
        case 3:
            gApList->field57 = 0;
            EnableButtonTouch();
            *(u16 *) &gApListScrollY = FX_DivS32(gApList->mScrollYMax * func_ov003_021cce6c(), gApList->field53);
            StartSoundSeq(0x13);
            RefreshApList();
            a = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
            if (a == 0) {
                func_ov003_021c590c();
            } else if (a < 0xe) {
                gApList->mScrollTask = AddTask(0, AdvanceApListScrollYDecrease, NULL, 0x78);
            } else {
                gApList->mScrollTask = AddTask(0, AdvanceApListScrollYIncrease, NULL, 0x78);
            }
            break;
        case 4:
            if (*(u16 *) &gApListScrollY == 0) {
                if (gApList->field58 == 0) {
                    StartSoundSeq(9);
                    gApList->field58 = 1;
                }
            } else {
                StartSoundSeq(0x13);
                gApList->mScrollTask = AddTask(0, AdvanceApListScrollYDecrease, NULL, 0x78);
            }
            break;
        case 6:
            s = gApList;
            if (s->mEntryCount <= 4 || *(u16 *) &gApListScrollY == s->mScrollYMax) {
                if (s->field58 == 0) {
                    StartSoundSeq(9);
                    gApList->field58 = 1;
                }
            } else {
                StartSoundSeq(0x13);
                gApList->mScrollTask = AddTask(0, AdvanceApListScrollYIncrease, NULL, 0x78);
            }
            break;
        case 5:
        case 7:
            gApList->field58 = 0;
            break;
    }
}

void func_ov003_021c5ec4(void) {
    int b;
    if (gApList->mScrollTask == 0 && gApList->field57 == 0) {
        switch (GetButtonResult()) {
            case 0:
                StartSoundSeq(7);
                break;
            case 1:
                if (gApListSelectedRow == 4) {
                    gApList->field54 = 1;
                    StartSoundSeq(6);
                    func_ov003_021c5724();
                } else {
                    b = gApListSelectedRow + FX_DivS32(*(u16 *) &gApListScrollY, 0x1c);
                    if ((gApList->mEntries + b * 0x2a)[0x28] == 2) {
                        StartSoundSeq(9);
                        func_ov003_021cce38();
                        DisableButtonTouch();
                        func_ov003_021cefc0(0x42, 1, 1, -1, 0);
                        SetUpdateFunction(func_ov003_021c56fc);
                        return;
                    }
                    gApList->field54 = 1;
                    gApList->mEntryIndex = b;
                    StartSoundSeq(6);
                }
                break;
            default:
                return;
        }
        SetUpdateFunction(func_ov003_021c5ea4);
    }
}

void func_ov003_021c5ea4(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(func_ov003_021c5e54);
}

void func_ov003_021c5e54(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0) {
        if (gApList->field54 != 0) {
            StartSlideButtonsOut();
        } else {
            DisableButtonTouch();
        }
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x1d, 8);
        SetUpdateFunction(func_ov003_021c5cdc);
    }
}

void func_ov003_021c5cdc(void) {
    int i;
    ApList *s;
    if (IsBlendBrightnessFadeSlotBusy(1) != 0) {
        return;
    }
    if (IsBlendBrightnessFadeSlotBusy(0) != 0) {
        return;
    }
    if (func_ov003_021bf2f0() == 0) {
        return;
    }
    RemoveTaskEntryWrapper(1, gApList->mBgOffsetTask);
    for (i = 0; i < 5; i++) {
        if (gApList->field10[i] != NULL) {
            DeleteOamEntry((u32 *) gApList->field10[i]);
        }
        if (gApList->field24[i] != NULL) {
            DeleteOamEntry((u32 *) gApList->field24[i]);
        }
    }
    ReleaseBgTextCanvas(gApList->fieldC);
    func_ov003_021cce78();
    ReleaseSelectionObjectSlots();
    func_ov003_021bf410();
    func_ov003_021cca10();
    DeleteLoadedFile(gApList->mXb4ApListBackNsc);
    DeleteLoadedFile(gApList->mYbBgStep31Ncl);
    ClearDispcntBits(1, 1);
    ClearDispcntBits(0, 0x1d);
    reg_G2_BG0OFS = 0;
    reg_G2_BG2OFS = 0;
    s = gApList;
    if (s->field54 == 0) {
        func_ov003_021cd27c();
        func_ov003_021cd790(func_ov003_021cdb6c()->fieldF4);
        func_ov003_021c2120(2, 0);
        SetUpdateFunction(SetupWay);
    } else if (gApListSelectedRow == 4) {
        func_ov003_021cd27c();
        func_ov003_021c2120(0, 1);
        SetUpdateFunction(func_ov003_021ca8e8);
    } else {
        func_ov003_021cdb14(s->mEntries + s->mEntryIndex * 0x2a);
        func_ov003_021c2120(0, 0);
        if ((gApList->mEntries + gApList->mEntryIndex * 0x2a)[0x28] != 0) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c20f8(1, 1);
            SetUpdateFunction(CreateEdit);
        } else {
            func_ov003_021c2120(0, 1);
            func_ov003_021c20f8(0, 1);
            SetUpdateFunction(func_ov003_021cbf60);
        }
    }
    FreeExpHeapBlockAndClearPointer(&gApList);
}

void RefreshApList(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    v1 = FX_DivS32(*(u16 *) &gApListScrollY, 0x1c);
    v4 = gApList->mEntryCount;
    ClearBgTextCanvas(gApList->fieldC, 0);
    if (5 < v4) {
        v4 = 5;
    }
    v2 = 0;
    v3 = v1;
    if (v4 > 0) {
        do {
            PrintApListEntryText(v3, v2);
            v2 = v2 + 1;
            v3 = v3 + 1;
        } while (v2 < v4);
    }
    v3 = 0;
    if (v4 > 0) {
        do {
            func_ov003_021c5b34(v1, v3);
            v3 = v3 + 1;
            v1 = v1 + 1;
        } while (v3 < v4);
    }
    RequestBgTextCanvasUpload(gApList->fieldC);
    RefreshApListRowPositions();
}

void PrintApListEntryText(int param_0, int param_1) {
    u16 a[17];
    int b;
    int c;
    int i;
    int n;
    c = param_0 * 0x2a;
    b = GetStringLengthWithLimit(gApList->mEntries + c, 0x20);
    param_1 *= 0x1c;
    if (param_0 < gApList->mEntryCount) {
        if (b <= 0x10) {
            param_1 += 6;
        }
        MI_CpuFill8(a, 0, 0x22);
        if (b <= 0x10) {
            n = b;
        } else {
            n = 0x10;
        }
        for (i = 0; i < n; i++) {
            a[i] = (gApList->mEntries + c)[i];
        }
        DrawCharsCentered(gApList->fieldC, 0xa, param_1, 2, 0xa, a, 1);
        if (b > 0x10) {
            MI_CpuFill8(a, 0, 0x22);
            n = b - 0x10;
            for (i = 0; i < n; i++) {
                a[i] = (gApList->mEntries + c)[i + 0x10];
            }
            param_1 += 0xc;
            DrawCharsCentered(gApList->fieldC, 0xa, param_1, 2, 0xa, a, 1);
        }
    }
}

void func_ov003_021c5b34(int param_0, int param_1) {
    OamEntry *p;
    int m;
    if (param_0 < gApList->mEntryCount) {
        p = gApList->field10[param_1];
        m = param_0 * 0x2a;
        p->field4 = (p->field4 & ~0x3ff) | gApList->field42[*(gApList->mEntries + m + 0x28)];
        p = gApList->field24[param_1];
        p->field4 = (p->field4 & ~0x3ff) | gApList->field48[*(u16 *) (gApList->mEntries + m + 0x26)];
    }
}

void RefreshApListRowPositions(void) {
    int a;
    int b;
    int i;
    a = 0x36 - FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
    b = gApList->mEntryCount;
    if (b > 5) {
        b = 5;
    }
    for (i = 0; i < b; i++, a += 0x1c) {
        OamEntry *p;
        p = gApList->field10[i];
        p->field0 = (p->field0 & 0xfe00ff00) | ((a - 2) & 0xff) | 0xb30000;
        p = gApList->field24[i];
        p->field0 = (p->field0 & 0xfe00ff00) | ((a + 1) & 0xff) | 0xd20000;
    }
    gApList->mBgOffsetPending = 1;
}

void AdvanceApListScrollYDecrease(u32 param_0) {
    int a;
    func_ov003_021cce38();
    ReleaseSelectionObjectSlots();
    if (*(u16 *) &gApListScrollY > 4) {
        *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY - 4;
    } else {
        *(u16 *) &gApListScrollY = 0;
    }
    a = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
    if (a == 0x18) {
        RefreshApList();
        return;
    }
    if (a > 0x18) {
        *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY + (0x1c - a);
        a = 0;
    }
    RefreshApListRowPositions();
    if (a == 0) {
        func_ov003_021cce58(FX_DivS32(*(u16 *) &gApListScrollY * gApList->field53, gApList->mScrollYMax));
        func_ov003_021cce48();
        func_ov003_021c590c();
        gApList->mScrollTask = 0;
        RequestTaskRemoval(0, param_0);
    }
}

void AdvanceApListScrollYIncrease(u32 param_0) {
    int a;
    func_ov003_021cce38();
    ReleaseSelectionObjectSlots();
    *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY + 4;
    a = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
    if (a >= 4) {
        RefreshApListRowPositions();
        return;
    }
    *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY - a;
    RefreshApList();
    func_ov003_021cce58(FX_DivS32(*(u16 *) &gApListScrollY * gApList->field53, gApList->mScrollYMax));
    func_ov003_021cce48();
    func_ov003_021c590c();
    gApList->mScrollTask = 0;
    RequestTaskRemoval(0, param_0);
}

void WriteApListBgOffset(void) {
    int v1;
    u32 v2;
    if (gApList->mBgOffsetPending != 0) {
        v1 = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
        v2 = (v1 + -0x32) * 0x10000 & (0x01ff0000u);
        reg_G2_BG0OFS = v2;
        reg_G2_BG2OFS = v2;
        gApList->mBgOffsetPending = 0;
    }
}

void func_ov003_021c590c(void) {
    u8 a;
    int b;
    a = gApListSelectedRow;
    if (a < 4) {
        b = 2;
    } else {
        b = 3;
    }
    PlaceSelectionPair(b, data_ov003_021d63b8[a * 4], data_ov003_021d63bc[a * 4], data_ov003_021d63ba[a * 4]);
}

void MoveApListSelectedRow(int param_0) {
    BOOL a;
    u8 v;
    a = TRUE;
    v = gApListSelectedRow;
    switch (v) {
        case 0:
            if (param_0 == 1) {
                if (*(u16 *) &gApListScrollY == 0) {
                    gApListSelectedRow = 4;
                } else {
                    StartSoundSeq(0x13);
                    gApList->mScrollTask = AddTask(0, AdvanceApListScrollYDecrease, NULL, 0x78);
                    return;
                }
            } else if (gApList->mEntryCount > 1) {
                gApListSelectedRow = v + 1;
            } else {
                a = FALSE;
            }
            break;
        case 1:
        case 2:
            if (param_0 == 1) {
                gApListSelectedRow = v - 1;
            } else if (gApList->mEntryCount > v + 1) {
                gApListSelectedRow++;
            } else {
                a = FALSE;
            }
            break;
        case 3:
            if (param_0 == 1) {
                gApListSelectedRow = v - 1;
            } else {
                StartApListScrollYIncrease();
                return;
            }
            break;
        case 4:
            if (param_0 == 1) {
                a = FALSE;
            } else {
                *(u16 *) &gApListScrollY = 0;
                gApListSelectedRow = 0;
                RefreshApList();
                func_ov003_021cce58(0);
            }
            break;
    }
    if (a == FALSE) {
        if (gApList->field59 == 0) {
            StartSoundSeq(9);
            gApList->field59 = 1;
        }
    } else {
        StartSoundSeq(8);
        func_ov003_021c590c();
    }
}

void StartApListScrollYDecrease(void) {
    if (*(u16 *) &gApListScrollY == 0) {
        if (gApList->field59 == 0) {
            StartSoundSeq(9);
            gApList->field59 = 1;
        }
    } else {
        StartSoundSeq(0x13);
        gApList->mScrollTask = AddTask(0, AdvanceApListScrollYDecrease, NULL, 0x78);
    }
}

void StartApListScrollYIncrease(void) {
    if (*(u16 *) &gApListScrollY == gApList->mScrollYMax || gApList->mEntryCount <= 4) {
        if (gApList->field59 == 0) {
            StartSoundSeq(9);
            gApList->field59 = 1;
        }
    } else {
        StartSoundSeq(0x13);
        gApList->mScrollTask = AddTask(0, AdvanceApListScrollYIncrease, NULL, 0x78);
    }
}

// placeholder: the original keeps the byte at a stack offset between its load and the call; the volatile
// local reproduces that.
void func_ov003_021c5724(void) {
    volatile u8 a;
    u8 b;
    a = data_ov003_021d7228[0];
    b = a;
    func_ov003_021cc948(gApList->mYbBgStep31Ncl, b, b);
}
