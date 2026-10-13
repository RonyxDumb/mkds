/* Decompiled C draft; module arm9; ROM address 020f6038. No matching claim. */
#include "types.h"
#include "deps/020f6038_func_020f6038.h"

undefined4 func_020f6038(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    iVar2 = VecFx32_CrossProduct_0(param_2 + 0x5c,param_2 + 0x130);
    func_020ff1b8(iVar2 < 0,(uint *)(uintptr_t)(param_2 + 0x60));
  }
  uVar3 = func_020fecdc((byte *)(uintptr_t)(param_1),param_2,param_3);
  if ((param_2 != 0) && (param_3 == 0)) {
    uVar1 = param_2 + 0x60U & 3;
    uVar4 = *(uint *)(param_2 + 0x60U & 0xfffffffc);
    func_020ff1a0(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,(undefined4 *)(uintptr_t)(param_2 + 0x168));
  }
  if ((param_2 != 0) && (param_3 != 0)) {
    uVar1 = param_2 + 0x44U & 3;
    uVar4 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
    uVar3 = func_020fe8ac(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    return uVar3;
  }
  return uVar3;
}

