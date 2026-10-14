/* Decompiled C draft; module arm9; ROM address 020176c0. No matching claim. */
#include "types.h"
#include "deps/020176c0_Mem_Exp_GetAllocatableSize.h"

uint Mem_Exp_GetAllocatableSize(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar8;
  uint uVar7;
  
  iVar1 = abs(param_2);
  uVar8 = param_1 + 0x24U & 3;
  uVar6 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar7 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  uVar6 = 0;
  uVar8 = 0xffffffff;
  if (uVar7 != 0) {
    do {
      iVar5 = uVar7 + 0x10;
      uVar3 = uVar7 + 4 & 3;
      uVar2 = *(uint *)(uVar7 + 4 & 0xfffffffc);
      uVar4 = ~(iVar1 - 1U) & (iVar1 - 1U) + iVar5;
      uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + iVar5;
      if (uVar4 < uVar3) {
        uVar3 = uVar3 - uVar4;
        if ((uVar6 < uVar3) || ((uVar6 == uVar3 && (uVar4 - iVar5 < uVar8)))) {
          uVar8 = uVar4 - iVar5;
          uVar6 = uVar3;
        }
      }
      uVar3 = uVar7 + 0xc & 3;
      uVar7 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
      uVar7 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
    } while (uVar7 != 0);
  }
  return uVar6;
}

