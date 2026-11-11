#include "00/code_021abd2c.h"
#include "code_0214d018.h"

void CPSi_sha1_init(Hash20Context *context) {
    MI_CpuFill8(context, 0, 0x5c);
    context->mUnk_00 = (0x67452301u);
    context->mUnk_04 = (0xefcdab89u);
    context->mUnk_08 = (0x98badcfeu);
    context->mUnk_0c = (0x10325476u);
    context->mUnk_10 = (0xc3d2e1f0u);
}
