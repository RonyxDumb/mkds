/* Decompiled C draft; module arm9; ROM address 020a1180. No matching claim. */
#include "types.h"
#include "deps/020a1180_func_020a1180.h"

uint func_020a1180(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020a1198 & 0xfffffffc) >> (uRam020a1198 & 3) * 8 |
          *(uint *)(uRam020a1198 & 0xfffffffc) << (uRam020a1198 & 3) * -8 + 0x20) + 0x3ac;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffff;
}

