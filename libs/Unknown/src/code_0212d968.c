#include "code_0212d968.h"
#include "Main/Unknown/code_0201750c.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_0212da1c.h"

u32 func_0212d9dc(Unk0212d9dc *a, void *p) {
    func_02017538(&a->mUnk_04, 12);
    a->mUnk_00 = p;
    return func_0212d98c(a) != 0;
}

u32 func_0212d98c(Unk0212d9dc *a) {
    void *p;

    p = func_0201808c(a->mUnk_00, 0x14, 4);
    if (p == 0) {
        return 0;
    }
    func_0212da1c(p);
    func_020174a4(&a->mUnk_04, p);
    return 1;
}

void func_0212d968(void) {
    u32 v;

    v = func_02021114();
    func_020211e4(1);
    func_02021154(v);
}
