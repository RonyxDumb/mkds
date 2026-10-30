#include "03/code_021d0ee0.h"
#include "03/code_021cfa68.h"
#include "03/code_021cfaa8.h"
#include "03/code_021d010c.h"
#include "03/code_021d0a88.h"
#include "03/code_021d0acc.h"
#include "03/code_021d0c58.h"
#include "03/code_021d0c84.h"
#include "03/code_021d0dd8.h"
#include "03/code_021d0df8.h"
#include "03/code_021d11d4.h"
#include "Main/Unknown/code_02009c04.h"

void func_ov003_021d0ee0(void) {
    switch (data_ov003_021da2ac->mUnk_a90) {
        case 1:
            if (data_ov003_021da2ac->mUnk_aac == 1) {
                data_ov003_021da2ac->mUnk_aac = 0;
                func_ov003_021d11d4();
                return;
            }
            if (data_ov003_021da2ac->mUnk_aac == 2) {
                data_ov003_021da2ac->mUnk_aac = 0;
                data_ov003_021da2ac->mUnk_a90 = 0x22;
            }
            return;
        case 2:
            func_ov003_021d0df8();
            return;
        case 3:
            func_ov003_021d0dd8();
            data_ov003_021da2ac->mUnk_a90 = 4;
            return;
        case 4:
            data_ov003_021da2ac->mUnk_a98++;
            func_ov003_021d0c84();
            return;
        case 5:
        case 6:
            func_ov003_021d0c84();
            return;
        case 7:
            func_ov003_021d0c58();
            return;
        case 8:
        case 9:
        case 10:
            func_ov003_021d0acc();
            return;
        case 11:
            func_ov003_021d0ab8();
            return;
        case 16:
            data_ov003_021da2ac->mUnk_a9c = 0;
            data_ov003_021da2ac->mUnk_a90 = 0x11;
            return;
        case 17:
            if (data_ov003_021da2ac->mUnk_a9c++ > 0x1e) {
                func_ov003_021d0a88();
            }
            return;
        case 18:
            func_02009c04();
            data_ov003_021da2ac->mUnk_a9c = 0;
            data_ov003_021da2ac->mUnk_a90 = 0x16;
            return;
        case 19:
            if (data_ov003_021da2ac->mUnk_a9c++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->mUnk_a90 = 0x14;
                }
            }
            return;
        case 21:
            func_ov003_021cfaa8();
            data_ov003_021da2ac->mUnk_a9c = 0;
            data_ov003_021da2ac->mUnk_a90 = 0x16;
            return;
        case 22:
            if (data_ov003_021da2ac->mUnk_a9c++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->mUnk_a90 = 0x17;
                }
            }
            return;
        case 24:
            func_ov003_021cfaa8();
            data_ov003_021da2ac->mUnk_a9c = 0;
            data_ov003_021da2ac->mUnk_a90 = 0x19;
            return;
        case 25:
            if (data_ov003_021da2ac->mUnk_a9c++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->mUnk_a90 = 0x1a;
                }
            }
            return;
        case 27:
            func_ov003_021cfaa8();
            data_ov003_021da2ac->mUnk_a9c = 0;
            data_ov003_021da2ac->mUnk_a90 = 0x1c;
            return;
        case 28:
            if (data_ov003_021da2ac->mUnk_a9c++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->mUnk_a90 = 0x1d;
                    return;
                } else {
                    u32 a = data_ov003_021da2ac->mUnk_a9c;

                    if (a % 0x1e == 1 && a > 0x37) {
                        func_ov003_021cfaa8();
                    }
                }
            }
            return;
        case 32:
            func_ov003_021cfaa8();
            data_ov003_021da2ac->mUnk_a9c = 0;
            data_ov003_021da2ac->mUnk_a90 = 0x21;
            return;
        case 33:
            if (data_ov003_021da2ac->mUnk_a9c++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->mUnk_a90 = 0x22;
                }
            }
            return;
        case 30:
            func_ov003_021cfaa8();
            return;
        case 34:
            return;
    }
}
