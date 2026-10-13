/* Decompiled C draft; module arm9; ROM address 020e7e58. No matching claim. */
#include "types.h"
#include "deps/020e7e58_E7Fn2_10.h"

void E7Fn2_10(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar2 = uRam020e7ebc;
  uVar1 = uRam020e7eb8;
  uVar5 = uRam020e7eb4;
  *puRam020e7eb0 = 1;
  func_02147288(uVar5,uVar1,uVar2);
  uVar4 = uRam020e7ec0 & 3;
  uVar3 = *(uint *)(uRam020e7ec0 & 0xfffffffc);
  *puRam020e7ec4 = 0;
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x48;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = 0;
  if (((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 1) == 0) {
    uVar5 = uRam020e7ec8;
  }
  *puRam020e7ecc = uVar5;
  return;
}

