#include "Main/Unknown/code_0202ecac.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

u32 func_0202ecbc(u32 index, u32 archiveNo) {
    return NNS_SndArcPlayerStartSeqArc(&data_0217d068, archiveNo, index);
}

u32 func_0202ecac(u32 index) {
    return func_0202ecbc(index, 0u);
}
