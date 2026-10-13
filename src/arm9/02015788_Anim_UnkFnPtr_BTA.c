/* Decompiled C draft; module arm9; ROM address 02015788. No matching claim. */
#include "types.h"
#include "deps/02015788_Anim_UnkFnPtr_BTA.h"

void Anim_UnkFnPtr_BTA(uint *param_1,uint param_2,undefined2 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 8 & 3;
  uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
  func_02015894(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_3,
                (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                     *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 0xc,param_1);
  uVar1 = (uint)(param_1 + 4) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  param_1[4] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x3fffffff;
  uVar1 = (uint)(param_1 + 4) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  param_1[4] = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x40000000;
  *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 8;
  return;
}

