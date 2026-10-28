#include "03/code_021cf260.h"
#include "03/unk_021da000.h"

void *func_ov003_021cf260(u32 index) {
    Unk021cf260 *state = *(Unk021cf260 **) &data_ov003_021da288;
    if ((state->mMask & (1 << index)) != 0) {
        return state->mRecords + (index - 1) * 0x1e;
    }
    return 0;
}
