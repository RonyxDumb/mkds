/* Decompiled C draft; module arm9; ROM address 020f2a6c. No matching claim. */
#include "types.h"
#include "deps/020f2a6c_func_020f2a6c.h"

void func_020f2a6c(uint param_1,uint param_2,int *param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar6;
  
  uVar6 = param_2 + 4 & 3;
  uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((int)(uVar6 * uVar6) < 0x10) {
    *param_3 = -(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
    uVar6 = param_1 + 4 & 3;
    uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
    param_3[1] = -(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    uVar6 = param_1 + 8 & 3;
    uVar5 = *(uint *)(param_1 + 8 & 0xfffffffc);
    param_3[2] = -(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    return;
  }
  *param_3 = (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                  *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 2;
  uVar6 = param_2 + 4 & 3;
  uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc);
  param_3[1] = (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) >> 2;
  uVar6 = param_2 + 8 & 3;
  uVar5 = *(uint *)(param_2 + 8 & 0xfffffffc);
  param_3[2] = (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) >> 2;
  *param_3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
             (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
             *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20);
  uVar6 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar5 = (uint)(param_3 + 2) & 3;
  uVar4 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
  param_3[2] = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) -
               (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  uVar6 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  lVar1 = (longlong)
          (int)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) *
          (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
  uVar5 = param_2 + 8 & 3;
  uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) *
          (longlong)(int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  uVar6 = (uint)(param_3 + 1) & 3;
  uVar5 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  param_3[1] = -(((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
                 ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14) +
                (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20));
  uVar6 = (uint)(param_3 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  uVar5 = param_2 + 4 & 3;
  uVar7 = *(uint *)(param_2 + 4 & 0xfffffffc);
  iVar3 = FX_Div(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,
                 uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  param_3[1] = iVar3;
  uVar6 = (uint)(param_3 + 1) & 3;
  uVar5 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  uVar4 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar5 = *(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
          *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20;
  uVar6 = (uint)(param_3 + 2) & 3;
  uVar7 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar5 * (longlong)(int)uVar5 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(param_3),param_3);
    return;
  }
  return;
}

