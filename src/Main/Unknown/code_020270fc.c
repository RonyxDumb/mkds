#include "Main/Unknown/code_020270fc.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025f54.h"
#include "Main/Unknown/code_02027188.h"
#include "Main/Unknown/code_0202719c.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_020270fc(s32 a) {
    data_02174e14->mUnk_064 = a;
    switch (data_02174e14->mUnk_07c) {
        case 8:
            func_02027be0();
            break;
        case 9:
            func_02027a58();
            break;
        case 10:
            func_02027850();
            break;
        case 11:
            func_02027648();
            break;
        case 12:
            func_02027448();
            break;
    }
    func_02027188();
    func_0202721c();
    func_02025f54((u32 *) &data_02174e14->mUnk_0f8, 0);
    data_02174e14->mUnk_0f0 = data_02174e14->mUnk_090[data_02174e14->mUnk_060].mUnk_00;
    data_02174e14->mUnk_0f4 = func_02025e60(data_02174e14->mUnk_0f0);
}

#pragma thumb off
