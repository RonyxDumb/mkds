/* Decompiled C draft; module arm9; ROM address 01ffbe70. No matching claim. */
#include "types.h"
#include "deps/01ffbe70_func_01ffbe70.h"

void func_01ffbe70(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = param_1 + 0x2ccU & 3;
  uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar7 = param_1 + 0xdcU & 3;
  uVar6 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  uVar8 = (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + 0x10;
  uVar3 = uVar8 & 3;
  uVar9 = *(uint *)(uVar8 & 0xfffffffc);
  uVar8 = param_1 + 0xd4U & 3;
  uVar5 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20);
  uVar7 = param_1 + 0xd8U & 3;
  uVar3 = *(uint *)(param_1 + 0xd8U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
  lVar1 = (longlong)(int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) *
          (longlong)(int)((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  *(uint *)(param_1 + 0xcc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar8 = param_1 + 0x7cU & 3;
  uVar7 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  puVar4 = (uint *)(param_1 + 0xcc);
  if (((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & uRam01ffbfd0) != 0) {
    uVar8 = param_1 + 0x2ccU & 3;
    uVar7 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 0x10;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *puVar4 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    *(undefined4 *)(param_1 + 0xdc) = 0x1000;
  }
  uVar8 = param_1 + 0x48U & 3;
  uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if (((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & 0x10000000) != 0) {
    uVar8 = param_1 + 0x4c4U & 3;
    uVar7 = *(uint *)(param_1 + 0x4c4U & 0xfffffffc);
    *puVar4 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    *(undefined4 *)(param_1 + 0xdc) = 0x1000;
  }
  uVar8 = param_1 + 0x48U & 3;
  uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if ((uVar8 & 0x20) != 0) {
    uVar7 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if ((((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) & uRam01ffbfd4) != 0) ||
       ((uVar8 & 0x20000000) != 0)) {
      uVar8 = param_1 + 0x2ccU & 3;
      uVar7 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
      uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *puVar4 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      *(undefined4 *)(param_1 + 0xdc) = 0x1000;
    }
    uVar8 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    lVar1 = (ulonglong)uRam01ffbfd8 * (ulonglong)uVar8;
    *puVar4 = (uint)lVar1 >> 0xc |
              (((int)uVar8 >> 0x1f) * uRam01ffbfd8 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar8 = param_1 + 0x48U & 3;
    uVar7 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & uRam01ffbfdc) != 0) {
      if ((int)(*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
               *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) < 0x8800) {
        *puVar4 = 0x8800;
        *(undefined4 *)(param_1 + 0xdc) = 0x1000;
      }
      return;
    }
    return;
  }
  uVar8 = param_1 + 0x4cU & 3;
  uVar7 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & uRam01ffbfd4) != 0) {
    uVar8 = param_1 + 0x2ccU & 3;
    uVar7 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 0x10;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    lVar1 = (ulonglong)uRam01ffbfe0 * (ulonglong)uVar8;
    *puVar4 = (uint)lVar1 >> 0xc |
              (((int)uVar8 >> 0x1f) * uRam01ffbfe0 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    *(undefined4 *)(param_1 + 0xdc) = 0x1000;
    return;
  }
  return;
}

