#include "00/code_02184950.h"
#include "00/code_02182fdc.h"
#include "00/code_02184934.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02026910.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_0212a910.h"
#include "00/code_021806a0.h"

void func_ov000_02184950(void *a) {
    void *b;
    void *c;
    s32 i;

    data_ov000_021b4c78 = func_02036bec(a, 4);
    data_ov000_021b4c78->mUnk_00 = a;
    func_ov000_02184934();
    if (func_ov000_021806d4() != 5) {
        func_02122728();
        func_02029454((u8) func_02122778(func_ov000_0219bb50()));
        func_02029440(data_0217d384->mUnk_1f52);
    }
    b = func_ov000_021804f4();
    c = func_ov000_021804e0();
    func_02026910(a, 2, b, c);
    func_0212a910(1, 1);
    data_0217b488->mUnk_6c = 0;
    for (i = 0; i < 4; i++) {
        data_0217b488->mUnk_5c[i] = 0;
    }
}
