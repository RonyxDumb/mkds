/* Decompiled C draft; module arm9; ROM address 020a128c. No matching claim. */
#include "types.h"
#include "deps/020a128c_func_020a128c.h"

bool func_020a128c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam020a12b4 & 0xfffffffc) >> (uRam020a12b4 & 3) * 8 |
          *(uint *)(uRam020a12b4 & 0xfffffffc) << (uRam020a12b4 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x3b4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0) {
    return false;
  }
  uVar3 = uVar3 + 0x3a8;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  return (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) < 0;
}

