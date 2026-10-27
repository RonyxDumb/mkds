#include "03/code_021cc464.h"
#include "03/code_021c2120.h"
#include "03/code_021cc410.h"
#include "03/code_021cdc10.h"
#include "03/code_021ce000.h"
#include "03/code_021cef80.h"
#include "03/unk_021da000.h"

void func_ov003_021cc464(void) {
    switch (func_ov003_021cef80()) {
        case 1:
            data_ov003_021da258 = 3;
            func_ov003_021cdc10(6);
            break;
        case 0:
            data_ov003_021da258 = 1;
            func_ov003_021cdc10(7);
            break;
        default:
            return;
    }
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021cc410);
}
