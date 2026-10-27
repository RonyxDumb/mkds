#include "Main/Unknown/code_0210f090.h"

#include "code_0201ec30.h"

u32 func_0210f090(Unk0210f090 *p) {
    if (p->mUnk_41c == 0) {
        return func_0201ec30();
    }
    if (p->mUnk_41c < 0x1e) {
        p->mUnk_41c = p->mUnk_41c + 1;
    } else {
        p->mUnk_41c = 0;
    }
    return 0;
}
