#include "03/code_021ca6f4.h"
#include "03/code_021bf2d0.h"
#include "03/code_021c2120.h"
#include "03/code_021ca56c.h"
#include "03/code_021cd0d0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"

void func_ov003_021ca6f4(void) {
    int a;
    int b;
    int i;
    data_ov003_021da22c++;
    if (data_ov003_021da22c >= 0x12c) {
        func_ov003_021cdbd0();
        a = func_ov003_021cd0d0(&b);
        if (a == 0) {
            *(u8 *) &data_ov003_021da228 = 2;
            func_ov003_021cefc0(0x43, 1, 1, -1, 0);
            func_ov003_021cdc10(0x12);
            func_ov003_021bf2d0();
            func_ov003_021c212c(func_ov003_021ca588);
            return;
        }
        for (i = 0; i < a; i++) {
            if (*(u8 *) (b + i * 0x2a + 0x28) != 2) {
                break;
            }
        }
        if (i == a) {
            *(u8 *) &data_ov003_021da228 = 3;
            func_ov003_021cefc0(0x42, 1, 1, -1, 0);
            func_ov003_021cdc10(0x12);
            func_ov003_021bf2d0();
            func_ov003_021c212c(func_ov003_021ca588);
        } else {
            *(u8 *) &data_ov003_021da228 = 1;
            func_ov003_021cdc10(0xf);
            func_ov003_021c212c(func_ov003_021ca688);
        }
    }
}
