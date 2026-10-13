/* Decompiled C draft; module arm7; ROM address 037f9854. No matching claim. */
#include "types.h"
#include "deps/037f9854_FUN_037f9854.h"

undefined4 FUN_037f9854(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int extraout_r1;
  uint uVar3;
  uint uVar4;
  
  uVar2 = FUN_037faf70();
  while( true ) {
    uVar1 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x14U & 3;
    uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    if ((int)uVar4 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
      uVar1 = param_1 + 0x18U & 3;
      uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
      FUN_03806b2c((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar4);
      uVar1 = param_1 + 0x10U & 3;
      uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + extraout_r1 * 4) = param_2
      ;
      uVar1 = param_1 + 0x1cU & 3;
      uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      *(uint *)(param_1 + 0x1c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
      FUN_037f9088((uint *)(uintptr_t)(param_1 + 8));
      FUN_037faf84(uVar2);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    FUN_037f9104(param_1);
  }
  FUN_037faf84(uVar2);
  return 0;
}

