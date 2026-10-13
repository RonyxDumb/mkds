/* Decompiled C draft; module arm9; ROM address 020a1ddc. No matching claim. */
#include "types.h"
#include "deps/020a1ddc_func_020a1ddc.h"

void func_020a1ddc(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = uRam020a1e38;
  iVar4 = 0;
  uVar6 = (uint)*(byte *)((*(uint *)(uRam020a1e34 & 0xfffffffc) >> (uRam020a1e34 & 3) * 8 |
                          *(uint *)(uRam020a1e34 & 0xfffffffc) << (uRam020a1e34 & 3) * -8 + 0x20) +
                         0x3d0);
  if (uVar6 != 0) {
    iVar5 = iVar4;
    do {
      uVar1 = uVar2 & 3;
      uVar3 = *(uint *)(uVar2 & 0xfffffffc);
      iVar4 = iVar4 + 1;
      *(undefined4 *)
       (iVar5 + param_1 * 4 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x24) = 0;
      iVar5 = iVar5 + 0x70;
    } while (iVar4 < (int)uVar6);
    return;
  }
  return;
}

