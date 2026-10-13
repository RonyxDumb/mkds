/* Decompiled C draft; module arm9; ROM address 02085824. No matching claim. */
#include "types.h"
#include "deps/02085824_func_02085824.h"

int func_02085824(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = 0;
  uVar3 = *(uint *)(uRam020858a4 & 0xfffffffc) >> (uRam020858a4 & 3) * 8 |
          *(uint *)(uRam020858a4 & 0xfffffffc) << (uRam020858a4 & 3) * -8 + 0x20;
  if (*(char *)(uVar3 + 0x58) == '\0') {
    iVar2 = (int)*(short *)((*(uint *)(uRam020858a8 & 0xfffffffc) >> (uRam020858a8 & 3) * 8 |
                            *(uint *)(uRam020858a8 & 0xfffffffc) << (uRam020858a8 & 3) * -8 + 0x20)
                           + 0x13c);
  }
  else {
    uVar3 = param_1 * 0x30 + uVar3 + 0x74;
    uVar1 = uVar3 & 3;
    uVar4 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = 0;
    do {
      if (uVar3 != (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) {
        iVar2 = (iVar2 + *(short *)((*(uint *)(uRam020858a8 & 0xfffffffc) >> (uRam020858a8 & 3) * 8
                                    | *(uint *)(uRam020858a8 & 0xfffffffc) <<
                                      (uRam020858a8 & 3) * -8 + 0x20) + uVar3 * 2 + 0x13e)) *
                0x10000 >> 0x10;
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < 2);
  }
  return iVar2;
}

