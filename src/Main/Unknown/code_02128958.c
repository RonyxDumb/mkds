#include "Main/Unknown/code_02128958.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on
void func_02128958(s16 *a) {
    void *h;
    h = func_020364e0(func_020364e8());
    data_0217d3fc = func_02036bec(h, 0x808);
    func_0212a1e0(h, a[0]);
}
#pragma thumb off
