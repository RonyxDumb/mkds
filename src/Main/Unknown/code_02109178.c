#include "Main/Unknown/code_02109178.h"
#include "Main/Unknown/code_0210d4a0.h"

u32 SoundReturnArgumentWrapper(u32 address) {
    u32 value0 = address;
    u32 value12;
    value12 = (u32) &SoundReturnArgument;
    value0 = SoundReturnArgument(value0);
    return value0;
}
