/* Decompiled C draft; module arm9; ROM address 020ce8bc. No matching claim. */
#include "types.h"
#include "deps/020ce8bc_func_020ce8bc.h"

uint func_020ce8bc(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020ce8cc & 0xfffffffc) >> (uRam020ce8cc & 3) * 8 |
          *(uint *)(uRam020ce8cc & 0xfffffffc) << (uRam020ce8cc & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

