/* Decompiled C draft; module arm7; ROM address 037f94d4. No matching claim. */
#include "types.h"
#include "deps/037f94d4_FUN_037f94d4.h"

void FUN_037f94d4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = DAT_037f9518 + 8U & 3;
  uVar2 = *(uint *)(DAT_037f9518 + 8U & 0xfffffffc);
  uVar1 = 0;
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  while ((uVar4 != 0 && (uVar4 != param_1))) {
    uVar2 = uVar4 + 0x4c & 3;
    uVar3 = *(uint *)(uVar4 + 0x4c & 0xfffffffc);
    uVar1 = uVar4;
    uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  if (uVar1 == 0) {
    uVar4 = param_1 + 0x4c & 3;
    uVar1 = *(uint *)(param_1 + 0x4c & 0xfffffffc);
    *(uint *)(DAT_037f9518 + 8) = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  }
  else {
    uVar4 = param_1 + 0x4c & 3;
    uVar2 = *(uint *)(param_1 + 0x4c & 0xfffffffc);
    *(uint *)(uVar1 + 0x4c) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  }
  return;
}

