#include "Main/Menu/own_entry_position_copy_cell.h"
#include "Main/Graphics/message_index.h"
#include "Main/Sound/seq_queue_seq_volume_control_and_seq_variables.h"

#pragma thumb on

void AddCharacterSeqQueueEntry(int characterIndex, int pairSide) {
    u32 pairNo;
    if ((characterIndex != 0xc) || (pairSide != 1)) {
        pairNo = GetCharacterSeqPairNo(characterIndex);
        AddSeqQueueEntry(pairNo, pairSide);
    }
}

u32 GetOwnEntryPositionCopyCellIndex(void) {
    return 0x8u;
}

#pragma thumb off
