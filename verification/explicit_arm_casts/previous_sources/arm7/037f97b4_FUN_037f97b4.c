/* Decompiled C draft; module arm7; ROM address 037f97b4. No matching claim. */
#include "types.h"
#include "deps/037f97b4_FUN_037f97b4.h"

undefined4 FUN_037f97b4(int param_1,uint *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 extraout_r1;
  
  uVar1 = FUN_037faf70();
  while( true ) {
    uVar4 = param_1 + 0x1cU & 3;
    uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
      if (param_2 != (uint *)0x0) {
        uVar4 = param_1 + 0x10U & 3;
        uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
        uVar2 = param_1 + 0x18U & 3;
        uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
        uVar4 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
                (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * 4;
        uVar2 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        *param_2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      }
      uVar4 = param_1 + 0x18U & 3;
      uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
      uVar2 = param_1 + 0x14U & 3;
      uVar5 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      FUN_03806b2c((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 1,
                   uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
      *(undefined4 *)(param_1 + 0x18) = extraout_r1;
      uVar4 = param_1 + 0x1cU & 3;
      uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      *(uint *)(param_1 + 0x1c) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) - 1;
      FUN_037f9088(param_1);
      FUN_037faf84(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    FUN_037f9104(param_1 + 8);
  }
  FUN_037faf84(uVar1);
  return 0;
}

