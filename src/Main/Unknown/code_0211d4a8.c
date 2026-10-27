#include "Main/Unknown/code_0211d4a8.h"

#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0211d650.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_0211d56c(void) {
    u32 a = 1;
    u16 h = data_0217d368->mUnk_04->mUnk_06;
    Unk027ffc40 *v;

    if (data_0217d368->mUnk_7c != 0) {
        data_0217d368->mUnk_60 = 0;
        data_0217d368->mUnk_7c = 0;
        if (data_0217d368->mUnk_14[h + data_0215cd4c[data_0217d368->mUnk_60].mUnk_00].mUnk_00 == 0 ||
            (func_0211d650() == 8 && data_0217d368->mUnk_60 == 1)) {
            a = 0;
            func_0211d56c();
        }
    } else {
        data_0217d368->mUnk_60++;
        if (data_0217d368->mUnk_60 >= 5) {
            data_0217d368->mUnk_60--;
            data_0217d368->mUnk_7c = a;
            v = (Unk027ffc40 *) 0x027ffc40;
            if (v->mUnk_00 != 2) {
                func_0212b7fc();
            }
        } else if (data_0217d368->mUnk_14[h + data_0215cd4c[data_0217d368->mUnk_60].mUnk_00].mUnk_00 == 0 ||
                   (func_0211d650() == 8 && data_0217d368->mUnk_60 == 1)) {
            a = 0;
            func_0211d56c();
        }
    }
    if (a != 0) {
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

void func_0211d4a8(void) {
    u32 a = 1;
    u16 h = data_0217d368->mUnk_04->mUnk_06;
    Unk027ffc40 *v;

    if (data_0217d368->mUnk_7c != 0) {
        data_0217d368->mUnk_60 = 4;
        data_0217d368->mUnk_7c = 0;
        if (data_0217d368->mUnk_14[h + data_0215cd4c[data_0217d368->mUnk_60].mUnk_00].mUnk_00 == 0 ||
            (func_0211d650() == 8 && data_0217d368->mUnk_60 == 1)) {
            a = 0;
            func_0211d4a8();
        }
    } else {
        data_0217d368->mUnk_60--;
        if (data_0217d368->mUnk_60 < 0) {
            data_0217d368->mUnk_60++;
            data_0217d368->mUnk_7c = a;
            v = (Unk027ffc40 *) 0x027ffc40;
            if (v->mUnk_00 != 2) {
                func_0212b7fc();
            }
        } else if (data_0217d368->mUnk_14[h + data_0215cd4c[data_0217d368->mUnk_60].mUnk_00].mUnk_00 == 0 ||
                   (func_0211d650() == 8 && data_0217d368->mUnk_60 == 1)) {
            a = 0;
            func_0211d4a8();
        }
    }
    if (a != 0) {
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

#pragma thumb off
