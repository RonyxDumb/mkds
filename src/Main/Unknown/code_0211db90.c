#include "Main/Unknown/code_0211db90.h"

#pragma thumb on

void func_0211dd44(void) {
    u32 uVar1;
    Unk020b4934 *local_20;
    Unk02021dc8 *local_1c;
    Unk020b4a44 *local_18;
    Unk020b4934 *local_14;
    Unk020b47d8 *local_10;
    Unk020b4a44 *local_c[1];
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbe4))));
    func_020b496c(&local_14, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbf0))));
    func_020b4810(&local_10, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbd8))));
    func_020b4a7c(local_c, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dc08))));
    func_020b496c(&local_14, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbdc))));
    func_020b4810(&local_10, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbf8))));
    func_020b49f4(&local_20, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dc04))));
    func_020b48ec(&local_1c, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbec))));
    func_020b4a7c(&local_18, (void *) uVar1);
    func_02116e70();
}

void func_0211db90(void) {
    u32 uVar1;
    int local_10;
    int local_c;
    int local_8[1];
    local_10 = 0;
    local_c = 0;
    local_8[0] = 0;
    if (data_0217d368->mUnk_2c == 3) {
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dc08))));
        func_020b4934((Unk020b4934 **) (&local_c), (void *) uVar1);
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbdc))));
        func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d368 + 0x20)), (void *) uVar1);
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbe0))));
        *(u32 *) ((int) data_0217d368 + 4) = uVar1;
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dc00))));
        *(u32 *) ((int) data_0217d368 + 8) = uVar1;
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbfc))));
        *(u32 *) ((int) data_0217d368 + 0xc) = uVar1;
    } else {
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbe4))));
        func_020b4934((Unk020b4934 **) (&local_c), (void *) uVar1);
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbf0))));
        func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d368 + 0x20)), (void *) uVar1);
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbf4))));
        *(u32 *) ((int) data_0217d368 + 4) = uVar1;
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbd4))));
        *(u32 *) ((int) data_0217d368 + 8) = uVar1;
        uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbe8))));
        *(u32 *) ((int) data_0217d368 + 0xc) = uVar1;
    }
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbd8))));
    func_020b4a44((Unk020b4a44 **) local_8, (void *) uVar1);
    uVar1 = ((u32) func_02036bec((void *) data_0217d368->mUnk_28, (u32) (((u32) 0x00000800u))));
    *(u32 *) ((int) data_0217d368 + 0x24) = uVar1;
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbf8))));
    func_020b49bc((Unk020b4934 **) (&local_10), (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dc04))));
    func_020b48b4(&data_0217d368->mUnk_00, (void *) uVar1);
    uVar1 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216dbec))));
    func_020b4a44((Unk020b4a44 **) ((int *) (u32) ((int) data_0217d368 + 0x10)), (void *) uVar1);
    ((u32) func_02016468((u32) 0x14, (u32) 0, (void *) (*(u32 *) (local_c + 0x14)),
                         (u32) (*(u32 *) (local_c + 0x10))));
    ((u32) func_02016468((u32) 0x1b, (u32) 0, (void *) ((int) data_0217d368->mUnk_20 + 0xc),
                         (u32) (*(u32 *) ((int) data_0217d368->mUnk_20 + 8))));
    ((u32) func_02016468((u32) 0x1b, (u32) (((u32) 0x00000800u)),
                         (void *) (*(u32 *) ((int) data_0217d368 + 0x24)), (u32) (((u32) 0x00000800u))));
    ((u32) func_02016468((u32) 0x1f, (u32) 0, (void *) (*(u32 *) (local_8[0] + 0xc)), (u32) 0x80));
    ((u32) func_02016468((u32) 0x23, (u32) 0, (void *) (*(u32 *) (local_10 + 0x14)),
                         (u32) (*(u32 *) (local_10 + 0x10))));
    ((u32) func_02016468((u32) 0x1e, (u32) 0,
                         (void *) (*(u32 *) ((int) data_0217d368->mUnk_10 + 0xc)),
                         (u32) (*(u32 *) ((int) data_0217d368->mUnk_10 + 8))));
}

#pragma thumb off
