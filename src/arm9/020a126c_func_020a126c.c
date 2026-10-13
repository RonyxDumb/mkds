/* Decompiled C draft; module arm9; ROM address 020a126c. No matching claim. */
#include "types.h"
#include "deps/020a126c_func_020a126c.h"

bool func_020a126c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020a1288 & 0xfffffffc) >> (uRam020a1288 & 3) * 8 |
          *(uint *)(uRam020a1288 & 0xfffffffc) << (uRam020a1288 & 3) * -8 + 0x20) + 0x3b4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return -1 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

