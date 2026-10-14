/* Decompiled C draft; module arm9; ROM address 02015e28. No matching claim. */
#include "types.h"
#include "deps/02015e28_Anim_UnkFnPtr_BVA.h"

void Anim_UnkFnPtr_BVA(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2 + 8 & 3;
  uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar1 = ((int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 0xc) *
          (uint)*(ushort *)(uVar3 + 6) + param_3;
  uVar3 = uVar3 + (uVar1 >> 5) * 4 + 0xc;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *param_1 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 1 << (uVar1 & 0x1f);
  return;
}

