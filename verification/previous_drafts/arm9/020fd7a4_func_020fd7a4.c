/* Decompiled C draft; module arm9; ROM address 020fd7a4. No matching claim. */
#include "types.h"
#include "deps/020fd7a4_func_020fd7a4.h"

uint func_020fd7a4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (*(uint *)(uRam020fd7ec & 0xfffffffc) >> (uRam020fd7ec & 3) * 8 |
          *(uint *)(uRam020fd7ec & 0xfffffffc) << (uRam020fd7ec & 3) * -8 + 0x20) + 0x268;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_1 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar2 = uVar1 + 0x74 & 3;
  uVar3 = *(uint *)(uVar1 + 0x74 & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if (((((uVar2 & 0x8000) != 0) && ((uVar2 & 0x180000) == 0)) && (*(short *)(uVar1 + 0x192) != 3))
     && (uVar2 = uVar1 + 0x198 & 3, uVar3 = *(uint *)(uVar1 + 0x198 & 0xfffffffc),
        uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0)) {
    return uVar1;
  }
  return 0;
}

