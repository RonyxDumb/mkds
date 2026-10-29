#include "Main/Unknown/code_020ca844.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020ca984.h"
#include "Main/Unknown/code_020ca9ac.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020ca844(void) {
    data_0217b438->mUnk_24++;
    if (data_0217b438->mUnk_24 >= 0x32) {
        data_0217b438->mUnk_24 = 0;
    }
    if (data_0217b438->mUnk_14 == 0 && data_0217b438->mUnk_18 == 0 && data_0217b438->mUnk_00 != 0 &&
        data_0217b438->mUnk_04 != 0) {
        if (func_020cacc0()) {
            data_0217b438->mUnk_14 = 1;
        } else if (func_020ca9ac(func_020ca9dc(), 1)) {
            data_0217b438->mUnk_14 = 1;
            data_0217b438->mUnk_10 = 1;
            switch (data_0217b438->mUnk_20) {
                case 0:
                    func_020ca984(0x10);
                    break;
                case 1:
                    func_020ca984(0xb);
                    break;
                case 2:
                    func_020ca984(5);
                    break;
            }
        } else if (func_020ca9ac(func_020ca9dc(), 10)) {
            data_0217b438->mUnk_18 = 1;
            func_020ca984(0x10);
        }
        if (func_020ca9ac(func_020ca9dc(), 0x40)) {
            func_020cadac(-1);
        } else if (func_020ca9ac(func_020ca9dc(), 0x80)) {
            func_020cadac(1);
        }
    }
    if (data_0217b438->mUnk_14 != 0) {
        data_0217b438->mUnk_14++;
        if (data_0217b438->mUnk_14 > 0xf) {
            if (data_0217b438->mUnk_00 != 0) {
                data_0217b438->mUnk_1c = data_0217b438->mUnk_20;
                data_0217b438->mUnk_14 = 0;
            }
            data_0217b438->mUnk_14 = 0;
            data_0217b438->mUnk_10 = 0;
        }
    }
    if (data_0217b438->mUnk_18 != 0) {
        data_0217b438->mUnk_18++;
        if (data_0217b438->mUnk_18 > 4) {
            if (data_0217b438->mUnk_00 != 0) {
                data_0217b438->mUnk_1c = -2;
                data_0217b438->mUnk_14 = 0;
            }
            data_0217b438->mUnk_18 = 0;
        }
    }
}
#pragma thumb off
