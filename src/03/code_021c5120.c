#include "03/code_021c5120.h"
#include "03/code_021c2120.h"
#include "03/code_021c52a0.h"
#include "03/code_021c52d0.h"
#include "03/code_021cdbd0.h"

void func_ov003_021c5120(void) {
    func_ov003_021c52f4();
    func_ov003_021c52f0();
    func_ov003_021c52d0();
    data_ov003_021da1e0 = data_ov003_021da1e0 + 1;
    if (data_ov003_021da1e0 >= 0x438) {
        func_ov003_021cdbd0();
        func_ov003_021c212c(func_ov003_021c52a0);
    }
}
