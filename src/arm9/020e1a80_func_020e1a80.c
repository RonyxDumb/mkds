/* Decompiled C draft; module arm9; ROM address 020e1a80. No matching claim. */
#include "types.h"
#include "deps/020e1a80_func_020e1a80.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020e1a80(int param_1,int param_2,uint param_3,ushort param_4,ushort param_5,
                  undefined2 *param_6,int param_7,int param_8,undefined4 param_9,uint *param_10,
                  uint *param_11,uint *param_12,uint *param_13,undefined4 param_14)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  bool bVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint uVar10;
  
  bVar4 = false;
  if (param_7 != 0) {
    if ((param_4 & param_5) == 0) {
      uVar10 = (uint)(param_10 + 1) & 3;
      uVar9 = *(uint *)((uint)(param_10 + 1) & 0xfffffffc);
      uVar10 = -(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20);
    }
    else {
      uVar10 = (uint)(param_10 + 1) & 3;
      uVar9 = *(uint *)((uint)(param_10 + 1) & 0xfffffffc);
      uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
    }
    uVar9 = param_8 + 0x120U & 3;
    uVar6 = *(uint *)(param_8 + 0x120U & 0xfffffffc);
    if ((int)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) < (int)uVar10) {
      bVar4 = true;
    }
  }
  uVar10 = (uint)(param_10 + 1) & 3;
  uVar9 = *(uint *)((uint)(param_10 + 1) & 0xfffffffc);
  lVar1 = (longlong)
          (int)((*(uint *)((uint)param_10 & 0xfffffffc) >> ((uint)param_10 & 3) * 8 |
                *(uint *)((uint)param_10 & 0xfffffffc) << ((uint)param_10 & 3) * -8 + 0x20) << 10) *
          (longlong)param_2;
  lVar2 = (longlong)(int)((uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) << 10) *
          (longlong)param_2;
  uVar10 = (uint)(param_10 + 2) & 3;
  uVar9 = *(uint *)((uint)(param_10 + 2) & 0xfffffffc);
  uVar6 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  lVar1 = (longlong)(int)((uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) << 10) *
          (longlong)param_2;
  uVar10 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar9 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  if (bVar4) {
    uVar8 = param_8 + 0x11cU & 3;
    uVar7 = *(uint *)(param_8 + 0x11cU & 0xfffffffc);
    if ((uVar7 >> uVar8 * 8 == 0 && uVar7 << uVar8 * -8 + 0x20 == 0) || ((param_4 & 8) == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0x12;
    }
    *param_6 = uVar5;
  }
  else {
    *param_6 = 8;
    param_11 = param_12;
  }
  uVar8 = (uint)(param_11 + 6) & 3;
  uVar7 = *(uint *)((uint)(param_11 + 6) & 0xfffffffc);
  if ((int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) <= (int)param_3) {
    param_11[6] = param_3;
    if ((param_4 & param_5) == 0) {
      param_11[7] = -(*(uint *)((uint)param_10 & 0xfffffffc) >> ((uint)param_10 & 3) * 8 |
                     *(uint *)((uint)param_10 & 0xfffffffc) << ((uint)param_10 & 3) * -8 + 0x20);
      uVar8 = (uint)(param_10 + 1) & 3;
      uVar7 = *(uint *)((uint)(param_10 + 1) & 0xfffffffc);
      param_11[8] = -(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
      uVar8 = (uint)(param_10 + 2) & 3;
      uVar7 = *(uint *)((uint)(param_10 + 2) & 0xfffffffc);
      param_11[9] = -(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
    }
    else {
      uVar8 = param_10[1];
      uVar7 = param_10[2];
      param_11[7] = *param_10;
      param_11[8] = uVar8;
      param_11[9] = uVar7;
    }
  }
  if ((int)(*(uint *)((uint)param_11 & 0xfffffffc) >> ((uint)param_11 & 3) * 8 |
           *(uint *)((uint)param_11 & 0xfffffffc) << ((uint)param_11 & 3) * -8 + 0x20) < (int)uVar6)
  {
    *param_11 = uVar6;
  }
  else {
    uVar8 = (uint)(param_11 + 3) & 3;
    uVar7 = *(uint *)((uint)(param_11 + 3) & 0xfffffffc);
    if ((int)uVar6 < (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
      param_11[3] = uVar6;
    }
  }
  uVar6 = (uint)(param_11 + 1) & 3;
  uVar8 = *(uint *)((uint)(param_11 + 1) & 0xfffffffc);
  if ((int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) < (int)uVar9) {
    param_11[1] = uVar9;
  }
  else {
    uVar6 = (uint)(param_11 + 4) & 3;
    uVar8 = *(uint *)((uint)(param_11 + 4) & 0xfffffffc);
    if ((int)uVar9 < (int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20)) {
      param_11[4] = uVar9;
    }
  }
  uVar9 = (uint)(param_11 + 2) & 3;
  uVar6 = *(uint *)((uint)(param_11 + 2) & 0xfffffffc);
  if ((int)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) < (int)uVar10) {
    param_11[2] = uVar10;
  }
  else {
    uVar9 = (uint)(param_11 + 5) & 3;
    uVar6 = *(uint *)((uint)(param_11 + 5) & 0xfffffffc);
    if ((int)uVar10 < (int)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20)) {
      param_11[5] = uVar10;
    }
  }
  if (param_13 != (uint *)0x0) {
    if ((param_4 & param_5) == 0) {
      param_1 = param_1 - param_3;
      lVar1 = (longlong)
              (int)(*(uint *)((uint)param_10 & 0xfffffffc) >> ((uint)param_10 & 3) * 8 |
                   *(uint *)((uint)param_10 & 0xfffffffc) << ((uint)param_10 & 3) * -8 + 0x20) *
              (longlong)param_1;
      local_30 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar10 = (uint)(param_10 + 1) & 3;
      uVar9 = *(uint *)((uint)(param_10 + 1) & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) * (longlong)param_1
      ;
      local_2c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar10 = (uint)(param_10 + 2) & 3;
      uVar9 = *(uint *)((uint)(param_10 + 2) & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) * (longlong)param_1
      ;
      local_28 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    }
    else {
      iVar3 = -(param_1 - param_3);
      lVar1 = (longlong)
              (int)(*(uint *)((uint)param_10 & 0xfffffffc) >> ((uint)param_10 & 3) * 8 |
                   *(uint *)((uint)param_10 & 0xfffffffc) << ((uint)param_10 & 3) * -8 + 0x20) *
              (longlong)iVar3;
      local_30 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar10 = (uint)(param_10 + 1) & 3;
      uVar9 = *(uint *)((uint)(param_10 + 1) & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) * (longlong)iVar3;
      local_2c = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
      uVar10 = (uint)(param_10 + 2) & 3;
      uVar9 = *(uint *)((uint)(param_10 + 2) & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) * (longlong)iVar3;
      local_28 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    }
    uVar10 = (uint)(param_13 + 1) & 3;
    uVar9 = *(uint *)((uint)(param_13 + 1) & 0xfffffffc);
    if ((int)local_2c < (int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20)) {
      *param_13 = local_30;
      param_13[1] = local_2c;
      param_13[2] = local_28;
    }
  }
  if (!bVar4) {
    return;
  }
  func_020e0680(param_8,param_9,param_10,param_14);
  return;
}

