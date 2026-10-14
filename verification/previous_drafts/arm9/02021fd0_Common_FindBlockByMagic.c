/* Decompiled C draft; module arm9; ROM address 02021fd0. No matching claim. */
#include "types.h"
#include "deps/02021fd0_Common_FindBlockByMagic.h"

uint Common_FindBlockByMagic(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar4 = 0;
  uVar2 = param_1 + (uint)*(ushort *)(param_1 + 0xc);
  if (*(ushort *)(param_1 + 0xe) != 0) {
    do {
      if ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) == param_2) {
        return uVar2;
      }
      uVar4 = uVar4 + 1;
      uVar1 = uVar2 + 4 & 3;
      uVar3 = *(uint *)(uVar2 + 4 & 0xfffffffc);
      uVar2 = uVar2 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    } while (uVar4 < *(ushort *)(param_1 + 0xe));
  }
  return 0;
}

