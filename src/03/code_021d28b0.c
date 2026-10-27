#include "03/code_021d28b0.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_0214d000.h"

void func_ov003_021d28b0(void *buffer) {
    func_0214d168(buffer, 0, 0x40000);
    data_ov003_021da2c8 = func_02017988(buffer, 0x40000, 0);
    if (data_ov003_021da2c8 == 0) {
        func_0200fd1c();
    }
}
