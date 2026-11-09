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

u16 func_020ca9c8(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 func_020ca9ac(u32 slotIndex, u32 mask) {
    return func_020ca9c8(&data_02175628[slotIndex], mask);
}

u32 func_020ca994(u32 seqIndex, u32 seqArcNo) {
    return NNS_SndArcPlayerStartSeqArc(&data_0217d068, seqArcNo, seqIndex);
}

u32 StartEmblemChoisesSound(u32 seqIndex) {
    return func_020ca994(seqIndex, 0u);
}
