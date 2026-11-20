#include "Main/Menu/multi_select_ns_input.h"
#include "Main/System/heap.h"
#include "Main/Net/led_pattern.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "sound_archive_load_result.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids_on_memory_sdat_and_list_links.h"
#include "Main/Sound/sound_source_types_and_handle_sound_start.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"

#include "Main/Menu/multi_select_ns_registers.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Menu/multi_select_ns_pair_new.h"
#include "Main/Menu/multi_select_ns.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/Graphics/rect_containing_point.h"
#include "Main/System/key_recording_buffer.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/select_kart_ghost_work.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Save/buddy_record_time.h"
#include "cell_transfer_state.h"
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
            if (gMultiSelectNS->mStateFrames < MULTI_SELECT_NS_SLIDE_FRAMES) {
                gMultiSelectNS->mOffset =
                    InterpolateS16(1, -0xc0, 0, gMultiSelectNS->mStateFrames, MULTI_SELECT_NS_SLIDE_FRAMES);
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
                gMultiSelectNS->mNextCallbacksIndex = WL_MENU_CALLBACKS_MEMBER_KEY_START;
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_PRESS_WAIT;
                RefreshMultiSelectNS(0);
                MultiSelectNSStartOnMemorySeqArc(4);
            } else if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                gMultiSelectNS->mNextCallbacksIndex = WL_MENU_CALLBACKS_MEMBER_GROUP;
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_SLIDE_OUT;
                RequestSelectReturnPressWithSound(0);
            } else if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_DIRECTION_UP) != 0 && gMultiSelectNS->mIndex > 0) {
                gMultiSelectNS->mIndex--;
                RefreshMultiSelectNS(1);
                MultiSelectNSStartSeqArcWrapper(0);
            } else if (MultiSelectNSGetNewBits(slotIndex, PAD_KEY_DIRECTION_DOWN) != 0 && gMultiSelectNS->mIndex < 1) {
                gMultiSelectNS->mIndex++;
                RefreshMultiSelectNS(1);
                MultiSelectNSStartSeqArcWrapper(0);
            } else if (value == 0) {
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_PRESS_WAIT;
                RefreshMultiSelectNS(gMultiSelectNS->mIndex != 0 ? 1 : 0);
                MultiSelectNSStartOnMemorySeqArc(4);
                gMultiSelectNS->mIndex = 0;
                SetMultiSimple(0);
                gMultiSelectNS->mNextCallbacksIndex = WL_MENU_CALLBACKS_MEMBER_KEY_START;
            } else if (value == 1) {
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_PRESS_WAIT;
                RefreshMultiSelectNS(gMultiSelectNS->mIndex != 1 ? 1 : 0);
                MultiSelectNSStartOnMemorySeqArc(4);
                gMultiSelectNS->mIndex = 1;
                SetMultiSimple(1);
                gMultiSelectNS->mNextCallbacksIndex = WL_MENU_CALLBACKS_MEMBER_KEY_START;
            }
            break;
        case MULTI_SELECT_NS_STATE_PRESS_WAIT:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames >= MULTI_SELECT_NS_PRESS_FRAMES) {
                gMultiSelectNS->mStateFrames = 0;
                gMultiSelectNS->mState = MULTI_SELECT_NS_STATE_SLIDE_OUT;
                RefreshMultiSelectNS(1);
            }
            break;
        case MULTI_SELECT_NS_STATE_SLIDE_OUT:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames < MULTI_SELECT_NS_SLIDE_FRAMES) {
                gMultiSelectNS->mOffset =
                    InterpolateS16(1, 0, -0xc0, gMultiSelectNS->mStateFrames, MULTI_SELECT_NS_SLIDE_FRAMES);
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
