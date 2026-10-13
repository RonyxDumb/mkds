/* Decompiled C draft; module arm9; ROM address 0201050c. No matching claim. */
#include "types.h"
#include "deps/0201050c_func_0201050c.h"

undefined4 func_0201050c(int param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar1 = *(ushort *)(param_1 + uVar5);
  param_1 = param_1 + uVar5;
  iVar2 = NNS_G3dGetResDataByName(param_2 + 0x3c,param_3);
  if (((iVar2 != 0) && (iVar3 = NNS_G3dGetResDataByName(param_1 + (uint)uVar1,param_3), iVar3 != 0))
     && ((*(byte *)(iVar3 + 3) & 1) == 0)) {
    func_020106c8(param_1,iVar3,param_2,iVar2);
    return 1;
  }
  return 0;
}

