#include "Main/Unknown/code_0208f0a0.h"
#include "code_020172d0.h"

void func_0208f0a0(void) {
    void *p;
    p = func_0201733c(&data_0217b08c->mUnk_00, 0);
    while (p != 0) {
        func_0208e99c(p);
        p = func_0201733c(&data_0217b08c->mUnk_00, p);
    }
}
