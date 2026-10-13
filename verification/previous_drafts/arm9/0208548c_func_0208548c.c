/* Decompiled C draft; module arm9; ROM address 0208548c. No matching claim. */
#include "types.h"
#include "deps/0208548c_func_0208548c.h"

uint func_0208548c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0208549c & 0xfffffffc) >> (uRam0208549c & 3) * 8 |
          *(uint *)(uRam0208549c & 0xfffffffc) << (uRam0208549c & 3) * -8 + 0x20) + 0x8c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

