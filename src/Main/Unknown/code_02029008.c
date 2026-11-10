#include "Main/Unknown/code_02029008.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_020291f0.h"
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
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on
#pragma thumb on
s32 UpdateSelectKartTouchHold(void) {
    s32 result = -1;
    CellFileSet *p = &gSelectKart->mSelectKartSParts;
    u16 slotIndex = func_020435bc();
    s32 pairX;
    s32 pairY;
    s32 rectIndex;
    if (gSelectKart->mTouchHeld != FALSE) {
        if (func_020291f0(slotIndex) != 0) {
            pairX = SelectKartGetSlotPairX(slotIndex);
            pairY = SelectKartGetSlotPairY(slotIndex);
            rectIndex = FindRectContainingPoint(pairX, pairY, p->mRects);
            if (rectIndex != gSelectKart->mTouchRect) {
                gSelectKart->mTouchHeld = FALSE;
                gSelectKart->mTouchHeldFrames = 0;
            } else {
                gSelectKart->mTouchHeldFrames++;
                result = rectIndex;
            }
        } else {
            gSelectKart->mTouchHeld = FALSE;
            gSelectKart->mTouchHeldFrames = 0;
        }
    } else if (SelectKartIsSlotPairNew(slotIndex) != 0) {
        result =
            FindRectContainingPoint(SelectKartGetSlotPairX(slotIndex), SelectKartGetSlotPairY(slotIndex), p->mRects);
        gSelectKart->mTouchHeld = TRUE;
        gSelectKart->mTouchHeldFrames = 0;
    }
    return result;
}

u32 IsSelectKartTouchRepeat(s32 rectIndex) {
    u32 result = 0;
    u32 repeatDue;
    SelectKart *d = gSelectKart;
    s32 heldFrames;
    if (d->mTouchRect == rectIndex) {
        heldFrames = d->mTouchHeldFrames;
        result |= (heldFrames == 0);
        repeatDue = 0;
        if (heldFrames >= 0x3c) {
            if ((heldFrames - 0x3c) % 0xf == 0) {
                repeatDue = 1;
            }
        }
        result |= repeatDue;
    }
    return result;
}

void func_02029008(void) {
    SelectKart *d = gSelectKart;
    CellFileSet *p;
    if (d->mUnk_104 == FALSE) {
        p = &d->mSelectCharacterGpMParts;
        p->mCellTable[1].mOffsetX = GetInterpolatedValue(&d->mInterpolations[0]);
        p->mCellTable[2].mOffsetX = p->mCellTable[1].mOffsetX;
        p->mCellTable[0].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[1]);
        p->mCellTable[3].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[2]);
        p->mCellTable[9].mOffsetY = GetInterpolatedValue(&gSelectKart->mInterpolations[3]);
        p->mCellTable[8].mOffsetY = p->mCellTable[9].mOffsetY;
        p->mCellTable[7].mOffsetY = p->mCellTable[8].mOffsetY;
        p->mCellTable[6].mOffsetY = p->mCellTable[7].mOffsetY;
        p->mCellTable[5].mOffsetY = p->mCellTable[6].mOffsetY;
        p->mCellTable[4].mOffsetY = p->mCellTable[5].mOffsetY;
    }
}
#pragma thumb off
