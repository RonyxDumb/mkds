/* Decompiled C draft; module arm9; ROM address 020f5550. No matching claim. */
#include "types.h"
#include "deps/020f5550_func_020f5550.h"

undefined4 func_020f5550(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    iVar2 = VecFx32_CrossProduct_0(param_2 + 0x5c,param_2 + 0x130);
    func_020ff1b8(iVar2 < 0,param_2 + 0x60);
    uVar1 = param_2 + 0x254U & 3;
    uVar3 = *(uint *)(param_2 + 0x254U & 0xfffffffc);
    func_020ff1b8(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_2 + 0x54);
  }
  uVar4 = func_020fecdc(param_1,param_2,param_3);
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + 0x21c;
  }
  uVar4 = func_020ff040(uVar4,iVar2,param_3);
  if ((param_2 != 0) && (param_3 == 0)) {
    uVar1 = param_2 + 0x60U & 3;
    uVar3 = *(uint *)(param_2 + 0x60U & 0xfffffffc);
    func_020ff1a0(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_2 + 0x250);
    uVar1 = param_2 + 0x54U & 3;
    uVar3 = *(uint *)(param_2 + 0x54U & 0xfffffffc);
    func_020ff1a0(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_2 + 0x254);
  }
  if ((param_2 != 0) && (param_3 != 0)) {
    uVar1 = param_2 + 0x44U & 3;
    uVar3 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
    uVar4 = func_020fe8ac(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    return uVar4;
  }
  return uVar4;
}

