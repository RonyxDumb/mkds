#include "Main/Unknown/code_020a22ac.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02061fec.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020a22ac(u16 a) {
    if (func_02061fec() != 1) {
        return;
    }
    if (func_01ffc67c(func_0207a974(a)) != 0) {
        return;
    }
    data_0217b1fc->mUnk_000[a].mUnk_64 = 10;
}
