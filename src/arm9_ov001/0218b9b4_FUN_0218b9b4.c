/* Decompiled C draft; module arm9_ov001; ROM address 0218b9b4. No matching claim. */
#include "types.h"
#include "deps/0218b9b4_FUN_0218b9b4.h"

void FUN_0218b9b4(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218ba20 + 0x62));
  FUN_02187218(param_1,8,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x78),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x7c));
  FUN_02188c48(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ba24),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ba28));
  FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar1 + 0x80));
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ba2c),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ba30));
  return;
}

