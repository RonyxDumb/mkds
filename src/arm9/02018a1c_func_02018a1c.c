/* Decompiled C draft; module arm9; ROM address 02018a1c. No matching claim. */
#include "types.h"
#include "deps/02018a1c_func_02018a1c.h"

void func_02018a1c(uint param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_50;
  
  iVar9 = 0x20;
  *(undefined2 *)(param_1 + 0x30) = *(undefined2 *)(param_2 + 8);
  *(undefined2 *)(param_1 + 0x32) = *(undefined2 *)(param_2 + 10);
  uVar1 = (*(code *)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20))
                    ((uint)*(ushort *)(param_1 + 0x30) << 5);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  uVar3 = param_1 + 0x28 & 3;
  uVar2 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
  Mem_CpuFill8((uint *)(uintptr_t)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20),0,
               (uint)*(ushort *)(param_1 + 0x30) << 5);
  local_50 = 0;
  if (*(short *)(param_1 + 0x30) != 0) {
    iVar7 = 0;
    do {
      uVar3 = param_1 + 0x28 & 3;
      uVar2 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
      uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      *(int *)(uVar5 + iVar7) = param_2 + iVar9;
      uVar3 = uVar5 + iVar7 & 3;
      uVar2 = *(uint *)(uVar5 + iVar7 & 0xfffffffc);
      uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      iVar10 = iVar9 + 0x58;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      iVar8 = uVar5 + iVar7;
      if ((int)(uVar3 << 0x17) < 0) {
        *(int *)(iVar8 + 4) = param_2 + iVar10;
        iVar10 = iVar9 + 100;
      }
      else {
        *(undefined4 *)(iVar8 + 4) = 0;
      }
      if ((int)(uVar3 << 0x16) < 0) {
        *(int *)(iVar8 + 8) = param_2 + iVar10;
        iVar10 = iVar10 + 0xc;
      }
      else {
        *(undefined4 *)(iVar8 + 8) = 0;
      }
      if ((int)(uVar3 << 0x15) < 0) {
        *(int *)(iVar8 + 0xc) = param_2 + iVar10;
        iVar10 = iVar10 + 8;
      }
      else {
        *(undefined4 *)(iVar8 + 0xc) = 0;
      }
      if ((int)(uVar3 << 0x14) < 0) {
        *(int *)(iVar8 + 0x10) = param_2 + iVar10;
        iVar10 = iVar10 + 0xc;
      }
      else {
        *(undefined4 *)(iVar8 + 0x10) = 0;
      }
      if ((int)(uVar3 << 0xf) < 0) {
        *(int *)(iVar8 + 0x14) = param_2 + iVar10;
        iVar9 = iVar10 + 0x14;
      }
      else {
        *(undefined4 *)(iVar8 + 0x14) = 0;
        iVar9 = iVar10;
      }
      iVar10 = -((int)(uVar3 << 7) >> 0x1f);
      *(short *)(iVar8 + 0x1c) =
           (((((short)iVar10 - (short)((int)(uVar3 << 6) >> 0x1f)) -
             (short)((int)(uVar3 << 5) >> 0x1f)) - (short)((int)(uVar3 << 4) >> 0x1f)) -
           (short)((int)(uVar3 << 3) >> 0x1f)) - (short)((int)(uVar3 << 2) >> 0x1f);
      if (*(ushort *)(iVar8 + 0x1c) == 0) {
        *(undefined4 *)(iVar8 + 0x18) = 0;
      }
      else {
        uVar1 = (*(code *)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20))
                          ((uint)*(ushort *)(iVar8 + 0x1c) << 3);
        *(undefined4 *)(iVar8 + 0x18) = uVar1;
        uVar2 = iVar8 + 0x18U & 3;
        uVar5 = *(uint *)(iVar8 + 0x18U & 0xfffffffc);
        puVar4 = (undefined4 *)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
        if (iVar10 != 0) {
          puVar4[1] = param_2 + iVar9;
          iVar9 = iVar9 + 8;
          *puVar4 = uRam02018d7c;
          puVar4 = puVar4 + 2;
        }
        if ((int)(uVar3 << 6) < 0) {
          puVar4[1] = param_2 + iVar9;
          iVar9 = iVar9 + 8;
          *puVar4 = uRam02018d80;
          puVar4 = puVar4 + 2;
        }
        if ((int)(uVar3 << 5) < 0) {
          puVar4[1] = param_2 + iVar9;
          iVar9 = iVar9 + 0x10;
          *puVar4 = uRam02018d84;
          puVar4 = puVar4 + 2;
        }
        if ((int)(uVar3 << 4) < 0) {
          puVar4[1] = param_2 + iVar9;
          iVar9 = iVar9 + 4;
          *puVar4 = uRam02018d88;
          puVar4 = puVar4 + 2;
        }
        if ((int)(uVar3 << 3) < 0) {
          puVar4[1] = param_2 + iVar9;
          iVar9 = iVar9 + 8;
          *puVar4 = uRam02018d8c;
          puVar4 = puVar4 + 2;
        }
        if ((int)(uVar3 << 2) < 0) {
          puVar4[1] = param_2 + iVar9;
          iVar9 = iVar9 + 0x10;
          *puVar4 = uRam02018d90;
        }
      }
      local_50 = local_50 + 1;
      iVar7 = iVar7 + 0x20;
    } while (local_50 < (int)(uint)*(ushort *)(param_1 + 0x30));
  }
  uVar1 = (*(code *)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20))
                    ((uint)*(ushort *)(param_1 + 0x32) * 0x14);
  *(undefined4 *)(param_1 + 0x2c) = uVar1;
  uVar3 = param_1 + 0x2c & 3;
  uVar2 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
  Mem_CpuFill8((uint *)(uintptr_t)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20),0,
               (uint)*(ushort *)(param_1 + 0x32) * 0x14);
  iVar7 = 0;
  if (*(short *)(param_1 + 0x32) != 0) {
    iVar10 = 0;
    do {
      uVar3 = param_1 + 0x2c & 3;
      uVar2 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
      uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      iVar8 = param_2 + iVar9;
      *(int *)(uVar2 + iVar10) = iVar8;
      uVar3 = iVar8 + 4U & 3;
      uVar5 = *(uint *)(iVar8 + 4U & 0xfffffffc);
      iVar6 = uVar2 + iVar10;
      *(short *)(iVar6 + 0x10) =
           (short)(1 << (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) << 0x18) >> 0x1c) + 3);
      uVar3 = iVar8 + 4U & 3;
      uVar2 = *(uint *)(iVar8 + 4U & 0xfffffffc);
      iVar7 = iVar7 + 1;
      *(short *)(iVar6 + 0x12) =
           (short)(1 << (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) << 0x14) >> 0x1c) + 3);
      uVar3 = iVar8 + 4U & 3;
      uVar2 = *(uint *)(iVar8 + 4U & 0xfffffffc);
      iVar10 = iVar10 + 0x14;
      *(uint *)(iVar6 + 0xc) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar3 = iVar8 + 0x1cU & 3;
      uVar2 = *(uint *)(iVar8 + 0x1cU & 0xfffffffc);
      iVar9 = iVar9 + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    } while (iVar7 < (int)(uint)*(ushort *)(param_1 + 0x32));
    return;
  }
  return;
}

