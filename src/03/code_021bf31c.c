#include "03/code_021bf31c.h"
#include "03/unk_021da000.h"

void func_ov003_021bf31c(s32 value) {
    Unk021da108 *state = *(Unk021da108 **) &data_ov003_021da108;
    if (state->mUnk_16 == -1) {
        state->mUnk_16 = value;
    }
}
