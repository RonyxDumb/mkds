/* Decompiled C draft; module arm9; ROM address 02010458. No matching claim. */
#include "types.h"
#include "deps/02010458_func_02010458.h"

undefined4 func_02010458(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar4;
  uint uVar3;
  
  uVar3 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  iVar4 = param_1 + uVar3;
  iVar1 = NNS_G3dGetResDataByName(iVar4 + (uint)*(ushort *)(param_1 + uVar3));
  if ((iVar1 != 0) && ((*(byte *)(iVar1 + 3) & 1) != 0)) {
    func_0201063c(iVar4);
    return 1;
  }
  return 0;
}

