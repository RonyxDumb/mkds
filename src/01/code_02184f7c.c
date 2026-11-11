#include "01/code_02184f7c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "code_02012b30.h"
#include "g2d_NAN_load.h"
#include "Main/Unknown/code_02021000.h"
#include "code_02022030.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"
#include "code_020220f0.h"
#include "code_02147cd8.h"

Lld *CreateLld(const char *fileName, void *cells, void *cellAnims) {
    s16 *box;
    LldEntry *entry;
    s32 entryIndex;
    Lld *list;
    LldData *data;
    LldRecord *rec;
    Unk021a5a58_2c_2c *cell;

    list = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x18);
    data = FindSceneFile((fileName));
    list->mEntryCount = data->mEntryCount;
    list->mEntries = HeapAlloc(GetHeap(GetCurrentHeapCall()), list->mEntryCount * 0x88);
    list->mCells = cells;
    list->mCellAnims = cellAnims;
    rec = data->mRecords;
    for (entryIndex = 0; entryIndex < list->mEntryCount; entryIndex++) {
        entry = &list->mEntries[entryIndex];
        entry->mLld = list;
        entry->mAnimIndex = rec[entryIndex].mUnk_00;
        entry->mPosX = rec[entryIndex].mUnk_02 > 0 ? 0.5f + (rec[entryIndex].mUnk_02 << 12)
                                                   : (rec[entryIndex].mUnk_02 << 12) - 0.5f;
        entry->mPosY = rec[entryIndex].mUnk_04 > 0 ? 0.5f + (rec[entryIndex].mUnk_04 << 12)
                                                   : (rec[entryIndex].mUnk_04 << 12) - 0.5f;
        entry->mScale = 0x1000;
        entry->mShown = rec[entryIndex].mUnk_06 != 0;
        NNS_G2dInitCellAnimation(&entry->mUnk_2c, NNS_G2dGetAnimSequenceByIdx(cellAnims, rec[entryIndex].mUnk_00),
                                 cells);
        if (rec[entryIndex].mUnk_06 > 1) {
            entry->mUnk_2c.mUnk_08 = TRUE;
        } else {
            entry->mUnk_2c.mUnk_08 = FALSE;
        }
        cell = (Unk021a5a58_2c_2c *) entry->mUnk_2c.mUnk_2c;
        if ((cell->mUnk_02 >> 11) & 1) {
            box = cell->mUnk_08;
            entry->mBoundsLeft = box[2] << 12;
            entry->mBoundsTop = box[3] << 12;
            entry->mBoundsRight = box[0] << 12;
            entry->mBoundsBottom = box[1] << 12;
        }
    }
    return list;
}

void AdvanceLld(Lld *lld, OamBuffer *oamBuffer) {
    s32 entryIndex;
    LldEntry *entry;
    Unk02022030 *cellAnim;
    s32 screenX;
    s32 screenY;
    s32 scaledPos[2];
    s32 unscaledPos[2];
    Unk021a5a58_2c_2c *cell;

    for (entryIndex = 0; entryIndex < lld->mEntryCount; entryIndex++) {
        entry = &lld->mEntries[entryIndex];
        cellAnim = &entry->mUnk_2c;
        if (entry->mCallback != NULL) {
            if (entry->mCallback(entry) != 0) {
                entry->mCallback = NULL;
            }
        }
        if (entry->mShown != FALSE && entry->mScale > 0) {
            screenX = (entry->mPosX >> 12) + lld->mOffsetX;
            screenY = (entry->mPosY >> 12) + lld->mOffsetY;
            if (screenX >= -64 && screenX <= 0x140 && screenY >= -48 && screenY <= 0xf0) {
                if (entry->mScale != 0x1000) {
                    u16 idx = AllocOamMatrixIndex(oamBuffer);
                    MtxFx22 mtx = {{0, 0, 0, 0}};

                    mtx.mUnk_00[0] = FX_Div(0x1000, entry->mScale);
                    mtx.mUnk_00[3] = FX_Div(0x1000, entry->mScale);
                    ((OamBuffer_000 *) oamBuffer->mOams)[idx].mUnk_06 = mtx.mUnk_00[0] >> 4;
                    ((OamBuffer_000 *) oamBuffer->mOams)[idx].mUnk_0e = mtx.mUnk_00[1] >> 4;
                    ((OamBuffer_000 *) oamBuffer->mOams)[idx].mUnk_16 = mtx.mUnk_00[2] >> 4;
                    ((OamBuffer_000 *) oamBuffer->mOams)[idx].mUnk_1e = mtx.mUnk_00[3] >> 4;
                    mtx.mUnk_00[0] = entry->mScale;
                    mtx.mUnk_00[3] = entry->mScale;
                    cell = (Unk021a5a58_2c_2c *) entry->mUnk_2c.mUnk_2c;
                    scaledPos[0] = screenX << 12;
                    scaledPos[1] = screenY << 12;
                    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
                        (GXOamAttr *) &oamBuffer->mOams[oamBuffer->mOamCount * 8], 0x80 - oamBuffer->mOamCount,
                        (Unk020224e0_c *) cell, &mtx, scaledPos, idx, 1);
                } else {
                    cell = (Unk021a5a58_2c_2c *) entry->mUnk_2c.mUnk_2c;
                    unscaledPos[0] = screenX << 12;
                    unscaledPos[1] = screenY << 12;
                    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
                        (GXOamAttr *) &oamBuffer->mOams[oamBuffer->mOamCount * 8], 0x80 - oamBuffer->mOamCount,
                        (Unk020224e0_c *) cell, NULL, unscaledPos, 0, 0);
                }
            }
        }
        if (cellAnim->mUnk_08 != FALSE) {
            NNS_G2dSetCellAnimationSpeed(&entry->mUnk_2c, 0x1000);
            NNS_G2dTickCellAnimation(&entry->mUnk_2c, 0x1000);
        }
    }
}

LldEntry *GetLldEntry(Lld *lld, s32 index) {
    return &lld->mEntries[index];
}

s32 FindLldEntryAtPoint(Lld *lld, s32 startIndex, s32 pointX, s32 pointY) {
    s32 fixedX;
    s32 fixedY;
    u16 count;
    LldEntry *entry;

    fixedX = pointX > 0 ? 0.5f + (pointX << 12) : (pointX << 12) - 0.5f;
    fixedY = pointY > 0 ? 0.5f + (pointY << 12) : (pointY << 12) - 0.5f;
    count = lld->mEntryCount;
    for (; startIndex < count; startIndex++) {
        entry = &lld->mEntries[startIndex];
        if (fixedX > entry->mPosX + entry->mBoundsLeft && fixedX < entry->mPosX + entry->mBoundsRight &&
            fixedY > entry->mPosY + entry->mBoundsTop && fixedY < entry->mPosY + entry->mBoundsBottom) {
            return startIndex;
        }
    }
    return -1;
}

void SetLldEntryCallback(LldEntry *entry, s32 (*callback)(LldEntry *)) {
    entry->mCallback = callback;
    entry->mUnk_10 = 0;
    entry->mUnk_14 = 0;
}

void ApplyLldEntryFrameCommand(LldEntry *entry, s32 frameOrCommand) {
    Unk02022030 *cellAnim = &entry->mUnk_2c;

    if (frameOrCommand == -1) {
        cellAnim->mUnk_14 = 2;
        entry->mUnk_2c.mUnk_08 = TRUE;
    } else if (frameOrCommand == -2) {
        NNS_G2dResetAnimCtrlState(cellAnim);
        cellAnim->mUnk_14 = 1;
        entry->mUnk_2c.mUnk_08 = TRUE;
    } else if (frameOrCommand == -3) {
        entry->mUnk_2c.mUnk_08 = FALSE;
    } else if (frameOrCommand == -4) {
        entry->mShown = TRUE;
    } else if (frameOrCommand == -5) {
        entry->mShown = FALSE;
    } else if (frameOrCommand >= 0) {
        entry->mShown = TRUE;
        NNS_G2dSetCellAnimationCurrentFrame(cellAnim, frameOrCommand);
    }
}

s32 GetLldEntryFrameIndex(LldEntry *entry) {
    if (entry->mShown != FALSE) {
        return NNS_G2dGetAnimCtrlCurrentFrame(&entry->mUnk_2c);
    }
    return -5;
}

void SetLldEntryPos(LldEntry *entry, s32 screenX, s32 screenY) {
    entry->mPosX = (screenX - entry->mLld->mOffsetX) << 12;
    entry->mPosY = (screenY - entry->mLld->mOffsetY) << 12;
}

s32 GetLldEntryX(LldEntry *entry) {
    return (entry->mPosX >> 12) + entry->mLld->mOffsetX;
}

s32 GetLldEntryY(LldEntry *entry) {
    return (entry->mPosY >> 12) + entry->mLld->mOffsetY;
}

void SetLldEntryScale(LldEntry *entry, s32 scale) {
    entry->mScale = scale;
}

s32 GetLldEntryScale(LldEntry *entry) {
    return entry->mScale;
}

void SetLldEntryBounds(LldEntry *entry, s32 left, s32 top, s32 right, s32 bottom) {
    entry->mBoundsLeft = left << 12;
    entry->mBoundsTop = top << 12;
    entry->mBoundsRight = right << 12;
    entry->mBoundsBottom = bottom << 12;
}

void StartDonketuStepSoundFirst(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x210);
}

void StartDonketuStepSoundSecond(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x210);
}
