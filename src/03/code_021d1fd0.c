#include "03/code_021d1fd0.h"
#include "03/unk_021da000.h"

void func_ov003_021d1fd0(void *object) {
    Unk021d1fd0 *state = *(Unk021d1fd0 **) &data_ov003_021da2c4;
    if (object == state->mUnk_718) {
        state->mUnk_794 = 1;
    } else {
        state->mUnk_795 = 1;
    }
}
