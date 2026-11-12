#include "Main/Menu/multi_select_ns_input.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02030000.h"
#include "Main/Net/led_pattern.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

#include "Main/Menu/multi_select_ns_registers.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Menu/multi_select_ns_pair_new.h"
#include "Main/Menu/multi_select_ns.h"
#include "Main/Graphics/rect_containing_point.h"
#include "Main/System/key_recording_buffer.h"
#include "Main/Graphics/oam.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
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
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, seqArcNo, index);
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
    s32 value;
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
            value = -1;
            if (MultiSelectNSIsSlotPairNew(slotIndex) != 0) {
                value = MultiSelectNSGetSlotPairX(slotIndex);
                pairY = MultiSelectNSGetSlotPairY(slotIndex);
                touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(value, pairY);
                value = FindRectContainingPoint(value, pairY, multiSelectNS->mBnbl);
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
            } else if (value == 0) {
                gMultiSelectNS->mState = 2;
                RefreshMultiSelectNS(gMultiSelectNS->mIndex != 0 ? 1 : 0);
                MultiSelectNSStartOnMemorySeqArc(4);
                gMultiSelectNS->mIndex = 0;
                SetMultiSimple(0);
                gMultiSelectNS->mNextCallbacksIndex = 2;
            } else if (value == 1) {
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
    SendLedPatternNone();
    HeapDestroy(gMultiSelectNS->mHeap);
    gMultiSelectNS = NULL;
}

#pragma thumb off

void MultiSelectNSGXS_SetVisiblePlane(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (bits << 8);
}

void MultiSelectNSWriteSubWinEnableBits(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0xe000) | (bits << 13);
}

void MultiSelectNSG2S_SetWnd0InsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WININ & ~0x3f) | lowBits;

    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WININ = value;
}

void MultiSelectNSG2S_SetWndOutsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WINOUT & ~0x3f) | lowBits;

    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WINOUT = value;
}
