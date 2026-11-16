#include "Main/Unknown/code_02109038.h"
#include "Main/Unknown/code_0210bcf4.h"

void sfx_2109038(void *source, u32 falloffIndex, Vec3 *ownerPosSource) {
    u32 value0 = (u32) source;
    u32 value1 = falloffIndex;
    u32 value2 = (u32) ownerPosSource;
    u32 value3;
    u32 value12;
    *(u8 *) ((value0) + (60)) = value1;
    value3 = ~(0u);
    value1 = value2;
    *(u32 *) ((value0) + (64)) = value3;
    sfx_initEmitter2(source, value1);
}
