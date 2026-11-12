#include "Main/Menu/own_entry_position_copy_cell.h"
#include "Main/Sound/character_seq_pair.h"
#include "Main/Sound/seq_queue.h"

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
