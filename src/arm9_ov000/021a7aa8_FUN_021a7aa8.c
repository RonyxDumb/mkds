/* Decompiled C draft; module arm9_ov000; ROM address 021a7aa8. No matching claim. */
#include "types.h"
#include "deps/021a7aa8_FUN_021a7aa8.h"

undefined4 FUN_021a7aa8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(int *)(param_1 + 100) + 0xf8) <
      (int)(uint)*(ushort *)(*(int *)(param_1 + 100) + 0xfc)) {
    return 0;
  }
  iVar1 = FUN_021a7064(DAT_021a7aec,param_1,0);
  if (iVar1 == 0) {
    return 0xffffffdf;
  }
  uVar2 = FUN_021a6fb4(param_1);
  return uVar2;
}

