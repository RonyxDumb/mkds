#include "Main/Unknown/code_020ca984.h"

#include "Main/Unknown/code_020ca994.h"
#include "Main/Unknown/code_020ca9ac.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

u32 GetEmblemChoisesInputSlot(void) {
    return 0x8u;
}

u16 EmblemChoisesGetInputSlotNewBits(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 EmblemChoisesGetNewBits(u32 slotIndex, u32 mask) {
    return EmblemChoisesGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

u32 EmblemChoisesStartSeqArc(u32 seqIndex, u32 seqArcNo) {
    return NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, seqArcNo, seqIndex);
}

u32 StartEmblemChoisesSound(u32 seqIndex) {
    return EmblemChoisesStartSeqArc(seqIndex, 0u);
}
