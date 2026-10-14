/* Decompiled C draft; module arm9; ROM address 021482cc. No matching claim. */
#include "types.h"
#include "deps/021482cc_VecFx32_Norm.h"

int VecFx32_Norm(uint param_1)

{
  ushort *puVar1;
  longlong *plVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar5;
  
  plVar2 = plRam0214832c;
  puVar1 = puRam02148328;
  uVar3 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar6 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar3 = param_1 + 8 & 3;
  uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  *puRam02148328 = 1;
  *plVar2 = ((longlong)(int)uVar3 * (longlong)(int)uVar3 +
            (longlong)(int)uVar6 * (longlong)(int)uVar6 +
            (longlong)(int)uVar5 * (longlong)(int)uVar5) * 4;
  do {
  } while ((*puVar1 & 0x8000) != 0);
  return (int)((*(uint *)(uRam02148330 & 0xfffffffc) >> (uRam02148330 & 3) * 8 |
               *(uint *)(uRam02148330 & 0xfffffffc) << (uRam02148330 & 3) * -8 + 0x20) + 1) >> 1;
}

