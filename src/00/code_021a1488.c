#include "00/code_021a1488.h"

u32 func_ov000_021a1488(void) {
    char name[12];
    u8 buffer[32];
    if (data_ov000_021b566c->mUnk_15 != 2) {
        return 0;
    }
    func_0200d9e0(name, 0xc, data_ov000_021b40b8, data_ov000_021b566c->mUnk_16 + 1);
    func_ov000_021a363c(data_ov000_021b41a8, name, buffer, 0x2f);
    func_0200d9e0(name, 0xc, data_ov000_021b40b8, data_ov000_021b566c->mUnk_0d + 1);
    func_ov000_021a360c(data_ov000_021b41ac, name, buffer, 0x2f);
    func_0200d9e0(name, 0xc, data_ov000_021b40b8, 3);
    func_ov000_021a360c(data_ov000_021b4118, name, buffer, 0x2f);
    return func_ov000_0219d558(6, buffer, 0);
}
