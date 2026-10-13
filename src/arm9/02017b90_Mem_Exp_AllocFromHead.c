/* Decompiled C draft; module arm9; ROM address 02017b90. No matching claim. */
#include "types.h"
#include "deps/02017b90_Mem_Exp_AllocFromHead.h"

void Mem_Exp_AllocFromHead(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int unaff_r6;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint uVar6;
  
  uVar1 = param_1 + 0x24;
  uVar4 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  bVar9 = (*(ushort *)(param_1 + 0x36) & 1) == 0;
  if (bVar9) {
    unaff_r6 = 1;
  }
  uVar2 = 0;
  if (!bVar9) {
    unaff_r6 = 0;
  }
  uVar7 = 0;
  uVar3 = 0xffffffff;
  if (uVar4 != 0) {
    uVar8 = uVar7;
    do {
      uVar7 = ~(param_3 - 1U) & (param_3 - 1U) + uVar4 + 0x10;
      uVar6 = uVar4 + 4 & 3;
      uVar5 = *(uint *)(uVar4 + 4 & 0xfffffffc);
      uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      if (((param_2 + (uVar7 - (uVar4 + 0x10)) <= uVar6) && (uVar6 < uVar3)) &&
         ((uVar2 = uVar4, unaff_r6 != 0 || (uVar3 = uVar6, uVar8 = uVar7, uVar6 == param_2))))
      break;
      uVar7 = uVar8;
      uVar8 = uVar4 + 0xc & 3;
      uVar4 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
      uVar4 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
      uVar8 = uVar7;
    } while (uVar4 != 0);
  }
  if (uVar2 != 0) {
    Mem_Exp_ConvertFreeBlockToUsedBlock(uVar1,uVar2,uVar7);
    return;
  }
  return;
}

