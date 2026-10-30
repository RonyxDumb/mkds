#include "03/code_021cd1c4.h"
#include "03/code_021cce78.h"
#include "03/code_021cd190.h"
#include "code_0214cfe4.h"
#include "code_02142eac.h"

u32 func_ov003_021cd1c4(void) {
    Unk021da26c *p;
    // volatile: the only spelling found that stores and reloads the argument on the stack.
    volatile u16 a = 0;
    func_0214cfe4(a, (*(Unk021da26c **) &data_ov003_021da26c)->mUnk_1300, 0x348);
    if (func_02143e10(*(Unk021da26c **) &data_ov003_021da26c, func_ov003_021cd080, 3) != 2) {
        return 0;
    }
    do {
        func_02143520(&(*(Unk021da26c **) &data_ov003_021da26c)->mUnk_168c);
    } while ((*(Unk021da26c **) &data_ov003_021da26c)->mUnk_168c.mUnk_00 != 2);
    p = *(Unk021da26c **) &data_ov003_021da26c;
    p->mUnk_1648 = data_ov003_021d6640;
    p->mUnk_1648.mUnk_00.mUnk_00 = p->mUnk_0f00;
    (*(Unk021da26c **) &data_ov003_021da26c)->mUnk_1648.mUnk_00.mUnk_08 = func_02143090();
    if (func_ov003_021cd190() != 0) {
        return 1;
    }
    return 0;
}
