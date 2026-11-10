#include "Main/Unknown/code_0203033c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02030000.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

#include "Main/Unknown/code_020302a0.h"
#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_02030708.h"
#include "Main/Unknown/code_020307b8.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_020ade08.h"
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
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02174000.h"
#include "registers.h"

u32 MultiSelectNSGetPairX(InputSlotPair *pair) {
    return pair->mPairX;
}

u32 MultiSelectNSGetSlotPairX(u32 slotIndex) {
    return MultiSelectNSGetPairX(&gInputSlots[slotIndex].mPair);
}

u32 MultiSelectNSGetPairY(InputSlotPair *pair) {
    return pair->mPairY;
}

u32 MultiSelectNSGetSlotPairY(u32 slotIndex) {
    return MultiSelectNSGetPairY(&gInputSlots[slotIndex].mPair);
}

u16 MultiSelectNSGetInputSlotNewBits(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u32 MultiSelectNSGetNewBits(u32 slotIndex, u32 mask) {
    return MultiSelectNSGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

void MultiSelectNSStartOnMemorySeqArc(u32 index) {
    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    MultiSelectNSStartSeqArc(index, 0);
    NNS_SndArcSetCurrent(&gFileSndArc);
}

void MultiSelectNSStartSeqArc(u32 index, u32 seqArcNo) {
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, seqArcNo, index);
}

void MultiSelectNSStartSeqArcWrapper(u32 index) {
    u32 indexCopy = index;
    u32 seqArcNo;
    u32 value12;
    seqArcNo = 0u;
    MultiSelectNSStartSeqArc(indexCopy, seqArcNo);
}

#pragma thumb on

s32 AdvanceMultiSelectNS(void) {
    MultiSelectNS *multiSelectNS;
    s32 result;
    s32 touchInReturnRect;
    s32 b;
    s32 pairY;
    u16 slotIndex;

    result = -1;
    slotIndex = GetPadInputSlot();
    multiSelectNS = gMultiSelectNS;
    switch (multiSelectNS->mState) {
        case 0:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames < 10) {
                gMultiSelectNS->mOffset = InterpolateS16(1, -0xc0, 0, gMultiSelectNS->mStateFrames, 10);
            } else {
                gMultiSelectNS->mStateFrames = 0;
                gMultiSelectNS->mOffset = 0;
                gMultiSelectNS->mState = 1;
            }
            SetMultiSelectNSCellTableOffsetY();
            break;
        case 1:
            touchInReturnRect = 0;
            b = -1;
            if (MultiSelectNSIsSlotPairNew(slotIndex) != 0) {
                b = MultiSelectNSGetSlotPairX(slotIndex);
                pairY = MultiSelectNSGetSlotPairY(slotIndex);
                touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(b, pairY);
                b = FindRectContainingPoint(b, pairY, multiSelectNS->mBnbl);
            }
            if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_A) != 0) {
                SetMultiSimple(gMultiSelectNS->mIndex == 1 ? 1 : 0);
                gMultiSelectNS->mNextCallbacksIndex = 2;
                gMultiSelectNS->mState = 2;
                RefreshMultiSelectNS(0);
                MultiSelectNSStartOnMemorySeqArc(4);
            } else if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                gMultiSelectNS->mNextCallbacksIndex = 0;
                gMultiSelectNS->mState = 3;
                RequestSelectReturnState3WithSound(0);
            } else if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_UP) != 0 && gMultiSelectNS->mIndex > 0) {
                gMultiSelectNS->mIndex--;
                RefreshMultiSelectNS(1);
                MultiSelectNSStartSeqArcWrapper(0);
            } else if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_DOWN) != 0 && gMultiSelectNS->mIndex < 1) {
                gMultiSelectNS->mIndex++;
                RefreshMultiSelectNS(1);
                MultiSelectNSStartSeqArcWrapper(0);
            } else if (b == 0) {
                gMultiSelectNS->mState = 2;
                RefreshMultiSelectNS(gMultiSelectNS->mIndex != 0 ? 1 : 0);
                MultiSelectNSStartOnMemorySeqArc(4);
                gMultiSelectNS->mIndex = 0;
                SetMultiSimple(0);
                gMultiSelectNS->mNextCallbacksIndex = 2;
            } else if (b == 1) {
                gMultiSelectNS->mState = 2;
                RefreshMultiSelectNS(gMultiSelectNS->mIndex != 1 ? 1 : 0);
                MultiSelectNSStartOnMemorySeqArc(4);
                gMultiSelectNS->mIndex = 1;
                SetMultiSimple(1);
                gMultiSelectNS->mNextCallbacksIndex = 2;
            }
            break;
        case 2:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames >= 5) {
                gMultiSelectNS->mStateFrames = 0;
                gMultiSelectNS->mState = 3;
                RefreshMultiSelectNS(1);
            }
            break;
        case 3:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames < 10) {
                gMultiSelectNS->mOffset = InterpolateS16(1, 0, -0xc0, gMultiSelectNS->mStateFrames, 10);
            } else {
                gMultiSelectNS->mOffset = 0;
                gMultiSelectNS->mState = 4;
            }
            SetMultiSelectNSCellTableOffsetY();
            break;
        case 4:
            result = multiSelectNS->mNextCallbacksIndex;
            break;
    }
    if (gMultiSelectNS->mState != 4) {
        DrawLayoutTable(multiSelectNS->mBncl, multiSelectNS->mNcer, multiSelectNS->mBnll, gMultiSelectNS->mOamList,
                        multiSelectNS->mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseMultiSelectNS(void) {
    func_0204f7f4();
    HeapDestroy(gMultiSelectNS->mHeap);
    gMultiSelectNS = NULL;
}

#pragma thumb off

void func_020303a8(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (bits << 8);
}

void MultiSelectNSWriteSubWinEnableBits(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0xe000) | (bits << 13);
}

void func_02030364(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WININ & ~0x3f) | lowBits;

    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WININ = value;
}

void func_0203033c(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WINOUT & ~0x3f) | lowBits;

    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WINOUT = value;
}
