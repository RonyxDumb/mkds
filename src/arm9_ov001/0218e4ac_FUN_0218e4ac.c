/* Decompiled C draft; module arm9_ov001; ROM address 0218e4ac. No matching claim. */
#include "types.h"
#include "deps/0218e4ac_FUN_0218e4ac.h"

void FUN_0218e4ac(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(*(int *)(param_1 + 0xa0) + 0x80);
  puVar1 = (undefined4 *)(param_1 + DAT_0218e4fc);
  *puVar1 = 0;
  puVar2 = (undefined4 *)(param_1 + DAT_0218e500);
  *puVar2 = *puVar1;
  *puVar2 = 0;
  FUN_02187218(param_1,8);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x34),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x38));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x3c),DAT_0218e504);
  return;
}

