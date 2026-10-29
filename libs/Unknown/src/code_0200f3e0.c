#include "code_0200f3e0.h"
#include "code_0200f3f4.h"
#include "Main/Unknown/code_0200f000.h"

// non-matching: 1.2 adds `sub sp, sp, #4` after the push and `add sp, sp, #4` before the pop (0x1c bytes against
// 0x14); the ROM's function is push {lr}, the two calls, pop {lr}
void func_0200f3e0(u32 a) {
    func_0200f3f4(a);
    func_0200f484();
}
