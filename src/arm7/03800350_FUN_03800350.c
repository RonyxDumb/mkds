/* Decompiled C draft; module arm7; ROM address 03800350. No matching claim. */
#include "types.h"
#include "deps/03800350_FUN_03800350.h"

void FUN_03800350(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint local_8 [2];
  
  uVar2 = (*(uint *)(DAT_038003f4 & 0xfffffffc) >> (DAT_038003f4 & 3) * 8 |
          *(uint *)(DAT_038003f4 & 0xfffffffc) << (DAT_038003f4 & 3) * -8 + 0x20) + 0x24;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 == 1) {
    local_8[0] = param_2 | param_1 >> 5 & 8 | (param_1 & 0xff) << 8;
  }
  else if (uVar2 == 2) {
    local_8[0] = param_2 | param_1 & 0xff00 | (param_1 & 0xff) << 0x10;
  }
  else if (uVar2 == 3) {
    local_8[0] = param_2 | param_1 >> 8 & 0xff00 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
  }
  FUN_03800538((int)(uintptr_t)(local_8),0,uVar2 + 1,DAT_038003f8);
  return;
}

