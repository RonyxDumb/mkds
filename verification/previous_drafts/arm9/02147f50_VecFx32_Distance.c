/* Decompiled C draft; module arm9; ROM address 02147f50. No matching claim. */
#include "types.h"
#include "deps/02147f50_VecFx32_Distance.h"

int VecFx32_Distance(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  longlong *plVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  plVar4 = plRam02147fd0;
  puVar3 = puRam02147fcc;
  uVar1 = param_1 + 4 & 3;
  uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_2 + 4 & 3;
  uVar6 = *(uint *)(param_2 + 4 & 0xfffffffc);
  iVar7 = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) -
          (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  uVar1 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  iVar9 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
          (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
  uVar2 = param_2 + 8 & 3;
  uVar6 = *(uint *)(param_2 + 8 & 0xfffffffc);
  iVar5 = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) -
          (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  *puRam02147fcc = 1;
  *plVar4 = ((longlong)iVar5 * (longlong)iVar5 +
            (longlong)iVar9 * (longlong)iVar9 + (longlong)iVar7 * (longlong)iVar7) * 4;
  do {
  } while ((*puVar3 & 0x8000) != 0);
  return (int)((*(uint *)(uRam02147fd4 & 0xfffffffc) >> (uRam02147fd4 & 3) * 8 |
               *(uint *)(uRam02147fd4 & 0xfffffffc) << (uRam02147fd4 & 3) * -8 + 0x20) + 1) >> 1;
}

