/* Decompiled C draft; module arm9; ROM address 020c3db4. No matching claim. */
#include "types.h"
#include "deps/020c3db4_func_020c3db4.h"

uint func_020c3db4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  uVar4 = *(uint *)(uRam020c3df8 & 0xfffffffc) >> (uRam020c3df8 & 3) * 8 |
          *(uint *)(uRam020c3df8 & 0xfffffffc) << (uRam020c3df8 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar2 = (*(uint *)(uRam020c3dfc & 0xfffffffc) >> (uRam020c3dfc & 3) * 8 |
          *(uint *)(uRam020c3dfc & 0xfffffffc) << (uRam020c3dfc & 3) * -8 + 0x20) + 0xb4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((((uVar3 == 3) || (uVar3 == 5)) || (uVar3 == 2)) &&
     (uVar4 = uVar4 + 0x1c, uVar3 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
     uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0)) {
    return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return 0;
}

