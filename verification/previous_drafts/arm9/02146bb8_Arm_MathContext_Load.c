/* Decompiled C draft; module arm9; ROM address 02146bb8. No matching claim. */
#include "types.h"
#include "deps/02146bb8_Arm_MathContext_Load.h"

void Arm_MathContext_Load(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  puVar3 = puRam02146c14;
  puVar2 = puRam02146c10;
  uVar1 = param_1 + 4 & 3;
  uVar7 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *puRam02146c10 =
       *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  puVar2[1] = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
  puVar4 = puRam02146c18;
  uVar1 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar7 = param_1 + 0xc & 3;
  uVar6 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  *puVar3 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  puVar3[1] = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  puVar5 = puRam02146c20;
  puVar2 = puRam02146c1c;
  *puVar4 = *(undefined2 *)(param_1 + 0x18);
  uVar1 = param_1 + 0x10 & 3;
  uVar8 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar7 = param_1 + 0x14 & 3;
  uVar6 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  *puVar2 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  puVar2[1] = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  *puVar5 = *(undefined2 *)(param_1 + 0x1a);
  return;
}

