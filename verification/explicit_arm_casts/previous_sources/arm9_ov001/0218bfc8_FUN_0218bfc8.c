/* Decompiled C draft; module arm9_ov001; ROM address 0218bfc8. No matching claim. */
#include "types.h"
#include "deps/0218bfc8_FUN_0218bfc8.h"

void FUN_0218bfc8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_02187218(param_1,2,DAT_0218c070);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c074),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c078));
  FUN_0219b1c4(*(undefined4 *)(param_1 + DAT_0218c07c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c080),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c078),0);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c084),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c088));
  iVar2 = *(int *)(param_1 + 0xa0);
  FUN_021889ec(param_1,*(undefined4 *)(iVar2 + DAT_0218c090),*(undefined4 *)(iVar2 + DAT_0218c094),
               *(undefined4 *)(iVar2 + DAT_0218c098),*(undefined4 *)(iVar2 + DAT_0218c08c));
  uVar1 = FUN_02187fc0(param_1);
  FUN_02188968(param_1,uVar1);
  uVar1 = FUN_02187fc0(param_1);
  FUN_02188980(param_1,uVar1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218c09c),DAT_0218c0a0);
  FUN_0218c5fc(param_1);
  return;
}

