#include "03/code_021bf760.h"
#include "03/code_021bf698.h"
#include "03/code_021d1000.h"

void func_ov003_021bf760(u32 param_0, u32 param_1, u32 param_2, u32 param_3) {
    s32 i;
    u8 *a;
    s32 b;

    func_ov003_021bf698();
    i = 0;
    a = data_ov003_021d5f4c + param_0 * 2;
    b = i;
    for (; i < 2; i++) {
        *(u32 *) (*(int *) &data_ov003_021da150 + b) = func_ov003_021d1be4(0, *a, 1);
        func_ov003_021d1790(*(u32 *) (*(int *) &data_ov003_021da150 + b), -1, 1);
        a++;
        b += 4;
    }
    func_ov003_021d17d4(*(u32 *) *(int *) &data_ov003_021da150, -1, param_1, param_3);
    func_ov003_021d17d4(*(u32 *) (*(int *) &data_ov003_021da150 + 4), -1, param_2, param_3);
}
