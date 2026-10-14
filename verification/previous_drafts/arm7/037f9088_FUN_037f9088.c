/* Decompiled C draft; module arm7; ROM address 037f9088. No matching claim. */
#include "types.h"
#include "deps/037f9088_FUN_037f9088.h"

void FUN_037f9088(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = FUN_037faf70();
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0) {
    while (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0) {
      iVar3 = FUN_037f95b4(param_1);
      *(undefined4 *)(iVar3 + 0x48) = 1;
      *(undefined4 *)(iVar3 + 0x5c) = 0;
      *(undefined4 *)(iVar3 + 100) = 0;
      uVar1 = iVar3 + 100U & 3;
      uVar4 = *(uint *)(iVar3 + 100U & 0xfffffffc);
      *(uint *)(iVar3 + 0x60) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    }
    param_1[1] = 0;
    uVar1 = (uint)(param_1 + 1) & 3;
    uVar4 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    *param_1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    FUN_037f8f48();
  }
  FUN_037faf84(uVar2);
  return;
}

