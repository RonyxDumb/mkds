#include "Main/Unknown/code_020303e8.h"
#include "Main/Unknown/code_0203003c.h"
#include "Main/Unknown/code_02030654.h"
#include "Main/Unknown/code_0203062c.h"
#include "Main/Unknown/code_02030688.h"
#include "Main/Unknown/code_020306b8.h"
#include "Main/Unknown/code_020306e0.h"
#include "Main/Unknown/code_02030708.h"
#include "Main/Unknown/code_020307b8.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

s32 func_020303e8(void) {
    Unk02174e54 *o;
    s32 r;
    s32 a;
    s32 b;
    s32 c;
    u16 i;

    r = -1;
    i = func_020435bc();
    o = data_02174e54;
    switch (o->mUnk_30) {
        case 0:
            o->mUnk_34++;
            if (data_02174e54->mUnk_34 < 10) {
                data_02174e54->mUnk_38 = func_020ae4c0(1, -0xc0, 0, data_02174e54->mUnk_34, 10);
            } else {
                data_02174e54->mUnk_34 = 0;
                data_02174e54->mUnk_38 = 0;
                data_02174e54->mUnk_30 = 1;
            }
            func_020309d8();
            break;
        case 1:
            a = 0;
            b = -1;
            if (func_02030708(i) != 0) {
                b = func_020306e0(i);
                c = func_020306b8(i);
                a = func_02128210(b, c);
                b = func_020291c4(b, c, o->mUnk_10);
            }
            if (func_02030688(i, 1) != 0) {
                func_0204aa28(data_02174e54->mUnk_28 == 1 ? 1 : 0);
                data_02174e54->mUnk_2c = 2;
                data_02174e54->mUnk_30 = 2;
                func_02030954(0);
                func_02030654(4);
            } else if (func_02030688(i, 2) != 0 || a != 0) {
                data_02174e54->mUnk_2c = 0;
                data_02174e54->mUnk_30 = 3;
                func_02128310(0);
            } else if (func_02030688(i, 0x40) != 0 && data_02174e54->mUnk_28 > 0) {
                data_02174e54->mUnk_28--;
                func_02030954(1);
                func_0203062c(0);
            } else if (func_02030688(i, 0x80) != 0 && data_02174e54->mUnk_28 < 1) {
                data_02174e54->mUnk_28++;
                func_02030954(1);
                func_0203062c(0);
            } else if (b == 0) {
                data_02174e54->mUnk_30 = 2;
                func_02030954(data_02174e54->mUnk_28 != 0 ? 1 : 0);
                func_02030654(4);
                data_02174e54->mUnk_28 = 0;
                func_0204aa28(0);
                data_02174e54->mUnk_2c = 2;
            } else if (b == 1) {
                data_02174e54->mUnk_30 = 2;
                func_02030954(data_02174e54->mUnk_28 != 1 ? 1 : 0);
                func_02030654(4);
                data_02174e54->mUnk_28 = 1;
                func_0204aa28(1);
                data_02174e54->mUnk_2c = 2;
            }
            break;
        case 2:
            o->mUnk_34++;
            if (data_02174e54->mUnk_34 >= 5) {
                data_02174e54->mUnk_34 = 0;
                data_02174e54->mUnk_30 = 3;
                func_02030954(1);
            }
            break;
        case 3:
            o->mUnk_34++;
            if (data_02174e54->mUnk_34 < 10) {
                data_02174e54->mUnk_38 = func_020ae4c0(1, 0, -0xc0, data_02174e54->mUnk_34, 10);
            } else {
                data_02174e54->mUnk_38 = 0;
                data_02174e54->mUnk_30 = 4;
            }
            func_020309d8();
            break;
        case 4:
            r = o->mUnk_2c;
            break;
    }
    if (data_02174e54->mUnk_30 != 4) {
        func_02124c30(o->mUnk_0c, o->mUnk_08, o->mUnk_14, data_02174e54->mUnk_20, o->mUnk_18);
    }
    return r;
}

#pragma thumb off
