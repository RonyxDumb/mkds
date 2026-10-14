/* Decompiled C draft; module arm7; ROM address 037ff128. No matching claim. */
#include "types.h"
#include "deps/037ff128_FUN_037ff128.h"

uint FUN_037ff128(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  FUN_037fc298();
  uVar2 = param_1 + param_2 * 4 + 0x3c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = 0;
  }
  else if (uVar2 < 0x2000000) {
    uVar2 = param_1 + uVar2;
  }
  FUN_037fc294();
  return uVar2;
}

