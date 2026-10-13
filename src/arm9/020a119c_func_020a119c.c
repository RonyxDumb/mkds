/* Decompiled C draft; module arm9; ROM address 020a119c. No matching claim. */
#include "types.h"
#include "deps/020a119c_func_020a119c.h"

uint func_020a119c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = 0;
  uVar4 = 0;
  uVar5 = (uint)*(byte *)((*(uint *)(uRam020a1210 & 0xfffffffc) >> (uRam020a1210 & 3) * 8 |
                          *(uint *)(uRam020a1210 & 0xfffffffc) << (uRam020a1210 & 3) * -8 + 0x20) +
                         0x3d0);
  if (uVar5 != 0) {
    do {
      uVar2 = (uVar4 & 0xffff) * 0x70 +
              (*(uint *)(uRam020a1214 & 0xfffffffc) >> (uRam020a1214 & 3) * 8 |
              *(uint *)(uRam020a1214 & 0xfffffffc) << (uRam020a1214 & 3) * -8 + 0x20) + 0x4c;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar4 = uVar4 + 1;
      if ((int)uVar2 < 1) {
        uVar2 = 0;
      }
      uVar3 = uVar3 + (uVar2 & 0xffff);
    } while ((int)uVar4 < (int)uVar5);
  }
  return uVar3 & 0xffff;
}

