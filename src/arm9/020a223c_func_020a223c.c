/* Decompiled C draft; module arm9; ROM address 020a223c. No matching claim. */
#include "types.h"
#include "deps/020a223c_func_020a223c.h"

uint func_020a223c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(uRam020a2260 & 0xfffffffc) >> (uRam020a2260 & 3) * 8 |
          *(uint *)(uRam020a2260 & 0xfffffffc) << (uRam020a2260 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x3b4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0) {
    uVar2 = param_1 * 0x70 + uVar3 + 0x68;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

