#include "03/code_021ccd18.h"
#include "03/code_021ccb1c.h"
#include "03/code_021ccc08.h"
#include "03/code_021cdbfc.h"
#include "03/code_021cdc10.h"
#include "03/code_021d2940.h"

void func_ov003_021ccd18(void) {
    (*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1d = 0;
    switch ((*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1c) {
    case 0:
        if ((*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1e == 0) {
            switch (func_ov003_021ccb50()) {
            case 1:
                if ((*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1b != 0) {
                    func_ov003_021cdc10(0x16);
                    func_ov003_021cdbfc(0);
                    (*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1d = 1;
                    func_ov003_021d2940((*(Unk021cca74 **) &data_ov003_021da268)->mUnk_14);
                    (*(Unk021cca74 **) &data_ov003_021da268)->mUnk_18 = (*(Unk021cca74 **) &data_ov003_021da268)->mOffset;
                    (*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1c = 1;
                }
                break;
            case 2:
                func_ov003_021ccc08(2);
                break;
            case 3:
                func_ov003_021ccc08(3);
                break;
            case 4:
                func_ov003_021ccbbc();
                break;
            }
        }
        break;
    case 1:
        func_ov003_021ccc90();
        break;
    case 2:
        if (func_ov003_021ccb1c(2) != 2) {
            (*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1d = 5;
            (*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1c = 0;
        } else if (func_ov003_021ccb50() == 2) {
            func_ov003_021ccc08(2);
        }
        break;
    case 3:
        if (func_ov003_021ccb1c(3) != 3) {
            (*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1d = 7;
            (*(Unk021cca74 **) &data_ov003_021da268)->mUnk_1c = 0;
        } else if (func_ov003_021ccb50() == 3) {
            func_ov003_021ccc08(3);
        }
        break;
    }
}
