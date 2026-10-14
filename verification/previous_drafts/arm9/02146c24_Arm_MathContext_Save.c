/* Decompiled C draft; module arm9; ROM address 02146c24. No matching claim. */
#include "types.h"
#include "deps/02146c24_Arm_MathContext_Save.h"

void Arm_MathContext_Save(uint *param_1)

{
  uint uVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = puRam02146c8c;
  uVar4 = uRam02146c88;
  uVar1 = uRam02146c84 + 4 & 3;
  uVar5 = *(uint *)(uRam02146c84 + 4 & 0xfffffffc);
  *param_1 = *(uint *)(uRam02146c84 & 0xfffffffc) >> (uRam02146c84 & 3) * 8 |
             *(uint *)(uRam02146c84 & 0xfffffffc) << (uRam02146c84 & 3) * -8 + 0x20;
  param_1[1] = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  uVar5 = uRam02146c90;
  uVar1 = uVar4 + 4 & 3;
  uVar6 = *(uint *)(uVar4 + 4 & 0xfffffffc);
  param_1[2] = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
               *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  param_1[3] = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  puVar3 = puRam02146c94;
  *(ushort *)(param_1 + 6) = *puVar2 & 3;
  uVar1 = uVar5 + 4 & 3;
  uVar4 = *(uint *)(uVar5 + 4 & 0xfffffffc);
  param_1[4] = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
               *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  param_1[5] = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  *(ushort *)((int)param_1 + 0x1a) = *puVar3 & 1;
  return;
}

