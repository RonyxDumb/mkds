/* Decompiled C draft; module arm9; ROM address 020b4f64. No matching claim. */
#include "types.h"
#include "deps/020b4f64_func_020b4f64.h"

void func_020b4f64(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  
  if (((*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
       *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) ==
       (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
       *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20)) &&
     (uVar1 = (uint)(param_2 + 2) & 3, uVar6 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc),
     uVar2 = param_3 + 8 & 3, uVar3 = *(uint *)(param_3 + 8 & 0xfffffffc),
     (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) ==
     (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20))) {
    iVar7 = param_2[1];
    iVar9 = param_2[2];
    *param_1 = *param_2;
    param_1[1] = iVar7;
    param_1[2] = iVar9;
    return;
  }
  uVar4 = func_020c0d9c();
  uVar4 = SomeFxProduct(uVar4,0x3000);
  iVar7 = SomeFxProduct(uVar4,(*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                              *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) -
                              (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                              *(uint *)((uint)param_2 & 0xfffffffc) <<
                              ((uint)param_2 & 3) * -8 + 0x20));
  uVar6 = *(uint *)((uint)param_2 & 0xfffffffc);
  uVar1 = param_3 + 4 & 3;
  uVar10 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar2 = (uint)(param_2 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  iVar9 = SomeFxProduct(uVar4,(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) -
                              (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20));
  uVar1 = (uint)(param_2 + 1) & 3;
  uVar10 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
  uVar2 = param_3 + 8 & 3;
  uVar11 = *(uint *)(param_3 + 8 & 0xfffffffc);
  uVar3 = (uint)(param_2 + 2) & 3;
  uVar8 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  iVar5 = SomeFxProduct(uVar4,(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) -
                              (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20));
  uVar2 = (uint)(param_2 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  *param_1 = (uVar6 >> ((uint)param_2 & 3) * 8 | uVar6 << ((uint)param_2 & 3) * -8 + 0x20) + iVar7;
  param_1[1] = (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) + iVar9;
  param_1[2] = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + iVar5;
  return;
}

