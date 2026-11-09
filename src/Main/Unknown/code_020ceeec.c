#include "Main/Unknown/code_020ceeec.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"

u32 ShuffledIndicesGetConnectionKind(void) {
    return (data_021759d0->mConnectionKind);
}

RandomState64 *ShuffledIndicesGetConnectionWorkRandomState(void) {
    return &gConnectionWork->mRandomState;
}
