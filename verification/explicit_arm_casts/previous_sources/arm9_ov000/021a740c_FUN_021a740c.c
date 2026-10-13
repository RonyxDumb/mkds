/* Decompiled C draft; module arm9_ov000; ROM address 021a740c. No matching claim. */
#include "types.h"
#include "deps/021a740c_FUN_021a740c.h"

undefined4 FUN_021a740c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 local_18 [2];
  undefined1 auStack_14 [4];
  
  iVar2 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar2 + 100);
  func_0x0200ed34(iVar3 + 0xe0);
  FUN_021ae290(*(undefined2 *)(param_1 + 0x10),0,0);
  FUN_021ae1e4();
  *(undefined4 *)(iVar3 + 0xf8) = 0;
  uVar1 = FUN_021ae100(local_18,auStack_14);
  **(undefined2 **)(param_1 + 0x14) = local_18[0];
  **(undefined4 **)(param_1 + 0x18) = uVar1;
  *(ushort *)(iVar2 + 0x70) = *(ushort *)(iVar2 + 0x70) | 4;
  func_0x0200ecc4(iVar3 + 0xe0);
  return 0;
}

