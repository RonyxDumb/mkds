#include "00/code_021abd2c.h"
#include "code_0214d018.h"

void CPSi_sha1_init(Hash20Context *context) {
    MI_CpuFill8(context, 0, 0x5c);
    context->mStateA = (0x67452301u);
    context->mStateB = (0xefcdab89u);
    context->mStateC = (0x98badcfeu);
    context->mStateD = (0x10325476u);
    context->mStateE = (0xc3d2e1f0u);
}
