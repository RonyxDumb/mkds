/* Decompiled C draft; module arm7; ROM address 037fab44. No matching claim. */
#include "types.h"
#include "deps/037fab44_FUN_037fab44.h"

void FUN_037fab44(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_037faf70();
  if (param_1 == 0) {
    FUN_037fb000();
  }
  uVar2 = *(uint *)(DAT_037fabbc & 0xfffffffc) >> (DAT_037fabbc & 3) * 8 |
          *(uint *)(DAT_037fabbc & 0xfffffffc) << (DAT_037fabbc & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = uVar2 + 0x18 & 3;
    uVar3 = *(uint *)(uVar2 + 0x18 & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  while (uVar2 != 0) {
    uVar3 = uVar2 + 8 & 3;
    uVar2 = *(uint *)(uVar2 + 8 & 0xfffffffc);
    if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == param_1) {
      FUN_037fabc0();
    }
    uVar2 = uVar4;
    if (uVar4 == 0) {
      uVar4 = 0;
    }
    else {
      uVar3 = uVar4 + 0x18 & 3;
      uVar4 = *(uint *)(uVar4 + 0x18 & 0xfffffffc);
      uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    }
  }
  FUN_037faf84(uVar1);
  return;
}

