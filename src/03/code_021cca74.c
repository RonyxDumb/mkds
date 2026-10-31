#include "03/code_021cca74.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"

void func_ov003_021cca74(s32 offset) {
    Unk021cca74 *state = data_ov003_021da268;
    func_ov003_021d17d4((Unk021d1770 *) state->mResource, -1, state->mX, offset + state->mY);
    data_ov003_021da268->mOffset = offset;
}
