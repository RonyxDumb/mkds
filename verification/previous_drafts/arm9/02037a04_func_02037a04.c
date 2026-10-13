/* Decompiled C draft; module arm9; ROM address 02037a04. No matching claim. */
#include "types.h"
#include "deps/02037a04_func_02037a04.h"

void func_02037a04(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(uRam02037a1c & 0xfffffffc) >> (uRam02037a1c & 3) * 8 |
          *(uint *)(uRam02037a1c & 0xfffffffc) << (uRam02037a1c & 3) * -8 + 0x20;
  *(byte *)(uVar1 + 0xd8) = *(byte *)(uVar1 + 0xd8) & 0xfe;
  return;
}

