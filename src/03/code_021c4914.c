#include "03/code_021c4914.h"
#include "03/code_021bf334.h"
#include "03/code_021c2120.h"
#include "03/code_021c4788.h"
#include "03/code_021cdc10.h"
#include "03/unk_021da000.h"

void func_ov003_021c4914(void) {
    switch (func_ov003_021bf334()) {
        case 1:
            data_ov003_021da1cc = 1;
            func_ov003_021cdc10(6);
            break;
        case 0:
            data_ov003_021da1cc = 0;
            func_ov003_021cdc10(7);
            break;
        default:
            return;
    }
    func_ov003_021c212c(func_ov003_021c48f4);
}
