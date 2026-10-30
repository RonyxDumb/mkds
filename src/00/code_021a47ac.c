#include "00/code_021a47ac.h"
#include "00/code_0218e53c.h"
#include "00/code_0218e8b4.h"
#include "00/code_021a3668.h"
#include "00/code_021a3000.h"
#include "00/unk_021b4000.h"

void func_ov000_021a47ac(Unk021a4a08 *a) {
    if (a == 0) {
        a = data_ov000_021b426c;
    }
    if (a->mUnk_0bc != 0) {
        func_ov000_021a3a18((Unk021a3a18 *) a, 2);
    }
    if (a->mUnk_000 != -1 && a->mUnk_0c4 != 0) {
        func_ov000_0218e53c(a->mUnk_000);
    }
    a->mUnk_000 = -1;
    a->mUnk_0ac = 0;
    if (a->mUnk_0c4 != 0) {
        func_ov000_0218e8b4();
    }
    if (a != &data_ov000_021b4278) {
        func_ov000_021a3668(a);
    }
}
