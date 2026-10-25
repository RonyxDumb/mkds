#include "01/code_0219e2b4.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02037000.h"

void func_ov001_0219e2b4(void)
{
    Unk021ca400 *p;

    data_ov001_021ca400->mUnk_008++;
    p = data_ov001_021ca400;
    if (p->mUnk_008 > data_ov001_021a6c50[3]) {
        p->mUnk_004 = 4;
        data_ov001_021ca400->mUnk_008 = 0;
        func_020370d4(data_ov001_021a6c50[4]);
        func_ov001_0219e5a0();
    }
}
