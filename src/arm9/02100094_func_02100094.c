/* Decompiled C draft; module arm9; ROM address 02100094. No matching claim. */
#include "types.h"
#include "deps/02100094_func_02100094.h"

uint func_02100094(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)*(ushort *)(param_1 + 4);
  while ((1 < (int)uVar3 &&
         (uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                  *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + (uVar3 - 1) * 4,
         uVar1 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
         *(short *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 0x6f))) {
    uVar3 = uVar3 - 1;
  }
  return uVar3;
}

