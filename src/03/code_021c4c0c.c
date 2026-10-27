#include "03/code_021c4c0c.h"
#include "03/code_021c2120.h"
#include "03/code_021c27d0.h"
#include "03/code_021c4bc4.h"
#include "03/code_021cdc10.h"
#include "03/code_021ce000.h"
#include "03/code_021cef80.h"
#include "03/unk_021da000.h"

void func_ov003_021c4c0c(void) {
    func_ov003_021c4c08();
    func_ov003_021c4c04();
    switch (func_ov003_021cef80()) {
        case 0:
            data_ov003_021da1d4 = 0;
            func_ov003_021cdc10(7);
            break;
        case 1:
            data_ov003_021da1d4 = 1;
            func_ov003_021cdc10(0xe);
            break;
        default:
            return;
    }
    func_ov003_021c27d0(0);
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021c4bc4);
}
