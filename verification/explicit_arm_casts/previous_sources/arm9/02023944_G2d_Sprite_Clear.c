/* Decompiled C draft; module arm9; ROM address 02023944. No matching claim. */
#include "types.h"
#include "deps/02023944_G2d_Sprite_Clear.h"

void G2d_Sprite_Clear(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(byte *)(param_1 + 0xc) == 4) {
    param_2 = param_2 | param_2 << 4;
    param_2 = param_2 | param_2 << 8;
    param_2 = param_2 | param_2 << 0x10;
  }
  else {
    param_2 = param_2 | param_2 << 8;
    param_2 = param_2 | param_2 << 0x10;
  }
  uVar1 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  Mem_CpuFastMemorySet
            (param_2,*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                     *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
             (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) *
             (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) *
             ((int)((uint)*(byte *)(param_1 + 0xc) * 0x40) >> 3));
  return;
}

