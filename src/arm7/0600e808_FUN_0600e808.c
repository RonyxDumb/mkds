/* Decompiled C draft; module arm7; ROM address 0600e808. No matching claim. */
#include "types.h"
#include "deps/0600e808_FUN_0600e808.h"

int FUN_0600e808(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(DAT_0600e820 & 0xfffffffc) >> (DAT_0600e820 & 3) * 8 |
          *(uint *)(DAT_0600e820 & 0xfffffffc) << (DAT_0600e820 & 3) * -8 + 0x20) + 0x31c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return param_1 * 0x1c + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

