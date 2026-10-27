#include "03/code_021cc658.h"
#include "03/code_021bf000.h"
#include "03/code_021c2120.h"
#include "03/code_021cc5a8.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"

void func_ov003_021cc658(void) {
    if (func_ov003_021d1f70(1) == 0) {
        func_ov003_021bf344();
        if ((u8) (data_ov003_021da258 + 0xfe) <= 1) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021cc5a8);
    }
}
