/* Decompiled C draft; module arm7; ROM address 037f973c. No matching claim. */
#include "types.h"
#include "deps/037f973c_FUN_037f973c.h"

undefined4 FUN_037f973c(int param_1,uint *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
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
      FUN_037faf84(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    FUN_037f9104(param_1 + 8);
  }
  FUN_037faf84(uVar1);
  return 0;
}

