#include "Main/Unknown/code_0203a520.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_0204673c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

// non-matching: size 0x3bc against 0x3c0; in case 9 the original keeps the address of data_0217b488 in r2 for the
// loads after its first use (this source reloads the address into r0) and sets the stores of members 0x08 and 0x04
// in a different order around the member 0x74 branch; every other case has the same instructions.
void func_0203a520(Unk0203a0dc *a, u32 b) {
    s32 r;
    data_0217b488->mUnk_08 = 0;
    r = -1;
    switch (b) {
        case 10:
            func_02045a2c(0);
            r = 2;
            break;
        case 9:
            if (data_021759c0->mUnk_08 != 5) {
                u32 t;
                u32 f;
                Unk0217aa00 *q;
                f = 0;
                q = data_0217aa00;
                if (q == 0) {
                    t = 0;
                } else {
                    t = q->mUnk_0000;
                }
                if (t != 0) {
                    if (q->mUnk_0004 != 0xd) {
                        f = 1;
                    }
                }
                if (f != 0) {
                    if (data_021759d0->mUnk_1c_2 == 0) {
                        r = 1;
                    } else {
                        r = 6;
                        data_0217b488->mUnk_74 = 3;
                    }
                    data_0217b488->mUnk_08 = 4;
                    data_0217b488->mUnk_04 = 1;
                } else {
                    r = 0;
                }
                if (data_021759c0->mUnk_08 == 1) {
                    func_0204673c();
                }
            } else {
                r = 0xc;
                data_0217b488->mUnk_1c = 0;
            }
            break;
        case 1:
        case 3:
            r = 2;
            data_021759c0->mUnk_1e8.mUnk_0c = 0;
            break;
        case 8:
            r = 2;
            data_021759c0->mUnk_1e8.mUnk_0c = r;
            break;
        case 2:
            switch (data_021759c0->mUnk_08) {
                case 0:
                    func_02046740();
                    r = 2;
                    break;
                case 3:
                    if (func_02045914() != 0) {
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 2;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 1;
                        }
                    } else {
                        if (data_021759c0->mUnk_020 == 0) {
                            data_0217b488->mUnk_08 = 2;
                        }
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 1;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 3;
                        }
                    }
                    break;
                case 5:
                    if (func_02045874() != 0) {
                        r = 0xc;
                        data_0217b488->mUnk_1c = 3;
                    } else {
                        r = 0xa;
                        data_0217b488->mUnk_1c = 2;
                    }
                    break;
                case 2:
                    if (func_020458cc() != 0) {
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 2;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 1;
                        }
                    } else {
                        if (data_021759c0->mUnk_020 == 0) {
                            data_0217b488->mUnk_08 = 2;
                        }
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 1;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 3;
                        }
                    }
                    break;
            }
            break;
        case 7:
            switch (data_021759c0->mUnk_08) {
                case 0:
                    if (func_02045bd4() != 0) {
                        r = 2;
                    } else {
                        r = 0xa;
                    }
                    break;
                case 4:
                    r = 0;
                    break;
                case 2:
                case 3:
                    if (data_021759d0->mUnk_1c_2 != 0) {
                        r = 6;
                        data_0217b488->mUnk_74 = 2;
                    } else {
                        r = 0xa;
                    }
                    break;
            }
            break;
        case 5:
            r = 1;
            data_0217b488->mUnk_08 = r;
            break;
        case 4:
            data_0217b488->mUnk_08 = 2;
            r = 1;
            break;
        case 6:
            data_0217b488->mUnk_08 = 3;
            r = 1;
            break;
    }
    if (r != -1) {
        a->mUnk_04 = r;
    }
}
