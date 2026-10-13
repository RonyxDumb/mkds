/* Decompiled C draft; module arm9_ov003; ROM address 021d1c3c. No matching claim. */
#include "types.h"
#include "deps/021d1c3c_FUN_021d1c3c.h"

void FUN_021d1c3c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 auStack_20 [8];
  undefined4 local_18;
  
  iVar1 = *(int *)(DAT_021d1c8c + param_1 * 4);
  iVar2 = iVar1 + *(int *)(iVar1 + param_2 * 8 + 4);
  uVar3 = (uint)*(ushort *)(iVar1 + param_2 * 8);
  local_18 = 0;
  func_0x0214d018(0,auStack_20,8);
  iVar1 = 0;
  if (uVar3 != 0) {
    do {
      func_0x0214cffc(iVar2,auStack_20,6);
      func_0x0214d02c(auStack_20,param_3,8);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 6;
      param_3 = param_3 + 8;
    } while (iVar1 < (int)uVar3);
  }
  return;
}

