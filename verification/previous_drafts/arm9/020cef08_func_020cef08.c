/* Decompiled C draft; module arm9; ROM address 020cef08. No matching claim. */
#include "types.h"
#include "deps/020cef08_func_020cef08.h"

uint func_020cef08(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020cef18 & 0xfffffffc) >> (uRam020cef18 & 3) * 8 |
          *(uint *)(uRam020cef18 & 0xfffffffc) << (uRam020cef18 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

