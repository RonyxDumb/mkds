/* Decompiled C draft; module arm9_ov001; ROM address 0218ea98. No matching claim. */
#include "types.h"
#include "deps/0218ea98_FUN_0218ea98.h"

undefined4 FUN_0218ea98(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x9c) + 4) + *(int *)(*(int *)(param_1 + 0xa0) + 0x84);
  iVar1 = *(int *)(param_1 + 8) - *(int *)(*(int *)(param_1 + 0xa0) + 0x88);
  if (iVar1 <= iVar2) {
    iVar1 = iVar2;
  }
  *(int *)(param_1 + 8) = iVar1;
  func_0x02061860();
  return 0;
}

