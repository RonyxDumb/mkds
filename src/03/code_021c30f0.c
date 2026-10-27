#include "03/code_021c30f0.h"
#include "03/code_021c2120.h"
#include "03/code_021c30d4.h"
#include "03/code_021cdc10.h"
#include "03/code_021ce000.h"
#include "03/code_021cef80.h"
#include "03/unk_021da000.h"

void func_ov003_021c30f0(void) {
    switch (func_ov003_021cef80()) {
        case 1:
            func_ov003_021cdc10(0xe);
            data_ov003_021da1a8 = 1;
            break;
        case 0:
            func_ov003_021cdc10(7);
            break;
        default:
            return;
    }
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021c30d4);
}
