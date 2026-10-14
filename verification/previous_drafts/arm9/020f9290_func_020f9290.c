/* Decompiled C draft; module arm9; ROM address 020f9290. No matching claim. */
#include "types.h"
#include "deps/020f9290_func_020f9290.h"

undefined4 func_020f9290(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x2000000) != 0) &&
      (iVar3 = VecFx32_CrossProduct_0(param_2,param_1 + 0x108), iVar3 < 0)) &&
     (uVar1 = param_1 + 0x74U & 3, uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
     ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 8) == 0)) {
    func_020f6fc4(param_1,1);
    return 1;
  }
  return 0;
}

