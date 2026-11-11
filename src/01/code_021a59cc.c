#include "01/code_021a59cc.h"
#include "01/code_02184f7c.h"

#include "types.h"
#include "01/code_021a5140.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02180ce8.h"
#include "01/code_02180cb4.h"
#include "01/unk_021ca000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a7000.h"
#include "code_0212df7c.h"

EmblemCursor *gEmblemCursor;

void ClampEmblemCursorCell(void) {
    s32 lo = 0;
    s32 hi = gEmblemCursor->mSide - 1;

    switch (gEmblemCursor->mSizeIndex) {
        case 1:
            hi -= 1;
            break;
        case 2:
            lo += 1;
            hi -= 1;
            break;
    }
    gEmblemCursor->mCellX = (gEmblemCursor->mCellX > lo) ? gEmblemCursor->mCellX : lo;
    gEmblemCursor->mCellX = (gEmblemCursor->mCellX < hi) ? gEmblemCursor->mCellX : hi;
    gEmblemCursor->mCellY = (gEmblemCursor->mCellY > lo) ? gEmblemCursor->mCellY : lo;
    gEmblemCursor->mCellY = (gEmblemCursor->mCellY < hi) ? gEmblemCursor->mCellY : hi;
}

void SetEmblemCursorCellShift(s32 shift) {
    gEmblemCursor->mCellShift = shift;
}

void SetEmblemCursorCellValue(u8 cellValue) {
    gEmblemCursor->mCellValue = cellValue;
}

u8 GetEmblemCursorCellValue(void) {
    return gEmblemCursor->mCellValue;
}

void SetEmblemCursorMode(s32 mode) {
    gEmblemCursor->mMode = mode;
}

s32 GetEmblemCursorMode(void) {
    return gEmblemCursor->mMode;
}

void SetEmblemCursorSizeIndex(s32 sizeIndex) {
    gEmblemCursor->mSizeIndex = sizeIndex;
    ClampEmblemCursorCell();
}

s32 GetEmblemCursorSizeIndex(void) {
    return gEmblemCursor->mSizeIndex;
}

void SetEmblemCursorCellFromPoint(s32 x, s32 y) {
    gEmblemCursor->mCellX = (x - gEmblemCursor->mOriginX) >> gEmblemCursor->mCellShift;
    gEmblemCursor->mCellY = (y - gEmblemCursor->mOriginY) >> gEmblemCursor->mCellShift;
    ClampEmblemCursorCell();
}

s32 GetEmblemCursorPointX(void) {
    return gEmblemCursor->mOriginX + (gEmblemCursor->mCellX << gEmblemCursor->mCellShift);
}

s32 GetEmblemCursorPointY(void) {
    return gEmblemCursor->mOriginY + (gEmblemCursor->mCellY << gEmblemCursor->mCellShift);
}

s32 GetEmblemCursorPrevPointX(void) {
    return gEmblemCursor->mOriginX + (gEmblemCursor->mPrevCellX << gEmblemCursor->mCellShift);
}

s32 GetEmblemCursorPrevPointY(void) {
    return gEmblemCursor->mOriginY + (gEmblemCursor->mPrevCellY << gEmblemCursor->mCellShift);
}

BOOL IsEmblemPointInGrid(s32 x, s32 y) {
    s32 px = (x - gEmblemCursor->mOriginX) >> gEmblemCursor->mCellShift;
    s32 py = (y - gEmblemCursor->mOriginY) >> gEmblemCursor->mCellShift;

    if (px >= 0 && px < gEmblemCursor->mSide && py >= 0 && py < gEmblemCursor->mSide) {
        return TRUE;
    }
    return FALSE;
}

s32 FillEmblemGridAtCursorCell(void) {
    return FillEmblemGridRegion(gEmblemCursor->mCellX, gEmblemCursor->mCellY, gEmblemCursor->mCellValue);
}

BOOL SetEmblemCursorCellValueFromGrid(void) {
    u8 gridCellValue = GetEmblemGridCellValue(gEmblemCursor->mCellX, gEmblemCursor->mCellY);

    if (gridCellValue != 0 && gridCellValue != gEmblemCursor->mCellValue) {
        gEmblemCursor->mCellValue = gridCellValue;
        return TRUE;
    }
    return FALSE;
}

void CreateEmblemCursorAndGrid(s32 originX, s32 originY, s32 side, s32 scrSide, s32 tableCount) {
    gEmblemCursor = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    gEmblemCursor->mOriginX = originX;
    gEmblemCursor->mOriginY = originY;
    gEmblemCursor->mSide = side;
    CreateEmblemGrid(side, scrSide, tableCount);
}

s32 AdvanceEmblemCursor(s32 down, s32 x, s32 y, s32 d, s32 dx, s32 dy) {
    s32 result;
    s32 i;
    s32 j;
    u8 writeValue;
    s32 saveX;
    s32 saveY;
    s32 prevPointFixedX;
    s32 prevPointFixedY;
    s32 pointFixedX;
    s32 pointFixedY;
    s32 prevPointCellX;
    s32 prevPointCellY;
    s32 pointCellX;
    s32 pointCellY;
    s32 originX;
    s32 originY;
    s32 cellShift;
    BOOL prevInGrid;
    BOOL pointInGrid;

    saveX = gEmblemCursor->mCellX;
    saveY = gEmblemCursor->mCellY;
    originX = gEmblemCursor->mOriginX;
    cellShift = gEmblemCursor->mCellShift;
    prevPointFixedX = (gEmblemCursor->mPrevX - originX) << 12;
    prevPointFixedX >>= cellShift;
    originY = gEmblemCursor->mOriginY;
    prevPointFixedY = (gEmblemCursor->mPrevY - originY) << 12;
    prevPointFixedY >>= cellShift;
    pointFixedX = (x - originX) << 12;
    pointFixedX >>= cellShift;
    pointFixedY = (y - originY) << 12;
    pointFixedY >>= cellShift;
    prevPointCellX = prevPointFixedX >> 12;
    prevPointCellY = prevPointFixedY >> 12;
    pointCellX = pointFixedX >> 12;
    pointCellY = pointFixedY >> 12;
    prevInGrid = FALSE;
    if (prevPointCellX >= 0 && prevPointCellX < gEmblemCursor->mSide && prevPointCellY >= 0 &&
        prevPointCellY < gEmblemCursor->mSide) {
        prevInGrid = TRUE;
    }
    pointInGrid = FALSE;
    if (pointCellX >= 0 && pointCellX < gEmblemCursor->mSide && pointCellY >= 0 && pointCellY < gEmblemCursor->mSide) {
        pointInGrid = TRUE;
    }
    result = 0;
    gEmblemCursor->mCellX += dx;
    gEmblemCursor->mCellY += dy;
    if ((gEmblemCursor->mPrevDown != 0 && prevInGrid != FALSE) || (down != 0 && pointInGrid != FALSE)) {
        if (gEmblemCursor->mMode == 1) {
            writeValue = 0;
        } else {
            writeValue = gEmblemCursor->mCellValue;
        }
        gEmblemCursor->mCellX = pointCellX;
        gEmblemCursor->mCellY = pointCellY;
        switch (gEmblemCursor->mMode) {
            case 0:
            case 1:
                if (gEmblemCursor->mPrevDown != 0) {
                    switch (gEmblemCursor->mSizeIndex) {
                        case 0:
                            if (SetEmblemGridLine(prevPointFixedX, prevPointFixedY, pointFixedX, pointFixedY,
                                                  writeValue) != 0) {
                                result = 1;
                            } else {
                                result = 0;
                            }
                            break;
                        case 1:
                            for (i = 0; i < 0x2000; i += 0x1000) {
                                for (j = 0; j < 0x2000; j += 0x1000) {
                                    if (SetEmblemGridLine(prevPointFixedX + i, prevPointFixedY + j, pointFixedX + i,
                                                          pointFixedY + j, writeValue) != 0) {
                                        result = 1;
                                    }
                                }
                            }
                            break;
                        case 2:
                            for (i = -0x1000; i < 0x2000; i += 0x1000) {
                                for (j = -0x1000; j < 0x2000; j += 0x1000) {
                                    if (SetEmblemGridLine(prevPointFixedX + i, prevPointFixedY + j, pointFixedX + i,
                                                          pointFixedY + j, writeValue) != 0) {
                                        result = 1;
                                    }
                                }
                            }
                            break;
                    }
                }
                d = result;
                break;
            case 2:
            case 3:
                d = 1;
                break;
        }
    }
    ClampEmblemCursorCell();
    if (d != 0) {
        if (gEmblemCursor->mMode == 1) {
            writeValue = 0;
        } else {
            writeValue = gEmblemCursor->mCellValue;
        }
        switch (gEmblemCursor->mMode) {
            case 0:
            case 1:
                switch (gEmblemCursor->mSizeIndex) {
                    case 0:
                        if (SetEmblemGridCellValue(gEmblemCursor->mCellX, gEmblemCursor->mCellY, writeValue) != 0) {
                            result = 1;
                        }
                        break;
                    case 1:
                        for (i = 0; i < 2; i++) {
                            for (j = 0; j < 2; j++) {
                                if (SetEmblemGridCellValue(gEmblemCursor->mCellX + i, gEmblemCursor->mCellY + j,
                                                           writeValue) != 0) {
                                    result = 1;
                                }
                            }
                        }
                        break;
                    case 2:
                        for (i = -1; i < 2; i++) {
                            for (j = -1; j < 2; j++) {
                                if (SetEmblemGridCellValue(gEmblemCursor->mCellX + i, gEmblemCursor->mCellY + j,
                                                           writeValue) != 0) {
                                    result = 1;
                                }
                            }
                        }
                        break;
                }
                break;
            case 2:
                result = FillEmblemGridAtCursorCell();
                break;
            case 3:
                result = SetEmblemCursorCellValueFromGrid();
                break;
        }
    }
    gEmblemCursor->mPrevDown = down;
    gEmblemCursor->mPrevX = x;
    gEmblemCursor->mPrevY = y;
    gEmblemCursor->mPrevCellX = saveX;
    gEmblemCursor->mPrevCellY = saveY;
    if (down == 0 && d == 0) {
        ClearEmblemGridCopied();
    }
    return result;
}

BOOL AdvanceEmblemColorCursorShrink(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        ApplyLldEntryFrameCommand(entry, 0);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - 0x19a);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
            return TRUE;
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        SetLldEntryScale(entry, 0);
        return FALSE;
    }
    return TRUE;
}

BOOL AdvanceEmblemColorCursorGrow(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        ApplyLldEntryFrameCommand(entry, 0);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + 0x19a);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    SetLldEntryScale(entry, 0x1000);
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    return TRUE;
}

void StartEmblemColorCursorShrinkAndGrow(void *lld, s32 index) {
    void *pickedEntry = GetLldEntry(lld, index);
    void *shrinkEntry = GetLldEntry(lld, 9);
    void *growEntry = GetLldEntry(lld, 10);

    SetLldEntryPos(shrinkEntry, GetLldEntryX(pickedEntry), GetLldEntryY(pickedEntry));
    SetLldEntryPos(growEntry, GetLldEntryX(pickedEntry), GetLldEntryY(pickedEntry));
    SetLldEntryCallback(shrinkEntry, (s32(*)(LldEntry *)) AdvanceEmblemColorCursorShrink);
    SetLldEntryCallback(growEntry, (s32(*)(LldEntry *)) AdvanceEmblemColorCursorGrow);
}

BOOL AdvanceEmblemButtonBounceThenWait(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - 0x19a);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + 0x19a);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    if (entry->mUnk_10 == 11) {
        if (gEmblem->mUnk_108c != NULL) {
            gEmblem->mUnk_108c();
            gEmblem->mUnk_108c = NULL;
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 20) {
        return FALSE;
    }
    ApplyLldEntryFrameCommand(entry, 0);
    return TRUE;
}

void StartEmblemButtonBounceThenWait(void *lld, s32 index) {
    SetLldEntryCallback(GetLldEntry(lld, index), (s32(*)(LldEntry *)) AdvanceEmblemButtonBounceThenWait);
}

BOOL AdvanceEmblemButtonBounce(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - 0x19a);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + 0x19a);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    ApplyLldEntryFrameCommand(entry, 0);
    return TRUE;
}

void StartEmblemButtonBounce(void *lld, s32 index) {
    SetLldEntryCallback(GetLldEntry(lld, index), (s32(*)(LldEntry *)) AdvanceEmblemButtonBounce);
}

BOOL AdvanceEmblemModeButtonPress(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        ApplyLldEntryFrameCommand(entry, 0);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - 0x19a);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        ApplyLldEntryFrameCommand(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + 0x19a);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    return TRUE;
}

void ResetEmblemButton(void *lld, s32 index) {
    LldEntry *entry = GetLldEntry(lld, index);

    SetLldEntryCallback(entry, NULL);
    ApplyLldEntryFrameCommand(entry, 0);
    entry->mScale = 0x1000;
}

void StartEmblemModeButtonPress(void *lld, s32 index) {
    ResetEmblemButton(gEmblem->mEmblemSLld, 14);
    ResetEmblemButton(gEmblem->mEmblemSLld, 15);
    ResetEmblemButton(gEmblem->mEmblemSLld, 16);
    ResetEmblemButton(gEmblem->mEmblemSLld, 17);
    ResetEmblemButton(gEmblem->mEmblemSLld, 18);
    ResetEmblemButton(gEmblem->mEmblemSLld, 19);
    ResetEmblemButton(gEmblem->mEmblemSLld, 20);
    ResetEmblemButton(gEmblem->mEmblemSLld, 21);
    SetLldEntryCallback(GetLldEntry(lld, index), (s32(*)(LldEntry *)) AdvanceEmblemModeButtonPress);
}

BOOL AdvanceEmblemButtonHold(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 10) {
        ApplyLldEntryFrameCommand(entry, 1);
        return FALSE;
    }
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    return TRUE;
}

void StartEmblemButtonHold(void *lld, s32 index) {
    SetLldEntryCallback(GetLldEntry(lld, index), (s32(*)(LldEntry *)) AdvanceEmblemButtonHold);
}

void StartEmblemButtonBounceAndToggle(void *lld, s32 index) {
    void *pressedEntry = GetLldEntry(lld, index);
    void *toggleEntry = GetLldEntry(lld, 24);

    if (GetLldEntryFrameIndex(toggleEntry) >= 0) {
        SetLldEntryCallback(pressedEntry, (s32(*)(LldEntry *)) AdvanceEmblemButtonBounceThenWait);
        ApplyLldEntryFrameCommand(toggleEntry, -5);
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 505);
    } else {
        SetLldEntryCallback(pressedEntry, (s32(*)(LldEntry *)) AdvanceEmblemButtonBounceThenWait);
        ApplyLldEntryFrameCommand(toggleEntry, 0);
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 506);
    }
}
