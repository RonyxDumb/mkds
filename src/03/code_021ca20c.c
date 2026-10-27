#include "03/code_021ca20c.h"
#include "03/code_021bf2d0.h"
#include "03/code_021c2120.h"
#include "03/code_021c2938.h"
#include "03/code_021ca108.h"
#include "03/code_021ca270.h"
#include "03/code_021cd000.h"
#include "03/code_021cdc10.h"
#include "03/code_021ce000.h"
#include "03/unk_021da000.h"

void func_ov003_021ca20c(void) {
    switch (func_ov003_021c2938()) {
        case 1:
            data_ov003_021da224 = 1;
            func_ov003_021c212c(func_ov003_021ca350);
            break;
        case 4:
            data_ov003_021da224 = 0;
            func_ov003_021cdbd0();
            func_ov003_021cdc10(9);
            func_ov003_021cefc0(0x41, 1, 1, -1, 0);
            func_ov003_021bf2d0();
            func_ov003_021c212c(func_ov003_021ca1e4);
            break;
    }
}
