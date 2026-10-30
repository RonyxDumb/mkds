#include "00/code_021848f4.h"
#include "00/code_021806e0.h"
#include "Main/Unknown/code_02026120.h"
#include "Main/Unknown/code_02122ae4.h"

void func_ov000_021848f4(void) {
    s32 a;

    a = func_02026120();
    if (a == 1 || a == 3) {
        if (func_02122ae4() != 0) {
            func_ov000_021806e0(7);
            return;
        }
        if (a == 1) {
            func_ov000_021806e0(5);
        }
        if (a == 3) {
            func_ov000_021806e0(6);
        }
    }
}
