#include "Main/Unknown/code_020b846c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"

// non-matching: the product address of the table element in the case-5 path is in r3 (original: ip) and the loaded word
// in r1 (original: r3); 5 words differ in register choice only
u32 func_020b846c(u32 a) {
    u32 r;
    Unk020ee684 *p;

    r = 0xb;
    switch (a) {
        case 0:
            r = 0x12;
            break;
        case 1:
            r = 0x10;
            break;
        case 2:
            r = 0x17;
            break;
        case 3:
            r = 0x14;
            break;
        case 4:
            r = 0xd;
            break;
        case 5:
            p = &(*(Unk020ee684 **) data_027e00c8)[func_020b4d9c()];
            switch (data_0217bc48[p->mUnk_030.mUnk_00].mUnk_08 == 3 ? (u16) p->mUnk_030.mUnk_08 : 0) {
                case 1:
                    r = 0xd;
                    break;
                case 2:
                    r = 0xe;
                    break;
                case 0:
                case 3:
                    r = 0xf;
                    break;
            }
            break;
        case 6:
            r = 0x16;
            break;
        case 7:
            r = 0x1b;
            break;
        case 8:
            r = 0x19;
            break;
        case 9:
            r = 0x13;
            break;
        case 10:
            r = 0x18;
            break;
        case 11:
            r = 0x11;
            break;
        case 12:
            r = 0x1a;
            break;
        case 13:
            r = 0x1e;
            break;
        case 14:
            r = 0x1c;
            break;
        case 15:
            r = 0x1d;
            break;
        case 16:
            r = 0x15;
            break;
        case 17:
            r = 0x1f;
            break;
        case 18:
        case 19:
            break;
    }
    return r;
}
