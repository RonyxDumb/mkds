/* Decompiled C draft; module arm9; ROM address 020f944c. No matching claim. */
#include "types.h"
#include "deps/020f944c_func_020f944c.h"

void func_020f944c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iStack_2c;
  uint uStack_28;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint uStack_14;
  
  uVar2 = param_1 + 0xe0U & 3;
  uVar3 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  iVar1 = func_020d3e34(param_1 + 0x50,uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,param_2,
                        &uStack_28);
  if (iVar1 == 0) {
    return;
  }
  if ((((*(ushort *)(param_2 + 2) & 0x40) == 0) &&
      (uVar2 = param_1 + 0x74U & 3, uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
      ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0x80000) == 0)) &&
     (uVar2 = param_1 + 0x44U & 3, uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
     iVar1 = func_020d6968(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,param_2), iVar1 != 0)) {
    VecFx32_Add(param_1 + 0x50,&uStack_28,param_1 + 0x50);
  }
  iVar1 = func_020d6a54(param_1,param_2,&iStack_2c);
  if (iVar1 == 1) {
    uVar2 = param_2 + 4U & 3;
    uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
    uStack_28 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar2 = param_1 + 0x54U & 3;
    uVar3 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
    uStack_24 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar2 = param_2 + 0xcU & 3;
    uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uStack_20 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if ((iStack_2c == 1) ||
       (uVar2 = param_2 + 0x78U & 3, uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
       uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20, (uVar2 & 0x80000000) != 0)) {
      uVar2 = param_2 + 0x78U & 3;
      uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
      *(uint *)(param_2 + 0x78) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0x7fffffff;
    }
    else {
      *(uint *)(param_2 + 0x78) = uVar2 & 0x7fffffff;
    }
    uStack_1c = uStack_28;
    uStack_18 = uStack_24;
    uStack_14 = uStack_20;
    func_020f77f8(param_1,1,&uStack_28,param_2 + 0x10);
    *(ushort *)(param_1 + 0x78) = *(ushort *)(param_1 + 0x78) & 0xbfff;
    return;
  }
  if (iVar1 == 2) {
    if ((iStack_2c == 1) ||
       (uVar2 = param_2 + 0x78U & 3, uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
       uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20, (uVar2 & 0x80000000) != 0)) {
      uVar2 = param_2 + 0x78U & 3;
      uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
      *(uint *)(param_2 + 0x78) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0x7fffffff;
    }
    else {
      *(uint *)(param_2 + 0x78) = uVar2 & 0x7fffffff;
    }
    func_020f77f8(param_1,2,param_2 + 4,param_2 + 0x10);
    return;
  }
  return;
}

