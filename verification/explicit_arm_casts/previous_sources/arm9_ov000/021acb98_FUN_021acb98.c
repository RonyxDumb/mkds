/* Decompiled C draft; module arm9_ov000; ROM address 021acb98. No matching claim. */
#include "types.h"
#include "deps/021acb98_FUN_021acb98.h"

void FUN_021acb98(undefined2 *param_1,ushort *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  iVar1 = thunk_FUN_021acecc(param_2,param_4);
  uVar4 = 0;
  iVar2 = 0;
  puVar3 = param_1;
  if (0 < iVar1) {
    do {
      uVar4 = uVar4 + (uint)*param_2 * param_3;
      *puVar3 = (short)uVar4;
      uVar4 = uVar4 >> 0x10;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < iVar1);
  }
  iVar1 = iVar2;
  if (iVar2 < param_4) {
    iVar1 = iVar2 + 1;
    param_1[iVar2] = (short)uVar4;
  }
  func_0x0214d168(param_1 + iVar1,0,(param_4 - iVar1) * 2);
  return;
}

