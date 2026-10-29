#include "code_0200f790.h"
#include "code_0200f7a0.h"

// clang-format off
// Calls func_0200f7a0 and returns.
// Not compiled code: its only call is in tail position, which 1.2 builds as `ldr ip, =callee; bx ip`
// (docs/compiler.md), not as a `bl` inside a frame.
asm void func_0200f790(void) {
    stmdb sp!, {lr}
    bl func_0200f7a0
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
