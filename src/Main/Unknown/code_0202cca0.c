#include "Main/Unknown/code_0202cca0.h"
#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/code_02110720.h"

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
