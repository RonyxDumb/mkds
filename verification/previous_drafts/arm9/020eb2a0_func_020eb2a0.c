/* Decompiled C draft; module arm9; ROM address 020eb2a0. No matching claim. */
#include "types.h"
#include "deps/020eb2a0_func_020eb2a0.h"

void func_020eb2a0(uint param_1,uint param_2,int param_3,int param_4,uint *param_5)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  int local_28 [2];
  int local_20;
  
  *param_5 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
             (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
  param_5[1] = 0;
  uVar7 = param_1 + 8 & 3;
  uVar5 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar6 = param_2 + 8 & 3;
  uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
  param_5[2] = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) -
               (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
  uVar7 = (uint)(param_5 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_5 + 1) & 0xfffffffc);
  uVar4 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  uVar6 = *(uint *)((uint)param_5 & 0xfffffffc) >> ((uint)param_5 & 3) * 8 |
          *(uint *)((uint)param_5 & 0xfffffffc) << ((uint)param_5 & 3) * -8 + 0x20;
  uVar7 = (uint)(param_5 + 2) & 3;
  uVar5 = *(uint *)((uint)(param_5 + 2) & 0xfffffffc);
  uVar7 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar7 * (longlong)(int)uVar7 +
          (longlong)(int)uVar6 * (longlong)(int)uVar6 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(param_5),local_28);
  }
  *param_5 = ((uint)((longlong)local_28[0] * (longlong)param_3) >> 0xc |
             (int)((ulonglong)((longlong)local_28[0] * (longlong)param_3) >> 0x20) << 0x14) -
             (*(uint *)((uint)param_5 & 0xfffffffc) >> ((uint)param_5 & 3) * 8 |
             *(uint *)((uint)param_5 & 0xfffffffc) << ((uint)param_5 & 3) * -8 + 0x20);
  uVar7 = (uint)(param_5 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_5 + 2) & 0xfffffffc);
  param_5[2] = ((uint)((longlong)local_20 * (longlong)param_3) >> 0xc |
               (int)((ulonglong)((longlong)local_20 * (longlong)param_3) >> 0x20) << 0x14) -
               (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20);
  uVar7 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar6 = param_2 + 4 & 3;
  uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc);
  param_5[1] = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) -
               (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
  uVar7 = (uint)(param_5 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_5 + 1) & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if ((int)uVar7 < 1) {
    param_5[1] = -(param_4 + uVar7);
  }
  else {
    param_5[1] = param_4 - uVar7;
  }
  uVar7 = (uint)(param_5 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_5 + 2) & 0xfffffffc);
  uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  uVar7 = (uint)(param_5 + 1) & 3;
  uVar4 = *(uint *)((uint)(param_5 + 1) & 0xfffffffc);
  uVar7 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  uVar4 = *(uint *)((uint)param_5 & 0xfffffffc) >> ((uint)param_5 & 3) * 8 |
          *(uint *)((uint)param_5 & 0xfffffffc) << ((uint)param_5 & 3) * -8 + 0x20;
  iVar2 = (int)((ulonglong)((longlong)(int)uVar7 * (longlong)(int)uVar7) >> 0x20);
  lVar1 = (longlong)(int)uVar4 * (longlong)(int)uVar4 + (longlong)(int)uVar6 * (longlong)(int)uVar6;
  iVar3 = (int)((ulonglong)lVar1 >> 0x20);
  bVar8 = (uint)((longlong)(int)uVar7 * (longlong)(int)uVar7) < (uint)lVar1;
  if ((int)(iVar2 - (iVar3 + (uint)bVar8)) < 0 !=
      (SBORROW4(iVar2,iVar3) != SBORROW4(iVar2 - iVar3,(uint)bVar8))) {
    if ((int)uVar7 < 1) {
      uVar7 = -uVar7;
    }
    if ((int)uVar7 < (int)uVar4) {
      *param_5 = uVar7;
    }
    else if ((int)(uVar4 + uVar7) < 0 != SBORROW4(uVar4,-uVar7)) {
      *param_5 = -uVar7;
    }
    uVar6 = (uint)(param_5 + 2) & 3;
    uVar4 = *(uint *)((uint)(param_5 + 2) & 0xfffffffc);
    uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
    if ((int)uVar7 < (int)uVar6) {
      param_5[2] = uVar7;
    }
    else if ((int)(uVar6 + uVar7) < 0 != SBORROW4(uVar6,-uVar7)) {
      param_5[2] = -uVar7;
    }
  }
  param_5[1] = 0;
  return;
}

