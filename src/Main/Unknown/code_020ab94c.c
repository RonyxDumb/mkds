#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020a9ed8.h"
#include "Main/Unknown/code_020a9f40.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020ab194.h"
#include "Main/Unknown/unk_02156000.h"

#pragma thumb on

void func_020ab9d0(u32 a) {
    switch (a) {
        case 0:
            func_020a9f40(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 1:
            func_020a9ff4(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 2:
            func_020a9fc4(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 3:
            func_020a9f98(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 4:
            func_020a9f6c(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 5:
            func_020a9f40(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
    }
    data_0217b334->mUnk_4c = a;
}

void func_020ab94c(s32 a, s32 b) {
    data_0217b334->mUnk_50 = a;
    data_0217b334->mUnk_54 = b;
    func_020ab194(data_0217b334->mUnk_50, data_0217b334->mUnk_54);
    *(vu32 *) 0x4001018 = (-data_0217b334->mUnk_50 & 0x1ff) | ((-data_0217b334->mUnk_54 << 16) & 0x1ff0000);
    func_020a9efc(data_0217b334->mUnk_50 + data_0217b334->mUnk_58, data_0217b334->mUnk_54 + data_0217b334->mUnk_5c,
                  data_0217b334->mUnk_50 + data_0217b334->mUnk_60, data_0217b334->mUnk_54 + data_0217b334->mUnk_64);
    func_020a9ed8(data_0217b334->mUnk_50 + data_0217b334->mUnk_68, data_0217b334->mUnk_54 + data_0217b334->mUnk_6c,
                  data_0217b334->mUnk_50 + data_0217b334->mUnk_70, data_0217b334->mUnk_54 + data_0217b334->mUnk_74);
}

#pragma thumb off
