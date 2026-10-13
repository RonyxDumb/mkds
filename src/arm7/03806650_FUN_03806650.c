/* Decompiled C draft; module arm7; ROM address 03806650. No matching claim. */
#include "types.h"
#include "deps/03806650_FUN_03806650.h"

undefined4 FUN_03806650(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar2 = DAT_038066b0 + 8U & 3;
  uVar1 = *(uint *)(DAT_038066b0 + 8U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  while( true ) {
    if (uVar2 == 0) {
      return 0;
    }
    if (uVar2 == param_1) break;
    uVar1 = uVar2 + 0x4c & 3;
    uVar2 = *(uint *)(uVar2 + 0x4c & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  uVar2 = param_1 + 0x48 & 3;
  uVar1 = *(uint *)(param_1 + 0x48 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 != 0) && (uVar2 != 1)) {
    return 0;
  }
  return 1;
}

