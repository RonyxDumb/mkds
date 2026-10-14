/* Decompiled C draft; module arm9; ROM address 02121e24. No matching claim. */
#include "types.h"
#include "deps/02121e24_func_02121e24.h"

uint func_02121e24(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x44 +
          (*(uint *)(uRam02121e40 & 0xfffffffc) >> (uRam02121e40 & 3) * 8 |
          *(uint *)(uRam02121e40 & 0xfffffffc) << (uRam02121e40 & 3) * -8 + 0x20) + 0x1e48;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

