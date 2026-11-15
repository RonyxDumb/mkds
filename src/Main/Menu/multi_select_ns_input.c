#include "Main/Menu/multi_select_ns_input.h"
#include "Main/System/heap.h"
#include "Main/Net/led_pattern.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/MapObjects/data_0217c000.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"

#include "Main/Menu/multi_select_ns_registers.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Menu/multi_select_ns_pair_new.h"
#include "Main/Menu/multi_select_ns.h"
#include "Main/Graphics/rect_containing_point.h"
#include "Main/System/key_recording_buffer.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "registers.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

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
    u32 unusedScratch;
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
        case MULTI_SELECT_NS_STATE_SLIDE_IN:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames < 10) {
                gMultiSelectNS->mOffset = InterpolateS16(1, -0xc0, 0, gMultiSelectNS->mStateFrames, 10);
            } else {
                gMultiSelectNS->mStateFrames = 0;
                gMultiSelectNS->mOffset = 0;
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_CHOOSE;
            }
            SetMultiSelectNSCellTableOffsetY();
            break;
        case MULTI_SELECT_NS_STATE_CHOOSE:
            touchInReturnRect = 0;
            value = -1;
            if (MultiSelectNSIsSlotPairNew(slotIndex) != 0) {
                value = MultiSelectNSGetSlotPairX(slotIndex);
                pairY = MultiSelectNSGetSlotPairY(slotIndex);
                touchInReturnRect = IsSelectReturnShownNoRequestAndInRect(value, pairY);
                value = FindRectContainingPoint(value, pairY, multiSelectNS->mBnbl);
            }
            if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_A) != 0) {
                SetMultiSimple(gMultiSelectNS->mIndex == 1 ? 1 : 0);
                gMultiSelectNS->mNextCallbacksIndex = 2;
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_PRESS_WAIT;
                RefreshMultiSelectNS(0);
                MultiSelectNSStartOnMemorySeqArc(4);
            } else if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                gMultiSelectNS->mNextCallbacksIndex = 0;
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_SLIDE_OUT;
                RequestSelectReturnPressWithSound(0);
            } else if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_UP) != 0 && gMultiSelectNS->mIndex > 0) {
                gMultiSelectNS->mIndex--;
                RefreshMultiSelectNS(1);
                MultiSelectNSStartSeqArcWrapper(0);
            } else if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_DOWN) != 0 && gMultiSelectNS->mIndex < 1) {
                gMultiSelectNS->mIndex++;
                RefreshMultiSelectNS(1);
                MultiSelectNSStartSeqArcWrapper(0);
            } else if (value == 0) {
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_PRESS_WAIT;
                RefreshMultiSelectNS(gMultiSelectNS->mIndex != 0 ? 1 : 0);
                MultiSelectNSStartOnMemorySeqArc(4);
                gMultiSelectNS->mIndex = 0;
                SetMultiSimple(0);
                gMultiSelectNS->mNextCallbacksIndex = 2;
            } else if (value == 1) {
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_PRESS_WAIT;
                RefreshMultiSelectNS(gMultiSelectNS->mIndex != 1 ? 1 : 0);
                MultiSelectNSStartOnMemorySeqArc(4);
                gMultiSelectNS->mIndex = 1;
                SetMultiSimple(1);
                gMultiSelectNS->mNextCallbacksIndex = 2;
            }
            break;
        case MULTI_SELECT_NS_STATE_PRESS_WAIT:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames >= 5) {
                gMultiSelectNS->mStateFrames = 0;
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_SLIDE_OUT;
                RefreshMultiSelectNS(1);
            }
            break;
        case MULTI_SELECT_NS_STATE_SLIDE_OUT:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames < 10) {
                gMultiSelectNS->mOffset = InterpolateS16(1, 0, -0xc0, gMultiSelectNS->mStateFrames, 10);
            } else {
                gMultiSelectNS->mOffset = 0;
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_DONE;
            }
            SetMultiSelectNSCellTableOffsetY();
            break;
        case MULTI_SELECT_NS_STATE_DONE:
            result = multiSelectNS->mNextCallbacksIndex;
            break;
    }
    if (gMultiSelectNS->mState != MULTI_SELECT_NS_STATE_DONE) {
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
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | (bits << 8);
}

void MultiSelectNSWriteSubWinEnableBits(u32 bits) {
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK)) |
        (bits << 13);
}

void MultiSelectNSG2S_SetWnd0InsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WININ & ~REG_G2S_DB_WININ_WIN0IN_MASK) | lowBits;

    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WININ = value;
}

void MultiSelectNSG2S_SetWndOutsidePlane(u32 lowBits, u32 extraBitFlag) {
    u32 value = (reg_G2S_DB_WINOUT & ~REG_G2S_DB_WINOUT_WINOUT_MASK) | lowBits;

    if (extraBitFlag != 0) {
        value |= 0x20;
    }
    reg_G2S_DB_WINOUT = value;
}
