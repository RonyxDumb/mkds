/* Decompiled C draft; module arm7; ROM address 037f9fd8. No matching claim. */
#include "types.h"
#include "deps/037f9fd8_FUN_037f9fd8.h"

void FUN_037f9fd8(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = FUN_037faf70();
  uVar2 = DAT_037fa048 + param_1 * 4;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)param_2 < 0) {
    param_2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  }
  uVar3 = uVar2 + 0x10 & 3;
  uVar2 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
  iVar5 = param_2 * 0xc + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar2 = iVar5 + 8U & 3;
  uVar3 = *(uint *)(iVar5 + 8U & 0xfffffffc);
  uVar4 = FUN_037fa218(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,param_3 + -0x20);
  *(undefined4 *)(iVar5 + 8) = uVar4;
  uVar2 = iVar5 + 4U & 3;
  uVar3 = *(uint *)(iVar5 + 4U & 0xfffffffc);
  uVar4 = FUN_037fa164((uint *)(uintptr_t)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20),(uint *)(uintptr_t)(param_3 + -0x20));
  *(undefined4 *)(iVar5 + 4) = uVar4;
  FUN_037faf84(uVar1);
  return;
}

