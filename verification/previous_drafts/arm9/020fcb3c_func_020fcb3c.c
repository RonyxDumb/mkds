/* Decompiled C draft; module arm9; ROM address 020fcb3c. No matching claim. */
#include "types.h"
#include "deps/020fcb3c_func_020fcb3c.h"

uint func_020fcb3c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam020fcb48 + 0x11cU & 3;
  uVar2 = *(uint *)(iRam020fcb48 + 0x11cU & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

