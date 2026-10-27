#include "03/code_021cc234.h"
#include "03/code_021bf334.h"
#include "03/code_021c2120.h"
#include "03/code_021cc084.h"
#include "03/code_021cdc10.h"
#include "03/unk_021da000.h"

void func_ov003_021cc234(void) {
    switch (func_ov003_021bf334()) {
        case 0:
            func_ov003_021cdc10(7);
            break;
        case 1:
            func_ov003_021cdc10(6);
            data_ov003_021da254 = 1;
            break;
        default:
            return;
    }
    func_ov003_021c212c(func_ov003_021cc214);
}
