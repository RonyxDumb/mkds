/* Decompiled C draft; module arm7; ROM address 037f8e98. No matching claim. */
#include "types.h"
#include "deps/037f8e98_FUN_037f8e98.h"

undefined4 FUN_037f8e98(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = DAT_037f8f40 + 8U & 3;
  uVar4 = *(uint *)(DAT_037f8f40 + 8U & 0xfffffffc);
  uVar1 = FUN_037faf70();
  uVar3 = 0;
  uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  while ((uVar2 != 0 && (uVar2 != param_1))) {
    uVar4 = uVar2 + 0x4c & 3;
    uVar5 = *(uint *)(uVar2 + 0x4c & 0xfffffffc);
    uVar3 = uVar2;
    uVar2 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  }
  if ((uVar2 == 0) || (uVar2 == DAT_037f8f44)) {
    FUN_037faf84(uVar1);
    uVar1 = 0;
  }
  else {
    uVar4 = uVar2 + 0x54 & 3;
    uVar2 = *(uint *)(uVar2 + 0x54 & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) != param_2) {
      if (uVar3 == 0) {
        uVar2 = param_1 + 0x4c & 3;
        uVar3 = *(uint *)(param_1 + 0x4c & 0xfffffffc);
        *(uint *)(DAT_037f8f40 + 8) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      }
      else {
        uVar2 = param_1 + 0x4c & 3;
        uVar4 = *(uint *)(param_1 + 0x4c & 0xfffffffc);
        *(uint *)(uVar3 + 0x4c) = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      }
      *(uint *)(param_1 + 0x54) = param_2;
      FUN_037f951c(param_1);
      FUN_037f8f48();
    }
    FUN_037faf84(uVar1);
    uVar1 = 1;
  }
  return uVar1;
}

