#include "01/code_0219ca2c.h"

void func_ov001_0219ca2c(void) {
    if (func_02127788() != 0) {
        if (data_ov001_021a9bf8->mUnk_28 == -2 || data_ov001_021a9bf8->mUnk_28 == -1) {
            if (func_02127794() == 1) {
                data_ov001_021a9bf8->mUnk_04 = 6;
            } else {
                data_ov001_021a9bf8->mUnk_04 = 2;
            }
        } else {
            if (func_02127794() == 0) {
                data_ov001_021a9bf8->mUnk_04 = 6;
                func_021282c8();
                data_ov001_021a9bf8->mUnk_2c = 1;
            } else {
                data_ov001_021a9bf8->mUnk_04 = 2;
            }
        }
        func_021277e4();
    }
}
