/* Decompiled C draft; module arm9; ROM address 02010294. No matching claim. */
#include "types.h"
#include "deps/02010294_func_02010294.h"

undefined4 func_02010294(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = param_1 + 8U & 3;
  uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
  param_1 = param_1 + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
  uVar2 = *(ushort *)(param_1 + 2);
  iVar3 = NNS_G3dGetResDataByName(param_2 + (uint)*(ushort *)(param_2 + 0x34),param_3);
  if (((iVar3 != 0) && (iVar4 = NNS_G3dGetResDataByName(param_1 + (uint)uVar2,param_3), iVar4 != 0))
     && ((*(byte *)(iVar4 + 3) & 1) == 0)) {
    func_020103c0(param_1,(ushort *)(uintptr_t)(iVar4),param_2,(ushort *)(uintptr_t)(iVar3));
    return 1;
  }
  return 0;
}

