#include "00/code_02184a6c.h"
#include "00/code_02182fdc.h"
#include "00/code_02184a50.h"
#include "Main/Unknown/code_02028000.h"

void func_ov000_02184a6c(void *a) {
    void *b;
    void *c;

    data_ov000_021b4c7c = func_02036bec(a, 4);
    data_ov000_021b4c7c->mUnk_00 = a;
    func_ov000_02184a50();
    b = func_ov000_021804f4();
    c = func_ov000_021804e0();
    func_02028864(a, 2, b, c);
}
