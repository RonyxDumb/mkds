#include "Main/Unknown/code_020cb1c4.h"

#include "Main/Unknown/code_020cb1cc.h"
#include "Main/Unknown/code_020cb1dc.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

u32 func_020cb1dc(u32 seqIndex, u32 seqArcNo) {
    return NNS_SndArcPlayerStartSeqArc(&data_0217d068, seqArcNo, seqIndex);
}

u32 func_020cb1cc(u32 seqIndex) {
    return func_020cb1dc(seqIndex, 0u);
}

u32 func_020cb1c4(u16 *pair) {
    return pair[2];
}
