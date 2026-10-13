/* Decompiled C draft; module arm9; ROM address 020f9880. No matching claim. */
#include "types.h"
#include "deps/020f9880_func_020f9880.h"

uint func_020f9880(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f989c & 0xfffffffc) >> (uRam020f989c & 3) * 8 |
          *(uint *)(uRam020f989c & 0xfffffffc) << (uRam020f989c & 3) * -8 + 0x20) + 0x84;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  return uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
}

