/* Decompiled C draft; module arm9; ROM address 0208537c. No matching claim. */
#include "types.h"
#include "deps/0208537c_func_0208537c.h"

uint func_0208537c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0208538c & 0xfffffffc) >> (uRam0208538c & 3) * 8 |
          *(uint *)(uRam0208538c & 0xfffffffc) << (uRam0208538c & 3) * -8 + 0x20) + 0x128;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

