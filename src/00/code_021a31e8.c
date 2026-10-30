#include "00/code_021a31e8.h"
#include "00/unk_021b4000.h"
#include "code_02134d30.h"
#include "code_0214d018.h"

u16 func_ov000_021a31e8(const void *a) {
    Unk021a31e8 t;
    func_0214d1fc(a, &t, 8);
    if (func_02134d30(t.mUnk_06, data_ov000_021b41f0, 2) == 0) {
        return t.mUnk_04;
    }
    return 0;
}
