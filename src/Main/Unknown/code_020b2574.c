#include "Main/Unknown/code_020b2574.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b29b0.h"
#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2a74.h"
#include "Main/Unknown/code_020b2b24.h"
#include "Main/Unknown/code_020b2b54.h"
#include "Main/Unknown/code_020b2b70.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b2ecc.h"
#include "Main/Unknown/code_020b3278.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020b2574(void) {
    s32 a;

    data_0217b354->mUnk_004 = data_0217b354->mUnk_000;
    data_0217b354->mUnk_034 = data_0217b354->mUnk_034 + 1;
    if (data_0217b354->mUnk_034 >= 0x32) {
        data_0217b354->mUnk_034 = 0;
    }
    if (func_020b2bf0() != 0) {
        return;
    }
    if ((func_020b252c() == 0 || func_020b252c() == 1) && func_020b24e4() == 2 && func_0203c0bc() != 0) {
        return;
    }
    if (data_0217b354->mUnk_014 == 0 && data_0217b354->mUnk_018 == 0 && func_020b32ec() == 0) {
        if (func_020b2bc8() != 0) {
            if (func_020b2b70() != 0) {
                if (func_020b252c() == 4 && func_020b2b5c() != 0 && func_020b2f58() != 0) {
                    if (func_020b2b24(func_020b2b54(), 1) != 0 || func_020b2a74(func_020b2b54()) != 0) {
                        data_0217b354->mUnk_024 = 10;
                        data_0217b354->mUnk_028 = data_0217b354->mUnk_024;
                        data_0217b354->mUnk_00c = 1;
                        func_020b3278();
                    }
                } else if (func_020b252c() == 4 && func_020b2ecc() != 0) {
                    if (func_020b2b24(func_020b2b54(), 1) != 0 || func_020b2a74(func_020b2b54()) != 0) {
                        data_0217b354->mUnk_024 = 6;
                        data_0217b354->mUnk_028 = data_0217b354->mUnk_024;
                        data_0217b354->mUnk_00c = 1;
                        func_020b3278();
                        func_020b2a60(1);
                    }
                } else if (func_020b252c() == 4 && func_020b2b5c() != 0) {
                    if (func_020b2b24(func_020b2b54(), 1) != 0 || func_020b2a74(func_020b2b54()) != 0) {
                        data_0217b354->mUnk_024 = 6;
                        data_0217b354->mUnk_028 = data_0217b354->mUnk_024;
                        data_0217b354->mUnk_00c = 1;
                        func_020b3278();
                    }
                } else if (func_020b2b24(func_020b2b54(), 8) != 0) {
                    if (func_020b2e98() != 0) {
                        func_02105c4c();
                        data_0217b354->mUnk_018 = 1;
                    } else {
                        func_02105d70();
                        func_020b2f88(1);
                    }
                } else if (func_020b302c() != 0) {
                    data_0217b354->mUnk_014 = 1;
                } else if (func_020b2b24(func_020b2b54(), 1) != 0) {
                    if (func_020b2e98() != 0) {
                        if (data_0217b354->mUnk_028 == 0) {
                            func_02105c4c();
                        } else {
                            func_020b3278();
                        }
                        data_0217b354->mUnk_014 = 1;
                        data_0217b354->mUnk_010 = 1;
                    } else {
                        func_02105d70();
                        func_020b2f88(1);
                    }
                } else if (func_020b2b24(func_020b2b54(), 2) != 0) {
                    if (func_020b2e98() != 0) {
                        func_02105c4c();
                        data_0217b354->mUnk_018 = 1;
                    }
                } else if (func_020ae408(func_020b2b54(), 0x40) != 0) {
                    func_020b3120(-1);
                } else if (func_020ae408(func_020b2b54(), 0x80) != 0) {
                    func_020b3120(1);
                }
            }
        } else if (func_020b29c4() != 0) {
            if (func_020b2b24(func_020b2b54(), 8) != 0) {
                if (func_020b2e98() != 0) {
                    func_02105c4c();
                    data_0217b354->mUnk_018 = 1;
                } else {
                    func_02105d70();
                    func_020b2f88(1);
                }
            } else if (func_020b302c() != 0) {
                data_0217b354->mUnk_014 = 1;
            } else if (func_020b2b24(func_020b2b54(), 1) != 0) {
                if (func_020b2e98() != 0) {
                    if (data_0217b354->mUnk_028 == 0) {
                        func_02105c4c();
                    } else {
                        func_020b3278();
                    }
                    data_0217b354->mUnk_014 = 1;
                    data_0217b354->mUnk_010 = 1;
                }
            } else if (func_020b2b24(func_020b2b54(), 2) != 0) {
                if (func_020b2e98() != 0) {
                    func_02105c4c();
                    data_0217b354->mUnk_018 = 1;
                }
            } else if (func_020ae408(func_020b2b54(), 0x40) != 0) {
                func_020b3120(-1);
            } else if (func_020ae408(func_020b2b54(), 0x80) != 0) {
                func_020b3120(1);
            }
        }
    }
    a = data_0217b354->mUnk_014;
    if (a != 0) {
        data_0217b354->mUnk_014 = a + 1;
        if (data_0217b354->mUnk_014 > 0xf) {
            if (func_020b2bc8() != 0) {
                if (func_020b2e98() != 0) {
                    data_0217b354->mUnk_024 = data_0217b354->mUnk_028;
                    func_020b2f88(0);
                } else {
                    func_020b2f88(1);
                }
            } else if (func_020b2e98() != 0) {
                data_0217b354->mUnk_024 = data_0217b354->mUnk_028;
                func_020b2f88(0);
            }
            data_0217b354->mUnk_014 = 0;
            data_0217b354->mUnk_010 = 0;
        }
    }
    a = data_0217b354->mUnk_018;
    if (a != 0) {
        data_0217b354->mUnk_018 = a + 1;
        if (data_0217b354->mUnk_018 > 4) {
            if (func_020b2bc8() != 0) {
                if (func_020b2e98() != 0) {
                    func_020b2f88(0);
                } else {
                    func_020b2f88(1);
                }
            } else if (func_020b2e98() != 0) {
                func_020b2f88(0);
            }
            data_0217b354->mUnk_018 = 0;
        }
    }
    if (func_020b29b0() != 0 && func_020b252c() == 5 && func_020b2bc8() != 0) {
        data_0217b354->mUnk_01c = data_0217b354->mUnk_01c + 1;
        if (data_0217b354->mUnk_01c > 0x384) {
            data_0217b354->mUnk_024 = func_020b24f8() != 4 ? 2 : 7;
        }
    }
    if (func_020b2ec0() != 0) {
        a = data_0217b354->mUnk_030;
        data_0217b354->mUnk_030 = a + 1;
        if (a >= 1) {
            data_0217b354->mUnk_02c = 2;
            data_0217b354->mUnk_030 = 1;
        }
    } else {
        data_0217b354->mUnk_02c = 0;
        data_0217b354->mUnk_030 = 0;
    }
}
#pragma thumb off
