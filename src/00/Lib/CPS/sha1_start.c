#include "00/Lib/CPS/sha1_start.h"
#include "cpu_copy_fill.h"

void CPSi_sha1_init(Hash20Context *context) {
    Mem_CpuFill8(context, 0, sizeof(Hash20Context));
    context->mStateA = (0x67452301u);
    context->mStateB = (0xefcdab89u);
    context->mStateC = (0x98badcfeu);
    context->mStateD = (0x10325476u);
    context->mStateE = (0xc3d2e1f0u);
}
