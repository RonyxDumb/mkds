#include "Main/Unknown/code_020472e4.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_020473a8.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

void func_020472e4(void *a, void *b) {
    u8 c[128];
    func_0204f5e4();
    func_0201804c(data_021759c8->mUnk_a80, 3);
    func_02047498(data_02164e88, 2);
    func_02047468(data_02164ea0, 3);
    if (b == (void *) 3) {
        func_02047498(data_02164eb4, 4);
        func_02047468(data_02164ed0, 5);
    } else {
        func_02047498(data_02164ee8, 4);
        func_02047468(data_02164f04, 5);
    }
    data_021759c8->mUnk_a74 = b;
    func_0201804c(data_021759c8->mUnk_a7c, 3);
    func_02048498(c, a, 0);
    func_02047498(c, 6);
    func_02048498(c, a, 1);
    func_02047498(c, 7);
    data_021759c8->mUnk_a70 = a;
}

#pragma thumb off
