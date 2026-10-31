#include "00/code_0218d1dc.h"
#include "00/code_0218b220.h"
#include "00/code_0218b3ac.h"

void func_ov000_0218d1dc(Unk021b4d24 *p) {
    int v1;
    int v2;
    if (p->mUnk_5d0 != 0) {
        v1 = p->mUnk_5d0;
        while (v1 != 0) {
            v2 = func_ov000_0218b220(v1);
            func_ov000_0218b3ac(&v1);
            v1 = v2;
        }
        p->mUnk_5d0 = 0;
    }
}
