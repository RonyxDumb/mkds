/* Decompiled C draft; module arm9; ROM address 02010c84. No matching claim. */
#include "types.h"
#include "deps/02010c84_Mode_CreateFromResource.h"

void Mode_CreateFromResource(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  MIi_CpuClear32(0,param_1,0x54);
  uVar2 = uRam02010ce8;
  uVar3 = uRam02010ce4;
  *(uint *)(param_1 + 0xc) =
       *(uint *)(uRam02010ce0 & 0xfffffffc) >> (uRam02010ce0 & 3) * 8 |
       *(uint *)(uRam02010ce0 & 0xfffffffc) << (uRam02010ce0 & 3) * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar3 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

