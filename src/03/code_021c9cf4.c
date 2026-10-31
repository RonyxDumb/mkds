#include "03/code_021c9cf4.h"
#include "03/code_021bf2d0.h"
#include "03/code_021c2120.h"
#include "03/code_021c2938.h"
#include "03/code_021c9cb0.h"
#include "03/code_021c9d94.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/unk_021da000.h"

void func_ov003_021c9cf4(void) {
    switch (func_ov003_021c2938()) {
        case 3:
            data_ov003_021da21c = 1;
            func_ov003_021cdbd0();
            func_ov003_021c2918();
            func_ov003_021c212c(func_ov003_021c9e64);
            break;
        case 4:
            data_ov003_021da21c = 0;
            func_ov003_021cdbd0();
            func_ov003_021cdc10(9);
            func_ov003_021cefc0(0x41, 1, 1, -1, 0);
            func_ov003_021bf2d0();
            func_ov003_021c212c(func_ov003_021c9ccc);
            break;
        case 5:
            data_ov003_021da21c = 0;
            func_ov003_021cdbd0();
            func_ov003_021cdc10(0x12);
            func_ov003_021cefc0(0x42, 1, 1, -1, 0);
            func_ov003_021bf2d0();
            func_ov003_021c212c(func_ov003_021c9ccc);
            break;
    }
}
