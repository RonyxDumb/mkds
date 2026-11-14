#include "00/code_021997f8.h"
#include "00/GameSpy/nonport.h"
#include "00/GameSpy/gt2Callback.h"

void func_ov000_021997f8(Gt2Connection *a) {
    u32 v1;
    if (a->mUnk_90 == 0) {
        a->mUnk_90 = 1;
        v1 = func_ov000_0218e8c4();
        a->mUnk_94 = v1;
    }
}
