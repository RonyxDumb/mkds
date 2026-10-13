/* Decompiled C draft; module arm9_ov001; ROM address 02184160. No matching claim. */
#include "types.h"
#include "deps/02184160_FUN_02184160.h"

void FUN_02184160(int param_1)

{
  undefined4 uVar1;
  
  FUN_02187218(param_1,8,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021841c8),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021841cc));
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021841d0);
  FUN_02188c48(param_1,uVar1,uVar1);
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 0x9c)));
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021841d4);
  FUN_02188cd8(param_1,uVar1,uVar1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021841d8),DAT_021841dc);
  return;
}

