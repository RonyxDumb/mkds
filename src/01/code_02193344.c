#include "01/code_02193344.h"
#include "01/code_02195000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"

void func_ov001_021933dc(void) {
    int i;
    int zero = 0;

    for (i = 0; i < 3; i++) {
        if (i == data_ov001_021a9bd4->mUnk_08 && data_ov001_021a9bd4->mUnk_14 != 0) {
            data_ov001_021a9bd4->mUnk_20[data_ov001_021a65e0[i]].mUnk_00 = 1;
            func_02124a20(data_ov001_021a65d8[i], 14, data_ov001_021a9bd4->mUnk_24, data_ov001_021a9bd4->mUnk_30);
        } else {
            data_ov001_021a9bd4->mUnk_20[data_ov001_021a65e0[i]].mUnk_00 = zero;
            func_02124a20(data_ov001_021a65d8[i], 15, data_ov001_021a9bd4->mUnk_24, data_ov001_021a9bd4->mUnk_30);
        }
    }
}

void func_ov001_02193344(void) {
    Unk021a9bd4 *obj;

    data_ov001_021a9bd4->mUnk_00 = data_ov001_021a9bd4->mUnk_04;
    switch (data_ov001_021a9bd4->mUnk_00) {
        case 0:
            func_ov001_02193a00();
            break;
        case 1:
            func_ov001_02193944();
            break;
        case 2:
            func_ov001_02193924();
            break;
        case 3:
            func_ov001_02193774();
            break;
        case 4:
            func_ov001_02193730();
            break;
        case 5:
            func_ov001_021935f8();
            break;
        case 6:
            func_ov001_02193578();
            break;
        case 7:
            func_ov001_02193514();
            break;
        case 8:
            func_ov001_0219348c();
            break;
        case 9:
            func_ov001_02193448();
            break;
    }
    func_ov001_021933dc();
    obj = data_ov001_021a9bd4;
    func_02124c30(obj->mUnk_30, obj->mUnk_24, 0, func_ov001_0219e90c(), obj->mUnk_20);
}
