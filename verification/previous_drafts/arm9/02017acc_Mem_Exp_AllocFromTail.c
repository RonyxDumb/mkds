/* Decompiled C draft; module arm9; ROM address 02017acc. No matching claim. */
#include "types.h"
#include "deps/02017acc_Mem_Exp_AllocFromTail.h"

void Mem_Exp_AllocFromTail(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int unaff_r5;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint uVar3;
  
  uVar6 = 0xffffffff;
  bVar7 = (*(ushort *)(param_1 + 0x36) & 1) == 0;
  if (bVar7) {
    unaff_r5 = 1;
  }
  uVar1 = 0;
  uVar3 = param_1 + 0x28U & 3;
  uVar2 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (!bVar7) {
    unaff_r5 = 0;
  }
  uVar2 = 0;
  if (uVar3 != 0) {
    uVar5 = uVar2;
    do {
      uVar2 = uVar3 + 4 & 3;
      uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      uVar2 = ~(param_3 - 1U) & (uVar4 + uVar3 + 0x10) - param_2;
      if (((-1 < (int)(uVar2 - (uVar3 + 0x10))) && (uVar4 < uVar6)) &&
         ((uVar1 = uVar3, unaff_r5 != 0 || (uVar5 = uVar2, uVar6 = uVar4, uVar4 == param_2))))
      break;
      uVar2 = uVar5;
      uVar5 = uVar3 + 8 & 3;
      uVar3 = *(uint *)(uVar3 + 8 & 0xfffffffc);
      uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      uVar5 = uVar2;
    } while (uVar3 != 0);
  }
  if (uVar1 != 0) {
    Mem_Exp_ConvertFreeBlockToUsedBlock(param_1 + 0x24,uVar1,uVar2);
    return;
  }
  return;
}

