/* Decompiled C draft; module arm9; ROM address 02055c5c. No matching claim. */
#include "types.h"
#include "deps/02055c5c_func_02055c5c.h"

void func_02055c5c(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam02055c7c & 0xfffffffc) >> (uRam02055c7c & 3) * 8 |
          *(uint *)(uRam02055c7c & 0xfffffffc) << (uRam02055c7c & 3) * -8 + 0x20;
  if ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) == 2) {
    *(ushort *)(uVar1 + 8) = *(ushort *)(uVar1 + 8) & 0xfffd;
  }
  return;
}

