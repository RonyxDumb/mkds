#include "Main/Unknown/code_02087cfc.h"

void func_02087cfc(void *animation, u32 entryIndex, u32 loopFlag) {
    u32 *loopFlags = *OFFSET_PTR(u32 *, animation, 32);
    loopFlags[entryIndex] = loopFlag;
    *(u16 *) animation = loopFlag;
}
