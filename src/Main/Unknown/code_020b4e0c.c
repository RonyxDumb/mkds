#include "Main/Unknown/code_020b4e0c.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b4e70.h"

s32 func_020b4e0c(void) {
    s32 r = 1;
    Vec3 v;
    s32 a = func_020b4e5c();

    if (a == 0x11 || a == 0x13) {
        func_0207a91c(&v, func_020b4d9c());
        r = func_020b4e70(&v);
    }
    return r;
}
