/* Decompiled C draft; module arm9; ROM address 0201e2cc. No matching claim. */
#include "types.h"
#include "deps/0201e2cc_func_0201e2cc.h"

void func_0201e2cc(short *param_1,int param_2,int *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int extraout_r1;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  _s32_div_f(*(undefined2 *)(param_2 + 0x26),param_1[3]);
  iVar3 = iRam0201e390;
  iVar2 = iRam0201e38c;
  puVar1 = puRam0201e388;
  if (extraout_r1 == 0) {
    uVar4 = (*(uint *)((uint)puRam0201e388 & 0xfffffffc) >> ((uint)puRam0201e388 & 3) * 8 |
            *(uint *)((uint)puRam0201e388 & 0xfffffffc) << ((uint)puRam0201e388 & 3) * -8 + 0x20) *
            iRam0201e38c + iRam0201e390;
    *puRam0201e388 = uVar4;
    *param_3 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
               *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) +
               ((int)((int)*param_1 * (uVar4 >> 0x17) + *param_1 * -0x100) >> 8);
    uVar5 = (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) * iVar2 + iVar3;
    *puVar1 = uVar5;
    uVar4 = (uint)(param_3 + 1) & 3;
    uVar6 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
    param_3[1] = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) +
                 ((int)((int)param_1[1] * (uVar5 >> 0x17) + param_1[1] * -0x100) >> 8);
    uVar5 = (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) * iVar2 + iVar3;
    *puVar1 = uVar5;
    uVar4 = (uint)(param_3 + 2) & 3;
    uVar6 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
    param_3[2] = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) +
                 ((int)((int)param_1[2] * (uVar5 >> 0x17) + param_1[2] * -0x100) >> 8);
    return;
  }
  return;
}

