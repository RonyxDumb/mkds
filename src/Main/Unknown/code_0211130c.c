#include "Main/Unknown/code_0211130c.h"

#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_02111324(Unk02111324 *a) {
    func_020ae6ac(data_0217d33c, data_0217d340);
    func_021114cc();
    func_020ae630(data_0217d33c, data_0217d340);
    if (a != 0 && func_0211145c() != -1) {
        a->mUnk_04 = func_0211145c();
    }
}

void *func_02111318(void) {
    return data_0217d33c;
}

void *func_0211130c(void) {
    return data_0217d340;
}

#pragma thumb off
