#include "00/code_02184a0c.h"
#include "00/code_021806e0.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02122ae4.h"

void func_ov000_02184a0c(void) {
    s32 a;

    a = func_02028130();
    if (a == 1 || a == 2) {
        if (func_02122ae4() != 0) {
            func_ov000_021806e0(7);
            return;
        }
        if (a == 1) {
            func_ov000_021806e0(6);
            return;
        }
        if (a == 2) {
            func_ov000_021806e0(4);
        }
    }
}
