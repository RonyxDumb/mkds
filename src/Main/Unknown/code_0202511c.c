#include "Main/Unknown/code_0202511c.h"

static inline void copy_entry(u8 *dst, s32 i) {
    u8 *t = data_0215316c[i].mUnk_00;
    dst[0] = t[0];
    dst[1] = t[1];
    dst[2] = t[2];
    dst[3] = t[3];
}

// non-matching: 75.2%; same case bodies, the table-entry byte copies and the register use around them differ
u32 func_0202511c(s32 a, void *c) {
    u8 *b = (u8 *) c;
    s32 r;
    s32 f;
    s32 q;
    s32 s;
    s32 t;
    u8 v1[4];

    r = 0x36;
    f = 0;
    switch (a) {
    case 0:
        r = 0x33;
        break;
    case 1:
        r = 0x32;
        break;
    case 2:
        switch (data_021759c0->mUnk_00c) {
        case 0:
        case 2:
            q = data_021759c0->mUnk_08;
            r = func_0202553c(data_021759c0->mUnk_00, b);
            f = 1;
            if (q == 4) {
                s = 0;
                if (data_021759c0->mUnk_2e == 4) {
                    b[1] = 0x2a;
                    s = 1;
                }
                if (s == 0) {
                    switch (data_021759c0->mUnk_2f) {
                    case 1:
                        b[1] = 0x2c;
                        break;
                    case 10:
                        break;
                    }
                }
                t = 1;
                switch (data_021759c0->mUnk_2e) {
                case 9:
                case 10:
                    b[2] = 0x25;
                    break;
                case 0x32:
                    b[2] = 0x26;
                    break;
                case 0x15:
                    b[2] = 0x27;
                    break;
                case 0x33:
                    b[2] = 0x28;
                    break;
                case 0x11:
                    b[2] = 0x29;
                    break;
                case 0x31:
                    break;
                default:
                    t = 0;
                    break;
                }
                if (t != 0) {
                    b[3] = 0x22;
                }
            }
            break;
        case 1:
            r = 0x33;
            break;
        case 3:
            switch (data_021759c0->mUnk_00) {
            case 0xe:
            case 0x14:
            case 0x19:
                r = 2;
                break;
            case 0x22:
                r = 3;
                break;
            case 0x21:
                r = 4;
                break;
            default:
                r = 1;
                break;
            }
            if (func_021054d0() != 0) {
                r = 6;
            } else {
                copy_entry(b, r);
                f = 1;
                func_0202553c(data_021759c0->mUnk_00, v1);
                b[2] = v1[2];
            }
            break;
        case 4:
            r = 5;
            break;
        case 5:
            r = 0x2a;
            break;
        case 6:
            r = 0x33;
            break;
        }
        break;
    case 4:
    case 5:
        r = 0x33;
        break;
    case 6:
        if (*(u16 *) 0x027ffc40 == 2) {
            r = 0x33;
        } else {
            r = 0x2e;
        }
        break;
    case 8:
        r = 0x2f;
        break;
    case 9:
        r = 0x31;
        break;
    case 10:
        r = 0x29;
        copy_entry(b, r);
        f = 1;
        b[1] = func_0211127c();
        break;
    case 12:
        r = 0x2d;
        break;
    case 13:
        r = 0x2e;
        break;
    case 3:
    case 7:
    case 11:
    case 14:
        r = 0x30;
        copy_entry(b, r);
        f = 1;
        if (data_0217d060 != 0) {
            b[1] = 0xff;
            b[2] = 0xff;
            b[3] = 0xff;
        }
        break;
    case 15:
        r = 0x33;
        break;
    }
    if (f == 0 && b != 0) {
        copy_entry(b, r);
    }
    return r;
}

u32 func_0202553c(u32 a, void *c) {
    Unk0215316c *b = (Unk0215316c *) c;
    u32 r;

    r = 0x36;
    switch (a) {
    case 20:
        r = 7;
        break;
    case 25:
        r = 34;
        break;
    case 14:
        r = 8;
        break;
    case 1:
        r = 9;
        break;
    case 31:
        r = 10;
        break;
    case 22:
        r = 11;
        break;
    case 9:
        r = 12;
        break;
    case 11:
        r = 13;
        break;
    case 16:
        r = 14;
        break;
    case 28:
        r = 15;
        break;
    case 19:
        r = 16;
        break;
    case 34:
        r = 17;
        break;
    case 33:
        r = 32;
        break;
    case 38:
        r = 18;
        break;
    case 26:
        r = 19;
        break;
    case 18:
        r = 20;
        break;
    case 10:
        r = 21;
        break;
    case 15:
        r = 22;
        break;
    case 35:
        r = 23;
        break;
    case 39:
        r = 24;
        break;
    case 13:
        r = 25;
        break;
    case 37:
        r = 26;
        break;
    case 24:
        r = 27;
        break;
    case 23:
        r = 29;
        break;
    case 36:
        r = 28;
        break;
    case 30:
        r = 30;
        break;
    case 27:
        r = 31;
        break;
    case 17:
        r = 33;
        break;
    case 32:
        r = 37;
        break;
    case 29:
        r = 35;
        break;
    case 12:
        r = 36;
        break;
    case 40:
        r = 38;
        break;
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
        r = 39;
        break;
    case 48:
    case 49:
    case 50:
    case 51:
        r = 40;
        break;
    case 52:
        r = 42;
        break;
    case 53:
        r = 51;
        break;
    }
    if (b != 0) {
        *b = data_0215316c[r];
    }
    return r;
}
