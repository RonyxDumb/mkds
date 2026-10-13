/* Decompiled C draft; module arm9; ROM address 01fff434. No matching claim. */
#include "types.h"
#include "deps/01fff434_func_01fff434.h"

void func_01fff434(int param_1,int param_2,int param_3,int *param_4,uint param_5,uint param_6,
                  longlong *param_7)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = FX_Div(((uint)((longlong)param_1 * (longlong)param_2) >> 0xc |
                 (int)((ulonglong)((longlong)param_1 * (longlong)param_2) >> 0x20) << 0x14) -
                 param_3,((uint)((longlong)param_1 * (longlong)param_1) >> 0xc |
                         (int)((ulonglong)((longlong)param_1 * (longlong)param_1) >> 0x20) << 0x14)
                         - 0x1000);
  param_2 = param_2 - ((uint)((longlong)iVar3 * (longlong)param_1) >> 0xc |
                      (int)((ulonglong)((longlong)iVar3 * (longlong)param_1) >> 0x20) << 0x14);
  lVar1 = (longlong)iVar3 *
          (longlong)
          (int)(*(uint *)(param_5 & 0xfffffffc) >> (param_5 & 3) * 8 |
               *(uint *)(param_5 & 0xfffffffc) << (param_5 & 3) * -8 + 0x20);
  lVar2 = (longlong)param_2 *
          (longlong)
          (int)(*(uint *)(param_6 & 0xfffffffc) >> (param_6 & 3) * 8 |
               *(uint *)(param_6 & 0xfffffffc) << (param_6 & 3) * -8 + 0x20);
  *param_4 = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
             ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  uVar7 = param_5 + 4 & 3;
  uVar5 = *(uint *)(param_5 + 4 & 0xfffffffc);
  uVar6 = param_6 + 4 & 3;
  uVar4 = *(uint *)(param_6 + 4 & 0xfffffffc);
  lVar1 = (longlong)iVar3 * (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
  lVar2 = (longlong)param_2 * (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
  param_4[1] = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
               ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  uVar7 = param_5 + 8 & 3;
  uVar5 = *(uint *)(param_5 + 8 & 0xfffffffc);
  uVar6 = param_6 + 8 & 3;
  uVar4 = *(uint *)(param_6 + 8 & 0xfffffffc);
  lVar1 = (longlong)iVar3 * (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
  lVar2 = (longlong)param_2 * (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
  param_4[2] = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
               ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  uVar7 = (uint)(param_4 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_4 + 1) & 0xfffffffc);
  uVar4 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  uVar6 = *(uint *)((uint)param_4 & 0xfffffffc) >> ((uint)param_4 & 3) * 8 |
          *(uint *)((uint)param_4 & 0xfffffffc) << ((uint)param_4 & 3) * -8 + 0x20;
  uVar7 = (uint)(param_4 + 2) & 3;
  uVar5 = *(uint *)((uint)(param_4 + 2) & 0xfffffffc);
  uVar7 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  *param_7 = (longlong)(int)uVar7 * (longlong)(int)uVar7 +
             (longlong)(int)uVar6 * (longlong)(int)uVar6 +
             (longlong)(int)uVar4 * (longlong)(int)uVar4;
  return;
}

