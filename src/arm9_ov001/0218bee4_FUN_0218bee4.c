/* Decompiled C draft; module arm9_ov001; ROM address 0218bee4. No matching claim. */
#include "types.h"
#include "deps/0218bee4_FUN_0218bee4.h"

void FUN_0218bee4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218bf94 + 0x62));
  FUN_02187218(param_1,2,DAT_0218bf98);
  FUN_02188d30(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bf9c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bfa0),DAT_0218bfa4);
  FUN_0219b1c4(*(undefined4 *)(param_1 + DAT_0218bfa8),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bfac),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bfa0),0);
  FUN_02188cd8(param_1,0,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bfb0));
  iVar3 = *(int *)(param_1 + 0xa0);
  FUN_02188a30(param_1,0,*(undefined4 *)(iVar3 + DAT_0218bfb8),*(undefined4 *)(iVar3 + DAT_0218bfbc)
               ,*(undefined4 *)(iVar3 + DAT_0218bfb4));
  FUN_02188968(param_1,(undefined4 *)(uintptr_t)(iVar1 + 0x80));
  uVar2 = FUN_02187fc0(param_1);
  FUN_02188980(param_1,(undefined4 *)(uintptr_t)(uVar2));
  FUN_02188e74(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bfc0),DAT_0218bfc4);
  return;
}

