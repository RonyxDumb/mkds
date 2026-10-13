/* Decompiled C draft; module arm9; ROM address 020ddaa0. No matching claim. */
#include "types.h"
#include "deps/020ddaa0_func_020ddaa0.h"

void func_020ddaa0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  
  func_020e6a18(param_2);
  uVar1 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  iVar7 = 1;
  if (1 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
    iVar6 = 0xc;
    puVar5 = (uint *)(param_2 + 0x14);
    do {
      iVar3 = func_020d3c44();
      *puVar5 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xc0ffffff
      ;
      *puVar5 = *(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
                *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20 |
                iVar3 << 0x18;
      uVar1 = param_1 + 0x44U & 3;
      uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      uVar4 = func_020e6cf8((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iVar6);
      func_020e67c4(param_2,uVar4,param_1 + 0x34,1);
      iVar6 = iVar6 + 0xc;
      iVar7 = iVar7 + 1;
      uVar1 = param_1 + 0x20U & 3;
      uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    } while (iVar7 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20));
    return;
  }
  return;
}

