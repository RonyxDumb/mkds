#include "01/code_0219e6ec.h"
#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"

int func_ov001_0219e824(void *param_1)
{
    Unk021a9034 callbacks = {
        func_ov001_0219e8d8, func_ov001_0219e858, func_ov001_0219e8c0, func_ov001_0219e89c, 0, 0, 10, 10, 0,
    };

    func_020487fc(param_1, &callbacks);
    return 0;
}

void func_ov001_0219e6ec(void *param_1)
{
    void *result;

    data_ov001_021ca400 = func_02036bec(param_1, 0x470);
    data_ov001_021ca400->mUnk_010 = param_1;
    data_ov001_021ca400->mUnk_01c = func_021250b0(param_1);
    data_ov001_021ca400->mUnk_014 = -1;
    data_ov001_021ca400->mUnk_000 = 0;
    data_ov001_021ca400->mUnk_004 = data_ov001_021ca400->mUnk_000;
    data_ov001_021ca400->mUnk_008 = 0;
    if (data_021759c0->mUnk_00 == 0x36) {
        data_ov001_021ca400->mUnk_00c = 1;
    } else {
        data_ov001_021ca400->mUnk_00c = 0;
    }
    data_ov001_021ca400->mUnk_018 = 0;
    data_ov001_021ca400->mUnk_46c = func_02047a28("common.bmg");
    func_ov001_0219e660();
    func_ov001_0219e38c();
    func_020ae6d4(data_ov001_021ca400->mUnk_068, 0);
    func_02124ed0(data_ov001_021ca400->mUnk_010, data_ov001_021ca400->mUnk_030, data_ov001_021ca400->mUnk_034,
                  &data_ov001_021ca400->mUnk_020);
    result = 0;
    *data_ov001_021ca400->mUnk_020 = 0;
    {
        u16 table[2][2] = {{200, 24}, {200, 24}};

        switch (data_ov001_021ca400->mUnk_00c) {
        case 0:
            result = func_020b3f7c(data_ov001_021ca400->mUnk_46c, 0x77);
            break;
        case 1:
            result = func_020b3f7c(data_ov001_021ca400->mUnk_46c, 0x78);
            break;
        }
        func_021243ac(data_ov001_021ca400->mUnk_010, 0, data_ov001_021ca400->mUnk_034,
                      table[data_ov001_021ca400->mUnk_00c][0], table[data_ov001_021ca400->mUnk_00c][1], 0,
                      data_ov001_021ca400->mUnk_024, data_ov001_021ca400->mUnk_030, data_ov001_021ca400->mUnk_020,
                      0x8000);
        func_0212426c(0, 0, data_ov001_021ca400->mUnk_034, result, data_ov001_021ca400->mUnk_030,
                      data_ov001_021ca400->mUnk_020);
    }
}
