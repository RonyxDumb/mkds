#include "g2d_CellTransferManager.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"

NNSG2dCellTransferState *NNSi_G2dGetCellTransferState(u32 handle) {
    return data_02174e04 + handle;
}

void NNS_G2dSetCellTransferStateRequested(u32 handle, u32 srcOffset, u32 szByte) {
    NNSG2dCellTransferState *state;

    state = NNSi_G2dGetCellTransferState(handle);
    state->mTransferRequested = ~0;
    state->mSrcOffset = srcOffset;
    state->mSzByte = szByte;
}
