#include "Main/Unknown/code_0211de40.h"

#pragma thumb on

// non-matching: 0x6c bytes, original 0x68; 26 instructions differ; first at +0x0: original `push {r4, r5, r6, lr}`,
// ours `push {r4, r5, r6, r7, lr}`
void func_0211ded0(int param_1, u32 param_2, u32 param_3, u32 param_4, u16 param_5, int param_6) {
    int iVar5;
    u32 *puVar4;
    u32 uVar3;
    int iVar2;
    int uVar1;
    uVar3 = 0xe;
    if ((param_6 != 0) && (param_6 == 1)) {
        uVar3 = 0x1e;
    }
    uVar1 = ((unsigned short *) &data_0215cee4)[param_1];
    puVar4 = (u32 *) *((int *) ((u32) (&data_0217d370)));
    func_02124748(uVar1, puVar4[1], *puVar4, puVar4[3], param_6, param_4, param_2, param_3);
    iVar2 = *((int *) ((u32) (&data_0217d370)));
    iVar5 = *(int *) (*(int *) (iVar2 + 8) + 0xc);
    iVar2 = func_02124a68(uVar1, *(u32 *) (iVar2 + 4), *(u32 *) (iVar2 + 0xc));
    ((u32) func_02016468((u32) (uVar3), (u32) ((u32) param_5 << 5), (void *) (iVar5 + iVar2 * 0x20), (u32) (0x20)));
    return;
}

void func_0211de98(void) {
    u32 uVar1;
    u32 local_10;
    u32 local_c[1];
    local_10 = 0;
    local_c[0] = 0;
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216de54))))));
    func_020b49f4((void **) (&local_10), (void *) (uVar1));
    uVar1 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216de58))))));
    func_020b48ec((void **) (local_c), (void *) (uVar1));
    return;
}

// non-matching: 0x50 bytes, original 0x58; 15 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_0211de40(u32 param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0xc)));
    *((int *) ((u32) (&data_0217d36c))) = iVar1;
    uVar2 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216de54))))));
    func_020b49bc((Unk020b4934 **) ((int *) (u32) (*((int *) ((u32) (&data_0217d36c))))), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216de58))))));
    func_020b48b4((void **) ((int *) (u32) (*((int *) ((u32) (&data_0217d36c))) + 4)), (void *) (uVar2));
    uVar2 = ((int) func_0204799c((const char *) (*((u32 *) ((u32) (&data_0216de50))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d36c))) + 8) = uVar2;
    return;
}

#pragma thumb off
